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
# RCS: @(#) $Id: ntkToplevel.tcl,v 1.1.2.7 2007/10/14 23:42:56 wiede Exp $
#--------------------------------------------------------------------------

itcl::eclass ::ntk::classes::toplevel {
    inherit ::ntk::classes::window

    private variable id

    public option -bg -default [list 16 33 65 255] \
            -validatemethod verifyColor -configuremethod toplevelConfig

    public method toplevelConfig {option value} {
        set itcl_options($option) $value
    }

    public method id {{value {}}} {
	if {$value eq ""} {
            return $id
	} else {
	    set id $value
	}
    }

    constructor {args} {
        eval ::ntk::classes::window::constructor $args
    } {
        set id ""
        set toplevel 1
        return $wpath
    }
}

