/*-----------------------------------------------------------------------*
 * filename - strupr.c
 *
 * function(s)
 *        strupr - converts a string to upper-case according to the
 *                 "C" locale

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

/*---------------------------------------------------------------------*

Name            strupr - converts lower-case letters in a string to upper-case

Usage           char *strupr(char *str);

Prototype in    string.h

Description     strupr converts lower-case letters in string str to upper-case.
                No other changes occur.

Return value    pointer to str

*---------------------------------------------------------------------*/

char * _RTLENTRYF _EXPFUNC strupr(char *str)
{
    char *p = str;

    while ( (*p = (char)toupper(*p)) != '\0' )
         p++;

    return str;
}

