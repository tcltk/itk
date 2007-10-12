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
# RCS: @(#) $Id: ntkScrollbar.tcl,v 1.1.2.3 2007/10/12 21:09:57 wiede Exp $
#--------------------------------------------------------------------------

itcl::eclass ::ntk::classes::scrollbar {
    inherit ::ntk::classes::theme 

    private variable scrollbarDraw [list]
    private variable scale [list 0.0 1.0] 
    private variable button_afterid "" 

    public option -clickx -default 0 -configuremethod scrollbarConfig
    public option -clicky -default 0 -configuremethod scrollbarConfig
    public option -dragging -default 0 -configuremethod scrollbarConfig
    public option -scaleoffset -default 0 -configuremethod scrollbarConfig
    public option -x1 -default 0 -configuremethod scrollbarConfig
    public option -x2 -default 0 -configuremethod scrollbarConfig
    public option -y1 -default 0 -configuremethod scrollbarConfig
    public option -y2 -default 0 -configuremethod scrollbarConfig
    public option -orient -default vertical -configuremethod scrollbarConfig
    public option -command -default {} -configuremethod scrollbarConfig
    public option -bg -default {} -validatemethod verifyColor -configuremethod labelConfig

    private method scrollbarConfig {option value} {
        set itcl_options($option) $value
        if {$scrollbarDraw ne ""} {
            $scrollbarDraw [path]
        }
    }

    public method scale {{value {}}} {
	if {$value eq ""} {
            return $scale
	} else {
	    set scale $value
	}
    }

    public method button_afterid {{value {}}} {
	if {$value eq ""} {
            return $button_afterid
	} else {
	    set button_afterid $value
	}
    }

    constructor {args} {
        eval ::ntk::classes::window::constructor -width 20 -height 20
    } {
	set itcl_options(-bg) [defaultBackgroundColor]
	set path [path]
	eval configure $args
	appendRedrawHandler [list $path labelDraw $path]

        themeScrollbarButton $path.a
        themeScrollbarTrough $path.trough
        $path.trough -buttonpress [list scrollbarScaleButtonpress $path] \
            -motion [list scrollbarScaleMotion $path] \
            -buttonrelease [list scrollbarScaleButtonrelease $path]
        themeScrollbarButton $path.b
# structure-key-callback $path -orient [list scrollbarOrientCallback $path]
# structure-make-method $path set [list scrollbarSetMethod $path]

        $path.a -buttonpress [list scrollbarButtonpress $path.a $path -1]
        $path.a -buttonrelease [list scrollbarButtonrelease $path.a $path]
        $path.b -buttonpress [list scrollbarButtonpress $path.b $path 1]
        $path.b -buttonrelease [list scrollbarButtonrelease $path.b $path]

        appendRedrawHandler $path [list scrollbarDraw $path]
        appendRedrawHandler $path.trough [list scrollbarDrawScale $path]

        #Trigger the request sizes, and redraws, just in case -orient wasn't specified in $args.
        $path configure -orient [$path cget -orient]
        return $path
    }

    public method scrollbarButtonRepeat {path delay cmd} {
        uplevel #0 $cmd
        $path button_afterid [after $delay [list scrollbarButtonRepeat $path $delay $cmd]]
    }

    public method scrollbarButtonpress {buttonpath path unit button x y globalx globaly} {
        $buttonpath pressed 1
        if {[$path cget -command] ne ""} {
            set cmd [concat [$path cget -command] scroll $unit units]
            scrollbarButtonRepeat $path 100 $cmd
        }
    }

    public method scrollbarButtonrelease {buttonpath path button x y globalx globaly} {
        $buttonpath pressed 0
        after cancel [$path button_afterid]
        $path button_afterid ""
    }

    public method scrollbarDraw {path} {
        if {[$path cget -orient] eq "vertical"} {
            scrollbarDrawVertical $path 
        } else {
            NS_scrollbarDrawHorizontal $path
        }
    }

    public method scrollbarDrawHorizontal {path} {
        set w [$path cget -width]
        set h [$path cget -height]
        [$path obj] setall [$path cget -bg]
        requestSize $path.a $h $h
        requestSize $path.b $h $h
        requestSize $path.trough 1 $h
        render $path $path.a $path.trough $path.b
    }

    public method scrollbarDrawScale {path} {
        lassign [$path scale] rstart rend
        set width [$path.trough cget -width]
	set height [$path.trough cget -height]

        if {[$path cget -orient] eq "vertical"} {
            set y [expr {round($rstart * $height)}]
            set yend [expr {round($rend * $height)}]
            set rectheight [expr {$yend - $y}]
            [$path.trough obj] setall [$path cget -bg]
            [$path.trough obj] rectangle 0 $y $width $rectheight [list 255 0 0 255]
            $path configure -y1 $y -y2 [expr {$y + $rectheight}]
        } else {
            set x [expr {round($rstart * $width)}]
            set xend [expr {round($rend * $width)}]
            set rectwidth [expr {$xend - $x}]
            [$path.trough obj] setall [$path cget -bg]
            [$path.trough obj] rectangle $x 0 $rectwidth $height [list 0 0 255 255]
            $path configure -x1 $x -x2 [expr {$x + $rectwidth}]
        }
    }

    public method scrollbarDrawVertical {path} {
        set w [$path cget -width]
        set h [$path cget -height]
        [$path obj] setall [$path cget -bg]
        requestSize $path.a $w $w
        requestSize $path.b $w $w
        requestSize $path.trough $w 1
        render $path $path.a $path.trough $path.b
    }

    public method scrollbarOrientCallback {path arg} {
        set w [$path cget -width]
        set h [$path cget -height]

        switch -- $arg {
        horizontal {
            $path.a direction left
            $path.b direction right
            requestSize $path.a $h $h
            requestSize $path.trough 1 $h
            requestSize $path.b $h $h
            grid $path.a -slot {0 0} -sticky height
            grid $path.trough -slot {1 0} -sticky {width height}
            grid $path.b -slot {2 0} -sticky height
          }
        vertical {
            $path.a direction up
            $path.b direction down
            requestSize $path.a $w $w
            requestSize $path.trough $w [expr {$h - ($w * 2)}]
            requestSize $path.b $w $w
            grid $path.a -slot {0 0} -sticky width
            grid $path.trough -slot {0 1} -sticky {width height}
            grid $path.b -slot {0 2} -sticky width
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
            if {$y >= [$path y1] && $y < [$path y2]} {
                $path configure -clickx $x -clicky $y -dragging 1 -scaleoffset [$path cget -y1]
            }
        } else {
            if {$x >= [$path x1] && $x < [$path x2]} {
                $path configure -clickx $x -clicky $y -dragging 1 -scaleoffset [$path cget -x1]
            }
        }
    }

    public method scrollbarScaleButtonrelease {path button x y globalx globaly} {
        $path configure -dragging 0
    }

    public method scrollbarScaleMotion {path x y globalx globaly} {
       if {![$path cget -dragging]} {
           return
	}
        set xd [expr {$globalx - [$path cget -clickx]}]
        set yd [expr {$globaly - [$path cget -clicky]}]
        lassign [$path scale] rstart rend
        set width [$path.trough cget -width]
        set height [$path.trough cget -height]
        if {[$path cget -orient] eq "vertical"} {
            if {$yd == 0} {
	        return
	    }
            set rat [expr {1.0 / $height}]
            set moveto [expr {($yd + [$path cget -scaleoffset]) * $rat}]
            set cmd [$path cget -command]
            uplevel #0 $cmd moveto [list $moveto]
        } else {
            if {$xd == 0} {
	        return
	    }
            set rat [expr {1.0 / $width}]
            set moveto [expr {($xd + [$path cget -scaleoffset]) * $rat}]
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
