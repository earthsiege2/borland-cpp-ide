/*------------------------------------------------------------------------
 * filename - rtlmain.c
 *
 * function(s)
 *        LibMain - Dummy LibMain for DLLs.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <windows.h>

#pragma argsused

int FAR PASCAL LibMain( HANDLE hInst, WORD wData, WORD cbHeap, LPSTR cmd )
{
    return 1;
}
