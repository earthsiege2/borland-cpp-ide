#############################################################################
# Configure the tools appropriately.                                        #
#############################################################################
AFLAGS   = -D__$(MODEL)__ -D_Windows -D_WINDOWS -o -m -mx -q -t -I$(BCINCL) -I$(INCLBASE)\RTLINC\common16
ASM      = tasmx
BRCC     = brcc
CC       = bcc $(CCPFX) +$(OBJDIR)\$(CFG) $(CCSFX)
CFLAGS   = -a- -c -D_WINDOWS -w -w-asm -xc -X -zC_TEXT -zR_DATA -n$(OBJDIR) -I$(INCLUDES) -m$(MODEL)
IMPLIB   = implib -i -o
INCLUDES = $(BCINCL);$(INCLBASE)\rtlinc\common16
LINK     = tlink -s -Twd # -Oc -Oi -Oa -Or
PUBTOOL  = pubdup.exe
PUBNAME  = names16.pub

!if $d(DEBUG)
    TLIB = tlib /C /P128
!else
    TLIB = tlib /C /0
!endif

!if $d(DLL)
    AFLAGS     = $(AFLAGS) -D_BUILDRTLDLL
    CFLAGS     = $(CFLAGS) -D_RTLDLL -D_BUILDRTLDLL -WDE -D_RWSTDBUILDDLL -D_RWSTDDLL
    DLLC0      = c0rtldll
    DLLDEF     = bcrtl
    DLLNAME    = bc$(DLLVER)rtl
    DLLVER     = 500
    LIBNAME    = cwd
    LINK       = $(LINK)
    IMPLIBNAME = crtldll
    IMPORT     = import
    OBJDIR     = $(OBJBASE)\d
!else
    CFLAGS     = $(CFLAGS) -WE -Vs
    OBJDIR     = $(OBJBASE)\$(MODEL)
    LIBNAME    = cw$(MODEL)
!endif

#############################################################################
# $(CFG) is created only once for each build.  In order to modify compiler  #
# options on a source directory basis, CC should be modified instead of     #
# CFLAGS.                                                                   #
#############################################################################
!if $d(PCH)
    CC = $(CC) -H
!endif

!if !$d(NOOPT)
    CC = $(CC) -O1
!endif

#############################################################################
# The source directories.                                                   #
#############################################################################
SRCDIRS =                              \
	  $(SRCBASE)\bios\common16     \
	  $(SRCBASE)\conio\common16    \
	  $(SRCBASE)\cstrings\common16 \
	  $(SRCBASE)\easywin           \
	  $(SRCBASE)\except            \
	  $(SRCBASE)\except\common16   \
	  $(SRCBASE)\except\win16      \
	  $(SRCBASE)\io\common16       \
	  $(SRCBASE)\io\win16          \
	  $(SRCBASE)\iostream          \
	  $(SRCBASE)\locale\common16   \
	  $(SRCBASE)\mathlib           \
	  $(SRCBASE)\math\common16     \
	  $(SRCBASE)\math\win16        \
	  $(SRCBASE)\memory\common16   \
	  $(SRCBASE)\memory\win16      \
	  $(SRCBASE)\misc              \
	  $(SRCBASE)\misc\common16     \
	  $(SRCBASE)\misc\win16        \
	  $(SRCBASE)\process\common16  \
	  $(SRCBASE)\process\win16     \
	  $(SRCBASE)\startup\win16     \
	  $(SRCBASE)\string            \
	  $(SRCBASE)\string\windows    \
	  $(SRCBASE)\time\common16     \

!if $d(DLL)
    SRCDIRS = $(SRCDIRS)                \
	      $(SRCBASE)\cstrings\win16 \
	      $(SRCBASE)\defs\win16
!endif
