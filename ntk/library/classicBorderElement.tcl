#---------------------------------------------------------------------------
# ntkWidget classicBorderElement.tcl --
#
# This file contains a ntkWidget classicBorderElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: classicBorderElement.tcl,v 1.1.2.1 2007/12/31 14:49:36 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::classicBorderElement {
    inherit ::ntk::classes::baseElement

    protected option -background -default [list 157 157 157 255] \
            -configurecommand borderElementConfigure
    protected option -borderwidth -default 2 \
            -configurecommand borderElementConfigure
    protected option -relief -default flat \
            -configurecommand borderElementConfigure

    public method InitializeOptionValues {styleName widget state} {
	InitializeOptionValuesBase $styleName $widget $state
puts stderr "BORDER!$this!borderwidth!$itcl_options(-borderwidth)!"
    }

    public method borderElementConfigure {option value} {
    }

    public method ElementSize {widthVar heightVar paddingVar} {
        upvar $paddingVar padding

        set borderWidth $itcl_options(-borderwidth)
	set padding [list $borderWidth $borderWidth $borderWidth $borderWidth]
puts stderr "BORDER SIZE!$this!$paddingVar!$itcl_options(-borderwidth)!"
    }

    public method ElementDraw {box state} {
        foreach {x y width height} $box break
    }
}

