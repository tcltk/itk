itcl::nwidget ::ntk::classes::grid {
    component gridBase
    delegate getGridValue to gridBase
    delegate setGridValue to gridBase

    constructor {w args} {
        set gridBase [::ntk::classes::gridBase [::itcl::scope $this layout] [::itcl::scope $this free] [::itcl::scope $this remove] 0 0]
    }

    protected method dump {} {
        puts stderr "BEGIN DUMP"
	set i 0
	foreach row [getGridValue grid] {
	    puts stderr "$i -> $row"
	    incr i
	}
	puts stderr "END DUMP"
    }

    protected method dumpSizes {} {
        foreach row [getGridValue grid] {
	    foreach cells $row {
	        foreach w $cells {
		    puts -nonewline stderr "$w is +[$w configure -x]+[$w configure -y][[$w configure -width]x[$w configure -height] \[[$w configure -slot]\]\t"
		}
	    }
	    put stderr ""
	}
    }

    protected method free {managerobj} {
        uplevel 0 [getGridValue free] $managerobj
    }

    protected method getVisible {columnsVar rowsVar} {
        # 
	# find the number of visible columns
	#
	set r 0
	foreach row [getGridValue grid] {
	    set c 0
	    foreach w $row {
	        if {$w eq ""} {
		    incr c
		    continue
		}
		for {set i 0} {$i < [$w configure -columnspan]} {incr i} {
		    lappend columns [expr {$c + $i}]
		}
		for {set i 0} {$i < [$w configure -rowspan]} {incr i} {
		    lappend rows [expr {$r + $i}]
		}
                incr c
	    }
	    incr r
	}
    }

    protected method insertWidget {gridVar w c r} {
	set grid [getGridValue grid]
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

    protected method integerCallback {w arg} {
        if {![string is integer -strict $arg]} {
            return -code error "invalid argument (not an integer): $arg"
        }
        return 1
    }

    protected method layout {parent} {
        set m [$parent configure -manager]
        set grid [$m getGridValue grid]
        set pwidth [$parent configure -width]
        set pheight [$parent configure -height]
        if {$pwidth <= 0 || $pheight <= 0} {
	    return
        }
        set cwork [list]
        for {set c 0} {$c < [$m peakcolumn]} {incr c} {
            set col [list]
            for {set r 0} {$r < [$m peakrow]} {incr r} {
                set cells [lindex $grid $r $c]
                if {![llength $cells]} {
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
                 if {![llength $cells]} {
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
dumpSizes

        redraw
    }

    protected method layoutDirection {worklist spankey reqdim wdir psize slotoffset sizesvar} {
        upvar $sizesvar sizes
        array set ratios {}
        array set sticky {}

        # Set ratios for the windows that span 1 column/row.
        foreach dim $worklist {
            foreach w $dim {
                if {[$w $spankey] > 1} {
	            continue
                }
                set s [lindex [$w configure -slot] $slotoffset]
                set ratio [expr {[$w configure $reqdim] * 100 / $psize}]
                if {[lsearch -exact [$w -sticky] $wdir] >= 0} {
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
                if {1 == [$w $spankey]} {
		    continue
	        }
                set s [lindex [$w configure -slot] $slotoffset]
                set es [expr {$s + [$w $spankey]}]
                set st [expr {[lsearch -exact [$w configure -sticky] $wdir] >= 0}]
                for {set i $s} {$i < $es} {incr i} {
                    if {![info exists ratios($i)]} {
                        set wratio [expr {[$w configure $reqdim] * 100 / $psize}]
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
                set s [lindex [$w configure -slot] $slotoffset]
                set es [expr {$s + [$w configure $spankey]}]
                set totalsize 0
                for {set i $s} {$i < $es} {incr i} {
                    incr totalsize $sizes($i)
                }
                if {$totalsize <= 0} {
                    set totalsize 1
                }
                $w $wdir $totalsize
            }
        }
    }

    protected method layoutXy {xsizesvar ysizesvar} {
 upvar $xsizesvar xsizes
 upvar $ysizesvar ysizes

        foreach row $grid {
            foreach cells $row {
                foreach w $cells {
                    if {$w eq ""} {
		        continue
                    }
                    lassign [$w configure-slot] xslot yslot
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
                    $w x $x y $y
                }
            }   
        }
    }

    protected method listSet {list_var i value} {
 upvar $list_var list

        if {[llength $list] >= $i} {
            lappend list $value
        } else {
            lset list $i $value
        }
    }

    protected method redraw {} {
        foreach row [getGridValue grid] {
            foreach cells $row {
                foreach w $cells {
                    #Resize the backing megaimage obj.
                    [$w obj] setsize [$w configure -width] [$w configure -height]
                    #Trigger a redraw of the widget.
                    redraw $w
                }
            }
        }
    }

    protected method relayoutTrace {w} {
        layout [$w configure -parent]
    }

    protected method remove {w} {
        set m [[$w configure -parent] configure -manager]
        set grid [$m getGridValue grid]
        removeWidget grid $w
        layout [$w configure -parent]
    }

    protected method removeWidget {gridvar w} {
 upvar $gridvar grid
        lassign [$w configure -slot] c r
        set row [lindex $grid $r]
        set cells [lindex $row $c]
        set i [lsearch -exact $cells $w]
        if {$i >= 0} {
            set cells [lreplace $cells $i $i]
        }
        lset row $c $cells
        lset grid $r $row 
    }

    protected method rmList {list slot span} {
        for {set i 0} {$i < $span} {incr i} {
            set e [lsearch -exact $list [expr {$slot + $i}]]
            if {$e < 0} {
                continue
            }
            set list [lreplace $list $e $e]
        }
        return $list
    }

    protected method setPeak {m peaktype peak} {
        if {$peak > [$m configire -$peaktype]} {
            $m $peaktype $peak
        }
    }

    protected method slotCallback {w arg} {
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
        set p [$w configure -parent]
        set grid [[$p configure -manager] getGridValue grid]

        removeWidget grid $w
        insertWidget grid $w $c $r
 
        [$p configure -manager] grid $grid
 
        #
        # There is a -slot trace, so when this completes successfully,
        # relayoutTrace will be evaluated.
        #
        return 1
    }

    protected method spanCallback {w arg} {
        if {![string is integer -strict $arg]} {
            return -code error "invalid argument (not an integer): $arg"
        }
        if {$arg <= 0} {
            return -code error "invalid span: $arg"
        }
        return 1
    }

    protected method stickyCallback {w arg} {
        foreach i $arg {
            if {"width" ne $i && "height" ne $i} {
                return -code error "invalid -sticky list item (should be width or height): $i"
            }
        }
        return 1
    }

    protected method isSticky {w arg} {
        return [expr {[lsearch -exact [$w configure -sticky] $arg] >= 0}]
    }

    protected method sumRatios {arname} {
 upvar $arname ar
        set s 0
        foreach {key value} [array get ar] {
            incr s $value
        }
        return $s
    }

    protected method grid {w args} {
        # See if the parent has a manager object already.
        # Create a new grid manager object if there isn't one already.
        set p [$w configure -parent]
        if {[$p configure -manager] eq ""} {
         set m [structure]
         $m \
           grid [list] \
           remanage gridLayout  \
           peakrow 0 \
           peakcolumn 0 \
           free NS__grid-free
       
         $p _manager $m 
        }
        # Unlock and initialize the grid data for the window.
 $w \
   -sticky {} \
   -columnspan 1 \
   -rowspan 1 \
   -slot [list 0 0] \
   -columnratio 0 \
   -rowratio 0 \
   _remove-from-manager NS__grid-remove

        #XXX we should relayout even if the {*} and eval fail.
        if {[llength $args]} {
            if {[catch {$w {*}$args} err]} {
                 destroyWindow $w
                 return -code error $err
            }
        }

        # Get the manager and set the peaks.
        set m [[$w configure -parent] configure -manager]
        lassign [$w configure -slot] c r
        setPeak $m peakrow [expr {$r + [$w configure -rowspan]}]
        setPeak $m peakcolumn [expr {$c + [$w configure -columnspan]}]
        # Get the grid prior to insertion from the parent.
        set grid [$m getGridValue grid]
        insertWidget grid $w $c $r

        # Set the new grid list.
        $m grid $grid
        layout [$w configure -parent]

        # Create the callbacks, now that the widget members have been initialized.
        structure-key-callback $w -sticky [list NS__grid-sticky-callback $w]
        structure-key-callback $w -columnspan [list NS__grid-span-callback $w]
        structure-key-callback $w -rowspan [list NS__grid-span-callback $w]
        structure-key-callback $w -slot [list NS__grid-slot-callback $w]

        foreach key [list -sticky -columnspan -rowspan -slot] {
         structure-trace-key $w $key [list NS__grid-relayout-trace $w]
        }

dump
dumpSizes
        return $w
    }
}
