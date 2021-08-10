#############################################################################
# Special compiler flags for STL modules.                                   #
# This file is included from each of the MAKEFILEs below this dir.          #
#############################################################################
XTRAFLAGS = $(XTRAFLAGS) -I..\ -D_RWSTD_COMPILE_INSTANTIATE=1 -V? -R- -X -O2 -k-
XTRAFLAGS = $(XTRAFLAGS) -w-inl -w-use -w-aus -w-csu
XTRAFLAGS = $(XTRAFLAGS) -H -He -Hc -Hs -H=$(OBJDIR)\stl.csm

!if !$d(CREATE_ALLSTL)
XTRAFLAGS = $(XTRAFLAGS) -Jgx
!endif