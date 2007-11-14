/*
 * ntkWidgetUtil.c --
 *
 * This file contains the C-implemeted part of a
 * Tcl interface for rendering widgets as bitmaps
 *
 * this is based on the megaimage package written by George Peter Staplin
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann and George Peter Staplin
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: ntkWidgetUtil.c,v 1.1.2.1 2007/11/14 17:35:07 wiede Exp $
 */

#include "ntkWidgetInt.h"

/* to be tried !! ((srcColor*srcAlpha)>>8 ) + ((((dstAlpha*(256-srcAlpha))>>8 )*dstColor)>>8 ) */
#define BLEND(a,b,alpha) (((a * (255 - alpha)) + (b * alpha)) / 255) & 255
#define PUT_PIXEL(bp,rgba) *bp++ = rgba[0]; *bp++ = rgba[1]; *bp++ = rgba[2]; *bp++ = rgba[3];
#define GET_PIXEL_PTR(wgtPtr,x,y) (wgtPtr->data +(wgtPtr->width*y*wgtPtr->typeEntryBytes) + (x*wgtPtr->typeEntryBytes))

#ifdef NTK_WIDGET_DEBUG
int _ntk_widget_debug_level = 0;

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetShowArgs()
 * ------------------------------------------------------------------------
 */

void
NtkWidgetShowArgs(
    int level,
    const char *str,
    int objc,
    Tcl_Obj * const* objv)
{
    int i;

    if (level > _ntk_widget_debug_level) {
        return;
    }
    fprintf(stderr, "%s", str);
    for (i = 0; i < objc; i++) {
        fprintf(stderr, "!%s", objv[i] == NULL ? "??" :
                Tcl_GetString(objv[i]));
    }
    fprintf(stderr, "!\n");
}
#endif


/*
 * ------------------------------------------------------------------------
 *  ExtractRGBAValues()
 *
 *  extracts the values for r (red) g (green) b (blue) and a (alpha)
 *  from a Tcl list
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
ExtractRGBAValues(
    Tcl_Interp *interp,
    Tcl_Obj *objPtr,
    unsigned char *r,
    unsigned char *g,
    unsigned char *b,
    unsigned char *a)
{
    Tcl_Obj **objv;
    int tmp;
    int objc;

    if (Tcl_ListObjGetElements (interp, objPtr, &objc, &objv) != TCL_OK) {
        return TCL_ERROR;
    }
    if (objc != 4) {
        Tcl_AppendResult(interp, "Invalid number of list elements for a pixel.",
	        TCL_STATIC);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj (interp, objv[0], &tmp) != TCL_OK) {
        return TCL_ERROR;
    }
    *r = (unsigned char)tmp;
    if (Tcl_GetIntFromObj (interp, objv[1], &tmp) != TCL_OK) {
        return TCL_ERROR;
    }
    *g = (unsigned char)tmp;
    if (Tcl_GetIntFromObj (interp, objv[2], &tmp) != TCL_OK) {
        return TCL_ERROR;
    }
    *b = (unsigned char)tmp;
    if (Tcl_GetIntFromObj (interp, objv[3], &tmp) != TCL_OK) {
        return TCL_ERROR;
    }
    *a = (unsigned char)tmp;
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  WidgetVerticalLine()
 * ------------------------------------------------------------------------
 */

static void
WidgetVerticalLine(
    NtkWidget *wgtPtr,
    int x1,
    int y1,
    int dy,
    unsigned char *rgba)
{
    unsigned char *bp;

fprintf(stderr, "WidgetVerticalLine!%d!%d!%d\n", x1, y1, dy);
    bp = GET_PIXEL_PTR(wgtPtr, x1, y1);
    while (dy) {
        PUT_PIXEL(bp, rgba);
	bp += (wgtPtr->width * wgtPtr->typeEntryBytes) -
	        /*one pixel*/wgtPtr->typeEntryBytes;
	dy--;
    }
}

/*
 * ------------------------------------------------------------------------
 *  WidgetHorizontalLine()
 * ------------------------------------------------------------------------
 */

static void
WidgetHorizontalLine(
    NtkWidget *wgtPtr,
    int x1,
    int y1,
    int dx,
    unsigned char *rgba)
{
    unsigned char *bp;

fprintf(stderr, "WidgetHorizontalLine!%d!%d!%d\n", x1, y1, dx);
    bp = GET_PIXEL_PTR(wgtPtr, x1, y1);
    while (dx) {
        PUT_PIXEL(bp, rgba);
	dx--;
    }
}

/*
 * ------------------------------------------------------------------------
 *  WidgetDiagonalLine()
 * ------------------------------------------------------------------------
 */

static void
WidgetDiagonalLine(
    NtkWidget *wgtPtr,
    int x1,
    int y1,
    int dy,
    int xdir,
    unsigned char *rgba)
{
    unsigned char *bp;

fprintf(stderr, "WidgetDiagonalLine!%d!%d!%d!%d\n", x1, y1, dy, xdir);
    bp = GET_PIXEL_PTR(wgtPtr, x1, y1);
    while (dy) {
        PUT_PIXEL(bp, rgba);
	bp += (wgtPtr->width * wgtPtr->typeEntryBytes) -
	        /*one pixel*/wgtPtr->typeEntryBytes +
		(xdir * wgtPtr->typeEntryBytes);
	dy--;
    }
}

/*
 * ------------------------------------------------------------------------
 *  WidgetAdjustedLine()
 * ------------------------------------------------------------------------
 */

static void
WidgetAdjustedLine(
    NtkWidget *wgtPtr,
    int x1,
    int y1,
    int x2,
    int y2,
    int dx,
    int dy,
    int xdir,
    unsigned char *rgba)
{
    unsigned char *bp;
    unsigned char transparency;
    int erroracc;
    int erroradj;

fprintf(stderr, "WidgetAdjustedLine!%d!%d!%d!%d!%d!%d!%d!\n", x1, y1, x2, y2, dx, dy, xdir);
    bp = GET_PIXEL_PTR(wgtPtr, x1, y1);
    erroracc = 0;
    if (dy > dx) { // y-major line
        erroradj = (dx << 16) / dy;
        if (xdir < 0) {
            while (dy) {
                erroracc += erroradj;
                ++y1;
                x2 = x1 - (erroracc >> 16);
                transparency = erroracc >> 8;
                if ((x2 < wgtPtr->width) && (y1 < wgtPtr->height)) {
	            bp = GET_PIXEL_PTR(wgtPtr, x2, y1);
		    *bp = BLEND(*bp,rgba[0],~transparency); bp++;
		    *bp = BLEND(*bp,rgba[1],~transparency); bp++;
		    *bp = BLEND(*bp,rgba[2],~transparency); bp++;
		    *bp = BLEND(*bp,rgba[3],~transparency); bp++;
		}
                if (((x2 - 1) < wgtPtr->width) && (y1 < wgtPtr->height)) {
	            bp = GET_PIXEL_PTR(wgtPtr, x2-1, y1);
		    *bp = BLEND(*bp,rgba[0],transparency); bp++;
		    *bp = BLEND(*bp,rgba[1],transparency); bp++;
		    *bp = BLEND(*bp,rgba[2],transparency); bp++;
		    *bp = BLEND(*bp,rgba[3],transparency); bp++;
		}
                dy--;
            }
        } else {
            while (dy) {
                erroracc += erroradj;
                ++y1; 
                x2 = x1 + (erroracc >> 16);
                transparency = erroracc >> 8;
                if ((x2 < wgtPtr->width) && (y1 < wgtPtr->height)) {
	            bp = GET_PIXEL_PTR(wgtPtr, x2, y1);
		    *bp = BLEND(*bp,rgba[0],~transparency); bp++;
		    *bp = BLEND(*bp,rgba[1],~transparency); bp++;
		    *bp = BLEND(*bp,rgba[2],~transparency); bp++;
		    *bp = BLEND(*bp,rgba[3],~transparency); bp++;
                } 
                if (((x2 + xdir) < wgtPtr->width) && (y1 < wgtPtr->height)) {
	            bp = GET_PIXEL_PTR(wgtPtr, x2+xdir, y1);
		    *bp = BLEND(*bp,rgba[0],transparency); bp++;
		    *bp = BLEND(*bp,rgba[1],transparency); bp++;
		    *bp = BLEND(*bp,rgba[2],transparency); bp++;
		    *bp = BLEND(*bp,rgba[3],transparency); bp++;
                } 
                dy--;
            }
        }
    } else {
        erroradj = (dy << 16) / dx;
        while (dx) {
            erroracc += erroradj;
            x1 += xdir;
            y2 = y1 + (erroracc >> 16);
            transparency = erroracc >> 8;
            if ((x1 < wgtPtr->width) && (y2 < wgtPtr->height)) {
	        bp = GET_PIXEL_PTR(wgtPtr, x1, y2);
		*bp = BLEND(*bp,rgba[0],~transparency); bp++;
		*bp = BLEND(*bp,rgba[1],~transparency); bp++;
		*bp = BLEND(*bp,rgba[2],~transparency); bp++;
		*bp = BLEND(*bp,rgba[3],~transparency); bp++;
	    }
            if ((x1 < wgtPtr->width) && ((y2 + 1) < wgtPtr->height)) {
	        bp = GET_PIXEL_PTR(wgtPtr, x1, y2+1);
		*bp = BLEND(*bp,rgba[0],transparency); bp++;
		*bp = BLEND(*bp,rgba[1],transparency); bp++;
		*bp = BLEND(*bp,rgba[2],transparency); bp++;
		*bp = BLEND(*bp,rgba[3],transparency); bp++;
            }
            dx--;
        } 
    }
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetLine()
 * ------------------------------------------------------------------------
 */

int
NtkWidgetLine(
    Tcl_Interp *interp,
    NtkWidget *wgtPtr,
    int x1,
    int y1,
    int x2,
    int y2,
    unsigned char *rgba)
{
    unsigned char *bp;
    int tmp;
    int dx;
    int dy;
    int xdir;

    if (y1 > y2) {
        tmp = x1; x1 = x2; x2 = tmp;
        tmp = y1; y1 = y2; y2 = tmp;
    }
    if (x1 < 0) {
       x1 = 0;
    }
    if (x1 > wgtPtr->width-1) {
       x1 = wgtPtr->width-1;
    }
    if (x2 < 0) {
       x2 = 0;
    }
    if (x2 > wgtPtr->width-1) {
       x2 = wgtPtr->width-1;
    }
    if (y1 < 0) {
       y1 = 0;
    }
    if (y1 > wgtPtr->height-1) {
       y1 = wgtPtr->height-1;
    }
    if (y2 < 0) {
       y2 = 0;
    }
    if (y2 > wgtPtr->height-1) {
       y2 = wgtPtr->height-1;
    }
fprintf(stderr, "WidgetLine!%d!%d!%d!%d!\n", x1, y1, x2, y2);
    bp = GET_PIXEL_PTR(wgtPtr, x1, y1);
    PUT_PIXEL(bp, rgba);
    bp = GET_PIXEL_PTR(wgtPtr, x2, y2);
    PUT_PIXEL(bp, rgba);
    dx = x2 - x1;
    dy = y2 - y1;
fprintf(stderr, "WidgetLine2!%d!%d!\n", dx, dy);
    if (dx >= 0) {
        xdir = 1;
    } else {
        xdir = -1;
        dx = -dx;
    }
    if (dx == 0) {
        WidgetVerticalLine(wgtPtr, x1, y1, dy, rgba);
        return TCL_OK;
    }
    if (dy == 0) {
        if (x1 > x2) {
            tmp = x1; x1 = x2; x2 = tmp;
        }
        WidgetHorizontalLine(wgtPtr, x1, y1, dx, rgba);
        return TCL_OK;
    }
    if (dx == dy) {
        WidgetDiagonalLine(wgtPtr, x1, y1, dy, xdir, rgba);
        return TCL_OK;
    }
    WidgetAdjustedLine(wgtPtr, x1, y1, x2, y2, dx, dy, xdir, rgba);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetFill()
 * ------------------------------------------------------------------------
 */

int
NtkWidgetFill(
    Tcl_Interp *interp,
    NtkWidget *wgtPtr,
    unsigned char *rgba)
{
    unsigned char *bp;
    int cnt;

    bp = GET_PIXEL_PTR(wgtPtr, 0, 0);
    cnt = wgtPtr->width * wgtPtr->height;
    while (cnt > 0) {
	PUT_PIXEL(bp,rgba);
        cnt--;
    }
    return TCL_OK;
}
