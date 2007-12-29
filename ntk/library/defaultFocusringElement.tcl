#---------------------------------------------------------------------------
# ntkWidget ntFocusringElement.tcl --
#
# This file contains a ntkWidget FocusringElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: defaultFocusringElement.tcl,v 1.1.2.1 2007/12/29 19:58:27 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::focusringElement {

    protected option -focuscolor -default [list 0 0 0 0] \
            -configurecommand focusringElementConfigure
    protected option -focusthickness -default 1 \
            -configurecommand focusringElementConfigure

    public method focusringElementConfigure {option value} {
    }

    public method FocusringElementSize {widthVar heightVar paddingVar} {
        upvar $widthVar width
        upvar $heightVar height
        upvar $paddingVar padding
    }

    public method FocusringElementDraw {box state} {
        foreach {x y width height} $box break
    }
}

