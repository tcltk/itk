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
# RCS: @(#) $Id: ntkEntry.tcl,v 1.1.2.11 2007/11/23 21:02:57 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::entry {
    inherit ::ntk::classes::theme 

    private variable constructing 1
    public methodvariable cursoroffset -default 0
    public methodvariable xslide -default 0
    public methodvariable offsetmap -default [list]

    public option -cursorcolor -default [list 255 0 0 255] \
            -configuremethod entryConfig

    private method entryConfig {option value} {
#puts stderr "entryConfig!$option!$value!"
        set itcl_options($option) $value
	switch -- $option {
	-text {
	    entryTrace
	  }
	default {
            entryDraw
	  }
	}
    }

    constructor {args} {
	set itcl_options(-width) 160
	set reqwidth 160
	set itcl_options(-bg) [list 255 255 255 255]
	set itcl_options(-keypress) [list $wpath entryKeypress]
	set itcl_options(-buttonpress) [list $wpath entryButtonpress]
puts stderr "HH!$itcl_options(-height)!"
	set themeConfig entryConfig
	set destroy entryDestroy
	if {[llength $args] > 0} {
	    configure {*}$args
	}
	appendRedrawHandler [list $wpath entryDraw]
	set constructing 0
	entryTrace
        return $wpath
    }

    public method entryButtonpress {button x y globalx globaly} {
puts stderr "entryButtonpress"
        foreach path [getFocus] {
            if {$path eq $wpath} {
                entryCursorSet [expr {$x - $xslide}]
                return
            }
        }
        focus $wpath
    }

    public method entryCursorIncrOffset {i} {
puts stderr "entryCursorIncrOffset"
        set co [$wpath cursoroffset]
        if {(($i < 0) && ($co > 0)) || (($i > 0) && 
               (($co < [string length $itcl_options(-text)]))} {
           incr co $i
           $wpath cursoroffset $co
           entryDraw
        }
    }

    public method entryCursorSet {x} {
        set lasti 0
        set cursoroffset 0
        set cursormap [list]
        set map [$wpath offsetmap]
        lassign [$textobj getsize] myWidth myHeight

        #
        # Build a map of low and high ranges for each cursor position.
        #
        for {set i 0} {$i < [llength $map]} {incr i} {
            set cur [lindex $map $i]
            set next [lindex $map [expr {$i + 1}]]

            if {$next eq ""} {
                lappend cursormap $lasti $myWidth
                continue
            }
	    set myLasti [expr {$cur + (($next - $cur) / 2)}]
            lappend cursormap $lasti $myLasti
        }
        #
        # Find the cursor offset using the map.
        #
        set i 0
        foreach {x1 x2} $cursormap {
            if {$x >= $x1 && $x < $x2} {
                $wpath cursoroffset $i
                entryDraw
                return
            }
            incr i
        }
    }

    public method entryDestroy {} {
        rename $textobj {}
    }

    public method entryDraw {} {
	if {$constructing} {
	    return
	}
        set myOffsetmap $offsetmap
        set cx 0
        if {[llength $myOffsetmap]} {
            set cx [lindex $myOffsetmap $cursoroffset]
        }
        if {$cx eq ""} {
            set cx 0
        }
        lassign [$obj getsize] objw objh
        if {$cx > 0} {
            incr cx -1
        }
        set $xslide 1
        if {$cx >= $itcl_options(-width)} {
            $wpath xslide [expr {$itcl_options(-width) - $cx}]
        } 
        $obj fill $itcl_options(-bg)
        $obj blendwidget $xslide 0 $textobj
	set myCursorColor $itcl_options(-cursorcolor)
        $obj line $cx 0 $cx $objh $myCursorColor
        set cx [expr {$cx + 1}]
        $obj line $cx 0 $cx $objh $myCursorColor
        render $wpath
    }

    public method entryKeypress {value keysym keycode} {
puts stderr "entryKeypress!$value!$keysym!$keycode!"
        set myText $itcl_options(-text)
        switch -- $keysym {
        normal {
            append myText $value
            set $itcl_options(-text) $myText
            entryCursorIncrOffset 1
          } 
        backspace {
            set co $cursoroffset
            incr co -1
            set $itcl_options(-text) [string range $myText 0 \
	            [expr {$co - 1}]][string range $myText [expr {$co + 1}] \
		    end]
            entryCursorIncrOffset -1
          }
        left {
            entryCursorIncrOffset -1
          }
        right {
            entryCursorIncrOffset 1
          }
        delete {
            set co $cursoroffset
            set $itcl_options(-text) [string range $myText 0 \
	            [expr {$co - 1}]][string range $myText [expr {$co + 1}] \
		    end]
          }
        return {
	    return
	  }
        }
        entryDraw
    }

    public method entryTextCallback {value} {
#puts stderr "entryTextCallback!$value!"
	if {$constructing} {
	    return
	}
        if {$value eq ""} {
	    return
	}
puts stderr "FONT!$itcl_options(-font)!$itcl_options(-fontsize)!$itcl_options(-textcolor)!$value!"
        set rgbadata [freetype $itcl_options(-font) \
                $itcl_options(-fontsize) $value $itcl_options(-textcolor) \
		myWidth myHeight myOffsetmap]
        offsetmap $myOffsetmap
        $textobj setdata $rgbadata
        requestSize [expr {$myWidth + 2}] [expr {$myHeight + 2}]
        return 1
    }

    public method entryTrace {} {
#puts stderr "entryTrace!"
	if {$itcl_options(-text) ne ""} {
            entryTextCallback $itcl_options(-text)
	    entryDraw
        }
    }

}

