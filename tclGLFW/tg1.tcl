lappend auto_path .
package require TclGLFW

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

::ntk::glfw::GLFW init
set win [::ntk::glfw::GLFW openWindow 500 400]
puts stderr "win!$win!"
::ntk::glfw::GLFW setWindowTitle "Hallo Arnulf"
set running 1
puts stderr "start!"
set modes [::ntk::glfw::GLFW getVideoModes]
puts stderr "modes![join $modes \n]!"
set dmode [::ntk::glfw::GLFW getDesktopMode]
puts stderr "dmode!$dmode!"
proc DispatchKey {key state} {
    puts stderr "DispatchKey!$key!$state!"
}
proc DispatchMousePos {x y} {
    puts stderr "DispatchMousePos!$x!$y!"
}
proc DispatchMouseButton {num state} {
    puts stderr "DispatchMouseButton!$num!$state!"
}
proc DispatchMouseWheel {where} {
    puts stderr "DispatchMouseWheel!$where!"
}
proc DispatchWindowSize {width height} {
    puts stderr "DispatchWindowSize!$width!$height!"
}
proc DispatchWindowRefresh {} {
    puts stderr "DispatchWindowRefresh!"
}
proc DispatchWindowClose {} {
    puts stderr "DispatchWindowClose!"
}
::ntk::glfw::GLFW enable GLFW_STICKY_KEYS
::ntk::glfw::GLFW enable GLFW_KEY_REPEAT
::ntk::glfw::GLFW enable GLFW_MOUSE_CURSOR
::ntk::glfw::GLFW setKeyCallback $win DispatchKey
::ntk::glfw::GLFW setMousePosCallback $win DispatchMousePos
::ntk::glfw::GLFW setMouseButtonCallback $win DispatchMouseButton
::ntk::glfw::GLFW setMouseWheelCallback $win DispatchMouseWheel
::ntk::glfw::GLFW setWindowSizeCallback $win DispatchWindowSize
::ntk::glfw::GLFW setWindowRefreshCallback $win DispatchWindowRefresh
::ntk::glfw::GLFW setWindowCloseCallback $win DispatchWindowClose

proc Draw {} {
    upvar lst lst

    ::ntk::glfw::GLFW glClearColor 0.25 0.0 0.0 0.0
    ::ntk::glfw::GLFW glClear GL_COLOR_BUFFER_BIT
    ::ntk::glfw::GLFW glDrawPixels 50 50 $lst
    ::ntk::glfw::GLFW swapBuffers
    ::ntk::glfw::GLFW glFlush
    set isOpened [::ntk::glfw::GLFW getWindowParam GLFW_OPENED]
    if {!$isOpened} {
        ::ntk::glfw::GLFW terminate
        exit 0
    }
    after 5 [list Draw]
}
after 5 [list Draw]
set xx 1
vwait xx
::ntk::glfw::GLFW terminate
exit 0
