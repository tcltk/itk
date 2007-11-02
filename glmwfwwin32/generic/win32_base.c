/*
 * win32.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the GLMWFW OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: win32_base.c,v 1.1.2.1 2007/11/02 19:16:28 wiede Exp $
 */

#include <stdlib.h>
#include "glmwfwInt.h"

typedef struct GlmwfwStubAPI {
int i;
} GlmwfwStubAPI;
struct GlmwfwStubAPI glmwfwStubAPI;

/*
 * ------------------------------------------------------------------------
 *  Initialize()
 *
 *      that is the starting point when loading the library
 *      it initializes all internal stuff
 *
 * ------------------------------------------------------------------------
 */

static int
Initialize (
    Tcl_Interp *interp)
{
    if (Tcl_InitStubs(interp, TCL_VERSION, 0) == NULL) {
        return TCL_ERROR;
    }

    return Tcl_PkgProvideEx(interp, "GlmwfwWin32", GLMWFW_VERSION, &glmwfwStubAPI);
}

/*
 * ------------------------------------------------------------------------
 *  Glmwfwwin32()
 *
 *  Invoked whenever a new INTERPRETER is created to install the
 *  glmwfw package.  Usually invoked within Tcl_AppInit() at
 *  the start of execution.
 *
 *  Creates the "::ntk::glmwfw" namespace and installs commands
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */

int
Glmwfwin32_Init (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }

    return  TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Glmwfwwin32_SafeInit()
 *
 *  Invoked whenever a new SAFE INTERPRETER is created to install
 *  the tclGLMWFW package.
 *
 *  Creates the "::ntk::glmwfw" namespace and installs access commands
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */

int
Glmwfwwin32_SafeInit (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}
