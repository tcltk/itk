#---------------------------------------------------------------------------
# ntkWidget ntkHelpers.tcl --
#
# This file contains a ntkWidget helper commands implementation
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
# RCS: @(#) $Id: ntkHelpers.tcl,v 1.1.2.12 2007/11/25 17:12:48 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::helpers {
    protected common colors

    private common rendering 0
    private common backgroundColor [list 16 33 65 255]
#    private common backgroundColor [list 255 255 255 0]
    protected common focusList [list]
    protected common defaultFont /usr/X11R6/lib/X11/fonts/truetype/Vera.ttf
    protected common defaultFontSize 12
    protected common defaultTextColor [list 10 10 10 255]
    protected common defaultBackgoundColor [list 127 127 127 255]

    constructor {args} {
        array set colors {
	    red {255 0 0 255}
	    green {0 255 0 255}
	    blue {0 0 255 255}

	    black {0 0 0 255}
	    white {255 255 255 255}

	    grey {127 127 127 255}

	    orange {255 165 0 255}
	    royalblue {65 105 225 255}
	    hummeryellow {... ... ... ...}
        }
    }
    protected proc verifyColor {option value} {
        switch -- [llength $value] {
        1 {
            #
            # Look in the symbolic colormap.
            #
            set lcvalue [string tolower $value]
            if {![info exist colors($lcvalue)]} {
                return -code error "invalid symbolic color $value"
            }
            #
            # The color is valid, so set it.
            #
            set itcl_options($option) $colors($lcvalue)
            return 0
          }
         
        4 {
            foreach c $value {
                if {![string is integer -strict $c]} {
                    return -code error "invalid color component in list (not an integer): $value"
                }
            }
            return 1
          }
        default {
            return -code error "invalid color format: $value"
          }
        }
    }
    protected proc defaultBackgroundColor {} {
#        return $colors(grey)
#        return $defaultBackgoundColor
         return [list 127 127 127 255]
    }

    protected proc verifyBorder {option value} {
        if {$value < 0} {
	    return -code error "invalid border value: $value"
	}
        if {![string is integer -strict $value]} {
	    return -code error "invalid border value: $value"
	}
        return 1
    }

    protected proc verifyBoolean {option value} {
        if {$value < 0} {
	    return -code error "invalid boolean value: $value"
	}
        if {![string is boolean -strict $value]} {
	    return -code error "invalid boolean value: $value"
	}
        return 1
    }

    public proc focus {path} {
        set focusList [list $path]
    }

    public proc focusAppend {path} {
        lappend focusList $path
    }

    public proc getFocus {} {
        return $focusList
    }

    public proc drawPixels {topWindow window} {
        set data [::ntk::widgetImage::Image getdata [$window windowImage]]
	set w [$window cget -width]
	set h [$window cget -height]
	::ntk::glmwfw::Glmwfw drawWidgetImagePixels $w $h $data
	::ntk::glmwfw::Glmwfw swapBuffers $topWindow
    }
}

proc dumpMegaimage {obj} {
    lassign [$obj getsize] width height
puts stderr "height!$height!"
    for {set y 0} {$y < $height} {incr y} {
        puts stderr "row!$y![$obj getrow $y]!"
    }
}

proc dumpMegaimage2 {obj} {
    lassign [$obj getsize] width height
    for {set y 0} {$y < $height} {incr y} {
        puts -nonewline stderr "$y!"
        foreach {r g b a} [$obj getrow $y] {
            puts -nonewline stderr "[format {%x %x %x %x  } $r $g $b $a] "
        }
        puts stderr ""
    }
}
    
