#---------------------------------------------------------------------------
# ntkWidget ntkText.tcl --
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
# RCS: @(#) $Id: ntkText.tcl,v 1.1.2.8 2007/12/01 22:53:27 wiede Exp $
#--------------------------------------------------------------------------

#--------------------------------------------------------------------------
# Internal layout of a line:
# [list [list width height] [list contextIdx1 text1] [list contextIdx1 text2]
#       [list contextIdx2 text3] ... [list contextIdxn textn]]
# a contextIdx is the index into methodvariable contexts
# a context consists of [list font fontsize textcolor]
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::text {
    inherit ::ntk::classes::theme 

    private variable constructing 1

    public methodvariable contexts -default [list]
    public methodvariable text -default [list]

    public option -cursorcolor -default [list 200 200 200 255] \
            -configuremethod textConfig
    public option -fg -default [list 125 125 0 255] \
            -configuremethod textConfig
    public option -theme -default [list] \
            -configuremethod textConfig
    public option -insert -default [list] \
            -configuremethod textConfig
    public option -themeclass -default [list] \
            -configuremethod textConfig

    private method textConfig {option value} {
#puts stderr "textConfig!$option!$value!"
        set itcl_options($option) $value
	switch -- $option {
	-insert {
	    textInsert $value
            textDraw
	  }
	default {
            textDraw
	  }
	}
    }

    constructor {args} {
	requestSize 200 300
	set itcl_options(-bg) [list 255 255 255 255]
	set contexts [list [list $defaultFont $defaultFontSize \
	        [list 0 0 0 255]]]
	set themeConfig textConfig
	set destroy entryDestroy
        if {[llength $args]} {
            configure {*}$args
        }
	appendRedrawHandler [list $wpath textDraw]
	set constructing 0
	set textArgs [themeGetText]
	if {[llength $textArgs] > 0} {
	    $wpath configure {*}$textArgs
	}   
	textDraw
        return $wpath
    }

    public method textDraw {} {
#puts stderr "textDraw!w!$itcl_options(-width)!h!$itcl_options(-height)!"
        themeDrawTextBackground
        set linemap [list]
        set myY 0
	set myContexts $contexts
        foreach line $text {
            set linegeom [lindex $line 0]
            lassign $linegeom linewidth lineheight
            set lineoffsetmap [list]
            set myX 0
            set linewidth 0
            set lineheight 0
	    lassign $line w h
            foreach seg [lrange $line 2 end] {
                set context [lindex $myContexts [lindex $seg 0]]
                lassign [lindex $context 0] font size color
                set txt [lindex $seg 1]
                if {[string length $txt] == 0} {
                    set txt " "
                }
                ::ntk::widgetImage::Image createtext $textImage \
		        $font $size $txt $color myWidth myHeight offsetmap
                if {$myHeight > $lineheight} {
		    set lineheight $myHeight
		}
                ::ntk::widgetImage::Image blendwidget $windowImage \
		        $myX $myY $textImage
                incr myX $myWidth
                lappend lineoffsetmap $offsetmap
                if {$myWidth > $linewidth} {
		    set linewidth $myWidth
		}
            }
            incr myY $lineheight
            lappend linemap $lineoffsetmap 
        }
    }

    public proc textInsert {arglist} {
        lassign $arglist pos newcontext insert
        lassign [split $pos .] myY myX
        incr myY -1 ; #compensate for the y starting at 1
        set myText $text
        set insertlist [split $insert \n] 
        set ylimit [expr {$myY + [llength $insertlist]}]
        while {$myY >= [llength $myText]} {
            lappend myText [list [list width height] [list 0 ""]]
        }
        set line [lindex $myText $myY]
        set newlinelist [textTrimEmpty \
	        [textInsertSegments $myX $line $newcontext $insertlist]]
        set myText [lreplace $myText $myY $myY]
        set myText [linsert $myText $myY {*}$newlinelist]
        set text $myText
	textDraw
        return 0
    }

    public proc textInsertSegments {myX line newcontext newtextlist} {
#puts stderr "textInsertSegments!myX!$myX!line!$line!newcontext!$newcontext!newtextlist!$newtextlist!"
        set ox 0
        set newtextlistoffset 0
        set result [list]
        set resultline [lindex $line 0]
        set found 0

        foreach seg [lrange $line 1 end] {
            lassign $seg context txt
            set textchars ""
            foreach c [split $txt ""] {
                if {$ox == $myX} {
                    set found 1
                    textInsertSegments2 result resultline $newcontext \
		            $newtextlist $context $textchars
                    set textchars ""
                } else {
                    append textchars $c
                }
                incr ox
            }
            lappend resultline [list $context $textchars]
        }
        if {!$found} {
            textInsertSegments2 result resultline $newcontext $newtextlist \
	            $context ""
        }
        return $result
    }

    public proc textInsertSegments2 {resultvar resultlinevar newcontext newtextlist context textchars} {
        upvar $resultvar result
        upvar $resultlinevar resultline
 
        # See if we can continue this line with the same context.
        if {$context == $newcontext} {
            append textchars [lindex $newtextlist 0]
            lappend resultline [list $context $textchars]
            lappend result $resultline
        } else {
            if {[string length $textchars]} {
                lappend resultline [list $context $textchars]
            }
            lappend resultline [list $newcontext [lindex $newtextlist 0]]
            lappend result $resultline
        }
        foreach newline [lrange $newtextlist 1 end] {
            set resultline [list width height]
            lappend resultline [list $newcontext $newline]
            lappend result $resultline
        }
    }

    public method textTrimEmpty {textlist} {
        set newtextlist [list]
        foreach line $textlist {
            set newline [lindex $line 0]
            foreach seg [lrange $line 1 end] {
                lassign $seg context text
                if {($context == 0) && ![string length $text]} {
		    continue
	        }
                lappend newline $seg
            }
            lappend newtextlist $newline
        }
        return $newtextlist
    }
}

