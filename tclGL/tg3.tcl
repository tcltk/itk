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
    ::ntk::gl::GL glColor3f 0.75 0.0 0.0
#    ::ntk::gl::GL glClear GL_COLOR_BUFFER_BIT
    ::ntk::gl::GL glColor3f 1.0 1.0 1.0
    ::ntk::gl::GL glEnable GL_LINE_STIPPLE

    ::ntk::gl::GL glLineStipple 1 0x0101
    drawOneLine 0.50 0.25 0.75 0.25
    ::ntk::gl::GL glLineStipple 1 0x00ff
    drawOneLine 0.25 0.25 0.55 0.25
    ::ntk::gl::GL glLineStipple 1 0x1c47
    drawOneLine 0.75 0.25 0.95 0.25
    ::ntk::gl::GL glDisable GL_LINE_STIPPLE
    ::ntk::gl::GL glFlush
    ::ntk::glmwfw::Glmwfw swapBuffers $win 
}

proc _reshape {w h} {
    ::ntk::gl::GL glViewport 0 0 $w $h
    ::ntk::gl::GL glMatrixMode GL_PROJECTION
    ::ntk::gl::GL glLoadIdentity
}

::ntk::glmwfw::Glmwfw init
set win [::ntk::glmwfw::Glmwfw openWindow 500 400]
::ntk::glmwfw::Glmwfw setWindowTitle $win "Hallo Arnulf"
source tg3_inc.tcl
#tgInit $win

init

proc Draw {win} {
    upvar lst lst
    upvar data data

#    ::ntk::gl::GL glClearColor 0.55 0.55 0.55 0.0
#    ::ntk::gl::GL glClear GL_COLOR_BUFFER_BIT
    display $win
#    ::ntk::glmwfw::Glmwfw swapBuffers $win
#    ::ntk::gl::GL glFlush
    set isOpened [::ntk::glmwfw::Glmwfw getWindowParam $win GLMWFW_OPENED]
    if {!$isOpened} {
        ::ntk::glmwfw::Glmwfw terminate
        exit 0
    }
    after 5 [list Draw $win]
}
after 5 [list Draw $win]

#WaitEvents $win

set xx 1
vwait xx
after cancel $::afterWaitId
::ntk::glmwfw::Glmwfw terminate
exit 0
