if {[catch {package present Tcl 8.5b1}]} return
package ifneeded ntkWidget 0.1 [list source [file join $dir ntk.tcl]]
