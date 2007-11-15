/*
 * ntkWidgetInt.h --
 *
 * This file contains internal definitions for the C-implemented part of a
 * a Tcl interface to the OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: ntkWidgetInt.h,v 1.1.2.2 2007/11/15 21:18:32 wiede Exp $
 */

#include <string.h>
#include <ctype.h>
#include <tcl.h>
#include <GL/gl.h>
#include "ntkWidget.h"

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

#define NTK_WIDGET_INTERP_DATA "ntkWidget_data"
#define NTK_WIDGET_INFO_VERSION 1

typedef struct NtkWidget {
    int width;
    int height;
    int numTypeItems;
    int numTypeEntryBits;
    int typeEntryBytes;
    int dataSize;
    void *data;
} NtkWidget;

typedef struct NtkWidgetInfo {
    int version;
    int noGLGetError;
    Tcl_HashTable widgets;
    int numWidgets;
} NtkWidgetInfo;

#ifdef NTK_WIDGET_DEBUG
MODULE_SCOPE int _ntk_widget_debug_level;
MODULE_SCOPE void NtkWidgetShowArgs(int level, const char *str, int objc,
        Tcl_Obj * const* objv);
#else
#define NtkWidgetShowArgs(a,b,c,d)
#endif

MODULE_SCOPE int NtkWidget_InitCommands(Tcl_Interp *interp,
        NtkWidgetInfo *infoPtr);
MODULE_SCOPE int ExtractRGBAValues(Tcl_Interp *interp, Tcl_Obj *objPtr,
	unsigned char *r, unsigned char *g, unsigned char *b,
	unsigned char *a);
MODULE_SCOPE int NtkWidgetLine(Tcl_Interp *interp, NtkWidget *wgtPtr,
	int x1, int y1, int x2, int y2, unsigned char *rgba);
MODULE_SCOPE int NtkWidgetFill(Tcl_Interp *interp, NtkWidget *wgtPtr,
	 unsigned char *rgba);
MODULE_SCOPE void NtkWidgetBlend(Tcl_Interp *interp, NtkWidget *destWgtPtr,
        NtkWidget *srcWgtPtr, int destx, int desty, int x1, int y1,
        int x2, int y2);
MODULE_SCOPE int NtkWidgetRotate(Tcl_Interp *interp, NtkWidget *wgtPtr,
	int degrees);
