/*
 * tclGLFWCmd.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the GLFW OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLFWCmd.c,v 1.1.2.2 2007/10/31 10:09:58 wiede Exp $
 */

#include <stdlib.h>
#include "tclGLFWInt.h"

Tcl_ObjCmdProc TclGLFW_InitCmd;
Tcl_ObjCmdProc TclGLFW_TerminateCmd;
Tcl_ObjCmdProc TclGLFW_OpenWindowHintCmd;
Tcl_ObjCmdProc TclGLFW_OpenWindowCmd;
Tcl_ObjCmdProc TclGLFW_CloseWindowCmd;
Tcl_ObjCmdProc TclGLFW_SetWindowTitleCmd;
Tcl_ObjCmdProc TclGLFW_SetWindowSizeCmd;
Tcl_ObjCmdProc TclGLFW_SetWindowPosCmd;
Tcl_ObjCmdProc TclGLFW_GetWindowParamCmd;
Tcl_ObjCmdProc TclGLFW_GetWindowSizeCmd;
Tcl_ObjCmdProc TclGLFW_GetMousePosCmd;
Tcl_ObjCmdProc TclGLFW_GetVideoModesCmd;
Tcl_ObjCmdProc TclGLFW_GetDesktopModeCmd;
Tcl_ObjCmdProc TclGLFW_SwapBuffersCmd;
Tcl_ObjCmdProc TclGLFW_SetKeyCallbackCmd;
Tcl_ObjCmdProc TclGLFW_SetMousePosCallbackCmd;
Tcl_ObjCmdProc TclGLFW_SetMouseButtonCallbackCmd;
Tcl_ObjCmdProc TclGLFW_SetMouseWheelCallbackCmd;
Tcl_ObjCmdProc TclGLFW_SetWindowSizeCallbackCmd;
Tcl_ObjCmdProc TclGLFW_SetWindowRefreshCallbackCmd;
Tcl_ObjCmdProc TclGLFW_SetWindowCloseCallbackCmd;
Tcl_ObjCmdProc TclGLFW_GetKeyCmd;
Tcl_ObjCmdProc TclGLFW_EnableCmd;
Tcl_ObjCmdProc TclGLFW_DisableCmd;
Tcl_ObjCmdProc TclGLFW_DefaultCmd;
Tcl_ObjCmdProc TclGLFW_UnknownCmd;
Tcl_ObjCmdProc TclGLFW_glDrawPixelsCmd;
Tcl_ObjCmdProc TclGLFW_DrawMegaimageCmd;
Tcl_ObjCmdProc TclGLFW_glClearColorCmd;
Tcl_ObjCmdProc TclGLFW_glClearCmd;
Tcl_ObjCmdProc TclGLFW_glFlushCmd;

typedef struct GLFWMethod {
    char* name;              /* method name */
    char* usage;             /* string describing usage */
    Tcl_ObjCmdProc *proc;    /* implementation C proc */
} GLFWMethod;

static GLFWMethod GLFWMethodList[] = {
    { "init", "", TclGLFW_InitCmd },
    { "terminate", "", TclGLFW_TerminateCmd },
    { "enable", "param", TclGLFW_EnableCmd },
    { "disable", "param", TclGLFW_DisableCmd },
    { "openWindowHint", "target hint", TclGLFW_OpenWindowHintCmd },
    { "openWindow", "width height", TclGLFW_OpenWindowCmd },
    { "closeWindow", "", TclGLFW_CloseWindowCmd },
    { "setWindowTitle", "title", TclGLFW_SetWindowTitleCmd },
    { "setWindowSize", "width height", TclGLFW_SetWindowSizeCmd },
    { "setWindowPos", "x y", TclGLFW_SetWindowPosCmd },
    { "getWindowParam", "paramName", TclGLFW_GetWindowParamCmd },
    { "getWindowSize", "", TclGLFW_GetWindowSizeCmd },
    { "getMousePos", "", TclGLFW_GetMousePosCmd },
    { "getVideoModes", "??", TclGLFW_GetVideoModesCmd },
    { "getDesktopMode", "??", TclGLFW_GetDesktopModeCmd },
    { "swapBuffers", "", TclGLFW_SwapBuffersCmd },
    { "getKey", "keyName", TclGLFW_GetKeyCmd },
    { "setKeyCallback", "functionName", TclGLFW_SetKeyCallbackCmd },
    { "setMousePosCallback", "functionName",
            TclGLFW_SetMousePosCallbackCmd },
    { "setMouseButtonCallback", "functionName",
            TclGLFW_SetMouseButtonCallbackCmd },
    { "setWindowSizeCallback", "functionName",
            TclGLFW_SetWindowSizeCallbackCmd },
    { "setWindowRefreshCallback", "functionName",
            TclGLFW_SetWindowRefreshCallbackCmd },
    { "setWindowcloseCallback", "functionName",
            TclGLFW_SetWindowCloseCallbackCmd },
    { "setMouseWheelCallback", "??", TclGLFW_SetMouseWheelCallbackCmd },
    { "glDrawPixels", "width height <pixel-list>", TclGLFW_glDrawPixelsCmd },
    { "drawMegaimage", "width height <pixel-list>", TclGLFW_DrawMegaimageCmd },
    { "glClearColor", "redVal greenVal blueVal alphaVal",
            TclGLFW_glClearColorCmd },
    { "glClear", "", TclGLFW_glClearCmd },
    { "glFlush", "", TclGLFW_glFlushCmd },
    /*
     *  Add an error handler to support all of the usual inquiries
     *  for the "info" command in the global namespace.
     */
    { "@error", "", TclGLFW_DefaultCmd },
    { NULL, NULL, NULL }
};

struct NameProcMap { const char *name; Tcl_ObjCmdProc *proc; };

/*
 * List of commands that are used to implement the [ntk glfw] subcommands.
 */

static const struct NameProcMap glfwCmds2[] = {
    { "::ntk::glfw::GLFW::init", TclGLFW_InitCmd },
    { "::ntk::glfw::GLFW::terminate", TclGLFW_TerminateCmd },
    { "::ntk::glfw::GLFW::enable", TclGLFW_EnableCmd },
    { "::ntk::glfw::GLFW::disable", TclGLFW_DisableCmd },
    { "::ntk::glfw::GLFW::openWindow", TclGLFW_OpenWindowCmd },
    { "::ntk::glfw::GLFW::openWindowHint", TclGLFW_OpenWindowHintCmd },
    { "::ntk::glfw::GLFW::closeWindow", TclGLFW_CloseWindowCmd },
    { "::ntk::glfw::GLFW::setWindowTitle", TclGLFW_SetWindowTitleCmd },
    { "::ntk::glfw::GLFW::setWindowPos", TclGLFW_SetWindowPosCmd },
    { "::ntk::glfw::GLFW::setWindowSize", TclGLFW_SetWindowSizeCmd },
    { "::ntk::glfw::GLFW::getWindowParam", TclGLFW_GetWindowParamCmd },
    { "::ntk::glfw::GLFW::getWindowSize", TclGLFW_GetWindowSizeCmd },
    { "::ntk::glfw::GLFW::getMousePos", TclGLFW_GetMousePosCmd },
    { "::ntk::glfw::GLFW::getVideoModes", TclGLFW_GetVideoModesCmd },
    { "::ntk::glfw::GLFW::getDesktopMode", TclGLFW_GetDesktopModeCmd },
    { "::ntk::glfw::GLFW::swapBuffers", TclGLFW_SwapBuffersCmd },
    { "::ntk::glfw::GLFW::getKey", TclGLFW_GetKeyCmd },
    { "::ntk::glfw::GLFW::setKeyCallback", TclGLFW_SetKeyCallbackCmd },
    { "::ntk::glfw::GLFW::setMousePosCallback", 
            TclGLFW_SetMousePosCallbackCmd },
    { "::ntk::glfw::GLFW::setMouseButtonCallback", 
            TclGLFW_SetMouseButtonCallbackCmd },
    { "::ntk::glfw::GLFW::setMouseWheelCallback",
            TclGLFW_SetMouseWheelCallbackCmd },
    { "::ntk::glfw::GLFW::setWindowSizeCallback",
            TclGLFW_SetWindowSizeCallbackCmd },
    { "::ntk::glfw::GLFW::setWindowRefreshCallback",
            TclGLFW_SetWindowRefreshCallbackCmd },
    { "::ntk::glfw::GLFW::setWindowCloseCallback",
            TclGLFW_SetWindowCloseCallbackCmd },
    { "::ntk::glfw::GLFW::unknown", TclGLFW_UnknownCmd },
    { "::ntk::glfw::GLFW::glDrawPixels", TclGLFW_glDrawPixelsCmd },
    { "::ntk::glfw::GLFW::drawMegaimage", TclGLFW_DrawMegaimageCmd },
    { "::ntk::glfw::GLFW::glClearColor", TclGLFW_glClearColorCmd },
    { "::ntk::glfw::GLFW::glClear", TclGLFW_glClearCmd },
    { "::ntk::glfw::GLFW::glFlush", TclGLFW_glFlushCmd },
    /*
     *  Add an error handler
     */
    { "::ntk::glfw::GlfW::@error", TclGLFW_DefaultCmd },
    { NULL, NULL }
};

/*
 * ------------------------------------------------------------------------
 *  TclGLFW_InitCommands()
 *
 *      that is the starting point when loading the library
 *      it initializes all internal stuff
 *
 * ------------------------------------------------------------------------
 */

int
TclGLFW_InitCommands (
    Tcl_Interp *interp,
    TclGLFWInfo *infoPtr)
{
    Tcl_Namespace *nsPtr;
    Tcl_Command cmd;
    int i;

    /*
     * Build the ensemble used to implement [ntk glfw].
     */

    nsPtr = Tcl_CreateNamespace(interp, "::ntk::glfw::GLFW", NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("ITCL: error in creating namespace: ::ntk::glfw::GLFW \n");
    }
    cmd = Tcl_CreateEnsemble(interp, nsPtr->fullName, nsPtr,
        TCL_ENSEMBLE_PREFIX);
    Tcl_Export(interp, nsPtr, "[a-z]*", 1);
    for (i=0 ; glfwCmds2[i].name!=NULL ; i++) {
        Tcl_CreateObjCommand(interp, glfwCmds2[i].name,
                glfwCmds2[i].proc, infoPtr, NULL);
    }
    Tcl_Obj *ensObjPtr = Tcl_NewStringObj("::ntk::glfw::GLFW", -1);
    Tcl_IncrRefCount(ensObjPtr);
    Tcl_Obj *unkObjPtr = Tcl_NewStringObj("::ntk::glfw::GLFW::unknown", -1);
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
 *  TclGLFWGetUsage()
 *
 * ------------------------------------------------------------------------
  */
void
TclGLFWGetUsage(
    Tcl_Interp *interp,
    Tcl_Obj *objPtr)       /* returns: summary of usage info */
{
    char *spaces = "  ";

    int i;

    for (i=0; GLFWMethodList[i].name != NULL; i++) {
        Tcl_AppendToObj(objPtr, spaces, -1);
        Tcl_AppendToObj(objPtr, "ntk glfw ", -1);
        Tcl_AppendToObj(objPtr, GLFWMethodList[i].name, -1);
        if (strlen(GLFWMethodList[i].usage) > 0) {
            Tcl_AppendToObj(objPtr, " ", -1);
            Tcl_AppendToObj(objPtr, GLFWMethodList[i].usage, -1);
	}
        spaces = "\n  ";
    }
}

/*
 * ------------------------------------------------------------------------
 *  TclGLFW_UnknownCmd()
 *
 *  the unknown handler for the ::itcl::builtin::Info ensemble
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_UnknownCmd(
    ClientData dummy,        /* not used */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int result;

    TclGLFWShowArgs(0, "TclGLFW_UnknownCmd", objc, objv);
    result = TCL_ERROR;
    /* produce usage message */
    Tcl_Obj *objPtr = Tcl_NewStringObj("unknown command: \"", -1);
    Tcl_AppendToObj(objPtr, Tcl_GetString(objv[2]), -1);
    Tcl_AppendToObj(objPtr, "\" should be one of...\n", -1);
    TclGLFWGetUsage(interp, objPtr);
    Tcl_SetResult(interp, Tcl_GetString(objPtr), TCL_DYNAMIC);
    return TCL_ERROR;
}

static Tcl_Interp *_interp;

/*
 * ------------------------------------------------------------------------
 *  TclGLFW_InitCmd()
 *
 *  Handles the GLFW init command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_InitCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWShowArgs(1, "TclGLFW_InitCmd", objc, objv);
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
 *  TclGLFW_TerminateCmd()
 *
 *  Handles the GLFW terminate command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_TerminateCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWShowArgs(1, "TclGLFW_TerminateCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw terminate\"",
	        NULL);
        return TCL_ERROR;
    }
    glfwTerminate();
/* FIX ME have to free the TclGLFWWindow structure(s) here !! */
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLFW_OpenWindowCmd()
 *
 *  Handles the GLFW openWindow command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_OpenWindowCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLFWInfo *infoPtr;
    TclGLFWWindow *winPtr;
    int isNew;
    int width;
    int height;
    int result;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_OpenWindowCmd", objc, objv);
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
    winPtr = (TclGLFWWindow *)ckalloc(sizeof(TclGLFWWindow));
    memset(winPtr, 0, sizeof(TclGLFWWindow));
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
 *  TclGLFW_CloseWindowCmd()
 *
 *  Handles the GLFW closeWindow command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_CloseWindowCmd(
    ClientData clientData, /* not used */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_CloseWindowCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw closeWindow\"",
	        NULL);
        return TCL_ERROR;
    }
    glfwCloseWindow();
/* FIX ME have to free the TclGLFWWindow structure here !! */
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLFW_OpenWindowHintCmd()
 *
 *  Handles the GLFW openWindowHint command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_OpenWindowHintCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    int target;
    int hint;
    const char *token;

    TclGLFWShowArgs(1, "TclGLFW_OpenWindowHintCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw openWindowHint <target> <hint>\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    target = TclGLFWWindowHint2Define(token);
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
 *  TclGLFW_SetWindowTitleCmd()
 *
 *  Handles the GLFW setWindowTitle command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGLFW_SetWindowTitleCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_SetWindowTitleCmd", objc, objv);
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
 *  TclGLFW_SetWindowSizeCmd()
 *
 *  Handles the GLFW setWindowSize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGLFW_SetWindowSizeCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;
    int width;
    int height;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_SetWindowSizeCmd", objc, objv);
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
 *  TclGLFW_GetWindowSizeCmd()
 *
 *  Handles the GLFW getWindowSize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGLFW_GetWindowSizeCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;
    int width;
    int height;
    Tcl_Obj *listPtr;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_GetWindowSizeCmd", objc, objv);
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
 *  TclGLFW_GetMousePosCmd()
 *
 *  Handles the GLFW getMousePos command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGLFW_GetMousePosCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_Obj *listPtr;
    TclGLFWInfo *infoPtr;
    int x;
    int y;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_GetMousePosCmd", objc, objv);
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
 *  TclGLFW_GetVideoModesCmd()
 *
 *  Handles the GLFW getVideoModes command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGLFW_GetVideoModesCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_Obj *listPtr;
    Tcl_Obj *listPtr2;
    TclGLFWInfo *infoPtr;
    GLFWvidmode *modePtr;
    GLFWvidmode mode;
    int numModes;
    int i;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_GetVideoModesCmd", objc, objv);
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
 *  TclGLFW_GetDesktopModeCmd()
 *
 *  Handles the GLFW getDesktopMode command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGLFW_GetDesktopModeCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_Obj *listPtr;
    TclGLFWInfo *infoPtr;
    GLFWvidmode *modePtr;
    GLFWvidmode mode;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_GetDesktopModeCmd", objc, objv);
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
 *  TclGLFW_SetWindowPosCmd()
 *
 *  Handles the GLFW setWindowPos command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGLFW_SetWindowPosCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;
    int x;
    int y;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_SetWindowPosCmd", objc, objv);
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
 *  TclGLFW_EnableCmd()
 *
 *  Handles the GLFW enable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_EnableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;
    const char *token;
    int param;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_EnableCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw enable param\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    param = TclGLFWEnableParam2Define(token);
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
 *  TclGLFW_DisableCmd()
 *
 *  Handles the GLFW disable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_DisableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;
    const char *token;
    int param;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_DisableCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw disable param\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    param = TclGLFWEnableParam2Define(token);
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
 *  TclGLFW_GetWindowParamCmd()
 *
 *  Handles the GLFW getWindowParam command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_GetWindowParamCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;
    const char *token;
    int param;
    int value;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_GetWindowParamCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw getWindowParam paramName\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    param = TclGLFWWindowParam2Define(token);
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
 *  TclGLFW_SwapBuffersCmd()
 *
 *  Handles the GLFW swapBuffers command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_SwapBuffersCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_SwapBuffersCmd", objc, objv);
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
 *  TclGLFW_GetKeyCmd()
 *
 *  Handles the GLFW getKey command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_GetKeyCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;
    const char *token;
    int key;
    int value;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_GetKeyCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw getKey <char>|<key string>\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    if (strlen(token) > 1) {
        key = TclGLFWKey2Define(Tcl_GetString(objv[1]));
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
    TclGLFWWindow *winPtr;
    TclGLFWInfo *infoPtr;
    int result;

    infoPtr = Tcl_GetAssocData(_interp, TCL_GLFW_INTERP_DATA, NULL);
    winPtr = infoPtr->currWindow;
    objPtr = TclGLFWDefine2Key(key);
//fprintf(stderr, "DispatchKey!%s!%d!%d!\n", objPtr == NULL ? "(nil)" : Tcl_GetString(objPtr), key, state);
    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    keyPtr = Tcl_NewIntObj (key);
    Tcl_IncrRefCount (keyPtr);
    statePtr = Tcl_NewIntObj (state);
    Tcl_IncrRefCount (statePtr);
    Tcl_ListObjAppendElement (_interp, listPtr, winPtr->keyCallback);
    Tcl_ListObjAppendElement(_interp, listPtr, keyPtr);
    Tcl_ListObjAppendElement(_interp, listPtr, statePtr);
//fprintf(stderr, "CALL!%s!\n", Tcl_GetString(listPtr));
    result = Tcl_GlobalEvalObj (_interp, listPtr);
    Tcl_DecrRefCount (listPtr);
    Tcl_DecrRefCount (keyPtr);
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
    TclGLFWWindow *winPtr;
    TclGLFWInfo *infoPtr;
    int result;

    infoPtr = Tcl_GetAssocData(_interp, TCL_GLFW_INTERP_DATA, NULL);
    winPtr = infoPtr->currWindow;
    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    xPtr = Tcl_NewIntObj (x);
    Tcl_IncrRefCount (xPtr);
    yPtr = Tcl_NewIntObj (y);
    Tcl_IncrRefCount (yPtr);
    Tcl_ListObjAppendElement (_interp, listPtr, winPtr->mousePosCallback);
    Tcl_ListObjAppendElement(_interp, listPtr, xPtr);
    Tcl_ListObjAppendElement(_interp, listPtr, yPtr);
    result = Tcl_GlobalEvalObj (_interp, listPtr);
    Tcl_DecrRefCount (xPtr);
    Tcl_DecrRefCount (yPtr);
    Tcl_DecrRefCount (listPtr);
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
    TclGLFWWindow *winPtr;
    TclGLFWInfo *infoPtr;
    int result;

    infoPtr = Tcl_GetAssocData(_interp, TCL_GLFW_INTERP_DATA, NULL);
    winPtr = infoPtr->currWindow;
    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    whichPtr = Tcl_NewIntObj (which);
    Tcl_IncrRefCount (whichPtr);
    whatPtr = Tcl_NewIntObj (what);
    Tcl_IncrRefCount (whatPtr);
    Tcl_ListObjAppendElement (_interp, listPtr, winPtr->mouseButtonCallback);
    Tcl_ListObjAppendElement(_interp, listPtr, whichPtr);
    Tcl_ListObjAppendElement(_interp, listPtr, whatPtr);
    result = Tcl_GlobalEvalObj (_interp, listPtr);
    Tcl_DecrRefCount (whichPtr);
    Tcl_DecrRefCount (whatPtr);
    Tcl_DecrRefCount (listPtr);
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
    TclGLFWWindow *winPtr;
    TclGLFWInfo *infoPtr;
    int result;

    infoPtr = Tcl_GetAssocData(_interp, TCL_GLFW_INTERP_DATA, NULL);
    winPtr = infoPtr->currWindow;
    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    wherePtr = Tcl_NewIntObj (where);
    Tcl_IncrRefCount (wherePtr);
    Tcl_ListObjAppendElement (_interp, listPtr, winPtr->mouseWheelCallback);
    Tcl_ListObjAppendElement(_interp, listPtr, wherePtr);
    result = Tcl_GlobalEvalObj (_interp, listPtr);
    Tcl_DecrRefCount (wherePtr);
    Tcl_DecrRefCount (listPtr);
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
    TclGLFWWindow *winPtr;
    TclGLFWInfo *infoPtr;
    int result;

    infoPtr = Tcl_GetAssocData(_interp, TCL_GLFW_INTERP_DATA, NULL);
    winPtr = infoPtr->currWindow;
    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    widthPtr = Tcl_NewIntObj (width);
    Tcl_IncrRefCount (widthPtr);
    heightPtr = Tcl_NewIntObj (height);
    Tcl_IncrRefCount (heightPtr);
    Tcl_ListObjAppendElement (_interp, listPtr, winPtr->windowSizeCallback);
    Tcl_ListObjAppendElement(_interp, listPtr, widthPtr);
    Tcl_ListObjAppendElement(_interp, listPtr, heightPtr);
    result = Tcl_GlobalEvalObj (_interp, listPtr);
    Tcl_DecrRefCount (widthPtr);
    Tcl_DecrRefCount (heightPtr);
    Tcl_DecrRefCount (listPtr);
}

/*
 * ------------------------------------------------------------------------
 *  DispatchWindowRefresh()
 *
 *  Handles the GLFW dispatching of window refreshing
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchWindowRefresh(
    void)
{
    Tcl_Obj *listPtr;
    TclGLFWWindow *winPtr;
    TclGLFWInfo *infoPtr;
    int result;

    infoPtr = Tcl_GetAssocData(_interp, TCL_GLFW_INTERP_DATA, NULL);
    winPtr = infoPtr->currWindow;
    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    Tcl_ListObjAppendElement (_interp, listPtr, winPtr->windowRefreshCallback);
    result = Tcl_GlobalEvalObj (_interp, listPtr);
    Tcl_DecrRefCount (listPtr);
}

/*
 * ------------------------------------------------------------------------
 *  DispatchWindowClose()
 *
 *  Handles the GLFW dispatching of window closing
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchWindowClose(
    int width,
    int height)
{
    Tcl_Obj *listPtr;
    TclGLFWWindow *winPtr;
    TclGLFWInfo *infoPtr;
    int result;

    infoPtr = Tcl_GetAssocData(_interp, TCL_GLFW_INTERP_DATA, NULL);
    winPtr = infoPtr->currWindow;
    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    Tcl_ListObjAppendElement (_interp, listPtr, winPtr->windowCloseCallback);
    result = Tcl_GlobalEvalObj (_interp, listPtr);
    Tcl_DecrRefCount (listPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLFW_SetKeyCallbackCmd()
 *
 *  Handles the GLFW setKeyCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_SetKeyCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLFWWindow *winPtr;
    TclGLFWInfo *infoPtr;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_SetKeyCallbackCmd", objc, objv);
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
 *  TclGLFW_SetMousePosCallbackCmd()
 *
 *  Handles the GLFW setMousePosCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_SetMousePosCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLFWWindow *winPtr;
    TclGLFWInfo *infoPtr;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_SetMousePosCallbackCmd", objc, objv);
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
 *  TclGLFW_SetMouseButtonCallbackCmd()
 *
 *  Handles the GLFW setMouseButtonCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_SetMouseButtonCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLFWWindow *winPtr;
    TclGLFWInfo *infoPtr;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_SetMouseButtonCallbackCmd", objc, objv);
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
 *  TclGLFW_SetMouseWheelCallbackCmd()
 *
 *  Handles the GLFW setMouseWheelCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_SetMouseWheelCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLFWWindow *winPtr;
    TclGLFWInfo *infoPtr;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_SetMouseWheelCallbackCmd", objc, objv);
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
 *  TclGLFW_SetWindowSizeCallbackCmd()
 *
 *  Handles the GLFW setWindowSizeCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_SetWindowSizeCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLFWWindow *winPtr;
    TclGLFWInfo *infoPtr;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_SetWindowSizeCallbackCmd", objc, objv);
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
 *  TclGLFW_SetWindowRefreshCallbackCmd()
 *
 *  Handles the GLFW setWindowRefreshCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_SetWindowRefreshCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLFWWindow *winPtr;
    TclGLFWInfo *infoPtr;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_SetWindowRefreshCallbackCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw setWindowRefreshCallback windowHandle function\"",
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
    winPtr->windowRefreshCallback = objv[2];
    Tcl_IncrRefCount(winPtr->windowRefreshCallback);
    glfwSetWindowRefreshCallback(DispatchWindowRefresh);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLFW_SetWindowCloseCallbackCmd()
 *
 *  Handles the GLFW setWindowCloseCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_SetWindowCloseCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLFWWindow *winPtr;
    TclGLFWInfo *infoPtr;

    infoPtr = (TclGLFWInfo *)clientData;
    TclGLFWShowArgs(1, "TclGLFW_SetWindowCloseCallbackCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw setWindowCloseCallback windowHandle function\"",
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
    winPtr->windowCloseCallback = objv[2];
    Tcl_IncrRefCount(winPtr->windowCloseCallback);
    glfwSetWindowSizeCallback(DispatchWindowClose);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLFW_DefaultCmd()
 *
 *  Handles any unknown options for the "ntk::glfw::GLFW" command
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_DefaultCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;
    int result;

    infoPtr = (TclGLFWInfo *)clientData;
    result = TCL_ERROR;
    TclGLFWShowArgs(0, "TclGLFW_DefaultCmd", objc, objv);
//    TclGLFW_GetEnsembleUsageForObj(interp, objv[0], resultPtr);
    return result;
}

#include <GL/gl.h>
/*
 * ------------------------------------------------------------------------
 *  TclGLFW_glDrawPixelsCmd()
 *
 *  Handles drawing of a pixel area with rgba values
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_glDrawPixelsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;
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

    infoPtr = (TclGLFWInfo *)clientData;
    result = TCL_OK;
    TclGLFWShowArgs(1, "TclGLFW_glDrawPixelsCmd", objc, objv);
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
 *  TclGLFW_glClearColorCmd()
 *
 *  Handles clearing of color buffer
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_glClearColorCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;
    double redVal;
    double greenVal;
    double blueVal;
    double alphaVal;
    int result;

    infoPtr = (TclGLFWInfo *)clientData;
    result = TCL_OK;
    TclGLFWShowArgs(1, "TclGLFW_glClearColorCmd", objc, objv);
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
 *  TclGLFW_glClearCmd()
 *
 *  Handles drawing of a pixel area with rgba values
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_glClearCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;
    const char *token;
    int param;
    int result;

    infoPtr = (TclGLFWInfo *)clientData;
    result = TCL_OK;
    TclGLFWShowArgs(1, "TclGLFW_glClearCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw glClear value\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
/* FIX ME !! */
//    param = TclGLFWGlKey2Define(token);
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
 *  TclGLFW_glFlushCmd()
 *
 *  Handles flush the buffers
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_glFlushCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;
    int result;

    infoPtr = (TclGLFWInfo *)clientData;
    result = TCL_OK;
    TclGLFWShowArgs(1, "TclGLFW_glFlushCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw glFlush\"",
	        NULL);
        return TCL_ERROR;
    }
    glFlush();
    return result;
}

#include "/home/arnulf/SOURCES/MEGAIMAGE/megapkg/csrc/include/megaimage_shared.h"
/*
 * ------------------------------------------------------------------------
 *  TclGLFW_DrawMegaimageCmd()
 *
 *  Handles drawing of a pixel area with rgba values
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLFW_DrawMegaimageCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLFWInfo *infoPtr;
    struct megaimage_header megaimageHeader;
    unsigned char *hdPtr;
    unsigned char *data;
    int lgth;
    int result;

    infoPtr = (TclGLFWInfo *)clientData;
    result = TCL_OK;
    TclGLFWShowArgs(1, "TclGLFW_DrawMegaimageCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glfw drawMegaimage data\"",
	        NULL);
        return TCL_ERROR;
    }
    hdPtr = Tcl_GetByteArrayFromObj(objv[1], &lgth);
    memcpy(&megaimageHeader, hdPtr, sizeof(struct megaimage_header));
    data = hdPtr + sizeof(struct megaimage_header);
//    glGet(GL_CURRENT_RASTER_POSITION);
    glDrawPixels(megaimageHeader.width, megaimageHeader.height,
            GL_RGBA, GL_UNSIGNED_BYTE, data);
#ifdef NOTDEF
    glRotatef(5.0f,0.0f,0.0f,1.0f);
    glRotatef(5.0f,0.0f,1.0f,0.0f);
    glRotatef(5.0f,1.0f,0.0f,0.0f);
#endif
    return result;
}
