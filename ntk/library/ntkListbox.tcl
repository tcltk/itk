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
# RCS: @(#) $Id: ntkListbox.tcl,v 1.1.2.6 2007/10/18 23:01:44 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::listbox {
    inherit ::ntk::classes::theme 

    private variable destroy listboxDestroy

    public option -selectioncolor -default [list 200 100 200 255] \
            -configuremethod listboxConfig
    public option -selectioncallback -default [list] \
            -configuremethod listboxConfig
    public option -xscrollcommand -default [list] -configuremethod listboxConfig
    public option -yscrollcommand -default [list] -configuremethod listboxConfig

    public methodvariable contexts -default [list]
    public methodvariable data -default [list]
    public methodvariable contextdata -default [list]
    public methodvariable sizedata -default [list]
    public methodvariable xoffset -default 0
    public methodvariable yoffset -default 0
    public methodvariable selected -default 0
    public methodvariable pendingAfterId -default ""
    public methodvariable peakwidth -default 1
    public methodvariable peaklineheight -default 0
    public methodvariable peaklinewidth -default 0
    public methodvariable totalheight -default 0
    public methodvariable starty -default 0

    private method listboxConfig {option value} {
        set itcl_options($option) $value
        listboxDraw $wpath
    }

    constructor {args} {
        set themeConfig listboxConfig
	set itcl_options(-width) 200
	set itcl_options(-height) 260
	if {[llength $args] > 0} {
	    configure {*}$args
	}
	appendRedrawHandler [list $wpath listboxRedraw $wpath]
	appendDestroyHandler [list $wpath listboxDestroy $wpath]
        set itcl_options(-buttonpress) [list $wpath listboxButtonPress $wpath]
        return $wpath
    }

    public method listboxButtonPress {path button x y globalx globaly} {
puts stderr "listboxButtonPress!$path!$button!"
        if {$button != 1} {
            return
        }
        if {($x < 0) || ($x >= [$path cget -width])} {
            return
        }
	set mySelected [list]
	set ly 1
	set i 0
	foreach d [$path data] sizeset [$path sizedata] {
	    lassign $sizeset _ myHeight
	    set testy [expr {$ly - [$path yoffset]}]
            if {($y >= $testy) && ($y < ($testy + $myHeight))} {
		if {[$path cget -selectioncallback] ne ""} {
	            uplevel #0 [linsert [$path cget -selectioncallback] end $i \
		            [lindex $path data] $i]
	        }
	        lappend mySelected $i
	        break
	    }
	    incr i
	    incr ly $myHeight
	    incr ly
        }
        $path selected $mySelected
        $path listboxDraw $path
    }

    public method listboxCollectContexts {path} {
        set myContextdata [$path contextdata]
        set myContexts [$path contexts]
        array set used {}
        foreach i $myContextdata {
            set used([expr {$i - 1}]) 1
        }
        set newcontexts [list]
        foreach i [array names used] {
             lappend newcontexts [lindex $myContexts $i]
        }
        $path contexts $newcontexts
    }



    public method delete {path args} {
	set mySelected [$path selected]
        switch -- [llength $args] {
        1 {
            set i [lindex $args 0]
	    #Deselect any previously selected item.
	    if {[set sel [lsearch -exact $mySelected $i]] >= 0} {
	        set mySelected [lreplace $mySelected $sel $sel]
	        $path selected $mySelected
            }
            $path data [lreplace [$path data] $i $i]
	    $path contextdata [lreplace [$path contextdata] $i $i]
	    $path sizedata [lreplace [$path sizedata] $i $i]
	    listboxMeasureLines $path 0 0
          }
        2 {
            lassign $args s e
	    if {$e eq "end"} {
	        set e [llength [$path data]]
	    }
	    # Deselect the deleted items (if they were selected)
	    for {set i $s} {$i < $e} {incr i} {
	         if {[set sel [lsearch -exact $mySelected $i]] >= 0} {
	             set mySelected [lreplace $mySelected $sel $sel]
		     $path selected $mySelected
	         }
	    }
	    $path data [lreplace [$path data] $s $e]
	    $path contextdata [lreplace [$path contextdata] $s $e]
	    $path sizedata [lreplace [$path sizedata] $s $e]
	    listboxMeasureLines $path 0 0
          } 
        default {
            return -code error "invalid number of arguments: $args\
should be: $path delete index ?end-index?"
          } 
        }
        if {[$path cget -yoffset] > [llength [$path cget -data]]} {
             $path configure -yoffset [llength [$path cget -data]]
         }
	 $path listboxCollectContexts $path
         $path listboxDraw $path
    }

    public method listboxDestroy {path} {
        #Cleanup any megaimage or freetype objects
    }

    public method listboxDraw {path} {
        set obj [$path obj]
        $obj setall [$path cget -bg]
        set tmp [megaimage-blank]
        set myX [expr {[$path xoffset] + [$path cget -bd] + 1}]
        set myY 0
        set mySelected [$path cget -selected]
	set myData [$path data]
	set datalen [llength $data]
	set sizes [$path sizedata]
        if {[$path totalheight] > [$path cget -height]} {
            set ylimit [expr {[$path totalheight] - [$path cget -height]}]
            if {[$path yoffset] > $ylimit} {
                $path yoffset $ylimit
            }
        }
        # Find which i to start with
        set yoff 0
        for {set i 0} {$i < $datalen} {incr i} {
            set myHeight [lindex $sizes $i 1]
            if {$yoff >= [$path yoffset] && [$path yoffset] < \
                    ($yoff + $myHeight)} {
                set myY [expr {$yoff - [$path yoffset]}]
                break
            }
            incr yoff $myHeight
            incr yoff
        }

        # Iterate and draw the range of the text that is visible.
        foreach d [lrange [$path data] $i end] \
                myContext [lrange [$path contextdata] $i end] \
                sizeset [lrange [$path sizedata] $i end] {
            lassign $sizeset myWidth myHeight
            lassign [listboxLookupContext $path $myContext] font fontsize \
                    textcolor
            set buf [freetype $font $fontsize $d $textcolor _ _]
            $tmp setdata $buf
            if {[lsearch -exact $mySelected $i] >= 0} {
                set tmp2 [megaimage-blank $myWidth $myHeight]
                $tmp2 setall [$path cget -selectioncolor]
                $tmp2 blendobj 0 0 $tmp
                $obj blendobj $myX $myY $tmp2
                rename $tmp2 {}
            } else {
                $obj blendobj $myX $myY $tmp
            }
            incr i
            incr myY $myHeight
            incr myY
            if {$myY >= [$path cget -height]} {
                break
            }
        }
        rename $tmp {}
        themeListboxDrawBorder $path
        listboxUpdateViews $path
        $path pendingAfterId ""
        render $path
    }

    public method listboxIdleDraw {path} {
        if {[$path pendingAfterId] ne ""} {
	    return
        }
        pendingAfterId [after idle [list listboxDraw $path]]
    }

    public method insert {myOffset args} {
        set cons [list]
        set sizes [list]
        foreach i $args {
            lappend cons 0
            lappend sizes [list 0 0]
        }
        if {$myOffset eq "end"} {
            set myOffset [llength [$wpath data]]
        }
        $wpath data [linsert [$wpath data] $myOffset {*}$args]
        $wpath contextdata [linsert [$wpath contextdata] $myOffset {*}$cons]
        $wpath sizedata [linsert [$wpath sizedata] $myOffset {*}$sizes]
        listboxMeasureLines $wpath $myOffset [expr {$myOffset + [llength $args]}]
        listboxDraw $wpath
    }

    public method itemconfigure {path index args} {
        array set myOptions $args
        array set conar [list -font [$path cget -font] \
                -fontsize [$path cget -fontsize] \
                -textcolor [$path cget -textcolor]]
        foreach {key value} [array get myOptions] {
            if {![info exists conar($key)]} {
                return -code error "invalid option: $key"
            }
            set conar($key) $value
        }
        # $conar(-textcolor) may be a symbolic color, so substitute it if needed.
        set key [string tolower $conar(-textcolor)]
        if {[info exists colors($key)]} {
            set conar(-textcolor) $colors($key)
        }
        set myContexts [$path contexts]
        lappend myContexts [list $conar(-font) $conar(-fontsize) $conar(-textcolor)]
        $path contexts $myContexts
        set myContextdata [$path contextdata]
        lset myContextdata $index [llength $myContexts]
        $path contextdata $myContextdata
        listboxMeasureLines $path $index [expr {$index + 1}]
        listboxIdleDraw $path
    }

    public method listboxLookupContext {path context} {
        set cons [$path contexts]
        if {$context == 0} {
            return [list [$path cget -font] [$path cget -fontsize] [$path cget -textcolor]]
        }
        incr context -1 ;# context zero is a virtual context that refers to the $path options
        return [lindex $cons $context]
    }

    public method listboxMeasureContents {path} {
        set myTotalheight 0
        set myPeakwidth 0
        set myPeakheight 0
        foreach line [$path data] {
            freetype-measure [$path cget -font] [$path cget -fontsize] $line myWidth myHeight
            if {$myHeight > $myPeakheight} {
                set myPeakheight $myHeight
            }
            if {$myWidth > $myPeakwidth} {
                set myPeakwidth $myWidth
            }
            incr myTotalheight $myHeight
            incr myTotalheight 2 ;#XXX from NS_listbox-draw
        }
        $path peaklineheight $myPeakheight
        $path peaklinewidth $myPeakwidth
        $path totalheight $myTotalheight
    }

    public method listboxMeasureLines {path start end} {
        set mySizes [$path sizedata]
        set myData [$path data]
        set myContexts [$path contexts]
        set myContextdata [$path contextdata]
        for {set i $start} {$i <= $end} {incr i} {
            if {$i >= [llength $data]} {
                break
            }
            set line [lindex $myData $i]
            if {[string length $line] == 0} {
                set line " "
            }
            set con [lindex $myContextdata $i]
            lassign [listboxLookupContext $path $con] myFont myFontsize _
            freetype-measure $myFont $myFontsize $line myWidth myHeight
            lset mySizes $i [list $myWidth $myHeight]
        }
        $path sizedata $mySizes
        listboxMeasureTotal $path
    }

    public method listboxMeasureTotal {path} {
        set myPeakwidth 0
        set myTotalheight 0

        foreach sizeset [$path sizedata] {
            lassign $sizeset myWidth myHeight
            if {$myWidth > $myPeakwidth} {
                set myPeakwidth $myWidth
            }
            incr myTotalheight $myHeight
            incr myTotalheight
        }
        $path peaklinewidth $myPeakwidth
        $path totalheight $myTotalheight
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

    public method listboxUpdateViews {path} {
        if {[$path peaklinewidth] > [$path cget -width]} {
         set delta [expr {[$path peaklinewidth] - [$path cget -width] + \
                 [$path xoffset]}]
         set rat [expr {1.0 / [$path peaklinewidth]}]
         set xscrollstart [expr {-[$path xoffset] * $rat}]
         set xscrollend [expr {((-[$path xoffset]) + \
                 [$path cget -width]) * $rat}]
        } else {
            set xscrollstart 0.0
            set xscrollend 1.0
        }

        if {[$path totalheight] > [$path cget -height]} {
            set rat [expr {1.0 / [$path totalheight]}]
            set yscrollstart [expr {[$path yoffset] * $rat}]
            set yscrollend [expr {([$path yoffset] + \
                    [$path cget -height]) * $rat}]
        } else {
            set yscrollstart 0.0
            set yscrollend 1.0
        }

        listboxUpdateView $path [$path cget -xscrollcommand] \
                $xscrollstart $xscrollend
        listboxUpdateView $path [$path cget -yscrollcommand] \
                $yscrollstart $yscrollend
    }


    public method xview {path args} {
        if {([llength $args] != 2) && ([llength $args] != 3)} {
            return -code error "invalid number of arguments to xview"
        }
        switch -- [lindex $args 0] {
        scroll {
            lassign $args type incr incrtype
            if {$incrtype eq "units"} {
                set i [$path xoffset]
                incr i [expr {- ($incr * 4)}]
                if {$i > 0} {
                    set i 0
                }
                if {[$path peaklinewidth] > [$path cget -width]} {
                    set peakx [expr {[$path peaklinewidth] - \
                            [$path cget -width]}]
                    if {abs($i) > $peakx} {
                        set i [expr {-$peakx}]
                    }
                    $path xoffset $i
                } else {
                    $path xoffset 0
                }
                listboxIdleDraw $path
            }
          }
        moveto {
            lassign $args type incr
            if {[$path peaklinewidth] > [$path cget -width]} {
                set lowoff [expr {[$path cget -width] - [$path peaklinewidth]}]
                set newoff [expr {-int([$path peaklinewidth] * $incr)}]
                if {$newoff < $lowoff} {
                    set newoff $lowoff
                }
                if {$newoff > 0} {
                    set newoff 0
                }
                $path xoffset $newoff
            } else {
                $path xoffset 0
            }
            listboxIdleDraw $path
          }
        }
    }

    public method yview {path args} {
        if {([llength $args] != 2) && ([llength $args] != 3)} {
            return -code error "invalid number of arguments to yview"
        }
        switch -- [lindex $args 0] {
        scroll {
            lassign $args type incr incrtype
            if {$incrtype eq "units"} {
                set i [$path yoffset]
                incr i [expr {$incr * 4}]
                set limit [expr {[$path totalheight] - [$path cget -height]}]
                if {$i < 0} {
                    set i 0
                }
                if {$i > $limit} {
                    set i $limit
                }
                if {[$path cget -height] > [$path totalheight]} {
                    set i 0
                }
                $path yoffset $i
                listboxIdleDraw $path
            }
          }
        moveto {
            lassign $args type incr
            if {$incr > 1.0} {
                set incr 1.0
            }
            set newoff [expr {int(floor([$path totalheight] * $incr))}]
            if {$newoff < 0} {
                set newoff 0
            } else { 
                if {[$path cget -height] > [$path totalheight]} {
                    set newoff 0
                }
                $path yoffset $newoff
                listboxIdleDraw $path
            }
          }
        }
    }
}
