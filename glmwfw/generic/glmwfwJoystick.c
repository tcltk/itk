/*
 * glmwfwJoystick.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the GLFW OpenGL multi window frame work
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
 * RCS: @(#) $Id: glmwfwJoystick.c,v 1.1.2.1 2007/11/02 16:29:39 wiede Exp $
 */

#include "glmwfwInt.h"
#include "glmwfwPlatform.h"

/*
 ************************************************************************
 ****                    Glmwfw user functions                       ****
 ************************************************************************
 */

/*
 *========================================================================
 * glmwfwGetJoystickParam() - Determine joystick capabilities
 *========================================================================
 */

int
glmwfwGetJoystickParam(
    GlmwfwWindow *winPtr,
    int joy,
    int param)
{
    /* Is Glmwfw initialized? */
    if (!winPtr->Opened) {
        return 0;
    }
    return _glmwfwPlatformGetJoystickParam(winPtr,joy, param);
}

/*
 *========================================================================
 * glmwfwGetJoystickPos() - Get joystick axis positions
 *========================================================================
 */

int
glmwfwGetJoystickPos(
    GlmwfwWindow *winPtr,
    int joy,
    float *pos,
    int numaxes)
{
    int       i;

    /* Is Glmwfw initialized? */
    if (!winPtr->Opened) {
        return 0;
    }
    // Clear positions
    for(i = 0; i < numaxes; i++) {
        pos[i] = 0.0f;
    }
    return _glmwfwPlatformGetJoystickPos(winPtr, joy, pos, numaxes);
}

/*
 *========================================================================
 * glmwfwGetJoystickButtons() - Get joystick button states
 *========================================================================
 */

int
glmwfwGetJoystickButtons(
    GlmwfwWindow *winPtr,
    int joy,
    unsigned char *buttons,
    int numbuttons)
{
    int i;

    /* Is Glmwfw initialized? */
    if(!winPtr->Opened) {
        return 0;
    }
    /* Clear button states */
    for(i = 0; i < numbuttons; i++) {
        buttons[i] = GLMWFW_RELEASE;
    }
    return _glmwfwPlatformGetJoystickButtons(winPtr, joy, buttons, numbuttons);
}
