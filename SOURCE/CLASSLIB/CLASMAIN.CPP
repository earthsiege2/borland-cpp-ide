/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CLASMAIN.CPP                                                          */
/*                                                                        */
/*  Copyright Borland International 1991, 1993                            */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*  Provides the LibMain() function for the DLL version                   */
/*  of the class libraries                                                */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __WINDOWS_H )
#include <windows.h>
#endif	// __WINDOWS_H

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

#endif  // __WIN32__
