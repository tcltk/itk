/*
 * glmwfwMaps.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the GLFW OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: glmwfwMaps.c,v 1.1.2.2 2007/11/24 19:06:30 wiede Exp $
 */

#include <stdlib.h>
#include "glmwfwInt.h"

typedef struct define2Key {
    const char *keyName;
    int keyDefine;
} define2Key;

define2Key keyMaps[] = {
    { "GLMWFW_KEY_SPACE", GLMWFW_KEY_SPACE},
    { "GLMWFW_KEY_ESC", GLMWFW_KEY_ESC},
    { "GLMWFW_KEY_F1", GLMWFW_KEY_F1},
    { "GLMWFW_KEY_F2", GLMWFW_KEY_F2},
    { "GLMWFW_KEY_F3", GLMWFW_KEY_F3},
    { "GLMWFW_KEY_F4", GLMWFW_KEY_F4},
    { "GLMWFW_KEY_F5", GLMWFW_KEY_F5},
    { "GLMWFW_KEY_F6", GLMWFW_KEY_F6},
    { "GLMWFW_KEY_F7", GLMWFW_KEY_F7},
    { "GLMWFW_KEY_F8", GLMWFW_KEY_F8},
    { "GLMWFW_KEY_F9", GLMWFW_KEY_F9},
    { "GLMWFW_KEY_F10", GLMWFW_KEY_F10},
    { "GLMWFW_KEY_F11", GLMWFW_KEY_F11},
    { "GLMWFW_KEY_F12", GLMWFW_KEY_F12},
    { "GLMWFW_KEY_F13", GLMWFW_KEY_F13},
    { "GLMWFW_KEY_F14", GLMWFW_KEY_F14},
    { "GLMWFW_KEY_F15", GLMWFW_KEY_F15},
    { "GLMWFW_KEY_F16", GLMWFW_KEY_F16},
    { "GLMWFW_KEY_F17", GLMWFW_KEY_F17},
    { "GLMWFW_KEY_F18", GLMWFW_KEY_F18},
    { "GLMWFW_KEY_F19", GLMWFW_KEY_F19},
    { "GLMWFW_KEY_F20", GLMWFW_KEY_F20},
    { "GLMWFW_KEY_F21", GLMWFW_KEY_F21},
    { "GLMWFW_KEY_F22", GLMWFW_KEY_F22},
    { "GLMWFW_KEY_F23", GLMWFW_KEY_F23},
    { "GLMWFW_KEY_F24", GLMWFW_KEY_F24},
    { "GLMWFW_KEY_F25", GLMWFW_KEY_F25},
    { "GLMWFW_KEY_UP", GLMWFW_KEY_UP},
    { "GLMWFW_KEY_DOWN", GLMWFW_KEY_DOWN},
    { "GLMWFW_KEY_LEFT", GLMWFW_KEY_LEFT},
    { "GLMWFW_KEY_RIGHT", GLMWFW_KEY_RIGHT},
    { "GLMWFW_KEY_LSHIFT", GLMWFW_KEY_LSHIFT},
    { "GLMWFW_KEY_RSHIFT", GLMWFW_KEY_RSHIFT},
    { "GLMWFW_KEY_LCTRL", GLMWFW_KEY_LCTRL},
    { "GLMWFW_KEY_RCTRL", GLMWFW_KEY_RCTRL},
    { "GLMWFW_KEY_LALT", GLMWFW_KEY_LALT},
    { "GLMWFW_KEY_RALT", GLMWFW_KEY_RALT},
    { "GLMWFW_KEY_TAB", GLMWFW_KEY_TAB},
    { "GLMWFW_KEY_ENTER", GLMWFW_KEY_ENTER},
    { "GLMWFW_KEY_BACKSPACE", GLMWFW_KEY_BACKSPACE},
    { "GLMWFW_KEY_INSERT", GLMWFW_KEY_INSERT},
    { "GLMWFW_KEY_DEL", GLMWFW_KEY_DEL},
    { "GLMWFW_KEY_PAGEUP", GLMWFW_KEY_PAGEUP},
    { "GLMWFW_KEY_PAGEDOWN", GLMWFW_KEY_PAGEDOWN},
    { "GLMWFW_KEY_HOME", GLMWFW_KEY_HOME},
    { "GLMWFW_KEY_END", GLMWFW_KEY_END},
    { "GLMWFW_KEY_KP_0", GLMWFW_KEY_KP_0},
    { "GLMWFW_KEY_KP_1", GLMWFW_KEY_KP_1},
    { "GLMWFW_KEY_KP_2", GLMWFW_KEY_KP_2},
    { "GLMWFW_KEY_KP_3", GLMWFW_KEY_KP_3},
    { "GLMWFW_KEY_KP_4", GLMWFW_KEY_KP_4},
    { "GLMWFW_KEY_KP_5", GLMWFW_KEY_KP_5},
    { "GLMWFW_KEY_KP_6", GLMWFW_KEY_KP_6},
    { "GLMWFW_KEY_KP_7", GLMWFW_KEY_KP_7},
    { "GLMWFW_KEY_KP_8", GLMWFW_KEY_KP_8},
    { "GLMWFW_KEY_KP_9", GLMWFW_KEY_KP_9},
    { "GLMWFW_KEY_KP_DIVIDE", GLMWFW_KEY_KP_DIVIDE},
    { "GLMWFW_KEY_KP_MULTIPLY", GLMWFW_KEY_KP_MULTIPLY},
    { "GLMWFW_KEY_KP_SUBTRACT", GLMWFW_KEY_KP_SUBTRACT},
    { "GLMWFW_KEY_KP_ADD", GLMWFW_KEY_KP_ADD},
    { "GLMWFW_KEY_KP_DECIMAL", GLMWFW_KEY_KP_DECIMAL},
    { "GLMWFW_KEY_KP_EQUAL", GLMWFW_KEY_KP_EQUAL},
    { "GLMWFW_KEY_KP_ENTER", GLMWFW_KEY_KP_ENTER},
    { "GLMWFW_KEY_ALTGR", GLMWFW_KEY_ALTGR},
    { NULL, 0}
};

// The following constants are used for both glmwfwGetWindowParam
// and glmwfwOpenWindowHint
define2Key windowHintMaps[] = {
    { "GLMWFW_REFRESH_RATE", GLMWFW_REFRESH_RATE},
    { "GLMWFW_ACCUM_RED_BITS", GLMWFW_ACCUM_RED_BITS},
    { "GLMWFW_ACCUM_GREEN_BITS", GLMWFW_ACCUM_GREEN_BITS},
    { "GLMWFW_ACCUM_BLUE_BITS", GLMWFW_ACCUM_BLUE_BITS},
    { "GLMWFW_ACCUM_ALPHA_BITS", GLMWFW_ACCUM_ALPHA_BITS},
    { "GLMWFW_AUX_BUFFERS", GLMWFW_AUX_BUFFERS},
    { "GLMWFW_STEREO", GLMWFW_STEREO},
    { "GLMWFW_WINDOW_NO_RESIZE", GLMWFW_WINDOW_NO_RESIZE},
    { "GLMWFW_FSAA_SAMPLES", GLMWFW_FSAA_SAMPLES},
    { NULL, 0}
};

// glmwfwGetWindowParam tokens
define2Key windowParamMaps[] = {
    { "GLMWFW_OPENED", GLMWFW_OPENED},
    { "GLMWFW_ACTIVE", GLMWFW_ACTIVE},
    { "GLMWFW_ICONIFIED", GLMWFW_ICONIFIED},
    { "GLMWFW_ACCELERATED", GLMWFW_ACCELERATED},
    { "GLMWFW_RED_BITS", GLMWFW_RED_BITS},
    { "GLMWFW_GREEN_BITS", GLMWFW_GREEN_BITS},
    { "GLMWFW_BLUE_BITS", GLMWFW_BLUE_BITS},
    { "GLMWFW_ALPHA_BITS", GLMWFW_ALPHA_BITS},
    { "GLMWFW_DEPTH_BITS", GLMWFW_DEPTH_BITS},
    { "GLMWFW_STENCIL_BITS", GLMWFW_STENCIL_BITS},
    { NULL, 0}
};

// glmwfwEnable/glmwfwDisable tokens
define2Key enableParamMaps[] = {
    { "GLMWFW_MOUSE_CURSOR", GLMWFW_MOUSE_CURSOR},
    { "GLMWFW_STICKY_KEYS", GLMWFW_STICKY_KEYS},
    { "GLMWFW_STICKY_MOUSE_BUTTONS", GLMWFW_STICKY_MOUSE_BUTTONS},
    { "GLMWFW_SYSTEM_KEYS", GLMWFW_SYSTEM_KEYS},
    { "GLMWFW_KEY_REPEAT", GLMWFW_KEY_REPEAT},
    { "GLMWFW_AUTO_POLL_EVENTS", GLMWFW_AUTO_POLL_EVENTS},
    { NULL, 0}
};


#ifdef NOTDEF
// Mouse button definitions
#define GLMWFW_MOUSE_BUTTON_1      0
#define GLMWFW_MOUSE_BUTTON_2      1
#define GLMWFW_MOUSE_BUTTON_3      2
#define GLMWFW_MOUSE_BUTTON_4      3
#define GLMWFW_MOUSE_BUTTON_5      4
#define GLMWFW_MOUSE_BUTTON_6      5
#define GLMWFW_MOUSE_BUTTON_7      6
#define GLMWFW_MOUSE_BUTTON_8      7
#define GLMWFW_MOUSE_BUTTON_LAST   GLMWFW_MOUSE_BUTTON_8

// Mouse button aliases
#define GLMWFW_MOUSE_BUTTON_LEFT   GLMWFW_MOUSE_BUTTON_1
#define GLMWFW_MOUSE_BUTTON_RIGHT  GLMWFW_MOUSE_BUTTON_2
#define GLMWFW_MOUSE_BUTTON_MIDDLE GLMWFW_MOUSE_BUTTON_3


// Joystick identifiers
#define GLMWFW_JOYSTICK_1          0
#define GLMWFW_JOYSTICK_2          1
#define GLMWFW_JOYSTICK_3          2
#define GLMWFW_JOYSTICK_4          3
#define GLMWFW_JOYSTICK_5          4
#define GLMWFW_JOYSTICK_6          5
#define GLMWFW_JOYSTICK_7          6
#define GLMWFW_JOYSTICK_8          7
#define GLMWFW_JOYSTICK_9          8
#define GLMWFW_JOYSTICK_10         9
#define GLMWFW_JOYSTICK_11         10
#define GLMWFW_JOYSTICK_12         11
#define GLMWFW_JOYSTICK_13         12
#define GLMWFW_JOYSTICK_14         13
#define GLMWFW_JOYSTICK_15         14
#define GLMWFW_JOYSTICK_16         15
#define GLMWFW_JOYSTICK_LAST       GLMWFW_JOYSTICK_16


//========================================================================
// Other definitions
//========================================================================

// glmwfwOpenWindow modes
#define GLMWFW_WINDOW               0x00010001
#define GLMWFW_FULLSCREEN           0x00010002


// glmwfwWaitThread wait modes
#define GLMWFW_WAIT                 0x00040001
#define GLMWFW_NOWAIT               0x00040002

// glmwfwGetJoystickParam tokens
#define GLMWFW_PRESENT              0x00050001
#define GLMWFW_AXES                 0x00050002
#define GLMWFW_BUTTONS              0x00050003

// glmwfwReadImage/glmwfwLoadTexture2D flags
#define GLMWFW_NO_RESCALE_BIT       0x00000001 // Only for glmwfwReadImage
#define GLMWFW_ORIGIN_UL_BIT        0x00000002
#define GLMWFW_BUILD_MIPMAPS_BIT    0x00000004 // Only for glmwfwLoadTexture2D
#define GLMWFW_ALPHA_MAP_BIT        0x00000008

// Time spans longer than this (seconds) are considered to be infinity
#define GLMWFW_INFINITY 100000.0


#endif 


int
GlmwfwKey2Define(
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
GlmwfwWindowParam2Define(
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
GlmwfwWindowHint2Define(
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
GlmwfwEnableParam2Define(
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
GlmwfwDefine2Key(
    int value)
{
    define2Key *key2DefinePtr;
    Tcl_Obj *objPtr;

    if (value < GLMWFW_KEY_ESC) {
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
