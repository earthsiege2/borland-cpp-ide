
!if !$d(BCB)
BCB = $(MAKEDIR)\..
!endif

!if !$d(DCC32)
DCC32           = $(BCB)\bin\dcc32
!endif

!if !$d(BCC)
BCC 		= $(BCB)\bin\bcc32
!endif

!if !$d(IMPLIB)
IMPLIB		= $(BCB)\bin\implib
!endif

!if !$d(ILINK)
ILINK		= $(BCB)\bin\ilink32
!endif

!if !$d(MAKE)
MAKE            = $(BCB)\bin\make
!endif

!if !$d(BPR2MAK)
BPR2MAK		= $(BCB)\bin\bpr2mak
!endif

!if !$d(VCTOBPR)
VCTOBPR		= $(BCB)\bin\vctobpr
!endif

!if !$d(DEFAULT_CLEAN)
DEFAULT_CLEAN = @echo make clean does nothing.
!endif

!if !$d(CLEAN_MFC)
CLEAN_MFC = @echo make clean does nothing.
!endif

.bpr.mak:
	$(BPR2MAK) -t..\..\default.bmk $? -o$@

.dsp.bpr:
	$(VCTOBPR) -I"$(BCB)\include;$(BCB)\include\idl" -1 $?