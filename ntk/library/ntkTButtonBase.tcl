#---------------------------------------------------------------------------
# ntkWidget ntkTButtonBase.tcl --
#
# This file contains a ntkWidget tbutton commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: ntkTButtonBase.tcl,v 1.1.2.1 2007/12/30 22:59:52 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::tbuttonBase {

    protected variable baseConfig

    # text options
    public option [list -text text Text] -default ""
    public option [list -textvariable textVariable Variable] -default ""
    public option [list -underline underline Underline] -default -1
    public option [list -width width Width] -default -1

    # image options
    public option [list -image image image] -default ""

    # Compound base/image options
    public option [list -compound compound Compound] -default none
    public option [list -padding padding Pad] -default -1
}

