#!/usr/bin/env tclsh

set glTypes [list \
    GLenum \
    GLboolean \
    GLbitfield \
    GLvoid \
    GLbyte \
    GLshort \
    GLint \
    GLubyte \
    GLushort \
    GLuint \
    GLsizei \
    GLfloat \
    GLclampf \
    GLdouble \
    GLclampd \
]

proc splitParams {params} {
    upvar name funcName

    set lst [list]
    set params [string trim $params]
    set paramLst $params
    set paramLst [split $params ","]
    set paramNo 0
    foreach entry $paramLst {
	incr paramNo
        set entry [string trim $entry]
	set orig_entry $entry
	while {[regsub -all {[*] [*]} $entry {**} entry]} {
	}
	set partLst [split $entry]
	set const ""
	if {[lindex $partLst 0] eq "const"} {
	   set const "const"
	   set partLst [lrange $partLst 1 end]
	}
	set numStars ""
	if {![regexp {^([^* ]+)[ ]*([* ]*)(.*)} [join $partLst] -> paramType numStars paramName]} {
	    if {![regexp {[*]+} [join $partLst]  -> xx]} {
	        set paramType [lindex $partLst 0]
	        set paramName ""
	    } else {
	        puts stderr "funny param!$partLst!"
	    }
	}
	lappend lst [list $const $paramType $numStars $paramName]
    }
    return $lst
}

set lineNo 0
set numComments -1
set numFuncs -1
set numTypedefs -1
set comments [list]
set lastDefineLineNo -1
set procNameLst [list]
set methodNameLst [list]
set cmdNameLst [list]
set funcLst [list]
set hadDefine 0
set hadFunc 0
set hadTypedef 0
set comment2 ""
while {[gets stdin line] >= 0} {
    incr lineNo
    set line [string trimright $line \n]
    if {[string match "GLAPI * *APIENTRY*" $line]} {
        while {![regexp {.*[(].*[)]} $line]} {
	    if {[gets stdin line2] < 0} {
	        break
	    }
            incr lineNo
            set line2 [string trimright $line2 \n]
            set line2 [string trim $line2]
	    set line "$line $line2"
        }
    }
    if {[string match "/*" $line]} {
        while {![regexp {/[*].*[*]/} $line]} {
	    if {[gets stdin line2] < 0} {
	        break
	    }
            incr lineNo
            set line2 [string trimright $line2 \n]
            set line2 [string trim $line2]
	    set line "$line $line2"
        }
    }
#puts stderr "LINE!$line![regexp {^/[*] } $line]!"
    if {[regexp {^#ifndef (GL_.*)[ ]*} $line -> comment2]} {
        # used instead of comment of there is no comment
        set comment ""
        set hadDefine 0
        set hadFunc 0
        set hadTypedef 0
    }
    if {[regexp {^/[*] (.*) [*]/$} $line -> comment]} {
        # comment save for later use
	set comment [string trim $comment]
        set comment [string trim $comment "*"]
	set comment [string trim $comment]
	set comment2 ""
        set commentLineNo $lineNo
#puts stderr "comment!$commentLineNo!$comment!"
        set hadDefine 0
        set hadFunc 0
        set hadTypedef 0
    } else {
        if {[regexp {^#define (GL_[^ \t]+)[ \t]+(0x[0-9a-fA-F]*)$} $line -> name value]} {
	    if {$comment eq "Boolean values"} {
	        continue
	    }
	    if {!$hadDefine} {
                incr numComments
		if {$comment2 != ""} {
		   set comment $comment2
		}
		puts [list DEFINE_GROUP $numComments $comment]
	        set hadDefine 1
            }
#puts stderr "defineStr!$name!$value!"
	    puts [list DEFINE $numComments $name $value]
	    set lastDefineLineNo $lineNo
	} else {
	    set haveInfo 0
            if {[regexp {^GLAPI (.*) GLAPIENTRY ([^ ]*)[ ]*[(]([^)]*)[)]} $line -> type name params]} {
		set haveInfo 1
	    } else {
                if {[regexp {^GLAPI (.*) APIENTRY ([^ ]*)[ ]*[(]([^)]*)[)]} $line -> type name params]} {
		    set haveInfo 1
	        }
	    }
	    if {$haveInfo} {
		set typeLst [split $type]
		set const ""
		set stars ""
		if {[llength $typeLst] > 1} {
		    if {[lindex $typeLst 0] eq "const"} {
		        set const const
		        set type [lrange $typeLst 1 end]
		    }
		}
	        if {![regexp {^([^* ]+)[ ]*([* ]*)} [join $type] -> type2 stars]} {
	            if {![regexp {[*]+} [join $type]  -> xx]} {
	                set type [lindex $type 0]
	            } else {
	                puts stderr "funny return type!$type!"
	            }
	        } else {
	            set type $type2
	        }
if {0} {
	    if {[regexp {(.*)([*]+)} $type -> type2 stars]} {
	        set type $type2
	    }
}
                if {($type ne "void") && ([lsearch $glTypes $type] < 0)} {
                    puts stderr "unknown return type: $type in function $name"
		}
		set name [string trim $name]
		switch -glob -- $name {
		*MESA {
		    continue
		  }
		}
		incr numFuncs
	        if {!$hadFunc} {
                    incr numComments
		    if {$comment2 != ""} {
		       set comment $comment2
		    }
		    puts [list FUNC_GROUP $numFuncs $comment]
	            set hadFunc 1
                }
	        set parLst [splitParams $params]
                puts [list FUNC $numFuncs $name [list $const $type $stars] $parLst]
#puts stderr "PARAMS![join $parLst !]!"
	    } else {
	        if {[regexp {^[ ]*typedef[ \t]+([^ ]+)[ \t]+[(]([^)]+)[)][ \t]+[(]([^)]+)[)]} $line -> typeType typeNamePart typeParams]} {
#puts "TYPEDEF!type!$typeNamePart!$typeParams!"
	            if {!$hadTypedef} {
                        incr numTypedefs
		        puts [list TYPEDEF_GROUP $numTypedefs $comment]
	                set hadTypedef 1
                    }
		    set typeParLst [splitParams $typeParams]
		    regsub {APIENTRYP } $typeNamePart {} typeName
		    set typeName [string trim $typeName]
                    puts [list TYPEDEF $numTypedefs $typeName $typeType $typeParLst]
		}
	    }
        }
    }
}
