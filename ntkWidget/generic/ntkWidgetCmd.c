/*
 * ntkWidgetCmd.c --
 *
 * This file contains the C-implemented startup part of a
 * Tcl interface for rendering widgets as bitmaps
 *
 * this is based on the megaimage package written by George Peter Staplin
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann and George Peter Staplin
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: ntkWidgetCmd.c,v 1.1.2.4 2007/11/17 12:58:45 wiede Exp $
 */

#include <stdlib.h>
#include "ntkWidgetInt.h"

Tcl_ObjCmdProc NtkWidget_UnknownCmd;
Tcl_ObjCmdProc NtkWidget_CreateCmd;
Tcl_ObjCmdProc NtkWidget_CreateTextCmd;
Tcl_ObjCmdProc NtkWidget_LineCmd;
Tcl_ObjCmdProc NtkWidget_BlendCmd;
Tcl_ObjCmdProc NtkWidget_BlendWidgetCmd;
Tcl_ObjCmdProc NtkWidget_GetDataCmd;
Tcl_ObjCmdProc NtkWidget_GetSizeCmd;
Tcl_ObjCmdProc NtkWidget_FillCmd;
Tcl_ObjCmdProc NtkWidget_SetDataCmd;
Tcl_ObjCmdProc NtkWidget_SetSizeCmd;
Tcl_ObjCmdProc NtkWidget_RectangleCmd;
Tcl_ObjCmdProc NtkWidget_RotateCmd;

typedef struct NtkWidgetMethod {
    char *commandName;       /* the command name with the namespace prefix */
    char *usage;             /* string describing usage */
    Tcl_ObjCmdProc *proc;    /* implementation C proc */
} NtkWidgetMethod;

static NtkWidgetMethod NtkWidgetMethodList[] = {
    { "::ntk::widget::Widget::unknown",
            "", NtkWidget_UnknownCmd },
    { "::ntk::widget::Widget::create",
            "width height itemsize", NtkWidget_CreateCmd },
    { "::ntk::widget::Widget::createtext",
            "font fontsize textcolor widthVar heightVar",
	    NtkWidget_CreateTextCmd },
    { "::ntk::widget::Widget::line",
            "widget x1 y1 x2 y2 rgbaList", NtkWidget_LineCmd },
    { "::ntk::widget::Widget::blend",
            "widget", NtkWidget_BlendCmd },
    { "::ntk::widget::Widget::blendwidget",
            "destWidget destX destY ?srcX1 srcY1 srcX2 srcY2? srcWidget",
	    NtkWidget_BlendWidgetCmd },
    { "::ntk::widget::Widget::getdata",
            "widget", NtkWidget_GetDataCmd },
    { "::ntk::widget::Widget::getsize",
            "widget", NtkWidget_GetSizeCmd },
    { "::ntk::widget::Widget::fill",
            "widget", NtkWidget_FillCmd },
    { "::ntk::widget::Widget::setdata",
            "widget data", NtkWidget_SetDataCmd },
    { "::ntk::widget::Widget::setsize",
            "widget width height", NtkWidget_SetSizeCmd },
    { "::ntk::widget::Widget::rectangle",
            "widget", NtkWidget_RectangleCmd },
    { "::ntk::widget::Widget::rotate",
            "widget degrees", NtkWidget_RotateCmd },
    { NULL, NULL, NULL }
};
#ifdef NOTDEF
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
    NtkWidgetInfo *infoPtr)
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
#endif
/*
 * ------------------------------------------------------------------------
 *  NtkWidget_InitCommands()
 *
 *      that is the starting point when loading the library
 *      it initializes all internal stuff
 *
 * ------------------------------------------------------------------------
 */

int
NtkWidget_InitCommands (
    Tcl_Interp *interp,
    NtkWidgetInfo *infoPtr)
{
    Tcl_Namespace *nsPtr;
    Tcl_Command cmd;
    int i;

    /*
     * Build the ensemble used to implement [ntk widget].
     */

    nsPtr = Tcl_CreateNamespace(interp, "::ntk::widget::Widget", NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("ntkWidget: error in creating namespace: ::ntk::widget::Widget \n");
    }
    cmd = Tcl_CreateEnsemble(interp, nsPtr->fullName, nsPtr,
        TCL_ENSEMBLE_PREFIX);
    Tcl_Export(interp, nsPtr, "[a-z]*", 1);
    for (i=0; NtkWidgetMethodList[i].commandName!=NULL; i++) {
        Tcl_CreateObjCommand(interp, NtkWidgetMethodList[i].commandName,
                NtkWidgetMethodList[i].proc, infoPtr, NULL);
    }
    Tcl_Obj *ensObjPtr = Tcl_NewStringObj("::ntk::widget::Widget", -1);
    Tcl_IncrRefCount(ensObjPtr);
    Tcl_Obj *unkObjPtr = Tcl_NewStringObj("::ntk::widget::Widget::unknown", -1);
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
 *  NtkWidgetGetUsage()
 *
 * ------------------------------------------------------------------------
  */
void
NtkWidgetGetUsage(
    Tcl_Interp *interp,
    NtkWidgetInfo *infoPtr,
    Tcl_Obj *objPtr)       /* returns: summary of usage info */
{
    const char *cp;
    char *spaces = "  ";
    int i;

    for (i=0; NtkWidgetMethodList[i].commandName != NULL; i++) {
	if (strcmp(NtkWidgetMethodList[i].commandName,
	        "::ntk::widget::Widget::unknown") == 0) {
	    continue;
	}
        Tcl_AppendToObj(objPtr, spaces, -1);
        Tcl_AppendToObj(objPtr, "ntk widget ", -1);
	cp = strrchr(NtkWidgetMethodList[i].commandName, ':');
	if (cp == NULL) {
	   cp = NtkWidgetMethodList[i].commandName;
	} else {
	   cp++;
	}
        Tcl_AppendToObj(objPtr, cp, -1);
        if (strlen(NtkWidgetMethodList[i].usage) > 0) {
            Tcl_AppendToObj(objPtr, " ", -1);
            Tcl_AppendToObj(objPtr, NtkWidgetMethodList[i].usage, -1);
	}
        spaces = "\n  ";
    }
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidget_UnknownCmd()
 *
 *  the unknown handler for the ::ntk::widget::Widget ensemble
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidget_UnknownCmd(
    ClientData clientData,   /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetInfo *infoPtr;
    int result;

    infoPtr = (NtkWidgetInfo *)clientData;
    NtkWidgetShowArgs(1, "NtkWidget_UnknownCmd", objc, objv);
    result = TCL_ERROR;
    /* produce usage message */
    Tcl_Obj *objPtr = Tcl_NewStringObj("unknown command: \"", -1);
    Tcl_AppendToObj(objPtr, Tcl_GetString(objv[2]), -1);
    Tcl_AppendToObj(objPtr, "\" should be one of...\n", -1);
    NtkWidgetGetUsage(interp, infoPtr, objPtr);
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

static int
CheckNumParams(
    Tcl_Interp *interp,
    NtkWidgetInfo *infoPtr,
    const char *funcName,
    int objc,
    int numParams)
{
    const char *cp;
    int i;
    
    if (objc != numParams+1) {
        for (i=0; NtkWidgetMethodList[i].commandName != NULL; i++) {
	    cp = strrchr(NtkWidgetMethodList[i].commandName, ':');
	    if (cp == NULL) {
	        cp = NtkWidgetMethodList[i].commandName;
	    } else {
	        cp++;
	    }
	    if (strcmp(cp, funcName) == 0) {
                Tcl_AppendResult(interp,
                        "wrong # args: should be \"ntk glwidget ",
		        funcName, " ", 
		        NtkWidgetMethodList[i].usage, "\"", NULL);
                return TCL_ERROR;
            }
        }
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidget_CreateCmd()
 *
 *  Handles the ntk widget create command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidget_CreateCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_HashEntry *hPtr;
    Tcl_Obj *objPtr;
    NtkWidgetInfo *infoPtr;
    NtkWidget *wgtPtr;
    const char **argv;
    char buf[30];
    int width;
    int height;
    int argc;
    int isNew;

    infoPtr = (NtkWidgetInfo *)clientData;
    NtkWidgetShowArgs(0, "NtkWIdget_CreateCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "create", objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[1], &width) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &height) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_SplitList(NULL, Tcl_GetString(objv[3]), &argc, &argv) != TCL_OK) {
        return TCL_ERROR;
    }
    if (argc != 2) {
	Tcl_AppendResult(interp, "bad argument value for itemsize \"",
	        Tcl_GetString(objv[3]), "\"", NULL);
        ckfree((char *)argv);
        return TCL_ERROR;
    }
    wgtPtr = (NtkWidget *)ckalloc(sizeof(NtkWidget));
    wgtPtr->width = width;
    wgtPtr->height = height;
    wgtPtr->numTypeItems = atoi(argv[0]);
    wgtPtr->numTypeEntryBits =  atoi(argv[1]);
    wgtPtr->typeEntryBytes = (wgtPtr->numTypeItems *
            (wgtPtr->numTypeEntryBits / 8));
    wgtPtr->fontInfo = NULL;
    wgtPtr->fontInfoSize = 0;
    wgtPtr->dataSize = width * height * wgtPtr->typeEntryBytes;
    wgtPtr->data = (char *)ckalloc(wgtPtr->dataSize);
    sprintf(buf, "widget_%d", infoPtr->numWidgets);
    objPtr = Tcl_NewStringObj(buf, -1);
    Tcl_IncrRefCount(objPtr);
    infoPtr->numWidgets++;
    hPtr = Tcl_CreateHashEntry(&infoPtr->widgets, (char *)objPtr, &isNew);
    Tcl_SetHashValue(hPtr, wgtPtr);
    Tcl_SetObjResult(interp, objPtr);
    ckfree((char *)argv);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidget_CreateTextCmd()
 *
 *  Handles the ntk widget createtext command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidget_CreateTextCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_HashEntry *hPtr;
    Tcl_Obj *objPtr;
    Tcl_Obj *varPtr;
    NtkWidgetInfo *infoPtr;
    NtkWidget *wgtPtr;
    const char *fontName;
    int fontSize;
    unsigned char rgba[4];
    int result;

    result = TCL_OK;
    infoPtr = (NtkWidgetInfo *)clientData;
    NtkWidgetShowArgs(0, "NtkWIdget_CreateTextCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "createtext", objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
    fontName = Tcl_GetString(objv[2]);
    if (Tcl_GetIntFromObj(interp, objv[3], &fontSize) != TCL_OK) {
        return TCL_ERROR;
    }
    if (ExtractRGBAValues(interp, objv[5], &rgba[0], &rgba[1],
            &rgba[2], &rgba[3]) != TCL_OK) {
        return TCL_ERROR;
    }
    if (NtkWidget_GetFreeTypeInfo(interp, infoPtr, fontName, fontSize,
            rgba, objv[4], wgtPtr) != TCL_OK) {
	return TCL_ERROR;
    }
fprintf(stderr, "bwidth!%d!%d!\n", wgtPtr->width, wgtPtr->height);
int i;
unsigned char *bp;
bp = wgtPtr->data;
for(i=0;i<wgtPtr->width*wgtPtr->height*4; i++) {
//fprintf(stderr, "0x%0x2 0x%02x 0x%02x 0x%02x\n", bp[i], bp[i+1],bp[i+2],bp[i+3]);
i+= 3;
}
fprintf(stderr, "W!%d!%d!\n", wgtPtr->width, wgtPtr->height);
    objPtr = Tcl_NewIntObj(wgtPtr->width);
    Tcl_IncrRefCount(objPtr);
fprintf(stderr, "SET!%s!%s!\n", Tcl_GetCurrentNamespace(interp)->fullName, Tcl_GetString(objv[6]));
    varPtr = Tcl_ObjSetVar2(interp, objv[6], NULL, objPtr, /*flags*/0);
    if (varPtr == NULL) {
        result = TCL_ERROR;
	goto outerr;
    }
    objPtr = Tcl_NewIntObj(wgtPtr->height);
    Tcl_IncrRefCount(objPtr);
fprintf(stderr, "SET!%s!%s!\n", Tcl_GetCurrentNamespace(interp)->fullName, Tcl_GetString(objv[7]));
    varPtr = Tcl_ObjSetVar2(interp, objv[7], NULL, objPtr, /*flags*/0);
    if (varPtr == NULL) {
        result = TCL_ERROR;
	goto outerr;
    }
    goto out;

outerr:
    
out:
    ckfree((char *)wgtPtr->fontInfo);
    wgtPtr->fontInfo = NULL;
    wgtPtr->fontInfoSize = 0;
    return result;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidget_LineCmd()
 *
 *  Handles the ntk widget line command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidget_LineCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_HashEntry *hPtr;
    NtkWidget *wgtPtr;
    NtkWidgetInfo *infoPtr;
    int x1;
    int y1;
    int x2;
    int y2;
    /* FIX ME if we don't use bytes as RGBA values !! */
    unsigned char rgba[4];

    infoPtr = (NtkWidgetInfo *)clientData;
    NtkWidgetShowArgs(0, "NtkWIdget_LineCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "line", objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
    if (Tcl_GetIntFromObj(interp, objv[2], &x1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[3], &y1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[4], &x2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[5], &y2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (ExtractRGBAValues(interp, objv[6], &rgba[0], &rgba[1],
            &rgba[2], &rgba[3]) != TCL_OK) {
        return TCL_ERROR;
    }
    return NtkWidgetLine(interp, wgtPtr, x1, y1, x2, y2, rgba);
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidget_BlendCmd()
 *
 *  Handles the ntk widget blend command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidget_BlendCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidget *wgtPtr;

    infoPtr = (NtkWidgetInfo *)clientData;
    NtkWidgetShowArgs(0, "NtkWIdget_BlendCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "blend", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
fprintf(stderr, "blend not yet implemented\n");
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidget_BlendWidgetCmd()
 *
 *  Handles the ntk widget blendwidget command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidget_BlendWidgetCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidget *wgtPtr;
    NtkWidget *srcWgtPtr;
    int x1;
    int y1;
    int x2;
    int y2;
    int destx;
    int desty;
    int idx;

    infoPtr = (NtkWidgetInfo *)clientData;
    NtkWidgetShowArgs(0, "NtkWIdget_BlendWidgetCmd", objc, objv);
    idx = -1;
    switch (objc) {
    case 5: {
	if (Tcl_GetIntFromObj (interp, objv[2], &destx) != TCL_OK) {
	    return TCL_ERROR;
	}
	if (Tcl_GetIntFromObj (interp, objv[3], &desty) != TCL_OK) {
	    return TCL_ERROR;
	}
	idx = 4;
	x1 = 0;
	y1 = 0;
        break;
      }
    case 9: {
	if (Tcl_GetIntFromObj (interp, objv[2], &destx) != TCL_OK) {
	    return TCL_ERROR;
	}
	if (Tcl_GetIntFromObj (interp, objv[3], &desty) != TCL_OK) {
	    return TCL_ERROR;
	}
	if (Tcl_GetIntFromObj (interp, objv[4], &x1) != TCL_OK) {
	    return TCL_ERROR;
	}
	if (Tcl_GetIntFromObj (interp, objv[5], &y1) != TCL_OK) {
	    return TCL_ERROR;
	}
	if (Tcl_GetIntFromObj (interp, objv[6], &x2) != TCL_OK) {
	    return TCL_ERROR;
	}
	if (Tcl_GetIntFromObj (interp, objv[7], &y2) != TCL_OK) {
	    return TCL_ERROR;
	}
	idx = 8;
        break;
      }
    default:
        CheckNumParams(interp, infoPtr, "blendwidget", objc, 1);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[idx]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[idx]), "\"", NULL);
        return TCL_ERROR;
    }
    srcWgtPtr = Tcl_GetHashValue(hPtr);
    if (idx == 4) {
        x2 = wgtPtr->width;
        y2 = wgtPtr->height;
    }
    NtkWidgetBlend(interp, wgtPtr, srcWgtPtr, destx, desty, x1, y1, x2, y2);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidget_GetDataCmd()
 *
 *  Handles the ntk widget getdata command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidget_GetDataCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_Obj *objPtr;
    NtkWidgetInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidget *wgtPtr;

    infoPtr = (NtkWidgetInfo *)clientData;
    NtkWidgetShowArgs(0, "NtkWIdget_GetDataCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "getdata", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
    objPtr = Tcl_NewByteArrayObj(wgtPtr->data, wgtPtr->dataSize);
    Tcl_SetObjResult(interp, objPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidget_GetSizeCmd()
 *
 *  Handles the ntk widget getsize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidget_GetSizeCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_Obj *listPtr;
    NtkWidgetInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidget *wgtPtr;

    infoPtr = (NtkWidgetInfo *)clientData;
    NtkWidgetShowArgs(0, "NtkWIdget_GetSizeCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "getsize", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
    listPtr = Tcl_NewListObj(0, NULL);
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(wgtPtr->width));
    Tcl_ListObjAppendElement(interp, listPtr, Tcl_NewIntObj(wgtPtr->height));
    Tcl_SetObjResult(interp, listPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidget_FillCmd()
 *
 *  Handles the ntk widget fill command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidget_FillCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_HashEntry *hPtr;
    NtkWidgetInfo *infoPtr;
    NtkWidget *wgtPtr;
    unsigned char rgba[4];

    infoPtr = (NtkWidgetInfo *)clientData;
    NtkWidgetShowArgs(0, "NtkWIdget_FillCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "fill", objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
    if (ExtractRGBAValues(interp, objv[2], &rgba[0], &rgba[1],
            &rgba[2], &rgba[3]) != TCL_OK) {
        return TCL_ERROR;
    }
    return NtkWidgetFill(interp, wgtPtr, rgba);
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidget_SetDataCmd()
 *
 *  Handles the ntk widget setdata command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidget_SetDataCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidget *wgtPtr;
    NtkWidget *srcWgtPtr;

    infoPtr = (NtkWidgetInfo *)clientData;
    NtkWidgetShowArgs(0, "NtkWIdget_SetDataCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "setdata", objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[2]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    srcWgtPtr = Tcl_GetHashValue(hPtr);
    ckfree((char *)wgtPtr->data);
    memcpy(wgtPtr, srcWgtPtr, sizeof(NtkWidget));
    wgtPtr->data = (char*)ckalloc(srcWgtPtr->dataSize);
    memcpy(wgtPtr->data, srcWgtPtr->data, srcWgtPtr->dataSize);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidget_SetSizeCmd()
 *
 *  Handles the ntk widget setsize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidget_SetSizeCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidget *wgtPtr;
    char *newBytes;
    int newSize;
    int width;
    int height;

    infoPtr = (NtkWidgetInfo *)clientData;
    NtkWidgetShowArgs(0, "NtkWIdget_SetSizeCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "setsize", objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
    if (Tcl_GetIntFromObj (interp, objv[2], &width) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj (interp, objv[3], &height) != TCL_OK) {
        return TCL_ERROR;
    }
    if ((wgtPtr->width == width) && (wgtPtr->height == height)) {
        return TCL_OK;
    }
    newSize = width * height * wgtPtr->typeEntryBytes;
    newBytes = ckalloc(newSize);
    if (newBytes == NULL) {
	Tcl_SetResult (interp, "unable to setsize.", TCL_STATIC);
	Tcl_AppendResult (interp, "  more info: ",
	        (char *)Tcl_PosixError (interp), NULL);
        return TCL_ERROR;
    }
    ckfree((char *)wgtPtr->data);
    wgtPtr->width = width;
    wgtPtr->height = height;
    wgtPtr->dataSize = newSize;
    wgtPtr->data = newBytes;
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidget_RectangleCmd()
 *
 *  Handles the ntk widget rectangle command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidget_RectangleCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidget *wgtPtr;

    infoPtr = (NtkWidgetInfo *)clientData;
    NtkWidgetShowArgs(0, "NtkWIdget_RectangleCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "rectangle", objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
fprintf(stderr, "rectangle not yet implemented\n");
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidget_RotateCmd()
 *
 *  Handles the ntk widget rotate command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidget_RotateCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidget *wgtPtr;
    int degrees;

    infoPtr = (NtkWidgetInfo *)clientData;
    NtkWidgetShowArgs(0, "NtkWIdget_RotateCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "rotate", objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
    if (Tcl_GetIntFromObj (interp, objv[2], &degrees) != TCL_OK) {
        return TCL_ERROR;
    }
    return NtkWidgetRotate(interp, wgtPtr, degrees);
}
