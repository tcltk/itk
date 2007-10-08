itcl::eclass ::ntk::classes::entry {
    inherit ::ntk::classes::window 

    private variable buttonDraw [list]
    private variable textobj [list]
    private variable destroy [list]
    private variable cursoroffset 0
    private variable xslide 0
    private variable offsetmap [list]

    public option -keypress -default {}
    public option -buttonpress -default {}
    public option -font -default {} -configuremethod entryConfig
    public option -fontsize -default {} -configuremethod entryConfig
    public option -text -default {} -configuremethod entryConfig
    public option -textcolor -default {} -validatemethod verifyColor -configuremethod entryConfig
    public option -cursorcolor -default [list 0 0 255 255] -configuremethod entryConfig
    public option -bg -default {} -validatemethod verifyColor -configuremethod entryConfig

    private method entryConfig {option value} {
        set itcl_options($option) $value
        if {$entryDraw ne ""} {
            $entryDraw [path]
        }
    }

    public method textobj {{value {}}} {
	if {$value eq ""} {
            return $textobj
	} else {
	    set textobj $value
	}
    }

    public method destroy {{value {}}} {
	if {$value eq ""} {
            return $destroy
	} else {
	    set destroy $value
	}
    }

    public method cursoroffset {{value {}}} {
	if {$value eq ""} {
            return $cursoroffset
	} else {
	    set cursoroffset $value
	}
    }

    public method xslide {{value {}}} {
	if {$value eq ""} {
            return $xslide
	} else {
	    set xslide $value
	}
    }

    public method offsetmap {{value {}}} {
	if {$value eq ""} {
            return $offsetmap
	} else {
	    set offsetmap $value
	}
    }

    constructor {args} {
        eval ::ntk::classes::window::constructor -width 160 -height 1
    } {
        freetype $defaultFont 12 "_^" [list 0 0 0 255] width height
	configure -height $height
	set itcl_options(-font) $defaultFont
	set itcl_options(-fontsize) 12
	set itcl_options(-textcolor) $defaultTextColor
	set itcl_options(-bg) [list 255 255 255 255]
	set itcl_options(-keypress) entryKeypress
	set itcl_options(-buttonpress) entryButtonpress
	set textobj [megaimage-blank 1 1]
	set destroy entryDestroy
	set path [path]
	eval configure $args
	appendRedrawHandler [list $path entryDraw $path]

	set entryDraw entryDraw
	entryDraw $path
        return $path
    }

    public method entryButtonpress {path button x y globalx globaly} {
        foreach w [getFocus] {
            if {$w eq $path} {
                entryCursorSet $path [expr {$x - [$path xslide]}]
                return
            }
        }
        focus $path
    }

    public method entryCursorIncrOffset {path i} {
        set co [$path cursoroffset]
        if {(($i < 0) && ($co > 0)) || (($i > 0) && 
               (($co < [string length [$path cget -text]]))} {
           incr co $i
           $path cursoroffset $co
           entryDraw $path
        }
    }

    public method entryCursorSet {path x} {
        set lasti 0
        set cursoroffset 0
        set cursormap [list]
        set map [$path offsetmap]
        lassign [[$path textobj] getsize] width height

        #
        # Build a map of low and high ranges for each cursor position.
        #
        for {set i 0} {$i < [llength $map]} {incr i} {
            set cur [lindex $map $i]
            set next [lindex $map [expr {$i + 1}]]

            if {$next eq ""} {
                lappend cursormap $lasti $width
                continue
            }
            lappend cursormap $lasti [set lasti [expr {$cur + (($next - $cur) / 2)}]]
        }

        #
        # Find the cursor offset using the map.
        #
        set i 0
        foreach {x1 x2} $cursormap {
            if {$x >= $x1 && $x < $x2} {
                $path cursoroffset $i
                entryDraw $path
                return
            }
            incr i
        }
    }

    public method entryDestroy {path} {
        rename [$path textobj] {}
    }

    public method entryDraw {path} {
        set myObj [$path obj]
        set myOffsetmap [$path offsetmap]
        set cx 0
        if {[llength $offsetmap]} {
            set cx [lindex $offsetmap [$path cursoroffset]]
        }
        if {$cx eq ""} {
            set cx 0
        }
        lassign [$obj getsize] objw objh
        if {$cx > 0} {
            incr cx -1
        }
        $path xslide 1
        if {$cx >= [$path width]} {
            $path xslide [expr {[$path cget -width] - $cx}]
        } 
        $myObj setall [$path cget -bg]
        $myObj blendobj [$path xslide] 0 [$path textobj]
        $myObj line $cx 0 $cx $objh [$path cget -cursorcolor]
        set cx [expr {$cx + 1}]
        $myObj line $cx 0 $cx $objh [$path cget -cursorcolor]
        $path render $path
    }

    public method entryKeypress {path value keysym keycode} {
        set myText [$path cget -text]
        switch -- $keysym {
        normal {
            append myText $value
            $path configure -text $myText
            entryCursorIncrOffset $path 1
          } 
        backspace {
            set co [$path cursoroffset]
            incr co -1
            $path configure -text [string range $myText 0 [expr {$co - 1}]][string range $myText [expr {$co + 1}] end]
            entryCursorIncrOffset $path -1
          }
        left {
            entryCursorIncrOffset $path -1
          }
        right {
            entryCursorIncrOffset $path 1
          }
        delete {
            set co [$path cursoroffset]
            $path configure -text [string range $myText 0 [expr {$co - 1}]][string range $myText [expr {$co + 1}] end]
          }
        return {
	    return
	  }
        }
        entryDraw $path
    }

    public method entryTextCallback {path value} {
        set rgbadata [freetype [$path cget -font] \
                [$path cget -fontsize] $value [$path cget -textcolor] \
		width height offsetmap]
        $path offsetmap $offsetmap
        set textobj [$path textobj]
        $textobj setdata $rgbadata
        requestSize $path [expr {$width + 2}] [expr {$height + 2}]
        return 1
    }
}
