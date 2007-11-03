package require TclGL
package require GlmwfwX11
package require Glmwfw

proc drawOneLine {x1 y1 x2 y2} {
#puts stderr "Drawline!$x1!$y1!$x2!$y2!"
    ::ntk::gl::GL glBegin GL_LINES
    ::ntk::gl::GL glVertex3f $x1 $y1 0.0
    ::ntk::gl::GL glVertex3f $x2 $y2 0.0
    ::ntk::gl::GL glEnd
}

proc init {} {
    ::ntk::gl::GL glClearColor 0.55 0.55 0.55 0.0
    ::ntk::gl::GL glShadeModel GL_FLAT
}

proc display {win} {
    ::ntk::gl::GL glColor3f 75.0 0.0 0.0
    ::ntk::gl::GL glOrtho 0.0 1.0 0.0 1.0 -1.0 1.0

    drawOneLine 0.25 0.1 0.75 0.1
    drawOneLine 0.25 0.11 0.75 0.11
    drawOneLine 0.25 0.12 0.75 0.12
    drawOneLine 0.25 0.13 0.75 0.13
    ::ntk::gl::GL glFlush
    ::ntk::glmwfw::Glmwfw swapBuffers $win 
}

::ntk::glmwfw::Glmwfw init
set win [::ntk::glmwfw::Glmwfw openWindow 500 400]
::ntk::glmwfw::Glmwfw setWindowTitle $win "Hallo Arnulf"
source tg_util.tcl
tgInit $win

init

display $win
WaitEvents $win

set xx 1
vwait xx
after cancel $::afterWaitId
::ntk::glmwfw::Glmwfw terminate
exit 0
