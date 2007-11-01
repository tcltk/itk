//========================================================================
// GLFW - An OpenGL framework
// File:        x11_glext.c
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

#include "platform.h"


//************************************************************************
//****               Platform implementation functions                ****
//************************************************************************

//========================================================================
// Check if an OpenGL extension is available at runtime
//========================================================================

int _glmwfwPlatformExtensionSupported( GLMWFWWindow *winPtr, const char *extension )
{
    const GLubyte *extensions;

    // Get list of GLX extensions
    extensions = (const GLubyte*) glXQueryExtensionsString( _glmwfwLibrary.Dpy,
                                                            winPtr->platformWindow->Scrn );
    if( extensions != NULL )
    {
        if( winPtr->infoPtr->stringInExtensionString( extension, extensions ) )
        {
            return GL_TRUE;
        }
    }

    return GL_FALSE;
}


//========================================================================
// Get the function pointer to an OpenGL function
//========================================================================

void * _glmwfwPlatformGetProcAddress( GLMWFWWindow *winPtr, const char *procname )
{
    return (void *) _glmwfw_glXGetProcAddress( (const GLubyte *) procname );
}

