# This is a part of the Microsoft Foundation Classes C++ library.
# Copyright (C) 1992-1995 Microsoft Corporation
# All rights reserved.
#
# This source code is only intended as a supplement to the
# Microsoft Foundation Classes Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# Microsoft Foundation Classes product.

PROJ=BATCH
OBJS= BATCH.obj BATCHDOC.obj BATCHVW.obj COMPRESS.obj DESTDIRD.obj \
	INTERLEA.obj MAINFRM.obj STDAFX.obj

#!include <$(MAKEDIR)\..\include\mfc\mfcsamps.mak>
!include <..\..\mfcrules.mak>

default: integration
	$(MAKE) -f $(PROJ).mak

clean:
	$(CLEAN_MFC)
                                
integration: $(PROJ).bpr $(PROJ).mak
    $(NOP)

batch.bpr: batch.dsp
	$(VCTOBPR) -I"$(BCB)\include;$(BCB)\include\idl" -2 $?