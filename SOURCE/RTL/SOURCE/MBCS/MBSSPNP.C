/*-----------------------------------------------------------------------*
 * filename - mbsspnp.c
 *
 * function(s)
 *        _mbsspnp - Returns a pointer for the initial segment not
 *                   containing any subset of a given set of character.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#include <mbctype.h>
#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _mbsspnp - Returns a pointer for the initial segment not
                           containing any subset of a given set of
                           character.

Usage           unsigned char *_mbsspnp(const unsigned char *str1,
                                        const unsigned char *str2);

Prototype in    mbstring.h

Description     _mbsspnp scans str1 until any one of the characters
                contained in str2 is found.

                The second byte of 2-bytes character is null character,
                this character is regarded as null character.

Return value    _mbsspnp returns a pointer in str1 for the initial
                segment not containing any subset in str.
                If str1 is composed only using any character in str2,
                _mbsspnp returns null.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsspnp(const unsigned char *s1, const unsigned char *s2)
{
    const unsigned char *p, *q;

    for (p = s1; *p; p++)
    {
        for (q = s2; *q; q++)
        {
            if (_ismbblead(*q))
            {
                if (*p == *q && p[1] == q[1])
                    break;
                q++;
                if (*q == '\0')
                    break;
            }
            else
            {
                if (*p == *q)
                    break;
            }
        }
        if (*q == '\0')
            break;
        if (_ismbblead(*p))
        {
            p++;
            if (*p == '\0')
                break;
        }
    }
    return (unsigned char*)( *p ? p : NULL );
}
