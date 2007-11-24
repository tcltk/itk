//========================================================================
// GLFW - An OpenGL framework
// File:        x11_init.c
// Platform:    X11 (Unix)
// API version: 2.6
// WWW:         http://glfw.sourceforge.net
//------------------------------------------------------------------------
// Copyright (c) 2002-2006 Camilla Berglund
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

/*
 * This file contains the C-implemented part of 
 * a Tcl interface to the GLFW X11 OpenGL library
 * This is a modified version of the original version adapted for use with Tcl
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: x11_init.c,v 1.1.2.5 2007/11/24 22:23:48 wiede Exp $
 */

#include "platform.h"



//************************************************************************
//****                  GLMWFW internal functions                     ****
//************************************************************************

//========================================================================
// Dynamically load libraries
//========================================================================

#ifdef _GLMWFW_DLOPEN_LIBGL
static char * _glmwfw_libGL_name[ ] =
{
    "libGL.so",
    "libGL.so.1",
    "/usr/lib/libGL.so",
    "/usr/lib/libGL.so.1",
    NULL
};
#endif

static void _glmwfwInitLibraries( void )
{
#ifdef _GLMWFW_DLOPEN_LIBGL
    int i;

    _glmwfwLibrary.Libs.libGL = NULL;
    for( i = 0; !_glmwfw_libGL_name[ i ] != NULL; i ++ )
    {
        _glmwfwLibrary.Libs.libGL = dlopen( _glmwfw_libGL_name[ i ],
                                          RTLD_LAZY | RTLD_GLOBAL );
	if( _glmwfwLibrary.Libs.libGL )
	    break;
    }
#endif
}


//========================================================================
// Terminate GLMWFW when exiting application
//========================================================================

void _glmwfwTerminate_atexit( void )
{
/* FIX ME !!! */
#ifdef NOTDEF
    glmwfwTerminate(winPtr);
#endif
}


//========================================================================
// Initialize X11 display
//========================================================================

static int _glmwfwInitDisplay( GlmwfwInfo *infoPtr )
{
    // Open display
    _glmwfwLibrary.Dpy = XOpenDisplay( 0 );
    if( !_glmwfwLibrary.Dpy )
    {
        return GL_FALSE;
    }
    _glmwfwLibrary.im = XOpenIM (_glmwfwLibrary.Dpy, 0, NULL, NULL);
    /* create an event handler for keybord mouse button etc. */
    Tcl_CreateFileHandler(ConnectionNumber(_glmwfwLibrary.Dpy),
            TCL_READABLE | TCL_EXCEPTION,
            event_handler, (ClientData)infoPtr); 

    // Check screens
    _glmwfwLibrary.NumScreens = ScreenCount( _glmwfwLibrary.Dpy );
    _glmwfwLibrary.DefaultScreen = DefaultScreen( _glmwfwLibrary.Dpy );

    // Check for XF86VidMode extension
#ifdef _GLMWFW_HAS_XF86VIDMODE
    _glmwfwLibrary.XF86VidMode.Available =
        XF86VidModeQueryExtension( _glmwfwLibrary.Dpy,
	                           &_glmwfwLibrary.XF86VidMode.EventBase,
	                           &_glmwfwLibrary.XF86VidMode.ErrorBase);
#else
    _glmwfwLibrary.XF86VidMode.Available = 0;
#endif

    // Check for XRandR extension
#ifdef _GLMWFW_HAS_XRANDR
    _glmwfwLibrary.XRandR.Available =
        XRRQueryExtension( _glmwfwLibrary.Dpy,
	                   &_glmwfwLibrary.XRandR.EventBase,
			   &_glmwfwLibrary.XRandR.ErrorBase );
#else
    _glmwfwLibrary.XRandR.Available = 0;
#endif

     return GL_TRUE;
}


//========================================================================
// Terminate X11 display
//========================================================================

static void _glmwfwTerminateDisplay( void )
{
    // Open display
    if( _glmwfwLibrary.Dpy )
    {
        XCloseDisplay( _glmwfwLibrary.Dpy );
        _glmwfwLibrary.Dpy = NULL;
    }
}


//************************************************************************
//****               Platform implementation functions                ****
//************************************************************************

//========================================================================
// Initialize various GLMWFW state
//========================================================================

int _glmwfwPlatformInit( GlmwfwInfo *infoPtr )
{
    // Initialize display
    if( !_glmwfwInitDisplay(infoPtr) )
    {
        return GL_FALSE;
    }

    // Try to load libGL.so if necessary
    _glmwfwInitLibraries();

    /* FIX ME !! */
#ifdef NOTDEF
    // Install atexit() routine
    atexit( _glmwfwTerminate_atexit );
#endif

    // Initialize joysticks
    _glmwfwInitJoysticks();

    // Start the timer
    _glmwfwInitTimer();

    return GL_TRUE;
}


//========================================================================
// Close window and kill all threads
//========================================================================

int _glmwfwPlatformTerminate( GlmwfwInfo *infoPtr )
{

    // Close OpenGL window
    infoPtr->closeWindow(infoPtr->currWindow);

    // Terminate display
    _glmwfwTerminateDisplay();

    // Terminate joysticks
    _glmwfwTerminateJoysticks();

    // Unload libGL.so if necessary
#ifdef _GLMWFW_DLOPEN_LIBGL
    if( _glmwfwLibrary.Libs.libGL != NULL )
    {
        dlclose( _glmwfwLibrary.Libs.libGL );
        _glmwfwLibrary.Libs.libGL = NULL;
    }
#endif

    return GL_TRUE;
}

