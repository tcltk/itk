/*
 * glmwfwCmd.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the GLFW OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: glmwfwCmd.c,v 1.1.2.5 2007/11/11 20:01:54 wiede Exp $
 */

#include <stdlib.h>
#include "glmwfwInt.h"

Tcl_ObjCmdProc Glmwfw_InitCmd;
Tcl_ObjCmdProc Glmwfw_TerminateCmd;
Tcl_ObjCmdProc Glmwfw_OpenWindowHintCmd;
Tcl_ObjCmdProc Glmwfw_OpenWindowCmd;
Tcl_ObjCmdProc Glmwfw_CloseWindowCmd;
Tcl_ObjCmdProc Glmwfw_SetWindowTitleCmd;
Tcl_ObjCmdProc Glmwfw_SetWindowSizeCmd;
Tcl_ObjCmdProc Glmwfw_SetWindowPosCmd;
Tcl_ObjCmdProc Glmwfw_GetWindowParamCmd;
Tcl_ObjCmdProc Glmwfw_GetWindowSizeCmd;
Tcl_ObjCmdProc Glmwfw_GetMousePosCmd;
Tcl_ObjCmdProc Glmwfw_GetVideoModesCmd;
Tcl_ObjCmdProc Glmwfw_GetDesktopModeCmd;
Tcl_ObjCmdProc Glmwfw_SwapBuffersCmd;
Tcl_ObjCmdProc Glmwfw_SetKeyCallbackCmd;
Tcl_ObjCmdProc Glmwfw_SetMousePosCallbackCmd;
Tcl_ObjCmdProc Glmwfw_SetMouseButtonCallbackCmd;
Tcl_ObjCmdProc Glmwfw_SetMouseWheelCallbackCmd;
Tcl_ObjCmdProc Glmwfw_SetWindowSizeCallbackCmd;
Tcl_ObjCmdProc Glmwfw_SetWindowRefreshCallbackCmd;
Tcl_ObjCmdProc Glmwfw_SetWindowCloseCallbackCmd;
Tcl_ObjCmdProc Glmwfw_GetKeyCmd;
Tcl_ObjCmdProc Glmwfw_EnableCmd;
Tcl_ObjCmdProc Glmwfw_DisableCmd;
Tcl_ObjCmdProc Glmwfw_DefaultCmd;
Tcl_ObjCmdProc Glmwfw_UnknownCmd;
Tcl_ObjCmdProc Glmwfw_WaitEventsCmd;
#ifndef NOTDEF
Tcl_ObjCmdProc Glmwfw_DrawMegaimageCmd;
#endif

typedef struct GlmwfwMethod {
    char* name;              /* method name */
    char* usage;             /* string describing usage */
    Tcl_ObjCmdProc *proc;    /* implementation C proc */
} GlmwfwMethod;

static GlmwfwMethod GlmwfwMethodList[] = {
    { "::ntk::glmwfw::Glmwfw::init", "", Glmwfw_InitCmd },
    { "::ntk::glmwfw::Glmwfw::terminate", "", Glmwfw_TerminateCmd },
    { "::ntk::glmwfw::Glmwfw::enable", "param", Glmwfw_EnableCmd },
    { "::ntk::glmwfw::Glmwfw::disable", "param", Glmwfw_DisableCmd },
    { "::ntk::glmwfw::Glmwfw::openWindowHint", "target hint",
            Glmwfw_OpenWindowHintCmd },
    { "::ntk::glmwfw::Glmwfw::openWindow", "width height",
            Glmwfw_OpenWindowCmd },
    { "::ntk::glmwfw::Glmwfw::closeWindow", "", Glmwfw_CloseWindowCmd },
    { "::ntk::glmwfw::Glmwfw::setWindowTitle", "title",
            Glmwfw_SetWindowTitleCmd },
    { "::ntk::glmwfw::Glmwfw::setWindowSize", "width height",
            Glmwfw_SetWindowSizeCmd },
    { "::ntk::glmwfw::Glmwfw::setWindowPos", "x y", Glmwfw_SetWindowPosCmd },
    { "::ntk::glmwfw::Glmwfw::getWindowParam", "paramName",
            Glmwfw_GetWindowParamCmd },
    { "::ntk::glmwfw::Glmwfw::getWindowSize", "", Glmwfw_GetWindowSizeCmd },
    { "::ntk::glmwfw::Glmwfw::getMousePos", "", Glmwfw_GetMousePosCmd },
    { "::ntk::glmwfw::Glmwfw::getVideoModes", "??", Glmwfw_GetVideoModesCmd },
    { "::ntk::glmwfw::Glmwfw::getDesktopMode", "??", Glmwfw_GetDesktopModeCmd },
    { "::ntk::glmwfw::Glmwfw::swapBuffers", "", Glmwfw_SwapBuffersCmd },
    { "::ntk::glmwfw::Glmwfw::getKey", "keyName", Glmwfw_GetKeyCmd },
    { "::ntk::glmwfw::Glmwfw::setKeyCallback", "functionName",
            Glmwfw_SetKeyCallbackCmd },
    { "::ntk::glmwfw::Glmwfw::setMousePosCallback", "functionName",
            Glmwfw_SetMousePosCallbackCmd },
    { "::ntk::glmwfw::Glmwfw::setMouseButtonCallback", "functionName",
            Glmwfw_SetMouseButtonCallbackCmd },
    { "::ntk::glmwfw::Glmwfw::setWindowSizeCallback", "functionName",
            Glmwfw_SetWindowSizeCallbackCmd },
    { "::ntk::glmwfw::Glmwfw::setWindowRefreshCallback", "functionName",
            Glmwfw_SetWindowRefreshCallbackCmd },
    { "::ntk::glmwfw::Glmwfw::setWindowcloseCallback", "functionName",
            Glmwfw_SetWindowCloseCallbackCmd },
    { "::ntk::glmwfw::Glmwfw::setMouseWheelCallback", "functionName",
            Glmwfw_SetMouseWheelCallbackCmd },
    { "::ntk::glmwfw::Glmwfw::waitEvents", "", Glmwfw_WaitEventsCmd },
#ifndef NOTDEF
    { "::ntk::glmwfw::Glmwfw::drawMegaimage", "width height <pixel-list>",
            Glmwfw_DrawMegaimageCmd },
#endif
    { "::ntk::glmwfw::Glmwfw::unknown", "", Glmwfw_UnknownCmd },
    { NULL, NULL, NULL }
};

/*
 * ------------------------------------------------------------------------
 *  Glmwfw_InitCommands()
 *
 *      that is the starting point when loading the library
 *      it initializes all internal stuff
 *
 * ------------------------------------------------------------------------
 */

int
Glmwfw_InitCommands (
    Tcl_Interp *interp,
    GlmwfwInfo *infoPtr)
{
    Tcl_Namespace *nsPtr;
    Tcl_Command cmd;
    int i;

    /*
     * Build the ensemble used to implement [ntk glmwfw].
     */

    nsPtr = Tcl_CreateNamespace(interp, "::ntk::glmwfw::Glmwfw", NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("ITCL: error in creating namespace: ::ntk::glmwfw::Glmwfw \n");
    }
    cmd = Tcl_CreateEnsemble(interp, nsPtr->fullName, nsPtr,
        TCL_ENSEMBLE_PREFIX);
    Tcl_Export(interp, nsPtr, "[a-z]*", 1);
    for (i=0 ; glmwfwGlmwfwMethodList[i].name!=NULL ; i++) {
        Tcl_CreateObjCommand(interp, GlmwfwMethodList[i].name,
                GlmwfwMethodList[i].proc, infoPtr, NULL);
    }
    Tcl_Obj *ensObjPtr = Tcl_NewStringObj("::ntk::glmwfw::Glmwfw", -1);
    Tcl_IncrRefCount(ensObjPtr);
    Tcl_Obj *unkObjPtr = Tcl_NewStringObj("::ntk::glmwfw::Glmwfw::unknown", -1);
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
 *  GlmwfwGetUsage()
 *
 * ------------------------------------------------------------------------
  */
void
GlmwfwGetUsage(
    Tcl_Interp *interp,
    Tcl_Obj *objPtr)       /* returns: summary of usage info */
{
    const char *cp;
    char *spaces = "  ";

    int i;

    for (i=0; GlmwfwMethodList[i].name != NULL; i++) {
	if (strcmp(GLMethodList[i].commandName,
	        "::ntk::glmwfw::Glmwfw::unknown") == 0) {
	    continue;
	}
        Tcl_AppendToObj(objPtr, spaces, -1);
        Tcl_AppendToObj(objPtr, "ntk glmwfw ", -1);
	cp = strrchr(GlmwfwMethodList[i].name, ':');
	if (cp == NULL) {
	   cp = GlmwfwMethodList[i].name;
	} else {
	   cp++;
	}
        Tcl_AppendToObj(objPtr, cp, -1);
        if (strlen(GlmwfwMethodList[i].usage) > 0) {
            Tcl_AppendToObj(objPtr, " ", -1);
            Tcl_AppendToObj(objPtr, GlmwfwMethodList[i].usage, -1);
	}
        spaces = "\n  ";
    }
}

/*
 * ------------------------------------------------------------------------
 *  Glmwfw_UnknownCmd()
 *
 *  the unknown handler for the ::itcl::builtin::Info ensemble
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_UnknownCmd(
    ClientData dummy,        /* not used */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int result;

    GlmwfwShowArgs(0, "Glmwfw_UnknownCmd", objc, objv);
    result = TCL_ERROR;
    /* produce usage message */
    Tcl_Obj *objPtr = Tcl_NewStringObj("unknown command: \"", -1);
    Tcl_AppendToObj(objPtr, Tcl_GetString(objv[2]), -1);
    Tcl_AppendToObj(objPtr, "\" should be one of...\n", -1);
    GlmwfwGetUsage(interp, objPtr);
    Tcl_SetResult(interp, Tcl_GetString(objPtr), TCL_DYNAMIC);
    return TCL_ERROR;
}


/*
 * ------------------------------------------------------------------------
 *  Glmwfw_InitCmd()
 *
 *  Handles the Glmwfw init command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_InitCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    GlmwfwInfo *infoPtr;

    /* NO LONGER NEEDED, call to glmwfwInit is done when loading package */
fprintf(stderr, "glmwfwInit NO LONGER NEEDED!!\n");
    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_InitCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw init\"",
	        NULL);
        return TCL_ERROR;
    }
    glmwfwInit(infoPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Glmwfw_TerminateCmd()
 *
 *  Handles the Glmwfw terminate command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_TerminateCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    FOREACH_HASH_DECLS;
    GlmwfwInfo *infoPtr;
    GlmwfwWindow *winPtr;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_TerminateCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw terminate\"",
	        NULL);
        return TCL_ERROR;
    }
    glmwfwTerminate(infoPtr);
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
 *  Glmwfw_OpenWindowCmd()
 *
 *  Handles the Glmwfw openWindow command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_OpenWindowCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    GlmwfwInfo *infoPtr;
    GlmwfwWindow *winPtr;
    int width;
    int height;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_OpenWindowCmd", objc, objv);
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
 *  Glmwfw_CloseWindowCmd()
 *
 *  Handles the Glmwfw closeWindow command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_CloseWindowCmd(
    ClientData clientData, /* not used */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    GlmwfwInfo *infoPtr;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_CloseWindowCmd", objc, objv);
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
/* FIX ME have to free the stuff in the GlmwfwWindow structure here !! */
    ckfree((char *)winPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Glmwfw_OpenWindowHintCmd()
 *
 *  Handles the Glmwfw openWindowHint command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_OpenWindowHintCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwInfo *infoPtr;
    GlmwfwWindow *winPtr;
    int target;
    int hint;
    const char *token;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_OpenWindowHintCmd", objc, objv);
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
    target = GlmwfwWindowHint2Define(token);
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
 *  Glmwfw_SetWindowTitleCmd()
 *
 *  Handles the Glmwfw setWindowTitle command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
Glmwfw_SetWindowTitleCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    GlmwfwInfo *infoPtr;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_SetWindowTitleCmd", objc, objv);
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
 *  Glmwfw_SetWindowSizeCmd()
 *
 *  Handles the Glmwfw setWindowSize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
Glmwfw_SetWindowSizeCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    GlmwfwInfo *infoPtr;
    int width;
    int height;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_SetWindowSizeCmd", objc, objv);
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
 *  Glmwfw_GetWindowSizeCmd()
 *
 *  Handles the Glmwfw getWindowSize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
Glmwfw_GetWindowSizeCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    GlmwfwInfo *infoPtr;
    int width;
    int height;
    Tcl_Obj *listPtr;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_GetWindowSizeCmd", objc, objv);
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
 *  Glmwfw_GetMousePosCmd()
 *
 *  Handles the Glmwfw getMousePos command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
Glmwfw_GetMousePosCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    Tcl_Obj *listPtr;
    GlmwfwInfo *infoPtr;
    int x;
    int y;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_GetMousePosCmd", objc, objv);
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
 *  Glmwfw_GetVideoModesCmd()
 *
 *  Handles the Glmwfw getVideoModes command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
Glmwfw_GetVideoModesCmd(
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
    GlmwfwInfo *infoPtr;
    Glmwfwvidmode *modePtr;
    Glmwfwvidmode mode;
    int numModes;
    int i;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_GetVideoModesCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw getVideoModes\"",
	        NULL);
        return TCL_ERROR;
    }
    modePtr = (Glmwfwvidmode *)ckalloc(sizeof(Glmwfwvidmode)*200);
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
 *  Glmwfw_GetDesktopModeCmd()
 *
 *  Handles the Glmwfw getDesktopMode command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
Glmwfw_GetDesktopModeCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_Obj *listPtr;
    GlmwfwInfo *infoPtr;
    Glmwfwvidmode *modePtr;
    Glmwfwvidmode mode;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_GetDesktopModeCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw getDesktopMode\"",
	        NULL);
        return TCL_ERROR;
    }
    modePtr = (Glmwfwvidmode *)ckalloc(sizeof(Glmwfwvidmode));
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
 *  Glmwfw_SetWindowPosCmd()
 *
 *  Handles the Glmwfw setWindowPos command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int
Glmwfw_SetWindowPosCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    GlmwfwInfo *infoPtr;
    int x;
    int y;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_SetWindowPosCmd", objc, objv);
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
 *  Glmwfw_EnableCmd()
 *
 *  Handles the Glmwfw enable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_EnableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    GlmwfwInfo *infoPtr;
    const char *token;
    int param;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_EnableCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw enable param\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    param = GlmwfwEnableParam2Define(token);
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
 *  Glmwfw_DisableCmd()
 *
 *  Handles the Glmwfw disable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_DisableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    GlmwfwInfo *infoPtr;
    const char *token;
    int param;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_DisableCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw disable param\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    param = GlmwfwEnableParam2Define(token);
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
 *  Glmwfw_GetWindowParamCmd()
 *
 *  Handles the Glmwfw getWindowParam command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_GetWindowParamCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_Obj *objPtr;
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    GlmwfwInfo *infoPtr;
    const char *token;
    int param;
    int value;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_GetWindowParamCmd", objc, objv);
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
    param = GlmwfwWindowParam2Define(token);
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
 *  Glmwfw_SwapBuffersCmd()
 *
 *  Handles the Glmwfw swapBuffers command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_SwapBuffersCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    GlmwfwInfo *infoPtr;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_SwapBuffersCmd", objc, objv);
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
 *  Glmwfw_GetKeyCmd()
 *
 *  Handles the Glmwfw getKey command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_GetKeyCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    GlmwfwInfo *infoPtr;
    GlmwfwWindow *winPtr;
    const char *token;
    int key;
    int value;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_GetKeyCmd", objc, objv);
    if (objc != 2) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk glmwfw getKey <char>|<key string>\"",
	        NULL);
        return TCL_ERROR;
    }
    token = Tcl_GetString(objv[1]);
    if (strlen(token) > 1) {
        key = GlmwfwKey2Define(Tcl_GetString(objv[1]));
        if (key == -1) {
            Tcl_AppendResult(interp, "bad key in getKey: \"", token,
	            "\"", NULL);
	    return TCL_ERROR;
        }
    } else {
        key = (int)(*token);
    }
fprintf(stderr, "key!%d!\n", key);
    winPtr = infoPtr->currWindow;
    value = glmwfwGetKey(winPtr, key);
fprintf(stderr, "value!%d!\n", value);
    Tcl_SetObjResult(interp, Tcl_NewIntObj(value));
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  DispatchKey()
 *
 *  Handles the Glmwfw dispatching of keys
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchKey(
    GlmwfwWindow *winPtr,
    int key,
    int state)
{
    Tcl_Obj *objPtr;
    Tcl_Obj *keyPtr;
    Tcl_Obj *statePtr;
    Tcl_Obj *listPtr;
    int result;

    objPtr = GlmwfwDefine2Key(key);
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
 *  Handles the Glmwfw dispatching of mouse motion
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchMousePos(
    GlmwfwWindow *winPtr,
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
 *  Handles the Glmwfw dispatching of mouse button press/release
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchMouseButton(
    GlmwfwWindow *winPtr,
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
 *  Handles the Glmwfw dispatching of mouse wheel motion
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchMouseWheel(
    GlmwfwWindow *winPtr,
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
 *  Handles the Glmwfw dispatching of window sizing
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchWindowSize(
    GlmwfwWindow *winPtr,
    int width,
    int height)
{
    Tcl_Obj *widthPtr;
    Tcl_Obj *heightPtr;
    Tcl_Obj *listPtr;
    int result;

fprintf(stderr, "INTERNAL DispatchWindowSize\n");
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
 *  Handles the Glmwfw dispatching of window refreshing
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
void DispatchWindowRefresh(
    GlmwfwWindow *winPtr)
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
 *  Handles the Glmwfw dispatching of window closing
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
int DispatchWindowClose(
    GlmwfwWindow *winPtr)
{
    Tcl_Obj *listPtr;
    int result;

fprintf(stderr, "INTERNAL DispatchWindowClose\n");
    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_IncrRefCount (listPtr);
    Tcl_ListObjAppendElement (winPtr->infoPtr->interp, listPtr,
            winPtr->windowCloseCallback);
    result = Tcl_GlobalEvalObj (winPtr->infoPtr->interp, listPtr);
    Tcl_DecrRefCount (listPtr);
    return GL_TRUE;
}

/*
 * ------------------------------------------------------------------------
 *  Glmwfw_SetKeyCallbackCmd()
 *
 *  Handles the Glmwfw setKeyCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_SetKeyCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    GlmwfwInfo *infoPtr;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_SetKeyCallbackCmd", objc, objv);
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
 *  Glmwfw_SetMousePosCallbackCmd()
 *
 *  Handles the Glmwfw setMousePosCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_SetMousePosCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    GlmwfwInfo *infoPtr;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_SetMousePosCallbackCmd", objc, objv);
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
 *  Glmwfw_SetMouseButtonCallbackCmd()
 *
 *  Handles the Glmwfw setMouseButtonCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_SetMouseButtonCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    GlmwfwInfo *infoPtr;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_SetMouseButtonCallbackCmd", objc, objv);
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
 *  Glmwfw_SetMouseWheelCallbackCmd()
 *
 *  Handles the Glmwfw setMouseWheelCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_SetMouseWheelCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    GlmwfwInfo *infoPtr;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_SetMouseWheelCallbackCmd", objc, objv);
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
 *  Glmwfw_SetWindowSizeCallbackCmd()
 *
 *  Handles the Glmwfw setWindowSizeCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_SetWindowSizeCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    GlmwfwInfo *infoPtr;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_SetWindowSizeCallbackCmd", objc, objv);
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
 *  Glmwfw_SetWindowRefreshCallbackCmd()
 *
 *  Handles the Glmwfw setWindowRefreshCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_SetWindowRefreshCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    GlmwfwInfo *infoPtr;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_SetWindowRefreshCallbackCmd", objc, objv);
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
 *  Glmwfw_SetWindowCloseCallbackCmd()
 *
 *  Handles the Glmwfw setWindowCloseCallback command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_SetWindowCloseCallbackCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    GlmwfwInfo *infoPtr;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_SetWindowCloseCallbackCmd", objc, objv);
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
    glmwfwSetWindowCloseCallback(winPtr, DispatchWindowClose);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Glmwfw_DefaultCmd()
 *
 *  Handles any unknown options for the "ntk::glmwfw::Glmwfw" command
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_DefaultCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    GlmwfwInfo *infoPtr;
    int result;

    infoPtr = (GlmwfwInfo *)clientData;
    result = TCL_ERROR;
    GlmwfwShowArgs(0, "Glmwfw_DefaultCmd", objc, objv);
//    Glmwfw_GetEnsembleUsageForObj(interp, objv[0], resultPtr);
    return result;
}

/*
 * ------------------------------------------------------------------------
 *  Glmwfw_WaitEventsCmd()
 *
 *  Handles waiting for new window and input events
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_WaitEventsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    GlmwfwInfo *infoPtr;

    infoPtr = (GlmwfwInfo *)clientData;
    GlmwfwShowArgs(1, "Glmwfw_WaitEventsCmd", objc, objv);
    glmwfwWaitEvents(infoPtr->currWindow);
    return TCL_OK;
}
#ifndef NOTDEF

#include "/home/arnulf/lib/include/megaimage_shared.h"
/*
 * ------------------------------------------------------------------------
 *  Glmwfw_DrawMegaimageCmd()
 *
 *  Handles drawing of a pixel area with rgba values
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
Glmwfw_DrawMegaimageCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    GlmwfwInfo *infoPtr;
    struct megaimage_header megaimageHeader;
    unsigned char *hdPtr;
    unsigned char *data;
    int lgth;
    int result;

    infoPtr = (GlmwfwInfo *)clientData;
    result = TCL_OK;
    GlmwfwShowArgs(1, "Glmwfw_DrawMegaimageCmd", objc, objv);
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
#endif
