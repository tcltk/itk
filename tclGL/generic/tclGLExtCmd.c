/*
 * tclGLCmdExt.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLExtCmd.c,v 1.1.2.2 2007/11/11 20:05:44 wiede Exp $
 */

#include <stdlib.h>
#define GL_GLEXT_PROTOTYPES 1
#include "tclGLInt.h"
#include "tclGLFuncSizes.h"

Tcl_ObjCmdProc TclGLext_UnknownCmd;
#include "tclGLExtProcNames.c"

typedef struct GLMethod {
    char* commandName;              /* method name */
    char* usage;             /* string describing usage */
    Tcl_ObjCmdProc *proc;    /* implementation C proc */
} GLMethod;

static GLMethod GLMethodList[] = {
#include "tclGLExtMethodInfos.c"
    { "::ntk::gl::GLext::unknown",
            "", TclGLext_UnknownCmd },
    { NULL, NULL, NULL }
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
 *  TclGLext_InitCommands()
 *
 *      that is the starting point when loading the library
 *      it initializes all internal stuff
 *
 * ------------------------------------------------------------------------
 */

int
TclGLext_InitCommands (
    Tcl_Interp *interp,
    TclGLInfo *infoPtr)
{
    Tcl_Namespace *nsPtr;
    Tcl_Command cmd;
    int i;

    /*
     * Build the ensemble used to implement [ntk gl].
     */

    nsPtr = Tcl_CreateNamespace(interp, "::ntk::gl::GLext", NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("ITCL: error in creating namespace: ::ntk::gl::GLext \n");
    }
    cmd = Tcl_CreateEnsemble(interp, nsPtr->fullName, nsPtr,
        TCL_ENSEMBLE_PREFIX);
    Tcl_Export(interp, nsPtr, "[a-z]*", 1);
    for (i=0 ; GLMethodList[i].commandName!=NULL ; i++) {
        Tcl_CreateObjCommand(interp, GLMethodList[i].commandName,
                GLMethodList[i].proc, infoPtr, NULL);
    }
    Tcl_Obj *ensObjPtr = Tcl_NewStringObj("::ntk::gl::GLext", -1);
    Tcl_IncrRefCount(ensObjPtr);
    Tcl_Obj *unkObjPtr = Tcl_NewStringObj("::ntk::gl::GLext::unknown", -1);
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
TclGLextGetUsage(
    Tcl_Interp *interp,
    TclGLInfo *infoPtr,
    Tcl_Obj *objPtr)       /* returns: summary of usage info */
{
    TclGLFunc *funcPtr;
    const char *cp;
    char *spaces = "  ";
    int i;

    for (i=0; GLMethodList[i].commandName != NULL; i++) {
	if (strcmp(GLMethodList[i].commandName,
	        "::ntk::gl::GLext::unknown") == 0) {
	    continue;
	}
        Tcl_AppendToObj(objPtr, spaces, -1);
        Tcl_AppendToObj(objPtr, "ntk ", -1);
	cp = strrchr(GLMethodList[i].commandName, ':');
	if (cp == NULL) {
	   cp = GLMethodList[i].commandName;
	} else {
	   cp++;
	}
        Tcl_AppendToObj(objPtr, cp, -1);
	if (GLMethodList[i].usage == NULL) {
	    if (i < TCL_NUM_GL_FUNCS) {
	        funcPtr = infoPtr->funcv[i];
		Tcl_AppendToObj(objPtr, " ", -1);
		Tcl_AppendToObj(objPtr, Tcl_GetString(funcPtr->usagePtr), -1);
	    }
	} else {
	    if (strlen(GLMethodList[i].usage) > 0) {
                Tcl_AppendToObj(objPtr, " ", -1);
                Tcl_AppendToObj(objPtr, GLMethodList[i].usage, -1);
	    }
	}
        spaces = "\n  ";
    }
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_UnknownCmd()
 *
 *  the unknown handler for the ::itcl::builtin::Info ensemble
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLext_UnknownCmd(
    ClientData clientData,   /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    TclGLInfo *infoPtr;
    int result;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_UnknownCmd", objc, objv);
    result = TCL_ERROR;
    /* produce usage message */
    Tcl_Obj *objPtr = Tcl_NewStringObj("unknown command: \"", -1);
    Tcl_AppendToObj(objPtr, Tcl_GetString(objv[2]), -1);
    Tcl_AppendToObj(objPtr, "\" should be one of...\n", -1);
    TclGLextGetUsage(interp, infoPtr, objPtr);
    Tcl_SetResult(interp, Tcl_GetString(objPtr), TCL_DYNAMIC);
    return TCL_ERROR;
}

#include <GL/gl.h>
#include <GL/glext.h>
#include "tclGLExtFuncs.c"
