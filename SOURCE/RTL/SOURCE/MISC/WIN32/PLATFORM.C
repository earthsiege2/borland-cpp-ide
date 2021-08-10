/*---------------------------------------------------------------------------
 * filename - platform.c
 *
 * function(s)
 *        PlatformDetect - detects the current operating system/platform.
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1993, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>
#include <_ostype.h>

unsigned int _EXPDATA _ostype;

static void PlatformDetect(void)
{
#pragma startup PlatformDetect 1

    if (GetProcAddress(GetModuleHandle ("kernel32.dll"), "Borland32"))
        _ostype = _DOS32;
    else if (GetVersion() & 0x80000000)
        _ostype = _WIN32S;
    else
        _ostype = _WIN32;
}

