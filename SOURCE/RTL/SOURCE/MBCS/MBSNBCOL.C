/*-----------------------------------------------------------------------*
 * filename - mbsnbcol.c
 *
 * variables(s)
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <mbctype.h>
#include <_locale.h>
#include <mbstring.h>
#include <windows.h>

/*-----------------------------------------------------------------------*

Name            _mbsnbcoll

Usage           int _RTLENTRY _EXPFUNC _mbsnbcoll( const unsigned char *__S1, const unsigned char *__S2, size_t n )

Prototype in    mbstring.h

Description     _mbsnbcoll() performs a case sensitive comparison of the
					 1st n bytes according to the current locale in use
*-----------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _mbsnbcoll( const unsigned char *__S1, const unsigned char *__S2, size_t n )
{
    int ret;

    ret = CompareString ( __locale->handle, 0, (LPCTSTR)__S1, n, (LPCTSTR)__S2, n );
    return (ret-2);
}
