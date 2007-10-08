::itcl::eclass ::ntk::classes::theme {
    inherit ::ntk::classes::window

    public proc themeButtonDrawBorder {path} {
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        themeDrawBorder [$path obj] 0 0 [$path cget -width] [$path cget -height] $low $high [$path cget -bd]
    }

    public proc themeButtonDrawPressedBorder {path} {
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        themeDrawBorder [$path obj] 0 0 [$path cget -width] [$path cget -height] $high $low [$path cget -bd]
    }

    public proc themeDrawBorder {obj x y width height low high bd} {
        incr bd -1
        while {$bd >= 0} {
            set x1 [expr {$x + $bd}]
            set y1 [expr {$y + $bd}]
            set x2 [expr {($x + $width) - $bd - 1}]
            set y2 [expr {($y + $height) - $bd - 1}]
            #top line
            $obj line $x1 $y1 $x2 $y1 $high
            #right line
            $obj line $x2 $y1 $x2 $y2 $low
            #bottom line
            $obj line $x1 $y2 $x2 $y2 $low
            #left line
            $obj line $x1 $y1 $x1 $y2 $high
            incr bd -1
        }
    }

    public proc themeDrawTextBackground {path} {
        # TODO add tile call with nice metallic background.
        [$path obj] setall [$path -bg]
    }

    public proc themeGetText {} {
        list -bg [list 255 255 255 255] -fg [list 0 0 0 255] -theme default -themeclass text
    }

    public proc themeLabelDrawBorder {path} {
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        themeDrawBorder [$path obj] 0 0 [$path cget -width] [$path cget -height] $low $high [$path cget -bd]
    }

    public proc themeScrollbarButton {path} {
#        NS_window $path 20 20
        $path pressed 0 direction up
        appendRedrawHandler $path [list themeScrollbarButtonDraw $path]
        foreach key [list pressed direction] {
#             structure-trace-key $path $key [list themeScrollbarButtonDraw $path]
        }
    }

    public proc themeScrollbarButtonDraw {path} {
        set low [list 20 20 20 255]
        set high [list 200 200 200 255]
        set w [$path width]
        set h [$path height]
        [$path obj] setall [[$path _parent] -bg]

        if {![$path pressed]} {
            themeDrawDorder [$path obj] 0 0 $w $h $low $high 1
        } else {
            themeDrawBorder [$path obj] 0 0 $w $h $high $low 1
        }
        switch -- [$path direction] {
        up {
            [$path obj] polygon [list 0 0 0 255] \
                    [expr {$w / 2}] 2  \
                    2 [expr {$h - 2}]  [expr {$w - 2}] [expr {$h - 2}]
          }
        down {
            [$path obj] polygon [list 0 0 0 255] \
                    2 2 [expr {$w - 2}] 2 \
                    [expr {$w / 2}] [expr {$h - 2}]         
          }
        left {
            [$path obj] polygon [list 0 0 0 255] \
                    2 [expr {$h / 2}] [expr {$w - 2}] 2 \
		    [expr {$w - 2}] [expr {$h - 2}]
          }
        right {
            [$path obj] polygon [list 0 0 0 255] \
                     2 2 [expr {$w - 2}] [expr {$h / 2}] 2 [expr {$h - 2}]
          }
        }
        $path render $path
    }

    public proc themeScrollbarTrough {path} {
#        NS_window $path 20 20
        appendRedrawHandler $path [list themeScrollbarTroughDraw $path]
    }

    public proc themeScrollbarTroughDraw {path} {
        [$path obj] setall [list 127 127 127 255]
        $path render $path
    }
}
