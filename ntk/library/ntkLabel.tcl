#---------------------------------------------------------------------------
# ntkWidget ntkLabel.tcl --
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
# RCS: @(#) $Id: ntkLabel.tcl,v 1.1.2.8 2007/10/19 10:11:58 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::label {
    inherit ::ntk::classes::theme 

    private variable constructing 1


    private method labelConfig {option value} {
        set itcl_options($option) $value
	switch -- $option {
	-text {
	    labelTrace
	  }
	default {
            labelDraw
	  }
	}
    }

    constructor {args} {
	set themeConfig labelConfig
	eval configure $args
	appendRedrawHandler [list $wpath labelDraw]
	set constructing 0
	labelTrace
        return $wpath
    }

    public method labelDraw {} {
#puts stderr "labelDraw!"
	if {$constructing} {
	    return
	}
	set myColor $itcl_options(-bg)
	if {[llength $myColor] == 1} {
	    $obj setall $colors($myColor)
	} else {
	    $obj setall $myColor
	}
        themeLabelDrawBorder $wpath
        labelDrawText
        render $wpath
    }

    public method labelDrawText {} {
        lassign [$obj getsize] winwidth winheight
        lassign [$textobj getsize] textwidth textheight
#puts stderr "labelDrawText!$wpath!$winwidth!$winheight!$textwidth!$textheight!"
        set myX [expr {($winwidth / 2) - ($textwidth / 2)}]
        set myY [expr {($winheight / 2) - ($textheight / 2)}]
        set myTextObj $textobj
        $obj blendobj $myX $myY $myTextObj
    }

    public method labelRequestSize {} {
        if {![string length $itcl_options(-text)]} {
	    return
	}
        freetype-measure $itcl_options(-font) $itcl_options(-fontsize) \
	        $itcl_options(-text) myWidth myHeight
        set bdt [expr {$itcl_options(-bd) * 2}]
        set rwidth [expr {$myWidth + $bdt + 2}]
        set rheight [expr {$myHeight + $bdt + 2}]
        requestSize $rwidth $rheight
    }

    public method labelTextCallback {value} {
#puts stderr "labelTextCallback!$value!"
	if {$constructing} {
	    return
	}
        set rgbadata [freetype $itcl_options(-font) \
                $itcl_options(-fontsize) $value $itcl_options(-textcolor) \
		myWidth myHeight myOffsetmap]
        $textobj setdata $rgbadata
        requestSize [expr {$myWidth + 2}] [expr {$myHeight + 2}]
        return 1
    }

    public method labelTrace {} {
#puts stderr "labelTrace!"
        labelTextCallback $itcl_options(-text)
	labelDraw
    }
}
