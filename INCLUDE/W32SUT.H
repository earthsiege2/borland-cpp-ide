#pragma option -b
/***
*w32sut.h -
*
*Purpose:
*       This file declares the constants, structures, and functions
*       used for accessing and using the Universal Thunk mechanism.
*
*       This file should be compiled either with constants W32SUT_16 or
*       W32SUT_32 defined.
*
****/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1994, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

/* Check that one of the 2 constants is defined  */
#ifdef W32SUT_16
#ifdef W32SUT_32
#error W32SUT_16 and W32SUT_32 cannot be defined simultaneously
#endif
#endif

#ifndef W32SUT_16
#ifndef W32SUT_32
#error  Either W32SUT_16 or W32SUT_32 should be defined
#endif
#endif


#if defined(__cplusplus)
extern "C" {
#endif


/****      Prototypes for 32 bit DLL   ***********/
#ifdef W32SUT_32

#ifndef __WINBASE_H
#pragma option -b.
#include <winbase.h>
#pragma option -b
#endif

typedef DWORD  ( WINAPI * UT32PROC)( LPVOID lpBuff,
                                     DWORD  dwUserDefined,
                                     LPVOID *lpTranslationList
                                   );

BOOL    WINAPI UTRegister( HANDLE     hModule,
                           LPCSTR     lpsz16BitDLL,
                           LPCSTR     lpszInitName,
                           LPCSTR     lpszProcName,
                           UT32PROC * ppfn32Thunk,
                           FARPROC    pfnUT32Callback,
                           LPVOID     lpBuff
                         );


VOID    WINAPI UTUnRegister(HANDLE hModule);

#endif


/****      Prototypes for 16 bit DLL   ***********/
#ifdef W32SUT_16

typedef DWORD (FAR PASCAL  * UT16CBPROC)( LPVOID lpBuff,
                                          DWORD  dwUserDefined,
                                          LPVOID FAR *lpTranslationList
                                        );


LPVOID  WINAPI  UTLinearToSelectorOffset(LPBYTE lpByte);
LPVOID  WINAPI  UTSelectorOffsetToLinear(LPBYTE lpByte);

#endif


#if defined(__cplusplus)
}
#endif
#pragma option -b.
