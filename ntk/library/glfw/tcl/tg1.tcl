lappend auto_path .
package require TclGlfw

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

::ntk::glfw::Glfw init
set win [::ntk::glfw::Glfw openWindow 500 400]
puts stderr "win!$win!"
::ntk::glfw::Glfw setWindowTitle "Hallo Arnulf"
set running 1
puts stderr "start!"
set modes [::ntk::glfw::Glfw getVideoModes]
puts stderr "modes![join $modes \n]!"
set dmode [::ntk::glfw::Glfw getDesktopMode]
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
::ntk::glfw::Glfw enable GLFW_STICKY_KEYS
::ntk::glfw::Glfw enable GLFW_KEY_REPEAT
::ntk::glfw::Glfw enable GLFW_MOUSE_CURSOR
::ntk::glfw::Glfw setKeyCallback $win DispatchKey
::ntk::glfw::Glfw setMousePosCallback $win DispatchMousePos
::ntk::glfw::Glfw setMouseButtonCallback $win DispatchMouseButton
::ntk::glfw::Glfw setMouseWheelCallback $win DispatchMouseWheel
::ntk::glfw::Glfw setWindowSizeCallback $win DispatchWindowSize

proc Draw {} {
    upvar lst lst

    ::ntk::glfw::Glfw glClearColor 0.25 0.0 0.0 0.0
    ::ntk::glfw::Glfw glClear GL_COLOR_BUFFER_BIT
    ::ntk::glfw::Glfw glDrawPixels 50 50 $lst
    ::ntk::glfw::Glfw swapBuffers
    ::ntk::glfw::Glfw glFlush
    set isOpened [::ntk::glfw::Glfw getWindowParam GLFW_OPENED]
    if {!$isOpened} {
        ::ntk::glfw::Glfw terminate
        exit 0
    }
    after 5 [list Draw]
}
after 5 [list Draw]
set xx 1
vwait xx
::ntk::glfw::Glfw terminate
exit 0
