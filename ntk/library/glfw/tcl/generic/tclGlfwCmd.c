/*
 * tclGlfwCmd.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the GLFW OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGlfwCmd.c,v 1.1.2.1 2007/10/25 19:02:43 wiede Exp $
 */

#include <stdlib.h>
#include "tclGlfwInt.h"

Tcl_ObjCmdProc TclGlfw_InitCmd;
Tcl_ObjCmdProc TclGlfw_TerminateCmd;
Tcl_ObjCmdProc TclGlfw_OpenWindowHintCmd;
Tcl_ObjCmdProc TclGlfw_OpenWindowCmd;
Tcl_ObjCmdProc TclGlfw_CloseWindowCmd;
Tcl_ObjCmdProc TclGlfw_SetWindowTitleCmd;
Tcl_ObjCmdProc TclGlfw_SetWindowSizeCmd;
Tcl_ObjCmdProc TclGlfw_SetWindowPosCmd;
Tcl_ObjCmdProc TclGlfw_GetWindowParamCmd;
Tcl_ObjCmdProc TclGlfw_GetWindowSizeCmd;
Tcl_ObjCmdProc TclGlfw_GetWindowPosCmd;
Tcl_ObjCmdProc TclGlfw_GetVideoModesCmd;
Tcl_ObjCmdProc TclGlfw_GetDesktopModeCmd;
Tcl_ObjCmdProc TclGlfw_SwapBuffersCmd;
Tcl_ObjCmdProc TclGlfw_GetKeyCmd;
Tcl_ObjCmdProc TclGlfw_EnableCmd;
Tcl_ObjCmdProc TclGlfw_DisableCmd;
Tcl_ObjCmdProc TclGlfw_DefaultCmd;
Tcl_ObjCmdProc TclGlfw_UnknownCmd;

typedef struct GlfwMethod {
    char* name;              /* method name */
    char* usage;             /* string describing usage */
    Tcl_ObjCmdProc *proc;    /* implementation C proc */
} GlfwMethod;

static GlfwMethod GlfwMethodList[] = {
    { "init", "??", TclGlfw_InitCmd },
    { "terminate", "??", TclGlfw_TerminateCmd },
    { "enable", "??", TclGlfw_EnableCmd },
    { "disable", "??", TclGlfw_DisableCmd },
    { "openWindowHint", "??", TclGlfw_OpenWindowHintCmd },
    { "openWindow", "??", TclGlfw_OpenWindowCmd },
    { "closeWindow", "??", TclGlfw_CloseWindowCmd },
    { "setWindowTitle", "??", TclGlfw_SetWindowTitleCmd },
    { "setWindowSize", "??", TclGlfw_SetWindowSizeCmd },
    { "setWindowPos", "??", TclGlfw_SetWindowPosCmd },
    { "getWindowParam", "??", TclGlfw_GetWindowParamCmd },
    { "getWindowSize", "??", TclGlfw_GetWindowSizeCmd },
    { "getVideoModes", "??", TclGlfw_GetVideoModesCmd },
    { "getDesktopMode", "??", TclGlfw_GetDesktopModeCmd },
    { "swapBuffers", "??", TclGlfw_SwapBuffersCmd },
    { "getKey", "??", TclGlfw_GetKeyCmd },
    /*
     *  Add an error handler to support all of the usual inquiries
     *  for the "info" command in the global namespace.
     */
    { "@error", "", TclGlfw_DefaultCmd },
    { NULL, NULL, NULL }
};

struct NameProcMap { const char *name; Tcl_ObjCmdProc *proc; };

/*
 * List of commands that are used to implement the [ntk glfw] subcommands.
 */

static const struct NameProcMap glfwCmds2[] = {
    { "::ntk::glfw::Glfw::init", TclGlfw_InitCmd },
    { "::ntk::glfw::Glfw::terminate", TclGlfw_TerminateCmd },
    { "::ntk::glfw::Glfw::enable", TclGlfw_EnableCmd },
    { "::ntk::glfw::Glfw::disable", TclGlfw_DisableCmd },
    { "::ntk::glfw::Glfw::openWindow", TclGlfw_OpenWindowCmd },
    { "::ntk::glfw::Glfw::openWindowHint", TclGlfw_OpenWindowHintCmd },
    { "::ntk::glfw::Glfw::closeWindow", TclGlfw_CloseWindowCmd },
    { "::ntk::glfw::Glfw::setWindowTitle", TclGlfw_SetWindowTitleCmd },
    { "::ntk::glfw::Glfw::setWindowSize", TclGlfw_SetWindowSizeCmd },
    { "::ntk::glfw::Glfw::getWindowParam", TclGlfw_GetWindowParamCmd },
    { "::ntk::glfw::Glfw::getWindowSize", TclGlfw_GetWindowSizeCmd },
    { "::ntk::glfw::Glfw::getVideoModes", TclGlfw_GetVideoModesCmd },
    { "::ntk::glfw::Glfw::getDesktopMode", TclGlfw_GetDesktopModeCmd },
    { "::ntk::glfw::Glfw::swapBuffers", TclGlfw_SwapBuffersCmd },
    { "::ntk::glfw::Glfw::getKey", TclGlfw_GetKeyCmd },
    { "::ntk::glfw::Glfw::unknown", TclGlfw_UnknownCmd },
    /*
     *  Add an error handler
     */
    { "::ntk::glfw::GlfW::@error", TclGlfw_DefaultCmd },
    { NULL, NULL }
};

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_InitCommands()
 *
 *      that is the starting point when loading the library
 *      it initializes all internal stuff
 *
 * ------------------------------------------------------------------------
 */

int
TclGlfw_InitCommands (
    Tcl_Interp *interp,
    TclGlfwInfo *infoPtr)
{
    Tcl_Namespace *nsPtr;
    Tcl_Command cmd;
    int i;

    /*
     * Build the ensemble used to implement [ntk glfw].
     */

    nsPtr = Tcl_CreateNamespace(interp, "::ntk::glfw::Glfw", NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("ITCL: error in creating namespace: ::ntk::glfw::Glfw \n");
    }
    cmd = Tcl_CreateEnsemble(interp, nsPtr->fullName, nsPtr,
        TCL_ENSEMBLE_PREFIX);
    Tcl_Export(interp, nsPtr, "[a-z]*", 1);
    for (i=0 ; glfwCmds2[i].name!=NULL ; i++) {
        Tcl_CreateObjCommand(interp, glfwCmds2[i].name,
                glfwCmds2[i].proc, infoPtr, NULL);
    }
    Tcl_Obj *ensObjPtr = Tcl_NewStringObj("::ntk::glfw::Glfw", -1);
    Tcl_IncrRefCount(ensObjPtr);
    Tcl_Obj *unkObjPtr = Tcl_NewStringObj("::ntk::glfw::Glfw::unknown", -1);
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
 *  TclGlfwGetUsage()
 *
 * ------------------------------------------------------------------------
  */
void
TclGlfwGetUsage(
    Tcl_Interp *interp,
    Tcl_Obj *objPtr)       /* returns: summary of usage info */
{
    char *spaces = "  ";
    int isOpenEnded = 0;

    int i;

    for (i=0; GlfwMethodList[i].name != NULL; i++) {
        if (*GlfwMethodList[i].name == '@'
	        && strcmp(GlfwMethodList[i].name,"@error") == 0) {
            isOpenEnded = 1;
        } else {
            Tcl_AppendToObj(objPtr, spaces, -1);
            Tcl_AppendToObj(objPtr, "ntk glfw ", -1);
            Tcl_AppendToObj(objPtr, GlfwMethodList[i].name, -1);
	    if (strlen(GlfwMethodList[i].usage) > 0) {
              Tcl_AppendToObj(objPtr, " ", -1);
              Tcl_AppendToObj(objPtr, GlfwMethodList[i].usage, -1);
	    }
            spaces = "\n  ";
        }
    }
    if (isOpenEnded) {
        Tcl_AppendToObj(objPtr,
            "\n...and others described on the man page", -1);
    }
}
#ifdef NOTDEF

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_GlfwCmd()
 *
 *  Invoked whenever the user issues the "ntk glfw" method for an object.
 *  Handles the following syntax:
 *
 *    info 
 *
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_GlfwCmd(
    ClientData clientData,   /* class definition */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    TclGlfwShowArgs(0, "TclGlfw_GlfwCmd", objc, objv);
    if (objc == 1) {
        /* produce usage message */
        Tcl_Obj *objPtr = Tcl_NewStringObj(
	        "wrong # args: should be one of...\n", -1);
        TclGlfwGetUsage(interp, objPtr);
	Tcl_SetResult(interp, Tcl_GetString(objPtr), TCL_DYNAMIC);
	return TCL_ERROR;
    }
    return TclGlfwEnsembleSubCmd(clientData, interp, "::ntk::glfw::Glfw",
            objc, objv, "TclGlfw_GlfwCmd");
}
#endif

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_UnknownCmd()
 *
 *  the unknown handler for the ::itcl::builtin::Info ensemble
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_UnknownCmd(
    ClientData dummy,        /* not used */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int result;

    TclGlfwShowArgs(0, "TclGlfw_UnknownCmd", objc, objv);
    result = TCL_ERROR;
    /* produce usage message */
    Tcl_Obj *objPtr = Tcl_NewStringObj("unknown command: \"", -1);
    Tcl_AppendToObj(objPtr, Tcl_GetString(objv[2]), -1);
    Tcl_AppendToObj(objPtr, "\" should be one of...\n", -1);
    TclGlfwGetUsage(interp, objPtr);
    Tcl_SetResult(interp, Tcl_GetString(objPtr), TCL_DYNAMIC);
    return TCL_ERROR;
}


/*
 * ------------------------------------------------------------------------
 *  TclGlfw_InitCmd()
 *
 *  Handles the GLFW init command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_InitCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    TclGlfwShowArgs(0, "TclGlfw_InitCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw init\"",
	        NULL);
        return TCL_ERROR;
    }
    glfwInit();
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_TerminateCmd()
 *
 *  Handles the GLFW terminate command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_TerminateCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    TclGlfwShowArgs(0, "TclGlfw_TerminateCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw terminate\"",
	        NULL);
        return TCL_ERROR;
    }
    glfwTerminate();
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_OpenWindowCmd()
 *
 *  Handles the GLFW openWindow command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_OpenWindowCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int width;
    int height;
    int result;

    TclGlfwShowArgs(0, "TclGlfw_OpenWindowCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw openWindow .....\"",
	        NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &width);
    Tcl_GetIntFromObj(interp, objv[2], &height);
    /* r = redbits, if 0 8 bits are used from the current glfw implementation */
    /* g = greenbits, see above */
    /* b = bluebits, see above */
    /* a = alphabits, see above */
    /* d = depthbits */
    /* s = stencilbits */
    /*                                    r g b a   d s */
    result = glfwOpenWindow(width,height, 0,0,0,0, 16,0, GLFW_WINDOW);
    if (result == 0) {
        return TCL_ERROR;
    }

    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_CloseWindowCmd()
 *
 *  Handles the GLFW closeWindow command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_CloseWindowCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    TclGlfwShowArgs(0, "TclGlfw_CloseWindowCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw closeWindow\"",
	        NULL);
        return TCL_ERROR;
    }
    glfwCloseWindow();
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_OpenWindowHintCmd()
 *
 *  Handles the GLFW openWindowHint command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_OpenWindowHintCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int target;
    int hint;
    const char *token;

    TclGlfwShowArgs(0, "TclGlfw_OpenWindowHintCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw openWindowHint <target> <hint>\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    target = TclGlfwWindowHint2Define(token);
    if (target < 0) {
        Tcl_AppendResult(interp, "bad target in openWindowHint: \"", token,
	        "\"", NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[2], &hint);
    glfwOpenWindowHint(target, hint);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_SetWindowTitleCmd()
 *
 *  Handles the GLFW setWindowTitle command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGlfw_SetWindowTitleCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    TclGlfwShowArgs(0, "TclGlfw_SetWindowTitleCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw setWindowTitle .....\"",
	        NULL);
        return TCL_ERROR;
    }
    glfwSetWindowTitle(Tcl_GetString(objv[1]));
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_SetWindowSizeCmd()
 *
 *  Handles the GLFW setWindowSize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGlfw_SetWindowSizeCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int width;
    int height;

    TclGlfwShowArgs(0, "TclGlfw_SetWindowSizeCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw setWindowSize width height\"",
	        NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &width);
    Tcl_GetIntFromObj(interp, objv[2], &height);
    glfwSetWindowSize(width, height);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_GetWindowSizeCmd()
 *
 *  Handles the GLFW getWindowSize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGlfw_GetWindowSizeCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int width;
    int height;
    Tcl_Obj *listPtr;

    TclGlfwShowArgs(0, "TclGlfw_GetWindowSizeCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw getWindowSize\"",
	        NULL);
        return TCL_ERROR;
    }
    glfwGetWindowSize(&width, &height);
    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(width));
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(height));
    Tcl_SetObjResult(interp, listPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_GetVideoModesCmd()
 *
 *  Handles the GLFW getVideoModes command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGlfw_GetVideoModesCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_Obj *listPtr;
    Tcl_Obj *listPtr2;
    GLFWvidmode *modePtr;
    GLFWvidmode mode;
    int numModes;
    int i;

    TclGlfwShowArgs(0, "TclGlfw_GetVideoModesCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw getVideoModes\"",
	        NULL);
        return TCL_ERROR;
    }
    modePtr = (GLFWvidmode *)ckalloc(sizeof(GLFWvidmode)*200);
    numModes = glfwGetVideoModes(modePtr, 200);
    listPtr = Tcl_NewListObj(0, NULL);
    for(i=0; i<numModes;i++) {
        mode = modePtr[i];
        listPtr2 = Tcl_NewListObj(0, NULL);
        Tcl_ListObjAppendElement(interp, listPtr2, Tcl_NewIntObj(mode.Height));
        Tcl_ListObjAppendElement(interp, listPtr2, Tcl_NewIntObj(mode.Width));
        Tcl_ListObjAppendElement(interp, listPtr2, Tcl_NewIntObj(mode.RedBits));
        Tcl_ListObjAppendElement(interp, listPtr2, Tcl_NewIntObj(mode.GreenBits));
        Tcl_ListObjAppendElement(interp, listPtr2, Tcl_NewIntObj(mode.BlueBits));
        Tcl_ListObjAppendElement(interp, listPtr, listPtr2);
    }
    Tcl_SetObjResult(interp, listPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_GetDesktopModeCmd()
 *
 *  Handles the GLFW getDesktopMode command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGlfw_GetDesktopModeCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_Obj *listPtr;
    GLFWvidmode *modePtr;
    GLFWvidmode mode;

    TclGlfwShowArgs(0, "TclGlfw_GetDesktopModeCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw getDesktopMode\"",
	        NULL);
        return TCL_ERROR;
    }
    modePtr = (GLFWvidmode *)ckalloc(sizeof(GLFWvidmode));
    glfwGetDesktopMode(modePtr);
    listPtr = Tcl_NewListObj(0, NULL);
    mode = modePtr[0];
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(mode.Height));
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(mode.Width));
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(mode.RedBits));
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(mode.GreenBits));
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(mode.BlueBits));
    Tcl_SetObjResult(interp, listPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_SetWindowPosCmd()
 *
 *  Handles the GLFW setWindowPos command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGlfw_SetWindowPosCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int x;
    int y;

    TclGlfwShowArgs(0, "TclGlfw_SetWindowPosCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw setWindowPos x y\"",
	        NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    glfwSetWindowPos(x, y);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_EnableCmd()
 *
 *  Handles the GLFW enable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_EnableCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int param;
    const char *token;

    TclGlfwShowArgs(0, "TclGlfw_EnableCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw enable param\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    param = TclGlfwEnableParam2Define(token);
    if (param < 0) {
        Tcl_AppendResult(interp, "bad param in enable: \"", token,
	        "\"", NULL);
        return TCL_ERROR;
    }
    glfwEnable(param);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_DisableCmd()
 *
 *  Handles the GLFW disable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_DisableCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int param;
    const char *token;

    TclGlfwShowArgs(0, "TclGlfw_DisableCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw disable param\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    param = TclGlfwEnableParam2Define(token);
    if (param < 0) {
        Tcl_AppendResult(interp, "bad param in disable: \"", token,
	        "\"", NULL);
        return TCL_ERROR;
    }
    glfwDisable(param);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_GetWindowParamCmd()
 *
 *  Handles the GLFW getWindowParam command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_GetWindowParamCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int param;
    int value;
    const char *token;

    TclGlfwShowArgs(0, "TclGlfw_GetWindowParamCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw getWindowParam param\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    param = TclGlfwWindowParam2Define(token);
    if (param < 0) {
        Tcl_AppendResult(interp, "bad param in getWindowParam: \"", token,
	        "\"", NULL);
        return TCL_ERROR;
    }
    value = glfwGetWindowParam(param);
    Tcl_SetObjResult(interp, Tcl_NewIntObj(value));
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_SwapBuffersCmd()
 *
 *  Handles the GLFW swapBuffers command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_SwapBuffersCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    TclGlfwShowArgs(0, "TclGlfw_SwapBuffersCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw swapBuffers\"",
	        NULL);
        return TCL_ERROR;
    }
glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers();
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_GetKeyCmd()
 *
 *  Handles the GLFW getKey command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_GetKeyCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    const char *token;
    int key;
    int value;

    TclGlfwShowArgs(0, "TclGlfw_GetKeyCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw getKey <char>|<key string>\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    if (strlen(token) > 1) {
        key = TclGlfwKey2Define(Tcl_GetString(objv[1]));
        if (key == -1) {
            Tcl_AppendResult(interp, "bad key in getKey: \"", token,
	            "\"", NULL);
	    return TCL_ERROR;
        }
    } else {
        key = (int)(*token);
    }
fprintf(stderr, "key!%d!\n", key);
    value = glfwGetKey(key);
fprintf(stderr, "value!%d!\n", value);
    Tcl_SetObjResult(interp, Tcl_NewIntObj(value));
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_DefaultCmd()
 *
 *  Handles any unknown options for the "ntk::glfw::Glfw" command
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_DefaultCmd(
    ClientData dummy,     /* not used */
    Tcl_Interp *interp,   /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int result;

    result = TCL_ERROR;
    TclGlfwShowArgs(0, "TclGlfw_DefaultCmd", objc, objv);
//    TclGlfw_GetEnsembleUsageForObj(interp, objv[0], resultPtr);
    return result;
}
