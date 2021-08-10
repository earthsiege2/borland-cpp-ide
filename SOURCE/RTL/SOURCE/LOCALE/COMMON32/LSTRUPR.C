/*-----------------------------------------------------------------------*
 * filename - lstrupr.c
 *
 * function(s)
 *        _lstrupr - converts lower-case letters in a string to upper-case
 *                   according to the current locale
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <string.h>
#include <ctype.h>
#include <_locale.h>

/*---------------------------------------------------------------------*

Name            _lstrupr - converts lower-case letters in a string to upper-case

Usage           char *_lstrupr(char *str);

Prototype in    string.h

Description     _lstrupr converts lower-case letters in string str to upper-case.
                No other changes occur.

Return value    pointer to str

*---------------------------------------------------------------------*/

char * _RTLENTRYF _EXPFUNC _lstrupr(char *str)
{
    unsigned char *p = (unsigned char *) str;

    while ( (*p = (unsigned char) _pLocale->pToUpper[ *p ] ) != '\0' )
         p++;

    return str;
}
