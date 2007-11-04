/*
 * glmwfwBase.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the GLFW OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: glmwfwBase.c,v 1.1.2.2 2007/11/04 08:51:23 wiede Exp $
 */

#include <stdlib.h>
#include "glmwfwInt.h"

typedef struct GlmwfwStubAPI {
int i;
} GlmwfwStubAPI;
struct GlmwfwStubAPI glmwfwStubAPI;

/*
 * ------------------------------------------------------------------------
 *  Initialize()
 *
 *      that is the starting point when loading the library
 *      it initializes all internal stuff
 *
 * ------------------------------------------------------------------------
 */

static int
Initialize (
    Tcl_Interp *interp)
{
    Tcl_Namespace *nsPtr;
    GlmwfwInfo *infoPtr;

    if (Tcl_InitStubs(interp, TCL_VERSION, 0) == NULL) {
        return TCL_ERROR;
    }

    nsPtr = Tcl_CreateNamespace(interp, GLMWFW_NAMESPACE, NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("glmwfw: cannot create namespace: \"%s\" \n",
	        GLMWFW_NAMESPACE);
    }
    /*
     *  Create the top-level data structure for tracking objects.
     *  Store this as "associated data" for easy access, but link
     *  it to the itcl namespace for ownership.
     */
    infoPtr = (GlmwfwInfo*)ckalloc(sizeof(GlmwfwInfo));
    memset(infoPtr, 0, sizeof(GlmwfwInfo));
    infoPtr->version = GLMWFW_INFO_VERSION;
    infoPtr->numWindows = 0;
    infoPtr->interp = interp;
    infoPtr->stringInExtensionString = _glmwfwStringInExtensionString;
    infoPtr->inputDeactivation = _glmwfwInputDeactivation;
    infoPtr->closeWindow = glmwfwCloseWindow;
    infoPtr->inputKey = _glmwfwInputKey;
    infoPtr->inputMouseClick = _glmwfwInputMouseClick;
    Tcl_InitObjHashTable(&infoPtr->windows);

    Tcl_SetAssocData(interp, GLMWFW_INTERP_DATA,
        (Tcl_InterpDeleteProc*)NULL, (ClientData)infoPtr);

    Tcl_Preserve((ClientData)infoPtr);

    Glmwfw_InitCommands(interp, infoPtr);

    glmwfwInit(infoPtr);
    Tcl_SetVar(interp, "::ntk::glmwfw::version", GLMWFW_VERSION,
            TCL_NAMESPACE_ONLY);
    Tcl_SetVar(interp, "::ntk::glmwfw::patchLevel", GLMWFW_PATCH_LEVEL,
            TCL_NAMESPACE_ONLY);

    /*
     *  Package is now loaded.
     */

    return Tcl_PkgProvideEx(interp, "Glmwfw", GLMWFW_VERSION, &glmwfwStubAPI);
}

/*
 * ------------------------------------------------------------------------
 *  Glmwfw_Init()
 *
 *  Invoked whenever a new INTERPRETER is created to install the
 *  glmwfw package.  Usually invoked within Tcl_AppInit() at
 *  the start of execution.
 *
 *  Creates the "::ntk::glmwfw" namespace and installs commands
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */

int
Glmwfw_Init (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }

    return  TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Glmwfw_SafeInit()
 *
 *  Invoked whenever a new SAFE INTERPRETER is created to install
 *  the glmwfw package.
 *
 *  Creates the "::ntk::glmwfw" namespace and installs access commands
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */

int
Glmwfw_SafeInit (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}
