/*
 * ntkWidgetBase.c --
 *
 * This file contains the C-implemented startup part of a
 * Tcl interface for rendering widgets as bitmaps
 *
 * this is based on the megaimage package written by George Peter Staplin
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann and George Peter Staplin
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: ntkWidgetBase.c,v 1.1.2.2 2007/11/16 20:27:16 wiede Exp $
 */

#include <stdlib.h>
#include "ntkWidgetInt.h"

typedef struct NtkWidgetStubAPI {
int i;
} NtkWidgetStubAPI;

struct NtkWidgetStubAPI ntkWidgetStubAPI;

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
    NtkWidgetInfo *infoPtr;

    if (Tcl_InitStubs(interp, TCL_VERSION, 0) == NULL) {
        return TCL_ERROR;
    }

    nsPtr = Tcl_CreateNamespace(interp, NTK_WIDGET_NAMESPACE, NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("ntkGlWidget: cannot create namespace: \"%s\" \n",
	        NTK_WIDGET_NAMESPACE);
    }
    /*
     *  Create the top-level data structure for tracking objects.
     *  Store this as "associated data" for easy access, but link
     *  it to the itcl namespace for ownership.
     */
    infoPtr = (NtkWidgetInfo*)ckalloc(sizeof(NtkWidgetInfo));
    memset(infoPtr, 0, sizeof(NtkWidgetInfo));
    infoPtr->version = NTK_WIDGET_INFO_VERSION;
    Tcl_InitObjHashTable(&infoPtr->widgets);
    infoPtr->numWidgets = 0;

    Tcl_SetAssocData(interp, NTK_WIDGET_INTERP_DATA,
        (Tcl_InterpDeleteProc*)NULL, (ClientData)infoPtr);

    Tcl_Preserve((ClientData)infoPtr);

    NtkWidget_InitCommands(interp, infoPtr);
    if (NtkWidget_InitFreeType(interp, infoPtr) != TCL_OK) {
        return TCL_ERROR;
    }

    Tcl_SetVar(interp, "::ntk::widget::version", NTK_WIDGET_VERSION,
            TCL_NAMESPACE_ONLY);
    Tcl_SetVar(interp, "::ntk::widget::patchLevel", NTK_WIDGET_PATCH_LEVEL,
            TCL_NAMESPACE_ONLY);
    /*
     *  Package is now loaded.
     */

    return Tcl_PkgProvideEx(interp, "ntkWidget", NTK_WIDGET_VERSION, &ntkWidgetStubAPI);
}

/*
 * ------------------------------------------------------------------------
 *  Ntkwidget_Init()
 *
 *  Invoked whenever a new INTERPRETER is created to install the
 *  tclGlfw package.  Usually invoked within Tcl_AppInit() at
 *  the start of execution.
 *
 *  Creates the "::ntk::widget" namespace and installs commands
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */

int
Ntkwidget_Init (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }

    return  TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Ntkwidget_SafeInit()
 *
 *  Invoked whenever a new SAFE INTERPRETER is created to install
 *  the tclGlfw package.
 *
 *  Creates the "::ntk::widget" namespace and installs access commands
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */

int
Ntkwidget_SafeInit (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}
