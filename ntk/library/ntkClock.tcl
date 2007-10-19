#---------------------------------------------------------------------------
# ntkWidget ntkClock.tcl --
#
# This file contains a ntkWidget button command implementation
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
# RCS: @(#) $Id: ntkClock.tcl,v 1.1.2.1 2007/10/19 08:37:52 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::clock {
    inherit ::ntk::classes::theme 

    private variable constructing 1

    public methodvariable afterId -default [list]

    public option -hourcolor -default [list 0 255 0 255] \
            -validatemethod verifyColor -configuremethod clockConfig
    public option -minutecolor -default [list 100 100 255 255] \
            -validatemethod verifyColor -configuremethod clockConfig
    public option -secondcolor -default [list 255 100 100 255] \
            -validatemethod verifyColor -configuremethod clockConfig
    public option -ringcolor -default [list 0 0 0 255] \
            -validatemethod verifyColor -configuremethod clockConfig

    private method clockConfig {option value} {
#puts stderr "clockConfig!$option!$value!"
        set itcl_options($option) $value
        switch -- $option {
	-rotate {
	    clockRotateCallback
	  }
	default {
	    set hour [clock format [clock seconds] -format %H]
	    set minute [clock format [clock seconds] -format %M]
            clockDraw $wpath $hour $minute
	  }
	}
    }

    constructor {args} {
	set itcl_options(-width) 200
	set itcl_options(-height) 200
	set themeConfig clockConfig
	set destroy clockDestroy
	if {[llength $args] > 0} {
	    configure {*}$args
	}
#	appendDestroyHandler [list $wpath clockDestroy $wpath]
	appendRedrawHandler [list $wpath clockRedraw $wpath]
	set constructing 0
	clockDraw $wpath
	set afterId [after 1000 [list $wpath clockCycle $wpath]]
        return $wpath
    }

    public method clockCycle {path} {
        lassign [split [clock format [clock seconds] -format {%H %M}]] \
	        hour minute
        if {$hour ne "0"} {
            set hour [string trim $hour 0]
        }
        if {$minute ne "0"} {
            set minute [string trim $minute 0]
        }
        clockDraw $path $hour $minute
        $path afterId [after 1000 [list $wpath clockCycle $path]]
    }

    public method clockDestroy {path} {
        catch {after cancel [$path afterId]}
    }

    public method clockDraw {path {hour {}} {minute {}}} {
	if {$hour eq ""} {
            lassign [split [clock format [clock seconds] -format {%H}]] hour
        }
	if {$minute eq ""} {
            lassign [split [clock format [clock seconds] -format {%M}]] minute
        }
+puts stderr "hour:$hour minute:$minute"
        set w [$path cget -width]
        set h [$path cget -height]
        if {$w < $h} {
            set min $w
        } else {
            set min $h
        }
        #
        # Draw the outside ring of the clock.
        #
        set radius [expr {($min - 6) / 2}]
        set obj [$path obj]
        $obj setall [list 0 0 0 0]
        set offset [expr {$radius + 2}]
        for {set r 0} {$r < 4} {incr r} {
            set lastx [expr {$offset + round(cos(6.28318530718) * $radius)}]
            set lasty [expr {$offset + round(sin(6.28318530718) * $radius)}]
            for {set a 0} {$a < 7.28318530718} {set a [expr {$a + 0.17}]} {
                set myX [expr {$offset + round(cos($a) * $radius)}]
                set myY [expr {$offset + round(sin($a) * $radius)}]
	        $obj line $lastx $lasty $myX $myY [$path cget -ringcolor]
                set lastx $myX 
                set lasty $myY
            }
            incr radius
        }
        set halfpi 1.57079632679
        set twopi 6.28318530718
        set s [expr {[clock seconds] - [clock scan 00:00:00]}]
        #
        # Draw the hour hand
        #
        set half [expr {$min / 2}]
        set theta [expr {$s * $twopi / 60.0 / 60.0 / 12.0}]
        set x2 [expr {round($offset + $radius * sin($theta))}]
        set y2 [expr {round($offset - $radius * cos($theta))}]
        $obj line $half $half $x2 $y2 [$path cget -hourcolor]
        $obj line $half $half [incr x2] [incr y2] [$path cget -hourcolor]
        # 
        # Draw the minute hand
        #
        set theta [expr {$s * $twopi / 60.0 / 60.0}]
        set x2 [expr {round($offset + $radius * sin($theta))}]
        set y2 [expr {round($offset - $radius * cos($theta))}]
        $obj line $half $half $x2 $y2 [$path cget -minutecolor]
        $obj line $half $half [incr x2] [incr y2] [$path cget -minutecolor]
        #
        # Draw the second hand
        #
        set theta [expr {$s * $twopi / 60.0}]
        set x2 [expr {round($offset + $radius * sin($theta))}]
        set y2 [expr {round($offset - $radius * cos($theta))}]
        $obj line $half $half $x2 $y2 [$path cget -secondcolor]
        $obj line $half $half [incr x2] [incr y2] [$path cget -secondcolor]
        render $path
    }

    public method clockRedraw {path} {
    }

    public method clockRotateCallback {value} {
        return 0
    }
}
