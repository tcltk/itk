#---------------------------------------------------------------------------
# ntkWidget clamLabelElement.tcl --
#
# This file contains a ntkWidget clamLabelElement commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: clamLabelElement.tcl,v 1.1.2.1 2007/12/31 14:50:37 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::clamLabelElement {
    inherit ::ntk::classes::baseElement ::ntk::classes::helpers

    protected option -compound -default none \
            -configurecommand labelElementConfigure
    protected option -space -default 4 \
            -configurecommand labelElementConfigure
    protected option -relief -default flat \
            -configurecommand labelElementConfigure
    source clamTextElementOptions.tcl
    source clamImageElementOptions.tcl

    public option -fontsize -default 12
    public option -textcolor -default [list 10 10 10 255]

    public methodvariable textImage -default [list]

    constructor {args} {
	set itcl_options(-font) $defaultFont
	set itcl_options(-fontsize) $defaultFontSize
        set textImage [::ntk::widgetImage::Image create 1 1]
    }

    public method InitializeOptionValues {styleName widget state} {
        InitializeOptionValuesBase $styleName $widget $state
    }

    public method labelElementConfigure {option value} {
    }

    public method ElementSize {widthVar heightVar paddingVar} {
        upvar $widthVar width
        upvar $heightVar height
        upvar $paddingVar padding

	::ntk::widgetImage::Image createtext $textImage \
	            $itcl_options(-font) $itcl_options(-fontsize) \
		    $itcl_options(-text) $itcl_options(-textcolor) \
	            myWidth height
	::ntk::widgetImage::Image measuretext $textImage \
	            $itcl_options(-font) $itcl_options(-fontsize) \
		    "0" avgWidth avgHeight
        set reqWidth $itcl_options(-width)
	if {$reqWidth <= 0} {
	    set specWidth [expr {$avgWidth * -$reqWidth}]
	    if {$specWidth > $myWidth} {
	        set width $specWidth
	    } else {
	        set width $myWidth
	    }
	} else {
	    set width [expr {$avgWidth * $reqWidth}]
	}
puts stderr "TEXT!$itcl_options(-text)!$itcl_options(-width)!$avgWidth!$width!$height!"
    }

    public method ElementDraw {box state} {
        foreach {x y width height} $box break
    }
}

