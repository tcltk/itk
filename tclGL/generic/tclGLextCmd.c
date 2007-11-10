/*
 * tclGLCmdExt.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLextCmd.c,v 1.1.2.1 2007/11/10 18:26:22 wiede Exp $
 */

#include <stdlib.h>
#define GL_GLEXT_PROTOTYPES 1
#include "tclGLInt.h"

Tcl_ObjCmdProc TclGLext_DefaultCmd;
Tcl_ObjCmdProc TclGLext_UnknownCmd;
Tcl_ObjCmdProc TclGLext_glBindBufferCmd;
Tcl_ObjCmdProc TclGLext_glDeleteBuffersCmd;
Tcl_ObjCmdProc TclGLext_glGenBuffersCmd;
Tcl_ObjCmdProc TclGLext_glIsBufferCmd;
Tcl_ObjCmdProc TclGLext_glBufferDataCmd;
Tcl_ObjCmdProc TclGLext_glBufferSubDataCmd;
Tcl_ObjCmdProc TclGLext_glGetBufferSubDataCmd;
Tcl_ObjCmdProc TclGLext_glMapBufferCmd;
Tcl_ObjCmdProc TclGLext_glUnmapBufferCmd;

typedef struct GLMethod {
    char* name;              /* method name */
    char* usage;             /* string describing usage */
    Tcl_ObjCmdProc *proc;    /* implementation C proc */
} GLMethod;

static GLMethod GLMethodList[] = {
    { "glBindBuffer", "<(GLenum) target> <(GLuint) buffer>",
            TclGLext_glBindBufferCmd },
    { "glDeleteBuffers", "<(GLsizei) count> <(GLuint *) buffer>",
            TclGLext_glDeleteBuffersCmd },
    { "glGenBuffer", "<(GLsizei) count> <(GLuint*) buffer>",
            TclGLext_glGenBuffersCmd },
    { "glIsBuffer", "<(GLuint) buffer>",
            TclGLext_glIsBufferCmd },
    { "glBufferData", "<(GLenum) target> <(GLsizeiptr)> <(const GLvoid *) buffer> <(GLenum) xx",
            TclGLext_glBufferDataCmd },
    { "glBufferSubData", "<(GLenum) target> <(GLintptr)> <(GLsizeiptr) yy> <(const GLvoid *) buffer>",
            TclGLext_glBufferSubDataCmd },
    { "glBufferGetSubData", "<(GLenum) target> <(GLintptr)> <(GLsizeiptr) yy> <(const GLvoid *) buffer>",
            TclGLext_glGetBufferSubDataCmd },
    { "glMapBuffer", "<(GLenum) target> <(GLenum) type>",
            TclGLext_glMapBufferCmd },
    { "glUnmapBuffer", "<(GLenum) target>",
            TclGLext_glUnmapBufferCmd },
    /*
     *  Add an error handler to support all of the usual inquiries
     *  for the "info" command in the global namespace.
     */
    { "@error", "", TclGLext_DefaultCmd },
    { NULL, NULL, NULL }
};

struct NameProcMap { const char *name; Tcl_ObjCmdProc *proc; };

/*
 * List of commands that are used to implement the [ntk glfw] subcommands.
 */

static const struct NameProcMap glCmds2[] = {
    { "::ntk::gl::GLext::unknown", TclGLext_UnknownCmd },
    { "::ntk::gl::GLext::glBindBuffer", TclGLext_glBindBufferCmd },
    { "::ntk::gl::GLext::glDeleteBuffers", TclGLext_glDeleteBuffersCmd },
    { "::ntk::gl::GLext::glGenBuffers", TclGLext_glGenBuffersCmd },
    { "::ntk::gl::GLext::glIsBuffer", TclGLext_glIsBufferCmd },
    { "::ntk::gl::GLext::glBufferData", TclGLext_glBufferDataCmd },
    { "::ntk::gl::GLext::glBufferSubData", TclGLext_glBufferSubDataCmd },
    { "::ntk::gl::GLext::glGetBufferSubData", TclGLext_glGetBufferSubDataCmd },
    { "::ntk::gl::GLext::glMapBuffer", TclGLext_glMapBufferCmd },
    { "::ntk::gl::GLext::glUnmapBuffer", TclGLext_glUnmapBufferCmd },
    /*
     *  Add an error handler
     */
    { "::ntk::gl::GLext::@error", TclGLext_DefaultCmd },
    { NULL, NULL }
};

/*
 * ------------------------------------------------------------------------
 *  GetGLError()
 *
 *      Handle GL errors
 *
 * ------------------------------------------------------------------------
 */

static int
GetGLError (
    Tcl_Interp *interp,
    TclGLInfo *infoPtr)
{
    GLenum glResult;
    int result;

    if (infoPtr->noGLGetError) {
        return TCL_OK;
    }
    glResult = glGetError();
    result = TCL_ERROR;
    switch (glResult) {
    case GL_NO_ERROR:
        result = TCL_OK;
        break;
    case GL_INVALID_VALUE:
        Tcl_AppendResult(interp, "GL ERROR GL_INVALID_VALUE", NULL);
        break;
    case GL_INVALID_ENUM:
        Tcl_AppendResult(interp, "GL ERROR GL_INVALID_ENUM", NULL);
        break;
    case GL_INVALID_OPERATION:
        Tcl_AppendResult(interp, "GL ERROR GL_INVALID_OPERATION", NULL);
        break;
    case GL_STACK_OVERFLOW:
        Tcl_AppendResult(interp, "GL ERROR GL_STACK_OVERFLOW", NULL);
        break;
    case GL_STACK_UNDERFLOW:
        Tcl_AppendResult(interp, "GL ERROR GL_STACK_UNDERFLOW", NULL);
        break;
    case GL_OUT_OF_MEMORY:
        Tcl_AppendResult(interp, "GL ERROR GL_OUT_OF_MEMORY", NULL);
        break;
    default:
        fprintf(stderr, "funny result in glGetError!0x%08x\n", glResult);
        break;
    }
    return result;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_InitCommands()
 *
 *      that is the starting point when loading the library
 *      it initializes all internal stuff
 *
 * ------------------------------------------------------------------------
 */

int
TclGLext_InitCommands (
    Tcl_Interp *interp,
    TclGLInfo *infoPtr)
{
    Tcl_Namespace *nsPtr;
    Tcl_Command cmd;
    int i;

    /*
     * Build the ensemble used to implement [ntk gl].
     */

    nsPtr = Tcl_CreateNamespace(interp, "::ntk::gl::GLext", NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("ITCL: error in creating namespace: ::ntk::gl::GLext \n");
    }
    cmd = Tcl_CreateEnsemble(interp, nsPtr->fullName, nsPtr,
        TCL_ENSEMBLE_PREFIX);
    Tcl_Export(interp, nsPtr, "[a-z]*", 1);
    for (i=0 ; glCmds2[i].name!=NULL ; i++) {
        Tcl_CreateObjCommand(interp, glCmds2[i].name,
                glCmds2[i].proc, infoPtr, NULL);
    }
    Tcl_Obj *ensObjPtr = Tcl_NewStringObj("::ntk::gl::GLext", -1);
    Tcl_IncrRefCount(ensObjPtr);
    Tcl_Obj *unkObjPtr = Tcl_NewStringObj("::ntk::gl::GLext::unknown", -1);
    Tcl_IncrRefCount(unkObjPtr);
    if (Tcl_SetEnsembleUnknownHandler(NULL,
            Tcl_FindEnsemble(interp, ensObjPtr, TCL_LEAVE_ERR_MSG),
	    unkObjPtr) != TCL_OK) {
        return TCL_ERROR;
    }
    Tcl_DecrRefCount(ensObjPtr);
    Tcl_DecrRefCount(unkObjPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLGetUsage()
 *
 * ------------------------------------------------------------------------
  */
void
TclGLextGetUsage(
    Tcl_Interp *interp,
    Tcl_Obj *objPtr)       /* returns: summary of usage info */
{
    char *spaces = "  ";
    int isOpenEnded = 0;

    int i;

    for (i=0; GLMethodList[i].name != NULL; i++) {
        if (*GLMethodList[i].name == '@'
	        && strcmp(GLMethodList[i].name,"@error") == 0) {
            isOpenEnded = 1;
        } else {
            Tcl_AppendToObj(objPtr, spaces, -1);
            Tcl_AppendToObj(objPtr, "ntk ", -1);
            Tcl_AppendToObj(objPtr, GLMethodList[i].name, -1);
	    if (strlen(GLMethodList[i].usage) > 0) {
              Tcl_AppendToObj(objPtr, " ", -1);
              Tcl_AppendToObj(objPtr, GLMethodList[i].usage, -1);
	    }
            spaces = "\n  ";
        }
    }
    if (isOpenEnded) {
        Tcl_AppendToObj(objPtr,
            "\n...and others described on the man page", -1);
    }
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_UnknownCmd()
 *
 *  the unknown handler for the ::itcl::builtin::Info ensemble
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLext_UnknownCmd(
    ClientData dummy,        /* not used */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    int result;

    TclGLShowArgs(1, "TclGLext_UnknownCmd", objc, objv);
    result = TCL_ERROR;
    /* produce usage message */
    Tcl_Obj *objPtr = Tcl_NewStringObj("unknown command: \"", -1);
    Tcl_AppendToObj(objPtr, Tcl_GetString(objv[2]), -1);
    Tcl_AppendToObj(objPtr, "\" should be one of...\n", -1);
    TclGLextGetUsage(interp, objPtr);
    Tcl_SetResult(interp, Tcl_GetString(objPtr), TCL_DYNAMIC);
    return TCL_ERROR;
}

/*
 * ------------------------------------------------------------------------
 *  TclGLext_DefaultCmd()
 *
 *  Handles any unknown options for the "ntk::gl::GL" command
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGLext_DefaultCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLInfo *infoPtr;
    int result;

    infoPtr = (TclGLInfo *)clientData;
    result = TCL_ERROR;
    TclGLShowArgs(0, "TclGLext_DefaultCmd", objc, objv);
    return result;
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
    int target;
    int buffer;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDeleteBuffersCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glBindBuffer <(GLenum) target> <(GLuint) buffers>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &target);
    Tcl_GetIntFromObj(interp, objv[2], &buffer);
    glBindBuffer(target, buffer);
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
    int byteArrayLength2;
    int n;
    unsigned int *buffers;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glDeleteBuffersCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDeleteBuffers <(GLsizei) n> <(GLuint *) buffers>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &n);
    buffers = (void *)Tcl_GetByteArrayFromObj(objv[2], &byteArrayLength2);
    glDeleteBuffers(n, buffers);
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
    int n;
    unsigned int *buffers;
//unsigned int buffers[5] = {-1, -1, -1, -1, -1};
buffers = NULL;
    unsigned int bufId;
    unsigned int bufId2;
    unsigned int bufId3;
    int result;
    int isNew;
    int i;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGenBuffersCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGenBuffers <(GLsizei) n> <(GLuint *) buffers>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &n);
    buffers = (unsigned int *)ckalloc(sizeof(unsigned int)*n);
memset(buffers, 0, sizeof(unsigned int)*n);
fprintf(stderr, "buffers!%p!\n", buffers);
    bufId = -1;
    bufId2 = -1;
    bufId3 = -1;
void (*glXGetProcAddressARB(const GLubyte *procName))();
    void (*pa)();
    pa = glXGetProcAddressARB((const GLubyte *)"glGenBuffers");
fprintf(stderr, "pa1!%p!%p!\n", pa, glGenBuffers);
    const unsigned char *str = glGetString(GL_EXTENSIONS);
fprintf(stderr, "EXT!%s!\n", str);
    glGenBuffersARB(1, &bufId);
    glBindBuffer(GL_ARRAY_BUFFER, bufId);
fprintf(stderr, "GEN0!0x%08x!\n", bufId);
    (*pa)(1, &bufId);
fprintf(stderr, "GEN1!0x%08x!%d!\n", bufId, GetGLError(interp, infoPtr));
    glGenBuffers(1, &bufId2);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufId2);
    glGenBuffers(1, &bufId3);
    glBindBuffer(GL_ARRAY_BUFFER, bufId3);
fprintf(stderr, "GEN!%d!0x%08x!0x%08x!0x%08x\n", n, bufId, bufId2, bufId3);
fprintf(stderr, "IS!%d!%d!%d!\n", glIsBuffer(bufId), glIsBuffer(bufId2), glIsBuffer(bufId3));
    result = GetGLError(interp, infoPtr);
    i = 0;
    char buf[50];
    Tcl_Obj *objPtr;
    Tcl_Obj *listPtr;
    listPtr = Tcl_NewListObj(0, NULL);
    for(i=0;i<n;i++) {
        sprintf(buf, "fbo_0x%08x", buffers[i]);
	objPtr = Tcl_NewStringObj(buf, -1);
	Tcl_IncrRefCount(objPtr);
	hPtr = Tcl_CreateHashEntry(&infoPtr->fbos, (char *)objPtr, &isNew);
	Tcl_SetHashValue(hPtr, buffers[i]);
        Tcl_ListObjAppendElement(interp, listPtr, objPtr);
    }
    Tcl_SetObjResult(interp, listPtr);
    return result;
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
    int n;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glIsBufferCmd", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glIsBuffers <(GLuint) n>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &n);
    return glIsBuffer(n);
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
    int n;
    int sizeiptr;
    int byteArrayLength3;
    void *data;
    int type;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glBufferDataCmd", objc, objv);
    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glBufferData <(GLenum) n> <(GLsizeiptr) sizeiptr> <(GLvoid *) data> <(GLenum) type>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &n);
    Tcl_GetIntFromObj(interp, objv[2], &sizeiptr);
    data = (void *)Tcl_GetByteArrayFromObj(objv[3], &byteArrayLength3);
    Tcl_GetIntFromObj(interp, objv[4], &type);
    glBufferData(n, sizeiptr, data, type);
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
    int n;
    int intptr;
    int sizeiptr;
    int byteArrayLength4;
    void *data;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glBufferSubDataCmd", objc, objv);
    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glBufferSubData <(GLenum) n> <(GLintptr) intptr> <(GLsizeiptr) sizeiptr> <(GLvoid *) data>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &n);
    Tcl_GetIntFromObj(interp, objv[2], &intptr);
    Tcl_GetIntFromObj(interp, objv[3], &sizeiptr);
    data = (void *)Tcl_GetByteArrayFromObj(objv[4], &byteArrayLength4);
    glBufferSubData(n, intptr, sizeiptr, data);
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
    int n;
    int intptr;
    int sizeiptr;
    int byteArrayLength4;
    void *data;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glGetBufferSubDataCmd", objc, objv);
    if (objc != 5) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glGetBufferSubData <(GLenum) n> <(GLintptr) intptr> <(GLsizeiptr) sizeiptr> <(GLvoid *) data>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &n);
    Tcl_GetIntFromObj(interp, objv[2], &intptr);
    Tcl_GetIntFromObj(interp, objv[3], &sizeiptr);
    data = (void *)Tcl_GetByteArrayFromObj(objv[4], &byteArrayLength4);
    glGetBufferSubData(n, intptr, sizeiptr, data);
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
    int n;
    int type;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glMapBufferCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glMapBuffer <(GLenum) n> <(GLenum) type>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &n);
    Tcl_GetIntFromObj(interp, objv[2], &type);
    glMapBuffer(n, type);
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
    int n;

    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_glUnmapBufferCmd", objc, objv);
    if (objc != 3) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glUnmapBuffer <(GLenum) n>\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &n);
    glUnmapBuffer(n);
    return GetGLError(interp, infoPtr);
}
