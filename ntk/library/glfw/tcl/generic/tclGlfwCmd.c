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
 * RCS: @(#) $Id: tclGlfwCmd.c,v 1.1.2.2 2007/10/26 22:52:46 wiede Exp $
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
Tcl_ObjCmdProc TclGlfw_GetMousePosCmd;
Tcl_ObjCmdProc TclGlfw_GetVideoModesCmd;
Tcl_ObjCmdProc TclGlfw_GetDesktopModeCmd;
Tcl_ObjCmdProc TclGlfw_SwapBuffersCmd;
Tcl_ObjCmdProc TclGlfw_SetKeyCallbackCmd;
Tcl_ObjCmdProc TclGlfw_SetMousePosCallbackCmd;
Tcl_ObjCmdProc TclGlfw_SetMouseButtonCallbackCmd;
Tcl_ObjCmdProc TclGlfw_SetMouseWheelCallbackCmd;
Tcl_ObjCmdProc TclGlfw_SetWindowSizeCallbackCmd;
Tcl_ObjCmdProc TclGlfw_GetKeyCmd;
Tcl_ObjCmdProc TclGlfw_EnableCmd;
Tcl_ObjCmdProc TclGlfw_DisableCmd;
Tcl_ObjCmdProc TclGlfw_DefaultCmd;
Tcl_ObjCmdProc TclGlfw_UnknownCmd;
Tcl_ObjCmdProc TclGlfw_glDrawPixelsCmd;
Tcl_ObjCmdProc TclGlfw_glClearColorCmd;
Tcl_ObjCmdProc TclGlfw_glClearCmd;
Tcl_ObjCmdProc TclGlfw_glFlushCmd;

typedef struct GlfwMethod {
    char* name;              /* method name */
    char* usage;             /* string describing usage */
    Tcl_ObjCmdProc *proc;    /* implementation C proc */
} GlfwMethod;

static GlfwMethod GlfwMethodList[] = {
    { "init", "", TclGlfw_InitCmd },
    { "terminate", "", TclGlfw_TerminateCmd },
    { "enable", "param", TclGlfw_EnableCmd },
    { "disable", "param", TclGlfw_DisableCmd },
    { "openWindowHint", "target hint", TclGlfw_OpenWindowHintCmd },
    { "openWindow", "width height", TclGlfw_OpenWindowCmd },
    { "closeWindow", "", TclGlfw_CloseWindowCmd },
    { "setWindowTitle", "title", TclGlfw_SetWindowTitleCmd },
    { "setWindowSize", "width height", TclGlfw_SetWindowSizeCmd },
    { "setWindowPos", "x y", TclGlfw_SetWindowPosCmd },
    { "getWindowParam", "paramName", TclGlfw_GetWindowParamCmd },
    { "getWindowSize", "", TclGlfw_GetWindowSizeCmd },
    { "getMousePos", "", TclGlfw_GetMousePosCmd },
    { "getVideoModes", "??", TclGlfw_GetVideoModesCmd },
    { "getDesktopMode", "??", TclGlfw_GetDesktopModeCmd },
    { "swapBuffers", "", TclGlfw_SwapBuffersCmd },
    { "getKey", "keyName", TclGlfw_GetKeyCmd },
    { "setKeyCallback", "functionName", TclGlfw_SetKeyCallbackCmd },
    { "setMousePosCallback", "functionName",
            TclGlfw_SetMousePosCallbackCmd },
    { "setMouseButtonCallback", "functionName",
            TclGlfw_SetMouseButtonCallbackCmd },
    { "setWindowSizeCallback", "functionName",
            TclGlfw_SetWindowSizeCallbackCmd },
    { "setMouseWheelCallback", "??", TclGlfw_SetMouseWheelCallbackCmd },
    { "glDrawPixels", "width height <pixel-list>", TclGlfw_glDrawPixelsCmd },
    { "glClearColor", "redVal greenVal blueVal alphaVal",
            TclGlfw_glClearColorCmd },
    { "glClear", "", TclGlfw_glClearCmd },
    { "glFlush", "", TclGlfw_glFlushCmd },
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
    { "::ntk::glfw::Glfw::setWindowPos", TclGlfw_SetWindowPosCmd },
    { "::ntk::glfw::Glfw::setWindowSize", TclGlfw_SetWindowSizeCmd },
    { "::ntk::glfw::Glfw::getWindowParam", TclGlfw_GetWindowParamCmd },
    { "::ntk::glfw::Glfw::getWindowSize", TclGlfw_GetWindowSizeCmd },
    { "::ntk::glfw::Glfw::getMousePos", TclGlfw_GetMousePosCmd },
    { "::ntk::glfw::Glfw::getVideoModes", TclGlfw_GetVideoModesCmd },
    { "::ntk::glfw::Glfw::getDesktopMode", TclGlfw_GetDesktopModeCmd },
    { "::ntk::glfw::Glfw::swapBuffers", TclGlfw_SwapBuffersCmd },
    { "::ntk::glfw::Glfw::getKey", TclGlfw_GetKeyCmd },
    { "::ntk::glfw::Glfw::setKeyCallback", TclGlfw_SetKeyCallbackCmd },
    { "::ntk::glfw::Glfw::setMousePosCallback", 
            TclGlfw_SetMousePosCallbackCmd },
    { "::ntk::glfw::Glfw::setMouseButtonCallback", 
            TclGlfw_SetMouseButtonCallbackCmd },
    { "::ntk::glfw::Glfw::setMouseWheelCallback",
            TclGlfw_SetMouseWheelCallbackCmd },
    { "::ntk::glfw::Glfw::setWindowSizeCallback",
            TclGlfw_SetWindowSizeCallbackCmd },
    { "::ntk::glfw::Glfw::unknown", TclGlfw_UnknownCmd },
    { "::ntk::glfw::Glfw::glDrawPixels", TclGlfw_glDrawPixelsCmd },
    { "::ntk::glfw::Glfw::glClearColor", TclGlfw_glClearColorCmd },
    { "::ntk::glfw::Glfw::glClear", TclGlfw_glClearCmd },
    { "::ntk::glfw::Glfw::glFlush", TclGlfw_glFlushCmd },
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

static Tcl_Interp *_interp;

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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwShowArgs(0, "TclGlfw_InitCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw init\"",
	        NULL);
        return TCL_ERROR;
    }
    _interp = interp;
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGlfwInfo *infoPtr;
    TclGlfwWindow *winPtr;
    int isNew;
    int width;
    int height;
    int result;

    infoPtr = (TclGlfwInfo *)clientData;
    TclGlfwShowArgs(0, "TclGlfw_OpenWindowCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw openWindow width height\"",
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
    char buf[50];
    infoPtr->numWindows++;
    sprintf(buf, "winhandle_%d", infoPtr->numWindows);
    winPtr = (TclGlfwWindow *)ckalloc(sizeof(TclGlfwWindow));
    memset(winPtr, 0, sizeof(TclGlfwWindow));
    winPtr->handlePtr = Tcl_NewStringObj(buf, -1);
    Tcl_IncrRefCount(winPtr->handlePtr);
    hPtr = Tcl_CreateHashEntry(&infoPtr->windowHandles,
            (char *)winPtr->handlePtr, &isNew);
    Tcl_SetHashValue(hPtr, winPtr);
    infoPtr->currWindow = winPtr;
    Tcl_AppendResult(interp, Tcl_GetString(winPtr->handlePtr), NULL);
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
    ClientData clientData, /* not used */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;

    infoPtr = (TclGlfwInfo *)clientData;
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;

    infoPtr = (TclGlfwInfo *)clientData;
    TclGlfwShowArgs(0, "TclGlfw_SetWindowTitleCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw setWindowTitle title\"",
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;
    int width;
    int height;

    infoPtr = (TclGlfwInfo *)clientData;
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;
    int width;
    int height;
    Tcl_Obj *listPtr;

    infoPtr = (TclGlfwInfo *)clientData;
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
 *  TclGlfw_GetMousePosCmd()
 *
 *  Handles the GLFW getMousePos command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGlfw_GetMousePosCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_Obj *listPtr;
    TclGlfwInfo *infoPtr;
    int x;
    int y;

    infoPtr = (TclGlfwInfo *)clientData;
    TclGlfwShowArgs(0, "TclGlfw_GetMousePosCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw getMousePos\"",
	        NULL);
        return TCL_ERROR;
    }
    glfwGetMousePos(&x, &y);
    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(x));
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(y));
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_Obj *listPtr;
    Tcl_Obj *listPtr2;
    TclGlfwInfo *infoPtr;
    GLFWvidmode *modePtr;
    GLFWvidmode mode;
    int numModes;
    int i;

    infoPtr = (TclGlfwInfo *)clientData;
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_Obj *listPtr;
    TclGlfwInfo *infoPtr;
    GLFWvidmode *modePtr;
    GLFWvidmode mode;

    infoPtr = (TclGlfwInfo *)clientData;
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;
    int x;
    int y;

    infoPtr = (TclGlfwInfo *)clientData;
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;
    const char *token;
    int param;

    infoPtr = (TclGlfwInfo *)clientData;
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;
    const char *token;
    int param;

    infoPtr = (TclGlfwInfo *)clientData;
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;
    const char *token;
    int param;
    int value;

    infoPtr = (TclGlfwInfo *)clientData;
    TclGlfwShowArgs(1, "TclGlfw_GetWindowParamCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw getWindowParam paramName\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    param = TclGlfwWindowParam2Define(token);
    if (param < 0) {
        Tcl_AppendResult(interp, "bad paramName in getWindowParam: \"", token,
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;

    infoPtr = (TclGlfwInfo *)clientData;
    TclGlfwShowArgs(1, "TclGlfw_SwapBuffersCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw swapBuffers\"",
	        NULL);
        return TCL_ERROR;
    }
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;
    const char *token;
    int key;
    int value;

    infoPtr = (TclGlfwInfo *)clientData;
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
 *  DispatchKey()
 *
 *  Handles the GLFW dispatching of keys
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchKey(
    int key,
    int state)
{
    Tcl_Obj *objPtr;
    Tcl_Obj *keyPtr;
    Tcl_Obj *statePtr;
    Tcl_Obj *listPtr;
    TclGlfwWindow *winPtr;
    TclGlfwInfo *infoPtr;
    int result;

    infoPtr = Tcl_GetAssocData(_interp, TCL_GLFW_INTERP_DATA, NULL);
    winPtr = infoPtr->currWindow;
    objPtr = TclGlfwDefine2Key(key);
//fprintf(stderr, "DispatchKey!%s!%d!%d!\n", objPtr == NULL ? "(nil)" : Tcl_GetString(objPtr), key, state);
    listPtr = Tcl_NewListObj(0, NULL);
    keyPtr = Tcl_NewIntObj (key);
    Tcl_IncrRefCount (keyPtr);
    statePtr = Tcl_NewIntObj (state);
    Tcl_IncrRefCount (statePtr);
    Tcl_ListObjAppendElement (_interp, listPtr, winPtr->keyCallback);
    Tcl_ListObjAppendElement(_interp, listPtr, keyPtr);
    Tcl_ListObjAppendElement(_interp, listPtr, statePtr);
//fprintf(stderr, "CALL!%s!\n", Tcl_GetString(listPtr));
    result = Tcl_GlobalEvalObj (_interp, listPtr);
}

/*
 * ------------------------------------------------------------------------
 *  DispatchMousePos()
 *
 *  Handles the GLFW dispatching of mouse motion
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchMousePos(
    int x,
    int y)
{
    Tcl_Obj *xPtr;
    Tcl_Obj *yPtr;
    Tcl_Obj *listPtr;
    TclGlfwWindow *winPtr;
    TclGlfwInfo *infoPtr;
    int result;

    infoPtr = Tcl_GetAssocData(_interp, TCL_GLFW_INTERP_DATA, NULL);
    winPtr = infoPtr->currWindow;
    listPtr = Tcl_NewListObj(0, NULL);
    xPtr = Tcl_NewIntObj (x);
    Tcl_IncrRefCount (xPtr);
    yPtr = Tcl_NewIntObj (y);
    Tcl_IncrRefCount (yPtr);
    Tcl_ListObjAppendElement (_interp, listPtr, winPtr->mousePosCallback);
    Tcl_ListObjAppendElement(_interp, listPtr, xPtr);
    Tcl_ListObjAppendElement(_interp, listPtr, yPtr);
    result = Tcl_GlobalEvalObj (_interp, listPtr);
}

/*
 * ------------------------------------------------------------------------
 *  DispatchMouseButton()
 *
 *  Handles the GLFW dispatching of mouse button press/release
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchMouseButton(
    int which,
    int what)
{
    Tcl_Obj *whichPtr;
    Tcl_Obj *whatPtr;
    Tcl_Obj *listPtr;
    TclGlfwWindow *winPtr;
    TclGlfwInfo *infoPtr;
    int result;

    infoPtr = Tcl_GetAssocData(_interp, TCL_GLFW_INTERP_DATA, NULL);
    winPtr = infoPtr->currWindow;
    listPtr = Tcl_NewListObj(0, NULL);
    whichPtr = Tcl_NewIntObj (which);
    Tcl_IncrRefCount (whichPtr);
    whatPtr = Tcl_NewIntObj (what);
    Tcl_IncrRefCount (whatPtr);
    Tcl_ListObjAppendElement (_interp, listPtr, winPtr->mouseButtonCallback);
    Tcl_ListObjAppendElement(_interp, listPtr, whichPtr);
    Tcl_ListObjAppendElement(_interp, listPtr, whatPtr);
    result = Tcl_GlobalEvalObj (_interp, listPtr);
}

/*
 * ------------------------------------------------------------------------
 *  DispatchMouseWheel()
 *
 *  Handles the GLFW dispatching of mouse wheel motion
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchMouseWheel(
    int where)
{
    Tcl_Obj *wherePtr;
    Tcl_Obj *listPtr;
    TclGlfwWindow *winPtr;
    TclGlfwInfo *infoPtr;
    int result;

    infoPtr = Tcl_GetAssocData(_interp, TCL_GLFW_INTERP_DATA, NULL);
    winPtr = infoPtr->currWindow;
    listPtr = Tcl_NewListObj(0, NULL);
    wherePtr = Tcl_NewIntObj (where);
    Tcl_IncrRefCount (wherePtr);
    Tcl_ListObjAppendElement (_interp, listPtr, winPtr->mouseWheelCallback);
    Tcl_ListObjAppendElement(_interp, listPtr, wherePtr);
    result = Tcl_GlobalEvalObj (_interp, listPtr);
}

/*
 * ------------------------------------------------------------------------
 *  DispatchWindowSize()
 *
 *  Handles the GLFW dispatching of window sizing
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchWindowSize(
    int width,
    int height)
{
    Tcl_Obj *widthPtr;
    Tcl_Obj *heightPtr;
    Tcl_Obj *listPtr;
    TclGlfwWindow *winPtr;
    TclGlfwInfo *infoPtr;
    int result;

    infoPtr = Tcl_GetAssocData(_interp, TCL_GLFW_INTERP_DATA, NULL);
    winPtr = infoPtr->currWindow;
    listPtr = Tcl_NewListObj(0, NULL);
    widthPtr = Tcl_NewIntObj (width);
    Tcl_IncrRefCount (widthPtr);
    heightPtr = Tcl_NewIntObj (height);
    Tcl_IncrRefCount (heightPtr);
    Tcl_ListObjAppendElement (_interp, listPtr, winPtr->windowSizeCallback);
    Tcl_ListObjAppendElement(_interp, listPtr, widthPtr);
    Tcl_ListObjAppendElement(_interp, listPtr, heightPtr);
    result = Tcl_GlobalEvalObj (_interp, listPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_SetKeyCallbackCmd()
 *
 *  Handles the GLFW setKeyCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_SetKeyCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGlfwWindow *winPtr;
    TclGlfwInfo *infoPtr;

    infoPtr = (TclGlfwInfo *)clientData;
    TclGlfwShowArgs(0, "TclGlfw_SetKeyCallbackCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw setKeyCallback winHandle function\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windowHandles, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such window handle \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    winPtr->keyCallback = objv[2];
    Tcl_IncrRefCount(winPtr->keyCallback);
    glfwSetKeyCallback(DispatchKey);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_SetMousePosCallbackCmd()
 *
 *  Handles the GLFW setMousePosCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_SetMousePosCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGlfwWindow *winPtr;
    TclGlfwInfo *infoPtr;

    infoPtr = (TclGlfwInfo *)clientData;
    TclGlfwShowArgs(0, "TclGlfw_SetMousePosCallbackCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw setMousePosCallback windowHandle function\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windowHandles, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such window handle \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    winPtr->mousePosCallback = objv[2];
    Tcl_IncrRefCount(winPtr->mousePosCallback);
    glfwSetMousePosCallback(DispatchMousePos);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_SetMouseButtonCallbackCmd()
 *
 *  Handles the GLFW setMouseButtonCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_SetMouseButtonCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGlfwWindow *winPtr;
    TclGlfwInfo *infoPtr;

    infoPtr = (TclGlfwInfo *)clientData;
    TclGlfwShowArgs(0, "TclGlfw_SetMouseButtonCallbackCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw setMouseButtonCallback windowHandle function\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windowHandles, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such window handle \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    winPtr->mouseButtonCallback = objv[2];
    Tcl_IncrRefCount(winPtr->mouseButtonCallback);
    glfwSetMouseButtonCallback(DispatchMouseButton);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_SetMouseWheelCallbackCmd()
 *
 *  Handles the GLFW setMouseWheelCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_SetMouseWheelCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGlfwWindow *winPtr;
    TclGlfwInfo *infoPtr;

    infoPtr = (TclGlfwInfo *)clientData;
    TclGlfwShowArgs(0, "TclGlfw_SetMouseWheelCallbackCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw setMouseWheelCallback windowHandle function\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windowHandles, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such window handle \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    winPtr->mouseWheelCallback = objv[2];
    Tcl_IncrRefCount(winPtr->mouseWheelCallback);
    glfwSetMouseWheelCallback(DispatchMouseWheel);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_SetWindowSizeCallbackCmd()
 *
 *  Handles the GLFW setWindowSizeCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_SetWindowSizeCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGlfwWindow *winPtr;
    TclGlfwInfo *infoPtr;

    infoPtr = (TclGlfwInfo *)clientData;
    TclGlfwShowArgs(0, "TclGlfw_SetWindowSizeCallbackCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw setWindowSizeCallback windowHandle function\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windowHandles, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such window handle \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    winPtr->windowSizeCallback = objv[2];
    Tcl_IncrRefCount(winPtr->windowSizeCallback);
    glfwSetWindowSizeCallback(DispatchWindowSize);
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
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;
    int result;

    infoPtr = (TclGlfwInfo *)clientData;
    result = TCL_ERROR;
    TclGlfwShowArgs(0, "TclGlfw_DefaultCmd", objc, objv);
//    TclGlfw_GetEnsembleUsageForObj(interp, objv[0], resultPtr);
    return result;
}

#include <GL/gl.h>
/*
 * ------------------------------------------------------------------------
 *  TclGlfw_glDrawPixelsCmd()
 *
 *  Handles drawing of a pixel area with rgba values
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_glDrawPixelsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;
    unsigned char *data;
    const char **rowv;
    const char **colv;
    const char **fldv;
    unsigned char *cp;
    int result;
    int width;
    int height;
    int rows;
    int cols;
    int flds;
    int r;
    int c;
    int f;

    infoPtr = (TclGlfwInfo *)clientData;
    result = TCL_OK;
    TclGlfwShowArgs(1, "TclGlfw_glDrawPixelsCmd", objc, objv);
    if (objc != 4) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw drawPixels width height <rgba-list>\"",
	        NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &width);
    Tcl_GetIntFromObj(interp, objv[2], &height);
    Tcl_SplitList(interp, Tcl_GetString(objv[3]), &rows, &rowv);
    data = (unsigned char *)ckalloc(sizeof(unsigned char)*(width*height*4));
    cp = data;
    for(r=0;r<rows;r++) {
        Tcl_SplitList(interp, rowv[r], &cols, &colv);
        for(c=0;c<cols;c++) {
            Tcl_SplitList(interp, colv[c], &flds, &fldv);
            for(f=0;f<flds;f++) {
	        *cp = (unsigned char)atoi(fldv[f]);
	        cp++;
	    }
	}
    }
    glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
    ckfree((char *)data);
    return result;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_glClearColorCmd()
 *
 *  Handles clearing of color buffer
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_glClearColorCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;
    double redVal;
    double greenVal;
    double blueVal;
    double alphaVal;
    int result;

    infoPtr = (TclGlfwInfo *)clientData;
    result = TCL_OK;
    TclGlfwShowArgs(1, "TclGlfw_glClearColorCmd", objc, objv);
    if (objc != 5) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw glClearColor red green blue alpha\"",
	        NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &redVal);
    Tcl_GetDoubleFromObj(interp, objv[2], &greenVal);
    Tcl_GetDoubleFromObj(interp, objv[3], &blueVal);
    Tcl_GetDoubleFromObj(interp, objv[4], &alphaVal);
    glClearColor((GLfloat)redVal, (GLfloat)greenVal, (GLfloat)blueVal,
            (GLfloat)alphaVal);
    return result;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_glClearCmd()
 *
 *  Handles drawing of a pixel area with rgba values
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_glClearCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;
    const char *token;
    int param;
    int result;

    infoPtr = (TclGlfwInfo *)clientData;
    result = TCL_OK;
    TclGlfwShowArgs(1, "TclGlfw_glClearCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw glClear value\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
/* FIX ME !! */
//    param = TclGlfwGlKey2Define(token);
param = GL_COLOR_BUFFER_BIT;    
    if (param < 0) {
        Tcl_AppendResult(interp, "bad param in glClear: \"", token,
	        "\"", NULL);
        return TCL_ERROR;
    }
    glClear(param);
    return result;
}

/*
 * ------------------------------------------------------------------------
 *  TclGlfw_glFlushCmd()
 *
 *  Handles flush the buffers
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGlfw_glFlushCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGlfwInfo *infoPtr;
    int result;

    infoPtr = (TclGlfwInfo *)clientData;
    result = TCL_OK;
    TclGlfwShowArgs(1, "TclGlfw_glFlushCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw glFlush\"",
	        NULL);
        return TCL_ERROR;
    }
    glFlush();
    return result;
}
