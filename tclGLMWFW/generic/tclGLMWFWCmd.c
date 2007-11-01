/*
 * tclGLMWFWCmd.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the GLMWFW OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLMWFWCmd.c,v 1.1.2.1 2007/11/01 14:05:14 wiede Exp $
 */

#include <stdlib.h>
#include "tclGLMWFWInt.h"

Tcl_ObjCmdProc TclGLMWFW_InitCmd;
Tcl_ObjCmdProc TclGLMWFW_TerminateCmd;
Tcl_ObjCmdProc TclGLMWFW_OpenWindowHintCmd;
Tcl_ObjCmdProc TclGLMWFW_OpenWindowCmd;
Tcl_ObjCmdProc TclGLMWFW_CloseWindowCmd;
Tcl_ObjCmdProc TclGLMWFW_SetWindowTitleCmd;
Tcl_ObjCmdProc TclGLMWFW_SetWindowSizeCmd;
Tcl_ObjCmdProc TclGLMWFW_SetWindowPosCmd;
Tcl_ObjCmdProc TclGLMWFW_GetWindowParamCmd;
Tcl_ObjCmdProc TclGLMWFW_GetWindowSizeCmd;
Tcl_ObjCmdProc TclGLMWFW_GetMousePosCmd;
Tcl_ObjCmdProc TclGLMWFW_GetVideoModesCmd;
Tcl_ObjCmdProc TclGLMWFW_GetDesktopModeCmd;
Tcl_ObjCmdProc TclGLMWFW_SwapBuffersCmd;
Tcl_ObjCmdProc TclGLMWFW_SetKeyCallbackCmd;
Tcl_ObjCmdProc TclGLMWFW_SetMousePosCallbackCmd;
Tcl_ObjCmdProc TclGLMWFW_SetMouseButtonCallbackCmd;
Tcl_ObjCmdProc TclGLMWFW_SetMouseWheelCallbackCmd;
Tcl_ObjCmdProc TclGLMWFW_SetWindowSizeCallbackCmd;
Tcl_ObjCmdProc TclGLMWFW_SetWindowRefreshCallbackCmd;
Tcl_ObjCmdProc TclGLMWFW_SetWindowCloseCallbackCmd;
Tcl_ObjCmdProc TclGLMWFW_GetKeyCmd;
Tcl_ObjCmdProc TclGLMWFW_EnableCmd;
Tcl_ObjCmdProc TclGLMWFW_DisableCmd;
Tcl_ObjCmdProc TclGLMWFW_DefaultCmd;
Tcl_ObjCmdProc TclGLMWFW_UnknownCmd;
Tcl_ObjCmdProc TclGLMWFW_WaitEventsCmd;
Tcl_ObjCmdProc TclGLMWFW_DrawMegaimageCmd;

typedef struct GLMWFWMethod {
    char* name;              /* method name */
    char* usage;             /* string describing usage */
    Tcl_ObjCmdProc *proc;    /* implementation C proc */
} GLMWFWMethod;

static GLMWFWMethod GLMWFWMethodList[] = {
    { "init", "", TclGLMWFW_InitCmd },
    { "terminate", "", TclGLMWFW_TerminateCmd },
    { "enable", "param", TclGLMWFW_EnableCmd },
    { "disable", "param", TclGLMWFW_DisableCmd },
    { "openWindowHint", "target hint", TclGLMWFW_OpenWindowHintCmd },
    { "openWindow", "width height", TclGLMWFW_OpenWindowCmd },
    { "closeWindow", "", TclGLMWFW_CloseWindowCmd },
    { "setWindowTitle", "title", TclGLMWFW_SetWindowTitleCmd },
    { "setWindowSize", "width height", TclGLMWFW_SetWindowSizeCmd },
    { "setWindowPos", "x y", TclGLMWFW_SetWindowPosCmd },
    { "getWindowParam", "paramName", TclGLMWFW_GetWindowParamCmd },
    { "getWindowSize", "", TclGLMWFW_GetWindowSizeCmd },
    { "getMousePos", "", TclGLMWFW_GetMousePosCmd },
    { "getVideoModes", "??", TclGLMWFW_GetVideoModesCmd },
    { "getDesktopMode", "??", TclGLMWFW_GetDesktopModeCmd },
    { "swapBuffers", "", TclGLMWFW_SwapBuffersCmd },
    { "getKey", "keyName", TclGLMWFW_GetKeyCmd },
    { "setKeyCallback", "functionName", TclGLMWFW_SetKeyCallbackCmd },
    { "setMousePosCallback", "functionName",
            TclGLMWFW_SetMousePosCallbackCmd },
    { "setMouseButtonCallback", "functionName",
            TclGLMWFW_SetMouseButtonCallbackCmd },
    { "setWindowSizeCallback", "functionName",
            TclGLMWFW_SetWindowSizeCallbackCmd },
    { "setWindowRefreshCallback", "functionName",
            TclGLMWFW_SetWindowRefreshCallbackCmd },
    { "setWindowcloseCallback", "functionName",
            TclGLMWFW_SetWindowCloseCallbackCmd },
    { "setMouseWheelCallback", "functionName",
            TclGLMWFW_SetMouseWheelCallbackCmd },
    { "waitEvents", "", TclGLMWFW_WaitEventsCmd },
    { "drawMegaimage", "width height <pixel-list>", TclGLMWFW_DrawMegaimageCmd },
    /*
     *  Add an error handler to support all of the usual inquiries
     *  for the "info" command in the global namespace.
     */
    { "@error", "", TclGLMWFW_DefaultCmd },
    { NULL, NULL, NULL }
};

struct NameProcMap { const char *name; Tcl_ObjCmdProc *proc; };

/*
 * List of commands that are used to implement the [ntk glmwfw] subcommands.
 */

static const struct NameProcMap glmwfwCmds2[] = {
    { "::ntk::glmwfw::GLMWFW::init", TclGLMWFW_InitCmd },
    { "::ntk::glmwfw::GLMWFW::terminate", TclGLMWFW_TerminateCmd },
    { "::ntk::glmwfw::GLMWFW::enable", TclGLMWFW_EnableCmd },
    { "::ntk::glmwfw::GLMWFW::disable", TclGLMWFW_DisableCmd },
    { "::ntk::glmwfw::GLMWFW::openWindow", TclGLMWFW_OpenWindowCmd },
    { "::ntk::glmwfw::GLMWFW::openWindowHint", TclGLMWFW_OpenWindowHintCmd },
    { "::ntk::glmwfw::GLMWFW::closeWindow", TclGLMWFW_CloseWindowCmd },
    { "::ntk::glmwfw::GLMWFW::setWindowTitle", TclGLMWFW_SetWindowTitleCmd },
    { "::ntk::glmwfw::GLMWFW::setWindowPos", TclGLMWFW_SetWindowPosCmd },
    { "::ntk::glmwfw::GLMWFW::setWindowSize", TclGLMWFW_SetWindowSizeCmd },
    { "::ntk::glmwfw::GLMWFW::getWindowParam", TclGLMWFW_GetWindowParamCmd },
    { "::ntk::glmwfw::GLMWFW::getWindowSize", TclGLMWFW_GetWindowSizeCmd },
    { "::ntk::glmwfw::GLMWFW::getMousePos", TclGLMWFW_GetMousePosCmd },
    { "::ntk::glmwfw::GLMWFW::getVideoModes", TclGLMWFW_GetVideoModesCmd },
    { "::ntk::glmwfw::GLMWFW::getDesktopMode", TclGLMWFW_GetDesktopModeCmd },
    { "::ntk::glmwfw::GLMWFW::swapBuffers", TclGLMWFW_SwapBuffersCmd },
    { "::ntk::glmwfw::GLMWFW::getKey", TclGLMWFW_GetKeyCmd },
    { "::ntk::glmwfw::GLMWFW::setKeyCallback", TclGLMWFW_SetKeyCallbackCmd },
    { "::ntk::glmwfw::GLMWFW::setMousePosCallback", 
            TclGLMWFW_SetMousePosCallbackCmd },
    { "::ntk::glmwfw::GLMWFW::setMouseButtonCallback", 
            TclGLMWFW_SetMouseButtonCallbackCmd },
    { "::ntk::glmwfw::GLMWFW::setMouseWheelCallback",
            TclGLMWFW_SetMouseWheelCallbackCmd },
    { "::ntk::glmwfw::GLMWFW::setWindowSizeCallback",
            TclGLMWFW_SetWindowSizeCallbackCmd },
    { "::ntk::glmwfw::GLMWFW::setWindowRefreshCallback",
            TclGLMWFW_SetWindowRefreshCallbackCmd },
    { "::ntk::glmwfw::GLMWFW::setWindowCloseCallback",
            TclGLMWFW_SetWindowCloseCallbackCmd },
    { "::ntk::glmwfw::GLMWFW::waitEvents", TclGLMWFW_WaitEventsCmd },
    { "::ntk::glmwfw::GLMWFW::unknown", TclGLMWFW_UnknownCmd },
    { "::ntk::glmwfw::GLMWFW::drawMegaimage", TclGLMWFW_DrawMegaimageCmd },
    /*
     *  Add an error handler
     */
    { "::ntk::glmwfw::GlfW::@error", TclGLMWFW_DefaultCmd },
    { NULL, NULL }
};

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_InitCommands()
 *
 *      that is the starting point when loading the library
 *      it initializes all internal stuff
 *
 * ------------------------------------------------------------------------
 */

int
TclGLMWFW_InitCommands (
    Tcl_Interp *interp,
    TclGLMWFWInfo *infoPtr)
{
    Tcl_Namespace *nsPtr;
    Tcl_Command cmd;
    int i;

    /*
     * Build the ensemble used to implement [ntk glmwfw].
     */

    nsPtr = Tcl_CreateNamespace(interp, "::ntk::glmwfw::GLMWFW", NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("ITCL: error in creating namespace: ::ntk::glmwfw::GLMWFW \n");
    }
    cmd = Tcl_CreateEnsemble(interp, nsPtr->fullName, nsPtr,
        TCL_ENSEMBLE_PREFIX);
    Tcl_Export(interp, nsPtr, "[a-z]*", 1);
    for (i=0 ; glmwfwCmds2[i].name!=NULL ; i++) {
        Tcl_CreateObjCommand(interp, glmwfwCmds2[i].name,
                glmwfwCmds2[i].proc, infoPtr, NULL);
    }
    Tcl_Obj *ensObjPtr = Tcl_NewStringObj("::ntk::glmwfw::GLMWFW", -1);
    Tcl_IncrRefCount(ensObjPtr);
    Tcl_Obj *unkObjPtr = Tcl_NewStringObj("::ntk::glmwfw::GLMWFW::unknown", -1);
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
 *  TclGLMWFWGetUsage()
 *
 * ------------------------------------------------------------------------
  */
void
TclGLMWFWGetUsage(
    Tcl_Interp *interp,
    Tcl_Obj *objPtr)       /* returns: summary of usage info */
{
    char *spaces = "  ";

    int i;

    for (i=0; GLMWFWMethodList[i].name != NULL; i++) {
        Tcl_AppendToObj(objPtr, spaces, -1);
        Tcl_AppendToObj(objPtr, "ntk glmwfw ", -1);
        Tcl_AppendToObj(objPtr, GLMWFWMethodList[i].name, -1);
        if (strlen(GLMWFWMethodList[i].usage) > 0) {
            Tcl_AppendToObj(objPtr, " ", -1);
            Tcl_AppendToObj(objPtr, GLMWFWMethodList[i].usage, -1);
	}
        spaces = "\n  ";
    }
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_UnknownCmd()
 *
 *  the unknown handler for the ::itcl::builtin::Info ensemble
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_UnknownCmd(
    ClientData dummy,        /* not used */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int result;

    TclGLMWFWShowArgs(0, "TclGLMWFW_UnknownCmd", objc, objv);
    result = TCL_ERROR;
    /* produce usage message */
    Tcl_Obj *objPtr = Tcl_NewStringObj("unknown command: \"", -1);
    Tcl_AppendToObj(objPtr, Tcl_GetString(objv[2]), -1);
    Tcl_AppendToObj(objPtr, "\" should be one of...\n", -1);
    TclGLMWFWGetUsage(interp, objPtr);
    Tcl_SetResult(interp, Tcl_GetString(objPtr), TCL_DYNAMIC);
    return TCL_ERROR;
}


/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_InitCmd()
 *
 *  Handles the GLMWFW init command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_InitCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    /* NO LONGER NEEDED, call to glmwfwInit is done when loading package */
    TclGLMWFWShowArgs(1, "TclGLMWFW_InitCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw init\"",
	        NULL);
        return TCL_ERROR;
    }
    glmwfwInit();
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_TerminateCmd()
 *
 *  Handles the GLMWFW terminate command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_TerminateCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    FOREACH_HASH_DECLS;
    TclGLMWFWInfo *infoPtr;
    GLMWFWWindow *winPtr;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_TerminateCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw terminate\"",
	        NULL);
        return TCL_ERROR;
    }
    glmwfwTerminate();
    FOREACH_HASH_VALUE(winPtr, &infoPtr->windows) {
        Tcl_DecrRefCount(winPtr->handlePtr);
	ckfree((char *)winPtr);
    }
//TclDumpMemoryInfo(stderr);
//Tcl_DumpActiveMemory(NULL);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_OpenWindowCmd()
 *
 *  Handles the GLMWFW openWindow command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_OpenWindowCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLMWFWInfo *infoPtr;
    GLMWFWWindow *winPtr;
    int width;
    int height;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_OpenWindowCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw openWindow width height\"",
	        NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &width);
    Tcl_GetIntFromObj(interp, objv[2], &height);
    /* r = redbits, if 0 8 bits are used from the current glmwfw implementation */
    /* g = greenbits, see above */
    /* b = bluebits, see above */
    /* a = alphabits, see above */
    /* d = depthbits */
    /* s = stencilbits */
    /*                                                r g b a   d s */
    winPtr = glmwfwOpenWindow(infoPtr, width, height, 0,0,0,0, 16,0,
            GLMWFW_WINDOW);
    if (winPtr == NULL) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_CloseWindowCmd()
 *
 *  Handles the GLMWFW closeWindow command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_CloseWindowCmd(
    ClientData clientData, /* not used */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    TclGLMWFWInfo *infoPtr;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_CloseWindowCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw closeWindow window\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such window: \"", Tcl_GetString(objv[1]),
	        NULL);
	return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    glmwfwCloseWindow(winPtr);
/* FIX ME have to free the stuff in the GLMWFWWindow structure here !! */
    ckfree((char *)winPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_OpenWindowHintCmd()
 *
 *  Handles the GLMWFW openWindowHint command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_OpenWindowHintCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLMWFWInfo *infoPtr;
    GLMWFWWindow *winPtr;
    int target;
    int hint;
    const char *token;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_OpenWindowHintCmd", objc, objv);
    if (objc != 4) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw openWindowHint window <target> <hint>\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such window: \"", Tcl_GetString(objv[1]),
	        NULL);
	return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    token = Tcl_GetString(objv[2]);
    target = TclGLMWFWWindowHint2Define(token);
    if (target < 0) {
        Tcl_AppendResult(interp, "bad target in openWindowHint: \"", token,
	        "\"", NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[3], &hint);
    glmwfwOpenWindowHint(winPtr, target, hint);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_SetWindowTitleCmd()
 *
 *  Handles the GLMWFW setWindowTitle command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGLMWFW_SetWindowTitleCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    TclGLMWFWInfo *infoPtr;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_SetWindowTitleCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw setWindowTitle window title\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such window: \"", Tcl_GetString(objv[1]),
	        NULL);
	return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    glmwfwSetWindowTitle(winPtr, Tcl_GetString(objv[2]));
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_SetWindowSizeCmd()
 *
 *  Handles the GLMWFW setWindowSize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGLMWFW_SetWindowSizeCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    TclGLMWFWInfo *infoPtr;
    int width;
    int height;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_SetWindowSizeCmd", objc, objv);
    if (objc != 4) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw setWindowSize window width height\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such window: \"", Tcl_GetString(objv[1]),
	        NULL);
	return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    Tcl_GetIntFromObj(interp, objv[2], &width);
    Tcl_GetIntFromObj(interp, objv[3], &height);
    glmwfwSetWindowSize(winPtr, width, height);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_GetWindowSizeCmd()
 *
 *  Handles the GLMWFW getWindowSize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGLMWFW_GetWindowSizeCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    TclGLMWFWInfo *infoPtr;
    int width;
    int height;
    Tcl_Obj *listPtr;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_GetWindowSizeCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw getWindowSize window\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such window: \"", Tcl_GetString(objv[1]),
	        NULL);
	return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    glmwfwGetWindowSize(winPtr, &width, &height);
    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(width));
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(height));
    Tcl_SetObjResult(interp, listPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_GetMousePosCmd()
 *
 *  Handles the GLMWFW getMousePos command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGLMWFW_GetMousePosCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    Tcl_Obj *listPtr;
    TclGLMWFWInfo *infoPtr;
    int x;
    int y;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_GetMousePosCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw getMousePos window\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such window: \"", Tcl_GetString(objv[1]),
	        NULL);
	return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    glmwfwGetMousePos(winPtr, &x, &y);
    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(x));
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(y));
    Tcl_SetObjResult(interp, listPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_GetVideoModesCmd()
 *
 *  Handles the GLMWFW getVideoModes command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGLMWFW_GetVideoModesCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_Obj *listPtr;
    Tcl_Obj *listPtr2;
    Tcl_Obj *widthPtr;
    Tcl_Obj *heightPtr;
    Tcl_Obj *redBitsPtr;
    Tcl_Obj *greenBitsPtr;
    Tcl_Obj *blueBitsPtr;
    TclGLMWFWInfo *infoPtr;
    GLMWFWvidmode *modePtr;
    GLMWFWvidmode mode;
    int numModes;
    int i;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_GetVideoModesCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw getVideoModes\"",
	        NULL);
        return TCL_ERROR;
    }
    modePtr = (GLMWFWvidmode *)ckalloc(sizeof(GLMWFWvidmode)*200);
    numModes = glmwfwGetVideoModes(infoPtr, modePtr, 200);
    listPtr = Tcl_NewListObj(0, NULL);
    for(i=0; i<numModes;i++) {
        mode = modePtr[i];
        listPtr2 = Tcl_NewListObj(0, NULL);
	Tcl_IncrRefCount(listPtr2);
	heightPtr = Tcl_NewIntObj(mode.Height);
	Tcl_IncrRefCount(heightPtr);
	widthPtr = Tcl_NewIntObj(mode.Width);
	Tcl_IncrRefCount(widthPtr);
	redBitsPtr = Tcl_NewIntObj(mode.RedBits);
	Tcl_IncrRefCount(redBitsPtr);
	greenBitsPtr = Tcl_NewIntObj(mode.GreenBits);
	Tcl_IncrRefCount(greenBitsPtr);
	blueBitsPtr = Tcl_NewIntObj(mode.BlueBits);
	Tcl_IncrRefCount(blueBitsPtr);
        Tcl_ListObjAppendElement(interp, listPtr2, heightPtr);
        Tcl_ListObjAppendElement(interp, listPtr2, widthPtr);
        Tcl_ListObjAppendElement(interp, listPtr2, redBitsPtr);
        Tcl_ListObjAppendElement(interp, listPtr2, greenBitsPtr);
        Tcl_ListObjAppendElement(interp, listPtr2, blueBitsPtr);
        Tcl_ListObjAppendElement(interp, listPtr, listPtr2);
	Tcl_DecrRefCount(listPtr2);
	Tcl_DecrRefCount(heightPtr);
	Tcl_DecrRefCount(widthPtr);
	Tcl_DecrRefCount(redBitsPtr);
	Tcl_DecrRefCount(greenBitsPtr);
	Tcl_DecrRefCount(blueBitsPtr);
    }
    Tcl_SetObjResult(interp, listPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_GetDesktopModeCmd()
 *
 *  Handles the GLMWFW getDesktopMode command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGLMWFW_GetDesktopModeCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_Obj *listPtr;
    TclGLMWFWInfo *infoPtr;
    GLMWFWvidmode *modePtr;
    GLMWFWvidmode mode;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_GetDesktopModeCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw getDesktopMode\"",
	        NULL);
        return TCL_ERROR;
    }
    modePtr = (GLMWFWvidmode *)ckalloc(sizeof(GLMWFWvidmode));
    glmwfwGetDesktopMode(infoPtr, modePtr);
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
 *  TclGLMWFW_SetWindowPosCmd()
 *
 *  Handles the GLMWFW setWindowPos command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
TclGLMWFW_SetWindowPosCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    TclGLMWFWInfo *infoPtr;
    int x;
    int y;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_SetWindowPosCmd", objc, objv);
    if (objc != 4) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw setWindowPos window x y\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such window: \"", Tcl_GetString(objv[1]),
	        NULL);
	return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    Tcl_GetIntFromObj(interp, objv[2], &x);
    Tcl_GetIntFromObj(interp, objv[3], &y);
    glmwfwSetWindowPos(winPtr, x, y);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_EnableCmd()
 *
 *  Handles the GLMWFW enable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_EnableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLMWFWInfo *infoPtr;
    const char *token;
    int param;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_EnableCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw enable param\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    param = TclGLMWFWEnableParam2Define(token);
    if (param < 0) {
        Tcl_AppendResult(interp, "bad param in enable: \"", token,
	        "\"", NULL);
        return TCL_ERROR;
    }
    glmwfwEnable(infoPtr->currWindow, param);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_DisableCmd()
 *
 *  Handles the GLMWFW disable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_DisableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLMWFWInfo *infoPtr;
    const char *token;
    int param;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_DisableCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw disable param\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    param = TclGLMWFWEnableParam2Define(token);
    if (param < 0) {
        Tcl_AppendResult(interp, "bad param in disable: \"", token,
	        "\"", NULL);
        return TCL_ERROR;
    }
    glmwfwDisable(infoPtr->currWindow, param);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_GetWindowParamCmd()
 *
 *  Handles the GLMWFW getWindowParam command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_GetWindowParamCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_Obj *objPtr;
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    TclGLMWFWInfo *infoPtr;
    const char *token;
    int param;
    int value;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_GetWindowParamCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw getWindowParam window paramName\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such window: \"", Tcl_GetString(objv[1]),
	        NULL);
	return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    token = Tcl_GetString(objv[2]);
    param = TclGLMWFWWindowParam2Define(token);
    if (param < 0) {
        Tcl_AppendResult(interp, "bad paramName in getWindowParam: \"", token,
	        "\"", NULL);
        return TCL_ERROR;
    }
    value = glmwfwGetWindowParam(winPtr, param);
    objPtr = Tcl_NewIntObj(value);
    Tcl_IncrRefCount(objPtr);
    Tcl_SetObjResult(interp, objPtr);
    Tcl_DecrRefCount(objPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_SwapBuffersCmd()
 *
 *  Handles the GLMWFW swapBuffers command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_SwapBuffersCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    TclGLMWFWInfo *infoPtr;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_SwapBuffersCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw swapBuffers window\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such window: \"", Tcl_GetString(objv[1]),
	        NULL);
	return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    glmwfwSwapBuffers(winPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_GetKeyCmd()
 *
 *  Handles the GLMWFW getKey command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_GetKeyCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLMWFWInfo *infoPtr;
    GLMWFWWindow *winPtr;
    const char *token;
    int key;
    int value;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_GetKeyCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw getKey <char>|<key string>\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    if (strlen(token) > 1) {
        key = TclGLMWFWKey2Define(Tcl_GetString(objv[1]));
        if (key == -1) {
            Tcl_AppendResult(interp, "bad key in getKey: \"", token,
	            "\"", NULL);
	    return TCL_ERROR;
        }
    } else {
        key = (int)(*token);
    }
fprintf(stderr, "key!%d!\n", key);
    value = glmwfwGetKey(winPtr, key);
fprintf(stderr, "value!%d!\n", value);
    Tcl_SetObjResult(interp, Tcl_NewIntObj(value));
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  DispatchKey()
 *
 *  Handles the GLMWFW dispatching of keys
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchKey(
    GLMWFWWindow *winPtr,
    int key,
    int state)
{
    Tcl_Obj *objPtr;
    Tcl_Obj *keyPtr;
    Tcl_Obj *statePtr;
    Tcl_Obj *listPtr;
    int result;

    objPtr = TclGLMWFWDefine2Key(key);
//fprintf(stderr, "DispatchKey!%s!%d!%d!\n", objPtr == NULL ? "(nil)" : Tcl_GetString(objPtr), key, state);
    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    keyPtr = Tcl_NewIntObj (key);
    Tcl_IncrRefCount (keyPtr);
    statePtr = Tcl_NewIntObj (state);
    Tcl_IncrRefCount (statePtr);
    Tcl_ListObjAppendElement (winPtr->infoPtr->interp, listPtr,
            winPtr->keyCallback);
    Tcl_ListObjAppendElement(winPtr->infoPtr->interp, listPtr, keyPtr);
    Tcl_ListObjAppendElement(winPtr->infoPtr->interp, listPtr, statePtr);
    Tcl_ListObjAppendElement(winPtr->infoPtr->interp, listPtr, objPtr);
//fprintf(stderr, "CALL!%s!\n", Tcl_GetString(listPtr));
    result = Tcl_GlobalEvalObj (winPtr->infoPtr->interp, listPtr);
    Tcl_DecrRefCount (listPtr);
    Tcl_DecrRefCount (statePtr);
    Tcl_DecrRefCount (keyPtr);
}

/*
 * ------------------------------------------------------------------------
 *  DispatchMousePos()
 *
 *  Handles the GLMWFW dispatching of mouse motion
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchMousePos(
    GLMWFWWindow *winPtr,
    int x,
    int y)
{
    Tcl_Obj *xPtr;
    Tcl_Obj *yPtr;
    Tcl_Obj *listPtr;
    int result;

    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    xPtr = Tcl_NewIntObj (x);
    Tcl_IncrRefCount (xPtr);
    yPtr = Tcl_NewIntObj (y);
    Tcl_IncrRefCount (yPtr);
    Tcl_ListObjAppendElement (winPtr->infoPtr->interp, listPtr,
            winPtr->mousePosCallback);
    Tcl_ListObjAppendElement(winPtr->infoPtr->interp, listPtr, xPtr);
    Tcl_ListObjAppendElement(winPtr->infoPtr->interp, listPtr, yPtr);
    result = Tcl_GlobalEvalObj (winPtr->infoPtr->interp, listPtr);
    Tcl_DecrRefCount (xPtr);
    Tcl_DecrRefCount (yPtr);
    Tcl_DecrRefCount (listPtr);
}

/*
 * ------------------------------------------------------------------------
 *  DispatchMouseButton()
 *
 *  Handles the GLMWFW dispatching of mouse button press/release
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchMouseButton(
    GLMWFWWindow *winPtr,
    int which,
    int what)
{
    Tcl_Obj *whichPtr;
    Tcl_Obj *whatPtr;
    Tcl_Obj *listPtr;
    int result;

    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    whichPtr = Tcl_NewIntObj (which);
    Tcl_IncrRefCount (whichPtr);
    whatPtr = Tcl_NewIntObj (what);
    Tcl_IncrRefCount (whatPtr);
    Tcl_ListObjAppendElement (winPtr->infoPtr->interp, listPtr,
            winPtr->mouseButtonCallback);
    Tcl_ListObjAppendElement(winPtr->infoPtr->interp, listPtr, whichPtr);
    Tcl_ListObjAppendElement(winPtr->infoPtr->interp, listPtr, whatPtr);
    result = Tcl_GlobalEvalObj (winPtr->infoPtr->interp, listPtr);
    Tcl_DecrRefCount (whichPtr);
    Tcl_DecrRefCount (whatPtr);
    Tcl_DecrRefCount (listPtr);
}

/*
 * ------------------------------------------------------------------------
 *  DispatchMouseWheel()
 *
 *  Handles the GLMWFW dispatching of mouse wheel motion
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchMouseWheel(
    GLMWFWWindow *winPtr,
    int where)
{
    Tcl_Obj *wherePtr;
    Tcl_Obj *listPtr;
    int result;

    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    wherePtr = Tcl_NewIntObj (where);
    Tcl_IncrRefCount (wherePtr);
    Tcl_ListObjAppendElement (winPtr->infoPtr->interp, listPtr,
            winPtr->mouseWheelCallback);
    Tcl_ListObjAppendElement(winPtr->infoPtr->interp, listPtr, wherePtr);
    result = Tcl_GlobalEvalObj (winPtr->infoPtr->interp, listPtr);
    Tcl_DecrRefCount (wherePtr);
    Tcl_DecrRefCount (listPtr);
}

/*
 * ------------------------------------------------------------------------
 *  DispatchWindowSize()
 *
 *  Handles the GLMWFW dispatching of window sizing
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchWindowSize(
    GLMWFWWindow *winPtr,
    int width,
    int height)
{
    Tcl_Obj *widthPtr;
    Tcl_Obj *heightPtr;
    Tcl_Obj *listPtr;
    int result;

    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    widthPtr = Tcl_NewIntObj (width);
    Tcl_IncrRefCount (widthPtr);
    heightPtr = Tcl_NewIntObj (height);
    Tcl_IncrRefCount (heightPtr);
    Tcl_ListObjAppendElement (winPtr->infoPtr->interp, listPtr,
            winPtr->windowSizeCallback);
    Tcl_ListObjAppendElement(winPtr->infoPtr->interp, listPtr, widthPtr);
    Tcl_ListObjAppendElement(winPtr->infoPtr->interp, listPtr, heightPtr);
    result = Tcl_GlobalEvalObj (winPtr->infoPtr->interp, listPtr);
    Tcl_DecrRefCount (widthPtr);
    Tcl_DecrRefCount (heightPtr);
    Tcl_DecrRefCount (listPtr);
}

/*
 * ------------------------------------------------------------------------
 *  DispatchWindowRefresh()
 *
 *  Handles the GLMWFW dispatching of window refreshing
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchWindowRefresh(
    GLMWFWWindow *winPtr)
{
    Tcl_Obj *listPtr;
    int result;

    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    Tcl_ListObjAppendElement (winPtr->infoPtr->interp, listPtr,
            winPtr->windowRefreshCallback);
    result = Tcl_GlobalEvalObj (winPtr->infoPtr->interp, listPtr);
    Tcl_DecrRefCount (listPtr);
}

/*
 * ------------------------------------------------------------------------
 *  DispatchWindowClose()
 *
 *  Handles the GLMWFW dispatching of window closing
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchWindowClose(
    GLMWFWWindow *winPtr,
    int width,
    int height)
{
    Tcl_Obj *listPtr;
    int result;

    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    Tcl_ListObjAppendElement (winPtr->infoPtr->interp, listPtr,
            winPtr->windowCloseCallback);
    result = Tcl_GlobalEvalObj (winPtr->infoPtr->interp, listPtr);
    Tcl_DecrRefCount (listPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_SetKeyCallbackCmd()
 *
 *  Handles the GLMWFW setKeyCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_SetKeyCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    TclGLMWFWInfo *infoPtr;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_SetKeyCallbackCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw setKeyCallback window function\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such window \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    winPtr->keyCallback = objv[2];
    Tcl_IncrRefCount(winPtr->keyCallback);
    glmwfwSetKeyCallback(winPtr, DispatchKey);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_SetMousePosCallbackCmd()
 *
 *  Handles the GLMWFW setMousePosCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_SetMousePosCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    TclGLMWFWInfo *infoPtr;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_SetMousePosCallbackCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw setMousePosCallback window function\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such window \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    winPtr->mousePosCallback = objv[2];
    Tcl_IncrRefCount(winPtr->mousePosCallback);
    glmwfwSetMousePosCallback(winPtr, DispatchMousePos);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_SetMouseButtonCallbackCmd()
 *
 *  Handles the GLMWFW setMouseButtonCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_SetMouseButtonCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    TclGLMWFWInfo *infoPtr;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_SetMouseButtonCallbackCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw setMouseButtonCallback window function\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such window \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    winPtr->mouseButtonCallback = objv[2];
    Tcl_IncrRefCount(winPtr->mouseButtonCallback);
    glmwfwSetMouseButtonCallback(winPtr, DispatchMouseButton);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_SetMouseWheelCallbackCmd()
 *
 *  Handles the GLMWFW setMouseWheelCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_SetMouseWheelCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    TclGLMWFWInfo *infoPtr;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_SetMouseWheelCallbackCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw setMouseWheelCallback window function\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such window \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    winPtr->mouseWheelCallback = objv[2];
    Tcl_IncrRefCount(winPtr->mouseWheelCallback);
    glmwfwSetMouseWheelCallback(winPtr, DispatchMouseWheel);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_SetWindowSizeCallbackCmd()
 *
 *  Handles the GLMWFW setWindowSizeCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_SetWindowSizeCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    TclGLMWFWInfo *infoPtr;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_SetWindowSizeCallbackCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw setWindowSizeCallback window function\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such window \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    winPtr->windowSizeCallback = objv[2];
    Tcl_IncrRefCount(winPtr->windowSizeCallback);
    glmwfwSetWindowSizeCallback(winPtr, DispatchWindowSize);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_SetWindowRefreshCallbackCmd()
 *
 *  Handles the GLMWFW setWindowRefreshCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_SetWindowRefreshCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    TclGLMWFWInfo *infoPtr;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_SetWindowRefreshCallbackCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw setWindowRefreshCallback window function\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such window \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    winPtr->windowRefreshCallback = objv[2];
    Tcl_IncrRefCount(winPtr->windowRefreshCallback);
    glmwfwSetWindowRefreshCallback(winPtr, DispatchWindowRefresh);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_SetWindowCloseCallbackCmd()
 *
 *  Handles the GLMWFW setWindowCloseCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_SetWindowCloseCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GLMWFWWindow *winPtr;
    TclGLMWFWInfo *infoPtr;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_SetWindowCloseCallbackCmd", objc, objv);
    if (objc != 3) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw setWindowCloseCallback window function\"",
	        NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->windows, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such window \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    winPtr = Tcl_GetHashValue(hPtr);
    winPtr->windowCloseCallback = objv[2];
    Tcl_IncrRefCount(winPtr->windowCloseCallback);
    glmwfwSetWindowSizeCallback(winPtr, DispatchWindowClose);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_DefaultCmd()
 *
 *  Handles any unknown options for the "ntk::glmwfw::GLMWFW" command
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_DefaultCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLMWFWInfo *infoPtr;
    int result;

    infoPtr = (TclGLMWFWInfo *)clientData;
    result = TCL_ERROR;
    TclGLMWFWShowArgs(0, "TclGLMWFW_DefaultCmd", objc, objv);
//    TclGLMWFW_GetEnsembleUsageForObj(interp, objv[0], resultPtr);
    return result;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_WaitEventsCmd()
 *
 *  Handles waiting for new window and input events
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_WaitEventsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLMWFWInfo *infoPtr;

    infoPtr = (TclGLMWFWInfo *)clientData;
    TclGLMWFWShowArgs(1, "TclGLMWFW_WaitEventsCmd", objc, objv);
    glmwfwWaitEvents(infoPtr);
    return TCL_OK;
}

#include "/home/arnulf/SOURCES/MEGAIMAGE/megapkg/csrc/include/megaimage_shared.h"
/*
 * ------------------------------------------------------------------------
 *  TclGLMWFW_DrawMegaimageCmd()
 *
 *  Handles drawing of a pixel area with rgba values
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLMWFW_DrawMegaimageCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLMWFWInfo *infoPtr;
    struct megaimage_header megaimageHeader;
    unsigned char *hdPtr;
    unsigned char *data;
    int lgth;
    int result;

    infoPtr = (TclGLMWFWInfo *)clientData;
    result = TCL_OK;
    TclGLMWFWShowArgs(1, "TclGLMWFW_DrawMegaimageCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw drawMegaimage data\"",
	        NULL);
        return TCL_ERROR;
    }
    hdPtr = Tcl_GetByteArrayFromObj(objv[1], &lgth);
    memcpy(&megaimageHeader, hdPtr, sizeof(struct megaimage_header));
    data = hdPtr + sizeof(struct megaimage_header);
    glDrawPixels(megaimageHeader.width, megaimageHeader.height,
            GL_RGBA, GL_UNSIGNED_BYTE, data);
    return result;
}
