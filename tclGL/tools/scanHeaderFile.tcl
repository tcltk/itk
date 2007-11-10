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
    set lst [list]
    set params [string trim $params]
    set paramLst $params
    set paramLst [split $params ","]
    set paramNo 0
    foreach entry $paramLst {
	incr paramNo
        set entry [string trim $entry]
	set partLst [split $entry]
	set const ""
	if {[lindex $partLst 0] eq "const"} {
	   set const "const"
	   set partLst [lrange $partLst 1 end]
	}
	set numStars ""
	if {[llength $partLst] == 1} {
	    set paramName "param$paramNo"
	    set paramType [lindex $partLst 0]
	} else {
	    regexp {^([^ ]+)[ ]([* ]*)(.*)} [join $partLst] -> paramType numStars paramName
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
while {[gets stdin line] >= 0} {
    incr lineNo
    set line [string trimright $line \n]
    if {[string match "GLAPI void GLAPIENTRY*" $line]} {
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
    if {[regexp {^/[*] (.*) [*]/$} $line -> comment]} {
        # comment save for later use as hash table */
	set comment [string trim $comment]
        set comment [string trim $comment "*"]
	set comment [string trim $comment]
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
		puts [list DEFINE_GROUP $numComments $comment]
	        set hadDefine 1
            }
#puts stderr "defineStr!$name!$value!"
	    puts [list DEFINE $numComments $name $value]
	    set lastDefineLineNo $lineNo
	} else {
            if {[regexp {^GLAPI ([^ ]*) GLAPIENTRY ([^ ]*)[(]([^)]*)[)]} $line -> type name params]} {
                if {($type ne "void") && ([lsearch $glTypes $type] < 0)} {
                    puts stderr "unknown return type: $type inf function $name"
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
		    puts [list FUNC_GROUP $numFuncs $comment]
	            set hadFunc 1
                }
	        set parLst [splitParams $params]
                puts [list FUNC $numFuncs $name $type $parLst]
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
