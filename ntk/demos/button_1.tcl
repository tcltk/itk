package require ntkWidget

proc eval_stdin {} {
    set cmd [gets stdin]
    catch {uplevel #0 $cmd} result
    puts $result
    puts -nonewline "% "
    flush stdout
}

::ntk::glmwfw::Glmwfw setWindowTitle $::ntk::_win "NtkWidget Button Demo 1"

proc flipName {win} {
    set name [$win cget -text]
    switch $name {
    Arnulf {
        $win configure -text Wiedemann
      }
    Wiedemann {
        $win configure -text Arnulf
      }
   }
}

set rotate 0
if {[llength $argv] > 0} {
    set rotate [lindex $argv 0]
}
set wPath [ntk button .w -width 100 -height 100 -xoffset 50 -yoffset 50 \
-text Arnulf -textcolor [list 0 0 0 255] -bd 2 -bg [list 255 255 255 255]]
$wPath configure -command [list flipName $wPath] -rotate $rotate

puts stderr "CFG![$wPath configure -command]!"
ntk grid $wPath

fileevent stdin readable eval_stdin
vwait forever
puts stderr "END !!!"
