/*
 * tclGLMWFW.h --
 *
 * This file contains definitions for the C-implemeted part of a Tcl
 * interface to the GLMWFW OpenGL library
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tclGLMWFW.h,v 1.1.2.1 2007/11/01 14:05:13 wiede Exp $
 */

/*
 * ------------------------------------------------------------------------
 *      PACKAGE:  tclGLMWFW
 *  DESCRIPTION:  Tcl interface to the GLMWFW OpenGL library
 * ------------------------------------------------------------------------
 */

#ifndef TCL_GLMWFW_H_INCLUDED
#define TCL_GLMWFW_H_INCLUDED

#include <string.h>
#include <ctype.h>
#include "tcl.h"

#ifndef TCL_ALPHA_RELEASE
#   define TCL_ALPHA_RELEASE    0
#endif
#ifndef TCL_BETA_RELEASE
#   define TCL_BETA_RELEASE     1
#endif
#ifndef TCL_FINAL_RELEASE
#   define TCL_FINAL_RELEASE    2
#endif

#define TCL_GLMWFW_MAJOR_VERSION      0
#define TCL_GLMWFW_MINOR_VERSION      1
#define TCL_GLMWFW_RELEASE_LEVEL      TCL_ALPHA_RELEASE
#define TCL_GLMWFW_RELEASE_SERIAL     0

#define TCL_GLMWFW_VERSION            "0.1"
#define TCL_GLMWFW_PATCH_LEVEL        "0.1.0.0"
#define TCL_GLMWFW_NAMESPACE          "::ntk::glmwfw"

//========================================================================
// Input handling definitions
//========================================================================

// Key and button state/action definitions
#define GLMWFW_RELEASE            0
#define GLMWFW_PRESS              1

// Keyboard key definitions: utf-8 encoding is used
// for printable keys (such as A-Z, 0-9 etc), and values above 0x10000
// represent special (non-printable) keys (e.g. F1, Page Up etc).
#define GLMWFW_KEY_UNKNOWN      -1
#define GLMWFW_KEY_SPACE        32
#define GLMWFW_KEY_SPECIAL      0x10000
#define GLMWFW_KEY_ESC          (GLMWFW_KEY_SPECIAL+1)
#define GLMWFW_KEY_F1           (GLMWFW_KEY_SPECIAL+2)
#define GLMWFW_KEY_F2           (GLMWFW_KEY_SPECIAL+3)
#define GLMWFW_KEY_F3           (GLMWFW_KEY_SPECIAL+4)
#define GLMWFW_KEY_F4           (GLMWFW_KEY_SPECIAL+5)
#define GLMWFW_KEY_F5           (GLMWFW_KEY_SPECIAL+6)
#define GLMWFW_KEY_F6           (GLMWFW_KEY_SPECIAL+7)
#define GLMWFW_KEY_F7           (GLMWFW_KEY_SPECIAL+8)
#define GLMWFW_KEY_F8           (GLMWFW_KEY_SPECIAL+9)
#define GLMWFW_KEY_F9           (GLMWFW_KEY_SPECIAL+10)
#define GLMWFW_KEY_F10          (GLMWFW_KEY_SPECIAL+11)
#define GLMWFW_KEY_F11          (GLMWFW_KEY_SPECIAL+12)
#define GLMWFW_KEY_F12          (GLMWFW_KEY_SPECIAL+13)
#define GLMWFW_KEY_F13          (GLMWFW_KEY_SPECIAL+14)
#define GLMWFW_KEY_F14          (GLMWFW_KEY_SPECIAL+15)
#define GLMWFW_KEY_F15          (GLMWFW_KEY_SPECIAL+16)
#define GLMWFW_KEY_F16          (GLMWFW_KEY_SPECIAL+17)
#define GLMWFW_KEY_F17          (GLMWFW_KEY_SPECIAL+18)
#define GLMWFW_KEY_F18          (GLMWFW_KEY_SPECIAL+19)
#define GLMWFW_KEY_F19          (GLMWFW_KEY_SPECIAL+20)
#define GLMWFW_KEY_F20          (GLMWFW_KEY_SPECIAL+21)
#define GLMWFW_KEY_F21          (GLMWFW_KEY_SPECIAL+22)
#define GLMWFW_KEY_F22          (GLMWFW_KEY_SPECIAL+23)
#define GLMWFW_KEY_F23          (GLMWFW_KEY_SPECIAL+24)
#define GLMWFW_KEY_F24          (GLMWFW_KEY_SPECIAL+25)
#define GLMWFW_KEY_F25          (GLMWFW_KEY_SPECIAL+26)
#define GLMWFW_KEY_UP           (GLMWFW_KEY_SPECIAL+27)
#define GLMWFW_KEY_DOWN         (GLMWFW_KEY_SPECIAL+28)
#define GLMWFW_KEY_LEFT         (GLMWFW_KEY_SPECIAL+29)
#define GLMWFW_KEY_RIGHT        (GLMWFW_KEY_SPECIAL+30)
#define GLMWFW_KEY_LSHIFT       (GLMWFW_KEY_SPECIAL+31)
#define GLMWFW_KEY_RSHIFT       (GLMWFW_KEY_SPECIAL+32)
#define GLMWFW_KEY_LCTRL        (GLMWFW_KEY_SPECIAL+33)
#define GLMWFW_KEY_RCTRL        (GLMWFW_KEY_SPECIAL+34)
#define GLMWFW_KEY_LALT         (GLMWFW_KEY_SPECIAL+35)
#define GLMWFW_KEY_RALT         (GLMWFW_KEY_SPECIAL+36)
#define GLMWFW_KEY_TAB          (GLMWFW_KEY_SPECIAL+37)
#define GLMWFW_KEY_ENTER        (GLMWFW_KEY_SPECIAL+38)
#define GLMWFW_KEY_BACKSPACE    (GLMWFW_KEY_SPECIAL+39)
#define GLMWFW_KEY_INSERT       (GLMWFW_KEY_SPECIAL+40)
#define GLMWFW_KEY_DEL          (GLMWFW_KEY_SPECIAL+41)
#define GLMWFW_KEY_PAGEUP       (GLMWFW_KEY_SPECIAL+42)
#define GLMWFW_KEY_PAGEDOWN     (GLMWFW_KEY_SPECIAL+43)
#define GLMWFW_KEY_HOME         (GLMWFW_KEY_SPECIAL+44)
#define GLMWFW_KEY_END          (GLMWFW_KEY_SPECIAL+45)
#define GLMWFW_KEY_KP_0         (GLMWFW_KEY_SPECIAL+46)
#define GLMWFW_KEY_KP_1         (GLMWFW_KEY_SPECIAL+47)
#define GLMWFW_KEY_KP_2         (GLMWFW_KEY_SPECIAL+48)
#define GLMWFW_KEY_KP_3         (GLMWFW_KEY_SPECIAL+49)
#define GLMWFW_KEY_KP_4         (GLMWFW_KEY_SPECIAL+50)
#define GLMWFW_KEY_KP_5         (GLMWFW_KEY_SPECIAL+51)
#define GLMWFW_KEY_KP_6         (GLMWFW_KEY_SPECIAL+52)
#define GLMWFW_KEY_KP_7         (GLMWFW_KEY_SPECIAL+53)
#define GLMWFW_KEY_KP_8         (GLMWFW_KEY_SPECIAL+54)
#define GLMWFW_KEY_KP_9         (GLMWFW_KEY_SPECIAL+55)
#define GLMWFW_KEY_KP_DIVIDE    (GLMWFW_KEY_SPECIAL+56)
#define GLMWFW_KEY_KP_MULTIPLY  (GLMWFW_KEY_SPECIAL+57)
#define GLMWFW_KEY_KP_SUBTRACT  (GLMWFW_KEY_SPECIAL+58)
#define GLMWFW_KEY_KP_ADD       (GLMWFW_KEY_SPECIAL+59)
#define GLMWFW_KEY_KP_DECIMAL   (GLMWFW_KEY_SPECIAL+60)
#define GLMWFW_KEY_KP_EQUAL     (GLMWFW_KEY_SPECIAL+61)
#define GLMWFW_KEY_KP_ENTER     (GLMWFW_KEY_SPECIAL+62)
#define GLMWFW_KEY_LAST         GLMWFW_KEY_KP_ENTER

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

// glmwfwGetWindowParam tokens
#define GLMWFW_OPENED               0x00020001
#define GLMWFW_ACTIVE               0x00020002
#define GLMWFW_ICONIFIED            0x00020003
#define GLMWFW_ACCELERATED          0x00020004
#define GLMWFW_RED_BITS             0x00020005
#define GLMWFW_GREEN_BITS           0x00020006
#define GLMWFW_BLUE_BITS            0x00020007
#define GLMWFW_ALPHA_BITS           0x00020008
#define GLMWFW_DEPTH_BITS           0x00020009
#define GLMWFW_STENCIL_BITS         0x0002000A

// The following constants are used for both glmwfwGetWindowParam
// and glmwfwOpenWindowHint
#define GLMWFW_REFRESH_RATE         0x0002000B
#define GLMWFW_ACCUM_RED_BITS       0x0002000C
#define GLMWFW_ACCUM_GREEN_BITS     0x0002000D
#define GLMWFW_ACCUM_BLUE_BITS      0x0002000E
#define GLMWFW_ACCUM_ALPHA_BITS     0x0002000F
#define GLMWFW_AUX_BUFFERS          0x00020010
#define GLMWFW_STEREO               0x00020011
#define GLMWFW_WINDOW_NO_RESIZE     0x00020012
#define GLMWFW_FSAA_SAMPLES         0x00020013

// glmwfwEnable/glmwfwDisable tokens
#define GLMWFW_MOUSE_CURSOR         0x00030001
#define GLMWFW_STICKY_KEYS          0x00030002
#define GLMWFW_STICKY_MOUSE_BUTTONS 0x00030003
#define GLMWFW_SYSTEM_KEYS          0x00030004
#define GLMWFW_KEY_REPEAT           0x00030005
#define GLMWFW_AUTO_POLL_EVENTS     0x00030006

// glmwfwGetJoystickParam tokens
#define GLMWFW_PRESENT              0x00050001
#define GLMWFW_AXES                 0x00050002
#define GLMWFW_BUTTONS              0x00050003

// Time spans longer than this (seconds) are considered to be infinity
#define GLMWFW_INFINITY 100000.0

#endif /* TCL_GLMWFW_H_INCLUDED */

