#----------------------------------------------------------------------------
# Mixing BC++ built 32-bit DLL's with non-BC applications.
# Copyright (c) 1996 by Borland International, All Rights Reserved
#----------------------------------------------------------------------------
!if defined(DEBUG)
CCDBG=/Zi
LLDBG=/v
!else
!undef CCDBG
!undef LLDBG
!endif

VCToBC.exe: VCToBC.obj VCToBC.res
   link $(LLDBG) VCToBC.obj kernel32.lib user32.lib gdi32.lib VCToBC.res

VCToBC.obj: CToBC.cpp bcdll.h CToBC.rh
   cl $(CCDBG) /c /GX /FoVCToBC.obj CToBC.cpp

VCToBC.res: CToBC.rc CToBC.rh
   rc -r -foVCToBC.res CToBC.rc
