/*
 * ntkWidgetImageCmd.c --
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
 * RCS: @(#) $Id: ntkWidgetImageCmd.c,v 1.1.2.8 2007/12/01 22:52:27 wiede Exp $
 */

#include <stdlib.h>
#include "ntkWidgetImageInt.h"

Tcl_ObjCmdProc NtkWidgetImage_UnknownCmd;
Tcl_ObjCmdProc NtkWidgetImage_BlendCmd;
Tcl_ObjCmdProc NtkWidgetImage_BlendWidgetCmd;
Tcl_ObjCmdProc NtkWidgetImage_CreateCmd;
Tcl_ObjCmdProc NtkWidgetImage_CreateTextCmd;
Tcl_ObjCmdProc NtkWidgetImage_ClipCopyWidgetCmd;
Tcl_ObjCmdProc NtkWidgetImage_FillCmd;
Tcl_ObjCmdProc NtkWidgetImage_GetDataCmd;
Tcl_ObjCmdProc NtkWidgetImage_GetSizeCmd;
Tcl_ObjCmdProc NtkWidgetImage_LineCmd;
Tcl_ObjCmdProc NtkWidgetImage_MeasureTextCmd;
Tcl_ObjCmdProc NtkWidgetImage_PixelCmd;
Tcl_ObjCmdProc NtkWidgetImage_PolygonCmd;
Tcl_ObjCmdProc NtkWidgetImage_RectangleCmd;
Tcl_ObjCmdProc NtkWidgetImage_RotateCmd;
Tcl_ObjCmdProc NtkWidgetImage_SetDataCmd;
Tcl_ObjCmdProc NtkWidgetImage_SetSizeCmd;

typedef struct NtkWidgetImageMethod {
    char *commandName;       /* the command name with the namespace prefix */
    char *usage;             /* string describing usage */
    Tcl_ObjCmdProc *proc;    /* implementation C proc */
} NtkWidgetImageMethod;

static NtkWidgetImageMethod NtkWidgetImageMethodList[] = {
    { "::ntk::widgetImage::Image::unknown",
            "", NtkWidgetImage_UnknownCmd },
    { "::ntk::widgetImage::Image::blend",
            "dstWidgetImage", NtkWidgetImage_BlendCmd },
    { "::ntk::widgetImage::Image::blendwidget",
            "dstWidgetImage destX destY ?srcX1 srcY1 srcX2 srcY2? srcWidget",
	    NtkWidgetImage_BlendWidgetCmd },
    { "::ntk::widgetImage::Image::clipcopy",
            "dstWidgetImage destX destY srcX srcY srcWidget",
	    NtkWidgetImage_ClipCopyWidgetCmd },
    { "::ntk::widgetImage::Image::create",
            "width height", NtkWidgetImage_CreateCmd },
    { "::ntk::widgetImage::Image::createtext",
            "dstWidgetImage font fontsize text textcolor widthVar heightVar",
	    NtkWidgetImage_CreateTextCmd },
    { "::ntk::widgetImage::Image::fill",
            "dstWidgetImage rgbaList", NtkWidgetImage_FillCmd },
    { "::ntk::widgetImage::Image::getdata",
            "dstWidgetImage", NtkWidgetImage_GetDataCmd },
    { "::ntk::widgetImage::Image::getsize",
            "dstWidgetImage", NtkWidgetImage_GetSizeCmd },
    { "::ntk::widgetImage::Image::line",
            "dstWidgetImage x1 y1 x2 y2 rgbaList", NtkWidgetImage_LineCmd },
    { "::ntk::widgetImage::Image::measuretext",
            "dstWidgetImage font fontsize text widthVar heightVar",
	    NtkWidgetImage_MeasureTextCmd },
    { "::ntk::widgetImage::Image::pixel",
            "dstWidgetImage x y", NtkWidgetImage_PixelCmd },
    { "::ntk::widgetImage::Image::polygon",
            "dstWwidgetImage rgbaList x1 y1 x2 y2 ...", \
	    NtkWidgetImage_PolygonCmd },
    { "::ntk::widgetImage::Image::rectangle",
            "dstWidgetImage x y width height rgbaList",
	    NtkWidgetImage_RectangleCmd },
    { "::ntk::widgetImage::Image::rotate",
            "dstWidgetImage degrees", NtkWidgetImage_RotateCmd },
    { "::ntk::widgetImage::Image::setdata",
            "dstWidgetImage data", NtkWidgetImage_SetDataCmd },
    { "::ntk::widgetImage::Image::setsize",
            "dstWidgetImage width height", NtkWidgetImage_SetSizeCmd },
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
    NtkWidgetImageInfo *infoPtr)
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
 *  NtkWidgetImage_InitCommands()
 *
 *      that is the starting point when loading the library
 *      it initializes all internal stuff
 *
 * ------------------------------------------------------------------------
 */

int
NtkWidgetImage_InitCommands (
    Tcl_Interp *interp,
    NtkWidgetImageInfo *infoPtr)
{
    Tcl_Namespace *nsPtr;
    Tcl_Command cmd;
    int i;

    /*
     * Build the ensemble used to implement [ntk widget].
     */

    nsPtr = Tcl_CreateNamespace(interp, "::ntk::widgetImage::Image", NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("ntkWidgetImage: error in creating namespace: ::ntk::widgetImage::Image \n");
    }
    cmd = Tcl_CreateEnsemble(interp, nsPtr->fullName, nsPtr,
        TCL_ENSEMBLE_PREFIX);
    Tcl_Export(interp, nsPtr, "[a-z]*", 1);
    for (i=0; NtkWidgetImageMethodList[i].commandName!=NULL; i++) {
        Tcl_CreateObjCommand(interp, NtkWidgetImageMethodList[i].commandName,
                NtkWidgetImageMethodList[i].proc, infoPtr, NULL);
    }
    Tcl_Obj *ensObjPtr = Tcl_NewStringObj("::ntk::widgetImage::Image", -1);
    Tcl_IncrRefCount(ensObjPtr);
    Tcl_Obj *unkObjPtr = Tcl_NewStringObj("::ntk::widgetImage::Image::unknown", -1);
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
 *  NtkWidgetImageGetUsage()
 *
 * ------------------------------------------------------------------------
  */
void
NtkWidgetImageGetUsage(
    Tcl_Interp *interp,
    NtkWidgetImageInfo *infoPtr,
    Tcl_Obj *objPtr)       /* returns: summary of usage info */
{
    const char *cp;
    char *spaces = "  ";
    int i;

    for (i=0; NtkWidgetImageMethodList[i].commandName != NULL; i++) {
	if (strcmp(NtkWidgetImageMethodList[i].commandName,
	        "::ntk::widget::Widget::unknown") == 0) {
	    continue;
	}
        Tcl_AppendToObj(objPtr, spaces, -1);
        Tcl_AppendToObj(objPtr, "ntk widget ", -1);
	cp = strrchr(NtkWidgetImageMethodList[i].commandName, ':');
	if (cp == NULL) {
	   cp = NtkWidgetImageMethodList[i].commandName;
	} else {
	   cp++;
	}
        Tcl_AppendToObj(objPtr, cp, -1);
        if (strlen(NtkWidgetImageMethodList[i].usage) > 0) {
            Tcl_AppendToObj(objPtr, " ", -1);
            Tcl_AppendToObj(objPtr, NtkWidgetImageMethodList[i].usage, -1);
	}
        spaces = "\n  ";
    }
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetImage_UnknownCmd()
 *
 *  the unknown handler for the ::ntk::widget::Widget ensemble
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_UnknownCmd(
    ClientData clientData,   /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetImageInfo *infoPtr;
    int result;

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWidgetImage_UnknownCmd", objc, objv);
    result = TCL_ERROR;
    /* produce usage message */
    Tcl_Obj *objPtr = Tcl_NewStringObj("unknown command: \"", -1);
    Tcl_AppendToObj(objPtr, Tcl_GetString(objv[2]), -1);
    Tcl_AppendToObj(objPtr, "\" should be one of...\n", -1);
    NtkWidgetImageGetUsage(interp, infoPtr, objPtr);
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

static int
CheckNumParams(
    Tcl_Interp *interp,
    NtkWidgetImageInfo *infoPtr,
    const char *funcName,
    int objc,
    int numParams,
    int maxParams)
{
    const char *cp;
    int i;
    
    if ((objc < numParams+1) || ((objc > maxParams+1) && (maxParams != -1))) {
        for (i=0; NtkWidgetImageMethodList[i].commandName != NULL; i++) {
	    cp = strrchr(NtkWidgetImageMethodList[i].commandName, ':');
	    if (cp == NULL) {
	        cp = NtkWidgetImageMethodList[i].commandName;
	    } else {
	        cp++;
	    }
	    if (strcmp(cp, funcName) == 0) {
                Tcl_AppendResult(interp,
                        "wrong # args: should be \"::ntk::widgetImage::Image ",
		        funcName, " ", 
		        NtkWidgetImageMethodList[i].usage, "\"", NULL);
                return TCL_ERROR;
            }
        }
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetImage_CreateCmd()
 *
 *  Handles the ntk widget create command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_CreateCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_HashEntry *hPtr;
    Tcl_Obj *objPtr;
    NtkWidgetImageInfo *infoPtr;
    NtkWidgetImage *wgtPtr;
    char buf[30];
    int width;
    int height;
    int isNew;

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_CreateCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "create", objc, 2, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[1], &width) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &height) != TCL_OK) {
        return TCL_ERROR;
    }
    wgtPtr = (NtkWidgetImage *)ckalloc(sizeof(NtkWidgetImage));
    wgtPtr->width = width;
    wgtPtr->height = height;
#define NUM_TYPE_ITEMS 4
#define NUM_TYPE_ENTRY_BITS 8
    wgtPtr->numTypeItems = NUM_TYPE_ITEMS;
    wgtPtr->numTypeEntryBits = NUM_TYPE_ENTRY_BITS;
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
//fprintf(stderr, "CREAWID!%s!%s!\n", Tcl_GetCurrentNamespace(interp)->fullName, Tcl_GetString(objPtr));
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetImage_CreateTextCmd()
 *
 *  Handles the ntk widget createtext command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_CreateTextCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_HashEntry *hPtr;
    Tcl_Obj *objPtr;
    Tcl_Obj *varPtr;
    NtkWidgetImageInfo *infoPtr;
    NtkWidgetImage *wgtPtr;
    const char *fontName;
    int fontSize;
    unsigned char rgba[4];
    int result;

    result = TCL_OK;
    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_CreateTextCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "createtext", objc, 7, 8) != TCL_OK) {
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
    if (strlen(Tcl_GetString(objv[4])) == 0) {
        /* FIX ME free old contents !! */
	wgtPtr->width = 0;
    } else {
        if (NtkWidgetImage_GetFreeTypeInfo(interp, infoPtr, fontName, fontSize,
                rgba, objv[4], wgtPtr, 0) != TCL_OK) {
	    return TCL_ERROR;
        }
    }
    objPtr = Tcl_NewIntObj(wgtPtr->width);
    Tcl_IncrRefCount(objPtr);
//fprintf(stderr, "SET!%s!%s!\n", Tcl_GetCurrentNamespace(interp)->fullName, Tcl_GetString(objv[6]));
    varPtr = Tcl_ObjSetVar2(interp, objv[6], NULL, objPtr, /*flags*/0);
    if (varPtr == NULL) {
        result = TCL_ERROR;
	goto outerr;
    }
    objPtr = Tcl_NewIntObj(wgtPtr->height);
    Tcl_IncrRefCount(objPtr);
//fprintf(stderr, "SET!%s!%s!\n", Tcl_GetCurrentNamespace(interp)->fullName, Tcl_GetString(objv[7]));
    varPtr = Tcl_ObjSetVar2(interp, objv[7], NULL, objPtr, /*flags*/0);
    if (varPtr == NULL) {
        result = TCL_ERROR;
	goto outerr;
    }
    if (objc == 9) {
	objPtr = Tcl_NewListObj(0, NULL);
        Tcl_IncrRefCount(objPtr);
	if (wgtPtr->width > 0) {
            if (NtkWidgetImage_GetFreeTypeOffsetMap(interp, wgtPtr, objPtr) !=
	            TCL_OK) {
                Tcl_DecrRefCount(objPtr);
	        result = TCL_ERROR;
	        goto outerr;
	    }
	}
        varPtr = Tcl_ObjSetVar2(interp, objv[8], NULL, objPtr, /*flags*/0);
        Tcl_DecrRefCount(objPtr);
        if (varPtr == NULL) {
            result = TCL_ERROR;
	    goto outerr;
        }
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
 *  NtkWidgetImage_MeasureTextCmd()
 *
 *  Handles the ntk widget measuetext command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_MeasureTextCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_Obj *objPtr;
    Tcl_Obj *varPtr;
    NtkWidgetImageInfo *infoPtr;
    NtkWidgetImage *wgtPtr;
    const char *fontName;
    int fontSize;
    unsigned char rgba[4];
    int result;

    result = TCL_OK;
    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_MeasueTextCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "measuretext", objc, 5, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    fontName = Tcl_GetString(objv[1]);
    if (Tcl_GetIntFromObj(interp, objv[2], &fontSize) != TCL_OK) {
        return TCL_ERROR;
    }
    wgtPtr = (NtkWidgetImage *)ckalloc(sizeof(NtkWidgetImage));
    wgtPtr->width = 0;
    wgtPtr->height = 0;
#define NUM_TYPE_ITEMS 4
#define NUM_TYPE_ENTRY_BITS 8
    wgtPtr->numTypeItems = NUM_TYPE_ITEMS;
    wgtPtr->numTypeEntryBits = NUM_TYPE_ENTRY_BITS;
    wgtPtr->typeEntryBytes = (wgtPtr->numTypeItems *
            (wgtPtr->numTypeEntryBits / 8));
    wgtPtr->fontInfo = NULL;
    wgtPtr->fontInfoSize = fontSize;
    wgtPtr->dataSize = 0;
    wgtPtr->data = NULL;

    if (NtkWidgetImage_GetFreeTypeInfo(interp, infoPtr, fontName, fontSize,
            rgba, objv[3], wgtPtr, 1) != TCL_OK) {
	return TCL_ERROR;
    }
    objPtr = Tcl_NewIntObj(wgtPtr->width);
    Tcl_IncrRefCount(objPtr);
    varPtr = Tcl_ObjSetVar2(interp, objv[4], NULL, objPtr, /*flags*/0);
    if (varPtr == NULL) {
        result = TCL_ERROR;
	goto outerr;
    }
    objPtr = Tcl_NewIntObj(wgtPtr->height);
    Tcl_IncrRefCount(objPtr);
    varPtr = Tcl_ObjSetVar2(interp, objv[5], NULL, objPtr, /*flags*/0);
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
 *  NtkWidgetImage_LineCmd()
 *
 *  Handles the ntk widget line command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_LineCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_HashEntry *hPtr;
    NtkWidgetImage *wgtPtr;
    NtkWidgetImageInfo *infoPtr;
    int x1;
    int y1;
    int x2;
    int y2;
    /* FIX ME if we don't use bytes as RGBA values !! */
    unsigned char rgba[4];

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_LineCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "line", objc, 6, 6) != TCL_OK) {
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
    return NtkWidgetImageLine(interp, wgtPtr, x1, y1, x2, y2, rgba);
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetImage_BlendCmd()
 *
 *  Handles the ntk widget blend command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_BlendCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetImageInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidgetImage *wgtPtr;

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_BlendCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "blend", objc, 1, 1) != TCL_OK) {
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
 *  NtkWidgetImage_BlendWidgetCmd()
 *
 *  Handles the ntk widget blendwidget command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_BlendWidgetCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetImageInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidgetImage *wgtPtr;
    NtkWidgetImage *srcWgtPtr;
    int x1;
    int y1;
    int x2;
    int y2;
    int destx;
    int desty;
    int idx;

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_BlendWidgetCmd", objc, objv);
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
        CheckNumParams(interp, infoPtr, "blendwidget", objc, 1, 1);
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
    NtkWidgetImageBlend(interp, wgtPtr, srcWgtPtr, destx, desty,
            x1, y1, x2, y2);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetImage_ClipCopyWidgetCmd()
 *
 *  Handles the ntk widget clipcopy command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_ClipCopyWidgetCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetImageInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidgetImage *wgtPtr;
    NtkWidgetImage *srcWgtPtr;
    int srcx;
    int srcy;
    int dstx;
    int dsty;

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_ClipCopyWidgetCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "clipcopy", objc, 6, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj (interp, objv[2], &dstx) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj (interp, objv[3], &dsty) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj (interp, objv[4], &srcx) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj (interp, objv[5], &srcy) != TCL_OK) {
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[6]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[6]), "\"", NULL);
        return TCL_ERROR;
    }
    srcWgtPtr = Tcl_GetHashValue(hPtr);
    NtkWidgetImageClipCopy(interp, wgtPtr, srcWgtPtr, dstx, dsty, srcx, srcy);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetImage_GetDataCmd()
 *
 *  Handles the ntk widget getdata command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_GetDataCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_Obj *objPtr;
    NtkWidgetImageInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidgetImage *wgtPtr;

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_GetDataCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "getdata", objc, 1, 1) != TCL_OK) {
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
 *  NtkWidgetImage_GetSizeCmd()
 *
 *  Handles the ntk widget getsize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_GetSizeCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_Obj *listPtr;
    NtkWidgetImageInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidgetImage *wgtPtr;

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_GetSizeCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "getsize", objc, 1, 1) != TCL_OK) {
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
 *  NtkWidgetImage_FillCmd()
 *
 *  Handles the ntk widget fill command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_FillCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_HashEntry *hPtr;
    NtkWidgetImageInfo *infoPtr;
    NtkWidgetImage *wgtPtr;
    unsigned char rgba[4];

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_FillCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "fill", objc, 2, 2) != TCL_OK) {
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
    return NtkWidgetImageFill(interp, wgtPtr, rgba);
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetImage_SetDataCmd()
 *
 *  Handles the ntk widget setdata command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_SetDataCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetImageInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidgetImage *wgtPtr;
    NtkWidgetImage *srcWgtPtr;

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_SetDataCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "setdata", objc, 2, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such source widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[2]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such destination widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    srcWgtPtr = Tcl_GetHashValue(hPtr);
    ckfree((char *)wgtPtr->data);
    memcpy(wgtPtr, srcWgtPtr, sizeof(NtkWidgetImage));
    wgtPtr->data = (char*)ckalloc(srcWgtPtr->dataSize);
    memcpy(wgtPtr->data, srcWgtPtr->data, srcWgtPtr->dataSize);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetImage_SetSizeCmd()
 *
 *  Handles the ntk widget setsize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_SetSizeCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetImageInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidgetImage *wgtPtr;
    char *newBytes;
    int newSize;
    int width;
    int height;

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_SetSizeCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "setsize", objc, 3, 3) != TCL_OK) {
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
 *  NtkWidgetImage_RectangleCmd()
 *
 *  Handles the ntk widget rectangle command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_RectangleCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetImageInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidgetImage *wgtPtr;
    unsigned char rgba[4];
    int x;
    int y;
    int width;
    int height;

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_RectangleCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "rectangle", objc, 6, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
    if (Tcl_GetIntFromObj (interp, objv[2], &x) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj (interp, objv[3], &y) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj (interp, objv[4], &width) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj (interp, objv[5], &height) != TCL_OK) {
        return TCL_ERROR;
    }
    if (ExtractRGBAValues(interp, objv[6], &rgba[0], &rgba[1],
            &rgba[2], &rgba[3]) != TCL_OK) {
        return TCL_ERROR;
    }
    return NtkWidgetImageMakeRectangle(wgtPtr, x, y, width, height, rgba);
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetImage_PolygonCmd()
 *
 *  Handles the ntk widget polygon command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_PolygonCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetImageInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidgetImage *wgtPtr;
    unsigned char rgba[4];
    int *points;
    int numPoints;
    int i;
    int result;

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_PolygonCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "polygon", objc, 8, -1) != TCL_OK) {
        return TCL_ERROR;
    }
    if ((objc - 3) % 2) {
        Tcl_SetResult (interp,
	        "invalid arguments: uneven number of polygon components",
		TCL_STATIC);
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
    numPoints = (objc - 3);
    points = (int *)ckalloc (sizeof (int) * numPoints);
    for (i = 3; i < objc; i++) {
        if (Tcl_GetIntFromObj (interp, objv[i], &points[i-3]) != TCL_OK) {
            ckfree ((char *)points);
            return TCL_ERROR;
        }
        i++;
        if (Tcl_GetIntFromObj (interp, objv[i], &points[i-3]) != TCL_OK) {
            ckfree ((char *)points);
            return TCL_ERROR;
        }
    }
    result = NtkWidgetImageMakePolygon(wgtPtr, numPoints, points, rgba);
    ckfree ((char *)points);
    return result;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetImage_RotateCmd()
 *
 *  Handles the ntk widget rotate command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_RotateCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    NtkWidgetImageInfo *infoPtr;
    Tcl_HashEntry *hPtr;
    NtkWidgetImage *wgtPtr;
    int degrees;

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_RotateCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "rotate", objc, 2, 2) != TCL_OK) {
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
    return NtkWidgetImageRotate(interp, wgtPtr, degrees);
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetImage_PixelCmd()
 *
 *  Handles the ntk widget pixel command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
NtkWidgetImage_PixelCmd(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_Obj *rgba;
    Tcl_Obj *ar[4];
    Tcl_HashEntry *hPtr;
    NtkWidgetImage *wgtPtr;
    NtkWidgetImageInfo *infoPtr;
    unsigned char *p;
    int x;
    int y;

    infoPtr = (NtkWidgetImageInfo *)clientData;
    NtkWidgetImageShowArgs(1, "NtkWIdget_PixelCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, "pixel", objc, 3, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->widgets, (char *)objv[1]);
    if (hPtr == NULL) {
	Tcl_AppendResult(interp, "no such widget: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
        return TCL_ERROR;
    }
    wgtPtr = Tcl_GetHashValue(hPtr);
    if (Tcl_GetIntFromObj (interp, objv[2], &x) != TCL_OK) {
        return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj (interp, objv[3], &y) != TCL_OK) {
        return TCL_ERROR;
    }
    if ((x < 0) || (x >= wgtPtr->width)) {
        Tcl_SetResult (interp, "invalid x range", TCL_STATIC);
        return TCL_ERROR;
    }
    if ((y < 0) || (y >= wgtPtr->height)) {
        Tcl_SetResult (interp, "invalid y range", TCL_STATIC);
        return TCL_ERROR;
    }
    p = wgtPtr->data + (wgtPtr->width * 4 * y) + (x * 4);
    ar[0] = Tcl_NewIntObj (*p & 255);
    p++;
    ar[1] = Tcl_NewIntObj (*p & 255);
    p++;
    ar[2] = Tcl_NewIntObj (*p & 255);
    p++;
    ar[3] = Tcl_NewIntObj (*p & 255);
    Tcl_IncrRefCount (ar[0]);
    Tcl_IncrRefCount (ar[1]);
    Tcl_IncrRefCount (ar[2]);
    Tcl_IncrRefCount (ar[3]);
    rgba = Tcl_NewListObj (4, ar);
    Tcl_IncrRefCount (rgba);
    Tcl_DecrRefCount (ar[0]);
    Tcl_DecrRefCount (ar[1]);
    Tcl_DecrRefCount (ar[2]);
    Tcl_DecrRefCount (ar[3]);
    Tcl_SetObjResult (interp, rgba);
    Tcl_DecrRefCount (rgba);
    return TCL_OK;
}
