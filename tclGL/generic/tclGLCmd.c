/*
 * tclGLCmd.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLCmd.c,v 1.1.2.1 2007/10/31 09:32:53 wiede Exp $
 */

#include <stdlib.h>
#include "tclGLInt.h"

Tcl_ObjCmdProc TclGL_DefaultCmd;
Tcl_ObjCmdProc TclGL_UnknownCmd;
Tcl_ObjCmdProc TclGL_Define2Str;
Tcl_ObjCmdProc TclGL_Str2Define;
Tcl_ObjCmdProc TclGL_MakeFloatVector;
#include "tclGLProcNames.c"

typedef struct GLMethod {
    char* name;              /* method name */
    char* usage;             /* string describing usage */
    Tcl_ObjCmdProc *proc;    /* implementation C proc */
} GLMethod;

static GLMethod GLMethodList[] = {
#include "tclGLMethodNames.c"
    { "glDefine2Str", "<define value>", TclGL_Define2Str },
    { "glStr2Define", "<define string>", TclGL_Str2Define },
    { "makeFloatVector", "<list>", TclGL_MakeFloatVector },
    /*
     *  Add an error handler to support all of the usual inquiries
     *  for the "info" command in the global namespace.
     */
    { "@error", "", TclGL_DefaultCmd },
    { NULL, NULL, NULL }
};

struct NameProcMap { const char *name; Tcl_ObjCmdProc *proc; };

/*
 * List of commands that are used to implement the [ntk glfw] subcommands.
 */

static const struct NameProcMap glCmds2[] = {
#include "tclGLCmdNames.c"
    { "::ntk::gl::GL::unknown", TclGL_UnknownCmd },
    { "::ntk::gl::GL::glDefine2Str", TclGL_Define2Str },
    { "::ntk::gl::GL::glStr2Define", TclGL_Str2Define },
    { "::ntk::gl::GL::makeFloatVector", TclGL_MakeFloatVector },
    /*
     *  Add an error handler
     */
    { "::ntk::gl::GL::@error", TclGL_DefaultCmd },
    { NULL, NULL }
};

/*
 * ------------------------------------------------------------------------
 *  GetGLError()
 *
 *      Handle GL errors
 *
 * ------------------------------------------------------------------------
 */

static int
GetGLError (
    Tcl_Interp *interp,
    TclGLInfo *infoPtr)
{
    GLenum glResult;
    int result;

    if (infoPtr->noGLGetError) {
        return TCL_OK;
    }
    glResult = glGetError();
    result = TCL_ERROR;
    switch (glResult) {
    case GL_NO_ERROR:
        result = TCL_OK;
        break;
    case GL_INVALID_VALUE:
        Tcl_AppendResult(interp, "GL ERROR GL_INVALID_VALUE", NULL);
        break;
    case GL_INVALID_ENUM:
        Tcl_AppendResult(interp, "GL ERROR GL_INVALID_ENUM", NULL);
        break;
    case GL_INVALID_OPERATION:
        Tcl_AppendResult(interp, "GL ERROR GL_INVALID_OPERATION", NULL);
        break;
    case GL_STACK_OVERFLOW:
        Tcl_AppendResult(interp, "GL ERROR GL_STACK_OVERFLOW", NULL);
        break;
    case GL_STACK_UNDERFLOW:
        Tcl_AppendResult(interp, "GL ERROR GL_STACK_UNDERFLOW", NULL);
        break;
    case GL_OUT_OF_MEMORY:
        Tcl_AppendResult(interp, "GL ERROR GL_OUT_OF_MEMORY", NULL);
        break;
    default:
        fprintf(stderr, "funny result in glGetError!0x%08x\n", glResult);
        break;
    }
    return result;
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_InitCommands()
 *
 *      that is the starting point when loading the library
 *      it initializes all internal stuff
 *
 * ------------------------------------------------------------------------
 */

int
TclGL_InitCommands (
    Tcl_Interp *interp,
    TclGLInfo *infoPtr)
{
    Tcl_Namespace *nsPtr;
    Tcl_Command cmd;
    int i;

    /*
     * Build the ensemble used to implement [ntk gl].
     */

    nsPtr = Tcl_CreateNamespace(interp, "::ntk::gl::GL", NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("ITCL: error in creating namespace: ::ntk::gl::GL \n");
    }
    cmd = Tcl_CreateEnsemble(interp, nsPtr->fullName, nsPtr,
        TCL_ENSEMBLE_PREFIX);
    Tcl_Export(interp, nsPtr, "[a-z]*", 1);
    for (i=0 ; glCmds2[i].name!=NULL ; i++) {
        Tcl_CreateObjCommand(interp, glCmds2[i].name,
                glCmds2[i].proc, infoPtr, NULL);
    }
    Tcl_Obj *ensObjPtr = Tcl_NewStringObj("::ntk::gl::GL", -1);
    Tcl_IncrRefCount(ensObjPtr);
    Tcl_Obj *unkObjPtr = Tcl_NewStringObj("::ntk::gl::GL::unknown", -1);
    Tcl_IncrRefCount(unkObjPtr);
    if (Tcl_SetEnsembleUnknownHandler(NULL,
            Tcl_FindEnsemble(interp, ensObjPtr, TCL_LEAVE_ERR_MSG),
	    unkObjPtr) != TCL_OK) {
        return TCL_ERROR;
    }
    Tcl_DecrRefCount(ensObjPtr);
    Tcl_DecrRefCount(unkObjPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLGetUsage()
 *
 * ------------------------------------------------------------------------
  */
void
TclGLGetUsage(
    Tcl_Interp *interp,
    Tcl_Obj *objPtr)       /* returns: summary of usage info */
{
    char *spaces = "  ";
    int isOpenEnded = 0;

    int i;

    for (i=0; GLMethodList[i].name != NULL; i++) {
        if (*GLMethodList[i].name == '@'
	        && strcmp(GLMethodList[i].name,"@error") == 0) {
            isOpenEnded = 1;
        } else {
            Tcl_AppendToObj(objPtr, spaces, -1);
            Tcl_AppendToObj(objPtr, "ntk ", -1);
            Tcl_AppendToObj(objPtr, GLMethodList[i].name, -1);
	    if (strlen(GLMethodList[i].usage) > 0) {
              Tcl_AppendToObj(objPtr, " ", -1);
              Tcl_AppendToObj(objPtr, GLMethodList[i].usage, -1);
	    }
            spaces = "\n  ";
        }
    }
    if (isOpenEnded) {
        Tcl_AppendToObj(objPtr,
            "\n...and others described on the man page", -1);
    }
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_UnknownCmd()
 *
 *  the unknown handler for the ::itcl::builtin::Info ensemble
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_UnknownCmd(
    ClientData dummy,        /* not used */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int result;

    TclGLShowArgs(1, "TclGL_UnknownCmd", objc, objv);
    result = TCL_ERROR;
    /* produce usage message */
    Tcl_Obj *objPtr = Tcl_NewStringObj("unknown command: \"", -1);
    Tcl_AppendToObj(objPtr, Tcl_GetString(objv[2]), -1);
    Tcl_AppendToObj(objPtr, "\" should be one of...\n", -1);
    TclGLGetUsage(interp, objPtr);
    Tcl_SetResult(interp, Tcl_GetString(objPtr), TCL_DYNAMIC);
    return TCL_ERROR;
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_Define2Str()
 *
 *  convert a GL_ define value to the corresponding string
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_Define2Str(
    ClientData clientData,   /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int value;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_Define2Str", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDefine2Str value\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &value);
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefineStrings, (char *)value);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define value: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
	return TCL_ERROR;
    }
    Tcl_AppendResult(interp, Tcl_GetString(Tcl_GetHashValue(hPtr)), NULL);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_Str2Define()
 *
 *  convert a GL_ define string to the corresponding value
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_Str2Define(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_Str2Define", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glStr2Define value\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define string: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
	return TCL_ERROR;
    }
    char buf[30];
    Tcl_Obj *objPtr;
    sprintf(buf, "0x%08x", (int)Tcl_GetHashValue(hPtr));
    objPtr = Tcl_NewStringObj(buf, -1);
    Tcl_AppendResult(interp, Tcl_GetString(objPtr), NULL);
    return TCL_OK;;
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_MakeFloatVector()
 *
 *  convert a list of floats into a Tcl_ByteArrayObj
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_MakeFloatVector(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_Obj *objPtr;
    TclGLInfo *infoPtr;
    float *floatVec;
    float floatVal;
    const char **argv;
    int argc;
    int i;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_MakeFloatVector", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk makeFloatVector list\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_SplitList(interp, Tcl_GetString(objv[1]), &argc, &argv);
    floatVec = (float *)ckalloc(sizeof(float)*argc);
    for(i=0;i<argc;i++) {
        floatVal = atof(argv[i]);
	floatVec[i] = floatVal;
    }
    objPtr = Tcl_NewByteArrayObj((unsigned char *)floatVec, sizeof(float)*argc);
    Tcl_AppendResult(interp, Tcl_GetString(objPtr), NULL);
    return TCL_OK;;
}

static Tcl_Interp *_interp;

/*
 * ------------------------------------------------------------------------
 *  TclGL_InitCmd()
 *
 *  Handles the GL init command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_InitCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLShowArgs(0, "TclGL_InitCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk gl init\"",
	        NULL);
        return TCL_ERROR;
    }
    _interp = interp;
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_DefaultCmd()
 *
 *  Handles any unknown options for the "ntk::gl::GL" command
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_DefaultCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLInfo *infoPtr;
    int result;

    infoPtr = (TclGLInfo *)clientData;
    result = TCL_ERROR;
    TclGLShowArgs(0, "TclGL_DefaultCmd", objc, objv);
    return result;
}

#include <GL/gl.h>
#include "tclGLFuncs.c"
