/*-----------------------------------------------------------------------*
 * filename - mbscoll.c
 *
 * function(s)
 *        _mbscoll -
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#include <mbctype.h>
#include <_locale.h>
#include <mbstring.h>
#include <windows.h>

/*-----------------------------------------------------------------------*

Name            _mbscoll

Usage           int _RTLENTRY _EXPFUNC _mbscoll( const unsigned char *__S1, const unsigned char *__S2)

Prototype in    mbstring.h

Description     _mbscoll() performs a case sensitive comparison of the
                strings according to the current locale in use.

*-----------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _mbscoll( const unsigned char *__S1, const unsigned char *__S2)
{
    int ret;

    ret = CompareString ( __locale->handle, 0, (LPCTSTR)__S1, -1, (LPCTSTR)__S2, -1 );
    return (ret-2);
}
