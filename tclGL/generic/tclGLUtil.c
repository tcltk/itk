/*
 * tclGLUtil.c --
 *
 * This file contains the C-implemeted part of 
 * tcl OpenGL interfaces
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLUtil.c,v 1.1.2.1 2007/10/31 09:32:54 wiede Exp $
 */

#include "tclGLInt.h"

#ifdef TCL_GL_DEBUG
int _tcl_gl_debug_level = 0;

/*
 * ------------------------------------------------------------------------
 *  TclGLShowArgs()
 * ------------------------------------------------------------------------
 */

void
TclGLShowArgs(
    int level,
    const char *str,
    int objc,
    Tcl_Obj * const* objv)
{
    int i;

    if (level > _tcl_gl_debug_level) {
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
