#---------------------------------------------------------------------------
# ntkWidget ntkScrollbar.tcl --
#
# This file contains a ntkWidget scrollbar command implementation
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
# RCS: @(#) $Id: ntkScrollbar.tcl,v 1.1.2.10 2007/11/23 21:02:57 wiede Exp $
#--------------------------------------------------------------------------

#--------------------------------------------------------------------------
# a scrollbar consists of three parts:
#   * button $wpath.a	       |v|    themeScrollbarButton
#   * trough $wpath.trough     | |    themeScrollbarTrough
#   * button $wpath.b          |^|    themeScrollbarButton
# 
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::scrollbar {
    inherit ::ntk::classes::theme 

    private variable constructing 1

    public option -orient -default vertical -configuremethod scrollbarConfig
    public option -command -default {} -configuremethod scrollbarConfig
    public option -scrollbarwidth -default 20 -configuremethod scrollbarConfig
    public option -slidercolor -default [list 127 127 150 255] i\
            -configuremethod scrollbarConfig

    public methodvariable buttonAfterId -default "" 
    public methodvariable clickx -default 0
    public methodvariable clicky -default 0
    public methodvariable dragging -default 0
    public methodvariable idleAfterId -default "" 
    public methodvariable scale -default [list 0.0 1.0] 
    public methodvariable scaleoffset -default 0
    public methodvariable x1 -default 0
    public methodvariable x2 -default 0
    public methodvariable y1 -default 0
    public methodvariable y2 -default 0

    private method scrollbarConfig {option value} {
        set itcl_options($option) $value
        switch -- $option {
        -orient {
            scrollbarOrientCallback $value
          }
        }
        scrollbarDraw
    }

    constructor {args} {
        set themeConfig scrollbarConfig
	set itclOptions(-width) 20
	set itclOptions(-height) 200
        if {[llength $args]} {
	    configure {*}$args
	}
	set constructing 0
	appendRedrawHandler [list $wpath scrollbarDraw]

        themeScrollbarButton $wpath.a
        themeScrollbarTrough $wpath.trough
        $wpath.trough configure \
	        -buttonpress [list $wpath scrollbarScaleButtonpress] \
                -motion [list $wpath scrollbarScaleMotion] \
                -buttonrelease [list $wpath scrollbarScaleButtonrelease]
        themeScrollbarButton $wpath.b
# structure-make-method $wpath set [list $wpath scrollbarSetMethod]

        $wpath.a configure -buttonpress \
                [list $wpath scrollbarButtonpress $wpath.a -1]
        $wpath.a configure -buttonrelease \
                [list $wpath scrollbarButtonrelease $wpath.a]
        $wpath.b configure -buttonpress \
                [list $wpath scrollbarButtonpress $wpath.b 1]
        $wpath.b configure -buttonrelease \
                [list $wpath scrollbarButtonrelease $wpath.b]

        $wpath appendRedrawHandler [list $wpath scrollbarDraw]
        $wpath.trough appendRedrawHandler [list $wpath scrollbarDrawScale]

        #Trigger the request sizes, and redraws, just in case -orient wasn't specified in $args.
        configure -orient $itcl_options(-orient)
        return $wpath
    }

    public method scrollbarButtonRepeat {delay cmd} {
        uplevel #0 $cmd
        $wpath idleAfterId [after idle [list $wpath buttonAfterId \
                [after $delay [list $wpath scrollbarButtonRepeat $delay $cmd]]]]
    }

    public method scrollbarButtonpress {buttonpath unit button x y globalx globaly} {
#puts stderr "scrollbarButtonpress!$buttonpath!$unit!$button!"
        $buttonpath pressed 1
        if {($itcl_options(-command) ne "") && ($buttonAfterId eq "") && \
                ($idleAfterId eq "")} {
            set cmd [concat $itcl_options(-command) scroll $unit units]
            scrollbarButtonRepeat 100 $cmd
        }
    }

    public method scrollbarButtonrelease {buttonpath button x y globalx globaly} {
#puts stderr "scrollbarButtonrelease!$buttonpath!$button!"
        $buttonpath pressed 0
        after cancel $buttonAfterId
        set buttonAfterId ""
        after cancel $idleAfterId
        set idleAfterId ""
    }

    public method scrollbarDraw {} {
        if {$constructing} {
	    return
	}
        if {$itcl_options(-orient) eq "vertical"} {
            scrollbarDrawVertical 
        } else {
            scrollbarDrawHorizontal
        }
    }

    public method scrollbarDrawHorizontal {} {
        $obj fill $itcl_options(-bg)
        render $wpath $wpath.a $wpath.trough $wpath.b
    }

    public method scrollbarDrawScale {} {
        lassign $scale rstart rend
        set myWidth [$wpath.trough cget -width]
        set myHeight [$wpath.trough cget -height]
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        if {$itcl_options(-orient) eq "vertical"} {
            set myY [expr {round($rstart * $myHeight)}]
            set yend [expr {round($rend * $myHeight)}]
            set rectheight [expr {$yend - $myY}]
            [$wpath.trough obj] fill $itcl_options(-bg)
            [$wpath.trough obj] rectangle 0 $myY $myWidth $rectheight \
                    $itcl_options(-slidercolor)
            themeDrawBorder [$wpath.trough obj] 0 $myY $myWidth $rectheight \
                    $low $high 1
            set y1 $myY
            set y2 [expr {$myY + $rectheight}]
        } else {
            set myX [expr {round($rstart * $myWidth)}]
            set xend [expr {round($rend * $myWidth)}]
            set rectwidth [expr {$xend - $myX}]
            [$wpath.trough obj] fill $itcl_options(-bg)
            [$wpath.trough obj] rectangle $myX 0 $rectwidth $myHeight \
                    $itcl_options(-slidercolor)
            themeDrawBorder [$wpath.trough obj] $myX 0 $rectwidth \
                    $myHeight $low $high 1
            set x1 $myX
            set x2 [expr {$myX + $rectwidth}]
        }
    }

    public method scrollbarDrawVertical {} {
        $obj fill $itcl_options(-bg)
        render $wpath $wpath.a $wpath.trough $wpath.b
    }

    public method scrollbarOrientCallback {arg} {
        if {[::info comm $wpath.a] eq ""} {
            return
        }
        set sw $itcl_options(-scrollbarwidth)
        switch -- $arg {
        horizontal {
            $wpath.a direction left
            $wpath.b direction right
            requestSize 200 $sw
            $wpath.a requestSize $sw $sw
            $wpath.trough requestSize [expr {200 - ($sw * 2)}] $sw
            $wpath.b requestSize $sw $sw
            ntk grid $wpath.a -slot {0 0} -sticky height
            ntk grid $wpath.trough -slot {1 0} -sticky {width height}
            ntk grid $wpath.b -slot {2 0} -sticky height
          }
        vertical {
            $wpath.a direction up
            $wpath.b direction down
            requestSize $sw 200
            $wpath.a requestSize $sw $sw
            $wpath.trough requestSize $sw [expr {200 - ($sw * 2)}]
            $wpath.b requestSize $sw $sw
            ntk grid $wpath.a -slot {0 0} -sticky width
            ntk grid $wpath.trough -slot {0 1} -sticky {width height}
            ntk grid $wpath.b -slot {0 2} -sticky width
          }
        default {
            return -code error "invalid argument for -orient: $arg"
          }
        }
        return 1
    }

    public method scrollbarScaleButtonpress {button x y globalx globaly} {
#puts stderr "scrollbarScaleButtonpress!$button!"
        lassign $scale start end
        if {$itcl_options(-orient) eq "vertical"} {
            if {($y >= $y1) && ($y < $y2)} {
                set clickx $x
                set clicky $y
                set dragging 1
                set scaleoffset $y1
            }
        } else {
            if {($x >= $x1) && ($x < $x2)} {
                set clickx $x
                set clicky $y
                set dragging 1
                set scaleoffset $x1
            }
        }
    }

    public method scrollbarScaleButtonrelease {button x y globalx globaly} {
#puts stderr "scrollbarScaleButtonrelease!$button!"
        set dragging 0
    }

    public method scrollbarScaleMotion {x y globalx globaly} {
#puts stderr "scrollbarScaleMotion!$dragging!"
       if {$dragging == 0} {
           return
	}
        set xd [expr {$x - $clickx}]
        set yd [expr {$y - $clicky}]
        lassign $scale rstart rend
        set myWidth [$wpath.trough cget -width]
        set myHeight [$wpath.trough cget -height]
        if {$itcl_options(-orient) eq "vertical"} {
            if {$yd == 0} {
	        return
	    }
            set rat [expr {1.0 / $myHeight}]
            set moveto [expr {($yd + $scaleoffset) * $rat}]
        } else {
            if {$xd == 0} {
	        return
	    }
            set rat [expr {1.0 / $myWidth}]
            set moveto [expr {($xd + $scaleoffset) * $rat}]
        }
        set cmd $itcl_options(-command)
#puts stderr "cmd!$cmd!$moveto!$x!$y!$globalx!$globaly!$clickx!$clicky!"
	if {$cmd ne ""} {
            uplevel #0 $cmd moveto [list $moveto]
        }
    }

    public method setView {rstart rend} {
#puts stderr "SCROLL:$rstart $rend"
        #$wpath.trough
        set scale [list $rstart $rend]
        scrollbarDrawScale
    }
}
