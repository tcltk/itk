package require Itcl 4.0
set megaimageDir /home/arnulf/SOURCES/MEGAIMAGE/megapkg/build/arch/i386/Linux
load $megaimageDir/megaimage.so
load $megaimageDir/megaimagetk.so
source ntk.tcl
source ntkHelpers.tcl
source ntkRender.tcl
source ntkGridBase.tcl
source ntkWindow.tcl
source ntkToplevel.tcl
source ntkFrame.tcl

set dotF [megaimage.frame .f persist]
pack $dotF -fill both -expand 1
$dotF size 800 600
bind $dotF <Enter> {focus $dotF}

rename . _old_toplevel_

puts stderr "TOP"
set top [ntk toplevel . -width 500 -height 500]
set topObj [$top obj]

set w2Path [ntk frame .w2 -width 100 -height 100]
update idletask
after 2000
$w2Path configure -bg [list 155 0 0 255]
#. objsetimage [. obj]

set w3Path [ntk frame .w3 -width 200 -height 200]
$w3Path configure -bg [list 255 150 150 255] -x 180 -y 150
#. objsetimage [. obj]
update idletask

after 2000
$w2Path configure -bg [list 255 0 0 255]
update idletask
puts stderr "END !!!"
