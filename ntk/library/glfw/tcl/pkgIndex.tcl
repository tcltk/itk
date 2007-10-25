if {[catch {package present Tcl 8.5b1}]} return
package ifneeded TclGlfw 0.1  [list load [file join $dir libTclGlfw0.1.so] TclGlfw]
