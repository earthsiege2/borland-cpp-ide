/*---------------------------------------------------------------------------
 * filename - platform.c
 *
 * function(s)
 *        PlatformDetect - detects the current operating system/platform.
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1993, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

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
    else
    {
        OSVERSIONINFO ver;
	
        ver.dwOSVersionInfoSize = sizeof(ver);
        GetVersionEx(&ver);
        switch(ver.dwPlatformId)
        {
        case VER_PLATFORM_WIN32s:
            _ostype = _WIN32S;
            break;
        case VER_PLATFORM_WIN32_WINDOWS:
            _ostype = _WIN95;
            break;
        case VER_PLATFORM_WIN32_NT:
            _ostype = _WINNT;
            break;
        default:
            //  Hmmm, shouldn't get here.  Set to least capable OS.
            _ostype = _WIN32S;
            break;
        }
    }
}



