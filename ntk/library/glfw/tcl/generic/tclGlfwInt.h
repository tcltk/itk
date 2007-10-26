/*
 * tclGlfwInt.h --
 *
 * This file contains internal definitions for the C-implemented part of a
 * a Tcl interface to the GLFW OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGlfwInt.h,v 1.1.2.2 2007/10/26 22:52:46 wiede Exp $
 */

#include <string.h>
#include <ctype.h>
#include <tcl.h>
#include "tclGlfw.h"
#include "../include/GL/glfw.h"

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

#define TCL_GLFW_INTERP_DATA "tclGlfw_data"
#define TCL_GLFW_INFO_VERSION 1
#define WINDOW_ALLOC 20

typedef struct TclGlfwWindow {
    Tcl_Obj *handlePtr;
    Tcl_Obj *windowSizeCallback;
    GLFWwindowsizefun *windowsizefun;
    Tcl_Obj *windowCloseCallback;
    GLFWwindowclosefun *windowclosefun;
    Tcl_Obj *windowRefreshCallback;
    GLFWwindowrefreshfun *windowrefreshfun;
    Tcl_Obj *mouseButtonCallback;
    GLFWmousebuttonfun *mousebuttonfun;
    Tcl_Obj *mousePosCallback;
    GLFWmouseposfun *mouseposfun;
    Tcl_Obj *mouseWheelCallback;
    GLFWmousewheelfun *mousewheelfun;
    Tcl_Obj *keyCallback;
    GLFWkeyfun *keyfun;
} TclGlfwWindow;

typedef struct TclGlfwInfo {
    int version;
    int numWindows;
    TclGlfwWindow *currWindow;
    Tcl_HashTable windowHandles;
} TclGlfwInfo;

#ifdef TCL_GLFW_DEBUG
MODULE_SCOPE int _tcl_glfw_debug_level;
MODULE_SCOPE void TclGlfwShowArgs(int level, const char *str, int objc,
        Tcl_Obj * const* objv);
#else
#define TclGlfwShowArgs(a,b,c,d)
#endif

MODULE_SCOPE int TclGlfw_InitCommands(Tcl_Interp *interp, TclGlfwInfo *infoPtr);
MODULE_SCOPE void TclShowArgs();
MODULE_SCOPE int TclGlfwKey2Define(const char *key);
MODULE_SCOPE int TclGlfwWindowParam2Define(const char *key);
MODULE_SCOPE int TclGlfwWindowHint2Define(const char *key);
MODULE_SCOPE int TclGlfwEnableParam2Define(const char *key);
MODULE_SCOPE Tcl_Obj * TclGlfwDefine2Key(int value);

