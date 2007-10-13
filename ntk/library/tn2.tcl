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

proc ntkInputKeyPress {args} {
#    puts stderr "ntkInputKeyPress called!$args!"
    ::ntk::classes::input::inputKeyPress {*}$args
}

proc ntkInputKeyRelease {args} {
#    puts stderr "ntkInputKeyRelease called!$args!"
    ::ntk::classes::input::inputKeyRelease {*}$args
}

proc ntkInputMousePress {args} {
#    puts stderr "ntkInputMousePress called!$args!"
    ::ntk::classes::input::inputMousePress {*}$args
}

proc ntkInputMouseRelease {args} {
#    puts stderr "ntkInputMouseRelease called!$args!"
    ::ntk::classes::input::inputMouseRelease {*}$args
}

proc ntkInputMotion {args} {
    puts stderr "ntkInputMotion called!$args!"
    ::ntk::classes::input::inputMotion {*}$args
}

set id [ntk-create-sys-window $width $height]
ntk-set-title $id "ntkWidget Demo"

puts stderr "TOP"
set top [ntk toplevel . -width $width -height $height]
. id $id

ntk-create-event-handler $id [list ntkInputKeyPress .] \
       [list ntkInputKeyRelease .] [list ntkInputMotion .] \
       [list ntkInputMousePress .] [list ntkInputMouseRelease .] \
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

proc bucmd {args} {
puts stderr "bucmd called!$args!"
}
if {1} {
set w4Path [ntk button .w4 -width 100 -height 20 -x 0 -y 350 -text button1 -textcolor [list [list 255 0 0 255]] -bg [list [list 199 234 0 255]] -bd 2 -command bucmd]
puts stderr "w4Path!$w4Path!"
}

if {1} {
set w5Path [ntk label .w5 -width 100 -height 100 -x 470 -y 50 -text label1 -textcolor [list [list 255 0 0 255]] -bg [list [list 123 234 150 255]] -bd 2]
puts stderr "w5Path!$w5Path!"
}

if {1} {
set w6Path [ntk entry .w6 -width 150 -height 40 -x 600 -y 50 -text entry1 -textcolor [list [list 255 0 0 255]] -bg [list [list 199 234 0 255]] -bd 4]
puts stderr "w6Path!$w6Path!"
}



puts stderr "setting eval-stdin"
fileevent stdin readable eval_stdin
vwait forever
puts stderr "END !!!"
