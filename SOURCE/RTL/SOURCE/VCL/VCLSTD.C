/*
   VCLSTD.C - This file brings in the proper libs for C++ Builder (Standard
              edition) It is the only .obj that goes into making VCL.LIB.
              This .obj is pulled in by a reference in crtlvcl.cpp If the
              user is not linking with the VCL libraries, then the external
              symbol request is satisfied by the one in the crtlstub.cpp
              file.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1999, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#define __VCL_STD_SKU__
#include "vcllib.c"