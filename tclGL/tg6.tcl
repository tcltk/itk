package require TclGL
package require GlmwfwX11
package require Glmwfw

proc init {} {
    ::ntk::gl::GL glClearColor 0.55 0.55 0.55 0.0
    ::ntk::gl::GL glShadeModel GL_FLAT
}

proc display {win} {
    ::ntk::gl::GL glClear GL_COLOR_BUFFER_BIT
    ::ntk::gl::GL glPushMatrix 
    ::ntk::gl::GL glRotatef $::spin 0.0 0.0 1.0
    ::ntk::gl::GL glColor3f 1.0 1.0 1.0
    ::ntk::gl::GL glRectf -0.25 -0.25 0.25 0.25
    ::ntk::gl::GL glPopMatrix 
    ::ntk::gl::GL glFlush
    ::ntk::glmwfw::Glmwfw swapBuffers $win 
#    after 50 [list display $win]
}

proc spin {win} {
    set ::spin [expr {$::spin + 2.0}]
    if {$::spin > 360.0} {
       set ::spin [expr {$::spin - 360.0}]
    }
}

set win [::ntk::glmwfw::Glmwfw openWindow 500 400]
::ntk::glmwfw::Glmwfw setWindowTitle $win "Hallo Arnulf"
source tg_util.tcl
tgInit $win

init

set spin 0.0
lappend callbacks spin

display $win
after 50 [list handleCallbacks $win]

set xx 1
vwait xx
after cancel $::afterWaitId
::ntk::glmwfw::Glmwfw terminate
exit 0
