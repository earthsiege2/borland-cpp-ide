#----------------------------------------------------------------------------
# Mixing BC++ built 32-bit DLL's with non-BC applications.
# Copyright (c) 1996 by Borland International, All Rights Reserved
#----------------------------------------------------------------------------
.autodepend

!if $d(DEBUG)
LLDBG=/v
CCDBG=-v -vi
!else
!undef LLDBG=
!undef CCDBG=
!endif

LIBS=cw32.lib import32.lib

BcToBc.exe: BCToBC.obj BCToBC.res
   tlink32 -c -Tpe -aa $(LLDBG) c0w32.obj BCToBC.obj, BCToBC.exe, , $(LIBS), , BCToBC.res

BCToBC.obj: CToBC.cpp
   bcc32 -tWE -c -oBCToBC.obj $(CCDBG) CToBC.cpp

BCToBC.res: CToBC.rc
   brc32 -r -foBCToBC.res CToBC.rc
