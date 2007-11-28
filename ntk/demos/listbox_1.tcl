#---------------------------------------------------------------------------
# ntkWidget listbox_1.tcl demo --
#
# This file contains a small demo for a button using the ntkWidget package
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: listbox_1.tcl,v 1.1.2.1 2007/11/28 21:39:16 wiede Exp $
#--------------------------------------------------------------------------

package require ntkWidget

# the next proc is mostly for debugging a simulated command line interface

proc eval_stdin {} {
    set cmd [gets stdin]
    catch {uplevel #0 $cmd} result
    puts $result
    puts -nonewline "% "
    flush stdout
}

::ntk::glmwfw::Glmwfw setWindowTitle $::ntk::_win "NtkWidget Listbox Demo 1"

set width 100
set height 200
ntk grid [ntk frame .left] -slot {0 0} -sticky height
.left requestSize $width $height

ntk grid [ntk scrollbar .left.yview \
        -command [list .left.list yview]] -slot {0 0} -sticky height
ntk grid [ntk scrollbar .left.xview -orient horizontal \
        -command [list .left.list xview]] -slot {1 1} -sticky width
ntk grid [ntk listbox .left.list \
        -fontsize 14 \
        -xscrollcommand [list .left.xview setView] \
        -yscrollcommand [list .left.yview setView]] \
        -slot {1 0} -sticky [list width height]

set wPath .left.list

$wPath insert end Tcl
$wPath insert end Tk
$wPath insert end "Itcl this is a long tag with some words"
$wPath insert end Tile
ntk render .

fileevent stdin readable eval_stdin
vwait forever
puts stderr "END !!!"
