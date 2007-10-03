::itcl::eclass ::ntk::classes::helpers {
    protected common colors

    private common rendering 0
    private common backgroundColor [list 16 33 65 255]

    constructor {args} {
        array set colors {
	    red {255 0 0 255}
	    green {0 255 0 255}
	    blue {0 0 255 255}

	    black {0 0 0 255}
	    white {255 255 255 255}

	    grey {127 127 127 255}

	    orange {255 165 0 255}
	    royalblue {65 105 225 255}
	    hummeryellow {... ... ... ...}
        }
    }
    protected proc verifyColor {option value} {
        switch -- [llength $value] {
        1 {
            #
            # Look in the symbolic colormap.
            #
            set lcvalue [string tolower $value]
            if {![info exist colors($lcvalue)]} {
                return -code error "invalid symbolic color $value"
            }
            #
            # The color is valid, so set it.
            #
puts stderr "COL!$colors($lcvalue)!"
            set options($option) $colors($lcvalue)
            return 0
          }
         
        4 {
            foreach c $value {
                if {![string is integer -strict $c]} {
                    return -code error "invalid color component in list (not an integer): $value"
                }
            }
            return 1
          }
        default {
            return -code error "invalid color format: $value"
          }
        }
    }
    protected proc defaultBackgroundColor {} {
        return $colors(grey)
    }
}
