if {[catch {package present Tcl 8.5b1}]} return
package ifneeded TclGLMWFWX11 0.1  [list load [file join $dir libTclGLMWFWX110.1.so] TclGLMWFWX11]
