#---------------------------------------------------------------------------
# ntkWidget classicPaddingElement.tcl --
#
# This file contains a ntkWidget classicPaddingElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: classicPaddingElement.tcl,v 1.1.2.1 2007/12/31 14:49:36 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::classicPaddingElement {
    inherit ::ntk::classes::baseElement

    protected option -padding -default 0 \
            -configurecommand paddingElementConfigure
    protected option -relief -default flat \
            -configurecommand paddingElementConfigure
    protected option -shiftrelief -default 0 \
            -configurecommand paddingElementConfigure

    public method paddingElementConfigure {option value} {
    }

    public method InitializeOptionValues {styleName widget state} {
	InitializeOptionValuesBase $styleName $widget $state
puts stderr "PADDING!$this!relief!$itcl_options(-relief)!"
	return
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

