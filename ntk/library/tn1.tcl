package require Itcl 4.0
load /home/arnulf/SOURCES/MEGAIMAGE/megapkg/build/arch/i386/Linux/megaimage.so
source ntk.tcl
source ntkBase.tcl
source ntkWindow.tcl

set path [ntk window .win1 400 400]
puts stderr "path!$path!"
puts stderr "width![$path configure -width]!"
puts stderr "width![$path cget -width]!"
puts stderr "obj![$path obj]!"
