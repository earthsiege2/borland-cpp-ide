#############################################################################
# Configure the tools appropriately.                                        #
#############################################################################
AFLAGS   = -D__$(MODEL)__ -D__DPMI16__ -D_WINDOWS -D_Windows -m -mx -q -t -I$(BC45INCL) -I$(INCLBASE)\rtlinc\common16
ASM      = tasm
CC       = bcc +$(OBJDIR)\$(CFG)
CFLAGS   = -WX -a- -c -D_WINDOWS -O1 -Vs -w -w-asm -xc -X -zC_TEXT -zR_DATA -n$(OBJDIR) -I$(INCLUDES) -m$(MODEL)
IMPLIB   = implib -i -c -o
INCLUDES = $(BC45INCL);$(INCLBASE)\rtlinc\common16
LIBNAME  = dpmi16
OBJDIR   = $(OBJBASE)

!if $d(DEBUG)
    TLIB = tlib /C /P128 /E
!else
    TLIB = tlib /C /0 /E
!endif

#############################################################################
# The source directories.                                                   #
#############################################################################
SRCDIRS =                              \
	  $(SRCBASE)\bios\common16     \
	  $(SRCBASE)\conio             \
	  $(SRCBASE)\conio\common16    \
	  $(SRCBASE)\defs\dpmi16       \
	  $(SRCBASE)\io\common16       \
	  $(SRCBASE)\mathlib           \
	  $(SRCBASE)\memory\win16      \
	  $(SRCBASE)\misc\dos          \
	  $(SRCBASE)\misc\win16        \
	  $(SRCBASE)\process\dos       \
	  $(SRCBASE)\process\dpmi16    \
	  $(SRCBASE)\process\win16     \
	  $(SRCBASE)\startup\win16
