#---------------------------------------------------------------------------
# ntkWidget ntkBackgroundElement.tcl --
#
# This file contains a ntkWidget BackgroundElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: defaultBackgroundElement.tcl,v 1.1.2.1 2007/12/29 19:58:27 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::backgroundElement {
    protected option -background -default [list 157 157 157 255] \
            -configurecommand backgroundElementConfigure

    public method backgroundElementConfigure {option value} {
    }

    public method BackgroundElementSize {widthVar heightVar paddingVar} {
        # nothing to do!!
    }

    public method BackgroundElementDraw {box state} {
        foreach {x y width height} $box break
    }
}

