
proc DispatchKey {key state} {
#    puts stderr "DispatchKey!$key!$state!"
}
proc DispatchMousePos {x y} {
#    puts stderr "DispatchMousePos!$x!$y!"
}
proc DispatchMouseButton {num state} {
#    puts stderr "DispatchMouseButton!$num!$state!"
}
proc DispatchMouseWheel {where} {
#    puts stderr "DispatchMouseWheel!$where!"
}
proc DispatchWindowSize {width height} {
#    puts stderr "DispatchWindowSize!$width!$height!"
}
proc DispatchWindowRefresh {} {
#    puts stderr "DispatchWindowRefresh!"
}
proc DispatchWindowClose {} {
#    puts stderr "DispatchWindowClose!"
}
::ntk::glfw::Glfw enable GLFW_STICKY_KEYS
::ntk::glfw::Glfw enable GLFW_KEY_REPEAT
::ntk::glfw::Glfw enable GLFW_MOUSE_CURSOR
::ntk::glfw::Glfw setKeyCallback $win DispatchKey
::ntk::glfw::Glfw setMousePosCallback $win DispatchMousePos
::ntk::glfw::Glfw setMouseButtonCallback $win DispatchMouseButton
::ntk::glfw::Glfw setMouseWheelCallback $win DispatchMouseWheel
::ntk::glfw::Glfw setWindowSizeCallback $win DispatchWindowSize
::ntk::glfw::Glfw setWindowRefreshCallback $win DispatchWindowRefresh
::ntk::glfw::Glfw setWindowCloseCallback $win DispatchWindowClose

proc Draw {} {
    upvar lst lst
    upvar data data

    ::ntk::glfw::Glfw glClearColor 0.55 0.55 0.55 0.0
    ::ntk::glfw::Glfw glClear GL_COLOR_BUFFER_BIT
    testRender
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

