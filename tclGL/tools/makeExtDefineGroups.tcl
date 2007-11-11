#!/usr/bin/env tclsh

set fd [open ../generic/tclGLDefineSizes.h r]
gets $fd line1
gets $fd line2
close $fd
set numDefineGroups [lindex [split $line1] 2]
set numDefines [lindex [split $line2] 2]
puts stderr "numDefineGroups!$numDefineGroups!$numDefines!"
set out_fd [open ../generic/tclGLInitDefineGroupHashTables.c a]
while {[gets stdin line] >= 0} {
    foreach {type grpIdx name} $line break
    switch $type {
    DEFINE_GROUP {
        incr numDefineGroups
        puts $out_fd "    objPtr = InitDefineGroup(interp, infoPtr, $numDefineGroups, \"$name\");"
      }
    DEFINE {
        set defineValue [lindex $line 3]
        incr numDefines
        puts $out_fd "    InitDefine(interp, infoPtr, objPtr, $numDefineGroups, $numDefines, \"$name\", \"$defineValue\", $defineValue);"
      }
    }
}
close $out_fd
set fd [open ../generic/tclGLDefineSizes.h w]
puts $fd "#define TCL_NUM_GL_DEFINE_GROUPS $numDefineGroups"
puts $fd "#define TCL_NUM_GL_DEFINE $numDefines"
close $fd
