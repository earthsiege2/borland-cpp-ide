/*---------------------------------------------------------------------------
 * filename - platform.c
 *
 * function(s)
 *        PlatformDetect - detects the current operating system/platform.
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1993, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>
#include <_ostype.h>

unsigned int _EXPDATA _ostype;

static void PlatformDetect(void)
{
#pragma startup PlatformDetect 1
    /*
      Here we call GetProcAddress to get the address of the
      "GetProcAddress" function.  This should never fail.  Then we call
      through the pfn to see if the phantom "Borland32" entry exists
      (dictating that we are under DPMI32).  This call will fail when we
      are not running under DPMI32 and thus we bypass the CG failure
      report.
    */
    typedef void * (__stdcall *pfn_t) (void *, const char *);
    pfn_t pfn;
    HANDLE hkernel32;
    hkernel32 = GetModuleHandle("kernel32.dll");
    pfn = (pfn_t)GetProcAddress(hkernel32, "GetProcAddress");
    if (pfn(hkernel32, "Borland32"))
        _ostype = _DOS32;
    else if (GetVersion() & 0x80000000)
        _ostype = _WIN32S;
    else
        _ostype = _WIN32;
}

