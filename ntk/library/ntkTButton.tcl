#---------------------------------------------------------------------------
# ntkWidget ntkTButton.tcl --
#
# This file contains a ntkWidget tbutton commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: ntkTButton.tcl,v 1.1.2.1 2007/12/30 22:59:52 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::tbutton {
    inherit ::ntk::classes::tbuttonBase

    private variable _elements

    public option [list -command command Command] -default "" \
        -configuremethodvar baseConfig
    public option [list -default default Default] -default normal

    public method tbuttonConfig {option value} {
        switch -- $option {
	-text {
	  }
	}
    }

    constructor {args} {
	set baseConfig tbuttonConfig
	foreach name [array names itcl_options] {
	    catch {unset itcl_options($name)}
	}
        if {[llength $args] > 0} {
	    configure {*}$args
puts stderr "TB!"
parray itcl_options
	}
    }

    public method getElementObject {elementName elementClassName} {
        if {![::info exists _elements($elementName,$elementClassName)]} {
	   set _elements($elementName,$elementClassName) [$elementClassName #auto] 
	}
	return [::namespace current]::$_elements($elementName,$elementClassName)
    }
}
