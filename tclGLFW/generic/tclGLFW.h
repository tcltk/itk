/*
 * tclGLFW.h --
 *
 * This file contains definitions for the C-implemeted part of a Tcl
 * interface to the GLFW OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLFW.h,v 1.1.2.1 2007/10/31 09:26:14 wiede Exp $
 */

/*
 * ------------------------------------------------------------------------
 *      PACKAGE:  tclGLFW
 *  DESCRIPTION:  Tcl interface to the GLFW OpenGL library
 * ------------------------------------------------------------------------
 */

#ifndef TCL_GLFW_H_INCLUDED
#define TCL_GLFW_H_INCLUDED

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

#define TCL_GLFW_MAJOR_VERSION      0
#define TCL_GLFW_MINOR_VERSION      1
#define TCL_GLFW_RELEASE_LEVEL      TCL_ALPHA_RELEASE
#define TCL_GLFW_RELEASE_SERIAL     0

#define TCL_GLFW_VERSION            "0.1"
#define TCL_GLFW_PATCH_LEVEL        "0.1.0.0"
#define TCL_GLFW_NAMESPACE          "::ntk::glfw"


#endif /* TCL_GLFW_H_INCLUDED */

