#-----------------------------------------------------------------------------
# ObjectWindows - (C) Copyright 1991, 1993 by Borland International
#
# Internal MAKEFILE to build owl16.ord
#
# Rebuilds the ord file using the -Ur option of the internal tlink build
# Reattach the header & follow any special instructions below.
#
# Notes:
#  Leave WEP out since a special resident entry is produced by the makefile
#  Leave @TGdiObject@0RefDec$qpxv out since it's signature may vary w/ diags
#  Comment out entries so that the total names are < 64K (name table limit)
#
#-----------------------------------------------------------------------------

$(.PATH.cpp)\owl16.ord: $(ILIBDEPOBJS)
  @cd $(.PATH.obj)
  $(TLINK)U @&&|
$(LMKORD) -L$(BCLIBDIR) c0dl +
$(LINKOBJS)
$(OWLDLL)
$(.PATH.cpp)\owl16.ord
-v- $(BIDSILIB) $(STDLIBS)
|
  @cd $(.PATH.cpp)

!include makefile

LMKORD = $(LDBG) -Twd -n -s -c -C -Ur
