#---------------------------------------------------------------------------
# ntkWidget ntkMenu.tcl --
#
# This file contains a ntkWidget label command implementation
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
# RCS: @(#) $Id: ntkMenu.tcl,v 1.1.2.3 2007/11/29 21:09:13 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::menu {
    inherit ::ntk::classes::theme 

    private variable constructing 1

    public methodvariable itemTypes -default [list]
    public methodvariable itemCallbacks -default [list]
    public methodvariable items -default [list] 

    private method menuConfig {option value} {
        set itcl_options($option) $value
	switch -- $option {
	-text {
	    menuDraw
	  }
	default {
            menuDraw
	  }
	}
    }

    constructor {args} {
set constructing 1
	set themeConfig menuConfig
	set itcl_options(-width) 50
	set itcl_options(-height) 30
	eval configure $args
	appendRedrawHandler [list $wpath menuDraw]
	set constructing 0
	menuTrace
        return $wpath
    }

    public method addentry {text callback} {
	lappend items $text
	lappend itemTypes entry
	lappend itemCallbacks $callback
        menuDraw
    }

    public method addmenu {text} {
        lappend items $text
	lappend itemTypes menu
	lappend itemCallbacks [list]
        menuDraw
    }

    public method addseparator {} {
        lappend items ""
	lappend itemTypes separator
	lappend itemCallbacks [list]
        menuDraw
    }

    public method menuDraw {} {
puts stderr "menuDraw"
	if {$constructing} {
	    return
	}
	set idx 0
	set lgth [llength $items]
	while {$idx < $lgth} {
	    set item [lindex $items $idx]
	    set itemType [lindex $itemTypes $idx]
	    set itemCallback [lindex $itemCallbacks $idx]
# FIX ME to be coded !!
	    switch $itemType {
	    entry {
	      }
	    menu {
	      }
	    separator {
	      }
	    }
	    
	    incr idx
	}
        render $wpath
    }

    public method menuTrace {} {
        menuDraw
    }
}

