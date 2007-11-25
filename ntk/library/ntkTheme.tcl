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
# RCS: @(#) $Id: ntkTheme.tcl,v 1.1.2.14 2007/11/25 15:37:22 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::theme {
    inherit ::ntk::classes::window

    private variable constructing 1
    protected variable themeConfig

    public methodvariable textImage -default [list]

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
        set xx [::ntk::widgetImage::Image create 1 1]
        ::ntk::widgetImage::Image createtext $xx $defaultFont $defaultFontSize "_^" [list 0 0 0 255] \
	        myWidth myHeight
	# MEMORY LEAK !! FIX ME !! need to destroy xx !!!
	# ::ntk::widgetImage::Image destroy $xx
	set itcl_options(-height) $myHeight
	set itcl_options(-reqwidth) $itcl_options(-width)
	set itcl_options(-reqheight) $myHeight
	set itcl_options(-font) $defaultFont
	set itcl_options(-fontsize) $defaultFontSize
	set itcl_options(-textcolor) $defaultTextColor
	set itcl_options(-bg) [defaultBackgroundColor]
	set textImage [::ntk::widgetImage::Image create 20 20]
    }

    public proc themeButtonDrawBorder {} {
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        themeDrawBorder 0 0 $itcl_options(-width) \
	        $itcl_options(-height) $low $high $itcl_options(-bd)
    }

    public proc themeButtonDrawPressedBorder {} {
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        themeDrawBorder 0 0 $itcl_options(-width) \
	        $itcl_options(-height) $high $low $itcl_options(-bd)
    }

    public proc themeDrawBorder {x y width height low high bd} {
        incr bd -1
        while {$bd >= 0} {
            set x1 [expr {$x + $bd}]
            set y1 [expr {$y + $bd}]
            set x2 [expr {($x + $width) - $bd - 1}]
            set y2 [expr {($y + $height) - $bd - 1}]
            #top line
            ::ntk::widgetImage::Image line $windowImage $x1 $y1 $x2 $y1 $high
            #right line
            ::ntk::widgetImage::Image line $windowImage $x2 $y1 $x2 $y2 $low
            #bottom line
            ::ntk::widgetImage::Image line $windowImage $x1 $y2 $x2 $y2 $low
            #left line
            ::ntk::widgetImage::Image line $windowImage $x1 $y1 $x1 $y2 $high
            incr bd -1
        }
    }
    public method themeDrawGenericBorder {} {
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        themeDrawBorder 0 0 $itcl_options(-width) \
                $itcl_options(-height) $high $low $itcl_options(-bd)
    }

    public proc themeDrawTextBackground {} {
        # TODO add tile call with nice metallic background.
        ::ntk::widgetImage::Image fill $windowImage $itcl_options(-bg)
    }

    public proc themeGetText {} {
        list -bg [list 255 255 255 255] -fg [list 0 0 0 255] \
	        -theme default -themeclass text
    }

    public proc themeLabelDrawBorder {} {
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        themeDrawBorder 0 0 $itcl_options(-width) \
	        $itcl_options(-height) $low $high $itcl_options(-bd)
    }

    public method themeListboxDrawBorder {} {
         set low [list 20 20 20 255]
         set high [list 200 200 200 255]
         themeDrawBorder 0 0 $itcl_options(-width) \
	         $itcl_options(-height) $high $low $itcl_options(-bd)
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
        ::ntk::widgetImage::Image fill [$path windowImage] [[$path parent] cget -bg]

        if {[$path pressed] == 0} {
            $path themeDrawBorder 0 0 $w $h $low $high 1
        } else {
            $path themeDrawBorder 0 0 $w $h $high $low 1
        }
        switch -- [$path direction] {
        up {
            [$path windowImage] polygon [list 0 0 0 255] \
                    [expr {$w / 2}] 2  \
                    2 [expr {$h - 2}]  [expr {$w - 2}] [expr {$h - 2}]
          }
        down {
            [$path windowImage] polygon [list 0 0 0 255] \
                    2 2 [expr {$w - 2}] 2 \
                    [expr {$w / 2}] [expr {$h - 2}]         
          }
        left {
            [$path windowImage] polygon [list 0 0 0 255] \
                    2 [expr {$h / 2}] [expr {$w - 2}] 2 \
		    [expr {$w - 2}] [expr {$h - 2}]
          }
        right {
            [$path windowImage] polygon [list 0 0 0 255] \
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
        [$path windowImage] fill [list 127 127 127 255]
        render $path
    }

    public method themeSpinboxButtonBgDraw {path} {
        [$path windowImage] fill $default_background_color
    }
  
    public method themeSpinboxButtonDownDraw {path} {
        set w [$path cget -width]
        set h [$path cget -height]
        [$path windowImage] polygon [list 0 0 0 255] \
                2 2       [expr {$w - 2}] 2 \
                [expr {$w / 2}] [expr {$h - 2}]
    }
  
    public method themeSpinboxButtonUpDraw {path} {
        set w [$path width]
        set h [$path height]
  
        [$path windowImage] polygon [list 0 0 0 255] \
             [expr {$w / 2}] 2 \
             2 [expr {$h - 2}]  [expr {$w - 2}] [expr {$h - 2}]
        render $path
    }
  
    public method themeSpinboxDrawTextareaBorder {path} {
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        themeDrawBorder [$path.textarea windowImage] 0 0 \
                [expr {[$path.textarea cget -width] - 1}] \
                [$path.textarea cget -height] $high $low [$path cget -bd]
   }
  
   public method themeSpinboxMakeButtonImage {direction} {
       set w 18
       set h 12
       set myWidgetImage [uplevel #0 ntkWidget #auto -width $w -height $h]
       if {$direction eq "up"} {
           $myWidgetImage polygon [list 0 0 0 255] \
                   [expr {$w / 2}] 2 \
                   2 [expr {$h - 2}]  [expr {$w - 2}] [expr {$h - 2}]
       } else {
               $myWidgetImage polygon [list 0 0 0 255] \
                   2 2 [expr {$w - 2}] 2 \
                   [expr {$w / 2}] [expr {$h - 2}]
       }
       return $myWidgetImage
    }
}
