/*
 * tclGlfwMaps.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the GLFW OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGlfwMaps.c,v 1.1.2.2 2007/10/26 22:52:46 wiede Exp $
 */

#include <stdlib.h>
#include "tclGlfwInt.h"

typedef struct define2Key {
    const char *keyName;
    int keyDefine;
} define2Key;

define2Key keyMaps[] = {
    { "GLFW_KEY_SPACE", GLFW_KEY_SPACE},
    { "GLFW_KEY_ESC", GLFW_KEY_ESC},
    { "GLFW_KEY_F1", GLFW_KEY_F1},
    { "GLFW_KEY_F2", GLFW_KEY_F2},
    { "GLFW_KEY_F3", GLFW_KEY_F3},
    { "GLFW_KEY_F4", GLFW_KEY_F4},
    { "GLFW_KEY_F5", GLFW_KEY_F5},
    { "GLFW_KEY_F6", GLFW_KEY_F6},
    { "GLFW_KEY_F7", GLFW_KEY_F7},
    { "GLFW_KEY_F8", GLFW_KEY_F8},
    { "GLFW_KEY_F9", GLFW_KEY_F9},
    { "GLFW_KEY_F10", GLFW_KEY_F10},
    { "GLFW_KEY_F11", GLFW_KEY_F11},
    { "GLFW_KEY_F12", GLFW_KEY_F12},
    { "GLFW_KEY_F13", GLFW_KEY_F13},
    { "GLFW_KEY_F14", GLFW_KEY_F14},
    { "GLFW_KEY_F15", GLFW_KEY_F15},
    { "GLFW_KEY_F16", GLFW_KEY_F16},
    { "GLFW_KEY_F17", GLFW_KEY_F17},
    { "GLFW_KEY_F18", GLFW_KEY_F18},
    { "GLFW_KEY_F19", GLFW_KEY_F19},
    { "GLFW_KEY_F20", GLFW_KEY_F20},
    { "GLFW_KEY_F21", GLFW_KEY_F21},
    { "GLFW_KEY_F22", GLFW_KEY_F22},
    { "GLFW_KEY_F23", GLFW_KEY_F23},
    { "GLFW_KEY_F24", GLFW_KEY_F24},
    { "GLFW_KEY_F25", GLFW_KEY_F25},
    { "GLFW_KEY_UP", GLFW_KEY_UP},
    { "GLFW_KEY_DOWN", GLFW_KEY_DOWN},
    { "GLFW_KEY_LEFT", GLFW_KEY_LEFT},
    { "GLFW_KEY_RIGHT", GLFW_KEY_RIGHT},
    { "GLFW_KEY_LSHIFT", GLFW_KEY_LSHIFT},
    { "GLFW_KEY_RSHIFT", GLFW_KEY_RSHIFT},
    { "GLFW_KEY_LCTRL", GLFW_KEY_LCTRL},
    { "GLFW_KEY_RCTRL", GLFW_KEY_RCTRL},
    { "GLFW_KEY_LALT", GLFW_KEY_LALT},
    { "GLFW_KEY_RALT", GLFW_KEY_RALT},
    { "GLFW_KEY_TAB", GLFW_KEY_TAB},
    { "GLFW_KEY_ENTER", GLFW_KEY_ENTER},
    { "GLFW_KEY_BACKSPACE", GLFW_KEY_BACKSPACE},
    { "GLFW_KEY_INSERT", GLFW_KEY_INSERT},
    { "GLFW_KEY_DEL", GLFW_KEY_DEL},
    { "GLFW_KEY_PAGEUP", GLFW_KEY_PAGEUP},
    { "GLFW_KEY_PAGEDOWN", GLFW_KEY_PAGEDOWN},
    { "GLFW_KEY_HOME", GLFW_KEY_HOME},
    { "GLFW_KEY_END", GLFW_KEY_END},
    { "GLFW_KEY_KP_0", GLFW_KEY_KP_0},
    { "GLFW_KEY_KP_1", GLFW_KEY_KP_1},
    { "GLFW_KEY_KP_2", GLFW_KEY_KP_2},
    { "GLFW_KEY_KP_3", GLFW_KEY_KP_3},
    { "GLFW_KEY_KP_4", GLFW_KEY_KP_4},
    { "GLFW_KEY_KP_5", GLFW_KEY_KP_5},
    { "GLFW_KEY_KP_6", GLFW_KEY_KP_6},
    { "GLFW_KEY_KP_7", GLFW_KEY_KP_7},
    { "GLFW_KEY_KP_8", GLFW_KEY_KP_8},
    { "GLFW_KEY_KP_9", GLFW_KEY_KP_9},
    { "GLFW_KEY_KP_DIVIDE", GLFW_KEY_KP_DIVIDE},
    { "GLFW_KEY_KP_MULTIPLY", GLFW_KEY_KP_MULTIPLY},
    { "GLFW_KEY_KP_SUBTRACT", GLFW_KEY_KP_SUBTRACT},
    { "GLFW_KEY_KP_ADD", GLFW_KEY_KP_ADD},
    { "GLFW_KEY_KP_DECIMAL", GLFW_KEY_KP_DECIMAL},
    { "GLFW_KEY_KP_EQUAL", GLFW_KEY_KP_EQUAL},
    { "GLFW_KEY_KP_ENTER", GLFW_KEY_KP_ENTER},
    { "GLFW_KEY_LAST", GLFW_KEY_LAST},
    { NULL, 0}
};

// The following constants are used for both glfwGetWindowParam
// and glfwOpenWindowHint
define2Key windowHintMaps[] = {
    { "GLFW_REFRESH_RATE", GLFW_REFRESH_RATE},
    { "GLFW_ACCUM_RED_BITS", GLFW_ACCUM_RED_BITS},
    { "GLFW_ACCUM_GREEN_BITS", GLFW_ACCUM_GREEN_BITS},
    { "GLFW_ACCUM_BLUE_BITS", GLFW_ACCUM_BLUE_BITS},
    { "GLFW_ACCUM_ALPHA_BITS", GLFW_ACCUM_ALPHA_BITS},
    { "GLFW_AUX_BUFFERS", GLFW_AUX_BUFFERS},
    { "GLFW_STEREO", GLFW_STEREO},
    { "GLFW_WINDOW_NO_RESIZE", GLFW_WINDOW_NO_RESIZE},
    { "GLFW_FSAA_SAMPLES", GLFW_FSAA_SAMPLES},
    { NULL, 0}
};

// glfwGetWindowParam tokens
define2Key windowParamMaps[] = {
    { "GLFW_OPENED", GLFW_OPENED},
    { "GLFW_ACTIVE", GLFW_ACTIVE},
    { "GLFW_ICONIFIED", GLFW_ICONIFIED},
    { "GLFW_ACCELERATED", GLFW_ACCELERATED},
    { "GLFW_RED_BITS", GLFW_RED_BITS},
    { "GLFW_GREEN_BITS", GLFW_GREEN_BITS},
    { "GLFW_BLUE_BITS", GLFW_BLUE_BITS},
    { "GLFW_ALPHA_BITS", GLFW_ALPHA_BITS},
    { "GLFW_DEPTH_BITS", GLFW_DEPTH_BITS},
    { "GLFW_STENCIL_BITS", GLFW_STENCIL_BITS},
    { NULL, 0}
};

// glfwEnable/glfwDisable tokens
define2Key enableParamMaps[] = {
    { "GLFW_MOUSE_CURSOR", GLFW_MOUSE_CURSOR},
    { "GLFW_STICKY_KEYS", GLFW_STICKY_KEYS},
    { "GLFW_STICKY_MOUSE_BUTTONS", GLFW_STICKY_MOUSE_BUTTONS},
    { "GLFW_SYSTEM_KEYS", GLFW_SYSTEM_KEYS},
    { "GLFW_KEY_REPEAT", GLFW_KEY_REPEAT},
    { "GLFW_AUTO_POLL_EVENTS", GLFW_AUTO_POLL_EVENTS},
    { NULL, 0}
};


#ifdef NOTDEF
// Mouse button definitions
#define GLFW_MOUSE_BUTTON_1      0
#define GLFW_MOUSE_BUTTON_2      1
#define GLFW_MOUSE_BUTTON_3      2
#define GLFW_MOUSE_BUTTON_4      3
#define GLFW_MOUSE_BUTTON_5      4
#define GLFW_MOUSE_BUTTON_6      5
#define GLFW_MOUSE_BUTTON_7      6
#define GLFW_MOUSE_BUTTON_8      7
#define GLFW_MOUSE_BUTTON_LAST   GLFW_MOUSE_BUTTON_8

// Mouse button aliases
#define GLFW_MOUSE_BUTTON_LEFT   GLFW_MOUSE_BUTTON_1
#define GLFW_MOUSE_BUTTON_RIGHT  GLFW_MOUSE_BUTTON_2
#define GLFW_MOUSE_BUTTON_MIDDLE GLFW_MOUSE_BUTTON_3


// Joystick identifiers
#define GLFW_JOYSTICK_1          0
#define GLFW_JOYSTICK_2          1
#define GLFW_JOYSTICK_3          2
#define GLFW_JOYSTICK_4          3
#define GLFW_JOYSTICK_5          4
#define GLFW_JOYSTICK_6          5
#define GLFW_JOYSTICK_7          6
#define GLFW_JOYSTICK_8          7
#define GLFW_JOYSTICK_9          8
#define GLFW_JOYSTICK_10         9
#define GLFW_JOYSTICK_11         10
#define GLFW_JOYSTICK_12         11
#define GLFW_JOYSTICK_13         12
#define GLFW_JOYSTICK_14         13
#define GLFW_JOYSTICK_15         14
#define GLFW_JOYSTICK_16         15
#define GLFW_JOYSTICK_LAST       GLFW_JOYSTICK_16


//========================================================================
// Other definitions
//========================================================================

// glfwOpenWindow modes
#define GLFW_WINDOW               0x00010001
#define GLFW_FULLSCREEN           0x00010002


// glfwWaitThread wait modes
#define GLFW_WAIT                 0x00040001
#define GLFW_NOWAIT               0x00040002

// glfwGetJoystickParam tokens
#define GLFW_PRESENT              0x00050001
#define GLFW_AXES                 0x00050002
#define GLFW_BUTTONS              0x00050003

// glfwReadImage/glfwLoadTexture2D flags
#define GLFW_NO_RESCALE_BIT       0x00000001 // Only for glfwReadImage
#define GLFW_ORIGIN_UL_BIT        0x00000002
#define GLFW_BUILD_MIPMAPS_BIT    0x00000004 // Only for glfwLoadTexture2D
#define GLFW_ALPHA_MAP_BIT        0x00000008

// Time spans longer than this (seconds) are considered to be infinity
#define GLFW_INFINITY 100000.0


#endif 


int
TclGlfwKey2Define(
    const char *key)
{
    define2Key *define2KeyPtr;

    define2KeyPtr = keyMaps;
    while (define2KeyPtr->keyName != NULL) {
        if (strcmp(define2KeyPtr->keyName, key) == 0) {
	    return define2KeyPtr->keyDefine;
        }
        define2KeyPtr++;
    }
    return -1;
}

int
TclGlfwWindowParam2Define(
    const char *key)
{
    define2Key *windowParam2DefinePtr;

    windowParam2DefinePtr = windowParamMaps;
    while (windowParam2DefinePtr->keyName != NULL) {
        if (strcmp(windowParam2DefinePtr->keyName, key) == 0) {
	    return windowParam2DefinePtr->keyDefine;
        }
        windowParam2DefinePtr++;
    }
    return -1;
}

int
TclGlfwWindowHint2Define(
    const char *key)
{
    define2Key *windowHint2DefinePtr;

    windowHint2DefinePtr = windowHintMaps;
    while (windowHint2DefinePtr->keyName != NULL) {
        if (strcmp(windowHint2DefinePtr->keyName, key) == 0) {
	    return windowHint2DefinePtr->keyDefine;
        }
        windowHint2DefinePtr++;
    }
    return -1;
}

int
TclGlfwEnableParam2Define(
    const char *key)
{
    define2Key *enableParam2DefinePtr;

    enableParam2DefinePtr = enableParamMaps;
    while (enableParam2DefinePtr->keyName != NULL) {
        if (strcmp(enableParam2DefinePtr->keyName, key) == 0) {
	    return enableParam2DefinePtr->keyDefine;
        }
        enableParam2DefinePtr++;
    }
    return -1;
}

Tcl_Obj *
TclGlfwDefine2Key(
    int value)
{
    define2Key *key2DefinePtr;
    Tcl_Obj *objPtr;

    if (value < GLFW_KEY_ESC) {
	char buf[10];

	sprintf(buf, "%c", value);
        objPtr = Tcl_NewStringObj(buf, -1);
        Tcl_IncrRefCount(objPtr);
        return objPtr;
    }
    key2DefinePtr = keyMaps;
    while (key2DefinePtr->keyName != NULL) {
        if (key2DefinePtr->keyDefine == value) {
            objPtr = Tcl_NewStringObj(key2DefinePtr->keyName, -1);
            Tcl_IncrRefCount(objPtr);
	    return objPtr;
        }
        key2DefinePtr++;
    }
    return NULL;
}
