itcl::eclass ::ntk::classes::frame {
    inherit ::ntk::classes::window 

    private variable frameNs ""

    option -bg -default {} -validatemethod verifyColor -configuremethod config
    option -tile -default ""

    public method config {option value} {
puts stderr "config!$option!$value!"
        set options($option) $value
#puts stderr "calling draw!"
	draw
    }
    public method draw {} {
	set myTile [cget -tile]
puts stderr "myTile!$myTile!"
        set myObj [cget -obj]
        if {($myTile ne "") && ($myTile ne "<undefined>")} {
	    $myObj tile $myTile
	} else {
	    set myColor [cget -bg]
	    if {[llength $myColor] == 1} {
puts stderr " DRAW OBJ: $myObj setall $colors($myColor)"
	        $myObj setall $colors($myColor)
	    } else {
	        $myObj setall $myColor
	    }
	}
puts stderr "RENDER!$path!"
        render $path
    }
  
    constructor {args} {
        eval ::ntk::classes::window::constructor $args
    } {
        incr cntWindows
	if {$frameNs eq ""} {
	    set frameNs ::ntk::frames
	    namespace eval $frameNs {}
	}
	configure -tile {}
	configure -bg [defaultBackgroundColor]
	appendRedrawHandler [list [::itcl::code $this draw]]

	set myTile [cget -tile]
puts stderr "myTile!$myTile!"
        set myObj [cget -obj]
        if {($myTile ne "") && ($myTile ne "<undefined>")} {
	    $myObj tile $myTile
	} else {
	    set myColor [cget -bg]
	    if {[llength $myColor] == 1} {
puts stderr " DRAW OBJ: $myObj setall $colors($myColor)"
	        $myObj setall $colors($myColor)
	    } else {
	        $myObj setall $myColor
	    }
	}
puts stderr "RENDER!$path!"
        render $path
    }
}

