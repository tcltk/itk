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
# RCS: @(#) $Id: ntkListbox.tcl,v 1.1.2.12 2007/11/28 21:38:08 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::listbox {
    inherit ::ntk::classes::theme 

    private variable destroy listboxDestroy

    public option -selectioncallback -default [list] \
            -configuremethod listboxConfig
    public option -selectioncolor -default [list 200 100 200 255] \
            -configuremethod listboxConfig
    public option -xscrollcommand -default [list] -configuremethod listboxConfig
    public option -yscrollcommand -default [list] -configuremethod listboxConfig

    public methodvariable contextdata -default [list]
    public methodvariable contexts -default [list]
    public methodvariable data -default [list]
    public methodvariable peaklineheight -default 0
    public methodvariable peaklinewidth -default 0
    public methodvariable peakwidth -default 1
    public methodvariable pendingAfterId -default ""
    public methodvariable selected -default 0
    public methodvariable sizedata -default [list]
    public methodvariable starty -default 0
    public methodvariable totalheight -default 0
    public methodvariable xoffset -default 0
    public methodvariable yoffset -default 0

    private method listboxConfig {option value} {
        set itcl_options($option) $value
        listboxDraw
    }

    constructor {args} {
        set themeConfig listboxConfig
	set itcl_options(-width) 200
	set itcl_options(-height) 260
	if {[llength $args] > 0} {
	    configure {*}$args
	}
	appendRedrawHandler [list $wpath listboxRedraw]
	appendDestroyHandler [list $wpath listboxDestroy]
        set itcl_options(-buttonpress) [list $wpath listboxButtonPress]
        return $wpath
    }

    public method listboxButtonPress {button x y globalx globaly} {
#puts stderr "listboxButtonPress!$button!"
        if {$button != 1} {
            return
        }
        if {($x < 0) || ($x >= $itcl_options(-width))} {
            return
        }
	set mySelected [list]
	set ly 1
	set i 0
	foreach d $data sizeset $sizedata {
	    lassign $sizeset _ myHeight
	    set testy [expr {$ly - $yoffset}]
            if {($y >= $testy) && ($y < ($testy + $myHeight))} {
		if {$itcl_options(-selectioncallback) ne ""} {
		    set cmd [list $itcl_options(-selectioncallback) \
		            $wpath $i [lindex $data $i]]
#puts stderr "CMD!$cmd!"
                    uplevel #0 $cmd
	        }
	        lappend mySelected $i
	        break
	    }
	    incr i
	    incr ly $myHeight
	    incr ly
        }
        set selected $mySelected
        listboxDraw
    }

    public method listboxCollectContexts {} {
        set myContextdata $contextdata
        set myContexts $contexts
        array set used {}
        foreach i $myContextdata {
            set used([expr {$i - 1}]) 1
        }
        set newcontexts [list]
        foreach i [array names used] {
             lappend newcontexts [lindex $myContexts $i]
        }
        set contexts $newcontexts
    }

    public method delete {args} {
	set mySelected $selected
        switch -- [llength $args] {
        1 {
            set i [lindex $args 0]
	    #Deselect any previously selected item.
	    if {[set sel [lsearch -exact $mySelected $i]] >= 0} {
	        set mySelected [lreplace $mySelected $sel $sel]
	        set selected $mySelected
            }
            set data [lreplace $data $i $i]
	    set contextdata [lreplace $contextdata $i $i]
	    set sizedata [lreplace $sizedata $i $i]
	    listboxMeasureLines 0 0
          }
        2 {
            lassign $args s e
	    if {$e eq "end"} {
	        set e [llength $data]
	    }
	    # Deselect the deleted items (if they were selected)
	    for {set i $s} {$i < $e} {incr i} {
	         if {[set sel [lsearch -exact $mySelected $i]] >= 0} {
	             set mySelected [lreplace $mySelected $sel $sel]
		     set selected $mySelected
	         }
	    }
	    set data [lreplace $data $s $e]
	    set contextdata [lreplace $contextdata $s $e]
	    set sizedata [lreplace $sizedata $s $e]
	    listboxMeasureLines 0 0
          } 
        default {
            return -code error "invalid number of arguments: $args\
should be: $wpath delete index ?end-index?"
          } 
        }
        if {$yoffset > [llength $data]} {
             set yoffset [llength $data]
         }
	 listboxCollectContexts
         listboxDraw
    }

    public method listboxDestroy {} {
        #Cleanup any ntkWidget or freetype objects
	# cleanup windowImage
    }

    public method listboxDraw {} {
#puts stderr "listboxDraw"
        ::ntk::widgetImage::Image fill $windowImage $itcl_options(-bg)
	::ntk::widgetImage::Image setsize $windowImage \
	        $itcl_options(-width) $itcl_options(-height)
	::ntk::widgetImage::Image fill $windowImage [list 0 0 0 0]
        set myX [expr {$xoffset + $itcl_options(-bd) + 1}]
        set myY 0
        set mySelected $selected
	set myData $data
	set datalen [llength $myData]
	set sizes $sizedata
        if {$totalheight > $itcl_options(-height)} {
            set ylimit [expr {$totalheight - $itcl_options(-height)}]
            if {$yoffset > $ylimit} {
                set yoffset $ylimit
            }
        }
        # Find which i to start with
        set yoff 0
        for {set i 0} {$i < $datalen} {incr i} {
            set myHeight [lindex $sizes $i 1]
            if {$yoff >= $yoffset && $yoffset < ($yoff + $myHeight)} {
                set myY [expr {$yoff - $yoffset}]
                break
            }
            incr yoff $myHeight
            incr yoff
        }

        # Iterate and draw the range of the text that is visible.
        foreach \
	        d [lrange $data $i end] \
                myContext [lrange $contextdata $i end] \
                sizeset [lrange $sizedata $i end] {
            lassign $sizeset myWidth myHeight
            lassign [listboxLookupContext $myContext] font fontsize \
                    textcolor
	    set buf [::ntk::widgetImage::Image create 1 1]
            ::ntk::widgetImage::Image createtext $buf $font $fontsize $d \
	            $textcolor bufWidth bufHeight
            if {[lsearch -exact $mySelected $i] >= 0} {
                ::ntk::widgetImage::Image rectangle $windowImage \
		        $myX $myY $bufWidth $bufHeight \
			$itcl_options(-selectioncolor)
                ::ntk::widgetImage::Image blendwidget $windowImage $myX $myY $buf
            } else {
                ::ntk::widgetImage::Image clipcopy $windowImage \
		        $myX $myY [expr {$myX + $bufWidth}] \
			[expr {$myY + $bufHeight}] $buf
            }
            incr i
            incr myY $myHeight
            incr myY
            if {$myY >= $itcl_options(-height)} {
                break
            }
        }
# FIX ME !!
#        rename $buf {}
        themeListboxDrawBorder
        listboxUpdateViews
        set pendingAfterId ""
        render $wpath
    }

    public method listboxIdleDraw {} {
        if {$pendingAfterId ne ""} {
	    return
        }
        set pendingAfterId [after idle [list $wpath listboxDraw]]
    }

    public method insert {myOffset args} {
        set cons [list]
        set sizes [list]
        foreach i $args {
            lappend cons 0
            lappend sizes [list 0 0]
        }
        if {$myOffset eq "end"} {
            set myOffset [llength $data]
        }
        set data [linsert $data $myOffset {*}$args]
        set contextdata [linsert $contextdata $myOffset {*}$cons]
        set sizedata [linsert $sizedata $myOffset {*}$sizes]
        listboxMeasureLines $myOffset [expr {$myOffset + [llength $args]}]
        listboxDraw
    }

    public method itemconfigure {index args} {
        array set myOptions $args
        array set conar [list -font $itcl_options(-font) \
                -fontsize $itcl_options(-fontsize) \
                -textcolor $itcl_options(-textcolor)]
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
        set myContexts $contexts
        lappend myContexts [list $conar(-font) $conar(-fontsize) $conar(-textcolor)]
        set contexts $myContexts
        set myContextdata $contextdata
        lset myContextdata $index [llength $myContexts]
        set contextdata $myContextdata
        listboxMeasureLines $index [expr {$index + 1}]
        listboxIdleDraw
    }

    public method listboxLookupContext {context} {
        set cons $contexts
        if {$context == 0} {
            return [list $itcl_options(-font) $itcl_options(-fontsize) \
	            $itcl_options(-textcolor)]
        }
	# context zero is a virtual context that refers to the options
        incr context -1 
        return [lindex $cons $context]
    }

    public method listboxMeasureContents {} {
        set myTotalheight 0
        set myPeakwidth 0
        set myPeakheight 0
        foreach line $data {
            ::ntk::widgetImage::Image measuretext $itcl_options(-font) \
	            $itcl_options(-fontsize) $line myWidth myHeight
            if {$myHeight > $myPeakheight} {
                set myPeakheight $myHeight
            }
            if {$myWidth > $myPeakwidth} {
                set myPeakwidth $myWidth
            }
            incr myTotalheight $myHeight
            incr myTotalheight 2 ;#XXX from NS_listbox-draw
        }
        set peaklineheight $myPeakheight
        set peaklinewidth $myPeakwidth
        set totalheight $myTotalheight
    }

    public method listboxMeasureLines {start end} {
        set mySizes $sizedata
        set myData $data
        set myContexts $contexts
        set myContextdata $contextdata
        for {set i $start} {$i <= $end} {incr i} {
            if {$i >= [llength $myData]} {
                break
            }
            set line [lindex $myData $i]
            if {[string length $line] == 0} {
                set line " "
            }
            set con [lindex $myContextdata $i]
            lassign [listboxLookupContext $con] myFont myFontsize _
            ::ntk::widgetImage::Image measuretext $myFont $myFontsize $line \
	            myWidth myHeight
            lset mySizes $i [list $myWidth $myHeight]
        }
        set sizedata $mySizes
        listboxMeasureTotal
    }

    public method listboxMeasureTotal {} {
        set myPeakwidth 0
        set myTotalheight 0

        foreach sizeset $sizedata {
            lassign $sizeset myWidth myHeight
            if {$myWidth > $myPeakwidth} {
                set myPeakwidth $myWidth
            }
            incr myTotalheight $myHeight
            incr myTotalheight
        }
        set peaklinewidth $myPeakwidth
        set totalheight $myTotalheight
    }

    public method listboxRedraw {} {
        listboxDraw
    }

    public method listboxTrace {} {
        listboxDraw
    }

    public method listboxUpdateView {basecmd ystart yend} {
        if {$basecmd ne ""} {
            uplevel #0 $basecmd [list $ystart] [list $yend]
        }
    }

    public method listboxUpdateViews {} {
        if {$peaklinewidth > $itcl_options(-width)} {
         set delta [expr {$peaklinewidth - $itcl_options(-width) + \
                 $xoffset}]
         set rat [expr {1.0 / $peaklinewidth}]
         set xscrollstart [expr {-$xoffset * $rat}]
         set xscrollend [expr {((-$xoffset) + \
                 $itcl_options(-width)) * $rat}]
        } else {
            set xscrollstart 0.0
            set xscrollend 1.0
        }
        if {$totalheight > $itcl_options(-height)} {
            set rat [expr {1.0 / $totalheight}]
            set yscrollstart [expr {$yoffset * $rat}]
            set yscrollend [expr {($yoffset + \
                    $itcl_options(-height)) * $rat}]
        } else {
            set yscrollstart 0.0
            set yscrollend 1.0
        }
        listboxUpdateView $itcl_options(-xscrollcommand) \
                $xscrollstart $xscrollend
        listboxUpdateView $itcl_options(-yscrollcommand) \
                $yscrollstart $yscrollend
    }

    public method xview {args} {
        if {([llength $args] != 2) && ([llength $args] != 3)} {
            return -code error "invalid number of arguments to xview"
        }
        switch -- [lindex $args 0] {
        scroll {
            lassign $args type incr incrtype
            if {$incrtype eq "units"} {
                set i $xoffset
                incr i [expr {- ($incr * 4)}]
                if {$i > 0} {
                    set i 0
                }
                if {$peaklinewidth > $itcl_options(-width)} {
                    set peakx [expr {$peaklinewidth - \
                            $itcl_options(-width)}]
                    if {abs($i) > $peakx} {
                        set i [expr {-$peakx}]
                    }
                    set xoffset $i
                } else {
                    set xoffset 0
                }
                listboxIdleDraw
            }
          }
        moveto {
            lassign $args type incr
            if {$peaklinewidth > $itcl_options(-width)} {
                set lowoff [expr {$itcl_options(-width) - $peaklinewidth}]
                set newoff [expr {-int($peaklinewidth * $incr)}]
                if {$newoff < $lowoff} {
                    set newoff $lowoff
                }
                if {$newoff > 0} {
                    set newoff 0
                }
                set xoffset $newoff
            } else {
                set xoffset 0
            }
            listboxIdleDraw
          }
        }
    }

    public method yview {args} {
        if {([llength $args] != 2) && ([llength $args] != 3)} {
            return -code error "invalid number of arguments to yview"
        }
        switch -- [lindex $args 0] {
        scroll {
            lassign $args type incr incrtype
            if {$incrtype eq "units"} {
                set i $yoffset
                incr i [expr {$incr * 4}]
                set limit [expr {$totalheight - $itcl_options(-height)}]
                if {$i < 0} {
                    set i 0
                }
                if {$i > $limit} {
                    set i $limit
                }
                if {$itcl_options(-height) > $totalheight} {
                    set i 0
                }
                set yoffset $i
                listboxIdleDraw
            }
          }
        moveto {
            lassign $args type incr
            if {$incr > 1.0} {
                set incr 1.0
            }
            set newoff [expr {int(floor($totalheight * $incr))}]
            if {$newoff < 0} {
                set newoff 0
            } else { 
                if {$itcl_options(-height) > $totalheight} {
                    set newoff 0
                }
                set yoffset $newoff
                listboxIdleDraw
            }
          }
        }
    }
}
