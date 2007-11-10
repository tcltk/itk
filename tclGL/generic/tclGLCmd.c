/*
 * tclGLCmd.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLCmd.c,v 1.1.2.4 2007/11/10 18:26:20 wiede Exp $
 */

#include <stdlib.h>
#include "tclGLInt.h"
#include "tclGLFuncSizes.h"

Tcl_ObjCmdProc TclGL_DefaultCmd;
Tcl_ObjCmdProc TclGL_UnknownCmd;
Tcl_ObjCmdProc TclGL_Define2Str;
Tcl_ObjCmdProc TclGL_Str2Define;
Tcl_ObjCmdProc TclGL_MakeUnsignedByteVector;
Tcl_ObjCmdProc TclGL_MakeIntVector;
Tcl_ObjCmdProc TclGL_MakeFloatVector;
Tcl_ObjCmdProc TclGL_MakeDoubleVector;
#include "tclGLProcNames.c"

typedef struct GLMethod {
    char *commandName;       /* the command name with the namespace prefix */
    char *usage;             /* string describing usage */
    Tcl_ObjCmdProc *proc;    /* implementation C proc */
} GLMethod;

static GLMethod GLMethodList[] = {
#include "tclGLMethodInfos.c"
    { "::ntk::gl::GL::unknown",
            "", TclGL_UnknownCmd },
    { "::ntk::gl::GL::define2Str",
            "<define value>", TclGL_Define2Str },
    { "::ntk::gl::GL::str2Define",
            "<define string>", TclGL_Str2Define },
    { "::ntk::gl::GL::makeIntVector",
            "<list>", TclGL_MakeIntVector },
    { "::ntk::gl::GL::makeUnsignedByteVector",
            "<list>", TclGL_MakeUnsignedByteVector },
    { "::ntk::gl::GL::makeFloatVector",
            "<list>", TclGL_MakeFloatVector },
    { "::ntk::gl::GL::makeDoubleVector",
            "<list>", TclGL_MakeDoubleVector },
    /*
     *  Add an error handler to support all of the usual inquiries
     *  for the "info" command in the global namespace.
     */
    { "::ntk::gl::GL::@error", "", TclGL_DefaultCmd },
    { NULL, NULL, NULL }
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
 *  TclGL_InitCommands()
 *
 *      that is the starting point when loading the library
 *      it initializes all internal stuff
 *
 * ------------------------------------------------------------------------
 */

int
TclGL_InitCommands (
    Tcl_Interp *interp,
    TclGLInfo *infoPtr)
{
    Tcl_Namespace *nsPtr;
    Tcl_Command cmd;
    int i;

    /*
     * Build the ensemble used to implement [ntk gl].
     */

    nsPtr = Tcl_CreateNamespace(interp, "::ntk::gl::GL", NULL, NULL);
    if (nsPtr == NULL) {
        Tcl_Panic("ITCL: error in creating namespace: ::ntk::gl::GL \n");
    }
    cmd = Tcl_CreateEnsemble(interp, nsPtr->fullName, nsPtr,
        TCL_ENSEMBLE_PREFIX);
    Tcl_Export(interp, nsPtr, "[a-z]*", 1);
    for (i=0 ; GLMethodList[i].commandName!=NULL ; i++) {
        Tcl_CreateObjCommand(interp, GLMethodList[i].commandName,
                GLMethodList[i].proc, infoPtr, NULL);
    }
    Tcl_Obj *ensObjPtr = Tcl_NewStringObj("::ntk::gl::GL", -1);
    Tcl_IncrRefCount(ensObjPtr);
    Tcl_Obj *unkObjPtr = Tcl_NewStringObj("::ntk::gl::GL::unknown", -1);
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
TclGLGetUsage(
    Tcl_Interp *interp,
    TclGLInfo *infoPtr,
    Tcl_Obj *objPtr)       /* returns: summary of usage info */
{
    TclGLFunc *funcPtr;
    char *spaces = "  ";
    const char *cp;
    int i;

    for (i=0; GLMethodList[i].commandName != NULL; i++) {
        Tcl_AppendToObj(objPtr, spaces, -1);
        Tcl_AppendToObj(objPtr, "ntk ", -1);
        Tcl_AppendToObj(objPtr, GLMethodList[i].commandName, -1);
	if (GLMethodList[i].usage == NULL) {
	    if (i < TCL_NUM_GL_FUNCS) {
	        funcPtr = infoPtr->funcv[i];
		cp = strrchr(GLMethodList[i].commandName, ':');
		if (cp == NULL) {
		   cp = GLMethodList[i].commandName;
		} else {
		   cp++;
		}
		Tcl_AppendToObj(objPtr, " ", -1);
		Tcl_AppendToObj(objPtr, cp, -1);
		Tcl_AppendToObj(objPtr, " ", -1);
		Tcl_AppendToObj(objPtr, Tcl_GetString(funcPtr->usagePtr), -1);
	    }
	} else {
            if (strlen(GLMethodList[i].usage) > 0) {
                Tcl_AppendToObj(objPtr, " ", -1);
                Tcl_AppendToObj(objPtr, GLMethodList[i].usage, -1);
	    }
        }
        spaces = "\n  ";
    }
}

/*
 * ------------------------------------------------------------------------
 *  CheckNumParams()
 *
 *  check if number of params is correct and return error message if not
 *  check if function is loadable if not yet available
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
void (*glXGetProcAddressARB(const GLubyte *procName))();

int
CheckNumParams(
    Tcl_Interp *interp,
    TclGLInfo *infoPtr,
    int funcNo,
    int objc,
    int numParams)
{
    TclGLFunc *funcPtr;

    if (funcNo >= TCL_NUM_GL_FUNCS) {
	char buf1[50];
	char buf2[50];
	sprintf(buf1, "%d", funcNo);
	sprintf(buf2, "%d", TCL_NUM_GL_FUNCS);
        Tcl_AppendResult(interp,
	        "func function number:", buf1, " max:", buf2, NULL);
        return TCL_ERROR;
    }
    funcPtr = infoPtr->funcv[funcNo];
    if (objc != numParams+1) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk ",
		Tcl_GetString(funcPtr->funcNamePtr), " ", 
		Tcl_GetString(funcPtr->usagePtr), "\"", NULL);
        return TCL_ERROR;
    }
    if (funcPtr->funcPtr == NULL) {
        if (funcPtr->flags & TCL_GL_FUNC_NOT_AVAILABLE) {
            Tcl_AppendResult(interp, "function \"",
	            Tcl_GetString(funcPtr->funcNamePtr),
		    "\" cannot be loaded", NULL);
            return TCL_ERROR;
	} else {
	    if (!(funcPtr->flags & TCL_GL_FUNC_LOADED)) {
	        funcPtr->funcPtr = glXGetProcAddressARB(
		        (const GLubyte *)Tcl_GetString(funcPtr->funcNamePtr));
	        if (funcPtr->funcPtr == NULL) {
		    funcPtr->flags &= ~TCL_GL_FUNC_AVAILABLE;
		    funcPtr->flags |= TCL_GL_FUNC_NOT_AVAILABLE;
                    Tcl_AppendResult(interp, "function \"",
	                    Tcl_GetString(funcPtr->funcNamePtr),
		            "\" cannot be loaded", NULL);
                    return TCL_ERROR;
		} else {
		    funcPtr->flags |= TCL_GL_FUNC_LOADED;
		}
	    }
	}
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  GetDoubleParam()
 *
 *  the get a double parameter from objv[x] parameter
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
GetDoubleParam(
    Tcl_Interp *interp,
    TclGLInfo *infoPtr,
    Tcl_Obj *objPtr,
    double *dPtr)
{
    if (Tcl_GetDoubleFromObj(interp, objPtr, dPtr) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  GetIntParam()
 *
 *  the get an int parameter from objv[x] parameter
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
GetIntParam(
    Tcl_Interp *interp,
    TclGLInfo *infoPtr,
    Tcl_Obj *objPtr,
    int *iPtr)
{
    if (Tcl_GetIntFromObj(interp, objPtr, iPtr) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  GetBooleanParam()
 *
 *  the get a boolean parameter from objv[x] parameter
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
GetBooleanParam(
    Tcl_Interp *interp,
    TclGLInfo *infoPtr,
    Tcl_Obj *objPtr,
    int *iPtr)
{
    if (Tcl_GetBooleanFromObj(interp, objPtr, iPtr) != TCL_OK) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  GetEnumParam()
 *
 *  the get a enum parameter from objv[x] parameter
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
GetEnumParam(
    Tcl_Interp *interp,
    TclGLInfo *infoPtr,
    Tcl_Obj *objPtr,
    int *iPtr)
{
    Tcl_HashEntry *hPtr;

    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objPtr);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define \"",
	        Tcl_GetString(objPtr), "\"", NULL);
        return TCL_ERROR;
    }
    *iPtr = (int)Tcl_GetHashValue(hPtr);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  GetBitfieldParam()
 *
 *  the get a bitfield parameter from objv[x] parameter
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
GetBitfieldParam(
    Tcl_Interp *interp,
    TclGLInfo *infoPtr,
    Tcl_Obj *objPtr,
    int *iPtr)
{
    Tcl_HashEntry *hPtr;
    Tcl_Obj *objPtr2;
    const char *cp;
    const char *ep;
    const char *token;
    int isEnd;
    int value;

    token = Tcl_GetString(objPtr);
    isEnd = 0;
    value = 0;
    cp = token;
    while (1) {
        if (strstr(cp, "|") == NULL) {
	    isEnd = 1;
	}
	while (*cp == ' ') {
	    cp++;
	}
	ep = cp;
	while ((*ep != '\0') && (*ep != '|')) {
	    ep++;
	}
	if (*ep != '\0') {
	    ep--;
	}
	objPtr2 = Tcl_NewStringObj(cp, ep-cp);
	Tcl_IncrRefCount(objPtr2);
	if (*ep == '\0') {
	    isEnd = 1;
	}
	cp = ep+2;
        hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objPtr2);
	Tcl_DecrRefCount(objPtr2);
        if (hPtr == NULL) {
            Tcl_AppendResult(interp, "no such define \"", \
	            Tcl_GetString(objPtr),"\"", NULL);
	    return TCL_ERROR;
        }
        value |= (GLenum)Tcl_GetHashValue(hPtr);
        if (isEnd) {
	    break;
	}
    }
    *iPtr = value;
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  GetPtrInParam()
 *
 *  the get a pointer in parameter from objv[x] parameter
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
GetPtrInParam(
    Tcl_Interp *interp,
    TclGLInfo *infoPtr,
    Tcl_Obj *objPtr,
    void **vPtr,
    int *lgthPtr)
{
    *vPtr = (void *)Tcl_GetByteArrayFromObj(objPtr, lgthPtr);
    if (*vPtr == NULL) {
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  GetPtrOutParam()
 *
 *  the set a pointer out parameter in objv[x] parameter
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
SetPtrOutParam(
    Tcl_Interp *interp,
    TclGLInfo *infoPtr,
    Tcl_Obj *objPtr,
    int lgth,
    void *vPtr)
{
    Tcl_Obj *objPtr2;

    objPtr2 = Tcl_NewByteArrayObj((unsigned char *)vPtr, lgth);
    Tcl_SetObjResult(interp, objPtr2);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_UnknownCmd()
 *
 *  the unknown handler for the ::itcl::builtin::Info ensemble
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_UnknownCmd(
    ClientData clientData,   /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    TclGLInfo *infoPtr;
    int result;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_UnknownCmd", objc, objv);
    result = TCL_ERROR;
    /* produce usage message */
    Tcl_Obj *objPtr = Tcl_NewStringObj("unknown command: \"", -1);
    Tcl_AppendToObj(objPtr, Tcl_GetString(objv[2]), -1);
    Tcl_AppendToObj(objPtr, "\" should be one of...\n", -1);
    TclGLGetUsage(interp, infoPtr, objPtr);
    Tcl_SetResult(interp, Tcl_GetString(objPtr), TCL_DYNAMIC);
    return TCL_ERROR;
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_Define2Str()
 *
 *  convert a GL_ define value to the corresponding string
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_Define2Str(
    ClientData clientData,   /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int value;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_Define2Str", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glDefine2Str value\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_GetIntFromObj(interp, objv[1], &value);
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefineStrings, (char *)value);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define value: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
	return TCL_ERROR;
    }
    Tcl_AppendResult(interp, Tcl_GetString(Tcl_GetHashValue(hPtr)), NULL);
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_Str2Define()
 *
 *  convert a GL_ define string to the corresponding value
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_Str2Define(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_Str2Define", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk glStr2Define value\"",
                NULL);
        return TCL_ERROR;
    }
    hPtr = Tcl_FindHashEntry(&infoPtr->glDefines, (char *)objv[1]);
    if (hPtr == NULL) {
        Tcl_AppendResult(interp, "no such define string: \"",
	        Tcl_GetString(objv[1]), "\"", NULL);
	return TCL_ERROR;
    }
    char buf[30];
    Tcl_Obj *objPtr;
    sprintf(buf, "0x%08x", (int)Tcl_GetHashValue(hPtr));
    objPtr = Tcl_NewStringObj(buf, -1);
    Tcl_AppendResult(interp, Tcl_GetString(objPtr), NULL);
    return TCL_OK;;
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_MakeUnisgnedByteVector()
 *
 *  convert a list of ints into a Tcl_ByteArrayObj
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_MakeUnsignedByteVector(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_Obj *objPtr;
    TclGLInfo *infoPtr;
    unsigned char *uCharVec;
    unsigned char uCharVal;
    const char **argv;
    int argc;
    int i;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_MakeUnsignedByteVector", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk makeUnsignedByteVector list\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_SplitList(interp, Tcl_GetString(objv[1]), &argc, &argv);
    uCharVec = (unsigned char *)ckalloc(sizeof(unsigned char)*argc);
    for(i=0;i<argc;i++) {
        uCharVal = atoi(argv[i]);
	uCharVec[i] = uCharVal;
    }
    objPtr = Tcl_NewByteArrayObj((unsigned char *)uCharVec,
            sizeof(unsigned char)*argc);
    Tcl_AppendResult(interp, Tcl_GetString(objPtr), NULL);
    return TCL_OK;;
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_MakeIntVector()
 *
 *  convert a list of ints into a Tcl_ByteArrayObj
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_MakeIntVector(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_Obj *objPtr;
    TclGLInfo *infoPtr;
    int *intVec;
    int intVal;
    const char **argv;
    int argc;
    int i;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_MakeIntVector", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk makeIntVector list\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_SplitList(interp, Tcl_GetString(objv[1]), &argc, &argv);
    intVec = (int *)ckalloc(sizeof(int)*argc);
    for(i=0;i<argc;i++) {
        intVal = atoi(argv[i]);
	intVec[i] = intVal;
    }
    objPtr = Tcl_NewByteArrayObj((unsigned char *)intVec, sizeof(int)*argc);
    Tcl_AppendResult(interp, Tcl_GetString(objPtr), NULL);
    return TCL_OK;;
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_MakeFloatVector()
 *
 *  convert a list of floats into a Tcl_ByteArrayObj
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_MakeFloatVector(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_Obj *objPtr;
    TclGLInfo *infoPtr;
    float *floatVec;
    float floatVal;
    const char **argv;
    int argc;
    int i;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_MakeFloatVector", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk makeFloatVector list\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_SplitList(interp, Tcl_GetString(objv[1]), &argc, &argv);
    floatVec = (float *)ckalloc(sizeof(float)*argc);
    for(i=0;i<argc;i++) {
        floatVal = atof(argv[i]);
	floatVec[i] = floatVal;
    }
    objPtr = Tcl_NewByteArrayObj((unsigned char *)floatVec, sizeof(float)*argc);
    Tcl_AppendResult(interp, Tcl_GetString(objPtr), NULL);
    return TCL_OK;;
}


/*
 * ------------------------------------------------------------------------
 *  TclGL_MakeDoubleVector()
 *
 *  convert a list of doubles into a Tcl_ByteArrayObj
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_MakeDoubleVector(
    ClientData clientData,  /* infoPtr */
    Tcl_Interp *interp,      /* current interpreter */
    int objc,                /* number of arguments */
    Tcl_Obj *CONST objv[])   /* argument objects */
{
    Tcl_Obj *objPtr;
    TclGLInfo *infoPtr;
    double *doubleVec;
    double doubleVal;
    const char **argv;
    int argc;
    int i;

    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGL_MakeDoubleVector", objc, objv);
    if (objc != 2) {
        Tcl_AppendResult(interp,
                "wrong # args: should be \"ntk makeDoubleVector list\"",
                NULL);
        return TCL_ERROR;
    }
    Tcl_SplitList(interp, Tcl_GetString(objv[1]), &argc, &argv);
    doubleVec = (double *)ckalloc(sizeof(double)*argc);
    for(i=0;i<argc;i++) {
        doubleVal = atof(argv[i]);
	doubleVec[i] = doubleVal;
    }
    objPtr = Tcl_NewByteArrayObj((unsigned char *)doubleVec, sizeof(double)*argc);
    Tcl_AppendResult(interp, Tcl_GetString(objPtr), NULL);
    return TCL_OK;;
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_InitCmd()
 *
 *  Handles the GL init command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_InitCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLShowArgs(0, "TclGL_InitCmd", objc, objv);
    if (objc != 1) {
	Tcl_AppendResult(interp,
	        "wrong # args: should be \"ntk gl init\"",
	        NULL);
        return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * ------------------------------------------------------------------------
 *  TclGL_DefaultCmd()
 *
 *  Handles any unknown options for the "ntk::gl::GL" command
 *
 *  Returns TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_DefaultCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLInfo *infoPtr;
    int result;

    infoPtr = (TclGLInfo *)clientData;
    result = TCL_ERROR;
    TclGLShowArgs(0, "TclGL_DefaultCmd", objc, objv);
    return result;
}
/*
 * ------------------------------------------------------------------------
 *  TclGL_CallGlFunction()
 *
 *  Handles the call of a GL function
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */
int
TclGL_CallGlFunction(
    int funcNo,            /* the internal number of the function */
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
{
    TclGLShowArgs(0, "TclGL_CallGlFunction", objc, objv);
    return TCL_OK;
}

#include <GL/gl.h>
#include "tclGLFuncs.c"
