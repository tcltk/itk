#---------------------------------------------------------------------------
# ntkWidget ntkScrollbarButton.tcl --
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
# RCS: @(#) $Id: ntkScrollbarButton.tcl,v 1.1.2.1 2007/10/18 21:41:06 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::scrollbarbutton {
    inherit ::ntk::classes::button 

    private variable constructing 1

    public methodvariable pressed -default 0 -callback scrollbarButtonCallback
    public methodvariable direction -default up -callback scrollbarButtonCallback

    private method scrollbarButtonConfig {option value} {
puts stderr "scrollbarButtonConfig!$option!$value!"
        set itcl_options($option) $value
        switch -- $option {
	default {
	  }
	}
    }

    public method scrollbarButtonCallback {what value} {
        switch $what {
	direction {
	    themeScrollbarButtonDraw $wpath
	  }
	pressed {
	    themeScrollbarButtonDraw $wpath
	  }
        default {
	    return -code error "scrollbarButtonCallback bad what!$what!"
	  }
	}
    }

    constructor {args} {
	set themeConfig scrollbarButtonConfig
        if {[llength $args] > 0} {
	    configure {*}$args
        }
	appendRedrawHandler [list $wpath redrawWindow $wpath]
	set constructing 0
	windowDraw $wpath
        return $wpath
    }
}
