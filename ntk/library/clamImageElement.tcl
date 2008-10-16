#---------------------------------------------------------------------------
# ntkWidget clamImageElement.tcl --
#
# This file contains a ntkWidget clamImageElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: clamImageElement.tcl,v 1.1.2.1 2007/12/31 14:50:36 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::clamImageElement {
    inherit ::ntk::classes::baseElement

    source clamImageElementOptions.tcl

    public method InitializeOptionValues {styleName widget state} {
puts stderr "clamImageElement INIT"
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
