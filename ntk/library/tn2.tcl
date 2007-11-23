package require Itcl 4.0
package require freetypeext
#package require ntk
lappend auto_path .
package require ntkWidget

proc eval_stdin {} {
    set cmd [gets stdin]
    catch {uplevel #0 $cmd} result
    puts $result
    puts -nonewline "% "
    flush stdout
}

if {0} {
proc ::callback {args} {
puts stderr "callback!$args!"
}
foreach c [info commands] { trace add execution $c enter [list ::callback $c] }
}

set width 800
set height 600
set configure_pending 0

proc dotConfigure {winid x y width height} {
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
set top [ntk toplevel . -width $width -height $height]
. id $id

ntk-create-event-handler $id [list ntk keyPress .] \
       [list ntk keyRelease .] [list ntk motion .] \
       [list ntk mousePress .] [list ntk mouseRelease .] \
       [list dotConfigure .]

ntk-move-sys-window $id 200 200
ntk-map-sys-window $id


set topObj [$top obj]

if {1} {
set w2Path [ntk frame .w2 -width 100 -height 100]
puts stderr "w2Path!$w2Path!"
after 2000 "[list $w2Path configure -bg [list 155 0 0 255]]"
after 6000 "[list $w2Path configure -bg [list 255 0 0 255]]"
}

if {1} {
set w3Path [ntk frame .w3 -width 200 -height 200]
puts stderr "w3Path!$w3Path!"
.w3 configure -bg [list 255 150 150 255] -x 180 -y 150
}

set ::numbucalls 0
proc bucmd {args} {
    incr ::numbucalls
puts stderr "bucmd called!$args!$::numbucalls"
    .w4 configure -text buttonpress$::numbucalls
}
if {1} {
set w4Path [ntk button .w4 -rotate 30 -width 100 -height 20 -text buttonpress0 -textcolor [list 255 0 0 255] -bg [list 199 234 0 255] -bd 2 -command bucmd]
$w4Path x 0
$w4Path y 350
$w4Path render $w4Path
puts stderr "w4Path!$w4Path!x![$w4Path x]![$w4Path y]!"
}

if {1} {
set w5Path [ntk label .w5 -width 100 -height 100 -x 470 -y 50 -text label1 -textcolor [list 255 0 0 255] -bg [list 123 234 150 255] -bd 2]
#$w5Path x 470
#$w5Path y 50
#$w5Path render $w5Path
puts stderr "w5Path!$w5Path!"
}

if {1} {
set w6Path [ntk entry .w6 -width 150 -height 40 -x 600 -y 50 -text entry1 -textcolor [list 255 0 0 255] -bg [list 199 234 0 255] -bd 4]
#$w6Path x 600
#$w6Path y 50
#$w6Path render $w6Path
puts stderr "w6Path!$w6Path!"
}

if {1} {
set w7Path [ntk text .w7 -width 300 -height 150 -x 60 -y 200 -textcolor [list 255 0 0 255] -bg [list 199 234 0 255] -bd 4]
$w7Path configure -insert [list 1.0 0 "hello world\nHello Arnulf\nThird line is a bit longer"]
#$w7Path x 600
#$w7Path y 50
#$w7Path configure -width 250
#$w7Path render $w7Path
puts stderr "w7Path!$w7Path!"
}

puts stderr "setting eval-stdin"
fileevent stdin readable eval_stdin
vwait forever
puts stderr "END !!!"
