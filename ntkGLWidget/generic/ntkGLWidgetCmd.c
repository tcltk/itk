/*
 * ntkGLWidgetCmd.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: ntkGLWidgetCmd.c,v 1.1.2.2 2007/11/11 11:46:31 wiede Exp $
 */

#include <stdlib.h>
#include "ntkGLWidgetInt.h"

Tcl_ObjCmdProc NtkGLWidget_UnknownCmd;
Tcl_ObjCmdProc NtkGLWidget_CreateCmd;
Tcl_ObjCmdProc NtkGLWidget_LineCmd;
Tcl_ObjCmdProc NtkGLWidget_BlendCmd;
Tcl_ObjCmdProc NtkGLWidget_BlendWidgetCmd;
Tcl_ObjCmdProc NtkGLWidget_GetDataCmd;
Tcl_ObjCmdProc NtkGLWidget_GetSizeCmd;
Tcl_ObjCmdProc NtkGLWidget_FillCmd;
Tcl_ObjCmdProc NtkGLWidget_SetDataCmd;
Tcl_ObjCmdProc NtkGLWidget_SetSizeCmd;
Tcl_ObjCmdProc NtkGLWidget_RectangleCmd;
Tcl_ObjCmdProc NtkGLWidget_RotateCmd;

typedef struct GLMethod {
    char *commandName;       /* the command name with the namespace prefix */
    char *usage;             /* string describing usage */
    Tcl_ObjCmdProc *proc;    /* implementation C proc */
} GLMethod;

static GLMethod GLMethodList[] = {
    { "::ntk::glWidget::Widget::unknown",
            "", NtkGLWidget_UnknownCmd },
    { "::ntk::glWidget::Widget::create",
            "", NtkGLWidget_CreateCmd },
    { "::ntk::glWidget::Widget::line",
            "", NtkGLWidget_LineCmd },
    { "::ntk::glWidget::Widget::blend",
            "", NtkGLWidget_BlendCmd },
    { "::ntk::glWidget::Widget::blendwidget",
            "", NtkGLWidget_BlendWidgetCmd },
    { "::ntk::glWidget::Widget::getdata",
            "", NtkGLWidget_GetDataCmd },
    { "::ntk::glWidget::Widget::getsize",
            "", NtkGLWidget_GetSizeCmd },
    { "::ntk::glWidget::Widget::fill",
            "", NtkGLWidget_FillCmd },
    { "::ntk::glWidget::Widget::setdata",
            "", NtkGLWidget_SetDataCmd },
    { "::ntk::glWidget::Widget::setsize",
            "", NtkGLWidget_SetSizeCmd },
    { "::ntk::glWidget::Widget::rectangle",
            "", NtkGLWidget_RectangleCmd },
    { "::ntk::glWidget::Widget::rotate",
            "", NtkGLWidget_RotateCmd },
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
    NtkGLWidgetInfo *infoPtr)
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
 *  NtkGLWidget_InitCommands()
 *
 *      that is the starting point when loading the library
 *      it initializes all internal stuff
 *
 * ------------------------------------------------------------------------
 */

int
NtkGLWidget_InitCommands (
    Tcl_Interp *interp,
    NtkGLWidgetInfo *infoPtr)
{
    Tcl_Namespace *nsPtr;
    Tcl_Command cmd;
    int i;

    /*
     * Build the ensemble used to implement [ntk gl].
     */

    nsPtr = Tcl_CreateNamespace(interp, "::ntk::glWidget::Widget", NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("ITCL: error in creating namespace: ::ntk::glWidget::Widget \n");
    }
    cmd = Tcl_CreateEnsemble(interp, nsPtr->fullName, nsPtr,
        TCL_ENSEMBLE_PREFIX);
    Tcl_Export(interp, nsPtr, "[a-z]*", 1);
    for (i=0 ; GLMethodList[i].commandName!=NULL ; i++) {
        Tcl_CreateObjCommand(interp, GLMethodList[i].commandName,
                GLMethodList[i].proc, infoPtr, NULL);
    }
    Tcl_Obj *ensObjPtr = Tcl_NewStringObj("::ntk::glWidget::Widget", -1);
    Tcl_IncrRefCount(ensObjPtr);
    Tcl_Obj *unkObjPtr = Tcl_NewStringObj("::ntk::glWidget::Widget::unknown", -1);
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
    NtkGLWidgetInfo *infoPtr,
    Tcl_Obj *objPtr)       /* returns: summary of usage info */
{
    char *spaces = "  ";
    int i;

    for (i=0; GLMethodList[i].commandName != NULL; i++) {
	if (strcmp(GLMethodList[i].commandName, "::ntk::glWidget::Widget::unknown") == 0) {
	    continue;
	}
        Tcl_AppendToObj(objPtr, spaces, -1);
        Tcl_AppendToObj(objPtr, "ntk ", -1);
        Tcl_AppendToObj(objPtr, GLMethodList[i].commandName, -1);
        if (strlen(GLMethodList[i].usage) > 0) {
            Tcl_AppendToObj(objPtr, " ", -1);
            Tcl_AppendToObj(objPtr, GLMethodList[i].usage, -1);
	}
        spaces = "\n  ";
    }
}

/*
 * ------------------------------------------------------------------------
 *  NtkGLWidget_UnknownCmd()
 *
 *  the unknown handler for the ::itcl::builtin::Info ensemble
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkGLWidget_UnknownCmd(
    ClientData clientData,   /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkGLWidgetInfo *infoPtr;
    int result;

    infoPtr = (NtkGLWidgetInfo *)clientData;
    NtkGLWidgetShowArgs(1, "NtkGLWidget_UnknownCmd", objc, objv);
    result = TCL_ERROR;
    /* produce usage message */
    Tcl_Obj *objPtr = Tcl_NewStringObj("unknown command: \"", -1);
    Tcl_AppendToObj(objPtr, Tcl_GetString(objv[2]), -1);
    Tcl_AppendToObj(objPtr, "\" should be one of...\n", -1);
    TclGLGetUsage(interp, infoPtr, objPtr);
    Tcl_SetResult(interp, Tcl_GetString(objPtr), TCL_DYNAMIC);
    return TCL_ERROR;
}

/*
 * ------------------------------------------------------------------------
 *  CheckNumParams()
 *
 *  check if number of params is correct and return error message if not
 *  check if function is loadable if not yet available
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
void (*glXGetProcAddressARB(const GLubyte *procName))();

int
CheckNumParams(
    Tcl_Interp *interp,
    NtkGLWidgetInfo *infoPtr,
    const char *funcName,
    int objc,
    int numParams)
{
    const char *cp;
    int i;
    
    if (objc != numParams+1) {
        for (i=0; GLMethodList[i].commandName != NULL; i++) {
	    cp = strrchr(GLMethodList[i].commandName, ':');
	    if (cp == NULL) {
	        cp = GLMethodList[i].commandName;
	    } else {
	        cp++;
	    }
	    if (strcmp(cp, funcName) == 0) {
                Tcl_AppendResult(interp,
                        "wrong # args: should be \"ntk glwidget ",
		        funcName, " ", 
		        GLMethodList[i].usage, "\"", NULL);
                return TCL_ERROR;
            }
        }
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkGLWidget_CreateCmd()
 *
 *  Handles the ntk glwidget create command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkGLWidget_CreateCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkGLWidgetInfo *infoPtr;

    infoPtr = (NtkGLWidgetInfo *)clientData;
    NtkGLWidgetShowArgs(0, "NtkGLWIdget_CreateCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "create", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkGLWidget_LineCmd()
 *
 *  Handles the ntk glwidget line command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkGLWidget_LineCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkGLWidgetInfo *infoPtr;

    infoPtr = (NtkGLWidgetInfo *)clientData;
    NtkGLWidgetShowArgs(0, "NtkGLWIdget_LineCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "line", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkGLWidget_BlendCmd()
 *
 *  Handles the ntk glwidget blen command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkGLWidget_BlendCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkGLWidgetInfo *infoPtr;

    infoPtr = (NtkGLWidgetInfo *)clientData;
    NtkGLWidgetShowArgs(0, "NtkGLWIdget_BlendCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "blend", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkGLWidget_BlendWidgetCmd()
 *
 *  Handles the ntk glwidget blendwidget command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkGLWidget_BlendWidgetCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkGLWidgetInfo *infoPtr;

    infoPtr = (NtkGLWidgetInfo *)clientData;
    NtkGLWidgetShowArgs(0, "NtkGLWIdget_BlendWidgetCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "blendwidget", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkGLWidget_GetDataCmd()
 *
 *  Handles the ntk glwidget getdata command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkGLWidget_GetDataCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkGLWidgetInfo *infoPtr;

    infoPtr = (NtkGLWidgetInfo *)clientData;
    NtkGLWidgetShowArgs(0, "NtkGLWIdget_GetDataCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "getdata", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkGLWidget_GetSizeCmd()
 *
 *  Handles the ntk glwidget getsize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkGLWidget_GetSizeCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkGLWidgetInfo *infoPtr;

    infoPtr = (NtkGLWidgetInfo *)clientData;
    NtkGLWidgetShowArgs(0, "NtkGLWIdget_GetSizeCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "getsize", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkGLWidget_FillCmd()
 *
 *  Handles the ntk glwidget fill command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkGLWidget_FillCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkGLWidgetInfo *infoPtr;

    infoPtr = (NtkGLWidgetInfo *)clientData;
    NtkGLWidgetShowArgs(0, "NtkGLWIdget_FillCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "fill", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkGLWidget_SetDataCmd()
 *
 *  Handles the ntk glwidget setdata command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkGLWidget_SetDataCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkGLWidgetInfo *infoPtr;

    infoPtr = (NtkGLWidgetInfo *)clientData;
    NtkGLWidgetShowArgs(0, "NtkGLWIdget_SetDataCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "setdata", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkGLWidget_SetSizeCmd()
 *
 *  Handles the ntk glwidget setsize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkGLWidget_SetSizeCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkGLWidgetInfo *infoPtr;

    infoPtr = (NtkGLWidgetInfo *)clientData;
    NtkGLWidgetShowArgs(0, "NtkGLWIdget_SetSizeCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "setsize", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkGLWidget_RectangleCmd()
 *
 *  Handles the ntk glwidget rectangle command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkGLWidget_RectangleCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkGLWidgetInfo *infoPtr;

    infoPtr = (NtkGLWidgetInfo *)clientData;
    NtkGLWidgetShowArgs(0, "NtkGLWIdget_RectangleCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "rectangle", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkGLWidget_RotateCmd()
 *
 *  Handles the ntk glwidget rotate command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkGLWidget_RotateCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkGLWidgetInfo *infoPtr;

    infoPtr = (NtkGLWidgetInfo *)clientData;
    NtkGLWidgetShowArgs(0, "NtkGLWIdget_RotateCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "rotate", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}
