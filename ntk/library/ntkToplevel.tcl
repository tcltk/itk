itcl::nwidget ::ntk::classes::toplevel {
    private common cntToplevels 0
    private common toplevels
    component base
    delegate option -reqwidth to base
    delegate option -reqheight to base
    delegate option -width to base
    delegate option -height to base
    delegate option -x to base
    delegate option -y to base
    delegate option -rotate to base
    delegate option -buttonpress to base
    delegate option -buttonrelease to base
    delegate option -keypress to base
    delegate option -keyrelease to base
    delegate method getValue to base
    delegate method setValue to base
    delegate method obj to base as [list getValue obj]

    constructor {width height} {
	incr cntToplevels
	set path [string trimleft $this :]
        if {[info exists toplevels($path)]} {
	    return -code error "window $this already exists"
	}
        set toplevels($path) $path
        set obj [megaimage-blank $width $height]
        set base [::ntk::classes::base ::ntk::classes::_win$cntToplevels $path $width $height $obj $parent 0 0 0 [list 16 33 65 255]]
        return $path
    }
}

