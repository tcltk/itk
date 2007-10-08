#---------------------------------------------------------------------------
# ntkWidget ntkGridBase.tcl --
#
# This file contains a ntkWidget grid utility commands implementation
#
# ntkWidget is derived from the NexTk implementation written by
# George Peter Staplin
#
# ntkWidget is a reimplementation of Tk based on megapkg, ntk and freetypeext
# written by George Peter Staplin
#
# Copyright (c) 2007 by Arnulf P. Wiedemann and George Peter Staplin
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: ntkGridBase.tcl,v 1.1.2.2 2007/10/08 19:57:13 wiede Exp $
#--------------------------------------------------------------------------

::itcl::eclass ::ntk::classes::gridBase {
    inherit ::ntk::classes::render

    public variable grid [list]
    public variable remanage [list]
    public variable peakrow [list]
    public variable peakcolumn [list]
    public variable free [list]
    public variable removeFromManager [list]

    public option -sticky [list]
    public option -columnspan 1
    public option -rowspan 1
    public option -slot [list 0 0]
    public option -columnratio 0
    public option -rowratio 0

if {0} {
    constructor {remanage free removeFromManager {peekrow 0} {peekcolumn 0}} {
        configure -path $path
        configure -remanage $remanage
        configure -free $free
        configure -removeFromManager $removeFromManager
        configure -peekrow $peekrow
        configure -peekcolumn $peekcolumn
    }
}
}

