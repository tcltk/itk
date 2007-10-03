package require Itcl 4.0
set megaimageDir /home/arnulf/SOURCES/MEGAIMAGE/megapkg/build/arch/i386/Linux
load $megaimageDir/megaimage.so
load $megaimageDir/megaimagetk.so
source ntk.tcl
source ntkHelpers.tcl
source ntkRender.tcl
source ntkGridBase.tcl
source ntkWindow.tcl
source ntkFrame.tcl

set dotF [megaimage.frame .f persist]
pack $dotF -fill both -expand 1
$dotF size 800 600
bind $dotF <Enter> {focus $dotF}

rename . _old_toplevel_

set top [ntk window . -width 500 -height 500]
set topObj [$top obj]
set path [ntk frame .w2 -width 100 -height 100]
set w2Obj [$path obj]
puts stderr "OBJS!$topObj!$w2Obj!"
$w2Obj setall [list 255 0 255 120]
puts stderr "CALLING CFG RED"
$path configure -bg red
$w2Obj setall [list 255 0 0 255]
puts stderr "CFG![$path configure -bg]!"
update idletask
$path render $path 
. objsetimage [. obj]
update idletask
puts stderr "END !!!"
