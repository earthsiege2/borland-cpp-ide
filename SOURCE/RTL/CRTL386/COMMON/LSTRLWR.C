/*-----------------------------------------------------------------------*
 * filename - lstrlwr.c
 *
 * function(s)
 *        _lstrlwr - converts a string to lower-case according
 *                   to the current locale
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <string.h>
#include <ctype.h>
#include <_locale.h>

/*---------------------------------------------------------------------*

Name            _lstrlwr - converts a string to lower-case

Usage           char *_lstrlwr(char *str);

Prototype in    string.h

Description     _lstrlwr converts upper-case letters in string str to lower-case.
                No other changes occur.

Return value    pointer to the converted string

*---------------------------------------------------------------------*/

char * _RTLENTRYF _EXPFUNC _lstrlwr(char *str)
{
    unsigned char *p = (unsigned char *) str;

    while ( (*p = (unsigned char) _pLocale->pToLower[ *p ] ) != '\0')
         p++;

    return str;
}



