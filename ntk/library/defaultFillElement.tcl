#---------------------------------------------------------------------------
# ntkWidget ntkFillElement.tcl --
#
# This file contains a ntkWidget FillElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: defaultFillElement.tcl,v 1.1.2.1 2007/12/29 19:58:27 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::fillElement {

    public method fillElementConfigure {option value} {
    }

    public method FillElementSize {widthVar heightVar paddingVar} {
        # nothing to do!!
    }

    public method FillElementDraw {box state} {
        foreach {x y width height} $box break
    }
}

