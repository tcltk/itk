lappend auto_path .
package require TclGL
package require TclGLFW

source tg_util.tcl

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

if {0} {
    set modes [::ntk::glfw::GLFW getVideoModes]
    puts stderr "modes![join $modes \n]!"
    set dmode [::ntk::glfw::GLFW getDesktopMode]
    puts stderr "dmode!$dmode!"
}

proc Draw {} {
    upvar lst lst

    ::ntk::gl::GL glClearColor 0.25 0.0 0.0 0.0
    ::ntk::gl::GL glClear GL_COLOR_BUFFER_BIT
    ::ntk::glfw::GLFW glDrawPixels 50 50 $lst
    ::ntk::glfw::GLFW swapBuffers
    ::ntk::gl::GL glFlush
}

Draw
WaitEvents

set xx 1
vwait xx
after cancel $::afterWaitId
::ntk::glfw::GLFW terminate
exit 0
