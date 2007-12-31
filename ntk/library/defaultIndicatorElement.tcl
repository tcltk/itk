#---------------------------------------------------------------------------
# ntkWidget defaultIndicatorElement.tcl --
#
# This file contains a ntkWidget defaultIndicatorElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: defaultIndicatorElement.tcl,v 1.1.2.2 2007/12/31 14:52:12 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::defaultIndicatorElement {

    protected option -background -default [list 157 157 157 0] \
            -configurecommand indicatorElementConfigure
    protected option -indicatorcolor -default [list 157 157 157 0] \
            -configurecommand indicatorElementConfigure
    protected option -indicatorrelief -default raised \
            -configurecommand indicatorElementConfigure
    protected option -indicatordiameter -default 12 \
            -configurecommand indicatorElementConfigure
    protected option -indicatormargin -default [list 0 2 4 2] \
            -configurecommand indicatorElementConfigure
    protected option -borderwidth -default 2 \
            -configurecommand indicatorElementConfigure

    public method indicatorElementConfigure {option value} {
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

