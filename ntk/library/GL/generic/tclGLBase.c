/*
 * tclGLBase.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLBase.c,v 1.1.2.2 2007/10/29 15:25:59 wiede Exp $
 */

#include <stdlib.h>
#include "tclGLInt.h"

typedef struct TclGLStubAPI {
int i;
} TclGLStubAPI;
struct TclGLStubAPI tclGLStubAPI;

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
    Tcl_Obj *objPtr;
    Tcl_HashEntry *hPtr;
    Tcl_Namespace *nsPtr;
    TclGLInfo *infoPtr;
    int isNew;

    if (Tcl_InitStubs(interp, TCL_VERSION, 0) == NULL) {
        return TCL_ERROR;
    }

    nsPtr = Tcl_CreateNamespace(interp, TCL_GL_NAMESPACE, NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("tclGlfw: cannot create namespace: \"%s\" \n",
	        TCL_GL_NAMESPACE);
    }
    /*
     *  Create the top-level data structure for tracking objects.
     *  Store this as "associated data" for easy access, but link
     *  it to the itcl namespace for ownership.
     */
    infoPtr = (TclGLInfo*)ckalloc(sizeof(TclGLInfo));
    memset(infoPtr, 0, sizeof(TclGLInfo));
    infoPtr->version = TCL_GL_INFO_VERSION;
#include "tclGLInitHashTables.c"

    Tcl_SetAssocData(interp, TCL_GL_INTERP_DATA,
        (Tcl_InterpDeleteProc*)NULL, (ClientData)infoPtr);

    Tcl_Preserve((ClientData)infoPtr);

    TclGL_InitCommands(interp, infoPtr);

// FIX ME !!!
//    int major, minor, rev;
//    glGetVersion(&major, &minor, &rev);
//fprintf(stderr, "GL version!%d!%d!%d!\n", major, minor, rev);

    Tcl_SetVar(interp, "::ntk::gl::version", TCL_GL_VERSION,
            TCL_NAMESPACE_ONLY);
    Tcl_SetVar(interp, "::ntk::gl::patchLevel", TCL_GL_PATCH_LEVEL,
            TCL_NAMESPACE_ONLY);
    /*
     *  Package is now loaded.
     */

    return Tcl_PkgProvideEx(interp, "TclGL", TCL_GL_VERSION, &tclGLStubAPI);
}

/*
 * ------------------------------------------------------------------------
 *  Tclgl_Init()
 *
 *  Invoked whenever a new INTERPRETER is created to install the
 *  tclGlfw package.  Usually invoked within Tcl_AppInit() at
 *  the start of execution.
 *
 *  Creates the "::ntk::gl" namespace and installs commands
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */

int
Tclgl_Init (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }

    return  TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Tclgl_SafeInit()
 *
 *  Invoked whenever a new SAFE INTERPRETER is created to install
 *  the tclGlfw package.
 *
 *  Creates the "::ntk::glfw" namespace and installs access commands
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */

int
Tclgl_SafeInit (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}
