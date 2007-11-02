//========================================================================
// GLFW - An OpenGL framework
// File:        x11_time.c
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
 * RCS: @(#) $Id: x11_time.c,v 1.1.2.1 2007/11/02 15:53:12 wiede Exp $
 */

#include "platform.h"


//========================================================================
// Initialise timer
//========================================================================

void _glmwfwInitTimer( void )
{
    struct timeval  tv;

    // "Resolution" is 1 us
    _glmwfwLibrary.Timer.Resolution = 1e-6;

    // Set start-time for timer
    gettimeofday( &tv, NULL );
    _glmwfwLibrary.Timer.t0 = (long long) tv.tv_sec * (long long) 1000000 +
		            (long long) tv.tv_usec;
}


//************************************************************************
//****               Platform implementation functions                ****
//************************************************************************

//========================================================================
// Return timer value in seconds
//========================================================================

double _glmwfwPlatformGetTime( GlmwfwWindow *winPtr )
{
    long long t;
    struct timeval  tv;

    gettimeofday( &tv, NULL );
    t = (long long) tv.tv_sec * (long long) 1000000 +
	(long long) tv.tv_usec;

    return (double)(t - _glmwfwLibrary.Timer.t0) * _glmwfwLibrary.Timer.Resolution;
}


//========================================================================
// Set timer value in seconds
//========================================================================

void _glmwfwPlatformSetTime( GlmwfwWindow *winPtr, double t )
{
    long long t0;
    struct timeval  tv;

    gettimeofday( &tv, NULL );
    t0 = (long long) tv.tv_sec * (long long) 1000000 +
	 (long long) tv.tv_usec;

    // Calulate new starting time
    _glmwfwLibrary.Timer.t0 = t0 - (long long)(t/_glmwfwLibrary.Timer.Resolution);
}


//========================================================================
// Put a thread to sleep for a specified amount of time
//========================================================================

void _glmwfwPlatformSleep( double time )
{
#ifdef _GLMWFW_HAS_PTHREAD

    if( time == 0.0 )
    {
#ifdef _GLMWFW_HAS_SCHED_YIELD
	sched_yield();
#endif
	return;
    }

    struct timeval  currenttime;
    struct timespec wait;
    pthread_mutex_t mutex;
    pthread_cond_t  cond;
    long dt_sec, dt_usec;

    // Not all pthread implementations have a pthread_sleep() function. We
    // do it the portable way, using a timed wait for a condition that we
    // will never signal. NOTE: The unistd functions sleep/usleep suspends
    // the entire PROCESS, not a signle thread, which is why we can not
    // use them to implement glmwfwSleep.

    // Set timeout time, relatvie to current time
    gettimeofday( &currenttime, NULL );
    dt_sec  = (long) time;
    dt_usec = (long) ((time - (double)dt_sec) * 1000000.0);
    wait.tv_nsec = (currenttime.tv_usec + dt_usec) * 1000L;
    if( wait.tv_nsec > 1000000000L )
    {
        wait.tv_nsec -= 1000000000L;
        dt_sec++;
    }
    wait.tv_sec  = currenttime.tv_sec + dt_sec;

    // Initialize condition and mutex objects
    pthread_mutex_init( &mutex, NULL );
    pthread_cond_init( &cond, NULL );

    // Do a timed wait
    pthread_mutex_lock( &mutex );
    pthread_cond_timedwait( &cond, &mutex, &wait );
    pthread_mutex_unlock( &mutex );

    // Destroy condition and mutex objects
    pthread_mutex_destroy( &mutex );
    pthread_cond_destroy( &cond );

#else

    // For systems without PTHREAD, use unistd usleep
    if( time > 0 )
    {
        usleep( (unsigned int) (time*1000000) );
    }

#endif // _GLMWFW_HAS_PTHREAD
}

