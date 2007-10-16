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
# RCS: @(#) $Id: ntkText.tcl,v 1.1.2.3 2007/10/16 16:24:41 wiede Exp $
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
	-insert {
	    textInsert $wpath $value
            textDraw $wpath
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
	set contexts [list [list $defaultFont $defaultFontSize [list 0 0 0 255]]]
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
	set textArgs [themeGetText]
	if {[llength $textArgs] > 0} {
	    $wpath configure {*}$textArgs
	}   
	textDraw $wpath
        return $wpath
    }

    public method textDraw {path} {
#puts stderr "textDraw!$path!"
        themeDrawTextBackground $path
        set linemap [list]
        set myTextobj [megaimage-blank 100 100]
        set myY 0
	set myContexts [$path contexts]
        foreach line [$path text] {
puts stderr "LINE1!$line!"
            set linegeom [lindex $line 0]
            lassign $linegeom linewidth lineheight
puts stderr "linegeom!$linegeom!"
            set lineoffsetmap [list]
            set myX 0
puts stderr "LINE!$line!$linewidth!$lineheight!"
#set linewidth 100
#set lineheight 10
            foreach seg [lrange $line 1 end] {
puts stderr "seg!$seg!$myContexts!"
                set context [lindex $myContexts [lindex $seg 0]]
puts stderr "context!$context!"
                lassign $context font size color
                set textdata [freetype $font $size [lindex $seg 1] $color myWidth myHeight offsetmap]
                $myTextobj setdata $textdata
puts stderr "BLEND!$myX!$myY![$path obj]!$myTextobj!"
                [$path obj] blendobj $myX $myY $myTextobj
                incr myX $myWidth
                lappend lineoffsetmap $offsetmap
            }
            incr myY $lineheight
            lappend linemap $lineoffsetmap 
        }
    }

    public proc textInsert {path arglist} {
        lassign $arglist pos newcontext insert
        lassign [split $pos .] myY myX
        incr myY -1 ; #compensate for the y starting at 1
        set myText [$path text]
puts stderr "INSERTLIST!$insert!"
        set insertlist [split $insert \n] 
        set ylimit [expr {$myY + [llength $insertlist]}]
puts stderr "myX!$myX!$myY![llength $myText]!"
        while {$myY >= [llength $myText]} {
            lappend myText [list [list width height] [list 0 ""]]
#            lappend myText [list [list 0 0] [list 0 ""]]
        }
        set line [lindex $myText $myY]
puts stderr "myText!$myText!$myY!$line!"
        set newlinelist [textTrimEmpty [textInsertSegments $myX $line $newcontext $insertlist]]
puts stderr "newlinelist!$newlinelist!"
puts stderr "TEXT1!$myText!$myY!"
        set myText [lreplace $myText $myY $myY]
        set myText [linsert $myText $myY {*}$newlinelist]
puts stderr "TEXT2!$myText!"
        $path text $myText
        return 0
    }

    public proc textInsertSegments {myX line newcontext newtextlist} {
puts stderr "textInsertSegments!myX!$myX!line!$line!newcontext!$newcontext!newtextlist!$newtextlist!"
        set ox 0
        set newtextlistoffset 0
        set result [list]
        set resultline [lindex $line 0]
puts stderr "RESL!$resultline!"
        set found 0

        foreach seg [lrange $line 1 end] {
puts stderr "textInsertSegments!seg!$seg!"
            lassign $seg context txt
puts stderr "t2!$context!$txt!"
            set textchars ""
            foreach c [split $txt ""] {
puts stderr "ox!$ox!$myX!$c!$textchars!"
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
puts stderr "textInsertSegments!result!$result!"
        return $result
    }

    public method textInsertSegments2 {resultvar resultlinevar newcontext newtextlist context textchars} {
        upvar $resultvar result
        upvar $resultlinevar resultline
 
        # See if we can continue this line with the same context.
puts stderr "textInsertSegments2!$context!$newcontext!$resultvar!$resultlinevar!$textchars!"
        if {$context == $newcontext} {
puts stderr "newtextlist!$newtextlist!"
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
puts stderr "resultline!$resultline!$result!"
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

