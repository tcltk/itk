
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClearIndexCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClearIndex <(GLfloat) c>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &c);
    glClearIndex((GLfloat )c);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClearColorCmd", objc, objv);
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
    glClearColor((GLclampf )red, (GLclampf )green, (GLclampf )blue, (GLclampf )alpha);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClearCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClear <(GLbitfield) mask>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mask = (GLenum)Tcl_GetHashValue(hPtr); 
    glClear((GLbitfield)mask);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexMaskCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexMask <(GLuint) mask>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &mask);
    glIndexMask((GLuint )mask);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColorMaskCmd", objc, objv);
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
    glColorMask((GLboolean )red, (GLboolean )green, (GLboolean )blue, (GLboolean )alpha);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glAlphaFuncCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glAlphaFunc <(GLenum) func> <(GLclampf) ref>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    func = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &ref);
    glAlphaFunc((GLenum)func, (GLclampf )ref);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glBlendFuncCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glBlendFunc <(GLenum) sfactor> <(GLenum) dfactor>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    sfactor = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    dfactor = (GLenum)Tcl_GetHashValue(hPtr); 
    glBlendFunc((GLenum)sfactor, (GLenum)dfactor);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLogicOpCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLogicOp <(GLenum) opcode>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    opcode = (GLenum)Tcl_GetHashValue(hPtr); 
    glLogicOp((GLenum)opcode);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCullFaceCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCullFace <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    glCullFace((GLenum)mode);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFrontFaceCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFrontFace <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    glFrontFace((GLenum)mode);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPointSizeCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPointSize <(GLfloat) size>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &size);
    glPointSize((GLfloat )size);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLineWidthCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLineWidth <(GLfloat) width>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &width);
    glLineWidth((GLfloat )width);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLineStippleCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLineStipple <(GLint) factor> <(GLushort) pattern>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &factor);
    Tcl_GetIntFromObj(interp, objv[2], &pattern);
    glLineStipple((GLint )factor, (GLushort )pattern);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPolygonModeCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPolygonMode <(GLenum) face> <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    face = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    glPolygonMode((GLenum)face, (GLenum)mode);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPolygonOffsetCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPolygonOffset <(GLfloat) factor> <(GLfloat) units>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &factor);
    Tcl_GetDoubleFromObj(interp, objv[2], &units);
    glPolygonOffset((GLfloat )factor, (GLfloat )units);
    return GetGLError(interp);
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
    int *mask;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPolygonStippleCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPolygonStipple <(GLubyte) mask>\"",
                NULL);
        return TCL_ERROR;
    }
    mask = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glPolygonStipple((GLubyte *)mask);
    return GetGLError(interp);
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
    int *mask;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetPolygonStippleCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetPolygonStipple <(GLubyte) mask>\"",
                NULL);
        return TCL_ERROR;
    }
    mask = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glGetPolygonStipple((GLubyte *)mask);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEdgeFlagCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEdgeFlag <(GLboolean) flag>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetBooleanFromObj(interp, objv[1], &flag);
    glEdgeFlag((GLboolean )flag);
    return GetGLError(interp);
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
    int *flag;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEdgeFlagvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEdgeFlagv <(GLboolean) flag>\"",
                NULL);
        return TCL_ERROR;
    }
    flag = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glEdgeFlagv((GLboolean *)flag);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glScissorCmd", objc, objv);
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
    glScissor((GLint )x, (GLint )y, (GLsizei )width, (GLsizei )height);
    return GetGLError(interp);
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
    double *equation;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClipPlaneCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClipPlane <(GLenum) plane> <(GLdouble) equation>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    plane = (GLenum)Tcl_GetHashValue(hPtr); 
    equation = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glClipPlane((GLenum)plane, (void *)equation);
    return GetGLError(interp);
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
    double *equation;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetClipPlaneCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetClipPlane <(GLenum) plane> <(GLdouble) equation>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    plane = (GLenum)Tcl_GetHashValue(hPtr); 
    equation = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glGetClipPlane((GLenum)plane, (void *)equation);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDrawBufferCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDrawBuffer <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    glDrawBuffer((GLenum)mode);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glReadBufferCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glReadBuffer <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    glReadBuffer((GLenum)mode);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEnableCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEnable <(GLenum) cap>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    cap = (GLenum)Tcl_GetHashValue(hPtr); 
    glEnable((GLenum)cap);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDisableCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDisable <(GLenum) cap>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    cap = (GLenum)Tcl_GetHashValue(hPtr); 
    glDisable((GLenum)cap);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIsEnabledCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIsEnabled <(GLenum) cap>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    cap = (GLenum)Tcl_GetHashValue(hPtr); 
    glIsEnabled((GLenum)cap);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEnableClientStateCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEnableClientState <(GLenum) cap>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    cap = (GLenum)Tcl_GetHashValue(hPtr); 
    glEnableClientState((GLenum)cap);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDisableClientStateCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDisableClientState <(GLenum) cap>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    cap = (GLenum)Tcl_GetHashValue(hPtr); 
    glDisableClientState((GLenum)cap);
    return GetGLError(interp);
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
    int *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetBooleanvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetBooleanv <(GLenum) pname> <(GLboolean) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glGetBooleanv((GLenum)pname, (GLboolean *)params);
    return GetGLError(interp);
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
    double *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetDoublevCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetDoublev <(GLenum) pname> <(GLdouble) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glGetDoublev((GLenum)pname, (void *)params);
    return GetGLError(interp);
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
    double *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetFloatvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetFloatv <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glGetFloatv((GLenum)pname, (void *)params);
    return GetGLError(interp);
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
    int *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetIntegervCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetIntegerv <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glGetIntegerv((GLenum)pname, (GLint *)params);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPushAttribCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPushAttrib <(GLbitfield) mask>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mask = (GLenum)Tcl_GetHashValue(hPtr); 
    glPushAttrib((GLbitfield)mask);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPopAttribCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPopAttrib \"",
                NULL);
        return TCL_ERROR;
    }

    glPopAttrib();
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPushClientAttribCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPushClientAttrib <(GLbitfield) mask>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mask = (GLenum)Tcl_GetHashValue(hPtr); 
    glPushClientAttrib((GLbitfield)mask);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPopClientAttribCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPopClientAttrib \"",
                NULL);
        return TCL_ERROR;
    }

    glPopClientAttrib();
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRenderModeCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRenderMode <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    glRenderMode((GLenum)mode);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetErrorCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetError \"",
                NULL);
        return TCL_ERROR;
    }

    glGetError();
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFinishCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFinish \"",
                NULL);
        return TCL_ERROR;
    }

    glFinish();
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFlushCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFlush \"",
                NULL);
        return TCL_ERROR;
    }

    glFlush();
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glHintCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glHint <(GLenum) target> <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    glHint((GLenum)target, (GLenum)mode);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClearDepthCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClearDepth <(GLclampd) depth>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &depth);
    glClearDepth((GLclampd )depth);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDepthFuncCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDepthFunc <(GLenum) func>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    func = (GLenum)Tcl_GetHashValue(hPtr); 
    glDepthFunc((GLenum)func);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDepthMaskCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDepthMask <(GLboolean) flag>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetBooleanFromObj(interp, objv[1], &flag);
    glDepthMask((GLboolean )flag);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDepthRangeCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDepthRange <(GLclampd) near_val> <(GLclampd) far_val>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &near_val);
    Tcl_GetDoubleFromObj(interp, objv[2], &far_val);
    glDepthRange((GLclampd )near_val, (GLclampd )far_val);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClearAccumCmd", objc, objv);
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
    glClearAccum((GLfloat )red, (GLfloat )green, (GLfloat )blue, (GLfloat )alpha);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glAccumCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glAccum <(GLenum) op> <(GLfloat) value>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    op = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &value);
    glAccum((GLenum)op, (GLfloat )value);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMatrixModeCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMatrixMode <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    glMatrixMode((GLenum)mode);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPushMatrixCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPushMatrix \"",
                NULL);
        return TCL_ERROR;
    }

    glPushMatrix();
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPopMatrixCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPopMatrix \"",
                NULL);
        return TCL_ERROR;
    }

    glPopMatrix();
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLoadIdentityCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLoadIdentity \"",
                NULL);
        return TCL_ERROR;
    }

    glLoadIdentity();
    return GetGLError(interp);
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
    double *m;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLoadMatrixdCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLoadMatrixd <(GLdouble) m>\"",
                NULL);
        return TCL_ERROR;
    }
    m = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glLoadMatrixd((void *)m);
    return GetGLError(interp);
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
    double *m;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLoadMatrixfCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLoadMatrixf <(GLfloat) m>\"",
                NULL);
        return TCL_ERROR;
    }
    m = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glLoadMatrixf((void *)m);
    return GetGLError(interp);
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
    double *m;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultMatrixdCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultMatrixd <(GLdouble) m>\"",
                NULL);
        return TCL_ERROR;
    }
    m = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glMultMatrixd((void *)m);
    return GetGLError(interp);
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
    double *m;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultMatrixfCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultMatrixf <(GLfloat) m>\"",
                NULL);
        return TCL_ERROR;
    }
    m = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glMultMatrixf((void *)m);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glScaledCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glScaled <(GLdouble) x> <(GLdouble) y> <(GLdouble) z>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glScaled((GLdouble )x, (GLdouble )y, (GLdouble )z);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glScalefCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glScalef <(GLfloat) x> <(GLfloat) y> <(GLfloat) z>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glScalef((GLfloat )x, (GLfloat )y, (GLfloat )z);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTranslatedCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTranslated <(GLdouble) x> <(GLdouble) y> <(GLdouble) z>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glTranslated((GLdouble )x, (GLdouble )y, (GLdouble )z);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTranslatefCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTranslatef <(GLfloat) x> <(GLfloat) y> <(GLfloat) z>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glTranslatef((GLfloat )x, (GLfloat )y, (GLfloat )z);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIsListCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIsList <(GLuint) list>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &list);
    glIsList((GLuint )list);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDeleteListsCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDeleteLists <(GLuint) list> <(GLsizei) range>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &list);
    Tcl_GetIntFromObj(interp, objv[2], &range);
    glDeleteLists((GLuint )list, (GLsizei )range);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGenListsCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGenLists <(GLsizei) range>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &range);
    glGenLists((GLsizei )range);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNewListCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNewList <(GLuint) list> <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &list);
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    glNewList((GLuint )list, (GLenum)mode);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEndListCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEndList \"",
                NULL);
        return TCL_ERROR;
    }

    glEndList();
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCallListCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCallList <(GLuint) list>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &list);
    glCallList((GLuint )list);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glListBaseCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glListBase <(GLuint) base>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &base);
    glListBase((GLuint )base);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glBeginCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glBegin <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    glBegin((GLenum)mode);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEndCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEnd \"",
                NULL);
        return TCL_ERROR;
    }

    glEnd();
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2dCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2d <(GLdouble) x> <(GLdouble) y>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    glVertex2d((GLdouble )x, (GLdouble )y);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2fCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2f <(GLfloat) x> <(GLfloat) y>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    glVertex2f((GLfloat )x, (GLfloat )y);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2iCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2i <(GLint) x> <(GLint) y>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    glVertex2i((GLint )x, (GLint )y);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2sCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2s <(GLshort) x> <(GLshort) y>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    glVertex2s((GLshort )x, (GLshort )y);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3dCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3d <(GLdouble) x> <(GLdouble) y> <(GLdouble) z>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glVertex3d((GLdouble )x, (GLdouble )y, (GLdouble )z);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3fCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3f <(GLfloat) x> <(GLfloat) y> <(GLfloat) z>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glVertex3f((GLfloat )x, (GLfloat )y, (GLfloat )z);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3iCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3i <(GLint) x> <(GLint) y> <(GLint) z>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    Tcl_GetIntFromObj(interp, objv[3], &z);
    glVertex3i((GLint )x, (GLint )y, (GLint )z);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3sCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3s <(GLshort) x> <(GLshort) y> <(GLshort) z>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    Tcl_GetIntFromObj(interp, objv[3], &z);
    glVertex3s((GLshort )x, (GLshort )y, (GLshort )z);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4dCmd", objc, objv);
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
    glVertex4d((GLdouble )x, (GLdouble )y, (GLdouble )z, (GLdouble )w);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4fCmd", objc, objv);
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
    glVertex4f((GLfloat )x, (GLfloat )y, (GLfloat )z, (GLfloat )w);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4iCmd", objc, objv);
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
    glVertex4i((GLint )x, (GLint )y, (GLint )z, (GLint )w);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4sCmd", objc, objv);
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
    glVertex4s((GLshort )x, (GLshort )y, (GLshort )z, (GLshort )w);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glVertex2dv((void *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glVertex2fv((void *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2ivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glVertex2iv((GLint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex2svCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex2sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glVertex2sv((GLshort *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glVertex3dv((void *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glVertex3fv((void *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3ivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glVertex3iv((GLint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex3svCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex3sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glVertex3sv((GLshort *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex4dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glVertex4dv((void *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex4fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glVertex4fv((void *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4ivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex4iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glVertex4iv((GLint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glVertex4svCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glVertex4sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glVertex4sv((GLshort *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3bCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3b <(GLbyte) nx> <(GLbyte) ny> <(GLbyte) nz>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &nx);
    Tcl_GetIntFromObj(interp, objv[2], &ny);
    Tcl_GetIntFromObj(interp, objv[3], &nz);
    glNormal3b((GLbyte )nx, (GLbyte )ny, (GLbyte )nz);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3dCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3d <(GLdouble) nx> <(GLdouble) ny> <(GLdouble) nz>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &nx);
    Tcl_GetDoubleFromObj(interp, objv[2], &ny);
    Tcl_GetDoubleFromObj(interp, objv[3], &nz);
    glNormal3d((GLdouble )nx, (GLdouble )ny, (GLdouble )nz);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3fCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3f <(GLfloat) nx> <(GLfloat) ny> <(GLfloat) nz>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &nx);
    Tcl_GetDoubleFromObj(interp, objv[2], &ny);
    Tcl_GetDoubleFromObj(interp, objv[3], &nz);
    glNormal3f((GLfloat )nx, (GLfloat )ny, (GLfloat )nz);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3iCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3i <(GLint) nx> <(GLint) ny> <(GLint) nz>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &nx);
    Tcl_GetIntFromObj(interp, objv[2], &ny);
    Tcl_GetIntFromObj(interp, objv[3], &nz);
    glNormal3i((GLint )nx, (GLint )ny, (GLint )nz);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3sCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3s <(GLshort) nx> <(GLshort) ny> <(GLshort) nz>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &nx);
    Tcl_GetIntFromObj(interp, objv[2], &ny);
    Tcl_GetIntFromObj(interp, objv[3], &nz);
    glNormal3s((GLshort )nx, (GLshort )ny, (GLshort )nz);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3bvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3bv <(GLbyte) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glNormal3bv((GLbyte *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glNormal3dv((void *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glNormal3fv((void *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3ivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glNormal3iv((GLint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glNormal3svCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glNormal3sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glNormal3sv((GLshort *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexdCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexd <(GLdouble) c>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &c);
    glIndexd((GLdouble )c);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexfCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexf <(GLfloat) c>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &c);
    glIndexf((GLfloat )c);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexiCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexi <(GLint) c>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &c);
    glIndexi((GLint )c);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexsCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexs <(GLshort) c>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &c);
    glIndexs((GLshort )c);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexubCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexub <(GLubyte) c>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &c);
    glIndexub((GLubyte )c);
    return GetGLError(interp);
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
    double *c;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexdvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexdv <(GLdouble) c>\"",
                NULL);
        return TCL_ERROR;
    }
    c = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glIndexdv((void *)c);
    return GetGLError(interp);
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
    double *c;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexfvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexfv <(GLfloat) c>\"",
                NULL);
        return TCL_ERROR;
    }
    c = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glIndexfv((void *)c);
    return GetGLError(interp);
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
    int *c;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexiv <(GLint) c>\"",
                NULL);
        return TCL_ERROR;
    }
    c = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glIndexiv((GLint *)c);
    return GetGLError(interp);
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
    int *c;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexsvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexsv <(GLshort) c>\"",
                NULL);
        return TCL_ERROR;
    }
    c = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glIndexsv((GLshort *)c);
    return GetGLError(interp);
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
    int *c;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIndexubvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIndexubv <(GLubyte) c>\"",
                NULL);
        return TCL_ERROR;
    }
    c = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glIndexubv((GLubyte *)c);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3bCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3b <(GLbyte) red> <(GLbyte) green> <(GLbyte) blue>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &red);
    Tcl_GetIntFromObj(interp, objv[2], &green);
    Tcl_GetIntFromObj(interp, objv[3], &blue);
    glColor3b((GLbyte )red, (GLbyte )green, (GLbyte )blue);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3dCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3d <(GLdouble) red> <(GLdouble) green> <(GLdouble) blue>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &red);
    Tcl_GetDoubleFromObj(interp, objv[2], &green);
    Tcl_GetDoubleFromObj(interp, objv[3], &blue);
    glColor3d((GLdouble )red, (GLdouble )green, (GLdouble )blue);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3fCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3f <(GLfloat) red> <(GLfloat) green> <(GLfloat) blue>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &red);
    Tcl_GetDoubleFromObj(interp, objv[2], &green);
    Tcl_GetDoubleFromObj(interp, objv[3], &blue);
    glColor3f((GLfloat )red, (GLfloat )green, (GLfloat )blue);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3iCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3i <(GLint) red> <(GLint) green> <(GLint) blue>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &red);
    Tcl_GetIntFromObj(interp, objv[2], &green);
    Tcl_GetIntFromObj(interp, objv[3], &blue);
    glColor3i((GLint )red, (GLint )green, (GLint )blue);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3sCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3s <(GLshort) red> <(GLshort) green> <(GLshort) blue>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &red);
    Tcl_GetIntFromObj(interp, objv[2], &green);
    Tcl_GetIntFromObj(interp, objv[3], &blue);
    glColor3s((GLshort )red, (GLshort )green, (GLshort )blue);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3ubCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3ub <(GLubyte) red> <(GLubyte) green> <(GLubyte) blue>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &red);
    Tcl_GetIntFromObj(interp, objv[2], &green);
    Tcl_GetIntFromObj(interp, objv[3], &blue);
    glColor3ub((GLubyte )red, (GLubyte )green, (GLubyte )blue);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3uiCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3ui <(GLuint) red> <(GLuint) green> <(GLuint) blue>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &red);
    Tcl_GetIntFromObj(interp, objv[2], &green);
    Tcl_GetIntFromObj(interp, objv[3], &blue);
    glColor3ui((GLuint )red, (GLuint )green, (GLuint )blue);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3usCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3us <(GLushort) red> <(GLushort) green> <(GLushort) blue>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &red);
    Tcl_GetIntFromObj(interp, objv[2], &green);
    Tcl_GetIntFromObj(interp, objv[3], &blue);
    glColor3us((GLushort )red, (GLushort )green, (GLushort )blue);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3bvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3bv <(GLbyte) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor3bv((GLbyte *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor3dv((void *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor3fv((void *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3ivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor3iv((GLint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3svCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor3sv((GLshort *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3ubvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3ubv <(GLubyte) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor3ubv((GLubyte *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3uivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3uiv <(GLuint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor3uiv((GLuint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor3usvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor3usv <(GLushort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor3usv((GLushort *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4bvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4bv <(GLbyte) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor4bv((GLbyte *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor4dv((void *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor4fv((void *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4ivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor4iv((GLint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4svCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor4sv((GLshort *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4ubvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4ubv <(GLubyte) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor4ubv((GLubyte *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4uivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4uiv <(GLuint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor4uiv((GLuint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColor4usvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColor4usv <(GLushort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glColor4usv((GLushort *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1dCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1d <(GLdouble) s>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &s);
    glTexCoord1d((GLdouble )s);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1fCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1f <(GLfloat) s>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &s);
    glTexCoord1f((GLfloat )s);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1iCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1i <(GLint) s>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &s);
    glTexCoord1i((GLint )s);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1sCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1s <(GLshort) s>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &s);
    glTexCoord1s((GLshort )s);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2dCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2d <(GLdouble) s> <(GLdouble) t>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &s);
    Tcl_GetDoubleFromObj(interp, objv[2], &t);
    glTexCoord2d((GLdouble )s, (GLdouble )t);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2fCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2f <(GLfloat) s> <(GLfloat) t>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &s);
    Tcl_GetDoubleFromObj(interp, objv[2], &t);
    glTexCoord2f((GLfloat )s, (GLfloat )t);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2iCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2i <(GLint) s> <(GLint) t>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &s);
    Tcl_GetIntFromObj(interp, objv[2], &t);
    glTexCoord2i((GLint )s, (GLint )t);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2sCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2s <(GLshort) s> <(GLshort) t>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &s);
    Tcl_GetIntFromObj(interp, objv[2], &t);
    glTexCoord2s((GLshort )s, (GLshort )t);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3dCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3d <(GLdouble) s> <(GLdouble) t> <(GLdouble) r>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &s);
    Tcl_GetDoubleFromObj(interp, objv[2], &t);
    Tcl_GetDoubleFromObj(interp, objv[3], &r);
    glTexCoord3d((GLdouble )s, (GLdouble )t, (GLdouble )r);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3fCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3f <(GLfloat) s> <(GLfloat) t> <(GLfloat) r>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &s);
    Tcl_GetDoubleFromObj(interp, objv[2], &t);
    Tcl_GetDoubleFromObj(interp, objv[3], &r);
    glTexCoord3f((GLfloat )s, (GLfloat )t, (GLfloat )r);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3iCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3i <(GLint) s> <(GLint) t> <(GLint) r>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &s);
    Tcl_GetIntFromObj(interp, objv[2], &t);
    Tcl_GetIntFromObj(interp, objv[3], &r);
    glTexCoord3i((GLint )s, (GLint )t, (GLint )r);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3sCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3s <(GLshort) s> <(GLshort) t> <(GLshort) r>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &s);
    Tcl_GetIntFromObj(interp, objv[2], &t);
    Tcl_GetIntFromObj(interp, objv[3], &r);
    glTexCoord3s((GLshort )s, (GLshort )t, (GLshort )r);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4dCmd", objc, objv);
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
    glTexCoord4d((GLdouble )s, (GLdouble )t, (GLdouble )r, (GLdouble )q);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4fCmd", objc, objv);
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
    glTexCoord4f((GLfloat )s, (GLfloat )t, (GLfloat )r, (GLfloat )q);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4iCmd", objc, objv);
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
    glTexCoord4i((GLint )s, (GLint )t, (GLint )r, (GLint )q);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4sCmd", objc, objv);
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
    glTexCoord4s((GLshort )s, (GLshort )t, (GLshort )r, (GLshort )q);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord1dv((void *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord1fv((void *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1ivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord1iv((GLint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord1svCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord1sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord1sv((GLshort *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord2dv((void *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord2fv((void *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2ivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord2iv((GLint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord2svCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord2sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord2sv((GLshort *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord3dv((void *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord3fv((void *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3ivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord3iv((GLint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord3svCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord3sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord3sv((GLshort *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord4dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord4dv((void *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord4fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord4fv((void *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4ivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord4iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord4iv((GLint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexCoord4svCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexCoord4sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glTexCoord4sv((GLshort *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2dCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2d <(GLdouble) x> <(GLdouble) y>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    glRasterPos2d((GLdouble )x, (GLdouble )y);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2fCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2f <(GLfloat) x> <(GLfloat) y>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    glRasterPos2f((GLfloat )x, (GLfloat )y);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2iCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2i <(GLint) x> <(GLint) y>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    glRasterPos2i((GLint )x, (GLint )y);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2sCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2s <(GLshort) x> <(GLshort) y>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    glRasterPos2s((GLshort )x, (GLshort )y);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3dCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3d <(GLdouble) x> <(GLdouble) y> <(GLdouble) z>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glRasterPos3d((GLdouble )x, (GLdouble )y, (GLdouble )z);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3fCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3f <(GLfloat) x> <(GLfloat) y> <(GLfloat) z>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &x);
    Tcl_GetDoubleFromObj(interp, objv[2], &y);
    Tcl_GetDoubleFromObj(interp, objv[3], &z);
    glRasterPos3f((GLfloat )x, (GLfloat )y, (GLfloat )z);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3iCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3i <(GLint) x> <(GLint) y> <(GLint) z>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    Tcl_GetIntFromObj(interp, objv[3], &z);
    glRasterPos3i((GLint )x, (GLint )y, (GLint )z);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3sCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3s <(GLshort) x> <(GLshort) y> <(GLshort) z>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &x);
    Tcl_GetIntFromObj(interp, objv[2], &y);
    Tcl_GetIntFromObj(interp, objv[3], &z);
    glRasterPos3s((GLshort )x, (GLshort )y, (GLshort )z);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4dCmd", objc, objv);
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
    glRasterPos4d((GLdouble )x, (GLdouble )y, (GLdouble )z, (GLdouble )w);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4fCmd", objc, objv);
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
    glRasterPos4f((GLfloat )x, (GLfloat )y, (GLfloat )z, (GLfloat )w);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4iCmd", objc, objv);
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
    glRasterPos4i((GLint )x, (GLint )y, (GLint )z, (GLint )w);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4sCmd", objc, objv);
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
    glRasterPos4s((GLshort )x, (GLshort )y, (GLshort )z, (GLshort )w);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glRasterPos2dv((void *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glRasterPos2fv((void *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2ivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glRasterPos2iv((GLint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos2svCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos2sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glRasterPos2sv((GLshort *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glRasterPos3dv((void *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glRasterPos3fv((void *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3ivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glRasterPos3iv((GLint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos3svCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos3sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glRasterPos3sv((GLshort *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos4dv <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glRasterPos4dv((void *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos4fv <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glRasterPos4fv((void *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4ivCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos4iv <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glRasterPos4iv((GLint *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRasterPos4svCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRasterPos4sv <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    v = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glRasterPos4sv((GLshort *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectdCmd", objc, objv);
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
    glRectd((GLdouble )x1, (GLdouble )y1, (GLdouble )x2, (GLdouble )y2);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectfCmd", objc, objv);
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
    glRectf((GLfloat )x1, (GLfloat )y1, (GLfloat )x2, (GLfloat )y2);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectiCmd", objc, objv);
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
    glRecti((GLint )x1, (GLint )y1, (GLint )x2, (GLint )y2);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectsCmd", objc, objv);
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
    glRects((GLshort )x1, (GLshort )y1, (GLshort )x2, (GLshort )y2);
    return GetGLError(interp);
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
    double *v1;
    double *v2;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectdvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRectdv <(GLdouble) v1> <(GLdouble) v2>\"",
                NULL);
        return TCL_ERROR;
    }
    v1 = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    v2 = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glRectdv((void *)v1, (void *)v2);
    return GetGLError(interp);
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
    double *v1;
    double *v2;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectfvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRectfv <(GLfloat) v1> <(GLfloat) v2>\"",
                NULL);
        return TCL_ERROR;
    }
    v1 = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    v2 = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glRectfv((void *)v1, (void *)v2);
    return GetGLError(interp);
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
    int *v1;
    int *v2;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectivCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRectiv <(GLint) v1> <(GLint) v2>\"",
                NULL);
        return TCL_ERROR;
    }
    v1 = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    v2 = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glRectiv((GLint *)v1, (GLint *)v2);
    return GetGLError(interp);
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
    int *v1;
    int *v2;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glRectsvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glRectsv <(GLshort) v1> <(GLshort) v2>\"",
                NULL);
        return TCL_ERROR;
    }
    v1 = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    v2 = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glRectsv((GLshort *)v1, (GLshort *)v2);
    return GetGLError(interp);
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
    int *ptr;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEdgeFlagPointerCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEdgeFlagPointer <(GLsizei) stride> <(GLvoid) ptr>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &stride);
    ptr = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glEdgeFlagPointer((GLsizei )stride, (GLvoid *)ptr);
    return GetGLError(interp);
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
    int **params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetPointervCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetPointerv <(GLenum) pname> <(GLvoid) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glGetPointerv((GLenum)pname, (GLvoid **)params);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glArrayElementCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glArrayElement <(GLint) i>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &i);
    glArrayElement((GLint )i);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDrawArraysCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDrawArrays <(GLenum) mode> <(GLint) first> <(GLsizei) count>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &first);
    Tcl_GetIntFromObj(interp, objv[3], &count);
    glDrawArrays((GLenum)mode, (GLint )first, (GLsizei )count);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glShadeModelCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glShadeModel <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    glShadeModel((GLenum)mode);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLightfCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLightf <(GLenum) light> <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    light = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[3], &param);
    glLightf((GLenum)light, (GLenum)pname, (GLfloat )param);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLightiCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLighti <(GLenum) light> <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    light = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[3], &param);
    glLighti((GLenum)light, (GLenum)pname, (GLint )param);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLightModelfCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLightModelf <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &param);
    glLightModelf((GLenum)pname, (GLfloat )param);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLightModeliCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLightModeli <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &param);
    glLightModeli((GLenum)pname, (GLint )param);
    return GetGLError(interp);
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
    double *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLightModelfvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLightModelfv <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glLightModelfv((GLenum)pname, (void *)params);
    return GetGLError(interp);
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
    int *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLightModelivCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLightModeliv <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glLightModeliv((GLenum)pname, (GLint *)params);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMaterialfCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMaterialf <(GLenum) face> <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    face = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[3], &param);
    glMaterialf((GLenum)face, (GLenum)pname, (GLfloat )param);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMaterialiCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMateriali <(GLenum) face> <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    face = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[3], &param);
    glMateriali((GLenum)face, (GLenum)pname, (GLint )param);
    return GetGLError(interp);
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
    double *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMaterialfvCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMaterialfv <(GLenum) face> <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    face = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glMaterialfv((GLenum)face, (GLenum)pname, (void *)params);
    return GetGLError(interp);
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
    int *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMaterialivCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMaterialiv <(GLenum) face> <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    face = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glMaterialiv((GLenum)face, (GLenum)pname, (GLint *)params);
    return GetGLError(interp);
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
    double *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetMaterialfvCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetMaterialfv <(GLenum) face> <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    face = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glGetMaterialfv((GLenum)face, (GLenum)pname, (void *)params);
    return GetGLError(interp);
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
    int *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetMaterialivCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetMaterialiv <(GLenum) face> <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    face = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glGetMaterialiv((GLenum)face, (GLenum)pname, (GLint *)params);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glColorMaterialCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glColorMaterial <(GLenum) face> <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    face = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    glColorMaterial((GLenum)face, (GLenum)mode);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPixelZoomCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPixelZoom <(GLfloat) xfactor> <(GLfloat) yfactor>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &xfactor);
    Tcl_GetDoubleFromObj(interp, objv[2], &yfactor);
    glPixelZoom((GLfloat )xfactor, (GLfloat )yfactor);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPixelStorefCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPixelStoref <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &param);
    glPixelStoref((GLenum)pname, (GLfloat )param);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPixelStoreiCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPixelStorei <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &param);
    glPixelStorei((GLenum)pname, (GLint )param);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPixelTransferfCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPixelTransferf <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &param);
    glPixelTransferf((GLenum)pname, (GLfloat )param);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPixelTransferiCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPixelTransferi <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &param);
    glPixelTransferi((GLenum)pname, (GLint )param);
    return GetGLError(interp);
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
    double *values;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetPixelMapfvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetPixelMapfv <(GLenum) map> <(GLfloat) values>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    map = (GLenum)Tcl_GetHashValue(hPtr); 
    values = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glGetPixelMapfv((GLenum)map, (void *)values);
    return GetGLError(interp);
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
    int *values;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetPixelMapuivCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetPixelMapuiv <(GLenum) map> <(GLuint) values>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    map = (GLenum)Tcl_GetHashValue(hPtr); 
    values = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glGetPixelMapuiv((GLenum)map, (GLuint *)values);
    return GetGLError(interp);
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
    int *values;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetPixelMapusvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetPixelMapusv <(GLenum) map> <(GLushort) values>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    map = (GLenum)Tcl_GetHashValue(hPtr); 
    values = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glGetPixelMapusv((GLenum)map, (GLushort *)values);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glStencilFuncCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glStencilFunc <(GLenum) func> <(GLint) ref> <(GLuint) mask>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    func = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &ref);
    Tcl_GetIntFromObj(interp, objv[3], &mask);
    glStencilFunc((GLenum)func, (GLint )ref, (GLuint )mask);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glStencilMaskCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glStencilMask <(GLuint) mask>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &mask);
    glStencilMask((GLuint )mask);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glStencilOpCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glStencilOp <(GLenum) fail> <(GLenum) zfail> <(GLenum) zpass>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    fail = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    zfail = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[3]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[3]),"\"", NULL);
	return TCL_ERROR;
    }
    zpass = (GLenum)Tcl_GetHashValue(hPtr); 
    glStencilOp((GLenum)fail, (GLenum)zfail, (GLenum)zpass);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClearStencilCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClearStencil <(GLint) s>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &s);
    glClearStencil((GLint )s);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexGendCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexGend <(GLenum) coord> <(GLenum) pname> <(GLdouble) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    coord = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[3], &param);
    glTexGend((GLenum)coord, (GLenum)pname, (GLdouble )param);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexGenfCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexGenf <(GLenum) coord> <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    coord = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[3], &param);
    glTexGenf((GLenum)coord, (GLenum)pname, (GLfloat )param);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexGeniCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexGeni <(GLenum) coord> <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    coord = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[3], &param);
    glTexGeni((GLenum)coord, (GLenum)pname, (GLint )param);
    return GetGLError(interp);
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
    double *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexGendvCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexGendv <(GLenum) coord> <(GLenum) pname> <(GLdouble) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    coord = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glTexGendv((GLenum)coord, (GLenum)pname, (void *)params);
    return GetGLError(interp);
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
    double *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexGenfvCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexGenfv <(GLenum) coord> <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    coord = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glTexGenfv((GLenum)coord, (GLenum)pname, (void *)params);
    return GetGLError(interp);
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
    int *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexGenivCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexGeniv <(GLenum) coord> <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    coord = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glTexGeniv((GLenum)coord, (GLenum)pname, (GLint *)params);
    return GetGLError(interp);
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
    double *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexGendvCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetTexGendv <(GLenum) coord> <(GLenum) pname> <(GLdouble) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    coord = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glGetTexGendv((GLenum)coord, (GLenum)pname, (void *)params);
    return GetGLError(interp);
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
    double *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexGenfvCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetTexGenfv <(GLenum) coord> <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    coord = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glGetTexGenfv((GLenum)coord, (GLenum)pname, (void *)params);
    return GetGLError(interp);
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
    int *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexGenivCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetTexGeniv <(GLenum) coord> <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    coord = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glGetTexGeniv((GLenum)coord, (GLenum)pname, (GLint *)params);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexEnvfCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexEnvf <(GLenum) target> <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[3], &param);
    glTexEnvf((GLenum)target, (GLenum)pname, (GLfloat )param);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexEnviCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexEnvi <(GLenum) target> <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[3], &param);
    glTexEnvi((GLenum)target, (GLenum)pname, (GLint )param);
    return GetGLError(interp);
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
    double *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexEnvfvCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexEnvfv <(GLenum) target> <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glTexEnvfv((GLenum)target, (GLenum)pname, (void *)params);
    return GetGLError(interp);
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
    int *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexEnvivCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexEnviv <(GLenum) target> <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glTexEnviv((GLenum)target, (GLenum)pname, (GLint *)params);
    return GetGLError(interp);
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
    double *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexEnvfvCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetTexEnvfv <(GLenum) target> <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glGetTexEnvfv((GLenum)target, (GLenum)pname, (void *)params);
    return GetGLError(interp);
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
    int *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetTexEnvivCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetTexEnviv <(GLenum) target> <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glGetTexEnviv((GLenum)target, (GLenum)pname, (GLint *)params);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexParameterfCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexParameterf <(GLenum) target> <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[3], &param);
    glTexParameterf((GLenum)target, (GLenum)pname, (GLfloat )param);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glTexParameteriCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glTexParameteri <(GLenum) target> <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[3], &param);
    glTexParameteri((GLenum)target, (GLenum)pname, (GLint )param);
    return GetGLError(interp);
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
    int *textures;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGenTexturesCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGenTextures <(GLsizei) n> <(GLuint) textures>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &n);
    textures = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glGenTextures((GLsizei )n, (GLuint *)textures);
    return GetGLError(interp);
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
    int *textures;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDeleteTexturesCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDeleteTextures <(GLsizei) n> <(GLuint) textures>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &n);
    textures = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glDeleteTextures((GLsizei )n, (GLuint *)textures);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glBindTextureCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glBindTexture <(GLenum) target> <(GLuint) texture>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &texture);
    glBindTexture((GLenum)target, (GLuint )texture);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIsTextureCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIsTexture <(GLuint) texture>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &texture);
    glIsTexture((GLuint )texture);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetMapdvCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetMapdv <(GLenum) target> <(GLenum) query> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    query = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glGetMapdv((GLenum)target, (GLenum)query, (void *)v);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetMapfvCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetMapfv <(GLenum) target> <(GLenum) query> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    query = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glGetMapfv((GLenum)target, (GLenum)query, (void *)v);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetMapivCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetMapiv <(GLenum) target> <(GLenum) query> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    query = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glGetMapiv((GLenum)target, (GLenum)query, (GLint *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord1dCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord1d <(GLdouble) u>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &u);
    glEvalCoord1d((GLdouble )u);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord1fCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord1f <(GLfloat) u>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &u);
    glEvalCoord1f((GLfloat )u);
    return GetGLError(interp);
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
    double *u;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord1dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord1dv <(GLdouble) u>\"",
                NULL);
        return TCL_ERROR;
    }
    u = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glEvalCoord1dv((void *)u);
    return GetGLError(interp);
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
    double *u;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord1fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord1fv <(GLfloat) u>\"",
                NULL);
        return TCL_ERROR;
    }
    u = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glEvalCoord1fv((void *)u);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord2dCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord2d <(GLdouble) u> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &u);
    Tcl_GetDoubleFromObj(interp, objv[2], &v);
    glEvalCoord2d((GLdouble )u, (GLdouble )v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord2fCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord2f <(GLfloat) u> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &u);
    Tcl_GetDoubleFromObj(interp, objv[2], &v);
    glEvalCoord2f((GLfloat )u, (GLfloat )v);
    return GetGLError(interp);
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
    double *u;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord2dvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord2dv <(GLdouble) u>\"",
                NULL);
        return TCL_ERROR;
    }
    u = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glEvalCoord2dv((void *)u);
    return GetGLError(interp);
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
    double *u;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalCoord2fvCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalCoord2fv <(GLfloat) u>\"",
                NULL);
        return TCL_ERROR;
    }
    u = (void *)Tcl_GetByteArrayFromObj(objv[1], NULL);
    glEvalCoord2fv((void *)u);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMapGrid1dCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMapGrid1d <(GLint) un> <(GLdouble) u1> <(GLdouble) u2>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &un);
    Tcl_GetDoubleFromObj(interp, objv[2], &u1);
    Tcl_GetDoubleFromObj(interp, objv[3], &u2);
    glMapGrid1d((GLint )un, (GLdouble )u1, (GLdouble )u2);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMapGrid1fCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMapGrid1f <(GLint) un> <(GLfloat) u1> <(GLfloat) u2>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &un);
    Tcl_GetDoubleFromObj(interp, objv[2], &u1);
    Tcl_GetDoubleFromObj(interp, objv[3], &u2);
    glMapGrid1f((GLint )un, (GLfloat )u1, (GLfloat )u2);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalPoint1Cmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalPoint1 <(GLint) i>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &i);
    glEvalPoint1((GLint )i);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalPoint2Cmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalPoint2 <(GLint) i> <(GLint) j>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &i);
    Tcl_GetIntFromObj(interp, objv[2], &j);
    glEvalPoint2((GLint )i, (GLint )j);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalMesh1Cmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalMesh1 <(GLenum) mode> <(GLint) i1> <(GLint) i2>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &i1);
    Tcl_GetIntFromObj(interp, objv[3], &i2);
    glEvalMesh1((GLenum)mode, (GLint )i1, (GLint )i2);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glEvalMesh2Cmd", objc, objv);
    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glEvalMesh2 <(GLenum) mode> <(GLint) i1> <(GLint) i2> <(GLint) j1> <(GLint) j2>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &i1);
    Tcl_GetIntFromObj(interp, objv[3], &i2);
    Tcl_GetIntFromObj(interp, objv[4], &j1);
    Tcl_GetIntFromObj(interp, objv[5], &j2);
    glEvalMesh2((GLenum)mode, (GLint )i1, (GLint )i2, (GLint )j1, (GLint )j2);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFogfCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFogf <(GLenum) pname> <(GLfloat) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &param);
    glFogf((GLenum)pname, (GLfloat )param);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFogiCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFogi <(GLenum) pname> <(GLint) param>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &param);
    glFogi((GLenum)pname, (GLint )param);
    return GetGLError(interp);
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
    double *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFogfvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFogfv <(GLenum) pname> <(GLfloat) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glFogfv((GLenum)pname, (void *)params);
    return GetGLError(interp);
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
    int *params;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFogivCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFogiv <(GLenum) pname> <(GLint) params>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    pname = (GLenum)Tcl_GetHashValue(hPtr); 
    params = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glFogiv((GLenum)pname, (GLint *)params);
    return GetGLError(interp);
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
    double *buffer;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glFeedbackBufferCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glFeedbackBuffer <(GLsizei) size> <(GLenum) type> <(GLfloat) buffer>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &size);
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    type = (GLenum)Tcl_GetHashValue(hPtr); 
    buffer = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glFeedbackBuffer((GLsizei )size, (GLenum)type, (void *)buffer);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPassThroughCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPassThrough <(GLfloat) token>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &token);
    glPassThrough((GLfloat )token);
    return GetGLError(interp);
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
    int *buffer;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glSelectBufferCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glSelectBuffer <(GLsizei) size> <(GLuint) buffer>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &size);
    buffer = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glSelectBuffer((GLsizei )size, (GLuint *)buffer);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glInitNamesCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glInitNames \"",
                NULL);
        return TCL_ERROR;
    }

    glInitNames();
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLoadNameCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLoadName <(GLuint) name>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &name);
    glLoadName((GLuint )name);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPushNameCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPushName <(GLuint) name>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &name);
    glPushName((GLuint )name);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glPopNameCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glPopName \"",
                NULL);
        return TCL_ERROR;
    }

    glPopName();
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glBlendEquationCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glBlendEquation <(GLenum) mode>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    mode = (GLenum)Tcl_GetHashValue(hPtr); 
    glBlendEquation((GLenum)mode);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glResetHistogramCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glResetHistogram <(GLenum) target>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    glResetHistogram((GLenum)target);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glResetMinmaxCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glResetMinmax <(GLenum) target>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    glResetMinmax((GLenum)target);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glActiveTextureCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glActiveTexture <(GLenum) texture>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    texture = (GLenum)Tcl_GetHashValue(hPtr); 
    glActiveTexture((GLenum)texture);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClientActiveTextureCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClientActiveTexture <(GLenum) texture>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    texture = (GLenum)Tcl_GetHashValue(hPtr); 
    glClientActiveTexture((GLenum)texture);
    return GetGLError(interp);
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
    int *data;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCompressedTexImage1DCmd", objc, objv);
    if (objc != 8) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCompressedTexImage1D <(GLenum) target> <(GLint) level> <(GLenum) internalformat> <(GLsizei) width> <(GLint) border> <(GLsizei) imageSize> <(GLvoid) data>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &level);
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[3]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[3]),"\"", NULL);
	return TCL_ERROR;
    }
    internalformat = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[4], &width);
    Tcl_GetIntFromObj(interp, objv[5], &border);
    Tcl_GetIntFromObj(interp, objv[6], &imageSize);
    data = (void *)Tcl_GetByteArrayFromObj(objv[7], NULL);
    glCompressedTexImage1D((GLenum)target, (GLint )level, (GLenum)internalformat, (GLsizei )width, (GLint )border, (GLsizei )imageSize, (GLvoid *)data);
    return GetGLError(interp);
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
    int *data;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCompressedTexImage2DCmd", objc, objv);
    if (objc != 9) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCompressedTexImage2D <(GLenum) target> <(GLint) level> <(GLenum) internalformat> <(GLsizei) width> <(GLsizei) height> <(GLint) border> <(GLsizei) imageSize> <(GLvoid) data>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &level);
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[3]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[3]),"\"", NULL);
	return TCL_ERROR;
    }
    internalformat = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[4], &width);
    Tcl_GetIntFromObj(interp, objv[5], &height);
    Tcl_GetIntFromObj(interp, objv[6], &border);
    Tcl_GetIntFromObj(interp, objv[7], &imageSize);
    data = (void *)Tcl_GetByteArrayFromObj(objv[8], NULL);
    glCompressedTexImage2D((GLenum)target, (GLint )level, (GLenum)internalformat, (GLsizei )width, (GLsizei )height, (GLint )border, (GLsizei )imageSize, (GLvoid *)data);
    return GetGLError(interp);
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
    int *data;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCompressedTexImage3DCmd", objc, objv);
    if (objc != 10) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCompressedTexImage3D <(GLenum) target> <(GLint) level> <(GLenum) internalformat> <(GLsizei) width> <(GLsizei) height> <(GLsizei) depth> <(GLint) border> <(GLsizei) imageSize> <(GLvoid) data>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &level);
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[3]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[3]),"\"", NULL);
	return TCL_ERROR;
    }
    internalformat = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[4], &width);
    Tcl_GetIntFromObj(interp, objv[5], &height);
    Tcl_GetIntFromObj(interp, objv[6], &depth);
    Tcl_GetIntFromObj(interp, objv[7], &border);
    Tcl_GetIntFromObj(interp, objv[8], &imageSize);
    data = (void *)Tcl_GetByteArrayFromObj(objv[9], NULL);
    glCompressedTexImage3D((GLenum)target, (GLint )level, (GLenum)internalformat, (GLsizei )width, (GLsizei )height, (GLsizei )depth, (GLint )border, (GLsizei )imageSize, (GLvoid *)data);
    return GetGLError(interp);
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
    int *data;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCompressedTexSubImage1DCmd", objc, objv);
    if (objc != 8) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCompressedTexSubImage1D <(GLenum) target> <(GLint) level> <(GLint) xoffset> <(GLsizei) width> <(GLenum) format> <(GLsizei) imageSize> <(GLvoid) data>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &level);
    Tcl_GetIntFromObj(interp, objv[3], &xoffset);
    Tcl_GetIntFromObj(interp, objv[4], &width);
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[5]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[5]),"\"", NULL);
	return TCL_ERROR;
    }
    format = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[6], &imageSize);
    data = (void *)Tcl_GetByteArrayFromObj(objv[7], NULL);
    glCompressedTexSubImage1D((GLenum)target, (GLint )level, (GLint )xoffset, (GLsizei )width, (GLenum)format, (GLsizei )imageSize, (GLvoid *)data);
    return GetGLError(interp);
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
    int *data;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCompressedTexSubImage2DCmd", objc, objv);
    if (objc != 10) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCompressedTexSubImage2D <(GLenum) target> <(GLint) level> <(GLint) xoffset> <(GLint) yoffset> <(GLsizei) width> <(GLsizei) height> <(GLenum) format> <(GLsizei) imageSize> <(GLvoid) data>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &level);
    Tcl_GetIntFromObj(interp, objv[3], &xoffset);
    Tcl_GetIntFromObj(interp, objv[4], &yoffset);
    Tcl_GetIntFromObj(interp, objv[5], &width);
    Tcl_GetIntFromObj(interp, objv[6], &height);
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[7]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[7]),"\"", NULL);
	return TCL_ERROR;
    }
    format = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[8], &imageSize);
    data = (void *)Tcl_GetByteArrayFromObj(objv[9], NULL);
    glCompressedTexSubImage2D((GLenum)target, (GLint )level, (GLint )xoffset, (GLint )yoffset, (GLsizei )width, (GLsizei )height, (GLenum)format, (GLsizei )imageSize, (GLvoid *)data);
    return GetGLError(interp);
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
    int *data;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glCompressedTexSubImage3DCmd", objc, objv);
    if (objc != 12) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glCompressedTexSubImage3D <(GLenum) target> <(GLint) level> <(GLint) xoffset> <(GLint) yoffset> <(GLint) zoffset> <(GLsizei) width> <(GLsizei) height> <(GLsizei) depth> <(GLenum) format> <(GLsizei) imageSize> <(GLvoid) data>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &level);
    Tcl_GetIntFromObj(interp, objv[3], &xoffset);
    Tcl_GetIntFromObj(interp, objv[4], &yoffset);
    Tcl_GetIntFromObj(interp, objv[5], &zoffset);
    Tcl_GetIntFromObj(interp, objv[6], &width);
    Tcl_GetIntFromObj(interp, objv[7], &height);
    Tcl_GetIntFromObj(interp, objv[8], &depth);
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[9]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[9]),"\"", NULL);
	return TCL_ERROR;
    }
    format = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[10], &imageSize);
    data = (void *)Tcl_GetByteArrayFromObj(objv[11], NULL);
    glCompressedTexSubImage3D((GLenum)target, (GLint )level, (GLint )xoffset, (GLint )yoffset, (GLint )zoffset, (GLsizei )width, (GLsizei )height, (GLsizei )depth, (GLenum)format, (GLsizei )imageSize, (GLvoid *)data);
    return GetGLError(interp);
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
    int *img;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetCompressedTexImageCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetCompressedTexImage <(GLenum) target> <(GLint) lod> <(GLvoid) img>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &lod);
    img = (void *)Tcl_GetByteArrayFromObj(objv[3], NULL);
    glGetCompressedTexImage((GLenum)target, (GLint )lod, (GLvoid *)img);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1dCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1d <(GLenum) target> <(GLdouble) s>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    glMultiTexCoord1d((GLenum)target, (GLdouble )s);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1dvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1dv <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord1dv((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1fCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1f <(GLenum) target> <(GLfloat) s>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    glMultiTexCoord1f((GLenum)target, (GLfloat )s);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1fvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1fv <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord1fv((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1iCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1i <(GLenum) target> <(GLint) s>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    glMultiTexCoord1i((GLenum)target, (GLint )s);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1ivCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1iv <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord1iv((GLenum)target, (GLint *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1sCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1s <(GLenum) target> <(GLshort) s>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    glMultiTexCoord1s((GLenum)target, (GLshort )s);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1svCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1sv <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord1sv((GLenum)target, (GLshort *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2dCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2d <(GLenum) target> <(GLdouble) s> <(GLdouble) t>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    Tcl_GetDoubleFromObj(interp, objv[3], &t);
    glMultiTexCoord2d((GLenum)target, (GLdouble )s, (GLdouble )t);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2dvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2dv <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord2dv((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2fCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2f <(GLenum) target> <(GLfloat) s> <(GLfloat) t>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    Tcl_GetDoubleFromObj(interp, objv[3], &t);
    glMultiTexCoord2f((GLenum)target, (GLfloat )s, (GLfloat )t);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2fvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2fv <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord2fv((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2iCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2i <(GLenum) target> <(GLint) s> <(GLint) t>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    Tcl_GetIntFromObj(interp, objv[3], &t);
    glMultiTexCoord2i((GLenum)target, (GLint )s, (GLint )t);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2ivCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2iv <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord2iv((GLenum)target, (GLint *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2sCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2s <(GLenum) target> <(GLshort) s> <(GLshort) t>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    Tcl_GetIntFromObj(interp, objv[3], &t);
    glMultiTexCoord2s((GLenum)target, (GLshort )s, (GLshort )t);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2svCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2sv <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord2sv((GLenum)target, (GLshort *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3dCmd", objc, objv);
    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3d <(GLenum) target> <(GLdouble) s> <(GLdouble) t> <(GLdouble) r>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    Tcl_GetDoubleFromObj(interp, objv[3], &t);
    Tcl_GetDoubleFromObj(interp, objv[4], &r);
    glMultiTexCoord3d((GLenum)target, (GLdouble )s, (GLdouble )t, (GLdouble )r);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3dvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3dv <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord3dv((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3fCmd", objc, objv);
    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3f <(GLenum) target> <(GLfloat) s> <(GLfloat) t> <(GLfloat) r>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    Tcl_GetDoubleFromObj(interp, objv[3], &t);
    Tcl_GetDoubleFromObj(interp, objv[4], &r);
    glMultiTexCoord3f((GLenum)target, (GLfloat )s, (GLfloat )t, (GLfloat )r);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3fvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3fv <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord3fv((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3iCmd", objc, objv);
    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3i <(GLenum) target> <(GLint) s> <(GLint) t> <(GLint) r>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    Tcl_GetIntFromObj(interp, objv[3], &t);
    Tcl_GetIntFromObj(interp, objv[4], &r);
    glMultiTexCoord3i((GLenum)target, (GLint )s, (GLint )t, (GLint )r);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3ivCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3iv <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord3iv((GLenum)target, (GLint *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3sCmd", objc, objv);
    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3s <(GLenum) target> <(GLshort) s> <(GLshort) t> <(GLshort) r>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    Tcl_GetIntFromObj(interp, objv[3], &t);
    Tcl_GetIntFromObj(interp, objv[4], &r);
    glMultiTexCoord3s((GLenum)target, (GLshort )s, (GLshort )t, (GLshort )r);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3svCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3sv <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord3sv((GLenum)target, (GLshort *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4dCmd", objc, objv);
    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4d <(GLenum) target> <(GLdouble) s> <(GLdouble) t> <(GLdouble) r> <(GLdouble) q>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    Tcl_GetDoubleFromObj(interp, objv[3], &t);
    Tcl_GetDoubleFromObj(interp, objv[4], &r);
    Tcl_GetDoubleFromObj(interp, objv[5], &q);
    glMultiTexCoord4d((GLenum)target, (GLdouble )s, (GLdouble )t, (GLdouble )r, (GLdouble )q);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4dvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4dv <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord4dv((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4fCmd", objc, objv);
    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4f <(GLenum) target> <(GLfloat) s> <(GLfloat) t> <(GLfloat) r> <(GLfloat) q>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    Tcl_GetDoubleFromObj(interp, objv[3], &t);
    Tcl_GetDoubleFromObj(interp, objv[4], &r);
    Tcl_GetDoubleFromObj(interp, objv[5], &q);
    glMultiTexCoord4f((GLenum)target, (GLfloat )s, (GLfloat )t, (GLfloat )r, (GLfloat )q);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4fvCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4fv <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord4fv((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4iCmd", objc, objv);
    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4i <(GLenum) target> <(GLint) s> <(GLint) t> <(GLint) r> <(GLint) q>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    Tcl_GetIntFromObj(interp, objv[3], &t);
    Tcl_GetIntFromObj(interp, objv[4], &r);
    Tcl_GetIntFromObj(interp, objv[5], &q);
    glMultiTexCoord4i((GLenum)target, (GLint )s, (GLint )t, (GLint )r, (GLint )q);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4ivCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4iv <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord4iv((GLenum)target, (GLint *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4sCmd", objc, objv);
    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4s <(GLenum) target> <(GLshort) s> <(GLshort) t> <(GLshort) r> <(GLshort) q>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    Tcl_GetIntFromObj(interp, objv[3], &t);
    Tcl_GetIntFromObj(interp, objv[4], &r);
    Tcl_GetIntFromObj(interp, objv[5], &q);
    glMultiTexCoord4s((GLenum)target, (GLshort )s, (GLshort )t, (GLshort )r, (GLshort )q);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4svCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4sv <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord4sv((GLenum)target, (GLshort *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLoadTransposeMatrixdCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLoadTransposeMatrixd <(GLdouble) m[16]>\"",
                NULL);
        return TCL_ERROR;
    }
fprintf(stderr, "glLoadTransposeMatrixd not yet implemented");
    return TCL_OK;
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glLoadTransposeMatrixfCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glLoadTransposeMatrixf <(GLfloat) m[16]>\"",
                NULL);
        return TCL_ERROR;
    }
fprintf(stderr, "glLoadTransposeMatrixf not yet implemented");
    return TCL_OK;
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultTransposeMatrixdCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultTransposeMatrixd <(GLdouble) m[16]>\"",
                NULL);
        return TCL_ERROR;
    }
fprintf(stderr, "glMultTransposeMatrixd not yet implemented");
    return TCL_OK;
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultTransposeMatrixfCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultTransposeMatrixf <(GLfloat) m[16]>\"",
                NULL);
        return TCL_ERROR;
    }
fprintf(stderr, "glMultTransposeMatrixf not yet implemented");
    return TCL_OK;
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glSampleCoverageCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glSampleCoverage <(GLclampf) value> <(GLboolean) invert>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetDoubleFromObj(interp, objv[1], &value);
    Tcl_GetBooleanFromObj(interp, objv[2], &invert);
    glSampleCoverage((GLclampf )value, (GLboolean )invert);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glActiveTextureARBCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glActiveTextureARB <(GLenum) texture>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    texture = (GLenum)Tcl_GetHashValue(hPtr); 
    glActiveTextureARB((GLenum)texture);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glClientActiveTextureARBCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glClientActiveTextureARB <(GLenum) texture>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    texture = (GLenum)Tcl_GetHashValue(hPtr); 
    glClientActiveTextureARB((GLenum)texture);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1dARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1dARB <(GLenum) target> <(GLdouble) s>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    glMultiTexCoord1dARB((GLenum)target, (GLdouble )s);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1dvARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1dvARB <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord1dvARB((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1fARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1fARB <(GLenum) target> <(GLfloat) s>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    glMultiTexCoord1fARB((GLenum)target, (GLfloat )s);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1fvARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1fvARB <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord1fvARB((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1iARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1iARB <(GLenum) target> <(GLint) s>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    glMultiTexCoord1iARB((GLenum)target, (GLint )s);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1ivARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1ivARB <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord1ivARB((GLenum)target, (GLint *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1sARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1sARB <(GLenum) target> <(GLshort) s>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    glMultiTexCoord1sARB((GLenum)target, (GLshort )s);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord1svARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord1svARB <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord1svARB((GLenum)target, (GLshort *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2dARBCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2dARB <(GLenum) target> <(GLdouble) s> <(GLdouble) t>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    Tcl_GetDoubleFromObj(interp, objv[3], &t);
    glMultiTexCoord2dARB((GLenum)target, (GLdouble )s, (GLdouble )t);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2dvARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2dvARB <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord2dvARB((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2fARBCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2fARB <(GLenum) target> <(GLfloat) s> <(GLfloat) t>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    Tcl_GetDoubleFromObj(interp, objv[3], &t);
    glMultiTexCoord2fARB((GLenum)target, (GLfloat )s, (GLfloat )t);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2fvARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2fvARB <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord2fvARB((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2iARBCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2iARB <(GLenum) target> <(GLint) s> <(GLint) t>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    Tcl_GetIntFromObj(interp, objv[3], &t);
    glMultiTexCoord2iARB((GLenum)target, (GLint )s, (GLint )t);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2ivARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2ivARB <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord2ivARB((GLenum)target, (GLint *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2sARBCmd", objc, objv);
    if (objc != 4) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2sARB <(GLenum) target> <(GLshort) s> <(GLshort) t>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    Tcl_GetIntFromObj(interp, objv[3], &t);
    glMultiTexCoord2sARB((GLenum)target, (GLshort )s, (GLshort )t);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord2svARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord2svARB <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord2svARB((GLenum)target, (GLshort *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3dARBCmd", objc, objv);
    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3dARB <(GLenum) target> <(GLdouble) s> <(GLdouble) t> <(GLdouble) r>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    Tcl_GetDoubleFromObj(interp, objv[3], &t);
    Tcl_GetDoubleFromObj(interp, objv[4], &r);
    glMultiTexCoord3dARB((GLenum)target, (GLdouble )s, (GLdouble )t, (GLdouble )r);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3dvARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3dvARB <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord3dvARB((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3fARBCmd", objc, objv);
    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3fARB <(GLenum) target> <(GLfloat) s> <(GLfloat) t> <(GLfloat) r>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    Tcl_GetDoubleFromObj(interp, objv[3], &t);
    Tcl_GetDoubleFromObj(interp, objv[4], &r);
    glMultiTexCoord3fARB((GLenum)target, (GLfloat )s, (GLfloat )t, (GLfloat )r);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3fvARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3fvARB <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord3fvARB((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3iARBCmd", objc, objv);
    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3iARB <(GLenum) target> <(GLint) s> <(GLint) t> <(GLint) r>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    Tcl_GetIntFromObj(interp, objv[3], &t);
    Tcl_GetIntFromObj(interp, objv[4], &r);
    glMultiTexCoord3iARB((GLenum)target, (GLint )s, (GLint )t, (GLint )r);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3ivARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3ivARB <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord3ivARB((GLenum)target, (GLint *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3sARBCmd", objc, objv);
    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3sARB <(GLenum) target> <(GLshort) s> <(GLshort) t> <(GLshort) r>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    Tcl_GetIntFromObj(interp, objv[3], &t);
    Tcl_GetIntFromObj(interp, objv[4], &r);
    glMultiTexCoord3sARB((GLenum)target, (GLshort )s, (GLshort )t, (GLshort )r);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord3svARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord3svARB <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord3svARB((GLenum)target, (GLshort *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4dARBCmd", objc, objv);
    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4dARB <(GLenum) target> <(GLdouble) s> <(GLdouble) t> <(GLdouble) r> <(GLdouble) q>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    Tcl_GetDoubleFromObj(interp, objv[3], &t);
    Tcl_GetDoubleFromObj(interp, objv[4], &r);
    Tcl_GetDoubleFromObj(interp, objv[5], &q);
    glMultiTexCoord4dARB((GLenum)target, (GLdouble )s, (GLdouble )t, (GLdouble )r, (GLdouble )q);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4dvARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4dvARB <(GLenum) target> <(GLdouble) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord4dvARB((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4fARBCmd", objc, objv);
    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4fARB <(GLenum) target> <(GLfloat) s> <(GLfloat) t> <(GLfloat) r> <(GLfloat) q>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetDoubleFromObj(interp, objv[2], &s);
    Tcl_GetDoubleFromObj(interp, objv[3], &t);
    Tcl_GetDoubleFromObj(interp, objv[4], &r);
    Tcl_GetDoubleFromObj(interp, objv[5], &q);
    glMultiTexCoord4fARB((GLenum)target, (GLfloat )s, (GLfloat )t, (GLfloat )r, (GLfloat )q);
    return GetGLError(interp);
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
    double *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4fvARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4fvARB <(GLenum) target> <(GLfloat) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord4fvARB((GLenum)target, (void *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4iARBCmd", objc, objv);
    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4iARB <(GLenum) target> <(GLint) s> <(GLint) t> <(GLint) r> <(GLint) q>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    Tcl_GetIntFromObj(interp, objv[3], &t);
    Tcl_GetIntFromObj(interp, objv[4], &r);
    Tcl_GetIntFromObj(interp, objv[5], &q);
    glMultiTexCoord4iARB((GLenum)target, (GLint )s, (GLint )t, (GLint )r, (GLint )q);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4ivARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4ivARB <(GLenum) target> <(GLint) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord4ivARB((GLenum)target, (GLint *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4sARBCmd", objc, objv);
    if (objc != 6) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4sARB <(GLenum) target> <(GLshort) s> <(GLshort) t> <(GLshort) r> <(GLshort) q>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    Tcl_GetIntFromObj(interp, objv[2], &s);
    Tcl_GetIntFromObj(interp, objv[3], &t);
    Tcl_GetIntFromObj(interp, objv[4], &r);
    Tcl_GetIntFromObj(interp, objv[5], &q);
    glMultiTexCoord4sARB((GLenum)target, (GLshort )s, (GLshort )t, (GLshort )r, (GLshort )q);
    return GetGLError(interp);
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
    int *v;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMultiTexCoord4svARBCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMultiTexCoord4svARB <(GLenum) target> <(GLshort) v>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    target = (GLenum)Tcl_GetHashValue(hPtr); 
    v = (void *)Tcl_GetByteArrayFromObj(objv[2], NULL);
    glMultiTexCoord4svARB((GLenum)target, (GLshort *)v);
    return GetGLError(interp);
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

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glBlendEquationSeparateATICmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glBlendEquationSeparateATI <(GLenum) modeRGB> <(GLenum) modeA>\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[1]),"\"", NULL);
	return TCL_ERROR;
    }
    modeRGB = (GLenum)Tcl_GetHashValue(hPtr); 
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[2]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",  Tcl_GetString(objv[2]),"\"", NULL);
	return TCL_ERROR;
    }
    modeA = (GLenum)Tcl_GetHashValue(hPtr); 
    glBlendEquationSeparateATI((GLenum)modeRGB, (GLenum)modeA);
    return GetGLError(interp);
}
