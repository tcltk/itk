#---------------------------------------------------------------------------
# ntkWidget defaultTextElement.tcl --
#
# This file contains a ntkWidget defaultTextElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: defaultTextElement.tcl,v 1.1.2.1 2007/12/30 22:55:58 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::defaultTextElement {
    inherit ::ntk::classes::baseElement

    source defaultTextElementOptions.tcl

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

