#!/usr/bin/env tclsh

set funcHeader {
/*
 * ------------------------------------------------------------------------
 *  TclGLext_%sCmd()
 *
 *  Handles the OpenGL %s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGLext_%sCmd(
    ClientData clientData, /* infoPtr */
    Tcl_Interp *interp,    /* current interpreter */
    int objc,              /* number of arguments */
    Tcl_Obj *CONST objv[]) /* argument objects */
%s
    Tcl_HashEntry *hPtr;
    TclGLInfo *infoPtr;
    int glResult;}

set initPart {
    glResult = 0;
    hPtr = NULL;
    infoPtr = (TclGLInfo *)clientData;
    TclGLShowArgs(1, "TclGLext_%sCmd", objc, objv);}


proc handleParams {paramInfo} {
    upvar name funcName

    set paramNo -1
    set usageStr ""
    set paramDecls ""
    set paramChecks [list]
    set outParams [list]
    set callParamInfos ""
    set usageSep ""
    set callParamSep ""
    set callType [list]
if {$funcName eq "glMultiDrawElements"} {
puts stderr "PARAMS!$paramInfo!"
}
    foreach entry $paramInfo {
        foreach {const type stars name} $entry break
	# nothing to do for plain void
	if {($type eq "void") && ($stars eq "")} {
	    continue
	}
        incr paramNo
	if {$const ne ""} {
	    set const "$const "
	}
	if {$name eq ""} {
	    set name param[expr {$paramNo+1}]
	}
        set myVarType int
        set myGetParamType int
        set myType $type
	append usageStr "$usageSep<($const$type$stars) $name>"
	set usageSep " "
	append callParamInfos "${callParamSep}(${myType}$stars)$name"
	set callParamSep ", "
	set paramCheckDone 0
	set callTypePart "int"
        switch $type {
        GLenum {
            set myGetParamType enum
          }
        GLboolean {
          }
        GLbitfield {
            set myGetParamType bitfield
          }
        GLvoid {
          }
        GLbyte {
          }
        GLshort {
          }
        GLint {
          }
        GLubyte {
          }
        GLushort {
          }
        GLuint {
          }
	GLhalfNV {
	  }
        GLsizeiptrARB {
          }
        GLintptrARB {
          }
        GLsizeiptr {
          }
        GLintptr {
          }
        GLcharARB {
          }
        GLhandleARB {
          }
        GLsizei {
          }
        GLfloat {
            set myGetParamType double
            set myVarType double
	    set callTypePart float
          }
        GLclampf {
            set myGetParamType double
            set myVarType double
	    set callTypePart float
          }
        GLdouble {
            set myGetParamType double
            set myVarType double
	    set callTypePart double
          }
        GLclampd {
            set myGetParamType double
            set myVarType double
	    set callTypePart double
          }
        default {
            puts stderr "funny param type!$type!"
            continue
          }
        }
	if {$stars ne ""} {
	    set callTypePart void
	}
	lappend callType $callTypePart$stars
	if {$stars ne ""} {
	    set myNo [expr {$paramNo+1}]
            if {$const ne ""} {
		switch [string length $stars] {
		1 {
	        lappend paramChecks "    if (GetPtrInParam(interp, infoPtr, objv\[$myNo\], &$name, &paramLength$myNo) != TCL_OK) {\n        return TCL_ERROR;\n    } "
		  }
		2 {
	        lappend paramChecks "    if (GetPtrPtrInParam(interp, infoPtr, objv\[$myNo\], &$name, &paramLength$myNo) != TCL_OK) {\n        return TCL_ERROR;\n    } "
		  }
		default {
		    puts stderr "ERROR cannot handle stars!$stars!"
		  }
		}
                lappend paramDecls "    void $stars$name;"
                lappend paramDecls "    int paramLength$myNo;"
	        set paramCheckDone 1
	    } else {
	        lappend outParams "    if (SetPtrOutParam(interp, infoPtr, objv\[$myNo\], paramLength$myNo, $name) != TCL_OK) {\n        return TCL_ERROR;\n    } "
                lappend paramDecls "    void $stars$name = NULL;"
		# to be fixed != 0!!
                lappend paramDecls "    int paramLength$myNo = 0;"
	        set paramCheckDone 1
puts stderr "NOT YET!$funcName!$entry!"
	    }
	}
        if {!$paramCheckDone} {
	    lappend paramChecks "    if (Get[string totitle ${myGetParamType}]Param(interp, infoPtr, objv\[[expr {$paramNo+1}]\], &$name) != TCL_OK) {\n        return TCL_ERROR;\n    } "
            lappend paramDecls "    $myVarType $name;"
	}
#puts stderr "PARAM!$paramNo!$entry!"
    }
#puts stderr "PA!$paramNo!$usageStr!$paramDecls!$paramChecks!$callParamInfos!$outParams!"
    return [list $paramNo $usageStr $paramDecls $paramChecks $callParamInfos $outParams $callType]
}

set funcTypeDefs [list]
set oldfuncTypeDefs [list]
set fd [open ../generic/tclGLFuncSizes.h r]
gets $fd line1
gets $fd line2
set numFuncGroups [lindex [split $line1] 2]
set numFuncs [lindex [split $line2] 2]
while {[gets $fd line] >= 0} {
    if {[string length [string trim $line]] == 0} {
        continue
    }
    lappend oldfuncTypeDefs $line
}
close $fd
set outFd [open ../generic/tclGLInitFuncGroupHashTables.c a]
set methodInfoFd [open ../generic/tclGLExtMethodInfos.c w]
set funcFd [open ../generic/tclGLExtFuncs.c w]
set procFd [open ../generic/tclGLExtProcNames.c w]
set openCurly "{"
set closeCurly "}"
set useIt 1
while {[gets stdin line] >= 0} {
    set isNormalReturn 1
    foreach {type grpIdx name} $line break
    switch $type {
    FUNC_GROUP {
	switch -glob $name {
	*_ATI* -
	*_3DFX* -
	*_APPLE* -
	*_MESA* -
	*_OML* -
	*_NV* -
	*_INGR* -
	*_IBM* -
	*_INTEL* -
	*_S3* -
	*_HP* -
	*_PGI* -
	*_SUN* -
	*_SGI* {
	     set useIt 0
	     continue
	  }
	default {
	     set useIt 1
	  }
	}
        incr numFuncGroups
        puts $outFd "    objPtr = InitFuncGroup(interp, infoPtr, $numFuncGroups, \"$name\");"
      }
    FUNC {
	if {!$useIt} {
	    continue
	}
	set usageStr ""
	set returnTypeLst [lindex $line 3]
	foreach {returnConst returnTypeStr returnStars} $returnTypeLst break
        set paramLst [lindex $line 4]
	switch $returnTypeStr {
	GLvoid -
	void {
	     set returnType "TCL_GLvoid"
	  }
	GLubyte {
	     set returnType "TCL_GLubyte"
	  }
	GLint {
	     set returnType "TCL_GLint"
	  }
	GLhandleARB {
	     set returnType "TCL_GLuint"
	  }
	GLuint {
	     set returnType "TCL_GLuint"
	  }
	GLboolean {
	     set returnType "TCL_GLboolean"
	  }
	GLenum {
	     set returnType "TCL_GLenum"
	  }
	default {
puts stderr "funny return type!$returnTypeStr!$returnTypeLst!"
	     set returnType "TCL_GLint"
	  }
	}
	set paramInfos [handleParams $paramLst]
        foreach {paramNo usageStr paramDecls paramChecks callParamInfos outParams callType} $paramInfos break
        incr numFuncs
	set returnFlags $returnType
	if {$returnStars ne ""} {
	    set returnFlags "${returnFlags}|TCL_GLptr"
	}
        puts $outFd "    InitFunc(interp, infoPtr, objPtr, $numFuncGroups, $numFuncs, \"$name\", $returnFlags, $paramNo, \"$usageStr\");"
        puts $methodInfoFd "    { \"::ntk::gl::GLext::$name\",\n            NULL, TclGLext_${name}Cmd },"
        puts $procFd "Tcl_ObjCmdProc TclGLext_${name}Cmd;"
        puts $funcFd [format $funcHeader $name $name $name $openCurly]
	puts $funcFd [join $paramDecls \n]
	puts $funcFd "    TclGLFunc *funcPtr;"
	switch $returnType {
	TCL_GLenum {
	    puts $funcFd "    $returnConst $returnTypeStr ${returnStars}retVal;"
	    puts $funcFd "    const char *enumStr;"
	  }
	TCL_GLboolean -
	TCL_GLubyte -
	TCL_GLint -
	TCL_GLuint {
	    puts $funcFd "    $returnConst $returnTypeStr ${returnStars}retVal;"
	  }
	}
	puts $funcFd [format $initPart $name]
	if {$name eq "glBegin"} {
	    puts $funcFd "    infoPtr->noGLGetError = 1;"
	}
	if {$name eq "glEnd"} {
	    puts $funcFd "    infoPtr->noGLGetError = 0;"
	}
	puts $funcFd "    if (CheckNumParams(interp, infoPtr, $numFuncs, objc, [expr {$paramNo+1}]) != TCL_OK) {\n        return TCL_ERROR;\n    }"
	if {[llength $paramChecks] > 0} {
	    puts $funcFd [join $paramChecks \n]
	}
        puts $funcFd "    funcPtr = infoPtr->funcv\[$numFuncs\];"
#puts stderr "callType!$callType!"
	set myConst ""
	if {$returnConst ne ""} {
	    set myConst "_const"
	}
	set myStars ""
	if {$returnStars ne ""} {
	    set myStars "_star"
	}
	set signature "${myConst}${returnTypeStr}$myStars"
	set callTypeStr "GLfunction_${signature}_[join $callType _]"
	regsub -all { } $callTypeStr {} callTypeStr
	regsub -all {[*]} $callTypeStr {Ptr} callTypeStr
	set callTypeParamStr [join $callType ", "]
	set callTypeDef "typedef $returnConst $returnTypeStr $returnStars (* $callTypeStr)($callTypeParamStr);"
	if {[lsearch $oldfuncTypeDefs $callTypeDef] < 0} {
	    if {[lsearch $funcTypeDefs $callTypeDef] < 0} {
	        lappend funcTypeDefs $callTypeDef
	    }
	}
	switch $returnType {
	TCL_GLvoid {
            puts $funcFd "    ((${callTypeStr})funcPtr->funcPtr)($callParamInfos);"
          }
	TCL_GLboolean {
            puts $funcFd "    retVal = (($callTypeStr)funcPtr->funcPtr)($callParamInfos);"
	    puts $funcFd "    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));"
          }
	TCL_GLubyte {
            puts $funcFd "    retVal = (($callTypeStr)funcPtr->funcPtr)($callParamInfos);"
	    if {$returnStars ne ""} {
	        puts $funcFd "    Tcl_SetObjResult(interp, Tcl_NewStringObj((const char *)retVal, -1));"
	    } else {
	        puts $funcFd "    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));"
	    }
          }
	TCL_GLint -
	TCL_GLuint {
            puts $funcFd "    retVal = (($callTypeStr)funcPtr->funcPtr)($callParamInfos);"
	    puts $funcFd "    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)retVal));"
          }
	TCL_GLenum {
            puts $funcFd "    retVal = (($callTypeStr)funcPtr->funcPtr)($callParamInfos);"
            puts $funcFd "    hPtr = Tcl_FindHashEntry(&infoPtr->glDefineStrings, (char *)retVal);"
            puts $funcFd "    if (hPtr == NULL) {"
            puts $funcFd "        char buf\[20\];"
            puts $funcFd "        sprintf(buf, \"0x%08x\", retVal);"
            puts $funcFd "        Tcl_AppendResult(interp, \"no such define value: \\\"\","
            puts $funcFd "            buf, \"\\\"\", NULL);"
            puts $funcFd "        return TCL_ERROR;"
            puts $funcFd "    }"

	    puts $funcFd "    enumStr = (const char *)Tcl_GetHashValue(hPtr);"

	    puts $funcFd "    Tcl_SetObjResult(interp, Tcl_NewStringObj(enumStr, -1));"
          }
	default {
puts stderr "NOT YET RET!$returnType!"
	  }
	}
	if {[llength $outParams] > 0} {
	    puts $funcFd [join $outParams \n]
	}
	if {$isNormalReturn} {
            puts $funcFd "    return GetGLError(interp, infoPtr);\n$closeCurly"
	} else {
	}
      }
    }
}
close $outFd
close $methodInfoFd
close $funcFd
close $procFd
set fd [open ../generic/tclGLFuncSizes.h a]
puts $fd "#undef TCL_NUM_GL_FUNC_GROUPS"
puts $fd "#undef TCL_NUM_GL_FUNCS"
puts $fd "#define TCL_NUM_GL_FUNC_GROUPS $numFuncGroups"
puts $fd "#define TCL_NUM_GL_FUNCS $numFuncs"
puts $fd ""
puts $fd [join $funcTypeDefs \n]
close $fd
