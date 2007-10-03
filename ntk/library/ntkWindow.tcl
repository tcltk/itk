::itcl::eclass ::ntk::classes::window {
    inherit ::ntk::classes::helpers ::ntk::classes::render

    protected common cntWindows 0
    protected common windows

    public variable parent [list]
    public variable children [list]
    public variable manager [list]
    public variable redraw [list]
    public variable destroy [list]
    public variable update 1
    public variable toplevel 0
    public variable removeFromManager [list]
    public variable renderTreeData [list]
    public variable bg [list]
    public variable obj [list]
    public variable path [list]


    public option -reqwidth 0
    public option -reqheight 0
    public option -width 0
    public option -height 0
    public option -x 0
    public option -y 0
    public option -rotate 0

    public option -buttonpress [list]
    public option -buttonrelease [list]
    public option -keypress [list]
    public option -keyrelease [list]
    public option -motion [list]
    
    private variable varOptions [list parent children manager redraw destroy update toplevel removeFromManager renderTreeData bg obj path]

    filter checkIsVarOption

    public method checkIsVarOption {args} {
	foreach {className methodName} [self target] break
	if {$methodName eq "unknown"} {
	    set what [lindex $args 0]
	    set value [lrange $args 1 1]
#puts stderr "checkIsVarOption called![join $args !]![self target]!"
	    if {[lsearch $varOptions $what]} {
	        if {[llength $value] == 0} {
	            return [set $what]
	        } else {
		   set $what $value
		   return $value
		}
	   }
	   return -code error "unknown method $methodName"
        } else {
	    set cmd "$methodName $args"
            return [uplevel 0 $cmd]
        }
    }

    public proc parent {path} {
#puts stderr "path!$path!"
        set parent [string range $path 0 [expr {[string last . $path] - 1}]]
	if {$parent eq ""} {
	    return .
	}
	return $parent
    }
    public proc toplevel {path} {
        set i [string first $path 1]
	if {$i < 0} {
	    return $path
	}
	incr i -1
	return [string range $path 0 $i]
    }
    public method children {{value {}}} {
#puts stderr "children!$this!$value!"
	if {$value eq ""} {
            return $children
	} else {
	    set children $value
	}
    }

    constructor {args} {
	incr cntWindows
	set path [string trimleft $this :]
        if {[info exists windows($path)]} {
	    return -code error "window $this already exists"
	}
#puts stderr "window constructor!$this!$path!"
        set windows($path) $path
	set parent [parent $path]
	eval configure $args
puts stderr "ARGS!$args!$options(-width)"
        set width $options(-width)
        set height $options(-height)
puts stderr "WIDTH!$width!$height!"
        set obj [megaimage-blank $width $height]
	#
	# Append the child to the parent's window list
	#
	if {$path ne "."} {
	    set pchildren [$parent children]
	    lappend pchildren $path
	    $parent children $pchildren
	}
        return $path
    }
    public method appendRedrawHandler {cmd} {
        set l [cget -redraw]
	lappend l $cmd
	configure -redraw $l
    }
}

