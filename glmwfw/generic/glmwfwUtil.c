/*
 * glmwfwUtil.c --
 *
 * This file contains the C-implemeted part of 
 * tcl GLFW interfaces
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: glmwfwUtil.c,v 1.1.2.1 2007/11/02 16:29:40 wiede Exp $
 */

#include "glmwfwInt.h"

#ifdef GLMWFW_DEBUG
int _tcl_glmwfw_debug_level = 0;

/*
 * ------------------------------------------------------------------------
 *  GlmwfwShowArgs()
 * ------------------------------------------------------------------------
 */

void
GlmwfwShowArgs(
    int level,
    const char *str,
    int objc,
    Tcl_Obj * const* objv)
{
    int i;

    if (level > _tcl_glmwfw_debug_level) {
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
