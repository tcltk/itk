if {[catch {package present Tcl 8.5b1}]} return
package ifneeded TclGLFW 0.1  [list load [file join $dir libTclGLFW0.1.so] TclGLFW]
