# BFCDB.MAK - Borland makefile for BFCD40*.DLL
#
# BFCD40[D].DLL is a DLL
#  which exports all the MFC/DB classes
#

# Default to No Debug Info mode
!ifndef DBGINFO
DBGINFO=0
!endif

!ifndef LIBNAME
LIBNAME=BFCD40
!endif

!if "$(DEBUG)" != "0"
CRTDLL=cw32mti.lib
!else
CRTDLL=cw32mti.lib
!endif

TARGET=w
DLL=2
TARG=$(LIBNAME)
TARGDEFS=/D_AFX_DB_IMPL
MFCDLL=BFC40
MFCOLE=BFCO40
LFLAGS=/n /m /s /w-inq $(LFLAGS)
RCFLAGS=@brcc32.cfg $(RCFLAGS)

!if "$(DBGINFO)" != "0"
LFLAGS=$(LFLAGS) /v
!endif

!if "$(DEBUG)" != "0"
# Debug DLL build
RCDEFINES=/D_DEBUG
PCH_FILE=stdafxd.csm
PCH_CPP=dlldb
TARG=$(TARG)D
MFCDLL=$(MFCDLL)D
MFCOLE=$(MFCOLE)D

!ELSE
# Release DLL build
RCDEFINES=
LFLAGS=$(LFLAGS)
PCH_FILE=stdafxd.csm
PCH_CPP=dlldb
!ENDIF

DEFFILE=$(PLATFORM)\$(TARG).DEF

MFCDLL=$(LIBDIR)\$(MFCDLL).lib
MFCOLE=$(LIBDIR)\$(MFCOLE).lib

!ifdef RELEASE # Release VERSION info
RCDEFINES=$(RCDEFINES) /DRELEASE
LFLAGS=$(LFLAGS) /release
!endif

LFLAGS=$(LFLAGS) /Tpd

LIBS=$(MFCDLL) $(MFCOLE) $(CRTDLL) ole2w32.lib import32.lib

bfcdb_goal: dll_goal

#############################################################################
# import most rules and library files from normal makefile

!include borland.mak

dll_goal: create.dir create.rsp $(TARG).dll $(LIBDIR)\$(TARG).lib

#############################################################################
# Build target

$D\$(TARG).res: mfcdb.rc build_.h
	brcc32 /r $(RCFLAGS) $(RCDEFINES) /fo $D\$(TARG).res mfcdb.rc

DLL_OBJS=$(DB) $(DAO)

$(TARG).dll:: $(DEFFILE) $D\$(TARG).res $(MRC_RESOURCES)

$(TARG).dll:: $(PCH_CPP).obj $(DLL_OBJS)
    tlink32 @&&!
$(LFLAGS) +
C0D32.OBJ +
$(**: = +^
)
$(TARG).DLL
$D\$(TARG).MAP
$(LIBS)
$(DEFFILE)
$D\$(TARG).res
!

$(LIBDIR)\$(TARG).lib: $(TARG).DLL
    implib  $(LIBDIR)\$(TARG).lib $(TARG).DLL

#############################################################################
