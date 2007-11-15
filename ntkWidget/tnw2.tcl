package require GlmwfwX11
package require Glmwfw

source ntkWidget.tcl

source tg_util.tcl

proc init {} {
}

proc display {win} {
    set widget [ntkWidget wgt -width 400 -height 200]
    $widget fill [list 0 255 0 255]
#    $widget line 5 5 115 115 [list 195 0 0 0]
    $widget line 5 5 95 60 [list 195 0 0 0]
    set data [$widget getdata]
    ::ntk::glmwfw::Glmwfw drawPixels2 400 200 $data
    ::ntk::glmwfw::Glmwfw swapBuffers $win
}

set win [::ntk::glmwfw::Glmwfw openWindow 500 400]
::ntk::glmwfw::Glmwfw setWindowTitle $win "ntkWidget demo"
source tg_util.tcl
tgInit $win

init

display $win

set xx 1
vwait xx
after cancel $::afterWaitId
::ntk::glmwfw::Glmwfw terminate
exit 0
