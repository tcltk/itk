#---------------------------------------------------------------------------
# ntkWidget ntkSizegripElement.tcl --
#
# This file contains a ntkWidget SizegripElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: defaultSizegripElement.tcl,v 1.1.2.1 2007/12/29 19:58:27 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::sizegripElement {

    protected option -background -default [list 157 157 157 0] \
            -configurecommand sizegripElementConfigure

    public method SizegripElementConfigure {option value} {
    }

    public method SizegripElementSize {widthVar heightVar paddingVar} {
        upvar $widthVar width
        upvar $heightVar height
        upvar $paddingVar padding
    }

    public method SizegripElementDraw {box state} {
        foreach {x y width height} $box break
    }
}

