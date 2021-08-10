/*-----------------------------------------------------------------------*
 * filename - lstrupr.c
 *
 * function(s)
 *        _lstrupr - converts lower-case letters in a string to upper-case
 *                   according to the current locale
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

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

    while ( (*p = (unsigned char) _ltoupper( *p ) ) != '\0' )
         p++;

    return str;
}
