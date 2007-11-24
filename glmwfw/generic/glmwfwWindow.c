/*
 * glmwfwWindow.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the GLFW OpenGL window frame work
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
 * RCS: @(#) $Id: glmwfwWindow.c,v 1.1.2.5 2007/11/24 22:18:16 wiede Exp $
 */

#include "glmwfwInt.h"
#include "glmwfwPlatform.h"

/*
 ************************************************************************
 *                  Glmwfw internal functions
 ************************************************************************
 */

/*
 *-------------------------------------------------------------------------
 * Clear all open window hints
 *-------------------------------------------------------------------------
 */

void
_glmwfwClearWindowHints(
    GlmwfwWindow *winPtr)
{
    winPtr->Hints.RefreshRate    = 0;
    winPtr->Hints.AccumRedBits   = 0;
    winPtr->Hints.AccumGreenBits = 0;
    winPtr->Hints.AccumBlueBits  = 0;
    winPtr->Hints.AccumAlphaBits = 0;
    winPtr->Hints.AuxBuffers     = 0;
    winPtr->Hints.Stereo         = 0;
    winPtr->Hints.WindowNoResize = 0;
    winPtr->Hints.Samples        = 0;
}

/*
 *========================================================================
 * Handle the input tracking part of window deactivation
 *========================================================================
 */

void
_glmwfwInputDeactivation(
    GlmwfwWindow *winPtr)
{
    int i;

    /* Release all keyboard keys */
    for (i = 0; i <= GLMWFW_KEY_LAST; i++) {
        if(winPtr->input.Key[i] == GLMWFW_PRESS) {
	    _glmwfwInputKey(winPtr, i, GLMWFW_RELEASE);
	}
    }

    /* Release all mouse buttons */
    for (i = 0; i <= GLMWFW_MOUSE_BUTTON_LAST; i++) {
        if (winPtr->input.MouseButton[i] == GLMWFW_PRESS)
	{
	    _glmwfwInputMouseClick(winPtr, i, GLMWFW_RELEASE);
	}
    }
}


//========================================================================
// _glmwfwClearInput() - Clear all input state
//========================================================================

void
_glmwfwClearInput(
    GlmwfwWindow *winPtr)
{
    int i;

    /* Release all keyboard keys */
    for (i = 0; i <= GLMWFW_KEY_LAST; i++) {
        winPtr->input.Key[i] = GLMWFW_RELEASE;
    }

    /* Clear last character */
    winPtr->input.LastChar = 0;

    /* Release all mouse buttons */
    for (i = 0; i <= GLMWFW_MOUSE_BUTTON_LAST; i++) {
        winPtr->input.MouseButton[i] = GLMWFW_RELEASE;
    }

    /* Set mouse position to (0,0) */
    winPtr->input.MousePosX = 0;
    winPtr->input.MousePosY = 0;

    /* Set mouse wheel position to 0 */
    winPtr->input.WheelPos = 0;

    /* The default is to use non sticky keys and mouse buttons */
    winPtr->input.StickyKeys = GL_FALSE;
    winPtr->input.StickyMouseButtons = GL_FALSE;

    /* The default is to disable key repeat */
    winPtr->input.KeyRepeat = GL_FALSE;
}

/*
 *========================================================================
 * _glmwfwInputKey() - Register keyboard activity
 *========================================================================
 */

void
_glmwfwInputKey(
    GlmwfwWindow *winPtr,
    int key,
    int action)
{
    int keyrepeat = 0;

    if (key < 0 || key > GLMWFW_KEY_LAST) {
	return;
    }

    // Are we trying to release an already released key?
    if (action == GLMWFW_RELEASE && winPtr->input.Key[key] != GLMWFW_PRESS) {
	return;
    }

    /* Register key action */
    if (action == GLMWFW_RELEASE && winPtr->input.StickyKeys) {
	winPtr->input.Key[key] = GLMWFW_STICK;
    } else {
	keyrepeat = (winPtr->input.Key[key] == GLMWFW_PRESS)
	        && (action == GLMWFW_PRESS);
	winPtr->input.Key[key] = (char)action;
    }

    /* Call user callback function */
    if (winPtr->keyFunc &&
            (winPtr->input.KeyRepeat || !keyrepeat)) {
	winPtr->keyFunc(winPtr, key, action);
    }
}

/*
 *========================================================================
 * _glmwfwInputChar() - Register (keyboard) character activity
 *========================================================================
 */

int
_glmwfwInputChar(
    GlmwfwWindow *winPtr,
    int character,
    int action)
{
    int keyrepeat = 0;

    /* Valid Unicode (ISO 10646) character? */
    if (!((character >= 32 && character <= 126) || character >= 160)) {
        return TCL_ERROR;
    }

    /* Is this a key repeat? */
    if (action == GLMWFW_PRESS && winPtr->input.LastChar == character) {
        keyrepeat = 1;
    }

    /* Store this character as last character (or clear it, if released) */
    if (action == GLMWFW_PRESS) {
        winPtr->input.LastChar = character;
    } else {
        winPtr->input.LastChar = 0;
    }

    /* Call user callback function */
    if (winPtr->charFunc && (winPtr->input.KeyRepeat || !keyrepeat)) {
        winPtr->charFunc(winPtr, character, action);
    }
    return TCL_OK;
}

/*
 *========================================================================
 * _glmwfwInputMouseClick() - Register mouse button clicks
 *========================================================================
 */

void
_glmwfwInputMouseClick(
    GlmwfwWindow *winPtr,
    int button,
    int action)
{
    if ((button >= 0) && (button <= GLMWFW_MOUSE_BUTTON_LAST)) {
        /* Register mouse button action */
        if ((action == GLMWFW_RELEASE) && (winPtr->input.StickyMouseButtons)) {
            winPtr->input.MouseButton[button] = GLMWFW_STICK;
        } else {
            winPtr->input.MouseButton[button] = (char)action;
        }

        /* Call user callback function */
        if (winPtr->mouseButtonFunc) {
	    winPtr->mouseButtonFunc(winPtr, button, action);
        }
    }
}


/*
 ************************************************************************
 ****                    Glmwfw user functions                       ****
 ************************************************************************
 */

/*
 *========================================================================
 * glmwfwOpenWindow() - Here is where the window is created, and the OpenGL
 * rendering context is created
 *========================================================================
 */

GlmwfwWindow *
glmwfwOpenWindow(
    GlmwfwInfo *infoPtr,
    int width,
    int height,
    int redbits,
    int greenbits,
    int bluebits,
    int alphabits,
    int depthbits,
    int stencilbits,
    int mode)
{
    Tcl_HashEntry *hPtr;
    GlmwfwWindow *winPtr;
    int isNew;
    char buf[50];
    int x;

    /* Check input arguments */
    if (mode != GLMWFW_WINDOW && mode != GLMWFW_FULLSCREEN) {
        Tcl_AppendResult(infoPtr->interp,
	        "bad mode: only GLMWFW_WINDOW and GLMWFW_FULLSCREEN are allowed",
		NULL);
        return NULL;
    }

    infoPtr->numWindows++;
    sprintf(buf, "winhandle_%d", infoPtr->numWindows);
    winPtr = (GlmwfwWindow *)ckalloc(sizeof(GlmwfwWindow));
    memset(winPtr, 0, sizeof(GlmwfwWindow));
    winPtr->handlePtr = Tcl_NewStringObj(buf, -1);
    winPtr->infoPtr = infoPtr;
    Tcl_IncrRefCount(winPtr->handlePtr);
    hPtr = Tcl_CreateHashEntry(&infoPtr->windows,
            (char *)winPtr->handlePtr, &isNew);
    Tcl_SetHashValue(hPtr, winPtr);
    infoPtr->currWindow = winPtr;
    Tcl_AppendResult(infoPtr->interp, Tcl_GetString(winPtr->handlePtr), NULL);

    // Clear Glmwfw window state
    winPtr->Active            = GL_TRUE;
    winPtr->Iconified         = GL_FALSE;
    winPtr->MouseLock         = GL_FALSE;
    winPtr->AutoPollEvents    = GL_TRUE;
    _glmwfwClearInput(winPtr);

    /* Check width & height */
    if (width > 0 && height <= 0) {
        /* Set the window aspect ratio to 4:3 */
        height = (width * 3) / 4;
    } else {
        if (width <= 0 && height > 0) {
            /* Set the window aspect ratio to 4:3 */
            width = (height * 4) / 3;
        } else {
	    if (width <= 0 && height <= 0) {
                /* Default window size */
                width  = 640;
                height = 480;
            }
        }
    }

    /* Remember window settings */
    winPtr->Width          = width;
    winPtr->Height         = height;
    winPtr->Fullscreen     = (mode == GLMWFW_FULLSCREEN ? 1 : 0);

    /* Platform specific window opening routine */
    if (!_glmwfwPlatformOpenWindow(winPtr, width, height, redbits, greenbits,
            bluebits, alphabits, depthbits, stencilbits, mode,
	    &winPtr->Hints)) {
        return NULL;
    }

    /* Flag that window is now opened */
    winPtr->Opened = GL_TRUE;

    /* Get window parameters (such as color buffer bits etc) */
    _glmwfwPlatformRefreshWindowParams(winPtr);

    /* Get OpenGL version */
    glmwfwGetGLVersion(infoPtr, &winPtr->GLVerMajor, &winPtr->GLVerMinor, &x);

    /* Do we have non-power-of-two textures? */
    winPtr->Has_GL_ARB_texture_non_power_of_two =
        glmwfwExtensionSupported(infoPtr, "GL_ARB_texture_non_power_of_two");

    /* Do we have automatic mipmap generation? */
    winPtr->Has_GL_SGIS_generate_mipmap =
        (winPtr->GLVerMajor >= 2) || (winPtr->GLVerMinor >= 4) ||
        glmwfwExtensionSupported(infoPtr, "GL_SGIS_generate_mipmap");

    /* If full-screen mode was requested, disable mouse cursor */
    if (mode == GLMWFW_FULLSCREEN ) {
        glmwfwDisable(winPtr, GLMWFW_MOUSE_CURSOR);
    }
    return winPtr;
}

/*
 *========================================================================
 * glmwfwOpenWindowHint() - Set hints for opening the window
 *========================================================================
 */

int
glmwfwOpenWindowHint(
    GlmwfwWindow *winPtr,
    int target,
    int hint)
{
    switch (target) {
    case GLMWFW_REFRESH_RATE:
        winPtr->Hints.RefreshRate = hint;
        break;
    case GLMWFW_ACCUM_RED_BITS:
        winPtr->Hints.AccumRedBits = hint;
        break;
    case GLMWFW_ACCUM_GREEN_BITS:
        winPtr->Hints.AccumGreenBits = hint;
        break;
    case GLMWFW_ACCUM_BLUE_BITS:
        winPtr->Hints.AccumBlueBits = hint;
        break;
    case GLMWFW_ACCUM_ALPHA_BITS:
        winPtr->Hints.AccumAlphaBits = hint;
        break;
    case GLMWFW_AUX_BUFFERS:
        winPtr->Hints.AuxBuffers = hint;
        break;
    case GLMWFW_STEREO:
        winPtr->Hints.Stereo = hint;
        break;
    case GLMWFW_WINDOW_NO_RESIZE:
        winPtr->Hints.WindowNoResize = hint;
        break;
    case GLMWFW_FSAA_SAMPLES:
        winPtr->Hints.Samples = hint;
        break;
    default:
        break;
    }
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwCloseWindow() - Properly kill the window / video display
 *========================================================================
 */

int
glmwfwCloseWindow(
    GlmwfwWindow *winPtr)
{
    /* Show mouse pointer again (if hidden) */
    glmwfwEnable(winPtr, GLMWFW_MOUSE_CURSOR);

    /* Close window */
    _glmwfwPlatformCloseWindow(winPtr);

    /* Window is no longer opened */
    winPtr->Opened = GL_FALSE;
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwSetWindowTitle() - Set the window title
 *========================================================================
 */

int
glmwfwSetWindowTitle(
    GlmwfwWindow *winPtr,
    const char *title)
{
    /* Set window title */
    _glmwfwPlatformSetWindowTitle(winPtr, title);
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwGetWindowSize() - Get the window size
 *========================================================================
 */

int
glmwfwGetWindowSize(
    GlmwfwWindow *winPtr,
    int *width,
    int *height)
{
    if (width != NULL) {
        *width = winPtr->Width;
    }
    if (height != NULL) {
        *height = winPtr->Height;
    }
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwSetWindowSize() - Set the window size
 *========================================================================
 */

int
glmwfwSetWindowSize(
    GlmwfwWindow *winPtr,
    int width,
    int height)
{
    /* Is Glmwfw initialized? */
    if (!winPtr->Opened || winPtr->Iconified) {
        return TCL_OK;
    }

    /* Don't do anything if the window size did not change */
    if (width == winPtr->Width && height == winPtr->Height) {
        return TCL_OK;
    }

    /* Change window size */
    _glmwfwPlatformSetWindowSize(winPtr, width, height);

    /* Refresh window parameters (may have changed due to changed video
     * modes)
     */
    _glmwfwPlatformRefreshWindowParams(winPtr);
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwSetWindowPos() - Set the window position
 *========================================================================
 */

int
glmwfwSetWindowPos(
    GlmwfwWindow *winPtr,
    int x,
    int y)
{
    /* Is Glmwfw initialized? */
    if (!winPtr->Opened || winPtr->Fullscreen ||
        winPtr->Iconified) {
        return TCL_OK;
    }
    /* Set window position */
    _glmwfwPlatformSetWindowPos(winPtr, x, y);
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwIconfyWindow() - Window iconification
 *========================================================================
 */

int
glmwfwIconifyWindow(
    GlmwfwWindow *winPtr)
{
    /* Is Glmwfw initialized? */
    if (winPtr->Opened || winPtr->Iconified) {
        return TCL_OK;
    }
    /* Iconify window */
    _glmwfwPlatformIconifyWindow(winPtr);
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwRestoreWindow() - Window un-iconification
 *========================================================================
 */

int
lmwfwRestoreWindow(
    GlmwfwWindow *winPtr)
{
    /* Is Glmwfw initialized? */
    if (winPtr->Opened || !winPtr->Iconified) {
        return TCL_OK;
    }
    /* Restore iconified window */
    _glmwfwPlatformRestoreWindow(winPtr);
    /* Refresh window parameters */
    _glmwfwPlatformRefreshWindowParams(winPtr);
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwSwapBuffers() - Swap buffers (double-buffering) and poll any new
 * events
 *========================================================================
 */

int
glmwfwSwapBuffers(
    GlmwfwWindow *winPtr)
{
    /* Is Glmwfw initialized? */
    if (!winPtr->Opened) {
        return TCL_OK;
    }
    /* Update display-buffer */
    if (winPtr->Opened) {
        _glmwfwPlatformSwapBuffers(winPtr);
    }
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwSwapInterval() - Set double buffering swap interval (0 = vsync off)
 *========================================================================
 */

int
glmwfwSwapInterval(
    GlmwfwWindow *winPtr,
    int interval)
{
    /* Is Glmwfw initialized? */
    if (!winPtr->Opened) {
        return TCL_OK;
    }
    /* Set double buffering swap interval */
    _glmwfwPlatformSwapInterval(winPtr, interval);
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwGetWindowParam() - Get window parameter
 *========================================================================
 */

int
glmwfwGetWindowParam(
    GlmwfwWindow *winPtr,
    int param)
{
    /* Is the window opened? */
    if (!winPtr->Opened) {
        if (param == GLMWFW_OPENED) {
            return GL_FALSE;
        }
        return 0;
    }
    /* Window parameters */
    switch (param) {
    case GLMWFW_OPENED:
        return GL_TRUE;
    case GLMWFW_ACTIVE:
        return winPtr->Active;
    case GLMWFW_ICONIFIED:
        return winPtr->Iconified;
    case GLMWFW_ACCELERATED:
        return winPtr->Accelerated;
    case GLMWFW_RED_BITS:
        return winPtr->RedBits;
    case GLMWFW_GREEN_BITS:
        return winPtr->GreenBits;
    case GLMWFW_BLUE_BITS:
        return winPtr->BlueBits;
    case GLMWFW_ALPHA_BITS:
        return winPtr->AlphaBits;
    case GLMWFW_DEPTH_BITS:
        return winPtr->DepthBits;
    case GLMWFW_STENCIL_BITS:
        return winPtr->StencilBits;
    case GLMWFW_ACCUM_RED_BITS:
        return winPtr->Hints.AccumRedBits;
    case GLMWFW_ACCUM_GREEN_BITS:
        return winPtr->Hints.AccumGreenBits;
    case GLMWFW_ACCUM_BLUE_BITS:
        return winPtr->Hints.AccumBlueBits;
    case GLMWFW_ACCUM_ALPHA_BITS:
        return winPtr->Hints.AccumAlphaBits;
    case GLMWFW_AUX_BUFFERS:
        return winPtr->Hints.AuxBuffers;
    case GLMWFW_STEREO:
        return winPtr->Hints.Stereo;
    case GLMWFW_REFRESH_RATE:
        return winPtr->Hints.RefreshRate;
    case GLMWFW_WINDOW_NO_RESIZE:
        return winPtr->Hints.WindowNoResize;
    case GLMWFW_FSAA_SAMPLES:
        return winPtr->Hints.Samples;
    default:
        return 0;
    }
}

/*
 *========================================================================
 * glmwfwSetWindowSizeCallback() - Set callback function for window size
 * changes
 *========================================================================
 */

int
glmwfwSetWindowSizeCallback(
    GlmwfwWindow *winPtr,
    glmwfwWindowSizeFunc cbfun)
{
    /* Is Glmwfw initialized? */
    if (!winPtr->Opened) {
        return TCL_OK;
    }
    /* Set callback function */
    winPtr->windowSizeFunc = cbfun;

    /* Call the callback function to let the application know the current
     * window size
     */
    if (cbfun) {
        cbfun(winPtr, winPtr->Width, winPtr->Height);
    }
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwSetWindowCloseCallback() - Set callback function for window close
 * events
 *========================================================================
 */

int
glmwfwSetWindowCloseCallback(
    GlmwfwWindow *winPtr,
    glmwfwWindowCloseFunc cbfun)
{
    /* Is Glmwfw initialized? */
    if (!winPtr->Opened) {
        return TCL_OK;
    }
    /* Set callback function */
    winPtr->windowCloseFunc = cbfun;
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwSetWindowRefreshCallback() - Set callback function for window
 * refresh events
 *========================================================================
 */

int
glmwfwSetWindowRefreshCallback(
    GlmwfwWindow *winPtr,
    glmwfwWindowRefreshFunc cbfun)
{
    /* Is Glmwfw initialized? */
    if (!winPtr->Opened) {
        return TCL_OK;
    }
    /* Set callback function */
    winPtr->windowRefreshFunc = cbfun;
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwPollEvents() - Poll for new window and input events
 *========================================================================
 */

int
glmwfwPollEvents(
    GlmwfwWindow *winPtr)
{
    /* Is Glmwfw initialized? */
    if (!winPtr->Opened) {
        return TCL_OK;
    }
    /* Poll for new events */
    _glmwfwPlatformPollEvents(winPtr);
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwWaitEvents() - Wait for new window and input events
 *========================================================================
 */

int
glmwfwWaitEvents(
    GlmwfwWindow *winPtr)
{
    /* Is Glmwfw initialized? */
    if (!winPtr->Opened) {
        return TCL_OK;
    }
    /* Poll for new events */
    _glmwfwPlatformWaitEvents(winPtr);
   return TCL_OK;
}
