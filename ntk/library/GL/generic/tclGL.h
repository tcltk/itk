/*
 * tclGL.h --
 *
 * This file contains definitions for the C-implemeted part of a Tcl
 * interface to the OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGL.h,v 1.1.2.1 2007/10/28 15:31:44 wiede Exp $
 */

/*
 * ------------------------------------------------------------------------
 *      PACKAGE:  tclGL
 *  DESCRIPTION:  Tcl interface to the OpenGL library
 * ------------------------------------------------------------------------
 */

#ifndef TCL_GL_H_INCLUDED
#define TCL_GL_H_INCLUDED

#include <string.h>
#include <ctype.h>
#include "tcl.h"

#ifndef TCL_ALPHA_RELEASE
#   define TCL_ALPHA_RELEASE    0
#endif
#ifndef TCL_BETA_RELEASE
#   define TCL_BETA_RELEASE     1
#endif
#ifndef TCL_FINAL_RELEASE
#   define TCL_FINAL_RELEASE    2
#endif

#define TCL_GL_MAJOR_VERSION      0
#define TCL_GL_MINOR_VERSION      1
#define TCL_GL_RELEASE_LEVEL      TCL_ALPHA_RELEASE
#define TCL_GL_RELEASE_SERIAL     0

#define TCL_GL_VERSION            "0.1"
#define TCL_GL_PATCH_LEVEL        "0.1.0.0"
#define TCL_GL_NAMESPACE          "::ntk::gl"


#endif /* TCL_GL_H_INCLUDED */

