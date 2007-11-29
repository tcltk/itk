#---------------------------------------------------------------------------
# ntkWidget ntkRender.tcl --
#
# This file contains a ntkWidget render command implementation
#
# ntkWidget is derived from the NexTk implementation written by
# George Peter Staplin
#
# ntkWidget is a reimplementation of Tk based on megapkg, ntk and freetypeext
# written by George Peter Staplin
#
# Copyright (c) 2007 by Arnulf P. Wiedemann and George Peter Staplin
#
# See the file "license.terms" for information on usage and redistribution of
# this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# RCS: @(#) $Id: ntkRender.tcl,v 1.1.2.19 2007/11/29 20:17:47 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::render {

    private common backgroundColor [list 16 33 65 255]
    private common rendering 0

    public proc render {args} {
        if {[llength $args] == 0} {
	    return -code error "expected a window to render"
	}
	foreach w $args {
	    $w update 1
	}
	if {$rendering} {
	    return
	}
	set rendering 1
	after idle [list ::ntk::classes::render::renderNow]
    }

    public proc renderNow {} {
	set myObj [. windowImage]
        ::ntk::widgetImage::Image fill $myObj [. cget -bg]
        renderTree $myObj .
        set myWinId [. id]
        . drawPixels $myWinId .
	set rendering 0
#puts stderr "renderNow END"
    }

    protected proc changeInTree {path} {
#puts stderr "changeInTree!$win![$path update]![$path children]!"
	if {![$path cget -visible]} {
	    return 0
	}
        if {[$path update]} {
            return 1
        }
        foreach child [$path children] {
            if {[changeInTree $child]} {
                return 1
            }
        } 
        return 0
    }

    protected proc renderRecurse {baseWindowImage path x y} {
#puts stderr "renderRecurse!$baseWindowImage!$path!$x!$y![$path children]!"
        foreach child [$path children] {
	    if {![$child cget -visible]} {
	        continue
	    }
            set cx [expr {$x + [$child cget -xoffset]}]
            set cy [expr {$y + [$child cget -yoffset]}]
            set r [$child cget -rotate]
	    set childWindowImage [$child windowImage]
            if {$r} {
		set myRenderTreeData [$child renderTreeData]
                if {$myRenderTreeData eq ""} {
                    $child renderTreeData [::ntk::widgetImage::Image create 1 1]
		    set myRenderTreeData [$child renderTreeData]
                }
                ::ntk::widgetImage::Image setdata $myRenderTreeData [::ntk::widgetImage::Image getdata $childWindowImage]
                renderRecurse $myRenderTreeData] $child 0 0
                ::ntk::widgetImage::Image rotate $myRenderTreeData $r
#puts stderr "BASE2a!$baseWindowImage!$cx!$cy!$myRenderTreeData!"
                ::ntk::widgetImage::Image blendwidget $baseWindowImage $cx $cy $myRenderTreeData
            } else {
#puts stderr "BASE2b!$baseWindowImage!$cx!$cy!$childWindowImage!"
                ::ntk::widgetImage::Image blendwidget $baseWindowImage $cx $cy $childWindowImage
                renderRecurse $baseWindowImage $child $cx $cy
            }
            $child update 0
        } 
    }

    public proc renderTree {baseWindowImage path} {
#puts stderr "renderTree!WIN!$path![$path children]!"
        foreach child [$path children] {
#puts stderr "CHILD:$child![$child cget -xoffset]![$child cget -yoffset]!"
	    if {![$child cget -visible]} {
	        continue
	    }
            if {[$child renderTreeData] eq ""} {
                $child renderTreeData [::ntk::widgetImage::Image create 1 1]
            } 
            set back [$child renderTreeData]
            if {[changeInTree $child]} {
#puts stderr "changeInChild:CHILD:$child!$back![$child windowImage]!"
                ::ntk::widgetImage::Image setdata $back [$child windowImage]
                renderRecurse $back $child 0 0
                if {[set r [$child cget -rotate]]} {
                    ::ntk::widgetImage::Image rotate $back $r
                }
                $child update 0
           }
#puts stderr "BLEND!$child![$child cget -xoffset]![$child cget -yoffset]![$back getsize]!"
           ::ntk::widgetImage::Image blendwidget $baseWindowImage [$child cget -xoffset] [$child cget -yoffset] $back
        }
#puts stderr "renderTree END!WIN!$path![$path children]!"
    }
}

