PKG_OBJECTS = tclGLMWFWBase.o tclGLMWFWCmd.o tclGLMWFWUtil.o \
    tclGLMWFWStubInit.o tclGLMWFWMaps.o tclGLMWFWWindow.o tclGLMWFWEnable.o \
    tclGLMWFWInput.o tclGLMWFWInit.o tclGLMWFWFullscreen.o tclGLMWFWGlext.o \
    tclGLMWFWJoystick.o
PKG_STUB_OBJECTS= 
PKG_HEADERS= generic/tclGLMWFW.h generic/tclGLMWFWInt.h
PKG_LIB_FILE=libTclGLMWFW0.1.so
PKG_STUB_LIB_FILE=

SHELL=/bin/sh

srcdir=.
prefix=/home/arnulf
exec_prefix=/home/arnulf
libdir=${exec_prefix}/lib
includedir=${prefix}/include
mandir=${prefix}/man

INSTALL=/usr/bin/install -c
INSTALL_PROGRAM=${INSTALL}
INSTALL_DATA=${INSTALL} -m 644
INSTALL_SCRIPT=${INSTALL}
PACKAGE_NAME=TclGLMWFW
PACKAGE_VERSION=0.1
CC=gcc
CFLAGS_DEFAULT=-g -DTCL_MEM_DEBUG
CFLAGS_WARNING=-Wall -Wno-implicit-int
CLEANFILES= pkgIndex.tcl
EXEEXT=

LDFLAGS_DEFAULT= -Wl,--export-dynamic

MAKE_LIB=${SHLIB_LD} -o $@ $(PKG_OBJECTS) ${SHLIB_LD_LIBS}
MAKE_SHARED_LIB=${SHLIB_LD} -o $@ $(PKG_OBJECTS) ${SHLIB_LD_LIBS}
MAKE_STATIC_LIB=${STLIB_LD} $@ $(PKG_OBJECTS)
MAKE_STUB_LIB=${STLIB_LD} $@ $(PKG_STUB_OBJECTS)

OBJEXT=o
RANLIB=:
RANLIB_STUB=:
SHLIB_CFLAGS=-fPIC
SHLIB_LD=${CC} -shared ${CFLAGS} ${LDFLAGS_DEFAULT}
SHLIB_LD_LIBS=${LIBS} /home/arnulf/SOURCES/tclOO/itcl-ng/itk/ntk/library/glfw/lib/x11/libglfw.a -L/home/arnulf/SOURCES/tclOO/head/unix -ltclstub8.5 \
-L/usr/X11/lib -lGLU -lGL -lX11 -lXrandr -pthread -lm
STLIB_LD=${AR} cr
TCL_SRC_DIR=/home/arnulf/SOURCES/tclOO/head				     TCL_BIN_DIR=/home/arnulf/SOURCES/tclOO/head/unix
# Not actually used, but can help when tracing errors			   TCL_LIBS=${DL_LIBS} ${LIBS} ${MATH_LIBS}
TCLSH_PROGRAM=/home/arnulf/SOURCES/tclOO/head/unix/tclsh
INCLUDES= -I. -I"./generic" -I"/home/arnulf/SOURCES/tclOO/head/generic" -I"/unix"
EXTRA_CFLAGS=
DEFS=-DPACKAGE_NAME=\"tclGLMWFW\" -DPACKAGE_TARNAME=\"tclGLMWFW\" -DPACKAGE_VERSION=\"0.1\" -DPACKAGE_STRING=\"TclGLMWFW\ 0.1\" -DPACKAGE_BUGREPORT=\"\" -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_LIMITS_H=1 -DHAVE_SYS_PARAM_H=1 -DUSE_THREAD_ALLOC=1 -D_REENTRANT=1 -D_THREAD_SAFE=1 -DTCL_THREADS=1 -D_LARGEFILE64_SOURCE=1 -DTCL_WIDE_INT_TYPE=long\ long -DHAVE_STRUCT_STAT64=1 -DHAVE_OPEN64=1 -DHAVE_LSEEK64=1 -DHAVE_TYPE_OFF64_T=1 -D_LARGEFILE64_SOURCE=1 -DTCL_WIDE_INT_TYPE=long\ long -DHAVE_STRUCT_STAT64=1 -DHAVE_OPEN64=1 -DHAVE_LSEEK64=1 -DHAVE_TYPE_OFF64_T=1 -DUSE_TCL_STUBS=1 -DBUILD_itcl=1  $(EXTRA_CFLAGS)
CPPFLAGS=
LIBS=  -lieee -lm
AR=ar
CFLAGS= -pipe ${CFLAGS_DEFAULT} ${CFLAGS_WARNING} ${SHLIB_CFLAGS} ${CFLAGS_DEFAULT} ${CFLAGS_WARNING} ${SHLIB_CFLAGS}
CYGPATH=echo
SDX=/home/arnulf/bin/sdx
RC=
CC_SWITCHES = ${CFLAGS} ${EXTRA_CLFAGS} ${CFLAGS_WARNING} ${SHLIB_CFLAGS} \
-I${GENERIC_DIR} -I../include -I"/home/arnulf/SOURCES/tclOO/head/unix" \
-I../ntk/library/glfw \
-DTCL_GLMWFW_DEBUG \
${AC_FLAGS} ${GENERIC_FLAGS} ${PROTO_FLAGS} \
${ENV_FLAGS}

TCLSH_ENV=TCL_LIBRARY="`$(CYGPATH) $(TCL_SRC_DIR)/library`" \
	  LD_LIBRARY_PATH="$(EXTRA_PATH):$(LD_LIBRARY_PATH)" \
		    PATH="$(EXTRA_PATH):$(PATH)" \
			      TCLLIBPATH="$(top_builddir)"


#========================================================================
# None of these assignments are substituted by configure
#========================================================================

SRC_DIR=$(srcdir)
TOP_DIR=$(SRC_DIR)
GENERIC_DIR=$(TOP_DIR)/generic
BINARIES=$(PKG_LIB_FILE) $(PKG_STUB_LIB_FILE) $(PKG_WIDGET_LIB_FILE) $(PKG_WIDGET_STUB_LIB_FILE)
DESTDIR=
PKG_DIR=$(PACKAGE_NAME)$(PACKAGE_VERSION)
PKG_KIT_ROOT=$(PKG_DIR)-$(PLATFORM)
PKG_KIT=$(PKG_KIT_ROOT).kit
pkglibdir=$(libdir)/$(PKG_DIR)
top_builddir=.
TCL_VERSION_REQ=8.5b1
EXTRA_PATH=$(top_builddir):$(TCL_BIN_DIR)
TCLSH=$(TCLSH_ENV) "$(TCLSH_PROGRAM)"
CONFIG_CLEAN_FILES=Makefile
COMPILE=$(CC) $(DEFS) $(INCLUDES) $(CPPFLAGS) $(CFLAGS)
VPATH=.:$(SRC_DIR)/generic:$(SRC_DIR)/unix:$(SRC_DIR)/win:$(SRC_DIR)/macosx
TESTFLAGS=
KIT_PKG_ROOT=$(PKG_KIT_ROOT).vfs/lib/$(PACKAGE_NAME)
# The quoting is horrific, I know!
RCFLAGS=--define PACKAGE_NAME='\"$(PACKAGE_NAME)\"' \
	--define PKG_LIB_FILE='\"$(PKG_LIB_FILE)\"' \
	--define PACKAGE_VERSION='\"$(PACKAGE_VERSION)\"' 
RES=res.o
ITERATIONS=1000

#========================================================================
# This is something that if found by executing a Tcl script
#========================================================================

PLATFORM:=$(shell echo 'package require platform;puts [platform::generic]' | $(TCLSH))

#========================================================================
# Master rules
#========================================================================

all: package libraries
package: $(PKG_LIB_FILE) pkgIndex.tcl
libraries: $(PKG_STUB_LIB_FILE)
install: all install-package # install-libraries install-headers install-doc
kit: sdx_valid $(PKG_KIT)

#========================================================================
# Basic installation rules
#========================================================================

install-package:
	@mkdir -p $(DESTDIR)$(pkglibdir)
	$(INSTALL_PROGRAM) $(PKG_LIB_FILE) $(DESTDIR)$(pkglibdir)/$(PKG_LIB_FILE)
	$(INSTALL_DATA) pkgIndex.tcl $(DESTDIR)$(pkglibdir)/pkgIndex.tcl


#========================================================================
# The rules for actually doing the build of the package.
#========================================================================

$(PKG_LIB_FILE): $(PKG_OBJECTS)
	-rm -f $(PKG_LIB_FILE)
	${MAKE_LIB}
	$(RANLIB) $(PKG_LIB_FILE)
$(PKG_STUB_LIB_FILE): $(PKG_STUB_OBJECTS)
	-rm -f $(PKG_STUB_LIB_FILE)
	${MAKE_STUB_LIB}
	$(RANLIB_STUB) $(PKG_STUB_LIB_FILE)

.c.o:
	$(COMPILE) -c $(CC_SWITCHES) `$(CYGPATH) $<` -o $@

tclGLMWFWBase.o: $(GENERIC_DIR)/tclGLMWFWInt.h $(GENERIC_DIR)/tclGLMWFW.h

tclGLMWFWCmd.o: $(GENERIC_DIR)/tclGLMWFWInt.h $(GENERIC_DIR)/tclGLMWFW.h

tclGLMWFWUtil.o: $(GENERIC_DIR)/tclGLMWFWInt.h $(GENERIC_DIR)/tclGLMWFW.h

tclGLMWFWMaps.o: $(GENERIC_DIR)/tclGLMWFWInt.h $(GENERIC_DIR)/tclGLMWFW.h

tclGLMWFWWindow.o: $(GENERIC_DIR)/tclGLMWFWInt.h $(GENERIC_DIR)/tclGLMWFW.h

tclGLMWFWEnable.o: $(GENERIC_DIR)/tclGLMWFWInt.h $(GENERIC_DIR)/tclGLMWFW.h

tclGLMWFWInput.o: $(GENERIC_DIR)/tclGLMWFWInt.h $(GENERIC_DIR)/tclGLMWFW.h

tclGLMWFWInit.o: $(GENERIC_DIR)/tclGLMWFWInt.h $(GENERIC_DIR)/tclGLMWFW.h

tclGLMWFWFullScreen.o: $(GENERIC_DIR)/tclGLMWFWInt.h $(GENERIC_DIR)/tclGLMWFW.h

tclGLMWFWGlext.o: $(GENERIC_DIR)/tclGLMWFWInt.h $(GENERIC_DIR)/tclGLMWFW.h

tclGLMWFWJoystick.o: $(GENERIC_DIR)/tclGLMWFWInt.h $(GENERIC_DIR)/tclGLMWFW.h


#========================================================================
# How to clean up after a build.
#========================================================================

clean:
	-test -z "$(BINARIES)" || rm -f $(BINARIES)
	-rm -f *.$(OBJEXT) core *.core
	-test -z "$(CLEANFILES)" || rm -f $(CLEANFILES)
distclean: clean
	-rm -f *.tab.c
	-rm -f $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log config.status

