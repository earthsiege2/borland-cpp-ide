#
# Inprise C++Builder - (C) Copyright 1999 by Borland International
#

CC       = bcc32
RC       = brcc32
AS       = tasm32

!if $d(__NMAKE__)
CXX      = bcc32 -P
CPP      = bcc32 -P
!endif

.asm.obj:
      $(AS) $(AFLAGS) $&.asm

.c.exe:
      $(CC) $(CFLAGS) $&.c

.c.obj:
      $(CC) $(CFLAGS) /c $&.c

.cpp.exe:
      $(CC) $(CFLAGS) $&.cpp

.cpp.obj:
      $(CC) $(CPPFLAGS) /c $&.cpp

.rc.res:
      $(RC) $(RFLAGS) /r $&

.SUFFIXES: .exe .obj .asm .c .res .rc

!if !$d(BCEXAMPLEDIR)
BCEXAMPLEDIR = $(MAKEDIR)\..\EXAMPLES
!endif
