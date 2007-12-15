#---------------------------------------------------------------------------
# ntkWidget ntkGridData.tcl --
#
# This file contains a ntkWidget window command implementation
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
# RCS: @(#) $Id: ntkGridData.tcl,v 1.1.2.2 2007/12/15 21:55:16 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::gridData {
    inherit ::ntk::classes::grid

    private variable constructing 1

    public methodvariable wpath -default [list]

    public option -sticky -default {} \
            -configuremethod gridDataConfig
    public option -columnspan -default 1 \
            -configuremethod gridDataConfig
    public option -rowspan -default 1 \
            -configuremethod gridDataConfig
    public option -columnratio -default 0 \
            -configuremethod gridDataConfig
    public option -rowratio -default 0 \
            -configuremethod gridDataConfig
    public option -slot -default [list 0 0] \
            -configuremethod gridDataConfig

    public method gridDataConfig {option value} {
#puts stderr "gridDataConfig!$option!$value!"
        set itcl_options($option) $value
	if {$wpath eq ""} {
	    return
	}
        switch -- $option {
	-sticky {
	    stickyCallback $wpath $value
	    relayoutTrace $wpath
	  }
	-columnspan {
	    spanCallback $wpath $value
	    relayoutTrace $wpath
	  }
	-rowspan {
	    spanCallback $wpath $value
	    relayoutTrace $wpath
	  }
	-slot {
	    slotCallback $wpath $value
	    relayoutTrace $wpath
	  }
	default {
	    return -code error "gridDataConfig no such option: \"$option\""
	  }
	}
    }

    constructor {path args} {
	::itcl::setcomponent $path geometryManager $this
	::itcl::adddelegatedoption $path delegate option -slot \
	        to geometryManager
	::itcl::adddelegatedoption $path delegate option -sticky \
	        to geometryManager
	::itcl::adddelegatedoption $path delegate option -columnspan \
	        to geometryManager
	::itcl::adddelegatedoption $path delegate option -rowspan \
	        to geometryManager
	::itcl::adddelegatedoption $path delegate option -columnratio \
	        to geometryManager
	::itcl::adddelegatedoption $path delegate option -rowratio \
	        to geometryManager
	::itcl::adddelegatedmethod $path delegate method peakcolumn \
	        to geometryManager
	::itcl::adddelegatedmethod $path delegate method peakrow \
	        to geometryManager
        set constructing 0
        return $this
    }

    public method slotinfo {slotoffset spankey} {
        set s [lindex $itcl_options(-slot) $slotoffset]
	set es [expr {$s + $itcl_options($spankey)}]
	return [list $s $es]
    }

    public method rowspan {} {
        return $itcl_options(-rowspan)
    }

    public method columnspan {} {
        return $itcl_options(-columnspan)
    }

    public method sticky {} {
        return $itcl_options(-sticky)
    }

    public method slot {} {
        return $itcl_options(-slot)
    }

    public method getScope {varname} {
        return [::itcl::scope $varname]
    }

}

