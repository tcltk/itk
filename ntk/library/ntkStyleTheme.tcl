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
# RCS: @(#) $Id: ntkStyleTheme.tcl,v 1.1.2.2 2007/12/30 22:58:19 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::styleTheme {
    private common _themeNames [list]
    private common _themeObjects
    private common _themeElements
    private common _themeLayouts
    private common _styleOptions
    private common _styleMaps
    private common _styles
    private common _styleParents

    private variable objectTheme
    private variable _parent

    public variable colors

    public common currentTheme default
    
    constructor {themeName parent theColors args} {
	if {[lsearch $_themeNames $themeName] >= 0} {
	    return -code error "theme: $themeName already exists!"
	}
	lappend _themeNames $themeName
        set _parent $parent
	set objectTheme $themeName
	set _styles($themeName,.) .
	set _styleParents($themeName,.) ""
	set _themeObjects($themeName) $this
        uplevel 0 array set colors [list $theColors]
    }

    public method styleConfigure {styleName args} {
       if {![::info exists _styles($objectTheme,$styleName)]} {
           set _styles($objectTheme,$styleName) $styleName
	   set parentStyle .
	   set idx [string first . $styleName]
	   if {$idx >= 0} {
	       incr idx
	       set parentStyle [string range $styleName $idx end]
	   }
           set _styleParents($objectTheme,$styleName) $parentStyle
       }
       foreach {optionName value} $args {
puts stderr "configure!$styleName!$optionName!$value!"
           uplevel 0 set _styleOptions($objectTheme,$styleName,$optionName) [list $value]
	}
    }

    public method styleMap {styleName args} {
       foreach {optionName value} $args {
#puts stderr "map!$styleName!$optionName!$value!"
           uplevel 0 set _styleMaps($styleName,$optionName) [list $value]
	}
    }

    public proc themeUse {themeName} {
        if {[lsearch $_themeNames $themeName] < 0} {
	    return -code error "theme $themeName does not exist!"
	}
        set currentTheme $themeName
    }

    public proc registerElement {themeName elementName elementClassName} {
        if {[lsearch $_themeNames $themeName] < 0} {
	    return -code error "theme $themeName does not exist!"
	}
#puts stderr "registerElement!$themeName!$elementName!$elementClassName!"
	set _themeElements($themeName,$elementName) $elementClassName
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

    public proc getElementClassName {elementName} {
        while {1} {
	    if {[::info exists _themeElements($currentTheme,$elementName)]} {
	        return $_themeElements($currentTheme,$elementName)
	    }
            set idx [string first . $elementName]
	    if {$idx < 0} {
	        break
	    }
	    incr idx
	    set elementName [string range $elementName $idx end]
        }
        return [list]
    }

    public proc registerLayout {themeName layoutName value} {
        if {[lsearch $_themeNames $themeName] < 0} {
	    return -code error "theme $themeName does not exist!"
	}
	set _themeLayouts($themeName,$layoutName) $value
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

    public proc getLayout {layoutName} {
        if {![::info exists _themeLayouts($currentTheme,$layoutName)]} {
	    return [list]
	}
        return $_themeLayouts($currentTheme,$layoutName)
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

    public proc getStateMapOptionValue {styleName optionName state} {
#puts stderr "ST!$styleName!$optionName!"
#parray _styleMaps
        if {[::info exists _styleMaps($styleName,$optionName)]} {
	    foreach {states value} $_styleMaps($styleName,$optionName) {
#puts stderr "getStateMapOption!$styleName!$optionName!$state!$states!$value!"
		set matches 1
	        foreach st $states {
		    switch -glob $st {
		    !* {
		       set st [string range $st 1 end]
		       if {[lsearch $state $st] >= 0} {
		           set matches 0
		       }
		      }
		    default {
		       if {[lsearch $state $st] < 0} {
		           set matches 0
		       }
		      }
		    }
	        }
	        if {$matches} {
		    return $value
		}
	    }
	}
	return [list]
    }

    public proc getStyleDefaultOptionValue {styleName optionName} {
#puts stderr "getStyleDefaultOptionValue!$styleName!$optionName!"
	while {1} {
#puts stderr "LOOK!$styleName!$optionName![::info exists _styleOptions($currentTheme,$styleName,$optionName)]!"
            if {[::info exists _styleOptions($currentTheme,$styleName,$optionName)]} {
	        return $_styleOptions($currentTheme,$styleName,$optionName)
	    }
	    if {![::info exists _styleParents($currentTheme,$styleName)]} {
	        break
	    }
	    set styleName $_styleParents($currentTheme,$styleName)
	    if {$styleName eq ""} {
	        break
	    }
	}
	return [list]
    }

public method xx {} {
#parray _styleOptions
#parray _styleMaps
#puts stderr "THEMES!$_themeNames!"
}

}

namespace eval ::ntk::theme {}
