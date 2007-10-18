#---------------------------------------------------------------------------
# ntkWidget ntkGridManager.tcl --
#
# This file contains a ntkWidget window command implementation
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
# RCS: @(#) $Id: ntkGridManager.tcl,v 1.1.2.5 2007/10/18 21:51:06 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::gridManager {
    public methodvariable grid -default [list]
    public methodvariable remanage -default layout
    public methodvariable peakrow -default 0
    public methodvariable peakcolumn -default 0
    public methodvariable free -default gridFree

    constructor {path args} {
        return $this
    }
}

