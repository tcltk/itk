/*
 * ntkWidgetImageInt.h --
 *
 * This file contains internal definitions for the C-implemented part of a
 * a Tcl interface to the OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: ntkWidgetImageInt.h,v 1.1.2.2 2007/11/25 19:57:47 wiede Exp $
 */

#include <string.h>
#include <ctype.h>
#include <tcl.h>
#include <GL/gl.h>
#include "ntkWidgetImage.h"

/*
 * Used to tag functions that are only to be visible within the module being
 * built and not outside it (where this is supported by the linker).
 */

#ifndef MODULE_SCOPE
#   ifdef __cplusplus
#       define MODULE_SCOPE extern "C"
#   else
#       define MODULE_SCOPE extern
#   endif
#endif

/*
 * Convenience macros for iterating through hash tables. FOREACH_HASH_DECLS
 * sets up the declarations needed for the main macro, FOREACH_HASH, which
 * does the actual iteration. FOREACH_HASH_VALUE is a restricted version that
 * only iterates over values.
 */

#define FOREACH_HASH_DECLS \
    Tcl_HashEntry *hPtr;Tcl_HashSearch search
#define FOREACH_HASH(key,val,tablePtr) \
    for(hPtr=Tcl_FirstHashEntry((tablePtr),&search); hPtr!=NULL ? \
            ((key)=(void *)Tcl_GetHashKey((tablePtr),hPtr),\
            (val)=Tcl_GetHashValue(hPtr),1):0; hPtr=Tcl_NextHashEntry(&search))
#define FOREACH_HASH_VALUE(val,tablePtr) \
    for(hPtr=Tcl_FirstHashEntry((tablePtr),&search); hPtr!=NULL ? \
            ((val)=Tcl_GetHashValue(hPtr),1):0;hPtr=Tcl_NextHashEntry(&search))

#define NTK_WIDGET_IMAGE_INTERP_DATA "ntkWidgetImage_data"
#define NTK_WIDGET_IMAGE_INFO_VERSION 1

struct NtkFreeTypeString;

typedef struct NtkWidgetImage {
    int width;
    int height;
    int numTypeItems;
    int numTypeEntryBits;
    int typeEntryBytes;
    int dataSize;
    Tcl_UniChar *unitext;
    int unitextlen;
    int fontInfoSize;
    struct NtkFreeTypeString *fontInfo;
    void *data;
} NtkWidgetImage;

typedef struct NtkWidgetImageInfo {
    int version;
    int noGLGetError;
    Tcl_HashTable widgets;
    int numWidgets;
} NtkWidgetImageInfo;

#ifdef NTK_WIDGET_IMAGE_DEBUG
MODULE_SCOPE int _ntk_widget_image_debug_level;
MODULE_SCOPE void NtkWidgetImageShowArgs(int level, const char *str, int objc,
        Tcl_Obj * const* objv);
#else
#define NtkWidgetImageShowArgs(a,b,c,d)
#endif

MODULE_SCOPE int NtkWidgetImage_InitCommands(Tcl_Interp *interp,
        NtkWidgetImageInfo *infoPtr);
MODULE_SCOPE int ExtractRGBAValues(Tcl_Interp *interp, Tcl_Obj *objPtr,
	unsigned char *r, unsigned char *g, unsigned char *b,
	unsigned char *a);
MODULE_SCOPE int NtkWidgetImageLine(Tcl_Interp *interp, NtkWidgetImage *wgtPtr,
	int x1, int y1, int x2, int y2, unsigned char *rgba);
MODULE_SCOPE int NtkWidgetImageFill(Tcl_Interp *interp, NtkWidgetImage *wgtPtr,
	 unsigned char *rgba);
MODULE_SCOPE void NtkWidgetImageBlend(Tcl_Interp *interp,
        NtkWidgetImage *destWgtPtr, NtkWidgetImage *srcWgtPtr, int destx,
	int desty, int x1, int y1, int x2, int y2);
MODULE_SCOPE int NtkWidgetImageRotate(Tcl_Interp *interp,
        NtkWidgetImage *wgtPtr, int degrees);
MODULE_SCOPE int NtkWidgetImage_InitFreeType(Tcl_Interp *interp,
        NtkWidgetImageInfo *infoPtr);
MODULE_SCOPE int NtkWidgetImage_GetFreeTypeInfo(Tcl_Interp *interp,
        NtkWidgetImageInfo *infoPtr, const char *fontName, int fontSize,
        unsigned char *rgbaPtr, Tcl_Obj *textPtr, NtkWidgetImage *wgtPtr,
	int measureOnly);
MODULE_SCOPE int NtkWidgetImage_GetFreeTypeOffsetMap(Tcl_Interp *interp,
        NtkWidgetImage *wgtPtr, Tcl_Obj *listPtr);

