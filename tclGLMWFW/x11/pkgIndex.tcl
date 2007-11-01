if {[catch {package present Tcl 8.5b1}]} return
package ifneeded TclGLMWFWX 0.1  [list load [file join $dir libTclGLMWFWX.0.1.so] TclGLMWFWX]
