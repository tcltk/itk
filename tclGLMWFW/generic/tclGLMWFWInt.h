/*
 * tclGLMWFWInt.h --
 *
 * This file contains internal definitions for the C-implemented part of a
 * a Tcl interface to the GLMWFW OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLMWFWInt.h,v 1.1.2.2 2007/11/01 15:09:25 wiede Exp $
 */

#include <string.h>
#include <ctype.h>
#include <tcl.h>
#include <GL/gl.h>
#include "tclGLMWFW.h"

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

#define TCL_GLMWFW_INTERP_DATA "tclGLMWFW_data"
#define TCL_GLMWFW_INFO_VERSION 1

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

#define WINDOW_ALLOC 20

struct GLMWFWWindow;
struct TclGLMWFWInfo;

#define GLMWFW_STICK            2

/*
 *------------------------------------------------------------------------
 * User input status (most of this should go in _GLFWwin)
 *------------------------------------------------------------------------
 */

struct GLMWFWplatformInput;

typedef struct GLMWFWInput {
    /* Mouse status */
    int MousePosX;
    int MousePosY;
    int WheelPos;
    char MouseButton[GLMWFW_MOUSE_BUTTON_LAST+1];

    /* Keyboard status */
    char Key[GLMWFW_KEY_LAST+1];
    int  LastChar;

    /* User selected settings */
    int  StickyKeys;
    int  StickyMouseButtons;
    int  KeyRepeat;
    struct GLMWFWplatformInput *platformInput;
} GLMWFWInput;

/*
 *------------------------------------------------------------------------
 * Window hints (set by glfwOpenWindowHint - will go into _GLFWthread)
 *------------------------------------------------------------------------
 */
typedef struct GLMWFWHints{
    int          RefreshRate;
    int          AccumRedBits;
    int          AccumGreenBits;
    int          AccumBlueBits;
    int          AccumAlphaBits;
    int          AuxBuffers;
    int          Stereo;
    int          WindowNoResize;
    int          Samples;
} GLMWFWHints;

/* Function pointer types */
typedef void (* GLMWFWwindowsizefun)(struct GLMWFWWindow *winPtr, int,int);
typedef int  (* GLMWFWwindowclosefun)(struct GLMWFWWindow *winPtr);
typedef void (* GLMWFWwindowrefreshfun)(struct GLMWFWWindow *winPtr);
typedef void (* GLMWFWmousebuttonfun)(struct GLMWFWWindow *winPtr, int,int);
typedef void (* GLMWFWmouseposfun)(struct GLMWFWWindow *winPtr, int,int);
typedef void (* GLMWFWmousewheelfun)(struct GLMWFWWindow *winPtr, int);
typedef void (* GLMWFWkeyfun)(struct GLMWFWWindow *winPtr, int,int);
typedef void (* GLMWFWcharfun)(struct GLMWFWWindow *winPtr, int,int);

typedef struct GLMWFWWindow {
    Tcl_Obj *handlePtr;
    Tcl_Obj *windowSizeCallback;
    GLMWFWwindowsizefun windowsizefun;
    Tcl_Obj *windowCloseCallback;
    GLMWFWwindowclosefun windowclosefun;
    Tcl_Obj *windowRefreshCallback;
    GLMWFWwindowrefreshfun windowrefreshfun;
    Tcl_Obj *mouseButtonCallback;
    GLMWFWmousebuttonfun mousebuttonfun;
    Tcl_Obj *mousePosCallback;
    GLMWFWmouseposfun mouseposfun;
    Tcl_Obj *mouseWheelCallback;
    GLMWFWmousewheelfun mousewheelfun;
    Tcl_Obj *keyCallback;
    GLMWFWkeyfun keyfun;
    Tcl_Obj *charCallback;
    GLMWFWkeyfun charfun;
    struct TclGLMWFWInfo *infoPtr;
    GLMWFWInput input;

    /* User selected window settings */
    int       Fullscreen;      /* Fullscreen flag */
    int       MouseLock;       /* Mouse-lock flag */
    int       AutoPollEvents;  /* Auto polling flag */
    int       SysKeysDisabled; /* System keys disabled flag */
    int       WindowNoResize;  /* Resize- and maximize gadgets disabled flag */

    /* Window status & parameters */
    int       Opened;          /* Flag telling if window is opened or not */
    int       Active;          /* Application active flag */
    int       Iconified;       /* Window iconified flag */
    int       Width;           /* Window width */
    int       Height;          /* Window heigth */
    int       Accelerated;     /* GL_TRUE if window is HW accelerated */
    int       DepthBits;
    int       StencilBits;
    int       RedBits;
    int       GreenBits;
    int       BlueBits;
    int       AlphaBits;
    GLMWFWHints hints;

    /* Extensions & OpenGL version */
    int       Has_GL_SGIS_generate_mipmap;
    int       Has_GL_ARB_texture_non_power_of_two;
    int       GLVerMajor,GLVerMinor;


} GLMWFWWindow;

typedef struct TclGLMWFWInfo {
    int version;
    int numWindows;
    GLMWFWWindow *currWindow;
    Tcl_HashTable windows;
    Tcl_Interp *interp;
    GLMWFWHints hints;
} TclGLMWFWInfo;

/* The video mode structure used by glfwGetVideoModes() */
typedef struct GLMWFWvidmode {
    int Width;
    int Height;
    int RedBits;
    int BlueBits;
    int GreenBits;
} GLMWFWvidmode;

#ifdef TCL_GLMWFW_DEBUG
MODULE_SCOPE int _tcl_glmwfw_debug_level;
MODULE_SCOPE void TclGLMWFWShowArgs(int level, const char *str, int objc,
        Tcl_Obj * const* objv);
#else
#define TclGLMWFWShowArgs(a,b,c,d)
#endif

MODULE_SCOPE int TclGLMWFW_InitCommands(Tcl_Interp *interp, TclGLMWFWInfo *infoPtr);
MODULE_SCOPE void TclShowArgs();
MODULE_SCOPE int TclGLMWFWKey2Define(const char *key);
MODULE_SCOPE int TclGLMWFWWindowParam2Define(const char *key);
MODULE_SCOPE int TclGLMWFWWindowHint2Define(const char *key);
MODULE_SCOPE int TclGLMWFWEnableParam2Define(const char *key);
MODULE_SCOPE Tcl_Obj * TclGLMWFWDefine2Key(int value);


/*
 *========================================================================
 * Prototypes
 *========================================================================
 */

/* GLMWFW initialization, termination and version querying */
MODULE_SCOPE int   glmwfwInit(void);
MODULE_SCOPE void  glmwfwTerminate(void);

/* Window handling */
MODULE_SCOPE GLMWFWWindow *glmwfwOpenWindow(TclGLMWFWInfo *infoPtr,
        int width, int height, int redbits, int greenbits, int bluebits,
        int alphabits, int depthbits, int stencilbits, int mode);
MODULE_SCOPE int glmwfwOpenWindowHint(GLMWFWWindow *winPtr, int target,
        int hint);
MODULE_SCOPE int glmwfwCloseWindow(GLMWFWWindow *winPtr);
MODULE_SCOPE int glmwfwSetWindowTitle(GLMWFWWindow *winPtr,
        const char *title);
MODULE_SCOPE int glmwfwGetWindowSize(GLMWFWWindow *winPtr, int *width,
        int *height);
MODULE_SCOPE int glmwfwSetWindowSize(GLMWFWWindow *winPtr, int width,
        int height);
MODULE_SCOPE int glmwfwSetWindowPos(GLMWFWWindow *winPtr, int x, int y);
MODULE_SCOPE int glmwfwIconifyWindow(GLMWFWWindow *winPtr);
MODULE_SCOPE int glmwfwRestoreWindow(GLMWFWWindow *winPtr);
MODULE_SCOPE int glmwfwSwapBuffers(GLMWFWWindow *winPtr);
MODULE_SCOPE int glmwfwSwapInterval(GLMWFWWindow *winPtr, int interval);
MODULE_SCOPE int glmwfwGetWindowParam(GLMWFWWindow *winPtr, int param);
MODULE_SCOPE int glmwfwSetWindowSizeCallback(GLMWFWWindow *winPtr,
        GLMWFWwindowsizefun cbfun);
MODULE_SCOPE int glmwfwSetWindowCloseCallback(GLMWFWWindow *winPtr,
        GLMWFWwindowclosefun cbfun);
MODULE_SCOPE int glmwfwSetWindowRefreshCallback(GLMWFWWindow *winPtr,
        GLMWFWwindowrefreshfun cbfun);

/* Video mode functions */
MODULE_SCOPE int   glmwfwGetVideoModes(TclGLMWFWInfo *infoPtr,
        GLMWFWvidmode *list, int maxcount);
MODULE_SCOPE void  glmwfwGetDesktopMode(TclGLMWFWInfo *infoPtr,
        GLMWFWvidmode *mode);

/* Input handling */
MODULE_SCOPE int  glmwfwPollEvents(GLMWFWWindow *winPtr);
MODULE_SCOPE int  glmwfwWaitEvents(GLMWFWWindow *winPtr);
MODULE_SCOPE int   glmwfwGetKey(GLMWFWWindow *winPtr, int key);
MODULE_SCOPE int   glmwfwGetMouseButton(GLMWFWWindow *winPtr, int button);
MODULE_SCOPE void  glmwfwGetMousePos(GLMWFWWindow *winPtr, int *xpos,
        int *ypos);
MODULE_SCOPE void  glmwfwSetMousePos(GLMWFWWindow *winPtr,
        int xpos, int ypos);
MODULE_SCOPE int   glmwfwGetMouseWheel(GLMWFWWindow *winPtr);
MODULE_SCOPE void  glmwfwSetMouseWheel(GLMWFWWindow *winPtr, int pos);
MODULE_SCOPE void  glmwfwSetKeyCallback(GLMWFWWindow *winPtr,
        GLMWFWkeyfun cbfun);
MODULE_SCOPE void  glmwfwSetCharCallback(GLMWFWWindow *winPtr,
        GLMWFWcharfun cbfun);
MODULE_SCOPE void  glmwfwSetMouseButtonCallback(GLMWFWWindow *winPtr,
        GLMWFWmousebuttonfun cbfun);
MODULE_SCOPE void  glmwfwSetMousePosCallback(GLMWFWWindow *winPtr,
        GLMWFWmouseposfun cbfun);
MODULE_SCOPE void  glmwfwSetMouseWheelCallback(GLMWFWWindow *winPtr,
        GLMWFWmousewheelfun cbfun);

/* Joystick input */
MODULE_SCOPE int  glmwfwGetJoystickParam(GLMWFWWindow *winPtr, int joy,
        int param);
MODULE_SCOPE int  glmwfwGetJoystickPos(GLMWFWWindow *winPtr, int joy,
        float *pos, int numaxes);
MODULE_SCOPE int  glmwfwGetJoystickButtons(GLMWFWWindow *winPtr, int joy,
        unsigned char *buttons, int numbuttons);

/* Time */
MODULE_SCOPE double  glmwfwGetTime(void);
MODULE_SCOPE void    glmwfwSetTime(double time);
MODULE_SCOPE void    glmwfwSleep(double time);

/* Extension support */
MODULE_SCOPE int    glmwfwExtensionSupported(TclGLMWFWInfo *infoPtr,
        const char *extension);
MODULE_SCOPE void*  glmwfwGetProcAddress(TclGLMWFWInfo *infoPtr,
        const char *procname);
MODULE_SCOPE void   glmwfwGetGLVersion(TclGLMWFWInfo *infoPtr, int *major,
        int *minor, int *rev);

/* Enable/disable functions */
MODULE_SCOPE void  glmwfwEnable(GLMWFWWindow *winPtr, int token);
MODULE_SCOPE void  glmwfwDisable(GLMWFWWindow *winPtr, int token);

MODULE_SCOPE void _glmwfwInputKey(GLMWFWWindow *winPtr, int key, int action);
MODULE_SCOPE void _glmwfwInputMouseClick(GLMWFWWindow *winPtr, int button,
        int action);
