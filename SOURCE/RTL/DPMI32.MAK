#############################################################################
# Configure the tools appropriately.                                        #
#############################################################################
AFLAGS   = -D__WIN32__ -D__DPMI32__ -I$(BCINCL) -I$(INCLBASE)\rtlinc\win32 -Mx -t -m
ASM      = tasm32
CC       = bcc32 +$(OBJDIR)\$(CFG)
CFLAGS   = -c -X -n$(OBJDIR) -I$(INCLUDES) -w -w-sig -WX
IMPLIB   = implib -i -c
INCLUDES = $(BCINCL);$(INCLBASE)\rtlinc\common32;$(INCLBASE)\rtlinc\win32
LIBNAME  = dpmi32
OBJDIR   = $(OBJBASE)
PUBTOOL  = pubdup.exe

!if $d(DEBUG)
    TLIB = tlib /C /P128
!else
    TLIB = tlib /C /0
!endif


#############################################################################
# The source directories.                                                   #
#############################################################################
SRCDIRS =                         \
	$(SRCBASE)\bios\dpmi32    \
	$(SRCBASE)\defs\dpmi32    \
	$(SRCBASE)\io\dpmi32      \
	$(SRCBASE)\memory\dpmi32  \
	$(SRCBASE)\misc\dpmi32    \
	$(SRCBASE)\process\dpmi32
