package require TclGL
package require GlmwfwX11
package require Glmwfw

source ntkWidget.tcl

source tg_util.tcl

proc init {} {
#    ::ntk::glmwfw::Glmwfw setWindowSize $::win 500 300
    ::ntk::gl::GL glClearColor 0.55 0.55 0.55 0.0
}

proc display {win} {
    ::ntk::gl::GL glClear GL_COLOR_BUFFER_BIT
    ::ntk::gl::GL glColor3f 0.75 0.0 0.0
    ::ntk::glmwfw::Glmwfw swapBuffers $win
}

set win [::ntk::glmwfw::Glmwfw openWindow 500 400]
::ntk::glmwfw::Glmwfw setWindowTitle $win "ntkWidget demo"
source tg_util.tcl
tgInit $win

init

display $win

    set widget [ntkWidget wgt -width 400 -height 200]
    $widget fill [list 0 255 0 255]
    $widget line 5 5 115 115 [list 195 0 0 0]
    $widget line 5 5 195 60 [list 195 0 0 0]
    set widget2 [ntkWidget wgt2 -width 20 -height 20]
    $widget2 fill [list 0 0 255 125]
    $widget2 rotate 10
    set data2 [$widget2 getdata]
puts stderr "size![$widget2 getsize]!"
    $widget blendwidget 50 50 [$widget2 widget]
    set data [$widget getdata]
    ::ntk::glmwfw::Glmwfw drawPixels2 400 200 $data
    ::ntk::glmwfw::Glmwfw swapBuffers $win

set xx 1
vwait xx
after cancel $::afterWaitId
::ntk::glmwfw::Glmwfw terminate
exit 0
