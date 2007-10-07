itcl::eclass ::ntk::classes::toplevel {
    inherit ::ntk::classes::window

    private variable id
    private variable toplevel
    private variable toplevelDraw [list]

    public option -bg -default [list 16 33 65 255] -validatemethod verifyColor -configuremethod toplevelConfig

    private method toplevelConfig {option value} {
        set itcl_options($option) $value
        if {$toplevelDraw ne ""} {
            $toplevelDraw $path
	}
    }

    constructor {args} {
        eval ::ntk::classes::window::constructor $args
    } {
        set id ""
        set toplevel 1
        return [path]
    }
    
    public method toplevelDraw {path} {
#puts stderr "toplevelDraw!$path!"
       set myTile [cget -tile]
        set myObj [obj]
        if {$myTile ne ""} {
            $myObj tile $myTile
        } else {
            set myColor [$path cget -bg]
            if {[llength $myColor] == 1} {
                $myObj setall $colors($myColor)
            } else {
                $myObj setall $myColor
            }
        }
        $path render $path
    }

}

