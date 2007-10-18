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
# RCS: @(#) $Id: ntkScrollbar.tcl,v 1.1.2.6 2007/10/18 21:42:27 wiede Exp $
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

    public methodvariable scale -default [list 0.0 1.0] 
    public methodvariable clickx -default 0
    public methodvariable clicky -default 0
    public methodvariable dragging -default 0
    public methodvariable buttonAfterId -default "" 
    public methodvariable idleAfterId -default "" 
    public methodvariable x1 -default 0
    public methodvariable x2 -default 0
    public methodvariable y1 -default 0
    public methodvariable y2 -default 0
    public methodvariable scaleoffset -default 0

    private method scrollbarConfig {option value} {
        set itcl_options($option) $value
        switch -- $option {
        -orient {
            scrollbarOrientCallback $wpath $value
          }
        }
        scrollbarDraw $wpath
    }

    constructor {args} {
        set themeConfig scrollbarConfig
	set itclOptions(-width) 20
	set itclOptions(-height) 200
        if {[llength $args]} {
	    configure {*}$args
	}
	set constructing 0
	appendRedrawHandler [list $wpath scrollbarDraw $wpath]

        themeScrollbarButton $wpath.a
        themeScrollbarTrough $wpath.trough
        $wpath.trough configure \
	        -buttonpress [list $wpath scrollbarScaleButtonpress $wpath] \
                -motion [list $wpath scrollbarScaleMotion $wpath] \
                -buttonrelease [list $wpath scrollbarScaleButtonrelease $wpath]
        themeScrollbarButton $wpath.b
# structure-make-method $wpath set [list $wpath scrollbarSetMethod $wpath]

        $wpath.a configure -buttonpress \
                [list $wpath scrollbarButtonpress $wpath.a $wpath -1]
        $wpath.a configure -buttonrelease \
                [list $wpath scrollbarButtonrelease $wpath.a $wpath]
        $wpath.b configure -buttonpress \
                [list $wpath scrollbarButtonpress $wpath.b $wpath 1]
        $wpath.b configure -buttonrelease \
                [list $wpath scrollbarButtonrelease $wpath.b $wpath]

        $wpath appendRedrawHandler [list $wpath scrollbarDraw $wpath]
        $wpath.trough appendRedrawHandler [list $wpath scrollbarDrawScale $wpath]

        #Trigger the request sizes, and redraws, just in case -orient wasn't specified in $args.
        $wpath configure -orient [$wpath cget -orient]
        return $wpath
    }

    public method scrollbarButtonRepeat {path delay cmd} {
        uplevel #0 $cmd
        $path idleAfterId [after idle [list $path buttonAfterId \
                [after $delay [list scrollbarButtonRepeat $path $delay $cmd]]]]
    }

    public method scrollbarButtonpress {buttonpath path unit button x y globalx globaly} {
        $buttonpath pressed 1
        if {([$path cget -command] ne "") && ([$path button_afterid] eq "") && \
                ([$path idle_afterid] eq "")} {
            set cmd [concat [$path cget -command] scroll $unit units]
            scrollbarButtonRepeat $path 100 $cmd
        }
    }

    public method scrollbarButtonrelease {buttonpath path button x y globalx globaly} {
        $buttonpath pressed 0
        after cancel [$path buttonAfterId]
        $path buttonAfterId ""
        after cancel [$path idleAfterId]
        $path idleAfterId ""
    }

    public method scrollbarDraw {path} {
        if {$constructing} {
	    return
	}
        if {[$path cget -orient] eq "vertical"} {
            scrollbarDrawVertical $path 
        } else {
            scrollbarDrawHorizontal $path
        }
    }

    public method scrollbarDrawHorizontal {path} {
        [$path obj] setall [$path cget -bg]
        render $path $path.a $path.trough $path.b
    }

    public method scrollbarDrawScale {path} {
        lassign [$path scale] rstart rend
        set myWidth [$path.trough cget -width]
        set myHeight [$path.trough cget -height]
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        if {[$path cget -orient] eq "vertical"} {
            set myY [expr {round($rstart * $myHeight)}]
            set yend [expr {round($rend * $myHeight)}]
            set rectheight [expr {$yend - $myY}]
            [$path.trough obj] setall [$path cget -bg]
            [$path.trough obj] rectangle 0 $myY $myWidth $rectheight \
                    [$path cget -slidercolor]
            themeDrawBorder [$path.trough obj] 0 $myY $myWidth $rectheight \
                    $low $high 1
            $path y1 myY$
            $path y2 [expr {$myY + $rectheight}]
        } else {
            set myX [expr {round($rstart * $myWidth)}]
            set xend [expr {round($rend * $myWidth)}]
            set rectwidth [expr {$xend - $myX}]
            [$path.trough obj] setall [$path -bg]
            [$path.trough obj] rectangle $myX 0 $rectwidth $myHeight \
                    [$path cget -slidercolor]
            themeDrawBorder [$path.trough obj] $myX 0 $rectwidth \
                    $myHeight $low $high 1
            $path x1 $myX
            $path x2 [expr {$myX + $rectwidth}]
        }
    }

    public method scrollbarDrawVertical {path} {
        [$path obj] setall [$path cget -bg]
        render $path $path.a $path.trough $path.b
    }

    public method scrollbarOrientCallback {path arg} {
        if {[::info comm $path] eq ""} {
            return
        }
        set sw [$path cget -scrollbarwidth]
        switch -- $arg {
        horizontal {
            $path.a direction left
            $path.b direction right
            requestSize $path 200 $sw
            requestSize $path.a $sw $sw
            requestSize $path.trough [expr {200 - ($sw * 2)}] $sw
            requestSize $path.b $sw $sw
            ntk grid $path.a -slot {0 0} -sticky height
            ntk grid $path.trough -slot {1 0} -sticky {width height}
            ntk grid $path.b -slot {2 0} -sticky height
          }
        vertical {
            $path.a direction up
            $path.b direction down
            requestSize $path $sw 200
            requestSize $path.a $sw $sw
            requestSize $path.trough $sw [expr {200 - ($sw * 2)}]
            requestSize $path.b $sw $sw
            ntk grid $path.a -slot {0 0} -sticky width
            ntk grid $path.trough -slot {0 1} -sticky {width height}
            ntk grid $path.b -slot {0 2} -sticky width
          }
        default {
            return -code error "invalid argument for -orient: $arg"
          }
        }
        return 1
    }

    public method scrollbarScaleButtonpress {path button x y globalx globaly} {
        lassign [$path scale] start end
        if {[$path cget -orient] eq "vertical"} {
            if {($y >= [$path y1]) && ($y < [$path y2])} {
                $path clickx $x
                $path clicky $y
                $path dragging 1
                $path scaleoffset [$path y1]
            }
        } else {
            if {($x >= [$path x1]) && ($x < [$path x2])} {
                $path clickx $x
                $path clicky $y
                $path dragging 1
                $path scaleoffset [$path x1]
            }
        }
    }

    public method scrollbarScaleButtonrelease {path button x y globalx globaly} {
        $path dragging 0
    }

    public method scrollbarScaleMotion {path x y globalx globaly} {
       if {[$path dragging] == 0} {
           return
	}
        set xd [expr {$x - [$path clickx]}]
        set yd [expr {$y - [$path clicky]}]
        lassign [$path scale] rstart rend
        set myWidth [$path.trough cget -width]
        set myHeight [$path.trough cget -height]
        if {[$path cget -orient] eq "vertical"} {
            if {$yd == 0} {
	        return
	    }
            set rat [expr {1.0 / $myHeight}]
            set moveto [expr {($yd + [$path scaleoffset]) * $rat}]
            set cmd [$path cget -command]
            uplevel #0 $cmd moveto [list $moveto]
        } else {
            if {$xd == 0} {
	        return
	    }
            set rat [expr {1.0 / $myWidth}]
            set moveto [expr {($xd + [$path scaleoffset]) * $rat}]
            set cmd [$path cget -command]
            uplevel #0 $cmd moveto [list $moveto]
        }
    }

    public method scrollbarSetMethod {path rstart rend} {
        #puts "SCROLL:$path $rstart $rend"
        #$path.trough
        $path scale [list $rstart $rend]
        scrollbarDrawScale $path
    }
}
