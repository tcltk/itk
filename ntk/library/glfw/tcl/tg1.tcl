lappend auto_path . /home/arnulf/Desktop/TCL3D/tcl3dsh-Linux-0.3.2
package require tcl3d
package require TclGlfw

::ntk::glfw::Glfw openWindow 300 200
::ntk::glfw::Glfw setWindowTitle "Hallo Arnulf"
set running 1
puts stderr "start!"
set modes [::ntk::glfw::Glfw getVideoModes]
puts stderr "modes![join $modes \n]!"
set dmode [::ntk::glfw::Glfw getDesktopMode]
puts stderr "dmode!$dmode!"
::ntk::glfw::Glfw enable GLFW_STICKY_KEYS
while {$running} {
    ::ntk::glfw::Glfw swapBuffers
    set isOpend [::ntk::glfw::Glfw getWindowParam GLFW_OPENED]
    set key [::ntk::glfw::Glfw getKey q]
    set running [expr {!$key}]
puts stderr "isOpend!$isOpend!$key!$running!"
    after 3000
}
::ntk::glfw::Glfw terminate
exit 0
