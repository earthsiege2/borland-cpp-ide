#############################################################################
# Configure the tools appropriately.                                        #
#############################################################################
AFLAGS   = -D__$(MODEL)__ -m -mx -q -t -I$(BC45INCL) -I$(INCLBASE)\rtlinc\common16
ASM      = tasm
CC       = bcc $(CCPFX) +$(OBJDIR)\$(CFG) $(CCSFX)
CFLAGS   = -c -k- -2- -Vs -w -w-asm -xc -X -zC_TEXT -zR_DATA -zTDATA -n$(OBJDIR) -I$(INCLUDES) -m$(MODEL)
INCLUDES = $(BC45INCL);$(INCLBASE)\rtlinc\common16
LIBNAME  = c$(MODEL)
OBJDIR   = $(OBJBASE)\$(MODEL)

!if $d(DEBUG)
    TLIB = tlib /C /P128 /E
!else
    TLIB = tlib /C /0 /E
!endif

!if $(MODEL) == t
    CFLAGS = $(CFLAGS) -x- -RT-
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
	  $(SRCBASE)\conio             \
	  $(SRCBASE)\conio\common16    \
	  $(SRCBASE)\cstrings\common16 \
	  $(SRCBASE)\io\common16       \
	  $(SRCBASE)\io\dos            \
	  $(SRCBASE)\iostream          \
	  $(SRCBASE)\locale\common16   \
	  $(SRCBASE)\math\common16     \
	  $(SRCBASE)\math\dos          \
	  $(SRCBASE)\memory\common16   \
	  $(SRCBASE)\memory\dos        \
	  $(SRCBASE)\misc              \
	  $(SRCBASE)\misc\common16     \
	  $(SRCBASE)\misc\dos          \
	  $(SRCBASE)\process\common16  \
	  $(SRCBASE)\process\dos       \
	  $(SRCBASE)\startup\dos       \
	  $(SRCBASE)\time\common16

!if $(MODEL) != t
    SRCDIRS = $(SRCDIRS)                 \
	      $(SRCBASE)\except          \
	      $(SRCBASE)\except\common16 \
	      $(SRCBASE)\mathlib         \
	      $(SRCBASE)\string
!endif


