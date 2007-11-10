
/*
 * ------------------------------------------------------------------------
 *  TclGL_glClearIndexCmd()
 *
 *  Handles the OpenGL glClearIndex command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glClearIndexCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double c;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClearIndexCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 0, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &c) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[0];
    ((GLfunction_void_float)funcPtr->funcPtr)((GLfloat)c);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glClearColorCmd()
 *
 *  Handles the OpenGL glClearColor command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glClearColorCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double red;
    double green;
    double blue;
    double alpha;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClearColorCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 1, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &alpha) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[1];
    ((GLfunction_void_float_float_float_float)funcPtr->funcPtr)((GLclampf)red, (GLclampf)green, (GLclampf)blue, (GLclampf)alpha);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glClearCmd()
 *
 *  Handles the OpenGL glClear command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glClearCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mask;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClearCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 2, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetBitfieldParam(interp, infoPtr, objv[1], &mask) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[2];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLbitfield)mask);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIndexMaskCmd()
 *
 *  Handles the OpenGL glIndexMask command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIndexMaskCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mask;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexMaskCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 3, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &mask) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[3];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLuint)mask);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColorMaskCmd()
 *
 *  Handles the OpenGL glColorMask command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColorMaskCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int red;
    int green;
    int blue;
    int alpha;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColorMaskCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 4, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &alpha) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[4];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLboolean)red, (GLboolean)green, (GLboolean)blue, (GLboolean)alpha);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glAlphaFuncCmd()
 *
 *  Handles the OpenGL glAlphaFunc command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glAlphaFuncCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int func;
    double ref;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glAlphaFuncCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 5, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &func) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &ref) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[5];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLenum)func, (GLclampf)ref);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glBlendFuncCmd()
 *
 *  Handles the OpenGL glBlendFunc command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glBlendFuncCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int sfactor;
    int dfactor;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glBlendFuncCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 6, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &sfactor) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &dfactor) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[6];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)sfactor, (GLenum)dfactor);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLogicOpCmd()
 *
 *  Handles the OpenGL glLogicOp command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLogicOpCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int opcode;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLogicOpCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 7, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &opcode) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[7];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)opcode);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCullFaceCmd()
 *
 *  Handles the OpenGL glCullFace command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCullFaceCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mode;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCullFaceCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 8, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[8];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)mode);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glFrontFaceCmd()
 *
 *  Handles the OpenGL glFrontFace command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glFrontFaceCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mode;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFrontFaceCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 9, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[9];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)mode);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPointSizeCmd()
 *
 *  Handles the OpenGL glPointSize command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPointSizeCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double size;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPointSizeCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 10, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &size) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[10];
    ((GLfunction_void_float)funcPtr->funcPtr)((GLfloat)size);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLineWidthCmd()
 *
 *  Handles the OpenGL glLineWidth command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLineWidthCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double width;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLineWidthCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 11, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[11];
    ((GLfunction_void_float)funcPtr->funcPtr)((GLfloat)width);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLineStippleCmd()
 *
 *  Handles the OpenGL glLineStipple command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLineStippleCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int factor;
    int pattern;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLineStippleCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 12, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &factor) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &pattern) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[12];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLint)factor, (GLushort)pattern);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPolygonModeCmd()
 *
 *  Handles the OpenGL glPolygonMode command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPolygonModeCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int face;
    int mode;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPolygonModeCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 13, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &face) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[13];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)face, (GLenum)mode);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPolygonOffsetCmd()
 *
 *  Handles the OpenGL glPolygonOffset command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPolygonOffsetCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double factor;
    double units;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPolygonOffsetCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 14, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &factor) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &units) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[14];
    ((GLfunction_void_float_float)funcPtr->funcPtr)((GLfloat)factor, (GLfloat)units);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPolygonStippleCmd()
 *
 *  Handles the OpenGL glPolygonStipple command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPolygonStippleCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *mask;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPolygonStippleCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 15, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &mask, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[15];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLubyte*)mask);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetPolygonStippleCmd()
 *
 *  Handles the OpenGL glGetPolygonStipple command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetPolygonStippleCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *mask = NULL;
    int paramLength0 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetPolygonStippleCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 16, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[16];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLubyte*)mask);
    if (SetPtrOutParam(interp, infoPtr, objv[1], paramLength0, mask) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEdgeFlagCmd()
 *
 *  Handles the OpenGL glEdgeFlag command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEdgeFlagCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int flag;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEdgeFlagCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 17, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &flag) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[17];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLboolean)flag);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEdgeFlagvCmd()
 *
 *  Handles the OpenGL glEdgeFlagv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEdgeFlagvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *flag;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEdgeFlagvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 18, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &flag, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[18];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLboolean*)flag);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glScissorCmd()
 *
 *  Handles the OpenGL glScissor command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glScissorCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    int width;
    int height;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glScissorCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 19, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[19];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLint)x, (GLint)y, (GLsizei)width, (GLsizei)height);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glClipPlaneCmd()
 *
 *  Handles the OpenGL glClipPlane command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glClipPlaneCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int plane;
    void *equation;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClipPlaneCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 20, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &plane) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &equation, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[20];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)plane, (GLdouble*)equation);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetClipPlaneCmd()
 *
 *  Handles the OpenGL glGetClipPlane command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetClipPlaneCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int plane;
    void *equation = NULL;
    int paramLength1 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetClipPlaneCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 21, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &plane) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[21];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)plane, (GLdouble*)equation);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength1, equation) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glDrawBufferCmd()
 *
 *  Handles the OpenGL glDrawBuffer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glDrawBufferCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mode;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDrawBufferCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 22, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[22];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)mode);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glReadBufferCmd()
 *
 *  Handles the OpenGL glReadBuffer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glReadBufferCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mode;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glReadBufferCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 23, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[23];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)mode);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEnableCmd()
 *
 *  Handles the OpenGL glEnable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEnableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int cap;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEnableCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 24, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &cap) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[24];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)cap);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glDisableCmd()
 *
 *  Handles the OpenGL glDisable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glDisableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int cap;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDisableCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 25, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &cap) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[25];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)cap);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIsEnabledCmd()
 *
 *  Handles the OpenGL glIsEnabled command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIsEnabledCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int cap;
    TclGLFunc *funcPtr;
    GLboolean retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIsEnabledCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 26, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &cap) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[26];
    retVal = ((GLfunction_GLboolean_int)funcPtr->funcPtr)((GLenum)cap);
    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEnableClientStateCmd()
 *
 *  Handles the OpenGL glEnableClientState command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEnableClientStateCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int cap;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEnableClientStateCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 27, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &cap) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[27];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)cap);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glDisableClientStateCmd()
 *
 *  Handles the OpenGL glDisableClientState command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glDisableClientStateCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int cap;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDisableClientStateCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 28, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &cap) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[28];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)cap);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetBooleanvCmd()
 *
 *  Handles the OpenGL glGetBooleanv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetBooleanvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    void *params = NULL;
    int paramLength1 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetBooleanvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 29, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[29];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)pname, (GLboolean*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength1, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetDoublevCmd()
 *
 *  Handles the OpenGL glGetDoublev command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetDoublevCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    void *params = NULL;
    int paramLength1 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetDoublevCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 30, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[30];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)pname, (GLdouble*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength1, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetFloatvCmd()
 *
 *  Handles the OpenGL glGetFloatv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetFloatvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    void *params = NULL;
    int paramLength1 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetFloatvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 31, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[31];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)pname, (GLfloat*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength1, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetIntegervCmd()
 *
 *  Handles the OpenGL glGetIntegerv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetIntegervCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    void *params = NULL;
    int paramLength1 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetIntegervCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 32, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[32];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)pname, (GLint*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength1, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPushAttribCmd()
 *
 *  Handles the OpenGL glPushAttrib command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPushAttribCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mask;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPushAttribCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 33, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetBitfieldParam(interp, infoPtr, objv[1], &mask) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[33];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLbitfield)mask);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPopAttribCmd()
 *
 *  Handles the OpenGL glPopAttrib command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPopAttribCmd(
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
    TclGLShowArgs(1, "TclGL_glPopAttribCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 34, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[34];
    ((GLfunction_void_)funcPtr->funcPtr)();
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPushClientAttribCmd()
 *
 *  Handles the OpenGL glPushClientAttrib command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPushClientAttribCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mask;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPushClientAttribCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 35, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetBitfieldParam(interp, infoPtr, objv[1], &mask) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[35];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLbitfield)mask);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPopClientAttribCmd()
 *
 *  Handles the OpenGL glPopClientAttrib command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPopClientAttribCmd(
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
    TclGLShowArgs(1, "TclGL_glPopClientAttribCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 36, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[36];
    ((GLfunction_void_)funcPtr->funcPtr)();
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRenderModeCmd()
 *
 *  Handles the OpenGL glRenderMode command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRenderModeCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mode;
    TclGLFunc *funcPtr;
    GLint retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRenderModeCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 37, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[37];
    retVal = ((GLfunction_GLint_int)funcPtr->funcPtr)((GLenum)mode);
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetErrorCmd()
 *
 *  Handles the OpenGL glGetError command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetErrorCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;

    TclGLFunc *funcPtr;
    GLenum retVal;
    const char *enumStr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetErrorCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 38, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[38];
    retVal = ((GLfunction_GLenum_)funcPtr->funcPtr)();
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefineStrings, (char *)retVal);
    if (hPtr == NULL) {
        char buf[20];
        sprintf(buf, "0x%08x", retVal);
        Tcl_AppendResult(interp, "no such define value: \"",
            buf, "\"", NULL);
        return TCL_ERROR;
    }
    enumStr = (const char *)Tcl_GetHashValue(hPtr);
    Tcl_SetObjResult(interp, Tcl_NewStringObj(enumStr, -1));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glFinishCmd()
 *
 *  Handles the OpenGL glFinish command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glFinishCmd(
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
    TclGLShowArgs(1, "TclGL_glFinishCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 39, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[39];
    ((GLfunction_void_)funcPtr->funcPtr)();
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glFlushCmd()
 *
 *  Handles the OpenGL glFlush command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glFlushCmd(
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
    TclGLShowArgs(1, "TclGL_glFlushCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 40, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[40];
    ((GLfunction_void_)funcPtr->funcPtr)();
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glHintCmd()
 *
 *  Handles the OpenGL glHint command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glHintCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int mode;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glHintCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 41, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[41];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)target, (GLenum)mode);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glClearDepthCmd()
 *
 *  Handles the OpenGL glClearDepth command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glClearDepthCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double depth;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClearDepthCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 42, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &depth) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[42];
    ((GLfunction_void_double)funcPtr->funcPtr)((GLclampd)depth);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glDepthFuncCmd()
 *
 *  Handles the OpenGL glDepthFunc command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glDepthFuncCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int func;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDepthFuncCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 43, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &func) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[43];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)func);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glDepthMaskCmd()
 *
 *  Handles the OpenGL glDepthMask command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glDepthMaskCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int flag;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDepthMaskCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 44, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &flag) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[44];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLboolean)flag);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glDepthRangeCmd()
 *
 *  Handles the OpenGL glDepthRange command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glDepthRangeCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double near_val;
    double far_val;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDepthRangeCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 45, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &near_val) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &far_val) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[45];
    ((GLfunction_void_double_double)funcPtr->funcPtr)((GLclampd)near_val, (GLclampd)far_val);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glClearAccumCmd()
 *
 *  Handles the OpenGL glClearAccum command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glClearAccumCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double red;
    double green;
    double blue;
    double alpha;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClearAccumCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 46, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &alpha) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[46];
    ((GLfunction_void_float_float_float_float)funcPtr->funcPtr)((GLfloat)red, (GLfloat)green, (GLfloat)blue, (GLfloat)alpha);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glAccumCmd()
 *
 *  Handles the OpenGL glAccum command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glAccumCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int op;
    double value;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glAccumCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 47, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &op) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &value) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[47];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLenum)op, (GLfloat)value);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMatrixModeCmd()
 *
 *  Handles the OpenGL glMatrixMode command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMatrixModeCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mode;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMatrixModeCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 48, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[48];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)mode);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glOrthoCmd()
 *
 *  Handles the OpenGL glOrtho command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glOrthoCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double left;
    double right;
    double bottom;
    double top;
    double near_val;
    double far_val;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glOrthoCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 49, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &left) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &right) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &bottom) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &top) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &near_val) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[6], &far_val) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[49];
    ((GLfunction_void_double_double_double_double_double_double)funcPtr->funcPtr)((GLdouble)left, (GLdouble)right, (GLdouble)bottom, (GLdouble)top, (GLdouble)near_val, (GLdouble)far_val);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glFrustumCmd()
 *
 *  Handles the OpenGL glFrustum command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glFrustumCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double left;
    double right;
    double bottom;
    double top;
    double near_val;
    double far_val;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFrustumCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 50, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &left) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &right) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &bottom) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &top) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &near_val) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[6], &far_val) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[50];
    ((GLfunction_void_double_double_double_double_double_double)funcPtr->funcPtr)((GLdouble)left, (GLdouble)right, (GLdouble)bottom, (GLdouble)top, (GLdouble)near_val, (GLdouble)far_val);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glViewportCmd()
 *
 *  Handles the OpenGL glViewport command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glViewportCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    int width;
    int height;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glViewportCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 51, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[51];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLint)x, (GLint)y, (GLsizei)width, (GLsizei)height);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPushMatrixCmd()
 *
 *  Handles the OpenGL glPushMatrix command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPushMatrixCmd(
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
    TclGLShowArgs(1, "TclGL_glPushMatrixCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 52, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[52];
    ((GLfunction_void_)funcPtr->funcPtr)();
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPopMatrixCmd()
 *
 *  Handles the OpenGL glPopMatrix command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPopMatrixCmd(
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
    TclGLShowArgs(1, "TclGL_glPopMatrixCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 53, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[53];
    ((GLfunction_void_)funcPtr->funcPtr)();
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLoadIdentityCmd()
 *
 *  Handles the OpenGL glLoadIdentity command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLoadIdentityCmd(
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
    TclGLShowArgs(1, "TclGL_glLoadIdentityCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 54, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[54];
    ((GLfunction_void_)funcPtr->funcPtr)();
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLoadMatrixdCmd()
 *
 *  Handles the OpenGL glLoadMatrixd command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLoadMatrixdCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *m;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLoadMatrixdCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 55, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &m, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[55];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)m);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLoadMatrixfCmd()
 *
 *  Handles the OpenGL glLoadMatrixf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLoadMatrixfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *m;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLoadMatrixfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 56, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &m, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[56];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)m);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultMatrixdCmd()
 *
 *  Handles the OpenGL glMultMatrixd command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultMatrixdCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *m;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultMatrixdCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 57, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &m, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[57];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)m);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultMatrixfCmd()
 *
 *  Handles the OpenGL glMultMatrixf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultMatrixfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *m;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultMatrixfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 58, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &m, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[58];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)m);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRotatedCmd()
 *
 *  Handles the OpenGL glRotated command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRotatedCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double angle;
    double x;
    double y;
    double z;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRotatedCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 59, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &angle) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[59];
    ((GLfunction_void_double_double_double_double)funcPtr->funcPtr)((GLdouble)angle, (GLdouble)x, (GLdouble)y, (GLdouble)z);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRotatefCmd()
 *
 *  Handles the OpenGL glRotatef command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRotatefCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double angle;
    double x;
    double y;
    double z;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRotatefCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 60, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &angle) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[60];
    ((GLfunction_void_float_float_float_float)funcPtr->funcPtr)((GLfloat)angle, (GLfloat)x, (GLfloat)y, (GLfloat)z);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glScaledCmd()
 *
 *  Handles the OpenGL glScaled command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glScaledCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    double z;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glScaledCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 61, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[61];
    ((GLfunction_void_double_double_double)funcPtr->funcPtr)((GLdouble)x, (GLdouble)y, (GLdouble)z);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glScalefCmd()
 *
 *  Handles the OpenGL glScalef command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glScalefCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    double z;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glScalefCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 62, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[62];
    ((GLfunction_void_float_float_float)funcPtr->funcPtr)((GLfloat)x, (GLfloat)y, (GLfloat)z);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTranslatedCmd()
 *
 *  Handles the OpenGL glTranslated command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTranslatedCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    double z;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTranslatedCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 63, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[63];
    ((GLfunction_void_double_double_double)funcPtr->funcPtr)((GLdouble)x, (GLdouble)y, (GLdouble)z);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTranslatefCmd()
 *
 *  Handles the OpenGL glTranslatef command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTranslatefCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    double z;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTranslatefCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 64, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[64];
    ((GLfunction_void_float_float_float)funcPtr->funcPtr)((GLfloat)x, (GLfloat)y, (GLfloat)z);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIsListCmd()
 *
 *  Handles the OpenGL glIsList command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIsListCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int list;
    TclGLFunc *funcPtr;
    GLboolean retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIsListCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 65, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &list) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[65];
    retVal = ((GLfunction_GLboolean_int)funcPtr->funcPtr)((GLuint)list);
    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glDeleteListsCmd()
 *
 *  Handles the OpenGL glDeleteLists command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glDeleteListsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int list;
    int range;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDeleteListsCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 66, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &list) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &range) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[66];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLuint)list, (GLsizei)range);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGenListsCmd()
 *
 *  Handles the OpenGL glGenLists command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGenListsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int range;
    TclGLFunc *funcPtr;
    GLuint retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGenListsCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 67, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &range) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[67];
    retVal = ((GLfunction_GLuint_int)funcPtr->funcPtr)((GLsizei)range);
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glNewListCmd()
 *
 *  Handles the OpenGL glNewList command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glNewListCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int list;
    int mode;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNewListCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 68, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &list) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[68];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLuint)list, (GLenum)mode);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEndListCmd()
 *
 *  Handles the OpenGL glEndList command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEndListCmd(
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
    TclGLShowArgs(1, "TclGL_glEndListCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 69, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[69];
    ((GLfunction_void_)funcPtr->funcPtr)();
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCallListCmd()
 *
 *  Handles the OpenGL glCallList command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCallListCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int list;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCallListCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 70, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &list) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[70];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLuint)list);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCallListsCmd()
 *
 *  Handles the OpenGL glCallLists command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCallListsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int n;
    int type;
    void *lists;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCallListsCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 71, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &n) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &lists, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[71];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLsizei)n, (GLenum)type, (GLvoid*)lists);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glListBaseCmd()
 *
 *  Handles the OpenGL glListBase command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glListBaseCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int base;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glListBaseCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 72, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &base) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[72];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLuint)base);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glBeginCmd()
 *
 *  Handles the OpenGL glBegin command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glBeginCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mode;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glBeginCmd", objc, objv);
    infoPtr->noGLGetError = 1;
    if (CheckNumParams(interp, infoPtr, 73, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[73];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)mode);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEndCmd()
 *
 *  Handles the OpenGL glEnd command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEndCmd(
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
    TclGLShowArgs(1, "TclGL_glEndCmd", objc, objv);
    infoPtr->noGLGetError = 0;
    if (CheckNumParams(interp, infoPtr, 74, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[74];
    ((GLfunction_void_)funcPtr->funcPtr)();
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex2dCmd()
 *
 *  Handles the OpenGL glVertex2d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex2dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 75, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[75];
    ((GLfunction_void_double_double)funcPtr->funcPtr)((GLdouble)x, (GLdouble)y);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex2fCmd()
 *
 *  Handles the OpenGL glVertex2f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex2fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 76, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[76];
    ((GLfunction_void_float_float)funcPtr->funcPtr)((GLfloat)x, (GLfloat)y);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex2iCmd()
 *
 *  Handles the OpenGL glVertex2i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex2iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 77, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[77];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLint)x, (GLint)y);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex2sCmd()
 *
 *  Handles the OpenGL glVertex2s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex2sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 78, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[78];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLshort)x, (GLshort)y);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex3dCmd()
 *
 *  Handles the OpenGL glVertex3d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex3dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    double z;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 79, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[79];
    ((GLfunction_void_double_double_double)funcPtr->funcPtr)((GLdouble)x, (GLdouble)y, (GLdouble)z);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex3fCmd()
 *
 *  Handles the OpenGL glVertex3f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex3fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    double z;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 80, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[80];
    ((GLfunction_void_float_float_float)funcPtr->funcPtr)((GLfloat)x, (GLfloat)y, (GLfloat)z);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex3iCmd()
 *
 *  Handles the OpenGL glVertex3i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex3iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    int z;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 81, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[81];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLint)x, (GLint)y, (GLint)z);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex3sCmd()
 *
 *  Handles the OpenGL glVertex3s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex3sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    int z;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 82, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[82];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLshort)x, (GLshort)y, (GLshort)z);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex4dCmd()
 *
 *  Handles the OpenGL glVertex4d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex4dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    double z;
    double w;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 83, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &w) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[83];
    ((GLfunction_void_double_double_double_double)funcPtr->funcPtr)((GLdouble)x, (GLdouble)y, (GLdouble)z, (GLdouble)w);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex4fCmd()
 *
 *  Handles the OpenGL glVertex4f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex4fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    double z;
    double w;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 84, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &w) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[84];
    ((GLfunction_void_float_float_float_float)funcPtr->funcPtr)((GLfloat)x, (GLfloat)y, (GLfloat)z, (GLfloat)w);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex4iCmd()
 *
 *  Handles the OpenGL glVertex4i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex4iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    int z;
    int w;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 85, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &w) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[85];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLint)x, (GLint)y, (GLint)z, (GLint)w);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex4sCmd()
 *
 *  Handles the OpenGL glVertex4s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex4sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    int z;
    int w;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 86, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &w) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[86];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLshort)x, (GLshort)y, (GLshort)z, (GLshort)w);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex2dvCmd()
 *
 *  Handles the OpenGL glVertex2dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex2dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 87, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[87];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex2fvCmd()
 *
 *  Handles the OpenGL glVertex2fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex2fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 88, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[88];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex2ivCmd()
 *
 *  Handles the OpenGL glVertex2iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex2ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 89, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[89];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex2svCmd()
 *
 *  Handles the OpenGL glVertex2sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex2svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 90, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[90];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex3dvCmd()
 *
 *  Handles the OpenGL glVertex3dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex3dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 91, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[91];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex3fvCmd()
 *
 *  Handles the OpenGL glVertex3fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex3fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 92, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[92];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex3ivCmd()
 *
 *  Handles the OpenGL glVertex3iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex3ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 93, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[93];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex3svCmd()
 *
 *  Handles the OpenGL glVertex3sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex3svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 94, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[94];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex4dvCmd()
 *
 *  Handles the OpenGL glVertex4dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex4dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 95, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[95];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex4fvCmd()
 *
 *  Handles the OpenGL glVertex4fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex4fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 96, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[96];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex4ivCmd()
 *
 *  Handles the OpenGL glVertex4iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex4ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 97, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[97];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertex4svCmd()
 *
 *  Handles the OpenGL glVertex4sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertex4svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 98, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[98];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glNormal3bCmd()
 *
 *  Handles the OpenGL glNormal3b command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glNormal3bCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int nx;
    int ny;
    int nz;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3bCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 99, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &nx) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &ny) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &nz) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[99];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLbyte)nx, (GLbyte)ny, (GLbyte)nz);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glNormal3dCmd()
 *
 *  Handles the OpenGL glNormal3d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glNormal3dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double nx;
    double ny;
    double nz;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 100, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &nx) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &ny) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &nz) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[100];
    ((GLfunction_void_double_double_double)funcPtr->funcPtr)((GLdouble)nx, (GLdouble)ny, (GLdouble)nz);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glNormal3fCmd()
 *
 *  Handles the OpenGL glNormal3f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glNormal3fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double nx;
    double ny;
    double nz;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 101, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &nx) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &ny) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &nz) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[101];
    ((GLfunction_void_float_float_float)funcPtr->funcPtr)((GLfloat)nx, (GLfloat)ny, (GLfloat)nz);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glNormal3iCmd()
 *
 *  Handles the OpenGL glNormal3i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glNormal3iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int nx;
    int ny;
    int nz;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 102, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &nx) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &ny) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &nz) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[102];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLint)nx, (GLint)ny, (GLint)nz);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glNormal3sCmd()
 *
 *  Handles the OpenGL glNormal3s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glNormal3sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int nx;
    int ny;
    int nz;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 103, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &nx) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &ny) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &nz) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[103];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLshort)nx, (GLshort)ny, (GLshort)nz);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glNormal3bvCmd()
 *
 *  Handles the OpenGL glNormal3bv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glNormal3bvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3bvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 104, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[104];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLbyte*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glNormal3dvCmd()
 *
 *  Handles the OpenGL glNormal3dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glNormal3dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 105, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[105];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glNormal3fvCmd()
 *
 *  Handles the OpenGL glNormal3fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glNormal3fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 106, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[106];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glNormal3ivCmd()
 *
 *  Handles the OpenGL glNormal3iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glNormal3ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 107, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[107];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glNormal3svCmd()
 *
 *  Handles the OpenGL glNormal3sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glNormal3svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 108, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[108];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIndexdCmd()
 *
 *  Handles the OpenGL glIndexd command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIndexdCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double c;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexdCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 109, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &c) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[109];
    ((GLfunction_void_double)funcPtr->funcPtr)((GLdouble)c);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIndexfCmd()
 *
 *  Handles the OpenGL glIndexf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIndexfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double c;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 110, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &c) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[110];
    ((GLfunction_void_float)funcPtr->funcPtr)((GLfloat)c);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIndexiCmd()
 *
 *  Handles the OpenGL glIndexi command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIndexiCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int c;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexiCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 111, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &c) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[111];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLint)c);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIndexsCmd()
 *
 *  Handles the OpenGL glIndexs command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIndexsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int c;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexsCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 112, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &c) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[112];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLshort)c);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIndexubCmd()
 *
 *  Handles the OpenGL glIndexub command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIndexubCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int c;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexubCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 113, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &c) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[113];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLubyte)c);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIndexdvCmd()
 *
 *  Handles the OpenGL glIndexdv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIndexdvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *c;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexdvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 114, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &c, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[114];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)c);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIndexfvCmd()
 *
 *  Handles the OpenGL glIndexfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIndexfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *c;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 115, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &c, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[115];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)c);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIndexivCmd()
 *
 *  Handles the OpenGL glIndexiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIndexivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *c;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 116, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &c, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[116];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)c);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIndexsvCmd()
 *
 *  Handles the OpenGL glIndexsv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIndexsvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *c;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexsvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 117, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &c, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[117];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)c);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIndexubvCmd()
 *
 *  Handles the OpenGL glIndexubv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIndexubvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *c;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexubvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 118, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &c, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[118];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLubyte*)c);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3bCmd()
 *
 *  Handles the OpenGL glColor3b command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3bCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int red;
    int green;
    int blue;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3bCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 119, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[119];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLbyte)red, (GLbyte)green, (GLbyte)blue);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3dCmd()
 *
 *  Handles the OpenGL glColor3d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double red;
    double green;
    double blue;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 120, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[120];
    ((GLfunction_void_double_double_double)funcPtr->funcPtr)((GLdouble)red, (GLdouble)green, (GLdouble)blue);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3fCmd()
 *
 *  Handles the OpenGL glColor3f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double red;
    double green;
    double blue;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 121, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[121];
    ((GLfunction_void_float_float_float)funcPtr->funcPtr)((GLfloat)red, (GLfloat)green, (GLfloat)blue);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3iCmd()
 *
 *  Handles the OpenGL glColor3i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int red;
    int green;
    int blue;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 122, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[122];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLint)red, (GLint)green, (GLint)blue);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3sCmd()
 *
 *  Handles the OpenGL glColor3s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int red;
    int green;
    int blue;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 123, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[123];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLshort)red, (GLshort)green, (GLshort)blue);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3ubCmd()
 *
 *  Handles the OpenGL glColor3ub command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3ubCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int red;
    int green;
    int blue;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3ubCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 124, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[124];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLubyte)red, (GLubyte)green, (GLubyte)blue);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3uiCmd()
 *
 *  Handles the OpenGL glColor3ui command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3uiCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int red;
    int green;
    int blue;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3uiCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 125, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[125];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLuint)red, (GLuint)green, (GLuint)blue);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3usCmd()
 *
 *  Handles the OpenGL glColor3us command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3usCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int red;
    int green;
    int blue;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3usCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 126, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[126];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLushort)red, (GLushort)green, (GLushort)blue);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4bCmd()
 *
 *  Handles the OpenGL glColor4b command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4bCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int red;
    int green;
    int blue;
    int alpha;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4bCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 127, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &alpha) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[127];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLbyte)red, (GLbyte)green, (GLbyte)blue, (GLbyte)alpha);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4dCmd()
 *
 *  Handles the OpenGL glColor4d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double red;
    double green;
    double blue;
    double alpha;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 128, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &alpha) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[128];
    ((GLfunction_void_double_double_double_double)funcPtr->funcPtr)((GLdouble)red, (GLdouble)green, (GLdouble)blue, (GLdouble)alpha);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4fCmd()
 *
 *  Handles the OpenGL glColor4f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double red;
    double green;
    double blue;
    double alpha;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 129, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &alpha) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[129];
    ((GLfunction_void_float_float_float_float)funcPtr->funcPtr)((GLfloat)red, (GLfloat)green, (GLfloat)blue, (GLfloat)alpha);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4iCmd()
 *
 *  Handles the OpenGL glColor4i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int red;
    int green;
    int blue;
    int alpha;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 130, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &alpha) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[130];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLint)red, (GLint)green, (GLint)blue, (GLint)alpha);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4sCmd()
 *
 *  Handles the OpenGL glColor4s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int red;
    int green;
    int blue;
    int alpha;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 131, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &alpha) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[131];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLshort)red, (GLshort)green, (GLshort)blue, (GLshort)alpha);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4ubCmd()
 *
 *  Handles the OpenGL glColor4ub command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4ubCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int red;
    int green;
    int blue;
    int alpha;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4ubCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 132, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &alpha) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[132];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLubyte)red, (GLubyte)green, (GLubyte)blue, (GLubyte)alpha);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4uiCmd()
 *
 *  Handles the OpenGL glColor4ui command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4uiCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int red;
    int green;
    int blue;
    int alpha;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4uiCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 133, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &alpha) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[133];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLuint)red, (GLuint)green, (GLuint)blue, (GLuint)alpha);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4usCmd()
 *
 *  Handles the OpenGL glColor4us command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4usCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int red;
    int green;
    int blue;
    int alpha;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4usCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 134, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &alpha) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[134];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLushort)red, (GLushort)green, (GLushort)blue, (GLushort)alpha);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3bvCmd()
 *
 *  Handles the OpenGL glColor3bv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3bvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3bvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 135, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[135];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLbyte*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3dvCmd()
 *
 *  Handles the OpenGL glColor3dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 136, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[136];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3fvCmd()
 *
 *  Handles the OpenGL glColor3fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 137, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[137];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3ivCmd()
 *
 *  Handles the OpenGL glColor3iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 138, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[138];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3svCmd()
 *
 *  Handles the OpenGL glColor3sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 139, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[139];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3ubvCmd()
 *
 *  Handles the OpenGL glColor3ubv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3ubvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3ubvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 140, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[140];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLubyte*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3uivCmd()
 *
 *  Handles the OpenGL glColor3uiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3uivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3uivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 141, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[141];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLuint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor3usvCmd()
 *
 *  Handles the OpenGL glColor3usv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor3usvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3usvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 142, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[142];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLushort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4bvCmd()
 *
 *  Handles the OpenGL glColor4bv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4bvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4bvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 143, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[143];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLbyte*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4dvCmd()
 *
 *  Handles the OpenGL glColor4dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 144, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[144];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4fvCmd()
 *
 *  Handles the OpenGL glColor4fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 145, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[145];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4ivCmd()
 *
 *  Handles the OpenGL glColor4iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 146, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[146];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4svCmd()
 *
 *  Handles the OpenGL glColor4sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 147, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[147];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4ubvCmd()
 *
 *  Handles the OpenGL glColor4ubv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4ubvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4ubvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 148, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[148];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLubyte*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4uivCmd()
 *
 *  Handles the OpenGL glColor4uiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4uivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4uivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 149, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[149];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLuint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColor4usvCmd()
 *
 *  Handles the OpenGL glColor4usv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColor4usvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4usvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 150, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[150];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLushort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord1dCmd()
 *
 *  Handles the OpenGL glTexCoord1d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord1dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double s;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 151, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[151];
    ((GLfunction_void_double)funcPtr->funcPtr)((GLdouble)s);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord1fCmd()
 *
 *  Handles the OpenGL glTexCoord1f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord1fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double s;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 152, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[152];
    ((GLfunction_void_float)funcPtr->funcPtr)((GLfloat)s);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord1iCmd()
 *
 *  Handles the OpenGL glTexCoord1i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord1iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int s;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 153, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[153];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLint)s);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord1sCmd()
 *
 *  Handles the OpenGL glTexCoord1s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord1sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int s;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 154, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[154];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLshort)s);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord2dCmd()
 *
 *  Handles the OpenGL glTexCoord2d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord2dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double s;
    double t;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 155, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[155];
    ((GLfunction_void_double_double)funcPtr->funcPtr)((GLdouble)s, (GLdouble)t);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord2fCmd()
 *
 *  Handles the OpenGL glTexCoord2f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord2fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double s;
    double t;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 156, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[156];
    ((GLfunction_void_float_float)funcPtr->funcPtr)((GLfloat)s, (GLfloat)t);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord2iCmd()
 *
 *  Handles the OpenGL glTexCoord2i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord2iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int s;
    int t;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 157, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[157];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLint)s, (GLint)t);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord2sCmd()
 *
 *  Handles the OpenGL glTexCoord2s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord2sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int s;
    int t;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 158, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[158];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLshort)s, (GLshort)t);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord3dCmd()
 *
 *  Handles the OpenGL glTexCoord3d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord3dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double s;
    double t;
    double r;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 159, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[159];
    ((GLfunction_void_double_double_double)funcPtr->funcPtr)((GLdouble)s, (GLdouble)t, (GLdouble)r);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord3fCmd()
 *
 *  Handles the OpenGL glTexCoord3f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord3fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double s;
    double t;
    double r;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 160, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[160];
    ((GLfunction_void_float_float_float)funcPtr->funcPtr)((GLfloat)s, (GLfloat)t, (GLfloat)r);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord3iCmd()
 *
 *  Handles the OpenGL glTexCoord3i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord3iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int s;
    int t;
    int r;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 161, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[161];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLint)s, (GLint)t, (GLint)r);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord3sCmd()
 *
 *  Handles the OpenGL glTexCoord3s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord3sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int s;
    int t;
    int r;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 162, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[162];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLshort)s, (GLshort)t, (GLshort)r);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord4dCmd()
 *
 *  Handles the OpenGL glTexCoord4d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord4dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double s;
    double t;
    double r;
    double q;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 163, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &q) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[163];
    ((GLfunction_void_double_double_double_double)funcPtr->funcPtr)((GLdouble)s, (GLdouble)t, (GLdouble)r, (GLdouble)q);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord4fCmd()
 *
 *  Handles the OpenGL glTexCoord4f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord4fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double s;
    double t;
    double r;
    double q;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 164, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &q) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[164];
    ((GLfunction_void_float_float_float_float)funcPtr->funcPtr)((GLfloat)s, (GLfloat)t, (GLfloat)r, (GLfloat)q);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord4iCmd()
 *
 *  Handles the OpenGL glTexCoord4i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord4iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int s;
    int t;
    int r;
    int q;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 165, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &q) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[165];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLint)s, (GLint)t, (GLint)r, (GLint)q);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord4sCmd()
 *
 *  Handles the OpenGL glTexCoord4s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord4sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int s;
    int t;
    int r;
    int q;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 166, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &q) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[166];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLshort)s, (GLshort)t, (GLshort)r, (GLshort)q);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord1dvCmd()
 *
 *  Handles the OpenGL glTexCoord1dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord1dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 167, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[167];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord1fvCmd()
 *
 *  Handles the OpenGL glTexCoord1fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord1fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 168, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[168];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord1ivCmd()
 *
 *  Handles the OpenGL glTexCoord1iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord1ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 169, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[169];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord1svCmd()
 *
 *  Handles the OpenGL glTexCoord1sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord1svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 170, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[170];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord2dvCmd()
 *
 *  Handles the OpenGL glTexCoord2dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord2dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 171, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[171];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord2fvCmd()
 *
 *  Handles the OpenGL glTexCoord2fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord2fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 172, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[172];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord2ivCmd()
 *
 *  Handles the OpenGL glTexCoord2iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord2ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 173, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[173];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord2svCmd()
 *
 *  Handles the OpenGL glTexCoord2sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord2svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 174, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[174];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord3dvCmd()
 *
 *  Handles the OpenGL glTexCoord3dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord3dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 175, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[175];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord3fvCmd()
 *
 *  Handles the OpenGL glTexCoord3fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord3fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 176, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[176];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord3ivCmd()
 *
 *  Handles the OpenGL glTexCoord3iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord3ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 177, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[177];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord3svCmd()
 *
 *  Handles the OpenGL glTexCoord3sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord3svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 178, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[178];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord4dvCmd()
 *
 *  Handles the OpenGL glTexCoord4dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord4dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 179, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[179];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord4fvCmd()
 *
 *  Handles the OpenGL glTexCoord4fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord4fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 180, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[180];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord4ivCmd()
 *
 *  Handles the OpenGL glTexCoord4iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord4ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 181, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[181];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoord4svCmd()
 *
 *  Handles the OpenGL glTexCoord4sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoord4svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 182, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[182];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos2dCmd()
 *
 *  Handles the OpenGL glRasterPos2d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos2dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 183, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[183];
    ((GLfunction_void_double_double)funcPtr->funcPtr)((GLdouble)x, (GLdouble)y);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos2fCmd()
 *
 *  Handles the OpenGL glRasterPos2f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos2fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 184, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[184];
    ((GLfunction_void_float_float)funcPtr->funcPtr)((GLfloat)x, (GLfloat)y);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos2iCmd()
 *
 *  Handles the OpenGL glRasterPos2i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos2iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 185, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[185];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLint)x, (GLint)y);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos2sCmd()
 *
 *  Handles the OpenGL glRasterPos2s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos2sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 186, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[186];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLshort)x, (GLshort)y);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos3dCmd()
 *
 *  Handles the OpenGL glRasterPos3d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos3dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    double z;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 187, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[187];
    ((GLfunction_void_double_double_double)funcPtr->funcPtr)((GLdouble)x, (GLdouble)y, (GLdouble)z);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos3fCmd()
 *
 *  Handles the OpenGL glRasterPos3f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos3fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    double z;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 188, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[188];
    ((GLfunction_void_float_float_float)funcPtr->funcPtr)((GLfloat)x, (GLfloat)y, (GLfloat)z);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos3iCmd()
 *
 *  Handles the OpenGL glRasterPos3i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos3iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    int z;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 189, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[189];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLint)x, (GLint)y, (GLint)z);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos3sCmd()
 *
 *  Handles the OpenGL glRasterPos3s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos3sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    int z;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 190, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[190];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLshort)x, (GLshort)y, (GLshort)z);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos4dCmd()
 *
 *  Handles the OpenGL glRasterPos4d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos4dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    double z;
    double w;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 191, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &w) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[191];
    ((GLfunction_void_double_double_double_double)funcPtr->funcPtr)((GLdouble)x, (GLdouble)y, (GLdouble)z, (GLdouble)w);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos4fCmd()
 *
 *  Handles the OpenGL glRasterPos4f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos4fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x;
    double y;
    double z;
    double w;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 192, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &w) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[192];
    ((GLfunction_void_float_float_float_float)funcPtr->funcPtr)((GLfloat)x, (GLfloat)y, (GLfloat)z, (GLfloat)w);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos4iCmd()
 *
 *  Handles the OpenGL glRasterPos4i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos4iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    int z;
    int w;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 193, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &w) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[193];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLint)x, (GLint)y, (GLint)z, (GLint)w);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos4sCmd()
 *
 *  Handles the OpenGL glRasterPos4s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos4sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    int z;
    int w;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 194, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &z) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &w) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[194];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLshort)x, (GLshort)y, (GLshort)z, (GLshort)w);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos2dvCmd()
 *
 *  Handles the OpenGL glRasterPos2dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos2dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 195, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[195];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos2fvCmd()
 *
 *  Handles the OpenGL glRasterPos2fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos2fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 196, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[196];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos2ivCmd()
 *
 *  Handles the OpenGL glRasterPos2iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos2ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 197, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[197];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos2svCmd()
 *
 *  Handles the OpenGL glRasterPos2sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos2svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 198, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[198];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos3dvCmd()
 *
 *  Handles the OpenGL glRasterPos3dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos3dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 199, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[199];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos3fvCmd()
 *
 *  Handles the OpenGL glRasterPos3fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos3fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 200, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[200];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos3ivCmd()
 *
 *  Handles the OpenGL glRasterPos3iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos3ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 201, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[201];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos3svCmd()
 *
 *  Handles the OpenGL glRasterPos3sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos3svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 202, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[202];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos4dvCmd()
 *
 *  Handles the OpenGL glRasterPos4dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos4dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 203, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[203];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos4fvCmd()
 *
 *  Handles the OpenGL glRasterPos4fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos4fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 204, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[204];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos4ivCmd()
 *
 *  Handles the OpenGL glRasterPos4iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos4ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 205, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[205];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRasterPos4svCmd()
 *
 *  Handles the OpenGL glRasterPos4sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRasterPos4svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 206, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[206];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRectdCmd()
 *
 *  Handles the OpenGL glRectd command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRectdCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x1;
    double y1;
    double x2;
    double y2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectdCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 207, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &x2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &y2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[207];
    ((GLfunction_void_double_double_double_double)funcPtr->funcPtr)((GLdouble)x1, (GLdouble)y1, (GLdouble)x2, (GLdouble)y2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRectfCmd()
 *
 *  Handles the OpenGL glRectf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRectfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double x1;
    double y1;
    double x2;
    double y2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 208, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &x1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &y1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &x2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &y2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[208];
    ((GLfunction_void_float_float_float_float)funcPtr->funcPtr)((GLfloat)x1, (GLfloat)y1, (GLfloat)x2, (GLfloat)y2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRectiCmd()
 *
 *  Handles the OpenGL glRecti command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRectiCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x1;
    int y1;
    int x2;
    int y2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectiCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 209, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &x2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &y2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[209];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLint)x1, (GLint)y1, (GLint)x2, (GLint)y2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRectsCmd()
 *
 *  Handles the OpenGL glRects command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRectsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x1;
    int y1;
    int x2;
    int y2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectsCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 210, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &x2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &y2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[210];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLshort)x1, (GLshort)y1, (GLshort)x2, (GLshort)y2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRectdvCmd()
 *
 *  Handles the OpenGL glRectdv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRectdvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v1;
    int paramLength0;
    void *v2;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectdvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 211, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v1, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v2, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[211];
    ((GLfunction_void_voidPtr_voidPtr)funcPtr->funcPtr)((GLdouble*)v1, (GLdouble*)v2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRectfvCmd()
 *
 *  Handles the OpenGL glRectfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRectfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v1;
    int paramLength0;
    void *v2;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 212, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v1, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v2, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[212];
    ((GLfunction_void_voidPtr_voidPtr)funcPtr->funcPtr)((GLfloat*)v1, (GLfloat*)v2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRectivCmd()
 *
 *  Handles the OpenGL glRectiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRectivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v1;
    int paramLength0;
    void *v2;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 213, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v1, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v2, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[213];
    ((GLfunction_void_voidPtr_voidPtr)funcPtr->funcPtr)((GLint*)v1, (GLint*)v2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glRectsvCmd()
 *
 *  Handles the OpenGL glRectsv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glRectsvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *v1;
    int paramLength0;
    void *v2;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectsvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 214, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &v1, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v2, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[214];
    ((GLfunction_void_voidPtr_voidPtr)funcPtr->funcPtr)((GLshort*)v1, (GLshort*)v2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glVertexPointerCmd()
 *
 *  Handles the OpenGL glVertexPointer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glVertexPointerCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int size;
    int type;
    int stride;
    void *ptr;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertexPointerCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 215, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &size) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &stride) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &ptr, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[215];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLint)size, (GLenum)type, (GLsizei)stride, (GLvoid*)ptr);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glNormalPointerCmd()
 *
 *  Handles the OpenGL glNormalPointer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glNormalPointerCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int type;
    int stride;
    void *ptr;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormalPointerCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 216, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &stride) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &ptr, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[216];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)type, (GLsizei)stride, (GLvoid*)ptr);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColorPointerCmd()
 *
 *  Handles the OpenGL glColorPointer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColorPointerCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int size;
    int type;
    int stride;
    void *ptr;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColorPointerCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 217, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &size) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &stride) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &ptr, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[217];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLint)size, (GLenum)type, (GLsizei)stride, (GLvoid*)ptr);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIndexPointerCmd()
 *
 *  Handles the OpenGL glIndexPointer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIndexPointerCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int type;
    int stride;
    void *ptr;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexPointerCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 218, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &stride) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &ptr, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[218];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)type, (GLsizei)stride, (GLvoid*)ptr);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexCoordPointerCmd()
 *
 *  Handles the OpenGL glTexCoordPointer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexCoordPointerCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int size;
    int type;
    int stride;
    void *ptr;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoordPointerCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 219, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &size) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &stride) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &ptr, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[219];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLint)size, (GLenum)type, (GLsizei)stride, (GLvoid*)ptr);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEdgeFlagPointerCmd()
 *
 *  Handles the OpenGL glEdgeFlagPointer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEdgeFlagPointerCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int stride;
    void *ptr;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEdgeFlagPointerCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 220, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &stride) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &ptr, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[220];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)stride, (GLvoid*)ptr);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetPointervCmd()
 *
 *  Handles the OpenGL glGetPointerv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetPointervCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    void **params = NULL;
    int paramLength1 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetPointervCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 221, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[221];
    ((GLfunction_void_int_voidPtrPtr)funcPtr->funcPtr)((GLenum)pname, (GLvoid**)params);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength1, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glArrayElementCmd()
 *
 *  Handles the OpenGL glArrayElement command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glArrayElementCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int i;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glArrayElementCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 222, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &i) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[222];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLint)i);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glDrawArraysCmd()
 *
 *  Handles the OpenGL glDrawArrays command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glDrawArraysCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mode;
    int first;
    int count;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDrawArraysCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 223, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &first) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &count) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[223];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)mode, (GLint)first, (GLsizei)count);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glDrawElementsCmd()
 *
 *  Handles the OpenGL glDrawElements command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glDrawElementsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mode;
    int count;
    int type;
    void *indices;
    int paramLength3;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDrawElementsCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 224, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &count) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[4], &indices, &paramLength3) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[224];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)mode, (GLsizei)count, (GLenum)type, (GLvoid*)indices);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glInterleavedArraysCmd()
 *
 *  Handles the OpenGL glInterleavedArrays command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glInterleavedArraysCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int format;
    int stride;
    void *pointer;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glInterleavedArraysCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 225, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &stride) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &pointer, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[225];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)format, (GLsizei)stride, (GLvoid*)pointer);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glShadeModelCmd()
 *
 *  Handles the OpenGL glShadeModel command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glShadeModelCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mode;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glShadeModelCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 226, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[226];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)mode);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLightfCmd()
 *
 *  Handles the OpenGL glLightf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLightfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int light;
    int pname;
    double param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLightfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 227, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &light) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[227];
    ((GLfunction_void_int_int_float)funcPtr->funcPtr)((GLenum)light, (GLenum)pname, (GLfloat)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLightiCmd()
 *
 *  Handles the OpenGL glLighti command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLightiCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int light;
    int pname;
    int param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLightiCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 228, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &light) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[228];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)light, (GLenum)pname, (GLint)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLightfvCmd()
 *
 *  Handles the OpenGL glLightfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLightfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int light;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLightfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 229, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &light) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[229];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)light, (GLenum)pname, (GLfloat*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLightivCmd()
 *
 *  Handles the OpenGL glLightiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLightivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int light;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLightivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 230, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &light) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[230];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)light, (GLenum)pname, (GLint*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetLightfvCmd()
 *
 *  Handles the OpenGL glGetLightfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetLightfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int light;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetLightfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 231, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &light) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[231];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)light, (GLenum)pname, (GLfloat*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetLightivCmd()
 *
 *  Handles the OpenGL glGetLightiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetLightivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int light;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetLightivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 232, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &light) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[232];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)light, (GLenum)pname, (GLint*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLightModelfCmd()
 *
 *  Handles the OpenGL glLightModelf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLightModelfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    double param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLightModelfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 233, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[233];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLenum)pname, (GLfloat)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLightModeliCmd()
 *
 *  Handles the OpenGL glLightModeli command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLightModeliCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    int param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLightModeliCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 234, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[234];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)pname, (GLint)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLightModelfvCmd()
 *
 *  Handles the OpenGL glLightModelfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLightModelfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    void *params;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLightModelfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 235, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &params, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[235];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)pname, (GLfloat*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLightModelivCmd()
 *
 *  Handles the OpenGL glLightModeliv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLightModelivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    void *params;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLightModelivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 236, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &params, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[236];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)pname, (GLint*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMaterialfCmd()
 *
 *  Handles the OpenGL glMaterialf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMaterialfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int face;
    int pname;
    double param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMaterialfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 237, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &face) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[237];
    ((GLfunction_void_int_int_float)funcPtr->funcPtr)((GLenum)face, (GLenum)pname, (GLfloat)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMaterialiCmd()
 *
 *  Handles the OpenGL glMateriali command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMaterialiCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int face;
    int pname;
    int param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMaterialiCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 238, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &face) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[238];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)face, (GLenum)pname, (GLint)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMaterialfvCmd()
 *
 *  Handles the OpenGL glMaterialfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMaterialfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int face;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMaterialfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 239, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &face) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[239];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)face, (GLenum)pname, (GLfloat*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMaterialivCmd()
 *
 *  Handles the OpenGL glMaterialiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMaterialivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int face;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMaterialivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 240, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &face) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[240];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)face, (GLenum)pname, (GLint*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetMaterialfvCmd()
 *
 *  Handles the OpenGL glGetMaterialfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetMaterialfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int face;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetMaterialfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 241, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &face) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[241];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)face, (GLenum)pname, (GLfloat*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetMaterialivCmd()
 *
 *  Handles the OpenGL glGetMaterialiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetMaterialivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int face;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetMaterialivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 242, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &face) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[242];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)face, (GLenum)pname, (GLint*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColorMaterialCmd()
 *
 *  Handles the OpenGL glColorMaterial command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColorMaterialCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int face;
    int mode;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColorMaterialCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 243, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &face) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[243];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)face, (GLenum)mode);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPixelZoomCmd()
 *
 *  Handles the OpenGL glPixelZoom command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPixelZoomCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double xfactor;
    double yfactor;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPixelZoomCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 244, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &xfactor) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &yfactor) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[244];
    ((GLfunction_void_float_float)funcPtr->funcPtr)((GLfloat)xfactor, (GLfloat)yfactor);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPixelStorefCmd()
 *
 *  Handles the OpenGL glPixelStoref command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPixelStorefCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    double param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPixelStorefCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 245, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[245];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLenum)pname, (GLfloat)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPixelStoreiCmd()
 *
 *  Handles the OpenGL glPixelStorei command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPixelStoreiCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    int param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPixelStoreiCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 246, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[246];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)pname, (GLint)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPixelTransferfCmd()
 *
 *  Handles the OpenGL glPixelTransferf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPixelTransferfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    double param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPixelTransferfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 247, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[247];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLenum)pname, (GLfloat)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPixelTransferiCmd()
 *
 *  Handles the OpenGL glPixelTransferi command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPixelTransferiCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    int param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPixelTransferiCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 248, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[248];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)pname, (GLint)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPixelMapfvCmd()
 *
 *  Handles the OpenGL glPixelMapfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPixelMapfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int map;
    int mapsize;
    void *values;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPixelMapfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 249, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &map) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &mapsize) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &values, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[249];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)map, (GLsizei)mapsize, (GLfloat*)values);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPixelMapuivCmd()
 *
 *  Handles the OpenGL glPixelMapuiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPixelMapuivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int map;
    int mapsize;
    void *values;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPixelMapuivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 250, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &map) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &mapsize) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &values, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[250];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)map, (GLsizei)mapsize, (GLuint*)values);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPixelMapusvCmd()
 *
 *  Handles the OpenGL glPixelMapusv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPixelMapusvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int map;
    int mapsize;
    void *values;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPixelMapusvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 251, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &map) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &mapsize) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &values, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[251];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)map, (GLsizei)mapsize, (GLushort*)values);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetPixelMapfvCmd()
 *
 *  Handles the OpenGL glGetPixelMapfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetPixelMapfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int map;
    void *values = NULL;
    int paramLength1 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetPixelMapfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 252, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &map) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[252];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)map, (GLfloat*)values);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength1, values) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetPixelMapuivCmd()
 *
 *  Handles the OpenGL glGetPixelMapuiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetPixelMapuivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int map;
    void *values = NULL;
    int paramLength1 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetPixelMapuivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 253, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &map) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[253];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)map, (GLuint*)values);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength1, values) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetPixelMapusvCmd()
 *
 *  Handles the OpenGL glGetPixelMapusv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetPixelMapusvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int map;
    void *values = NULL;
    int paramLength1 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetPixelMapusvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 254, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &map) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[254];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)map, (GLushort*)values);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength1, values) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glBitmapCmd()
 *
 *  Handles the OpenGL glBitmap command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glBitmapCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int width;
    int height;
    double xorig;
    double yorig;
    double xmove;
    double ymove;
    void *bitmap;
    int paramLength6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glBitmapCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 255, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &xorig) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &yorig) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &xmove) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[6], &ymove) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &bitmap, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[255];
    ((GLfunction_void_int_int_float_float_float_float_voidPtr)funcPtr->funcPtr)((GLsizei)width, (GLsizei)height, (GLfloat)xorig, (GLfloat)yorig, (GLfloat)xmove, (GLfloat)ymove, (GLubyte*)bitmap);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glReadPixelsCmd()
 *
 *  Handles the OpenGL glReadPixels command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glReadPixelsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    int width;
    int height;
    int format;
    int type;
    void *pixels = NULL;
    int paramLength6 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glReadPixelsCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 256, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[6], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[256];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLint)x, (GLint)y, (GLsizei)width, (GLsizei)height, (GLenum)format, (GLenum)type, (GLvoid*)pixels);
    if (SetPtrOutParam(interp, infoPtr, objv[7], paramLength6, pixels) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glDrawPixelsCmd()
 *
 *  Handles the OpenGL glDrawPixels command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glDrawPixelsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int width;
    int height;
    int format;
    int type;
    void *pixels;
    int paramLength4;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDrawPixelsCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 257, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[5], &pixels, &paramLength4) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[257];
    ((GLfunction_void_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLsizei)width, (GLsizei)height, (GLenum)format, (GLenum)type, (GLvoid*)pixels);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCopyPixelsCmd()
 *
 *  Handles the OpenGL glCopyPixels command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCopyPixelsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int x;
    int y;
    int width;
    int height;
    int type;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCopyPixelsCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 258, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[258];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLint)x, (GLint)y, (GLsizei)width, (GLsizei)height, (GLenum)type);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glStencilFuncCmd()
 *
 *  Handles the OpenGL glStencilFunc command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glStencilFuncCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int func;
    int ref;
    int mask;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glStencilFuncCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 259, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &func) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &ref) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &mask) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[259];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)func, (GLint)ref, (GLuint)mask);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glStencilMaskCmd()
 *
 *  Handles the OpenGL glStencilMask command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glStencilMaskCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mask;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glStencilMaskCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 260, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &mask) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[260];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLuint)mask);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glStencilOpCmd()
 *
 *  Handles the OpenGL glStencilOp command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glStencilOpCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int fail;
    int zfail;
    int zpass;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glStencilOpCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 261, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &fail) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &zfail) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &zpass) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[261];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)fail, (GLenum)zfail, (GLenum)zpass);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glClearStencilCmd()
 *
 *  Handles the OpenGL glClearStencil command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glClearStencilCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int s;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClearStencilCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 262, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[262];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLint)s);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexGendCmd()
 *
 *  Handles the OpenGL glTexGend command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexGendCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int coord;
    int pname;
    double param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexGendCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 263, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &coord) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[263];
    ((GLfunction_void_int_int_double)funcPtr->funcPtr)((GLenum)coord, (GLenum)pname, (GLdouble)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexGenfCmd()
 *
 *  Handles the OpenGL glTexGenf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexGenfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int coord;
    int pname;
    double param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexGenfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 264, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &coord) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[264];
    ((GLfunction_void_int_int_float)funcPtr->funcPtr)((GLenum)coord, (GLenum)pname, (GLfloat)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexGeniCmd()
 *
 *  Handles the OpenGL glTexGeni command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexGeniCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int coord;
    int pname;
    int param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexGeniCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 265, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &coord) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[265];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)coord, (GLenum)pname, (GLint)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexGendvCmd()
 *
 *  Handles the OpenGL glTexGendv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexGendvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int coord;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexGendvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 266, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &coord) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[266];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)coord, (GLenum)pname, (GLdouble*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexGenfvCmd()
 *
 *  Handles the OpenGL glTexGenfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexGenfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int coord;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexGenfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 267, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &coord) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[267];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)coord, (GLenum)pname, (GLfloat*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexGenivCmd()
 *
 *  Handles the OpenGL glTexGeniv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexGenivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int coord;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexGenivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 268, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &coord) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[268];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)coord, (GLenum)pname, (GLint*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetTexGendvCmd()
 *
 *  Handles the OpenGL glGetTexGendv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetTexGendvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int coord;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexGendvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 269, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &coord) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[269];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)coord, (GLenum)pname, (GLdouble*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetTexGenfvCmd()
 *
 *  Handles the OpenGL glGetTexGenfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetTexGenfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int coord;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexGenfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 270, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &coord) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[270];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)coord, (GLenum)pname, (GLfloat*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetTexGenivCmd()
 *
 *  Handles the OpenGL glGetTexGeniv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetTexGenivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int coord;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexGenivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 271, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &coord) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[271];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)coord, (GLenum)pname, (GLint*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexEnvfCmd()
 *
 *  Handles the OpenGL glTexEnvf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexEnvfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    double param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexEnvfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 272, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[272];
    ((GLfunction_void_int_int_float)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLfloat)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexEnviCmd()
 *
 *  Handles the OpenGL glTexEnvi command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexEnviCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    int param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexEnviCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 273, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[273];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLint)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexEnvfvCmd()
 *
 *  Handles the OpenGL glTexEnvfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexEnvfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexEnvfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 274, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[274];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLfloat*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexEnvivCmd()
 *
 *  Handles the OpenGL glTexEnviv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexEnvivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexEnvivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 275, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[275];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLint*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetTexEnvfvCmd()
 *
 *  Handles the OpenGL glGetTexEnvfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetTexEnvfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexEnvfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 276, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[276];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLfloat*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetTexEnvivCmd()
 *
 *  Handles the OpenGL glGetTexEnviv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetTexEnvivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexEnvivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 277, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[277];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLint*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexParameterfCmd()
 *
 *  Handles the OpenGL glTexParameterf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexParameterfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    double param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexParameterfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 278, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[278];
    ((GLfunction_void_int_int_float)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLfloat)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexParameteriCmd()
 *
 *  Handles the OpenGL glTexParameteri command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexParameteriCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    int param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexParameteriCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 279, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[279];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLint)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexParameterfvCmd()
 *
 *  Handles the OpenGL glTexParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 280, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[280];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLfloat*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexParameterivCmd()
 *
 *  Handles the OpenGL glTexParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 281, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[281];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLint*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetTexParameterfvCmd()
 *
 *  Handles the OpenGL glGetTexParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetTexParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 282, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[282];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLfloat*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetTexParameterivCmd()
 *
 *  Handles the OpenGL glGetTexParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetTexParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 283, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[283];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLint*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetTexLevelParameterfvCmd()
 *
 *  Handles the OpenGL glGetTexLevelParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetTexLevelParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int pname;
    void *params = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexLevelParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 284, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[284];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLenum)pname, (GLfloat*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength3, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetTexLevelParameterivCmd()
 *
 *  Handles the OpenGL glGetTexLevelParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetTexLevelParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int pname;
    void *params = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexLevelParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 285, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[285];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLenum)pname, (GLint*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength3, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexImage1DCmd()
 *
 *  Handles the OpenGL glTexImage1D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexImage1DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int internalFormat;
    int width;
    int border;
    int format;
    int type;
    void *pixels;
    int paramLength7;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexImage1DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 286, objc, 8) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &internalFormat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &border) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[6], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[7], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[8], &pixels, &paramLength7) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[286];
    ((GLfunction_void_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLint)internalFormat, (GLsizei)width, (GLint)border, (GLenum)format, (GLenum)type, (GLvoid*)pixels);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexImage2DCmd()
 *
 *  Handles the OpenGL glTexImage2D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexImage2DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int internalFormat;
    int width;
    int height;
    int border;
    int format;
    int type;
    void *pixels;
    int paramLength8;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexImage2DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 287, objc, 9) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &internalFormat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &border) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[7], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[8], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[9], &pixels, &paramLength8) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[287];
    ((GLfunction_void_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLint)internalFormat, (GLsizei)width, (GLsizei)height, (GLint)border, (GLenum)format, (GLenum)type, (GLvoid*)pixels);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetTexImageCmd()
 *
 *  Handles the OpenGL glGetTexImage command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetTexImageCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int format;
    int type;
    void *pixels = NULL;
    int paramLength4 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexImageCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 288, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[288];
    ((GLfunction_void_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLenum)format, (GLenum)type, (GLvoid*)pixels);
    if (SetPtrOutParam(interp, infoPtr, objv[5], paramLength4, pixels) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGenTexturesCmd()
 *
 *  Handles the OpenGL glGenTextures command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGenTexturesCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int n;
    void *textures = NULL;
    int paramLength1 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGenTexturesCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 289, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &n) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[289];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)n, (GLuint*)textures);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength1, textures) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glDeleteTexturesCmd()
 *
 *  Handles the OpenGL glDeleteTextures command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glDeleteTexturesCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int n;
    void *textures;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDeleteTexturesCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 290, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &n) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &textures, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[290];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)n, (GLuint*)textures);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glBindTextureCmd()
 *
 *  Handles the OpenGL glBindTexture command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glBindTextureCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int texture;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glBindTextureCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 291, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &texture) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[291];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)target, (GLuint)texture);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPrioritizeTexturesCmd()
 *
 *  Handles the OpenGL glPrioritizeTextures command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPrioritizeTexturesCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int n;
    void *textures;
    int paramLength1;
    void *priorities;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPrioritizeTexturesCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 292, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &n) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &textures, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &priorities, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[292];
    ((GLfunction_void_int_voidPtr_voidPtr)funcPtr->funcPtr)((GLsizei)n, (GLuint*)textures, (GLclampf*)priorities);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glIsTextureCmd()
 *
 *  Handles the OpenGL glIsTexture command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glIsTextureCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int texture;
    TclGLFunc *funcPtr;
    GLboolean retVal;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIsTextureCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 293, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &texture) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[293];
    retVal = ((GLfunction_GLboolean_int)funcPtr->funcPtr)((GLuint)texture);
    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexSubImage1DCmd()
 *
 *  Handles the OpenGL glTexSubImage1D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexSubImage1DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int xoffset;
    int width;
    int format;
    int type;
    void *pixels;
    int paramLength6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexSubImage1DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 294, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &xoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[6], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &pixels, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[294];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLint)xoffset, (GLsizei)width, (GLenum)format, (GLenum)type, (GLvoid*)pixels);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexSubImage2DCmd()
 *
 *  Handles the OpenGL glTexSubImage2D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexSubImage2DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int xoffset;
    int yoffset;
    int width;
    int height;
    int format;
    int type;
    void *pixels;
    int paramLength8;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexSubImage2DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 295, objc, 9) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &xoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &yoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[7], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[8], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[9], &pixels, &paramLength8) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[295];
    ((GLfunction_void_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLint)xoffset, (GLint)yoffset, (GLsizei)width, (GLsizei)height, (GLenum)format, (GLenum)type, (GLvoid*)pixels);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCopyTexImage1DCmd()
 *
 *  Handles the OpenGL glCopyTexImage1D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCopyTexImage1DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int internalformat;
    int x;
    int y;
    int width;
    int border;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCopyTexImage1DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 296, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &internalformat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &border) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[296];
    ((GLfunction_void_int_int_int_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLenum)internalformat, (GLint)x, (GLint)y, (GLsizei)width, (GLint)border);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCopyTexImage2DCmd()
 *
 *  Handles the OpenGL glCopyTexImage2D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCopyTexImage2DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int internalformat;
    int x;
    int y;
    int width;
    int height;
    int border;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCopyTexImage2DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 297, objc, 8) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &internalformat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &border) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[297];
    ((GLfunction_void_int_int_int_int_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLenum)internalformat, (GLint)x, (GLint)y, (GLsizei)width, (GLsizei)height, (GLint)border);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCopyTexSubImage1DCmd()
 *
 *  Handles the OpenGL glCopyTexSubImage1D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCopyTexSubImage1DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int xoffset;
    int x;
    int y;
    int width;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCopyTexSubImage1DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 298, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &xoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[298];
    ((GLfunction_void_int_int_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLint)xoffset, (GLint)x, (GLint)y, (GLsizei)width);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCopyTexSubImage2DCmd()
 *
 *  Handles the OpenGL glCopyTexSubImage2D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCopyTexSubImage2DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int xoffset;
    int yoffset;
    int x;
    int y;
    int width;
    int height;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCopyTexSubImage2DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 299, objc, 8) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &xoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &yoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[299];
    ((GLfunction_void_int_int_int_int_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLint)xoffset, (GLint)yoffset, (GLint)x, (GLint)y, (GLsizei)width, (GLsizei)height);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMap1dCmd()
 *
 *  Handles the OpenGL glMap1d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMap1dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double u1;
    double u2;
    int stride;
    int order;
    void *points;
    int paramLength5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMap1dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 300, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &u1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &u2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &stride) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &order) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &points, &paramLength5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[300];
    ((GLfunction_void_int_double_double_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLdouble)u1, (GLdouble)u2, (GLint)stride, (GLint)order, (GLdouble*)points);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMap1fCmd()
 *
 *  Handles the OpenGL glMap1f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMap1fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double u1;
    double u2;
    int stride;
    int order;
    void *points;
    int paramLength5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMap1fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 301, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &u1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &u2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &stride) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &order) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &points, &paramLength5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[301];
    ((GLfunction_void_int_float_float_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLfloat)u1, (GLfloat)u2, (GLint)stride, (GLint)order, (GLfloat*)points);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMap2dCmd()
 *
 *  Handles the OpenGL glMap2d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMap2dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double u1;
    double u2;
    int ustride;
    int uorder;
    double v1;
    double v2;
    int vstride;
    int vorder;
    void *points;
    int paramLength9;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMap2dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 302, objc, 10) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &u1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &u2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &ustride) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &uorder) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[6], &v1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[7], &v2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &vstride) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[9], &vorder) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[10], &points, &paramLength9) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[302];
    ((GLfunction_void_int_double_double_int_int_double_double_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLdouble)u1, (GLdouble)u2, (GLint)ustride, (GLint)uorder, (GLdouble)v1, (GLdouble)v2, (GLint)vstride, (GLint)vorder, (GLdouble*)points);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMap2fCmd()
 *
 *  Handles the OpenGL glMap2f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMap2fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double u1;
    double u2;
    int ustride;
    int uorder;
    double v1;
    double v2;
    int vstride;
    int vorder;
    void *points;
    int paramLength9;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMap2fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 303, objc, 10) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &u1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &u2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &ustride) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &uorder) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[6], &v1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[7], &v2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &vstride) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[9], &vorder) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[10], &points, &paramLength9) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[303];
    ((GLfunction_void_int_float_float_int_int_float_float_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLfloat)u1, (GLfloat)u2, (GLint)ustride, (GLint)uorder, (GLfloat)v1, (GLfloat)v2, (GLint)vstride, (GLint)vorder, (GLfloat*)points);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetMapdvCmd()
 *
 *  Handles the OpenGL glGetMapdv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetMapdvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int query;
    void *v = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetMapdvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 304, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &query) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[304];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)query, (GLdouble*)v);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, v) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetMapfvCmd()
 *
 *  Handles the OpenGL glGetMapfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetMapfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int query;
    void *v = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetMapfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 305, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &query) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[305];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)query, (GLfloat*)v);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, v) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetMapivCmd()
 *
 *  Handles the OpenGL glGetMapiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetMapivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int query;
    void *v = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetMapivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 306, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &query) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[306];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)query, (GLint*)v);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, v) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEvalCoord1dCmd()
 *
 *  Handles the OpenGL glEvalCoord1d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEvalCoord1dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double u;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord1dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 307, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &u) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[307];
    ((GLfunction_void_double)funcPtr->funcPtr)((GLdouble)u);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEvalCoord1fCmd()
 *
 *  Handles the OpenGL glEvalCoord1f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEvalCoord1fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double u;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord1fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 308, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &u) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[308];
    ((GLfunction_void_float)funcPtr->funcPtr)((GLfloat)u);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEvalCoord1dvCmd()
 *
 *  Handles the OpenGL glEvalCoord1dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEvalCoord1dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *u;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord1dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 309, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &u, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[309];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)u);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEvalCoord1fvCmd()
 *
 *  Handles the OpenGL glEvalCoord1fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEvalCoord1fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *u;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord1fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 310, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &u, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[310];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)u);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEvalCoord2dCmd()
 *
 *  Handles the OpenGL glEvalCoord2d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEvalCoord2dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double u;
    double v;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord2dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 311, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &u) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &v) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[311];
    ((GLfunction_void_double_double)funcPtr->funcPtr)((GLdouble)u, (GLdouble)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEvalCoord2fCmd()
 *
 *  Handles the OpenGL glEvalCoord2f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEvalCoord2fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double u;
    double v;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord2fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 312, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &u) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &v) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[312];
    ((GLfunction_void_float_float)funcPtr->funcPtr)((GLfloat)u, (GLfloat)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEvalCoord2dvCmd()
 *
 *  Handles the OpenGL glEvalCoord2dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEvalCoord2dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *u;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord2dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 313, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &u, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[313];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLdouble*)u);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEvalCoord2fvCmd()
 *
 *  Handles the OpenGL glEvalCoord2fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEvalCoord2fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    void *u;
    int paramLength0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord2fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 314, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetPtrInParam(interp, infoPtr, objv[1], &u, &paramLength0) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[314];
    ((GLfunction_void_voidPtr)funcPtr->funcPtr)((GLfloat*)u);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMapGrid1dCmd()
 *
 *  Handles the OpenGL glMapGrid1d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMapGrid1dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int un;
    double u1;
    double u2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMapGrid1dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 315, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &un) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &u1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &u2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[315];
    ((GLfunction_void_int_double_double)funcPtr->funcPtr)((GLint)un, (GLdouble)u1, (GLdouble)u2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMapGrid1fCmd()
 *
 *  Handles the OpenGL glMapGrid1f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMapGrid1fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int un;
    double u1;
    double u2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMapGrid1fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 316, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &un) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &u1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &u2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[316];
    ((GLfunction_void_int_float_float)funcPtr->funcPtr)((GLint)un, (GLfloat)u1, (GLfloat)u2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMapGrid2dCmd()
 *
 *  Handles the OpenGL glMapGrid2d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMapGrid2dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int un;
    double u1;
    double u2;
    int vn;
    double v1;
    double v2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMapGrid2dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 317, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &un) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &u1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &u2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &vn) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &v1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[6], &v2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[317];
    ((GLfunction_void_int_double_double_int_double_double)funcPtr->funcPtr)((GLint)un, (GLdouble)u1, (GLdouble)u2, (GLint)vn, (GLdouble)v1, (GLdouble)v2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMapGrid2fCmd()
 *
 *  Handles the OpenGL glMapGrid2f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMapGrid2fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int un;
    double u1;
    double u2;
    int vn;
    double v1;
    double v2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMapGrid2fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 318, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &un) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &u1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &u2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &vn) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &v1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[6], &v2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[318];
    ((GLfunction_void_int_float_float_int_float_float)funcPtr->funcPtr)((GLint)un, (GLfloat)u1, (GLfloat)u2, (GLint)vn, (GLfloat)v1, (GLfloat)v2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEvalPoint1Cmd()
 *
 *  Handles the OpenGL glEvalPoint1 command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEvalPoint1Cmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int i;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalPoint1Cmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 319, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &i) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[319];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLint)i);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEvalPoint2Cmd()
 *
 *  Handles the OpenGL glEvalPoint2 command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEvalPoint2Cmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int i;
    int j;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalPoint2Cmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 320, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &i) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &j) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[320];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLint)i, (GLint)j);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEvalMesh1Cmd()
 *
 *  Handles the OpenGL glEvalMesh1 command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEvalMesh1Cmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mode;
    int i1;
    int i2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalMesh1Cmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 321, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &i1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &i2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[321];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)mode, (GLint)i1, (GLint)i2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glEvalMesh2Cmd()
 *
 *  Handles the OpenGL glEvalMesh2 command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glEvalMesh2Cmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mode;
    int i1;
    int i2;
    int j1;
    int j2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalMesh2Cmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 322, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &i1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &i2) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &j1) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &j2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[322];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)mode, (GLint)i1, (GLint)i2, (GLint)j1, (GLint)j2);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glFogfCmd()
 *
 *  Handles the OpenGL glFogf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glFogfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    double param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFogfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 323, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[323];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLenum)pname, (GLfloat)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glFogiCmd()
 *
 *  Handles the OpenGL glFogi command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glFogiCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    int param;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFogiCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 324, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &param) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[324];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)pname, (GLint)param);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glFogfvCmd()
 *
 *  Handles the OpenGL glFogfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glFogfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    void *params;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFogfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 325, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &params, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[325];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)pname, (GLfloat*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glFogivCmd()
 *
 *  Handles the OpenGL glFogiv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glFogivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int pname;
    void *params;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFogivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 326, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &params, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[326];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)pname, (GLint*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glFeedbackBufferCmd()
 *
 *  Handles the OpenGL glFeedbackBuffer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glFeedbackBufferCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int size;
    int type;
    void *buffer = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFeedbackBufferCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 327, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &size) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[327];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLsizei)size, (GLenum)type, (GLfloat*)buffer);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, buffer) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPassThroughCmd()
 *
 *  Handles the OpenGL glPassThrough command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPassThroughCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double token;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPassThroughCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 328, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &token) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[328];
    ((GLfunction_void_float)funcPtr->funcPtr)((GLfloat)token);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glSelectBufferCmd()
 *
 *  Handles the OpenGL glSelectBuffer command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glSelectBufferCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int size;
    void *buffer = NULL;
    int paramLength1 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glSelectBufferCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 329, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &size) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[329];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLsizei)size, (GLuint*)buffer);
    if (SetPtrOutParam(interp, infoPtr, objv[2], paramLength1, buffer) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glInitNamesCmd()
 *
 *  Handles the OpenGL glInitNames command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glInitNamesCmd(
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
    TclGLShowArgs(1, "TclGL_glInitNamesCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 330, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[330];
    ((GLfunction_void_)funcPtr->funcPtr)();
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLoadNameCmd()
 *
 *  Handles the OpenGL glLoadName command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLoadNameCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int name;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLoadNameCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 331, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &name) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[331];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLuint)name);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPushNameCmd()
 *
 *  Handles the OpenGL glPushName command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPushNameCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int name;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPushNameCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 332, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetIntParam(interp, infoPtr, objv[1], &name) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[332];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLuint)name);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glPopNameCmd()
 *
 *  Handles the OpenGL glPopName command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glPopNameCmd(
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
    TclGLShowArgs(1, "TclGL_glPopNameCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 333, objc, 0) != TCL_OK) {
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[333];
    ((GLfunction_void_)funcPtr->funcPtr)();
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glDrawRangeElementsCmd()
 *
 *  Handles the OpenGL glDrawRangeElements command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glDrawRangeElementsCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mode;
    int start;
    int end;
    int count;
    int type;
    void *indices;
    int paramLength5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDrawRangeElementsCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 334, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &start) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &end) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &count) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &indices, &paramLength5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[334];
    ((GLfunction_void_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)mode, (GLuint)start, (GLuint)end, (GLsizei)count, (GLenum)type, (GLvoid*)indices);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexImage3DCmd()
 *
 *  Handles the OpenGL glTexImage3D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexImage3DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int internalFormat;
    int width;
    int height;
    int depth;
    int border;
    int format;
    int type;
    void *pixels;
    int paramLength9;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexImage3DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 335, objc, 10) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &internalFormat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &depth) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &border) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[8], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[9], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[10], &pixels, &paramLength9) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[335];
    ((GLfunction_void_int_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLint)internalFormat, (GLsizei)width, (GLsizei)height, (GLsizei)depth, (GLint)border, (GLenum)format, (GLenum)type, (GLvoid*)pixels);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glTexSubImage3DCmd()
 *
 *  Handles the OpenGL glTexSubImage3D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glTexSubImage3DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int xoffset;
    int yoffset;
    int zoffset;
    int width;
    int height;
    int depth;
    int format;
    int type;
    void *pixels;
    int paramLength10;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexSubImage3DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 336, objc, 11) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &xoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &yoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &zoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &depth) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[9], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[10], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[11], &pixels, &paramLength10) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[336];
    ((GLfunction_void_int_int_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLint)xoffset, (GLint)yoffset, (GLint)zoffset, (GLsizei)width, (GLsizei)height, (GLsizei)depth, (GLenum)format, (GLenum)type, (GLvoid*)pixels);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCopyTexSubImage3DCmd()
 *
 *  Handles the OpenGL glCopyTexSubImage3D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCopyTexSubImage3DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int xoffset;
    int yoffset;
    int zoffset;
    int x;
    int y;
    int width;
    int height;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCopyTexSubImage3DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 337, objc, 9) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &xoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &yoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &zoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[9], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[337];
    ((GLfunction_void_int_int_int_int_int_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLint)xoffset, (GLint)yoffset, (GLint)zoffset, (GLint)x, (GLint)y, (GLsizei)width, (GLsizei)height);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColorTableCmd()
 *
 *  Handles the OpenGL glColorTable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColorTableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int internalformat;
    int width;
    int format;
    int type;
    void *table;
    int paramLength5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColorTableCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 338, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &internalformat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &table, &paramLength5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[338];
    ((GLfunction_void_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)internalformat, (GLsizei)width, (GLenum)format, (GLenum)type, (GLvoid*)table);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColorSubTableCmd()
 *
 *  Handles the OpenGL glColorSubTable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColorSubTableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int start;
    int count;
    int format;
    int type;
    void *data;
    int paramLength5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColorSubTableCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 339, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &start) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &count) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &data, &paramLength5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[339];
    ((GLfunction_void_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLsizei)start, (GLsizei)count, (GLenum)format, (GLenum)type, (GLvoid*)data);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColorTableParameterivCmd()
 *
 *  Handles the OpenGL glColorTableParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColorTableParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColorTableParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 340, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[340];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLint*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glColorTableParameterfvCmd()
 *
 *  Handles the OpenGL glColorTableParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glColorTableParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColorTableParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 341, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[341];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLfloat*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCopyColorSubTableCmd()
 *
 *  Handles the OpenGL glCopyColorSubTable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCopyColorSubTableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int start;
    int x;
    int y;
    int width;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCopyColorSubTableCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 342, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &start) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[342];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLsizei)start, (GLint)x, (GLint)y, (GLsizei)width);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCopyColorTableCmd()
 *
 *  Handles the OpenGL glCopyColorTable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCopyColorTableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int internalformat;
    int x;
    int y;
    int width;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCopyColorTableCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 343, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &internalformat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[343];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLenum)internalformat, (GLint)x, (GLint)y, (GLsizei)width);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetColorTableCmd()
 *
 *  Handles the OpenGL glGetColorTable command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetColorTableCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int format;
    int type;
    void *table = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetColorTableCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 344, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[344];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)format, (GLenum)type, (GLvoid*)table);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength3, table) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetColorTableParameterfvCmd()
 *
 *  Handles the OpenGL glGetColorTableParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetColorTableParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetColorTableParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 345, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[345];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLfloat*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetColorTableParameterivCmd()
 *
 *  Handles the OpenGL glGetColorTableParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetColorTableParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetColorTableParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 346, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[346];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLint*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glBlendEquationCmd()
 *
 *  Handles the OpenGL glBlendEquation command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glBlendEquationCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int mode;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glBlendEquationCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 347, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &mode) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[347];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)mode);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glBlendColorCmd()
 *
 *  Handles the OpenGL glBlendColor command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glBlendColorCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double red;
    double green;
    double blue;
    double alpha;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glBlendColorCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 348, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &red) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &green) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &blue) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &alpha) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[348];
    ((GLfunction_void_float_float_float_float)funcPtr->funcPtr)((GLclampf)red, (GLclampf)green, (GLclampf)blue, (GLclampf)alpha);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glHistogramCmd()
 *
 *  Handles the OpenGL glHistogram command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glHistogramCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int width;
    int internalformat;
    int sink;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glHistogramCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 349, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &internalformat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &sink) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[349];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLsizei)width, (GLenum)internalformat, (GLboolean)sink);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glResetHistogramCmd()
 *
 *  Handles the OpenGL glResetHistogram command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glResetHistogramCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glResetHistogramCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 350, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[350];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)target);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetHistogramCmd()
 *
 *  Handles the OpenGL glGetHistogram command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetHistogramCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int reset;
    int format;
    int type;
    void *values = NULL;
    int paramLength4 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetHistogramCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 351, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &reset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[351];
    ((GLfunction_void_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLboolean)reset, (GLenum)format, (GLenum)type, (GLvoid*)values);
    if (SetPtrOutParam(interp, infoPtr, objv[5], paramLength4, values) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetHistogramParameterfvCmd()
 *
 *  Handles the OpenGL glGetHistogramParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetHistogramParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetHistogramParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 352, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[352];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLfloat*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetHistogramParameterivCmd()
 *
 *  Handles the OpenGL glGetHistogramParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetHistogramParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetHistogramParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 353, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[353];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLint*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMinmaxCmd()
 *
 *  Handles the OpenGL glMinmax command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMinmaxCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int internalformat;
    int sink;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMinmaxCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 354, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &internalformat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &sink) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[354];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLenum)internalformat, (GLboolean)sink);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glResetMinmaxCmd()
 *
 *  Handles the OpenGL glResetMinmax command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glResetMinmaxCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glResetMinmaxCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 355, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[355];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)target);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetMinmaxCmd()
 *
 *  Handles the OpenGL glGetMinmax command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetMinmaxCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int reset;
    int format;
    int types;
    void *values = NULL;
    int paramLength4 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetMinmaxCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 356, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &reset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &types) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[356];
    ((GLfunction_void_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLboolean)reset, (GLenum)format, (GLenum)types, (GLvoid*)values);
    if (SetPtrOutParam(interp, infoPtr, objv[5], paramLength4, values) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetMinmaxParameterfvCmd()
 *
 *  Handles the OpenGL glGetMinmaxParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetMinmaxParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetMinmaxParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 357, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[357];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLfloat*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetMinmaxParameterivCmd()
 *
 *  Handles the OpenGL glGetMinmaxParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetMinmaxParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetMinmaxParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 358, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[358];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLint*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glConvolutionFilter1DCmd()
 *
 *  Handles the OpenGL glConvolutionFilter1D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glConvolutionFilter1DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int internalformat;
    int width;
    int format;
    int type;
    void *image;
    int paramLength5;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glConvolutionFilter1DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 359, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &internalformat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[4], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[6], &image, &paramLength5) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[359];
    ((GLfunction_void_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)internalformat, (GLsizei)width, (GLenum)format, (GLenum)type, (GLvoid*)image);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glConvolutionFilter2DCmd()
 *
 *  Handles the OpenGL glConvolutionFilter2D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glConvolutionFilter2DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int internalformat;
    int width;
    int height;
    int format;
    int type;
    void *image;
    int paramLength6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glConvolutionFilter2DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 360, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &internalformat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[6], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &image, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[360];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)internalformat, (GLsizei)width, (GLsizei)height, (GLenum)format, (GLenum)type, (GLvoid*)image);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glConvolutionParameterfCmd()
 *
 *  Handles the OpenGL glConvolutionParameterf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glConvolutionParameterfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    double params;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glConvolutionParameterfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 361, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &params) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[361];
    ((GLfunction_void_int_int_float)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLfloat)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glConvolutionParameterfvCmd()
 *
 *  Handles the OpenGL glConvolutionParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glConvolutionParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glConvolutionParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 362, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[362];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLfloat*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glConvolutionParameteriCmd()
 *
 *  Handles the OpenGL glConvolutionParameteri command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glConvolutionParameteriCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    int params;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glConvolutionParameteriCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 363, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &params) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[363];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLint)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glConvolutionParameterivCmd()
 *
 *  Handles the OpenGL glConvolutionParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glConvolutionParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params;
    int paramLength2;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glConvolutionParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 364, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[3], &params, &paramLength2) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[364];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLint*)params);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCopyConvolutionFilter1DCmd()
 *
 *  Handles the OpenGL glCopyConvolutionFilter1D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCopyConvolutionFilter1DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int internalformat;
    int x;
    int y;
    int width;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCopyConvolutionFilter1DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 365, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &internalformat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[365];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLenum)internalformat, (GLint)x, (GLint)y, (GLsizei)width);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCopyConvolutionFilter2DCmd()
 *
 *  Handles the OpenGL glCopyConvolutionFilter2D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCopyConvolutionFilter2DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int internalformat;
    int x;
    int y;
    int width;
    int height;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCopyConvolutionFilter2DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 366, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &internalformat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &x) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &y) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[366];
    ((GLfunction_void_int_int_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLenum)internalformat, (GLint)x, (GLint)y, (GLsizei)width, (GLsizei)height);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetConvolutionFilterCmd()
 *
 *  Handles the OpenGL glGetConvolutionFilter command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetConvolutionFilterCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int format;
    int type;
    void *image = NULL;
    int paramLength3 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetConvolutionFilterCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 367, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[367];
    ((GLfunction_void_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)format, (GLenum)type, (GLvoid*)image);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength3, image) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetConvolutionParameterfvCmd()
 *
 *  Handles the OpenGL glGetConvolutionParameterfv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetConvolutionParameterfvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetConvolutionParameterfvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 368, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[368];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLfloat*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetConvolutionParameterivCmd()
 *
 *  Handles the OpenGL glGetConvolutionParameteriv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetConvolutionParameterivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int pname;
    void *params = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetConvolutionParameterivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 369, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &pname) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[369];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)pname, (GLint*)params);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, params) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glSeparableFilter2DCmd()
 *
 *  Handles the OpenGL glSeparableFilter2D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glSeparableFilter2DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int internalformat;
    int width;
    int height;
    int format;
    int type;
    void *row;
    int paramLength6;
    void *column;
    int paramLength7;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glSeparableFilter2DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 370, objc, 8) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &internalformat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[6], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &row, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[8], &column, &paramLength7) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[370];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)internalformat, (GLsizei)width, (GLsizei)height, (GLenum)format, (GLenum)type, (GLvoid*)row, (GLvoid*)column);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetSeparableFilterCmd()
 *
 *  Handles the OpenGL glGetSeparableFilter command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetSeparableFilterCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int format;
    int type;
    void *row = NULL;
    int paramLength3 = 0;
    void *column = NULL;
    int paramLength4 = 0;
    void *span = NULL;
    int paramLength5 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetSeparableFilterCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 371, objc, 6) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &type) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[371];
    ((GLfunction_void_int_int_int_voidPtr_voidPtr_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLenum)format, (GLenum)type, (GLvoid*)row, (GLvoid*)column, (GLvoid*)span);
    if (SetPtrOutParam(interp, infoPtr, objv[4], paramLength3, row) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[5], paramLength4, column) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (SetPtrOutParam(interp, infoPtr, objv[6], paramLength5, span) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glActiveTextureCmd()
 *
 *  Handles the OpenGL glActiveTexture command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glActiveTextureCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int texture;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glActiveTextureCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 372, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &texture) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[372];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)texture);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glClientActiveTextureCmd()
 *
 *  Handles the OpenGL glClientActiveTexture command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glClientActiveTextureCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int texture;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClientActiveTextureCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 373, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &texture) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[373];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)texture);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCompressedTexImage1DCmd()
 *
 *  Handles the OpenGL glCompressedTexImage1D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCompressedTexImage1DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int internalformat;
    int width;
    int border;
    int imageSize;
    void *data;
    int paramLength6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCompressedTexImage1DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 374, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &internalformat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &border) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &imageSize) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &data, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[374];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLenum)internalformat, (GLsizei)width, (GLint)border, (GLsizei)imageSize, (GLvoid*)data);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCompressedTexImage2DCmd()
 *
 *  Handles the OpenGL glCompressedTexImage2D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCompressedTexImage2DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int internalformat;
    int width;
    int height;
    int border;
    int imageSize;
    void *data;
    int paramLength7;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCompressedTexImage2DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 375, objc, 8) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &internalformat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &border) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &imageSize) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[8], &data, &paramLength7) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[375];
    ((GLfunction_void_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLenum)internalformat, (GLsizei)width, (GLsizei)height, (GLint)border, (GLsizei)imageSize, (GLvoid*)data);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCompressedTexImage3DCmd()
 *
 *  Handles the OpenGL glCompressedTexImage3D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCompressedTexImage3DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int internalformat;
    int width;
    int height;
    int depth;
    int border;
    int imageSize;
    void *data;
    int paramLength8;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCompressedTexImage3DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 376, objc, 9) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[3], &internalformat) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &depth) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &border) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &imageSize) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[9], &data, &paramLength8) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[376];
    ((GLfunction_void_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLenum)internalformat, (GLsizei)width, (GLsizei)height, (GLsizei)depth, (GLint)border, (GLsizei)imageSize, (GLvoid*)data);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCompressedTexSubImage1DCmd()
 *
 *  Handles the OpenGL glCompressedTexSubImage1D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCompressedTexSubImage1DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int xoffset;
    int width;
    int format;
    int imageSize;
    void *data;
    int paramLength6;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCompressedTexSubImage1DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 377, objc, 7) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &xoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[5], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &imageSize) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[7], &data, &paramLength6) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[377];
    ((GLfunction_void_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLint)xoffset, (GLsizei)width, (GLenum)format, (GLsizei)imageSize, (GLvoid*)data);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCompressedTexSubImage2DCmd()
 *
 *  Handles the OpenGL glCompressedTexSubImage2D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCompressedTexSubImage2DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int xoffset;
    int yoffset;
    int width;
    int height;
    int format;
    int imageSize;
    void *data;
    int paramLength8;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCompressedTexSubImage2DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 378, objc, 9) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &xoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &yoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[7], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &imageSize) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[9], &data, &paramLength8) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[378];
    ((GLfunction_void_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLint)xoffset, (GLint)yoffset, (GLsizei)width, (GLsizei)height, (GLenum)format, (GLsizei)imageSize, (GLvoid*)data);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glCompressedTexSubImage3DCmd()
 *
 *  Handles the OpenGL glCompressedTexSubImage3D command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glCompressedTexSubImage3DCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int level;
    int xoffset;
    int yoffset;
    int zoffset;
    int width;
    int height;
    int depth;
    int format;
    int imageSize;
    void *data;
    int paramLength10;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCompressedTexSubImage3DCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 379, objc, 11) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &level) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &xoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &yoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &zoffset) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[6], &width) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[7], &height) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[8], &depth) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[9], &format) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[10], &imageSize) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[11], &data, &paramLength10) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[379];
    ((GLfunction_void_int_int_int_int_int_int_int_int_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)level, (GLint)xoffset, (GLint)yoffset, (GLint)zoffset, (GLsizei)width, (GLsizei)height, (GLsizei)depth, (GLenum)format, (GLsizei)imageSize, (GLvoid*)data);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glGetCompressedTexImageCmd()
 *
 *  Handles the OpenGL glGetCompressedTexImage command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glGetCompressedTexImageCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int lod;
    void *img = NULL;
    int paramLength2 = 0;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetCompressedTexImageCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 380, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &lod) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[380];
    ((GLfunction_void_int_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint)lod, (GLvoid*)img);
    if (SetPtrOutParam(interp, infoPtr, objv[3], paramLength2, img) != TCL_OK) {
        return TCL_ERROR;
    } 
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1dCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 381, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[381];
    ((GLfunction_void_int_double)funcPtr->funcPtr)((GLenum)target, (GLdouble)s);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1dvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 382, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[382];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1fCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 383, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[383];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLenum)target, (GLfloat)s);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1fvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 384, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[384];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1iCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 385, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[385];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)target, (GLint)s);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1ivCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 386, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[386];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1sCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 387, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[387];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)target, (GLshort)s);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1svCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 388, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[388];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2dCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    double t;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 389, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[389];
    ((GLfunction_void_int_double_double)funcPtr->funcPtr)((GLenum)target, (GLdouble)s, (GLdouble)t);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2dvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 390, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[390];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2fCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    double t;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 391, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[391];
    ((GLfunction_void_int_float_float)funcPtr->funcPtr)((GLenum)target, (GLfloat)s, (GLfloat)t);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2fvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 392, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[392];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2iCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    int t;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 393, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[393];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLint)s, (GLint)t);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2ivCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 394, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[394];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2sCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    int t;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 395, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[395];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLshort)s, (GLshort)t);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2svCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 396, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[396];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3dCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    double t;
    double r;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 397, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[397];
    ((GLfunction_void_int_double_double_double)funcPtr->funcPtr)((GLenum)target, (GLdouble)s, (GLdouble)t, (GLdouble)r);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3dvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 398, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[398];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3fCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    double t;
    double r;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 399, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[399];
    ((GLfunction_void_int_float_float_float)funcPtr->funcPtr)((GLenum)target, (GLfloat)s, (GLfloat)t, (GLfloat)r);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3fvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 400, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[400];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3iCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    int t;
    int r;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 401, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[401];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLint)s, (GLint)t, (GLint)r);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3ivCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 402, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[402];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3sCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    int t;
    int r;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 403, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[403];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLshort)s, (GLshort)t, (GLshort)r);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3svCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 404, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[404];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4dCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4d command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4dCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    double t;
    double r;
    double q;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4dCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 405, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &q) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[405];
    ((GLfunction_void_int_double_double_double_double)funcPtr->funcPtr)((GLenum)target, (GLdouble)s, (GLdouble)t, (GLdouble)r, (GLdouble)q);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4dvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4dv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4dvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4dvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 406, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[406];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4fCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4f command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4fCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    double t;
    double r;
    double q;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4fCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 407, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &q) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[407];
    ((GLfunction_void_int_float_float_float_float)funcPtr->funcPtr)((GLenum)target, (GLfloat)s, (GLfloat)t, (GLfloat)r, (GLfloat)q);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4fvCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4fv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4fvCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4fvCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 408, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[408];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4iCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4i command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4iCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    int t;
    int r;
    int q;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4iCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 409, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &q) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[409];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLint)s, (GLint)t, (GLint)r, (GLint)q);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4ivCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4iv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4ivCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4ivCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 410, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[410];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4sCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    int t;
    int r;
    int q;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4sCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 411, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &q) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[411];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLshort)s, (GLshort)t, (GLshort)r, (GLshort)q);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4svCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4sv command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4svCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4svCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 412, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[412];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLoadTransposeMatrixdCmd()
 *
 *  Handles the OpenGL glLoadTransposeMatrixd command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLoadTransposeMatrixdCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double m[16];
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLoadTransposeMatrixdCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 413, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &m[16]) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[413];
    ((GLfunction_void_double)funcPtr->funcPtr)((GLdouble)m[16]);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glLoadTransposeMatrixfCmd()
 *
 *  Handles the OpenGL glLoadTransposeMatrixf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glLoadTransposeMatrixfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double m[16];
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLoadTransposeMatrixfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 414, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &m[16]) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[414];
    ((GLfunction_void_float)funcPtr->funcPtr)((GLfloat)m[16]);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultTransposeMatrixdCmd()
 *
 *  Handles the OpenGL glMultTransposeMatrixd command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultTransposeMatrixdCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double m[16];
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultTransposeMatrixdCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 415, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &m[16]) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[415];
    ((GLfunction_void_double)funcPtr->funcPtr)((GLdouble)m[16]);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultTransposeMatrixfCmd()
 *
 *  Handles the OpenGL glMultTransposeMatrixf command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultTransposeMatrixfCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double m[16];
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultTransposeMatrixfCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 416, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &m[16]) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[416];
    ((GLfunction_void_float)funcPtr->funcPtr)((GLfloat)m[16]);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glSampleCoverageCmd()
 *
 *  Handles the OpenGL glSampleCoverage command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glSampleCoverageCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    double value;
    int invert;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glSampleCoverageCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 417, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetDoubleParam(interp, infoPtr, objv[1], &value) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &invert) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[417];
    ((GLfunction_void_float_int)funcPtr->funcPtr)((GLclampf)value, (GLboolean)invert);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glActiveTextureARBCmd()
 *
 *  Handles the OpenGL glActiveTextureARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glActiveTextureARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int texture;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glActiveTextureARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 418, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &texture) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[418];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)texture);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glClientActiveTextureARBCmd()
 *
 *  Handles the OpenGL glClientActiveTextureARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glClientActiveTextureARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int texture;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClientActiveTextureARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 419, objc, 1) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &texture) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[419];
    ((GLfunction_void_int)funcPtr->funcPtr)((GLenum)texture);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1dARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 420, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[420];
    ((GLfunction_void_int_double)funcPtr->funcPtr)((GLenum)target, (GLdouble)s);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1dvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 421, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[421];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1fARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 422, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[422];
    ((GLfunction_void_int_float)funcPtr->funcPtr)((GLenum)target, (GLfloat)s);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1fvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 423, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[423];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1iARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1iARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1iARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1iARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 424, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[424];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)target, (GLint)s);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1ivARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 425, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[425];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1sARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1sARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1sARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1sARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 426, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[426];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)target, (GLshort)s);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord1svARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord1svARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord1svARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1svARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 427, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[427];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2dARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    double t;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 428, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[428];
    ((GLfunction_void_int_double_double)funcPtr->funcPtr)((GLenum)target, (GLdouble)s, (GLdouble)t);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2dvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 429, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[429];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2fARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    double t;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 430, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[430];
    ((GLfunction_void_int_float_float)funcPtr->funcPtr)((GLenum)target, (GLfloat)s, (GLfloat)t);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2fvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 431, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[431];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2iARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2iARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2iARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    int t;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2iARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 432, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[432];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLint)s, (GLint)t);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2ivARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 433, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[433];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2sARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2sARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2sARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    int t;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2sARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 434, objc, 3) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[434];
    ((GLfunction_void_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLshort)s, (GLshort)t);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord2svARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord2svARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord2svARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2svARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 435, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[435];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3dARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    double t;
    double r;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 436, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[436];
    ((GLfunction_void_int_double_double_double)funcPtr->funcPtr)((GLenum)target, (GLdouble)s, (GLdouble)t, (GLdouble)r);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3dvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 437, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[437];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3fARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    double t;
    double r;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 438, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[438];
    ((GLfunction_void_int_float_float_float)funcPtr->funcPtr)((GLenum)target, (GLfloat)s, (GLfloat)t, (GLfloat)r);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3fvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 439, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[439];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3iARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3iARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3iARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    int t;
    int r;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3iARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 440, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[440];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLint)s, (GLint)t, (GLint)r);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3ivARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 441, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[441];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3sARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3sARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3sARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    int t;
    int r;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3sARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 442, objc, 4) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[442];
    ((GLfunction_void_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLshort)s, (GLshort)t, (GLshort)r);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord3svARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord3svARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord3svARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3svARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 443, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[443];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4dARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4dARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4dARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    double t;
    double r;
    double q;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4dARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 444, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &q) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[444];
    ((GLfunction_void_int_double_double_double_double)funcPtr->funcPtr)((GLenum)target, (GLdouble)s, (GLdouble)t, (GLdouble)r, (GLdouble)q);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4dvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4dvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4dvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4dvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 445, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[445];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLdouble*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4fARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4fARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4fARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    double s;
    double t;
    double r;
    double q;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4fARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 446, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetDoubleParam(interp, infoPtr, objv[5], &q) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[446];
    ((GLfunction_void_int_float_float_float_float)funcPtr->funcPtr)((GLenum)target, (GLfloat)s, (GLfloat)t, (GLfloat)r, (GLfloat)q);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4fvARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4fvARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4fvARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4fvARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 447, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[447];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLfloat*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4iARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4iARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4iARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    int t;
    int r;
    int q;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4iARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 448, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &q) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[448];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLint)s, (GLint)t, (GLint)r, (GLint)q);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4ivARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4ivARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4ivARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4ivARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 449, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[449];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLint*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4sARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4sARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4sARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    int s;
    int t;
    int r;
    int q;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4sARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 450, objc, 5) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[2], &s) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[3], &t) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[4], &r) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetIntParam(interp, infoPtr, objv[5], &q) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[450];
    ((GLfunction_void_int_int_int_int_int)funcPtr->funcPtr)((GLenum)target, (GLshort)s, (GLshort)t, (GLshort)r, (GLshort)q);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glMultiTexCoord4svARBCmd()
 *
 *  Handles the OpenGL glMultiTexCoord4svARB command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glMultiTexCoord4svARBCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int target;
    void *v;
    int paramLength1;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4svARBCmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 451, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &target) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetPtrInParam(interp, infoPtr, objv[2], &v, &paramLength1) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[451];
    ((GLfunction_void_int_voidPtr)funcPtr->funcPtr)((GLenum)target, (GLshort*)v);
    return GetGLError(interp, infoPtr);
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_glBlendEquationSeparateATICmd()
 *
 *  Handles the OpenGL glBlendEquationSeparateATI command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_glBlendEquationSeparateATICmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;
    int modeRGB;
    int modeA;
    TclGLFunc *funcPtr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glBlendEquationSeparateATICmd", objc, objv);
    if (CheckNumParams(interp, infoPtr, 452, objc, 2) != TCL_OK) {
        return TCL_ERROR;
    }
    if (GetEnumParam(interp, infoPtr, objv[1], &modeRGB) != TCL_OK) {
        return TCL_ERROR;
    } 
    if (GetEnumParam(interp, infoPtr, objv[2], &modeA) != TCL_OK) {
        return TCL_ERROR;
    } 
    funcPtr = infoPtr->funcv[452];
    ((GLfunction_void_int_int)funcPtr->funcPtr)((GLenum)modeRGB, (GLenum)modeA);
    return GetGLError(interp, infoPtr);
}
