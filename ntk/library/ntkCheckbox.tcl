#---------------------------------------------------------------------------
# ntkWidget ntkCheckbox.tcl --
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
# RCS: @(#) $Id: ntkCheckbox.tcl,v 1.1.2.1 2007/10/27 20:04:23 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::checkbox {
    inherit ::ntk::classes::theme 

    private variable constructing 1

    public option -check -default 0 -configuremethod checkboxConfig
    public option -checkcolor -default [list 0 0 0 255] \
            -configuremethod checkboxConfig

    private method checkboxConfig {option value} {
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
	set themeConfig checkboxConfig
	set itcl_options(-width) 20
	set itcl_options(-height) 20
	set itcl_options(-bg) [list 255 255 255 255]
	set itcl_options(-buttonpress) [list $wpath checkboxButtonpress]
	eval configure $args
	appendRedrawHandler [list $wpath checkboxDraw]
	set constructing 0
	checkboxDraw
        return $wpath
    }
 
    public method checkboxButtonpress {button x y globalx globaly} {
        set itcl_options(-check) [expr {!$itcl_options(-check)}]
    }

    public method checkboxDraw {} {
        $obj setall $itcl_options(-bg)
        themeDrawGenericBorder $wpath
        if {$itcl_options(-check)} {
            set w $itcl_options(-width)
            set h $itcl_options(-height)
            set bd $itcl_options(-bd)
            set y1 [expr {$bd - 1}]
            set y2 [expr {$h - $bd - 1}]
            $obj line [expr {$w - $bd - 1}] $y1 [expr {$w / 3}] $y2 \
	            $itcl_options(-checkcolor)
            $obj line [expr {$w - $bd - 2}] $y1 [expr {($w / 3) - 1}] $y2 \
	            $itcl_options(-checkcolor)
            set x1 [expr {($w / 3) - 1}]
            $obj line $x1 $y2 [expr {$bd + 1}] [expr {$h - $bd - ($h / 4)}] \
	            $itcl_options(-checkcolor)
            $obj line $x1 [expr {$y2 - 1}] [expr {$bd + 1}] \
	            [expr {$h - $bd - ($h / 4) - 1}] $itcl_options(-checkcolor)
        }
        render $path
    }
}

