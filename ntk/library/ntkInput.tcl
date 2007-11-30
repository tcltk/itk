#---------------------------------------------------------------------------
# ntkWidget ntkInput.tcl --
#
# This file contains a ntkWidget input command implementation
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
# RCS: @(#) $Id: ntkInput.tcl,v 1.1.2.13 2007/11/30 19:14:44 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::input {
    inherit ::ntk::classes::helpers

    private common input

    set input(activewindows) [list]

    public proc inputRotationSize {theta w h width_var height_var} {
        upvar $width_var width
        upvar $height_var height

        set width [expr {round (abs ($w * cos ($theta)) + \
	        abs ($h * sin ($theta)) + 2)}]
        set height [expr {round (abs ($h * cos ($theta)) + \
	        abs ($w * sin ($theta)) + 2)}]
    }

    public proc inputConstructPolygon {path xoffset yoffset} {
        set x1 $xoffset 
        set y1 $yoffset
        set x2 [expr {$x1 + [$path cget -width]}]
        set y2 [expr {$y1 + [$path cget -height]}]
        list $x1 $y1  $x2 $y1  $x2 $y2  $x1 $y2
    }

    public proc inputDestroy {path} {
        set i [lsearch -exact $input(activewindows) $path]
        if {$i < 0} {
	    return
        }
        set input(activewindows) [lreplace $input(activewindows) $i $i]
    }

    public proc inputKeyPress {win key keysym keycode} {
#puts stderr "inputKeyPress!$win!$key!$keysym!$keycode!$focusList!"
        foreach path $focusList {
            set callback [$path cget -keypress]
            if {$callback ne ""} {
                uplevel #0 [linsert $callback end $key $keysym $keycode]
            }
        }
    }

    public proc inputKeyRelease {win key keysym keycode} {
#puts stderr "inputKeyRelease!$win!$key!$keysym!$keycode!focus!$focusList!"
        foreach path $focusList {
            set callback [$path cget -keyrelease]
            if {$callback ne ""} {
                uplevel #0 [linsert $callback end $key $keysym $keycode]
            }
        }
    }

    public proc inputMotion {win x y} {
        foreach path $input(activewindows) {
            lassign [inputTranslateXyFromRoot $path $x $y] px py
            set callback [$path cget -motion]
            if {$callback ne ""} {
                uplevel #0 $callback $px $py $x $y
            }
        }
        inputMotionRecurse . $x $y $x $y
    }

    public proc inputMotionRecurse {path x y globalx globaly} {
        set children [$path children]
        if {[llength $children] == 0} {
            #XXX handle the root/toplevel window when there are no children?
            return 0
        }
        set ci [expr {[llength $children] - 1}]
	set c [lindex $children $ci]
	while {$ci >= 0} {
            set x1 [$c cget -x]
            set y1 [$c cget -y]
	    set myWidth [$c cget -width]
	    set myHeight [$c cget -height]
            set x2 [expr {$x1 + $myWidth}]
            set y2 [expr {$y1 + $myHeight}] 
            set px $x
	    set py $y
	    set myRotate [$c cget -rotate]
            if {$myRotate} {
                inputRotationSize [expr {3.14159 * $myRotate / 180}] \
                    $myWidth $myHeight newwidth newheight
                set xmod [expr {$x1 + $newwidth / 2}]
                set ymod [expr {$y1 + $newheight / 2}]
                set px [expr {$px - $xmod}]
                set py [expr {$py - $ymod}]
                inputRotatePoint $px $py $myRotate pxx pyy
                set px [expr {$pxx + $x1 + ($myWidth / 2)}]
                set py [expr {$pyy + $y1 + ($myHeight / 2)}]
            }
            if {$px >= $x1 && $px < $x2 && $py >= $y1 && $py < $y2} {
                set localx [expr {$px - $x1}]
                set localy [expr {$py - $y1}]  
                if {[catch {
		        lassign [[$c obj] pixel $localx $localy] _ _ _ a
		    } err]} {
                    #DEBUG
                    puts stderr "invalid offset in $c!$err!$localx!$localy!"
                    return 0
                }
                if {$a > 0} {
                    if {[inputMotionRecurse $c $localx $localy $globalx $globaly]} {
                        return 1
                    } else {
                        set callback [$c cget -motion]
                        if {$callback ne ""} {
                            uplevel #0 $callback $localx $localy $globalx $globaly
                        }
                        return 1
                    }
                }   
            }
	    incr ci -1
	    set c [lindex $children $ci]
        } 
        return 0
    }

    public proc inputMousePress {basewin button x y} {
#puts stderr "inputMousePress!$basewin!$button!$x!$y!"
        inputMousePressRecurse $basewin $button $x $y $x $y
    }

    public proc inputMousePressDispatch {path button x y globalx globaly} {
        set callback [$path cget -buttonpress]
#puts stderr "MOUSE PRESS DISPATCH $path!$button!$callback!"
        if {$callback ne ""} {
            lappend input(activewindows) $path
            uplevel #0 $callback $button $x $y $globalx $globaly
        }
    }

    public proc inputMousePressRecurse {basewin button x y globalx globaly} {
        set children [$basewin children]
        if {[llength $children] == 0} {
            return 0
        }
        set ci [expr {[llength $children] - 1}]
        set c [lindex $children $ci]
        while {$ci >= 0} {
            set x1 [$c cget -xoffset]
            set y1 [$c cget -yoffset]
	    set myWidth [$c cget -width]
	    set myHeight [$c cget -height]
            set x2 [expr {$x1 + $myWidth}]
            set y2 [expr {$y1 + $myHeight}] 
            set px $x
	    set py $y
	    set myRotate [$c cget -rotate]
            if {$myRotate} {
                inputRotationSize [expr {3.14159 * $myRotate / 180}] \
                        $myWidth $myHeight newwidth newheight
                set xmod [expr {$x1 + $newwidth / 2}]
                set ymod [expr {$y1 + $newheight / 2}]
                set px [expr {$px - $xmod}]
                set py [expr {$py - $ymod}]
                inputRotatePoint $px $py $myRotate pxx pyy
                set px [expr {$pxx + $x1 + ($myWidth / 2)}]
                set py [expr {$pyy + $y1 + ($myHeight / 2)}]
            }
            if {$px >= $x1 && $px < $x2 && $py >= $y1 && $py < $y2} {
                set localx [expr {$px - $x1}]
                set localy [expr {$py - $y1}]  
                if {[catch {
		        lassign [::ntk::widgetImage::Image pixel [$c windowImage] $localx $localy] _ _ _ a
		    } err]} {
                    #DEBUG
                    puts stderr "invalid offset in $c ERR!$err"
                    return 0
                }
                if {$a > 0} {
                    if {[inputMousePressRecurse $c $button $localx $localy \
                            $globalx $globaly]} {
                        return 1
                    } else {
                        inputMousePressDispatch $c $button $localx $localy \
                            $globalx $globaly
                        return 1
                    }
                }
            }
            incr ci -1
	    set c [lindex $children $ci]
        } 
        return 0
    }

    public proc inputMouseRelease {win button x y} {
        foreach path $input(activewindows) {
            lassign [inputTranslateXyFromRoot $path $x $y] px py
#puts stderr "RELEASE $path $px $py"
            set callback [$path cget -buttonrelease]
            if {$callback ne ""} {
                uplevel #0 $callback $button $px $py $x $y
            }
        }
        set input(activewindows) [list]
    }

    public proc inputRotatePoint {x y deg rotpx_var rotpy_var} {
        upvar $rotpx_var rotpx
        upvar $rotpy_var rotpy

        set theta [expr {3.14159 * ($deg) / 180}]
        set c [expr {cos($theta)}]
        set s [expr {sin($theta)}]
        set rotpx [expr {int(($x * $c) - ($y * $s))}]
        set rotpy [expr {int(($x * $s) + ($y * $c))}]
    }

    public proc inputRotatePolygon {poly width height deg} {
        set theta [expr {3.14159 * (-$deg) / 180}]
        set c [expr {cos($theta)}]
        set s [expr {sin($theta)}]
        set x1 [lindex $poly 0]
        set y1 [lindex $poly 1]
        inputRotationSize $theta $width $height newwidth newheight
        #
        # Start in the upper left quadrant, and proceed clockwise.
        #
        set rotpoly [list]
        set xsub [expr {$x1 + ($width / 2)}]
        set ysub [expr {$y1 + ($height / 2)}]
        set xadd [expr {$x1 + ($newwidth / 2)}]
        set yadd [expr {$y1 + ($newheight / 2)}]

        foreach {x y} $poly {
             set x [expr {$x - $xsub}]
             set y [expr {$y - $ysub}]
             set xx [expr {int(($x * $c) - ($y * $s)) + $xadd}]
             set yy [expr {int(($x * $s) + ($y * $c)) + $yadd}]
             lappend rotpoly $xx $yy
        }

        return $rotpoly
    }

    public proc inputTranslatePolygon {poly xadd yadd} {
        set tpoly [list]
        foreach {x y} $poly {
            incr x $xadd
            incr y $yadd
            lappend tpoly $x $y
        }
        return $tpoly
    }

    public proc inputTranslateXyFromRoot {path x y} {
        set worklist [list $path]
        set myParent [$path parent]
        while {($myParent ne "") && [llength [$myParent parent]]} {
            set worklist [linsert $worklist 0 $myParent]
            set myParent [$myParent parent]
	    if {$myParent eq "."} {
	        break
	    }
        }
        set px $x
	set py $y 
        foreach c $worklist {
            set x1 [$c cget -xoffset]
            set y1 [$c cget -yoffset]
	    set myWidth [$c cget -width]
	    set myHeight [$c cget -height]
	    set myRotate [$c cget -rotate]
            if {$myRotate} {
                inputRotationSize [expr {3.14159 * $myRotate / 180}] \
                        $myWidth $myHeight newwidth newheight
                set xmod [expr {$x1 + $newwidth / 2}]
                set ymod [expr {$y1 + $newheight / 2}]
                set px [expr {$px - $xmod}]
                set py [expr {$py - $ymod}]
                inputRotatePoint $px $py $myRotate pxx pyy
                set px [expr {$pxx + $x1 + ($myWidth / 2)}]
                set py [expr {$pyy + $y1 + ($myHeight / 2)}]
            }
            set px [expr {$px - $x1}]
            set py [expr {$py - $y1}]
       }
       list $px $py
    }

    public proc inputXYInWindows {path pointx pointy {totalrotation 0}} {
        set r [list]
        if {0} { 
            if {![winfo exists .debug]} {
                toplevel .debug
                pack [canvas .debug.c -width 800 -height 600] -fill both -expand 1
            }
        }
#puts stderr SEARCHING:$w
        foreach c [$path children] {
            set x1 [$c cget -xoffset]
            set y1 [$c cget -yoffset]
            set myWidth [$c cget -width]
            set myHeight [$c cget -height]
	    set x2 [expr {$x1 + $myWidth}]
            set y2 [expr {$y1 + $myHeight}] 
            set px $pointx
	    set py $pointy
	    set myRotate [$c rotate]
            if {$myRotate} {
                inputRotationSize [expr {3.14159 * $myRotate / 180}] \
                        $myWidth $myHeight newwidth newheight
                set xmod [expr {$x1 + $newwidth / 2}]
                set ymod [expr {$y1 + $newheight / 2}]
                set px [expr {$px - $xmod}]
                set py [expr {$py - $ymod}]
                inputRotatePoint $px $py $myRotate pxx pyy
                set px [expr {$pxx + $x1 + ($myWidth / 2)}]
                set py [expr {$pyy + $y1 + ($myHeight / 2)}]
            }
            if {0} {
               .debug.c create text $px $py -text "$px,$py" -fill orange 
               .debug.c create polygon [list $x1 $y1 $x2 $y1 $x2 $y2 $x1 $y2 $x1 $y1] -fill {} -outline green 
            }
            if {$px >= $x1 && $px < $x2 && $py >= $y1 && $py < $y2} {
                lappend r [list $c [list [expr {$px - $x1}] [expr {$py - $y1}]]]
#puts stderr "FOUND:$c POINTX:$pointx POINTY:$pointy"
                set r [concat $r [inputXYInWindows $c \
	                [expr {$px - $x1}] [expr {$py - $y1}] $myRotate]]
            }
        }
        return $r
    }

    public proc inputCompat8.5Keypress {key keysym keycode} {
        set ::NS_unfiltered_keysym $keysym
        inputKeyPress . $key [inputCompat8.5Keysym $keysym] $keycode
    }

    public proc inputCompat8.5Keyrelease {key keysym keycode} {
        set ::NS_unfiltered_keysym $keysym
        inputKeyRelease . $key [inputCompat8.5Keysym $keysym] $keycode
    }

    public proc inputCompat8.5Keysym {keysym} {
        switch -- $keysym {
        Left {
            set keysym left 
          }
        Right {
            set keysym right
          }
        Up {
            set keysym up
          }
        Down {
            set keysym down
          }
        Delete {
            set keysym delete
          }
        BackSpace {
            set keysym backspace
          }
        Shift_L {
            set keysym shift_l
          }
        Shift_R {
            set keysym shift_r
          }
        Return {
            set keysym return
          }
        default {
            set keysym normal
          }
        }
        return $keysym
    }

    public proc inputFrom8.5 {win} {
        bind $win <KeyPress> [list inputCompat8.5Keypress %A %K %k]
        bind $win <KeyRelease> [list inputCompat8.5Keyrelease %A %K %k]
        bind $win <Motion> {inputMotion . %x %y}
        bind $win <ButtonPress> {inputMousePress . %b %x %y}
        bind $win <ButtonRelease> {inputMouseRelease . %b %x %y}
    }
}
