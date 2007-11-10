#!/usr/bin/env tclsh

set funcHeader {
/*
 * ------------------------------------------------------------------------
 *  TclGL_%sCmd()
 *
 *  Handles the OpenGL %s command
 *  Returns a status TCL_OK/TCL_ERROR to indicate success/failure.
 * ------------------------------------------------------------------------
 */
/* ARGSUSED */

int
TclGL_%sCmd(
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
    TclGLShowArgs(1, "TclGL_%sCmd", objc, objv);}


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
    foreach entry $paramInfo {
        foreach {const type stars name} $entry break
	# nothing to do for plain void
	if {($type eq "void") && ($stars eq "")} {
	    continue
	}
	if {$const ne ""} {
	    set const "$const "
	}
        incr paramNo
        set myVarType int
        set myGetParamType int
        set myType $type
	append usageStr "$usageSep<($const$type$stars) $name"
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
            if {$const ne ""} {
	        lappend paramChecks "    if (GetPtrInParam(interp, infoPtr, objv\[[expr {$paramNo+1}]\], &$name, &paramLength$paramNo) != TCL_OK) {\n        return TCL_ERROR;\n    } "
                lappend paramDecls "    void $stars$name;"
                lappend paramDecls "    int paramLength$paramNo;"
	        set paramCheckDone 1
	    } else {
	        lappend outParams "    if (SetPtrOutParam(interp, infoPtr, objv\[[expr {$paramNo+1}]\], paramLength$paramNo, $name) != TCL_OK) {\n        return TCL_ERROR;\n    } "
                lappend paramDecls "    void $stars$name = NULL;"
		# to be fixed != 0!!
                lappend paramDecls "    int paramLength$paramNo = 0;"
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
set numFuncGroups -1
set numFuncs -1
set outFd [open ../generic/tclGLInitFuncGroupHashTables.c w]
set methodInfoFd [open ../generic/tclGLMethodInfos.c w]
set funcFd [open ../generic/tclGLFuncs.c w]
set procFd [open ../generic/tclGLProcNames.c w]
set openCurly "{"
set closeCurly "}"
while {[gets stdin line] >= 0} {
    set isNormalReturn 1
    foreach {type grpIdx name} $line break
    switch $type {
    FUNC_GROUP {
        incr numFuncGroups
        puts $outFd "    objPtr = InitFuncGroup(interp, infoPtr, $numFuncGroups, \"$name\");"
      }
    FUNC {
	set usageStr ""
        set returnTypeStr [lindex $line 3]
        set paramLst [lindex $line 4]
	switch $returnTypeStr {
	void {
	     set returnType "TCL_GLvoid"
	  }
	GLint {
	     set returnType "TCL_GLint"
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
puts stderr "funny return type!$returnTypeStr!"
	     set returnType "TCL_GLint"
	  }
	}
	set paramInfos [handleParams $paramLst]
        foreach {paramNo usageStr paramDecls paramChecks callParamInfos outParams callType} $paramInfos break
        incr numFuncs
        puts $outFd "    InitFunc(interp, infoPtr, objPtr, $numFuncGroups, $numFuncs, \"$name\", $returnType, $paramNo, \"$usageStr\");"
        puts $methodInfoFd "    { \"::ntk::gl::GL::$name\",\n            NULL, TclGL_${name}Cmd },"
        puts $procFd "Tcl_ObjCmdProc TclGL_${name}Cmd;"
        puts $funcFd [format $funcHeader $name $name $name $openCurly]
	puts $funcFd [join $paramDecls \n]
	puts $funcFd "    TclGLFunc *funcPtr;"
	switch $returnType {
	TCL_GLenum {
	    puts $funcFd "    $returnTypeStr retVal;"
	    puts $funcFd "    const char *enumStr;"
	  }
	TCL_GLboolean -
	TCL_GLint -
	TCL_GLuint {
	    puts $funcFd "    $returnTypeStr retVal;"
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
	set callTypeStr "GLfunction_${returnTypeStr}_[join $callType _]"
	regsub -all { } $callTypeStr {} callTypeStr
	regsub -all {[*]} $callTypeStr {Ptr} callTypeStr
	set callTypeParamStr [join $callType ", "]
	set callTypeDef "typedef $returnTypeStr (* $callTypeStr)($callTypeParamStr);"
	if {[lsearch $funcTypeDefs $callTypeDef] < 0} {
	    lappend funcTypeDefs $callTypeDef
	}
	switch $returnType {
	TCL_GLvoid {
            puts $funcFd "    ((${callTypeStr})funcPtr->funcPtr)($callParamInfos);"
          }
	TCL_GLboolean {
            puts $funcFd "    retVal = (($callTypeStr)funcPtr->funcPtr)($callParamInfos);"
	    puts $funcFd "    Tcl_SetObjResult(interp, Tcl_NewBooleanObj((int)retVal));"
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
set fd [open ../generic/tclGLFuncSizes.h w]
puts $fd "#define TCL_NUM_GL_FUNC_GROUPS $numFuncGroups"
puts $fd "#define TCL_NUM_GL_FUNCS $numFuncs"
puts $fd ""
puts $fd [join $funcTypeDefs \n]
close $fd
