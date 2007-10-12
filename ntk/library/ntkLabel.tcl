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
# RCS: @(#) $Id: ntkLabel.tcl,v 1.1.2.3 2007/10/12 21:09:57 wiede Exp $
#--------------------------------------------------------------------------

itcl::eclass ::ntk::classes::label {
    inherit ::ntk::classes::theme 

    private variable constructing 1

    public option -font -default {} -configuremethod labelConfig
    public option -fontsize -default {} -configuremethod labelConfig
    public option -text -default {} -configuremethod labelConfig
    public option -textcolor -default {} -validatemethod verifyColor -configuremethod labelConfig
    public option -bg -default {} -validatemethod verifyColor -configuremethod labelConfig
    public option -bd -default 0 -validatemethod verifyBorder -configuremethod labelConfig

    private method labelConfig {option value} {
        set itcl_options($option) $value
        labelDraw $wpath
    }

    constructor {args} {
        eval ::ntk::classes::window::constructor -width 10 -height 10
    } {
	set itcl_options(-font) $defaultFont
	set itcl_options(-fontsize) 12
	set itcl_options(-bg) [defaultBackgroundColor]
	eval configure $args
puts stderr "TC!$itcl_options(-textcolor)!"
	appendRedrawHandler [list $wpath labelDraw $wpath]
	set constructing 0
	labelDraw $wpath
        return $wpath
    }

    public method labelDraw {path} {
	if {$constructing} {
	    return
	}
        set myColor [$path cget -bg]
        if {[llength $myColor] == 1} {
            $obj setall $colors($myColor)
        } else {
            $obj setall $myColor
        }
        if {[$path cget -bd] > 0} {
            themeLabelDrawBorder $path
        }
        if {[string length [$path cget -text]]} {
puts stderr "PAR! [$path cget -font] [$path cget -fontsize] \
	            [$path cget -text] [$path cget -textcolor] !"
            set rgba [freetype [$path cget -font] [$path cget -fontsize] \
	            [$path cget -text] [$path cget -textcolor] \
	            myWidth myHeight]

            set x [expr {[$path cget -width] / 2 - $myWidth / 2}]
            set y [expr {[$path cget -height] / 2 - $myHeight / 2}]
            set tmp [megaimage $rgba]
            [$path obj] blendobj $x $y $tmp
            rename $tmp {}
        }
        render $path
    }

    public method labelRequestSize {path} {
        if {![string length [$path cget -text]]} {
	    return
	}
        freetype-measure [$path cget -font] [$path cget -fontsize] \
	        [$path cget -text] width height
        set bdt [expr {[$path cget -bd] * 2}]
        set rwidth [expr {$width + $bdt + 2}]
        set rheight [expr {$height + $bdt + 2}]
        requestSize $path $rwidth $rheight
    }
}
