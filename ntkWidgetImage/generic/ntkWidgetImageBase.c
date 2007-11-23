/*
 * ntkWidgetImageBase.c --
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
 * RCS: @(#) $Id: ntkWidgetImageBase.c,v 1.1.2.1 2007/11/23 18:06:47 wiede Exp $
 */

#include <stdlib.h>
#include "ntkWidgetImageInt.h"

typedef struct NtkWidgetImageStubAPI {
int i;
} NtkWidgetImageStubAPI;

struct NtkWidgetImageStubAPI ntkWidgetImageStubAPI;

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
    NtkWidgetImageInfo *infoPtr;

    if (Tcl_InitStubs(interp, TCL_VERSION, 0) == NULL) {
        return TCL_ERROR;
    }

    nsPtr = Tcl_CreateNamespace(interp, NTK_WIDGET_IMAGE_NAMESPACE, NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("ntkWidgetImage: cannot create namespace: \"%s\" \n",
	        NTK_WIDGET_IMAGE_NAMESPACE);
    }
    /*
     *  Create the top-level data structure for tracking objects.
     *  Store this as "associated data" for easy access, but link
     *  it to the itcl namespace for ownership.
     */
    infoPtr = (NtkWidgetImageInfo*)ckalloc(sizeof(NtkWidgetImageInfo));
    memset(infoPtr, 0, sizeof(NtkWidgetImageInfo));
    infoPtr->version = NTK_WIDGET_IMAGE_INFO_VERSION;
    Tcl_InitObjHashTable(&infoPtr->widgets);
    infoPtr->numWidgets = 0;

    Tcl_SetAssocData(interp, NTK_WIDGET_IMAGE_INTERP_DATA,
        (Tcl_InterpDeleteProc*)NULL, (ClientData)infoPtr);

    Tcl_Preserve((ClientData)infoPtr);

    NtkWidgetImage_InitCommands(interp, infoPtr);
    if (NtkWidgetImage_InitFreeType(interp, infoPtr) != TCL_OK) {
        return TCL_ERROR;
    }

    Tcl_SetVar(interp, "::ntk::widgetImage::version",
            NTK_WIDGET_IMAGE_VERSION, TCL_NAMESPACE_ONLY);
    Tcl_SetVar(interp, "::ntk::widgetImage::patchLevel",
            NTK_WIDGET_IMAGE_PATCH_LEVEL, TCL_NAMESPACE_ONLY);
    /*
     *  Package is now loaded.
     */

    return Tcl_PkgProvideEx(interp, "ntkWidgetImage",
            NTK_WIDGET_IMAGE_VERSION, &ntkWidgetImageStubAPI);
}

/*
 * ------------------------------------------------------------------------
 *  Ntkwidgetimage_Init()
 *
 *  Invoked whenever a new INTERPRETER is created to install the
 *  tclGlfw package.  Usually invoked within Tcl_AppInit() at
 *  the start of execution.
 *
 *  Creates the "::ntk::widgetImage" namespace and installs commands
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */

int
Ntkwidgetimage_Init (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }

    return  TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  Ntkwidgetimage_SafeInit()
 *
 *  Invoked whenever a new SAFE INTERPRETER is created to install
 *  the tclGlfw package.
 *
 *  Creates the "::ntk::widgetImage" namespace and installs access commands
 *
 *  Returns TCL_OK on success, or TCL_ERROR (along with an error
 *  message in the interpreter) if anything goes wrong.
 * ------------------------------------------------------------------------
 */

int
Ntkwidgetimage_SafeInit (
    Tcl_Interp *interp)
{
    if (Initialize(interp) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}
