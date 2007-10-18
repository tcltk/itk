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
# RCS: @(#) $Id: ntkToplevel.tcl,v 1.1.2.10 2007/10/18 21:52:39 wiede Exp $
#--------------------------------------------------------------------------

itcl::extendedclass ::ntk::classes::toplevel {
    inherit ::ntk::classes::window

    public methodvariable id -default [list]

    constructor {args} {
        eval ::ntk::classes::window::constructor $args
    } {
        set toplevel 1
        return $wpath
    }
}

