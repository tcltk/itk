#---------------------------------------------------------------------------
# ntkWidget ntkWindow.tcl --
#
# This file contains a ntkWidget window command implementation
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
# RCS: @(#) $Id: ntkWindow.tcl,v 1.1.2.10 2007/10/15 09:24:52 wiede Exp $
#--------------------------------------------------------------------------

::itcl::extendedclass ::ntk::classes::window {
    inherit ::ntk::classes::helpers ::ntk::classes::render

    protected common cntWindows 0
    protected common windows

    private variable parent [list]
    private variable children [list]
    private variable manager [list]
    private variable redraw [list]
    private variable update 1
    private variable removeFromManager [list]
    private variable renderTreeData [list]

    protected variable destroy [list]
    protected variable toplevel 0
    protected variable obj [list]
    protected variable wpath [list]

    public component geometryManager
    public component verticalScrollbar
    public component horizontalScrollbar

    public option -x -default 0 -configuremethod windowConfig
    public option -y -default 0 -configuremethod windowConfig
    public option -width -default 0 -configuremethod windowConfig
    public option -height -default 0 -configuremethod windowConfig
    public option -rotate -default 0 -configuremethod windowConfig
    public option -reqwidth -default 0 -configuremethod windowConfig
    public option -reqheight -default 0 -configuremethod windowConfig
    public option -buttonpress -default [list] -configuremethod windowConfig
    public option -buttonrelease -default [list] -configuremethod windowConfig
    public option -keypress -default [list] -configuremethod windowConfig
    public option -keyrelease -default [list] -configuremethod windowConfig
    public option -motion -default [list] -configuremethod windowConfig
    public option -visible -default 1 -validatemethod verifyBoolean \
            -configuremethod windowConfig
    
    public method windowConfig {option value} {
#puts stderr "windowConfig![namespace current]!$option!$value!"
        set itcl_options($option) $value
        windowDraw $wpath
    }

    public proc windowParent {path} {
        set parent [string range $path 0 [expr {[string last . $path] - 1}]]
	if {$parent eq ""} {
	    return .
	}
	return $parent
    }

    public proc toplevelPath {path} {
        set i [string first . $path 1]
	if {$i < 0} {
	    return $path
	}
	incr i -1
	return [string range $path 0 $i]
    }

    public method parent {{value {}}} {
	if {$value eq ""} {
            return $parent
	} else {
	    set parent $value
	}
    }

    public method children {{value {}}} {
	if {$value eq ""} {
            return $children
	} else {
	    set children $value
	}
    }

    public method manager {{value {}}} {
	if {$value eq ""} {
            return $manager
	} else {
	    set manager $value
	}
    }

    public method redraw {{value {}}} {
	if {$value eq ""} {
            return $redraw
	} else {
	    set redraw $value
	}
    }

    public method destroy {{value {}}} {
	if {$value eq ""} {
            return $destroy
	} else {
	    set destroy $value
	}
    }

    public method update {{value {}}} {
	if {$value eq ""} {
            return $update
	} else {
	    set update $value
	}
    }

    public method toplevel {{value {}}} {
	if {$value eq ""} {
            return $toplevel
	} else {
	    set toplevel $value
	}
    }

    public method removeFromManager {{value {}}} {
	if {$value eq ""} {
            return $removeFromManager
	} else {
	    set removeFromManager $value
	}
    }

    public method renderTreeData {{value {}}} {
	if {$value eq ""} {
            return $renderTreeData
	} else {
	    set renderTreeData $value
	}
    }

    public method obj {{value {}}} {
	if {$value eq ""} {
            return $obj
	} else {
	    set obj $value
	}
    }

    public method wpath {{value {}}} {
	if {$value eq ""} {
            return $wpath
	} else {
	    set wpath $value
	}
    }

    constructor {args} {
#puts stderr "constructor OPTIONS![info exists itcl_options]!"
	incr cntWindows
	set wpath [string trimleft $this :]
        if {[info exists windows($wpath)]} {
	    return -code error "window $this already exists"
	}
        set windows($wpath) $wpath
	set parent [windowParent $wpath]
puts stderr "ARGS![join $args !]!"
	eval configure $args
        set obj [megaimage-blank $itcl_options(-width) $itcl_options(-height)]
	#
	# Append the child to the parent's window list
	#
	if {$wpath ne "."} {
	    set pchildren [$parent children]
	    lappend pchildren $wpath
	    $parent children $pchildren
	}
	set destroy [list destroyWindow $wpath]
	set geometryManager [list]
	set verticalScrollbar [list]
	set horizontalScrollbar [list]
        return $wpath
    }

    public method appendRedrawHandler {cmd} {
        lappend redraw $cmd
    }
    
    public method appendDestroyHandler {cmd} {
	lappend destroy $cmd
    }
    
    public method destroyWindow {path} {
         if {![info exists windows($path)]} {
	     #NO ERROR
	     return
	 }
         # Destroy this window's children.
         foreach c [$path children] {
             destroyWindow $c 
         }  

         # Invoke destroy handlers.
         foreach cmd [$path destroy] {
             uplevel #0 $cmd
         }

         set myParent [windowParent $path]

         # Remove $path from the parent's list of children.
         set pchildren [$parent children]
         set i [lsearch -exact $pchildren $path]
         set pchildren [lreplace $pchildren $i $i]
         $parent children $pchildren
 
         if {[$path removeFromManager] ne ""} {
             [$path removeFromManager] $path
         }
         # If this window was a parent for managed children then free the manager.
#       set m $manager
#       if {$m ne ""} {
#          [$m free] $m
#       }
        inputDestroy $path

        rename [$path obj] {}
        if {[$path renderTreeData] ne ""} {
            rename [$path renderTreeData] {}
        }
        unset windows($path)
    }

    public method dispatchRedraw {path} {
        foreach cmd [$path redraw] {
            uplevel #0 $cmd
        }
    }

    public method raise {path} {
        if {$path eq "."} {
	    return
	}
	if {![info exists windows($path)]} {
	    return -code error "invalid window: $path"
        }
	set lparent [windowParent $path]
	set c [$parent children]
	set i [lsearch -exact $c $path]
	$parent children [linsert [lreplace $c $i $i] end $path]
    }

    public method redrawWindow {path} {
        [$path obj] setsize [$path cget -width] [$path cget -height]
    }

    public method remanageWindow {path} {
        set p [$path parent]
	set myManager [$p manager]
	if {$myManager eq ""} {
	    $path configure -width [$path cget -reqwidth] -height [$path cget -reqheight]
	    set w [$path cget -width]
	    set h [$path cget -height]
	    if {$w <= 0} {set w 1}
	    if {$h <= 0} {set h 1}
	    [$path obj] setsize $w $h
	    dispatchRedraw $path
	    return
	}
        $myManager remanage] $p
    }

    public method requestSize {path width height} {
        $path configure -reqwidth $width -reqheight $height
	remanageWindow $path
    }

    public method windowDraw {path} {
#puts stderr "windowDraw!$path!$obj!"
	if {$obj eq ""} {
	    return
        }
        set myColor [$path cget -bg]
        if {[llength $myColor] == 1} {
            $obj setall $colors($myColor)
        } else {
            $obj setall $myColor
        }
        render $path
    }

    public method setGeometryManager {manager} {
        set geometryManager $manager
    }
}
