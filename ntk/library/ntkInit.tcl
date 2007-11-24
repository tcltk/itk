#---------------------------------------------------------------------------
# ntkWidget ntkInit.tcl --
#
# This file contains the initializing procs for the ntkWidget package
#
# ntkWidget is derived from the NexTk implementation written by
# George Peter Staplin
#
# ntkWidget is a reimplementation of Tk based on megapkg, ntk and freetypeext
# written by George Peter Staplin
#
# Copyright (c) 2007 by Arnulf P. Wiedemann and George Peter Staplin
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: ntkInit.tcl,v 1.1.2.1 2007/11/24 23:05:01 wiede Exp $
#--------------------------------------------------------------------------

namespace eval ::ntk {
    proc ntkWidgetInit {} {
	set _w 200
	set _h 200
        set ::ntk::_win [::ntk::glmwfw::Glmwfw openWindow $_w $_h]
        set _win $::ntk::_win
	::ntk::glmwfw::Glmwfw setWindowTitle $_win "ntkWidget"
	uplevel #0 [list ntk toplevel .  -width $_w -height $_h -bg [list 0 255 0 0]]
	. id $_win
        ::ntk::glmwfw::Glmwfw enable GLMWFW_STICKY_KEYS
        ::ntk::glmwfw::Glmwfw disable GLMWFW_KEY_REPEAT
        ::ntk::glmwfw::Glmwfw enable GLMWFW_MOUSE_CURSOR
        ::ntk::glmwfw::Glmwfw setKeyCallback $_win \
                ::ntk::DispatchKey
        ::ntk::glmwfw::Glmwfw setMousePosCallback $_win \
                ::ntk::DispatchMousePos
        ::ntk::glmwfw::Glmwfw setMouseButtonCallback $_win \
                ::ntk::DispatchMouseButton
        ::ntk::glmwfw::Glmwfw setMouseWheelCallback $_win \
                ::ntk::DispatchMouseWheel
        ::ntk::glmwfw::Glmwfw setWindowSizeCallback $_win \
                ::ntk::DispatchWindowSize
        ::ntk::glmwfw::Glmwfw setWindowRefreshCallback $_win \
                ::ntk::DispatchWindowRefresh
        ::ntk::glmwfw::Glmwfw setWindowCloseCallback $_win \
                ::ntk::DispatchWindowClose
    }
    
    proc DispatchKey {winHandle key state keySym keyVal} {
puts stderr "::ntk::DispatchKey!$winHandle!$key!$state!$keySym!$keyVal!"
        if {$state} {
	    return [ntk keyPress $winHandle $key $keySym $keyVal]
	} else {
	    return [ntk keyRelease $winHandle $key $keySym $keyVal]
	}
    }

    proc DispatchMousePos {winHandle x y} {
#    puts stderr "::ntk::DispatchMousePos!$winHandle!$x!$y!"
    }

    proc DispatchMouseButton {winHandle num state x y} {
#puts stderr "::ntk::DispatchMouseButton!$winHandle!$num!$state!$x!$y!"
        if {$state} {
	    return [ntk mousePress . $num $x $y]
	} else {
	    return [ntk mouseRelease . $num $x $y]
        }
    }

    proc DispatchMouseWheel {winHandle where} {
puts stderr "::ntk::DispatchMouseWheel!$winHandle!$where!"
    }

    proc DispatchWindowSize {winHandle width height} {
puts stderr "::ntk::DispatchWindowSize!$winHandle!$width!$height!"
    }

    proc DispatchWindowRefresh {winHandle} {
puts stderr "::ntk::DispatchWindowRefresh!$winHandle!"
         ntk render .
    }

    proc DispatchWindowClose {winHandle} {
puts stderr "::ntk::DispatchWindowClose!$winHandle!"
        ::ntk::glmwfw::Glmwfw terminate
        exit 0
    }

    ntkWidgetInit
}
