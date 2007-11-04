//========================================================================
// GLFW - An OpenGL framework
// File:        x11_window.c
// Platform:    X11 (Unix)
// API version: 2.6
// WWW:         http://glfw.sourceforge.net
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

/*
 * This file contains the C-implemented part of 
 * a Tcl interface to the GLFW X11 OpenGL library
 * This is a modified version of the original version adapted for use with Tcl
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: x11_window.c,v 1.1.2.4 2007/11/04 13:31:31 wiede Exp $
 */

#include "platform.h"


/* Defines some GLX FSAA tokens if not yet defined */
#ifndef GLX_SAMPLE_BUFFERS
# define GLX_SAMPLE_BUFFERS  100000
#endif 
#ifndef GLX_SAMPLES 
# define GLX_SAMPLES         100001
#endif 


/* KDE decoration values */
enum {
  KDE_noDecoration = 0,
  KDE_normalDecoration = 1,
  KDE_tinyDecoration = 2,
  KDE_noFocus = 256,
  KDE_standaloneMenuBar = 512,
  KDE_desktopIcon = 1024 ,
  KDE_staysOnTop = 2048
};


//************************************************************************
//****                  Glmwfw internal functions                       ****
//************************************************************************

//========================================================================
// _glmwfwWaitForMapNotify()
//========================================================================

Bool _glmwfwWaitForMapNotify( Display *d, XEvent *e, char *arg )
{
    return (e->type == MapNotify) && (e->xmap.window == (Window)arg);
}


//========================================================================
// _glmwfwWaitForUnmapNotify()
//========================================================================

Bool _glmwfwWaitForUnmapNotify( Display *d, XEvent *e, char *arg )
{
    return (e->type == UnmapNotify) && (e->xmap.window == (Window)arg);
}


//========================================================================
// _glmwfwDisableDecorations() - Turn off window decorations
// Based on xawdecode: src/wmhooks.c
//========================================================================

#define MWM_HINTS_DECORATIONS (1L << 1)

static void _glmwfwDisableDecorations( GlmwfwWindow *winPtr )
{
    int                   RemovedDecorations;
    Atom                  HintAtom;
    XSetWindowAttributes  attributes;

    RemovedDecorations = 0;

    // First try to set MWM hints
    HintAtom = XInternAtom( _glmwfwLibrary.Dpy, "_MOTIF_WM_HINTS", True );
    if ( HintAtom != None )
    {
        struct {
            unsigned long flags;
            unsigned long functions;
            unsigned long decorations;
                     long input_mode;
            unsigned long status;
        } MWMHints = { MWM_HINTS_DECORATIONS, 0, 0, 0, 0 };

        XChangeProperty( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, HintAtom, HintAtom,
                         32, PropModeReplace, (unsigned char *)&MWMHints,
                         sizeof(MWMHints)/4 );
        RemovedDecorations = 1;
    }

    // Now try to set KWM hints
    HintAtom = XInternAtom( _glmwfwLibrary.Dpy, "KWM_WIN_DECORATION", True );
    if ( HintAtom != None )
    {
        long KWMHints = KDE_tinyDecoration;

        XChangeProperty( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, HintAtom, HintAtom,
                         32, PropModeReplace, (unsigned char *)&KWMHints,
                         sizeof(KWMHints)/4 );
        RemovedDecorations = 1;
    }

    // Now try to set GNOME hints
    HintAtom = XInternAtom(_glmwfwLibrary.Dpy, "_WIN_HINTS", True );
    if ( HintAtom != None )
    {
        long GNOMEHints = 0;

        XChangeProperty( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, HintAtom, HintAtom,
                         32, PropModeReplace, (unsigned char *)&GNOMEHints,
                         sizeof(GNOMEHints)/4 );
        RemovedDecorations = 1;
    }

    // Now try to set KDE NET_WM hints
    HintAtom = XInternAtom( _glmwfwLibrary.Dpy, "_NET_WM_WINDOW_TYPE", True );
    if ( HintAtom != None )
    {
        Atom NET_WMHints[2];

        NET_WMHints[0] = XInternAtom( _glmwfwLibrary.Dpy, "_KDE_NET_WM_WINDOW_TYPE_OVERRIDE", True );
        /* define a fallback... */
        NET_WMHints[1] = XInternAtom( _glmwfwLibrary.Dpy, "_NET_WM_WINDOW_TYPE_NORMAL", True );

        XChangeProperty( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, HintAtom, XA_ATOM,
                         32, PropModeReplace, (unsigned char *)&NET_WMHints,
                         2 );
        RemovedDecorations = 1;
    }

    // Set ICCCM fullscreen WM hint
    HintAtom = XInternAtom( _glmwfwLibrary.Dpy, "_NET_WM_STATE", True );
    if ( HintAtom != None )
    {
        Atom NET_WMHints[1];

        NET_WMHints[0] = XInternAtom( _glmwfwLibrary.Dpy, "_NET_WM_STATE_FULLSCREEN", True );

        XChangeProperty( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, HintAtom, XA_ATOM,
                         32, PropModeReplace, (unsigned char *)&NET_WMHints, 1 );
    }


    // Did we sucessfully remove the window decorations?
    if( RemovedDecorations )
    {
        // Finally set the transient hints
        XSetTransientForHint( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, RootWindow(_glmwfwLibrary.Dpy, winPtr->platformWindow->Scrn) );
        XUnmapWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );
        XMapWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );
    }
    else
    {
        // The Butcher way of removing window decorations
        attributes.override_redirect = True;
        XChangeWindowAttributes( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win,
                                 CWOverrideRedirect, &attributes );
        winPtr->platformWindow->OverrideRedirect = GL_TRUE;
    }
}


//========================================================================
// _glmwfwEnableDecorations() - Turn on window decorations
//========================================================================

static void _glmwfwEnableDecorations(GlmwfwWindow *winPtr)
{
    int                   ActivatedDecorations;
    Atom                  HintAtom;

    // If this is an override redirect window, skip it...
    if(winPtr->platformWindow->OverrideRedirect )
    {
        return;
    }

    ActivatedDecorations = 0;

    // First try to unset MWM hints
    HintAtom = XInternAtom( _glmwfwLibrary.Dpy, "_MOTIF_WM_HINTS", True );
    if ( HintAtom != None )
    {
        XDeleteProperty( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, HintAtom );
        ActivatedDecorations = 1;
    }

    // Now try to unset KWM hints
    HintAtom = XInternAtom( _glmwfwLibrary.Dpy, "KWM_WIN_DECORATION", True );
    if ( HintAtom != None )
    {
        XDeleteProperty( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, HintAtom );
        ActivatedDecorations = 1;
    }

    // Now try to unset GNOME hints
    HintAtom = XInternAtom( _glmwfwLibrary.Dpy, "_WIN_HINTS", True );
    if ( HintAtom != None )
    {
        XDeleteProperty( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, HintAtom );
        ActivatedDecorations = 1;
    }

    // Now try to unset NET_WM hints
    HintAtom = XInternAtom( _glmwfwLibrary.Dpy, "_NET_WM_WINDOW_TYPE", True );
    if ( HintAtom != None )
    {
        Atom NET_WMHints = XInternAtom( _glmwfwLibrary.Dpy, "_NET_WM_WINDOW_TYPE_NORMAL", True);
        if( NET_WMHints != None )
        {
            XChangeProperty( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win,
                            HintAtom, XA_ATOM, 32, PropModeReplace,
                            (unsigned char *)&NET_WMHints, 1 );
            ActivatedDecorations = 1;
        }
    }

    // Finally unset the transient hints if necessary
    if( ActivatedDecorations )
    {
        // NOTE: Does this work?
        XSetTransientForHint( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, None);
        XUnmapWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );
        XMapWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );
    }
}


//========================================================================
// _glmwfwChooseVisual() - We do our own function here, since
// glXChooseVisual does not behave as we want it to (not according to the
// Glmwfw specs)
//========================================================================

XVisualInfo * _glmwfwChooseVisual( Display *Dpy, int Screen, int r, int g,
    int b, int a, int d, int s, int ar, int ag, int ab, int aa, int aux,
				 int fsaa, int stereo)
{
    XVisualInfo *VI, *VI_list, VI_tmp;
    int  nitems_return, i;
    int  vi_gl, vi_rgba, vi_double, vi_stereo;
    int  vi_r, vi_g, vi_b, vi_a, vi_d, vi_s, vi_ar, vi_ag, vi_ab, vi_aa;
    int  vi_aux;
    int  color, accum, vi_accum;
    int  missing, color_diff, extra_diff;
    int  best_vis, best_missing, best_color_diff, best_extra_diff;
    int  samples, samplebuffers, vi_samples, vi_samplebuffers;

    // Get list of visuals for this screen & display
    VI_tmp.screen = Screen;
    VI_list = XGetVisualInfo( Dpy, VisualScreenMask, &VI_tmp,
                              &nitems_return );
    if( VI_list == NULL )
    {
        return NULL;
    }

    // Pick some prefered color depth if the user did not request a
    // specific depth (note: if the user did not request a specific color
    // depth, this will not be a driving demand, it's only here to avoid
    // selection randomness)
    color = (r > 0 || g > 0 || b > 0);
    if( !color )
    {
        r = g = b = 8;
    }

    // Make sure that stereo is 1 or 0
    stereo = stereo ? 1 : 0;

    // Convenience pre-calculation
    accum = (ar > 0 || ag > 0 || ab > 0 || aa > 0);
    
    samples = fsaa;
    samplebuffers = (fsaa > 0) ? 1 : 0;
    
    

    // Loop through list of visuals to find best match
    best_vis        = -1;
    best_missing    = 0x7fffffff;
    best_color_diff = 0x7fffffff;
    best_extra_diff = 0x7fffffff;
    for( i = 0; i < nitems_return; i ++ )
    {
        // We want GL, RGBA & DOUBLEBUFFER, and NOT STEREO / STEREO
        glXGetConfig( Dpy, &VI_list[i], GLX_USE_GL, &vi_gl );
        glXGetConfig( Dpy, &VI_list[i], GLX_RGBA, &vi_rgba );
        glXGetConfig( Dpy, &VI_list[i], GLX_DOUBLEBUFFER, &vi_double );
        glXGetConfig( Dpy, &VI_list[i], GLX_STEREO, &vi_stereo );
        vi_stereo = vi_stereo ? 1 : 0;
        if( vi_gl && vi_rgba && vi_double && (vi_stereo == stereo) )
        {
            // Get visual color parameters
            glXGetConfig( Dpy, &VI_list[i], GLX_RED_SIZE, &vi_r );
            glXGetConfig( Dpy, &VI_list[i], GLX_GREEN_SIZE, &vi_g );
            glXGetConfig( Dpy, &VI_list[i], GLX_BLUE_SIZE, &vi_b );

            // Get visual "extra" parameters
            glXGetConfig( Dpy, &VI_list[i], GLX_ALPHA_SIZE, &vi_a );
            glXGetConfig( Dpy, &VI_list[i], GLX_DEPTH_SIZE, &vi_d );
            glXGetConfig( Dpy, &VI_list[i], GLX_STENCIL_SIZE, &vi_s );
            glXGetConfig( Dpy, &VI_list[i], GLX_ACCUM_RED_SIZE, &vi_ar );
            glXGetConfig( Dpy, &VI_list[i], GLX_ACCUM_GREEN_SIZE, &vi_ag );
            glXGetConfig( Dpy, &VI_list[i], GLX_ACCUM_BLUE_SIZE, &vi_ab );
            glXGetConfig( Dpy, &VI_list[i], GLX_ACCUM_ALPHA_SIZE, &vi_aa );
            glXGetConfig( Dpy, &VI_list[i], GLX_AUX_BUFFERS, &vi_aux );
	    glXGetConfig( Dpy, &VI_list[i], GLX_SAMPLE_BUFFERS, &vi_samplebuffers );
	    glXGetConfig( Dpy, &VI_list[i], GLX_SAMPLES, &vi_samples );
	    
            vi_accum = (vi_ar > 0 || vi_ag > 0 || vi_ab > 0 || vi_aa > 0);

            // Check how many buffers are missing
            missing = 0;
            if( a > 0 && vi_a == 0 ) missing ++;
            if( d > 0 && vi_d == 0 ) missing ++;
            if( s > 0 && vi_s == 0 ) missing ++;
            if( accum && !vi_accum ) missing ++;
            if( aux > 0 && vi_aux == 0 ) missing ++;
	    if( samplebuffers > 0 && vi_samplebuffers == 0 ) missing ++;
	    

            // Calculate color diff
            color_diff = (r - vi_r) * (r - vi_r) +
                         (g - vi_g) * (g - vi_g) +
                         (b - vi_b) * (b - vi_b);

            // Calculate "extra" diff
            extra_diff = 0;
            if( a > 0 )
            {
                extra_diff += (a - vi_a) * (a - vi_a);
            }
            if( d > 0 )
            {
                extra_diff += (d - vi_d) * (d - vi_d);
            }
            if( s > 0 )
            {
                extra_diff += (s - vi_s) * (s - vi_s);
            }
            if( accum )
            {
                extra_diff += (ar - vi_ar) * (ar - vi_ar) +
                              (ag - vi_ag) * (ag - vi_ag) +
                              (ab - vi_ab) * (ab - vi_ab) +
                              (aa - vi_aa) * (aa - vi_aa);
            }
            if( aux > 0 )
            {
                extra_diff += (aux - vi_aux) * (aux - vi_aux);
            }
	    if( samples > 0 )
	    {
	      extra_diff += (samples - vi_samples) * (samples - vi_samples);
	      
	    }
            // Check if this is a better match. We implement some
            // complicated rules, by prioritizing in this order:
            //  1) Visuals with the least number of missing buffers always
            //     have priority
            //  2a) If (r,g,b)!=(0,0,0), color depth has priority over
            //      other buffers
            //  2b) If (r,g,b)==(0,0,0), other buffers have priority over
            //      color depth
            if( missing < best_missing )
            {
                best_vis = i;
            }
            else if( missing == best_missing )
            {
                if( color )
                {
                    if( (color_diff < best_color_diff) ||
                        (color_diff == best_color_diff &&
                         extra_diff < best_extra_diff) )
                    {
                        best_vis = i;
                    }
                }
                else
                {
                    if( (extra_diff < best_extra_diff) ||
                        (extra_diff == best_extra_diff &&
                         color_diff < best_color_diff) )
                    {
                        best_vis = i;
                    }
                }
            }
            if( best_vis == i )
            {
                best_missing    = missing;
                best_color_diff = color_diff;
                best_extra_diff = extra_diff;
            }
        }
    }

    // Copy best visual to a visual to return
    if( best_vis >= 0 )
    {
        VI = XGetVisualInfo( Dpy, VisualIDMask, &VI_list[ best_vis ],
                             &nitems_return );
    }
    else
    {
        VI = NULL;
    }

    // Free visuals list
    XFree( VI_list );

    return VI;
}


//========================================================================
// _glmwfwTranslateKey() - Translates an X Window key to internal coding
//========================================================================

static int _glmwfwTranslateKey( int keycode )
{
    KeySym key, key_lc, key_uc;

    // Try secondary keysym, for numeric keypad keys
    // Note: This way we always force "NumLock = ON", which at least
    // enables Glmwfw users to detect numeric keypad keys
    key = XKeycodeToKeysym( _glmwfwLibrary.Dpy, keycode, 1 );
    switch( key )
    {
        // Numeric keypad
        case XK_KP_0:         return GLMWFW_KEY_KP_0;
        case XK_KP_1:         return GLMWFW_KEY_KP_1;
        case XK_KP_2:         return GLMWFW_KEY_KP_2;
        case XK_KP_3:         return GLMWFW_KEY_KP_3;
        case XK_KP_4:         return GLMWFW_KEY_KP_4;
        case XK_KP_5:         return GLMWFW_KEY_KP_5;
        case XK_KP_6:         return GLMWFW_KEY_KP_6;
        case XK_KP_7:         return GLMWFW_KEY_KP_7;
        case XK_KP_8:         return GLMWFW_KEY_KP_8;
        case XK_KP_9:         return GLMWFW_KEY_KP_9;
        case XK_KP_Separator:
        case XK_KP_Decimal:   return GLMWFW_KEY_KP_DECIMAL;
        case XK_KP_Equal:     return GLMWFW_KEY_KP_EQUAL;
        case XK_KP_Enter:     return GLMWFW_KEY_KP_ENTER;
        default:              break;
    }

    // Now try pimary keysym
    key = XKeycodeToKeysym( _glmwfwLibrary.Dpy, keycode, 0 );
    switch( key )
    {
        // Special keys (non character keys)
        case XK_Escape:       return GLMWFW_KEY_ESC;
        case XK_Tab:          return GLMWFW_KEY_TAB;
        case XK_Shift_L:      return GLMWFW_KEY_LSHIFT;
        case XK_Shift_R:      return GLMWFW_KEY_RSHIFT;
        case XK_Control_L:    return GLMWFW_KEY_LCTRL;
        case XK_Control_R:    return GLMWFW_KEY_RCTRL;
        case XK_Meta_L:
        case XK_Alt_L:        return GLMWFW_KEY_LALT;
        case XK_Mode_switch:  // Mapped to Alt_R on many keyboards
        case XK_Meta_R:
        case XK_Alt_R:        return GLMWFW_KEY_RALT;
        case XK_KP_Delete:
        case XK_Delete:       return GLMWFW_KEY_DEL;
        case XK_BackSpace:    return GLMWFW_KEY_BACKSPACE;
        case XK_Return:       return GLMWFW_KEY_ENTER;
        case XK_KP_Home:
        case XK_Home:         return GLMWFW_KEY_HOME;
        case XK_KP_End:
        case XK_End:          return GLMWFW_KEY_END;
        case XK_KP_Page_Up:
        case XK_Page_Up:      return GLMWFW_KEY_PAGEUP;
        case XK_KP_Page_Down:
        case XK_Page_Down:    return GLMWFW_KEY_PAGEDOWN;
        case XK_KP_Insert:
        case XK_Insert:       return GLMWFW_KEY_INSERT;
        case XK_KP_Left:
        case XK_Left:         return GLMWFW_KEY_LEFT;
        case XK_KP_Right:
        case XK_Right:        return GLMWFW_KEY_RIGHT;
        case XK_KP_Down:
        case XK_Down:         return GLMWFW_KEY_DOWN;
        case XK_KP_Up:
        case XK_Up:           return GLMWFW_KEY_UP;
        case XK_F1:           return GLMWFW_KEY_F1;
        case XK_F2:           return GLMWFW_KEY_F2;
        case XK_F3:           return GLMWFW_KEY_F3;
        case XK_F4:           return GLMWFW_KEY_F4;
        case XK_F5:           return GLMWFW_KEY_F5;
        case XK_F6:           return GLMWFW_KEY_F6;
        case XK_F7:           return GLMWFW_KEY_F7;
        case XK_F8:           return GLMWFW_KEY_F8;
        case XK_F9:           return GLMWFW_KEY_F9;
        case XK_F10:          return GLMWFW_KEY_F10;
        case XK_F11:          return GLMWFW_KEY_F11;
        case XK_F12:          return GLMWFW_KEY_F12;
        case XK_F13:          return GLMWFW_KEY_F13;
        case XK_F14:          return GLMWFW_KEY_F14;
        case XK_F15:          return GLMWFW_KEY_F15;
        case XK_F16:          return GLMWFW_KEY_F16;
        case XK_F17:          return GLMWFW_KEY_F17;
        case XK_F18:          return GLMWFW_KEY_F18;
        case XK_F19:          return GLMWFW_KEY_F19;
        case XK_F20:          return GLMWFW_KEY_F20;
        case XK_F21:          return GLMWFW_KEY_F21;
        case XK_F22:          return GLMWFW_KEY_F22;
        case XK_F23:          return GLMWFW_KEY_F23;
        case XK_F24:          return GLMWFW_KEY_F24;
        case XK_F25:          return GLMWFW_KEY_F25;

        // Numeric keypad (should have been detected in secondary keysym!)
        case XK_KP_Divide:    return GLMWFW_KEY_KP_DIVIDE;
        case XK_KP_Multiply:  return GLMWFW_KEY_KP_MULTIPLY;
        case XK_KP_Subtract:  return GLMWFW_KEY_KP_SUBTRACT;
        case XK_KP_Add:       return GLMWFW_KEY_KP_ADD;
        case XK_KP_Equal:     return GLMWFW_KEY_KP_EQUAL;
        case XK_KP_Enter:     return GLMWFW_KEY_KP_ENTER;

        // The rest (should be printable keys)
        default:
            // Make uppercase
// ARNULF
            XConvertCase( key, &key_lc, &key_uc );
//            key = key_uc;
            key = key_lc;
// END ARNULF

            // Valid ISO 8859-1 character?
            if( (key >=  32 && key <= 126) ||
                (key >= 160 && key <= 255) )
            {
                return (int) key;
            }
            return GLMWFW_KEY_UNKNOWN;
    }
}


#ifdef NOTDEF
//========================================================================
// _glmwfwTranslateChar() - Translates an X Window event to Unicode
//========================================================================

static int _glmwfwTranslateChar( XKeyEvent *event )
{
    KeySym keysym;

    // Get X11 keysym
    XLookupString( event, NULL, 0, &keysym, NULL );

    // Convert to Unicode (see x11_keysym2unicode.c)
    return (int) _glmwfwKeySym2Unicode( keysym );
}
#endif

//========================================================================
// Handle next X event (called by _glmwfwGetNextEvent and event_handler)
//========================================================================

int _glmwfwHandleNextEvent(
    GlmwfwWindow *winPtr,
    XEvent *event)
{
    XEvent next_event;

    // Handle certain window messages
    switch (event->type) {
    // Is a key being pressed?
    case KeyPress: {
        // Translate and report key press
        winPtr->infoPtr->inputKey( winPtr, _glmwfwTranslateKey( event->xkey.keycode ), GLMWFW_PRESS );

#ifdef NOTDEF
        // Translate and report character input
        if (winPtr->platformWindow->charfun) {
                _glmwfwInputChar( winPtr, _glmwfwTranslateChar( &event->xkey ), GLMWFW_PRESS );
        }
#endif
        break;
      }
    // Is a key being released?
    case KeyRelease: {
        // Do not report key releases for key repeats. For key repeats
        // we will get KeyRelease/KeyPress pairs with identical time
        // stamps. User selected key repeat filtering is handled in
        // _glmwfwInputKey()/_glmwfwInputChar().
        if (XEventsQueued(_glmwfwLibrary.Dpy, QueuedAfterReading)) {
            XPeekEvent(_glmwfwLibrary.Dpy, &next_event);
            if (next_event.type == KeyPress &&
                    next_event.xkey.window == event->xkey.window &&
                    next_event.xkey.keycode == event->xkey.keycode &&
                    next_event.xkey.time == event->xkey.time) {
                // Do not report anything for this event
                break;
            }
        }
        // Translate and report key release
        winPtr->infoPtr->inputKey( winPtr, _glmwfwTranslateKey( event->xkey.keycode ), GLMWFW_RELEASE );

#ifdef NOTDEF
        // Translate and report character input
        if (winPtr->platformWindow->charfunc) {
            _glmwfwInputChar( winPtr, _glmwfwTranslateChar( &event->xkey ), GLMWFW_RELEASE );
        }
#endif
        break;
      }
    // Were any of the mouse-buttons pressed?
    case ButtonPress: {
        if (event->xbutton.button == Button1) {
            winPtr->infoPtr->inputMouseClick( winPtr, GLMWFW_MOUSE_BUTTON_LEFT, GLMWFW_PRESS );
        } else {
	    if (event->xbutton.button == Button2) {
                winPtr->infoPtr->inputMouseClick(winPtr,
		        GLMWFW_MOUSE_BUTTON_MIDDLE, GLMWFW_PRESS);
            } else {
	        if (event->xbutton.button == Button3) {
                    winPtr->infoPtr->inputMouseClick(winPtr,
		            GLMWFW_MOUSE_BUTTON_RIGHT, GLMWFW_PRESS );
                } else {
                // XFree86 3.3.2 and later translates mouse wheel up/down into
                // mouse button 4 & 5 presses
                    if (event->xbutton.button == Button4) {
                        winPtr->input.WheelPos++;  // To verify: is this up or down?
                        if (winPtr->mousewheelfun) {
                            winPtr->mousewheelfun(winPtr, winPtr->input.WheelPos);
                        }
                    } else {
		        if (event->xbutton.button == Button5) {
                            winPtr->input.WheelPos--;
                            if (winPtr->mousewheelfun) {
                                winPtr->mousewheelfun(winPtr,
		                        winPtr->input.WheelPos);
                            }
	                }
		    }
	        }
            }
	}
        break;
      }
    // Were any of the mouse-buttons released?
    case ButtonRelease: {
        if (event->xbutton.button == Button1) {
            winPtr->infoPtr->inputMouseClick(winPtr,
	            GLMWFW_MOUSE_BUTTON_LEFT, GLMWFW_RELEASE);
        } else {
	    if (event->xbutton.button == Button2) {
                winPtr->infoPtr->inputMouseClick(winPtr,
		        GLMWFW_MOUSE_BUTTON_MIDDLE, GLMWFW_RELEASE);
            } else {
	        if (event->xbutton.button == Button3) {
                    winPtr->infoPtr->inputMouseClick(winPtr,
		            GLMWFW_MOUSE_BUTTON_RIGHT, GLMWFW_RELEASE);
                }
	    }
	}
        break;
      }
    // Was the mouse moved?
    case MotionNotify: {
        if (event->xmotion.x != winPtr->input.platformInput->CursorPosX ||
                event->xmotion.y != winPtr->input.platformInput->CursorPosY) {
            if (winPtr->MouseLock) {
                winPtr->input.MousePosX += event->xmotion.x -
                        winPtr->input.platformInput->CursorPosX;
                winPtr->input.MousePosY += event->xmotion.y -
                        winPtr->input.platformInput->CursorPosY;
            } else {
                winPtr->input.MousePosX = event->xmotion.x;
                winPtr->input.MousePosY = event->xmotion.y;
            }
            winPtr->input.platformInput->CursorPosX = event->xmotion.x;
            winPtr->input.platformInput->CursorPosY = event->xmotion.y;
            winPtr->input.platformInput->MouseMoved = GL_TRUE;
            // Call user callback function
            if (winPtr->mouseposfun) {
                winPtr->mouseposfun(winPtr, winPtr->input.MousePosX,
                        winPtr->input.MousePosY);
            }
        }
        break;
      }
    // Was the window resized?
    case ConfigureNotify: {
fprintf(stderr, "glmwfw ConfigureNotify 1:%d!%d!%d!%d\n", event->xconfigure.width, event->xconfigure.height, winPtr->Width, winPtr->Height);
        if (event->xconfigure.width != winPtr->Width ||
                event->xconfigure.height != winPtr->Height) {
            winPtr->Width = event->xconfigure.width;
            winPtr->Height = event->xconfigure.height;
fprintf(stderr, "glmwfw ConfigureNotify 2:%p\n", winPtr->windowsizefun);
            if (winPtr->windowsizefun) {
                winPtr->windowsizefun(winPtr, winPtr->Width,
                        winPtr->Height);
            }
        }
        break;
      }
    // Was the window closed by the window manager?
    case ClientMessage: {
        if ((Atom) event->xclient.data.l[0] ==
	        winPtr->platformWindow->WMDeleteWindow) {
            return GL_TRUE;
        }
	if ((Atom) event->xclient.data.l[0] ==
	        winPtr->platformWindow->WMPing) {
	    XSendEvent(_glmwfwLibrary.Dpy, RootWindow(_glmwfwLibrary.Dpy,
	            winPtr->platformWindow->VI->screen), False,
		    SubstructureNotifyMask | SubstructureRedirectMask, event);
        }
        break;
      }
    // Was the window mapped (un-iconified)?
    case MapNotify: {
fprintf(stderr, "glmwfw MapNotify:\n");
        winPtr->platformWindow->MapNotifyCount++;
        break;
      }
    // Was the window unmapped (iconified)?
    case UnmapNotify: {
fprintf(stderr, "glmwfw UnmapNotify:\n");
        winPtr->platformWindow->MapNotifyCount--;
        break;
      }
    // Was the window activated?
    case FocusIn: {
        winPtr->platformWindow->FocusInCount++;
        break;
      }
    // Was the window de-activated?
    case FocusOut: {
        winPtr->platformWindow->FocusInCount--;
        break;
      }
    // Was the window contents damaged?
    case Expose: {
        // Call user callback function
fprintf(stderr, "glmwfw Expose:%p\n", winPtr->windowrefreshfun);
        if (winPtr->windowrefreshfun) {
            winPtr->windowrefreshfun(winPtr);
        }
        break;
      }
    // Was the window destroyed?
    case DestroyNotify: {
fprintf(stderr, "111 DestroyNotify:\n");
        return GL_TRUE;
      }
    default: {
#if defined( _GLMWFW_HAS_XRANDR )
        switch (event->type - _glmwfwLibrary.XRandR.EventBase) {
	case RRScreenChangeNotify: {
	    // Show XRandR that we really care
	    XRRUpdateConfiguration( &event );
	    break;
	  }
        }
#endif
        break;
      }
    }
    // The window was not destroyed
    return GL_FALSE;
}

/* ARNULF */
static int
dispatch_event(
    GlmwfwInfo *infoPtr,
    XEvent *xe)
{
    GlmwfwWindow *winPtr;
    int result;

    result = _glmwfwHandleNextEvent(infoPtr->currWindow, xe);
if (result != 0) {
fprintf(stderr, "_glmwfwHandleNextEvent:result!%d\n", result);
}
    winPtr = infoPtr->currWindow;
//fprintf(stderr, "dispatch_event!%p!0x%08x\n", winPtr, xe->type);
    switch (xe->type) {
    case ButtonPress: {
        XButtonEvent *xbutton = &xe->xbutton;
fprintf(stderr, "ButtonPress:!0x%08x!0x%08x\n", xbutton->button, xe->type);
fprintf(stderr, "x:%d!y:%d!x_root:%d!y_root:%d!window:0x%08x!\n", xbutton->x, xbutton->y, xbutton->x_root, xbutton->y_root, (unsigned int)xbutton->window);
fprintf(stderr, "RR!%d!%d!%d!%d!\n", winPtr->xRoot, winPtr->yRoot, xbutton->x_root-xbutton->x,xbutton->y_root-xbutton->y);
      }
      break;
    case ButtonRelease: {
//        XButtonEvent *xbutton = &xe->xbutton;
      }
      break;
    case ClientMessage: {
        XClientMessageEvent * c_event = (XClientMessageEvent *)xe;
fprintf(stderr, "ClientMessage message_type:0x%08x\n", (unsigned int)c_event->message_type);
fprintf(stderr, "ClientMessage format:0x%08x!0x%08x!0x%08x!0x%08x!0x%08x!0x%08x!\n", c_event->format, (unsigned int)xe->xclient.data.l[0], (unsigned int)winPtr->platformWindow->WMDeleteWindow,(unsigned int)xe->xclient.data.l[1], (unsigned int)xe->xclient.data.l[2], (unsigned int)xe->xclient.data.l[3] );
            if( (Atom) xe->xclient.data.l[0] == winPtr->platformWindow->WMDeleteWindow ) {
fprintf(stderr, "DELETE WINDOW\n");
                winPtr->infoPtr->closeWindow(winPtr);
            }
      }
      break;
    case ConfigureNotify: {
fprintf(stderr, "ConfigureNotify:\n");
      }
      break;
    case DestroyNotify: {
fprintf(stderr, "DestroyNotify:\n");
      }
      break;
    case Expose: {
fprintf(stderr, "Expose:\n");
      }
      break;
    case NoExpose: {
fprintf(stderr, "NoExpose:\n");
      }
      break;
    case KeyPress: {
fprintf(stderr, "KeyPress:\n");
      }
      break;
    case KeyRelease: {
fprintf(stderr, "KeyRelease:\n");
      }
      break;
    case VisibilityNotify: {
fprintf(stderr, "VisibilityNotify:\n");
      }
      break;
    case MotionNotify: {
fprintf(stderr, "MotionNotify:\n");
      }
      break;
    case EnterNotify: {
fprintf(stderr, "EnterNotify:\n");
      }
      break;
    case LeaveNotify: {
fprintf(stderr, "LeaveNotify:\n");
      }
      break;
    case PropertyNotify: {
fprintf(stderr, "PropertyNotify:\n");
      }
      break;
    case CreateNotify: {
fprintf(stderr, "CreateNotify:\n");
      }
      break;
    case MapNotify: {
fprintf(stderr, "MapNotify:\n");
      }
      break;
    case UnmapNotify: {
fprintf(stderr, "UnmapNotify:\n");
      }
      break;
    case SelectionClear: {
fprintf(stderr, "SelectionClear:\n");
      }
      break;
    case SelectionRequest: {
fprintf(stderr, "SelectionRequest:\n");
      }
      break;
    case ResizeRequest: {
fprintf(stderr, "ResizeRequest:\n");
      }
      break;
    case FocusIn: {
fprintf(stderr, "FocusIn:\n");
      }
    case FocusOut: {
fprintf(stderr, "FocusOut:\n");
      }
      break;
    default: {
fprintf(stderr, "default:\n");
      }
      break;
    }
    return result;
}

void
event_handler (
    ClientData cdata,
    int mask)
{
    GlmwfwInfo *infoPtr;
    XEvent xe;
    int result;
    int allResult;

    infoPtr = (GlmwfwInfo *) cdata;

    allResult = 0;
again:
    while (XPending (_glmwfwLibrary.Dpy)) {
        XNextEvent (_glmwfwLibrary.Dpy, &xe);
        result = dispatch_event (infoPtr, &xe);
        allResult += result;
    }
    XSync (_glmwfwLibrary.Dpy, 0);
    if (XPending (_glmwfwLibrary.Dpy)) {
        goto again;
    }
    if (!infoPtr->currWindow->Opened) {
fprintf(stderr, "Call windowclosefun %d\n", allResult);
        infoPtr->currWindow->windowclosefun(infoPtr->currWindow);
    }
}

/* ARNULF END */

//========================================================================
// Get next X event (called by glmwfwPollEvents)
//========================================================================

static int _glmwfwGetNextEvent( GlmwfwWindow *winPtr )
{
    XEvent event;

    // Pull next event from event queue
    XNextEvent( _glmwfwLibrary.Dpy, &event );
    return _glmwfwHandleNextEvent(winPtr, &event);
}


//========================================================================
// _glmwfwCreateNULLCursor() - Create a blank cursor (for locked mouse mode)
//========================================================================

Cursor _glmwfwCreateNULLCursor( Display *display, Window root )
{
    Pixmap    cursormask;
    XGCValues xgc;
    GC        gc;
    XColor    col;
    Cursor    cursor;

    cursormask = XCreatePixmap( display, root, 1, 1, 1 );
    xgc.function = GXclear;
    gc = XCreateGC( display, cursormask, GCFunction, &xgc );
    XFillRectangle( display, cursormask, gc, 0, 0, 1, 1 );
    col.pixel = 0;
    col.red = 0;
    col.flags = 4;
    cursor = XCreatePixmapCursor( display, cursormask, cursormask,
                                  &col,&col, 0,0 );
    XFreePixmap( display, cursormask );
    XFreeGC( display, gc );

    return cursor;
}


//========================================================================
// _glmwfwInitGLXExtensions() - Initialize GLX-specific extensions
//========================================================================

static void _glmwfwInitGLXExtensions( GlmwfwWindow *winPtr )
{
    int has_swap_control;

    // Initialize OpenGL extension: GLX_SGI_swap_control
    has_swap_control = _glmwfwPlatformExtensionSupported( winPtr,
                           "GLX_SGI_swap_control"
                       );

    if( has_swap_control )
    {
        winPtr->platformWindow->SwapInterval = (GLXSWAPINTERVALSGI_T)
            _glmwfw_glXGetProcAddress( (GLubyte*) "glXSwapIntervalSGI" );
    }
    else
    {
        winPtr->platformWindow->SwapInterval = NULL;
    }
}


//************************************************************************
//****               Platform implementation functions                ****
//************************************************************************

//========================================================================
// _glmwfwPlatformOpenWindow() - Here is where the window is created, and
// the OpenGL rendering context is created
//========================================================================

int _glmwfwPlatformOpenWindow( GlmwfwWindow *winPtr, int width, int height, int redbits,
    int greenbits, int bluebits, int alphabits, int depthbits,
    int stencilbits, int mode, GlmwfwHints* hints )
{
    Colormap    cmap;
    XSetWindowAttributes wa;
    XEvent      event;
    Atom protocols[2];

    winPtr->platformWindow = (_GlmwfwPlatformWindow *)
            ckalloc(sizeof(_GlmwfwPlatformWindow));
    winPtr->input.platformInput = (_GlmwfwPlatformInput *)
            ckalloc(sizeof(_GlmwfwPlatformInput));
    // Clear platform specific Glmwfw window state
    winPtr->platformWindow->VI               = NULL;
    winPtr->platformWindow->CX               = (GLXContext)0;
    winPtr->platformWindow->Win              = (Window)0;
    winPtr->platformWindow->Hints            = NULL;
    winPtr->platformWindow->PointerGrabbed   = GL_FALSE;
    winPtr->platformWindow->KeyboardGrabbed  = GL_FALSE;
    winPtr->platformWindow->OverrideRedirect = GL_FALSE;
    winPtr->platformWindow->FS.ModeChanged   = GL_FALSE;
    winPtr->platformWindow->Saver.Changed    = GL_FALSE;
    winPtr->Hints.RefreshRate      = hints->RefreshRate;

    // Fullscreen & screen saver settings
    // Check if GLX is supported on this display
    if( !glXQueryExtension( _glmwfwLibrary.Dpy, NULL, NULL ) )
    {
        _glmwfwPlatformCloseWindow(winPtr);
        return GL_FALSE;
    }

    // Get screen ID for this window
    winPtr->platformWindow->Scrn = _glmwfwLibrary.DefaultScreen;

    // Get an appropriate visual
    winPtr->platformWindow->VI = _glmwfwChooseVisual( _glmwfwLibrary.Dpy,
            winPtr->platformWindow->Scrn,
            redbits, greenbits, bluebits,
            alphabits, depthbits, stencilbits,
            hints->AccumRedBits, hints->AccumGreenBits,
            hints->AccumBlueBits, hints->AccumAlphaBits,
            hints->AuxBuffers, hints->Samples, hints->Stereo );
    if( winPtr->platformWindow->VI == NULL )
    {
        _glmwfwPlatformCloseWindow(winPtr);
        return GL_FALSE;
    }

    // Create a GLX context
    winPtr->platformWindow->CX = glXCreateContext( _glmwfwLibrary.Dpy,
            winPtr->platformWindow->VI, 0, GL_TRUE );
    if( winPtr->platformWindow->CX == NULL )
    {
        _glmwfwPlatformCloseWindow(winPtr);
        return GL_FALSE;
    }

    // Create a colormap
    cmap = XCreateColormap( _glmwfwLibrary.Dpy, RootWindow( _glmwfwLibrary.Dpy,
            winPtr->platformWindow->VI->screen),
	    winPtr->platformWindow->VI->visual, AllocNone );

    // Do we want fullscreen?
    if( mode == GLMWFW_FULLSCREEN )
    {
        // Change video mode
        _glmwfwSetVideoMode( winPtr, winPtr->platformWindow->Scrn,
	        &winPtr->Width, &winPtr->Height, &winPtr->Hints.RefreshRate );
        // Remember old screen saver settings
        XGetScreenSaver( _glmwfwLibrary.Dpy,
	        &winPtr->platformWindow->Saver.Timeout,
                &winPtr->platformWindow->Saver.Interval,
		&winPtr->platformWindow->Saver.Blanking,
                &winPtr->platformWindow->Saver.Exposure );

        // Disable screen saver
        XSetScreenSaver( _glmwfwLibrary.Dpy, 0, 0, DontPreferBlanking,
                         DefaultExposures );
    }

    // Attributes for window
    wa.colormap = cmap;
    wa.border_pixel = 0;
    wa.event_mask = 
	KeyPressMask |
	KeyReleaseMask |
	ButtonPressMask |
	ButtonReleaseMask |
	EnterWindowMask |
	LeaveWindowMask  |
	PointerMotionMask |
	PointerMotionHintMask |
        ExposureMask |
	VisibilityChangeMask |
        StructureNotifyMask |
	ResizeRedirectMask |
	FocusChangeMask |
	OwnerGrabButtonMask;

    // Create a window
    winPtr->platformWindow->Win = XCreateWindow(
        _glmwfwLibrary.Dpy,
        RootWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI->screen ),
        0, 0,                          // Upper left corner
        winPtr->Width, winPtr->Height, // Width, height
        0,                             // Borderwidth
        winPtr->platformWindow->VI->depth, // Depth
        InputOutput,
        winPtr->platformWindow->VI->visual,
        CWBorderPixel | CWColormap | CWEventMask,
        &wa
    );
    if( !winPtr->platformWindow->Win )
    {
        _glmwfwPlatformCloseWindow(winPtr);
        return GL_FALSE;
    }

    // Get the delete window WM protocol atom
    winPtr->platformWindow->WMDeleteWindow = XInternAtom( _glmwfwLibrary.Dpy,
                                           "WM_DELETE_WINDOW",
                                           False );

    // Get the ping WM protocol atom
    winPtr->platformWindow->WMPing = XInternAtom( _glmwfwLibrary.Dpy, "_NET_WM_PING", False );

    protocols[0] = winPtr->platformWindow->WMDeleteWindow;
    protocols[1] = winPtr->platformWindow->WMPing;

    // Allow us to trap the Window Close protocol
    XSetWMProtocols( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, protocols,
                     sizeof(protocols) / sizeof(Atom) );

    // Remove window decorations for fullscreen windows
    if( mode == GLMWFW_FULLSCREEN )
    {
        _glmwfwDisableDecorations(winPtr);
    }

    winPtr->platformWindow->Hints = XAllocSizeHints();

    if( hints->WindowNoResize )
    {
	winPtr->platformWindow->Hints->flags |= (PMinSize | PMaxSize);
        winPtr->platformWindow->Hints->min_width = winPtr->platformWindow->Hints->max_width = winPtr->Width;
        winPtr->platformWindow->Hints->min_height = winPtr->platformWindow->Hints->max_height = winPtr->Height;
    }

    if( mode == GLMWFW_FULLSCREEN )
    {
	winPtr->platformWindow->Hints->flags |= PPosition;
	winPtr->platformWindow->Hints->x = 0;
	winPtr->platformWindow->Hints->y = 0;
    }

    XSetWMNormalHints( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, winPtr->platformWindow->Hints );

    // Map window
    XMapWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );

    // Wait for map notification
    XIfEvent( _glmwfwLibrary.Dpy, &event, _glmwfwWaitForMapNotify,
              (char*)winPtr->platformWindow->Win );

    // Make sure that our window ends up on top of things
    XRaiseWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );

    // Fullscreen mode "post processing"
    if( mode == GLMWFW_FULLSCREEN )
    {
#if defined( _GLMWFW_HAS_XRANDR )
	// Request screen change notifications
	if( _glmwfwLibrary.XRandR.Available )
	{
	    XRRSelectInput( _glmwfwLibrary.Dpy,
	                    winPtr->platformWindow->Win,
			    RRScreenChangeNotifyMask );
	}
#endif

        // Force window position/size (some WMs do their own window
        // geometry, which we want to override)
        XMoveWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, 0, 0 );
        XResizeWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, winPtr->Width,
                       winPtr->Height );

        // Grab keyboard
        if( XGrabKeyboard( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, True,
                           GrabModeAsync, GrabModeAsync, CurrentTime ) ==
            GrabSuccess )
        {
            winPtr->platformWindow->KeyboardGrabbed = GL_TRUE;
        }

        // Grab mouse cursor
        if( XGrabPointer( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, True,
                          ButtonPressMask | ButtonReleaseMask |
                          PointerMotionMask, GrabModeAsync, GrabModeAsync,
                          winPtr->platformWindow->Win, None, CurrentTime ) ==
            GrabSuccess )
        {
            winPtr->platformWindow->PointerGrabbed = GL_TRUE;
        }

        // Try to get window inside viewport (for virtual displays) by
        // moving the mouse cursor to the upper left corner (and then to
        // the center) - this works for XFree86
        XWarpPointer( _glmwfwLibrary.Dpy, None, winPtr->platformWindow->Win, 0,0,0,0, 0,0 );
        XWarpPointer( _glmwfwLibrary.Dpy, None, winPtr->platformWindow->Win, 0,0,0,0,
                      winPtr->Width/2, winPtr->Height/2 );
    }

    // Set window & icon name
    _glmwfwPlatformSetWindowTitle( winPtr, "GLMWFW Window" );

    // Connect the context to the window
    glXMakeCurrent( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, winPtr->platformWindow->CX );

    // Start by clearing the front buffer to black (avoid ugly desktop
    // remains in our OpenGL window)
    glClear( GL_COLOR_BUFFER_BIT );
    glXSwapBuffers( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );

    // Initialize GLX-specific OpenGL extensions
    _glmwfwInitGLXExtensions(winPtr);

    return GL_TRUE;
}


//========================================================================
// Properly kill the window/video display
//========================================================================

int _glmwfwPlatformCloseWindow( GlmwfwWindow *winPtr )
{
fprintf(stderr, "_glmwfwPlatformCloseWindow\n");
#if defined( _GLMWFW_HAS_XRANDR )
    XRRScreenConfiguration *sc;
    Window root;
#endif

    // Free WM size hints
    if( winPtr->platformWindow->Hints )
    {
	XFree( winPtr->platformWindow->Hints );
	winPtr->platformWindow->Hints = NULL;
    }

    // Do we have a rendering context?
    if( winPtr->platformWindow->CX )
    {
        // Release the context
        glXMakeCurrent( _glmwfwLibrary.Dpy, None, NULL );

        // Delete the context
        glXDestroyContext( _glmwfwLibrary.Dpy, winPtr->platformWindow->CX );
        winPtr->platformWindow->CX = NULL;
    }

    // Ungrab pointer and/or keyboard?
    if( winPtr->platformWindow->KeyboardGrabbed )
    {
        XUngrabKeyboard( _glmwfwLibrary.Dpy, CurrentTime );
        winPtr->platformWindow->KeyboardGrabbed = GL_FALSE;
    }
    if( winPtr->platformWindow->PointerGrabbed )
    {
        XUngrabPointer( _glmwfwLibrary.Dpy, CurrentTime );
        winPtr->platformWindow->PointerGrabbed = GL_FALSE;
    }

    // Do we have a window?
    if( winPtr->platformWindow->Win )
    {
        // Unmap the window
        XUnmapWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );

        // Destroy the window
        XDestroyWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );
        winPtr->platformWindow->Win = (Window) 0;
    }

    // Did we change the fullscreen resolution?
    if( winPtr->platformWindow->FS.ModeChanged )
    {
#if defined( _GLMWFW_HAS_XRANDR )
	if( _glmwfwLibrary.XRandR.Available )
	{
	    root = RootWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Scrn );
	    sc = XRRGetScreenInfo( _glmwfwLibrary.Dpy, root );

	    XRRSetScreenConfig( _glmwfwLibrary.Dpy,
	                        sc,
				root,
			        winPtr->platformWindow->FS.OldSizeID,
				winPtr->platformWindow->FS.OldRotation,
				CurrentTime );

	    XRRFreeScreenConfigInfo( sc );
	}
#elif defined( _GLMWFW_HAS_XF86VIDMODE )
        if( _glmwfwLibrary.XF86VidMode.Available )
        {
            // Unlock mode switch
            XF86VidModeLockModeSwitch( _glmwfwLibrary.Dpy,
                                       winPtr->platformWindow->Scrn,
                                       0 );

            // Change the video mode back to the old mode
            XF86VidModeSwitchToMode( _glmwfwLibrary.Dpy,
                winPtr->platformWindow->Scrn, &winPtr->platformWindow->FS.OldMode );
        }
#endif
        winPtr->platformWindow->FS.ModeChanged = GL_FALSE;
    }

    // Did we change the screen saver setting?
    if( winPtr->platformWindow->Saver.Changed )
    {
        // Restore old screen saver settings
        XSetScreenSaver( _glmwfwLibrary.Dpy, winPtr->platformWindow->Saver.Timeout,
                         winPtr->platformWindow->Saver.Interval, winPtr->platformWindow->Saver.Blanking,
                         winPtr->platformWindow->Saver.Exposure );
        winPtr->platformWindow->Saver.Changed = GL_FALSE;
    }

    XSync( _glmwfwLibrary.Dpy, True );
    return TCL_OK;
}


//========================================================================
// _glmwfwPlatformSetWindowTitle() - Set the window title.
//========================================================================

int _glmwfwPlatformSetWindowTitle( GlmwfwWindow *winPtr, const char *title )
{
    // Set window & icon title
    XStoreName( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, title );
    XSetIconName( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, title );
    return TCL_OK;
}


//========================================================================
// _glmwfwPlatformSetWindowSize() - Set the window size.
//========================================================================

int _glmwfwPlatformSetWindowSize( GlmwfwWindow *winPtr, int width, int height )
{
    int     mode = 0, rate, sizechanged = GL_FALSE;
    GLint   drawbuffer;
    GLfloat clearcolor[4];

    rate = winPtr->Hints.RefreshRate;

    // If we are in fullscreen mode, get some info about the current mode
    if( winPtr->Fullscreen )
    {
        // Get closest match for target video mode
        mode = _glmwfwGetClosestVideoMode( winPtr->platformWindow->Scrn, &width, &height, &rate );
    }

    if( winPtr->WindowNoResize )
    {
        winPtr->platformWindow->Hints->min_width = winPtr->platformWindow->Hints->max_width = width;
        winPtr->platformWindow->Hints->min_height = winPtr->platformWindow->Hints->max_height = height;
    }

    XSetWMNormalHints( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, winPtr->platformWindow->Hints );

    // Change window size before changing fullscreen mode?
    if( winPtr->Fullscreen && (width > winPtr->Width) )
    {
        XResizeWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, width, height );
        sizechanged = GL_TRUE;
    }

    // Change fullscreen video mode?
    if( winPtr->Fullscreen )
    {
        // Change video mode (keeping current rate)
        _glmwfwSetVideoModeMODE( winPtr, winPtr->platformWindow->Scrn, mode, winPtr->Hints.RefreshRate );

        // Clear the front buffer to black (avoid ugly desktop remains in
        // our OpenGL window)
        glGetIntegerv( GL_DRAW_BUFFER, &drawbuffer );
        glGetFloatv( GL_COLOR_CLEAR_VALUE, clearcolor );
        glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
        glClear( GL_COLOR_BUFFER_BIT );
        if( drawbuffer == GL_BACK )
        {
            glXSwapBuffers( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );
        }
        glClearColor( clearcolor[0], clearcolor[1], clearcolor[2],
                      clearcolor[3] );
    }

    // Set window size (if not already changed)
    if( !sizechanged )
    {
        XResizeWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, width, height );
    }
    return TCL_OK;
}


//========================================================================
// _glmwfwPlatformSetWindowPos() - Set the window position.
//========================================================================

int _glmwfwPlatformSetWindowPos( GlmwfwWindow *winPtr, int x, int y )
{
    // Set window position
    winPtr->xRoot = x;
    winPtr->yRoot = y;
    XMoveWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, x, y );
    return TCL_OK;
}


//========================================================================
// _glmwfwPlatformIconfyWindow() - Window iconification
//========================================================================

int _glmwfwPlatformIconifyWindow( GlmwfwWindow *winPtr )
{
    // We can't do this for override redirect windows
    if( winPtr->platformWindow->OverrideRedirect )
    {
        return TCL_OK;
    }

    // In fullscreen mode, we need to restore the desktop video mode
    if( winPtr->Fullscreen )
    {
#if defined( _GLMWFW_HAS_XF86VIDMODE )
        if( _glmwfwLibrary.XF86VidMode.Available )
        {
            // Unlock mode switch
            XF86VidModeLockModeSwitch( _glmwfwLibrary.Dpy,
                                       winPtr->platformWindow->Scrn,
                                       0 );

            // Change the video mode back to the old mode
            XF86VidModeSwitchToMode( _glmwfwLibrary.Dpy,
                winPtr->platformWindow->Scrn, &winPtr->platformWindow->FS.OldMode );
        }
#endif
        winPtr->platformWindow->FS.ModeChanged = GL_FALSE;
    }

    // Show mouse pointer
    if( winPtr->platformWindow->PointerHidden )
    {
        XUndefineCursor( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );
        winPtr->platformWindow->PointerHidden = GL_FALSE;
    }

    // Un-grab mouse pointer
    if( winPtr->platformWindow->PointerGrabbed )
    {
        XUngrabPointer( _glmwfwLibrary.Dpy, CurrentTime );
        winPtr->platformWindow->PointerGrabbed = GL_FALSE;
    }

    // Iconify window
    XIconifyWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win,
                    winPtr->platformWindow->Scrn );

    // Window is now iconified
    winPtr->Iconified = GL_TRUE;
    return TCL_OK;
}


//========================================================================
// Window un-iconification
//========================================================================

int _glmwfwPlatformRestoreWindow( GlmwfwWindow *winPtr )
{
    // We can't do this for override redirect windows
    if( winPtr->platformWindow->OverrideRedirect )
    {
        return TCL_OK;
    }

    // In fullscreen mode, change back video mode to user selected mode
    if( winPtr->Fullscreen )
    {
        _glmwfwSetVideoMode( winPtr, winPtr->platformWindow->Scrn,
	                   &winPtr->Width, &winPtr->Height, &winPtr->Hints.RefreshRate );
    }

    // Un-iconify window
    XMapWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );

    // In fullscreen mode...
    if( winPtr->Fullscreen )
    {
        // Make sure window is in upper left corner
        XMoveWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, 0, 0 );

        // Get input focus
        XSetInputFocus( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, RevertToParent,
                        CurrentTime );
    }

    // Lock mouse, if necessary
    if( winPtr->MouseLock )
    {
        // Hide cursor
        if( !winPtr->platformWindow->PointerHidden )
        {
            XDefineCursor( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win,
                           _glmwfwCreateNULLCursor( _glmwfwLibrary.Dpy,
                                                  winPtr->platformWindow->Win ) );
            winPtr->platformWindow->PointerHidden = GL_TRUE;
        }

        // Grab cursor
        if( !winPtr->platformWindow->PointerGrabbed )
        {
            if( XGrabPointer( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, True,
                              ButtonPressMask | ButtonReleaseMask |
                              PointerMotionMask, GrabModeAsync,
                              GrabModeAsync, winPtr->platformWindow->Win, None,
                              CurrentTime ) == GrabSuccess )
            {
                winPtr->platformWindow->PointerGrabbed = GL_TRUE;
            }
        }
    }

    // Window is no longer iconified
    winPtr->Iconified = GL_FALSE;
    return TCL_OK;
}


//========================================================================
// _glmwfwPlatformSwapBuffers() - Swap buffers (double-buffering) and poll
// any new events.
//========================================================================

int _glmwfwPlatformSwapBuffers( GlmwfwWindow *winPtr )
{
    // Update display-buffer
    glXSwapBuffers( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );
    return TCL_OK;
}


//========================================================================
// _glmwfwPlatformSwapInterval() - Set double buffering swap interval
//========================================================================

int _glmwfwPlatformSwapInterval( GlmwfwWindow *winPtr, int interval )
{
    if( winPtr->platformWindow->SwapInterval )
    {
        winPtr->platformWindow->SwapInterval( interval );
    }
    return TCL_OK;
}


//========================================================================
// _glmwfwPlatformRefreshWindowParams()
//========================================================================

int _glmwfwPlatformRefreshWindowParams( GlmwfwWindow *winPtr )
{
#if defined( _GLMWFW_HAS_XRANDR )
    XRRScreenConfiguration *sc;
#elif defined( _GLMWFW_HAS_XF86VIDMODE )
    XF86VidModeModeLine modeline;
    int dotclock;
    float pixels_per_second, pixels_per_frame;
#endif
    int sample_buffers;

    // AFAIK, there is no easy/sure way of knowing if OpenGL is hardware
    // accelerated
    winPtr->Accelerated = GL_TRUE;

    // "Standard" window parameters
    glXGetConfig( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI, GLX_RED_SIZE,
                  &winPtr->RedBits );
    glXGetConfig( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI, GLX_GREEN_SIZE,
                  &winPtr->GreenBits );
    glXGetConfig( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI, GLX_BLUE_SIZE,
                  &winPtr->BlueBits );
    glXGetConfig( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI, GLX_ALPHA_SIZE,
                  &winPtr->AlphaBits );
    glXGetConfig( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI, GLX_DEPTH_SIZE,
                  &winPtr->DepthBits );
    glXGetConfig( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI, GLX_STENCIL_SIZE,
                  &winPtr->StencilBits );
    glXGetConfig( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI, GLX_ACCUM_RED_SIZE,
                  &winPtr->Hints.AccumRedBits );
    glXGetConfig( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI, GLX_ACCUM_GREEN_SIZE,
                  &winPtr->Hints.AccumGreenBits );
    glXGetConfig( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI, GLX_ACCUM_BLUE_SIZE,
                  &winPtr->Hints.AccumBlueBits );
    glXGetConfig( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI, GLX_ACCUM_ALPHA_SIZE,
                  &winPtr->Hints.AccumAlphaBits );
    glXGetConfig( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI, GLX_AUX_BUFFERS,
                  &winPtr->Hints.AuxBuffers );

    // Get stereo rendering setting
    glXGetConfig( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI, GLX_STEREO,
                  &winPtr->Hints.Stereo );
    winPtr->Hints.Stereo = winPtr->Hints.Stereo ? 1 : 0;

    // Get multisample buffer samples
    glXGetConfig( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI, GLX_SAMPLES,
		  &winPtr->Hints.Samples );
    glXGetConfig( _glmwfwLibrary.Dpy, winPtr->platformWindow->VI, GLX_SAMPLE_BUFFERS, 
		  &sample_buffers );
    if( sample_buffers == 0 )
      winPtr->Hints.Samples = 0;
    
    // Default to refresh rate unknown (=0 according to GLMWFW spec)
    winPtr->Hints.RefreshRate = 0;
		  
    // Retrieve refresh rate, if possible
#if defined( _GLMWFW_HAS_XRANDR )
    if( _glmwfwLibrary.XRandR.Available )
    {
	sc = XRRGetScreenInfo( _glmwfwLibrary.Dpy,
	                       RootWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Scrn ) );
	winPtr->platformWindow->RefreshRate = XRRConfigCurrentRate( sc );
	XRRFreeScreenConfigInfo( sc );
    }
#elif defined( _GLMWFW_HAS_XF86VIDMODE )
    if( _glmwfwLibrary.XF86VidMode.Available )
    {
        // Use the XF86VidMode extension to get current video mode
        XF86VidModeGetModeLine( _glmwfwLibrary.Dpy, winPtr->platformWindow->Scrn,
                                &dotclock, &modeline );
        pixels_per_second = 1000.0f * (float) dotclock;
        pixels_per_frame  = (float) modeline.htotal * modeline.vtotal;
        winPtr->platformWindow->RefreshRate = (int)(pixels_per_second/pixels_per_frame+0.5);
    }
#endif
    return TCL_OK;
}


//========================================================================
// _glmwfwPlatformPollEvents() - Poll for new window and input events
//========================================================================

int _glmwfwPlatformPollEvents( GlmwfwWindow *winPtr )
{
    int winclosed = GL_FALSE;

    // Flag that the cursor has not moved
    winPtr->input.platformInput->MouseMoved = GL_FALSE;

    // Clear MapNotify and FocusIn counts
    winPtr->platformWindow->MapNotifyCount = 0;
    winPtr->platformWindow->FocusInCount = 0;

    // Use XSync to synchronise events to the X display.
    // I don't know if this can have a serious performance impact. My
    // benchmarks with a GeForce card under Linux shows no difference with
    // or without XSync, but when the GL window is rendered over a slow
    // network I have noticed bad event syncronisation problems when XSync
    // is not used, so I decided to use it.
    XSync( _glmwfwLibrary.Dpy, False );

    // Empty the window event queue
    while( XPending( _glmwfwLibrary.Dpy ) )
    {
        if( _glmwfwGetNextEvent(winPtr) )
        {
            winclosed = GL_TRUE;
        }
    }

    // Did we get mouse movement in locked cursor mode?
    if( winPtr->input.platformInput->MouseMoved && winPtr->MouseLock )
    {
        int maxx, minx, maxy, miny;

        // Calculate movement threshold
        minx = winPtr->Width / 4;
        maxx = (winPtr->Width * 3) / 4;
        miny = winPtr->Height / 4;
        maxy = (winPtr->Height * 3) / 4;

        // Did the mouse cursor move beyond our movement threshold
        if(winPtr->input.platformInput->CursorPosX < minx || winPtr->input.platformInput->CursorPosX > maxx ||
           winPtr->input.platformInput->CursorPosY < miny || winPtr->input.platformInput->CursorPosY > maxy)
        {
            // Move the mouse pointer back to the window center so that it
            // does not wander off...
            _glmwfwPlatformSetMouseCursorPos( winPtr, winPtr->Width/2,
                                            winPtr->Height/2 );
            XSync( _glmwfwLibrary.Dpy, False );
        }
    }

    // Was the window (un)iconified?
    if( winPtr->platformWindow->MapNotifyCount < 0 && !winPtr->Iconified )
    {
        // Show mouse pointer
        if( winPtr->platformWindow->PointerHidden )
        {
            XUndefineCursor( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );
            winPtr->platformWindow->PointerHidden = GL_FALSE;
        }

        // Un-grab mouse pointer
        if( winPtr->platformWindow->PointerGrabbed )
        {
            XUngrabPointer( _glmwfwLibrary.Dpy, CurrentTime );
            winPtr->platformWindow->PointerGrabbed = GL_FALSE;
        }

        winPtr->Iconified = GL_TRUE;
    }
    else if( winPtr->platformWindow->MapNotifyCount > 0 && winPtr->Iconified )
    {
        // Restore fullscreen mode properties
        if( winPtr->Fullscreen )
        {
            // Change back video mode to user selected mode
            _glmwfwSetVideoMode( winPtr, winPtr->platformWindow->Scrn, &winPtr->Width,
                               &winPtr->Height, &winPtr->Hints.RefreshRate );

            // Disable window manager decorations
            _glmwfwEnableDecorations(winPtr);

            // Make sure window is in upper left corner
            XMoveWindow( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, 0, 0 );

            // Get input focus
            XSetInputFocus( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win,
                            RevertToParent, CurrentTime );
        }

        // Hide cursor if necessary
        if( winPtr->MouseLock && !winPtr->platformWindow->PointerHidden )
        {
            if( !winPtr->platformWindow->PointerHidden )
            {
                XDefineCursor( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win,
                    _glmwfwCreateNULLCursor( _glmwfwLibrary.Dpy,
                                           winPtr->platformWindow->Win ) );
                winPtr->platformWindow->PointerHidden = GL_TRUE;
            }
        }

        // Grab cursor if necessary
        if( (winPtr->MouseLock || winPtr->Fullscreen) &&
            !winPtr->platformWindow->PointerGrabbed )
        {
            if( XGrabPointer( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, True,
                    ButtonPressMask | ButtonReleaseMask |
                    PointerMotionMask, GrabModeAsync,
                    GrabModeAsync, winPtr->platformWindow->Win, None,
                    CurrentTime ) == GrabSuccess )
            {
                winPtr->platformWindow->PointerGrabbed = GL_TRUE;
            }
        }

        winPtr->Iconified = GL_FALSE;
    }

    // Did the window get/lose focus
    if( winPtr->platformWindow->FocusInCount > 0 && !winPtr->Active )
    {
        // If we are in fullscreen mode, restore window
        if( winPtr->Fullscreen && winPtr->Iconified )
        {
            _glmwfwPlatformRestoreWindow(winPtr);
        }

        // Window is now active
        winPtr->Active = GL_TRUE;
    }
    else if( winPtr->platformWindow->FocusInCount < 0 && winPtr->Active )
    {
        // If we are in fullscreen mode, iconfify window
        if( winPtr->Fullscreen )
        {
            _glmwfwPlatformIconifyWindow(winPtr);
        }

        // Window is not active
        winPtr->Active = GL_FALSE;
	winPtr->infoPtr->inputDeactivation(winPtr);
    }

    // Was there a window close request?
    if( winclosed && winPtr->windowclosefun )
    {
        // Check if the program wants us to close the window
        winclosed = winPtr->windowclosefun(winPtr);
    }
    if (winclosed) {
        winPtr->infoPtr->closeWindow(winPtr);
    }
    return TCL_OK;
}


//========================================================================
// _glmwfwPlatformWaitEvents() - Wait for new window and input events
//========================================================================

int _glmwfwPlatformWaitEvents( GlmwfwWindow *winPtr )
{
    XEvent event;

fprintf(stderr, "_glmwfwPlatformWaitEvents\n");
    // Wait for new events (blocking)
    XNextEvent( _glmwfwLibrary.Dpy, &event );
    XPutBackEvent( _glmwfwLibrary.Dpy, &event );

    // Poll events from queue
    _glmwfwPlatformPollEvents(winPtr);
    return TCL_OK;
}


//========================================================================
// _glmwfwPlatformHideMouseCursor() - Hide mouse cursor (lock it)
//========================================================================

int _glmwfwPlatformHideMouseCursor( GlmwfwWindow *winPtr )
{
    // Hide cursor
    if( !winPtr->platformWindow->PointerHidden )
    {
        XDefineCursor( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win,
                       _glmwfwCreateNULLCursor( _glmwfwLibrary.Dpy,
                                              winPtr->platformWindow->Win ) );
        winPtr->platformWindow->PointerHidden = GL_TRUE;
    }

    // Grab cursor to user window
    if( !winPtr->platformWindow->PointerGrabbed )
    {
        if( XGrabPointer( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win, True,
                          ButtonPressMask | ButtonReleaseMask |
                          PointerMotionMask, GrabModeAsync, GrabModeAsync,
                          winPtr->platformWindow->Win, None, CurrentTime ) ==
            GrabSuccess )
        {
            winPtr->platformWindow->PointerGrabbed = GL_TRUE;
        }
    }
    return TCL_OK;
}


//========================================================================
// _glmwfwPlatformShowMouseCursor() - Show mouse cursor (unlock it)
//========================================================================

int _glmwfwPlatformShowMouseCursor( GlmwfwWindow *winPtr )
{
    // Un-grab cursor (only in windowed mode: in fullscreen mode we still
    // want the mouse grabbed in order to confine the cursor to the window
    // area)
    if( winPtr->platformWindow->PointerGrabbed && !winPtr->Fullscreen )
    {
        XUngrabPointer( _glmwfwLibrary.Dpy, CurrentTime );
        winPtr->platformWindow->PointerGrabbed = GL_FALSE;
    }

    // Show cursor
    if( winPtr->platformWindow->PointerHidden )
    {
        XUndefineCursor( _glmwfwLibrary.Dpy, winPtr->platformWindow->Win );
        winPtr->platformWindow->PointerHidden = GL_FALSE;
    }
    return TCL_OK;
}


//========================================================================
// _glmwfwPlatformSetMouseCursorPos() - Set physical mouse cursor position
//========================================================================

int _glmwfwPlatformSetMouseCursorPos( GlmwfwWindow *winPtr, int x, int y )
{
    // Change cursor position
    winPtr->input.platformInput->CursorPosX = x;
    winPtr->input.platformInput->CursorPosY = y;
    XWarpPointer( _glmwfwLibrary.Dpy, None, winPtr->platformWindow->Win, 0,0,0,0, x, y );
    return TCL_OK;
}
