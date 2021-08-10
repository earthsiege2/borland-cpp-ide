# This is a part of the Microsoft Foundation Classes C++ library.
# Copyright (C) 1992-1995 Microsoft Corporation
# All rights reserved.
#
# This source code is only intended as a supplement to the
# Microsoft Foundation Classes Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# Microsoft Foundation Classes product.

PROJ=SPEAKN
OBJS=speakn.obj
WAVPATH=res\\
WAVFILES =	$(WAVPATH)correct.wav \
		$(WAVPATH)dog.wav \
		$(WAVPATH)frog.wav \
		$(WAVPATH)giveup.wav \
		$(WAVPATH)goodbye.wav \
		$(WAVPATH)incorrec.wav \
		$(WAVPATH)pig.wav \
		$(WAVPATH)question.wav \
		$(WAVPATH)train.wav \
		$(WAVPATH)welcome.wav

#!include <$(MAKEDIR)\..\include\mfc\mfcsamps.mak>
!include <..\..\mfcrules.mak>

default: integration
	$(MAKE) -f $(PROJ).mak

clean:
	$(CLEAN_MFC)
                                
integration: $(PROJ).bpr $(PROJ).mak $(WAVFILES)
    $(NOP)

$(WAVPATH)correct.wav:	$(WAVPATH)correct.wa
$(WAVPATH)dog.wav:	$(WAVPATH)dog.wa
$(WAVPATH)frog.wav:	$(WAVPATH)frog.wa
$(WAVPATH)giveup.wav:	$(WAVPATH)giveup.wa
$(WAVPATH)goodbye.wav:	$(WAVPATH)goodbye.wa
$(WAVPATH)incorrec.wav:	$(WAVPATH)incorrec.wa
$(WAVPATH)pig.wav:	$(WAVPATH)pig.wa
$(WAVPATH)question.wav:	$(WAVPATH)question.wa
$(WAVPATH)train.wav:	$(WAVPATH)train.wa
$(WAVPATH)welcome.wav:	$(WAVPATH)welcome.wa

.wa.wav:
	$(COPY) $? $@