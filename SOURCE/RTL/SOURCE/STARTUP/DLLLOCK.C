/*-----------------------------------------------------------------------*
 * filename - dlllock.c
 *
 * function(s)
 *
 *   __CRTL_DLL_Lock
 *   __CRTL_DLL_Unlock
 *
 *
 *   Both functions are called from the startup code.  Lock happens
 *   very early and Unlock happens very late.
 *
 *
 *   __CRTL_DLL_Lock()
 *
 *     locks the RTL (with a LoadLibrary) when the DLL being built
 *     (which is using this startup code) is linked to the RTLDLL's
 *     import library.  Else, the static RTL stubs out this call in
 *     dllstub.c.
 *
 *     This is needed for Windows95 since Win95 has problems
 *     unloading DLLs which have references to other DLLs that may
 *     be both implicitly and explicitly loaded.  WinNT handles
 *     this properly, and this extra locking shouldn't affect it.
 *
 *   __CRTL_DLL_Unlock()
 *
 *     Unlocks the RTL (with FreeLibrary)
 *
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.3  $        */

#include <windows.h>
#include <_defs.h>

#ifndef __RTLDLLVERSTR
#error __RTLDLLVERSTR must be defined
#endif

/*
   This rats-nest of macros simply allows us to create a string from
   a define that the makefile specifies.  The RTLDLL name is:

     "Cx32##yy.DLL"

   where x is :
    'W' for normal Windows or
    'P' for Pascal (the VCL version)

   ## is the two digit version number of the RTL

   yy is :
    'MT' for Multi threaded or
    '' (blank) for Single threaded
*/

#define __PASTE3(a,b,c) a##b##c
#define __STR(a) #a

#define ADDVER(a) __PASTE3 ( __STR(a), __RTLDLLVERSTR,".DLL")
#define ADDVER_MT(a) __PASTE3 ( __STR(a), __RTLDLLVERSTR,"MT.DLL")


static HINSTANCE hDLL;
static char    sRTLDLL [] =
#  ifdef __MT__
  ADDVER_MT(CC32);
#  else
  ADDVER(CC32);
#  endif

void _RTLENTRY __CRTL_DLL_Lock (void)
{
  hDLL = LoadLibrary (sRTLDLL);
  if ((int)hDLL == NULL)
    _ErrorExit("RTLDLL cannot find itself!");
}

void _RTLENTRY __CRTL_DLL_Unlock (void)
{
  if (hDLL)
  {
    FreeLibrary (hDLL);
    hDLL = (HINSTANCE) 0;
  }
}
