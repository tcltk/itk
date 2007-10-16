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
# RCS: @(#) $Id: ntkText.tcl,v 1.1.2.2 2007/10/16 14:18:47 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::text {
    inherit ::ntk::classes::theme 

    private variable constructing 1

    public methodvariable contexts -default [list  \
            [list Vera.ttf 12 [list 0 0 0 255]]]
    public methodvariable text -default [list]

    public option -fg -default [list 125 125 0 255] \
            -configuremethod textConfig
    public option -theme -default [list] \
            -configuremethod textConfig
    public option -themeclass -default [list] \
            -configuremethod textConfig
    public option -cursorcolor -default [list 200 200 200 255] \
            -configuremethod textConfig
    public option -insert -default [list] \
            -configuremethod textConfig

    private method textConfig {option value} {
#puts stderr "textConfig!$option!$value!"
        set itcl_options($option) $value
	switch -- $option {
	-text {
	    textInsert $wpath $value
	  }
	default {
            textDraw $wpath
	  }
	}
    }

    constructor {args} {
	set itcl_options(-width) 200
	set itcl_options(-height) 300
	set itcl_options(-bg) [list 255 255 255 255]
	set themeConfig textConfig
	set destroy entryDestroy
        if {[llength $args]} {
            if {[catch {configure {*}$args} err]} {
                destroyWindow $wpath
                return -code error $err
            }
        }
	appendRedrawHandler [list $wpath textDraw $wpath]
	set constructing 0
parray itcl_options
puts stderr "wpath!$wpath!"
	set textArgs [themeGetText]
puts stderr "textArgs!$textArgs!"
	if {[llength $textArgs] > 0} {
	    $wpath configure {*}$textArgs
	}   
	textDraw $wpath
        return $wpath
    }

    public method textDraw {path} {
puts stderr "textDraw!$path!"
        themeDrawTextBackground $path
        set linemap [list]
        set textobj [megaimage-blank 1 1]
        set y 0
        foreach line [$path text] {
            set linegeom [lindex $line 0]
            lassign $linegeom linewidth lineheight
            set lineoffsetmap [list]
            set x 0
            foreach seg [lrange $line 1 end] {
                set context [lindex [$path contexts] [lindex $seg 0]]
                lassign $context font size color
                set textdata [freetype $font $size $color myWidth myHeight offsetmap]
                 $textobj setdata $textdata
                 [$path obj] blendobj $x $y $textobj
                 incr x $myWidth
                 lappend lineoffsetmap $offsetmap
            }
            incr y $lineheight
            lappend linemap $lineoffsetmap 
        }
    }

    public proc textInsert {path arglist} {
        lassign $arglist pos newcontext insert
        lassign [split $pos .] myY myX
        incr myY -1 ; #compensate for the y starting at 1
        set text [$path text]
        set insertlist [split $insert \n] 
        set ylimit [expr {$myY + [llength $insertlist]}]
        while {$myY >= [llength $text]} {
            lappend text [list [list width height] [list 0 ""]]
        }
        set line [lindex $text $myY]
        set newlinelist [textTrimEmpty [textInsertSegments $myX $line $newcontext $insertlist]]
        set text [lreplace $text $myY $myY]
        set text [linsert $text $myY {*}$newlinelist]
        $path text $text
        return 0
    }

    public proc textInsertSegments {x line newcontext newtextlist} {
        set ox 0
        set newtextlistoffset 0
        set result [list]
        set resultline [lindex $line 0]
        set found 0

        foreach seg [lrange $line 1 end] {
            lassign $seg context txt
            set textchars ""
            foreach c [split $txt ""] {
                if {$ox == $x} {
                    set found 1
                    textInsertSegments-2 result resultline $newcontext \
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
            textInsertSegments-2 result resultline $newcontext $newtextlist \
	            $context ""
        }
        return $result
    }

    public method textInsertegments-2 {resultvar resultlinevar newcontext newtextlist context textchars} {
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

