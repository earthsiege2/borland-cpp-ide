#############################################################################
# Configure the tools appropriately.                                        #
#############################################################################
AFLAGS   = -Mx -t -m -D__WIN32__ -I$(BC45INCL) -I$(INCLBASE)\rtlinc\common32 -I$(INCLBASE)\rtlinc\win32
ASM      = tasm32
BRCC     = brcc32
CC       = bcc32 +$(OBJDIR)\$(CFG)
CFLAGS   = -c -X -n$(OBJDIR) -I$(INCLUDES) -w -w-sig
IMPLIB   = implib -i -c
INCLUDES = $(BC45INCL);$(INCLBASE)\rtlinc\common32;$(INCLBASE)\rtlinc\win32
LINK     = tlink32 -s -c -Tpd
LIBNAME  = cw32
OBJDIR   = $(OBJBASE)\obj$(MTSUFFIX)$(DLLSUFFIX)

!if $d(DEBUG)
    TLIB = tlib /C /P128
!else
    TLIB   = tlib /C /0
    CFLAGS = $(CFLAGS) -O2
!endif

!if $d(MT)
    AFLAGS   = $(AFLAGS) -D_MT
    CFLAGS   = $(CFLAGS) -D_MT -WM
    MTSUFFIX = mt
!endif

!if $d(DLL)
    AFLAGS     = $(AFLAGS) -D_BUILDRTLDLL
    CFLAGS     = $(CFLAGS) -D_BUILDRTLDLL -WD
    DLLC0      = c0d32
    DLLDEF     = $(LIBNAME)$(MTSUFFIX)
    DLLNAME    = $(LIBNAME)$(DLLVER)$(MTSUFFIX)
    DLLSUFFIX  = x
    DLLVER     = 15
    IMPLIBNAME = $(LIBNAME)$(MTSUFFIX)i
    IMPORT     = import32
!else
    CFLAGS     = $(CFLAGS) -W
!endif

#############################################################################
# $(CFG) is created only once for each build.  In order to modify compiler  #
# options on a source directory basis, CC should be modified instead of     #
# CFLAGS.                                                                   #
#############################################################################
!if $d(PCH)
    CC = $(CC) -H -Hc
!endif

#############################################################################
# The source directories.                                                   #
#############################################################################
SRCDIRS =                               \
	  $(SRCBASE)\conio              \
	  $(SRCBASE)\conio\common32     \
	  $(SRCBASE)\conio\win32        \
	  $(SRCBASE)\cstrings\common32  \
	  $(SRCBASE)\except             \
	  $(SRCBASE)\except\common32    \
	  $(SRCBASE)\except\win32       \
	  $(SRCBASE)\io\common32        \
	  $(SRCBASE)\io\win32           \
	  $(SRCBASE)\iostream           \
	  $(SRCBASE)\iostream\common32  \
	  $(SRCBASE)\locale\common32    \
	  $(SRCBASE)\math\common32      \
	  $(SRCBASE)\memory\common32    \
	  $(SRCBASE)\memory\win32       \
	  $(SRCBASE)\misc               \
	  $(SRCBASE)\misc\common32      \
	  $(SRCBASE)\misc\win32         \
	  $(SRCBASE)\process\common32   \
	  $(SRCBASE)\process\win32      \
	  $(SRCBASE)\startup\common32   \
	  $(SRCBASE)\startup\win32      \
	  $(SRCBASE)\string             \
	  $(SRCBASE)\string\windows     \
	  $(SRCBASE)\threads\win32      \
	  $(SRCBASE)\time\common32      \
	  $(SRCBASE)\time\win32

!if $d(MT)
    SRCDIRS = $(SRCDIRS)                \
	      $(SRCBASE)\threads        \
	      $(SRCBASE)\threads\win32
!endif

!if $d(DLL) && !$d(MT)
    SRCDIRS = $(SRCDIRS)                \
	      $(SRCBASE)\defs\win32 
!endif
