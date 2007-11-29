#---------------------------------------------------------------------------
# ntkWidget clock_1.tcl demo --
#
# This file contains a small demo for a button using the ntkWidget package
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: clock_1.tcl,v 1.1.2.1 2007/11/29 18:16:12 wiede Exp $
#--------------------------------------------------------------------------

# optional command line parameter: rotate 
# the value determines how much the label is rotated counter clock wise
# negative values rotate clockwise
# the value is in the range of 0 .. 360 (degrees)

package require ntkWidget

# the next proc is mostly for debugging a simulated command line interface

proc eval_stdin {} {
    set cmd [gets stdin]
    catch {uplevel #0 $cmd} result
    puts $result
    puts -nonewline "% "
    flush stdout
}

::ntk::glmwfw::Glmwfw setWindowTitle $::ntk::_win "NtkWidget Clock Demo 1"

set rotate 0
if {[llength $argv] > 0} {
    set rotate [lindex $argv 0]
}
set wPath [ntk clock .w -bd 2 -bg [list 255 255 255 255]]
$wPath configure -rotate $rotate

# pack the widget using ntkWidget grid manager
#ntk grid $wPath
$wPath clockCycle

fileevent stdin readable eval_stdin
vwait forever
puts stderr "END !!!"
