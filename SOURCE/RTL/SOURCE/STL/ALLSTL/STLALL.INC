#############################################################################
# Special compiler flags for STL modules.                                   #
# This file is included from the MAKEFILE in this dir which builds allstl   #
#############################################################################
XTRAFLAGS = $(XTRAFLAGS) -I..\ -D_RWSTD_COMPILE_INSTANTIATE=1 -V? -R- -X -O2 -k-
XTRAFLAGS = $(XTRAFLAGS) -w-inl -w-use -w-aus -w-csu
XTRAFLAGS = $(XTRAFLAGS) -H -He -Hc -Hs -H=$(OBJDIR)\stl.csm
