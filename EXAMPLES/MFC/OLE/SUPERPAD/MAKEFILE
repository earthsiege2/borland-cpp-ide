# This is a part of the Microsoft Foundation Classes C++ library.
# Copyright (C) 1992-1995 Microsoft Corporation
# All rights reserved.
#
# This source code is only intended as a supplement to the
# Microsoft Foundation Classes Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# Microsoft Foundation Classes product.

PROJ=SUPERPAD
OBJS=superpad.obj paddoc.obj padview.obj mainfrm.obj ipframe.obj \
	 pageset.obj tabstop.obj padframe.obj aboutbox.obj paditem.obj \
	 linkitem.obj

#!include <$(MAKEDIR)\..\include\mfc\mfcsamps.mak>
!include <..\..\mfcrules.mak>

default: integration
	$(MAKE) -f $(PROJ).mak

clean:
	$(CLEAN_MFC)
                                
integration: $(PROJ).bpr $(PROJ).mak
    $(NOP)