/*
 * tclGlfwUtil.c --
 *
 * This file contains the C-implemeted part of 
 * tcl GLFW interfaces
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGlfwUtil.c,v 1.1.2.1 2007/10/25 19:02:44 wiede Exp $
 */

#include "tclGlfwInt.h"

#ifdef TCL_GLFW_DEBUG
int _tcl_glfw_debug_level = 0;

/*
 * ------------------------------------------------------------------------
 *  TclGlfwShowArgs()
 * ------------------------------------------------------------------------
 */

void
TclGlfwShowArgs(
    int level,
    const char *str,
    int objc,
    Tcl_Obj * const* objv)
{
    int i;

    if (level > _tcl_glfw_debug_level) {
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
