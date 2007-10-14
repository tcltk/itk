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

set width 800
set height 600
set configure_pending 0

proc topConfigure {winid x y width height} {
puts stderr "global configure called"
    global configure configure_pending

    if {$width == [. cget -width] && $height == [. cget -height]} {
        return
    }
    set configure [list $width $height]
    if {$configure_pending} {
        return
    }
    set configure_pending 1
    after idle [list configureNow $winid]
}

proc configureNow {winid} {
puts stderr "global configureNow called"
    global configure configure_pending

    lassign $configure width height
    set obj [. obj]
    $obj setsize $width $height
    . configure -width $width -height $height
    set rat [expr {$width / 7.0}]
    ntk_request-size .left [expr {int($rat)}] $height
    ntk_request-size .right [expr {round($rat * 6)}] $height
    set configure_pending 0
}

set id [ntk-create-sys-window $width $height]
ntk-set-title $id "ntkWidget Demo"

puts stderr "TOP"
set top [ntk toplevel .  -width $width -height $height -bg [list [list 255 255 255 0]]]
. id $id

ntk-create-event-handler $id [list ntk keyPress .] \
       [list ntk keyRelease .] [list ntk motion .] \
       [list ntk mousePress .] [list ntk mouseRelease .] \
       [list topConfigure .]

ntk-move-sys-window $id 200 200
ntk-map-sys-window $id


set topObj [$top obj]

::itcl::eclass geo {
    public option -sticky -default nswe 
}
geo geo1

set w2Path [ntk button .w2 -width 100 -height 100 -x 50 -y 50 -text arnulf -textcolor [list [list 0 0 0 255]] -bd 2 -bg [list [list 255 255 255 255]]]
puts stderr "w2Path!$w2Path![$w2Path obj]!"
set xx [::ntk::classes::gridManager gd1 $w2Path]
puts stderr "XX!$xx!"
if {0} {
::itcl::setcomponent $w2Path geometryManager geo1
set compInfo [$w2Path info component geometryManager]
set compClass [namespace qualifiers [lindex $compInfo 0]]
puts stderr "compClass!$compClass!"
::itcl::adddelegatedoption $w2Path delegate option -sticky to geometryManager
}
puts stderr "COLUMNSPAN![$w2Path cget -columnspan]!"
puts stderr "PEAKCOLUMN![$w2Path peakcolumn]!"
#[$w2Path obj] line 5 5 80 5 [list 255 0 0 255]
#[$w2Path obj] line 5 6 80 6 [list 0 0 0 0]
#$w2Path render $w2Path

puts stderr "setting eval-stdin"
fileevent stdin readable eval_stdin
vwait forever
puts stderr "END !!!"
