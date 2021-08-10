/*-----------------------------------------------------------------------*
 * filename - strlwr.c
 *
 * function(s)
 *        strlwr - converts a string to lower-case according to the
 *                 "C" locale
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

/*---------------------------------------------------------------------*

Name            strlwr - converts a string to lower-case

Usage           char *strlwr(char *str);

Prototype in    string.h

Description     strlwr converts upper-case letters in string str to lower-case.
                No other changes occur.

Return value    pointer to the converted string

*---------------------------------------------------------------------*/

char * _RTLENTRYF _EXPFUNC strlwr(char *s)
{
    char *p = s;
    while ( (*p = (char)tolower(*p)) != '\0')
         p++;
    return s;
}
