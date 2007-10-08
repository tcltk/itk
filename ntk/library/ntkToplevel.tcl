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
# RCS: @(#) $Id: ntkToplevel.tcl,v 1.1.2.5 2007/10/08 19:57:13 wiede Exp $
#--------------------------------------------------------------------------

itcl::eclass ::ntk::classes::toplevel {
    inherit ::ntk::classes::window

    private variable id
    private variable toplevel
    private variable toplevelDraw [list]

    public option -bg -default [list 16 33 65 255] -validatemethod verifyColor -configuremethod toplevelConfig

    private method toplevelConfig {option value} {
        set itcl_options($option) $value
        if {$toplevelDraw ne ""} {
            $toplevelDraw $path
	}
    }

    public method id {{value {}}} {
	if {$value eq ""} {
            return $id
	} else {
	    set id $value
	}
    }

    public method toplevel {{value {}}} {
	if {$value eq ""} {
            return $toplevel
	} else {
	    set toplevel $value
	}
    }

    constructor {args} {
        eval ::ntk::classes::window::constructor $args
    } {
        set id ""
        set toplevel 1
        return [path]
    }
    
    public method toplevelDraw {path} {
#puts stderr "toplevelDraw!$path!"
       set myTile [cget -tile]
        set myObj [obj]
        if {$myTile ne ""} {
            $myObj tile $myTile
        } else {
            set myColor [$path cget -bg]
            if {[llength $myColor] == 1} {
                $myObj setall $colors($myColor)
            } else {
                $myObj setall $myColor
            }
        }
        $path render $path
    }

}

