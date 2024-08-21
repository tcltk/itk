/*
 * ------------------------------------------------------------------------
 *      PACKAGE:  [incr Tk]
 *  DESCRIPTION:  Building mega-widgets with [incr Tcl]
 *
 *  [incr Tk] provides a framework for building composite "mega-widgets"
 *  using [incr Tcl] classes.  It defines a set of base classes that are
 *  specialized to create all other widgets.
 *
 *  This file defines procedures used to manage mega-widget options
 *  specified within class definitions.
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
#include "itkInt.h"

/*
 *  FORWARD DECLARATIONS
 */
static char* ItkTraceClassDestroy (void *cdata,
    Tcl_Interp *interp, const char *name1, const char *name2, int flags);
static Tcl_HashTable* ItkGetClassesWithOptInfo (
    Tcl_Interp *interp);
static void ItkFreeClassesWithOptInfo (void *cdata,
    Tcl_Interp *interp);


/*
 * ------------------------------------------------------------------------
 *  Itk_ClassOptionDefineCmd()
 *
 *  Invoked when a class definition is being parse to handle an
 *  itk_option declaration.  Adds a new option to a mega-widget
 *  declaration, with some code that will be executed whenever the
 *  option is changed via "configure".  If there is already an existing
 *  option by that name, then this new option is folded into the
 *  existing option, but the <init> value is ignored.  The X11 resource
 *  database names must be consistent with the existing option.
 *
 *  Handles the following syntax:
 *
 *      itk_option define <switch> <resName> <resClass> <init> ?<config>?
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
Itk_ClassOptionDefineCmd(
    void *clientData,        /* class parser info */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *const objv[])   /* argument objects */
{
    ItclObjectInfo *info = (ItclObjectInfo*)clientData;
    ItclClass *iclsPtr = (ItclClass*)Itcl_PeekStack(&info->clsStack);

    int newEntry;
    const char *switchName;
    const char *resName;
    const char *resClass;
    const char *init;
    const char *config;
    ItkClassOptTable *optTable;
    Tcl_HashEntry *entry;
    ItkClassOption *opt;

    ItclShowArgs(1, "Itk_ClassOptionDefineCmd", objc, objv);
    /*
     *  Make sure that the arguments look right.  The option switch
     *  name must start with a '-'.
     */
    if (objc < 5 || objc > 6) {
	Tcl_WrongNumArgs(interp, 1, objv,
		"-switch resourceName resourceClass init ?config?");
	return TCL_ERROR;
    }

    switchName = Tcl_GetString(objv[1]);
    if (*switchName != '-') {
	Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
		"bad option name \"", switchName, "\": should be -",
		switchName, (char*)NULL);
	return TCL_ERROR;
    }
    if (strstr(switchName, ".")) {
	Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
		"bad option name \"", switchName,
		"\": illegal character \".\"", (char*)NULL);
	return TCL_ERROR;
    }

    resName = Tcl_GetString(objv[2]);
    if (!islower((int)*resName)) {
	Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
		"bad resource name \"", resName,
		"\": should start with a lower case letter",
		(char*)NULL);
	return TCL_ERROR;
    }

    resClass = Tcl_GetString(objv[3]);
    if (!isupper((int)*resClass)) {
	Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
	       "bad resource class \"", resClass,
	       "\": should start with an upper case letter",
	       (char*)NULL);
	return TCL_ERROR;
    }

    if (iclsPtr == NULL) {
	Tcl_AppendResult(interp, "can only handle options on class level",
		NULL);
	return TCL_ERROR;
    }
    /*
     *  Make sure that this option has not already been defined in
     *  the context of this class.  Options can be redefined in
     *  other classes, but can only be defined once in a given
     *  class.  This ensures that there will be no confusion about
     *  which option is being referenced if the configuration code
     *  is redefined by a subsequent "body" command.
     */
    optTable = Itk_CreateClassOptTable(interp, iclsPtr);
    entry = Tcl_CreateHashEntry(&optTable->options, switchName, &newEntry);

    if (!newEntry) {
	Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
		"option \"", switchName, "\" already defined in class \"",
		Tcl_GetString(iclsPtr->fullNamePtr), "\"",
		(char*)NULL);
	return TCL_ERROR;
    }

    /*
     *  Create a new option record and add it to the table for this
     *  class.
     */
    init = Tcl_GetString(objv[4]);

    if (objc == 6) {
	config = Tcl_GetString(objv[5]);
    } else {
	config = NULL;
    }

    if (Itk_CreateClassOption(interp, iclsPtr, switchName, resName, resClass,
	    init, config, &opt) != TCL_OK) {
	return TCL_ERROR;
    }

    Tcl_SetHashValue(entry, (void *)opt);
    Itk_OptListAdd(&optTable->order, entry);
    return TCL_OK;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_ClassOptionIllegalCmd()
 *
 *  Invoked when a class definition is being parse to handle an
 *  itk_option declaration.  Handles an "illegal" declaration like
 *  "add" or "remove", which can only be used after a widget has
 *  been created.  Returns TCL_ERROR along with an error message.
 * ------------------------------------------------------------------------
 */
int
Itk_ClassOptionIllegalCmd(
    void *clientData,        /* class parser info */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *const objv[])   /* argument objects */
{
    char *op = Tcl_GetString(objv[0]);

    Tcl_AppendStringsToObj(Tcl_GetObjResult(interp),
	    "can only ", op, " options for a specific widget\n",
	    "(move this command into the constructor)",
	    (char*)NULL);

    return TCL_ERROR;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_ConfigClassOption()
 *
 *  Invoked whenever a class-based configuration option has been
 *  configured with a new value.  If the option has any extra code
 *  associated with it, the code is invoked at this point to bring
 *  the widget up-to-date.
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */
int
Itk_ConfigClassOption(
    Tcl_Interp *interp,        /* interpreter managing the class */
    ItclObject *contextObj,    /* object being configured */
    void *cdata,          /* class option */
    const char *newval)        /* new value for this option */
{
    ItkClassOption *opt = (ItkClassOption*)cdata;
    int result = TCL_OK;
    ItclMemberCode *mcode;
    Tcl_CallFrame frame;

    /*
     *  If the option has any config code, execute it now.
     *  Make sure that the namespace context is set up correctly.
     */
    mcode = opt->codePtr;
    if (mcode && mcode->bodyPtr) {

	Itcl_PushCallFrame(interp, &frame, opt->iclsPtr->nsPtr, 1);
	Itcl_SetContext(interp, contextObj);

	result = Tcl_EvalObjEx(interp, mcode->bodyPtr, 0);

	Itcl_UnsetContext(interp);
	Itcl_PopCallFrame(interp);

	/*
	 * Here we engage in some ugly hackery workaround until
	 * someone has time to come back and implement this
	 * properly.
	 *
	 * In Itcl/Itk 3, the same machinery was used to implement
	 * method invocation and configbody invocation, and the
	 * code here looked like:
	 *

	result = Itcl_EvalMemberCode(interp, (ItclMemberFunc*)NULL,
	    opt->member, contextObj, 0, (Tcl_Obj**)NULL);

	 *
	 * In Itcl 4, Itcl methods have become (a particular variant)
	 * of TclOO methods.  It's not clear whether config bodies
	 * should also do that, or what?
	 *
	 * Instead the existing solution above has been to just "eval"
	 * the configbody body script in a suitable context, which
	 * works very nearly correctly.  The trouble is that unlike
	 * method invocation, we've not pushed a proper frame, nor
	 * have we unwound a return level, so when the "eval" returns
	 * TCL_RETURN we've not been handling that right.  You will
	 * find some configbody bodies out there that expect to be
	 * able to use [return] for early exit.  Iwidgets test
	 * Extbutton-2.8 is an example.
	 *
	 * As a cheap workaround, we put in explicit special treatment
	 * for (result == TCL_RETURN) here.  This is essentially a
	 * reproduction of the Tcl internal routine TclUpdateReturnInfo()
	 * but without the benefit of internals access.
 	 */

	if (result == TCL_RETURN) {
	    Tcl_Obj *opts = Tcl_GetReturnOptions(interp, TCL_RETURN);
	    Tcl_Obj *levelKey = Tcl_NewStringObj("-level", -1);
	    Tcl_Obj *levelObj;
	    int level;

	    Tcl_DictObjGet(NULL, opts, levelKey, &levelObj);
	    Tcl_GetIntFromObj(NULL, levelObj, &level);

	    Tcl_DictObjPut(NULL, opts, levelKey, Tcl_NewIntObj(--level));
	    result = Tcl_SetReturnOptions(interp, opts);

	    Tcl_DecrRefCount(levelKey);
	}
    }
    return result;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_CreateClassOptTable()
 *
 *  Finds or creates an option table which will contain all of the
 *  class-based configuration options for a mega-widget.  These are
 *  the options included in the class definition which add new behavior
 *  to the mega-widget.
 *
 *  This table is automatically deleted by ItkTraceClassDestroy
 *  whenever the class namespace is destroyed.  The "unset" operation
 *  of a private class variable is used to detect the destruction of
 *  the namespace.
 *
 *  Returns a pointer to an option table which will contain pointers to
 *  ItkClassOption records.
 * ------------------------------------------------------------------------
 */
ItkClassOptTable*
Itk_CreateClassOptTable(
    Tcl_Interp *interp,        /* interpreter managing the class */
    ItclClass *iclsPtr)        /* class definition */
{
    int newEntry, result;
    Tcl_HashTable *itkClasses;
    Tcl_HashEntry *entry;
    ItkClassOptTable *optTable;
    Tcl_CallFrame frame;

    /*
     *  Look for the specified class definition in the table.
     *  If it does not yet exist, then create a new slot for it.
     *  When a table is created for the first time, add a
     *  special sentinel variable "_itk_option_data" to the
     *  class namespace, and put a trace on this variable.
     *  Whenever it is destroyed, have it delete the option table
     *  for this class.
     */
    itkClasses = ItkGetClassesWithOptInfo(interp);

    entry = Tcl_CreateHashEntry(itkClasses, (char*)iclsPtr, &newEntry);
    if (newEntry) {
	optTable = (ItkClassOptTable*)ckalloc(sizeof(ItkClassOptTable));
	Tcl_InitHashTable(&optTable->options, TCL_STRING_KEYS);
	Itk_OptListInit(&optTable->order, &optTable->options);

	Tcl_SetHashValue(entry, (void *)optTable);

	result = Itcl_PushCallFrame(interp, &frame,
	     iclsPtr->nsPtr, /* isProcCallFrame */ 0);

	if (result == TCL_OK) {
	    Tcl_TraceVar(interp, "_itk_option_data",
		    (TCL_TRACE_UNSETS | TCL_NAMESPACE_ONLY),
		    ItkTraceClassDestroy, (void *)iclsPtr);
	    Itcl_PopCallFrame(interp);
	}
    } else {
	optTable = (ItkClassOptTable*)Tcl_GetHashValue(entry);
    }
    return optTable;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_FindClassOptTable()
 *
 *  Looks for an option table containing all of the class-based
 *  configuration options for a mega-widget.  These are the options
 *  included in a class definition which add new behavior to the
 *  mega-widget.
 *
 *  Returns a pointer to an option table which will contain pointers to
 *  Itk_ClassOption records.  If a table does not exist for this class,
 *  this returns NULL.
 * ------------------------------------------------------------------------
 */
ItkClassOptTable*
Itk_FindClassOptTable(
    ItclClass *iclsPtr)          /* class definition */
{
    Tcl_HashTable *itkClasses;
    Tcl_HashEntry *entry;

    /*
     *  Look for the specified class definition in the table.
     */
    itkClasses = ItkGetClassesWithOptInfo(iclsPtr->interp);
    entry = Tcl_FindHashEntry(itkClasses, (char*)iclsPtr);
    if (entry) {
	return (ItkClassOptTable*)Tcl_GetHashValue(entry);
    }
    return NULL;
}


/*
 * ------------------------------------------------------------------------
 *  ItkTraceClassDestroy()
 *
 *  Invoked automatically whenever the "_itk_option_data" variable
 *  is destroyed within a class namespace.  This should be a signal
 *  that the namespace is being destroyed.
 *
 *  Releases any option data that exists for the class.
 *
 *  Returns NULL on success, or a pointer to a string describing any
 *  error that is encountered.
 * ------------------------------------------------------------------------
 */
static char*
ItkTraceClassDestroy(
    void *cdata,          /* class definition data */
    Tcl_Interp *interp,        /* interpreter managing the class */
    const char *name1,       /* name of variable involved in trace */
    const char *name2,       /* name of array element within variable */
    int flags)                 /* flags describing trace */
{
    ItclClass *iclsPtr = (ItclClass*)cdata;

    Tcl_HashTable *itkClasses;
    Tcl_HashEntry *entry;
    ItkClassOptTable *optTable;
    Tcl_HashSearch place;
    ItkClassOption *opt;

    /*
     *  Look for the specified class definition in the table.
     *  If it is found, delete all the option records and tear
     *  down the table.
     */
    itkClasses = ItkGetClassesWithOptInfo(interp);
    entry = Tcl_FindHashEntry(itkClasses, (char*)iclsPtr);
    if (entry) {
	optTable = (ItkClassOptTable*)Tcl_GetHashValue(entry);
	Tcl_DeleteHashEntry(entry);

	entry = Tcl_FirstHashEntry(&optTable->options, &place);
	while (entry) {
	    opt = (ItkClassOption*)Tcl_GetHashValue(entry);
	    Itk_DelClassOption(opt);
	    entry = Tcl_NextHashEntry(&place);
	}
	Tcl_DeleteHashTable(&optTable->options);
	Itk_OptListFree(&optTable->order);
	ckfree((char*)optTable);
    }
    return NULL;
}


/*
 * ------------------------------------------------------------------------
 *  Itk_CreateClassOption()
 *
 *  Creates the data representing a configuration option for an
 *  Archetype mega-widget.  This record represents an option included
 *  in the class definition.  It adds new behavior to the mega-widget
 *  class.
 *
 *  If successful, returns TCL_OK along with a pointer to the option
 *  record.  Returns TCL_ERROR (along with an error message in the
 *  interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */
int
Itk_CreateClassOption(
    Tcl_Interp *interp,            /* interpreter managing the class */
    ItclClass *iclsPtr,            /* class containing this option */
    const char *switchName,        /* name of command-line switch */
    const char *resName,           /* resource name in X11 database */
    const char *resClass,          /* resource class name in X11 database */
    const char *defVal,            /* last-resort default value */
    const char *config,            /* configuration code */
    ItkClassOption **optPtr)       /* returns: option record */
{
    ItkClassOption *opt;
    ItclMemberCode *mcode;

    /*
     *  If this option has any "config" code, then try to create
     *  an implementation for it.
     */
    if (config) {
	if (Itcl_CreateMemberCode(interp, iclsPtr, (char*)NULL, config,
	    &mcode) != TCL_OK) {

	    return TCL_ERROR;
	}
	Itcl_PreserveData((void *)mcode);
#ifdef NOTDEF
	Itcl_EventuallyFree((void *)mcode, (Tcl_FreeProc *)Itcl_DeleteMemberCode);
#endif
    } else {
	mcode = NULL;
    }

    /*
     *  Create the record to represent this option.
     */
    opt = (ItkClassOption*)ckalloc(sizeof(ItkClassOption));
    memset(opt, 0, sizeof(ItkClassOption));
    opt->iclsPtr      = iclsPtr;
    opt->flags        = 0;
    opt->protection   = Itcl_Protection(interp, 0);
    opt->namePtr      = Tcl_NewStringObj(switchName, -1);
    Tcl_IncrRefCount(opt->namePtr);
    opt->fullNamePtr = Tcl_NewStringObj(Tcl_GetString(iclsPtr->fullNamePtr), -1);
    Tcl_AppendToObj(opt->fullNamePtr, "::", 2);
    Tcl_AppendToObj(opt->fullNamePtr, switchName, -1);
    Tcl_IncrRefCount(opt->fullNamePtr);
    opt->codePtr = mcode;

    opt->resName = (char*)ckalloc((strlen(resName)+1));
    strcpy(opt->resName, resName);

    opt->resClass = (char*)ckalloc((strlen(resClass)+1));
    strcpy(opt->resClass, resClass);

    opt->init = (char*)ckalloc((strlen(defVal)+1));
    strcpy(opt->init, defVal);

    *optPtr = opt;
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Itk_FindClassOption()
 *
 *  Searches for a class-based configuration option for an Archetype
 *  mega-widget.   The specified name is treated as the "switch" name
 *  (e.g., "-option"), but this procedure will recognize it even without
 *  the leading "-".
 *
 *  If an option is found that was defined in the specified class,
 *  then this procedure returns a pointer to the option definition.
 *  Otherwise, it returns NULL.
 * ------------------------------------------------------------------------
 */
ItkClassOption*
Itk_FindClassOption(
    ItclClass *iclsPtr,            /* class containing this option */
    const char *switchName)        /* name of command-line switch */
{
    ItkClassOption *opt = NULL;

    Tcl_DString buffer;
    ItkClassOptTable *optTable;
    Tcl_HashEntry *entry;

    /*
     *  If the switch does not have a leading "-", add it on.
     */
    Tcl_DStringInit(&buffer);
    if (*switchName != '-') {
	Tcl_DStringAppend(&buffer, "-", -1);
	Tcl_DStringAppend(&buffer, switchName, -1);
	switchName = Tcl_DStringValue(&buffer);
    }

    /*
     *  Look for the option table for the specified class, and check
     *  for the requested switch.
     */
    optTable = Itk_FindClassOptTable(iclsPtr);
    if (optTable) {
	entry = Tcl_FindHashEntry(&optTable->options, switchName);
	if (entry) {
	    opt = (ItkClassOption*)Tcl_GetHashValue(entry);
	}
    }
    Tcl_DStringFree(&buffer);
    return opt;
}

/*
 * ------------------------------------------------------------------------
 *  Itk_DelClassOption()
 *
 *  Destroys a configuration option previously created by
 *  Itk_CreateClassOption().
 * ------------------------------------------------------------------------
 */
void
Itk_DelClassOption(
    ItkClassOption *opt)  /* pointer to option data */
{
#ifdef NOTDEF
    Itcl_DeleteMember(opt->member);
#endif
    ckfree(opt->resName);
    ckfree(opt->resClass);
    ckfree(opt->init);

    ckfree((char*)opt);
}


/*
 * ------------------------------------------------------------------------
 *  ItkGetClassesWithOptInfo()
 *
 *  Returns a pointer to a hash table containing the list of registered
 *  classes in the specified interpreter.  If the hash table does not
 *  already exist, it is created.
 * ------------------------------------------------------------------------
 */
static Tcl_HashTable*
ItkGetClassesWithOptInfo(
    Tcl_Interp *interp)  /* interpreter handling this registration */
{
    Tcl_HashTable* classesTable;

    /*
     *  If the registration table does not yet exist, then create it.
     */
    classesTable = (Tcl_HashTable*)Tcl_GetAssocData(interp,
	"itk_classesWithOptInfo", (Tcl_InterpDeleteProc**)NULL);

    if (!classesTable) {
	classesTable = (Tcl_HashTable*)ckalloc(sizeof(Tcl_HashTable));
	Tcl_InitHashTable(classesTable, TCL_ONE_WORD_KEYS);
	Tcl_SetAssocData(interp, "itk_classesWithOptInfo",
	    ItkFreeClassesWithOptInfo, (void *)classesTable);
    }
    return classesTable;
}

/*
 * ------------------------------------------------------------------------
 *  ItkFreeClassesWithOptInfo()
 *
 *  When an interpreter is deleted, this procedure is called to
 *  free up the associated data created by ItkGetClassesWithOptInfo.
 * ------------------------------------------------------------------------
 */
static void
ItkFreeClassesWithOptInfo(
    void *clientData,       /* associated data */
    Tcl_Interp *interp)          /* interpreter being freed */
{
    Tcl_HashTable *tablePtr = (Tcl_HashTable*)clientData;
    Tcl_HashSearch place;
    Tcl_HashSearch place2;
    Tcl_HashEntry *entry;
    Tcl_HashEntry *entry2;
    ItkClassOptTable *optTable;
    ItkClassOption *opt;

    entry = Tcl_FirstHashEntry(tablePtr, &place);
    while (entry) {
	optTable = (ItkClassOptTable*)Tcl_GetHashValue(entry);

	entry2 = Tcl_FirstHashEntry(&optTable->options, &place2);
	while (entry2) {
	    opt = (ItkClassOption*)Tcl_GetHashValue(entry2);
	    Itk_DelClassOption(opt);
	    entry2 = Tcl_NextHashEntry(&place2);
	}
	Tcl_DeleteHashTable(&optTable->options);
	Itk_OptListFree(&optTable->order);
	ckfree((char*)optTable);

	entry = Tcl_NextHashEntry(&place);
    }

    Tcl_DeleteHashTable(tablePtr);
    ckfree((char*)tablePtr);
}
