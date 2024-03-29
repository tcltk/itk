/*
 * ------------------------------------------------------------------------
 *      PACKAGE:  [incr Tk]
 *  DESCRIPTION:  Building mega-widgets with [incr Tcl]
 *
 *  [incr Tk] provides a framework for building composite "mega-widgets"
 *  using [incr Tcl] classes.  It defines a set of base classes that are
 *  specialized to create all other widgets.
 *
 *  This part adds C implementations for some of the methods in the
 *  base class itk::Archetype.
 *
 * ========================================================================
 *  AUTHOR:  Michael J. McLennan
 *           Bell Labs Innovations for Lucent Technologies
 *           mmclennan@lucent.com
 *           http://www.tcltk.com/itcl
 * ========================================================================
 *           Copyright (c) 1993-1998  Lucent Technologies, Inc.
 * ------------------------------------------------------------------------
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 */
#include <assert.h>
#include "itkInt.h"

/*
 *  FORWARD DECLARATIONS
 */

static int Itk_PropagateOption (Tcl_Interp *interp,
    ItclObject *contextObj, ClientData cdata, const char *newval);

static int Itk_ArchSetOption (Tcl_Interp *interp,
    ArchInfo *info, const char *name, const char *value);

static ArchComponent* Itk_CreateArchComponent (
    Tcl_Interp *interp, ArchInfo *info, char *name,
    ItclClass *iclsPtr, Tcl_Command accessCmd);
static void Itk_DelArchComponent (ArchComponent *archComp);

static int Itk_GetArchOption (Tcl_Interp *interp,
    ArchInfo *info, char *switchName, char *resName, char *resClass,
    const char *defVal, char *currVal, ArchOption **aoPtr);
static void Itk_InitArchOption (Tcl_Interp *interp,
    ArchInfo *info, ArchOption *archOpt, const char *defVal,
    char *currVal);
static void Itk_DelArchOption (ArchOption *archOpt);

static int Itk_RemoveArchOptionPart (ArchInfo *info,
    char *switchName, ClientData from);
static int Itk_IgnoreArchOptionPart (ArchInfo *info,
    GenericConfigOpt *opt);

static ConfigCmdline* Itk_CreateConfigCmdline (
    Tcl_Interp *interp, Tcl_Command accessCmd, char *switchName);
static void Itk_DeleteConfigCmdline (ClientData cdata);

static Tcl_HashTable* Itk_CreateGenericOptTable (Tcl_Interp *interp,
    const char *options);
static void Itk_DelGenericOptTable (Tcl_HashTable *tPtr);

static GenericConfigOpt* Itk_CreateGenericOpt (Tcl_Interp *interp,
    const char *switchName, Tcl_Command accessCmd);
static void Itk_DelGenericOpt (GenericConfigOpt* opt);



/*
 * ------------------------------------------------------------------------
 *  Itk_DelMergeInfo()
 *
 *  Destroys the "merge" info record shared by commands in the
 *  itk::option-parser namespace.  Invoked automatically when the
 *  namespace containing the parsing commands is destroyed and there
 *  are no more uses of the data.
 * ------------------------------------------------------------------------
 */
void
Itk_DelMergeInfo(
    void* cdata)  /* data to be destroyed */
{
    ArchMergeInfo *mergeInfo = (ArchMergeInfo*)cdata;

    Tcl_HashEntry *entry;
    Tcl_HashSearch place;
    Tcl_Obj *codePtr;

    assert(mergeInfo->optionTable == NULL);

    entry = Tcl_FirstHashEntry(&mergeInfo->usualCode, &place);
    while (entry) {
        codePtr = (Tcl_Obj*)Tcl_GetHashValue(entry);
        Tcl_DecrRefCount(codePtr);
        entry = Tcl_NextHashEntry(&place);
    }
    Tcl_DeleteHashTable(&mergeInfo->usualCode);

    ckfree((char*)mergeInfo);
}


/*
 * ------------------------------------------------------------------------
 *  Itk_DelArchInfo()
 *
 *  Invoked when the option info associated with an itk::Archetype
 *  widget is no longer needed.  This usually happens when a widget
 *  is destroyed.  Frees the given bundle of data and removes it
 *  from the global list of Archetype objects.
 * ------------------------------------------------------------------------
 */
void
Itk_DelArchInfo(
    ClientData cdata)    /* client data for Archetype objects */
{
    ArchInfo *info = (ArchInfo*)cdata;

    Tcl_HashEntry *entry;
    Tcl_HashSearch place;
    ArchOption *archOpt;
    ArchComponent *archComp;

    /*
     *  Destroy all component widgets.
     */
    entry = Tcl_FirstHashEntry(&info->components, &place);
    while (entry) {
        archComp = (ArchComponent*)Tcl_GetHashValue(entry);
        Itk_DelArchComponent(archComp);
        entry = Tcl_NextHashEntry(&place);
    }
    Tcl_DeleteHashTable(&info->components);

    /*
     *  Destroy all information associated with configuration options.
     */
    entry = Tcl_FirstHashEntry(&info->options, &place);
    while (entry) {
        archOpt = (ArchOption*)Tcl_GetHashValue(entry);
        Itk_DelArchOption(archOpt);
        entry = Tcl_NextHashEntry(&place);
    }
    Tcl_DeleteHashTable(&info->options);
    Itk_OptListFree(&info->order);

    ckfree((char*)info);
}


/*
 * ------------------------------------------------------------------------
 *  Itk_ArchCompAddCmd()
 *
 *  Invoked by [incr Tcl] to handle the itk::Archetype::itk_component
 *  method.  Adds a new component widget into the mega-widget,
 *  integrating its configuration options into the master list.
 *
 *      itk_component add ?-protected? ?-private? ?--? <name> \
 *          <createCmds> <optionCmds>
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchCompAddCmd(
    ClientData dummy,        /* unused */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *const objv[])   /* argument objects */
{
    Tcl_HashEntry *entry = NULL;
    char *path = NULL;
    ArchComponent *archComp = NULL;
    ArchMergeInfo *mergeInfo = NULL;
    Tcl_Obj *objNamePtr = NULL;
    Tcl_Obj *tmpNamePtr = NULL;
    Tcl_Obj *winNamePtr = NULL;
    Tcl_Obj *hullNamePtr = NULL;
    int pLevel = ITCL_PUBLIC;

    int newEntry;
    int result;
    const char *cmd;
    const char *token;
    const char *resultStr;
    char *name;
    Tcl_Namespace *parserNs;
    ItclClass *contextClass;
    ItclClass *ownerClass;
    ItclObject *contextObj;
    ArchInfo *info;
    Tcl_Command accessCmd;
    Tcl_Obj *objPtr;
    Tcl_DString buffer;

    ItclShowArgs(1, "Itk_ArchCompAddCmd", objc, objv);
    /*
     *  Get the Archetype info associated with this widget.
     */
    contextClass = NULL;
    if (Itcl_GetContext(interp, &contextClass, &contextObj) != TCL_OK ||
        !contextObj) {

        Tcl_ResetResult(interp);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "cannot access components without an object context",
            (char*)NULL);
        return TCL_ERROR;
    }

    if (Itk_GetArchInfo(interp, contextObj, &info) != TCL_OK) {
        return TCL_ERROR;
    }

    /*
     *  Look for options like "-protected" or "-private".
     */
    cmd = Tcl_GetString(objv[0]);

    while (objc > 1) {
        token = Tcl_GetString(objv[1]);
        if (*token != '-') {
            break;
        } else {
	    if (strcmp(token,"-protected") == 0) {
                pLevel = ITCL_PROTECTED;
            } else {
	        if (strcmp(token,"-private") == 0) {
                    pLevel = ITCL_PRIVATE;
                } else {
		    if (strcmp(token,"--") == 0) {
                        objc--;
                        objv++;
                        break;
                    } else {
                        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                                "bad option \"", token,
                                "\": should be -private, -protected or --",
                                (char*)NULL);
                            return TCL_ERROR;
                    }
		}
	    }
	}
        objc--;
        objv++;
    }

    if ((objc < 3) || (objc > 4)) {
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "wrong # args: should be \"", cmd,
            " ?-protected? ?-private? ?--? name createCmds ?optionCmds?",
            (char*)NULL);
        return TCL_ERROR;
    }

    ItclShowArgs(1, "COMPADD2", objc, objv);
    /*
     *  See if a component already exists with the symbolic name.
     */
    name = Tcl_GetString(objv[1]);
    entry = Tcl_CreateHashEntry(&info->components, name, &newEntry);
    if (!newEntry) {
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "component \"", name, "\" already defined",
            (char*)NULL);
        return TCL_ERROR;
    }

    /*
     *  If this component is the "hull" for the mega-widget, then
     *  move the object access command out of the way before
     *  creating the component, so it is not accidentally deleted.
     */
    Tcl_DStringInit(&buffer);

    objNamePtr = Tcl_NewStringObj((char*)NULL, 0);
    Tcl_GetCommandFullName(contextObj->iclsPtr->interp, contextObj->accessCmd,
            objNamePtr);
    Tcl_IncrRefCount(objNamePtr);

    if (strcmp(name, "hull") == 0) {
        tmpNamePtr = Tcl_NewStringObj((char*)NULL, 0);
        Tcl_GetCommandFullName(contextObj->iclsPtr->interp,
            contextObj->accessCmd, tmpNamePtr);
        Tcl_AppendToObj(tmpNamePtr, "-widget-", -1);
        Tcl_IncrRefCount(tmpNamePtr);

        result = Itcl_RenameCommand(interp, Tcl_GetString(objNamePtr),
                Tcl_GetString(tmpNamePtr));

        if (result != TCL_OK) {
            goto compFail;
        }
    }

    /*
     *  Execute the <createCmds> to create the component widget.
     *  Do this one level up, in the scope of the calling routine.
     */
    result = Tcl_EvalObjEx(interp, objv[2], 0);
    if (result != TCL_OK) {
        goto compFail;
    }

    /*
     *  Take the result from the widget creation commands as the
     *  path name for the new component.  Make a local copy of
     *  this, since the interpreter will get used in the mean time.
     */
    resultStr = Tcl_GetStringResult(interp);
    path = (char*)ckalloc((unsigned)(strlen(resultStr)+1));
    strcpy(path, resultStr);

    /*
     *  Look for the access command token in the context of the
     *  calling namespace.  By-pass any protection at this point.
     */
    accessCmd = Tcl_FindCommand(interp, path, (Tcl_Namespace*)NULL,
        /* flags */ 0);

    if (!accessCmd) {
        Tcl_ResetResult(interp);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
           "cannot find component access command \"",
            path, "\" for component \"", name, "\"",
            (char*)NULL);
        goto compFail;
    }

    winNamePtr = Tcl_NewStringObj((char*)NULL, 0);
    Tcl_GetCommandFullName(interp, accessCmd, winNamePtr);
    Tcl_IncrRefCount(winNamePtr);


    /*
     *  Create the component record.  Set the protection level
     *  according to the "-protected" or "-private" option.
     */
    ownerClass = contextClass;

    archComp = Itk_CreateArchComponent(interp, info, name, ownerClass,
            accessCmd);

    if (!archComp) {
        goto compFail;
    }

    Tcl_SetHashValue(entry, (ClientData)archComp);
    archComp->protection = pLevel;

    /*
     *  If this component is the "hull" for the mega-widget, then
     *  move the hull widget access command to a different name,
     *  and move the object access command back into place.  This
     *  way, when the widget name is used as a command, the object
     *  access command will handle all requests.
     */
    if (strcmp(name, "hull") == 0) {
        hullNamePtr = Tcl_NewStringObj((char*)NULL, 0);
        Tcl_GetCommandFullName(interp, accessCmd, hullNamePtr);
        Tcl_AppendToObj(hullNamePtr, "-itk_hull", -1);
        Tcl_IncrRefCount(hullNamePtr);

        result = Itcl_RenameCommand(interp, Tcl_GetString(winNamePtr),
                Tcl_GetString(hullNamePtr));

        if (result != TCL_OK) {
            goto compFail;
        }

        Tcl_DecrRefCount(winNamePtr);  /* winNamePtr keeps current name */
        winNamePtr = hullNamePtr;
        hullNamePtr = NULL;

        result = Itcl_RenameCommand(interp, Tcl_GetString(tmpNamePtr),
                Tcl_GetString(objNamePtr));

        if (result != TCL_OK) {
            goto compFail;
        }
    } else {

        /*
         *  Add a binding onto the new component, so that when its
         *  window is destroyed, it will automatically remove itself
         *  from its parent's component list.  Avoid doing these things
         *  for the "hull" component, since it is a special case and
         *  these things are not really necessary.
         */
        Tcl_DStringSetLength(&buffer, 0);
        Tcl_DStringAppend(&buffer, "::bindtags ", -1);
        Tcl_DStringAppend(&buffer, path, -1);
        if (Tcl_Eval(interp, Tcl_DStringValue(&buffer)) != TCL_OK) {
            goto compFail;
        }

	/*
	 * NOTE: We need the [::itcl::code] because the itk_component
	 * method is protected.
	 */

        Tcl_DStringSetLength(&buffer, 0);
        Tcl_DStringAppend(&buffer, "::bind itk-destroy-", -1);
        Tcl_DStringAppend(&buffer, path, -1);
        Tcl_DStringAppend(&buffer, " <Destroy> [::itcl::code ", -1);

        Tcl_DStringAppend(&buffer,
            Tcl_GetStringFromObj(objNamePtr,(int*)NULL), -1);

        Tcl_DStringAppend(&buffer, " itk_component delete ", -1);
        Tcl_DStringAppend(&buffer, name, -1);
        Tcl_DStringAppend(&buffer, "]\n", -1);
        Tcl_DStringAppend(&buffer, "::bindtags ", -1);
        Tcl_DStringAppend(&buffer, path, -1);
        Tcl_DStringAppend(&buffer, " {itk-destroy-", -1);
        Tcl_DStringAppend(&buffer, path, -1);
        Tcl_DStringAppend(&buffer, " ", -1);
        Tcl_DStringAppend(&buffer, Tcl_GetStringResult(interp), -1);
        Tcl_DStringAppend(&buffer, "}", -1);

        if (Tcl_Eval(interp, Tcl_DStringValue(&buffer)) != TCL_OK) {
            goto compFail;
        }
    }

    /*
     *  Query the list of configuration options for this widget,
     *  so we will know which ones are valid.  Build an option
     *  table to represent these, so they can be found quickly
     *  by the option parsing commands in "itk::option-parser".
     */
    Tcl_DStringSetLength(&buffer, 0);
    Tcl_DStringAppendElement(&buffer,
        Tcl_GetStringFromObj(winNamePtr, (int*)NULL));
    Tcl_DStringAppendElement(&buffer, "configure");

    result = Tcl_Eval(interp, Tcl_DStringValue(&buffer));

    if (result != TCL_OK) {
        goto compFail;
    }
    Tcl_DStringSetLength(&buffer, 0);
    Tcl_DStringAppend(&buffer, Tcl_GetStringResult(interp), -1);

    /*
     *  Find the "itk::option-parser" namespace and get the data
     *  record shared by all of the parsing commands.
     */
    parserNs = Tcl_FindNamespace(interp, "::itk::option-parser",
        (Tcl_Namespace*)NULL, TCL_LEAVE_ERR_MSG);

    if (!parserNs) {
        goto compFail;
    }
    mergeInfo = (ArchMergeInfo*)parserNs->clientData;
    assert(mergeInfo);

    /*
     *  Initialize the data record used by the option parsing commands.
     *  Store a table of valid configuration options, along with the
     *  info for the mega-widget that is being updated.
     */
    mergeInfo->optionTable = Itk_CreateGenericOptTable(interp,
            Tcl_DStringValue(&buffer));

    if (!mergeInfo->optionTable) {
        goto compFail;
    }
    mergeInfo->archInfo = info;
    mergeInfo->archComp = archComp;

    /*
     *  Execute the option-handling commands in the "itk::option-parser"
     *  namespace.  If there are no option-handling commands, invoke
     *  the "usual" command instead.
     */
    if (objc != 4) {
        objPtr = Tcl_NewStringObj("usual", -1);
        Tcl_IncrRefCount(objPtr);
    } else {
        objPtr = objv[3];
    }

    Tcl_Eval(interp, "::namespace path [::lreplace [::namespace path] end+1 end ::itk::option-parser]");
    result = Tcl_EvalObj(interp, objPtr);
    Tcl_Eval(interp, "::namespace path [::lrange [::namespace path] 0 end-1]");

    if (objc != 4) {
        Tcl_DecrRefCount(objPtr);
    }
    if (result != TCL_OK) {
        goto compFail;
    }

    Itk_DelGenericOptTable(mergeInfo->optionTable);
    mergeInfo->optionTable = NULL;
    mergeInfo->archInfo    = NULL;
    mergeInfo->archComp    = NULL;

    ckfree(path);

    Tcl_DStringFree(&buffer);
    if (objNamePtr) {
        Tcl_DecrRefCount(objNamePtr);
    }
    if (tmpNamePtr) {
        Tcl_DecrRefCount(tmpNamePtr);
    }
    if (winNamePtr) {
        Tcl_DecrRefCount(winNamePtr);
    }
    if (hullNamePtr) {
        Tcl_DecrRefCount(hullNamePtr);
    }

    Tcl_SetResult(interp, name, TCL_VOLATILE);
    return TCL_OK;

    /*
     *  If any errors were encountered, clean up and return.
     */
compFail:
    if (archComp) {
        Itk_DelArchComponent(archComp);
    }
    if (entry) {
        Tcl_DeleteHashEntry(entry);
    }
    if (path) {
        ckfree(path);
    }
    if (mergeInfo && mergeInfo->optionTable) {
        Itk_DelGenericOptTable(mergeInfo->optionTable);
        mergeInfo->optionTable = NULL;
        mergeInfo->archInfo    = NULL;
        mergeInfo->archComp    = NULL;
    }

    Tcl_DStringFree(&buffer);
    if (objNamePtr) {
        Tcl_DecrRefCount(objNamePtr);
    }
    if (tmpNamePtr) {
        Tcl_DecrRefCount(tmpNamePtr);
    }
    if (winNamePtr) {
        Tcl_DecrRefCount(winNamePtr);
    }
    if (hullNamePtr) {
        Tcl_DecrRefCount(hullNamePtr);
    }

    /*
     *  Add error info and return.
     */
    objPtr = Tcl_NewStringObj((char*)NULL, 0);
    Tcl_AppendToObj(objPtr, "\n    (while creating component \"", -1);
    Tcl_AppendToObj(objPtr, name, -1);
    Tcl_AppendToObj(objPtr, "\" for widget \"", -1);
    Tcl_GetCommandFullName(contextObj->iclsPtr->interp,
        contextObj->accessCmd, objPtr);
    Tcl_AppendToObj(objPtr, "\")", -1);
    Tcl_IncrRefCount(objPtr);

    Tcl_AddErrorInfo(interp, Tcl_GetStringFromObj(objPtr, (int*)NULL));
    Tcl_DecrRefCount(objPtr);


    return TCL_ERROR;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_ArchCompDeleteCmd()
 *
 *  Invoked by [incr Tcl] to handle the itk::Archetype::itk_component
 *  method.  Removes an existing component widget from a mega-widget,
 *  and removes any configuration options associated with it.
 *
 *      itk_component delete <name> ?<name> <name>...?
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchCompDeleteCmd(
    ClientData dummy,        /* unused */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *const objv[])   /* argument objects */
{
    int i;
    char *token;
    ItclClass *contextClass;
    ItclObject *contextObj;
    ArchInfo *info;
    Tcl_HashEntry *entry;
    Tcl_HashSearch place;
    Itcl_ListElem *elem;
    ArchComponent *archComp;
    ArchOption *archOpt;
    ArchOptionPart *optPart;
    Itcl_List delOptList;
    Tcl_DString buffer;

    ItclShowArgs(2, "Itk_ArchCompDeleteCmd", objc, objv);
    /*
     *  Get the Archetype info associated with this widget.
     */
    contextClass = NULL;
    if (Itcl_GetContext(interp, &contextClass, &contextObj) != TCL_OK ||
        !contextObj) {

        Tcl_ResetResult(interp);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "cannot access components without an object context",
            (char*)NULL);
        return TCL_ERROR;
    }
    if (Itk_GetArchInfo(interp, contextObj, &info) != TCL_OK) {
        return TCL_ERROR;
    }

    /*
     *  Scan through the list of component names and delete each
     *  one.  Make sure that each component exists.
     */
    for (i=1; i < objc; i++) {
        token = Tcl_GetString(objv[i]);
        entry = Tcl_FindHashEntry(&info->components, token);
        if (!entry) {
            Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                "name \"", token, "\" is not a component",
                (char*)NULL);
            return TCL_ERROR;
        }
        archComp = (ArchComponent*)Tcl_GetHashValue(entry);
if (archComp == NULL) {
    continue;
}

       /*
        *  Clean up the binding tag that causes the widget to
        *  call this method automatically when destroyed.
        *  Ignore errors if anything goes wrong.
        */
        Tcl_DStringInit(&buffer);
        Tcl_DStringAppend(&buffer, "::itk::remove_destroy_hook ", -1);
        Tcl_DStringAppend(&buffer, archComp->pathName, -1);
        (void) Tcl_Eval(interp, Tcl_DStringValue(&buffer));
        Tcl_ResetResult(interp);
        Tcl_DStringFree(&buffer);

        Tcl_UnsetVar2(interp, "itk_component", token, 0);
        Tcl_DeleteHashEntry(entry);

        /*
         *  Clean up the options that belong to the component.  Do this
         *  by scanning through all available options and looking for
         *  those that belong to the component.  If we remove them as
         *  we go, we'll mess up Tcl_NextHashEntry.  So instead, we
         *  build up a list of options to remove, and then remove the
         *  options below.
         */
        Itcl_InitList(&delOptList);
        entry = Tcl_FirstHashEntry(&info->options, &place);
        while (entry) {
            archOpt = (ArchOption*)Tcl_GetHashValue(entry);
            elem = Itcl_FirstListElem(&archOpt->parts);
            while (elem) {
                optPart = (ArchOptionPart*)Itcl_GetListValue(elem);
                if (optPart->from == (ClientData)archComp) {
                    Itcl_AppendList(&delOptList, (ClientData)entry);
                }
                elem = Itcl_NextListElem(elem);
            }
            entry = Tcl_NextHashEntry(&place);
        }

        /*
         *  Now that we've figured out which options to delete,
         *  go through the list and remove them.
         */
        elem = Itcl_FirstListElem(&delOptList);
        while (elem) {
            entry = (Tcl_HashEntry*)Itcl_GetListValue(elem);
            token = (char *)Tcl_GetHashKey(&info->options, entry);

            Itk_RemoveArchOptionPart(info, token, (ClientData)archComp);

            elem = Itcl_NextListElem(elem);
        }
        Itcl_DeleteList(&delOptList);

        Itk_DelArchComponent(archComp);
    }
    return TCL_OK;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_ArchOptKeepCmd()
 *
 *  Invoked by [incr Tcl] to handle the "keep" command in the itk
 *  option parser.  Integrates a list of component configuration options
 *  into a mega-widget, so that whenever the mega-widget is updated,
 *  the component will be updated as well.
 *
 *  Handles the following syntax:
 *
 *      keep <option> ?<option>...?
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchOptKeepCmd(
    ClientData clientData,   /* option merging info record */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *const objv[])   /* argument objects */
{
    ArchMergeInfo *mergeInfo = (ArchMergeInfo*)clientData;
    int result = TCL_OK;

    int i;
    char *token;
    Tcl_HashEntry *entry;
    GenericConfigOpt *opt;
    ArchOption *archOpt;
    ArchOptionPart *optPart;
    ConfigCmdline *cmdlinePtr;

    ItclShowArgs(2, "Itk_ArchOptKeepCmd", objc, objv);
    if (objc < 2) {
        Tcl_WrongNumArgs(interp, 1, objv, "option ?option...?");
        return TCL_ERROR;
    }

    /*
     *  Make sure that this command is being accessed in the
     *  proper context.  The merge info record should be set up
     *  properly.
     */
    if (!mergeInfo->archInfo || !mergeInfo->optionTable) {
        token = Tcl_GetStringFromObj(objv[0], (int*)NULL);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                "improper usage: \"", token,
                "\" should only be accessed via itk_component",
                (char*)NULL);
        return TCL_ERROR;
    }

    /*
     *  Scan through all of the options on the list, and make
     *  sure that they are valid options for this component.
     *  Integrate them into the option info for the mega-widget.
     */
    for (i=1; i < objc; i++) {
        token = Tcl_GetStringFromObj(objv[i], (int*)NULL);
        entry = Tcl_FindHashEntry(mergeInfo->optionTable, token);
        if (!entry) {
            Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                "option not recognized: ", token,
                (char*)NULL);
            result = TCL_ERROR;
            break;
        }
        opt = (GenericConfigOpt*)Tcl_GetHashValue(entry);

        /*
         *  If this option has already been integrated, then
         *  remove it and start again.
         */
        Itk_IgnoreArchOptionPart(mergeInfo->archInfo, opt);

        /*
         *  Build a command prefix that can be used to apply changes
         *  to this option for this component.
         */
        cmdlinePtr = Itk_CreateConfigCmdline(interp,
            mergeInfo->archComp->accessCmd, token);

        optPart = Itk_CreateOptionPart(interp, (ClientData)cmdlinePtr,
            Itk_PropagateOption, Itk_DeleteConfigCmdline,
            (ClientData)mergeInfo->archComp);

        result = Itk_AddOptionPart(interp, mergeInfo->archInfo,
            opt->switchName, opt->resName, opt->resClass,
            opt->init, opt->value, optPart, &archOpt);

        if (result == TCL_OK) {
            opt->integrated = archOpt;
            opt->optPart    = optPart;
        } else {
            Itk_DelOptionPart(optPart);
            result = TCL_ERROR;
            break;
        }
    }
    return result;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_ArchOptIgnoreCmd()
 *
 *  Invoked by [incr Tcl] to handle the "ignore" command in the itk
 *  option parser.  Removes a list of component configuration options
 *  from a mega-widget.  This negates the action of previous "keep"
 *  and "rename" commands.
 *
 *  Handles the following syntax:
 *
 *      ignore <option> ?<option>...?
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchOptIgnoreCmd(
    ClientData clientData,   /* option merging info record */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *const objv[])   /* argument objects */
{
    ArchMergeInfo *mergeInfo = (ArchMergeInfo*)clientData;

    int i;
    char *token;
    Tcl_HashEntry *entry;
    GenericConfigOpt *opt;

    ItclShowArgs(2, "Itk_ArchOptIgnoreCmd", objc, objv);
    if (objc < 2) {
        Tcl_WrongNumArgs(interp, 1, objv, "option ?option...?");
        return TCL_ERROR;
    }

    /*
     *  Make sure that this command is being accessed in the
     *  proper context.  The merge info record should be set up
     *  properly.
     */
    if (!mergeInfo->archInfo || !mergeInfo->optionTable) {
        token = Tcl_GetStringFromObj(objv[0], (int*)NULL);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "improper usage: \"", token,
            "\" should only be accessed via itk_component",
            (char*)NULL);
        return TCL_ERROR;
    }

    /*
     *  Scan through all of the options on the list, and make
     *  sure that they are valid options for this component.
     *  Remove them from the mega-widget.
     */
    for (i=1; i < objc; i++) {
        token = Tcl_GetStringFromObj(objv[i], (int*)NULL);
        entry = Tcl_FindHashEntry(mergeInfo->optionTable, token);
        if (!entry) {
            Tcl_AppendResult(interp, "option not recognized: ", token,
                (char*)NULL);
            return TCL_ERROR;
        }
        opt = (GenericConfigOpt*)Tcl_GetHashValue(entry);

        /*
         *  If this option has already been integrated, then
         *  remove it.  Otherwise, ignore it.
         */
        Itk_IgnoreArchOptionPart(mergeInfo->archInfo, opt);
    }
    return TCL_OK;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_ArchOptRenameCmd()
 *
 *  Invoked by [incr Tcl] to handle the "rename" command in the itk
 *  option parser.  Integrates one configuration option into a
 *  mega-widget, using a different name for the option.  Whenever the
 *  mega-widget option is updated, the renamed option will be updated
 *  as well.  Handles the following syntax:
 *
 *      rename <oldSwitch> <newSwitch> <resName> <resClass>
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchOptRenameCmd(
    ClientData clientData,   /* option merging info record */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *const objv[])   /* argument objects */
{
    ArchMergeInfo *mergeInfo = (ArchMergeInfo*)clientData;

    int result;
    char *oldSwitch, *newSwitch, *resName, *resClass;
    Tcl_HashEntry *entry;
    GenericConfigOpt *opt;
    ArchOption *archOpt;
    ArchOptionPart *optPart;
    ConfigCmdline *cmdlinePtr;

    ItclShowArgs(2, "Itk_ArchOptRenameCmd", objc, objv);
    if (objc != 5) {
        Tcl_WrongNumArgs(interp, 1, objv,
            "oldSwitch newSwitch resourceName resourceClass");
        return TCL_ERROR;
    }

    /*
     *  Make sure that this command is being accessed in the
     *  proper context.  The merge info record should be set up
     *  properly.
     */
    if (!mergeInfo->archInfo || !mergeInfo->optionTable) {
        char *token = Tcl_GetStringFromObj(objv[0], (int*)NULL);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "improper usage: \"", token,
            "\" should only be accessed via itk_component",
            (char*)NULL);
        return TCL_ERROR;
    }

    oldSwitch = Tcl_GetStringFromObj(objv[1], (int*)NULL);
    newSwitch = Tcl_GetStringFromObj(objv[2], (int*)NULL);
    resName   = Tcl_GetStringFromObj(objv[3], (int*)NULL);
    resClass  = Tcl_GetStringFromObj(objv[4], (int*)NULL);

    /*
     *  Make sure that the resource name and resource class look good.
     */
    if (!islower((int)*resName)) {
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "bad resource name \"", resName,
            "\": should start with a lower case letter",
            (char*)NULL);
        return TCL_ERROR;
    }
    if (!isupper((int)*resClass)) {
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "bad resource class \"", resClass,
            "\": should start with an upper case letter",
            (char*)NULL);
        return TCL_ERROR;
    }

    /*
     *  Make sure that the specified switch exists in the widget.
     */
    entry = Tcl_FindHashEntry(mergeInfo->optionTable, oldSwitch);
    if (!entry) {
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "option not recognized: ", oldSwitch,
            (char*)NULL);
        return TCL_ERROR;
    }
    opt = (GenericConfigOpt*)Tcl_GetHashValue(entry);

    /*
     *  If this option has already been integrated, then
     *  remove it and start again.
     */
    Itk_IgnoreArchOptionPart(mergeInfo->archInfo, opt);

    /*
     *  Build a command prefix that can be used to apply changes
     *  to this option for this component.
     */
    cmdlinePtr = Itk_CreateConfigCmdline(interp,
        mergeInfo->archComp->accessCmd, oldSwitch);

    optPart = Itk_CreateOptionPart(interp, (ClientData)cmdlinePtr,
        Itk_PropagateOption, Itk_DeleteConfigCmdline,
        (ClientData)mergeInfo->archComp);

    /*
     *  Merge this option into the mega-widget with a new name.
     */
    result = Itk_AddOptionPart(interp, mergeInfo->archInfo, newSwitch,
        resName, resClass, opt->init, opt->value, optPart,
        &archOpt);

    if (result == TCL_OK) {
        opt->integrated = archOpt;
        opt->optPart    = optPart;
    } else {
        Itk_DelOptionPart(optPart);
        result = TCL_ERROR;
    }
    return result;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_ArchOptUsualCmd()
 *
 *  Invoked by [incr Tcl] to handle the "usual" command in the itk
 *  option parser.  Looks for a set of "usual" option-handling commands
 *  associated with the given tag or component class and then evaluates
 *  the commands in the option parser namespace.  This keeps the user
 *  from having to type a bunch of "keep" and "rename" commands for
 *  each component widget.
 *
 *  Handles the following syntax:
 *
 *      usual ?<tag>?
 *
 *  If the <tag> is not specified, then the class name for the
 *  component is used as the tag name.
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchOptUsualCmd(
    ClientData clientData,   /* option merging info record */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *const objv[])   /* argument objects */
{
    ArchMergeInfo *mergeInfo = (ArchMergeInfo*)clientData;

    const char *tag;
    Tcl_HashEntry *entry;
    Tcl_Obj *codePtr;

    ItclShowArgs(2, "Itk_ArchOptUsualCmd", objc, objv);
    if (objc > 2) {
        Tcl_WrongNumArgs(interp, 1, objv, "?tag?");
        return TCL_ERROR;
    }

    /*
     *  Make sure that this command is being accessed in the
     *  proper context.  The merge info record should be set up
     *  properly.
     */
    if (!mergeInfo->archInfo || !mergeInfo->optionTable) {
        char *token = Tcl_GetStringFromObj(objv[0], (int*)NULL);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "improper usage: \"", token,
            "\" should only be accessed via itk_component",
            (char*)NULL);
        return TCL_ERROR;
    }

    /*
     *  If a tag name was specified, then use this to look up
     *  the "usual" code.  Otherwise, use the class name for
     *  the component widget.
     */
    if (objc == 2) {
        tag = Tcl_GetStringFromObj(objv[1], (int*)NULL);
    } else {
        tag = Tk_Class(mergeInfo->archComp->tkwin);
    }

    /*
     *  Look for some code associated with the tag and evaluate
     *  it in the current context.
     */
    entry = Tcl_FindHashEntry(&mergeInfo->usualCode, tag);
    if (entry) {
        codePtr = (Tcl_Obj*)Tcl_GetHashValue(entry);
        return Tcl_EvalObj(interp, codePtr);
    }

    Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
        "can't find usual code for tag \"", tag, "\"",
        (char*)NULL);
    return TCL_ERROR;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_UsualCmd()
 *
 *  Invoked by [incr Tcl] to handle the "usual" command in the ::itk
 *  namespace.  Used to query or set the option-handling code associated
 *  with a widget class or arbitrary tag name.  This code is later
 *  used by the "usual" command in the "itk::option-parser" namespace.
 *
 *  Handles the following syntax:
 *
 *      usual ?<tag>? ?<code>?
 *
 *  If the <tag> is not specified, then this returns a list of all
 *  known tags.  If the <code> is not specified, then this returns
 *  the current code associated with <tag>, or an empty string if
 *  <tag> is not recognized.  Otherwise, it sets the code fragment
 *  for <tag> to <code>.
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_UsualCmd(
    ClientData clientData,   /* option merging info record */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *const objv[])   /* argument objects */
{
    ArchMergeInfo *mergeInfo = (ArchMergeInfo*)clientData;

    int newEntry;
    char *tag, *token;
    Tcl_HashEntry *entry;
    Tcl_HashSearch place;
    Tcl_Obj *codePtr;

    ItclShowArgs(2, "Itk_UsualCmd", objc, objv);
    if (objc > 3) {
        Tcl_WrongNumArgs(interp, 1, objv, "?tag? ?commands?");
        return TCL_ERROR;
    }

    /*
     *  If no arguments were specified, then return a list of
     *  all known tags.
     */
    if (objc == 1) {
        entry = Tcl_FirstHashEntry(&mergeInfo->usualCode, &place);
        while (entry) {
            tag = (char *)Tcl_GetHashKey(&mergeInfo->usualCode, entry);
            Tcl_AppendElement(interp, tag);
            entry = Tcl_NextHashEntry(&place);
        }
        return TCL_OK;
    } else {

        /*
         *  If a code fragment was specified, then save it in the
         *  hash table for "usual" code.
         */
        if (objc == 3) {
            token = Tcl_GetStringFromObj(objv[1], (int*)NULL);
            entry = Tcl_CreateHashEntry(&mergeInfo->usualCode, token,
	            &newEntry);
            if (!newEntry) {
                codePtr = (Tcl_Obj*)Tcl_GetHashValue(entry);
                Tcl_DecrRefCount(codePtr);
            }

            codePtr = objv[2];
            Tcl_IncrRefCount(codePtr);
            Tcl_SetHashValue(entry, (ClientData)codePtr);

            return TCL_OK;
        }
    }

    /*
     *  Otherwise, look for a code fragment with the specified tag.
     */
    token = Tcl_GetStringFromObj(objv[1], (int*)NULL);
    entry = Tcl_FindHashEntry(&mergeInfo->usualCode, token);
    if (entry) {
        codePtr = (Tcl_Obj*)Tcl_GetHashValue(entry);
        Tcl_SetObjResult(interp, codePtr);
    }
    return TCL_OK;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_ArchOptionAddCmd()
 *
 *  Invoked by [incr Tcl] to handle the itk::Archetype::itk_option add
 *  method.  Finds an option within a class definition or belonging to
 *  a component widget and adds it into the option list for this widget.
 *  If the option is already on the list, this method does nothing.
 *  Handles the following syntax:
 *
 *      itk_option add <name> ?<name> <name>...?
 *
 *      where <name> is one of:
 *        class::option
 *        component.option
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchOptionAddCmd(
    ClientData dummy,        /* unused */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *const objv[])   /* argument objects */
{
    ItclClass *contextClass;
    ItclClass *iclsPtr;
    ItclObject *contextObj;
    ArchInfo *info;

    int i;
    int result;
    char *token;
    const char *head;
    const char *tail;
    char *sep;
    char tmp;
    ItkClassOption *opt;
    GenericConfigOpt *generic;
    ArchOption *archOpt;
    ArchOptionPart *optPart;
    ArchComponent *archComp;
    ConfigCmdline *cmdlinePtr;
    Tcl_HashEntry *entry;
    Tcl_DString buffer;

    ItclShowArgs(2, "Itk_ArchOptionAddCmd", objc, objv);
    /*
     *  Get the Archetype info associated with this widget.
     */
    contextClass = NULL;
    if (Itcl_GetContext(interp, &contextClass, &contextObj) != TCL_OK ||
        !contextObj) {

        Tcl_ResetResult(interp);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "cannot access options without an object context",
            (char*)NULL);
        return TCL_ERROR;
    }

    if (Itk_GetArchInfo(interp, contextObj, &info) != TCL_OK) {
        return TCL_ERROR;
    }

    /*
     *  Scan through the list of options and locate each one.
     *  If it is not already on the option part list, add it.
     */
    for (i=1; i < objc; i++) {
        token = Tcl_GetString(objv[i]);
        Itcl_ParseNamespPath(token, &buffer, &head, &tail);

        /*
         *  HANDLE:  class::option
         */
        if (head) {
            iclsPtr = Itcl_FindClass(interp, head, /* autoload */ 1);
            if (iclsPtr == NULL) {
                Tcl_DStringFree(&buffer);
                return TCL_ERROR;
            }

            opt = Itk_FindClassOption(iclsPtr, tail);
            if (!opt) {
                Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                    "option \"", tail, "\" not defined in class \"",
                    Tcl_GetString(iclsPtr->fullNamePtr), "\"",
                    (char*)NULL);
                Tcl_DStringFree(&buffer);
                return TCL_ERROR;
            }

            optPart = Itk_FindArchOptionPart(info, Tcl_GetString(opt->namePtr),
                (ClientData)iclsPtr);

            if (!optPart) {
                optPart = Itk_CreateOptionPart(interp, (ClientData)opt,
                    Itk_ConfigClassOption, (Tcl_CmdDeleteProc*)NULL,
                    (ClientData)iclsPtr);

                result = Itk_AddOptionPart(interp, info,
		        Tcl_GetString(opt->namePtr),
                        opt->resName, opt->resClass, opt->init, (char*)NULL,
                        optPart, &archOpt);

                if (result != TCL_OK) {
                    Itk_DelOptionPart(optPart);
                    Tcl_DStringFree(&buffer);
                    return TCL_ERROR;
                }
            }
            Tcl_DStringFree(&buffer);
            continue;
        }

        Tcl_DStringFree(&buffer);

        /*
         *  HANDLE:  component.option
         */
        sep = strstr(token, ".");
        if (sep) {
            tmp = *sep;
            *sep = '\0';
            head = token;
            tail = sep+1;

            entry = Tcl_FindHashEntry(&info->components, head);
            if (!entry) {
                Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                    "name \"", head, "\" is not a component",
                    (char*)NULL);
                *sep = tmp;
                return TCL_ERROR;
            }
            *sep = tmp;
            archComp = (ArchComponent*)Tcl_GetHashValue(entry);

            generic = Itk_CreateGenericOpt(interp, tail, archComp->accessCmd);
            if (!generic) {
                char msg[256];
                sprintf(msg, "\n    (while adding option \"%.100s\")", token);
                Tcl_AddErrorInfo(interp, msg);
                return TCL_ERROR;
            }

            optPart = Itk_FindArchOptionPart(info, generic->switchName,
                (ClientData)archComp);

            if (!optPart) {
                cmdlinePtr = Itk_CreateConfigCmdline(interp,
                    archComp->accessCmd, generic->switchName);

                optPart = Itk_CreateOptionPart(interp, (ClientData)cmdlinePtr,
                    Itk_PropagateOption, Itk_DeleteConfigCmdline,
                    (ClientData)archComp);

                result = Itk_AddOptionPart(interp, info,
                    generic->switchName, generic->resName, generic->resClass,
                    generic->init, generic->value, optPart, &archOpt);

                if (result != TCL_OK) {
                    Itk_DelOptionPart(optPart);
                    Itk_DelGenericOpt(generic);
                    return TCL_ERROR;
                }
            }
            Itk_DelGenericOpt(generic);
            continue;
        }

        /*
         *  Anything else is an error.
         */
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "bad option \"", token, "\": should be one of...\n",
            "  class::option\n",
            "  component.option",
            (char*)NULL);
        return TCL_ERROR;
    }

    return TCL_OK;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_ArchOptionRemoveCmd()
 *
 *  Invoked by [incr Tcl] to handle the itk::Archetype::itk_option remove
 *  method.  Finds an option within a class definition or belonging to
 *  a component widget and removes it from the option list for this widget.
 *  If the option has already been removed from the list, this method does
 *  nothing.  Handles the following syntax:
 *
 *      itk_option remove <name> ?<name> <name>...?
 *
 *      where <name> is one of:
 *        class::option
 *        component.option
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_ArchOptionRemoveCmd(
    ClientData dummy,        /* unused */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *const objv[])   /* argument objects */
{
    ItclClass *contextClass;
    ItclClass *iclsPtr;
    ItclObject *contextObj;
    ArchInfo *info;

    int i;
    char *name;
    const char *head;
    const char *tail;
    char *sep;
    char tmp;
    ItkClassOption *opt;
    GenericConfigOpt *generic;
    ArchComponent *archComp;
    Tcl_HashEntry *entry;
    Tcl_DString buffer;

    ItclShowArgs(2, "Itk_ArchOptionRemoveCmd", objc, objv);
    /*
     *  Get the Archetype info associated with this widget.
     */
    contextClass = NULL;
    if (Itcl_GetContext(interp, &contextClass, &contextObj) != TCL_OK ||
        !contextObj) {

        Tcl_ResetResult(interp);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "cannot access options without an object context",
            (char*)NULL);
        return TCL_ERROR;
    }

    if (Itk_GetArchInfo(interp, contextObj, &info) != TCL_OK) {
        return TCL_ERROR;
    }

    /*
     *  Scan through the list of options and locate each one.
     *  If it is on the option list, remove it.
     */
    for (i=1; i < objc; i++) {
        name = Tcl_GetString(objv[i]);
        Itcl_ParseNamespPath(name, &buffer, &head, &tail);

        /*
         *  HANDLE:  class::option
         */
        if (head) {
            iclsPtr = Itcl_FindClass(interp, head, /* autoload */ 1);
            if (!iclsPtr) {
                Tcl_DStringFree(&buffer);
                return TCL_ERROR;
            }

            opt = Itk_FindClassOption(iclsPtr, tail);
            if (!opt) {
                Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                    "option \"", tail, "\" not defined in class \"",
                    Tcl_GetString(iclsPtr->fullNamePtr), "\"",
                    (char*)NULL);
                Tcl_DStringFree(&buffer);
                return TCL_ERROR;
            }

            Itk_RemoveArchOptionPart(info, Tcl_GetString(opt->namePtr),
                (ClientData)iclsPtr);

            Tcl_DStringFree(&buffer);
            continue;
        }
        Tcl_DStringFree(&buffer);

        /*
         *  HANDLE:  component.option
         */
        sep = strstr(name, ".");
        if (sep) {
            tmp = *sep;
            *sep = '\0';
            head = name;
            tail = sep+1;

            entry = Tcl_FindHashEntry(&info->components, head);
            if (!entry) {
                Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                    "name \"", head, "\" is not a component",
                    (char*)NULL);
                *sep = tmp;
                return TCL_ERROR;
            }
            *sep = tmp;
            archComp = (ArchComponent*)Tcl_GetHashValue(entry);

            generic = Itk_CreateGenericOpt(interp, tail, archComp->accessCmd);
            if (!generic) {
                char msg[256];
                sprintf(msg, "\n    (while removing option \"%.100s\")",
                    name);
                Tcl_AddErrorInfo(interp, msg);
                return TCL_ERROR;
            }

            Itk_RemoveArchOptionPart(info, generic->switchName,
                (ClientData)archComp);

            Itk_DelGenericOpt(generic);
            continue;
        }

        /*
         *  Anything else is an error.
         */
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "bad option \"", name, "\": should be one of...\n",
            "  class::option\n",
            "  component.option",
            (char*)NULL);
        return TCL_ERROR;
    }

    return TCL_OK;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_PropagateOption()
 *
 *  Invoked whenever a widget-based configuration option has been
 *  configured with a new value.  Propagates the new value down to
 *  the widget by invoking the "configure" method on the widget.
 *  This causes the widget to bring itself up to date automatically.
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
static int
Itk_PropagateOption(
    Tcl_Interp *interp,        /* interpreter managing the class */
    ItclObject *contextObj,    /* itcl object being configured */
    ClientData cdata,          /* command prefix to use for configuration */
    const char *newval)        /* new value for this option */
{
    ConfigCmdline *cmdlinePtr = (ConfigCmdline*)cdata;
    int result;
    Tcl_Obj *objPtr;

    objPtr = Tcl_NewStringObj((const char *)newval, -1);
    Tcl_IncrRefCount(objPtr);

    cmdlinePtr->objv[3] = objPtr;
    result = Itcl_EvalArgs(interp, 4, cmdlinePtr->objv);

    Tcl_DecrRefCount(objPtr);
    return result;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_PropagatePublicVar()
 *
 *  Invoked whenever a mega-widget configuration option containing
 *  a public variable part has been configured with a new value.
 *  Updates the public variable with the new value and invokes any
 *  "config" code associated with it.
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Itk_PropagatePublicVar(
    Tcl_Interp *interp,        /* interpreter managing the class */
    ItclObject *contextObj,    /* itcl object being configured */
    ClientData cdata,          /* command prefix to use for configuration */
    const char *newval)        /* new value for this option */
{
    ItclVariable *ivPtr = (ItclVariable*)cdata;

    int result = TCL_OK;
    const char *val;
    ItclMemberCode *mcode;

    /*
     *  Update the public variable with the new option value.
     *  There should already be a call frame installed for handling
     *  instance variables, but make sure that the namespace context
     *  is the most-specific class, so that the public variable can
     *  be found.
     */

    if (result == TCL_OK) {
	/*
	 * Casting away const of newval only to satisfy Tcl 8.3 and
	 * earlier headers.
	 */

#if 1
	val = ItclSetInstanceVar(interp, Tcl_GetString(ivPtr->fullNamePtr),
		NULL, newval, contextObj, ivPtr->iclsPtr);
#else
        val = Tcl_SetVar2(interp, Tcl_GetString(ivPtr->fullNamePtr), (char *) NULL,
            (char *) newval, TCL_LEAVE_ERR_MSG);
#endif

        if (!val) {
            result = TCL_ERROR;
        }
    }

    if (result != TCL_OK) {
        char msg[256];
        sprintf(msg, "\n    (error in configuration of public variable \"%.100s\")", Tcl_GetString(ivPtr->fullNamePtr));
        Tcl_AddErrorInfo(interp, msg);
        return TCL_ERROR;
    }

    /*
     *  If this variable has some "config" code, invoke it now.
     *
     *  NOTE:  Invoke the "config" code in the class scope
     *    containing the data member.
     */
    mcode = ivPtr->codePtr;
    if (mcode && mcode->bodyPtr) {
	Tcl_CallFrame frame;

	Itcl_PushCallFrame(interp, &frame, ivPtr->iclsPtr->nsPtr, 1);
	Itcl_SetContext(interp, contextObj);

        result = Tcl_EvalObjEx(interp, mcode->bodyPtr, 0);

	Itcl_UnsetContext(interp);
	Itcl_PopCallFrame(interp);

        if (result == TCL_OK) {
            Tcl_ResetResult(interp);
        } else {
            char msg[256];
            sprintf(msg, "\n    (error in configuration of public variable \"%.100s\")", Tcl_GetString(ivPtr->fullNamePtr));
            Tcl_AddErrorInfo(interp, msg);
        }
    }

    return result;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_ArchSetOption()
 *
 *  Sets a configuration option within an Archetype mega-widget.
 *  Changes the "itk_option" array to reflect the new value, but
 *  unlike Itk_ArchConfigOption(), this procedure does not update
 *  the widget by propagating changes or invoking any "config" code.
 *  It merely sets the widget state.  It is useful when a widget is
 *  first being constructed, to initialize option values.
 *
 *  NOTE:  This procedure assumes that there is a valid object context
 *    and a call frame supporting object data member access.  It is
 *    usually called from within the methods of the Archetype base
 *    class, so this is a good assumption.  If it is called anywhere
 *    else, the caller is responsible for installing the object context
 *    and setting up a call frame.
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */
static int
Itk_ArchSetOption(
    Tcl_Interp *interp,        /* interpreter managing this widget */
    ArchInfo *info,            /* Archetype info */
    const char *name,          /* name of configuration option */
    const char *value)         /* new value for configuration option */
{
    Tcl_HashEntry *entry;
    ArchOption *archOpt;

    entry = Tcl_FindHashEntry(&info->options, name);
    if (!entry) {
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "unknown option \"", name, "\"",
            (char*)NULL);
        return TCL_ERROR;
    }
    archOpt = (ArchOption*)Tcl_GetHashValue(entry);

    if (!Tcl_SetVar2(interp, "itk_option", archOpt->switchName,
	    (const char *)value, 0)) {
        Itk_ArchOptAccessError(interp, info, archOpt);
        return TCL_ERROR;
    }
    return TCL_OK;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_ArchConfigOption()
 *
 *  Sets a configuration option within an Archetype mega-widget.
 *  Changes the "itk_option" array to reflect the new value, and then
 *  invokes any option parts to handle the new setting or propagate
 *  the value down to component parts.
 *
 *  NOTE:  This procedure assumes that there is a valid object context
 *    and a call frame supporting object data member access.  It is
 *    usually called from within the methods of the Archetype base
 *    class, so this is a good assumption.  If it is called anywhere
 *    else, the caller is responsible for installing the object context
 *    and setting up a call frame.
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */
int
Itk_ArchConfigOption(
    Tcl_Interp *interp,        /* interpreter managing this widget */
    ArchInfo *info,            /* Archetype info */
    char *name,          /* name of configuration option */
    char *value)               /* new value for configuration option */
{
    int result;
    const char *v;
    char *lastval;
    Tcl_HashEntry *entry;
    ArchOption *archOpt;
    Itcl_ListElem *part;
    ArchOptionPart *optPart;
    Itcl_InterpState istate;
    ItclClass *iclsPtr;
    ItclObject *ioPtr;

    /*
     *  Query the "itk_option" array to get the current setting.
     */
    entry = Tcl_FindHashEntry(&info->options, name);
    if (!entry) {
        /* Bug 227876
	 * Ensure that the interp result is unshared.
	 */

        Tcl_ResetResult (interp);
        Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
            "unknown option \"", name, "\"",
            (char*)NULL);
        return TCL_ERROR;
    }
    archOpt = (ArchOption*)Tcl_GetHashValue(entry);

#if 0
    v = Tcl_GetVar2(interp, "itk_option", archOpt->switchName, 0);
#else
    Itcl_GetContext(interp, &iclsPtr, &ioPtr);

    v = ItclGetInstanceVar(interp, "itk_option", archOpt->switchName,
	    ioPtr, iclsPtr);
#endif

    if (v) {
        lastval = (char*)ckalloc((unsigned)(strlen(v)+1));
        strcpy(lastval, v);
    } else {
        lastval = NULL;
    }

    /*
     *  Update the "itk_option" array with the new setting.
     */
#if 0
    if (!Tcl_SetVar2(interp, "itk_option", archOpt->switchName, value, 0)) {
#else
    if (!ItclSetInstanceVar(interp, "itk_option", archOpt->switchName, value,
	    ioPtr, iclsPtr)) {
#endif
        Itk_ArchOptAccessError(interp, info, archOpt);
        result = TCL_ERROR;
        goto configDone;
    }

    /*
     *  Scan through all option parts to handle the new setting.
     */
    result = TCL_OK;
    part   = Itcl_FirstListElem(&archOpt->parts);

    while (part) {
        optPart = (ArchOptionPart*)Itcl_GetListValue(part);
        result  = (*optPart->configProc)(interp, info->itclObj,
            optPart->clientData, value);

        if (result != TCL_OK) {
            Itk_ArchOptConfigError(interp, info, archOpt);
            break;
        }
        part = Itcl_NextListElem(part);
    }

    /*
     *  If the option configuration failed, then set the option
     *  back to its previous settings.  Scan back through all of
     *  the option parts and sync them up with the old value.
     */
    if (result == TCL_ERROR) {
        istate = Itcl_SaveInterpState(interp, result);

#if 0
        Tcl_SetVar2(interp, "itk_option", archOpt->switchName, lastval, 0);
#else
	ItclSetInstanceVar(interp, "itk_option", archOpt->switchName, lastval,
	    ioPtr, iclsPtr);
#endif

        part = Itcl_FirstListElem(&archOpt->parts);
        while (part) {
            optPart = (ArchOptionPart*)Itcl_GetListValue(part);
            (*optPart->configProc)(interp, info->itclObj,
                optPart->clientData, lastval);

            part = Itcl_NextListElem(part);
        }
        result = Itcl_RestoreInterpState(interp, istate);
    }

    archOpt->flags |= ITK_ARCHOPT_INIT;  /* option has been set */

configDone:
    if (lastval) {
        ckfree(lastval);
    }
    return result;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_CreateArchComponent()
 *
 *  Creates the data representing a component widget within an Archetype
 *  mega-widget.  Each component has an access command that is used to
 *  communicate with it.  Each component is registered by its symbolic
 *  name in the "itk_component" array.
 *
 *  Returns a pointer to the new record.  If anything goes wrong,
 *  this returns NULL, along with an error message in the interpreter.
 * ------------------------------------------------------------------------
 */
static ArchComponent*
Itk_CreateArchComponent(
    Tcl_Interp *interp,            /* interpreter managing the object */
    ArchInfo *info,                /* info associated with mega-widget */
    char *name,                    /* symbolic name for this component */
    ItclClass *iclsPtr,            /* component created in this class */
    Tcl_Command accessCmd)         /* access command for component */
{
    const char *init;
    const char *wname;
    ArchComponent *archComp;
    ArchOption *archOpt;
    Tk_Window tkwin;
    Tcl_HashEntry *entry;
    Tcl_HashSearch place;

    /*
     *  Save this component in the itk_component() array.
     */
    wname = Tcl_GetCommandName(interp, accessCmd);
    Tcl_SetVar2(interp, "itk_component", name, (char *)wname, 0);

    /*
     *  If the symbolic name for the component is "hull", then this
     *  is the toplevel or frame that embodies a mega-widget.  Update
     *  the Archtype info to include the window token.
     */
    tkwin = Tk_NameToWindow(interp, (char *)wname, Tk_MainWindow(interp));

    if (strcmp(name, "hull") == 0) {
        if (tkwin == NULL) {
            Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                    "cannot find hull window with access command \"",
		    wname, "\"", (char*)NULL);
            return NULL;
        }
        info->tkwin = tkwin;

        /*
         *  We are now in a position to query configuration options
         *  relative to this window.  Scan through all existing options
         *  and update the initial values according to the X11 resource
         *  database.
         */
        entry = Tcl_FirstHashEntry(&info->options, &place);
        while (entry) {
            archOpt = (ArchOption*)Tcl_GetHashValue(entry);

            init = NULL;
            if ((archOpt->resName != NULL) && (archOpt->resClass != NULL)) {
                init = Tk_GetOption(tkwin, archOpt->resName, archOpt->resClass);
            }

            if (init &&
	            (!archOpt->init || (strcmp(init, archOpt->init) != 0))) {
                if (!archOpt->init) {
                    ckfree(archOpt->init);
                }
                archOpt->init = (char*)ckalloc((unsigned)(strlen(init)+1));
                strcpy(archOpt->init, init);

                if (Itk_ArchSetOption(interp, info,
                        archOpt->switchName, init) != TCL_OK) {
                    return NULL;
                }
            }
            entry = Tcl_NextHashEntry(&place);
        }
    }

    /*
     *  Create the record to represent this component.
     */
    archComp = (ArchComponent*)ckalloc(sizeof(ArchComponent));

    memset(archComp, 0, sizeof(ArchComponent));
    archComp->namePtr = Tcl_NewStringObj(name, -1);
    Tcl_IncrRefCount(archComp->namePtr);
    archComp->iclsPtr     = iclsPtr;
    archComp->protection  = ITCL_PUBLIC;
    archComp->accessCmd  = accessCmd;
    archComp->tkwin      = tkwin;
    archComp->pathName   = (char *) ckalloc((unsigned)(strlen(wname)+1));
    strcpy(archComp->pathName, wname);

    return archComp;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_DelArchComponent()
 *
 *  Destroys an Archetype component record previously created by
 *  Itk_CreateArchComponent().
 * ------------------------------------------------------------------------
 */
static void
Itk_DelArchComponent(
    ArchComponent *archComp)  /* pointer to component data */
{
#ifdef NOTDEF
    ckfree((char*)archComp->member);
#endif
    ckfree((char*)archComp->pathName);
    ckfree((char*)archComp);
}


/*
 * ------------------------------------------------------------------------
 *  Itk_GetArchOption()
 *
 *  Finds or creates the data representing a composite configuration
 *  option for an Archetype mega-widget.  Each option acts as a single
 *  entity, but is composed of several parts which propagate changes
 *  down to the component widgets.  If the option already exists, then
 *  the specified resource name and resource class must match the
 *  existing definition.
 *
 *  If the option is created, an initial value for is determined by
 *  querying the X11 resource database, and if this fails, the
 *  hard-wired default value is used.
 *
 *  If successful, returns TCL_OK along with a pointer to the option
 *  record.  Returns TCL_ERROR (along with an error message in the
 *  interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */
static int
Itk_GetArchOption(
    Tcl_Interp *interp,            /* interpreter managing the object */
    ArchInfo *info,                /* info for Archetype mega-widget */
    char *switchName,              /* name of command-line switch */
    char *resName,                 /* resource name in X11 database */
    char *resClass,                /* resource class name in X11 database */
    const char *defVal,            /* last-resort default value */
    char *currVal,                 /* current option value */
    ArchOption **aoPtr)            /* returns: option record */
{
    int result = TCL_OK;

    int newEntry;
    char *name;
    ArchOption *archOpt;
    Tcl_HashEntry *entry;

    /*
     *  If the switch does not have a leading "-", add it on.
     */
    if (*switchName != '-') {
        name = (char *)ckalloc((unsigned)(strlen(switchName)+2));
        *name = '-';
        strcpy(name+1, switchName);
    } else {
        name = switchName;
    }

    /*
     *  See if an option already exists with the switch name.
     *  If it does, then make sure that the given resource name
     *  and resource class match the existing definition.
     */
    entry = Tcl_CreateHashEntry(&info->options, name, &newEntry);
    if (!newEntry) {
        archOpt = (ArchOption*)Tcl_GetHashValue(entry);

        if (resName && !archOpt->resName) {
            archOpt->resName = (char*)ckalloc((unsigned)(strlen(resName)+1));
            strcpy(archOpt->resName, resName);
        }
        else if (resName && strcmp(archOpt->resName, resName) != 0) {
            Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                "bad resource name \"", resName, "\" for option \"",
                name, "\": should be \"", archOpt->resName, "\"",
                (char*)NULL);
            result = TCL_ERROR;
            goto getArchOptionDone;
        }

        if (resClass && !archOpt->resClass) {
            archOpt->resClass = (char*)ckalloc((unsigned)(strlen(resClass)+1));
            strcpy(archOpt->resClass, resClass);
        } else {
	    if (resClass && strcmp(archOpt->resClass, resClass) != 0) {
                Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
                    "bad resource class \"", resClass, "\" for option \"",
                    name, "\": should be \"", archOpt->resClass, "\"",
                    (char*)NULL);
                result = TCL_ERROR;
                goto getArchOptionDone;
	    }
        }

        if (!archOpt->init) {
            Itk_InitArchOption(interp, info, archOpt, defVal, currVal);
        }
        *aoPtr = archOpt;

        result = TCL_OK;
        goto getArchOptionDone;
    }

    /*
     *  Create the record to represent this option, and save it
     *  in the option table.
     */
    archOpt = (ArchOption*)ckalloc(sizeof(ArchOption));

    archOpt->switchName = (char*)ckalloc((unsigned)(strlen(name)+1));
    strcpy(archOpt->switchName, name);

    if (resName) {
        archOpt->resName = (char*)ckalloc((unsigned)(strlen(resName)+1));
        strcpy(archOpt->resName, resName);
    } else {
        archOpt->resName = NULL;
    }

    if (resClass) {
        archOpt->resClass = (char*)ckalloc((unsigned)(strlen(resClass)+1));
        strcpy(archOpt->resClass, resClass);
    } else {
        archOpt->resClass = NULL;
    }

    archOpt->flags = 0;
    Itcl_InitList(&archOpt->parts);

    archOpt->init = NULL;
    Itk_InitArchOption(interp,info,archOpt,defVal,currVal);

    Tcl_SetHashValue(entry, (ClientData)archOpt);
    Itk_OptListAdd(&info->order, entry);

    *aoPtr = archOpt;

getArchOptionDone:
    if (name != switchName) {
        ckfree(name);
    }
    return result;
}

/*
 * ------------------------------------------------------------------------
 *  Itk_InitArchOption()
 *
 *  Sets the initial value for a composite configuration option for
 *  an Archetype mega-widget.  This is usually invoked when an option
 *  is first created by Itk_GetArchOption().  It queries the X11
 *  resource database for an initial value, and if nothing is found,
 *  falls back on a last-resort value.  It stores the initial value
 *  in the "itk_option" array, adds a copy to the option info, and
 *  returns.
 *
 *  If successful, returns TCL_OK along with a pointer to the option
 *  record.  Returns TCL_ERROR (along with an error message in the
 *  interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */
static void
Itk_InitArchOption(
    Tcl_Interp *interp,            /* interpreter managing the object */
    ArchInfo *info,                /* info for Archetype mega-widget */
    ArchOption *archOpt,           /* option to initialize */
    const char *defVal,            /* last-resort default value */
    char *currVal)                 /* current option value */
{
    const char *init = NULL;
    const char *ival;
    char c;

    /*
     *  If the option is already initialized, then abort.
     */
    if (archOpt->init) {
        return;
    }

    /*
     *  If this widget has a Tk window, query the X11 resource
     *  database for an initial option value.  If all else fails,
     *  use the hard-wired default value.
     */
    if (archOpt->resName && archOpt->resClass && info->tkwin != NULL) {
        init = Tk_GetOption(info->tkwin, archOpt->resName, archOpt->resClass);
    }
    if (init == NULL) {
        init = defVal;
    }

    /*
     *  Normally, the initial value for the itk_option array is
     *  the same as the initial value for the option.  Watch
     *  out for the fixed Tk options (-class, -colormap, -screen
     *  and -visual).  Since these cannot be modified later,
     *  they must be set to their current value.
     */
    c = *(archOpt->switchName+1);

    if ((c == 'c' && strcmp(archOpt->switchName,"-class") == 0) ||
        (c == 'c' && strcmp(archOpt->switchName,"-colormap") == 0) ||
        (c == 's' && strcmp(archOpt->switchName,"-screen") == 0) ||
        (c == 'v' && strcmp(archOpt->switchName,"-visual") == 0)) {
        ival = currVal;
    } else {
        ival = init;
    }

    Tcl_SetVar2(interp, "itk_option", archOpt->switchName,
            (char *)((ival) ? ival : ""), 0);

    if (ival) {
        archOpt->init = (char*)ckalloc((unsigned)(strlen(ival)+1));
        strcpy(archOpt->init, ival);
    }
}

/*
 * ------------------------------------------------------------------------
 *  Itk_DelArchOption()
 *
 *  Destroys an Archetype configuration option previously created by
 *  Itk_CreateArchOption().
 * ------------------------------------------------------------------------
 */
static void
Itk_DelArchOption(
    ArchOption *archOpt)  /* pointer to option data */
{
    Itcl_ListElem *elem;
    ArchOptionPart *optPart;

    /*
     *  Delete all "parts" relating to component widgets.
     */
    elem = Itcl_FirstListElem(&archOpt->parts);
    while (elem) {
        optPart = (ArchOptionPart*)Itcl_GetListValue(elem);
        Itk_DelOptionPart(optPart);
        elem = Itcl_DeleteListElem(elem);
    }

    /*
     *  Free any remaining data.
     */
    ckfree(archOpt->switchName);
    if (archOpt->resName) {
        ckfree(archOpt->resName);
    }
    if (archOpt->resClass) {
        ckfree(archOpt->resClass);
    }
    if (archOpt->init) {
        ckfree(archOpt->init);
    }
    ckfree((char*)archOpt);
}


/*
 * ------------------------------------------------------------------------
 *  Itk_CreateOptionPart()
 *
 *  Creates the data representing a part within a configuration option
 *  for an Archetype mega-widget.  Each part has a bit of code used to
 *  apply configuration changes to some part of the mega-widget.
 *  This is characterized by a bit of ClientData, and a "config"
 *  procedure that knows how to execute it.  The ClientData is
 *  automatically disposed of by the delete proc when this option
 *  part is destroyed.
 *
 *  Option parts typically come from two sources:  Options defined
 *  in the class definition, and options propagated upward from
 *  component parts.
 *
 *  Returns a pointer to the new option part.
 * ------------------------------------------------------------------------
 */
ArchOptionPart*
Itk_CreateOptionPart(
    Tcl_Interp *interp,              /* interpreter handling this request */
    ClientData cdata,                /* data representing this part */
    Itk_ConfigOptionPartProc *cproc, /* proc used to apply config changes */
    Tcl_CmdDeleteProc *dproc,        /* proc used to clean up ClientData */
    ClientData from)                 /* who contributed this option */
{
    ArchOptionPart *optPart;

    /*
     *  Create the record to represent this part of the option.
     */
    optPart = (ArchOptionPart*)ckalloc(sizeof(ArchOptionPart));
    optPart->clientData = cdata;
    optPart->configProc = cproc;
    optPart->deleteProc = dproc;
    optPart->from       = from;

    return optPart;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_AddOptionPart()
 *
 *  Integrates an option part into a composite configuration option
 *  for an Archetype mega-widget.  If a composite option does not
 *  yet exist with the specified switch name, it is created automatically.
 *
 *  Adds the option part onto the composite list, and reconfigures
 *  the widget to update this option properly.
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error message
 *  in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */
int
Itk_AddOptionPart(
    Tcl_Interp *interp,              /* interpreter handling this request */
    ArchInfo *info,                  /* info for Archetype mega-widget */
    char *switchName,                /* name of command-line switch */
    char *resName,                   /* resource name in X11 database */
    char *resClass,                  /* resource class name in X11 database */
    const char *defVal,              /* last-resort default value */
    char *currVal,                   /* current value (or NULL) */
    ArchOptionPart *optPart,         /* part to be added in */
    ArchOption **raOpt)              /* returns: option containing new part */
{
    const char *init = NULL;
    int result;
    ArchOption *archOpt;
    Itcl_ListElem *elemPtr;

    *raOpt = NULL;
    archOpt = NULL;

    /*
     *  Find or create a composite option for the mega-widget.
     */
    result = Itk_GetArchOption(interp, info, switchName, resName, resClass,
        defVal, currVal, &archOpt);

    if (result != TCL_OK) {
        return TCL_ERROR;
    }

    /*
     *  Add the option part to the composite option.  If the
     *  composite option has already been configured, then
     *  simply update this part to the current value.  Otherwise,
     *  leave the configuration to Itk_ArchInitCmd().
     */
    elemPtr = Itcl_AppendList(&archOpt->parts, (ClientData)optPart);

    if ((archOpt->flags & ITK_ARCHOPT_INIT) != 0) {

        if (result == TCL_OK) {
            init = Tcl_GetVar2(interp, "itk_option", archOpt->switchName, 0);
        }

        if (!init) {
            Itk_ArchOptAccessError(interp, info, archOpt);
	    Itcl_DeleteListElem(elemPtr);
            return TCL_ERROR;
        }

        if (!currVal || (strcmp(init,currVal) != 0)) {
            result  = (*optPart->configProc)(interp, info->itclObj,
                optPart->clientData, init);

            if (result != TCL_OK) {
                Itk_ArchOptConfigError(interp, info, archOpt);
		Itcl_DeleteListElem(elemPtr);
                return TCL_ERROR;
            }
        }
    }

    *raOpt = archOpt;
    return TCL_OK;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_FindArchOptionPart()
 *
 *  Searches for a specific piece of a composite configuration option
 *  for an Archetype mega-widget.  The specified name is treated as the
 *  "switch" name (e.g., "-option"), but this procedure will recognize
 *  it even without the leading "-".
 *
 *  Returns a pointer to the option with the matching switch name and
 *  source, or NULL if the option is not recognized.
 * ------------------------------------------------------------------------
 */
ArchOptionPart*
Itk_FindArchOptionPart(
    ArchInfo *info,                /* info for Archetype mega-widget */
    char *switchName,              /* name of command-line switch */
    ClientData from)               /* who contributed this option */
{
    ArchOptionPart *optPart = NULL;

    char *name;
    Tcl_HashEntry *entry;
    ArchOption *archOpt;
    ArchOptionPart *op;
    Itcl_ListElem *elem;

    /*
     *  If the switch does not have a leading "-", add it on.
     */
    if (*switchName != '-') {
        name = (char *)ckalloc((unsigned)(strlen(switchName)+2));
        *name = '-';
        strcpy(name+1, switchName);
    } else {
        name = switchName;
    }

    /*
     *  Look for a composite option, and then for a part with the
     *  matching source.
     */
    entry = Tcl_FindHashEntry(&info->options, name);

    if (entry) {
        archOpt = (ArchOption*)Tcl_GetHashValue(entry);
        elem = Itcl_FirstListElem(&archOpt->parts);
        while (elem) {
            op = (ArchOptionPart*)Itcl_GetListValue(elem);
            if (op->from == from) {
                optPart = op;
                break;
            }
            elem = Itcl_NextListElem(elem);
        }
    }

    if (name != switchName) {
        ckfree(name);
    }
    return optPart;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_RemoveArchOptionPart()
 *
 *  Searches for a specific piece of a composite configuration option
 *  for an Archetype mega-widget.  The specified name is treated as the
 *  "switch" name (e.g., "-option"), but this procedure will recognize
 *  it even without the leading "-".  If an option part with the
 *  specified name and source is found on the list, it is removed.
 *
 *  NOTE:  This procedure assumes that there is a valid object context
 *    and a call frame supporting object data member access.  It is
 *    usually called from within the methods of the Archetype base
 *    class, so this is a good assumption.  If it is called anywhere
 *    else, the caller is responsible for installing the object context
 *    and setting up a call frame.
 *
 *  Returns non-zero if the part was found and removed, and 0 otherwise.
 * ------------------------------------------------------------------------
 */
static int
Itk_RemoveArchOptionPart(
    ArchInfo *info,                /* info for Archetype mega-widget */
    char *switchName,              /* name of command-line switch */
    ClientData from)               /* who contributed this option */
{
    int result = 0;

    char *name;
    Tcl_HashEntry *entry;
    ArchOption *archOpt;
    ArchOptionPart *op;
    Itcl_ListElem *elem;


    /*
     *  If the switch does not have a leading "-", add it on.
     */
    if (*switchName != '-') {
        name = (char *)ckalloc(strlen(switchName)+2);
        *name = '-';
        strcpy(name+1, switchName);
    } else {
        name = switchName;
    }

    /*
     *  Look for a composite option, and then for a part with the
     *  matching source.  If found, remove it.
     */
    entry = Tcl_FindHashEntry(&info->options, name);

    if (entry) {
        archOpt = (ArchOption*)Tcl_GetHashValue(entry);
        elem = Itcl_FirstListElem(&archOpt->parts);
        while (elem) {
            op = (ArchOptionPart*)Itcl_GetListValue(elem);
            if (op->from == from) {
                Itk_DelOptionPart(op);
                result = 1;
                elem = Itcl_DeleteListElem(elem);
            }
            else {
                elem = Itcl_NextListElem(elem);
            }
        }

        /*
         *  If this option is now dead (no parts left), then
         *  remove it from the widget.  Be careful to delete it
         *  from the "itk_option" array as well.
         */
        if (Itcl_GetListLength(&archOpt->parts) == 0) {
            Tcl_UnsetVar2(info->itclObj->iclsPtr->interp,
                "itk_option", archOpt->switchName, 0);

            Itk_DelArchOption(archOpt);
            Itk_OptListRemove(&info->order, entry);
            Tcl_DeleteHashEntry(entry);
        }
    }

    if (name != switchName) {
        ckfree(name);
    }
    return result;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_IgnoreArchOptionPart()
 *
 *  Removes the specified part from a composite configuration option
 *  for an Archetype mega-widget.  This is usually called before
 *  keeping or renaming an option, to make sure that the option
 *  is not already integrated elsewhere on the composite list.
 *  This also handles the action of "ignoring" a configuration option.
 *
 *  NOTE:  This procedure assumes that there is a valid object context
 *    and a call frame supporting object data member access.  It is
 *    usually called from within the methods of the Archetype base
 *    class, so this is a good assumption.  If it is called anywhere
 *    else, the caller is responsible for installing the object context
 *    and setting up a call frame.
 *
 *  Returns non-zero if the part was found and removed, and 0 otherwise.
 * ------------------------------------------------------------------------
 */
static int
Itk_IgnoreArchOptionPart(
    ArchInfo *info,                /* info for Archetype mega-widget */
    GenericConfigOpt *opt)         /* part to be ignored */
{
    int result = 0;

    Tcl_HashEntry *entry;
    ArchOptionPart *op;
    Itcl_ListElem *elem;

    /*
     *  If the part is not integrated, then do nothing.
     *  Otherwise, find the missing part and remove it.
     */
    if (opt->integrated) {
        elem = Itcl_FirstListElem(&opt->integrated->parts);
        while (elem) {
            op = (ArchOptionPart*)Itcl_GetListValue(elem);
            if (op == opt->optPart) {
                Itk_DelOptionPart(op);
                result = 1;
                elem = Itcl_DeleteListElem(elem);
            }
            else {
                elem = Itcl_NextListElem(elem);
            }
        }

        /*
         *  If this option is now dead (no parts left), then
         *  remove it from the widget.  Be careful to delete it
         *  from the "itk_option" array as well.
         */
        if (Itcl_GetListLength(&opt->integrated->parts) == 0) {
            Tcl_UnsetVar2(info->itclObj->iclsPtr->interp,
                "itk_option", opt->integrated->switchName, 0);

            entry = Tcl_FindHashEntry(&info->options,
                opt->integrated->switchName);

            if (entry) {
                Itk_OptListRemove(&info->order, entry);
                Tcl_DeleteHashEntry(entry);
            }
            Itk_DelArchOption(opt->integrated);
        }

        /*
         *  Forget that this part was ever integrated.
         */
        opt->integrated = NULL;
        opt->optPart = NULL;
    }
    return result;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_DelOptionPart()
 *
 *  Destroys part of an Archetype configuration option created by
 *  Itk_CreateOptionPart().
 * ------------------------------------------------------------------------
 */
void
Itk_DelOptionPart(
    ArchOptionPart *optPart)  /* option part data to be destroyed */
{
    if (optPart->clientData && optPart->deleteProc) {
        (*optPart->deleteProc)(optPart->clientData);
    }
    ckfree((char*)optPart);
}


/*
 * ------------------------------------------------------------------------
 *  Itk_CreateConfigCmdline()
 *
 *  Creates the data representing a command line for a "configure"
 *  operation.  Each "configure" command has the following form:
 *
 *      <object> configure -<option> <value>
 *
 *  The first three arguments are created in this procedure.  The
 *  <value> argument is reinitialized each time the command is
 *  executed.
 *
 *  Returns a pointer to the new command record.
 * ------------------------------------------------------------------------
 */
static ConfigCmdline*
Itk_CreateConfigCmdline(
    Tcl_Interp *interp,              /* interpreter handling this request */
    Tcl_Command accessCmd,           /* command for <object> being config'd */
    char *switchName)                /* switch name of option being config'd */
{
    int i;
    ConfigCmdline *cmdlinePtr;
    Tcl_Obj *objPtr;

    /*
     *  Create the record to represent this part of the option.
     */
    cmdlinePtr = (ConfigCmdline*)ckalloc(sizeof(ConfigCmdline));
    memset(cmdlinePtr, 0, sizeof(ConfigCmdline));

    objPtr = Tcl_NewStringObj((char*)NULL, 0);
    Tcl_GetCommandFullName(interp, accessCmd, objPtr);
    cmdlinePtr->objv[0] = objPtr;
    cmdlinePtr->objv[1] = Tcl_NewStringObj("configure", -1);
    cmdlinePtr->objv[2] = Tcl_NewStringObj(switchName, -1);

    for (i=0; i < 3; i++) {
        Tcl_IncrRefCount(cmdlinePtr->objv[i]);
    }
    return cmdlinePtr;
}

/*
 * ------------------------------------------------------------------------
 *  Itk_DeleteConfigCmdline()
 *
 *  Deletes the data created by Itk_CreateConfigCmdline.  Called
 *  when an option part is deleted to free up the memory associated
 *  with the configure command.
 * ------------------------------------------------------------------------
 */
static void
Itk_DeleteConfigCmdline(
    ClientData cdata)                /* command to be freed */
{
    ConfigCmdline *cmdlinePtr = (ConfigCmdline*)cdata;
    int i;

    /*
     *  TRICKY NOTE:  Decrement the reference counts for only the
     *    first three arguments on the command line.  The fourth
     *    argument is released after each configure operation.
     */
    for (i=0; i < 3; i++) {
        Tcl_DecrRefCount(cmdlinePtr->objv[i]);
    }
    ckfree((char*)cmdlinePtr);
}


/*
 * ------------------------------------------------------------------------
 *  Itk_CreateGenericOptTable()
 *
 *  Parses a string describing a widget's configuration options (of the
 *  form returned by the usual widget "configure" method) and creates
 *  a hash table for easy lookup of option information.  Entries in
 *  the hash table are indexed by switch names like "-background".
 *  Values are GenericConfigOpt records.  Alias options like "-bg" are
 *  ignored.
 *
 *  This table is used by option parsing commands in "itk::option-parser"
 *  to validate widget options.
 *
 *  Returns a pointer to a new hash table, which should later be freed
 *  via Itk_DelGenericOptTable().  Returns NULL if an error is found in
 *  the configuration list.
 * ------------------------------------------------------------------------
 */
static Tcl_HashTable*
Itk_CreateGenericOptTable(
    Tcl_Interp *interp,          /* interpreter handling this request */
    const char *options)               /* string description of config options */
{
    int confc;
    const char **confv = NULL;
    int optc;
    const char **optv = NULL;

    int i, newEntry;
    Tcl_HashTable *tPtr;
    Tcl_HashEntry *entry;
    GenericConfigOpt *info;

    tPtr = (Tcl_HashTable*)ckalloc(sizeof(Tcl_HashTable));
    Tcl_InitHashTable(tPtr, TCL_STRING_KEYS);

    /*
     *  Split the list of options and store each one in the table.
     *  Only consider options with all 5 required components.  Avoid
     *  aliases like "-bg".
     */
    if (Tcl_SplitList(interp, options, &confc, &confv) != TCL_OK) {
        goto tableFail;
    }
    for (i=0; i < confc; i++) {
        if (Tcl_SplitList(interp, confv[i], &optc, &optv) != TCL_OK) {
            goto tableFail;
        }
        if (optc == 5) {    /* avoid aliased options */
            entry = Tcl_CreateHashEntry(tPtr, optv[0], &newEntry);
            if (newEntry) {
                info = (GenericConfigOpt*)ckalloc(sizeof(GenericConfigOpt));
                info->switchName = (char *)optv[0];
                info->resName    = (char *)optv[1];
                info->resClass   = (char *)optv[2];
                info->init       = (char *)optv[3];
                info->value      = (char *)optv[4];
                info->storage    = (char **)optv;
                info->integrated = NULL;
                info->optPart    = NULL;
                Tcl_SetHashValue(entry, (ClientData)info);
            }
        }
        else {
            ckfree((char*)optv);
        }
    }

    ckfree((char*)confv);
    return tPtr;

tableFail:
    if (confv) {
        ckfree((char*)confv);
    }
    Itk_DelGenericOptTable(tPtr);
    return NULL;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_DelGenericOptTable()
 *
 *  Destroys an option table previously created by
 *  Itk_CreateGenericOptTable() and frees all memory associated with it.
 *  Should be called whenever a table is no longer needed, to free up
 *  resources.
 * ------------------------------------------------------------------------
 */
static void
Itk_DelGenericOptTable(
    Tcl_HashTable *tPtr)  /* option table to be destroyed */
{
    Tcl_HashEntry *entry;
    Tcl_HashSearch place;
    GenericConfigOpt *info;

    /*
     *  Scan through all options in the table and free entries.
     */
    entry = Tcl_FirstHashEntry(tPtr, &place);
    while (entry) {
        info = (GenericConfigOpt*)Tcl_GetHashValue(entry);
        ckfree((char*)info->storage);
        ckfree((char*)info);
        entry = Tcl_NextHashEntry(&place);
    }

    Tcl_DeleteHashTable(tPtr);
    ckfree((char*)tPtr);
}


/*
 * ------------------------------------------------------------------------
 *  Itk_CreateGenericOpt()
 *
 *  Parses a string describing a widget's configuration option (of the
 *  form returned by the usual widget "configure" method) and creates
 *  a representation for one option.  Similar to
 *  Itk_CreateGenericOptTable(), but only handles one option at a
 *  time.
 *
 *  Returns a pointer to the option info, which should later be freed
 *  via Itk_DelGenericOpt().  Returns NULL (along with an error
 *  message in the interpreter) if an error is found.
 *
 *  SIDE EFFECT:  Resets the interpreter result.
 * ------------------------------------------------------------------------
 */
static GenericConfigOpt*
Itk_CreateGenericOpt(
    Tcl_Interp *interp,          /* interpreter handling this request */
    const char *switchName,      /* command-line switch for option */
    Tcl_Command accessCmd)       /* access command for component */
{
    GenericConfigOpt *genericOpt = NULL;
    Tcl_Obj *codePtr = NULL;

    int optc, result;
    const char **optv;
    char *name;
    const char *my_name;
    char *info;
    Tcl_Obj *resultPtr;

    /*
     *  If the switch does not have a leading "-", add it on.
     */
    if (*switchName != '-') {
        name = (char *)ckalloc((unsigned)(strlen(switchName)+2));
        *name = '-';
        strcpy(name+1, switchName);
	my_name = name;
    } else {
        my_name = switchName;
    }

    /*
     *  Build a "configure" command to query info for the requested
     *  option.  Evaluate the command and get option info.
     */
    codePtr = Tcl_NewStringObj((char*)NULL, 0);
    Tcl_IncrRefCount(codePtr);

    Tcl_GetCommandFullName(interp, accessCmd, codePtr);
    Tcl_AppendToObj(codePtr, " configure ", -1);
    Tcl_AppendToObj(codePtr, my_name, -1);

    if (Tcl_EvalObj(interp, codePtr) != TCL_OK) {
        goto optionDone;
    }

    /*
     *  Only consider options with all 5 required components.  Avoid
     *  aliases like "-bg".
     */
    resultPtr = Tcl_GetObjResult(interp);
    Tcl_IncrRefCount(resultPtr);
    info = Tcl_GetStringFromObj(resultPtr, (int*)NULL);

    result = Tcl_SplitList(interp, info, &optc, &optv);

    Tcl_DecrRefCount(resultPtr);

    if (result != TCL_OK) {
        goto optionDone;
    }
    if (optc == 5) {    /* avoid aliased options */
        genericOpt = (GenericConfigOpt*)ckalloc(sizeof(GenericConfigOpt));
        genericOpt->switchName = (char *)optv[0];
        genericOpt->resName    = (char *)optv[1];
        genericOpt->resClass   = (char *)optv[2];
        genericOpt->init       = (char *)optv[3];
        genericOpt->value      = (char *)optv[4];
        genericOpt->storage    = (char **)optv;
        genericOpt->integrated = NULL;
        genericOpt->optPart    = NULL;
    }
    else {
        ckfree((char*)optv);
    }

optionDone:
    if (my_name != switchName) {
        ckfree((char *)my_name);
    }
    if (codePtr) {
        Tcl_DecrRefCount(codePtr);
    }
    if (genericOpt) {
        Tcl_ResetResult(interp);
    }
    return genericOpt;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_DelGenericOpt()
 *
 *  Destroys a generic option previously created by Itk_CreateGenericOpt()
 *  and frees all memory associated with it.  Should be called whenever
 *  an option representation is no longer needed, to free up resources.
 * ------------------------------------------------------------------------
 */
static void
Itk_DelGenericOpt(
    GenericConfigOpt *opt)  /* option info to be destroyed */
{
    ckfree((char*)opt->storage);
    ckfree((char*)opt);
}

