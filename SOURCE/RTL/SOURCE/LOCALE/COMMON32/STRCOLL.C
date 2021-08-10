/*-----------------------------------------------------------------------*
 * filename - strcoll.c
 *
 * function(s)
 *        strcoll - compares two strings
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <string.h>

/*---------------------------------------------------------------------*

Name            strcoll - compares two strings

Usage           int strcoll(const char *s1, const char *s2);

Prototype in    string.h

Description     strcoll compares the string pointed to by s1 to the
                string pointed to by s2, according to the collating
                sequence set by setlocale. 

Return value    returns a value that is
                   < 0 if s1 is less than s2
                   == 0 if s1 is same as s2
                   > 0 if si is greater than s2

*---------------------------------------------------------------------*/


int _RTLENTRY _EXPFUNC strcoll( const char *s1, const char *s2 )

{
    return( strcmp( s1, s2 ) );
}

