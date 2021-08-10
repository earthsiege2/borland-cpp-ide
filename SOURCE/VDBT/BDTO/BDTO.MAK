#---------------------------------------------------------------------------
# Visual Database Tools
# Copyright (c) 1996 by Borland International, All Rights Reserved
#
# Makefile for C++ database access classes.
#
# Make Define Enabled Options:
#
#     FLAT - Create 32 Bit Libraries
#     DEBUG - Add Debug Information
#     CODEGUARD - Enable CodeGuard
#     DYNAMIC_RTL - Create Libraries Linkable to RTL.DLL
#     USERDLL - Create Object Modules Linkable to a DLL
#
#---------------------------------------------------------------------------

.autodepend

!ifdef FLAT
  SUFFIX=32
  MODEL=F
  COMPILE=$(BCBINDIR)\bcc32
!else
  SUFFIX=16
  MODEL=
  COMPILE=$(BCBINDIR)\bcc
!endif

!ifndef BCROOT
  BCROOT=$(MAKEDIR)\..
!endif

BCINCDIR=$(BCROOT)\include
BCLIBDIR=$(BCROOT)\lib
BCBINDIR=$(BCROOT)\bin

TLIBFLAGS = /C /P512

!ifndef DEBUG
  TLIBFLAGS = /0 $(TLIBFLAGS)
!endif

TLIB=$(BCBINDIR)\tlib $(TLIBFLAGS)

!if $d( USERDLL ) && ! $d( FLAT )
!  ifdef DYNAMIC_RTL
    TYPE = d
!  else
    TYPE = u
!  endif
!elif $d( DYNAMIC_RTL )
    TYPE = i
! else
  TYPE =
!endif

__OBJS= __wrapit.obj   \
        __base.obj     \
        __batch.obj    \
        __bdtevent.obj \
        __database.obj \
        __dataset.obj  \
        __datasour.obj \
        __field.obj    \
        __fielddef.obj \
        __functor.obj  \
        __indexdef.obj \
        __param.obj    \
        __query.obj    \
        __session.obj  \
        __storedpr.obj \
        __stream.obj   \
        __strings.obj  \
        __table.obj    \
        __varrec.obj

.path.obj = obj$(SUFFIX)$(TYPE)
.path.lib = $(BCLIBDIR)
\TYPE     = \$(TYPE)
-+TYPE    = -+$(TYPE)
PROJ      = bdto$(MODEL)
PROJ_LIB  = $(PROJ).lib

.cpp.obj:
  $(COMPILE) +&&|
    -3
    -c
    -d
    -DSTRICT;_BUILDBDTOLIB
    -n$(.path.obj)
    -w+
    -Hc
    -H=$(.path.obj)\$(PROJ).csm
    -I$(BCINCDIR)
    -vi-
!ifndef FLAT
!  ifdef USERDLL
    -WD
!  else
    -WS
!  endif
    -xc
    -ml
!else
    -WM-
!endif
!ifdef CODEGUARD
!ifndef NOCODEGUARD
    -vG
!endif
!endif
!ifdef DEBUG
    -v
    -Od
!else
    -Ox
!endif
!ifdef DYNAMIC_RTL
    -D_RTLDLL
!endif
| $(CFLAGS) $**
  -copy $@ $(@:\=$(\TYPE))

all: $(.path.obj)\nul $(PROJ_LIB)

$(.path.obj)\nul :
  @if not exist $(.path.obj)\nul md $(.path.obj)

$(PROJ_LIB): $(__OBJS:__=)
  cd $(.path.obj)
  $(TLIB) $< @&&|
    $(__OBJS:__=$(-+TYPE))
|
  cd ..

clean:
  @deltree /Y $(.path.obj)
  @if exist $(.path.lib)\$(PROJ_LIB) del $(.path.lib)\$(PROJ_LIB)
