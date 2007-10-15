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
# RCS: @(#) $Id: ntkLabel.tcl,v 1.1.2.5 2007/10/15 09:24:51 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::label {
    inherit ::ntk::classes::theme 

    private variable constructing 1
    private variable textobj [list]

    public option -font -default {} -configuremethod labelConfig
    public option -fontsize -default {} -configuremethod labelConfig
    public option -text -default {} -configuremethod labelConfig
    public option -textcolor -default {} -validatemethod verifyColor \
            -configuremethod labelConfig
    public option -bg -default {} -validatemethod verifyColor \
            -configuremethod labelConfig
    public option -bd -default 0 -validatemethod verifyBorder \
            -configuremethod labelConfig

    private method labelConfig {option value} {
        set itcl_options($option) $value
	switch -- $option {
	-text {
	    labelTrace $wpath
	  }
	default {
            labelDraw $wpath
	  }
	}
    }

    public method textobj {{value {}}} {
	if {$value eq ""} {
            return $textobj
	} else {
	    set textobj $value
	}
    }

    constructor {args} {
        eval ::ntk::classes::window::constructor -width 10 -height 10
    } {
	set itcl_options(-font) $defaultFont
	set itcl_options(-fontsize) $defaultFontSize
	set itcl_options(-bg) [defaultBackgroundColor]
	eval configure $args
	set textobj [megaimage-blank 20 20]
	appendRedrawHandler [list $wpath labelDraw $wpath]
	set constructing 0
	labelTrace $wpath
        return $wpath
    }

    public method labelDraw {path} {
#puts stderr "labelDraw!$path!"
	if {$constructing} {
	    return
	}
	set myColor [$path cget -bg]
	if {[llength $myColor] == 1} {
	    $obj setall $colors($myColor)
	} else {
	    $obj setall $myColor
	}
        themeLabelDrawBorder $path
        labelDrawText $path
        render $path
    }

    public method labelDrawText {path} {
        lassign [$obj getsize] winwidth winheight
        lassign [[$path textobj] getsize] textwidth textheight
#puts stderr "labelDrawText!$path!$wpath!$winwidth!$winheight!$textwidth!$textheight!"
        set x [expr {($winwidth / 2) - ($textwidth / 2)}]
        set y [expr {($winheight / 2) - ($textheight / 2)}]
        set myTextObj [$path textobj]
        [$path obj] blendobj $x $y $myTextObj
    }

    public method labelRequestSize {path} {
        if {![string length [$path cget -text]]} {
	    return
	}
        freetype-measure [$path cget -font] [$path cget -fontsize] \
	        [$path cget -text] myWidth myHeight
        set bdt [expr {[$path cget -bd] * 2}]
        set rwidth [expr {$myWidth + $bdt + 2}]
        set rheight [expr {$myHeight + $bdt + 2}]
        requestSize $path $rwidth $rheight
    }

    public method labelTextCallback {path value} {
#puts stderr "labelTextCallback!$path!$value!"
	if {$constructing} {
	    return
	}
        set rgbadata [freetype [$path cget -font] \
                [$path cget -fontsize] $value [$path cget -textcolor] \
		myWidth myHeight myOffsetmap]
        set textobj [$path textobj]
        $textobj setdata $rgbadata
        requestSize $path [expr {$myWidth + 2}] [expr {$myHeight + 2}]
        return 1
    }

    public method labelTrace {path} {
#puts stderr "labelTrace!$path!"
        labelTextCallback $path [$path cget -text]
	labelDraw $path
    }
}
