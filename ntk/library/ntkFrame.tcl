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
# RCS: @(#) $Id: ntkFrame.tcl,v 1.1.2.4 2007/10/08 19:57:13 wiede Exp $
#--------------------------------------------------------------------------

itcl::eclass ::ntk::classes::frame {
    inherit ::ntk::classes::window 

    private variable frameNs ""
    private variable frameDraw [list]

    option -bg -default {} -validatemethod verifyColor -configuremethod frameConfig
    option -tile -default "" -configuremethod frameConfig

    private method frameConfig {option value} {
        set itcl_options($option) $value
        if {$frameDraw ne ""} {
            $frameDraw [path]
        }
    }

    constructor {args} {
        eval ::ntk::classes::window::constructor $args
    } {
#	configure -tile {}
	configure -bg [defaultBackgroundColor]
	set path [path]
	appendRedrawHandler [list $path frameDraw $path]

	set frameDraw frameDraw
	frameDraw $path
        return $path
    }

    public method frameDraw {path} {
#puts stderr "frameDraw!$path!"
	set myTile [cget -tile]
        set myObj [obj]
        if {($myTile ne "") && ($myTile ne "<undefined>")} {
	    $myObj tile $myTile
	} else {
	    set myColor [$path cget -bg]
	    if {[llength $myColor] == 1} {
	        $myObj setall $colors($myColor)
	    } else {
	        $myObj setall $myColor
	    }
	}
        $path render $path
    }
}

