# -*- tcl -*-

# itk.decls --
#
#	This file contains the declarations for all supported public
#	functions that are exported by the Itk library via the stubs table.
#	This file is used to generate the itkDecls.h file.
#
# See the file "license.terms" for information on usage and redistribution
# of this file, and for a DISCLAIMER OF ALL WARRANTIES.

# public API
library itk
interface itk
hooks {itkInt}
epoch 0
scspec ITKAPI

# Declare each of the functions in the public Itk interface.  Note that
# the an index should never be reused for a different function in order
# to preserve backwards compatibility.


#
#  Exported functions:
#

declare 0 {
    int Itk_Init(Tcl_Interp *interp)
}
declare 1 {
    int Itk_SafeInit(Tcl_Interp *interp)
}


#
#  Functions needed for the Archetype base class:
#

declare 13 {
    int Itk_ArchetypeInit(Tcl_Interp *interp)
}



# private API
interface itkInt

#
# Functions used within the package, but not considered "public"
#

#
#  Functions used internally by this package:
#

declare 2 {
    int Itk_ConfigBodyCmd(void *cdata, Tcl_Interp *interp,
	Tcl_Size objc, Tcl_Obj *const objv[])
}
declare 3 {
    int Itk_UsualCmd(void *cdata, Tcl_Interp *interp, Tcl_Size objc,
	Tcl_Obj *const objv[])
}

#
#  Functions for managing options included in class definitions:
#

declare 4 {
    int Itk_ClassOptionDefineCmd(void *cdata, Tcl_Interp *interp,
	Tcl_Size objc, Tcl_Obj *const objv[])
}
declare 5 {
    int Itk_ClassOptionIllegalCmd(void *cdata, Tcl_Interp *interp, \
	Tcl_Size objc, Tcl_Obj *const objv[])
}
declare 6 {
    int Itk_ConfigClassOption(Tcl_Interp *interp, ItclObject *contextObj, \
	void *cdata, const char *newVal)
}
declare 7 {
    ItkClassOptTable* Itk_CreateClassOptTable(Tcl_Interp *interp, \
	ItclClass *cdefn)
}
declare 8 {
    ItkClassOptTable* Itk_FindClassOptTable(ItclClass *cdefn)
}
#declare 9 {
#    void Itk_DeleteClassOptTable(Tcl_Interp *interp, ItclClass *cdefn)
#}
declare 10 {
    int Itk_CreateClassOption(Tcl_Interp *interp, ItclClass *cdefn,
	const char *switchName, const char *resName, const char *resClass, const char *defVal,
	const char *config, ItkClassOption **optPtr)
}
declare 11 {
    ItkClassOption* Itk_FindClassOption(ItclClass *cdefn, const char *switchName)
}
declare 12 {
    void Itk_DelClassOption(ItkClassOption *opt)
}

#
#  Functions for maintaining the ordered option list:
#

declare 14 {
    void Itk_OptListInit(ItkOptList *olist, Tcl_HashTable *options)
}
declare 15 {
    void Itk_OptListFree(ItkOptList *olist)
}
declare 16 {
    void Itk_OptListAdd(ItkOptList *olist, Tcl_HashEntry *entry)
}
declare 17 {
    void Itk_OptListRemove(ItkOptList *olist, Tcl_HashEntry *entry)
}


