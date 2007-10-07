::itcl::eclass ::ntk::classes::window {
    inherit ::ntk::classes::helpers ::ntk::classes::render

    protected common cntWindows 0
    protected common windows

    private variable parent [list]
    private variable children [list]
    private variable manager [list]
    private variable redraw [list]
    private variable destroy [list]
    private variable update 1
    private variable toplevel 0
    private variable removeFromManager [list]
    private variable renderTreeData [list]
    private variable bg [list]
    private variable obj [list]
    private variable path [list]


    public option -x -default 0 -configuremethod config
    public option -y -default 0 -configuremethod config
    public option -width -default 0 -configuremethod config
    public option -height -default 0 -configuremethod config
    public option -rotate -default 0 -configuremethod config

    public option -reqwidth 0
    public option -reqheight 0

    public option -buttonpress [list]
    public option -buttonrelease [list]
    public option -keypress [list]
    public option -keyrelease [list]
    public option -motion [list]
    
    public method config {option value} {
#puts stderr "config![namespace current]!$option!$value!"
        set itcl_options($option) $value
        if {$renderTreeData ne ""} {
	    $renderTreeData [path]
	}
    }

    public proc windowParent {path} {
        set parent [string range $path 0 [expr {[string last . $path] - 1}]]
	if {$parent eq ""} {
	    return .
	}
	return $parent
    }

    public proc windowToplevel {path} {
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

    public method bg {{value {}}} {
	if {$value eq ""} {
            return $bg
	} else {
	    set bg $value
	}
    }

    public method obj {{value {}}} {
	if {$value eq ""} {
            return $obj
	} else {
	    set obj $value
	}
    }

    public method path {{value {}}} {
	if {$value eq ""} {
            return $path
	} else {
	    set path $value
	}
    }

    constructor {args} {
#puts stderr "constructor OPTIONS![info exists itcl_options]!"
	incr cntWindows
	set path [string trimleft $this :]
        if {[info exists windows($path)]} {
	    return -code error "window $this already exists"
	}
        set windows($path) $path
	set parent [windowParent $path]
	eval configure $args
        set width [cget -width]
        set height [cget -height]
        set obj [megaimage-blank $width $height]
	#
	# Append the child to the parent's window list
	#
	if {$path ne "."} {
	    set pchildren [$parent children]
	    lappend pchildren $path
	    $parent children $pchildren
	}
	set destroy [list destroyWindow $path]
        return $path
    }

    public method appendRedrawHandler {cmd} {
        set l [redraw]
	lappend l $cmd
	redraw $l
    }
    
    public method appendDestroyHandler {path cmd} {
        set l [$path destroy]
	lappend l $cmd
	$path destroy $l
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
#       set m [$path manager]
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
        #puts stderr REDRAW:$path
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
        [$path obj] setsize [$path width] [$path height]
    }

    public method remanageWindow {path} {
        set p [$path parent]
	set myManager [$p manager]
	if {$myManager eq ""} {
	    $path width [$path reqwidth] height [$path reqheight]
	    set w [$path width]
	    set h [$path height]
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
}
