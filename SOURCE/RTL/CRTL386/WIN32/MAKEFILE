# MAKEFILE - makes a library (or libraries) for WIN32
#
# Invoke as follows:
#
#       MAKE defines...
#
# One of the following command line defines is required.  When building
# the entire library, MAKE must be run once with each define in the
# exact order shown.
#
#       -DCLIB      build portable portion of library
#       -DCLIBNT    build WIN32-specific portion of library
#       -DIOSTREAM  build C++ iostreams
#
# Optional command line defines:
#
#       -DDLL       build exportable library and DLL version of library
#       -DMT        build multi-thread library


all : buildlib

!ifndef CLIB
!  ifndef CLIBNT
!    ifndef IOSTREAM
!      error Must use -DCLIB, -DCLIBNT, or -DIOSTREAM
!    endif
!  endif
!endif

# If building the DLL or the exportable library, define _BUILDRTLDLL
# and append an 'x' to the name of the object file directory.

!if $d(DLL)
EXPFLAGS = -D_BUILDRTLDLL
AEXPFLAGS = -D_BUILDRTLDLL
EXPSUFFIX = x
!endif

# Build multi-thread library (cw32mt.lib) if MT is defined.
# Otherwise, build normal Win32 library (cw32.lib)

!ifdef MT
CMTFLAGS = -D_MT -WM
AMTFLAGS = -D_MT
LIBNAME = cw32mt
!else
LIBNAME = cw32
!endif

# Define WINAPI to be _stdcall if the new WinNT with stdcall API is being used.

!ifdef STDCALL
APITYPE = -DWINAPI=_stdcall
!endif

# Directory where libraries will be stored.

LIB = lib

# CLIB (all portable modules except for iostreams).
# This must be built first.

!ifdef CLIB
!  ifdef CLIBNT
!    error CLIBNT defined.
!  endif
SRC = ..\common
! ifdef MT
OBJNX = objmt
!  else
OBJNX = obj
!  endif
!include "clib.mak"
!endif

# CLIBNT (WIN32-specific modules)

!ifdef CLIBNT
SRC = clib
! ifdef MT
OBJNX = objmt
!  else
OBJNX = obj
!  endif
!include "clibnt.mak"
!endif

# IOSTREAMS (portable)

!ifdef IOSTREAM
SRC = ..\iostream
.PATH.cpp = ..\iostream
! ifdef MT
OBJNX = objmt
!  else
OBJNX = obj
!  endif
!include "iostream.mak"
!endif

# Define search paths

OBJ = $(OBJNX)$(EXPSUFFIX)

.PATH.lib = $(LIB)
.PATH.obj = $(OBJ)
.PATH.c   = $(SRC)
.PATH.cas = $(SRC)
.PATH.cpp = $(SRC)
.PATH.asm = $(SRC)

# How to compile and assemble modules.  The CFLAGS are placed in
# TURBOC.CFG instead of being specified each time the compiler is run.

CFLAGS = -Etasm -c -X -n$(OBJ) -Iinclude;rtlinc;..\..\rtlapi;..\rtlinc;$(SRC) -w -w-sig -W -Di386 $(CMTFLAGS) $(EXPFLAGS) $(APITYPE)
AFLAGS = $(AMTFLAGS) $(AEXPFLAGS) -D__WIN32__ -I..\..\rtlapi -I..\rtlinc -I$(SRC) -Mx -t -m

!if $d(DEBUG)
CC  = bcc32 -v +turboc.cfg
ASM = tasm /zi $(AFLAGS)
LINK= tlink32 -v
TLIB= tlib /P128
!else
CC  = bcc32 +turboc.cfg
ASM = tasm $(AFLAGS)
LINK= tlink32
TLIB= tlib
!endif

.c.obj :
        $(CC) { $<}

.cas.obj :
        $(CC) { $<}

.cpp.obj :
        $(CC) { $<}

.asm.obj :
        $(ASM) $*,$(OBJ)\;

# To replace a single module in the library, type MAKE name.rep

.obj.rep :
        $(TLIB) $(LIB)\$(LIBNAME)$(EXPSUFFIX).lib -+$*.obj

# How to build the library.  The target "lib" is defined in one
# of the makefiles included above; it in turn depends on the objects
# defined by the macros OBJ1-5.

buildlib : cfg lib librsp
!ifdef CLIB
    if exist $(LIB)\$(LIBNAME)$(EXPSUFFIX).lib del $(LIB)\$(LIBNAME)$(EXPSUFFIX).lib
!endif
    $(TLIB) /c $(LIB)\$(LIBNAME)$(EXPSUFFIX).lib @tlib.rsp,temp.lst
    if exist $(LIB)\$(LIBNAME)$(EXPSUFFIX).bak del $(LIB)\$(LIBNAME)$(EXPSUFFIX).bak
    del temp.lst

# Compiler configuration file.

cfg :
        copy &&!
$(CFLAGS)
!       turboc.cfg

# LIB response file.

librsp :
        makersp "+$(OBJ)\\\\%s &\n" &&|
        $(OBJ1)
        $(OBJ2)
        $(OBJ3)
        $(OBJ4)
        $(OBJ5)
|       > tlib.rsp

# Create the DLL version of the RTL and its matching import library.
# The response files and objects are assumed to have been created by
# previous invocations of MAKE.

dll : # dummy.obj
	brc32 -r version
        $(LINK) -s -c -Tpd @dll.rsp,$(LIB)\$(LIBNAME).dll,,$(LIB)\import32,$(LIBNAME).def,version.res
        implib $(LIB)\$(LIBNAME)i.lib $(LIB)\$(LIBNAME).dll
        $(TLIB) $(LIB)\$(LIBNAME)i.lib @import.rsp,nul.
        del $(LIB)\$(LIBNAME)i.bak
#       del dll.rsp
#       del import.rsp
