/*
 * ntkGLWidgetUtil.c --
 *
 * This file contains the C-implemeted part of 
 * tcl OpenGL interfaces
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: ntkGLWidgetUtil.c,v 1.1.2.1 2007/11/11 10:08:16 wiede Exp $
 */

#include "ntkGLWidgetInt.h"

#ifdef NTK_GL_WIDGET_DEBUG
int _ntk_gl_widget_debug_level = 0;

/*
 * ------------------------------------------------------------------------
 *  NtkGLWidgetShowArgs()
 * ------------------------------------------------------------------------
 */

void
NtkGLWidgetShowArgs(
    int level,
    const char *str,
    int objc,
    Tcl_Obj * const* objv)
{
    int i;

    if (level > _ntk_gl_widget_debug_level) {
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
