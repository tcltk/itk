package require Itcl 4.0
source ntk.tcl

set ::win [::ntk::glmwfw::Glmwfw openWindow 500 400]
::ntk::glmwfw::Glmwfw setWindowTitle $::win "Ntk Toplevel"

set top [ntk toplevel . -width 400 -height 400]
set path [ntk window .win1 -width 400 -height 400]
puts stderr "path!$path!"
puts stderr "width![$path configure -width]!"
puts stderr "width![$path cget -width]!"
puts stderr "obj![$path obj]!"
puts stderr END
