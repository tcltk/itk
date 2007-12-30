#---------------------------------------------------------------------------
# ntkWidget ntkStyleLayout.tcl --
#
# This file contains a ntkWidget StyleLayout commands implementation
#
# this code is influenced by the tile/ttk implementation written by
# Joe English
#
# Copyright (c) 2007 by Arnulf P. Wiedemann
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: styleLayout.tcl,v 1.1.2.1 2007/12/30 23:03:47 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::styleLayout {

    private common _width -1
    private common _height -1
    private common _padding -1

    private proc nodeSize {styleName children element widget state widthVar heightVar paddingVar} {
        upvar $widthVar width
	upvar $heightVar height
	upvar $paddingVar padding

        $element InitializeOptionValues $styleName $widget $state
        set elementWidth 0
        set elementHeight 0
        set elementPadding [list 0 0 0 0]
        $element ElementSize elementWidth elementHeight elementPadding
puts stderr "ELEMW!$element!$elementWidth!$elementHeight!$elementPadding!"
	set subWidth 0
	set subHeight 0
        # FIX ME need code for children of element here !!
#        layoutPartSize $children $styleName $widget $state subWidth subHeight
puts stderr "SUB!$element!$subWidth!$subHeight!"
	incr subWidth [lindex $elementPadding 0]
	incr subWidth [lindex $elementPadding 2]
	incr subHeight [lindex $elementPadding 1]
	incr subHeight [lindex $elementPadding 3]
	if {$elementWidth > $subWidth} {
	    set width $elementWidth
	} else {
	    set width $subWidth
	}
	if {$elementHeight > $subHeight} {
	    set height $elementHeight
	} else {
	    set height $subHeight
	}
        set padding $elementPadding
puts stderr "END!$width!$height!$padding!"
    }

    private proc layoutPartSize {layout styleName widget state widthVar heightVar} {
	upvar $widthVar width
	upvar $heightVar height

	foreach partName [dict keys $layout] {
	    set children ""
            set value [dict get $layout $partName]
	    if {[dict exists $value -children]} {
	        set children [dict get $value -children]
	    }
	    set elementClassName [::ntk::classes::styleTheme::getElementClassName $partName]
	    if {$elementClassName eq ""} {
	        return -code error "no such element: $partName"
	    }
            set element [$widget getElementObject $partName $elementClassName]
#puts stderr "layoutPart!$partName!$elementClassName!$element!"
	    if {$element eq ""} {
	        return -code error "no such element object: $partName"
	    }
	    nodeSize $styleName $children $element $widget $state myWidth myHeight myPadding
	    set restWidth 0
	    set restHeight 0
            layoutPartSize $children $styleName $widget $state restWidth restHeight
	    # FIX ME need code for PACK_LEFT and PACK_RIGHT HERE !!
	    if {$myWidth > $restWidth} {
	        set width $myWidth
	    } else {
	        set width $restWidth
	    }
	    if {$myHeight > $restHeight} {
	        set height $myHeight
	    } else {
	        set height $restHeight
	    }
	}
    }

    public proc layoutSize {widget styleName state} {
        set layout [::ntk::classes::styleTheme::getLayout $styleName]
	if {$layout eq ""} {
	    return -code error "no such layout: $styleName"
	}
	set _width 0
	set _height 0
	set _padding [list 0 0 0 0]
	layoutPartSize $layout $styleName $widget $state _width _height
puts stderr "WI!$_width!$_height!$_padding!"
    }
}

