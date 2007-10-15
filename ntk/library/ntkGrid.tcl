#---------------------------------------------------------------------------
# ntkWidget ntkGrid.tcl --
#
# This file contains a ntkWidget grid command implementation
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
# RCS: @(#) $Id: ntkGrid.tcl,v 1.1.2.5 2007/10/15 09:24:51 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::grid {
    protected proc dump {grid} {
        puts stderr "BEGIN DUMP"
	set i 0
	foreach row $grid {
	    puts stderr "$i -> $row"
	    incr i
	}
	puts stderr "END DUMP"
    }

    protected proc dumpSizes {grid} {
        foreach row $grid {
	    foreach cells $row {
	        foreach w $cells {
		    puts -nonewline stderr "$w is +[$w cget -x]+[$w cget -y] [$w cget -width]x[$w cget -height] \[[$w cget -slot]\]\t"
		}
	    }
	    puts stderr ""
	}
    }

    protected proc free {managerobj} {
        uplevel 0 [free] $managerobj
    }

    protected proc getVisible {columnsVar rowsVar} {
        # 
	# find the number of visible columns
	#
	set r 0
	foreach row [grid] {
	    set c 0
	    foreach w $row {
	        if {$w eq ""} {
		    incr c
		    continue
		}
		for {set i 0} {$i < [$w cget -columnspan]} {incr i} {
		    lappend columns [expr {$c + $i}]
		}
		for {set i 0} {$i < [$w cget -rowspan]} {incr i} {
		    lappend rows [expr {$r + $i}]
		}
                incr c
	    }
	    incr r
	}
    }

    protected proc insertWidget {gridVar w c r} {
	upvar $gridVar grid

        if {[llength $grid] <= ($r + 1)} {
            #
            # The grid row doesn't exist, so insert it.
            #
            for {set i [expr {[llength $grid] - 1}]} {$i < $r} {incr i} {
                lappend grid [list]
            }
       } 
       set row [lindex $grid $r]
       if {[llength $row] <= ($c + 1)} {
           #
           # The grid column doesn't exist in the row, so insert it.
           #
           for {set i [expr {[llength $row] - 1}]} {$i < $c} {incr i} {
               lappend row {}
           }
       }
       set cells [lindex $row $c]
       if {![llength $cells]} {
           set cells [list $w]
       } else {
           lappend cells $w
       }
       lset row $c $cells
       lset grid $r $row
    }

    protected proc integerCallback {w arg} {
        if {![string is integer -strict $arg]} {
            return -code error "invalid argument (not an integer): $arg"
        }
        return 1
    }

    public proc layout {parent} {
        set m [$parent manager]
        set grid [$m grid]
        set pwidth [$parent cget -width]
        set pheight [$parent cget -height]
        if {$pwidth <= 0 || $pheight <= 0} {
	    return
        }
        set cwork [list]
        for {set c 0} {$c < [$m peakcolumn]} {incr c} {
            set col [list]
            for {set r 0} {$r < [$m peakrow]} {incr r} {
                set cells [lindex $grid $r $c]
                if {[llength $cells] == 0} {
	            continue
	        }
                lappend col {*}$cells
            }
            if {[llength $col]} {
                lappend cwork $col
            }
        }

        layoutDirection $cwork -columnspan reqwidth width $pwidth 0 xsizes

        set rwork [list]
        foreach row $grid {
             set rbuf [list]
             foreach cells $row {
                 if {[llength $cells] == 0} {
	             continue
	         }
                 lappend rbuf {*}$cells
             }
             if {[llength $rbuf]} {
                 lappend rwork $rbuf
             }
        }

        layoutDirection $rwork -rowspan reqheight height $pheight 1 ysizes
        layoutXy $grid xsizes ysizes

puts stderr "parent $pwidth $pheight"
dumpSizes $grid
        redraw $grid
    }

    protected proc layoutDirection {worklist spankey reqdim wdir psize slotoffset sizesvar} {
        upvar $sizesvar sizes
        array set ratios {}
        array set sticky {}

        # Set ratios for the windows that span 1 column/row.
        foreach dim $worklist {
            foreach w $dim {
                if {[$w cget $spankey] > 1} {
	            continue
                }
                set s [lindex [$w cget -slot] $slotoffset]
                set ratio [expr {[$w cget -$reqdim] * 100 / $psize}]
                if {[lsearch -exact [$w cget -sticky] $wdir] >= 0} {
                    set sticky($s) 1
                }
                if {![info exists ratios($s)] || $ratio > $ratios($s)} {
                    set ratios($s) $ratio 
                }
            }
        }

        # Now handle the multiple span windows.
        foreach dim $worklist {
            foreach w $dim {
                if {[$w cget $spankey] == 1} {
		    continue
	        }
                set s [lindex [$w cget -slot] $slotoffset]
                set es [expr {$s + [$w cget $spankey]}]
                set st [expr {[lsearch -exact [$w cget -sticky] $wdir] >= 0}]
                for {set i $s} {$i < $es} {incr i} {
                    if {![info exists ratios($i)]} {
                        set wratio [expr {[$w cget $reqdim] * 100 / $psize}]
                        for {set subi $s} {$subi < $es} {incr subi} {
                            if {[info exists ratios($subi)]} {
                                set wratio [expr {$wratio - $ratios($subi)}]
                            }
                        }
                        set wratio [expr {($wratio > 0) ? $wratio : 0}]
                        set ratios($i) $wratio
                    } 
                    if {$st} {
                        set sticky($i) 1
                    }
                }
            }
        }
        set totalcells [llength [array names ratios]]
        if {$totalcells <= 0} {
	    return
        }
        set totalratio [sumRatios ratios]

        if {$totalratio > 100} {
            # The widgets will all have to be bumped down in ratio.
            # This means that sticky width/height has no effect.
            set bump [expr {($totalratio - 100) / $totalcells}]
            foreach key [array names ratios] {
                set ratios($key) [expr {$ratios($key) - $bump}]
            }
        } else {
            set nonstickyratio 0
            set stickyratio 0
            foreach {i value} [array get ratios] {
                if {![info exists sticky($i)]} {
                    incr nonstickyratio $value
                } else {
                    incr stickyratio $value
                }
            }
            set fillcells [llength [array names sticky]]
            if {$fillcells > 0} {
                set ratiodelta [expr {100 - $nonstickyratio - $stickyratio}]
                set bump [expr {$ratiodelta / $fillcells}]
                foreach i [array names sticky] {
                    set ratios($i) [expr {$ratios($i) + $bump}]
                }
            }  
        }
        # Now calculate the size for each cell.
        foreach i [array names ratios] {
             set sizes($i) [expr {$ratios($i) * $psize / 100}]
        }

        #Set the size for this dimension of the widget.
        foreach dim $worklist {
            foreach w $dim {
                set s [lindex [$w cget -slot] $slotoffset]
                set es [expr {$s + [$w cget $spankey]}]
                set totalsize 0
                for {set i $s} {$i < $es} {incr i} {
                    incr totalsize $sizes($i)
                }
                if {$totalsize <= 0} {
                    set totalsize 1
                }
                $w configure -$wdir $totalsize
            }
        }
    }

    protected proc layoutXy {grid xsizesvar ysizesvar} {
        upvar $xsizesvar xsizes
        upvar $ysizesvar ysizes

        foreach row $grid {
            foreach cells $row {
                foreach w $cells {
                    if {$w eq ""} {
		        continue
                    }
                    lassign [$w cget -slot] xslot yslot
                    set x 0
		    set y 0
                    for {set xi 0} {$xi < $xslot} {incr xi} {
                        if {[info exists xsizes($xi)]} {
			    incr x $xsizes($xi)
			}
                    }
                    for {set yi 0} {$yi < $yslot} {incr yi} {
                        if {[info exists ysizes($yi)]} {
			    incr y $ysizes($yi)
			}
                    }
                    $w configure -x $x -y $y
                }
            }   
        }
    }

    protected proc listSet {list_var i value} {
        upvar $list_var list

        if {[llength $list] >= $i} {
            lappend list $value
        } else {
            lset list $i $value
        }
    }

    protected proc redraw {grid} {
        foreach row $grid {
            foreach cells $row {
                foreach w $cells {
                    #Resize the backing megaimage obj.
                    [$w obj] setsize [$w cget -width] [$w cget -height]
                    #Trigger a redraw of the widget.
                    $w dispatchRedraw $w
                }
            }
        }
    }

    protected proc relayoutTrace {w} {
        layout [$w parent]
    }

    protected proc remove {w} {
        set m [[$w parent] manager]
        set grid [$m grid]
        removeWidget grid $w
        layout [$w parent]
    }

    protected proc removeWidget {gridvar w} {
        upvar $gridvar grid

        lassign [$w cget -slot] c r
        set row [lindex $grid $r]
        set cells [lindex $row $c]
        set i [lsearch -exact $cells $w]
        if {$i >= 0} {
            set cells [lreplace $cells $i $i]
        }
        lset row $c $cells
        lset grid $r $row 
    }

    protected proc rmList {list slot span} {
        for {set i 0} {$i < $span} {incr i} {
            set e [lsearch -exact $list [expr {$slot + $i}]]
            if {$e < 0} {
                continue
            }
            set list [lreplace $list $e $e]
        }
        return $list
    }

    protected proc setPeak {m peaktype peak} {
        if {$peak > [$m $peaktype]} {
            $m $peaktype $peak
        }
    }

    protected proc slotCallback {w arg} {
        if {[llength $arg] != 2} {
            return -code error "invalid list length (should be 2): $arg"
        }
        lassign $arg c r
        if {![string is integer -strict $c]} {
            return -code error "invalid column for slot (not an integer): $c"
        }
        if {![string is integer -strict $r]} {
            return -code error "invalid row for slot (not an integer): $r"
        }
        set p [$w parent]
        set grid [[$p manager] getGridValue grid]

        removeWidget grid $w
        insertWidget grid $w $c $r
 
        [$p manager] grid $grid
 
        #
        # There is a -slot trace, so when this completes successfully,
        # relayoutTrace will be evaluated.
        #
        return 1
    }

    protected proc spanCallback {w arg} {
        if {![string is integer -strict $arg]} {
            return -code error "invalid argument (not an integer): $arg"
        }
        if {$arg <= 0} {
            return -code error "invalid span: $arg"
        }
        return 1
    }

    protected proc stickyCallback {w arg} {
        foreach i $arg {
            if {"width" ne $i && "height" ne $i} {
                return -code error "invalid -sticky list item (should be width or height): $i"
            }
        }
        return 1
    }

    protected proc isSticky {w arg} {
        return [expr {[lsearch -exact [$w cget -sticky] $arg] >= 0}]
    }

    protected proc sumRatios {arname} {
        upvar $arname ar

        set s 0
        foreach {key value} [array get ar] {
            incr s $value
        }
        return $s
    }

    public proc grid {path args} {
        # See if the parent has a manager object already.
        # Create a new grid manager object if there isn't one already.
        set p [$path parent]
        if {[$p manager] eq ""} {
	    set m [::ntk::classes::gridManager m$p $p]
            $p manager $m 
        }
        # Unlock and initialize the grid data for the window.
	set m2 [::ntk::classes::gridManager m$path $path]
        $path configure -sticky [list] -columnspan 1 -rowspan 1 \
                 -slot [list 0 0] -columnratio 0 -rowratio 0 
        $path removeFromManager gridRemove

        #XXX we should relayout even if the {*} and eval fail.
        if {[llength $args]} {
            if {[catch {$w {*}$args} err]} {
                 destroyWindow $w
                 return -code error $err
            }
        }

        # Get the manager and set the peaks.
        set m [[$path parent] manager]
        lassign [$path cget -slot] c r
        setPeak $m peakrow [expr {$r + [$path cget -rowspan]}]
        setPeak $m peakcolumn [expr {$c + [$path cget -columnspan]}]
        # Get the grid prior to insertion from the parent.
        set grid [$m grid]
        insertWidget grid $path $c $r

        # Set the new grid list.
        $m grid $grid
        layout [$path parent]

        # Create the callbacks, now that the widget members have been initialized.
if {0} {
        structure-key-callback $path -sticky [list NS__grid-sticky-callback $path]
        structure-key-callback $path -columnspan [list NS__grid-span-callback $path]
        structure-key-callback $path -rowspan [list NS__grid-span-callback $path]
        structure-key-callback $path -slot [list NS__grid-slot-callback $path]

        foreach key [list -sticky -columnspan -rowspan -slot] {
             structure-trace-key $path $key [list NS__grid-relayout-trace $path]
        }
}
dump $grid
dumpSizes $grid
        return $path
    }
}
