#---------------------------------------------------------------------------
# Visual Database Tools
# Copyright (c) 1996 by Borland International, All Rights Reserved
#
# Makefile for C++ database access classes.
#---------------------------------------------------------------------------

.autodepend

!ifdef FLAT
	SUFFIX=32
	MODEL=F
!else
	SUFFIX=16
	MODEL=
!endif

OBJDIR=obj$(SUFFIX)

!ifndef BCROOT
BCROOT=$(MAKEDIR)\..
!endif

BCINCDIR=$(BCROOT)\include
BCLIBDIR=$(BCROOT)\lib
BCBINDIR=$(BCROOT)\bin

CFLAGS=-I$(BCINCDIR) -D_BUILDBDTOLIB +bdto$(SUFFIX).cfg

!ifdef DEBUG
	CFLAGS=-v $(CFLAGS)
!endif

!ifdef CODEGUARD
!ifndef NOCODEGUARD
	CFLAGS=-vG $(CFLAGS)
!endif
!endif

!ifdef FLAT
	COMPILE=$(BCBINDIR)\bcc32 $(CFLAGS)
!else
	COMPILE=$(BCBINDIR)\bcc -WS $(CFLAGS)
!endif

.path.obj=$(OBJDIR)

.cpp.obj:
	$(COMPILE) $<

BDTO_LIB=bdto$(MODEL).lib

PFXOBJS=\
 PFXwrapit.obj\
 PFXbase.obj\
 PFXstrings.obj\
 PFXsession.obj\
 PFXdatabase.obj\
 PFXfielddef.obj\
 PFXdataset.obj\
 PFXdatasour.obj\
 PFXfield.obj\
 PFXindexdef.obj\
 PFXtable.obj\
 PFXbatch.obj\
 PFXparam.obj\
 PFXstoredpr.obj\
 PFXquery.obj\
 PFXstream.obj\
 PFXvarrec.obj\
 PFXbdtevent.obj\
 PFXfunctor.obj

OBJS=$(PFXOBJS:PFX=)
LIBOBJS=$(PFXOBJS:PFX=+)

all: prep $(BCLIBDIR)\$(BDTO_LIB)

prep:
	@if not exist $(.path.obj)\nul md $(.path.obj)

$(BCLIBDIR)\$(BDTO_LIB): $(OBJS)
	if exist $(BCLIBDIR)\$(BDTO_LIB) del $(BCLIBDIR)\$(BDTO_LIB)
	cd $(.path.obj)
	$(BCBINDIR)\tlib /0 /P128 $(BCLIBDIR)\$(BDTO_LIB) @&&|
$(LIBOBJS)
|
	cd ..

clean:
	@echo y > y.txt
	@if exist $(.path.obj)\*.* del $(.path.obj)\*.* < y.txt
	@if exist $(.path.obj)\nul rd $(.path.obj)
	@if exist $(BCLIBDIR)\$(BDTO_LIB) del $(BCLIBDIR)\$(BDTO_LIB)
	@del y.txt
