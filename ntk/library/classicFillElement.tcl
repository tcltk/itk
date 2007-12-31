#---------------------------------------------------------------------------
# ntkWidget classicFillElement.tcl --
#
# This file contains a ntkWidget classicFillElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: classicFillElement.tcl,v 1.1.2.1 2007/12/31 14:49:36 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::classicFillElement {

    public method fillElementConfigure {option value} {
    }

    public method ElementSize {widthVar heightVar paddingVar} {
        # nothing to do!!
    }

    public method ElementDraw {box state} {
        foreach {x y width height} $box break
    }
}

