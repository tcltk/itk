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
# RCS: @(#) $Id: ntkRender.tcl,v 1.1.2.11 2007/10/18 21:52:39 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::render {

    private common backgroundColor [list 16 33 65 255]
    private variable rendering 0

    public method render {args} {
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
	after idle [::itcl::code $this renderNow]
    }

    protected method renderNow {} {
	set myObj [. obj]
        $myObj setall [. cget -bg]
        renderTree $myObj .
        set myWinId [. id]
#puts stderr "renderNow!ntk-put-image $myWinId $myObj!"
	ntk-resize-image $myWinId [. cget -width] [. cget -height]
	ntk-put-image  $myWinId $myObj
	set rendering 0
#puts stderr "renderNow END"
    }

    protected method changeInTree {path} {
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

    protected method renderRecurse {baseobj path x y} {
#puts stderr "renderRecurse!$baseobj!$path!$x!$y![$path children]!"
        foreach child [$path children] {
	    if {![$child cget -visible]} {
	        continue
	    }
            set cx [expr {$x + [$child x]}]
            set cy [expr {$y + [$child y]}]
            set r [$child cget -rotate]
	    set childObj [$child obj]
            if {$r} {
		set myRenderTreeData
                if {$myRenderTreeData] eq ""} {
                    $child renderTreeData [megaimage-blank 1 1]
                }
                $myRenderTreeData setdata [$childObj getdata]
                renderRecurse $myRenderTreeData] $child 0 0
                $myRenderTreeData rotate $r
#puts stderr "BASE2a!$baseobj!$cx!$cy!$myRenderTreeData!"
                $baseobj blendobj $cx $cy $myRenderTreeData
            } else {
#puts stderr "BASE2b!$baseobj!$cx!$cy!$childObj!"
                $baseobj blendobj $cx $cy $childObj
                renderRecurse $baseobj $child $cx $cy
            }
            $child update 0
        } 
    }

    public method renderTree {baseobj path} {
#puts stderr "renderTree!WIN!$path![$path children]!"
        foreach child [$path children] {
#puts stderr "CHILD:$child![$child x]![$child y]!"
	    if {![$child cget -visible]} {
	        continue
	    }
            if {[$child renderTreeData] eq ""} {
                $child renderTreeData [megaimage-blank 1 1]
            } 
            set back [$child renderTreeData]
            if {[changeInTree $child]} {
#puts stderr changeInChild:CHILD:$child
                $back setdata [[$child obj] getdata]
                renderRecurse $back $child 0 0
                if {[set r [$child cget -rotate]]} {
                    $back rotate $r
                }
                $child update 0
           }
#puts stderr "BLEND!$child![$child x]![$child y]!"
           $baseobj blendobj [$child x] [$child y] $back
        }
#puts stderr "renderTree END!WIN!$win![$path children]!"
    }
}

