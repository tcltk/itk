#---------------------------------------------------------------------------
# ntkWidget defaultPaddingElement.tcl --
#
# This file contains a ntkWidget defaultPaddingElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: defaultPaddingElement.tcl,v 1.1.2.3 2008/01/02 19:58:57 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::defaultPaddingElement {
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
puts stderr "PADDING!$this!padding!$itcl_options(-padding)!"
	return
    }

    public method ElementSize {widthVar heightVar paddingVar} {
        upvar $paddingVar padding

        set padding [ReliefPadding $itcl_options(-padding) $itcl_options(-relief) $itcl_options(-shiftrelief)]
    }

    public method ElementDraw {box state} {
        foreach {x y width height} $box break
    }
}

