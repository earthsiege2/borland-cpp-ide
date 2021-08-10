/*
   VCLLIB.C - This file brings in the proper libs for C++ Builder.  It is
              the only .obj that goes into making VCL.LIB.  This .obj is
              pulled in by a reference in crtlvcl.cpp  If the user is not
              linking with the VCL libraries, then the external symbol
              request is satisfied by the one in the crtlstub.cpp file.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1997, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.7  $        */


/* __VCLPACKVERSTR is set from the RTL's main WIN32.MAK file.  This allows the
   VCL Package versions to be specified in only one place makeing version
   updates easier */

#ifndef __VCLPACKVERSTR
#error __VCLPACKVERSTR must be defined
#endif

#define __PASTE3(a,b,c) a##b##c
#define __STR(a) #a

#define ADDVER(a) __PASTE3 ( __STR(a), __VCLPACKVERSTR,".lib")

/* These must be listed in REVERSE order of linkage preference */
#pragma comment (lib, ADDVER(bcbsmp))  /* VCL Samples                     */
#pragma comment (lib, ADDVER(dclocx))  /* ActiveX Samples                 */
#ifndef __VCL_STD_SKU__
#pragma comment (lib, ADDVER(vcldbx))  /* eXtra VCL Database stuff        */
#pragma comment (lib, ADDVER(vcldb))   /* VCL Database stuff              */
#endif
#pragma comment (lib, ADDVER(vcle))    /* VCL Emulation stuff (in C++)    */
#pragma comment (lib, ADDVER(vclx))    /* eXtra VCL stuff                 */
#pragma comment (lib, ADDVER(vcl))     /* Normal VCL stuff                */

#include <_defs.h>

/*
   The following symbol errs as undefined if VCL.LIB is linked with
   CW32.LIB, CW32MT.LIB, CW32I.LIB, or CW32MTI.LIB
*/

#define NAME __Must_Link_VCL_Apps_With_The_CP32MT_Or_CP32MTI_RTL

extern char NAME;

void _RTLENTRY __declspec(naked) __CRTL_VCLLIB_Linkage (void)
{
    NAME++;
    __emit__(0xC3); /* asm ret */
}
