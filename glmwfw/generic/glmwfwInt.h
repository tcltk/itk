/*
 * glmwfwInt.h --
 *
 * This file contains internal definitions for the C-implemented part of a
 * a Tcl interface to the GLFW OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: glmwfwInt.h,v 1.1.2.3 2007/11/04 13:25:30 wiede Exp $
 */

#include <string.h>
#include <ctype.h>
#include <tcl.h>
#include <GL/gl.h>
#include "glmwfw.h"

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

#define GLMWFW_INTERP_DATA "glmwfw_data"
#define GLMWFW_INFO_VERSION 1

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

struct GlmwfwWindow;
struct GlmwfwInfo;

#define GLMWFW_STICK            2

/*
 *------------------------------------------------------------------------
 * User input status (most of this should go in _GLFWwin)
 *------------------------------------------------------------------------
 */

struct _GlmwfwPlatformInput;
struct _GlmwfwPlatformWindow;

typedef struct GlmwfwInput {
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
    struct _GlmwfwPlatformInput *platformInput;
} GlmwfwInput;

/*
 *------------------------------------------------------------------------
 * Window hints (set by glfwOpenWindowHint - will go into _GLFWthread)
 *------------------------------------------------------------------------
 */
typedef struct GlmwfwHints{
    int          RefreshRate;
    int          AccumRedBits;
    int          AccumGreenBits;
    int          AccumBlueBits;
    int          AccumAlphaBits;
    int          AuxBuffers;
    int          Stereo;
    int          WindowNoResize;
    int          Samples;
} GlmwfwHints;

/* Function pointer types */
typedef int (* glmwfwStringInExtensionStringT)(const char *, const GLubyte *);
typedef void (* glmwfwInputDeactivationT)(struct GlmwfwWindow *);
typedef int (* glmwfwCloseWindowT)(struct GlmwfwWindow *);
typedef void (* glmwfwInputKeyT)(struct GlmwfwWindow *, int, int);
typedef void (* glmwfwInputMouseClickT)(struct GlmwfwWindow *, int, int);

typedef void (* glmwfwwindowsizefun)(struct GlmwfwWindow *, int,int);
typedef int (* glmwfwwindowclosefun)(struct GlmwfwWindow *);
typedef void (* glmwfwwindowrefreshfun)(struct GlmwfwWindow *);
typedef void (* glmwfwmousebuttonfun)(struct GlmwfwWindow *, int,int);
typedef void (* glmwfwmouseposfun)(struct GlmwfwWindow *, int,int);
typedef void (* glmwfwmousewheelfun)(struct GlmwfwWindow *, int);
typedef void (* glmwfwkeyfun)(struct GlmwfwWindow *, int,int);
typedef void (* glmwfwcharfun)(struct GlmwfwWindow *, int,int);

typedef struct GlmwfwWindow {
    Tcl_Obj *handlePtr;
    Tcl_Obj *windowSizeCallback;
    glmwfwwindowsizefun windowsizefun;
    Tcl_Obj *windowCloseCallback;
    glmwfwwindowclosefun windowclosefun;
    Tcl_Obj *windowRefreshCallback;
    glmwfwwindowrefreshfun windowrefreshfun;
    Tcl_Obj *mouseButtonCallback;
    glmwfwmousebuttonfun mousebuttonfun;
    Tcl_Obj *mousePosCallback;
    glmwfwmouseposfun mouseposfun;
    Tcl_Obj *mouseWheelCallback;
    glmwfwmousewheelfun mousewheelfun;
    Tcl_Obj *keyCallback;
    glmwfwkeyfun keyfun;
    Tcl_Obj *charCallback;
    glmwfwkeyfun charfun;
    struct GlmwfwInfo *infoPtr;
    GlmwfwInput input;

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
    int       xRoot;           /* absolute x value of Window on display */
    int       yRoot;           /* absolute y value of Window on display */
    int       Accelerated;     /* GL_TRUE if window is HW accelerated */
    int       DepthBits;
    int       StencilBits;
    int       RedBits;
    int       GreenBits;
    int       BlueBits;
    int       AlphaBits;
    GlmwfwHints Hints;

    /* Extensions & OpenGL version */
    int       Has_GL_SGIS_generate_mipmap;
    int       Has_GL_ARB_texture_non_power_of_two;
    int       GLVerMajor;
    int       GLVerMinor;

    struct _GlmwfwPlatformWindow *platformWindow;
} GlmwfwWindow;

typedef struct GlmwfwInfo {
    int version;
    int numWindows;
    GlmwfwWindow *currWindow;
    Tcl_HashTable windows;
    Tcl_Interp *interp;
    GlmwfwHints hints;

    /* these are the functions which a called from the platform specific
     * packages. We need to have function pointers, so the platform specific
     * package can be loaded before the main package */
    glmwfwStringInExtensionStringT stringInExtensionString;
    glmwfwInputDeactivationT inputDeactivation;
    glmwfwCloseWindowT closeWindow;
    glmwfwInputKeyT inputKey;
    glmwfwInputMouseClickT inputMouseClick;
} GlmwfwInfo;

/* The video mode structure used by glfwGetVideoModes() */
typedef struct Glmwfwvidmode {
    int Width;
    int Height;
    int RedBits;
    int BlueBits;
    int GreenBits;
} Glmwfwvidmode;

#ifdef GLMWFW_DEBUG
MODULE_SCOPE int _tcl_glmwfw_debug_level;
MODULE_SCOPE void GlmwfwShowArgs(int level, const char *str, int objc,
        Tcl_Obj * const* objv);
#else
#define GlmwfwShowArgs(a,b,c,d)
#endif

MODULE_SCOPE int Glmwfw_InitCommands(Tcl_Interp *interp, GlmwfwInfo *infoPtr);
MODULE_SCOPE int GlmwfwKey2Define(const char *key);
MODULE_SCOPE int GlmwfwWindowParam2Define(const char *key);
MODULE_SCOPE int GlmwfwWindowHint2Define(const char *key);
MODULE_SCOPE int GlmwfwEnableParam2Define(const char *key);
MODULE_SCOPE Tcl_Obj * GlmwfwDefine2Key(int value);


/*
 *========================================================================
 * Prototypes
 *========================================================================
 */

/* GLMWFW initialization, termination and version querying */
MODULE_SCOPE int glmwfwInit(GlmwfwInfo *infoPtr);
MODULE_SCOPE int glmwfwTerminate(GlmwfwInfo *infoPtr);

/* Window handling */
MODULE_SCOPE GlmwfwWindow *glmwfwOpenWindow(GlmwfwInfo *infoPtr,
        int width, int height, int redbits, int greenbits, int bluebits,
        int alphabits, int depthbits, int stencilbits, int mode);
MODULE_SCOPE int glmwfwOpenWindowHint(GlmwfwWindow *winPtr, int target,
        int hint);
MODULE_SCOPE int glmwfwCloseWindow(GlmwfwWindow *winPtr);
MODULE_SCOPE int glmwfwSetWindowTitle(GlmwfwWindow *winPtr,
        const char *title);
MODULE_SCOPE int glmwfwGetWindowSize(GlmwfwWindow *winPtr, int *width,
        int *height);
MODULE_SCOPE int glmwfwSetWindowSize(GlmwfwWindow *winPtr, int width,
        int height);
MODULE_SCOPE int glmwfwSetWindowPos(GlmwfwWindow *winPtr, int x, int y);
MODULE_SCOPE int glmwfwIconifyWindow(GlmwfwWindow *winPtr);
MODULE_SCOPE int glmwfwRestoreWindow(GlmwfwWindow *winPtr);
MODULE_SCOPE int glmwfwSwapBuffers(GlmwfwWindow *winPtr);
MODULE_SCOPE int glmwfwSwapInterval(GlmwfwWindow *winPtr, int interval);
MODULE_SCOPE int glmwfwGetWindowParam(GlmwfwWindow *winPtr, int param);
MODULE_SCOPE int glmwfwSetWindowSizeCallback(GlmwfwWindow *winPtr,
        glmwfwwindowsizefun cbfun);
MODULE_SCOPE int glmwfwSetWindowCloseCallback(GlmwfwWindow *winPtr,
        glmwfwwindowclosefun cbfun);
MODULE_SCOPE int glmwfwSetWindowRefreshCallback(GlmwfwWindow *winPtr,
        glmwfwwindowrefreshfun cbfun);

/* Video mode functions */
MODULE_SCOPE int glmwfwGetVideoModes(GlmwfwInfo *infoPtr,
        Glmwfwvidmode *list, int maxcount);
MODULE_SCOPE int glmwfwGetDesktopMode(GlmwfwInfo *infoPtr,
        Glmwfwvidmode *mode);

/* Input handling */
MODULE_SCOPE int glmwfwPollEvents(GlmwfwWindow *winPtr);
MODULE_SCOPE int glmwfwWaitEvents(GlmwfwWindow *winPtr);
MODULE_SCOPE int glmwfwGetKey(GlmwfwWindow *winPtr, int key);
MODULE_SCOPE int glmwfwGetMouseButton(GlmwfwWindow *winPtr, int button);
MODULE_SCOPE int glmwfwGetMousePos(GlmwfwWindow *winPtr, int *xpos,
        int *ypos);
MODULE_SCOPE int glmwfwSetMousePos(GlmwfwWindow *winPtr,
        int xpos, int ypos);
MODULE_SCOPE int glmwfwGetMouseWheel(GlmwfwWindow *winPtr);
MODULE_SCOPE int glmwfwSetMouseWheel(GlmwfwWindow *winPtr, int pos);
MODULE_SCOPE int glmwfwSetKeyCallback(GlmwfwWindow *winPtr,
        glmwfwkeyfun cbfun);
MODULE_SCOPE int glmwfwSetCharCallback(GlmwfwWindow *winPtr,
        glmwfwcharfun cbfun);
MODULE_SCOPE int glmwfwSetMouseButtonCallback(GlmwfwWindow *winPtr,
        glmwfwmousebuttonfun cbfun);
MODULE_SCOPE int glmwfwSetMousePosCallback(GlmwfwWindow *winPtr,
        glmwfwmouseposfun cbfun);
MODULE_SCOPE int glmwfwSetMouseWheelCallback(GlmwfwWindow *winPtr,
        glmwfwmousewheelfun cbfun);

/* Joystick input */
MODULE_SCOPE int glmwfwGetJoystickParam(GlmwfwWindow *winPtr, int joy,
        int param);
MODULE_SCOPE int glmwfwGetJoystickPos(GlmwfwWindow *winPtr, int joy,
        float *pos, int numaxes);
MODULE_SCOPE int glmwfwGetJoystickButtons(GlmwfwWindow *winPtr, int joy,
        unsigned char *buttons, int numbuttons);

/* Time */
MODULE_SCOPE double glmwfwGetTime(GlmwfwInfo *infoPtr);
MODULE_SCOPE void glmwfwSetTime(GlmwfwInfo *infoPtr, double time);

/* Extension support */
MODULE_SCOPE int  glmwfwExtensionSupported(GlmwfwInfo *infoPtr,
        const char *extension);
MODULE_SCOPE void* glmwfwGetProcAddress(GlmwfwInfo *infoPtr,
        const char *procname);
MODULE_SCOPE void  glmwfwGetGLVersion(GlmwfwInfo *infoPtr, int *major,
        int *minor, int *rev);

/* Enable/disable functions */
MODULE_SCOPE int glmwfwEnable(GlmwfwWindow *winPtr, int token);
MODULE_SCOPE int glmwfwDisable(GlmwfwWindow *winPtr, int token);

MODULE_SCOPE void _glmwfwInputKey(GlmwfwWindow *winPtr, int key, int action);
MODULE_SCOPE void _glmwfwInputMouseClick(GlmwfwWindow *winPtr, int button,
        int action);
MODULE_SCOPE void _glmwfwInputDeactivation(GlmwfwWindow *winPtr);
MODULE_SCOPE int _glmwfwStringInExtensionString(const char *string,
        const GLubyte *extensions);
