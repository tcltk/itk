
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
::ntk::glmwfw::Glmwfw enable GLMWFW_STICKY_KEYS
::ntk::glmwfw::Glmwfw enable GLMWFW_KEY_REPEAT
::ntk::glmwfw::Glmwfw enable GLMWFW_MOUSE_CURSOR
::ntk::glmwfw::Glmwfw setKeyCallback $win DispatchKey
::ntk::glmwfw::Glmwfw setMousePosCallback $win DispatchMousePos
::ntk::glmwfw::Glmwfw setMouseButtonCallback $win DispatchMouseButton
::ntk::glmwfw::Glmwfw setMouseWheelCallback $win DispatchMouseWheel
::ntk::glmwfw::Glmwfw setWindowSizeCallback $win DispatchWindowSize
::ntk::glmwfw::Glmwfw setWindowRefreshCallback $win DispatchWindowRefresh
::ntk::glmwfw::Glmwfw setWindowCloseCallback $win DispatchWindowClose


