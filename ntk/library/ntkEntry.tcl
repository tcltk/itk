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
# RCS: @(#) $Id: ntkEntry.tcl,v 1.1.2.12 2007/11/25 17:12:48 wiede Exp $
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
#puts stderr "entryButtonpress!$button![getFocus]!"
        foreach path [getFocus] {
            if {$path eq $wpath} {
                entryCursorSet [expr {$x - $xslide}]
                return
            }
        }
        focus $wpath
    }

    public method entryCursorIncrOffset {i} {
#puts stderr "entryCursorIncrOffset1!$i!$cursoroffset!"
        if {(($i < 0) && ($cursoroffset > 0)) || (($i > 0) && 
               (($cursoroffset < [string length $itcl_options(-text)])))} {
           incr cursoroffset $i
           entryDraw
        }
    }

    public method entryCursorSet {x} {
        set lasti 0
        set cursoroffset 0
        set cursormap [list]
        set map [$wpath offsetmap]
        foreach {myWidth myHeight} \
	        [::ntk::widgetImage::Image getsize $textImage] break

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
        rename $textImage {}
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
        foreach {objw objh} \
	        [::ntk::widgetImage::Image getsize $windowImage] break
        if {$cx > 0} {
            incr cx -1
        }
        set $xslide 1
        if {$cx >= $itcl_options(-width)} {
            $wpath xslide [expr {$itcl_options(-width) - $cx}]
        } 
        ::ntk::widgetImage::Image fill $windowImage $itcl_options(-bg)
        ::ntk::widgetImage::Image blendwidget $windowImage $xslide 0 $textImage
	set myCursorColor $itcl_options(-cursorcolor)
        ::ntk::widgetImage::Image line $windowImage $cx 0 $cx $objh $myCursorColor
        set cx [expr {$cx + 1}]
        ::ntk::widgetImage::Image line $windowImage $cx 0 $cx $objh $myCursorColor
        render $wpath
    }

    public method entryKeypress {value keysym keycode} {
#puts stderr "entryKeypress!$value!$keysym!$keycode!"
        switch -- $keysym {
        normal {
            set myText $itcl_options(-text)
	    if {$cursoroffset == 0} {
	        set startStr ""
		set endStr $myText
	    } else {
	        set startStr [string range $myText 0 [expr {$cursoroffset-1}]]
		if {$cursoroffset == [string length $myText]} {
		    set endStr ""
		} else {
	            set endStr [string range $myText $cursoroffset end]
	        }
	    }
	    configure -text "$startStr$value$endStr"
            entryCursorIncrOffset 1
          } 
        backspace {
            set myText $itcl_options(-text)
	    switch $cursoroffset {
	    0 {
	        set startStr ""
		set endStr $myText
	      }
	    1 {
	        set startStr ""
		set endStr [string range $myText 1 end]
	      }
	    default {
		if {$cursoroffset == [string length $myText]} {
	            set startStr [string range $myText 0 [expr {$cursoroffset-1}]]
		    set endStr ""
		} else {
	            set startStr [string range $myText 0 [expr {$cursoroffset-2}]]
	            set endStr [string range $myText $cursoroffset end]
	        }
	      }
	    }
	    configure -text "$startStr$endStr"
            entryCursorIncrOffset -1
          }
        left {
            entryCursorIncrOffset -1
          }
        right {
            entryCursorIncrOffset 1
          }
        delete {
            set myText $itcl_options(-text)
	    switch $cursoroffset {
	    0 {
	        set startStr ""
		set endStr $myText
	      }
	    1 {
	        set startStr ""
		set endStr [string range $myText 1 end]
	      }
	    default {
		if {$cursoroffset == [string length $myText]} {
	            set startStr [string range $myText 0 [expr {$cursoroffset-1}]]
		    set endStr ""
		} else {
	            set startStr [string range $myText 0 [expr {$cursoroffset-2}]]
	            set endStr [string range $myText $cursoroffset end]
	        }
	      }
	    }
	    configure -text "$startStr$endStr"
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
	::ntk::widgetImage::Image createtext $textImage $itcl_options(-font) \
                $itcl_options(-fontsize) $value $itcl_options(-textcolor) \
		myWidth myHeight myOffsetmap
        offsetmap $myOffsetmap
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

