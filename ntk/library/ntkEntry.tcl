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
# RCS: @(#) $Id: ntkEntry.tcl,v 1.1.2.18 2007/12/01 18:59:10 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::entry {
    inherit ::ntk::classes::theme 

    private variable constructing 1
    public methodvariable cursoroffset -default 0
    public methodvariable slidex -default 0
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
	set itcl_options(-bd) 1
	set itcl_options(-bg) [list 255 255 255 255]
	set itcl_options(-keypress) [list $wpath entryKeypress]
	set itcl_options(-buttonpress) [list $wpath entryButtonpress]
	set themeConfig entryConfig
	set destroy entryDestroy
	if {[llength $args] > 0} {
	    configure {*}$args
	}
	appendRedrawHandler [list $wpath entryDraw]
	appendDestroyHandler [list $wpath entryDestroy]
	set constructing 0
	entryTrace
        return $wpath
    }

    public method entryButtonpress {button x y globalx globaly} {
#puts stderr "entryButtonpress!$button![getFocus]!"
        foreach path [getFocus] {
            if {$path eq $wpath} {
                entryCursorSet [expr {$x - $slidex}]
                return
            }
        }
        focus $wpath
    }

    public method entryCursorIncrOffset {i} {
if {[catch {
	set co $cursoroffset
	incr co $i
        if {(($co >= 0) && \
               ($co <= [string length $itcl_options(-text)]))} {
           set cursoroffset $co
           entryDraw
        }
} err ]} {
puts stderr "ERR!$err!"
}
    }

    public method entryCursorSet {x} {
        set lasti 0
        set co 0
        set cursormap [list]
        set map $offsetmap
	if {[llength $map] == 0} {
	    entryDraw
	    return
	}
	foreach hi [lrange $map 1 end] {
	    set halfwidth [expr {($high - $low) / 2}]
	    set midx [expr {$low +$halfwidth}]
	    if {$x  <$midx} {
	        break
	    } else {
	        if {$x < $high} {
	            incr co
		    break
		}
	    }
	    incr co
	    set low $high
        }	
	if {$co > [llengthz $map]} {
	    set co [llength $map]
	}
	set cursoroffset $co
        entryDraw
    }

    public method entryDestroy {} {
        rename $textImage {}
    }

    public method entryDraw {} {
	if {$constructing} {
	    return
	}
	::ntk::widgetImage::Image fill $windowImage $itcl_options(-bg)
        set myOffsetmap $offsetmap
	set co $cursoroffset
	set myCursorColor $itcl_options(-cursorcolor)

        if {[llength $myOffsetmap] == 0} {
	    set cursorx [expr {$itcl_options(-bd) + 1}]
        } else {
	    if {$co >= [llength $myOffsetmap]} {
	        set co [expr {[llength $myOffsetmap] - 1}]
	    }
            set cursorx [expr {([lindex $myOffsetmap $co] - $slidex) + \
	            $itcl_options(-bd)}]
            foreach {textWidth textHeight} \
	            [::ntk::widgetImage::Image getsize $textImage] break
	    set y [expr {($itcl_options(-height) - $textHeight) / 2}]
	    if {$y < $itcl_options(-bd)} {
	        set y $itcl_options(-bd)
	    }
	    ::ntk::widgetImage::Image blendwidget $windowImage \
	            $slidex $y $textImage
	}
	# Draw the cursor
	::ntk::widgetImage::Image line $windowImage $cursorx \
	        $itcl_options(-bd) $cursorx $itcl_options(-height) \
	        $myCursorColor
        incr cursorx
        ::ntk::widgetImage::Image line $windowImage $cursorx \
	        $itcl_options(-bd) $cursorx $itcl_options(-height) \
	        $myCursorColor
        render $wpath
    }

    public method entryKeypress {value keysym keycode} {
	set xx ""
        binary scan $value H2 xx
puts stderr "entryKeypress!$value!$xx!$keysym!$keycode!"
	if {$keysym eq ""} {
	    if {$value eq ""} {
	        return
	    }
	}
	if {[uplevel #0 ntk isControlKey]} {
	    return
	}
        switch -- $keysym {
	Alt -
	Altgr -
	Control {
	    return
	  }
	Tab {
	    # ???
	    return
	  }
	notsupported {
	    return
	  }
        Delete -
        Backspace {
	    set co $cursoroffset
	    if {$keysym eq "backspace"} {
	       if {$co > 0} {
	           incr co -1
	       }
	    }
            set myText $itcl_options(-text)
	    set myText [string range $myText 0 \
	            [expr {$co - 1}]][string range $myText [expr {$co + 1}] end]
	    configure -text $myText
	    if {$keysym eq "backspace"} {
                entryCursorIncrOffset -1
	    }
          }
        Left {
            entryCursorIncrOffset -1
          }
        Right {
            entryCursorIncrOffset 1
          }
        Return {
	    return
	  }
        default {
            set myText $itcl_options(-text)
	    set co $cursoroffset
	    set myText [string range $myText 0 \
	            [expr {$co - 1}]]$value[string range $myText $co end]
	    configure -text $myText
            entryCursorIncrOffset 1
          } 
        }
        entryDraw
    }

    public method entryTextCallback {value} {
#puts stderr "entryTextCallback!$value!"
	if {$constructing} {
	    return
	}
	if {[string length $value] == 0} {
	    set offsetmap [list]
	    set slidex 0
	    set cursoroffset 0
	    ::ntk::widgetImage::Image setsize $textImage 1 1
	    return
	}
	::ntk::widgetImage::Image createtext $textImage $itcl_options(-font) \
                $itcl_options(-fontsize) $value $itcl_options(-textcolor) \
		myWidth myHeight myOffsetmap
        set offsetmap $myOffsetmap
	set bd2 [expr {$itcl_options(-bd) * 2}]
        requestSize [expr {$myWidth + 2 + $bd2}] \
	        [expr {$myHeight + 2 + $bd2}]
        return
    }

    public method entryTrace {} {
#puts stderr "entryTrace!"
        entryTextCallback $itcl_options(-text)
        entryDraw
    }
}

