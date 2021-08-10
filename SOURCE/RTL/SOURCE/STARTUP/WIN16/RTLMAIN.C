/*------------------------------------------------------------------------
 * filename - rtlmain.c
 *
 * function(s)
 *        LibMain - Dummy LibMain for DLLs.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <windows.h>

#pragma argsused

int FAR PASCAL LibMain( HANDLE hInst, WORD wData, WORD cbHeap, LPSTR cmd )
{
    return 1;
}
