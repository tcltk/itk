#---------------------------------------------------------------------------
# ntkWidget classicTextElement.tcl --
#
# This file contains a ntkWidget classicTextElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: classicTextElement.tcl,v 1.1.2.1 2007/12/31 14:49:36 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::classicTextElement {
    inherit ::ntk::classes::baseElement

    source classicTextElementOptions.tcl

    public method InitializeOptionValues {styleName widget state} {
puts stderr "defaultTextElement INIT"
        InitializeOptionValuesBase $styleName $widget $state
    }

    public method textElementConfigure {option value} {
    }

    public method ElementSize {widthVar heightVar paddingVar} {
        upvar $widthVar width
        upvar $heightVar height
        upvar $paddingVar padding
puts stderr "Textelem!$itcl_options(-text)!"

        set width 72
	set height 16
    }

    public method ElementDraw {box state} {
        foreach {x y width height} $box break
    }
}

