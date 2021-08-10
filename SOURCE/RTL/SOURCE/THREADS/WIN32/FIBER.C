/*-----------------------------------------------------------------------*
 * filename - fiber.c
 *
 * function(s)
 *      GetFiberData
 *      GetCurrentFiber
 *
 * These functions were originally defined as inline in WINNT.H.  Since
 * we don't support inline functions in "C" (yet), we have moved them here
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1996, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.0  $        */

#include <ntbc.h>

void __emit__(unsigned char, ...);      /* prototype for __emit__ */

PVOID GetFiberData( void )
{

    __emit__ (0x64, 0xA1, 0x10, 0, 0, 0); /* mov eax,fs:[0x10] */
    _EAX = *((DWORD *)_EAX);
    return (PVOID)_EAX;
}

PVOID GetCurrentFiber( void )
{
    __emit__ (0x64, 0xA1, 0x10, 0, 0, 0); /* mov eax,fs:[0x10] */
    return (PVOID)_EAX;
}
