
/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBlendColorCmd()
 *
 *  Handles the OpenGL glBlendColor command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBlendColorCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    double param3;
    double param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBlendColorCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 455, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[455];
    ((GLfunction_void_float_float_float_float)funcPtr->funcPtr)((GLclampf)param1, (GLclampf)param2, (GLclampf)param3, (GLclampf)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBlendEquationCmd()
 *
 *  Handles the OpenGL glBlendEquation command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBlendEquationCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBlendEquationCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 456, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[456];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDrawRangeElementsCmd()
 *
 *  Handles the OpenGL glDrawRangeElements command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDrawRangeElementsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    void *param6;
    int paramLength6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDrawRangeElementsCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 457, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &param6, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[457];
    ((GLfunction_void_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLuint)param3, (GLsizei)param4, (GLenum)param5, (GLvoid*)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glColorTableCmd()
 *
 *  Handles the OpenGL glColorTable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glColorTableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    void *param6;
    int paramLength6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glColorTableCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 458, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &param6, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[458];
    ((GLfunction_void_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLsizei)param3, (GLenum)param4, (GLenum)param5, (GLvoid*)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glColorTableParameterfvCmd()
 *
 *  Handles the OpenGL glColorTableParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glColorTableParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glColorTableParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 459, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[459];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glColorTableParameterivCmd()
 *
 *  Handles the OpenGL glColorTableParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glColorTableParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glColorTableParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 460, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[460];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCopyColorTableCmd()
 *
 *  Handles the OpenGL glCopyColorTable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCopyColorTableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCopyColorTableCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 461, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[461];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint)param3, (GLint)param4, (GLsizei)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetColorTableCmd()
 *
 *  Handles the OpenGL glGetColorTable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetColorTableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4 = NULL;
    int paramLength4 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetColorTableCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 462, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[462];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLenum)param3, (GLvoid*)param4);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetColorTableParameterfvCmd()
 *
 *  Handles the OpenGL glGetColorTableParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetColorTableParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetColorTableParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 463, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[463];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetColorTableParameterivCmd()
 *
 *  Handles the OpenGL glGetColorTableParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetColorTableParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetColorTableParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 464, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[464];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glColorSubTableCmd()
 *
 *  Handles the OpenGL glColorSubTable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glColorSubTableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    void *param6;
    int paramLength6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glColorSubTableCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 465, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &param6, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[465];
    ((GLfunction_void_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLsizei)param2, (GLsizei)param3, (GLenum)param4, (GLenum)param5, (GLvoid*)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCopyColorSubTableCmd()
 *
 *  Handles the OpenGL glCopyColorSubTable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCopyColorSubTableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCopyColorSubTableCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 466, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[466];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLsizei)param2, (GLint)param3, (GLint)param4, (GLsizei)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glConvolutionFilter1DCmd()
 *
 *  Handles the OpenGL glConvolutionFilter1D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glConvolutionFilter1DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    void *param6;
    int paramLength6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glConvolutionFilter1DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 467, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &param6, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[467];
    ((GLfunction_void_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLsizei)param3, (GLenum)param4, (GLenum)param5, (GLvoid*)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glConvolutionFilter2DCmd()
 *
 *  Handles the OpenGL glConvolutionFilter2D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glConvolutionFilter2DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    void *param7;
    int paramLength7;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glConvolutionFilter2DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 468, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &param7, &paramLength7) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[468];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLsizei)param3, (GLsizei)param4, (GLenum)param5, (GLenum)param6, (GLvoid*)param7);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glConvolutionParameterfCmd()
 *
 *  Handles the OpenGL glConvolutionParameterf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glConvolutionParameterfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glConvolutionParameterfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 469, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[469];
    ((GLfunction_void_int_int_float)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glConvolutionParameterfvCmd()
 *
 *  Handles the OpenGL glConvolutionParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glConvolutionParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glConvolutionParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 470, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[470];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glConvolutionParameteriCmd()
 *
 *  Handles the OpenGL glConvolutionParameteri command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glConvolutionParameteriCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glConvolutionParameteriCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 471, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[471];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glConvolutionParameterivCmd()
 *
 *  Handles the OpenGL glConvolutionParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glConvolutionParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glConvolutionParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 472, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[472];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCopyConvolutionFilter1DCmd()
 *
 *  Handles the OpenGL glCopyConvolutionFilter1D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCopyConvolutionFilter1DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCopyConvolutionFilter1DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 473, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[473];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint)param3, (GLint)param4, (GLsizei)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCopyConvolutionFilter2DCmd()
 *
 *  Handles the OpenGL glCopyConvolutionFilter2D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCopyConvolutionFilter2DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCopyConvolutionFilter2DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 474, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[474];
    ((GLfunction_void_int_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint)param3, (GLint)param4, (GLsizei)param5, (GLsizei)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetConvolutionFilterCmd()
 *
 *  Handles the OpenGL glGetConvolutionFilter command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetConvolutionFilterCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4 = NULL;
    int paramLength4 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetConvolutionFilterCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 475, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[475];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLenum)param3, (GLvoid*)param4);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetConvolutionParameterfvCmd()
 *
 *  Handles the OpenGL glGetConvolutionParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetConvolutionParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetConvolutionParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 476, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[476];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetConvolutionParameterivCmd()
 *
 *  Handles the OpenGL glGetConvolutionParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetConvolutionParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetConvolutionParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 477, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[477];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetSeparableFilterCmd()
 *
 *  Handles the OpenGL glGetSeparableFilter command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetSeparableFilterCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4 = NULL;
    int paramLength4 = 0;
    void *param5 = NULL;
    int paramLength5 = 0;
    void *param6 = NULL;
    int paramLength6 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetSeparableFilterCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 478, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[478];
    ((GLfunction_void_int_int_int_voidPtr_voidPtr_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLenum)param3, (GLvoid*)param4, (GLvoid*)param5, (GLvoid*)param6);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[5], paramLength5, param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[6], paramLength6, param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSeparableFilter2DCmd()
 *
 *  Handles the OpenGL glSeparableFilter2D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSeparableFilter2DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    void *param7;
    int paramLength7;
    void *param8;
    int paramLength8;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSeparableFilter2DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 479, objc, 8) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &param7, &paramLength7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[8], &param8, &paramLength8) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[479];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLsizei)param3, (GLsizei)param4, (GLenum)param5, (GLenum)param6, (GLvoid*)param7, (GLvoid*)param8);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetHistogramCmd()
 *
 *  Handles the OpenGL glGetHistogram command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetHistogramCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    void *param5 = NULL;
    int paramLength5 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetHistogramCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 480, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[480];
    ((GLfunction_void_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLboolean)param2, (GLenum)param3, (GLenum)param4, (GLvoid*)param5);
    if (SetPtrOutParam(interp, infoPtr, objv[5], paramLength5, param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetHistogramParameterfvCmd()
 *
 *  Handles the OpenGL glGetHistogramParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetHistogramParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetHistogramParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 481, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[481];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetHistogramParameterivCmd()
 *
 *  Handles the OpenGL glGetHistogramParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetHistogramParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetHistogramParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 482, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[482];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetMinmaxCmd()
 *
 *  Handles the OpenGL glGetMinmax command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetMinmaxCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    void *param5 = NULL;
    int paramLength5 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetMinmaxCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 483, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[483];
    ((GLfunction_void_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLboolean)param2, (GLenum)param3, (GLenum)param4, (GLvoid*)param5);
    if (SetPtrOutParam(interp, infoPtr, objv[5], paramLength5, param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetMinmaxParameterfvCmd()
 *
 *  Handles the OpenGL glGetMinmaxParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetMinmaxParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetMinmaxParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 484, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[484];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetMinmaxParameterivCmd()
 *
 *  Handles the OpenGL glGetMinmaxParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetMinmaxParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetMinmaxParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 485, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[485];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glHistogramCmd()
 *
 *  Handles the OpenGL glHistogram command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glHistogramCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glHistogramCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 486, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[486];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLsizei)param2, (GLenum)param3, (GLboolean)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMinmaxCmd()
 *
 *  Handles the OpenGL glMinmax command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMinmaxCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMinmaxCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 487, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[487];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLboolean)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glResetHistogramCmd()
 *
 *  Handles the OpenGL glResetHistogram command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glResetHistogramCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glResetHistogramCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 488, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[488];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glResetMinmaxCmd()
 *
 *  Handles the OpenGL glResetMinmax command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glResetMinmaxCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glResetMinmaxCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 489, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[489];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTexImage3DCmd()
 *
 *  Handles the OpenGL glTexImage3D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTexImage3DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    int param9;
    void *param10;
    int paramLength10;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTexImage3DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 490, objc, 10) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[9], &param9) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[10], &param10, &paramLength10) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[490];
    ((GLfunction_void_int_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLsizei)param4, (GLsizei)param5, (GLsizei)param6, (GLint)param7, (GLenum)param8, (GLenum)param9, (GLvoid*)param10);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTexSubImage3DCmd()
 *
 *  Handles the OpenGL glTexSubImage3D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTexSubImage3DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    int param9;
    int param10;
    void *param11;
    int paramLength11;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTexSubImage3DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 491, objc, 11) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[9], &param9) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[10], &param10) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[11], &param11, &paramLength11) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[491];
    ((GLfunction_void_int_int_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4, (GLint)param5, (GLsizei)param6, (GLsizei)param7, (GLsizei)param8, (GLenum)param9, (GLenum)param10, (GLvoid*)param11);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCopyTexSubImage3DCmd()
 *
 *  Handles the OpenGL glCopyTexSubImage3D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCopyTexSubImage3DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    int param9;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCopyTexSubImage3DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 492, objc, 9) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[9], &param9) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[492];
    ((GLfunction_void_int_int_int_int_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4, (GLint)param5, (GLint)param6, (GLint)param7, (GLsizei)param8, (GLsizei)param9);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glActiveTextureCmd()
 *
 *  Handles the OpenGL glActiveTexture command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glActiveTextureCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glActiveTextureCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 493, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[493];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glClientActiveTextureCmd()
 *
 *  Handles the OpenGL glClientActiveTexture command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glClientActiveTextureCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glClientActiveTextureCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 494, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[494];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1dCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 495, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[495];
    ((GLfunction_void_int_double)funcPtr->funcPtr)((GLenum)param1, (GLdouble)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1dvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 496, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[496];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLdouble*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1fCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 497, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[497];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLenum)param1, (GLfloat)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1fvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 498, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[498];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1iCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 499, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[499];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1ivCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 500, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[500];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1sCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 501, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[501];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)param1, (GLshort)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1svCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 502, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[502];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2dCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 503, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[503];
    ((GLfunction_void_int_double_double)funcPtr->funcPtr)((GLenum)param1, (GLdouble)param2, (GLdouble)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2dvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 504, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[504];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLdouble*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2fCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 505, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[505];
    ((GLfunction_void_int_float_float)funcPtr->funcPtr)((GLenum)param1, (GLfloat)param2, (GLfloat)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2fvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 506, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[506];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2iCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 507, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[507];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2ivCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 508, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[508];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2sCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 509, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[509];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLshort)param2, (GLshort)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2svCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 510, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[510];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3dCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    double param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 511, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[511];
    ((GLfunction_void_int_double_double_double)funcPtr->funcPtr)((GLenum)param1, (GLdouble)param2, (GLdouble)param3, (GLdouble)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3dvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 512, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[512];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLdouble*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3fCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    double param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 513, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[513];
    ((GLfunction_void_int_float_float_float)funcPtr->funcPtr)((GLenum)param1, (GLfloat)param2, (GLfloat)param3, (GLfloat)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3fvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 514, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[514];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3iCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 515, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[515];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3ivCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 516, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[516];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3sCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 517, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[517];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLshort)param2, (GLshort)param3, (GLshort)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3svCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 518, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[518];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4dCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    double param4;
    double param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 519, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[519];
    ((GLfunction_void_int_double_double_double_double)funcPtr->funcPtr)((GLenum)param1, (GLdouble)param2, (GLdouble)param3, (GLdouble)param4, (GLdouble)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4dvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 520, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[520];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLdouble*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4fCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    double param4;
    double param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 521, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[521];
    ((GLfunction_void_int_float_float_float_float)funcPtr->funcPtr)((GLenum)param1, (GLfloat)param2, (GLfloat)param3, (GLfloat)param4, (GLfloat)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4fvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 522, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[522];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4iCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 523, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[523];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4, (GLint)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4ivCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 524, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[524];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4sCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 525, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[525];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLshort)param2, (GLshort)param3, (GLshort)param4, (GLshort)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4svCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 526, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[526];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glLoadTransposeMatrixfCmd()
 *
 *  Handles the OpenGL glLoadTransposeMatrixf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glLoadTransposeMatrixfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glLoadTransposeMatrixfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 527, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[527];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glLoadTransposeMatrixdCmd()
 *
 *  Handles the OpenGL glLoadTransposeMatrixd command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glLoadTransposeMatrixdCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glLoadTransposeMatrixdCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 528, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[528];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultTransposeMatrixfCmd()
 *
 *  Handles the OpenGL glMultTransposeMatrixf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultTransposeMatrixfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultTransposeMatrixfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 529, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[529];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultTransposeMatrixdCmd()
 *
 *  Handles the OpenGL glMultTransposeMatrixd command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultTransposeMatrixdCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultTransposeMatrixdCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 530, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[530];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSampleCoverageCmd()
 *
 *  Handles the OpenGL glSampleCoverage command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSampleCoverageCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSampleCoverageCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 531, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[531];
    ((GLfunction_void_float_int)funcPtr->funcPtr)((GLclampf)param1, (GLboolean)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCompressedTexImage3DCmd()
 *
 *  Handles the OpenGL glCompressedTexImage3D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCompressedTexImage3DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    void *param9;
    int paramLength9;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCompressedTexImage3DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 532, objc, 9) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[9], &param9, &paramLength9) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[532];
    ((GLfunction_void_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLenum)param3, (GLsizei)param4, (GLsizei)param5, (GLsizei)param6, (GLint)param7, (GLsizei)param8, (GLvoid*)param9);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCompressedTexImage2DCmd()
 *
 *  Handles the OpenGL glCompressedTexImage2D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCompressedTexImage2DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    void *param8;
    int paramLength8;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCompressedTexImage2DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 533, objc, 8) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[8], &param8, &paramLength8) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[533];
    ((GLfunction_void_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLenum)param3, (GLsizei)param4, (GLsizei)param5, (GLint)param6, (GLsizei)param7, (GLvoid*)param8);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCompressedTexImage1DCmd()
 *
 *  Handles the OpenGL glCompressedTexImage1D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCompressedTexImage1DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    void *param7;
    int paramLength7;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCompressedTexImage1DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 534, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &param7, &paramLength7) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[534];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLenum)param3, (GLsizei)param4, (GLint)param5, (GLsizei)param6, (GLvoid*)param7);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCompressedTexSubImage3DCmd()
 *
 *  Handles the OpenGL glCompressedTexSubImage3D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCompressedTexSubImage3DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    int param9;
    int param10;
    void *param11;
    int paramLength11;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCompressedTexSubImage3DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 535, objc, 11) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[9], &param9) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[10], &param10) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[11], &param11, &paramLength11) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[535];
    ((GLfunction_void_int_int_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4, (GLint)param5, (GLsizei)param6, (GLsizei)param7, (GLsizei)param8, (GLenum)param9, (GLsizei)param10, (GLvoid*)param11);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCompressedTexSubImage2DCmd()
 *
 *  Handles the OpenGL glCompressedTexSubImage2D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCompressedTexSubImage2DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    void *param9;
    int paramLength9;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCompressedTexSubImage2DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 536, objc, 9) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[9], &param9, &paramLength9) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[536];
    ((GLfunction_void_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4, (GLsizei)param5, (GLsizei)param6, (GLenum)param7, (GLsizei)param8, (GLvoid*)param9);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCompressedTexSubImage1DCmd()
 *
 *  Handles the OpenGL glCompressedTexSubImage1D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCompressedTexSubImage1DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    void *param7;
    int paramLength7;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCompressedTexSubImage1DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 537, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &param7, &paramLength7) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[537];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLsizei)param4, (GLenum)param5, (GLsizei)param6, (GLvoid*)param7);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetCompressedTexImageCmd()
 *
 *  Handles the OpenGL glGetCompressedTexImage command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetCompressedTexImageCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetCompressedTexImageCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 538, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[538];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLvoid*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBlendFuncSeparateCmd()
 *
 *  Handles the OpenGL glBlendFuncSeparate command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBlendFuncSeparateCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBlendFuncSeparateCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 539, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[539];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLenum)param3, (GLenum)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glFogCoordfCmd()
 *
 *  Handles the OpenGL glFogCoordf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glFogCoordfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glFogCoordfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 540, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[540];
    ((GLfunction_void_float)funcPtr->funcPtr)((GLfloat)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glFogCoordfvCmd()
 *
 *  Handles the OpenGL glFogCoordfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glFogCoordfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glFogCoordfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 541, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[541];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glFogCoorddCmd()
 *
 *  Handles the OpenGL glFogCoordd command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glFogCoorddCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glFogCoorddCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 542, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[542];
    ((GLfunction_void_double)funcPtr->funcPtr)((GLdouble)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glFogCoorddvCmd()
 *
 *  Handles the OpenGL glFogCoorddv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glFogCoorddvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glFogCoorddvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 543, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[543];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glFogCoordPointerCmd()
 *
 *  Handles the OpenGL glFogCoordPointer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glFogCoordPointerCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glFogCoordPointerCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 544, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[544];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLsizei)param2, (GLvoid*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiDrawArraysCmd()
 *
 *  Handles the OpenGL glMultiDrawArrays command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiDrawArraysCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2 = NULL;
    int paramLength2 = 0;
    void *param3 = NULL;
    int paramLength3 = 0;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiDrawArraysCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 545, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[545];
    ((GLfunction_void_int_voidPtr_voidPtr_int)funcPtr->funcPtr)((GLenum)param1, (GLint*)param2, (GLsizei*)param3, (GLsizei)param4);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength2, param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiDrawElementsCmd()
 *
 *  Handles the OpenGL glMultiDrawElements command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiDrawElementsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    int param3;
    void **param4;
    int paramLength4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiDrawElementsCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 546, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[546];
    ((GLfunction_void_int_voidPtr_int_voidPtrPtr_int)funcPtr->funcPtr)((GLenum)param1, (GLsizei*)param2, (GLenum)param3, (GLvoid**)param4, (GLsizei)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glPointParameterfCmd()
 *
 *  Handles the OpenGL glPointParameterf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glPointParameterfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glPointParameterfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 547, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[547];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLenum)param1, (GLfloat)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glPointParameterfvCmd()
 *
 *  Handles the OpenGL glPointParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glPointParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glPointParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 548, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[548];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glPointParameteriCmd()
 *
 *  Handles the OpenGL glPointParameteri command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glPointParameteriCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glPointParameteriCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 549, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[549];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glPointParameterivCmd()
 *
 *  Handles the OpenGL glPointParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glPointParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glPointParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 550, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[550];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3bCmd()
 *
 *  Handles the OpenGL glSecondaryColor3b command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3bCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3bCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 551, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[551];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLbyte)param1, (GLbyte)param2, (GLbyte)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3bvCmd()
 *
 *  Handles the OpenGL glSecondaryColor3bv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3bvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3bvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 552, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[552];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLbyte*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3dCmd()
 *
 *  Handles the OpenGL glSecondaryColor3d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 553, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[553];
    ((GLfunction_void_double_double_double)funcPtr->funcPtr)((GLdouble)param1, (GLdouble)param2, (GLdouble)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3dvCmd()
 *
 *  Handles the OpenGL glSecondaryColor3dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 554, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[554];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3fCmd()
 *
 *  Handles the OpenGL glSecondaryColor3f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 555, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[555];
    ((GLfunction_void_float_float_float)funcPtr->funcPtr)((GLfloat)param1, (GLfloat)param2, (GLfloat)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3fvCmd()
 *
 *  Handles the OpenGL glSecondaryColor3fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 556, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[556];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3iCmd()
 *
 *  Handles the OpenGL glSecondaryColor3i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 557, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[557];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLint)param1, (GLint)param2, (GLint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3ivCmd()
 *
 *  Handles the OpenGL glSecondaryColor3iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 558, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[558];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3sCmd()
 *
 *  Handles the OpenGL glSecondaryColor3s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 559, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[559];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLshort)param1, (GLshort)param2, (GLshort)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3svCmd()
 *
 *  Handles the OpenGL glSecondaryColor3sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 560, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[560];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3ubCmd()
 *
 *  Handles the OpenGL glSecondaryColor3ub command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3ubCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3ubCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 561, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[561];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLubyte)param1, (GLubyte)param2, (GLubyte)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3ubvCmd()
 *
 *  Handles the OpenGL glSecondaryColor3ubv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3ubvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3ubvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 562, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[562];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLubyte*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3uiCmd()
 *
 *  Handles the OpenGL glSecondaryColor3ui command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3uiCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3uiCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 563, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[563];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLuint)param1, (GLuint)param2, (GLuint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3uivCmd()
 *
 *  Handles the OpenGL glSecondaryColor3uiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3uivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3uivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 564, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[564];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLuint*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3usCmd()
 *
 *  Handles the OpenGL glSecondaryColor3us command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3usCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3usCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 565, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[565];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLushort)param1, (GLushort)param2, (GLushort)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3usvCmd()
 *
 *  Handles the OpenGL glSecondaryColor3usv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3usvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3usvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 566, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[566];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLushort*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColorPointerCmd()
 *
 *  Handles the OpenGL glSecondaryColorPointer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColorPointerCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColorPointerCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 567, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[567];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLenum)param2, (GLsizei)param3, (GLvoid*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2dCmd()
 *
 *  Handles the OpenGL glWindowPos2d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 568, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[568];
    ((GLfunction_void_double_double)funcPtr->funcPtr)((GLdouble)param1, (GLdouble)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2dvCmd()
 *
 *  Handles the OpenGL glWindowPos2dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 569, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[569];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2fCmd()
 *
 *  Handles the OpenGL glWindowPos2f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 570, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[570];
    ((GLfunction_void_float_float)funcPtr->funcPtr)((GLfloat)param1, (GLfloat)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2fvCmd()
 *
 *  Handles the OpenGL glWindowPos2fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 571, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[571];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2iCmd()
 *
 *  Handles the OpenGL glWindowPos2i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 572, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[572];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLint)param1, (GLint)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2ivCmd()
 *
 *  Handles the OpenGL glWindowPos2iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 573, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[573];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2sCmd()
 *
 *  Handles the OpenGL glWindowPos2s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 574, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[574];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLshort)param1, (GLshort)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2svCmd()
 *
 *  Handles the OpenGL glWindowPos2sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 575, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[575];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3dCmd()
 *
 *  Handles the OpenGL glWindowPos3d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 576, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[576];
    ((GLfunction_void_double_double_double)funcPtr->funcPtr)((GLdouble)param1, (GLdouble)param2, (GLdouble)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3dvCmd()
 *
 *  Handles the OpenGL glWindowPos3dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 577, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[577];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3fCmd()
 *
 *  Handles the OpenGL glWindowPos3f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 578, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[578];
    ((GLfunction_void_float_float_float)funcPtr->funcPtr)((GLfloat)param1, (GLfloat)param2, (GLfloat)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3fvCmd()
 *
 *  Handles the OpenGL glWindowPos3fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 579, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[579];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3iCmd()
 *
 *  Handles the OpenGL glWindowPos3i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 580, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[580];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLint)param1, (GLint)param2, (GLint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3ivCmd()
 *
 *  Handles the OpenGL glWindowPos3iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 581, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[581];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3sCmd()
 *
 *  Handles the OpenGL glWindowPos3s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 582, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[582];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLshort)param1, (GLshort)param2, (GLshort)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3svCmd()
 *
 *  Handles the OpenGL glWindowPos3sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 583, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[583];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGenQueriesCmd()
 *
 *  Handles the OpenGL glGenQueries command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGenQueriesCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2 = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGenQueriesCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 584, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[584];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLuint*)param2);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength2, param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDeleteQueriesCmd()
 *
 *  Handles the OpenGL glDeleteQueries command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDeleteQueriesCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDeleteQueriesCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 585, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[585];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLuint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glIsQueryCmd()
 *
 *  Handles the OpenGL glIsQuery command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glIsQueryCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;
     GLboolean retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glIsQueryCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 586, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[586];
    retVal = ((GLfunction_GLboolean_int)funcPtr->funcPtr)((GLuint)param1);
    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBeginQueryCmd()
 *
 *  Handles the OpenGL glBeginQuery command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBeginQueryCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBeginQueryCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 587, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[587];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glEndQueryCmd()
 *
 *  Handles the OpenGL glEndQuery command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glEndQueryCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glEndQueryCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 588, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[588];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetQueryivCmd()
 *
 *  Handles the OpenGL glGetQueryiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetQueryivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetQueryivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 589, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[589];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetQueryObjectivCmd()
 *
 *  Handles the OpenGL glGetQueryObjectiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetQueryObjectivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetQueryObjectivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 590, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[590];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetQueryObjectuivCmd()
 *
 *  Handles the OpenGL glGetQueryObjectuiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetQueryObjectuivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetQueryObjectuivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 591, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[591];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLuint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBindBufferCmd()
 *
 *  Handles the OpenGL glBindBuffer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBindBufferCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBindBufferCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 592, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[592];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDeleteBuffersCmd()
 *
 *  Handles the OpenGL glDeleteBuffers command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDeleteBuffersCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDeleteBuffersCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 593, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[593];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLuint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGenBuffersCmd()
 *
 *  Handles the OpenGL glGenBuffers command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGenBuffersCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2 = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGenBuffersCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 594, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[594];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLuint*)param2);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength2, param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glIsBufferCmd()
 *
 *  Handles the OpenGL glIsBuffer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glIsBufferCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;
     GLboolean retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glIsBufferCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 595, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[595];
    retVal = ((GLfunction_GLboolean_int)funcPtr->funcPtr)((GLuint)param1);
    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBufferDataCmd()
 *
 *  Handles the OpenGL glBufferData command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBufferDataCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBufferDataCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 596, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[596];
    ((GLfunction_void_int_int_voidPtr_int)funcPtr->funcPtr)((GLenum)param1, (GLsizeiptr)param2, (GLvoid*)param3, (GLenum)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBufferSubDataCmd()
 *
 *  Handles the OpenGL glBufferSubData command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBufferSubDataCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBufferSubDataCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 597, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[597];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLintptr)param2, (GLsizeiptr)param3, (GLvoid*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetBufferSubDataCmd()
 *
 *  Handles the OpenGL glGetBufferSubData command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetBufferSubDataCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4 = NULL;
    int paramLength4 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetBufferSubDataCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 598, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[598];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLintptr)param2, (GLsizeiptr)param3, (GLvoid*)param4);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMapBufferCmd()
 *
 *  Handles the OpenGL glMapBuffer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMapBufferCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMapBufferCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 599, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[599];
    ((GLfunction_GLvoid_star_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUnmapBufferCmd()
 *
 *  Handles the OpenGL glUnmapBuffer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUnmapBufferCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;
     GLboolean retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUnmapBufferCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 600, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[600];
    retVal = ((GLfunction_GLboolean_int)funcPtr->funcPtr)((GLenum)param1);
    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetBufferParameterivCmd()
 *
 *  Handles the OpenGL glGetBufferParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetBufferParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetBufferParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 601, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[601];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetBufferPointervCmd()
 *
 *  Handles the OpenGL glGetBufferPointerv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetBufferPointervCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void **param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetBufferPointervCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 602, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[602];
    ((GLfunction_void_int_int_voidPtrPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLvoid**)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glActiveTextureARBCmd()
 *
 *  Handles the OpenGL glActiveTextureARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glActiveTextureARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glActiveTextureARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 603, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[603];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glClientActiveTextureARBCmd()
 *
 *  Handles the OpenGL glClientActiveTextureARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glClientActiveTextureARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glClientActiveTextureARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 604, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[604];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1dARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 605, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[605];
    ((GLfunction_void_int_double)funcPtr->funcPtr)((GLenum)param1, (GLdouble)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1dvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 606, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[606];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLdouble*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1fARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 607, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[607];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLenum)param1, (GLfloat)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1fvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 608, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[608];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1iARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1iARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1iARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1iARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 609, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[609];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1ivARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 610, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[610];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1sARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1sARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1sARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1sARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 611, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[611];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)param1, (GLshort)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord1svARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1svARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord1svARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord1svARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 612, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[612];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2dARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 613, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[613];
    ((GLfunction_void_int_double_double)funcPtr->funcPtr)((GLenum)param1, (GLdouble)param2, (GLdouble)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2dvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 614, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[614];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLdouble*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2fARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 615, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[615];
    ((GLfunction_void_int_float_float)funcPtr->funcPtr)((GLenum)param1, (GLfloat)param2, (GLfloat)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2fvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 616, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[616];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2iARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2iARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2iARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2iARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 617, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[617];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2ivARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 618, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[618];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2sARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2sARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2sARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2sARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 619, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[619];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLshort)param2, (GLshort)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord2svARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2svARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord2svARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord2svARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 620, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[620];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3dARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    double param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 621, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[621];
    ((GLfunction_void_int_double_double_double)funcPtr->funcPtr)((GLenum)param1, (GLdouble)param2, (GLdouble)param3, (GLdouble)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3dvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 622, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[622];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLdouble*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3fARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    double param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 623, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[623];
    ((GLfunction_void_int_float_float_float)funcPtr->funcPtr)((GLenum)param1, (GLfloat)param2, (GLfloat)param3, (GLfloat)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3fvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 624, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[624];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3iARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3iARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3iARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3iARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 625, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[625];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3ivARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 626, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[626];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3sARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3sARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3sARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3sARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 627, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[627];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLshort)param2, (GLshort)param3, (GLshort)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord3svARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3svARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord3svARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord3svARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 628, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[628];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4dARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    double param4;
    double param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 629, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[629];
    ((GLfunction_void_int_double_double_double_double)funcPtr->funcPtr)((GLenum)param1, (GLdouble)param2, (GLdouble)param3, (GLdouble)param4, (GLdouble)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4dvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 630, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[630];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLdouble*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4fARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    double param4;
    double param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 631, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[631];
    ((GLfunction_void_int_float_float_float_float)funcPtr->funcPtr)((GLenum)param1, (GLfloat)param2, (GLfloat)param3, (GLfloat)param4, (GLfloat)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4fvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 632, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[632];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4iARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4iARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4iARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4iARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 633, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[633];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4, (GLint)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4ivARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 634, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[634];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4sARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4sARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4sARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4sARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 635, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[635];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLshort)param2, (GLshort)param3, (GLshort)param4, (GLshort)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiTexCoord4svARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4svARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiTexCoord4svARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiTexCoord4svARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 636, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[636];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glLoadTransposeMatrixfARBCmd()
 *
 *  Handles the OpenGL glLoadTransposeMatrixfARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glLoadTransposeMatrixfARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glLoadTransposeMatrixfARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 637, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[637];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glLoadTransposeMatrixdARBCmd()
 *
 *  Handles the OpenGL glLoadTransposeMatrixdARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glLoadTransposeMatrixdARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glLoadTransposeMatrixdARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 638, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[638];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultTransposeMatrixfARBCmd()
 *
 *  Handles the OpenGL glMultTransposeMatrixfARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultTransposeMatrixfARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultTransposeMatrixfARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 639, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[639];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultTransposeMatrixdARBCmd()
 *
 *  Handles the OpenGL glMultTransposeMatrixdARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultTransposeMatrixdARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultTransposeMatrixdARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 640, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[640];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSampleCoverageARBCmd()
 *
 *  Handles the OpenGL glSampleCoverageARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSampleCoverageARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSampleCoverageARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 641, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[641];
    ((GLfunction_void_float_int)funcPtr->funcPtr)((GLclampf)param1, (GLboolean)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCompressedTexImage3DARBCmd()
 *
 *  Handles the OpenGL glCompressedTexImage3DARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCompressedTexImage3DARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    void *param9;
    int paramLength9;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCompressedTexImage3DARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 642, objc, 9) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[9], &param9, &paramLength9) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[642];
    ((GLfunction_void_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLenum)param3, (GLsizei)param4, (GLsizei)param5, (GLsizei)param6, (GLint)param7, (GLsizei)param8, (GLvoid*)param9);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCompressedTexImage2DARBCmd()
 *
 *  Handles the OpenGL glCompressedTexImage2DARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCompressedTexImage2DARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    void *param8;
    int paramLength8;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCompressedTexImage2DARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 643, objc, 8) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[8], &param8, &paramLength8) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[643];
    ((GLfunction_void_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLenum)param3, (GLsizei)param4, (GLsizei)param5, (GLint)param6, (GLsizei)param7, (GLvoid*)param8);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCompressedTexImage1DARBCmd()
 *
 *  Handles the OpenGL glCompressedTexImage1DARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCompressedTexImage1DARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    void *param7;
    int paramLength7;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCompressedTexImage1DARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 644, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &param7, &paramLength7) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[644];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLenum)param3, (GLsizei)param4, (GLint)param5, (GLsizei)param6, (GLvoid*)param7);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCompressedTexSubImage3DARBCmd()
 *
 *  Handles the OpenGL glCompressedTexSubImage3DARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCompressedTexSubImage3DARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    int param9;
    int param10;
    void *param11;
    int paramLength11;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCompressedTexSubImage3DARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 645, objc, 11) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[9], &param9) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[10], &param10) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[11], &param11, &paramLength11) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[645];
    ((GLfunction_void_int_int_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4, (GLint)param5, (GLsizei)param6, (GLsizei)param7, (GLsizei)param8, (GLenum)param9, (GLsizei)param10, (GLvoid*)param11);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCompressedTexSubImage2DARBCmd()
 *
 *  Handles the OpenGL glCompressedTexSubImage2DARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCompressedTexSubImage2DARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    void *param9;
    int paramLength9;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCompressedTexSubImage2DARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 646, objc, 9) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[9], &param9, &paramLength9) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[646];
    ((GLfunction_void_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4, (GLsizei)param5, (GLsizei)param6, (GLenum)param7, (GLsizei)param8, (GLvoid*)param9);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCompressedTexSubImage1DARBCmd()
 *
 *  Handles the OpenGL glCompressedTexSubImage1DARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCompressedTexSubImage1DARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    void *param7;
    int paramLength7;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCompressedTexSubImage1DARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 647, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &param7, &paramLength7) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[647];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLsizei)param4, (GLenum)param5, (GLsizei)param6, (GLvoid*)param7);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetCompressedTexImageARBCmd()
 *
 *  Handles the OpenGL glGetCompressedTexImageARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetCompressedTexImageARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetCompressedTexImageARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 648, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[648];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLvoid*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glPointParameterfARBCmd()
 *
 *  Handles the OpenGL glPointParameterfARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glPointParameterfARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glPointParameterfARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 649, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[649];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLenum)param1, (GLfloat)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glPointParameterfvARBCmd()
 *
 *  Handles the OpenGL glPointParameterfvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glPointParameterfvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glPointParameterfvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 650, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[650];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWeightbvARBCmd()
 *
 *  Handles the OpenGL glWeightbvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWeightbvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWeightbvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 651, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[651];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLbyte*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWeightsvARBCmd()
 *
 *  Handles the OpenGL glWeightsvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWeightsvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWeightsvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 652, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[652];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWeightivARBCmd()
 *
 *  Handles the OpenGL glWeightivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWeightivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWeightivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 653, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[653];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWeightfvARBCmd()
 *
 *  Handles the OpenGL glWeightfvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWeightfvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWeightfvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 654, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[654];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWeightdvARBCmd()
 *
 *  Handles the OpenGL glWeightdvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWeightdvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWeightdvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 655, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[655];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLdouble*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWeightubvARBCmd()
 *
 *  Handles the OpenGL glWeightubvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWeightubvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWeightubvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 656, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[656];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLubyte*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWeightusvARBCmd()
 *
 *  Handles the OpenGL glWeightusvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWeightusvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWeightusvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 657, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[657];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLushort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWeightuivARBCmd()
 *
 *  Handles the OpenGL glWeightuivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWeightuivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWeightuivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 658, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[658];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLuint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWeightPointerARBCmd()
 *
 *  Handles the OpenGL glWeightPointerARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWeightPointerARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWeightPointerARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 659, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[659];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLenum)param2, (GLsizei)param3, (GLvoid*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexBlendARBCmd()
 *
 *  Handles the OpenGL glVertexBlendARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexBlendARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexBlendARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 660, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[660];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLint)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCurrentPaletteMatrixARBCmd()
 *
 *  Handles the OpenGL glCurrentPaletteMatrixARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCurrentPaletteMatrixARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCurrentPaletteMatrixARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 661, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[661];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLint)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMatrixIndexubvARBCmd()
 *
 *  Handles the OpenGL glMatrixIndexubvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMatrixIndexubvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMatrixIndexubvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 662, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[662];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLubyte*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMatrixIndexusvARBCmd()
 *
 *  Handles the OpenGL glMatrixIndexusvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMatrixIndexusvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMatrixIndexusvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 663, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[663];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLushort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMatrixIndexuivARBCmd()
 *
 *  Handles the OpenGL glMatrixIndexuivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMatrixIndexuivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMatrixIndexuivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 664, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[664];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLuint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMatrixIndexPointerARBCmd()
 *
 *  Handles the OpenGL glMatrixIndexPointerARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMatrixIndexPointerARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMatrixIndexPointerARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 665, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[665];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLenum)param2, (GLsizei)param3, (GLvoid*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2dARBCmd()
 *
 *  Handles the OpenGL glWindowPos2dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 666, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[666];
    ((GLfunction_void_double_double)funcPtr->funcPtr)((GLdouble)param1, (GLdouble)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2dvARBCmd()
 *
 *  Handles the OpenGL glWindowPos2dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 667, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[667];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2fARBCmd()
 *
 *  Handles the OpenGL glWindowPos2fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 668, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[668];
    ((GLfunction_void_float_float)funcPtr->funcPtr)((GLfloat)param1, (GLfloat)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2fvARBCmd()
 *
 *  Handles the OpenGL glWindowPos2fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 669, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[669];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2iARBCmd()
 *
 *  Handles the OpenGL glWindowPos2iARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2iARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2iARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 670, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[670];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLint)param1, (GLint)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2ivARBCmd()
 *
 *  Handles the OpenGL glWindowPos2ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 671, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[671];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2sARBCmd()
 *
 *  Handles the OpenGL glWindowPos2sARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2sARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2sARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 672, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[672];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLshort)param1, (GLshort)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos2svARBCmd()
 *
 *  Handles the OpenGL glWindowPos2svARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos2svARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos2svARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 673, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[673];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3dARBCmd()
 *
 *  Handles the OpenGL glWindowPos3dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 674, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[674];
    ((GLfunction_void_double_double_double)funcPtr->funcPtr)((GLdouble)param1, (GLdouble)param2, (GLdouble)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3dvARBCmd()
 *
 *  Handles the OpenGL glWindowPos3dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 675, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[675];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3fARBCmd()
 *
 *  Handles the OpenGL glWindowPos3fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 676, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[676];
    ((GLfunction_void_float_float_float)funcPtr->funcPtr)((GLfloat)param1, (GLfloat)param2, (GLfloat)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3fvARBCmd()
 *
 *  Handles the OpenGL glWindowPos3fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 677, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[677];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3iARBCmd()
 *
 *  Handles the OpenGL glWindowPos3iARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3iARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3iARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 678, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[678];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLint)param1, (GLint)param2, (GLint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3ivARBCmd()
 *
 *  Handles the OpenGL glWindowPos3ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 679, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[679];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3sARBCmd()
 *
 *  Handles the OpenGL glWindowPos3sARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3sARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3sARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 680, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[680];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLshort)param1, (GLshort)param2, (GLshort)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWindowPos3svARBCmd()
 *
 *  Handles the OpenGL glWindowPos3svARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWindowPos3svARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWindowPos3svARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 681, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[681];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib1dARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib1dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib1dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib1dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 682, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[682];
    ((GLfunction_void_int_double)funcPtr->funcPtr)((GLuint)param1, (GLdouble)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib1dvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib1dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib1dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib1dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 683, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[683];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLdouble*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib1fARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib1fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib1fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib1fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 684, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[684];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLuint)param1, (GLfloat)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib1fvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib1fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib1fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib1fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 685, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[685];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib1sARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib1sARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib1sARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib1sARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 686, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[686];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLuint)param1, (GLshort)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib1svARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib1svARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib1svARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib1svARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 687, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[687];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib2dARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib2dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib2dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib2dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 688, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[688];
    ((GLfunction_void_int_double_double)funcPtr->funcPtr)((GLuint)param1, (GLdouble)param2, (GLdouble)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib2dvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib2dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib2dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib2dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 689, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[689];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLdouble*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib2fARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib2fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib2fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib2fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 690, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[690];
    ((GLfunction_void_int_float_float)funcPtr->funcPtr)((GLuint)param1, (GLfloat)param2, (GLfloat)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib2fvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib2fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib2fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib2fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 691, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[691];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib2sARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib2sARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib2sARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib2sARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 692, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[692];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLuint)param1, (GLshort)param2, (GLshort)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib2svARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib2svARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib2svARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib2svARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 693, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[693];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib3dARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib3dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib3dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    double param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib3dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 694, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[694];
    ((GLfunction_void_int_double_double_double)funcPtr->funcPtr)((GLuint)param1, (GLdouble)param2, (GLdouble)param3, (GLdouble)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib3dvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib3dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib3dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib3dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 695, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[695];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLdouble*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib3fARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib3fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib3fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    double param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib3fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 696, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[696];
    ((GLfunction_void_int_float_float_float)funcPtr->funcPtr)((GLuint)param1, (GLfloat)param2, (GLfloat)param3, (GLfloat)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib3fvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib3fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib3fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib3fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 697, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[697];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib3sARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib3sARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib3sARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib3sARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 698, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[698];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLuint)param1, (GLshort)param2, (GLshort)param3, (GLshort)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib3svARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib3svARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib3svARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib3svARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 699, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[699];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4NbvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4NbvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4NbvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4NbvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 700, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[700];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLbyte*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4NivARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4NivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4NivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4NivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 701, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[701];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4NsvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4NsvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4NsvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4NsvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 702, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[702];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4NubARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4NubARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4NubARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4NubARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 703, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[703];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLuint)param1, (GLubyte)param2, (GLubyte)param3, (GLubyte)param4, (GLubyte)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4NubvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4NubvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4NubvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4NubvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 704, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[704];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLubyte*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4NuivARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4NuivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4NuivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4NuivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 705, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[705];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLuint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4NusvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4NusvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4NusvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4NusvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 706, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[706];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLushort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4bvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4bvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4bvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4bvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 707, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[707];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLbyte*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4dARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    double param4;
    double param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 708, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[708];
    ((GLfunction_void_int_double_double_double_double)funcPtr->funcPtr)((GLuint)param1, (GLdouble)param2, (GLdouble)param3, (GLdouble)param4, (GLdouble)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4dvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 709, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[709];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLdouble*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4fARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    double param4;
    double param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 710, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[710];
    ((GLfunction_void_int_float_float_float_float)funcPtr->funcPtr)((GLuint)param1, (GLfloat)param2, (GLfloat)param3, (GLfloat)param4, (GLfloat)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4fvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 711, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[711];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4ivARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 712, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[712];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4sARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4sARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4sARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4sARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 713, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[713];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLuint)param1, (GLshort)param2, (GLshort)param3, (GLshort)param4, (GLshort)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4svARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4svARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4svARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4svARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 714, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[714];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4ubvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4ubvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4ubvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4ubvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 715, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[715];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLubyte*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4uivARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4uivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4uivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4uivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 716, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[716];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLuint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttrib4usvARBCmd()
 *
 *  Handles the OpenGL glVertexAttrib4usvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttrib4usvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttrib4usvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 717, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[717];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLushort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexAttribPointerARBCmd()
 *
 *  Handles the OpenGL glVertexAttribPointerARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexAttribPointerARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    void *param6;
    int paramLength6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexAttribPointerARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 718, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &param6, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[718];
    ((GLfunction_void_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLint)param2, (GLenum)param3, (GLboolean)param4, (GLsizei)param5, (GLvoid*)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glEnableVertexAttribArrayARBCmd()
 *
 *  Handles the OpenGL glEnableVertexAttribArrayARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glEnableVertexAttribArrayARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glEnableVertexAttribArrayARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 719, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[719];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLuint)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDisableVertexAttribArrayARBCmd()
 *
 *  Handles the OpenGL glDisableVertexAttribArrayARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDisableVertexAttribArrayARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDisableVertexAttribArrayARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 720, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[720];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLuint)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glProgramStringARBCmd()
 *
 *  Handles the OpenGL glProgramStringARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glProgramStringARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glProgramStringARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 721, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[721];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLsizei)param3, (GLvoid*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBindProgramARBCmd()
 *
 *  Handles the OpenGL glBindProgramARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBindProgramARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBindProgramARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 722, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[722];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDeleteProgramsARBCmd()
 *
 *  Handles the OpenGL glDeleteProgramsARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDeleteProgramsARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDeleteProgramsARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 723, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[723];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLuint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGenProgramsARBCmd()
 *
 *  Handles the OpenGL glGenProgramsARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGenProgramsARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2 = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGenProgramsARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 724, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[724];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLuint*)param2);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength2, param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glProgramEnvParameter4dARBCmd()
 *
 *  Handles the OpenGL glProgramEnvParameter4dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glProgramEnvParameter4dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    double param3;
    double param4;
    double param5;
    double param6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glProgramEnvParameter4dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 725, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[725];
    ((GLfunction_void_int_int_double_double_double_double)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLdouble)param3, (GLdouble)param4, (GLdouble)param5, (GLdouble)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glProgramEnvParameter4dvARBCmd()
 *
 *  Handles the OpenGL glProgramEnvParameter4dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glProgramEnvParameter4dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glProgramEnvParameter4dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 726, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[726];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLdouble*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glProgramEnvParameter4fARBCmd()
 *
 *  Handles the OpenGL glProgramEnvParameter4fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glProgramEnvParameter4fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    double param3;
    double param4;
    double param5;
    double param6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glProgramEnvParameter4fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 727, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[727];
    ((GLfunction_void_int_int_float_float_float_float)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLfloat)param3, (GLfloat)param4, (GLfloat)param5, (GLfloat)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glProgramEnvParameter4fvARBCmd()
 *
 *  Handles the OpenGL glProgramEnvParameter4fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glProgramEnvParameter4fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glProgramEnvParameter4fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 728, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[728];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLfloat*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glProgramLocalParameter4dARBCmd()
 *
 *  Handles the OpenGL glProgramLocalParameter4dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glProgramLocalParameter4dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    double param3;
    double param4;
    double param5;
    double param6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glProgramLocalParameter4dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 729, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[729];
    ((GLfunction_void_int_int_double_double_double_double)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLdouble)param3, (GLdouble)param4, (GLdouble)param5, (GLdouble)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glProgramLocalParameter4dvARBCmd()
 *
 *  Handles the OpenGL glProgramLocalParameter4dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glProgramLocalParameter4dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glProgramLocalParameter4dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 730, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[730];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLdouble*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glProgramLocalParameter4fARBCmd()
 *
 *  Handles the OpenGL glProgramLocalParameter4fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glProgramLocalParameter4fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    double param3;
    double param4;
    double param5;
    double param6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glProgramLocalParameter4fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 731, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[731];
    ((GLfunction_void_int_int_float_float_float_float)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLfloat)param3, (GLfloat)param4, (GLfloat)param5, (GLfloat)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glProgramLocalParameter4fvARBCmd()
 *
 *  Handles the OpenGL glProgramLocalParameter4fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glProgramLocalParameter4fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glProgramLocalParameter4fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 732, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[732];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLfloat*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetProgramEnvParameterdvARBCmd()
 *
 *  Handles the OpenGL glGetProgramEnvParameterdvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetProgramEnvParameterdvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetProgramEnvParameterdvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 733, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[733];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLdouble*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetProgramEnvParameterfvARBCmd()
 *
 *  Handles the OpenGL glGetProgramEnvParameterfvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetProgramEnvParameterfvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetProgramEnvParameterfvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 734, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[734];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetProgramLocalParameterdvARBCmd()
 *
 *  Handles the OpenGL glGetProgramLocalParameterdvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetProgramLocalParameterdvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetProgramLocalParameterdvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 735, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[735];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLdouble*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetProgramLocalParameterfvARBCmd()
 *
 *  Handles the OpenGL glGetProgramLocalParameterfvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetProgramLocalParameterfvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetProgramLocalParameterfvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 736, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[736];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetProgramivARBCmd()
 *
 *  Handles the OpenGL glGetProgramivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetProgramivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetProgramivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 737, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[737];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetProgramStringARBCmd()
 *
 *  Handles the OpenGL glGetProgramStringARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetProgramStringARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetProgramStringARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 738, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[738];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLvoid*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetVertexAttribdvARBCmd()
 *
 *  Handles the OpenGL glGetVertexAttribdvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetVertexAttribdvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetVertexAttribdvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 739, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[739];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLdouble*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetVertexAttribfvARBCmd()
 *
 *  Handles the OpenGL glGetVertexAttribfvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetVertexAttribfvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetVertexAttribfvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 740, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[740];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetVertexAttribivARBCmd()
 *
 *  Handles the OpenGL glGetVertexAttribivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetVertexAttribivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetVertexAttribivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 741, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[741];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetVertexAttribPointervARBCmd()
 *
 *  Handles the OpenGL glGetVertexAttribPointervARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetVertexAttribPointervARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void **param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetVertexAttribPointervARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 742, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[742];
    ((GLfunction_void_int_int_voidPtrPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLvoid**)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glIsProgramARBCmd()
 *
 *  Handles the OpenGL glIsProgramARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glIsProgramARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;
     GLboolean retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glIsProgramARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 743, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[743];
    retVal = ((GLfunction_GLboolean_int)funcPtr->funcPtr)((GLuint)param1);
    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBindBufferARBCmd()
 *
 *  Handles the OpenGL glBindBufferARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBindBufferARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBindBufferARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 744, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[744];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDeleteBuffersARBCmd()
 *
 *  Handles the OpenGL glDeleteBuffersARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDeleteBuffersARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDeleteBuffersARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 745, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[745];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLuint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGenBuffersARBCmd()
 *
 *  Handles the OpenGL glGenBuffersARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGenBuffersARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2 = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGenBuffersARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 746, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[746];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLuint*)param2);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength2, param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glIsBufferARBCmd()
 *
 *  Handles the OpenGL glIsBufferARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glIsBufferARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;
     GLboolean retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glIsBufferARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 747, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[747];
    retVal = ((GLfunction_GLboolean_int)funcPtr->funcPtr)((GLuint)param1);
    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBufferDataARBCmd()
 *
 *  Handles the OpenGL glBufferDataARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBufferDataARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBufferDataARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 748, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[748];
    ((GLfunction_void_int_int_voidPtr_int)funcPtr->funcPtr)((GLenum)param1, (GLsizeiptrARB)param2, (GLvoid*)param3, (GLenum)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBufferSubDataARBCmd()
 *
 *  Handles the OpenGL glBufferSubDataARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBufferSubDataARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBufferSubDataARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 749, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[749];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLintptrARB)param2, (GLsizeiptrARB)param3, (GLvoid*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetBufferSubDataARBCmd()
 *
 *  Handles the OpenGL glGetBufferSubDataARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetBufferSubDataARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4 = NULL;
    int paramLength4 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetBufferSubDataARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 750, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[750];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLintptrARB)param2, (GLsizeiptrARB)param3, (GLvoid*)param4);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMapBufferARBCmd()
 *
 *  Handles the OpenGL glMapBufferARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMapBufferARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMapBufferARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 751, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[751];
    ((GLfunction_GLvoid_star_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUnmapBufferARBCmd()
 *
 *  Handles the OpenGL glUnmapBufferARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUnmapBufferARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;
     GLboolean retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUnmapBufferARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 752, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[752];
    retVal = ((GLfunction_GLboolean_int)funcPtr->funcPtr)((GLenum)param1);
    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetBufferParameterivARBCmd()
 *
 *  Handles the OpenGL glGetBufferParameterivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetBufferParameterivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetBufferParameterivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 753, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[753];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetBufferPointervARBCmd()
 *
 *  Handles the OpenGL glGetBufferPointervARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetBufferPointervARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void **param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetBufferPointervARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 754, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[754];
    ((GLfunction_void_int_int_voidPtrPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLvoid**)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGenQueriesARBCmd()
 *
 *  Handles the OpenGL glGenQueriesARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGenQueriesARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2 = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGenQueriesARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 755, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[755];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLuint*)param2);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength2, param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDeleteQueriesARBCmd()
 *
 *  Handles the OpenGL glDeleteQueriesARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDeleteQueriesARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDeleteQueriesARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 756, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[756];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLuint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glIsQueryARBCmd()
 *
 *  Handles the OpenGL glIsQueryARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glIsQueryARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;
     GLboolean retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glIsQueryARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 757, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[757];
    retVal = ((GLfunction_GLboolean_int)funcPtr->funcPtr)((GLuint)param1);
    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBeginQueryARBCmd()
 *
 *  Handles the OpenGL glBeginQueryARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBeginQueryARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBeginQueryARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 758, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[758];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glEndQueryARBCmd()
 *
 *  Handles the OpenGL glEndQueryARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glEndQueryARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glEndQueryARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 759, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[759];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetQueryivARBCmd()
 *
 *  Handles the OpenGL glGetQueryivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetQueryivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetQueryivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 760, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[760];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetQueryObjectivARBCmd()
 *
 *  Handles the OpenGL glGetQueryObjectivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetQueryObjectivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetQueryObjectivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 761, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[761];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetQueryObjectuivARBCmd()
 *
 *  Handles the OpenGL glGetQueryObjectuivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetQueryObjectuivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetQueryObjectuivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 762, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[762];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLuint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDeleteObjectARBCmd()
 *
 *  Handles the OpenGL glDeleteObjectARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDeleteObjectARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDeleteObjectARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 763, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[763];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLhandleARB)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetHandleARBCmd()
 *
 *  Handles the OpenGL glGetHandleARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetHandleARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;
     GLhandleARB retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetHandleARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 764, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[764];
    retVal = ((GLfunction_GLhandleARB_int)funcPtr->funcPtr)((GLenum)param1);
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDetachObjectARBCmd()
 *
 *  Handles the OpenGL glDetachObjectARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDetachObjectARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDetachObjectARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 765, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[765];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLhandleARB)param1, (GLhandleARB)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCreateShaderObjectARBCmd()
 *
 *  Handles the OpenGL glCreateShaderObjectARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCreateShaderObjectARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;
     GLhandleARB retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCreateShaderObjectARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 766, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[766];
    retVal = ((GLfunction_GLhandleARB_int)funcPtr->funcPtr)((GLenum)param1);
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glShaderSourceARBCmd()
 *
 *  Handles the OpenGL glShaderSourceARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glShaderSourceARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void **param3;
    int paramLength3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glShaderSourceARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 767, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[767];
    ((GLfunction_void_int_int_voidPtrPtr_voidPtr)funcPtr->funcPtr)((GLhandleARB)param1, (GLsizei)param2, (GLcharARB**)param3, (GLint*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCompileShaderARBCmd()
 *
 *  Handles the OpenGL glCompileShaderARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCompileShaderARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCompileShaderARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 768, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[768];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLhandleARB)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCreateProgramObjectARBCmd()
 *
 *  Handles the OpenGL glCreateProgramObjectARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCreateProgramObjectARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;

    TclGLFunc *funcPtr;
     GLhandleARB retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCreateProgramObjectARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 769, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[769];
    retVal = ((GLfunction_GLhandleARB_)funcPtr->funcPtr)();
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glAttachObjectARBCmd()
 *
 *  Handles the OpenGL glAttachObjectARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glAttachObjectARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glAttachObjectARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 770, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[770];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLhandleARB)param1, (GLhandleARB)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glLinkProgramARBCmd()
 *
 *  Handles the OpenGL glLinkProgramARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glLinkProgramARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glLinkProgramARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 771, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[771];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLhandleARB)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUseProgramObjectARBCmd()
 *
 *  Handles the OpenGL glUseProgramObjectARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUseProgramObjectARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUseProgramObjectARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 772, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[772];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLhandleARB)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glValidateProgramARBCmd()
 *
 *  Handles the OpenGL glValidateProgramARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glValidateProgramARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glValidateProgramARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 773, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[773];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLhandleARB)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform1fARBCmd()
 *
 *  Handles the OpenGL glUniform1fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform1fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform1fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 774, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[774];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLint)param1, (GLfloat)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform2fARBCmd()
 *
 *  Handles the OpenGL glUniform2fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform2fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform2fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 775, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[775];
    ((GLfunction_void_int_float_float)funcPtr->funcPtr)((GLint)param1, (GLfloat)param2, (GLfloat)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform3fARBCmd()
 *
 *  Handles the OpenGL glUniform3fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform3fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    double param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform3fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 776, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[776];
    ((GLfunction_void_int_float_float_float)funcPtr->funcPtr)((GLint)param1, (GLfloat)param2, (GLfloat)param3, (GLfloat)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform4fARBCmd()
 *
 *  Handles the OpenGL glUniform4fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform4fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    double param3;
    double param4;
    double param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform4fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 777, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[777];
    ((GLfunction_void_int_float_float_float_float)funcPtr->funcPtr)((GLint)param1, (GLfloat)param2, (GLfloat)param3, (GLfloat)param4, (GLfloat)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform1iARBCmd()
 *
 *  Handles the OpenGL glUniform1iARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform1iARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform1iARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 778, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[778];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLint)param1, (GLint)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform2iARBCmd()
 *
 *  Handles the OpenGL glUniform2iARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform2iARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform2iARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 779, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[779];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLint)param1, (GLint)param2, (GLint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform3iARBCmd()
 *
 *  Handles the OpenGL glUniform3iARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform3iARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform3iARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 780, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[780];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLint)param1, (GLint)param2, (GLint)param3, (GLint)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform4iARBCmd()
 *
 *  Handles the OpenGL glUniform4iARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform4iARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform4iARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 781, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[781];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLint)param1, (GLint)param2, (GLint)param3, (GLint)param4, (GLint)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform1fvARBCmd()
 *
 *  Handles the OpenGL glUniform1fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform1fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform1fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 782, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[782];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLsizei)param2, (GLfloat*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform2fvARBCmd()
 *
 *  Handles the OpenGL glUniform2fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform2fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform2fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 783, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[783];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLsizei)param2, (GLfloat*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform3fvARBCmd()
 *
 *  Handles the OpenGL glUniform3fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform3fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform3fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 784, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[784];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLsizei)param2, (GLfloat*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform4fvARBCmd()
 *
 *  Handles the OpenGL glUniform4fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform4fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform4fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 785, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[785];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLsizei)param2, (GLfloat*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform1ivARBCmd()
 *
 *  Handles the OpenGL glUniform1ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform1ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform1ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 786, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[786];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLsizei)param2, (GLint*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform2ivARBCmd()
 *
 *  Handles the OpenGL glUniform2ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform2ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform2ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 787, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[787];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLsizei)param2, (GLint*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform3ivARBCmd()
 *
 *  Handles the OpenGL glUniform3ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform3ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform3ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 788, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[788];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLsizei)param2, (GLint*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniform4ivARBCmd()
 *
 *  Handles the OpenGL glUniform4ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniform4ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniform4ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 789, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[789];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLsizei)param2, (GLint*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniformMatrix2fvARBCmd()
 *
 *  Handles the OpenGL glUniformMatrix2fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniformMatrix2fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniformMatrix2fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 790, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[790];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLsizei)param2, (GLboolean)param3, (GLfloat*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniformMatrix3fvARBCmd()
 *
 *  Handles the OpenGL glUniformMatrix3fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniformMatrix3fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniformMatrix3fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 791, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[791];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLsizei)param2, (GLboolean)param3, (GLfloat*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUniformMatrix4fvARBCmd()
 *
 *  Handles the OpenGL glUniformMatrix4fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUniformMatrix4fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUniformMatrix4fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 792, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[792];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLsizei)param2, (GLboolean)param3, (GLfloat*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetObjectParameterfvARBCmd()
 *
 *  Handles the OpenGL glGetObjectParameterfvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetObjectParameterfvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetObjectParameterfvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 793, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[793];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLhandleARB)param1, (GLenum)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetObjectParameterivARBCmd()
 *
 *  Handles the OpenGL glGetObjectParameterivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetObjectParameterivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetObjectParameterivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 794, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[794];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLhandleARB)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetInfoLogARBCmd()
 *
 *  Handles the OpenGL glGetInfoLogARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetInfoLogARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    void *param4 = NULL;
    int paramLength4 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetInfoLogARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 795, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[795];
    ((GLfunction_void_int_int_voidPtr_voidPtr)funcPtr->funcPtr)((GLhandleARB)param1, (GLsizei)param2, (GLsizei*)param3, (GLcharARB*)param4);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetAttachedObjectsARBCmd()
 *
 *  Handles the OpenGL glGetAttachedObjectsARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetAttachedObjectsARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    void *param4 = NULL;
    int paramLength4 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetAttachedObjectsARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 796, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[796];
    ((GLfunction_void_int_int_voidPtr_voidPtr)funcPtr->funcPtr)((GLhandleARB)param1, (GLsizei)param2, (GLsizei*)param3, (GLhandleARB*)param4);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetUniformLocationARBCmd()
 *
 *  Handles the OpenGL glGetUniformLocationARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetUniformLocationARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;
     GLint retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetUniformLocationARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 797, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[797];
    retVal = ((GLfunction_GLint_int_voidPtr)funcPtr->funcPtr)((GLhandleARB)param1, (GLcharARB*)param2);
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetActiveUniformARBCmd()
 *
 *  Handles the OpenGL glGetActiveUniformARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetActiveUniformARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4 = NULL;
    int paramLength4 = 0;
    void *param5 = NULL;
    int paramLength5 = 0;
    void *param6 = NULL;
    int paramLength6 = 0;
    void *param7 = NULL;
    int paramLength7 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetActiveUniformARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 798, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[798];
    ((GLfunction_void_int_int_int_voidPtr_voidPtr_voidPtr_voidPtr)funcPtr->funcPtr)((GLhandleARB)param1, (GLuint)param2, (GLsizei)param3, (GLsizei*)param4, (GLint*)param5, (GLenum*)param6, (GLcharARB*)param7);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[5], paramLength5, param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[6], paramLength6, param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[7], paramLength7, param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetUniformfvARBCmd()
 *
 *  Handles the OpenGL glGetUniformfvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetUniformfvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetUniformfvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 799, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[799];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLhandleARB)param1, (GLint)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetUniformivARBCmd()
 *
 *  Handles the OpenGL glGetUniformivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetUniformivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetUniformivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 800, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[800];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLhandleARB)param1, (GLint)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetShaderSourceARBCmd()
 *
 *  Handles the OpenGL glGetShaderSourceARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetShaderSourceARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    void *param4 = NULL;
    int paramLength4 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetShaderSourceARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 801, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[801];
    ((GLfunction_void_int_int_voidPtr_voidPtr)funcPtr->funcPtr)((GLhandleARB)param1, (GLsizei)param2, (GLsizei*)param3, (GLcharARB*)param4);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBindAttribLocationARBCmd()
 *
 *  Handles the OpenGL glBindAttribLocationARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBindAttribLocationARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBindAttribLocationARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 802, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[802];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLhandleARB)param1, (GLuint)param2, (GLcharARB*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetActiveAttribARBCmd()
 *
 *  Handles the OpenGL glGetActiveAttribARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetActiveAttribARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4 = NULL;
    int paramLength4 = 0;
    void *param5 = NULL;
    int paramLength5 = 0;
    void *param6 = NULL;
    int paramLength6 = 0;
    void *param7 = NULL;
    int paramLength7 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetActiveAttribARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 803, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[803];
    ((GLfunction_void_int_int_int_voidPtr_voidPtr_voidPtr_voidPtr)funcPtr->funcPtr)((GLhandleARB)param1, (GLuint)param2, (GLsizei)param3, (GLsizei*)param4, (GLint*)param5, (GLenum*)param6, (GLcharARB*)param7);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[5], paramLength5, param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[6], paramLength6, param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[7], paramLength7, param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetAttribLocationARBCmd()
 *
 *  Handles the OpenGL glGetAttribLocationARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetAttribLocationARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;
     GLint retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetAttribLocationARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 804, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[804];
    retVal = ((GLfunction_GLint_int_voidPtr)funcPtr->funcPtr)((GLhandleARB)param1, (GLcharARB*)param2);
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDrawBuffersARBCmd()
 *
 *  Handles the OpenGL glDrawBuffersARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDrawBuffersARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDrawBuffersARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 805, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[805];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLenum*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBlendColorEXTCmd()
 *
 *  Handles the OpenGL glBlendColorEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBlendColorEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    double param3;
    double param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBlendColorEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 806, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[806];
    ((GLfunction_void_float_float_float_float)funcPtr->funcPtr)((GLclampf)param1, (GLclampf)param2, (GLclampf)param3, (GLclampf)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glPolygonOffsetEXTCmd()
 *
 *  Handles the OpenGL glPolygonOffsetEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glPolygonOffsetEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glPolygonOffsetEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 807, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[807];
    ((GLfunction_void_float_float)funcPtr->funcPtr)((GLfloat)param1, (GLfloat)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTexImage3DEXTCmd()
 *
 *  Handles the OpenGL glTexImage3DEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTexImage3DEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    int param9;
    void *param10;
    int paramLength10;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTexImage3DEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 808, objc, 10) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[9], &param9) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[10], &param10, &paramLength10) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[808];
    ((GLfunction_void_int_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLenum)param3, (GLsizei)param4, (GLsizei)param5, (GLsizei)param6, (GLint)param7, (GLenum)param8, (GLenum)param9, (GLvoid*)param10);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTexSubImage3DEXTCmd()
 *
 *  Handles the OpenGL glTexSubImage3DEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTexSubImage3DEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    int param9;
    int param10;
    void *param11;
    int paramLength11;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTexSubImage3DEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 809, objc, 11) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[9], &param9) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[10], &param10) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[11], &param11, &paramLength11) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[809];
    ((GLfunction_void_int_int_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4, (GLint)param5, (GLsizei)param6, (GLsizei)param7, (GLsizei)param8, (GLenum)param9, (GLenum)param10, (GLvoid*)param11);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTexSubImage1DEXTCmd()
 *
 *  Handles the OpenGL glTexSubImage1DEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTexSubImage1DEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    void *param7;
    int paramLength7;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTexSubImage1DEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 810, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &param7, &paramLength7) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[810];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLsizei)param4, (GLenum)param5, (GLenum)param6, (GLvoid*)param7);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTexSubImage2DEXTCmd()
 *
 *  Handles the OpenGL glTexSubImage2DEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTexSubImage2DEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    void *param9;
    int paramLength9;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTexSubImage2DEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 811, objc, 9) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[9], &param9, &paramLength9) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[811];
    ((GLfunction_void_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4, (GLsizei)param5, (GLsizei)param6, (GLenum)param7, (GLenum)param8, (GLvoid*)param9);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCopyTexImage1DEXTCmd()
 *
 *  Handles the OpenGL glCopyTexImage1DEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCopyTexImage1DEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCopyTexImage1DEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 812, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[812];
    ((GLfunction_void_int_int_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLenum)param3, (GLint)param4, (GLint)param5, (GLsizei)param6, (GLint)param7);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCopyTexImage2DEXTCmd()
 *
 *  Handles the OpenGL glCopyTexImage2DEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCopyTexImage2DEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCopyTexImage2DEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 813, objc, 8) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[813];
    ((GLfunction_void_int_int_int_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLenum)param3, (GLint)param4, (GLint)param5, (GLsizei)param6, (GLsizei)param7, (GLint)param8);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCopyTexSubImage1DEXTCmd()
 *
 *  Handles the OpenGL glCopyTexSubImage1DEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCopyTexSubImage1DEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCopyTexSubImage1DEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 814, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[814];
    ((GLfunction_void_int_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4, (GLint)param5, (GLsizei)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCopyTexSubImage2DEXTCmd()
 *
 *  Handles the OpenGL glCopyTexSubImage2DEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCopyTexSubImage2DEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCopyTexSubImage2DEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 815, objc, 8) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[815];
    ((GLfunction_void_int_int_int_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4, (GLint)param5, (GLint)param6, (GLsizei)param7, (GLsizei)param8);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCopyTexSubImage3DEXTCmd()
 *
 *  Handles the OpenGL glCopyTexSubImage3DEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCopyTexSubImage3DEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    int param7;
    int param8;
    int param9;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCopyTexSubImage3DEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 816, objc, 9) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &param8) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[9], &param9) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[816];
    ((GLfunction_void_int_int_int_int_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLint)param3, (GLint)param4, (GLint)param5, (GLint)param6, (GLint)param7, (GLsizei)param8, (GLsizei)param9);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetHistogramEXTCmd()
 *
 *  Handles the OpenGL glGetHistogramEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetHistogramEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    void *param5 = NULL;
    int paramLength5 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetHistogramEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 817, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[817];
    ((GLfunction_void_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLboolean)param2, (GLenum)param3, (GLenum)param4, (GLvoid*)param5);
    if (SetPtrOutParam(interp, infoPtr, objv[5], paramLength5, param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetHistogramParameterfvEXTCmd()
 *
 *  Handles the OpenGL glGetHistogramParameterfvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetHistogramParameterfvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetHistogramParameterfvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 818, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[818];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetHistogramParameterivEXTCmd()
 *
 *  Handles the OpenGL glGetHistogramParameterivEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetHistogramParameterivEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetHistogramParameterivEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 819, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[819];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetMinmaxEXTCmd()
 *
 *  Handles the OpenGL glGetMinmaxEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetMinmaxEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    void *param5 = NULL;
    int paramLength5 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetMinmaxEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 820, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[820];
    ((GLfunction_void_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLboolean)param2, (GLenum)param3, (GLenum)param4, (GLvoid*)param5);
    if (SetPtrOutParam(interp, infoPtr, objv[5], paramLength5, param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetMinmaxParameterfvEXTCmd()
 *
 *  Handles the OpenGL glGetMinmaxParameterfvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetMinmaxParameterfvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetMinmaxParameterfvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 821, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[821];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetMinmaxParameterivEXTCmd()
 *
 *  Handles the OpenGL glGetMinmaxParameterivEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetMinmaxParameterivEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetMinmaxParameterivEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 822, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[822];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glHistogramEXTCmd()
 *
 *  Handles the OpenGL glHistogramEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glHistogramEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glHistogramEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 823, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[823];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLsizei)param2, (GLenum)param3, (GLboolean)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMinmaxEXTCmd()
 *
 *  Handles the OpenGL glMinmaxEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMinmaxEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMinmaxEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 824, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[824];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLboolean)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glResetHistogramEXTCmd()
 *
 *  Handles the OpenGL glResetHistogramEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glResetHistogramEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glResetHistogramEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 825, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[825];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glResetMinmaxEXTCmd()
 *
 *  Handles the OpenGL glResetMinmaxEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glResetMinmaxEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glResetMinmaxEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 826, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[826];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glConvolutionFilter1DEXTCmd()
 *
 *  Handles the OpenGL glConvolutionFilter1DEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glConvolutionFilter1DEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    void *param6;
    int paramLength6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glConvolutionFilter1DEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 827, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &param6, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[827];
    ((GLfunction_void_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLsizei)param3, (GLenum)param4, (GLenum)param5, (GLvoid*)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glConvolutionFilter2DEXTCmd()
 *
 *  Handles the OpenGL glConvolutionFilter2DEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glConvolutionFilter2DEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    void *param7;
    int paramLength7;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glConvolutionFilter2DEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 828, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &param7, &paramLength7) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[828];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLsizei)param3, (GLsizei)param4, (GLenum)param5, (GLenum)param6, (GLvoid*)param7);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glConvolutionParameterfEXTCmd()
 *
 *  Handles the OpenGL glConvolutionParameterfEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glConvolutionParameterfEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glConvolutionParameterfEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 829, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[829];
    ((GLfunction_void_int_int_float)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glConvolutionParameterfvEXTCmd()
 *
 *  Handles the OpenGL glConvolutionParameterfvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glConvolutionParameterfvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glConvolutionParameterfvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 830, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[830];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glConvolutionParameteriEXTCmd()
 *
 *  Handles the OpenGL glConvolutionParameteriEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glConvolutionParameteriEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glConvolutionParameteriEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 831, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[831];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glConvolutionParameterivEXTCmd()
 *
 *  Handles the OpenGL glConvolutionParameterivEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glConvolutionParameterivEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glConvolutionParameterivEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 832, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[832];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCopyConvolutionFilter1DEXTCmd()
 *
 *  Handles the OpenGL glCopyConvolutionFilter1DEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCopyConvolutionFilter1DEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCopyConvolutionFilter1DEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 833, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[833];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint)param3, (GLint)param4, (GLsizei)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCopyConvolutionFilter2DEXTCmd()
 *
 *  Handles the OpenGL glCopyConvolutionFilter2DEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCopyConvolutionFilter2DEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCopyConvolutionFilter2DEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 834, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[834];
    ((GLfunction_void_int_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint)param3, (GLint)param4, (GLsizei)param5, (GLsizei)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetConvolutionFilterEXTCmd()
 *
 *  Handles the OpenGL glGetConvolutionFilterEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetConvolutionFilterEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4 = NULL;
    int paramLength4 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetConvolutionFilterEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 835, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[835];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLenum)param3, (GLvoid*)param4);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetConvolutionParameterfvEXTCmd()
 *
 *  Handles the OpenGL glGetConvolutionParameterfvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetConvolutionParameterfvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetConvolutionParameterfvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 836, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[836];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetConvolutionParameterivEXTCmd()
 *
 *  Handles the OpenGL glGetConvolutionParameterivEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetConvolutionParameterivEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetConvolutionParameterivEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 837, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[837];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetSeparableFilterEXTCmd()
 *
 *  Handles the OpenGL glGetSeparableFilterEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetSeparableFilterEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4 = NULL;
    int paramLength4 = 0;
    void *param5 = NULL;
    int paramLength5 = 0;
    void *param6 = NULL;
    int paramLength6 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetSeparableFilterEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 838, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[838];
    ((GLfunction_void_int_int_int_voidPtr_voidPtr_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLenum)param3, (GLvoid*)param4, (GLvoid*)param5, (GLvoid*)param6);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[5], paramLength5, param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[6], paramLength6, param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSeparableFilter2DEXTCmd()
 *
 *  Handles the OpenGL glSeparableFilter2DEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSeparableFilter2DEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    void *param7;
    int paramLength7;
    void *param8;
    int paramLength8;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSeparableFilter2DEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 839, objc, 8) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &param7, &paramLength7) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[8], &param8, &paramLength8) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[839];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLsizei)param3, (GLsizei)param4, (GLenum)param5, (GLenum)param6, (GLvoid*)param7, (GLvoid*)param8);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glAreTexturesResidentEXTCmd()
 *
 *  Handles the OpenGL glAreTexturesResidentEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glAreTexturesResidentEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;
     GLboolean retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glAreTexturesResidentEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 840, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[840];
    retVal = ((GLfunction_GLboolean_int_voidPtr_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLuint*)param2, (GLboolean*)param3);
    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBindTextureEXTCmd()
 *
 *  Handles the OpenGL glBindTextureEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBindTextureEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBindTextureEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 841, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[841];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDeleteTexturesEXTCmd()
 *
 *  Handles the OpenGL glDeleteTexturesEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDeleteTexturesEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDeleteTexturesEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 842, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[842];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLuint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGenTexturesEXTCmd()
 *
 *  Handles the OpenGL glGenTexturesEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGenTexturesEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2 = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGenTexturesEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 843, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[843];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLuint*)param2);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength2, param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glIsTextureEXTCmd()
 *
 *  Handles the OpenGL glIsTextureEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glIsTextureEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;
     GLboolean retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glIsTextureEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 844, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[844];
    retVal = ((GLfunction_GLboolean_int)funcPtr->funcPtr)((GLuint)param1);
    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glPrioritizeTexturesEXTCmd()
 *
 *  Handles the OpenGL glPrioritizeTexturesEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glPrioritizeTexturesEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glPrioritizeTexturesEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 845, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[845];
    ((GLfunction_void_int_voidPtr_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLuint*)param2, (GLclampf*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glArrayElementEXTCmd()
 *
 *  Handles the OpenGL glArrayElementEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glArrayElementEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glArrayElementEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 846, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[846];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLint)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glColorPointerEXTCmd()
 *
 *  Handles the OpenGL glColorPointerEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glColorPointerEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    void *param5;
    int paramLength5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glColorPointerEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 847, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[5], &param5, &paramLength5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[847];
    ((GLfunction_void_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLenum)param2, (GLsizei)param3, (GLsizei)param4, (GLvoid*)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDrawArraysEXTCmd()
 *
 *  Handles the OpenGL glDrawArraysEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDrawArraysEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDrawArraysEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 848, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[848];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLint)param2, (GLsizei)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glEdgeFlagPointerEXTCmd()
 *
 *  Handles the OpenGL glEdgeFlagPointerEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glEdgeFlagPointerEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glEdgeFlagPointerEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 849, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[849];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLsizei)param2, (GLboolean*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetPointervEXTCmd()
 *
 *  Handles the OpenGL glGetPointervEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetPointervEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void **param2 = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetPointervEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 850, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[850];
    ((GLfunction_void_int_voidPtrPtr)funcPtr->funcPtr)((GLenum)param1, (GLvoid**)param2);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength2, param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glIndexPointerEXTCmd()
 *
 *  Handles the OpenGL glIndexPointerEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glIndexPointerEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glIndexPointerEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 851, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[851];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLsizei)param2, (GLsizei)param3, (GLvoid*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glNormalPointerEXTCmd()
 *
 *  Handles the OpenGL glNormalPointerEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glNormalPointerEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glNormalPointerEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 852, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[852];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLsizei)param2, (GLsizei)param3, (GLvoid*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTexCoordPointerEXTCmd()
 *
 *  Handles the OpenGL glTexCoordPointerEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTexCoordPointerEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    void *param5;
    int paramLength5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTexCoordPointerEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 853, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[5], &param5, &paramLength5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[853];
    ((GLfunction_void_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLenum)param2, (GLsizei)param3, (GLsizei)param4, (GLvoid*)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexPointerEXTCmd()
 *
 *  Handles the OpenGL glVertexPointerEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexPointerEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    void *param5;
    int paramLength5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexPointerEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 854, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[5], &param5, &paramLength5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[854];
    ((GLfunction_void_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLenum)param2, (GLsizei)param3, (GLsizei)param4, (GLvoid*)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBlendEquationEXTCmd()
 *
 *  Handles the OpenGL glBlendEquationEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBlendEquationEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBlendEquationEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 855, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[855];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glPointParameterfEXTCmd()
 *
 *  Handles the OpenGL glPointParameterfEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glPointParameterfEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glPointParameterfEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 856, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[856];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLenum)param1, (GLfloat)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glPointParameterfvEXTCmd()
 *
 *  Handles the OpenGL glPointParameterfvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glPointParameterfvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glPointParameterfvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 857, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[857];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glColorSubTableEXTCmd()
 *
 *  Handles the OpenGL glColorSubTableEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glColorSubTableEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    void *param6;
    int paramLength6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glColorSubTableEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 858, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &param6, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[858];
    ((GLfunction_void_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLsizei)param2, (GLsizei)param3, (GLenum)param4, (GLenum)param5, (GLvoid*)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCopyColorSubTableEXTCmd()
 *
 *  Handles the OpenGL glCopyColorSubTableEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCopyColorSubTableEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCopyColorSubTableEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 859, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[859];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLsizei)param2, (GLint)param3, (GLint)param4, (GLsizei)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glColorTableEXTCmd()
 *
 *  Handles the OpenGL glColorTableEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glColorTableEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    void *param6;
    int paramLength6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glColorTableEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 860, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &param6, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[860];
    ((GLfunction_void_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLsizei)param3, (GLenum)param4, (GLenum)param5, (GLvoid*)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetColorTableEXTCmd()
 *
 *  Handles the OpenGL glGetColorTableEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetColorTableEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4 = NULL;
    int paramLength4 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetColorTableEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 861, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[861];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLenum)param3, (GLvoid*)param4);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetColorTableParameterivEXTCmd()
 *
 *  Handles the OpenGL glGetColorTableParameterivEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetColorTableParameterivEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetColorTableParameterivEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 862, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[862];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetColorTableParameterfvEXTCmd()
 *
 *  Handles the OpenGL glGetColorTableParameterfvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetColorTableParameterfvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetColorTableParameterfvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 863, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[863];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glIndexMaterialEXTCmd()
 *
 *  Handles the OpenGL glIndexMaterialEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glIndexMaterialEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glIndexMaterialEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 864, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[864];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glIndexFuncEXTCmd()
 *
 *  Handles the OpenGL glIndexFuncEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glIndexFuncEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glIndexFuncEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 865, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[865];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLenum)param1, (GLclampf)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glLockArraysEXTCmd()
 *
 *  Handles the OpenGL glLockArraysEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glLockArraysEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glLockArraysEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 866, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[866];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLint)param1, (GLsizei)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glUnlockArraysEXTCmd()
 *
 *  Handles the OpenGL glUnlockArraysEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glUnlockArraysEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;

    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glUnlockArraysEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 867, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[867];
    ((GLfunction_void_)funcPtr->funcPtr)();
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCullParameterdvEXTCmd()
 *
 *  Handles the OpenGL glCullParameterdvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCullParameterdvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2 = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCullParameterdvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 868, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[868];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLdouble*)param2);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength2, param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glCullParameterfvEXTCmd()
 *
 *  Handles the OpenGL glCullParameterfvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glCullParameterfvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2 = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glCullParameterfvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 869, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[869];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLfloat*)param2);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength2, param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDrawRangeElementsEXTCmd()
 *
 *  Handles the OpenGL glDrawRangeElementsEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDrawRangeElementsEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    void *param6;
    int paramLength6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDrawRangeElementsEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 870, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &param6, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[870];
    ((GLfunction_void_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLuint)param3, (GLsizei)param4, (GLenum)param5, (GLvoid*)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glApplyTextureEXTCmd()
 *
 *  Handles the OpenGL glApplyTextureEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glApplyTextureEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glApplyTextureEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 871, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[871];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTextureLightEXTCmd()
 *
 *  Handles the OpenGL glTextureLightEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTextureLightEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTextureLightEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 872, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[872];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTextureMaterialEXTCmd()
 *
 *  Handles the OpenGL glTextureMaterialEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTextureMaterialEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTextureMaterialEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 873, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[873];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glPixelTransformParameteriEXTCmd()
 *
 *  Handles the OpenGL glPixelTransformParameteriEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glPixelTransformParameteriEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glPixelTransformParameteriEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 874, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[874];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glPixelTransformParameterfEXTCmd()
 *
 *  Handles the OpenGL glPixelTransformParameterfEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glPixelTransformParameterfEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glPixelTransformParameterfEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 875, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[875];
    ((GLfunction_void_int_int_float)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glPixelTransformParameterivEXTCmd()
 *
 *  Handles the OpenGL glPixelTransformParameterivEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glPixelTransformParameterivEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glPixelTransformParameterivEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 876, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[876];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLint*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glPixelTransformParameterfvEXTCmd()
 *
 *  Handles the OpenGL glPixelTransformParameterfvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glPixelTransformParameterfvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glPixelTransformParameterfvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 877, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[877];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLfloat*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3bEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3bEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3bEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3bEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 878, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[878];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLbyte)param1, (GLbyte)param2, (GLbyte)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3bvEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3bvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3bvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3bvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 879, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[879];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLbyte*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3dEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3dEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3dEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3dEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 880, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[880];
    ((GLfunction_void_double_double_double)funcPtr->funcPtr)((GLdouble)param1, (GLdouble)param2, (GLdouble)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3dvEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3dvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3dvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3dvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 881, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[881];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3fEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3fEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3fEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3fEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 882, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[882];
    ((GLfunction_void_float_float_float)funcPtr->funcPtr)((GLfloat)param1, (GLfloat)param2, (GLfloat)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3fvEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3fvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3fvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3fvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 883, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[883];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3iEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3iEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3iEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3iEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 884, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[884];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLint)param1, (GLint)param2, (GLint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3ivEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3ivEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3ivEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3ivEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 885, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[885];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3sEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3sEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3sEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3sEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 886, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[886];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLshort)param1, (GLshort)param2, (GLshort)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3svEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3svEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3svEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3svEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 887, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[887];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3ubEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3ubEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3ubEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3ubEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 888, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[888];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLubyte)param1, (GLubyte)param2, (GLubyte)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3ubvEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3ubvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3ubvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3ubvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 889, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[889];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLubyte*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3uiEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3uiEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3uiEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3uiEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 890, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[890];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLuint)param1, (GLuint)param2, (GLuint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3uivEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3uivEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3uivEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3uivEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 891, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[891];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLuint*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3usEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3usEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3usEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3usEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 892, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[892];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLushort)param1, (GLushort)param2, (GLushort)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColor3usvEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColor3usvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColor3usvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColor3usvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 893, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[893];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLushort*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSecondaryColorPointerEXTCmd()
 *
 *  Handles the OpenGL glSecondaryColorPointerEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSecondaryColorPointerEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSecondaryColorPointerEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 894, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[894];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLint)param1, (GLenum)param2, (GLsizei)param3, (GLvoid*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTextureNormalEXTCmd()
 *
 *  Handles the OpenGL glTextureNormalEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTextureNormalEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTextureNormalEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 895, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[895];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiDrawArraysEXTCmd()
 *
 *  Handles the OpenGL glMultiDrawArraysEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiDrawArraysEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2 = NULL;
    int paramLength2 = 0;
    void *param3 = NULL;
    int paramLength3 = 0;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiDrawArraysEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 896, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[896];
    ((GLfunction_void_int_voidPtr_voidPtr_int)funcPtr->funcPtr)((GLenum)param1, (GLint*)param2, (GLsizei*)param3, (GLsizei)param4);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength2, param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glMultiDrawElementsEXTCmd()
 *
 *  Handles the OpenGL glMultiDrawElementsEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glMultiDrawElementsEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    int param3;
    void **param4;
    int paramLength4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glMultiDrawElementsEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 897, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[897];
    ((GLfunction_void_int_voidPtr_int_voidPtrPtr_int)funcPtr->funcPtr)((GLenum)param1, (GLsizei*)param2, (GLenum)param3, (GLvoid**)param4, (GLsizei)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glFogCoordfEXTCmd()
 *
 *  Handles the OpenGL glFogCoordfEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glFogCoordfEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glFogCoordfEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 898, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[898];
    ((GLfunction_void_float)funcPtr->funcPtr)((GLfloat)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glFogCoordfvEXTCmd()
 *
 *  Handles the OpenGL glFogCoordfvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glFogCoordfvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glFogCoordfvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 899, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[899];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glFogCoorddEXTCmd()
 *
 *  Handles the OpenGL glFogCoorddEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glFogCoorddEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glFogCoorddEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 900, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[900];
    ((GLfunction_void_double)funcPtr->funcPtr)((GLdouble)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glFogCoorddvEXTCmd()
 *
 *  Handles the OpenGL glFogCoorddvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glFogCoorddvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glFogCoorddvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 901, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[901];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glFogCoordPointerEXTCmd()
 *
 *  Handles the OpenGL glFogCoordPointerEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glFogCoordPointerEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glFogCoordPointerEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 902, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[902];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLsizei)param2, (GLvoid*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTangent3bEXTCmd()
 *
 *  Handles the OpenGL glTangent3bEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTangent3bEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTangent3bEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 903, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[903];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLbyte)param1, (GLbyte)param2, (GLbyte)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTangent3bvEXTCmd()
 *
 *  Handles the OpenGL glTangent3bvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTangent3bvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTangent3bvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 904, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[904];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLbyte*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTangent3dEXTCmd()
 *
 *  Handles the OpenGL glTangent3dEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTangent3dEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTangent3dEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 905, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[905];
    ((GLfunction_void_double_double_double)funcPtr->funcPtr)((GLdouble)param1, (GLdouble)param2, (GLdouble)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTangent3dvEXTCmd()
 *
 *  Handles the OpenGL glTangent3dvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTangent3dvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTangent3dvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 906, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[906];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTangent3fEXTCmd()
 *
 *  Handles the OpenGL glTangent3fEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTangent3fEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTangent3fEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 907, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[907];
    ((GLfunction_void_float_float_float)funcPtr->funcPtr)((GLfloat)param1, (GLfloat)param2, (GLfloat)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTangent3fvEXTCmd()
 *
 *  Handles the OpenGL glTangent3fvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTangent3fvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTangent3fvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 908, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[908];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTangent3iEXTCmd()
 *
 *  Handles the OpenGL glTangent3iEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTangent3iEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTangent3iEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 909, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[909];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLint)param1, (GLint)param2, (GLint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTangent3ivEXTCmd()
 *
 *  Handles the OpenGL glTangent3ivEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTangent3ivEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTangent3ivEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 910, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[910];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTangent3sEXTCmd()
 *
 *  Handles the OpenGL glTangent3sEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTangent3sEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTangent3sEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 911, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[911];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLshort)param1, (GLshort)param2, (GLshort)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTangent3svEXTCmd()
 *
 *  Handles the OpenGL glTangent3svEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTangent3svEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTangent3svEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 912, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[912];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBinormal3bEXTCmd()
 *
 *  Handles the OpenGL glBinormal3bEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBinormal3bEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBinormal3bEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 913, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[913];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLbyte)param1, (GLbyte)param2, (GLbyte)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBinormal3bvEXTCmd()
 *
 *  Handles the OpenGL glBinormal3bvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBinormal3bvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBinormal3bvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 914, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[914];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLbyte*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBinormal3dEXTCmd()
 *
 *  Handles the OpenGL glBinormal3dEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBinormal3dEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBinormal3dEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 915, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[915];
    ((GLfunction_void_double_double_double)funcPtr->funcPtr)((GLdouble)param1, (GLdouble)param2, (GLdouble)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBinormal3dvEXTCmd()
 *
 *  Handles the OpenGL glBinormal3dvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBinormal3dvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBinormal3dvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 916, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[916];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBinormal3fEXTCmd()
 *
 *  Handles the OpenGL glBinormal3fEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBinormal3fEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    double param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBinormal3fEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 917, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[917];
    ((GLfunction_void_float_float_float)funcPtr->funcPtr)((GLfloat)param1, (GLfloat)param2, (GLfloat)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBinormal3fvEXTCmd()
 *
 *  Handles the OpenGL glBinormal3fvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBinormal3fvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBinormal3fvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 918, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[918];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBinormal3iEXTCmd()
 *
 *  Handles the OpenGL glBinormal3iEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBinormal3iEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBinormal3iEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 919, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[919];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLint)param1, (GLint)param2, (GLint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBinormal3ivEXTCmd()
 *
 *  Handles the OpenGL glBinormal3ivEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBinormal3ivEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBinormal3ivEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 920, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[920];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBinormal3sEXTCmd()
 *
 *  Handles the OpenGL glBinormal3sEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBinormal3sEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBinormal3sEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 921, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[921];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLshort)param1, (GLshort)param2, (GLshort)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBinormal3svEXTCmd()
 *
 *  Handles the OpenGL glBinormal3svEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBinormal3svEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBinormal3svEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 922, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[922];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glTangentPointerEXTCmd()
 *
 *  Handles the OpenGL glTangentPointerEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glTangentPointerEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glTangentPointerEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 923, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[923];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLsizei)param2, (GLvoid*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBinormalPointerEXTCmd()
 *
 *  Handles the OpenGL glBinormalPointerEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBinormalPointerEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBinormalPointerEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 924, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[924];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)param1, (GLsizei)param2, (GLvoid*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBlendFuncSeparateEXTCmd()
 *
 *  Handles the OpenGL glBlendFuncSeparateEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBlendFuncSeparateEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBlendFuncSeparateEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 925, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[925];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLenum)param3, (GLenum)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexWeightfEXTCmd()
 *
 *  Handles the OpenGL glVertexWeightfEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexWeightfEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexWeightfEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 926, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[926];
    ((GLfunction_void_float)funcPtr->funcPtr)((GLfloat)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexWeightfvEXTCmd()
 *
 *  Handles the OpenGL glVertexWeightfvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexWeightfvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *param1;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexWeightfvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 927, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &param1, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[927];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVertexWeightPointerEXTCmd()
 *
 *  Handles the OpenGL glVertexWeightPointerEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVertexWeightPointerEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVertexWeightPointerEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 928, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[928];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLsizei)param1, (GLenum)param2, (GLsizei)param3, (GLvoid*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSampleMaskEXTCmd()
 *
 *  Handles the OpenGL glSampleMaskEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSampleMaskEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSampleMaskEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 929, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[929];
    ((GLfunction_void_float_int)funcPtr->funcPtr)((GLclampf)param1, (GLboolean)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSamplePatternEXTCmd()
 *
 *  Handles the OpenGL glSamplePatternEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSamplePatternEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSamplePatternEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 930, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[930];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBeginVertexShaderEXTCmd()
 *
 *  Handles the OpenGL glBeginVertexShaderEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBeginVertexShaderEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;

    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBeginVertexShaderEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 931, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[931];
    ((GLfunction_void_)funcPtr->funcPtr)();
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glEndVertexShaderEXTCmd()
 *
 *  Handles the OpenGL glEndVertexShaderEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glEndVertexShaderEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;

    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glEndVertexShaderEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 932, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[932];
    ((GLfunction_void_)funcPtr->funcPtr)();
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBindVertexShaderEXTCmd()
 *
 *  Handles the OpenGL glBindVertexShaderEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBindVertexShaderEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBindVertexShaderEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 933, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[933];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLuint)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGenVertexShadersEXTCmd()
 *
 *  Handles the OpenGL glGenVertexShadersEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGenVertexShadersEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;
     GLuint retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGenVertexShadersEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 934, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[934];
    retVal = ((GLfunction_GLuint_int)funcPtr->funcPtr)((GLuint)param1);
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDeleteVertexShaderEXTCmd()
 *
 *  Handles the OpenGL glDeleteVertexShaderEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDeleteVertexShaderEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDeleteVertexShaderEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 935, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[935];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLuint)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glShaderOp1EXTCmd()
 *
 *  Handles the OpenGL glShaderOp1EXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glShaderOp1EXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glShaderOp1EXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 936, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[936];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLuint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glShaderOp2EXTCmd()
 *
 *  Handles the OpenGL glShaderOp2EXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glShaderOp2EXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glShaderOp2EXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 937, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[937];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLuint)param3, (GLuint)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glShaderOp3EXTCmd()
 *
 *  Handles the OpenGL glShaderOp3EXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glShaderOp3EXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glShaderOp3EXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 938, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[938];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLuint)param2, (GLuint)param3, (GLuint)param4, (GLuint)param5);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSwizzleEXTCmd()
 *
 *  Handles the OpenGL glSwizzleEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSwizzleEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSwizzleEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 939, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[939];
    ((GLfunction_void_int_int_int_int_int_int)funcPtr->funcPtr)((GLuint)param1, (GLuint)param2, (GLenum)param3, (GLenum)param4, (GLenum)param5, (GLenum)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glWriteMaskEXTCmd()
 *
 *  Handles the OpenGL glWriteMaskEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glWriteMaskEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
    int param6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glWriteMaskEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 940, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[940];
    ((GLfunction_void_int_int_int_int_int_int)funcPtr->funcPtr)((GLuint)param1, (GLuint)param2, (GLenum)param3, (GLenum)param4, (GLenum)param5, (GLenum)param6);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glInsertComponentEXTCmd()
 *
 *  Handles the OpenGL glInsertComponentEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glInsertComponentEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glInsertComponentEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 941, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[941];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLuint)param1, (GLuint)param2, (GLuint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glExtractComponentEXTCmd()
 *
 *  Handles the OpenGL glExtractComponentEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glExtractComponentEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glExtractComponentEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 942, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[942];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLuint)param1, (GLuint)param2, (GLuint)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGenSymbolsEXTCmd()
 *
 *  Handles the OpenGL glGenSymbolsEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGenSymbolsEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    int param4;
    TclGLFunc *funcPtr;
     GLuint retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGenSymbolsEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 943, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[943];
    retVal = ((GLfunction_GLuint_int_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLenum)param3, (GLuint)param4);
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSetInvariantEXTCmd()
 *
 *  Handles the OpenGL glSetInvariantEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSetInvariantEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSetInvariantEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 944, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[944];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLvoid*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glSetLocalConstantEXTCmd()
 *
 *  Handles the OpenGL glSetLocalConstantEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glSetLocalConstantEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glSetLocalConstantEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 945, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[945];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLvoid*)param3);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVariantbvEXTCmd()
 *
 *  Handles the OpenGL glVariantbvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVariantbvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVariantbvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 946, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[946];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLbyte*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVariantsvEXTCmd()
 *
 *  Handles the OpenGL glVariantsvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVariantsvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVariantsvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 947, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[947];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLshort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVariantivEXTCmd()
 *
 *  Handles the OpenGL glVariantivEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVariantivEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVariantivEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 948, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[948];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVariantfvEXTCmd()
 *
 *  Handles the OpenGL glVariantfvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVariantfvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVariantfvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 949, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[949];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLfloat*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVariantdvEXTCmd()
 *
 *  Handles the OpenGL glVariantdvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVariantdvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVariantdvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 950, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[950];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLdouble*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVariantubvEXTCmd()
 *
 *  Handles the OpenGL glVariantubvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVariantubvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVariantubvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 951, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[951];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLubyte*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVariantusvEXTCmd()
 *
 *  Handles the OpenGL glVariantusvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVariantusvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVariantusvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 952, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[952];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLushort*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVariantuivEXTCmd()
 *
 *  Handles the OpenGL glVariantuivEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVariantuivEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    void *param2;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVariantuivEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 953, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &param2, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[953];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLuint*)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glVariantPointerEXTCmd()
 *
 *  Handles the OpenGL glVariantPointerEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glVariantPointerEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glVariantPointerEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 954, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[954];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLuint)param3, (GLvoid*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glEnableVariantClientStateEXTCmd()
 *
 *  Handles the OpenGL glEnableVariantClientStateEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glEnableVariantClientStateEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glEnableVariantClientStateEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 955, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[955];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLuint)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDisableVariantClientStateEXTCmd()
 *
 *  Handles the OpenGL glDisableVariantClientStateEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDisableVariantClientStateEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDisableVariantClientStateEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 956, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[956];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLuint)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBindLightParameterEXTCmd()
 *
 *  Handles the OpenGL glBindLightParameterEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBindLightParameterEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;
     GLuint retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBindLightParameterEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 957, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[957];
    retVal = ((GLfunction_GLuint_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2);
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBindMaterialParameterEXTCmd()
 *
 *  Handles the OpenGL glBindMaterialParameterEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBindMaterialParameterEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;
     GLuint retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBindMaterialParameterEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 958, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[958];
    retVal = ((GLfunction_GLuint_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2);
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBindTexGenParameterEXTCmd()
 *
 *  Handles the OpenGL glBindTexGenParameterEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBindTexGenParameterEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    int param3;
    TclGLFunc *funcPtr;
     GLuint retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBindTexGenParameterEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 959, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[959];
    retVal = ((GLfunction_GLuint_int_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2, (GLenum)param3);
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBindTextureUnitParameterEXTCmd()
 *
 *  Handles the OpenGL glBindTextureUnitParameterEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBindTextureUnitParameterEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;
     GLuint retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBindTextureUnitParameterEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 960, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[960];
    retVal = ((GLfunction_GLuint_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2);
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBindParameterEXTCmd()
 *
 *  Handles the OpenGL glBindParameterEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBindParameterEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;
     GLuint retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBindParameterEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 961, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[961];
    retVal = ((GLfunction_GLuint_int)funcPtr->funcPtr)((GLenum)param1);
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glIsVariantEnabledEXTCmd()
 *
 *  Handles the OpenGL glIsVariantEnabledEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glIsVariantEnabledEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;
     GLboolean retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glIsVariantEnabledEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 962, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[962];
    retVal = ((GLfunction_GLboolean_int_int)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2);
    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetVariantBooleanvEXTCmd()
 *
 *  Handles the OpenGL glGetVariantBooleanvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetVariantBooleanvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetVariantBooleanvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 963, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[963];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLboolean*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetVariantIntegervEXTCmd()
 *
 *  Handles the OpenGL glGetVariantIntegervEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetVariantIntegervEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetVariantIntegervEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 964, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[964];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetVariantFloatvEXTCmd()
 *
 *  Handles the OpenGL glGetVariantFloatvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetVariantFloatvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetVariantFloatvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 965, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[965];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetVariantPointervEXTCmd()
 *
 *  Handles the OpenGL glGetVariantPointervEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetVariantPointervEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void **param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetVariantPointervEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 966, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[966];
    ((GLfunction_void_int_int_voidPtrPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLvoid**)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetInvariantBooleanvEXTCmd()
 *
 *  Handles the OpenGL glGetInvariantBooleanvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetInvariantBooleanvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetInvariantBooleanvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 967, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[967];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLboolean*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetInvariantIntegervEXTCmd()
 *
 *  Handles the OpenGL glGetInvariantIntegervEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetInvariantIntegervEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetInvariantIntegervEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 968, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[968];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetInvariantFloatvEXTCmd()
 *
 *  Handles the OpenGL glGetInvariantFloatvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetInvariantFloatvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetInvariantFloatvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 969, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[969];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetLocalConstantBooleanvEXTCmd()
 *
 *  Handles the OpenGL glGetLocalConstantBooleanvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetLocalConstantBooleanvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetLocalConstantBooleanvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 970, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[970];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLboolean*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetLocalConstantIntegervEXTCmd()
 *
 *  Handles the OpenGL glGetLocalConstantIntegervEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetLocalConstantIntegervEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetLocalConstantIntegervEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 971, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[971];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLint*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetLocalConstantFloatvEXTCmd()
 *
 *  Handles the OpenGL glGetLocalConstantFloatvEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetLocalConstantFloatvEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3 = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetLocalConstantFloatvEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 972, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[972];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLenum)param2, (GLfloat*)param3);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength3, param3) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glActiveStencilFaceEXTCmd()
 *
 *  Handles the OpenGL glActiveStencilFaceEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glActiveStencilFaceEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glActiveStencilFaceEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 973, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[973];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)param1);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glProgramNamedParameter4fNVCmd()
 *
 *  Handles the OpenGL glProgramNamedParameter4fNV command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glProgramNamedParameter4fNVCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    double param4;
    double param5;
    double param6;
    double param7;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glProgramNamedParameter4fNVCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 974, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[974];
    ((GLfunction_void_int_int_voidPtr_float_float_float_float)funcPtr->funcPtr)((GLuint)param1, (GLsizei)param2, (GLubyte*)param3, (GLfloat)param4, (GLfloat)param5, (GLfloat)param6, (GLfloat)param7);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glProgramNamedParameter4dNVCmd()
 *
 *  Handles the OpenGL glProgramNamedParameter4dNV command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glProgramNamedParameter4dNVCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    double param4;
    double param5;
    double param6;
    double param7;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glProgramNamedParameter4dNVCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 975, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &param5) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[6], &param6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[7], &param7) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[975];
    ((GLfunction_void_int_int_voidPtr_double_double_double_double)funcPtr->funcPtr)((GLuint)param1, (GLsizei)param2, (GLubyte*)param3, (GLdouble)param4, (GLdouble)param5, (GLdouble)param6, (GLdouble)param7);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glProgramNamedParameter4fvNVCmd()
 *
 *  Handles the OpenGL glProgramNamedParameter4fvNV command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glProgramNamedParameter4fvNVCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glProgramNamedParameter4fvNVCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 976, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[976];
    ((GLfunction_void_int_int_voidPtr_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLsizei)param2, (GLubyte*)param3, (GLfloat*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glProgramNamedParameter4dvNVCmd()
 *
 *  Handles the OpenGL glProgramNamedParameter4dvNV command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glProgramNamedParameter4dvNVCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    void *param4;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glProgramNamedParameter4dvNVCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 977, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &param4, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[977];
    ((GLfunction_void_int_int_voidPtr_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLsizei)param2, (GLubyte*)param3, (GLdouble*)param4);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetProgramNamedParameterfvNVCmd()
 *
 *  Handles the OpenGL glGetProgramNamedParameterfvNV command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetProgramNamedParameterfvNVCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    void *param4 = NULL;
    int paramLength4 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetProgramNamedParameterfvNVCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 978, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[978];
    ((GLfunction_void_int_int_voidPtr_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLsizei)param2, (GLubyte*)param3, (GLfloat*)param4);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glGetProgramNamedParameterdvNVCmd()
 *
 *  Handles the OpenGL glGetProgramNamedParameterdvNV command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glGetProgramNamedParameterdvNVCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    void *param3;
    int paramLength3;
    void *param4 = NULL;
    int paramLength4 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glGetProgramNamedParameterdvNVCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 979, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &param3, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[979];
    ((GLfunction_void_int_int_voidPtr_voidPtr)funcPtr->funcPtr)((GLuint)param1, (GLsizei)param2, (GLubyte*)param3, (GLdouble*)param4);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength4, param4) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glDepthBoundsEXTCmd()
 *
 *  Handles the OpenGL glDepthBoundsEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glDepthBoundsEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double param1;
    double param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glDepthBoundsEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 980, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[980];
    ((GLfunction_void_double_double)funcPtr->funcPtr)((GLclampd)param1, (GLclampd)param2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_glBlendEquationSeparateEXTCmd()
 *
 *  Handles the OpenGL glBlendEquationSeparateEXT command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_glBlendEquationSeparateEXTCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int param1;
    int param2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_glBlendEquationSeparateEXTCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 981, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &param1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &param2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[981];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)param1, (GLenum)param2);
    return GetGLError(interp, infoPtr);
}
