/*-----------------------------------------------------------------------*
 * filename - mbsset.c
 *
 * function(s)
 *        _mbsset - Fills characters into one string.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */


#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _mbsset - Fills characters into one string.

Usage           unsigned char *_mbsset(unsigned char *s, unsigned int c);

Prototype in    mbstring.h

Description     Fills the character c into the string s.
                If c is 2-bytes character and the size of s is odd
                number of bytes, _mbsset fills 0x20(1-byte space
                character) for the gap between them.

Return value    Returns a pointer same as an argument s.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsset(unsigned char *s, unsigned int c)
{
    unsigned char *p;
    unsigned char c1;

    p = s;
    c1 = (c >> 8);
    if (c1)
    {
        while (*p && p[1])
        {
            *p++ = c1;
            *p++ = (unsigned char)c;
        }
        if (*p && p[1] == '\0')
            *p = '\x20';
    }
    else
    {
        while (*p)
            *p++ = (unsigned char)c;
    }
    return s;
}
