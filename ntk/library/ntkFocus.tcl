proc NS_focus {path} {
 set ::NS_focus_list [list $path]}

proc NS_focus-append {path} {
 lappend ::NS_focus_list $path}

proc NS_get-focus {} {
 return $::NS_focus_list}

