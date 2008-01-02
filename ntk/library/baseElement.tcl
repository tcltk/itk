#---------------------------------------------------------------------------
# ntkWidget baseElement.tcl --
#
# This file contains a ntkWidget baseElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: baseElement.tcl,v 1.1.2.2 2008/01/02 19:58:57 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::baseElement {
    public method InitializeOptionValuesBase {styleName widget state} {
        foreach optionName [array names itcl_options] {
	    if {$optionName eq ""} {
	        continue
	    }
	    set widgetValue ""
	    catch {set widgetValue [$widget cget $optionName]}
puts stderr "HANDLE!$optionName!$widgetValue!$widget!"
	    if {($widgetValue ne "") && ($widgetValue ne "<undefined>")} {
	        set itcl_options($optionName) $widgetValue
	    } else {
	        set dynamicSetting [::ntk::classes::styleTheme::getStateMapOptionValue $styleName $optionName $state]
#puts stderr "DYN!$dynamicSetting!"
	        if {$dynamicSetting ne ""} {
		    set itcl_options($optionName) $dynamicSetting
		} else {
	            set styleDefault [::ntk::classes::styleTheme::getStyleDefaultOptionValue $styleName $optionName]
puts stderr "STDEF!$styleDefault!"
	            if {$styleDefault ne ""} {
		        set itcl_options($optionName) $styleDefault
		    } else {
		        set itcl_options($optionName) [info option $optionName -default]
		    }
		    
		}
	    }
puts stderr "FINAL!$itcl_options($optionName)!"
	}
    }
    
    protected method ReliefPadding {padding relief shiftRelief} {
	switch [llength $padding] {
	1 {
	    set leftPad [lindex $padding 0]
	    set rightPad $leftPad
	    set topPad $leftPad
	    set bottomPad $leftPad
	  }
	2 {
	    set leftPad [lindex $padding 0]
	    set topPad [lindex $padding 1]
	    set rightPad $leftPad
	    set bottomPad $topPad
	  }
	4 {
	    set leftPad [lindex $padding 0]
	    set topPad [lindex $padding 1]
	    set rightPad [lindex $padding 2]
	    set bottomPad [lindex $padding 3]
	  }
	}
        switch $relief {
	raised {
	    incr rightPad $shiftRelief
	    incr bottomPad $shiftRelief
	  }
	sunken {
	    incr leftPad $shiftRelief
	    incr topPad $shiftRelief
	  }
	default {
	    set h1 [expr {$shiftRelief / 2}]
	    set h2 [expr {$shiftRelief % 2}]
	    incr leftPad $h1
	    incr topPad $h1
	    incr rightPad $h2
	    incr bottomPad $h2
	  }
	}
        return [list $leftPad $topPad $rightPad $bottomPad]
    }

}
