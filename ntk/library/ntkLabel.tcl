itcl::eclass ::ntk::classes::label {
    inherit ::ntk::classes::theme 

    private variable labelDraw [list]

    public option -font -default {} -configuremethod labelConfig
    public option -fontsize -default {} -configuremethod labelConfig
    public option -text -default {} -configuremethod labelConfig
    public option -textcolor -default {} -validatemethod verifyColor -configuremethod labelConfig
    public option -bg -default {} -validatemethod verifyColor -configuremethod labelConfig
    public option -bd -default 0 -validatemethod verifyBorder -configuremethod labelConfig

    private method labelConfig {option value} {
        set itcl_options($option) $value
        if {$labelDraw ne ""} {
            $labelDraw [path]
        }
    }

    constructor {args} {
        eval ::ntk::classes::window::constructor -width 10 -height 10
    } {
	set itcl_options(-font) $defaultFont
	set itcl_options(-fontsize) 12
	set itcl_options(-bg) [defaultBackgroundColor]
	set path [path]
	eval configure $args
	appendRedrawHandler [list $path labelDraw $path]

	set labelDraw labelDraw
	labelDraw $path
        return $path
    }

    public method labelDraw {path} {
        set myObj [obj]
        set myColor [$path cget -bg]
        if {[llength $myColor] == 1} {
            $myObj setall $colors($myColor)
        } else {
            $myObj setall $myColor
        }
        if {[$path cget -bd] > 0} {
            themeLabelDrawBorder $path
        }
        if {[string length [$path cget -text]]} {
#puts stderr "PAR! [$path cget -font] [$path cget -fontsize] \
	            [$path cget -text] [$path cget -textcolor] !"
            set rgba [freetype [$path cget -font] [$path cget -fontsize] \
	            [$path cget -text] [$path cget -textcolor] \
	            myWidth myHeight]

            set x [expr {[$path cget -width] / 2 - $myWidth / 2}]
            set y [expr {[$path cget -height] / 2 - $myHeight / 2}]
            set tmp [megaimage $rgba]
            [$path obj] blendobj $x $y $tmp
            rename $tmp {}
        }
        $path render $path
    }

    public method labelRequestSize {path} {
        if {![string length [$path cget -text]]} {
	    return
	}
        freetype-measure [$path cget -font] [$path cget -fontsize] \
	        [$path cget -text] width height
        set bdt [expr {[$path cget -bd] * 2}]
        set rwidth [expr {$width + $bdt + 2}]
        set rheight [expr {$height + $bdt + 2}]
        requestSize $path $rwidth $rheight
    }
}
