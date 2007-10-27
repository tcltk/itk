#---------------------------------------------------------------------------
# ntkWidget ntkSpinbox.tcl --
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
# RCS: @(#) $Id: ntkSpinbox.tcl,v 1.1.2.2 2007/10/27 20:30:00 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::spinbox {
    inherit ::ntk::classes::theme 

    private variable constructing 1

    public option -items -default [list] -configuremethod spinboxConfig
    public option -itemindex -default -1 -configuremethod spinboxConfig

    private method spinboxConfig {option value} {
        set itcl_options($option) $value
	switch -- $option {
	-text {
	    spinboxTrace
	  }
	default {
            spinboxDraw
	  }
	}
    }

    constructor {args} {
	set themeConfig labelConfig
	set itcl_options(-width) 100
	set itcl_options(-height) 24
	eval configure $args
        ntk grid [ntk window $wpath.textarea -width 90 -height 24] -slot {0 0} \
                -rowspan 2 -sticky width
	appendRedrawHandler [list $wpath labelDraw]
	$wpath.textarea appendRedrawHandler [list $wpath spinboxDraw]
        ntk button $wpath.up -image [themeSpinboxMakeButtonImage up] \
	       -command [list $wpath spinboxUp]
        ntk button $wpath.down -image [themeSpinboxMakeButtonImage down] \
	       -command [list $wpath spinboxDown]
        ntk grid $wpath.up -slot {1 0} -sticky height
        ntk grid $wpath.down -slot {1 1} -sticky height
	set constructing 0
	spinboxDraw
        return $wpath
    }

    public method spinboxDown {} {
        set i $itcl_options(-itemindex)
        set len [llength $itcl_options(-items)]
        incr i
        if {$i >= $len} {
            set i [expr {$len - 1}]
        }
        set itcl_options(-itemindex) $i
        spinboxDraw
    }

    public method spinboxUp {} {
        set i [$path -itemindex]
        incr i -1
        if {$i < 0} {
             set i 0
        }
        set itcl_options(-itemindex) $i
        spinboxDraw
    }

    proc spinboxDraw {} {
        [$wpath.textarea obj] setall [$wpath -bg]
        themeSpinboxDrawTextareaBorder $wpath
        set item [lindex $itcl_options(-items) $itcl_options(-itemindex)]
        if {$item ne ""} {
            set textobj [megaimage [freetype $itcl_options(-font) \
	            $itcl_options(-fontsize) $item $itcl_options(-textcolor) \
	            textwidth textheight]]
            $wpath.textarea requestSize [expr {$textwidth + 2}] \
	            [expr {$textheight + 2}]
            set myX [expr {($itcl_options(-width) / 2) - ($textwidth / 2)}]
            set myY [expr {($itcl_options(-height) / 2) - ($textheight / 2)}]
            [$wpath.textarea obj] blendobj $myX $myY $textobj
            rename $textobj {}
        }
        render $path.textarea
    }
}
