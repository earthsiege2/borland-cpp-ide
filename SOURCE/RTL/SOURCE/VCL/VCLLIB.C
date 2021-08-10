/*
   VCLLIB.C - This file brings in the proper libs for C++ Builder.  It is
              the only .obj that goes into making VCL.LIB.  This .obj is
              pulled in by a reference in crtlvcl.cpp  If the user is not
              linking with the VCL libraries, then the external symbol
              request is satisfied by the one in the crtlstub.cpp file.

*/

/* $Copyright: 1997$ */
/* $Revision: 9.13 $        */


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
/* Pre-bcb6 these libs had __VCLPACKVERSTR appended to them. Starting
 * in bcb6 the version number has been removed so ADDVER is no longer used. 
 */
#pragma comment (lib, "bcbsmp.lib")  /* VCL Samples                     */
#pragma comment (lib, "dclocx.lib")  /* ActiveX Samples                 */
#ifndef __VCL_STD_SKU__
#pragma comment (lib, "vcldbx.lib")  /* eXtra VCL Database stuff        */
#pragma comment (lib, "vcldb.lib")   /* VCL Database stuff              */
#endif
#pragma comment (lib, "vcle.lib")    /* VCL Emulation stuff (in C++)    */
#pragma comment (lib, "vclx.lib")    /* eXtra VCL stuff                 */
#pragma comment (lib, "vcl.lib")     /* Normal VCL stuff                */
#pragma comment (lib, "rtl.lib")     /* Delphi RTL stuff                */

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
