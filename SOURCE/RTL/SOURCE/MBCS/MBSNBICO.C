/*-----------------------------------------------------------------------*
 * filename - mbsnbico.c
 *
 * function(s)
 *        _mbsnbicoll -
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */


#include <mbctype.h>
#include <_locale.h>
#include <mbstring.h>
#include <windows.h>

/*------------------------------------------------------------------------*

Name            _mbsnbicoll

Usage           int _RTLENTRY _EXPFUNC _mbsnbicoll( const unsigned char *__S1, const unsigned char *__S2, size_t n );

Prototype in    mbstring.h

Description     _mbsnbicoll() Collates up to n bytes of 2 MBCS strings. This performs
                a comparison of the strings ignoring case and according to the
                current locale in use.

*-------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _mbsnbicoll( const unsigned char *__S1, const unsigned char *__S2, size_t n )
{
    int ret;

    ret = CompareString ( __locale->handle, NORM_IGNORECASE, (LPCTSTR)__S1, n, (LPCTSTR)__S2, n );
    return (ret-2);
}
