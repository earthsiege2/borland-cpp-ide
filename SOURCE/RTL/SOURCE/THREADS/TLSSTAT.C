/*-----------------------------------------------------------------------*
 * filename - tlsstat.c
 *
 * function(s)
 *
 *   ___CRTL_TLS_Alloc
 *   ___CRTL_TLS_Free
 *   ___CRTL_TLS_GetValue
 *   ___CRTL_TLS_SetValue
 *
 *   These functions simply pass through to the System API versions, and are
 *   linked in only when linking with the static RTL lib (not the RTLDLL).
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1998, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.7.2.1 $        */

#include <_defs.h>
#include <windows.h>

DWORD WINAPI _EXPFUNC ___CRTL_TLS_Alloc (void)
{
    return TlsAlloc ();
}

BOOL WINAPI _EXPFUNC ___CRTL_TLS_Free (DWORD id)
{
    return TlsFree (id);
}

LPVOID WINAPI _EXPFUNC ___CRTL_TLS_GetValue (DWORD id)
{
    return TlsGetValue (id);
}

BOOL WINAPI _EXPFUNC ___CRTL_TLS_SetValue (DWORD id, LPVOID value)
{
    return TlsSetValue (id, value);
}

#pragma argsused
void WINAPI _EXPFUNC ___CRTL_TLS_InitThread (DWORD id)
{
}

#pragma argsused
void WINAPI _EXPFUNC ___CRTL_TLS_ExitThread (DWORD id)
{
}

int _RTLENTRY _EXPFUNC __CRTL_TLS_GetInfo (void)
/*
  This function in used for internal testing.  It returns the number of
  Alloc's that have been made.
*/
{
    return 0;
}
