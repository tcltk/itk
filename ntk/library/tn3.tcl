package require Itcl 4.0
source ntk.tcl
lappend auto_path .
package require ntkWidgetImage

proc eval_stdin {} {
    set cmd [gets stdin]
    catch {uplevel #0 $cmd} result
    puts $result
    puts -nonewline "% "
    flush stdout
}

set width 800
set height 600

set win [::ntk::glmwfw::Glmwfw openWindow $width $height]
::ntk::glmwfw::Glmwfw setWindowTitle $win "NtkWidget Demo"
set top [ntk toplevel .  -width $width -height $height -bg [list 0 255 0 0]]
. id $win
puts stderr "TOP DONE"
source tg_util.tcl
tgInit $win

#ntk-create-event-handler $id [list ntk keyPress .] \
#       [list ntk keyRelease .] [list ntk motion .] \
#       [list ntk mousePress .] [list ntk mouseRelease .] \
#       [list topConfigure .]

#ntk-move-sys-window $id 200 200
#ntk-map-sys-window $id

set w2Path [ntk button .w2 -width 100 -xoffset 50 -yoffset 50 -height 100 -text arnulf -textcolor [list 0 0 0 255] -bd 2 -bg [list 255 255 255 255]]

puts stderr "w2Path!$w2Path![$w2Path windowImage]!"
if {0} {
set xx [::ntk::classes::gridManager gd1 $w2Path]
puts stderr "XX!$xx!"
puts stderr "COLUMNSPAN![$w2Path configure -columnspan 2]!"
puts stderr "COLUMNSPAN![$w2Path cget -columnspan]!"
puts stderr "PEAKCOLUMN![$w2Path peakcolumn]!"
}
ntk grid $w2Path
puts stderr "setting eval-stdin"
fileevent stdin readable eval_stdin
vwait forever
puts stderr "END !!!"
