// Borland C++ - (C) Copyright 1991, 1992 by Borland International

// Example program used to demonstrate DLL's. This file, is one of the
// files used to build BITMAP.DLL which is used in the DLLDEMO program.

#define  STRICT
#include <windows.h>
#pragma hdrstop

// Turn off warning: Parameter '' is never used
#pragma argsused

// Every DLL has an entry point LibMain || DllEntryPoint
// and an exit point WEP.
#if defined(__FLAT__)
BOOL WINAPI DllEntryPoint( HINSTANCE hinstDll,
                           DWORD fdwRreason,
                           LPVOID plvReserved)
#else /* not flat model  */
int FAR PASCAL LibMain( HINSTANCE hInstance,
                        WORD wDataSegment,
                        WORD wHeapSize,
                        LPSTR lpszCmdLine )
#endif /* __FLAT */
{
#ifndef  __FLAT__

// The startup code for the DLL initializes the local heap(if there is one)
// with a call to LocalInit which locks the data segment.

    if ( wHeapSize != 0 )
        UnlockData( 0 );
#endif
    return 1;   // Indicate that the DLL was initialized successfully.
}

// Turn off warning: Parameter '' is never used
#pragma argsused

int FAR PASCAL WEP ( int bSystemExit )
{
    return 1;
}
