/*
 * tclGLMWFWInput.c --
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
 * RCS: @(#) $Id: tclGLMWFWInput.c,v 1.1.2.2 2007/11/01 16:14:36 wiede Exp $
 */

#include "tclGLMWFWInt.h"
#include "tclGLMWFWPlatform.h"

/*
 *========================================================================
 * glmwfwGetKey()
 *========================================================================
 */

int
glmwfwGetKey(
    GLMWFWWindow *winPtr,
    int key)
{
    /* Is GLMWFW initialized? */
    if (!winPtr->Opened )
    {
        return GLMWFW_RELEASE;
    }

    /* Is it a valid key? */
    if (key < 0 || key > GLMWFW_KEY_LAST) {
        return GLMWFW_RELEASE;
    }

    if (winPtr->input.Key[key] == GLMWFW_STICK) {
        /* Sticky mode: release key now */
        winPtr->input.Key[key] = GLMWFW_RELEASE;
        return GLMWFW_PRESS;
    }
    return (int)winPtr->input.Key[key];
}

/*
 *========================================================================
 * glmwfwGetMouseButton()
 *========================================================================
 */

int
glmwfwGetMouseButton(
    GLMWFWWindow *winPtr,
    int button)
{
    /* Is GLMWFW initialized? */
    if (!winPtr->Opened ) {
        return GLMWFW_RELEASE;
    }
    /* Is it a valid mouse button? */
    if (button < 0 || button > GLMWFW_MOUSE_BUTTON_LAST) {
        return GLMWFW_RELEASE;
    }
    if (winPtr->input.MouseButton[button] == GLMWFW_STICK ) {
        /* Sticky mode: release mouse button now */
        winPtr->input.MouseButton[button] = GLMWFW_RELEASE;
        return GLMWFW_PRESS;
    }
    return (int)winPtr->input.MouseButton[button];
}


//========================================================================
// glmwfwGetMousePos()
//========================================================================

int
glmwfwGetMousePos(
    GLMWFWWindow *winPtr,
    int *xpos,
    int *ypos)
{
    /* Is GLMWFW initialized? */
    if (!winPtr->Opened) {
        return TCL_OK;
    }
    /* Return mouse position */
    if (xpos != NULL) {
        *xpos = winPtr->input.MousePosX;
    }
    if (ypos != NULL) {
        *ypos = winPtr->input.MousePosY;
    }
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwSetMousePos()
 *========================================================================
 */

int
glmwfwSetMousePos(
    GLMWFWWindow *winPtr,
    int xpos,
    int ypos)
{
    /* Is GLMWFW initialized? */
    if (!winPtr->Opened )
    {
        return TCL_OK;
    }

    /* Don't do anything if the mouse position did not change */
    if (xpos == winPtr->input.MousePosX && ypos == winPtr->input.MousePosY) {
        return TCL_OK;
    }
    /* Set GLMWFW mouse position */
    winPtr->input.MousePosX = xpos;
    winPtr->input.MousePosY = ypos;
    // If we have a locked mouse, do not change cursor position
    if (winPtr->MouseLock) {
        return TCL_OK;
    }
    /* Update physical cursor position */
    _glmwfwPlatformSetMouseCursorPos(winPtr, xpos, ypos);
   return TCL_OK;
}

/*
 *========================================================================
 * glmwfwGetMouseWheel()
 *========================================================================
 */

int
glmwfwGetMouseWheel(
    GLMWFWWindow *winPtr)
{
    /* Is GLMWFW initialized? */
    if (!winPtr->Opened) {
        return 0;
    }
    /* Return mouse wheel position */
    return winPtr->input.WheelPos;
}

/*
 *========================================================================
 * glmwfwSetMouseWheel()
 *========================================================================
 */

int
glmwfwSetMouseWheel(
    GLMWFWWindow *winPtr,
    int pos)
{
    /* Is GLMWFW initialized? */
    if (!winPtr->Opened ) {
        return TCL_OK;
    }
    /* Set mouse wheel position */
    winPtr->input.WheelPos = pos;
    return TCL_OK;
}

/*
 *========================================================================
  *glmwfwSetKeyCallback() - Set callback function for keyboard input
 *========================================================================
 */

int
glmwfwSetKeyCallback(
    GLMWFWWindow *winPtr,
    GLMWFWkeyfun cbfun)
{
    /* Is GLMWFW initialized? */
    if (!winPtr->Opened ) {
        return TCL_OK;
    }
    /* Set callback function */
    winPtr->keyfun = cbfun;
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwSetCharCallback() - Set callback function for character input
 *========================================================================
 */

int
glmwfwSetCharCallback(
    GLMWFWWindow *winPtr,
    GLMWFWcharfun cbfun)
{
    /* Is GLMWFW initialized? */
    if (!winPtr->Opened) {
        return TCL_OK;
    }
    /* Set callback function */
    winPtr->charfun = cbfun;
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwSetMouseButtonCallback() - Set callback function for mouse clicks
 *========================================================================
 */

int
glmwfwSetMouseButtonCallback(
    GLMWFWWindow *winPtr,
    GLMWFWmousebuttonfun cbfun)
{
    /* Is GLMWFW initialized? */
    if (!winPtr->Opened) {
        return TCL_OK;
    }
    /* Set callback function */
    winPtr->mousebuttonfun = cbfun;
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwSetMousePosCallback() - Set callback function for mouse moves
 *========================================================================
 */

int
glmwfwSetMousePosCallback(
    GLMWFWWindow *winPtr,
    GLMWFWmouseposfun cbfun)
{
    /* Is GLMWFW initialized? */
    if (!winPtr->Opened) {
        return TCL_OK;
    }
    /* Set callback function */
    winPtr->mouseposfun = cbfun;
    /* Call the callback function to let the application know the current
     * mouse position
     */
    if (cbfun) {
        cbfun(winPtr,winPtr->input.MousePosX, winPtr->input.MousePosY);
    }
    return TCL_OK;
}

/*
 *========================================================================
 * glmwfwSetMouseWheelCallback() - Set callback function for mouse wheel
 *========================================================================
 */

int
glmwfwSetMouseWheelCallback(
    GLMWFWWindow *winPtr,
    GLMWFWmousewheelfun cbfun)
{
    /* Is GLMWFW initialized? */
    if (!winPtr->Opened) {
        return TCL_OK;
    }
    /* Set callback function */
    winPtr->mousewheelfun = cbfun;
    /* Call the callback function to let the application know the current
     * mouse wheel position
     */
    if (cbfun) {
        cbfun(winPtr, winPtr->input.WheelPos);
    }
    return TCL_OK;
}

