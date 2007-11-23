#---------------------------------------------------------------------------
# ntkWidget ntkToplevel.tcl --
#
# This file contains a ntkWidget toplevel command implementation
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
# RCS: @(#) $Id: ntkToplevel.tcl,v 1.1.2.12 2007/11/23 21:02:57 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::toplevel {
    inherit ::ntk::classes::window

    public methodvariable id -default [list]

    public methodvariable grid -default [list]
    public methodvariable remanage -default layout
    public methodvariable peakrow -default 0
    public methodvariable peakcolumn -default 0
    public methodvariable free -default gridFree

    public method layout {} {
puts stderr "toplevel layout called"
        ::ntk::classes::grid::layout $wpath
    }

    constructor {args} {
	if {[llength $args] > 0} {
	    configure {*}$args
	}
        set toplevel 1
        return $wpath
    }
}

