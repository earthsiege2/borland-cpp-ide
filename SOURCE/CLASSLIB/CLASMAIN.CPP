/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CLASMAIN.CPP                                                          */
/*                                                                        */
/*  Copyright (c) 1991, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*  Provides the LibMain() function for the DLL version                   */
/*  of the class libraries                                                */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __WINDOWS_H )
#include <windows.h>
#endif

#if defined(__WIN32__)

BOOL DllEntryPoint(HINSTANCE /*hInstance*/, DWORD /*flag*/, LPVOID)
{
    return 1;
}

#else

extern "C" int FAR PASCAL LibMain( HANDLE, WORD, WORD, LPSTR )
{
    return 1;
}

#endif
