#----------------------------------------------------------------------------
# Mixing BC++ built 32-bit DLL's with non-BC applications.
# Copyright (c) 1996 by Borland International, All Rights Reserved
#----------------------------------------------------------------------------
.autodepend

CCOPT = -tWD
LLOPT = -c -x -aa -Tpd

!if $d(DEBUG)
CCOPT = $(CCOPT) -v -vi
LLOPT = $(LLOPT) -v
!endif

# Note special startup code.
bcdll.dll: bcdll.obj bcdll.def
   tlink32 $(LLOPT) @&&|
c0d32dyn.obj bcdll.obj, bcdll.dll, bcdll.map, import32.lib cw32.lib, bcdll.def
|

bcdll.obj: bcdll.cpp
   bcc32 $(CCOPT) -c -w-aus bcdll.cpp
