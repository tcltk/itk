#---------------------------------------------------------------------------
# ntkWidget defaultBackgroundElement.tcl --
#
# This file contains a ntkWidget defaultBackgroundElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: defaultBackgroundElement.tcl,v 1.1.2.2 2007/12/30 22:58:19 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::defaultBackgroundElement {
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

