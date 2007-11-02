lappend auto_path .
package require TclGL
package require GlmwfwX11
package require Glmwfw

source tg_util.tcl

set lst0 [list 0.5 0.0 0.5 0.5]
set lst1 [list 0.78 0.0 0.5 1.0]
set lst2 [list]
foreach i {1 2 3 4 5 6 7 8 9 10} {
    set lst2 [concat $lst2 $lst0]
    set lst2 [concat $lst2 $lst0]
    set lst2 [concat $lst2 $lst0]
    set lst2 [concat $lst2 $lst1]
    set lst2 [concat $lst2 $lst1]
}
set lst [list]
foreach i {1 2 3 4 5 6 7 8 9 10} {
    set lst [concat $lst $lst2]
    set lst [concat $lst $lst2]
    set lst [concat $lst $lst2]
    set lst [concat $lst $lst2]
    set lst [concat $lst $lst2]
}
set lst [::ntk::gl::GL makeFloatVector $lst]

set win [::ntk::glmwfw::Glmwfw openWindow 500 400]
::ntk::glmwfw::Glmwfw setWindowTitle $win "Hallo Arnulf"
tgInit $win

if {0} {
    set modes [::ntk::glmwfw::Glmwfw getVideoModes]
    puts stderr "modes![join $modes \n]!"
    set dmode [::ntk::glmwfw::Glmwfw getDesktopMode]
    puts stderr "dmode!$dmode!"
}

proc Draw {win} {
    upvar lst lst

    ::ntk::gl::GL glClearColor 0.25 0.0 0.0 0.0
    ::ntk::gl::GL glClear GL_COLOR_BUFFER_BIT
    ::ntk::gl::GL glDrawPixels 50 50 GL_RGBA GL_FLOAT $lst
    ::ntk::glmwfw::Glmwfw swapBuffers $win 
    ::ntk::gl::GL glFlush
}

Draw $win

set win2 [::ntk::glmwfw::Glmwfw openWindow 400 300]
puts stderr "WIN2!$win2!"
::ntk::glmwfw::Glmwfw setWindowTitle $win2 "Hallo Arnulf 2"
tgInit $win2
Draw $win2

WaitEvents $win2

set xx 1
vwait xx
after cancel $::afterWaitId
::ntk::glmwfw::Glmwfw terminate
exit 0
