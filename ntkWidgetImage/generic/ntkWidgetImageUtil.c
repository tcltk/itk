/*
 * ntkWidgetImageUtil.c --
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
 * RCS: @(#) $Id: ntkWidgetImageUtil.c,v 1.1.2.1 2007/11/23 18:06:48 wiede Exp $
 */

#include <stdlib.h>
#include <math.h>
#include "ntkWidgetImageInt.h"
/* needed on SUSE Linux 10.0 */
double round(double);

/* to be tried !! ((srcColor*srcAlpha)>>8 ) + ((((dstAlpha*(256-srcAlpha))>>8 )*dstColor)>>8 ) */
#define BLEND(dst,src,alpha) (((dst * (256 - alpha))>>8) + (((src * alpha))>>8))
#define BLEND2(dstColor,srcColor,srcAlpha,dstAlpha) (((srcColor*srcAlpha)>>8) + ((((dstAlpha*(256-srcAlpha))>>8) * dstColor)>>8))

#define PUT_PIXEL(bp,rgba) *bp++ = rgba[0]; *bp++ = rgba[1]; *bp++ = rgba[2]; *bp++ = rgba[3];

#define GET_PIXEL_PTR(wgtPtr,x,y) (wgtPtr->data + (wgtPtr->width*(y)*wgtPtr->typeEntryBytes) + ((x)*wgtPtr->typeEntryBytes))

/* 2^30 */
#define ROTSCALE 1073741824

static int *cos_table;
static int *sin_table;
static int64_t *xsinetable = NULL;
static int64_t *xcosinetable = NULL;
static int xtablewidth = 0;

#ifdef NTK_WIDGET_IMAGE_DEBUG
int _ntk_widget_image_debug_level = 0;

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetImageShowArgs()
 * ------------------------------------------------------------------------
 */

void
NtkWidgetImageShowArgs(
    int level,
    const char *str,
    int objc,
    Tcl_Obj * const* objv)
{
    int i;

    if (level > _ntk_widget_image_debug_level) {
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
 *  InitRotationTable()
 *
 * ------------------------------------------------------------------------
 */
static int
InitRotationTable (
    Tcl_Interp *interp)
{
    int a;
    double coeff;
    double radians;
    int offset = 0;
 
    cos_table = (int *)ckalloc(sizeof(int)*46);
    sin_table = (int *)ckalloc(sizeof(int)*46);
 
    if ((cos_table == NULL) || (sin_table == NULL)) {
         Tcl_SetResult (interp, "unable to allocate sin/cos rotation table",
	         TCL_STATIC);
         return TCL_ERROR;
    }
    /* as trigonometry is 35 years ago for me here a reminder
     * acos(0): get the radians for angle x for which cos(x) is 0
     * as cos for angle 90 degrees is zero divide by 90 to get the radians
     * for 1 degree */
    coeff = acos(0) / 90;
    /* values for cos_table go from 0.0 to 0.707107
     * values for sin table go from 1.0 to 0.707107 */
    for (a = 0; a <= 45; ++a) {
        radians = coeff * a;
//fprintf(stderr, "SC!%d!%f!%f!%f!%f!\n", a, sin(radians), cos(radians), coeff, acos(0));
        cos_table[offset] = (int)((double)ROTSCALE * cos(radians));
        sin_table[offset] = (int)((double)ROTSCALE * sin(radians)); 
        ++offset;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  IntCosAndSin()
 *
 * ------------------------------------------------------------------------
 */
static void
IntCosAndSin (
    int a,
    int64_t *cosine,
    int64_t *sine)
{
    int ss = 1; /*sign of sin*/
    int sc = 1; /*sign of cos*/
    if (a > 0) {
        a %= 360;
    } else {
        a %= -360;
    }
    /*
     * make sure it's -180 < $a <=180 
     */
    if (a > 180) {
        a = a - 360;
    }
    if (a < -180) {
        a = a + 360;
    } 
    /*
     *  Consider negative angles; after this 0<=$a<=180
     */
    if (a < 0) {
        ss = -ss;
        a = -a;
    }
    /*
     * Convert the angle to the first quadrant.
     */ 
    if (a > 90) {
        sc = -sc;
        a = 180 - a;
    }
    if (a <= 45) {
        *cosine = sc * cos_table[a];
        *sine = ss * sin_table[a];
    } else {
        a = 90 - a;
        *cosine = sc * sin_table[a];
        *sine = ss * cos_table[a];
    }
}

/*
 * ------------------------------------------------------------------------
 *  WidgetVerticalLine()
 * ------------------------------------------------------------------------
 */

static void
WidgetVerticalLine(
    NtkWidgetImage *wgtPtr,
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
    NtkWidgetImage *wgtPtr,
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
    NtkWidgetImage *wgtPtr,
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
    NtkWidgetImage *wgtPtr,
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
fprintf(stderr, "dy > dx\n");
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
 *  NtkWidgetImageLine()
 * ------------------------------------------------------------------------
 */

int
NtkWidgetImageLine(
    Tcl_Interp *interp,
    NtkWidgetImage *wgtPtr,
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
//fprintf(stderr, "WidgetLine!%d!%d!%d!%d!\n", x1, y1, x2, y2);
    bp = GET_PIXEL_PTR(wgtPtr, x1, y1);
    PUT_PIXEL(bp, rgba);
    bp = GET_PIXEL_PTR(wgtPtr, x2, y2);
    PUT_PIXEL(bp, rgba);
    dx = x2 - x1;
    dy = y2 - y1;
//fprintf(stderr, "WidgetLine2!%d!%d!\n", dx, dy);
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
 *  NtkWidgetImageFill()
 * ------------------------------------------------------------------------
 */

int
NtkWidgetImageFill(
    Tcl_Interp *interp,
    NtkWidgetImage *wgtPtr,
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

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetImageBlend()
 * ------------------------------------------------------------------------
 */

void
NtkWidgetImageBlend(
    Tcl_Interp *interp,
    NtkWidgetImage *dstWgtPtr,
    NtkWidgetImage *srcWgtPtr,
    int dstx,
    int dsty,
    int x1,
    int y1,
    int x2,
    int y2)
{
    int y; /* relative to the base */
    int xiter;
    int yiter;
    int srcpyincr;
    int dstpyincr;
    unsigned char *srcp;
    unsigned char *dstp;
    int srcAlpha;
    int dstAlpha;
    int i;

    if (x2 > srcWgtPtr->width) {
        x2 = srcWgtPtr->width;
    }
    if (y2 > srcWgtPtr->height) {
        y2 = srcWgtPtr->height;
    }
    xiter = x2 - x1;
    yiter = y2 - y1;
    if (x1 < 0) {
        xiter = srcWgtPtr->width + x1;
	x1 = 0;
    }
    if (y1 < 0) {
        yiter = srcWgtPtr->height + y1;
	y1 = 0;
    }
    if (dstx >= dstWgtPtr->width) {
        return;
    }
    if (dsty >= dstWgtPtr->height) {
        return;
    }
    if (dstx < 0) {
        xiter += dstx;
	dstx = 0;
    }
    if (dsty < 0) {
        yiter += dsty;
	dsty = 0;
    }
    if ((dstx + xiter) >= dstWgtPtr->width) {
        xiter = dstWgtPtr->width - dstx;
    }
    if ((dsty + yiter) >= dstWgtPtr->height) {
        yiter = dstWgtPtr->height - dsty;
    }
    if (xiter <= 0 || yiter <= 0) {
        return;
    }

    /*
     * Calculate the number of remaining bytes in src
     * of the line after writing to dst.
     */
    srcpyincr = (srcWgtPtr->width - xiter) * 4;
    dstpyincr = (dstWgtPtr->width - xiter) * 4;
    srcp = GET_PIXEL_PTR(srcWgtPtr, x1, y1);
    dstp = GET_PIXEL_PTR(dstWgtPtr, dstx, dsty);

#ifdef DEBUG
fprintf (stderr, "dstx %d dsty %d xiter %d yiter %d x1 %d y1 %d srcpyincr %d dstcpyincr %d\n", dstx, dsty, xiter, yiter, x1, y1, srcpyincr, dstpyincr);
#endif

#define BLEND_PIXELS do { \
   srcAlpha = srcp[3]+1; \
   dstAlpha = dstp[3]+1; \
   dstp[0] = BLEND2(dstp[0], srcp[0], srcAlpha, dstAlpha); \
   dstp[1] = BLEND2(dstp[1], srcp[1], srcAlpha, dstAlpha); \
   dstp[2] = BLEND2(dstp[2], srcp[2], srcAlpha, dstAlpha); \
   dstp += 4; srcp += 4; \
 } while (0)

    for (y = 0; y < yiter; ++y, srcp += srcpyincr, dstp += dstpyincr) {
        i = xiter;
        switch (i % 3) {
        case 0:
	  do {
            BLEND_PIXELS;
	    --i;
        case 2:
	    BLEND_PIXELS;
	    --i;
        case 1:
	    BLEND_PIXELS;
	    --i;
          } while (i >= 3);
        }
    }
}

/*
 * ------------------------------------------------------------------------
 *  NtkWidgetImageRotate()
 * ------------------------------------------------------------------------
 */

int
NtkWidgetImageRotate(
    Tcl_Interp *interp,
    NtkWidgetImage *wgtPtr,
    int degrees)
{
    int x;
    int y;
    int srcx;
    int srcy;
    int srcxr; /*right pixels offset*/
    int srcyd; /*down y pixel offset*/
    int centerx;
    int centery;
    int newwidth;
    int newheight;
    int halfnewwidth;
    int halfnewheight;
    unsigned char *newbytes;
    unsigned char *src;
    unsigned char *dest;
    double db;
    size_t newsize;
    int r;
    int g;
    int b;
    int a;
    int srclinebytes;
    int64_t cosine;
    int64_t sine;
    int64_t xsine;
    int64_t xcosine;
    int64_t ysine;
    int64_t ycosine;
    int i;

    if (degrees == 0) {
        return TCL_OK;
    }
    if (cos_table == NULL) {
        InitRotationTable(interp);
    }
    centerx = wgtPtr->width / 2;
    centery = wgtPtr->height / 2;
    db = (3.14159265359 * degrees) / 180;
    newwidth = (abs(round(wgtPtr->width * cos(db))) +
            abs(round(wgtPtr->height * sin(db))) + 2.0);
    newheight = (abs(round(wgtPtr->height * cos(db))) +
            abs(round(wgtPtr->width * sin(db))) + 2.0);
//fprintf(stderr, "NW!%d!%d!%d!%d!%f!%f!%d!\n", wgtPtr->width, wgtPtr->height, newwidth, newheight, sin(db), cos(db), degrees);
    IntCosAndSin(degrees, &cosine, &sine);
    newsize = newwidth * newheight * wgtPtr->typeEntryBytes;
    newbytes = (unsigned char *)ckalloc(newsize);
    if (newbytes == NULL) {
        Tcl_SetResult (interp, "allocating memory for image rotation",
                TCL_STATIC);
                Tcl_AddErrorInfo (interp, (char *) Tcl_PosixError (interp));
        return TCL_ERROR;
    }
    halfnewwidth = newwidth / 2;
    halfnewheight = newheight / 2;
    /*
     * Initialize the values to 0 for completely transparent display.
     */
    memset (newbytes, 0, newsize);

#define SETRGBA do { \
 r = (r + src[0]) >> 1; \
 g = (g + src[1]) >> 1; \
 b = (b + src[2]) >> 1; \
 a = (a + src[3]) >> 1; \
} while (0)

    srclinebytes = wgtPtr->width * wgtPtr->typeEntryBytes;
    dest = newbytes;
    ysine = -halfnewheight * sine;
    ycosine = -halfnewheight * cosine;
    /*
     * We keep 2 tables around, and reallocate them as needed to fit
     * larger images.
     */
    if (xtablewidth < newwidth) {
        if (xsinetable) {
            ckfree ((char *)xsinetable);
            xsinetable = NULL;
        }
        if (xcosinetable) {
            ckfree((char *)xcosinetable);
            xcosinetable = NULL;
        }
        xtablewidth = newwidth;
        xsinetable = (int64_t *)ckalloc(sizeof (*xsinetable) * xtablewidth);
        xcosinetable = (int64_t *)ckalloc(sizeof (*xcosinetable) * xtablewidth);
        if ((xsinetable  == NULL) || (xcosinetable == NULL)) {
            Tcl_SetResult (interp, "unable to allocate x co(sine) tables",
                    TCL_STATIC);
            Tcl_AddErrorInfo (interp, (char *)Tcl_PosixError (interp));
            return TCL_ERROR;
        }
    }
    xsine = -halfnewwidth * sine;
    xcosine = -halfnewwidth * cosine;
    for (i = 0; i < newwidth; ++i) {
        xsinetable[i] = xsine;
        xcosinetable[i] = xcosine;
        xsine += sine;
        xcosine += cosine;
    }
    for (y = 0; y < newheight; ++y, ysine += sine, ycosine += cosine) {
        for (x = 0; x < newwidth; ++x
                /*, xsine += sine, xcosine += cosine*/) {
            srcx = centerx + ((xcosinetable[x] - ysine) / ROTSCALE);
            srcy = centery + ((xsinetable[x] + ycosine) / ROTSCALE);
            srcxr = srcx + 1;
            srcyd = srcy + 1;
            r = 0;
            g = 0;
            b = 0;
            a = 0;
            if ((srcx >= 0) && (srcy >= 0)) {
               if ((srcx < wgtPtr->width) && (srcy < wgtPtr->height)) {
                   src = wgtPtr->data + (srclinebytes * srcy) +
		           (srcx * wgtPtr->typeEntryBytes);
                   r = src[0];
                   g = src[1];
                   b = src[2];
                   a = src[3];
                   if (srcyd < wgtPtr->height) {
                       src += srclinebytes;
                       SETRGBA;
                   }
               }
               if ((srcxr < wgtPtr->width) && (srcy < wgtPtr->height)) {
                   src = wgtPtr->data + (srclinebytes * srcy) +
		           srcxr * wgtPtr->typeEntryBytes;
                   SETRGBA;
               }
           }
           dest[0] = r;
           dest[1] = g;
           dest[2] = b;
           dest[3] = a;
           dest += 4;
       }
   }
#undef SETRGBA
    ckfree ((char *)wgtPtr->data);
    wgtPtr->dataSize = newsize;
    wgtPtr->data = newbytes;
    wgtPtr->width = newwidth;
    wgtPtr->height = newheight;
    return TCL_OK;
}
