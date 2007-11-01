/*
 * tclGLMWFWFullscreen.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the GLMWFW OpenGL multi window frame work
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * This work is derived from/based on GLFW - An OpenGL framework version 2.6
 * by Camilla Berglund http://glmwfw.sourceforge.net
 *
 * It is adapted for use in Tcl environment. Instead of one window
 * this version supports multiple windows and has a stubs interface for the
 * different platforms. The platform dependent code parts are loadable packages
 * and package require command has to look for the right one dependent on the
 * platform
 *
 * RCS: @(#) $Id: tclGLMWFWFullscreen.c,v 1.1.2.1 2007/11/01 15:38:06 wiede Exp $
 */

#include "tclGLMWFWInt.h"
#include "tclGLMWFWPlatform.h"

/*
 ************************************************************************
 ****                    GLMWFW user functions                       ****
 ************************************************************************
 */

/*
 *========================================================================
 * glmwfwGetVideoModes() - Get a list of available video modes
 *========================================================================
 */

int
glmwfwGetVideoModes(
    TclGLMWFWInfo *infoPtr,
    GLMWFWvidmode *list,
    int maxcount)
{
    int count;
    int i;
    int swap;
    int res1;
    int res2;
    int depth1;
    int depth2;
    GLMWFWvidmode vm;

    if (maxcount <= 0 || list == (GLMWFWvidmode*)0) {
        return 0;
    }
    /* Get list of video modes */
    count = _glmwfwPlatformGetVideoModes(list, maxcount);
    /* Sort list (bubble sort) */
    do {
        swap = 0;
        for (i = 0; i < count-1; ++i) {
            res1   = list[i].Width*list[i].Height;
            depth1 = list[i].RedBits+list[i].GreenBits+list[i].BlueBits;
            res2   = list[i+1].Width*list[i+1].Height;
            depth2 = list[i+1].RedBits+list[i+1].GreenBits+
                     list[i+1].BlueBits;
            if ((depth2<depth1) || ((depth2==depth1) && (res2<res1))) {
                vm = list[i];
                list[i] = list[i+1];
                list[i+1] = vm;
                swap = 1;
            }
        }
    } while(swap);
    return count;
}

/*
 *========================================================================
 * glmwfwGetDesktopMode() - Get the desktop video mode
 *========================================================================
 */

int
glmwfwGetDesktopMode(
    TclGLMWFWInfo *infoPtr,
    GLMWFWvidmode *mode)
{
    if (mode == (GLMWFWvidmode*)0) {
        return TCL_OK;
    }
    _glmwfwPlatformGetDesktopMode(mode);
    return TCL_OK;
}
