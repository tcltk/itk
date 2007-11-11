/*
 * ntkGLWidgetInt.h --
 *
 * This file contains internal definitions for the C-implemented part of a
 * a Tcl interface to the OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: ntkGLWidgetInt.h,v 1.1.2.1 2007/11/11 10:08:16 wiede Exp $
 */

#include <string.h>
#include <ctype.h>
#include <tcl.h>
#include <GL/gl.h>
#include "ntkGLWidget.h"

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

#define NTK_GL_WIDGET_INTERP_DATA "ntkGLWidget_data"
#define NTK_GL_WIDGET_INFO_VERSION 1

typedef struct NtkGLWIdgetInfo {
    int version;
    int noGLGetError;
} NtkGLWidgetInfo;

#ifdef NTK_GL_WIDGET_DEBUG
MODULE_SCOPE int _ntk_gl_widget_debug_level;
MODULE_SCOPE void NtkGLWidgetShowArgs(int level, const char *str, int objc,
        Tcl_Obj * const* objv);
#else
#define NtkGLWidgetShowArgs(a,b,c,d)
#endif

MODULE_SCOPE int NtkGLWidget_InitCommands(Tcl_Interp *interp,
        NtkGLWidgetInfo *infoPtr);

