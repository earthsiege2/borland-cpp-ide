# This is a part of the Microsoft Foundation Classes C++ library.
# Copyright (C) 1992 Microsoft Corporation
# All rights reserved.
#
# This source code is only intended as a supplement to the
# Microsoft Foundation Classes Reference and Microsoft
# QuickHelp and/or WinHelp documentation provided with the library.
# See these sources for detailed information regarding the
# Microsoft Foundation Classes product.

PROJ=CMNCTRL

#!include <$(MAKEDIR)\..\include\mfc\mfcsamps.mak>
!include <..\..\mfcrules.mak>

default: integration
	$(MAKE) -f $(PROJ)1.mak
	$(MAKE) -f $(PROJ)2.mak

clean:
	$(CLEAN_MFC)
                                
integration: $(PROJ)1.bpr $(PROJ)1.mak $(PROJ)2.bpr $(PROJ)2.mak
    $(NOP)

cmnctrl1.bpr: cmnctrl1.dsp
	$(VCTOBPR) -I"$(BCB)\include;$(BCB)\include\idl" -2 $?

cmnctrl2.bpr: cmnctrl2.dsp
	$(VCTOBPR) -I"$(BCB)\include;$(BCB)\include\idl" -2 $?