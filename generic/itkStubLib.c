/*
 * itkStubLib.c --
 *
 *	Stub object that will be statically linked into extensions that wish
 *	to access Itk.
 *
 * Copyright (c) 1998-1999 by XXXX
 * Copyright (c) 1998 Paul Duffin.
 *
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 */

/*
 * We need to ensure that we use the stub macros so that this file contains
 * no references to any of the stub functions.  This will make it possible
 * to build an extension that references Tcl_InitStubs but doesn't end up
 * including the rest of the stub functions.
 */

#ifndef USE_TCL_STUBS
#define USE_TCL_STUBS
#endif
#undef USE_TCL_STUB_PROCS

#ifndef USE_ITK_STUBS
#define USE_ITK_STUBS 1
#endif
#undef USE_ITK_STUB_PROCS
#undef BUILD_itk

#include "itk.h"


/*
 *----------------------------------------------------------------------
 *
 * Itk_InitStubs --
 *
 *	Tries to initialise the stub table pointers and ensures that
 *	the correct version of Itk is loaded.
 *
 * Results:
 *	The actual version of Itk that satisfies the request, or
 *	NULL to indicate that an error occurred.
 *
 * Side effects:
 *	Sets the stub table pointers.
 *
 *----------------------------------------------------------------------
 */

const char *
Itk_InitStubs (
    Tcl_Interp *interp,
    const char *version,
    int exact)
{
    const char *actualVersion;

    actualVersion = Tcl_PkgRequireEx(interp, "itk", (const char *)version,
            exact, (ClientData *) &itkStubsPtr);
    if (actualVersion == NULL) {
	itkStubsPtr = NULL;
	return NULL;
    }

    return actualVersion;
}
