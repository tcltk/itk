lappend auto_path .
package require TclGLFW
package require TclGL
package require megaimage

source tg_util.tcl

set myObj [megaimage-blank 30 30]
set data [$myObj getdata]

set lst1 [list]
foreach i {1 2 3 4 5 6 7 8 9 10} {
    lappend lst1 [list 125 0 125 125]
    lappend lst1 [list 125 0 125 125]
    lappend lst1 [list 125 0 125 125]
    lappend lst1 [list 200 0 125 255]
    lappend lst1 [list 200 0 125 255]
}
set lst [list]
foreach i {1 2 3 4 5 6 7 8 9 10} {
    lappend lst $lst1
    lappend lst $lst1
    lappend lst $lst1
    lappend lst $lst1
    lappend lst $lst1
}

set win [::ntk::glfw::GLFW openWindow 500 400]
::ntk::glfw::GLFW setWindowTitle "Hallo Arnulf"
tgInit $win

proc Draw {} {
    upvar lst lst
    upvar data data

    ::ntk::gl::GL glClearColor 0.25 0.0 0.0 0.0
    ::ntk::gl::GL glClear GL_COLOR_BUFFER_BIT
    ::ntk::glfw::GLFW glDrawPixels 50 50 $lst
    ::ntk::glfw::GLFW drawMegaimage $data
    ::ntk::glfw::GLFW swapBuffers
    ::ntk::gl::GL glFlush
    set isOpened [::ntk::glfw::GLFW getWindowParam GLFW_OPENED]
    if {!$isOpened} {
        ::ntk::glfw::GLFW terminate
        exit 0
    }
}

Draw
WaitEvents

set xx 1
vwait xx
::ntk::glfw::GLFW terminate
exit 0
