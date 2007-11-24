package require Itcl 4.0
source ntk.tcl
#lappend auto_path .
package require ntkWidgetImage

proc eval_stdin {} {
    set cmd [gets stdin]
    catch {uplevel #0 $cmd} result
    puts $result
    puts -nonewline "% "
    flush stdout
}

::ntk::glmwfw::Glmwfw setWindowTitle $::ntk::_win "NtkWidget Button Demo"

proc flipName {} {
    set name [.w2 cget -text]
    switch $name {
    Arnulf {
        .w2 configure -text Wiedemann
      }
    Wiedemann {
        .w2 configure -text Arnulf
      }
   }
}

set w2Path [ntk button .w2 -width 100 -height 100 -xoffset 50 -yoffset 50 -text Arnulf -textcolor [list 0 0 0 255] -bd 2 -bg [list 255 255 255 255] -command flipName -rotate 0]

if {0} {
set xx [::ntk::classes::gridManager gd1 $w2Path]
puts stderr "XX!$xx!"
puts stderr "COLUMNSPAN![$w2Path configure -columnspan 2]!"
puts stderr "COLUMNSPAN![$w2Path cget -columnspan]!"
puts stderr "PEAKCOLUMN![$w2Path peakcolumn]!"
}

ntk grid $w2Path

#puts stderr "setting eval-stdin"
fileevent stdin readable eval_stdin
vwait forever
puts stderr "END !!!"
