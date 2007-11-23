#---------------------------------------------------------------------------
# ntkWidget ntkButton.tcl --
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
# RCS: @(#) $Id: ntkButton.tcl,v 1.1.2.14 2007/11/23 21:02:57 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::button {
    inherit ::ntk::classes::theme 

    private variable constructing 1

    public option -textwidth -default 0 -configuremethod buttonConfig
    public option -textheight -default 0 -configuremethod buttonConfig
    public option -command -default {} -configuremethod buttonConfig
    public option -state -default released -configuremethod buttonConfig

    private method buttonConfig {option value} {
puts stderr "buttonConfig!$option!$value!"
        set itcl_options($option) $value
        switch -- $option {
	-font -
	-fontsize -
	-bg -
	-bd -
	-textcolor -
	-state -
	-text {
	    buttonTrace
	  }
	default {
            buttonDraw
	  }
	}
    }

    constructor {args} {
puts stderr "BUTTON CONSTR"
	set itcl_options(-buttonpress) [list $wpath buttonPress]
	set itcl_options(-buttonrelease) [list $wpath buttonRelease]
	set itcl_options(-width) 60
	set itcl_options(-height) 30
	set itcl_options(-bd) 1
	set itcl_options(-reqwidth) 60
	set itcl_options(-reqheight) 30
	set themeConfig buttonConfig
	set destroy buttonDestroy
puts stderr "BUTTON CONFIG $args"
	if {[llength $args] > 0} {
	    configure {*}$args
	}
	appendRedrawHandler [list $wpath buttonRedraw]
	set constructing 0
puts stderr "BUTTON DRAW"
	buttonDraw
puts stderr "BUTTON CONSTR END"
        return $wpath
    }

    public method buttonPress {button x y globalx globaly} {
#puts stderr "button!buttonPress called $x $y"
        if {$button == 1} {
            configure -state pressed
        }
#puts stderr "button!buttonPress END"
    }

    public method buttonRelease {button x y globalx globaly} {
#puts stderr "button!buttonRelease called $button $x $y"
        configure -state released
        if {($x < 0) || ($y < 0) || ($x >= $itcl_options(-width)) ||
	        ($y >= $itcl_options(-height))} {
            return
        }
        if {$button == 1} {
	    set cmd $itcl_options(-command)
#puts stderr "CMD!$cmd!"
	    if {$cmd ne ""} {
                uplevel #0 $cmd
	    }
        }
    }

    public method buttonDestroy {} {
        rename [textImage] {}
    }

    public method buttonDraw {} {
puts stderr "buttonDraw!"
	if {$constructing} {
	    return
	}
	set myColor $itcl_options(-bg)
	if {[llength $myColor] == 1} {
	    ::ntk::widgetImage::Image fill $windowImage $colors($myColor)
	} else {
	    ::ntk::widgetImage::Image fill $windowImage $myColor
	}
        themeButtonDrawBorder
        buttonDrawText
        render $wpath
    }

    public method buttonDrawPressed {} {
#puts stderr "buttonDrawPressed!"
	set myColor $itcl_options(-bg)
	if {[llength $myColor] == 1} {
	    $windowImage fill $colors($myColor)
	} else {
	    $windowImage fill $myColor
	}
        themeButtonDrawPressedBorder $wpath
        buttonDrawText
        render $wpath
    }

    public method buttonDrawText {} {
        lassign [::ntk::widgetImage::Image getsize $windowImage] winwidth winheight
#puts stderr "WIHE!$winwidth!$winheight!$itcl_options(-width)!$itcl_options(-height)!"
        lassign [::ntk::widgetImage::Image getsize $textImage] textwidth textheight
#puts stderr "buttonDrawText!$wpath!$winwidth!$winheight!$textwidth!$textheight!"
        set myX [expr {($winwidth / 2) - ($textwidth / 2)}]
        set myY [expr {($winheight / 2) - ($textheight / 2)}]
#puts stderr "TextObj!$textImage!$myX!$myY!$obj!"
        ::ntk::widgetImage::Image blendwidget $windowImage $myX $myY $textImage
    }

    public method buttonRedraw {} {
#puts stderr "buttonRedraw!"
	if {$constructing} {
	    return
	}
        if {$itcl_options(-state) eq "released"} {
            buttonDraw
            return
        }
        buttonDrawPressed
    }

    public method buttonStateCallback {value} {
        if {($value ne "pressed")  && ($value ne "released")} {
            return -code error "invalid argument: $value"
        }
        return 1
    }

    public method buttonTextCallback {value} {
puts stderr "buttonTextCallback!$value!$textImage!"
	::ntk::widgetImage::Image createtext $textImage $itcl_options(-font) \
	        $itcl_options(-fontsize) $value $itcl_options(-textcolor) \
	        myWidth myHeight
#puts stderr MYWH!$myWidth!$myHeight!"
        configure -textwidth $myWidth -textheight $myHeight
	set myBd $itcl_options(-bd)
        set myWidth [expr {$myWidth + 2 + ($myBd * 2)}]
        set myHeight [expr {$myHeight + 2 + ($myBd * 2)}]
        requestSize $myWidth $myHeight
#puts stderr "buttonTextCallback END!$value!"
        return 1
   }

    public method buttonTrace {} {
#puts stderr "buttonTrace!"
        buttonTextCallback $itcl_options(-text)
        buttonRedraw
#puts stderr "buttonTrace END!"
    }
}
