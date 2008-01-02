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
# RCS: @(#) $Id: styleLayout.tcl,v 1.1.2.2 2008/01/02 19:58:57 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::styleLayout {

    private common _width -1
    private common _height -1
    private common _padding -1

    private proc nodeSize {layout styleName idx value widget state widthVar heightVar paddingVar} {
        upvar $widthVar width
	upvar $heightVar height
	upvar $paddingVar padding

	if {[llength $value] == 0} {
	    set width 0
	    set height 0
	    return
	}
	set nodeNames [dict keys $layout]
	set nodeName [lindex $nodeNames $idx]
	set children ""
puts stderr "VAL!$value!"
	if {[dict exists $value -children]} {
	    set children [dict get $value -children]
	}
	set elementClassName [::ntk::classes::styleTheme::getElementClassName $nodeName]
	if {$elementClassName eq ""} {
	    return -code error "no such element: $nodeName"
	}
        set element [$widget getElementObject $nodeName $elementClassName]
#puts stderr "NodeListSize!$nodeName!$elementClassName!$element!"
	if {$element eq ""} {
	    return -code error "no such element object: $nodeName"
	}
        $element InitializeOptionValues $styleName $widget $state
        set elementWidth 0
        set elementHeight 0
        set elementPadding [list 0 0 0 0]
        $element ElementSize elementWidth elementHeight elementPadding
puts stderr "ELEMW!$element!$elementWidth!$elementHeight!$elementPadding!"
	set subWidth 0
	set subHeight 0
        NodeListSize $children $styleName 0 $widget $state subWidth subHeight
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

    private proc NodeListSize {layout styleName idx widget state widthVar heightVar} {
	upvar $widthVar width
	upvar $heightVar height

	if {$layout eq ""} {
	    set width 0
	    set height 0
	    return
	}
	set nodeNames [dict keys $layout]
#puts stderr "nodeNames!$nodeNames!$idx![llength $nodeNames]!"
	if {$idx >= [llength $nodeNames]} {
puts stderr "IDX outside nodeNames"
	    set width 0
	    set height 0
	    return
	}
	set nodeName [lindex $nodeNames $idx]
puts stderr "NodeListSize!HANDLE!$nodeName!"
        set value [dict get $layout $nodeName]
	nodeSize $layout $styleName $idx $value $widget $state myWidth myHeight myPadding
	set restWidth 0
	set restHeight 0
	incr idx
        NodeListSize $layout $styleName $idx $widget $state restWidth restHeight
	set packSide none
	if {[dict exists $value -side]} {
	   set packSide [dict get $value -side]
	}
	set widthDone 0
	set heightDone 0
	switch $packSide {
	left -
	right {
	    set width [expr {$width + $restWidth}]
	    set widthDone 1
	  }
	top -
	bottom {
	    set height [expr {$height + $restHeight}]
	    set heightDone 1
	  }
	}
	if {!$widthDone} {
	    if {$myWidth > $restWidth} {
	        set width $myWidth
	    } else {
	        set width $restWidth
	    }
	}
	if {!$heightDone} {
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
	NodeListSize $layout $styleName 0 $widget $state _width _height
puts stderr "WI!$_width!$_height!$_padding!"
    }

    protected proc StickBox {parcel width height layout} {
	set sticky none
	if {[dict exists $layout -sticky]} {
	    set sticky [dict get $layout -sticky]
	}
        foreach {x y w h} $parcel break
	if {$width > $w} {
	    set width $w
	}
	if {$height > $h} {
	    set height $h
	}
        set dx [expr {$w - $width}]
        set dy [expr {$h - $height}]
        # X coordinate adjustment
	if {[string first e $sticky] && [string first w $sticky]} {
	    # no-op -- use entire parcel width
	} else {
	    switch -glob $sticky {
	    *w* {
	        set w $width
	      }
	    *e* {
		incr x $dx
	        set w $width
	      }
            default {
	        incr x [expr {$dx / 2}]
	        set w $width
	      }
	    }
	}
        # Y coordinate adjustment
	if {[string first n $sticky] && [string first s $sticky]} {
	    # no-op -- use entire parcel width
	} else {
	    switch -glob $sticky {
	    *n* {
	        set h $height
	      }
	    *s* {
		incr y $dy
	        set h $height
	      }
            default {
	        incr y [expr {$dy / 2}]
	        set h $height
	      }
	    }
	}
        return [list $x $y $w $h]
    }

    protected proc PositionBox {cavity width height layout} {
        set side none
	if {[dict exists $layout -side]} {
	    set side [dict get $layout -side]
	}
        set fill none
	if {[dict exists $layout -fill]} {
	    set fill [dict get $layout -fill]
	}
        if {$fill ne "none"} {
	    set parcel $cavity
	} else {
	    switch $side {
	    top {
	        set parcel [PackTop $cavity $height]
	      }
	    left {
	        set parcel [PackLeft $cavity $width]
	      }
	    bottom {
	        set parcel [PackBottom $cavity $height]
	      }
	    right {
	        set parcel [PackRight $cavity $width]
	      }
	    none {
	        set parcel $cavity
	      }
	    }
	}
        return [StickBox $parcel $width $height $layout]
    }

    protected proc PadBox {parcel padding} {
puts stderr "PadBox!$parcel!$padding!"
        foreach {x y w h} $parcel break
	incr x [lindex $padding 0]
	incr y [lindex $padding 1]
	incr w [expr {-([lindex $padding 0] + [lindex $padding 2])}]
	incr h [expr {-([lindex $padding 1] + [lindex $padding 3])}]
	if {$w <= 0} {
	    set w 1
	}
	if {$h <= 0} {
	    set h 1
	}
	return [list $x $y $w $h]
    }

    protected proc PlaceNodeList {layout styleName idx widget state cavity} {
	if {[llength $layout] == 0} {
	    return
	}
	set nodeNames [dict keys $layout]
	set nextIdx 0
	while {$nextIdx < [llength $nodeNames]} {
	    set nodeName [lindex $nodeNames $nextIdx]
	    set value [dict get $layout $nodeName]
	    nodeSize $layout $styleName $nextIdx $value $widget $state myWidth myHeight myPadding
	    set parcel [PositionBox $cavity $myWidth $myHeight $value]
puts stderr "PlaceNodeList!$nodeName!parcel:$parcel!$value!"
	    if {[dict exists $value -children]} {
	        set children [dict get $value -children]
	        if {[llength $children] > 0} {
	            set childBox [PadBox $parcel $myPadding]
		    PlaceNodeList $children $styleName 0 $widget $state $childBox
		}
	    }
	    dict set value -parcel $parcel
puts stderr "VALUE!$value!"
	    incr nextIdx
	}
    }

    public proc doLayout {widget styleName state} {
        set layout [::ntk::classes::styleTheme::getLayout $styleName]
	if {$layout eq ""} {
	    return -code error "no such layout: $styleName"
	}
        PlaceNodeList $layout $styleName 0 $widget $state [list 0 0 $_width $_height]
puts stderr "LAYOUT END!$layout!"
    }
}

