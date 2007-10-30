/*
 * tclGLInt.h --
 *
 * This file contains internal definitions for the C-implemented part of a
 * a Tcl interface to the OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLInt.h,v 1.1.2.3 2007/10/30 21:59:32 wiede Exp $
 */

#include <string.h>
#include <ctype.h>
#include <tcl.h>
#include <GL/gl.h>
#include "tclGL.h"

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

#define TCL_GL_INTERP_DATA "tclGL_data"
#define TCL_GL_INFO_VERSION 1

typedef struct TclGLInfo {
    int version;
    int noGLGetError;
#include "tclGLHashTables.h"
} TclGLInfo;

#ifdef TCL_GL_DEBUG
MODULE_SCOPE int _tcl_gl_debug_level;
MODULE_SCOPE void TclGLShowArgs(int level, const char *str, int objc,
        Tcl_Obj * const* objv);
#else
#define TclGLShowArgs(a,b,c,d)
#endif

MODULE_SCOPE int TclGL_InitCommands(Tcl_Interp *interp, TclGLInfo *infoPtr);

