#---------------------------------------------------------------------------
# ntkWidget ntkFrame.tcl --
#
# This file contains a ntkWidget frame command implementation
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
# RCS: @(#) $Id: ntkFrame.tcl,v 1.1.2.9 2007/10/22 20:32:53 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::frame {
    inherit ::ntk::classes::window 

    option -tile -default {} -configuremethod frameConfig

    private method frameConfig {option value} {
        set itcl_options($option) $value
        frameDraw
    }

    constructor {args} {
        ::ntk::classes::window::constructor
    } {
	set itcl_options(-bg) [defaultBackgroundColor]
	if {[llength $args] > 0} {
	    configure {*}$args
	}
	appendRedrawHandler [list $wpath frameDraw]
	frameDraw
        return $wpath
    }

    public method frameDraw {} {
#puts stderr "frameDraw!"
	set myTile $itcl_options(-tile)
        if {$myTile ne ""} {
	    $obj tile $myTile
	} else {
	    set myColor $itcl_options(-bg)
	    if {[llength $myColor] == 1} {
	        $obj setall $colors($myColor)
	    } else {
	        $obj setall $myColor
	    }
	}
        render $wpath
    }
}

