#---------------------------------------------------------------------------
# ntkWidget ntkStyleTheme.tcl --
#
# This file contains a ntkWidget StyleTheme commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: ntkStyleTheme.tcl,v 1.1.2.1 2007/12/29 19:59:45 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::styleTheme {
    private common _themeNames [list]
    private common _themeObjects
    private common _themeElements
    private common _themeLayouts
    private variable _options
    private variable _maps

    public variable colors
    public common currentTheme default

    constructor {name theColors args} {
	if {[lsearch $_themeNames $name] >= 0} {
	    return -code error "theme: $name already exists!"
	}
	lappend _themeNames $name
	set _themeObjects($name) $this
        uplevel 0 array set colors [list $theColors]
parray colors
    }

    public method configure {name args} {
       foreach {optionName value} $args {
puts stderr "configure!$name!$optionName!$value!"
           uplevel 0 set _options($name,$optionName) [list $value]
	}
    }

    public method map {name args} {
       foreach {optionName value} $args {
puts stderr "map!$name!$optionName!$value!"
           uplevel 0 set _maps($name,$optionName) [list $value]
	}
    }

    public proc registerElement {themeName elementName elementClassName} {
        if {[lsearch $_themeNames $themeName] < 0} {
	    return -code error "theme $themeName does not exist!"
	}
	set _themeElements($themeName,$elementName) $elementClassName
    }

    public proc registerLayout {themeName layoutName value} {
        if {[lsearch $_themeNames $themeName] < 0} {
	    return -code error "theme $themeName does not exist!"
	}
	set _themeLayouts($themeName,$layoutName) $value
    }

    public proc elements {themeName} {
        if {[lsearch $_themeNames $themeName] < 0} {
	    return -code error "theme $themeName does not exist!"
	}
	set names [list]
	foreach entry [lsort [array names _themeElements]] {
	    foreach {thName elementName} [split $entry ,] break
	    if {$thName eq $themeName} {
	        lappend names $elementName
	    }
	}
        return $names
    }

    public proc layouts {themeName} {
        if {[lsearch $_themeNames $themeName] < 0} {
	    return -code error "theme $themeName does not exist!"
	}
	set names [list]
	foreach entry [lsort [array names _themeLayouts]] {
	    foreach {thName layoutName} [split $entry ,] break
	    if {$thName eq $themeName} {
	        lappend names $layoutName
	    }
	}
        return $names
    }

    public proc themeObject {name} {
	if {$name eq "current"} {
	    set name $currentTheme
	}
        if {[::info exists _themeObjects($name)]} {
	    return $_themeObjects($name)
	} else {
	    return ""
	}
    }

public method xx {} {
parray _options
parray _maps
puts stderr "THEMES!$_themeNames!"
}

}

namespace eval ::ntk::theme {}
