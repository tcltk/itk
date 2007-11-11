/*
 * ntkGLWidgetBase.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: ntkGLWidgetBase.c,v 1.1.2.2 2007/11/11 11:46:31 wiede Exp $
 */

#include <stdlib.h>
#include "ntkGLWidgetInt.h"

typedef struct NtkGLWidgetStubAPI {
int i;
} NtkGLWidgetStubAPI;

struct NtkGLWidgetStubAPI ntkGLWidgetStubAPI;

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
    NtkGLWidgetInfo *infoPtr;

    if (Tcl_InitStubs(interp, TCL_VERSION, 0) == NULL) {
        return TCL_ERROR;
    }

    nsPtr = Tcl_CreateNamespace(interp, NTK_GL_WIDGET_NAMESPACE, NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("ntkGlWidget: cannot create namespace: \"%s\" \n",
	        NTK_GL_WIDGET_NAMESPACE);
    }
    /*
     *  Create the top-level data structure for tracking objects.
     *  Store this as "associated data" for easy access, but link
     *  it to the itcl namespace for ownership.
     */
    infoPtr = (NtkGLWidgetInfo*)ckalloc(sizeof(NtkGLWidgetInfo));
    memset(infoPtr, 0, sizeof(NtkGLWidgetInfo));
    infoPtr->version = NTK_GL_WIDGET_INFO_VERSION;

    Tcl_SetAssocData(interp, NTK_GL_WIDGET_INTERP_DATA,
        (Tcl_InterpDeleteProc*)NULL, (ClientData)infoPtr);

    Tcl_Preserve((ClientData)infoPtr);

    NtkGLWidget_InitCommands(interp, infoPtr);

    Tcl_SetVar(interp, "::ntk::glWidget::version", NTK_GL_WIDGET_VERSION,
            TCL_NAMESPACE_ONLY);
    Tcl_SetVar(interp, "::ntk::glWidget::patchLevel", NTK_GL_WIDGET_PATCH_LEVEL,
            TCL_NAMESPACE_ONLY);
    /*
     *  Package is now loaded.
     */

    return Tcl_PkgProvideEx(interp, "ntkGLWidget", NTK_GL_WIDGET_VERSION, &ntkGLWidgetStubAPI);
}

/*
 * ------------------------------------------------------------------------
 *  Ntkglwidget_Init()
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
Ntkglwidget_Init (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }

    return  TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Ntkglwidget_SafeInit()
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
Ntkglwidget_SafeInit (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}
