#---------------------------------------------------------------------------
# ntkWidget ntkTheme.tcl --
#
# This file contains a ntkWidget theme command implementation
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
# RCS: @(#) $Id: ntkTheme.tcl,v 1.1.2.10 2007/10/22 20:32:53 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::theme {
    inherit ::ntk::classes::window

    private variable constructing 1
    protected variable themeConfig

    public methodvariable textobj -default [list]

    public option -font -default {} -configuremethodvar themeConfig
    public option -fontsize -default {} -configuremethodvar themeConfig
    public option -text -default {} -configuremethodvar themeConfig
    public option -textcolor -default {} -validatemethodvar verifyColor \
            -configuremethodvar themeConfig
    public option -bd -default 0 -validatemethod verifyBorder \
            -configuremethodvar themeConfig

    constructor {args} {
        eval ::ntk::classes::window::constructor -width 60 -height 100
    } {
        freetype $defaultFont $defaultFontSize "_^" [list 0 0 0 255] \
	        myWidth myHeight
	set itcl_options(-height) $myHeight
	set reqwidth $itcl_options(-width)
	set reqheight $myHeight
	set itcl_options(-font) $defaultFont
	set itcl_options(-fontsize) $defaultFontSize
	set itcl_options(-textcolor) $defaultTextColor
	set itcl_options(-bg) [defaultBackgroundColor]
	set textobj [megaimage-blank 20 20]
    }

    public proc themeButtonDrawBorder {path} {
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        themeDrawBorder [$path obj] 0 0 [$path cget -width] [$path cget -height] $low $high [$path cget -bd]
    }

    public proc themeButtonDrawPressedBorder {path} {
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        themeDrawBorder [$path obj] 0 0 [$path cget -width] [$path cget -height] $high $low [$path cget -bd]
    }

    public proc themeDrawBorder {obj x y width height low high bd} {
        incr bd -1
        while {$bd >= 0} {
            set x1 [expr {$x + $bd}]
            set y1 [expr {$y + $bd}]
            set x2 [expr {($x + $width) - $bd - 1}]
            set y2 [expr {($y + $height) - $bd - 1}]
            #top line
#puts stderr "top!$obj!$x1!$y1!$x2!$y1!$high!$low!"
            $obj line $x1 $y1 $x2 $y1 $high
            #right line
            $obj line $x2 $y1 $x2 $y2 $low
            #bottom line
            $obj line $x1 $y2 $x2 $y2 $low
            #left line
            $obj line $x1 $y1 $x1 $y2 $high
            incr bd -1
        }
    }

    public proc themeDrawTextBackground {path} {
        # TODO add tile call with nice metallic background.
        [$path obj] setall [$path cget -bg]
    }

    public proc themeGetText {} {
        list -bg [list 255 255 255 255] -fg [list 0 0 0 255] \
	        -theme default -themeclass text
    }

    public proc themeLabelDrawBorder {path} {
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        themeDrawBorder [$path obj] 0 0 [$path cget -width] \
	        [$path cget -height] $low $high [$path cget -bd]
    }

    public method themeListboxDrawBorder {path} {
         set low [list 20 20 20 255]
         set high [list 200 200 200 255]
         themeDrawBorder [$path obj] 0 0 [$path cget -width] \
	         [$path cget -height] $high $low [$path cget -bd]
    }

    public proc themeScrollbarButton {path} {
        uplevel #0 ntk::classes::scrollbarbutton $path -width 20 -height 20
        $path appendRedrawHandler [list $path themeScrollbarButtonDraw $path]
        foreach key [list pressed direction] {
#             structure-trace-key $path $key [list $path themeScrollbarButtonDraw $path]
        }
    }

    public proc themeScrollbarButtonDraw {path} {
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        set w [$path cget -width]
        set h [$path cget -height]
        [$path obj] setall [[$path parent] cget -bg]

        if {[$path pressed] == 0} {
            themeDrawBorder [$path obj] 0 0 $w $h $low $high 1
        } else {
            themeDrawBorder [$path obj] 0 0 $w $h $high $low 1
        }
        switch -- [$path direction] {
        up {
            [$path obj] polygon [list 0 0 0 255] \
                    [expr {$w / 2}] 2  \
                    2 [expr {$h - 2}]  [expr {$w - 2}] [expr {$h - 2}]
          }
        down {
            [$path obj] polygon [list 0 0 0 255] \
                    2 2 [expr {$w - 2}] 2 \
                    [expr {$w / 2}] [expr {$h - 2}]         
          }
        left {
            [$path obj] polygon [list 0 0 0 255] \
                    2 [expr {$h / 2}] [expr {$w - 2}] 2 \
		    [expr {$w - 2}] [expr {$h - 2}]
          }
        right {
            [$path obj] polygon [list 0 0 0 255] \
                     2 2 [expr {$w - 2}] [expr {$h / 2}] 2 [expr {$h - 2}]
          }
        }
        render $path
    }

    public proc themeScrollbarTrough {path} {
        uplevel #0 ntk::classes::scrollbarbutton $path -width 20 -height 20
        $path appendRedrawHandler [list $path themeScrollbarButtonDraw $path]
    }

    public proc themeScrollbarTroughDraw {path} {
        [$path obj] setall [list 127 127 127 255]
        render $path
    }

}
