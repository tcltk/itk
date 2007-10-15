#---------------------------------------------------------------------------
# ntkWidget ntkListbox.tcl --
#
# This file contains a ntkWidget listbox command implementation
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
# RCS: @(#) $Id: ntkListbox.tcl,v 1.1.2.3 2007/10/15 09:24:51 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::listbox {
    inherit ::ntk::classes::window 

    private variable listboxDraw [list]
    private variable destroy listboxDestroy

    public option -font -default {} -configuremethod listboxlabelConfig
    public option -fontsize -default {} -configuremethod listboxConfig
    public option -textcolor -default {} -validatemethod verifyColor -configuremethod listboxConfig
    public option -bg -default {} -validatemethod verifyColor -configuremethod listboxConfig
    public option -bd -default 0 -validatemethod verifyBorder -configuremethod listboxConfig
    public option -selectionbordecolor -default {} -configuremethod listboxConfig
    public option -selectioncallback -default [list] -configuremethod listboxConfig
    public option -xscrollcommand -default [list] -configuremethod listboxConfig
    public option -yscrollcommand -default [list] -configuremethod listboxConfig
    public option -xoffset -default 0 -configuremethod listboxConfig
    public option -yoffset -default 0 -configuremethod listboxConfig
    public option -yoffsetmap -default [list] -configuremethod listboxConfig
    public option -selected -default 0 -configuremethod listboxConfig
    public option -pending_afterid -default "" -configuremethod listboxConfig
    public option -peakwidth -default 1 -configuremethod listboxConfig
    public option -data -default [list] -configuremethod listboxConfig

    private method listboxConfig {option value} {
        set itcl_options($option) $value
        if {$listboxDraw ne ""} {
            $listboxDraw [path]
        }
    }

    constructor {args} {
        eval ::ntk::classes::window::constructor -width 200 -height 200
    } {
	set itcl_options(-font) $defaultFont
	set itcl_options(-fontsize) 12
	set itcl_options(-bg) [defaultBackgroundColor]
	set itcl_options(-textcolor) [defaultTextColor]
	set itcl_options(-selectionbordercolor) [list 0 0 0 255]
	set path [path]
	eval configure $args
	appendRedrawHandler [list $path listboxRedraw $path]
# $path -buttonpress [list listboxButtonPress $path]

	set listboxDraw listboxDraw
        return $path
    }

    public method listboxButtonPress {path button x y globalx globaly} {
        if {$button != 1} {
            return
        }
        if {($x < 0) || ($x >= [$path cget -width])} {
            return
        }
        set map [$path cegt -yoffsetmap]
        set i [$path cget -yoffset]
        set selected [list]
        foreach {start end} $map {
            if {($y >= $start) && ($y < $end)} {
                lappend selected $i
   #puts "SEL:$selected [lindex [$path cget -data] $i]"
                if {[$path cget -selectioncallback] ne ""} {
                    uplevel #0 [linsert [$path cget -selectioncallback] end $i [lindex [$path cget -data] $i]]
                }
                break
            }
            incr i
        } 
        $path configure -selected $selected
        $path listboxDraw
    }

    public method listboxDeleteMethod {path args} {
        switch -- [llength $args] {
        1 {
           set i [lindex $args 0]
           set data [$path cget -data]
           $path configure -data [lreplace $data $i $i]
          }
        2 {
           lassign $args s e
           set data [$path cget -data]
           $path configre -data [lreplace $data $s $e]
          } 
        default {
           return -code error "invalid number of arguments: $args"
          } 
         }
         if {[$path cget -yoffset] > [llength [$path cget -data]]} {
             $path configure -yoffset [llength [$path cget -data]]
         }
         $path listboxDraw $path
    }

    public method listboxDestroy {path} {
        #Cleanup any megaimage or freetype objects
    }

    public method listboxDraw {path} {
        set obj [$path obj]
        set data [$path cget -data]
        $obj setall [$path cget -bg]
        set tmp [megaimage-blank]
        set x 4
        set y 4
        set selected [$path cget -selected]
        set yoffsetmap [list]
        set peakwidth 1
        for {set i [$path cget -yoffset]} {$i < [llength $data]} {incr i} {  
            set line [lindex $data $i]
            set buf [freetype [$path cget -font] [$path cget -fontsize] $line [$path cget -textcolor] width height]
            if {$width > $peakwidth} {
                set peakwidth $width
            }
            $tmp setdata $buf
            $obj blendobj $x $y $tmp
            configure -ystart $y
            lappend yoffsetmap $y
            incr y $height
            lappend yoffsetmap $y
            set yend $y
            if {[lsearch -exact $selected $i] >= 0} {
                set y [expr {$ystart - 1}]
                $obj line 1 $y $width $y [$path cget -selectionbordercolor]
                set y [expr {$yend + 1}]
                $obj line 1 $y $width $y [$path cget -selectionbordercolor]
            }
            incr y 2
            if {$y >= [$path cget -height]} {
                break
            }
        }
        $path configure -yoffsetmap $yoffsetmap
        $path configure -peakwidth $peakwidth
        rename $tmp {}
        #set xrat [expr {1.0 / $peakwidth}]
        #set xscrollstart [expr {[$path cget -xoffset] * $xrat}]
        #set yscrollend [expr {}]
        if {[info exists height]} {
            set rat [expr {1.0 / [llength $data]}]
            set yscrollstart [expr {[$path yoffset] * $rat}] 
            set yscrollend [expr {$i  * $rat}]
            if {$yscrollend > 1.0} {
	        set yscrollend 1.0 
	    }
            listboxUpdateView $path [$path cget -yscrollcommand] $yscrollstart $yscrollend
        } else {
            listboxUpdateView $path [$path cget -yscrollcommand] 0.0 1.0
        }
        render $path
        configure -pending_afterid ""
    }

    public method listboxIdleDraw {path} {
        if {[$path cget -pending_afterid] ne ""} {
	    return
        }
        configure -pending_afterid [after idle [list listboxDraw $path]]
    }

    public method listboxInsert {path offset args} {
        set data [$path cget -data]
        set data [linsert $data $offset {*}$args]
        $path configure -data $data
        listboxDraw $path
    }

    public method listboxInsertMethod {path offset args} {
        set data [$path cget -data]
        $path configure -data [linsert $data $offset {*}$args]
        listboxDraw $path
    }

    public method listboxRedraw {path} {
        listboxDraw $path
    }

    public method listboxTrace {path} {
        listboxDraw $path
    }

   public method listboxUpdateView {path basecmd ystart yend} {
       if {$basecmd ne ""} {
           uplevel #0 $basecmd [list $ystart] [list $yend]
       }
   }

    public method listboxXviewMethod {path args} {
        if {([llength $args] != 2) && ([llength $args] != 3)} {
            return -code error "invalid number of arguments to xview"
        }
        switch -- [lindex $args 0] {
        scroll {
            lassign $args type incr incrtype
          }
        }
    }

    public method listboxYviewMethod {path args} {
        if {([llength $args] != 2) && ([llength $args] != 3)} {
            return -code error "invalid number of arguments to yview"
        }
        switch -- [lindex $args 0] {
        scroll {
            lassign $args type incr incrtype
            if {$incrtype eq "units"} {
                set i [$path yoffset]
                incr i $incr
                if {($i >= 0) && ($i < [llength [$path cget -data]])} {
                    $path configure -yoffset $i
                    listboxIdleDraw $path
                }
            }
          }
        moveto {
            lassign $args type incr
            set newoff [expr {int(floor([llength [$path cget data]] * $incr))}]
            if {$newoff < 0} {
                set newoff 0
            } else { 
	        if {$newoff >= [llength [$path cget -data]]} {
                    set newoff [expr {[llength [$path cget -data]] - 1}]
                }
                $path configure -yoffset $newoff
                listboxIdleDraw $path
            }
          }
        }
    }
}
