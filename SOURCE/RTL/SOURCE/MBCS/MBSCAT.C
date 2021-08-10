/*-----------------------------------------------------------------------*
 * filename - mbscat.c
 *
 * function(s)
 *        _mbscat - Appends one string to another.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <string.h>
#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _mbscat - Appends one string to another.

Usage           unsigned char *_mbscat(unsigned char *dest,
                                       const unsigned char *src);

Prototype in    mbstring.h

Description     _mbscat appends a copy of src to the end of dest.
                The length of the resulting string is strlen(dest)
                + strlen(src).

                If the second byte of 2-bytes character is null,the first
                byte character isn't regarded as null.It is equal with strcat().

Return value    Returns a pointer to dest.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbscat(unsigned char *s1, const unsigned char *s2)
{
    return (unsigned char *)strcat((char *)s1, (const char *)s2);
}
