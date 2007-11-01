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
 * RCS: @(#) $Id: tclGLMWFWEnable.c,v 1.1.2.1 2007/11/01 14:33:29 wiede Exp $
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
_glfwEnableMouseCursor(
    GLMWFWWindow *winPtr)
{
    int CenterPosX;
    int CenterPosY;

    if (!winPtr->Opened || !winPtr->MouseLock ) {
        return TCL_OK;
    }

    /* Show mouse cursor */
    _glfwPlatformShowMouseCursor(winPtr);

    CenterPosX = winPtr->Width / 2;
    CenterPosY = winPtr->Height / 2;

    if (CenterPosX != winPtr->input.MousePosX ||
            CenterPosY != winPtr->input.MousePosY) {
	_glfwPlatformSetMouseCursorPos(winPtr, CenterPosX, CenterPosY);
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
_glfwDisableMouseCursor(
    GLMWFWWindow *winPtr)
{
    if (!winPtr->Opened || winPtr->MouseLock )
    {
        return TCL_OK;
    }

    /* Hide mouse cursor */
    _glfwPlatformHideMouseCursor(winPtr);

    /* Move cursor to the middle of the window */
    _glfwPlatformSetMouseCursorPos(winPtr, winPtr->Width>>1, winPtr->Height>>1);
    /* From now on the mouse is locked */
    winPtr->MouseLock = GL_TRUE;
    return TCL_OK;
}

/*
 *========================================================================
 * _glfwEnableStickyKeys() - Enable sticky keys
 * _glfwDisableStickyKeys() - Disable sticky keys
 *========================================================================
 */

static int
_glfwEnableStickyKeys(
    GLMWFWWindow *winPtr)
{
    winPtr->input.StickyKeys = 1;
    return TCL_OK;
}

static int
_glfwDisableStickyKeys(
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
 * _glfwEnableStickyMouseButtons() - Enable sticky mouse buttons
 * _glfwDisableStickyMouseButtons() - Disable sticky mouse buttons
 *========================================================================
 */

static int
_glfwEnableStickyMouseButtons(
    GLMWFWWindow *winPtr)
{
    winPtr->input.StickyMouseButtons = 1;
    return TCL_OK;
}

static int
_glfwDisableStickyMouseButtons(
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
 * _glfwEnableSystemKeys() - Enable system keys
 * _glfwDisableSystemKeys() - Disable system keys
 *========================================================================
 */

static int
_glfwEnableSystemKeys(
    GLMWFWWindow *winPtr)
{
    if (!winPtr->SysKeysDisabled) {
        return TCL_OK;
    }
    _glfwPlatformEnableSystemKeys(winPtr);
    /* Indicate that system keys are no longer disabled */
    winPtr->SysKeysDisabled = GL_FALSE;
    return TCL_OK;
}

static int
_glfwDisableSystemKeys(
    GLMWFWWindow *winPtr)
{
    if (winPtr->SysKeysDisabled) {
        return TCL_OK;
    }
    _glfwPlatformDisableSystemKeys(winPtr);
    /* Indicate that system keys are now disabled */
    winPtr->SysKeysDisabled = GL_TRUE;
    return TCL_OK;
}

/*
 *========================================================================
 * _glfwEnableKeyRepeat() - Enable key repeat
 * _glfwDisableKeyRepeat() - Disable key repeat
 *========================================================================
 */

static int
_glfwEnableKeyRepeat(
    GLMWFWWindow *winPtr)
{
    winPtr->input.KeyRepeat = 1;
    return TCL_OK;
}

static int
_glfwDisableKeyRepeat(
    GLMWFWWindow *winPtr)
{
    winPtr->input.KeyRepeat = 0;
    return TCL_OK;
}

/*
 *========================================================================
 * _glfwEnableAutoPollEvents() - Enable automatic event polling
 * _glfwDisableAutoPollEvents() - Disable automatic event polling
 *========================================================================
 */

static int
_glfwEnableAutoPollEvents(
    GLMWFWWindow *winPtr)
{
    winPtr->AutoPollEvents = 1;
    return TCL_OK;
}

static int
_glfwDisableAutoPollEvents(
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
 * glfwEnable() - Enable certain GLMWFW/window/system functions.
 *========================================================================
 */

int
glfwEnable(
    GLMWFWWindow *winPtr,
    int token)
{
    switch (token) {
    case GLMWFW_MOUSE_CURSOR:
        _glfwEnableMouseCursor(winPtr);
        break;
    case GLMWFW_STICKY_KEYS:
        _glfwEnableStickyKeys(winPtr);
        break;
    case GLMWFW_STICKY_MOUSE_BUTTONS:
        _glfwEnableStickyMouseButtons(winPtr);
        break;
    case GLMWFW_SYSTEM_KEYS:
        _glfwEnableSystemKeys(winPtr);
        break;
    case GLMWFW_KEY_REPEAT:
        _glfwEnableKeyRepeat(winPtr);
        break;
    case GLMWFW_AUTO_POLL_EVENTS:
        _glfwEnableAutoPollEvents(winPtr);
        break;
    default:
        break;
    }
    return TCL_OK;
}

/*
 *========================================================================
 * glfwDisable() - Disable certain GLMWFW/window/system functions.
 *========================================================================
 */

int
glfwDisable(
    GLMWFWWindow *winPtr,
    int token)
{
    switch (token) {
    case GLMWFW_MOUSE_CURSOR:
        _glfwDisableMouseCursor(winPtr);
        break;
    case GLMWFW_STICKY_KEYS:
        _glfwDisableStickyKeys(winPtr);
        break;
    case GLMWFW_STICKY_MOUSE_BUTTONS:
        _glfwDisableStickyMouseButtons(winPtr);
        break;
    case GLMWFW_SYSTEM_KEYS:
        _glfwDisableSystemKeys(winPtr);
        break;
    case GLMWFW_KEY_REPEAT:
        _glfwDisableKeyRepeat(winPtr);
        break;
    case GLMWFW_AUTO_POLL_EVENTS:
        _glfwDisableAutoPollEvents(winPtr);
        break;
    default:
        break;
    }
    return TCL_OK;
}
