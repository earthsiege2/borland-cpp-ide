//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.8  $
//
// Provides the main entry point function for the DLL version of the class
// libraries
//----------------------------------------------------------------------------
#include <classlib/pch.h>
#include <classlib/defs.h>
#include <services/wsysinc.h>
#include <tchar.h>

#if defined(BI_PLAT_WIN32)

int WINAPI DllEntryPoint(HINSTANCE /*hInstance*/, DWORD /*flag*/, LPVOID)
{
    return 1;
}

#elif defined(BI_PLAT_WIN16)

extern "C" int FAR PASCAL LibMain(HINSTANCE, WORD, WORD, LPSTR)
{
    return 1;
}

#elif defined(BI_PLAT_OS2)

int _tmain()
{
    return 0;
}

#endif
