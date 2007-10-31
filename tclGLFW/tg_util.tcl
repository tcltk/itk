proc DispatchKey {key state keyVal} {
    puts stderr "DispatchKey!$key!$state![format %c $key]!$keyVal!"
}
proc DispatchMousePos {x y} {
#    puts stderr "DispatchMousePos!$x!$y!"
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

proc WaitEvents {} {
    set isOpened [::ntk::glfw::GLFW getWindowParam GLFW_OPENED]
    if {!$isOpened} {
        ::ntk::glfw::GLFW terminate
        exit 0
    }
    ::ntk::glfw::GLFW waitEvents
    set ::afterWaitId [after 50 [list WaitEvents]]
}

proc tgInit {win} {
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
}

