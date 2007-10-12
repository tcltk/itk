#---------------------------------------------------------------------------
# ntkWidget ntkEntry.tcl --
#
# This file contains a ntkWidget entry command implementation
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
# RCS: @(#) $Id: ntkEntry.tcl,v 1.1.2.3 2007/10/12 21:09:56 wiede Exp $
#--------------------------------------------------------------------------

itcl::eclass ::ntk::classes::entry {
    inherit ::ntk::classes::theme 

    private variable constructing 1
    private variable textobj [list]
    private variable cursoroffset 0
    private variable xslide 0
    private variable offsetmap [list]

    public option -font -default {} -configuremethod entryConfig
    public option -fontsize -default {} -configuremethod entryConfig
    public option -text -default {} -configuremethod entryConfig
    public option -textcolor -default {} -validatemethod verifyColor \
            -configuremethod entryConfig
    public option -cursorcolor -default [list 255 0 0 255] \
            -configuremethod entryConfig
    public option -bg -default {} -validatemethod verifyColor \
            -configuremethod entryConfig
    public option -bd -default 1 -validatemethod verifyBorder \
            -configuremethod entryConfig
    public option -keypress -default {} -configuremethod entryConfig
    public option -buttonpress -default {} -configuremethod entryConfig

    private method entryConfig {option value} {
puts stderr "entryConfig!$option!$value!"
        set itcl_options($option) $value
	switch -- $option {
	-text {
	    entryTrace $wpath
	  }
	default {
            entryDraw $wpath
	  }
	}
    }

    public method textobj {{value {}}} {
	if {$value eq ""} {
            return $textobj
	} else {
	    set textobj $value
	}
    }

    public method cursoroffset {{value {}}} {
	if {$value eq ""} {
            return $cursoroffset
	} else {
	    set cursoroffset $value
	}
    }

    public method xslide {{value {}}} {
	if {$value eq ""} {
            return $xslide
	} else {
	    set xslide $value
	}
    }

    public method offsetmap {{value {}}} {
	if {$value eq ""} {
            return $offsetmap
	} else {
	    set offsetmap $value
	}
    }

    constructor {args} {
#        freetype $defaultFont $defaultFontSize "_^" [list 0 0 0 255] myWidth myHeight
#        eval ::ntk::classes::window::constructor -width 160 -height $myHeight
        eval ::ntk::classes::window::constructor -width 60 -height 20 
    } {
puts stderr "CONST!$constructing!"
	set itcl_options(-font) $defaultFont
	set itcl_options(-fontsize) $defaultFontSize
	set itcl_options(-textcolor) $defaultTextColor
	set itcl_options(-bg) [list 255 255 255 255]
	set itcl_options(-keypress) entryKeypress
	set itcl_options(-buttonpress) entryButtonpress
	set textobj [megaimage-blank 1 1]
	set destroy entryDestroy
puts stderr "OPT!BG!$itcl_options(-bg)!$itcl_options(-width)!"
	eval configure $args
	appendRedrawHandler [list $wpath entryDraw $wpath]
	set constructing 0
	entryDraw $wpath
        return $wpath
    }

    public method entryButtonpress {path button x y globalx globaly} {
        foreach w [getFocus] {
            if {$w eq $path} {
                entryCursorSet $path [expr {$x - [$path xslide]}]
                return
            }
        }
        focus $path
    }

    public method entryCursorIncrOffset {path i} {
        set co [$path cursoroffset]
        if {(($i < 0) && ($co > 0)) || (($i > 0) && 
               (($co < [string length [$path cget -text]]))} {
           incr co $i
           $path cursoroffset $co
           entryDraw $path
        }
    }

    public method entryCursorSet {path x} {
        set lasti 0
        set cursoroffset 0
        set cursormap [list]
        set map [$path offsetmap]
        lassign [[$path textobj] getsize] width height

        #
        # Build a map of low and high ranges for each cursor position.
        #
        for {set i 0} {$i < [llength $map]} {incr i} {
            set cur [lindex $map $i]
            set next [lindex $map [expr {$i + 1}]]

            if {$next eq ""} {
                lappend cursormap $lasti $width
                continue
            }
            lappend cursormap $lasti [set lasti [expr {$cur + (($next - $cur) / 2)}]]
        }

        #
        # Find the cursor offset using the map.
        #
        set i 0
        foreach {x1 x2} $cursormap {
            if {$x >= $x1 && $x < $x2} {
                $path cursoroffset $i
                entryDraw $path
                return
            }
            incr i
        }
    }

    public method entryDestroy {path} {
        rename [$path textobj] {}
    }

    public method entryDraw {path} {
	if {$constructing} {
	    return
	}
        set myOffsetmap [$path offsetmap]
        set cx 0
        if {[llength $myOffsetmap]} {
            set cx [lindex $myOffsetmap [$path cursoroffset]]
        }
        if {$cx eq ""} {
            set cx 0
        }
        lassign [$obj getsize] objw objh
        if {$cx > 0} {
            incr cx -1
        }
        $path xslide 1
	set myWidth [$path cget -width]
        if {$cx >= $myWidth} {
            $path xslide [expr {$myWidth - $cx}]
        } 
puts stderr "BG![$path cget -bg]!"
        $obj setall [$path cget -bg]
        $obj blendobj [$path xslide] 0 [$path textobj]
	set myCursorColor [$path cget -cursorcolor]
        $obj line $cx 0 $cx $objh $myCursorColor
        set cx [expr {$cx + 1}]
        $obj line $cx 0 $cx $objh $myCursorColor
        render $path
    }

    public method entryKeypress {path value keysym keycode} {
        set myText [$path cget -text]
        switch -- $keysym {
        normal {
            append myText $value
            $path configure -text $myText
            entryCursorIncrOffset $path 1
          } 
        backspace {
            set co [$path cursoroffset]
            incr co -1
            $path configure -text [string range $myText 0 [expr {$co - 1}]][string range $myText [expr {$co + 1}] end]
            entryCursorIncrOffset $path -1
          }
        left {
            entryCursorIncrOffset $path -1
          }
        right {
            entryCursorIncrOffset $path 1
          }
        delete {
            set co [$path cursoroffset]
            $path configure -text [string range $myText 0 [expr {$co - 1}]][string range $myText [expr {$co + 1}] end]
          }
        return {
	    return
	  }
        }
        entryDraw $path
    }

    public method entryTextCallback {path value} {
        set rgbadata [freetype [$path cget -font] \
                [$path cget -fontsize] $value [$path cget -textcolor] \
		width height offsetmap]
        $path offsetmap $offsetmap
        set textobj [$path textobj]
        $textobj setdata $rgbadata
        requestSize $path [expr {$width + 2}] [expr {$height + 2}]
        return 1
    }

    public method entryTrace {path} {
puts stderr "entryTrace!$path!$constructing!"
        if {$constructing} {
	    return
	}
        entryTextCallback $path [$path cget -text]
	entryDraw $path
    }

}

