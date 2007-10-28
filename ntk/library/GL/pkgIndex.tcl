if {[catch {package present Tcl 8.5b1}]} return
package ifneeded TclGL 0.1  [list load [file join $dir libTclGL0.1.so] TclGL]
