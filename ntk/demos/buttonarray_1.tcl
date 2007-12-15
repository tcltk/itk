package require ntkWidget

# the next proc is mostly for debugging a simulated command line interface

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

for {set a 0} {$a < 200} {incr a} {
set tim [time {
    set b [expr int(floor($a /10))]
    set wPath [ntk button .w$a -width 200 -height 100 -xoffset 50 -yoffset 50 \
      -text Arnulf -textcolor [list 0 0 0 255] -bd 2 -bg [list 255 255 255 255]]
    $wPath configure -command [list flipName $wPath] -rotate $rotate

    # pack the widget using ntkWidget grid manager
    set c [expr $a % 10]
    ntk grid $wPath  -slot "$c $b"

#    $wPath bind <KeyPress-Shift-A> {puts "Hello Arnulf"}
#    update
}]
#puts stderr "tim!$tim!"
}

update
#fileevent stdin readable eval_stdin
#vwait forever
after 1000
puts stderr "END !!!"
