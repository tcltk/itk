package require TclGL
package require GlmwfwX11
package require Glmwfw

proc init {} {
    set xx [::ntk::gl::GL glGetString GL_EXTENSIONS]
puts stderr "xx![join [lsort [split $xx]] \n]!"
    ::ntk::gl::GL glClearColor 0.55 0.55 0.55 0.0
    ::ntk::gl::GL glShadeModel GL_FLAT
    ::ntk::gl::GL glOrtho 0.0 1.0 0.0 1.0 -1.0 1.0
puts stderr "init done"
}

proc display {win} {
    ::ntk::gl::GL glClear GL_COLOR_BUFFER_BIT
    ::ntk::gl::GL glColor3f 0.75 0.0 0.0

    ::ntk::gl::GL glFlush
    ::ntk::glmwfw::Glmwfw swapBuffers $win 
#    after 50 [list display $win]
}

set win [::ntk::glmwfw::Glmwfw openWindow 500 400]
::ntk::glmwfw::Glmwfw setWindowTitle $win "Arnulf Cube with Numbered Vertices"
source tg_util.tcl
tgInit $win

init

display $win
set xx [::ntk::gl::GLext::glGenBuffersARB 2 xx]
puts stderr "xx!$xx!"

set xx 1
vwait xx
after cancel $::afterWaitId
::ntk::glmwfw::Glmwfw terminate
exit 0
