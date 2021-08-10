# BORLAND.MAK: Borland makefile for MFC variants
#
# Usage: MAKE -F BORLAND.MAK CLEAN        (removes all intermediary files)
#    or: MAKE -F BORLAND.MAK options      (builds library variant (see below))
# Note that an MAKE CLEAN should be performed before building a new variant.
#
# 'Options' are one of each of:
#   "DLL"              (defaults to 0)
#           If this item is 0, then a normal library is generated.
#                       DLL=1 is obsolete and not supported by this release.
#           If this item is 2, objects suitable for the shared DLL version
#           of MFC are created.  Note: DLL=2 is to be used only from
#           MFCDLL.MAK, MFCOLE.MAK, or MFCDB.MAK
#
#   "DEBUG"             (defaults to 1)
#           If this item is 1, diagnostic support is compiled into
#           the library.  If this item is 0, then diagnostic support
#           is disabled. Diagnostic support does not include debug info
#           information.
#
#   "OBJ=.\obj"         (defaults to '$$(MODEL)$(BASE)$(DEBUG)')
#           This optional specification specifies where temporary OBJ files
#           are stored during the build process.  The directory is created or
#           removed as necessary.
#
#   "OPT="              (no default value)
#           This allows additional compiler options to be added to the build.
#           If more than one switch is desired, put double-quotes around the
#           whole OPT= argument, e.g., "OPT=/J /W3".
#
#   "NO_PCH=1"
#           Set this item to override the default use of precompiled headers.
#
#   "BROWSE=1"          (defaults to 0)
#           Set this option to build browse info
#
#   "MT=0"              (defaults to 1)
#           To build a non-multithreaded library instead of the default
#           (which enables multitheading and uses the multithread
#           C-runtimes) you can use MT=0.
#
#=============================================================================
# Borland Additional flags
#=============================================================================
#
#   "NO_CLEAN_PCH"      (defaults to off)
#           To prevent deleting an existing PCH (.csm) file
#
#   "DBGINFO"           (defaults to 0)
#           If this item is 1, Turbo Debugger debug info is compiled into
#           the library.  If it's 0, then no debugger info is added.
#
#   "LIBDIR=..\..\lib"
#           Directory for libraries that are created
#
#   "MFCINCL=..\..\include\mfc"
#           MFC Include directory base
#
#   "BCINCL=..\..\include"
#           BC++ Include directory
#
#############################################################################
# Define defaults if not defined

# Default to DEBUG mode
!ifndef DEBUG
DEBUG=1
!endif

# Default to No Debug Info mode
!ifndef DBGINFO
DBGINFO=0
!endif

# Check for MS syntax
!ifdef CODEVIEW
DBGINFO=$(CODEVIEW)
!endif

# Default to NOT DLL
!ifndef DLL
DLL=0
!endif

# Default to no BROWSE info
!ifndef BROWSE
BROWSE=0
!endif

# Default to no precompiled headers
#!ifndef NO_PCH
#NO_PCH=1
#!endif

# Default to no _MBCS build
MBCS=0

# Default to multithreading support
!ifndef MT
MT=1
!endif

# Lib directory
!ifndef LIBDIR
LIBDIR=..\..\LIB
!endif

# Lib Path
!ifndef LPATH
LIBDIR=..\..\LIB
!endif

# MFC Include directory base
!ifndef MFCINCL
MFCINCL=..\..\include\mfc
!endif

# BC Include directory
!ifndef BCINCL
BCINCL=..\..\include
!endif

# Clean up PCH file
!ifndef NO_CLEAN_PCH
NO_CLEAN_PCH=0
!endif

BASE=W
MODEL=N
PLATFORM=INTEL

LFLAGS=$(LFLAGS) /j$(LPATH) /L$(LPATH)

#
# DEBUG OPTIONS
#
!if "$(DEBUG)" != "0"

DEBUGSUF=D
DEBDEFS=/D_DEBUG
DEBOPTS=

!endif

#
# NON-DEBUG OPTIONS
#
!if "$(DEBUG)" == "0"

DEBUGSUF=
DEBDEFS=
DEBOPTS=/O1

!endif

!if "$(DBGINFO)" == "1"
DEBOPTS=/Od /v /vi
!endif

#
# PLATFORM options
#
CPP=bcc32
LIB32=tlib
LINK32=tlink32

CL_MODEL=/D_X86_


# TYPE = Library Type Designator
#       c = normal C library
#       d = DLL library
TYPE=c
DEXT=

#
# Object File Directory
#
!if "$(OBJ)" == ""
D=$$$(MODEL)$(BASE)$(DEBUGSUF)$(DEXT)    # subdirectory specific to variant
!else
D=$(OBJ)                                 # User specified directory
!endif

#
# _AFXDLL DLL Variant
#

!if "$(DLL)" == "2"
# _AFXDLL library
TYPE=e
!if "$(OBJ)" == ""
D=DLL$(DEBUGSUF).$(BASE)
!if "$(UNICODE)" == "1"
D=$(MODEL)$D
!endif
D=$$$D
!endif
TARGOPTS=$(TARGOPTS)
TARGDEFS=$(TARGDEFS)
!if "$(MT)" != "0"
TARGOPTS=$(TARGOPTS) /WM /D_MT=1
!endif
TARGDEFS=$(TARGDEFS) /D_WINDLL /D_AFXDLL
!else
# not _AFXDLL library
!if "$(MT)" != "0"
TARGOPTS=$(TARGOPTS) /WM /D_MT=1
!endif
!endif

MODEL=N

!if "$(DLL)" == "2"
!if "$(TARG)" == ""
!error DLL=2 is used only from BFCDLL.MAK, BFCOLE.MAK, or BFCDB.MAK
!endif
GOAL=$(TARG)
!else
GOAL=$(MODEL)afx$(TYPE)$(BASE)$(DEBUGSUF)
!endif


#
# COMPILER OPTIONS
#
DEFS=$(DEFS) /D_WCHAR_T_DEFINED /D__MSC /D_ANONYMOUS_STRUCT
!if "$(DLL)" == "2"
DEFS=$(DEFS) /D_RTLDLL /D_DLL
!endif
CL_OPT= -g0 -j1 -VF4 $(INCROPTS) $(DEBOPTS) $(CVOPTS) $(TARGOPTS)

!if "$(BROWSE)" != "0"
CL_OPT=-R $(CL_OPT)
!endif

CL_OPT=-n$D $(CL_OPT)

DEFS=$(DEFS) $(DEBDEFS) $(TARGDEFS)

#############################################################################
# Library Components

OBJECT=objcore.obj except.obj \
	validadd.obj dumpcont.obj dumpflt.obj \
	arccore.obj arcobj.obj arcex.obj

# non-shared diagnostics
OBJDIAG=dumpinit.obj dumpout.obj \
	afxasert.obj afxmem.obj afxabort.obj

FILES=filecore.obj filetxt.obj filemem.obj fileshrd.obj \
	filex.obj filest.obj

COLL1=array_b.obj array_d.obj array_p.obj array_o.obj \
	array_s.obj array_u.obj array_w.obj \
	list_o.obj list_p.obj list_s.obj

COLL2=map_pp.obj map_pw.obj map_so.obj \
	map_sp.obj map_ss.obj map_wo.obj map_wp.obj plex.obj

MISC=\
	strcore.obj strex.obj timecore.obj \
	afxdbcs.obj afxstate.obj afxtls.obj bormem.obj

MISC=$(MISC) mtcore.obj mtex.obj

WINDOWS=\
	wincore.obj winfrm.obj winfrm2.obj winfrmx.obj \
	winmdi.obj tooltip.obj winmini.obj winhand.obj \
	winmain.obj barcore.obj bartool.obj bardlg.obj \
	barstat.obj bardock.obj dockcont.obj dockstat.obj \
	dcprev.obj dcmeta.obj trckrect.obj

DIALOG=\
	winctrl1.obj winctrl2.obj winctrl3.obj winctrl4.obj \
	winbtn.obj dlgcore.obj dlgdata.obj dlgfloat.obj \
	dlgprop.obj dlgcomm.obj dlgfile.obj dlgprnt.obj \
	dlgclr.obj dlgfnt.obj dlgfr.obj ccdata.obj dlgtempl.obj

WINMISC=\
	wingdi.obj wingdix.obj winstr.obj winmenu.obj \
	auxdata.obj afxcrit.obj afxtrace.obj winutil.obj

WINMISC=$(WINMISC) winocc.obj

DOCVIEW=\
	cmdtarg.obj doccore.obj doctempl.obj \
	docsingl.obj docmulti.obj docmgr.obj \
	viewcore.obj viewprnt.obj winsplit.obj viewscrl.obj \
	viewform.obj viewedit.obj viewprev.obj viewcmn.obj

DOCVIEW=$(DOCVIEW) docmapi.obj

APPLICATION=\
	thrdcore.obj appcore.obj appinit.obj appterm.obj \
	appui.obj appui2.obj appui3.obj appgray.obj appdlg.obj \
	app3d.obj appprnt.obj apphelp.obj apphelpx.obj \
	filelist.obj

!if "$(DLL)" != "2"
APPLICATION=$(APPLICATION) app3ds.obj \
	nolib.obj appmodul.obj dllmodul.obj oleexp.obj
!endif

# ODBC components:
DB=\
	dbcore.obj dbrfx.obj dbview.obj dbflt.obj \
	dblong.obj

# DAO is not supported under Borland C++
#DB=\
#	$(DB) daocore.obj daodfx.obj daoview.obj

SOCKETS=sockcore.obj

OLEREQ=olelock.obj

OLE=\
	oleinit.obj olebar.obj olecli1.obj olecli2.obj \
	olecli3.obj oledobj1.obj oledobj2.obj \
	oledisp1.obj oledisp2.obj oledlgs1.obj oledlgs2.obj \
	oledlgs3.obj oledata.obj \
	oledoc1.obj oledoc2.obj oledrop1.obj oledrop2.obj \
	olemsgf.obj oleenum.obj olefact.obj oleipfrm.obj \
	olelink.obj olemisc.obj olestrm.obj olesvr1.obj \
	olesvr2.obj olereg.obj oletsvr.obj oleui1.obj \
	oleui2.obj oleunk.obj oleverb.obj olecall.obj \
	olevar.obj viewrich.obj oledll.obj oletyplb.obj

OLE=$(OLE)\
	 occmgr.obj occevent.obj occcont.obj occsite.obj \
	 occlock.obj occddx.obj occddxf.obj occdlg.obj

OLECTL=\
	ctlcache.obj ctlcore.obj ctlconn.obj \
	ctldata.obj ctlevent.obj ctlmodul.obj \
	ctlframe.obj ctlfont.obj ctlinplc.obj \
	ctllic.obj oleconn.obj ctlobj.obj ctlpict.obj \
	ctlpropx.obj ctlppg.obj ctlprop.obj \
	ctlpset.obj ctlpstg.obj ctlpstm.obj \
	ctlrefl.obj ctlreg.obj ctltrack.obj \
	ctlview.obj olepset.obj ctlpbag.obj \
	olepro32.obj \
	ppgcolor.obj ppgfont.obj ppgpict.obj \
	ppgstock.obj

!if "$(DEBUG)" == "1"
OLECTL=$(OLECTL) ctlinl.obj bormem.obj
!endif

OLEDLL=$(OLE) $(OLECTL) $(OLEASM)

!if "$(DEBUG)" == "1"
INLINES = afxinl1.obj afxinl2.obj afxinl3.obj
!else
INLINES =
!endif

CPP_OBJS=$(OBJECT) $(OBJDIAG) $(INLINES) $(FILES) $(COLL1) $(COLL2) $(MISC) \
	$(WINDOWS) $(DIALOG) $(WINMISC) $(DOCVIEW) $(APPLICATION) \
	$(SOCKETS) $(OLEREQ) $(OLE) $(DAO) $(DB)


OBJS=$(CPP_OBJS) $(OLEASM)


#############################################################################
# Standard tools

#############################################################################
# Set CPPFLAGS for use with .cpp.obj and .c.obj rules
# Define rule for use with OBJ directory
# C++ uses a PCH file

CPPFLAGS=$(CPPFLAGS) $(CL_MODEL) $(CL_OPT) $(PDBOPTS) $(DEFS) $(OPT)
BORRSP=bor.rsp

!ifndef NO_PCH
!ifndef PCH_FILE
# put the PCH file in the OBJ directory for easy cleanup later
PCH_FILE=$(D)\stdafx
!if "$(BROWSE)" != "0"
PCH_FILE=$(PCH_FILE)b
!endif
PCH_FILE=$(PCH_FILE).csm
!endif
!ifndef PCH_CPP
PCH_CPP=objcore
!endif
PCH_CMD=-Hc -H=$(PCH_FILE)
!else
PCH_CMD=-H-
PCH_FILE=
!endif
CPPFLAGS=$(CPPFLAGS) $(PCH_CMD)

.SUFFIXES: .cpp

.path.obj = $D

.cpp.obj:
	bcc32 @$(BORRSP) /c { $< }

!ifndef NO_PCH
PCH_TARGETS=$(PCH_FILE) $D\$(PCH_CPP).obj
!endif

#############################################################################
# Goals to build

GOALS=create.dir create.rsp
!ifndef NO_PCH
GOALS=$(GOALS) $(PCH_TARGETS)
!endif
GOALS=$(GOALS) $(LIBDIR)\$(GOAL).lib

goal: $(GOALS)

create.rsp:
!ifndef NO_PCH
!if "$(NO_CLEAN_PCH)" == "0"
    @-if exist $(PCH_FILE) echo Erasing PCH file: $(PCH_FILE) for a fresh build
    @-if exist $(PCH_FILE) erase $(PCH_FILE) > nul
!endif
!endif
    @-if exist $(BORRSP) erase $(BORRSP) > nul
    copy &&|
$(CPPFLAGS) -I$(BCINCL);$(MFCINCL)
| $(BORRSP)

create.dir:
	@-if not exist $D\*.* mkdir $D
	@-if not exist $(LIBDIR) mkdir $(LIBDIR)

clean:
	-if exist $D\*.obj erase $D\*.obj
	-if exist $D\*.csm erase $D\*.csm
	-if exist $D\*.res erase $D\*.res
	-if exist $D\*.rsc erase $D\*.rsc
	-if exist $D\*.map erase $D\*.map
	-if exist $D\*.* rmdir $D

#############################################################################
# Precompiled header file

!ifndef NO_PCH

!if "$(DEBUG)" == "1"
HDRS =$(MFCINCL)\*.h
!else
HDRS =$(MFCINCL)\*.h $(MFCINCL)\*.inl
!endif

!if "$(DLL)" != "2"
$(PCH_TARGETS): $(PCH_CPP).cpp $(HDRS)
	bcc32 @&&!
-H -H=$(PCH_FILE) $(CL_MODEL) $(CL_OPT) $(PDBOPTS) $(DEFS) $(OPT) /c $(PCH_CPP).cpp
!

!endif # DLL != 2
!endif # NO_PCH


#############################################################################
# Build the library from the up-to-date objs

!if "$(DLL)" != "2"
# Build final library
$(LIBDIR)\$(GOAL).lib: $(OBJS)
	@-if exist $@ erase $@
	@tlib $@ /P2048 @&&!
+-$(**: = &^
+-)
!

!endif #DLL!=2

#############################################################################
