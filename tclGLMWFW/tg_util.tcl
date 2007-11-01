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
    set isOpened [::ntk::glmwfw::GLMWFW getWindowParam GLMWFW_OPENED]
    if {!$isOpened} {
        ::ntk::glmwfw::GLMWFW terminate
        exit 0
    }
    ::ntk::glmwfw::GLMWFW waitEvents
    set ::afterWaitId [after 50 [list WaitEvents]]
}

proc tgInit {win} {
    ::ntk::glmwfw::GLMWFW enable GLMWFW_STICKY_KEYS
    ::ntk::glmwfw::GLMWFW enable GLMWFW_KEY_REPEAT
    ::ntk::glmwfw::GLMWFW enable GLMWFW_MOUSE_CURSOR
    ::ntk::glmwfw::GLMWFW setKeyCallback $win DispatchKey
    ::ntk::glmwfw::GLMWFW setMousePosCallback $win DispatchMousePos
    ::ntk::glmwfw::GLMWFW setMouseButtonCallback $win DispatchMouseButton
    ::ntk::glmwfw::GLMWFW setMouseWheelCallback $win DispatchMouseWheel
    ::ntk::glmwfw::GLMWFW setWindowSizeCallback $win DispatchWindowSize
    ::ntk::glmwfw::GLMWFW setWindowRefreshCallback $win DispatchWindowRefresh
    ::ntk::glmwfw::GLMWFW setWindowCloseCallback $win DispatchWindowClose
}

