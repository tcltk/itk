/*
 * tclGLBase.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLBase.c,v 1.1.2.3 2007/11/11 00:54:11 wiede Exp $
 */

#include <stdlib.h>
#include "tclGLInt.h"
#include "tclGLDefineSizes.h"
#include "tclGLFuncSizes.h"
//#include "tclGLTypedefSizes.h"

typedef struct TclGLStubAPI {
int i;
} TclGLStubAPI;
struct TclGLStubAPI tclGLStubAPI;

/*
 * ------------------------------------------------------------------------
 *  InitDefineGroup()
 *
 *      put a define defineGroup info into the hashTable
 * ------------------------------------------------------------------------
 */

static Tcl_Obj*
InitDefineGroup (
    Tcl_Interp *interp,
    TclGLInfo *infoPtr,
    int groupNo,
    const char *name)
{
    Tcl_HashEntry *hPtr;
    Tcl_Obj *objPtr;
    TclGLDefineGroup *defineGroupPtr;
    int isNew;

    objPtr = Tcl_NewStringObj(name, -1);
    defineGroupPtr = (TclGLDefineGroup *)ckalloc(sizeof(TclGLDefineGroup));
    defineGroupPtr->defineGroupNo = groupNo;
    defineGroupPtr->defineGroupNamePtr = objPtr;
    Tcl_IncrRefCount(defineGroupPtr->defineGroupNamePtr);
    hPtr = Tcl_CreateHashEntry(&infoPtr->defineGroups, (char *)objPtr, &isNew);
    Tcl_SetHashValue(hPtr, defineGroupPtr);
    return objPtr;
}
/*
 * ------------------------------------------------------------------------
 *  InitDefine()
 *
 *      put a define info into the hashTable
 * ------------------------------------------------------------------------
 */

static Tcl_Obj*
InitDefine (
    Tcl_Interp *interp,
    TclGLInfo *infoPtr,
    Tcl_Obj *objPtr,
    int defineGroupNo,
    int defineNo,
    const char *defineName,
    const char *defineValueStr,
    int defineValue)
{
    Tcl_HashTable *hTablePtr;
    Tcl_HashEntry *hPtr;
    TclGLDefine *definePtr;
    int isNew;

    hTablePtr = infoPtr->defineGroupHashTables[defineGroupNo];
    definePtr = (TclGLDefine *)ckalloc(sizeof(TclGLDefine));
    definePtr->defineGroupNo = defineGroupNo;
    definePtr->value = defineValue;
    definePtr->defineGroupNamePtr = objPtr;
    Tcl_IncrRefCount(definePtr->defineGroupNamePtr);
    definePtr->defineNamePtr = Tcl_NewStringObj(defineName, -1);
    Tcl_IncrRefCount(definePtr->defineNamePtr);
    definePtr->defineValuePtr = Tcl_NewStringObj(defineValueStr, -1);
    Tcl_IncrRefCount(definePtr->defineValuePtr);
    hPtr = Tcl_CreateHashEntry(hTablePtr, (char *)definePtr->defineNamePtr,
            &isNew);
    Tcl_SetHashValue(hPtr, definePtr);
    hPtr = Tcl_CreateHashEntry(&infoPtr->glDefines,
            (char *)definePtr->defineNamePtr, &isNew);
    Tcl_IncrRefCount(definePtr->defineNamePtr);
    Tcl_SetHashValue(hPtr, defineValue);
    hPtr = Tcl_CreateHashEntry(&infoPtr->glDefineStrings,
            (char *)defineValue, &isNew);
    Tcl_SetHashValue(hPtr, definePtr->defineNamePtr);
    Tcl_IncrRefCount(definePtr->defineNamePtr);
    return TCL_OK;
}
/*
 * ------------------------------------------------------------------------
 *  InitDefineGroupHashTables()
 *
 *      call InitDefineGroup and InitDefine for all entries
 *
 * ------------------------------------------------------------------------
 */

static int
InitDefineGroupHashTables (
    Tcl_Interp *interp,
    TclGLInfo *infoPtr)
{
    Tcl_Obj *objPtr;

#include "tclGLInitDefineGroupHashTables.c"
    return TCL_OK;
}
/*
 * ------------------------------------------------------------------------
 *  InitFuncGroup()
 *
 *      put a func funcGroup info into the hashTable
 * ------------------------------------------------------------------------
 */

static Tcl_Obj*
InitFuncGroup (
    Tcl_Interp *interp,
    TclGLInfo *infoPtr,
    int groupNo,
    const char *name)
{
    Tcl_HashEntry *hPtr;
    Tcl_Obj *objPtr;
    TclGLFuncGroup *funcGroupPtr;
    int isNew;

    objPtr = Tcl_NewStringObj(name, -1);
    funcGroupPtr = (TclGLFuncGroup *)ckalloc(sizeof(TclGLFuncGroup));
    funcGroupPtr->funcGroupNo = groupNo;
    funcGroupPtr->funcGroupNamePtr = objPtr;
    Tcl_IncrRefCount(funcGroupPtr->funcGroupNamePtr);
    hPtr = Tcl_CreateHashEntry(&infoPtr->funcGroups, (char *)objPtr, &isNew);
    Tcl_SetHashValue(hPtr, funcGroupPtr);
    return objPtr;
}
/*
 * ------------------------------------------------------------------------
 *  InitFunc()
 *
 *      put a func info into the hashTable
 * ------------------------------------------------------------------------
 */

static Tcl_Obj*
InitFunc (
    Tcl_Interp *interp,
    TclGLInfo *infoPtr,
    Tcl_Obj *objPtr,
    int funcGroupNo,
    int funcNo,
    const char *funcName,
    int returnType,
    int numParams,
    const char *usageStr)
{
    Tcl_HashTable *hTablePtr;
    Tcl_HashEntry *hPtr;
    TclGLFunc *funcPtr;
    int isNew;

    hTablePtr = infoPtr->funcGroupHashTables[funcGroupNo];
    funcPtr = infoPtr->funcv[funcNo];
    funcPtr->flags = TCL_GL_FUNC_AVAILABLE;
    funcPtr->funcGroupNo = funcGroupNo;
    funcPtr->returnType = returnType;
    funcPtr->numParams = numParams;
    funcPtr->funcGroupNamePtr = objPtr;
    Tcl_IncrRefCount(funcPtr->funcGroupNamePtr);
    funcPtr->funcNamePtr = Tcl_NewStringObj(funcName, -1);
    Tcl_IncrRefCount(funcPtr->funcNamePtr);
    funcPtr->usagePtr = Tcl_NewStringObj(usageStr, -1);
    Tcl_IncrRefCount(funcPtr->usagePtr);
    hPtr = Tcl_CreateHashEntry(hTablePtr, (char *)funcPtr->funcNamePtr,
            &isNew);
    Tcl_SetHashValue(hPtr, funcPtr);
    /* FIX ME */
    /* NEED PARAMS HERE !! */
    return TCL_OK;
}
/*
 * ------------------------------------------------------------------------
 *  InitFuncGroupHashTables()
 *
 *      call InitFuncGroup and InitFunc for all entries
 *
 * ------------------------------------------------------------------------
 */

static int
InitFuncGroupHashTables (
    Tcl_Interp *interp,
    TclGLInfo *infoPtr)
{
    Tcl_Obj *objPtr;

#include "tclGLInitFuncGroupHashTables.c"
    return TCL_OK;
}
/*
 * ------------------------------------------------------------------------
 *  Initialize()
 *
 *      that is the starting point when loading the library
 *      it initializes all internal stuff
 *
 * ------------------------------------------------------------------------
 */

static int
Initialize (
    Tcl_Interp *interp)
{
    Tcl_Namespace *nsPtr;
    TclGLInfo *infoPtr;
    int i;

    if (Tcl_InitStubs(interp, TCL_VERSION, 0) == NULL) {
        return TCL_ERROR;
    }

    nsPtr = Tcl_CreateNamespace(interp, TCL_GL_NAMESPACE, NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("tclGlfw: cannot create namespace: \"%s\" \n",
	        TCL_GL_NAMESPACE);
    }
    /*
     *  Create the top-level data structure for tracking objects.
     *  Store this as "associated data" for easy access, but link
     *  it to the itcl namespace for ownership.
     */
    infoPtr = (TclGLInfo*)ckalloc(sizeof(TclGLInfo));
    memset(infoPtr, 0, sizeof(TclGLInfo));
    infoPtr->version = TCL_GL_INFO_VERSION;
    Tcl_InitObjHashTable(&infoPtr->glDefines);
    Tcl_InitObjHashTable(&infoPtr->glExtensions);
    Tcl_InitHashTable(&infoPtr->glDefineStrings, TCL_ONE_WORD_KEYS);
    Tcl_InitObjHashTable(&infoPtr->fbos);
    Tcl_InitObjHashTable(&infoPtr->defineGroups);
    infoPtr->defineGroupHashTables =
            (Tcl_HashTable **)ckalloc(sizeof(Tcl_HashTable *)*
	    (TCL_NUM_GL_DEFINE_GROUPS+1));
    for (i=0;i<=TCL_NUM_GL_DEFINE_GROUPS;i++) {
        infoPtr->defineGroupHashTables[i] =
	        (Tcl_HashTable *)ckalloc(sizeof(Tcl_HashTable));
        Tcl_InitObjHashTable(infoPtr->defineGroupHashTables[i]);
    }
    if (InitDefineGroupHashTables(interp, infoPtr) != TCL_OK) {
        return TCL_ERROR;
    }

    Tcl_InitObjHashTable(&infoPtr->funcGroups);
    infoPtr->funcGroupHashTables =
            (Tcl_HashTable **)ckalloc(sizeof(Tcl_HashTable *)*
	    (TCL_NUM_GL_FUNC_GROUPS+1));
    for (i=0;i<=TCL_NUM_GL_FUNC_GROUPS;i++) {
        infoPtr->funcGroupHashTables[i] =
	        (Tcl_HashTable *)ckalloc(sizeof(Tcl_HashTable));
        Tcl_InitObjHashTable(infoPtr->funcGroupHashTables[i]);
    }
    infoPtr->funcv = (TclGLFunc **)ckalloc(sizeof(TclGLFunc *)*
            (TCL_NUM_GL_FUNCS+1));
    for (i=0;i<=TCL_NUM_GL_FUNCS;i++) {
        infoPtr->funcv[i] = (TclGLFunc *)ckalloc(sizeof(TclGLFunc));
        memset(infoPtr->funcv[i], 0, sizeof(TclGLFunc));
    }
    if (InitFuncGroupHashTables(interp, infoPtr) != TCL_OK) {
        return TCL_ERROR;
    }

    Tcl_InitObjHashTable(&infoPtr->typedefGroups);

    Tcl_SetAssocData(interp, TCL_GL_INTERP_DATA,
        (Tcl_InterpDeleteProc*)NULL, (ClientData)infoPtr);

    Tcl_Preserve((ClientData)infoPtr);

    TclGL_InitCommands(interp, infoPtr);
    TclGLext_InitCommands(interp, infoPtr);

// FIX ME !!!
//    int major, minor, rev;
//    glGetVersion(&major, &minor, &rev);
//fprintf(stderr, "GL version!%d!%d!%d!\n", major, minor, rev);

    Tcl_SetVar(interp, "::ntk::gl::version", TCL_GL_VERSION,
            TCL_NAMESPACE_ONLY);
    Tcl_SetVar(interp, "::ntk::gl::patchLevel", TCL_GL_PATCH_LEVEL,
            TCL_NAMESPACE_ONLY);
    /*
     *  Package is now loaded.
     */

    return Tcl_PkgProvideEx(interp, "TclGL", TCL_GL_VERSION, &tclGLStubAPI);
}

/*
 * ------------------------------------------------------------------------
 *  Tclgl_Init()
 *
 *  Invoked whenever a new INTERPRETER is created to install the
 *  tclGlfw package.  Usually invoked within Tcl_AppInit() at
 *  the start of execution.
 *
 *  Creates the "::ntk::gl" namespace and installs commands
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */

int
Tclgl_Init (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }

    return  TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Tclgl_SafeInit()
 *
 *  Invoked whenever a new SAFE INTERPRETER is created to install
 *  the tclGlfw package.
 *
 *  Creates the "::ntk::glfw" namespace and installs access commands
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */

int
Tclgl_SafeInit (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}
