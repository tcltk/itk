/*
 * glmwfwGlext.c --
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
 * RCS: @(#) $Id: glmwfwGlext.c,v 1.1.2.1 2007/11/02 16:29:39 wiede Exp $
 */

#include "glmwfwInt.h"
#include "glmwfwPlatform.h"

/*
 ************************************************************************
 ****                  GLFW internal functions                       ****
 ************************************************************************
 */

/*
 *========================================================================
 * _glmwfwStringInExtensionString() - Check if a string can be found in an
 * OpenGL extension string
 *========================================================================
 */

int
_glmwfwStringInExtensionString(
    const char *string,
    const GLubyte *extensions)
{
    const GLubyte *start;
    GLubyte *where;
    GLubyte *terminator;

    /* It takes a bit of care to be fool-proof about parsing the
     * OpenGL extensions string. Don't be fooled by sub-strings,
     * etc.
     */
    start = extensions;
    while(1) {
        where = (GLubyte *)strstr((const char *)start, string);
        if (!where) {
            return GL_FALSE;
        }
        terminator = where + strlen(string);
        if (where == start || *(where - 1) == ' ') {
            if (*terminator == ' ' || *terminator == '\0') {
                break;
            }
        }
        start = terminator;
    }
    return GL_TRUE;
}

/*
 ************************************************************************
 ****                    Glmwfw user functions                       ****
 ************************************************************************
 */

/*
 *========================================================================
 * glmwfwExtensionSupported() - Check if an OpenGL extension is available
 * at runtime
 *========================================================================
 */

int
glmwfwExtensionSupported(
    GlmwfwInfo *infoPtr,
    const char *extension)
{
    const GLubyte *extensions;
    GLubyte       *where;

    /* Is Glmwfw initialized? */
    if (!infoPtr->currWindow->Opened) {
        return GL_FALSE;
    }
    /* Extension names should not have spaces */
    where = (GLubyte *)strchr(extension, ' ');
    if (where || *extension == '\0') {
        return GL_FALSE;
    }
    /* Check if extension is in the standard OpenGL extensions string */
    extensions = (GLubyte *)glGetString(GL_EXTENSIONS);
    if (extensions != NULL) {
        if (_glmwfwStringInExtensionString(extension, extensions)) {
            return GL_TRUE;
        }
    }
    /* Additional platform specific extension checking (e.g. WGL) */
    if (_glmwfwPlatformExtensionSupported(infoPtr->currWindow, extension)) {
        return GL_TRUE;
    }
    return GL_FALSE;
}

/*
 *========================================================================
 * glmwfwGetProcAddress() - Get the function pointer to an OpenGL function.
 * This function can be used to get access to extended OpenGL functions.
 *========================================================================
 */

void *
glmwfwGetProcAddress(
    GlmwfwInfo *infoPtr,
    const char *procname)
{
    /* Is Glmwfw initialized? */
    if (!infoPtr->currWindow->Opened) {
        return NULL;
    }
    return _glmwfwPlatformGetProcAddress(infoPtr->currWindow, procname);
}

/*
 *========================================================================
 * glmwfwGetGLVersion() - Get OpenGL version
 *========================================================================
 */

void
glmwfwGetGLVersion(
    GlmwfwInfo *infoPtr,
    int *major,
    int *minor,
    int *rev)
{
    GLuint _major;
    GLuint _minor = 0;
    GLuint _rev = 0;
    const GLubyte *version;
    GLubyte *ptr;

    /* Is Glmwfw initialized? */
    if (!infoPtr->currWindow->Opened) {
        return;
    }
    /* Get OpenGL version string */
    version = glGetString(GL_VERSION);
    if (!version) {
        return;
    }
    /* Parse string */
    ptr = (GLubyte*) version;
    for(_major = 0; *ptr >= '0' && *ptr <= '9'; ptr++) {
        _major = 10*_major + (*ptr - '0');
    }
    if (*ptr == '.') {
        ptr ++;
        for (_minor = 0; *ptr >= '0' && *ptr <= '9'; ptr++) {
            _minor = 10*_minor + (*ptr - '0');
        }
        if (*ptr == '.') {
            ptr ++;
            for(_rev = 0; *ptr >= '0' && *ptr <= '9'; ptr++) {
                _rev = 10*_rev + (*ptr - '0');
            }
        }
    }
    /* Return parsed values */
    if (major != NULL) {
        *major = _major;
    }
    if (minor != NULL) {
        *minor = _minor;
    }
    if (rev != NULL) {
        *rev = _rev;
    }
}

