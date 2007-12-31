#---------------------------------------------------------------------------
# ntkWidget clamSeparatorElement.tcl --
#
# This file contains a ntkWidget clamSeparatorElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: clamSeparatorElement.tcl,v 1.1.2.1 2007/12/31 14:50:37 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::clamSeparatorElement {

    protected option -orient -default horizontal \
            -configurecommand separatorElementConfigure
    protected option -background -default [list 157 157 157 0] \
            -configurecommand separatorElementConfigure

    public method separatorElementConfigure {option value} {
    }

    public method ElementSize {widthVar heightVar paddingVar} {
        upvar $widthVar width
        upvar $heightVar height
        upvar $paddingVar padding
    }

    public method ElementDraw {box state} {
        foreach {x y width height} $box break
    }
}

