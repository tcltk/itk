//========================================================================
// GLFW - An OpenGL framework
// File:        win32_window.c
// Platform:    Windows
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
//****                  GLMWFW internal functions                       ****
//************************************************************************

#define _GLMWFW_WNDCLASSNAME "GLMWFW26"


//========================================================================
// Enable/disable minimize/restore animations
//========================================================================

static int _glmwfwMinMaxAnimations( int enable )
{
    ANIMATIONINFO AI;
    int old_enable;

    // Get old animation setting
    AI.cbSize = sizeof( ANIMATIONINFO );
    SystemParametersInfo( SPI_GETANIMATION, AI.cbSize, &AI, 0 );
    old_enable = AI.iMinAnimate;

    // If requested, change setting
    if( old_enable != enable )
    {
        AI.iMinAnimate = enable;
        SystemParametersInfo( SPI_SETANIMATION, AI.cbSize, &AI,
                              SPIF_SENDCHANGE );
    }

    return old_enable;
}


//========================================================================
// Function for bringing a window into focus and placing it on top of the
// window z stack. Due to some nastiness with how Win98/ME/2k/XP handles
// SetForegroundWindow, we have to go through some really bizarre measures to
// achieve this (thanks again, MS, for making life so much easier)!
//========================================================================

static void _glmwfwSetForegroundWindow( HWND hWnd )
{
    int try_count = 0;
    int old_animate;

    // Try the standard approach first...
    BringWindowToTop( hWnd );
    SetForegroundWindow( hWnd );

    // If it worked, return now
    if( hWnd == GetForegroundWindow() )
    {
        // Try to modify the system settings (since this is the foreground
        // process, we are allowed to do this)
        SystemParametersInfo( SPI_SETFOREGROUNDLOCKTIMEOUT, 0, (LPVOID)0,
                              SPIF_SENDCHANGE );
        return;
    }

    // For other Windows versions than 95 & NT4.0, the standard approach
    // may not work, so if we failed we have to "trick" Windows into
    // making our window the foureground window: Iconify and restore
    // again. It is ugly, but it seems to work (we turn off those annoying
    // zoom animations to make it look a bit better at least).

    // Turn off minimize/restore animations
    old_animate = _glmwfwMinMaxAnimations( 0 );

    // We try this a few times, just to be on the safe side of things...
    do
    {
        // Iconify & restore
        ShowWindow( hWnd, SW_HIDE );
        ShowWindow( hWnd, SW_SHOWMINIMIZED );
        ShowWindow( hWnd, SW_SHOWNORMAL );

        // Try to get focus
        BringWindowToTop( hWnd );
        SetForegroundWindow( hWnd );

        // We do not want to keep going on forever, so we keep track of
        // how many times we tried
        try_count ++;
    }
    while( hWnd != GetForegroundWindow() && try_count <= 3 );

    // Restore the system minimize/restore animation setting
    (void) _glmwfwMinMaxAnimations( old_animate );

    // Try to modify the system settings (since this is now hopefully the
    // foreground process, we are probably allowed to do this)
    SystemParametersInfo( SPI_SETFOREGROUNDLOCKTIMEOUT, 0, (LPVOID)0,
                          SPIF_SENDCHANGE );
}


//========================================================================
// Sets the device context pixel format using a PFD
//========================================================================

static int _glmwfwSetPixelFormatPFD( GlmwfwWindow *winPtr, int redbits, int greenbits, int bluebits,
                                   int alphabits, int depthbits, int stencilbits,
                                   int mode, _GLMWFWhints* hints )
{
    int PixelFormat;
    PIXELFORMATDESCRIPTOR pfd;

    // Set required pixel format
    pfd.nSize           = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion        = 1;
    pfd.dwFlags         = PFD_DRAW_TO_WINDOW | // Draw to window
                          PFD_SUPPORT_OPENGL | // Support OpenGL
                          PFD_DOUBLEBUFFER;    // Double buffered window
    pfd.iPixelType      = PFD_TYPE_RGBA;       // Request an RGBA format
    pfd.cColorBits      = (BYTE) (redbits +
                                  greenbits +
                                  bluebits);   // Color bits (ex. alpha)
    pfd.cRedBits        = (BYTE) redbits;      // Red bits
    pfd.cRedShift       = 0;                   // Red shift ignored
    pfd.cGreenBits      = (BYTE) greenbits;    // Green bits
    pfd.cGreenShift     = 0;                   // Green shift ignored
    pfd.cBlueBits       = (BYTE) bluebits;     // Blue bits
    pfd.cBlueShift      = 0;                   // Blue shift ignored
    pfd.cAlphaBits      = (BYTE) alphabits;    // Alpha bits
    pfd.cAlphaShift     = 0;                   // Alpha shift ignored
    pfd.cAccumBits      = (BYTE) (hints->AccumRedBits +
                                  hints->AccumGreenBits +
                                  hints->AccumBlueBits +
                                  hints->AccumAlphaBits); // Accum. bits
    pfd.cAccumRedBits   = (BYTE) hints->AccumRedBits;   // Accum. red bits
    pfd.cAccumGreenBits = (BYTE) hints->AccumGreenBits; // Accum. green bits
    pfd.cAccumBlueBits  = (BYTE) hints->AccumBlueBits;  // Accum. blue bits
    pfd.cAccumAlphaBits = (BYTE) hints->AccumAlphaBits; // Accum. alpha bits
    pfd.cDepthBits      = (BYTE) depthbits;    // Depth buffer bits
    pfd.cStencilBits    = (BYTE) stencilbits;  // Stencil buffer bits
    pfd.cAuxBuffers     = (BYTE) hints->AuxBuffers;   // No. of aux buffers
    pfd.iLayerType      = PFD_MAIN_PLANE;      // Drawing layer: main
    pfd.bReserved       = 0;                   // (reserved)
    pfd.dwLayerMask     = 0;                   // Ignored
    pfd.dwVisibleMask   = 0;                   // "
    pfd.dwDamageMask    = 0;                   // "

    if( depthbits <= 0 )
    {
        // We do not need a depth buffer
        pfd.dwFlags |= PFD_DEPTH_DONTCARE;
    }

    if( hints->Stereo )
    {
        // Request a stereo mode
        pfd.dwFlags |= PFD_STEREO;
    }

    // Find a matching pixel format
    PixelFormat = _glmwfw_ChoosePixelFormat( winPtr->platformWindow->DC, &pfd );
    if( !PixelFormat )
    {
        return GL_FALSE;
    }

    // Get actual pixel format description
    if( !_glmwfw_DescribePixelFormat( winPtr->platformWindow->DC, PixelFormat, sizeof(pfd), &pfd ) )
    {
        return GL_FALSE;
    }

    // "stereo" is a strict requirement
    if( hints->Stereo && !(pfd.dwFlags & PFD_STEREO) )
    {
        return GL_FALSE;
    }

    // Set the pixel-format
    if( !_glmwfw_SetPixelFormat( winPtr->platformWindow->DC, PixelFormat, &pfd ) )
    {
        return GL_FALSE;
    }

    return GL_TRUE;
}


//========================================================================
// Sets the device context pixel format using attributes
//========================================================================

#define _glmwfwSetWGLAttribute( _glmwfwName, _glmwfwValue ) \
    attribs[ count++ ] = _glmwfwName; \
    attribs[ count++ ] = _glmwfwValue;

static int _glmwfwSetPixelFormatAttrib( GlmwfwWindow *winPtr, int redbits, int greenbits, int bluebits,
                                      int alphabits, int depthbits, int stencilbits,
                                      int mode, _GlmwfwHints* hints )
{
    int PixelFormat, dummy, count = 0;
    int attribs[128];
    PIXELFORMATDESCRIPTOR pfd;
    
    int accumredbits = hints->AccumRedBits;
    int accumgreenbits = hints->AccumGreenBits;
    int accumbluebits = hints->AccumBlueBits;
    int accumalphabits = hints->AccumAlphaBits;

    _glmwfwSetWGLAttribute( WGL_DRAW_TO_WINDOW_ARB, GL_TRUE );
    _glmwfwSetWGLAttribute( WGL_ACCELERATION_ARB,   WGL_FULL_ACCELERATION_ARB );
    _glmwfwSetWGLAttribute( WGL_SUPPORT_OPENGL_ARB, GL_TRUE );
    _glmwfwSetWGLAttribute( WGL_DOUBLE_BUFFER_ARB,  GL_TRUE );
    _glmwfwSetWGLAttribute( WGL_COLOR_BITS_ARB,     redbits + greenbits + bluebits );
    _glmwfwSetWGLAttribute( WGL_RED_BITS_ARB,       redbits );
    _glmwfwSetWGLAttribute( WGL_GREEN_BITS_ARB,     greenbits );
    _glmwfwSetWGLAttribute( WGL_BLUE_BITS_ARB,      bluebits );
    _glmwfwSetWGLAttribute( WGL_ALPHA_BITS_ARB,     alphabits );
    _glmwfwSetWGLAttribute( WGL_DEPTH_BITS_ARB,     depthbits );
    _glmwfwSetWGLAttribute( WGL_STENCIL_BITS_ARB,   stencilbits );
    _glmwfwSetWGLAttribute( WGL_AUX_BUFFERS_ARB,    hints->AuxBuffers );
    
    if( accumredbits || accumgreenbits || accumbluebits || accumalphabits )
    {
        _glmwfwSetWGLAttribute( WGL_ACCUM_BITS_ARB, accumredbits +
                                                  accumgreenbits +
                                                  accumbluebits +
                                                  accumalphabits );

        _glmwfwSetWGLAttribute( WGL_ACCUM_RED_BITS_ARB, accumredbits );
        _glmwfwSetWGLAttribute( WGL_ACCUM_GREEN_BITS_ARB, accumgreenbits );
        _glmwfwSetWGLAttribute( WGL_ACCUM_BLUE_BITS_ARB, accumbluebits );
        _glmwfwSetWGLAttribute( WGL_ACCUM_ALPHA_BITS_ARB, accumalphabits );
    }

    if( hints->Stereo )
    {
        _glmwfwSetWGLAttribute( WGL_STEREO_ARB, GL_TRUE );
    }

    if( hints->Samples > 0 )
    {
        _glmwfwSetWGLAttribute( WGL_SAMPLE_BUFFERS_ARB, 1 );
        _glmwfwSetWGLAttribute( WGL_SAMPLES_ARB, hints->Samples );
    }

    _glmwfwSetWGLAttribute( 0, 0 );

    if( !winPtr->platformWindow->ChoosePixelFormat( winPtr->platformWindow->DC, attribs, NULL, 1, &PixelFormat, &dummy ) )
    {
        return GL_FALSE;
    }

    if( !_glmwfw_DescribePixelFormat( winPtr->platformWindow->DC, PixelFormat, sizeof(pfd), &pfd ) )
    {
        return GL_FALSE;
    }

    // Set the pixel-format
    if( !_glmwfw_SetPixelFormat( winPtr->platformWindow->DC, PixelFormat, &pfd ) )
    {
        return GL_FALSE;
    }

    return GL_TRUE; 
}

#undef _glmwfwSetWGLAttribute


//========================================================================
// Translates a Windows key to the corresponding GLMWFW key
//========================================================================

static int _glmwfwTranslateKey( WPARAM wParam, LPARAM lParam )
{
    MSG next_msg;
    DWORD msg_time;
    DWORD scan_code;

    // Check which key was pressed or released
    switch( wParam )
    {
        // The SHIFT keys require special handling
        case VK_SHIFT:
            // Compare scan code for this key with that of VK_RSHIFT in
            // order to determine which shift key was pressed (left or
            // right)
            scan_code = MapVirtualKey( VK_RSHIFT, 0 );
            if( ((lParam & 0x01ff0000) >> 16) == scan_code )
            {
                return GLMWFW_KEY_RSHIFT;
            }
            return GLMWFW_KEY_LSHIFT;

        // The CTRL keys require special handling
        case VK_CONTROL:
            // Is this an extended key (i.e. right key)?
            if( lParam & 0x01000000 )
            {
                return GLMWFW_KEY_RCTRL;
            }
            // Here is a trick: "Alt Gr" sends LCTRL, then RALT. We only
            // want the RALT message, so we try to see if the next message
            // is a RALT message. In that case, this is a false LCTRL!
            msg_time = GetMessageTime();
            if( PeekMessage( &next_msg, NULL, 0, 0, PM_NOREMOVE ) )
            {
                if( next_msg.message == WM_KEYDOWN ||
                    next_msg.message == WM_SYSKEYDOWN )
                {
                    if( next_msg.wParam == VK_MENU &&
                        (next_msg.lParam & 0x01000000) &&
                        next_msg.time == msg_time )
                    {
                        // Next message is a RALT down message, which
                        // means that this is NOT a proper LCTRL message!
                        return GLMWFW_KEY_UNKNOWN;
                    }
                }
            }
            return GLMWFW_KEY_LCTRL;

        // The ALT keys require special handling
        case VK_MENU:
            // Is this an extended key (i.e. right key)?
            if( lParam & 0x01000000 )
            {
                return GLMWFW_KEY_RALT;
            }
            return GLMWFW_KEY_LALT;

        // The ENTER keys require special handling
        case VK_RETURN:
            // Is this an extended key (i.e. right key)?
            if( lParam & 0x01000000 )
            {
                return GLMWFW_KEY_KP_ENTER;
            }
            return GLMWFW_KEY_ENTER;

        // Special keys (non character keys)
        case VK_ESCAPE:        return GLMWFW_KEY_ESC;
        case VK_TAB:           return GLMWFW_KEY_TAB;
        case VK_BACK:          return GLMWFW_KEY_BACKSPACE;
        case VK_HOME:          return GLMWFW_KEY_HOME;
        case VK_END:           return GLMWFW_KEY_END;
        case VK_PRIOR:         return GLMWFW_KEY_PAGEUP;
        case VK_NEXT:          return GLMWFW_KEY_PAGEDOWN;
        case VK_INSERT:        return GLMWFW_KEY_INSERT;
        case VK_DELETE:        return GLMWFW_KEY_DEL;
        case VK_LEFT:          return GLMWFW_KEY_LEFT;
        case VK_UP:            return GLMWFW_KEY_UP;
        case VK_RIGHT:         return GLMWFW_KEY_RIGHT;
        case VK_DOWN:          return GLMWFW_KEY_DOWN;
        case VK_F1:            return GLMWFW_KEY_F1;
        case VK_F2:            return GLMWFW_KEY_F2;
        case VK_F3:            return GLMWFW_KEY_F3;
        case VK_F4:            return GLMWFW_KEY_F4;
        case VK_F5:            return GLMWFW_KEY_F5;
        case VK_F6:            return GLMWFW_KEY_F6;
        case VK_F7:            return GLMWFW_KEY_F7;
        case VK_F8:            return GLMWFW_KEY_F8;
        case VK_F9:            return GLMWFW_KEY_F9;
        case VK_F10:           return GLMWFW_KEY_F10;
        case VK_F11:           return GLMWFW_KEY_F11;
        case VK_F12:           return GLMWFW_KEY_F12;
        case VK_F13:           return GLMWFW_KEY_F13;
        case VK_F14:           return GLMWFW_KEY_F14;
        case VK_F15:           return GLMWFW_KEY_F15;
        case VK_F16:           return GLMWFW_KEY_F16;
        case VK_F17:           return GLMWFW_KEY_F17;
        case VK_F18:           return GLMWFW_KEY_F18;
        case VK_F19:           return GLMWFW_KEY_F19;
        case VK_F20:           return GLMWFW_KEY_F20;
        case VK_F21:           return GLMWFW_KEY_F21;
        case VK_F22:           return GLMWFW_KEY_F22;
        case VK_F23:           return GLMWFW_KEY_F23;
        case VK_F24:           return GLMWFW_KEY_F24;
        case VK_SPACE:         return GLMWFW_KEY_SPACE;

        // Numeric keypad
        case VK_NUMPAD0:       return GLMWFW_KEY_KP_0;
        case VK_NUMPAD1:       return GLMWFW_KEY_KP_1;
        case VK_NUMPAD2:       return GLMWFW_KEY_KP_2;
        case VK_NUMPAD3:       return GLMWFW_KEY_KP_3;
        case VK_NUMPAD4:       return GLMWFW_KEY_KP_4;
        case VK_NUMPAD5:       return GLMWFW_KEY_KP_5;
        case VK_NUMPAD6:       return GLMWFW_KEY_KP_6;
        case VK_NUMPAD7:       return GLMWFW_KEY_KP_7;
        case VK_NUMPAD8:       return GLMWFW_KEY_KP_8;
        case VK_NUMPAD9:       return GLMWFW_KEY_KP_9;
        case VK_DIVIDE:        return GLMWFW_KEY_KP_DIVIDE;
        case VK_MULTIPLY:      return GLMWFW_KEY_KP_MULTIPLY;
        case VK_SUBTRACT:      return GLMWFW_KEY_KP_SUBTRACT;
        case VK_ADD:           return GLMWFW_KEY_KP_ADD;
        case VK_DECIMAL:       return GLMWFW_KEY_KP_DECIMAL;

        // The rest (should be printable keys)
        default:
            // Convert to printable character (ISO-8859-1 or Unicode)
            wParam = MapVirtualKey( (UINT) wParam, 2 ) & 0x0000FFFF;

            // Make sure that the character is uppercase
            if( _glmwfwLibrary.Sys.HasUnicode )
            {
                wParam = (WPARAM) CharUpperW( (LPWSTR) wParam );
            }
            else
            {
                wParam = (WPARAM) CharUpperA( (LPSTR) wParam );
            }

            // Valid ISO-8859-1 character?
            if( (wParam >=  32 && wParam <= 126) ||
                (wParam >= 160 && wParam <= 255) )
            {
                return (int) wParam;
            }
            return GLMWFW_KEY_UNKNOWN;
    }
}


//========================================================================
// Translates a windows key to Unicode
//========================================================================

static void _glmwfwTranslateChar( DWORD wParam, DWORD lParam, int action )
{
    BYTE  keyboard_state[ 256 ];
    UCHAR char_buf[ 10 ];
    WCHAR unicode_buf[ 10 ];
    UINT  scan_code;
    int   i, num_chars, unicode;

    // Get keyboard state
    GetKeyboardState( keyboard_state );

    // Derive scan code from lParam and action
    scan_code = (lParam & 0x01ff0000) >> 16;
    if( action == GLMWFW_RELEASE )
    {
        scan_code |= 0x8000000;
    }

    // Do we have Unicode support?
    if( _glmwfwLibrary.Sys.HasUnicode )
    {
        // Convert to Unicode
        num_chars = ToUnicode(
            wParam,          // virtual-key code
            scan_code,       // scan code
            keyboard_state,  // key-state array
            unicode_buf,     // buffer for translated key
            10,              // size of translated key buffer
            0                // active-menu flag
        );
        unicode = 1;
    }
    else
    {
        // Convert to ISO-8859-1
        num_chars = ToAscii(
            wParam,            // virtual-key code
            scan_code,         // scan code
            keyboard_state,    // key-state array
            (LPWORD) char_buf, // buffer for translated key
            0                  // active-menu flag
        );
        unicode = 0;
    }

    // Report characters
    for( i = 0;  i < num_chars;  i++ )
    {
        // Get next character from buffer
        if( unicode )
        {
            _glmwfwInputChar( (int) unicode_buf[ i ], action );
        }
        else
        {
            _glmwfwInputChar( (int) char_buf[ i ], action );
        }
    }
}


//========================================================================
// Window callback function (handles window events)
//========================================================================

static LRESULT CALLBACK _glmwfwWindowCallback( HWND hWnd, UINT uMsg,
                                             WPARAM wParam, LPARAM lParam )
{
    int WheelDelta, Iconified;

    // Handle certain window messages
    switch( uMsg )
    {
        // Window activate message? (iconification?)
        case WM_ACTIVATE:
        {
            winPtr->Active = LOWORD(wParam) != WA_INACTIVE ? GL_TRUE : GL_FALSE;

            Iconified = HIWORD(wParam) ? GL_TRUE : GL_FALSE;

            // Were we deactivated/iconified?
            if( (!winPtr->Active || Iconified) && !winPtr->Iconified )
            {
                _glmwfwInputDeactivation();

                // If we are in fullscreen mode we need to iconify
                if( winPtr->Opened && winPtr->Fullscreen )
                {
                    // Do we need to manually iconify?
                    if( !Iconified )
                    {
                        // Minimize window
                        CloseWindow( winPtr->platformWindow->Wnd );

                        // The window is now iconified
                        Iconified = GL_TRUE;
                    }

                    // Change display settings to the desktop resolution
                    ChangeDisplaySettings( NULL, CDS_FULLSCREEN );
                }

                // Unlock mouse
                if( !winPtr->platformWindow->OldMouseLockValid )
                {
                    winPtr->platformWindow->OldMouseLock = winPtr->MouseLock;
                    winPtr->platformWindow->OldMouseLockValid = GL_TRUE;
                    glfwEnable( GLMWFW_MOUSE_CURSOR );
                }
            }
            else if( winPtr->Active || !Iconified )
            {
                // If we are in fullscreen mode we need to maximize
                if( winPtr->Opened && winPtr->Fullscreen && winPtr->Iconified )
                {
                    // Change display settings to the user selected mode
                    _glmwfwSetVideoModeMODE( winPtr->platformWindow->ModeID );

                    // Do we need to manually restore window?
                    if( Iconified )
                    {
                        // Restore window
                        OpenIcon( winPtr->platformWindow->Wnd );

                        // The window is no longer iconified
                        Iconified = GL_FALSE;

                        // Activate window
                        ShowWindow( hWnd, SW_SHOW );
                        _glmwfwSetForegroundWindow( winPtr->platformWindow->Wnd );
                        SetFocus( winPtr->platformWindow->Wnd );
                    }
                }

                // Lock mouse, if necessary
                if( winPtr->platformWindow->OldMouseLockValid && winPtr->platformWindow->OldMouseLock )
                {
                    glfwDisable( GLMWFW_MOUSE_CURSOR );
                }
                winPtr->platformWindow->OldMouseLockValid = GL_FALSE;
            }

            winPtr->Iconified = Iconified;
            return 0;
        }

        // Intercept system commands (forbid certain actions/events)
        case WM_SYSCOMMAND:
        {
            switch( wParam )
            {
                // Screensaver trying to start or monitor trying to enter
                // powersave?
                case SC_SCREENSAVE:
                case SC_MONITORPOWER:
                    if( winPtr->Fullscreen )
                    {
                        return 0;
                    }
                    else
                    {
                        break;
                    }

                // User trying to access application menu using ALT?
                case SC_KEYMENU:
                    return 0;
            }
            break;
        }

        // Did we receive a close message?
        case WM_CLOSE:
            PostQuitMessage( 0 );
            return 0;

        // Is a key being pressed?
        case WM_KEYDOWN:
        case WM_SYSKEYDOWN:
        {
            // Translate and report key press
            _glmwfwInputKey( _glmwfwTranslateKey( wParam, lParam ),
                           GLMWFW_PRESS );

#ifdef NOTDEF
            // Translate and report character input
            if( winPtr->charfun )
            {
                _glmwfwTranslateChar( (DWORD) wParam, (DWORD) lParam, GLMWFW_PRESS );
            }
#endif
            return 0;
          }  

        // Is a key being released?
        case WM_KEYUP:
        case WM_SYSKEYUP:
        {
            // Special trick: release both shift keys on SHIFT up event
            if( wParam == VK_SHIFT )
            {
                _glmwfwInputKey( GLMWFW_KEY_LSHIFT, GLMWFW_RELEASE );
                _glmwfwInputKey( GLMWFW_KEY_RSHIFT, GLMWFW_RELEASE );
            }
            else
            {
                // Translate and report key release
                _glmwfwInputKey( _glmwfwTranslateKey( wParam, lParam ),
                               GLMWFW_RELEASE );
            }

#ifdef NOTDEF
            // Translate and report character input
            if( winPtr->charfun )
            {
                _glmwfwTranslateChar( (DWORD) wParam, (DWORD) lParam, GLMWFW_RELEASE );
            }
#endif
            return 0;
        }

        // Were any of the mouse-buttons pressed?
        case WM_LBUTTONDOWN:
            SetCapture(hWnd);
            _glmwfwInputMouseClick( GLMWFW_MOUSE_BUTTON_LEFT, GLMWFW_PRESS );
            return 0;
        case WM_RBUTTONDOWN:
            SetCapture(hWnd);
            _glmwfwInputMouseClick( GLMWFW_MOUSE_BUTTON_RIGHT, GLMWFW_PRESS );
            return 0;
        case WM_MBUTTONDOWN:
            SetCapture(hWnd);
            _glmwfwInputMouseClick( GLMWFW_MOUSE_BUTTON_MIDDLE, GLMWFW_PRESS );
            return 0;
        case WM_XBUTTONDOWN:
        {
            if( HIWORD(wParam) == XBUTTON1 )
            {
                SetCapture(hWnd);
                _glmwfwInputMouseClick( GLMWFW_MOUSE_BUTTON_4, GLMWFW_PRESS );
            }
            else if( HIWORD(wParam) == XBUTTON2 )
            {
                SetCapture(hWnd);
                _glmwfwInputMouseClick( GLMWFW_MOUSE_BUTTON_5, GLMWFW_PRESS );
            }
            return 1;
        }

        // Were any of the mouse-buttons released?
        case WM_LBUTTONUP:
            ReleaseCapture();
            _glmwfwInputMouseClick( GLMWFW_MOUSE_BUTTON_LEFT, GLMWFW_RELEASE );
            return 0;
        case WM_RBUTTONUP:
            ReleaseCapture();
            _glmwfwInputMouseClick( GLMWFW_MOUSE_BUTTON_RIGHT, GLMWFW_RELEASE );
            return 0;
        case WM_MBUTTONUP:
            ReleaseCapture();
            _glmwfwInputMouseClick( GLMWFW_MOUSE_BUTTON_MIDDLE, GLMWFW_RELEASE );
            return 0;
        case WM_XBUTTONUP:
        {
            if( HIWORD(wParam) == XBUTTON1 )
            {
                ReleaseCapture();
                _glmwfwInputMouseClick( GLMWFW_MOUSE_BUTTON_4, GLMWFW_RELEASE );
            }
            else if( HIWORD(wParam) == XBUTTON2 )
            {
                ReleaseCapture();
                _glmwfwInputMouseClick( GLMWFW_MOUSE_BUTTON_5, GLMWFW_RELEASE );
            }
            return 1;
        }

        // Did the mouse move?
        case WM_MOUSEMOVE:
        {
            {
                int NewMouseX, NewMouseY;

                // Get signed (!) mouse position
                NewMouseX = (int)((short)LOWORD(lParam));
                NewMouseY = (int)((short)HIWORD(lParam));

                if( NewMouseX != winPtr->input.platformInput->OldMouseX ||
                    NewMouseY != winPtr->input.platformInput->OldMouseY )
                {
                    if( winPtr->MouseLock )
                    {
                        winPtr->input.MousePosX += NewMouseX -
                                                winPtr->input.platformInput->OldMouseX;
                        winPtr->input.MousePosY += NewMouseY -
                                                winPtr->input.platformInput->OldMouseY;
                    }
                    else
                    {
                        winPtr->input.MousePosX = NewMouseX;
                        winPtr->input.MousePosY = NewMouseY;
                    }
                    winPtr->input.platformInput->OldMouseX = NewMouseX;
                    winPtr->input.platformInput->OldMouseY = NewMouseY;
                    winPtr->input.MouseMoved = GL_TRUE;
    
                    // Call user callback function
                    if( winPtr->mouseposfun )
                    {
                        winPtr->mouseposfun( winPtr, winPtr->input.MousePosX,
                                                   winPtr->input.MousePosY );
                    }
                }
            }
            return 0;
        }

        // Mouse wheel action?
        case WM_MOUSEWHEEL:
        {
            // WM_MOUSEWHEEL is not supported under Windows 95
            if( _glmwfwLibrary.Sys.WinVer != _GLMWFW_WIN_95 )
            {
                WheelDelta = (((int)wParam) >> 16) / WHEEL_DELTA;
                winPtr->input.WheelPos += WheelDelta;
                if( winPtr->mousewheelfun )
                {
                    winPtr->mousewheelfun( winPtr, winPtr->input.WheelPos );
                }
                return 0;
            }
            break;
        }

        // Resize the window?
        case WM_SIZE:
        {
            // get the new size
            winPtr->Width  = LOWORD(lParam);
            winPtr->Height = HIWORD(lParam);

            // If the mouse is locked, update the clipping rect
            if( winPtr->MouseLock )
            {
                RECT ClipWindowRect;
                if( GetWindowRect( winPtr->platformWindow->Wnd, &ClipWindowRect ) )
                {
                    ClipCursor( &ClipWindowRect );
                }
            }

            // Call the user-supplied callback, if it exists
            if( winPtr->windowsizefun )
            {
                winPtr->windowsizefun( LOWORD(lParam),
                                             HIWORD(lParam) );
            }
            return 0;
        }

        // Move the window?
        case WM_MOVE:
        {
            // If the mouse is locked, update the clipping rect
            if( winPtr->MouseLock )
            {
                RECT ClipWindowRect;
                if( GetWindowRect( winPtr->platformWindow->Wnd, &ClipWindowRect ) )
                {
                    ClipCursor( &ClipWindowRect );
                }
            }
            return 0;
        }

        // Was the window contents damaged?
        case WM_PAINT:
        {
            // Call user callback function
            if( winPtr->windowrefreshfun )
            {
                winPtr->windowrefreshfun(winPtr);
            }
            break;
        }

	case WM_DISPLAYCHANGE:
	{
	    // TODO: Do stuff here.

	    break;
	}
    }

    // Pass all unhandled messages to DefWindowProc
    return DefWindowProc( hWnd, uMsg, wParam, lParam );
}


//========================================================================
// Translate client window size to full window size (including window borders)
//========================================================================

static void _glmwfwGetFullWindowSize( int w, int h, int *w2, int *h2 )
{
    RECT rect;

    // Create a window rectangle
    rect.left   = (long)0;
    rect.right  = (long)w-1;
    rect.top    = (long)0;
    rect.bottom = (long)h-1;

    // Adjust according to window styles
    AdjustWindowRectEx( &rect, winPtr->platformWindow->dwStyle, FALSE,
                        winPtr->platformWindow->dwExStyle );

    // Calculate width and height of full window
    *w2 = rect.right-rect.left+1;
    *h2 = rect.bottom-rect.top+1;
}


//========================================================================
// Initialize WGL-specific extensions
//========================================================================

static void _glmwfwInitWGLExtensions( void )
{
    GLubyte *extensions;
    int     has_swap_control, has_pixel_format;

    winPtr->platformWindow->GetExtensionsStringEXT = (WGLGETEXTENSIONSSTRINGEXT_T)
        wglGetProcAddress( "wglGetExtensionsStringEXT" );
    if( !winPtr->platformWindow->GetExtensionsStringEXT )
    {
	// Try wglGetExtensionsStringARB
	winPtr->platformWindow->GetExtensionsStringARB = (WGLGETEXTENSIONSSTRINGARB_T)
	    wglGetProcAddress( "wglGetExtensionsStringARB" );
	if( !winPtr->platformWindow->GetExtensionsStringARB )
	{
	    return;
	}
    }

    // Initialize OpenGL extension: WGL_EXT_swap_control
    has_swap_control = GL_FALSE;
    has_pixel_format = GL_FALSE;
    extensions = (GLubyte *) glGetString( GL_EXTENSIONS );

    if( extensions != NULL )
    {
        has_swap_control = _glmwfwStringInExtensionString(
                               "WGL_EXT_swap_control",
                               extensions
                           );
        has_pixel_format = _glmwfwStringInExtensionString(
                               "WGL_ARB_pixel_format",
                               extensions
                           );
    }

    if( !has_swap_control )
    {
        has_swap_control = _glmwfwPlatformExtensionSupported(
                               "WGL_EXT_swap_control"
                           );
    }

    if( !has_pixel_format )
    {
        has_pixel_format = _glmwfwPlatformExtensionSupported(
                               "WGL_ARB_pixel_format"
                           );
    }

    if( has_swap_control )
    {
        winPtr->platformWindow->SwapInterval = (WGLSWAPINTERVALEXT_T)
            wglGetProcAddress( "wglSwapIntervalEXT" );
    }
    else
    {
        winPtr->platformWindow->SwapInterval = NULL;
    }
    
    if( has_pixel_format )
    {
        winPtr->platformWindow->ChoosePixelFormat = (WGLCHOOSEPIXELFORMATARB_T)
            wglGetProcAddress( "wglChoosePixelFormatARB" );
        winPtr->platformWindow->GetPixelFormatAttribiv = (WGLGETPIXELFORMATATTRIBIVARB_T)
            wglGetProcAddress( "wglGetPixelFormatAttribivARB" );
    }
    else
    {
        winPtr->platformWindow->ChoosePixelFormat = NULL;
        winPtr->platformWindow->GetPixelFormatAttribiv = NULL;
    }  
}


//========================================================================
// Creates the GLMWFW window and rendering context
//========================================================================

static int _glmwfwCreateWindow( GlmwfwWindow *winPtr, int redbits, int greenbits, int bluebits,
                              int alphabits, int depthbits, int stencilbits,
                              int mode, _GLMWFWhints* hints )
{
    int    full_width, full_height;
    RECT   wa;
    POINT  pos;

    winPtr->platformWindow->DC  = NULL;
    winPtr->platformWindow->RC  = NULL;
    winPtr->platformWindow->Wnd = NULL;

    // Set window size to true requested size (adjust for window borders)
    _glmwfwGetFullWindowSize( winPtr->Width, winPtr->Height, &full_width,
                            &full_height );

    // Adjust window position to working area (e.g. if the task bar is at
    // the top of the display). Fullscreen windows are always opened in
    // the upper left corner regardless of the desktop working area. 
    if( winPtr->platformWindow->Fullscreen )
    {
        wa.left = wa.top = 0;
    }
    else
    {
        SystemParametersInfo( SPI_GETWORKAREA, 0, &wa, 0 );
    }

    // Create window
    winPtr->platformWindow->Wnd = CreateWindowEx(
               winPtr->platformWindow->dwExStyle,        // Extended style
               _GLMWFW_WNDCLASSNAME,        // Class name
               "GLMWFW Window",             // Window title
               winPtr->platformWindow->dwStyle,          // Defined window style
               wa.left, wa.top,           // Window position
               full_width,                // Decorated window width
               full_height,               // Decorated window height
               NULL,                      // No parent window
               NULL,                      // No menu
               _glmwfwLibrary.Instance,     // Instance
               NULL );                    // Nothing to WM_CREATE

    if( !winPtr->platformWindow->Wnd )
    {
        return GL_FALSE;
    }

    // Get a device context
    winPtr->platformWindow->DC = GetDC( winPtr->platformWindow->Wnd );
    if( !winPtr->platformWindow->DC )
    {
        return GL_FALSE;
    }

    if( winPtr->platformWindow->ChoosePixelFormat )
    {
        if( !_glmwfwSetPixelFormatAttrib( winPtr, redbits, greenbits, bluebits, alphabits,
                                        depthbits, stencilbits, mode, hints ) )
        {
            return GL_FALSE;
        }
    }
    else
    {
        if( !_glmwfwSetPixelFormatPFD( winPtr, redbits, greenbits, bluebits, alphabits,
                                     depthbits, stencilbits, mode, hints ) )
        {
            return GL_FALSE;
        }
    }

    // Get a rendering context
    winPtr->platformWindow->RC = wglCreateContext( winPtr->platformWindow->DC );
    if( !winPtr->platformWindow->RC )
    {
        return GL_FALSE;
    }

    // Activate the OpenGL rendering context
    if( !wglMakeCurrent( winPtr->platformWindow->DC, winPtr->platformWindow->RC ) )
    {
        return GL_FALSE;
    }

    // Initialize WGL-specific OpenGL extensions
    _glmwfwInitWGLExtensions();

    // Initialize mouse position
    GetCursorPos( &pos );
    ScreenToClient( winPtr->platformWindow->Wnd, &pos );
    winPtr->input.platformInput->OldMouseX = winPtr->input.MousePosX = pos.x;
    winPtr->input.platformInput->OldMouseY = winPtr->input.MousePosY = pos.y;

    return GL_TRUE;
}


//========================================================================
// Destroys the GLMWFW window and rendering context
//========================================================================

static void _glmwfwDestroyWindow( GlmwfwWindow *winPtr )
{
    // Do we have a rendering context?
    if( winPtr->platformWindow->RC )
    {
        // Release the DC and RC contexts
        wglMakeCurrent( NULL, NULL );

        // Delete the rendering context
        wglDeleteContext( winPtr->platformWindow->RC );
        winPtr->platformWindow->RC = NULL;
    }

    // Do we have a device context?
    if( winPtr->platformWindow->DC )
    {
        // Release the device context
        ReleaseDC( winPtr->platformWindow->Wnd, winPtr->platformWindow->DC );
        winPtr->platformWindow->DC = NULL;
    }

    // Do we have a window?
    if( winPtr->platformWindow->Wnd )
    {
        // Destroy the window
        if( _glmwfwLibrary.Sys.WinVer <= _GLMWFW_WIN_NT4 )
        {
            // Note: Hiding the window first fixes an annoying W98/NT4
            // remaining icon bug for fullscreen displays
            ShowWindow( winPtr->platformWindow->Wnd, SW_HIDE );
        }

        DestroyWindow( winPtr->platformWindow->Wnd );
        winPtr->platformWindow->Wnd = NULL;
    }
}



//************************************************************************
//****               Platform implementation functions                ****
//************************************************************************

//========================================================================
// Here is where the window is created, and the OpenGL rendering context is
// created
//========================================================================

GlmwfwWindow * _glmwfwPlatformOpenWindow( int width, int height,
                             int redbits, int greenbits, int bluebits,
                             int alphabits, int depthbits, int stencilbits,
                             int mode, _GLMWFWhints* hints )
{
    WNDCLASS    wc;
    DWORD  dwStyle, dwExStyle;

    winPtr->platformWindow = (_GlmwfwPlatformWindow *)
            ckalloc(sizeof(_GlmwfwPlatformWindow));
    winPtr->input.platformInput = (_GlmwfwPlatformInput *)
            ckalloc(sizeof(_GlmwfwPlatformInput));
    // Clear platform specific GLMWFW window state
    winPtr->platformWindow->ClassAtom         = 0;
    winPtr->platformWindow->OldMouseLockValid = GL_FALSE;
    winPtr->platformWindow->ChoosePixelFormat = NULL;
    winPtr->platformWindow->GetPixelFormatAttribiv = NULL;

    // Remember desired refresh rate for this window (used only in
    // fullscreen mode)
    winPtr->platformWindow->DesiredRefreshRate = hints->RefreshRate;

    // Set window class parameters
    wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; // Redraw on...
    wc.lpfnWndProc   = (WNDPROC)_glmwfwWindowCallback;  // Message handler
    wc.cbClsExtra    = 0;                             // No extra class data
    wc.cbWndExtra    = 0;                             // No extra window data
    wc.hInstance     = _glmwfwLibrary.Instance;         // Set instance
    wc.hCursor       = LoadCursor( NULL, IDC_ARROW ); // Load arrow pointer
    wc.hbrBackground = NULL;                          // No background
    wc.lpszMenuName  = NULL;                          // No menu
    wc.lpszClassName = _GLMWFW_WNDCLASSNAME;            // Set class name

    // Load user-provided icon if available
    wc.hIcon = LoadIcon( _glmwfwLibrary.Instance, "GLMWFW_ICON" );
    if( !wc.hIcon )
    {
        // Load default icon
        wc.hIcon = LoadIcon( NULL, IDI_WINLOGO ); 
    }

    // Register the window class
    winPtr->platformWindow->ClassAtom = RegisterClass( &wc );
    if( !winPtr->platformWindow->ClassAtom )
    {
        _glmwfwPlatformCloseWindow(winPtr);
        return GL_FALSE;
    }

    // Do we want full-screen mode?
    if( winPtr->Fullscreen )
    {
        _glmwfwSetVideoMode( winPtr, &winPtr->Width, &winPtr->Height,
                           redbits, greenbits, bluebits,
                           hints->RefreshRate );
    }

    // Set common window styles
    dwStyle   = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE;
    dwExStyle = WS_EX_APPWINDOW;

    // Set window style, depending on fullscreen mode
    if( winPtr->Fullscreen )
    {
        dwStyle |= WS_POPUP;

        // Here's a trick for helping us getting window focus
        // (SetForegroundWindow doesn't work properly under
        // Win98/ME/2K/.NET/+)
	/*
        if( _glmwfwLibrary.Sys.WinVer != _GLMWFW_WIN_95 &&
            _glmwfwLibrary.Sys.WinVer != _GLMWFW_WIN_NT4 && 
            _glmwfwLibrary.Sys.WinVer != _GLMWFW_WIN_XP )
        {
            dwStyle |= WS_MINIMIZE;
        }
	*/
    }
    else
    {
        dwStyle |= WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;

        if( !hints->WindowNoResize )
        {
            dwStyle |= ( WS_MAXIMIZEBOX | WS_SIZEBOX );
            dwExStyle |= WS_EX_WINDOWEDGE;
        }
    }

    // Remember window styles (used by _glmwfwGetFullWindowSize)
    winPtr->platformWindow->dwStyle   = dwStyle;
    winPtr->platformWindow->dwExStyle = dwExStyle;

    if( !_glmwfwCreateWindow( winPtr, redbits, greenbits, bluebits, alphabits,
                            depthbits, stencilbits, mode, hints ) )
    {
        _glmwfwPlatformCloseWindow(winPtr);
        return GL_FALSE;
    }

    if( winPtr->platformWindow->ChoosePixelFormat && hints->Samples > 0 )
    {
	// Iteratively try to create a context with a decreasing number of
	// FSAA samples (requires window recreation).

        for (;;)
        {
            _glmwfwDestroyWindow(winPtr);

            if( _glmwfwCreateWindow( winPtr, redbits, greenbits, bluebits, alphabits,
                                   depthbits, stencilbits, mode, hints ) )
            {
                break;
            }

            if( hints->Samples > 0 )
            {
                hints->Samples--;
            }
            else
            {
                _glmwfwPlatformCloseWindow(winPtr);
                return GL_FALSE;
            }
        }
    }

    // Make sure that our window ends up on top of things
    if( winPtr->Fullscreen )
    {
        // Place the window above all topmost windows
        SetWindowPos( winPtr, winPtr->platformWindow->Wnd, HWND_TOPMOST, 0,0,0,0,
                      SWP_NOMOVE | SWP_NOSIZE );
    }
    _glmwfwSetForegroundWindow( winPtr, winPtr->platformWindow->Wnd );
    SetFocus( winPtr->platformWindow->Wnd );

    // Start by clearing the front buffer to black (avoid ugly desktop
    // remains in our OpenGL window)
    glClear( GL_COLOR_BUFFER_BIT );
    _glmwfw_SwapBuffers( winPtr, winPtr->platformWindow->DC );

    return GL_TRUE;
}


//========================================================================
// Properly kill the window / video display
//========================================================================

int _glmwfwPlatformCloseWindow( GlmwfwWindow *winPtr )
{
    _glmwfwDestroyWindow(winPtr);

    // Do we have an instance?
    if( winPtr->platformWindow->ClassAtom )
    {
        // Unregister class
        UnregisterClass( _GLMWFW_WNDCLASSNAME, _glmwfwLibrary.Instance );
        winPtr->platformWindow->ClassAtom = 0;
    }

    // Are we in fullscreen mode?
    if( winPtr->Fullscreen )
    {
        // Switch back to desktop resolution
        ChangeDisplaySettings( NULL, CDS_FULLSCREEN );
    }
}


//========================================================================
// Set the window title
//========================================================================

int _glmwfwPlatformSetWindowTitle( GlmwfwWindow *winPtr, const char *title )
{
    // Set window title
    (void) SetWindowText( winPtr->platformWindow->Wnd, title );
    return TCL_OK;
}


//========================================================================
// Set the window size.
//========================================================================

int _glmwfwPlatformSetWindowSize( GlmwfwWindow *winPtr, int width, int height )
{
    int     bpp, mode = 0, refresh;
    int     sizechanged = GL_FALSE;
    GLint   drawbuffer;
    GLfloat clearcolor[4];

    // If we are in fullscreen mode, get some info about the current mode
    if( winPtr->Fullscreen )
    {
        DEVMODE dm;

        // Get current BPP settings
        dm.dmSize = sizeof( DEVMODE );
        if( EnumDisplaySettings( NULL, winPtr->platformWindow->ModeID, &dm ) )
        {
            // Get bpp
            bpp = dm.dmBitsPerPel;

            // Get closest match for target video mode
            refresh = winPtr->platformWindow->DesiredRefreshRate;
            mode = _glmwfwGetClosestVideoModeBPP( &width, &height, &bpp,
                                                &refresh );
        }
        else
        {
            mode = winPtr->platformWindow->ModeID;
        }
    }
    else
    {
        // If we are in windowed mode, adjust the window size to
        // compensate for window decorations
        _glmwfwGetFullWindowSize( winPtr, width, height, &width, &height );
    }

    // Change window size before changing fullscreen mode?
    if( winPtr->platformWindow->Fullscreen && (width > winPtr->platformWindow->Width) )
    {
        SetWindowPos( winPtr->platformWindow->Wnd, HWND_TOP, 0, 0, width, height,
                      SWP_NOOWNERZORDER | SWP_NOMOVE | SWP_NOZORDER );
        sizechanged = GL_TRUE;
    }

    // Change fullscreen video mode?
    if( winPtr->Fullscreen && mode != winPtr->platformWindow->ModeID )
    {
        // Change video mode
        _glmwfwSetVideoModeMODE( winPtr, mode );

        // Clear the front buffer to black (avoid ugly desktop remains in
        // our OpenGL window)
        glGetIntegerv( GL_DRAW_BUFFER, &drawbuffer );
        glGetFloatv( GL_COLOR_CLEAR_VALUE, clearcolor );
        glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
        glClear( GL_COLOR_BUFFER_BIT );
        if( drawbuffer == GL_BACK )
        {
            _glmwfw_SwapBuffers( winPtr, winPtr->platformWindow->DC );
        }
        glClearColor( clearcolor[0], clearcolor[1], clearcolor[2],
                      clearcolor[3] );
    }

    // Set window size (if not already changed)
    if( !sizechanged )
    {
        SetWindowPos( winPtr, winPtr->platformWindow->Wnd, HWND_TOP, 0, 0, width, height,
                      SWP_NOOWNERZORDER | SWP_NOMOVE | SWP_NOZORDER );
    }
    return TCL_OK;
}


//========================================================================
// Set the window position
//========================================================================

void _glmwfwPlatformSetWindowPos( int x, int y )
{
    // Set window position
    (void) SetWindowPos( winPtr->platformWindow->Wnd, HWND_TOP, x, y, 0, 0,
                         SWP_NOOWNERZORDER | SWP_NOSIZE | SWP_NOZORDER );
}


//========================================================================
// Window iconification
//========================================================================

int _glmwfwPlatformIconifyWindow( GlmwfwWindow *winPtr )
{
    // Iconify window
    CloseWindow( winPtr->platformWindow->Wnd );

    // Window is now iconified
    winPtr->platformWindow->Iconified = GL_TRUE;

    // If we are in fullscreen mode we need to change video modes
    if( winPtr->Fullscreen )
    {
        // Change display settings to the desktop resolution
        ChangeDisplaySettings( NULL, CDS_FULLSCREEN );
    }

    // Unlock mouse
    if( !winPtr->platformWindow->OldMouseLockValid )
    {
        winPtr->platformWindow->OldMouseLock = winPtr->MouseLock;
        winPtr->platformWindow->OldMouseLockValid = GL_TRUE;
        glfwEnable( GLMWFW_MOUSE_CURSOR );
    }
    return TCL_OK;
}


//========================================================================
// Window un-iconification
//========================================================================

int _glmwfwPlatformRestoreWindow( GlmwfwWindow *winPtr )
{
    // If we are in fullscreen mode we need to change video modes
    if( winPtr->Fullscreen )
    {
        // Change display settings to the user selected mode
        _glmwfwSetVideoModeMODE( winPtr, winPtr->platformWindow->ModeID );
    }

    // Un-iconify window
    OpenIcon( winPtr->platformWindow->Wnd );

    // Make sure that our window ends up on top of things
    ShowWindow( winPtr->platformWindow->Wnd, SW_SHOW );
    _glmwfwSetForegroundWindow( winPtr->platformWindow->Wnd );
    SetFocus( winPtr->platformWindow->Wnd );

    // Window is no longer iconified
    winPtr->Iconified = GL_FALSE;

    // Lock mouse, if necessary
    if( winPtr->platformWindow->OldMouseLockValid && winPtr->platformWindow->OldMouseLock )
    {
        glfwDisable( GLMWFW_MOUSE_CURSOR );
    }
    winPtr->platformWindow->OldMouseLockValid = GL_FALSE;
    return TCL_OK;
}


//========================================================================
// Swap buffers (double-buffering)
//========================================================================

int _glmwfwPlatformSwapBuffers( GlmwfwWindow *winPtr )
{
    _glmwfw_SwapBuffers( winPtr, winPtr->platformWindow->DC );
    return TCL_OK;
}


//========================================================================
// Set double buffering swap interval
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
// Write back window parameters into GLMWFW window structure
//========================================================================

int _glmwfwPlatformRefreshWindowParams( GlmwfwWindow *winPtr )
{
    PIXELFORMATDESCRIPTOR pfd;
    DEVMODE dm;
    int     PixelFormat, mode;

    // Obtain a detailed description of current pixel format
    PixelFormat = _glmwfw_GetPixelFormat( winPtr->platformWindow->DC );

    if( !winPtr->platformWindow->GetPixelFormatAttribiv )
    {
        _glmwfw_DescribePixelFormat( winPtr->platformWindow->DC, PixelFormat,
                                   sizeof(PIXELFORMATDESCRIPTOR), &pfd );

        // Is current OpenGL context accelerated?
        winPtr->platformWindow->Accelerated = (pfd.dwFlags & PFD_GENERIC_ACCELERATED) ||
                               !(pfd.dwFlags & PFD_GENERIC_FORMAT) ? 1 : 0;

        // "Standard" window parameters
        winPtr->RedBits        = pfd.cRedBits;
        winPtr->GreenBits      = pfd.cGreenBits;
        winPtr->BlueBits       = pfd.cBlueBits;
        winPtr->AlphaBits      = pfd.cAlphaBits;
        winPtr->DepthBits      = pfd.cDepthBits;
        winPtr->StencilBits    = pfd.cStencilBits;
        winPtr->Hints.AccumRedBits   = pfd.cAccumRedBits;
        winPtr->Hints.AccumGreenBits = pfd.cAccumGreenBits;
        winPtr->Hints.AccumBlueBits  = pfd.cAccumBlueBits;
        winPtr->Hints.AccumAlphaBits = pfd.cAccumAlphaBits;
        winPtr->Hints.AuxBuffers     = pfd.cAuxBuffers;
        winPtr->Hints.Stereo         = pfd.dwFlags & PFD_STEREO ? 1 : 0;
        winPtr->Hints.Samples        = 0;
    }
    else
    {
        const int attribs[] = {
            WGL_ACCELERATION_ARB,
            WGL_RED_BITS_ARB,
            WGL_GREEN_BITS_ARB,
            WGL_BLUE_BITS_ARB,
            WGL_ALPHA_BITS_ARB,
            WGL_DEPTH_BITS_ARB,
            WGL_STENCIL_BITS_ARB,
            WGL_ACCUM_RED_BITS_ARB,
            WGL_ACCUM_GREEN_BITS_ARB,
            WGL_ACCUM_BLUE_BITS_ARB,
            WGL_ACCUM_ALPHA_BITS_ARB,
            WGL_AUX_BUFFERS_ARB,
            WGL_STEREO_ARB,
            WGL_SAMPLES_ARB
        };

        int values[sizeof(attribs) / sizeof(attribs[0])];

        winPtr->platformWindow->GetPixelFormatAttribiv( winPtr->platformWindow->DC, PixelFormat, 0, 
                                         sizeof(attribs) / sizeof(attribs[0]), 
                                         attribs, values);

        // Is current OpenGL context accelerated?
        winPtr->platformWindow->Accelerated = (values[0] == WGL_FULL_ACCELERATION_ARB);

        // "Standard" window parameters
        winPtr->RedBits        = values[1];
        winPtr->GreenBits      = values[2];
        winPtr->BlueBits       = values[3];
        winPtr->AlphaBits      = values[4];
        winPtr->DepthBits      = values[5];
        winPtr->StencilBits    = values[6];
        winPtr->Hints.AccumRedBits   = values[7];
        winPtr->Hints.AccumGreenBits = values[8]; 
        winPtr->Hints.AccumBlueBits  = values[9];
        winPtr->Hints.AccumAlphaBits = values[10];
        winPtr->Hints.AuxBuffers     = values[11];
        winPtr->Hints.Stereo         = values[12];
        winPtr->Hints.Samples        = values[13];
    }

    // Get refresh rate
    mode = winPtr->Fullscreen ? winPtr->platformWindow->ModeID : ENUM_CURRENT_SETTINGS;
    dm.dmSize = sizeof( DEVMODE );

    if( EnumDisplaySettings( NULL, mode, &dm ) )
    {
        winPtr->RefreshRate = dm.dmDisplayFrequency;
        if( winPtr->RefreshRate <= 1 )
        {
            winPtr->RefreshRate = 0;
        }
    }
    else
    {
        winPtr->RefreshRate = 0;
    }
    return TCL_OK;
}


//========================================================================
// Poll for new window and input events
//========================================================================

int _glmwfwPlatformPollEvents( GlmwfwWindow *winPtr )
{
    MSG msg;
    int winclosed = GL_FALSE;

    // Flag: mouse was not moved (will be changed by _glmwfwGetNextEvent if
    // there was a mouse move event)
    winPtr->input.MouseMoved = GL_FALSE;
    if( winPtr->MouseLock )
    {
        winPtr->input.platformInput->OldMouseX = winPtr->Width/2;
        winPtr->input.platformInput->OldMouseY = winPtr->Height/2;
    }
    else
    {
        winPtr->input.platformInput->OldMouseX = winPtr->input.MousePosX;
        winPtr->input.platformInput->OldMouseY = winPtr->input.MousePosY;
    }

    // Check for new window messages
    while( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
    {
        switch( msg.message )
        {
            // QUIT-message (from close window)?
            case WM_QUIT:
                winclosed = GL_TRUE;
                break;

            // Ok, send it to the window message handler
            default:
                DispatchMessage( &msg );
                break;
        }
    }

    // LSHIFT/RSHIFT fixup (keys tend to "stick" without this fix)
    // This is the only async event handling in GLMWFW, but it solves some
    // nasty problems.
    // Caveat: Does not work under Win 9x/ME.
    if( _glmwfwLibrary.Sys.WinVer >= _GLMWFW_WIN_NT4 )
    {
        int lshift_down, rshift_down;

        // Get current state of left and right shift keys
        lshift_down = (GetAsyncKeyState( VK_LSHIFT ) >> 15) & 1;
        rshift_down = (GetAsyncKeyState( VK_RSHIFT ) >> 15) & 1;

        // See if this differs from our belief of what has happened
        // (we only have to check for lost key up events)
        if( !lshift_down && winPtr->input.Key[ GLMWFW_KEY_LSHIFT ] == 1 )
        {
            _glmwfwInputKey( GLMWFW_KEY_LSHIFT, GLMWFW_RELEASE );
        }
        if( !rshift_down && winPtr->input.Key[ GLMWFW_KEY_RSHIFT ] == 1 )
        {
            _glmwfwInputKey( GLMWFW_KEY_RSHIFT, GLMWFW_RELEASE );
        }
    }

    // Did we have mouse movement in locked cursor mode?
    if( winPtr->input.MouseMoved && winPtr->MouseLock )
    {
        _glmwfwPlatformSetMouseCursorPos( winPtr, winPtr->Width / 2,
                                        winPtr->Height / 2 );
    }

    // Was there a window close request?
    if( winclosed && winPtr->windowclosefun )
    {
        // Check if the program wants us to close the window
        winclosed = winPtr->windowclosefun(winPtr);
    }
    if( winclosed )
    {
        glfwCloseWindow(winPtr);
    }
    return TCL_OK;
}


//========================================================================
// _glmwfwPlatformWaitEvents() - Wait for new window and input events
//========================================================================

int _glmwfwPlatformWaitEvents( GlmwfwWindow *winPtr )
{
    // Wait for new events
    WaitMessage();

    // Poll new events
    _glmwfwPlatformPollEvents(winPtr);
    return TCL_OK;
}


//========================================================================
// Hide mouse cursor (lock it)
//========================================================================

int _glmwfwPlatformHideMouseCursor( GlmwfwWindow *winPtr )
{
    RECT ClipWindowRect;

    // Hide cursor
    ShowCursor( FALSE );

    // Clip cursor to the window
    if( GetWindowRect( winPtr->platformWindow->Wnd, &ClipWindowRect ) )
    {
        ClipCursor( &ClipWindowRect );
    }

    // Capture cursor to user window
    SetCapture( winPtr->platformWindow->Wnd );
    return TCL_OK;
}


//========================================================================
// Show mouse cursor (unlock it)
//========================================================================

int _glmwfwPlatformShowMouseCursor( GlmwfwWindow *winPtr )
{
    // Un-capture cursor
    ReleaseCapture();

    // Disable cursor clipping
    ClipCursor( NULL );

    // Show cursor
    ShowCursor( TRUE );
    return TCL_OK;
}


//========================================================================
// Set physical mouse cursor position
//========================================================================

int _glmwfwPlatformSetMouseCursorPos( GlmwfwWindow *winPtrint x, int y )
{
    POINT pos;

    // Convert client coordinates to screen coordinates
    pos.x = x;
    pos.y = y;
    ClientToScreen( winPtr->platformWindow->Wnd, &pos );

    // Change cursor position
    SetCursorPos( pos.x, pos.y );
    return TCL_OK;
}

