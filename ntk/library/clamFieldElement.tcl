#---------------------------------------------------------------------------
# ntkWidget clamFieldElement.tcl --
#
# This file contains a ntkWidget FieldElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: clamFieldElement.tcl,v 1.1.2.1 2007/12/31 14:50:36 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::clamFieldElement {

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

