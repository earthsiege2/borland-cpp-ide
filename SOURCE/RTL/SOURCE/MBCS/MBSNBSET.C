/*-----------------------------------------------------------------------*
 * filename - mbsnbset.c
 *
 * function(s)
 *        _mbsnbset - Fills characters into one string.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */


#include <mbctype.h>
#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _mbsnbset - Fills characters into one string.

Usage           unsigned char *_mbsnbset(unsigned char *s, unsigned int c,
                                         size_t maxlen);

Prototype in    mbstring.h

Description     Fills the character c into the first maxlen bytes of
                the string s.

                If string(s) < maxlen, _mbsnbset fills c up to s.
                If string(s) > maxlen, _mbsnbset fills c into the first
                maxlen bytes of s.
                If c is 2-bytes character and the length of s is odd
                number of bytes, _mbsnbset fills 0x20(1-byte space
                character) for the gap between them.

Return value    Returns a pointer same as an argument s.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsnbset(unsigned char *s, unsigned int c, size_t n)
{
    unsigned char *p = s;

    if (c & 0xFF00)
    {
        for ( ; n > 0 && *p; n--)
        {
            if (--n <= 0 || p[1] == '\0')
            {
                *p = '\x20';
                break;
            }
            p[0] = (unsigned char)(c >> 8);
            p[1] = (unsigned char)c;
            p += 2;
        }
    }
    else
    {
        for ( ; n > 0 && *p; n--)
            *p++ = (unsigned char)c;
    }
    return s;
}

