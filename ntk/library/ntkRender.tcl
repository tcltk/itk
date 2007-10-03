::itcl::eclass ::ntk::classes::render {

    private common backgroundColor [list 16 33 65 255]
    private variable rendering 0

    public method render {args} {
        if {[llength $args] == 0} {
	    return -code error "expected a window to render"
	}
	foreach w $args {
	    $w configure -update 1
	}
	if {$rendering} {
	    return
	}
	set rendering 1
	after idle [::itcl::code $this renderNow]
    }
    protected method renderNow {} {
puts stderr "renderNow"
	set myObj [. obj]
puts stderr "myObj!$myObj!"
        $myObj setall $backgroundColor
        renderTree $myObj .
puts stderr "NOW!.f objsetimage $myObj!"
	.f objsetimage $myObj
    }

    protected method changeInTree {win} {
puts stderr "changeInTree!$win![$win cget -update]![$win cget -children]!"
        if {[$win cget -update]} {
            return 1
        }
        foreach child [$win cget -children] {
            if {[changeInTree $child]} {
                return 1
            }
        } 
        return 0
    }

    protected method renderRecurse {baseobj win x y} {
puts stderr "renderRecurse!$baseobj!$win!$x!$y![$win children]!"
        foreach child [$win children] {
            set cx [expr {$x + [$child cget -x]}]
            set cy [expr {$y + [$child cget -y]}]
            set r [$child cget -rotate]
            if {$r} {
                if {[$child cget -renderTreeData] eq ""} {
                    $child configure -renderTreeData [megaimage-blank 1 1]
                }
                [$child cget -renderTreeData] setdata [[$child cget -obj] getdata]
                renderRecurse [$child cget -renderTreeData] $child 0 0
                [$child cget -renderTreeData] rotate $r
puts stderr "BASE2a!$baseobj!$cx!$cy![$child cget -renderTreeData]!"
                $baseobj blendobj $cx $cy [$child cget -renderTreeData]
            } else {
puts stderr "BASE2b!$baseobj!$cx!$cy![$child obj]!"
                $baseobj blendobj $cx $cy [$child cget -obj]
                renderRecurse $baseobj $child $cx $cy
            }
            $child configure -update 0
        } 
    }

    public method renderTree {baseobj win} {
puts stderr "renderTree!WIN!$win![$win cget -children]!"
        foreach child [$win cget -children] {
puts stderr CHILD:$child
            if {[$child cget -renderTreeData] eq ""} {
                $child configure -renderTreeData [megaimage-blank 1 1]
            } 
            set back [$child cget -renderTreeData]
            if {[changeInTree $child]} {
puts stderr changeInChild:CHILD:$child
                $back setdata [[$child cget -obj] getdata]
                renderRecurse $back $child 0 0
if {0} {
                if {[set r [$child cget -rotate]]} {
                    $back rotate $r
                }
}
                $child configure -update 0
           }
puts stderr "BASE3!$baseobj!$back!"
#           $baseobj blendobj [$child cget -x] [$child cget -y] $back
           $baseobj blendobj 0 0 $back
        }
    }
}

