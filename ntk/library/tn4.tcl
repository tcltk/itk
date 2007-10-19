package require Itcl 4.0
package require megaimage
package require freetypeext
package require ntk
lappend auto_path .
package require ntkWidget

proc eval_stdin {} {
    set cmd [gets stdin]
    catch {uplevel #0 $cmd} result
    puts $result
    puts -nonewline "% "
    flush stdout
}

set wdth 800
set hght 600
set configure_pending 0

proc topConfigure {winid x y width height} {
puts stderr "global configure called"
    global cfg configure_pending

    if {$width == [. cget -width] && $height == [. cget -height]} {
        return
    }
    set cfg [list $width $height]
    if {$configure_pending} {
        return
    }
    set configure_pending 1
    after idle [list configureNow $winid]
}

proc configureNow {winid} {
puts stderr "global configureNow called"
    global cfg configure_pending

    lassign $cfg w h
    set obj [. obj]
    $obj setsize $w $h
    . configure -width $w -height $h
    set rat [expr {$width / 7.0}]
    ntk_request-size .left [expr {int($rat)}] $h
    ntk_request-size .right [expr {round($rat * 6)}] $h
    set configure_pending 0
}

set id [ntk-create-sys-window $wdth $hght]
ntk-set-title $id "ntkWidget Demo"

puts stderr "TOP"
set top [ntk toplevel .  -width $wdth -height $hght -bg [list 255 255 255 0]]
. id $id

puts stderr "TOP DONE"
ntk-create-event-handler $id [list ntk keyPress .] \
       [list ntk keyRelease .] [list ntk motion .] \
       [list ntk mousePress .] [list ntk mouseRelease .] \
       [list topConfigure .]

ntk-move-sys-window $id 200 200
ntk-map-sys-window $id


set topObj [$top obj]

if {1} {
set w8Path [ntk listbox .w8 -width 100 -height 100 -x 50 -y 50 -textcolor [list 0 0 0 255] -bd 2 -bg [list 255 255 255 255]]
puts stderr "w8Path!$w8Path![$w8Path obj]!"
$w8Path insert 0 hallo arnulf apple orange
}
if {1} {
set w9Path [ntk scrollbar .w9 -width 100 -height 100 -x 250 -y 50 -textcolor [list 0 0 0 255] -bd 2 -bg [list 255 255 255 255]]
puts stderr "w9Path!$w9Path![$w9Path obj]!"
}

if {1} {
set w10Path [ntk clock .w10 -width 200 -height 200 -x 50 -y 250 -bd 2 -bg [list 255 255 255 255]]
puts stderr "w10Path!$w10Path![$w10Path obj]!"
}

puts stderr "setting eval-stdin"
fileevent stdin readable eval_stdin
vwait forever
}
puts stderr "END !!!"
