/*-----------------------------------------------------------------------*
 * filename - mbsupr.c
 *
 * function(s)
 *        _mbsupr - Converts lowercase letters in a string to uppercase.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

#include <ctype.h>
#include <mbctype.h>
#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _mbsupr - Converts lowercase letters in a string to
                          uppercase.

Usage           unsigned char *_mbsupr(unsigned char *s);

Prototype in    mbstring.h

Description     Converts all lowercase letters in the string s to
                uppercase.

Return value    Returns the value of a pointer same as argument s.

                If the second byte of 2-byte character is null character,
                the first byte of this character is regarded as null.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsupr(unsigned char *s)
{
    unsigned char *p;

    for (p = s; *p; p++)
    {
        if (_ismbblead(*p) && p[1])
            p++;
        else
            *p = _ltoupper(*p);
    }
    return s;
}
