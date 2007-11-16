/*
 * ntkWidgetFreetype.c --
 *
 * This file contains the C-implemeted part of a
 * Tcl interface for rendering widgets as bitmaps
 *
 * this is based on the freetypeext package written by George Peter Staplin
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann and George Peter Staplin
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: ntkWidgetFreeType.c,v 1.1.2.1 2007/11/16 20:27:16 wiede Exp $
 */

#include <math.h>
#include "ntkWidgetInt.h"

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include FT_BITMAP_H

#define SCALE_FACTOR 64

static FT_Library library;

static struct CachedFont{
    FT_Face face;
    Tcl_Obj *fontNamePtr;
    int fontSize;
} CachedFont;

typedef struct NtkFreeTypeString {
    FT_Bitmap bitmap;
    size_t bitmapLength;
    int width;
    int height;
    int x;
    int y;
    int top;
    int bottom;
    int vertAdvance;
    int horiAdvance;
    int xOffset;
    int yOffset;
} NtkFreeTypeString;


/*
 * ------------------------------------------------------------------------
 *  NtkWidget_InitFreeType()
 * ------------------------------------------------------------------------
 */

int
NtkWidget_InitFreeType(
    Tcl_Interp *interp,
    NtkWidgetInfo *infoPtr)
{
    int result;

    result = FT_Init_FreeType(&library);
    if (result) {
        Tcl_AppendResult(interp, "ERROR during initialisation of FreeType",
	        NULL);
	return TCL_ERROR;
    }
    CachedFont.fontNamePtr = NULL;
    CachedFont.fontSize = 0;
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  LoadString()
 * ------------------------------------------------------------------------
 */

static int
LoadString (
    Tcl_Interp *interp,
    NtkWidget *wgtPtr,
    FT_Face face,
    Tcl_UniChar *unitext,
    int unitextlen,
    int justmeasure)
{
    NtkFreeTypeString *ftInfoPtr;
    int i;
    int result;
    int left;
    int right;
    int top;
    int bottom;
    int peakheight;

#define ROUND(val) (((val) + 32) & -64)
#define FLOOR(val) ((val) & -64)
#define CEIL(val) (((val) + 63) & -64)
#define TRUNCATE(val) ((val) >> 6)
 
    peakheight = 1;
    for (i=0;i<unitextlen;++i) {
        FT_ULong c = (FT_ULong)unitext[i];
        int totaly = 0;
        result = FT_Load_Char(face, c, FT_LOAD_RENDER);
        if (result != 0) {
            Tcl_SetResult (interp, "error loading character", TCL_STATIC);
            return TCL_ERROR;
        }
        left  = FLOOR(face->glyph->metrics.horiBearingX);
        right = CEIL(face->glyph->metrics.horiBearingX +
	        face->glyph->metrics.width);
        top = CEIL(face->glyph->metrics.horiBearingY);
        bottom = FLOOR(face->glyph->metrics.horiBearingY -
	        face->glyph->metrics.height);
	ftInfoPtr = &wgtPtr->fontInfo[i];
        if (justmeasure != 0) {
            ftInfoPtr->bitmap = face->glyph->bitmap;
            ftInfoPtr->bitmapLength = face->glyph->bitmap.rows *
	            abs(face->glyph->bitmap.pitch);
            ftInfoPtr->bitmap.buffer = 
	            (void *)ckalloc (ftInfoPtr->bitmapLength);
            if (ftInfoPtr->bitmap.buffer == NULL) {
                Tcl_AppendResult (interp, "malloc failure: ",
	                (char *)Tcl_PosixError (interp), NULL);
                return TCL_ERROR;   
            }
            memcpy (ftInfoPtr->bitmap.buffer, face->glyph->bitmap.buffer,
	            ftInfoPtr->bitmapLength);
        }  
        ftInfoPtr->width = TRUNCATE(face->glyph->metrics.width);
        ftInfoPtr->height = TRUNCATE (face->glyph->metrics.height);
        ftInfoPtr->x = TRUNCATE (face->glyph->metrics.horiBearingX);
        ftInfoPtr->y = TRUNCATE (top);
        ftInfoPtr->top = TRUNCATE (top);
        ftInfoPtr->bottom = TRUNCATE (bottom);
        ftInfoPtr->vertAdvance = TRUNCATE (face->glyph->metrics.vertAdvance);
        ftInfoPtr->horiAdvance = TRUNCATE (face->glyph->metrics.horiAdvance);
        ftInfoPtr->xOffset = TRUNCATE (ROUND (face->glyph->advance.x));
        ftInfoPtr->yOffset = -TRUNCATE (ROUND (face->glyph->advance.y));

        /*
          printf ("vertadvance %d\n", f->rendered[i].vertadvance);
         */
        if (Tcl_UniCharIsSpace (unitext[i])) {
            ftInfoPtr->width = ftInfoPtr->horiAdvance;
        }
        wgtPtr->width += ftInfoPtr->width + abs(ftInfoPtr->x);
        totaly = ftInfoPtr->vertAdvance;
        if (totaly > peakheight) {
            peakheight = totaly;
        }
    }
    wgtPtr->width += wgtPtr->fontInfo[0].x;
    wgtPtr->height = peakheight;
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  GetFreeTypeInfo()
 * ------------------------------------------------------------------------
 */

int
NtkWidget_GetFreeTypeInfo(
    Tcl_Interp *interp,
    NtkWidgetInfo *infoPtr,
    const char *fontName,
    int fontSize,
    unsigned char *rgbaPtr,
    Tcl_Obj *textPtr,
    NtkWidget *wgtPtr)
{
    Tcl_UniChar *unitext;
    NtkFreeTypeString *ftInfoPtr;
    unsigned char *bitmap;
    int numRgbaBytes;
    int result;
    int unitextlen;
    int bottom;
    int i;

    unitext = Tcl_GetUnicodeFromObj(textPtr, &unitextlen);
    if (unitextlen <= 0) {
        Tcl_SetResult (interp, "string must not be empty", TCL_STATIC);
        return TCL_ERROR;
    }
    if (wgtPtr->fontInfo == NULL) {
        wgtPtr->fontInfo = (NtkFreeTypeString *)
	        ckalloc(sizeof(NtkFreeTypeString));
	if (wgtPtr->fontInfo == NULL) {
	    Tcl_AppendResult(interp, "cannot get memory for FreeType info",
	            NULL);
	    return TCL_ERROR;
	}
    }
    if ((CachedFont.fontNamePtr == NULL) ||
            (strcmp(Tcl_GetString(CachedFont.fontNamePtr), fontName) != 0) ||
	    (CachedFont.fontSize != fontSize)) {
        if (CachedFont.fontNamePtr != NULL) {
	    FT_Done_Face(CachedFont.face);
        } else {
	    CachedFont.fontNamePtr = Tcl_NewStringObj("", 0);
	}
        Tcl_SetStringObj(CachedFont.fontNamePtr, fontName, -1);
	CachedFont.fontSize = fontSize;
	result = FT_New_Face(library, fontName, 0, &CachedFont.face);
	if (result == FT_Err_Unknown_File_Format) {
	    Tcl_SetResult(interp, "invalid font file format", TCL_STATIC);
	    return TCL_ERROR;
	}
	if (result != 0) {
	    Tcl_SetResult(interp, "unable to open or read font file",
	           TCL_STATIC);
	    return TCL_ERROR;
	}
        result = FT_Set_Char_Size(CachedFont.face, 0,
	        fontSize + SCALE_FACTOR, 81, 81);
	if (result != 0) {
	    Tcl_SetResult(interp, "ERROR in setting FreeType char size",
	           TCL_STATIC);
	    return TCL_ERROR;
	}
    }
    if (wgtPtr->fontInfoSize != unitextlen) {
        if (wgtPtr->fontInfoSize > 0) {
	    ckfree((char *)wgtPtr->fontInfo);
	}
	wgtPtr->fontInfoSize = unitextlen;
	wgtPtr->fontInfo = (NtkFreeTypeString *)
	        ckalloc(sizeof(NtkFreeTypeString)*unitextlen);
    }
    if (LoadString(interp, wgtPtr, CachedFont.face, unitext, unitextlen,
            /*justmeasure*/0) != TCL_OK) {
        return TCL_ERROR;
    }
    bottom = 0;
    for (i=0;i<unitextlen;++i) {
        if (wgtPtr->fontInfo[i].bottom < bottom) {
            bottom = wgtPtr->fontInfo[i].bottom;
        }
    }
    wgtPtr->dataSize = wgtPtr->width * wgtPtr->height *
            /*RGBA*/wgtPtr->typeEntryBytes;
    bitmap = (unsigned char *)ckalloc (wgtPtr->dataSize);
    memset (bitmap, 0, wgtPtr->dataSize);
    numRgbaBytes = wgtPtr->typeEntryBytes;
    for (i= 0;i<unitextlen;++i) {
	unsigned char *dp;
	unsigned char ch;
	int desty;
	int destx;
	int ty;
	int tx;
	int x;
	int y;

	destx = 0;
        ftInfoPtr = &wgtPtr->fontInfo[i];
        desty = ftInfoPtr->vertAdvance;
        desty -= ftInfoPtr->top;
        desty += bottom;
        if (desty < 0) {
            desty = 0;
	}
        destx += (ftInfoPtr->x < 0) ? 0 : ftInfoPtr->x;

	unsigned char fpdelta;
	unsigned char finalalpha;
        for (ty = 0, y = desty; ty < ftInfoPtr->bitmap.rows &&
	        y >= 0 && y < wgtPtr->height; ++ty, ++y) {
            for (tx = 0, x = destx; tx < ftInfoPtr->bitmap.width && x >= 0 &&
	            x < wgtPtr->width; ++tx, ++x) {
                dp = bitmap + (y*wgtPtr->width*numRgbaBytes) + (x*numRgbaBytes);
                ch = ftInfoPtr->bitmap.buffer[ty*ftInfoPtr->bitmap.pitch+tx];
                if (ch == 0) {
	            continue;
	        }
                fpdelta = /*peak value*/ 255 - ch;
                finalalpha = rgbaPtr[3];
                if (fpdelta > finalalpha) {
                    finalalpha = 0;
                } else {
                    finalalpha -= fpdelta;
                }
                dp[0] = rgbaPtr[0];
                dp[1] = rgbaPtr[1];
                dp[2] = rgbaPtr[2];
                dp[3] = finalalpha;
            }
        }
        x += ftInfoPtr->width;
        ckfree((char *)ftInfoPtr->bitmap.buffer);
    }
}
