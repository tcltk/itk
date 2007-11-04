//========================================================================
// GLFW - An OpenGL framework
// File:        platform.h
// Platform:    X11 (Unix)
// API version: 2.6
// WWW:         http://glmwfw.sourceforge.net
//------------------------------------------------------------------------
// Copyright (c) 2002-2006 Camilla Berglund
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#ifndef _platform_h_
#define _platform_h_


// This is the X11 version of GLFW
#define _GLMWFW_X11


// Include files
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/Xatom.h>
#include <GL/glx.h>
#include "../../glmwfw/generic/glmwfwInt.h"
#include "../../glmwfw/generic/glmwfwPlatform.h"

// With XFree86, we can use the XF86VidMode extension
#if defined( _GLMWFW_HAS_XF86VIDMODE )
 #include <X11/extensions/xf86vmode.h>
#endif

#if defined( _GLMWFW_HAS_XRANDR )
 #include <X11/extensions/Xrandr.h>
#endif

// Do we have support for dlopen/dlsym?
#if defined( _GLMWFW_HAS_DLOPEN )
 #include <dlfcn.h>
#endif

// We support two different ways for getting the number of processors in
// the system: sysconf (POSIX) and sysctl (BSD?)
#if defined( _GLMWFW_HAS_SYSCONF )

 // Use a single constant for querying number of online processors using
 // the sysconf function (e.g. SGI defines _SC_NPROC_ONLN instead of
 // _SC_NPROCESSORS_ONLN)
 #ifndef _SC_NPROCESSORS_ONLN
  #ifdef  _SC_NPROC_ONLN
   #define _SC_NPROCESSORS_ONLN _SC_NPROC_ONLN
  #else
   #error POSIX constant _SC_NPROCESSORS_ONLN not defined!
  #endif
 #endif

 // Macro for querying the number of processors
 #define _glmwfw_numprocessors(n) n=(int)sysconf(_SC_NPROCESSORS_ONLN)

#elif defined( _GLMWFW_HAS_SYSCTL )

 #include <sys/types.h>
 #include <sys/sysctl.h>

 // Macro for querying the number of processors
 #define _glmwfw_numprocessors(n) { \
    int mib[2], ncpu; \
    size_t len = 1; \
    mib[0] = CTL_HW; \
    mib[1] = HW_NCPU; \
    n      = 1; \
    if( sysctl( mib, 2, &ncpu, &len, NULL, 0 ) != -1 ) \
    { \
        if( len > 0 ) \
        { \
            n = ncpu; \
        } \
    } \
 }

#else

 // If neither sysconf nor sysctl is supported, assume single processor
 // system
 #define _glmwfw_numprocessors(n) n=1

#endif

void (*glXGetProcAddress(const GLubyte *procName))();
void (*glXGetProcAddressARB(const GLubyte *procName))();
void (*glXGetProcAddressEXT(const GLubyte *procName))();

// We support four different ways for getting addresses for GL/GLX
// extension functions: glXGetProcAddress, glXGetProcAddressARB,
// glXGetProcAddressEXT, and dlsym
#if   defined( _GLMWFW_HAS_GLXGETPROCADDRESSARB )
 #define _glmwfw_glXGetProcAddress(x) glXGetProcAddressARB(x)
#elif defined( _GLMWFW_HAS_GLXGETPROCADDRESS )
 #define _glmwfw_glXGetProcAddress(x) glXGetProcAddress(x)
#elif defined( _GLMWFW_HAS_GLXGETPROCADDRESSEXT )
 #define _glmwfw_glXGetProcAddress(x) glXGetProcAddressEXT(x)
#elif defined( _GLMWFW_HAS_DLOPEN )
 #define _glmwfw_glXGetProcAddress(x) dlsym(_glmwfwLibs.libGL,x)
 #define _GLMWFW_DLOPEN_LIBGL
#else
#define _glmwfw_glXGetProcAddress(x) NULL
#endif

// glXSwapIntervalSGI typedef (X11 buffer-swap interval control)
typedef int ( * GLXSWAPINTERVALSGI_T) (int interval);


//========================================================================

//------------------------------------------------------------------------
// Window structure
//------------------------------------------------------------------------

typedef struct _GlmwfwPlatformWindow {
    // Platform specific window resources
    Window      Win;             // Window
    int         Scrn;            // Screen ID
    XVisualInfo *VI;             // Visual
    GLXContext  CX;              // OpenGL rendering context
    Atom        WMDeleteWindow;  // For WM close detection
    Atom        WMPing;          // For WM ping response
    XSizeHints  *Hints;          // WM size hints

    // Platform specific extensions
    GLXSWAPINTERVALSGI_T SwapInterval;

    // Various platform specific internal variables
    int         OverrideRedirect; // True if window is OverrideRedirect
    int         KeyboardGrabbed; // True if keyboard is currently grabbed
    int         PointerGrabbed;  // True if pointer is currently grabbed
    int         PointerHidden;   // True if pointer is currently hidden
    int         MapNotifyCount;  // Used for during processing
    int         FocusInCount;    // Used for during processing

    // Screensaver data
    struct {
	int     Changed;
	int     Timeout;
	int     Interval;
	int     Blanking;
	int     Exposure;
    } Saver;

    // Fullscreen data
    struct {
	int     ModeChanged;
#if defined( _GLMWFW_HAS_XF86VIDMODE )
	XF86VidModeModeInfo OldMode;
#endif
#if defined( _GLMWFW_HAS_XRANDR )
        SizeID   OldSizeID;
	int      OldWidth;
	int      OldHeight;
	Rotation OldRotation;
#endif
    } FS;
} _GlmwfwPlatformWindow;


//------------------------------------------------------------------------
// User input status (most of this should go in _GLMWFWwin)
//------------------------------------------------------------------------
typedef struct _GlmwfwPlatformInput {
    // Platform specific internal variables
    int  MouseMoved, CursorPosX, CursorPosY;

} _GlmwfwPlatformInput;

//------------------------------------------------------------------------
// Library global data
//------------------------------------------------------------------------
struct {

// ========= PLATFORM SPECIFIC PART ======================================

    Display     *Dpy;
    int         NumScreens;
    int         DefaultScreen;

    struct {
	int	Available;
	int     EventBase;
	int     ErrorBase;
    } XF86VidMode;

    struct {
	int	Available;
	int     EventBase;
	int     ErrorBase;
    } XRandR;

    // Timer data
    struct {
	double       Resolution;
	long long    t0;
    } Timer;

#if defined(_GLMWFW_DLOPEN_LIBGL)
    struct {
	void        *libGL;          // dlopen handle for libGL.so
    } Libs;
#endif
} _glmwfwLibrary;


//------------------------------------------------------------------------
// Joystick information & state
//------------------------------------------------------------------------
typedef struct _GlmwfwPlatformJoystick {
    int           Present;
    int           fd;
    int           NumAxes;
    int           NumButtons;
    float         *Axis;
    unsigned char *Button;
} _GlmwfwPlatformJoystick;
_GlmwfwPlatformJoystick _glmwfwJoy[ GLMWFW_JOYSTICK_LAST + 1 ];


//========================================================================
// Prototypes for platform specific internal functions
//========================================================================

// Time
void _glmwfwInitTimer( void );

// Fullscreen support
int  _glmwfwGetClosestVideoMode( int screen, int *width, int *height, int *rate );
void _glmwfwSetVideoModeMODE( GlmwfwWindow *winPtr, int screen, int mode, int rate );
void _glmwfwSetVideoMode( GlmwfwWindow *winPtr, int screen, int *width, int *height, int *rate );

// Cursor handling
Cursor _glmwfwCreateNULLCursor( Display *display, Window root );

// Joystick input
void _glmwfwInitJoysticks( void );
void _glmwfwTerminateJoysticks( void );

// Unicode support
long _glmwfwKeySym2Unicode( KeySym keysym );

int _glmwfwHandleNextEvent( GlmwfwWindow *winPtr, XEvent *event);

#endif // _platform_h_
