/*
 * tclGLFWBase.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the GLFW OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLFWBase.c,v 1.1.2.1 2007/10/31 09:26:14 wiede Exp $
 */

#include <stdlib.h>
#include "tclGLFWInt.h"

typedef struct TclGLFWStubAPI {
int i;
} TclGLFWStubAPI;
struct TclGLFWStubAPI tclGLFWStubAPI;

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
    TclGLFWInfo *infoPtr;

    if (Tcl_InitStubs(interp, TCL_VERSION, 0) == NULL) {
        return TCL_ERROR;
    }

    nsPtr = Tcl_CreateNamespace(interp, TCL_GLFW_NAMESPACE, NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("tclGLFW: cannot create namespace: \"%s\" \n",
	        TCL_GLFW_NAMESPACE);
    }
    /*
     *  Create the top-level data structure for tracking objects.
     *  Store this as "associated data" for easy access, but link
     *  it to the itcl namespace for ownership.
     */
    infoPtr = (TclGLFWInfo*)ckalloc(sizeof(TclGLFWInfo));
    memset(infoPtr, 0, sizeof(TclGLFWInfo));
    infoPtr->version = TCL_GLFW_INFO_VERSION;
    infoPtr->numWindows = 0;
    Tcl_InitObjHashTable(&infoPtr->windowHandles);

    Tcl_SetAssocData(interp, TCL_GLFW_INTERP_DATA,
        (Tcl_InterpDeleteProc*)NULL, (ClientData)infoPtr);

    Tcl_Preserve((ClientData)infoPtr);

    TclGLFW_InitCommands(interp, infoPtr);

    glfwInit();
    int major, minor, rev;
    glfwGetVersion(&major, &minor, &rev);
fprintf(stderr, "GLFW version!%d!%d!%d!\n", major, minor, rev);

    Tcl_SetVar(interp, "::ntk::glfw::version", TCL_GLFW_VERSION,
            TCL_NAMESPACE_ONLY);
    Tcl_SetVar(interp, "::ntk::glfw::patchLevel", TCL_GLFW_PATCH_LEVEL,
            TCL_NAMESPACE_ONLY);

    /*
     *  Package is now loaded.
     */

    return Tcl_PkgProvideEx(interp, "TclGLFW", TCL_GLFW_VERSION, &tclGLFWStubAPI);
}

/*
 * ------------------------------------------------------------------------
 *  Tclglfw_Init()
 *
 *  Invoked whenever a new INTERPRETER is created to install the
 *  tclGLFW package.  Usually invoked within Tcl_AppInit() at
 *  the start of execution.
 *
 *  Creates the "::ntk::glfw" namespace and installs commands
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */

int
Tclglfw_Init (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }

    return  TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Tclglfw_SafeInit()
 *
 *  Invoked whenever a new SAFE INTERPRETER is created to install
 *  the tclGLFW package.
 *
 *  Creates the "::ntk::glfw" namespace and installs access commands
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */

int
Tclglfw_SafeInit (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}
