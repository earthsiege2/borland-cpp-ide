/*-----------------------------------------------------------------------*
 * filename - mbsicoll.c
 *
 * function(s)
 *        _mbsicoll -
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

/* -----------------------------------------------------------------------*

Name            _mbsicoll

Usage           _mbsicoll ( const unsigned char * String1,const unsigned char * String2);

Prototype in    mbsicoll.h

Description     _mbsicoll() performs a case-insensitive comparison of the
                strings according to the current locale in use.

*--------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _mbsicoll( const unsigned char *__S1, const unsigned char *__S2 )
{
    int ret;

    ret = CompareString ( __locale->handle, NORM_IGNORECASE, (LPCTSTR)__S1, -1, (LPCTSTR)__S2, -1 );
    return (ret-2);
}
