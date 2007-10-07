package require Itcl 4.0
lappend auto_path .
package require ntkWidget

set classes [::itcl::find classes ::ntk::*]
set ntkInfo [dict create classes [list]]
foreach cls $classes {
    dict with ntkInfo {
        lappend classes $cls [list methods [list] procs [list] variables [list] commons [list] options [list]]
    }
    set meths [namespace eval ${cls} { info function }]
    foreach entry $meths {
	set methodName [namespace tail $entry]
	set funcInfo [namespace eval ${cls} { info function $methodName}]
	foreach {protection type _name argInfo bodyInfo} $funcInfo break
	if {[string match "@itcl-builtin-*" $bodyInfo]} {
	    continue
	}
        dict with ntkInfo classes $cls {
            switch $type {
	    proc {
	        lappend procs [list $methodName [list protection $protection args $argInfo body $bodyInfo]]
	      }
	    method {
	        lappend methods [list $methodName [list protection $protection args $argInfo body $bodyInfo]]
              }
	    }
        }
    }
    set vars [namespace eval ${cls} { info variable }]
    foreach entry $vars {
	set varName [namespace tail $entry]
	switch $varName {
	this {
	    continue
	  }
	}
	set protection [namespace eval $cls { info variable $varName -protection }]
	set type [namespace eval $cls { info variable $varName -type }]
	set init [namespace eval $cls { info variable $varName -init }]
	set config [namespace eval $cls { info variable $varName -config }]
        dict with ntkInfo classes $cls {
            switch $type {
	    common {
	        lappend commons [list $varName [list protection $protection init $init config $config]]
	      }
	    variable {
	        lappend variables [list $varName [list protection $protection init $init config $config]]
              }
	    }
        }
    }
    set opts [namespace eval ${cls} { info option }]
    foreach entry $opts {
	set optName [namespace tail $entry]
	set head [namespace qualifiers $entry]
	if {![string equal $head $cls]} {
	    continue
	}
	set protection [namespace eval $cls { info option $optName -protection }]
	set resource [namespace eval $cls { info option $optName -resource }]
	set class [namespace eval $cls { info option $optName -class }]
	set default [namespace eval $cls { info option $optName -default }]
	set cgetmethod [namespace eval $cls { info option $optName -cgetmethod }]
	set configuremethod [namespace eval $cls { info option $optName -configuremethod }]
	set validatemethod [namespace eval $cls { info option $optName -validatemethod }]
        dict with ntkInfo classes $cls {
	    lappend options [list $optName [list protection $protection resource $resource class $class default $default cgetmethod $cgetmethod configuremethod $configuremethod validatemethod $validatemethod]]
        }
    }
}

puts stderr "CL!$classes![dict get $ntkInfo classes]!"
