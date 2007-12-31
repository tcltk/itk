#---------------------------------------------------------------------------
# ntkWidget defaultFieldElement.tcl --
#
# This file contains a ntkWidget defaultFieldElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: defaultFieldElement.tcl,v 1.1.2.2 2007/12/31 14:52:12 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::defaultFieldElement {

    protected option -fieldbackground -default [list 255 255 255 255] \
            -configurecommand fieldElementConfigure
    protected option -borderwidth -default 2 \
            -configurecommand fieldElementConfigure

    public method fieldElementConfigure {option value} {
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

