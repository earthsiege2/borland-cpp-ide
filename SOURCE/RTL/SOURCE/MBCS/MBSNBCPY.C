/*-----------------------------------------------------------------------*
 * filename - mbsnbcpy.c
 *
 * function(s)
 *        _mbsnbcpy - Copies a given number of bytes from one string
 *                    into another.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <mbctype.h>
#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _mbsnbcpy - Copies a given number of bytes from one string
                            into another.

Usage           unsigned char *_mbsnbcpy(unsigned char *dest,
                                         const unsigned char *src, size_t n);

Prototype in    mbstring.h

Description     _mbsnbcpy copies up to n character from src to dest,
                or null-padding dest.

                _mbsnbcpy doesn't check whether it is a null pointer or
                not, so don't pass it.

                If the second byte of 2-bytes character is null,
                that character is regarded as null. 

Return value    Returns a pointer to dest.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsnbcpy(unsigned char *s1, const unsigned char *s2, size_t n)
{
    unsigned char *p;

    p = s1;
    while (n > 0 && *s2)
    {
        if (_ismbblead(*s2))
        {
            if (n < 2 || s2[1] == '\0')
                break;
            *p++ = *s2++;
            n--;
        }
        *p++ = *s2++;
        n--;
    }
    for ( ; n > 0; n--)
        *p++ = '\0';
    return s1;
}
