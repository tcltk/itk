if {[catch {package present Tcl }]} return
package ifneeded TclGL 0.1  [list load [file join $dir libTclGL0.1.so] TclGL] 
