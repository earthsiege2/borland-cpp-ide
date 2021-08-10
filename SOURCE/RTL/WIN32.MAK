#############################################################################
# Configure the tools appropriately.                                        #
#############################################################################
# This is the major version # of the RTL DLL.
DLLMAJOR  = 5

# VCLPACKVER is the VCL Package version number in the .BPL filenames
VCLPACKVER=$(DLLMAJOR)0

# PRODVER is the version # of the Borland C++Builder product
PRODVER=$(DLLMAJOR).0

# BETA is defined only prior to RTM and indicates the current milestone.
#BETA=rtm

!if $d(DLL)
DLLCOPYRIGHTSTR = Copyright Inprise Corporation 1994,2000

# DLLVER is the version number in the RTL .DLL files: the xx (c?32xx*.dll)
# DLLVERSTR is a string representation of the same number for VERSION.RC
  DLLVER        = $(DLLMAJOR)0
  DLLVERSTR     = $(DLLMAJOR).0
!if $d(MT)
!if $d(MAGIC)
  DLLDESCSTR    = Borland C++ Multi-thread RTL (WIN/VCL MT)
!endif # MAGIC
!else
  DLLDESCSTR    = Borland C++ Single-thread RTL (WIN ST)
!endif # MT

# -b:0x32X00000 for base address - X should be only the major version num.
#               ie: 4 for 40 & 45, 5 for 50, 6 for 60, 7 for 70...
LINKER_DLL_BASE_SWITCH=-b:0x32$(DLLMAJOR)00000
!endif

!if $d(MAGIC) && $d(DLL)
!  if $d(RTLSOURCE)
     EXTLIB=$(BCB)\lib\release\vcl$(VCLPACKVER).lib $(BCB)\lib\release\vcle$(VCLPACKVER).lib
!  else
     EXTLIB=$(EXTDIR)\vcl$(VCLPACKVER).lib $(EXTDIR)\vcle$(VCLPACKVER).lib
!  endif
!endif

!if $d(RTLSOURCE)
AFLAGS   = /kh30000 -t -m -D__WIN32__ -I$(BCINCL:;= -I) -I$(INCLBASE)\rtlinc
!else
AFLAGS   = /kh30000 -t -m -D__WIN32__ -I$(INCLBASE) -I$(INCLBASE)\rtlinc
!endif
!if $d(TASM_CASE_SENSITIVE)
AFLAGS   = -ml $(AFLAGS)
!else
AFLAGS   = -mx $(AFLAGS)
!endif

ASM      = tasm32
BRCC     = brcc32
!if $d(MT)
  BRCC   = $(BRCC) -d__MT__
!endif
!if $d(MAGIC)
  BRCC   = $(BRCC) -dMAGIC
!endif

CC       = bcc32 +$(OBJDIR)\$(CFG) $(XTRAFLAGS) $(CCXTRAFLAGS)
CPP      = cpp32 +$(OBJDIR)\$(CFG) $(XTRAFLAGS) $(CPPXTRAFLAGS)
CFLAGS   = -c -X -n$(OBJDIR) -I$(INCLUDES) -ff- -j3 -jb -w -w-sig -V? -D__RTL_BUILD__;NO_STRICT;__USELOCALES__
!if $d(CREATE_ALLSTL)
CFLAGS   = $(CFLAGS) -Jgi -w- -D__CREATE_ALLSTL__
!endif
IMPLIB   = implib -i -c -f
!if $d(RTLSOURCE)
INCLUDES = $(BCINCL);$(INCLBASE)\rtlinc
!else
INCLUDES = $(INCLBASE);$(INCLBASE)\windows;$(INCLBASE)\rtlinc
!endif
!if $d(DLL)
LINK     = ilink32
LINKEROPTS=$(LINKEROPTS) -s -c -Tpd -Gn -Gm -M $(LINKER_DLL_BASE_SWITCH)
LINKEROPTS=$(LINKEROPTS) -D"$(DLLDESCSTR)"
!endif

!if $d(MAGIC)
#
# The RTLDLL now has the prefix CC32 always.  The CC32xxMT.DLL supports
# both the standard Win32 RTL (the old CW32...) and the VCL compatible RTL
# (the old CP32...). The import libraries will still have the same names:
# cw32i, cw32mti, cp32mti
#
LIBNAME      = cp32
LIBNAME_W    = cw32
DLLBASENAME  = cc32
!else
LIBNAME      = cw32
DLLBASENAME  = cc32
!endif

OBJDIR = $(OBJBASE)\obj$(MAGICSUFFIX)$(MTSUFFIX)$(DLLSUFFIX)
PUBTOOL = pubdup.exe
PUBNAME = names32.pub

!if $d(DEBUG)
    TLIB = tlib /C /P512
    TLIB_NO_PURGE = tlib /C /P512
    CFLAGS = $(CFLAGS) -D_RWDEBUG=1 -x -xp
!else
    TLIB = tlib /C /0 /P512
    TLIB_NO_PURGE = tlib /C /P512
    CFLAGS = $(CFLAGS) -O2
!endif

!if $d(MAGIC)
    CFLAGS = $(CFLAGS) -DMAGIC "-D__VCLPACKVERSTR=\"$(VCLPACKVER)\"" -D__VCLPACKVER=$(VCLPACKVER)
    AFLAGS = $(AFLAGS) -DMAGIC
    MAGICSUFFIX = mg
!endif

!if $d(MT)
    AFLAGS = $(AFLAGS) -D_MT
    CFLAGS = $(CFLAGS) -WM
    MTSUFFIX = mt
!else
    CFLAGS = $(CFLAGS) -WM-
!endif

!if $d(BETA)
    CFLAGS = $(CFLAGS) "-D__RTL_BETA=$(BETA)"
!endif

!if $d(MBCS)
    CFLAGS = $(CFLAGS) -D_MBCS -D_MBC_USE_MACROS
    AFLAGS = $(AFLAGS) -D_MBCS -D_MBC_USE_MACROS
!endif

!if $d(DLL)
    AFLAGS = $(AFLAGS) -D_BUILDRTLDLL
    CFLAGS = $(CFLAGS) -D_BUILDRTLDLL -WD -D_RWSTDBUILDDLL -D_RWSTDDLL "-D__RTLDLLVERSTR=\"$(DLLVER)\""
    BRCC = $(BRCC) "-D__RTLDLLVERSTR=\"$(DLLVERSTR)\0\""
    BRCC = $(BRCC) "-D__RTLDLLPRODNAMESTR=\"Borland C++ Builder $(PRODVER)\0\""
    BRCC = $(BRCC) "-D__RTLDLLDESCSTR=\"$(DLLDESCSTR)\0\""
    BRCC = $(BRCC) "-D__RTLDLLCOPYRIGHTSTR=\"$(DLLCOPYRIGHTSTR)\0\""
!if $d(BETA)
    BRCC = $(BRCC) "-D__RTLDLLBETASTR=\"[pre-release version: $(BETA)]\0\""
!endif
    DLLC0 = c0d32
    DLLNAME = $(DLLBASENAME)$(DLLVER)$(MTSUFFIX)
    DLLSUFFIX = x
    IMPLIBNAME = $(LIBNAME)$(MTSUFFIX)i
    IMPORT = import32
!if $d(MAGIC)
    IMPORT = $(IMPORT)
    IMPLIBNAME_W = $(LIBNAME_W)$(MTSUFFIX)i
# Don't force in the VCL memory manager any more
#$(EXTDIR)\memmgr.lib
!endif
!else
    CFLAGS = $(CFLAGS) -W
!endif

#############################################################################
# $(CFG) is created only once for each build.  In order to modify compiler  #
# options on a source directory basis, CC should be modified instead of     #
# CFLAGS.                                                                   #
#############################################################################
!if $d(PCH)
    CC = $(CC) -H -Hc -Hs- -H=$(OBJBASE).csm
!endif

#############################################################################
# The source directories.                                                   #
#############################################################################

#----------------------------------------------------------------------------
# Note: The following dirs must be built in this order for the RTL to work
#----------------------------------------------------------------------------

SRCDIRS =                               \
          $(SRCBASE)\memory             \
          $(SRCBASE)\vcl                \
          $(SRCBASE)\stl\predecl        \
          $(SRCBASE)\stl\allstl         \
          $(SRCBASE)\stl                \
          $(SRCBASE)\conio              \
          $(SRCBASE)\cstrings           \
          $(SRCBASE)\except             \
          $(SRCBASE)\io                 \
          $(SRCBASE)\locale             \
          $(SRCBASE)\math               \
          $(SRCBASE)\mbcs               \
          $(SRCBASE)\misc               \
          $(SRCBASE)\process            \
          $(SRCBASE)\startup            \
          $(SRCBASE)\threads            \
          $(SRCBASE)\time               \
          $(SRCBASE)\pcre


#!if !$d(DLL) && (!$d(MT) || $d(MAGIC))
    SRCDIRS = $(SRCDIRS)                \
              $(SRCBASE)\defs
#!endif
