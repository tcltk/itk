

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
    int result;
    int glResult;
    double c;

    glResult = 0;
    hPtr = NULL;
    c  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glClearIndexCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClearIndex <(GLfloat) c>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &c);
    glClearIndex((float)c);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double red;
    double green;
    double blue;
    double alpha;

    glResult = 0;
    hPtr = NULL;
    red  = 0.0;
    green  = 0.0;
    blue  = 0.0;
    alpha  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glClearColorCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClearColor <(GLclampf) red> <(GLclampf) green> <(GLclampf) blue> <(GLclampf) alpha>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &red);
    Tcl_GetDoubleFromObj(interp, objv[2], &green);
    Tcl_GetDoubleFromObj(interp, objv[3], &blue);
    Tcl_GetDoubleFromObj(interp, objv[4], &alpha);
    glClearColor((float)red, (float)green, (float)blue, (float)alpha);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glClearCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClear <(GLbitfield) mask>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glClear not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    int mask;

    glResult = 0;
    hPtr = NULL;
    mask  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glIndexMaskCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexMask <(GLuint) mask>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &mask);
    glIndexMask((unsigned int)mask);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int red;
    int green;
    int blue;
    int alpha;

    glResult = 0;
    hPtr = NULL;
    red  = 0;
    green  = 0;
    blue  = 0;
    alpha  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColorMaskCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColorMask <(GLboolean) red> <(GLboolean) green> <(GLboolean) blue> <(GLboolean) alpha>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetBooleanFromObj(interp, objv[1], &red);
    Tcl_GetBooleanFromObj(interp, objv[2], &green);
    Tcl_GetBooleanFromObj(interp, objv[3], &blue);
    Tcl_GetBooleanFromObj(interp, objv[4], &alpha);
    glColorMask((unsigned char)red, (unsigned char)green, (unsigned char)blue, (unsigned char)alpha);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glAlphaFuncCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glAlphaFunc <(GLenum) func> <(GLclampf) ref>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glAlphaFunc not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glBlendFuncCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glBlendFunc <(GLenum) sfactor> <(GLenum) dfactor>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glBlendFunc not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLogicOpCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLogicOp <(GLenum) opcode>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glLogicOp not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glCullFaceCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCullFace <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glCullFace not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glFrontFaceCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFrontFace <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glFrontFace not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    double size;

    glResult = 0;
    hPtr = NULL;
    size  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPointSizeCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPointSize <(GLfloat) size>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &size);
    glPointSize((float)size);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double width;

    glResult = 0;
    hPtr = NULL;
    width  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLineWidthCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLineWidth <(GLfloat) width>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &width);
    glLineWidth((float)width);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int factor;
    int pattern;

    glResult = 0;
    hPtr = NULL;
    factor  = 0;
    pattern  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLineStippleCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLineStipple <(GLint) factor> <(GLushort) pattern>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &factor);
    Tcl_GetIntFromObj(interp, objv[2], &pattern);
    glLineStipple((int)factor, (unsigned short)pattern);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPolygonModeCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPolygonMode <(GLenum) face> <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glPolygonMode not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    double factor;
    double units;

    glResult = 0;
    hPtr = NULL;
    factor  = 0.0;
    units  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPolygonOffsetCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPolygonOffset <(GLfloat) factor> <(GLfloat) units>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &factor);
    Tcl_GetDoubleFromObj(interp, objv[2], &units);
    glPolygonOffset((float)factor, (float)units);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPolygonStippleCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPolygonStipple <(GLubyte) mask>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glPolygonStipple not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetPolygonStippleCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetPolygonStipple <(GLubyte) mask>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetPolygonStipple not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    int flag;

    glResult = 0;
    hPtr = NULL;
    flag  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEdgeFlagCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEdgeFlag <(GLboolean) flag>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetBooleanFromObj(interp, objv[1], &flag);
    glEdgeFlag((unsigned char)flag);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEdgeFlagvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEdgeFlagv <(GLboolean) flag>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glEdgeFlagv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    int x;
    int y;
    int width;
    int height;

    glResult = 0;
    hPtr = NULL;
    x  = 0;
    y  = 0;
    width  = 0;
    height  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glScissorCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glScissor <(GLint) x> <(GLint) y> <(GLsizei) width> <(GLsizei) height>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    Tcl_GetIntFromObj(interp, objv[3], &width);
    Tcl_GetIntFromObj(interp, objv[4], &height);
    glScissor((int)x, (int)y, (int)width, (int)height);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glClipPlaneCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClipPlane <(GLenum) plane> <(GLdouble) equation>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glClipPlane not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetClipPlaneCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetClipPlane <(GLenum) plane> <(GLdouble) equation>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetClipPlane not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glDrawBufferCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDrawBuffer <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glDrawBuffer not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glReadBufferCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glReadBuffer <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glReadBuffer not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEnableCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEnable <(GLenum) cap>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glEnable not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glDisableCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDisable <(GLenum) cap>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glDisable not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glIsEnabledCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIsEnabled <(GLenum) cap>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glIsEnabled not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEnableClientStateCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEnableClientState <(GLenum) cap>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glEnableClientState not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glDisableClientStateCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDisableClientState <(GLenum) cap>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glDisableClientState not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetBooleanvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetBooleanv <(GLenum) pname> <(GLboolean) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetBooleanv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetDoublevCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetDoublev <(GLenum) pname> <(GLdouble) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetDoublev not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetFloatvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetFloatv <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetFloatv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetIntegervCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetIntegerv <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetIntegerv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPushAttribCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPushAttrib <(GLbitfield) mask>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glPushAttrib not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPopAttribCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPopAttrib \"",
                NULL);
        return TCL_ERROR;
    }


    glPopAttrib();
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPushClientAttribCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPushClientAttrib <(GLbitfield) mask>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glPushClientAttrib not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPopClientAttribCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPopClientAttrib \"",
                NULL);
        return TCL_ERROR;
    }


    glPopClientAttrib();
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRenderModeCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRenderMode <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRenderMode not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetErrorCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetError \"",
                NULL);
        return TCL_ERROR;
    }


    glGetError();
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glFinishCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFinish \"",
                NULL);
        return TCL_ERROR;
    }


    glFinish();
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glFlushCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFlush \"",
                NULL);
        return TCL_ERROR;
    }


    glFlush();
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glHintCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glHint <(GLenum) target> <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glHint not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    double depth;

    glResult = 0;
    hPtr = NULL;
    depth  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glClearDepthCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClearDepth <(GLclampd) depth>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &depth);
    glClearDepth((double)depth);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glDepthFuncCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDepthFunc <(GLenum) func>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glDepthFunc not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    int flag;

    glResult = 0;
    hPtr = NULL;
    flag  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glDepthMaskCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDepthMask <(GLboolean) flag>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetBooleanFromObj(interp, objv[1], &flag);
    glDepthMask((unsigned char)flag);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double near_val;
    double far_val;

    glResult = 0;
    hPtr = NULL;
    near_val  = 0.0;
    far_val  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glDepthRangeCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDepthRange <(GLclampd) near_val> <(GLclampd) far_val>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &near_val);
    Tcl_GetDoubleFromObj(interp, objv[2], &far_val);
    glDepthRange((double)near_val, (double)far_val);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double red;
    double green;
    double blue;
    double alpha;

    glResult = 0;
    hPtr = NULL;
    red  = 0.0;
    green  = 0.0;
    blue  = 0.0;
    alpha  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glClearAccumCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClearAccum <(GLfloat) red> <(GLfloat) green> <(GLfloat) blue> <(GLfloat) alpha>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &red);
    Tcl_GetDoubleFromObj(interp, objv[2], &green);
    Tcl_GetDoubleFromObj(interp, objv[3], &blue);
    Tcl_GetDoubleFromObj(interp, objv[4], &alpha);
    glClearAccum((float)red, (float)green, (float)blue, (float)alpha);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glAccumCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glAccum <(GLenum) op> <(GLfloat) value>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glAccum not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMatrixModeCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMatrixMode <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMatrixMode not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPushMatrixCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPushMatrix \"",
                NULL);
        return TCL_ERROR;
    }


    glPushMatrix();
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPopMatrixCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPopMatrix \"",
                NULL);
        return TCL_ERROR;
    }


    glPopMatrix();
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLoadIdentityCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLoadIdentity \"",
                NULL);
        return TCL_ERROR;
    }


    glLoadIdentity();
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLoadMatrixdCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLoadMatrixd <(GLdouble) m>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glLoadMatrixd not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLoadMatrixfCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLoadMatrixf <(GLfloat) m>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glLoadMatrixf not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultMatrixdCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultMatrixd <(GLdouble) m>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultMatrixd not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultMatrixfCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultMatrixf <(GLfloat) m>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultMatrixf not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    double x;
    double y;
    double z;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    z  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glScaledCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glScaled <(GLdouble) x> <(GLdouble) y> <(GLdouble) z>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glScaled((double)x, (double)y, (double)z);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x;
    double y;
    double z;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    z  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glScalefCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glScalef <(GLfloat) x> <(GLfloat) y> <(GLfloat) z>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glScalef((float)x, (float)y, (float)z);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x;
    double y;
    double z;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    z  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTranslatedCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTranslated <(GLdouble) x> <(GLdouble) y> <(GLdouble) z>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glTranslated((double)x, (double)y, (double)z);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x;
    double y;
    double z;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    z  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTranslatefCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTranslatef <(GLfloat) x> <(GLfloat) y> <(GLfloat) z>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glTranslatef((float)x, (float)y, (float)z);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int list;

    glResult = 0;
    hPtr = NULL;
    list  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glIsListCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIsList <(GLuint) list>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &list);
    glIsList((unsigned int)list);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int list;
    int range;

    glResult = 0;
    hPtr = NULL;
    list  = 0;
    range  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glDeleteListsCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDeleteLists <(GLuint) list> <(GLsizei) range>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &list);
    Tcl_GetIntFromObj(interp, objv[2], &range);
    glDeleteLists((unsigned int)list, (int)range);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int range;

    glResult = 0;
    hPtr = NULL;
    range  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGenListsCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGenLists <(GLsizei) range>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &range);
    glGenLists((int)range);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glNewListCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNewList <(GLuint) list> <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glNewList not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEndListCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEndList \"",
                NULL);
        return TCL_ERROR;
    }


    glEndList();
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int list;

    glResult = 0;
    hPtr = NULL;
    list  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glCallListCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCallList <(GLuint) list>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &list);
    glCallList((unsigned int)list);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int base;

    glResult = 0;
    hPtr = NULL;
    base  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glListBaseCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glListBase <(GLuint) base>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &base);
    glListBase((unsigned int)base);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glBeginCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glBegin <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glBegin not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEndCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEnd \"",
                NULL);
        return TCL_ERROR;
    }


    glEnd();
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x;
    double y;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex2dCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2d <(GLdouble) x> <(GLdouble) y>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    glVertex2d((double)x, (double)y);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x;
    double y;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex2fCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2f <(GLfloat) x> <(GLfloat) y>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    glVertex2f((float)x, (float)y);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int x;
    int y;

    glResult = 0;
    hPtr = NULL;
    x  = 0;
    y  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex2iCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2i <(GLint) x> <(GLint) y>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    glVertex2i((int)x, (int)y);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int x;
    int y;

    glResult = 0;
    hPtr = NULL;
    x  = 0;
    y  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex2sCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2s <(GLshort) x> <(GLshort) y>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    glVertex2s((short)x, (short)y);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x;
    double y;
    double z;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    z  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex3dCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3d <(GLdouble) x> <(GLdouble) y> <(GLdouble) z>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glVertex3d((double)x, (double)y, (double)z);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x;
    double y;
    double z;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    z  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex3fCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3f <(GLfloat) x> <(GLfloat) y> <(GLfloat) z>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glVertex3f((float)x, (float)y, (float)z);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int x;
    int y;
    int z;

    glResult = 0;
    hPtr = NULL;
    x  = 0;
    y  = 0;
    z  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex3iCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3i <(GLint) x> <(GLint) y> <(GLint) z>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    Tcl_GetIntFromObj(interp, objv[3], &z);
    glVertex3i((int)x, (int)y, (int)z);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int x;
    int y;
    int z;

    glResult = 0;
    hPtr = NULL;
    x  = 0;
    y  = 0;
    z  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex3sCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3s <(GLshort) x> <(GLshort) y> <(GLshort) z>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    Tcl_GetIntFromObj(interp, objv[3], &z);
    glVertex3s((short)x, (short)y, (short)z);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x;
    double y;
    double z;
    double w;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    z  = 0.0;
    w  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex4dCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex4d <(GLdouble) x> <(GLdouble) y> <(GLdouble) z> <(GLdouble) w>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    Tcl_GetDoubleFromObj(interp, objv[4], &w);
    glVertex4d((double)x, (double)y, (double)z, (double)w);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x;
    double y;
    double z;
    double w;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    z  = 0.0;
    w  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex4fCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex4f <(GLfloat) x> <(GLfloat) y> <(GLfloat) z> <(GLfloat) w>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    Tcl_GetDoubleFromObj(interp, objv[4], &w);
    glVertex4f((float)x, (float)y, (float)z, (float)w);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int x;
    int y;
    int z;
    int w;

    glResult = 0;
    hPtr = NULL;
    x  = 0;
    y  = 0;
    z  = 0;
    w  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex4iCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex4i <(GLint) x> <(GLint) y> <(GLint) z> <(GLint) w>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    Tcl_GetIntFromObj(interp, objv[3], &z);
    Tcl_GetIntFromObj(interp, objv[4], &w);
    glVertex4i((int)x, (int)y, (int)z, (int)w);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int x;
    int y;
    int z;
    int w;

    glResult = 0;
    hPtr = NULL;
    x  = 0;
    y  = 0;
    z  = 0;
    w  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex4sCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex4s <(GLshort) x> <(GLshort) y> <(GLshort) z> <(GLshort) w>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    Tcl_GetIntFromObj(interp, objv[3], &z);
    Tcl_GetIntFromObj(interp, objv[4], &w);
    glVertex4s((short)x, (short)y, (short)z, (short)w);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex2dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glVertex2dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex2fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glVertex2fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex2ivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glVertex2iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex2svCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glVertex2sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex3dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glVertex3dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex3fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glVertex3fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex3ivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glVertex3iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex3svCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glVertex3sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex4dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex4dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glVertex4dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex4fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex4fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glVertex4fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex4ivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex4iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glVertex4iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glVertex4svCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex4sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glVertex4sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    int nx;
    int ny;
    int nz;

    glResult = 0;
    hPtr = NULL;
    nx  = 0;
    ny  = 0;
    nz  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glNormal3bCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3b <(GLbyte) nx> <(GLbyte) ny> <(GLbyte) nz>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &nx);
    Tcl_GetIntFromObj(interp, objv[2], &ny);
    Tcl_GetIntFromObj(interp, objv[3], &nz);
    glNormal3b((signed char)nx, (signed char)ny, (signed char)nz);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double nx;
    double ny;
    double nz;

    glResult = 0;
    hPtr = NULL;
    nx  = 0.0;
    ny  = 0.0;
    nz  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glNormal3dCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3d <(GLdouble) nx> <(GLdouble) ny> <(GLdouble) nz>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &nx);
    Tcl_GetDoubleFromObj(interp, objv[2], &ny);
    Tcl_GetDoubleFromObj(interp, objv[3], &nz);
    glNormal3d((double)nx, (double)ny, (double)nz);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double nx;
    double ny;
    double nz;

    glResult = 0;
    hPtr = NULL;
    nx  = 0.0;
    ny  = 0.0;
    nz  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glNormal3fCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3f <(GLfloat) nx> <(GLfloat) ny> <(GLfloat) nz>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &nx);
    Tcl_GetDoubleFromObj(interp, objv[2], &ny);
    Tcl_GetDoubleFromObj(interp, objv[3], &nz);
    glNormal3f((float)nx, (float)ny, (float)nz);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int nx;
    int ny;
    int nz;

    glResult = 0;
    hPtr = NULL;
    nx  = 0;
    ny  = 0;
    nz  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glNormal3iCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3i <(GLint) nx> <(GLint) ny> <(GLint) nz>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &nx);
    Tcl_GetIntFromObj(interp, objv[2], &ny);
    Tcl_GetIntFromObj(interp, objv[3], &nz);
    glNormal3i((int)nx, (int)ny, (int)nz);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int nx;
    int ny;
    int nz;

    glResult = 0;
    hPtr = NULL;
    nx  = 0;
    ny  = 0;
    nz  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glNormal3sCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3s <(GLshort) nx> <(GLshort) ny> <(GLshort) nz>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &nx);
    Tcl_GetIntFromObj(interp, objv[2], &ny);
    Tcl_GetIntFromObj(interp, objv[3], &nz);
    glNormal3s((short)nx, (short)ny, (short)nz);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glNormal3bvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3bv <(GLbyte) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glNormal3bv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glNormal3dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glNormal3dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glNormal3fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glNormal3fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glNormal3ivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glNormal3iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glNormal3svCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glNormal3sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    double c;

    glResult = 0;
    hPtr = NULL;
    c  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glIndexdCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexd <(GLdouble) c>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &c);
    glIndexd((double)c);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double c;

    glResult = 0;
    hPtr = NULL;
    c  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glIndexfCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexf <(GLfloat) c>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &c);
    glIndexf((float)c);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int c;

    glResult = 0;
    hPtr = NULL;
    c  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glIndexiCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexi <(GLint) c>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &c);
    glIndexi((int)c);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int c;

    glResult = 0;
    hPtr = NULL;
    c  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glIndexsCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexs <(GLshort) c>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &c);
    glIndexs((short)c);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int c;

    glResult = 0;
    hPtr = NULL;
    c  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glIndexubCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexub <(GLubyte) c>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &c);
    glIndexub((unsigned char)c);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glIndexdvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexdv <(GLdouble) c>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glIndexdv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glIndexfvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexfv <(GLfloat) c>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glIndexfv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glIndexivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexiv <(GLint) c>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glIndexiv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glIndexsvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexsv <(GLshort) c>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glIndexsv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glIndexubvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexubv <(GLubyte) c>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glIndexubv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    int red;
    int green;
    int blue;

    glResult = 0;
    hPtr = NULL;
    red  = 0;
    green  = 0;
    blue  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3bCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3b <(GLbyte) red> <(GLbyte) green> <(GLbyte) blue>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &red);
    Tcl_GetIntFromObj(interp, objv[2], &green);
    Tcl_GetIntFromObj(interp, objv[3], &blue);
    glColor3b((signed char)red, (signed char)green, (signed char)blue);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double red;
    double green;
    double blue;

    glResult = 0;
    hPtr = NULL;
    red  = 0.0;
    green  = 0.0;
    blue  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3dCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3d <(GLdouble) red> <(GLdouble) green> <(GLdouble) blue>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &red);
    Tcl_GetDoubleFromObj(interp, objv[2], &green);
    Tcl_GetDoubleFromObj(interp, objv[3], &blue);
    glColor3d((double)red, (double)green, (double)blue);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double red;
    double green;
    double blue;

    glResult = 0;
    hPtr = NULL;
    red  = 0.0;
    green  = 0.0;
    blue  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3fCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3f <(GLfloat) red> <(GLfloat) green> <(GLfloat) blue>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &red);
    Tcl_GetDoubleFromObj(interp, objv[2], &green);
    Tcl_GetDoubleFromObj(interp, objv[3], &blue);
    glColor3f((float)red, (float)green, (float)blue);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int red;
    int green;
    int blue;

    glResult = 0;
    hPtr = NULL;
    red  = 0;
    green  = 0;
    blue  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3iCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3i <(GLint) red> <(GLint) green> <(GLint) blue>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &red);
    Tcl_GetIntFromObj(interp, objv[2], &green);
    Tcl_GetIntFromObj(interp, objv[3], &blue);
    glColor3i((int)red, (int)green, (int)blue);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int red;
    int green;
    int blue;

    glResult = 0;
    hPtr = NULL;
    red  = 0;
    green  = 0;
    blue  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3sCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3s <(GLshort) red> <(GLshort) green> <(GLshort) blue>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &red);
    Tcl_GetIntFromObj(interp, objv[2], &green);
    Tcl_GetIntFromObj(interp, objv[3], &blue);
    glColor3s((short)red, (short)green, (short)blue);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int red;
    int green;
    int blue;

    glResult = 0;
    hPtr = NULL;
    red  = 0;
    green  = 0;
    blue  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3ubCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3ub <(GLubyte) red> <(GLubyte) green> <(GLubyte) blue>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &red);
    Tcl_GetIntFromObj(interp, objv[2], &green);
    Tcl_GetIntFromObj(interp, objv[3], &blue);
    glColor3ub((unsigned char)red, (unsigned char)green, (unsigned char)blue);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int red;
    int green;
    int blue;

    glResult = 0;
    hPtr = NULL;
    red  = 0;
    green  = 0;
    blue  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3uiCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3ui <(GLuint) red> <(GLuint) green> <(GLuint) blue>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &red);
    Tcl_GetIntFromObj(interp, objv[2], &green);
    Tcl_GetIntFromObj(interp, objv[3], &blue);
    glColor3ui((unsigned int)red, (unsigned int)green, (unsigned int)blue);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int red;
    int green;
    int blue;

    glResult = 0;
    hPtr = NULL;
    red  = 0;
    green  = 0;
    blue  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3usCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3us <(GLushort) red> <(GLushort) green> <(GLushort) blue>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &red);
    Tcl_GetIntFromObj(interp, objv[2], &green);
    Tcl_GetIntFromObj(interp, objv[3], &blue);
    glColor3us((unsigned short)red, (unsigned short)green, (unsigned short)blue);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3bvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3bv <(GLbyte) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor3bv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor3dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor3fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3ivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor3iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3svCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor3sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3ubvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3ubv <(GLubyte) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor3ubv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3uivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3uiv <(GLuint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor3uiv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor3usvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3usv <(GLushort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor3usv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor4bvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4bv <(GLbyte) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor4bv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor4dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor4dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor4fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor4fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor4ivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor4iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor4svCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor4sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor4ubvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4ubv <(GLubyte) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor4ubv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor4uivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4uiv <(GLuint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor4uiv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColor4usvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4usv <(GLushort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColor4usv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    double s;

    glResult = 0;
    hPtr = NULL;
    s  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord1dCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1d <(GLdouble) s>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &s);
    glTexCoord1d((double)s);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double s;

    glResult = 0;
    hPtr = NULL;
    s  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord1fCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1f <(GLfloat) s>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &s);
    glTexCoord1f((float)s);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int s;

    glResult = 0;
    hPtr = NULL;
    s  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord1iCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1i <(GLint) s>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &s);
    glTexCoord1i((int)s);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int s;

    glResult = 0;
    hPtr = NULL;
    s  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord1sCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1s <(GLshort) s>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &s);
    glTexCoord1s((short)s);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double s;
    double t;

    glResult = 0;
    hPtr = NULL;
    s  = 0.0;
    t  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord2dCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2d <(GLdouble) s> <(GLdouble) t>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &s);
    Tcl_GetDoubleFromObj(interp, objv[2], &t);
    glTexCoord2d((double)s, (double)t);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double s;
    double t;

    glResult = 0;
    hPtr = NULL;
    s  = 0.0;
    t  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord2fCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2f <(GLfloat) s> <(GLfloat) t>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &s);
    Tcl_GetDoubleFromObj(interp, objv[2], &t);
    glTexCoord2f((float)s, (float)t);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int s;
    int t;

    glResult = 0;
    hPtr = NULL;
    s  = 0;
    t  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord2iCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2i <(GLint) s> <(GLint) t>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &s);
    Tcl_GetIntFromObj(interp, objv[2], &t);
    glTexCoord2i((int)s, (int)t);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int s;
    int t;

    glResult = 0;
    hPtr = NULL;
    s  = 0;
    t  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord2sCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2s <(GLshort) s> <(GLshort) t>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &s);
    Tcl_GetIntFromObj(interp, objv[2], &t);
    glTexCoord2s((short)s, (short)t);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double s;
    double t;
    double r;

    glResult = 0;
    hPtr = NULL;
    s  = 0.0;
    t  = 0.0;
    r  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord3dCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3d <(GLdouble) s> <(GLdouble) t> <(GLdouble) r>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &s);
    Tcl_GetDoubleFromObj(interp, objv[2], &t);
    Tcl_GetDoubleFromObj(interp, objv[3], &r);
    glTexCoord3d((double)s, (double)t, (double)r);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double s;
    double t;
    double r;

    glResult = 0;
    hPtr = NULL;
    s  = 0.0;
    t  = 0.0;
    r  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord3fCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3f <(GLfloat) s> <(GLfloat) t> <(GLfloat) r>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &s);
    Tcl_GetDoubleFromObj(interp, objv[2], &t);
    Tcl_GetDoubleFromObj(interp, objv[3], &r);
    glTexCoord3f((float)s, (float)t, (float)r);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int s;
    int t;
    int r;

    glResult = 0;
    hPtr = NULL;
    s  = 0;
    t  = 0;
    r  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord3iCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3i <(GLint) s> <(GLint) t> <(GLint) r>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &s);
    Tcl_GetIntFromObj(interp, objv[2], &t);
    Tcl_GetIntFromObj(interp, objv[3], &r);
    glTexCoord3i((int)s, (int)t, (int)r);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int s;
    int t;
    int r;

    glResult = 0;
    hPtr = NULL;
    s  = 0;
    t  = 0;
    r  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord3sCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3s <(GLshort) s> <(GLshort) t> <(GLshort) r>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &s);
    Tcl_GetIntFromObj(interp, objv[2], &t);
    Tcl_GetIntFromObj(interp, objv[3], &r);
    glTexCoord3s((short)s, (short)t, (short)r);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double s;
    double t;
    double r;
    double q;

    glResult = 0;
    hPtr = NULL;
    s  = 0.0;
    t  = 0.0;
    r  = 0.0;
    q  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord4dCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord4d <(GLdouble) s> <(GLdouble) t> <(GLdouble) r> <(GLdouble) q>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &s);
    Tcl_GetDoubleFromObj(interp, objv[2], &t);
    Tcl_GetDoubleFromObj(interp, objv[3], &r);
    Tcl_GetDoubleFromObj(interp, objv[4], &q);
    glTexCoord4d((double)s, (double)t, (double)r, (double)q);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double s;
    double t;
    double r;
    double q;

    glResult = 0;
    hPtr = NULL;
    s  = 0.0;
    t  = 0.0;
    r  = 0.0;
    q  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord4fCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord4f <(GLfloat) s> <(GLfloat) t> <(GLfloat) r> <(GLfloat) q>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &s);
    Tcl_GetDoubleFromObj(interp, objv[2], &t);
    Tcl_GetDoubleFromObj(interp, objv[3], &r);
    Tcl_GetDoubleFromObj(interp, objv[4], &q);
    glTexCoord4f((float)s, (float)t, (float)r, (float)q);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int s;
    int t;
    int r;
    int q;

    glResult = 0;
    hPtr = NULL;
    s  = 0;
    t  = 0;
    r  = 0;
    q  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord4iCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord4i <(GLint) s> <(GLint) t> <(GLint) r> <(GLint) q>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &s);
    Tcl_GetIntFromObj(interp, objv[2], &t);
    Tcl_GetIntFromObj(interp, objv[3], &r);
    Tcl_GetIntFromObj(interp, objv[4], &q);
    glTexCoord4i((int)s, (int)t, (int)r, (int)q);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int s;
    int t;
    int r;
    int q;

    glResult = 0;
    hPtr = NULL;
    s  = 0;
    t  = 0;
    r  = 0;
    q  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord4sCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord4s <(GLshort) s> <(GLshort) t> <(GLshort) r> <(GLshort) q>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &s);
    Tcl_GetIntFromObj(interp, objv[2], &t);
    Tcl_GetIntFromObj(interp, objv[3], &r);
    Tcl_GetIntFromObj(interp, objv[4], &q);
    glTexCoord4s((short)s, (short)t, (short)r, (short)q);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord1dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord1dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord1fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord1fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord1ivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord1iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord1svCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord1sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord2dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord2dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord2fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord2fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord2ivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord2iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord2svCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord2sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord3dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord3dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord3fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord3fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord3ivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord3iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord3svCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord3sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord4dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord4dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord4dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord4fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord4fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord4fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord4ivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord4iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord4iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexCoord4svCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord4sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexCoord4sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    double x;
    double y;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos2dCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2d <(GLdouble) x> <(GLdouble) y>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    glRasterPos2d((double)x, (double)y);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x;
    double y;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos2fCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2f <(GLfloat) x> <(GLfloat) y>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    glRasterPos2f((float)x, (float)y);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int x;
    int y;

    glResult = 0;
    hPtr = NULL;
    x  = 0;
    y  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos2iCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2i <(GLint) x> <(GLint) y>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    glRasterPos2i((int)x, (int)y);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int x;
    int y;

    glResult = 0;
    hPtr = NULL;
    x  = 0;
    y  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos2sCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2s <(GLshort) x> <(GLshort) y>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    glRasterPos2s((short)x, (short)y);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x;
    double y;
    double z;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    z  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos3dCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3d <(GLdouble) x> <(GLdouble) y> <(GLdouble) z>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glRasterPos3d((double)x, (double)y, (double)z);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x;
    double y;
    double z;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    z  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos3fCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3f <(GLfloat) x> <(GLfloat) y> <(GLfloat) z>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glRasterPos3f((float)x, (float)y, (float)z);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int x;
    int y;
    int z;

    glResult = 0;
    hPtr = NULL;
    x  = 0;
    y  = 0;
    z  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos3iCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3i <(GLint) x> <(GLint) y> <(GLint) z>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    Tcl_GetIntFromObj(interp, objv[3], &z);
    glRasterPos3i((int)x, (int)y, (int)z);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int x;
    int y;
    int z;

    glResult = 0;
    hPtr = NULL;
    x  = 0;
    y  = 0;
    z  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos3sCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3s <(GLshort) x> <(GLshort) y> <(GLshort) z>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    Tcl_GetIntFromObj(interp, objv[3], &z);
    glRasterPos3s((short)x, (short)y, (short)z);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x;
    double y;
    double z;
    double w;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    z  = 0.0;
    w  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos4dCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos4d <(GLdouble) x> <(GLdouble) y> <(GLdouble) z> <(GLdouble) w>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    Tcl_GetDoubleFromObj(interp, objv[4], &w);
    glRasterPos4d((double)x, (double)y, (double)z, (double)w);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x;
    double y;
    double z;
    double w;

    glResult = 0;
    hPtr = NULL;
    x  = 0.0;
    y  = 0.0;
    z  = 0.0;
    w  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos4fCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos4f <(GLfloat) x> <(GLfloat) y> <(GLfloat) z> <(GLfloat) w>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    Tcl_GetDoubleFromObj(interp, objv[4], &w);
    glRasterPos4f((float)x, (float)y, (float)z, (float)w);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int x;
    int y;
    int z;
    int w;

    glResult = 0;
    hPtr = NULL;
    x  = 0;
    y  = 0;
    z  = 0;
    w  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos4iCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos4i <(GLint) x> <(GLint) y> <(GLint) z> <(GLint) w>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    Tcl_GetIntFromObj(interp, objv[3], &z);
    Tcl_GetIntFromObj(interp, objv[4], &w);
    glRasterPos4i((int)x, (int)y, (int)z, (int)w);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int x;
    int y;
    int z;
    int w;

    glResult = 0;
    hPtr = NULL;
    x  = 0;
    y  = 0;
    z  = 0;
    w  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos4sCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos4s <(GLshort) x> <(GLshort) y> <(GLshort) z> <(GLshort) w>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    Tcl_GetIntFromObj(interp, objv[3], &z);
    Tcl_GetIntFromObj(interp, objv[4], &w);
    glRasterPos4s((short)x, (short)y, (short)z, (short)w);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos2dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRasterPos2dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos2fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRasterPos2fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos2ivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRasterPos2iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos2svCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRasterPos2sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos3dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRasterPos3dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos3fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRasterPos3fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos3ivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRasterPos3iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos3svCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRasterPos3sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos4dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos4dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRasterPos4dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos4fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos4fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRasterPos4fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos4ivCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos4iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRasterPos4iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRasterPos4svCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos4sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRasterPos4sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    double x1;
    double y1;
    double x2;
    double y2;

    glResult = 0;
    hPtr = NULL;
    x1  = 0.0;
    y1  = 0.0;
    x2  = 0.0;
    y2  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRectdCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRectd <(GLdouble) x1> <(GLdouble) y1> <(GLdouble) x2> <(GLdouble) y2>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x1);
    Tcl_GetDoubleFromObj(interp, objv[2], &y1);
    Tcl_GetDoubleFromObj(interp, objv[3], &x2);
    Tcl_GetDoubleFromObj(interp, objv[4], &y2);
    glRectd((double)x1, (double)y1, (double)x2, (double)y2);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double x1;
    double y1;
    double x2;
    double y2;

    glResult = 0;
    hPtr = NULL;
    x1  = 0.0;
    y1  = 0.0;
    x2  = 0.0;
    y2  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRectfCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRectf <(GLfloat) x1> <(GLfloat) y1> <(GLfloat) x2> <(GLfloat) y2>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &x1);
    Tcl_GetDoubleFromObj(interp, objv[2], &y1);
    Tcl_GetDoubleFromObj(interp, objv[3], &x2);
    Tcl_GetDoubleFromObj(interp, objv[4], &y2);
    glRectf((float)x1, (float)y1, (float)x2, (float)y2);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int x1;
    int y1;
    int x2;
    int y2;

    glResult = 0;
    hPtr = NULL;
    x1  = 0;
    y1  = 0;
    x2  = 0;
    y2  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRectiCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRecti <(GLint) x1> <(GLint) y1> <(GLint) x2> <(GLint) y2>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x1);
    Tcl_GetIntFromObj(interp, objv[2], &y1);
    Tcl_GetIntFromObj(interp, objv[3], &x2);
    Tcl_GetIntFromObj(interp, objv[4], &y2);
    glRecti((int)x1, (int)y1, (int)x2, (int)y2);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int x1;
    int y1;
    int x2;
    int y2;

    glResult = 0;
    hPtr = NULL;
    x1  = 0;
    y1  = 0;
    x2  = 0;
    y2  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRectsCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRects <(GLshort) x1> <(GLshort) y1> <(GLshort) x2> <(GLshort) y2>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &x1);
    Tcl_GetIntFromObj(interp, objv[2], &y1);
    Tcl_GetIntFromObj(interp, objv[3], &x2);
    Tcl_GetIntFromObj(interp, objv[4], &y2);
    glRects((short)x1, (short)y1, (short)x2, (short)y2);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRectdvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRectdv <(GLdouble) v1> <(GLdouble) v2>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRectdv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRectfvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRectfv <(GLfloat) v1> <(GLfloat) v2>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRectfv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRectivCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRectiv <(GLint) v1> <(GLint) v2>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRectiv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glRectsvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRectsv <(GLshort) v1> <(GLshort) v2>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glRectsv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEdgeFlagPointerCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEdgeFlagPointer <(GLsizei) stride> <(GLvoid) ptr>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glEdgeFlagPointer not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetPointervCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetPointerv <(GLenum) pname> <(GLvoid) *params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetPointerv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    int i;

    glResult = 0;
    hPtr = NULL;
    i  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glArrayElementCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glArrayElement <(GLint) i>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &i);
    glArrayElement((int)i);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glDrawArraysCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDrawArrays <(GLenum) mode> <(GLint) first> <(GLsizei) count>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glDrawArrays not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glShadeModelCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glShadeModel <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glShadeModel not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLightfCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLightf <(GLenum) light> <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glLightf not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLightiCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLighti <(GLenum) light> <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glLighti not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLightModelfCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLightModelf <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glLightModelf not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLightModeliCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLightModeli <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glLightModeli not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLightModelfvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLightModelfv <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glLightModelfv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLightModelivCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLightModeliv <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glLightModeliv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMaterialfCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMaterialf <(GLenum) face> <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMaterialf not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMaterialiCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMateriali <(GLenum) face> <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMateriali not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMaterialfvCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMaterialfv <(GLenum) face> <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMaterialfv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMaterialivCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMaterialiv <(GLenum) face> <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMaterialiv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetMaterialfvCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetMaterialfv <(GLenum) face> <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetMaterialfv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetMaterialivCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetMaterialiv <(GLenum) face> <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetMaterialiv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glColorMaterialCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColorMaterial <(GLenum) face> <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glColorMaterial not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    double xfactor;
    double yfactor;

    glResult = 0;
    hPtr = NULL;
    xfactor  = 0.0;
    yfactor  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPixelZoomCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPixelZoom <(GLfloat) xfactor> <(GLfloat) yfactor>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &xfactor);
    Tcl_GetDoubleFromObj(interp, objv[2], &yfactor);
    glPixelZoom((float)xfactor, (float)yfactor);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPixelStorefCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPixelStoref <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glPixelStoref not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPixelStoreiCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPixelStorei <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glPixelStorei not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPixelTransferfCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPixelTransferf <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glPixelTransferf not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPixelTransferiCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPixelTransferi <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glPixelTransferi not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetPixelMapfvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetPixelMapfv <(GLenum) map> <(GLfloat) values>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetPixelMapfv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetPixelMapuivCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetPixelMapuiv <(GLenum) map> <(GLuint) values>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetPixelMapuiv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetPixelMapusvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetPixelMapusv <(GLenum) map> <(GLushort) values>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetPixelMapusv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glStencilFuncCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glStencilFunc <(GLenum) func> <(GLint) ref> <(GLuint) mask>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glStencilFunc not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    int mask;

    glResult = 0;
    hPtr = NULL;
    mask  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glStencilMaskCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glStencilMask <(GLuint) mask>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &mask);
    glStencilMask((unsigned int)mask);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glStencilOpCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glStencilOp <(GLenum) fail> <(GLenum) zfail> <(GLenum) zpass>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glStencilOp not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    int s;

    glResult = 0;
    hPtr = NULL;
    s  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glClearStencilCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClearStencil <(GLint) s>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &s);
    glClearStencil((int)s);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexGendCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexGend <(GLenum) coord> <(GLenum) pname> <(GLdouble) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexGend not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexGenfCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexGenf <(GLenum) coord> <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexGenf not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexGeniCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexGeni <(GLenum) coord> <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexGeni not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexGendvCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexGendv <(GLenum) coord> <(GLenum) pname> <(GLdouble) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexGendv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexGenfvCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexGenfv <(GLenum) coord> <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexGenfv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexGenivCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexGeniv <(GLenum) coord> <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexGeniv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetTexGendvCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetTexGendv <(GLenum) coord> <(GLenum) pname> <(GLdouble) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetTexGendv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetTexGenfvCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetTexGenfv <(GLenum) coord> <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetTexGenfv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetTexGenivCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetTexGeniv <(GLenum) coord> <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetTexGeniv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexEnvfCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexEnvf <(GLenum) target> <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexEnvf not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexEnviCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexEnvi <(GLenum) target> <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexEnvi not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexEnvfvCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexEnvfv <(GLenum) target> <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexEnvfv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexEnvivCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexEnviv <(GLenum) target> <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexEnviv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetTexEnvfvCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetTexEnvfv <(GLenum) target> <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetTexEnvfv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetTexEnvivCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetTexEnviv <(GLenum) target> <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetTexEnviv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexParameterfCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexParameterf <(GLenum) target> <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexParameterf not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glTexParameteriCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexParameteri <(GLenum) target> <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glTexParameteri not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGenTexturesCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGenTextures <(GLsizei) n> <(GLuint) textures>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGenTextures not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glDeleteTexturesCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDeleteTextures <(GLsizei) n> <(GLuint) textures>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glDeleteTextures not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glBindTextureCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glBindTexture <(GLenum) target> <(GLuint) texture>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glBindTexture not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    int texture;

    glResult = 0;
    hPtr = NULL;
    texture  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glIsTextureCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIsTexture <(GLuint) texture>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &texture);
    glIsTexture((unsigned int)texture);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetMapdvCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetMapdv <(GLenum) target> <(GLenum) query> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetMapdv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetMapfvCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetMapfv <(GLenum) target> <(GLenum) query> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetMapfv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetMapivCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetMapiv <(GLenum) target> <(GLenum) query> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetMapiv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    double u;

    glResult = 0;
    hPtr = NULL;
    u  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEvalCoord1dCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord1d <(GLdouble) u>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &u);
    glEvalCoord1d((double)u);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double u;

    glResult = 0;
    hPtr = NULL;
    u  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEvalCoord1fCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord1f <(GLfloat) u>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &u);
    glEvalCoord1f((float)u);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEvalCoord1dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord1dv <(GLdouble) u>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glEvalCoord1dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEvalCoord1fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord1fv <(GLfloat) u>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glEvalCoord1fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    double u;
    double v;

    glResult = 0;
    hPtr = NULL;
    u  = 0.0;
    v  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEvalCoord2dCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord2d <(GLdouble) u> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &u);
    Tcl_GetDoubleFromObj(interp, objv[2], &v);
    glEvalCoord2d((double)u, (double)v);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    double u;
    double v;

    glResult = 0;
    hPtr = NULL;
    u  = 0.0;
    v  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEvalCoord2fCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord2f <(GLfloat) u> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &u);
    Tcl_GetDoubleFromObj(interp, objv[2], &v);
    glEvalCoord2f((float)u, (float)v);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEvalCoord2dvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord2dv <(GLdouble) u>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glEvalCoord2dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEvalCoord2fvCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord2fv <(GLfloat) u>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glEvalCoord2fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    int un;
    double u1;
    double u2;

    glResult = 0;
    hPtr = NULL;
    un  = 0;
    u1  = 0.0;
    u2  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMapGrid1dCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMapGrid1d <(GLint) un> <(GLdouble) u1> <(GLdouble) u2>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &un);
    Tcl_GetDoubleFromObj(interp, objv[2], &u1);
    Tcl_GetDoubleFromObj(interp, objv[3], &u2);
    glMapGrid1d((int)un, (double)u1, (double)u2);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int un;
    double u1;
    double u2;

    glResult = 0;
    hPtr = NULL;
    un  = 0;
    u1  = 0.0;
    u2  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMapGrid1fCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMapGrid1f <(GLint) un> <(GLfloat) u1> <(GLfloat) u2>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &un);
    Tcl_GetDoubleFromObj(interp, objv[2], &u1);
    Tcl_GetDoubleFromObj(interp, objv[3], &u2);
    glMapGrid1f((int)un, (float)u1, (float)u2);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int i;

    glResult = 0;
    hPtr = NULL;
    i  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEvalPoint1Cmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalPoint1 <(GLint) i>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &i);
    glEvalPoint1((int)i);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int i;
    int j;

    glResult = 0;
    hPtr = NULL;
    i  = 0;
    j  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEvalPoint2Cmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalPoint2 <(GLint) i> <(GLint) j>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &i);
    Tcl_GetIntFromObj(interp, objv[2], &j);
    glEvalPoint2((int)i, (int)j);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEvalMesh1Cmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalMesh1 <(GLenum) mode> <(GLint) i1> <(GLint) i2>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glEvalMesh1 not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glEvalMesh2Cmd", objc, objv);

    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalMesh2 <(GLenum) mode> <(GLint) i1> <(GLint) i2> <(GLint) j1> <(GLint) j2>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glEvalMesh2 not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glFogfCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFogf <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glFogf not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glFogiCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFogi <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glFogi not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glFogfvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFogfv <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glFogfv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glFogivCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFogiv <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glFogiv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glFeedbackBufferCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFeedbackBuffer <(GLsizei) size> <(GLenum) type> <(GLfloat) buffer>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glFeedbackBuffer not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    double token;

    glResult = 0;
    hPtr = NULL;
    token  = 0.0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPassThroughCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPassThrough <(GLfloat) token>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &token);
    glPassThrough((float)token);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glSelectBufferCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glSelectBuffer <(GLsizei) size> <(GLuint) buffer>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glSelectBuffer not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glInitNamesCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glInitNames \"",
                NULL);
        return TCL_ERROR;
    }


    glInitNames();
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int name;

    glResult = 0;
    hPtr = NULL;
    name  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLoadNameCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLoadName <(GLuint) name>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &name);
    glLoadName((unsigned int)name);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;
    int name;

    glResult = 0;
    hPtr = NULL;
    name  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPushNameCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPushName <(GLuint) name>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetIntFromObj(interp, objv[1], &name);
    glPushName((unsigned int)name);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glPopNameCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPopName \"",
                NULL);
        return TCL_ERROR;
    }


    glPopName();
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glBlendEquationCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glBlendEquation <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glBlendEquation not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glResetHistogramCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glResetHistogram <(GLenum) target>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glResetHistogram not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glResetMinmaxCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glResetMinmax <(GLenum) target>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glResetMinmax not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glActiveTextureCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glActiveTexture <(GLenum) texture>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glActiveTexture not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glClientActiveTextureCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClientActiveTexture <(GLenum) texture>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glClientActiveTexture not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glCompressedTexImage1DCmd", objc, objv);

    if (objc != 8) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCompressedTexImage1D <(GLenum) target> <(GLint) level> <(GLenum) internalformat> <(GLsizei) width> <(GLint) border> <(GLsizei) imageSize> <(GLvoid) data>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glCompressedTexImage1D not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glCompressedTexImage2DCmd", objc, objv);

    if (objc != 9) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCompressedTexImage2D <(GLenum) target> <(GLint) level> <(GLenum) internalformat> <(GLsizei) width> <(GLsizei) height> <(GLint) border> <(GLsizei) imageSize> <(GLvoid) data>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glCompressedTexImage2D not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glCompressedTexImage3DCmd", objc, objv);

    if (objc != 10) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCompressedTexImage3D <(GLenum) target> <(GLint) level> <(GLenum) internalformat> <(GLsizei) width> <(GLsizei) height> <(GLsizei) depth> <(GLint) border> <(GLsizei) imageSize> <(GLvoid) data>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glCompressedTexImage3D not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glCompressedTexSubImage1DCmd", objc, objv);

    if (objc != 8) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCompressedTexSubImage1D <(GLenum) target> <(GLint) level> <(GLint) xoffset> <(GLsizei) width> <(GLenum) format> <(GLsizei) imageSize> <(GLvoid) data>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glCompressedTexSubImage1D not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glCompressedTexSubImage2DCmd", objc, objv);

    if (objc != 10) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCompressedTexSubImage2D <(GLenum) target> <(GLint) level> <(GLint) xoffset> <(GLint) yoffset> <(GLsizei) width> <(GLsizei) height> <(GLenum) format> <(GLsizei) imageSize> <(GLvoid) data>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glCompressedTexSubImage2D not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glCompressedTexSubImage3DCmd", objc, objv);

    if (objc != 12) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCompressedTexSubImage3D <(GLenum) target> <(GLint) level> <(GLint) xoffset> <(GLint) yoffset> <(GLint) zoffset> <(GLsizei) width> <(GLsizei) height> <(GLsizei) depth> <(GLenum) format> <(GLsizei) imageSize> <(GLvoid) data>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glCompressedTexSubImage3D not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glGetCompressedTexImageCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetCompressedTexImage <(GLenum) target> <(GLint) lod> <(GLvoid) img>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glGetCompressedTexImage not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1dCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1d <(GLenum) target> <(GLdouble) s>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1d not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1dvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1dv <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1fCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1f <(GLenum) target> <(GLfloat) s>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1f not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1fvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1fv <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1iCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1i <(GLenum) target> <(GLint) s>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1i not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1ivCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1iv <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1sCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1s <(GLenum) target> <(GLshort) s>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1s not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1svCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1sv <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2dCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2d <(GLenum) target> <(GLdouble) s> <(GLdouble) t>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2d not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2dvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2dv <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2fCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2f <(GLenum) target> <(GLfloat) s> <(GLfloat) t>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2f not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2fvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2fv <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2iCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2i <(GLenum) target> <(GLint) s> <(GLint) t>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2i not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2ivCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2iv <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2sCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2s <(GLenum) target> <(GLshort) s> <(GLshort) t>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2s not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2svCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2sv <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3dCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3d <(GLenum) target> <(GLdouble) s> <(GLdouble) t> <(GLdouble) r>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3d not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3dvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3dv <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3fCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3f <(GLenum) target> <(GLfloat) s> <(GLfloat) t> <(GLfloat) r>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3f not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3fvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3fv <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3iCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3i <(GLenum) target> <(GLint) s> <(GLint) t> <(GLint) r>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3i not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3ivCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3iv <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3sCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3s <(GLenum) target> <(GLshort) s> <(GLshort) t> <(GLshort) r>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3s not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3svCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3sv <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4dCmd", objc, objv);

    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4d <(GLenum) target> <(GLdouble) s> <(GLdouble) t> <(GLdouble) r> <(GLdouble) q>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4d not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4dvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4dv <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4dv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4fCmd", objc, objv);

    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4f <(GLenum) target> <(GLfloat) s> <(GLfloat) t> <(GLfloat) r> <(GLfloat) q>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4f not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4fvCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4fv <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4fv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4iCmd", objc, objv);

    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4i <(GLenum) target> <(GLint) s> <(GLint) t> <(GLint) r> <(GLint) q>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4i not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4ivCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4iv <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4iv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4sCmd", objc, objv);

    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4s <(GLenum) target> <(GLshort) s> <(GLshort) t> <(GLshort) r> <(GLshort) q>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4s not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4svCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4sv <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4sv not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLoadTransposeMatrixdCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLoadTransposeMatrixd <(GLdouble) m[16]>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glLoadTransposeMatrixd not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glLoadTransposeMatrixfCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLoadTransposeMatrixf <(GLfloat) m[16]>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glLoadTransposeMatrixf not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultTransposeMatrixdCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultTransposeMatrixd <(GLdouble) m[16]>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultTransposeMatrixd not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultTransposeMatrixfCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultTransposeMatrixf <(GLfloat) m[16]>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultTransposeMatrixf not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;
    double value;
    int invert;

    glResult = 0;
    hPtr = NULL;
    value  = 0.0;
    invert  = 0;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glSampleCoverageCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glSampleCoverage <(GLclampf) value> <(GLboolean) invert>\"",
                NULL);
        return TCL_ERROR;
    }

    Tcl_GetDoubleFromObj(interp, objv[1], &value);
    Tcl_GetBooleanFromObj(interp, objv[2], &invert);
    glSampleCoverage((float)value, (unsigned char)invert);
    result = GetGLError(interp);
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glActiveTextureARBCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glActiveTextureARB <(GLenum) texture>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glActiveTextureARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glClientActiveTextureARBCmd", objc, objv);

    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClientActiveTextureARB <(GLenum) texture>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glClientActiveTextureARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1dARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1dARB <(GLenum) target> <(GLdouble) s>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1dARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1dvARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1dvARB <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1dvARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1fARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1fARB <(GLenum) target> <(GLfloat) s>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1fARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1fvARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1fvARB <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1fvARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1iARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1iARB <(GLenum) target> <(GLint) s>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1iARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1ivARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1ivARB <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1ivARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1sARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1sARB <(GLenum) target> <(GLshort) s>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1sARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord1svARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1svARB <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord1svARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2dARBCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2dARB <(GLenum) target> <(GLdouble) s> <(GLdouble) t>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2dARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2dvARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2dvARB <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2dvARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2fARBCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2fARB <(GLenum) target> <(GLfloat) s> <(GLfloat) t>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2fARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2fvARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2fvARB <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2fvARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2iARBCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2iARB <(GLenum) target> <(GLint) s> <(GLint) t>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2iARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2ivARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2ivARB <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2ivARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2sARBCmd", objc, objv);

    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2sARB <(GLenum) target> <(GLshort) s> <(GLshort) t>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2sARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord2svARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2svARB <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord2svARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3dARBCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3dARB <(GLenum) target> <(GLdouble) s> <(GLdouble) t> <(GLdouble) r>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3dARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3dvARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3dvARB <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3dvARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3fARBCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3fARB <(GLenum) target> <(GLfloat) s> <(GLfloat) t> <(GLfloat) r>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3fARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3fvARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3fvARB <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3fvARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3iARBCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3iARB <(GLenum) target> <(GLint) s> <(GLint) t> <(GLint) r>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3iARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3ivARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3ivARB <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3ivARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3sARBCmd", objc, objv);

    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3sARB <(GLenum) target> <(GLshort) s> <(GLshort) t> <(GLshort) r>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3sARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord3svARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3svARB <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord3svARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4dARBCmd", objc, objv);

    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4dARB <(GLenum) target> <(GLdouble) s> <(GLdouble) t> <(GLdouble) r> <(GLdouble) q>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4dARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4dvARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4dvARB <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4dvARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4fARBCmd", objc, objv);

    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4fARB <(GLenum) target> <(GLfloat) s> <(GLfloat) t> <(GLfloat) r> <(GLfloat) q>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4fARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4fvARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4fvARB <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4fvARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4iARBCmd", objc, objv);

    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4iARB <(GLenum) target> <(GLint) s> <(GLint) t> <(GLint) r> <(GLint) q>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4iARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4ivARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4ivARB <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4ivARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4sARBCmd", objc, objv);

    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4sARB <(GLenum) target> <(GLshort) s> <(GLshort) t> <(GLshort) r> <(GLshort) q>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4sARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glMultiTexCoord4svARBCmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4svARB <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glMultiTexCoord4svARB not yet implemented");
    result = TCL_OK;
    return result;
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
    int result;
    int glResult;

    glResult = 0;
    hPtr = NULL;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(0, "TclGL_glBlendEquationSeparateATICmd", objc, objv);

    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glBlendEquationSeparateATI <(GLenum) modeRGB> <(GLenum) modeA>\"",
                NULL);
        return TCL_ERROR;
    }

fprintf(stderr, "glBlendEquationSeparateATI not yet implemented");
    result = TCL_OK;
    return result;
}
