/*-----------------------------------------------------------------------*
 * filename - mbsnset.c
 *
 * function(s)
 *        _mbsnset - Fills characters into one string.
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

Name            _mbsnset - Fills character into one string.

Usage           unsigned char *_mbsnset(unsigned char *s, unsigned int c,
                                        size_t maxlen);

Prototype in    mbstring.h

Description     Fills the character c into the first maxlen character of
                the string s.

                If string(s) < the byte size of maxlen, _mbsnset fills
                c up to s.
                If string(s) > the byte size of maxlen, _mbsnset fills
                c into the first maxlen bytes of s.
                If c is 2-bytes character and the length of s is odd
                number of bytes, _mbsnset fills 0x20(1-byte space
                character) for the gap between them.
                And if c is filled till the first byte of 2-bytes character,
                _mbsnset fills 0x20.

Return value    Returns a pointer same as an argument s.

                The second byte of the 2-bytes character in string s
                is null, the first byte of this character is regarded
                as a 1-byte character.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsnset(unsigned char *s, unsigned int c, size_t n)
{
    unsigned char *p;
    unsigned char c1;
    char dirty;

    p = s;
    dirty = 0;
    c1 = (c >> 8);
    for ( ; n > 0 && *p; n--)
    {
        if (c1)
        {
            dirty = (dirty == 0 && _ismbblead(*p));
            if (p[1] == '\0')
            {
                *p = '\x20';
                return s;
            }
            *p++ = c1;
        }
        dirty = (dirty == 0 && _ismbblead(*p));
        *p++ = (unsigned char)c;
    }
    if (dirty && *p)
        *p = '\x20';
    return s;
}
