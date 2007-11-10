/*
 * tclGLInt.h --
 *
 * This file contains internal definitions for the C-implemented part of a
 * a Tcl interface to the OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLInt.h,v 1.1.2.2 2007/11/10 18:26:22 wiede Exp $
 */

#include <string.h>
#include <ctype.h>
#include <tcl.h>
#include <GL/gl.h>
#include "tclGL.h"

/*
 * Used to tag functions that are only to be visible within the module being
 * built and not outside it (where this is supported by the linker).
 */

#ifndef MODULE_SCOPE
#   ifdef __cplusplus
#       define MODULE_SCOPE extern "C"
#   else
#       define MODULE_SCOPE extern
#   endif
#endif

/*
 * Convenience macros for iterating through hash tables. FOREACH_HASH_DECLS
 * sets up the declarations needed for the main macro, FOREACH_HASH, which
 * does the actual iteration. FOREACH_HASH_VALUE is a restricted version that
 * only iterates over values.
 */

#define FOREACH_HASH_DECLS \
    Tcl_HashEntry *hPtr;Tcl_HashSearch search
#define FOREACH_HASH(key,val,tablePtr) \
    for(hPtr=Tcl_FirstHashEntry((tablePtr),&search); hPtr!=NULL ? \
            ((key)=(void *)Tcl_GetHashKey((tablePtr),hPtr),\
            (val)=Tcl_GetHashValue(hPtr),1):0; hPtr=Tcl_NextHashEntry(&search))
#define FOREACH_HASH_VALUE(val,tablePtr) \
    for(hPtr=Tcl_FirstHashEntry((tablePtr),&search); hPtr!=NULL ? \
            ((val)=Tcl_GetHashValue(hPtr),1):0;hPtr=Tcl_NextHashEntry(&search))

#define TCL_GL_INTERP_DATA "tclGL_data"
#define TCL_GL_INFO_VERSION 1

typedef struct TclGLDefineGroup {
    int defineGroupNo;
    Tcl_Obj *defineGroupNamePtr;
} TclGLDefineGroup;

typedef struct TclGLFuncGroup {
    int funcGroupNo;
    Tcl_Obj *funcGroupNamePtr;
} TclGLFuncGroup;

typedef struct TclGLTypedefGroup {
    int typedefGroupNo;
    Tcl_Obj *typedefGroupNamePtr;
} TclGLTypedefGroup;

typedef struct TclGLDefine {
    int defineGroupNo;
    int value;
    Tcl_Obj *defineGroupNamePtr;
    Tcl_Obj *defineValuePtr;
    Tcl_Obj *defineNamePtr;
} TclGLDefine;

#define TCL_GL_IN_PARAM         0x000001
#define TCL_GL_OUT_PARAM        0x000002
#define TCL_GL_IN_OUT_PARAM     0x000004
#define TCL_GL_CONST_PARAM      0x000008
#define TCL_GLenum 		0x000100
#define TCL_GLboolean 		0x000200
#define TCL_GLbitfield 		0x000400
#define TCL_GLvoid 		0x000800
#define TCL_GLbyte 		0x001000
#define TCL_GLshort 		0x002000
#define TCL_GLint 		0x004000
#define TCL_GLubyte 		0x008000
#define TCL_GLushort 		0x010000
#define TCL_GLuint 		0x020000
#define TCL_GLsizei 		0x040000
#define TCL_GLfloat 		0x080000
#define TCL_GLclampf 		0x100000
#define TCL_GLdouble 		0x200000
#define TCL_GLclampd 		0x400000

typedef struct TclGLParam {
    int flags;
    int returnFlags;
    Tcl_Obj *paramNamePtr;
} TclGLParam;

typedef void (*GLfunction)();

#define TCL_GL_FUNC_AVAILABLE		0x00001
#define TCL_GL_FUNC_NOT_AVAILABLE	0x00002
#define TCL_GL_FUNC_LOADED		0x00004

typedef struct TclGLFunc {
    int funcGroupNo;
    int funcNo;
    int flags;
    Tcl_Obj *funcGroupNamePtr;
    Tcl_Obj *funcNamePtr;
    int returnType;
    int numParams;
    TclGLParam **funcParams;
    Tcl_Obj *usagePtr;
    GLfunction funcPtr;
} TclGLFunc;

typedef struct TclGLInfo {
    int version;
    int noGLGetError;
    Tcl_HashTable fbos;
    Tcl_HashTable defineGroups;
    Tcl_HashTable funcGroups;
    Tcl_HashTable typedefGroups;
    Tcl_HashTable glDefines;
    Tcl_HashTable glDefineStrings;
    Tcl_HashTable **defineGroupHashTables;
    Tcl_HashTable **funcGroupHashTables;
    Tcl_HashTable **typedefGroupHashTables;
    TclGLFunc **funcv;
} TclGLInfo;

#ifdef TCL_GL_DEBUG
MODULE_SCOPE int _tcl_gl_debug_level;
MODULE_SCOPE void TclGLShowArgs(int level, const char *str, int objc,
        Tcl_Obj * const* objv);
#else
#define TclGLShowArgs(a,b,c,d)
#endif

MODULE_SCOPE int TclGL_InitCommands(Tcl_Interp *interp, TclGLInfo *infoPtr);
MODULE_SCOPE int TclGLext_InitCommands(Tcl_Interp *interp, TclGLInfo *infoPtr);
