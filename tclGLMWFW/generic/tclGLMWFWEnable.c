/*
 * tclGLMWFWEnable.c --
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
 * RCS: @(#) $Id: tclGLMWFWEnable.c,v 1.1.2.2 2007/11/01 16:14:36 wiede Exp $
 */

#include "tclGLMWFWInt.h"
#include "tclGLMWFWPlatform.h"

/*
 ************************************************************************
 ****                  GLMWFW internal functions                       ****
 ************************************************************************
 */

/*
 *========================================================================
 * Enable (show) mouse cursor
 *========================================================================
 */

static int
_glmwfwEnableMouseCursor(
    GLMWFWWindow *winPtr)
{
    int CenterPosX;
    int CenterPosY;

    if (!winPtr->Opened || !winPtr->MouseLock ) {
        return TCL_OK;
    }

    /* Show mouse cursor */
    _glmwfwPlatformShowMouseCursor(winPtr);

    CenterPosX = winPtr->Width / 2;
    CenterPosY = winPtr->Height / 2;

    if (CenterPosX != winPtr->input.MousePosX ||
            CenterPosY != winPtr->input.MousePosY) {
	_glmwfwPlatformSetMouseCursorPos(winPtr, CenterPosX, CenterPosY);
	winPtr->input.MousePosX = CenterPosX;
	winPtr->input.MousePosY = CenterPosY;
	if (winPtr->mouseposfun) {
	    winPtr->mouseposfun(winPtr, winPtr->input.MousePosX, 
	            winPtr->input.MousePosY);
	}
    }
    /* From now on the mouse is unlocked */
    winPtr->MouseLock = GL_FALSE;
    return TCL_OK;
}

/*
 *========================================================================
 * Disable (hide) mouse cursor
 *========================================================================
 */

static int
_glmwfwDisableMouseCursor(
    GLMWFWWindow *winPtr)
{
    if (!winPtr->Opened || winPtr->MouseLock )
    {
        return TCL_OK;
    }

    /* Hide mouse cursor */
    _glmwfwPlatformHideMouseCursor(winPtr);

    /* Move cursor to the middle of the window */
    _glmwfwPlatformSetMouseCursorPos(winPtr, winPtr->Width>>1, winPtr->Height>>1);
    /* From now on the mouse is locked */
    winPtr->MouseLock = GL_TRUE;
    return TCL_OK;
}

/*
 *========================================================================
 * _glmwfwEnableStickyKeys() - Enable sticky keys
 * _glmwfwDisableStickyKeys() - Disable sticky keys
 *========================================================================
 */

static int
_glmwfwEnableStickyKeys(
    GLMWFWWindow *winPtr)
{
    winPtr->input.StickyKeys = 1;
    return TCL_OK;
}

static int
_glmwfwDisableStickyKeys(
    GLMWFWWindow *winPtr)
{
    int i;

    winPtr->input.StickyKeys = 0;

    /* Release all sticky keys */
    for (i = 0; i <= GLMWFW_KEY_LAST; i++) {
        if (winPtr->input.Key[i] == 2) {
            winPtr->input.Key[i] = 0;
        }
    }
    return TCL_OK;
}

/*
 *========================================================================
 * _glmwfwEnableStickyMouseButtons() - Enable sticky mouse buttons
 * _glmwfwDisableStickyMouseButtons() - Disable sticky mouse buttons
 *========================================================================
 */

static int
_glmwfwEnableStickyMouseButtons(
    GLMWFWWindow *winPtr)
{
    winPtr->input.StickyMouseButtons = 1;
    return TCL_OK;
}

static int
_glmwfwDisableStickyMouseButtons(
    GLMWFWWindow *winPtr)
{
    int i;

    winPtr->input.StickyMouseButtons = 0;

    // Release all sticky mouse buttons
    for (i = 0; i <= GLMWFW_MOUSE_BUTTON_LAST; i++) {
        if (winPtr->input.MouseButton[i] == 2) {
            winPtr->input.MouseButton[i] = 0;
        }
    }
    return TCL_OK;
}

/*
 *========================================================================
 * _glmwfwEnableSystemKeys() - Enable system keys
 * _glmwfwDisableSystemKeys() - Disable system keys
 *========================================================================
 */

static int
_glmwfwEnableSystemKeys(
    GLMWFWWindow *winPtr)
{
    if (!winPtr->SysKeysDisabled) {
        return TCL_OK;
    }
    _glmwfwPlatformEnableSystemKeys(winPtr);
    /* Indicate that system keys are no longer disabled */
    winPtr->SysKeysDisabled = GL_FALSE;
    return TCL_OK;
}

static int
_glmwfwDisableSystemKeys(
    GLMWFWWindow *winPtr)
{
    if (winPtr->SysKeysDisabled) {
        return TCL_OK;
    }
    _glmwfwPlatformDisableSystemKeys(winPtr);
    /* Indicate that system keys are now disabled */
    winPtr->SysKeysDisabled = GL_TRUE;
    return TCL_OK;
}

/*
 *========================================================================
 * _glmwfwEnableKeyRepeat() - Enable key repeat
 * _glmwfwDisableKeyRepeat() - Disable key repeat
 *========================================================================
 */

static int
_glmwfwEnableKeyRepeat(
    GLMWFWWindow *winPtr)
{
    winPtr->input.KeyRepeat = 1;
    return TCL_OK;
}

static int
_glmwfwDisableKeyRepeat(
    GLMWFWWindow *winPtr)
{
    winPtr->input.KeyRepeat = 0;
    return TCL_OK;
}

/*
 *========================================================================
 * _glmwfwEnableAutoPollEvents() - Enable automatic event polling
 * _glmwfwDisableAutoPollEvents() - Disable automatic event polling
 *========================================================================
 */

static int
_glmwfwEnableAutoPollEvents(
    GLMWFWWindow *winPtr)
{
    winPtr->AutoPollEvents = 1;
    return TCL_OK;
}

static int
_glmwfwDisableAutoPollEvents(
    GLMWFWWindow *winPtr)
{
    winPtr->AutoPollEvents = 0;
    return TCL_OK;
}

/*
 ************************************************************************
 ****                    GLMWFW user functions                       ****
 ************************************************************************
 */

/*
 *========================================================================
 * glmwfwEnable() - Enable certain GLMWFW/window/system functions.
 *========================================================================
 */

int
glmwfwEnable(
    GLMWFWWindow *winPtr,
    int token)
{
    switch (token) {
    case GLMWFW_MOUSE_CURSOR:
        _glmwfwEnableMouseCursor(winPtr);
        break;
    case GLMWFW_STICKY_KEYS:
        _glmwfwEnableStickyKeys(winPtr);
        break;
    case GLMWFW_STICKY_MOUSE_BUTTONS:
        _glmwfwEnableStickyMouseButtons(winPtr);
        break;
    case GLMWFW_SYSTEM_KEYS:
        _glmwfwEnableSystemKeys(winPtr);
        break;
    case GLMWFW_KEY_REPEAT:
        _glmwfwEnableKeyRepeat(winPtr);
        break;
    case GLMWFW_AUTO_POLL_EVENTS:
        _glmwfwEnableAutoPollEvents(winPtr);
        break;
    default:
        break;
    }
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwDisable() - Disable certain GLMWFW/window/system functions.
 *========================================================================
 */

int
glmwfwDisable(
    GLMWFWWindow *winPtr,
    int token)
{
    switch (token) {
    case GLMWFW_MOUSE_CURSOR:
        _glmwfwDisableMouseCursor(winPtr);
        break;
    case GLMWFW_STICKY_KEYS:
        _glmwfwDisableStickyKeys(winPtr);
        break;
    case GLMWFW_STICKY_MOUSE_BUTTONS:
        _glmwfwDisableStickyMouseButtons(winPtr);
        break;
    case GLMWFW_SYSTEM_KEYS:
        _glmwfwDisableSystemKeys(winPtr);
        break;
    case GLMWFW_KEY_REPEAT:
        _glmwfwDisableKeyRepeat(winPtr);
        break;
    case GLMWFW_AUTO_POLL_EVENTS:
        _glmwfwDisableAutoPollEvents(winPtr);
        break;
    default:
        break;
    }
    return TCL_OK;
}
