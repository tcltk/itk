#---------------------------------------------------------------------------
# ntkWidget clamBackgroundElement.tcl --
#
# This file contains a ntkWidget clamBackgroundElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: clamBackgroundElement.tcl,v 1.1.2.1 2007/12/31 14:50:35 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::clamBackgroundElement {
    inherit ::ntk::classes::baseElement

    protected option -background -default [list 157 157 157 255] \
            -configurecommand backgroundElementConfigure

    public method backgroundElementConfigure {option value} {
    }

    public method ElementSize {widthVar heightVar paddingVar} {
        # nothing to do!!
    }

    public method InitializeOptionValues {styleName widget state} {
	InitializeOptionValuesBase $styleName $widget $state
puts stderr "BACKGROUND!$this!background!$itcl_options(-background)!"
    }

    public method ElementDraw {box state} {
        foreach {x y width height} $box break
    }
}

