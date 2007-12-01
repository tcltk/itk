#---------------------------------------------------------------------------
# ntkWidget ntkSpinbox.tcl --
#
# This file contains a ntkWidget spinbox command implementation
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
# RCS: @(#) $Id: ntkSpinbox.tcl,v 1.1.2.5 2007/12/01 22:53:27 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::spinbox {
    inherit ::ntk::classes::theme 

    private variable constructing 1
    private variable drawing 0

    public option -items -default [list] -configuremethod spinboxConfig
    public option -itemindex -default 1 -configuremethod spinboxConfig

    private method spinboxConfig {option value} {
#puts stderr "spinboxConfig!$option!$value!"
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
	set constructing 1
	set themeConfig spinboxConfig
	configure -width 100
	configure -height 24
	configure {*}$args
        ::ntk::widgetImage::Image fill $windowImage $itcl_options(-bg)
#	        -width 90 -height 24 -bg [list 255 255 255 255]] -slot {0 0} \

        ntk grid [uplevel #0 ntk theme $wpath.textarea \
	        -width 90 -height 24] -slot {0 0} \
                -rowspan 2 -sticky width
	appendRedrawHandler [list $wpath spinboxDraw]
	$wpath.textarea appendRedrawHandler [list $wpath spinboxDraw]
        uplevel #0 [list ntk button $wpath.up \
	        -image [themeSpinboxMakeButtonImage up] \
	        -command [list $wpath spinboxUp]]
        uplevel #0 [list ntk button $wpath.down \
	        -image [themeSpinboxMakeButtonImage down] \
	        -command [list $wpath spinboxDown]]
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
        set i $itcl_options(-itemindex)
        incr i -1
        if {$i < 0} {
             set i 0
        }
        set itcl_options(-itemindex) $i
        spinboxDraw
    }

    public method spinboxDraw {} {
#puts stderr "spinboxDraw!$constructing!$drawing!"
	if {$constructing} {
	    return
	}
	if {$drawing} {
	    return
	}
	set drawing 1
        ::ntk::widgetImage::Image fill [$wpath.textarea windowImage] \
	        $itcl_options(-bg)
        themeSpinboxDrawTextareaBorder $wpath
        set item [lindex $itcl_options(-items) $itcl_options(-itemindex)]
        if {$item ne ""} {
	    ::ntk::widgetImage::Image createtext $textImage \
	            $itcl_options(-font) $itcl_options(-fontsize) \
		    $item $itcl_options(-textcolor) textwidth textheight
            $wpath.textarea requestSize [expr {$textwidth + 2}] \
	            [expr {$textheight + 2}]
            set myX [expr {([$wpath.textarea cget -width] / 2) - \
	            ($textwidth / 2)}]
            set myY [expr {([$wpath.textarea cget -height] / 2) - \
	            ($textheight / 2)}]
            ::ntk::widgetImage::Image blendwidget \
	            [$wpath.textarea windowImage] $myX $myY $textImage
        }
        render $wpath.textarea
	set drawing 0
    }
}
