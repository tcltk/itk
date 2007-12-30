#---------------------------------------------------------------------------
# ntkWidget defaultImageElement.tcl --
#
# This file contains a ntkWidget defaultImageElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: defaultImageElement.tcl,v 1.1.2.1 2007/12/30 22:55:57 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::defaultImageElement {
    inherit ::ntk::classes::baseElement

    source defaultImageElementOptions.tcl

    public method InitializeOptionValues {styleName widget state} {
puts stderr "defaultImageElement INIT"
        InitializeOptionValuesBase $styleName $widget $state
    }

    public method imageElementConfigure {option value} {
    }

    public method ElementSize {widthVar heightVar paddingVar} {
        upvar $widthVar width
        upvar $heightVar height
        upvar $paddingVar padding

	# FIX ME !!
        set width 0
	set height 0
    }

    public method ElementDraw {box state} {
        foreach {x y width height} $box break
    }
}

