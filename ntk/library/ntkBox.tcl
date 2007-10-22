#---------------------------------------------------------------------------
# ntkWidget ntkBox.tcl --
#
# This file contains a ntkWidget button command implementation
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
# RCS: @(#) $Id: ntkBox.tcl,v 1.1.2.1 2007/10/22 20:34:19 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::box {
    inherit ::ntk::classes::theme 

    private variable constructing 1

    public methodvariable pologons -default [list]

    public option -rotatexy -default 0 -configuremethod boxConfig
    public option -rotatexz -default 0 -configuremethod boxConfig
    public option -rotateyy -default 0 -configuremethod boxConfig
    public option -centerx -default 50 -configuremethod boxConfig
    public option -centery -default 50 -configuremethod boxConfig
    public option -centerz -default 50 -configuremethod boxConfig
    public option -z -default 0 -configuremethod boxConfig

    private method boxConfig {option value} {
#puts stderr "boxConfig!$option!$value!"
        set itcl_options($option) $value
        switch -- $option {
	default {
            boxDraw
	  }
	}
    }

    constructor {args} {
	set themeConfig boxConfig
	set destroy boxDestroy
	if {[llength $args] > 0} {
	    configure {*}$args
	}
	appendRedrawHandler [list $wpath boxRedraw]
	set constructing 0
	boxDraw
        return $wpath
    }
}

