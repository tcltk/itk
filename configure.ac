#!/bin/bash -norc
dnl	This file is an input file used by the GNU "autoconf" program to
dnl	generate the file "configure", which is run during Tcl installation
dnl	to configure the system for the local environment.

#-----------------------------------------------------------------------
# Sample configure.ac for Tcl Extensions.  The only places you should
# need to modify this file are marked by the string __CHANGE__
#-----------------------------------------------------------------------

#-----------------------------------------------------------------------
# __CHANGE__
# Set your package name and version numbers here.
#
# This initializes the environment with PACKAGE_NAME and PACKAGE_VERSION
# set as provided.  These will also be added as -D defs in your Makefile
# so you can encode the package version directly into the source files.
# This will also define a special symbol for Windows (BUILD_<PACKAGE_NAME>
# so that we create the export library with the dll.
#-----------------------------------------------------------------------

AC_INIT([itk], [4.2.3])

#--------------------------------------------------------------------
# Call TEA_INIT as the first TEA_ macro to set up initial vars.
# This will define a ${TEA_PLATFORM} variable == "unix" or "windows"
# as well as PKG_LIB_FILE and PKG_STUB_LIB_FILE.
#--------------------------------------------------------------------

TEA_INIT()

#--------------------------------------------------------------------
# Try to ensure the existence of a tclconfig directory in either
# $srcdir or the current dir, if one can't be found in $srcdir.
# If this package is being built as part of a bundle then a tclconfig
# directory might exist in $srcdir's parent directory.
#--------------------------------------------------------------------

AC_PROG_LN_S
CONFIG_CLEAN_FILES=
if test ! -d $srcdir/tclconfig ; then
    if test -d $srcdir/../tclconfig ; then
	$LN_S $srcdir/../tclconfig tclconfig
	CONFIG_CLEAN_FILES=tclconfig
    fi
fi
AC_SUBST(CONFIG_CLEAN_FILES)

#--------------------------------------------------------------------
# Tell autoconf where to find tcl.m4 and install.sh.
#--------------------------------------------------------------------

AC_CONFIG_AUX_DIR(tclconfig)

#--------------------------------------------------------------------
# Load the tclConfig.sh file
#--------------------------------------------------------------------

TEA_PATH_TCLCONFIG
TEA_LOAD_TCLCONFIG

#--------------------------------------------------------------------
# Load the tkConfig.sh file if necessary (Tk extension)
#--------------------------------------------------------------------

TEA_PATH_TKCONFIG
TEA_LOAD_TKCONFIG

#--------------------------------------------------------------------
# Load the itclConfig.sh file
#--------------------------------------------------------------------

TEA_PATH_CONFIG(itcl)
TEA_LOAD_CONFIG(itcl)

ITCL_INCLUDES="-I\"`${CYGPATH} ${itcl_SRC_DIR}/generic`\""

#-----------------------------------------------------------------------
# Handle the --prefix=... option by defaulting to what Tcl gave.
# Must be called after TEA_LOAD_TCLCONFIG and before TEA_SETUP_COMPILER.
#-----------------------------------------------------------------------

TEA_PREFIX

#-----------------------------------------------------------------------
# Standard compiler checks.
# This sets up CC by using the CC env var, or looks for gcc otherwise.
# This also calls AC_PROG_CC and a few others to create the basic setup
# necessary to compile executables.
#-----------------------------------------------------------------------

TEA_SETUP_COMPILER

#-----------------------------------------------------------------------
# __CHANGE__
# Specify the C source files to compile in TEA_ADD_SOURCES,
# public headers that need to be installed in TEA_ADD_HEADERS,
# stub library C source files to compile in TEA_ADD_STUB_SOURCES,
# and runtime Tcl library files in TEA_ADD_TCL_SOURCES.
# This defines PKG(_STUB)_SOURCES, PKG(_STUB)_OBJECTS, PKG_HEADERS
# and PKG_TCL_SOURCES.
#-----------------------------------------------------------------------

TEA_ADD_SOURCES([
                itkArchBase.c
	        itkArchetype.c
	        itkBase.c
                itkCmd.c
                itkHelpers.c
                itkOption.c
	        itkUtil.c
                itkStubInit.c
                ])
TEA_ADD_HEADERS([generic/itk.h generic/itkInt.h])
TEA_ADD_INCLUDES([${ITCL_INCLUDES} -I\"`${CYGPATH} ${srcdir}/generic`\"])
TEA_ADD_LIBS([])
TEA_ADD_CFLAGS([])
#TEA_ADD_STUB_SOURCES([itkStubLib.c])
TEA_ADD_TCL_SOURCES([library/Archetype.itk
                library/Toplevel.itk
                library/Widget.itk
                library/itk.tcl
                library/tclIndex])

#--------------------------------------------------------------------
# __CHANGE__
#
# You can add more files to clean if your extension creates any extra
# files by extending CLEANFILES.
# Add pkgIndex.tcl if it is generated in the Makefile instead of ./configure
# and change Makefile.in to move it from CONFIG_CLEAN_FILES to BINARIES var.
#
# A few miscellaneous platform-specific items:
# TEA_ADD_* any platform specific compiler/build info here.
#--------------------------------------------------------------------

#CLEANFILES="$CLEANFILES pkgIndex.tcl"
if test "${TEA_PLATFORM}" = "windows" ; then
    # Ensure no empty if clauses
    :
    #TEA_ADD_SOURCES([win/winFile.c])
    #TEA_ADD_INCLUDES([-I\"$(${CYGPATH} ${srcdir}/win)\"])
    TEA_ADD_SOURCES([dllEntryPoint.c])
else
    # Ensure no empty else clauses
    :
    #TEA_ADD_SOURCES([unix/unixFile.c])
    #TEA_ADD_LIBS([-lsuperfly])
fi

#--------------------------------------------------------------------
# __CHANGE__
# Choose which headers you need.  Extension authors should try very
# hard to only rely on the Tcl public header files.  Internal headers
# contain private data structures and are subject to change without
# notice.
# This MUST be called after TEA_LOAD_TCLCONFIG / TEA_LOAD_TKCONFIG
#--------------------------------------------------------------------

#TEA_PUBLIC_TCL_HEADERS
TEA_PRIVATE_TCL_HEADERS

TEA_PUBLIC_TK_HEADERS
#TEA_PRIVATE_TK_HEADERS
TEA_PATH_X

#--------------------------------------------------------------------
# We need to enable the threading macros found in tcl.h and tclInt.h.
# The use of the threading features is determined by the core the
# extension is loaded into, but we need to compile with these macros
# turned on.
#--------------------------------------------------------------------

AC_DEFINE(TCL_THREADS)

#--------------------------------------------------------------------
# Check whether --enable-threads or --disable-threads was given.
# This auto-enables if Tcl was compiled threaded.
#--------------------------------------------------------------------

#TEA_ENABLE_THREADS

#--------------------------------------------------------------------
# The statement below defines a collection of symbols related to
# building as a shared library instead of a static library.
#--------------------------------------------------------------------

TEA_ENABLE_SHARED

#--------------------------------------------------------------------
# This macro figures out what flags to use with the compiler/linker
# when building shared/static debug/optimized objects.  This information
# can be taken from the tclConfig.sh file, but this figures it all out.
#--------------------------------------------------------------------

TEA_CONFIG_CFLAGS

#--------------------------------------------------------------------
# Set the default compiler switches based on the --enable-symbols option.
#--------------------------------------------------------------------

TEA_ENABLE_SYMBOLS

#--------------------------------------------------------------------
# Itcl stubs
#--------------------------------------------------------------------

if test "${SHARED_BUILD}" = "1" ; then
    AC_DEFINE(USE_ITCL_STUBS)
fi

#--------------------------------------------------------------------
# This macro generates a line to use when building a library.  It
# depends on values set by the TEA_ENABLE_SHARED, TEA_ENABLE_SYMBOLS,
# and TEA_LOAD_TCLCONFIG macros above.
#--------------------------------------------------------------------

TEA_MAKE_LIB

#--------------------------------------------------------------------
# Determine the name of the tclsh and/or wish executables in the
# Tcl and Tk build directories or the location they were installed
# into. These paths are used to support running test cases only,
# the Makefile should not be making use of these paths to generate
# a pkgIndex.tcl file or anything else at extension build time.
#--------------------------------------------------------------------

TEA_PROG_TCLSH
TEA_PROG_WISH

#--------------------------------------------------------------------
# Setup a *Config.sh.in configuration file.
#--------------------------------------------------------------------

# itk_SRC_DIR must be a fully qualified path
eval itk_SRC_DIR="$srcdir"
itk_SRC_DIR="`(cd "${itk_SRC_DIR}"; pwd)`"

itk_LIB_FILE="${PKG_LIB_FILE}"
itk_STUB_LIB_FILE="${PKG_STUB_LIB_FILE}"

TEA_EXPORT_CONFIG([itk])
AC_SUBST(ITCL_VERSION)
AC_SUBST(itk_SRC_DIR)
AC_SUBST(itk_LIB_FILE)
AC_SUBST(itk_STUB_LIB_FILE)

#--------------------------------------------------------------------
# Specify files to substitute AC variables in. You may alternatively
# have a special pkgIndex.tcl.in or other files which require
# substituting the AC variables in. Include these here.
#--------------------------------------------------------------------

AC_CONFIG_FILES([Makefile pkgIndex.tcl])
AC_CONFIG_FILES([itkConfig.sh])

#--------------------------------------------------------------------
# Finally, substitute all of the various values into the files
# specified with AC_CONFIG_FILES.
#--------------------------------------------------------------------

AC_OUTPUT()
