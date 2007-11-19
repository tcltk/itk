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
#    $widget line 5 5 115 115 [list 195 0 0 0]
#    $widget line 5 5 195 60 [list 195 0 0 0]
if {0} {
    set widget2 [ntkWidget wgt2 -width 20 -height 20]
    $widget2 fill [list 0 0 255 255]
    set widget2a [ntkWidget wgt2a -width 2 -height 20]
    $widget2a fill [list 255 0 0 255]
    $widget2 blendwidget 18 0 [$widget2a widget]
    $widget2 rotate 22
    set data2 [$widget2 getdata]
#puts stderr "size![$widget2 getsize]!"
#    $widget blendwidget 50 50 [$widget2 widget]
    $widget blendwidget 0 0 [$widget2 widget]
}
    set widget3 [ntkWidget wgt3 -width 20 -height 20]
    $widget3 createText Vera.ttf 14 "Arnulf geht jetzt" [list 0 0 0 255] w h
    set widget3b [ntkWidget wgt3b -width 2 -height 19]
    $widget3b fill [list 255 0 0 255]
    set widget3a [ntkWidget wgt3a -width 229 -height 1]
    $widget3a fill [list 255 0 0 255]
#    $widget3 createText Vera.ttf 14 "Arnulf" [list 0 0 0 255] w h
    $widget3 blendwidget 0 0 [$widget3a widget]
    $widget3 rotate -22
    $widget blendwidget 0 0 [$widget3 widget]
    $widget blendwidget 113 0 [$widget3b widget]
    set data [$widget getdata]
#    set data [$widget3 getdata]
    ::ntk::glmwfw::Glmwfw drawPixels2 400 200 $data
#    ::ntk::glmwfw::Glmwfw drawPixels2 232 41 $data
    ::ntk::glmwfw::Glmwfw swapBuffers $win

set xx 1
vwait xx
after cancel $::afterWaitId
::ntk::glmwfw::Glmwfw terminate
exit 0
