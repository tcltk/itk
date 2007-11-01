//========================================================================
// GLMWFW - An OpenGL framework
// File:        x11_fullscreen.c
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

#include "platform.h"


//************************************************************************
//****                  GLMWFW internal functions                     ****
//************************************************************************

//========================================================================
// _glmwfwBPP2RGB() - Convert BPP to RGB bits (based on "best guess")
//========================================================================

static void _glmwfwBPP2RGB( int bpp, int *r, int *g, int *b )
{
    int delta;

    // Special case: BPP = 32 (I don't think this is necessary for X11??)
    if( bpp == 32 )
	bpp = 24;

    // Convert "bits per pixel" to red, green & blue sizes
    *r = *g = *b = bpp / 3;
    delta = bpp - (*r * 3);
    if( delta >= 1 )
    {
        *g = *g + 1;
    }
    if( delta == 2 )
    {
        *r = *r + 1;
    }
}


//========================================================================
// Finds the video mode closest in size to the specified desired size
//========================================================================

int _glmwfwGetClosestVideoMode( int screen, int *width, int *height, int *rate )
{
#if defined( _GLMWFW_HAS_XRANDR )
    int i, match, bestmatch;
    int sizecount, bestsize;
    int ratecount, bestrate;
    short *ratelist;
    XRRScreenConfiguration *sc;
    XRRScreenSize *sizelist;

    if( _glmwfwLibrary.XRandR.Available )
    {
	sc = XRRGetScreenInfo( _glmwfwLibrary.Dpy,
			       RootWindow( _glmwfwLibrary.Dpy, screen ) );

	sizelist = XRRConfigSizes( sc, &sizecount );

        // Find the best matching mode
        bestsize  = -1;
        bestmatch = 999999;
        for( i = 0; i < sizecount; i++ )
        {
            match = (*width - sizelist[i].width) *
                    (*width - sizelist[i].width) +
                    (*height - sizelist[i].height) *
                    (*height - sizelist[i].height);
            if( match < bestmatch )
            {
                bestmatch = match;
                bestsize  = i;
            }
        }

	if( bestsize != -1 )
	{
	    // Report width & height of best matching mode
	    *width = sizelist[bestsize].width;
	    *height = sizelist[bestsize].height;

	    if( *rate > 0 )
	    {
		ratelist = XRRConfigRates( sc, bestsize, &ratecount );

		bestrate = -1;
		bestmatch = 999999;
		for( i = 0; i < ratecount; i++ )
		{
		    match = abs( ratelist[i] - *rate );
		    if( match < bestmatch )
		    {
			bestmatch = match;
			bestrate = ratelist[i];
		    }
		}
		
		if( bestrate != -1 )
		{
		    *rate = bestrate;
		}
	    }
	}

        // Free modelist
	XRRFreeScreenConfigInfo( sc );

	if( bestsize != -1 )
	{
	    return bestsize;
	}
    }
#elif defined( _GLMWFW_HAS_XF86VIDMODE )
    XF86VidModeModeInfo **modelist;
    int modecount, i, bestmode, bestmatch, match;

    // Use the XF86VidMode extension to control video resolution
    if( _glmwfwLibrary.XF86VidMode.Available )
    {
        // Get a list of all available display modes
        XF86VidModeGetAllModeLines( _glmwfwLibrary.Dpy, screen,
                                    &modecount, &modelist );

        // Find the best matching mode
        bestmode  = -1;
        bestmatch = 999999;
        for( i = 0; i < modecount; i++ )
        {
            match = (*width - modelist[i]->hdisplay) *
                    (*width - modelist[i]->hdisplay) +
                    (*height - modelist[i]->vdisplay) *
                    (*height - modelist[i]->vdisplay);
            if( match < bestmatch )
            {
                bestmatch = match;
                bestmode  = i;
            }
        }

	if( bestmode != -1 )
	{
	    // Report width & height of best matching mode
	    *width = modelist[ bestmode ]->hdisplay;
	    *h = modelist[ bestmode ]->vdisplay;
	}

        // Free modelist
        XFree( modelist );

	if( bestmode != -1 )
	{
	    return bestmode;
	}
    }
#endif

    // Default: Simply use the screen resolution
    *width = DisplayWidth( _glmwfwLibrary.Dpy, screen );
    *height = DisplayHeight( _glmwfwLibrary.Dpy, screen );

    return 0;
}


//========================================================================
// Change the current video mode
//========================================================================

void _glmwfwSetVideoModeMODE( GLMWFWWindow *winPtr, int screen, int mode, int rate )
{
#if defined( _GLMWFW_HAS_XRANDR )
    XRRScreenConfiguration *sc;
    Window root;

    if( _glmwfwLibrary.XRandR.Available )
    {
	root = RootWindow( _glmwfwLibrary.Dpy, screen );
	sc   = XRRGetScreenInfo( _glmwfwLibrary.Dpy, root );

        // Remember old size and flag that we have changed the mode
        if( !winPtr->platformWindow->FS.ModeChanged )
        {
	    winPtr->platformWindow->FS.OldSizeID = XRRConfigCurrentConfiguration( sc, &winPtr->platformWindow->FS.OldRotation );
	    winPtr->platformWindow->FS.OldWidth  = DisplayWidth( _glmwfwLibrary.Dpy, screen );
	    winPtr->platformWindow->FS.OldHeight = DisplayHeight( _glmwfwLibrary.Dpy, screen );

            winPtr->platformWindow->FS.ModeChanged = GL_TRUE;
        }

	if( rate > 0 )
	{
	    // Set desired configuration
	    XRRSetScreenConfigAndRate( _glmwfwLibrary.Dpy,
				       sc,
				       root,
				       mode,
				       RR_Rotate_0,
				       (short) rate,
				       CurrentTime );
	}
	else
	{
	    // Set desired configuration
	    XRRSetScreenConfig( _glmwfwLibrary.Dpy,
				sc,
				root,
				mode,
				RR_Rotate_0,
				CurrentTime );
	}

	XRRFreeScreenConfigInfo( sc );
    }
#elif defined( _GLMWFW_HAS_XF86VIDMODE )
    XF86VidModeModeInfo **modelist;
    int modecount;

    // Use the XF86VidMode extension to control video resolution
    if( _glmwfwLibrary.XF86VidMode.Available )
    {
        // Get a list of all available display modes
        XF86VidModeGetAllModeLines( _glmwfwLibrary.Dpy, screen,
                                    &modecount, &modelist );

        // Unlock mode switch if necessary
        if( winPtr->platformWindow->FS.ModeChanged )
        {
            XF86VidModeLockModeSwitch( _glmwfwLibrary.Dpy, screen, 0 );
        }

        // Change the video mode to the desired mode
        XF86VidModeSwitchToMode(  _glmwfwLibrary.Dpy, screen,
                                  modelist[ mode ] );

        // Set viewport to upper left corner (where our window will be)
        XF86VidModeSetViewPort( _glmwfwLibrary.Dpy, screen, 0, 0 );

        // Lock mode switch
        XF86VidModeLockModeSwitch( _glmwfwLibrary.Dpy, screen, 1 );

        // Remember old mode and flag that we have changed the mode
        if( !winPtr->platformWindow->FS.ModeChanged )
        {
            winPtr->platformWindow->FS.OldMode = *modelist[ 0 ];
            winPtr->platformWindow->FS.ModeChanged = GL_TRUE;
        }

        // Free mode list
        XFree( modelist );
    }
#endif
}


//========================================================================
// Change the current video mode
//========================================================================

void _glmwfwSetVideoMode( GLMWFWWindow *winPtr, int screen, int *width, int *height, int *rate )
{
    int     bestmode;

    // Find a best match mode
    bestmode = _glmwfwGetClosestVideoMode( screen, width, height, rate );

    // Change mode
    _glmwfwSetVideoModeMODE( winPtr, screen, bestmode, *rate );
}



//************************************************************************
//****               Platform implementation functions                ****
//************************************************************************

struct _glmwfwResolution {
    int width;
    int height;
};

//========================================================================
// List available video modes
//========================================================================

int _glmwfwPlatformGetVideoModes( GLMWFWvidmode *list, int maxcount )
{
    int     count, k, l, r, g, b, rgba, gl;
    int     depth, screen;
    Display *dpy;
    XVisualInfo *vislist, dummy;
    int     viscount, rgbcount, rescount;
    int     *rgbarray;
    struct _glmwfwResolution *resarray;
#if defined( _GLMWFW_HAS_XRANDR )
    XRRScreenConfiguration *sc;
    XRRScreenSize *sizelist;
    int     sizecount;
#elif defined( _GLMWFW_HAS_XF86VIDMODE )
    XF86VidModeModeInfo **modelist;
    int     modecount, width, height;
#endif

    // Get display and screen
    dpy = _glmwfwLibrary.Dpy;
    screen = DefaultScreen( dpy );

    // Get list of visuals
    vislist = XGetVisualInfo( dpy, 0, &dummy, &viscount );
    if( vislist == NULL )
    {
	return 0;
    }

    rgbarray = (int*) ckalloc( sizeof(int) * viscount );
    rgbcount = 0;

    // Build RGB array
    for( k = 0; k < viscount; k++ )
    {
        // Does the visual support OpenGL & true color?
        glXGetConfig( dpy, &vislist[k], GLX_USE_GL, &gl );
        glXGetConfig( dpy, &vislist[k], GLX_RGBA, &rgba );
        if( gl && rgba )
        {
            // Get color depth for this visual
            depth = vislist[k].depth;

            // Convert to RGB
            _glmwfwBPP2RGB( depth, &r, &g, &b );
            depth = (r<<16) | (g<<8) | b;

            // Is this mode unique?
            for( l = 0; l < rgbcount; l++ )
            {
                if( depth == rgbarray[ l ] )
                {
                    break;
                }
            }
            if( l >= rgbcount )
            {
                rgbarray[ rgbcount ] = depth;
                rgbcount++;
            }
        }
    }

    rescount = 0;
    resarray = NULL;

    // Build resolution array
#if defined( _GLMWFW_HAS_XRANDR )
    if( _glmwfwLibrary.XRandR.Available )
    {
	sc = XRRGetScreenInfo( dpy, RootWindow( dpy, screen ) );
	sizelist = XRRConfigSizes( sc, &sizecount );

	resarray = (struct _glmwfwResolution*) ckalloc( sizeof(struct _glmwfwResolution) * sizecount );

        for( k = 0; k < sizecount; k++ )
        {
	    resarray[ rescount ].width = sizelist[ k ].width;
	    resarray[ rescount ].height = sizelist[ k ].height;
	    rescount++;
        }

	XRRFreeScreenConfigInfo( sc );
    }
#elif defined( _GLMWFW_HAS_XF86VIDMODE )
    if( _glmwfwLibrary.XF86VidMode.Available )
    {
        XF86VidModeGetAllModeLines( dpy, screen, &modecount, &modelist );

	resarray = (struct _glmwfwResolution*) ckalloc( sizeof(struct _glmwfwResolution) * modecount );

        for( k = 0; k < modecount; k++ )
        {
            width  = modelist[ k ]->hdisplay;
            height = modelist[ k ]->vdisplay;

            // Is this mode unique?
            for( l = 0; l < rescount; l++ )
            {
                if( width == resarray[ l ].width && height == resarray[ l ].height )
                {
                    break;
                }
            }
            if( l >= rescount )
            {
                resarray[ rescount ].width = width;
                resarray[ rescount ].height = height;
                rescount++;
            }
        }

	XFree( modelist );
    }
#endif

    if( !resarray )
    {
	rescount = 1;
	resarray = (struct _glmwfwResolution*) ckalloc( sizeof(struct _glmwfwResolution) * rescount );

	resarray[ 0 ].width = DisplayWidth( dpy, screen );
	resarray[ 0 ].height = DisplayHeight( dpy, screen );
    }

    // Build permutations of colors and resolutions
    count = 0;
    for( k = 0; k < rgbcount && count < maxcount; k++ )
    {
        for( l = 0; l < rescount && count < maxcount; l++ )
        {
            list[count].Width     = resarray[ l ].width;
            list[count].Height    = resarray[ l ].height;
            list[count].RedBits   = (rgbarray[ k ] >> 16) & 255;
            list[count].GreenBits = (rgbarray[ k ] >> 8) & 255;
            list[count].BlueBits  = rgbarray[ k ] & 255;
            count++;
        }
    }

    // Free visuals list
    XFree( vislist );

    ckfree( (char *)resarray );
    ckfree( (char *)rgbarray );

    return count;
}


//========================================================================
// Get the desktop video mode
//========================================================================

int _glmwfwPlatformGetDesktopMode( GLMWFWvidmode *mode )
{
    Display *dpy;
    int     bpp, screen;
#if defined( _GLMWFW_HAS_XF86VIDMODE )
    XF86VidModeModeInfo **modelist;
    int     modecount;
#endif

    // Get display and screen
    dpy = _glmwfwLibrary.Dpy;
    screen = DefaultScreen( dpy );

    // Get display depth
    bpp = DefaultDepth( dpy, screen );

    // Convert BPP to RGB bits
    _glmwfwBPP2RGB( bpp, &mode->RedBits, &mode->GreenBits, &mode->BlueBits );

#if defined( _GLMWFW_HAS_XRANDR )
    if( _glmwfwLibrary.XRandR.Available )
    {
        if( winPtr->platformWindow->FS.ModeChanged )
        {
	    mode->Width  = winPtr->platformWindow->FS.OldWidth;
	    mode->Height = winPtr->platformWindow->FS.OldHeight;
	    return;
	}
    }
#elif defined( _GLMWFW_HAS_XF86VIDMODE )
    if( _glmwfwLibrary.XF86VidMode.Available )
    {
        if( winPtr->platformWindow->FS.ModeChanged )
        {
            // The old (desktop) mode is stored in winPtr->platformWindow->FS.OldMode
            mode->Width  = winPtr->platformWindow->FS.OldMode.hdisplay;
            mode->Height = winPtr->platformWindow->FS.OldMode.vdisplay;
        }
        else
        {
            // Use the XF86VidMode extension to get list of video modes
            XF86VidModeGetAllModeLines( dpy, screen, &modecount,
                                        &modelist );

            // The first mode in the list is the current (desktio) mode
            mode->Width  = modelist[ 0 ]->hdisplay;
            mode->Height = modelist[ 0 ]->vdisplay;

            // Free list
            XFree( modelist );
        }

	return TCL_OK;
    }
#endif

    // Get current display width and height
    mode->Width  = DisplayWidth( dpy, screen );
    mode->Height = DisplayHeight( dpy, screen );
    return TCL_OK;
}

