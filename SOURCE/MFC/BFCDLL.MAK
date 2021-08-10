# BFCDLL.MAK - Borland makefile for BFC40*.DLL
#
# BFC40[D].DLL is a DLL
#  which exports all the MFC classes
#

# Default to No Debug Info mode
!ifndef DBGINFO
DBGINFO=0
!endif

!ifndef LIBNAME
LIBNAME=BFC40
!endif

!if "$(DEBUG)" != "0"
CRTDLL=CW32MTI.lib
!else
CRTDLL=CW32MTI.lib
!endif

TARGET=w
DLL=2
TARGDEFS=/D_AFX_CORE_IMPL
LFLAGS=/n /m /s /w-inq $(LFLAGS)
RCFLAGS=@brcc32.cfg

!if "$(DBGINFO)" != "0"
LFLAGS=$(LFLAGS) /v
!endif

!if "$(DEBUG)" != "0"
# Debug DLL build
TARGTYPE=$(TARGTYPE)D
RCDEFINES=$(RCDEFINES) /D_DEBUG
!ifndef MONOLITHIC
MONOLITHIC=0
!endif
!ELSE
# Release DLL build
RCDEFINES=$(RCDEFINES)
LFLAGS=$(LFLAGS)
!ifndef MONOLITHIC
MONOLITHIC=1
!endif
!ENDIF

!if "$(MONOLITHIC)" == "1"
TARGDEFS=$(TARGDEFS) /D_AFX_OLE_IMPL /D_AFX_DB_IMPL /D_AFX_NET_IMPL
RCDEFINES=$(RCDEFINES) /D_AFX_MONOLITHIC
!endif

CFNAME=$(LIBNAME)$(TARGTYPE)
TARG=$(LIBNAME)$(PF)$(TARGTYPE)
TARG_STATIC=BFCS40$(PF)$(TARGTYPE)

DEFFILE=$(PLATFORM)\$(TARG).DEF


!ifdef RELEASE # Release VERSION info
RCDEFINES=$(RCDEFINES) /DRELEASE
!endif

LFLAGS=$(LFLAGS) /Tpd

bfcdll_goal: dll_goal

PCH_TARGETS=stdafx.obj

#############################################################################
# import most rules and library files from normal makefile

!include borland.mak

dll_goal: create.dir create.rsp \
	$(TARG).dll $(LIBDIR)\$(TARG).lib $(LIBDIR)\$(TARG_STATIC).lib

#############################################################################
# more flags and switches

LFLAGS=$(LFLAGS)
LIBS=$(CRTDLL) import32.lib ole2w32.lib

#############################################################################

STATICLINK_OBJS=stdafx.obj nolib.obj \
	appmodul.obj dllmodul.obj oleexp.obj

CPPFLAGS_STATIC=\
	$(CL_MODEL) $(CL_OPT) $(DEFS) $(OPT) $(EH) $(PCH_CMD)


stdafx.obj $(PCH_FILE): stdafx.cpp stdafx.h
	$(CPP) /H\"stdafx.h\" @&&!
/c $(CPPFLAGS_STATIC) stdafx.cpp
!

appmodul.obj: stdafx.obj appmodul.cpp
	$(CPP) @&&!
/c $(CPPFLAGS_STATIC) appmodul.cpp
!

dllmodul.obj: stdafx.obj dllmodul.cpp
	$(CPP) @&&!
/c $(CPPFLAGS_STATIC) dllmodul.cpp
!

oleexp.obj: stdafx.obj oleexp.cpp
	$(CPP) @&&!
/c $(CPPFLAGS_STATIC) oleexp.cpp
!

nolib.obj: stdafx.obj nolib.cpp
	$(CPP) @&&!
/c $(CPPFLAGS_STATIC) nolib.cpp
!

#############################################################################
# Build target

$D\$(TARG).res: mfcdll.rc build_.h
	brcc32 -v $(RCFLAGS) $(RCDEFINES) /fo $D\$(TARG).res mfcdll.rc

DLL_OBJS=$(OBJECT) $(OBJDIAG) $(INLINES) $(FILES) $(COLL1) $(COLL2) $(MISC) \
	$(WINDOWS) $(DIALOG) $(WINMISC) $(DOCVIEW) $(APPLICATION) $(OLEREQ)

!if "$(MONOLITHIC)" == "1"
DLL_OBJS=$(DLL_OBJS) $(SOCKETS) $(OLEDLL) $(DAO) $(DB)
!endif

DLL_OBJS=$(DLL_OBJS) dllinit.obj

DLL_RESOURCES=$D\$(TARG).res

$(TARG).dll:: $(DEFFILE) $(DLL_RESOURCES)

$(TARG).dll:: $(DLL_OBJS)
	$(LINK32) @&&!
$(LFLAGS) +
C0D32.OBJ +
$(**: = +^
)
$(TARG).DLL
$(TARG).MAP
$(LIBS)
$(DEFFILE)
$(DLL_RESOURCES)
!

$(LIBDIR)\$(TARG).lib: $(TARG).dll
    implib  $(LIBDIR)\$(TARG).lib $(TARG).DLL

$(LIBDIR)\$(TARG_STATIC).lib: $(STATICLINK_OBJS)
	$(LIB32) $@ /P2048 @&&!
+-$(**: = &^
+-)
!

#############################################################################
