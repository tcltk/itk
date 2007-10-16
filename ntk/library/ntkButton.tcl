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
# RCS: @(#) $Id: ntkButton.tcl,v 1.1.2.9 2007/10/16 10:01:42 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::button {
    inherit ::ntk::classes::theme 

    private variable constructing 1

    public option -textwidth -default 0 -configuremethod buttonConfig
    public option -textheight -default 0 -configuremethod buttonConfig
    public option -command -default {} -configuremethod buttonConfig
    public option -state -default released -configuremethod buttonConfig

    private method buttonConfig {option value} {
#puts stderr "buttonConfig!$option!$value!"
        set itcl_options($option) $value
        switch -- $option {
	-font -
	-fontsize -
	-bg -
	-bd -
	-textcolor -
	-state -
	-text {
	    buttonTrace $wpath
	  }
	default {
             buttonDraw $wpath
	  }
	}
    }

    constructor {args} {
	set itcl_options(-buttonpress) [list $wpath buttonPress $wpath]
	set itcl_options(-buttonrelease) [list $wpath buttonRelease $wpath]
	set themeConfig buttonConfig
	set destroy buttonDestroy
	configure {*}$args
	appendRedrawHandler [list $wpath buttonRedraw $wpath]
	set constructing 0
	buttonDraw $wpath
        return $wpath
    }

    public method buttonPress {path button x y globalx globaly} {
puts stderr "button!buttonPress called $x $y"
        if {$button == 1} {
            $path configure -state pressed
        }
#puts stderr "button!buttonPress END"
    }

    public method buttonRelease {path button x y globalx globaly} {
puts stderr "button!buttonRelease called $button $x $y"
        $path configure -state released
        if {($x < 0) || ($y < 0) || ($x >= [$path cget -width]) ||
	        ($y >= [$path cget -height])} {
            return
        }
        if {$button == 1} {
	    set cmd [$path cget -command]
puts stderr "CMD!$cmd!"
	    if {$cmd ne ""} {
                uplevel #0 $cmd
	    }
        }
    }

    public method buttonDestroy {path} {
        rename [$path textobj] {}
    }

    public method buttonDraw {path} {
#puts stderr "buttonDraw!$path!"
	if {$constructing} {
	    return
	}
	set myColor [$path cget -bg]
	if {[llength $myColor] == 1} {
	    $obj setall $colors($myColor)
	} else {
	    $obj setall $myColor
	}
        themeButtonDrawBorder $path
        buttonDrawText $path
        render $path
    }

    public method buttonDrawPressed {path} {
	set myColor [$path cget -bg]
	if {[llength $myColor] == 1} {
	    $obj setall $colors($myColor)
	} else {
	    $obj setall $myColor
	}
        themeButtonDrawPressedBorder $path
        buttonDrawText $path
        render $path
    }

    public method buttonDrawText {path} {
        lassign [$obj getsize] winwidth winheight
        lassign [[$path textobj] getsize] textwidth textheight
#puts stderr "buttonDrawText!$path!$wpath!$winwidth!$winheight!$textwidth!$textheight!"
        set myX [expr {($winwidth / 2) - ($textwidth / 2)}]
        set myY [expr {($winheight / 2) - ($textheight / 2)}]
        set myTextObj [$path textobj]
        [$path obj] blendobj $myX $myY $myTextObj
    }

    public method buttonRedraw {path} {
#puts stderr "buttonRedraw!$path!"
	if {$constructing} {
	    return
	}
        if {[$path cget -state] eq "released"} {
            buttonDraw $path
            return
        }
        buttonDrawPressed $path
    }

    public method buttonStateCallback {path value} {
        if {($value ne "pressed")  && ($value ne "released")} {
            return -code error "invalid argument: $value"
        }
        return 1
    }

    public method buttonTextCallback {path value} {
#puts stderr "buttonTextCallback!$path!$value!"
        set rgbadata [freetype $itcl_options(-font) \
                $itcl_options(-fontsize) $value $itcl_options(-textcolor) \
		myWidth myHeight offsetmap]
        set textobj [$path textobj]
        $path configure -textwidth $myWidth -textheight $myHeight
        $textobj setdata $rgbadata
	set myBd [$path cget -bd]
        set myWidth [expr {$myWidth + 2 + ($myBd * 2)}]
        set myHeight [expr {$myHeight + 2 + ($myBd * 2)}]
        requestSize $path $myWidth $myHeight
#puts stderr "buttonTextCallback END!$path!$value!"
        return 1
   }

    public method buttonTrace {path} {
#puts stderr "buttonTrace!$path!"
        buttonTextCallback $path [$path cget -text]
        buttonRedraw $path
#puts stderr "buttonTrace END!$path!"
    }
}
