/*-----------------------------------------------------------------------*
 * filename - mbsncoll.c
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

Name            _mbsncoll

Usage           int _RTLENTRY _EXPFUNC _mbsncoll( const unsigned char *__S1, const unsigned char *__S2, size_t n )

Prototype in    mbstring.h

Description     _mbsncoll() performs a case sensitive comparison of the
					 1st n characters according to the current locale in use
*-----------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _mbsncoll( const unsigned char *__S1, const unsigned char *__S2, size_t n )
{
    int ret;
    int CharCount1;
    int CharCount2;

    CharCount1 = _mbsnbcnt ( __S1,n );
    CharCount2 = _mbsnbcnt ( __S2,n );

    ret = CompareString ( __locale->handle, 0, (LPCTSTR)__S1, CharCount1, (LPCTSTR)__S2, CharCount2 );
    return (ret-2);
}
