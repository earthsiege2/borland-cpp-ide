/*-----------------------------------------------------------------------*
 * filename - DllMain.c
 *
 * function(s)
 *      DllMain     - default DLL user initialization
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

/*---------------------------------------------------------------------*

Name            DLLMain - default DLL user initialization

Usage           BOOL  WINAPI DllMain(HINSTANCE hInst,
                           DWORD ul_reason_being_called,
                           LPVOID lpReserved)

Prototype in    none

Description     DllMain is called by the default DllEntrypoint when a DLL
                is initialized, after all other RTL initialization is
                performed.  This is the default version, which is
                linked if the user does not provide one.

Return value    If it is successful, DllMain returns 1; if an error
                occurs, it returns 0.

*---------------------------------------------------------------------*/

#pragma argsused

BOOL  WINAPI DllMain(HINSTANCE hInst,
                           DWORD ul_reason_being_called,
                           LPVOID lpReserved)
{
    return 1;
}






