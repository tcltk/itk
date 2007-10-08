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
# RCS: @(#) $Id: ntkButton.tcl,v 1.1.2.2 2007/10/08 19:57:12 wiede Exp $
#--------------------------------------------------------------------------

itcl::eclass ::ntk::classes::button {
    inherit ::ntk::classes::theme 

    private variable buttonDraw [list]
    private variable textobj [list]
    private variable destroy [list]

    public option -font -default {} -configuremethod buttonConfig
    public option -fontsize -default {} -configuremethod buttonConfig
    public option -text -default {} -configuremethod buttonConfig
    public option -textcolor -default {} -configuremethod textCallback
    public option -textwidth -default 0 -configuremethod buttonConfig
    public option -textheight -default 0 -configuremethod buttonConfig
    public option -bg -default {} -validatemethod verifyColor -configuremethod buttonConfig
    public option -bd -default 1 -validatemethod verifyBorder -configuremethod buttonConfig
    public option -command -default {} -configuremethod buttonConfig
    public option -buttonpress -default {} -configuremethod buttonConfig
    public option -buttonrelease -default {} -configuremethod buttonConfig
    public option -state -default released -configuremethod stateCallback

    private method buttonConfig {option value} {
        set itcl_options($option) $value
        if {$buttonDraw ne ""} {
            $buttonDraw [path]
        }
    }

    public method textobj {{value {}}} {
	if {$value eq ""} {
            return $textobj
	} else {
	    set textobj $value
	}
    }

    public method destroy {{value {}}} {
	if {$value eq ""} {
            return $destroy
	} else {
	    set destroy $value
	}
    }

    constructor {args} {
        eval ::ntk::classes::window::constructor -width 1 -height 1
    } {
	set itcl_options(-width) 20
	set itcl_options(-height) 20
	set itcl_options(-font) $defaultFont
	set itcl_options(-fontsize) $defaultFontSize
	set itcl_options(-textcolor) $defaultTextColor
	set itcl_options(-bg) [defaultBackgroundColor]
	set itcl_options(-bd) 1
	set itcl_options(-buttonpress) buttonPress
	set itcl_options(-buttonrelease) buttonRelease
	set textobj [megaimage-blank 20 20]
	set destroy buttonDestroy
	set path [path]
	eval configure $args
	appendRedrawHandler [list $path buttonRedraw $path]

	set buttonDraw buttonDraw
	buttonDraw $path
        return $path
    }

    public method buttonDraw {path} {
puts stderr "buttonDraw!$path!"
        set myObj [obj]
	set myColor [$path cget -bg]
	if {[llength $myColor] == 1} {
	    $myObj setall $colors($myColor)
	} else {
	    $myObj setall $myColor
	}
        themeButtonDrawBorder $path
        buttonDrawText $path
        $path render $path
    }

    public method buttonPress {path button x y globalx globaly} {
        if {$button == 1} {
            $path configure -state pressed
        }
    }

    public method buttonRelease {path button x y globalx globaly} {
        $path configure -state released
        if {($x < 0) || ($y < 0) || ($x >= [$path cget -width]) ||
	        ($y >= [$path cget -height])} {
            return
        }
        if {($button == 1) && ([$path cget -command] ne "")} {
            uplevel #0 [$path cget -command]
        }
    }

    public method buttonDestroy {path} {
        rename [$path textobj] {}
    }

    public method buttonDrawPressed {path} {
	set myObj [$path obj]
	set myColor [$path cget -bg]
	if {[llength $myColor] == 1} {
	    $myObj setall $colors($myColor)
	} else {
	    $myObj setall $myColor
	}
        themeButtonDrawPressedBorder $path
        buttonDrawText $path
        $path render $path
    }

    public method buttonDrawText {path} {
        set myObj [$path obj]
        lassign [$myObj getsize] winwidth winheight
        lassign [[$path textobj] getsize] textwidth textheight
        set x [expr {($winwidth / 2) - ($textwidth / 2)}]
        set y [expr {($winheight / 2) - ($textheight / 2)}]
        $myObj blendobj $x $y [$path textobj]
    }

    public method buttonRedraw {path} {
        if {[$path -state] eq "released"} {
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
        set rgbadata [freetype [$path cget -font] \
                [$path cget -fontsize] $value [$path cget -textcolor]
		width height offsetmap]
        set textobj [$path textobj]
        $path configure -textwidth $width -textheight $height
        $textobj setdata $rgbadata
        set width [expr {$width + 2 + ([$path cget -bd] * 2)}]
        set height [expr {$height + 2 + ([$path cget -bd] * 2)}]
        requestSize $path $width $height
        return 1
   }

    public method buttonTrace {path} {
        buttonTextCallback $path [$path cget -text]
        buttonRedraw $path
    }
}
