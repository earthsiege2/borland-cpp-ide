/*-----------------------------------------------------------------------*
 * filename - mbsdec.c
 *
 * function(s)
 *        _mbsdec - Returns a string pointer back to 1 byte backward.
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

Name            _mbsdec - Returns a string pointer back to 1 byte backward.

Usage           unsigned char *_mbsdec(const unsigned char *s,
                                       const unsigned char *p);

Prototype in    mbstring.h

Description     _mbsdec returns a pointer p indicating the character
                in string s back to 1 byte backward.

                If there is no more character before string p(it is the
                same position as s),returns null pointer.

Return value    Returns a pointer back to 1 byte, or null pointer if
                there is no character before.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsdec(const unsigned char *s, const unsigned char *p)
{
    unsigned char *q;

    if (!s || !p || p <= s)
        return NULL;
    q = (unsigned char *)(p - 1);
    if (_ismbblead(*q))
        return (q - 1);
    q--;
    while ((const unsigned char *)q >= s)
    {
        if (!(_ismbblead(*q))) break;
        q--;
    }
    return (unsigned char *)(p - ((int)((unsigned char *)p - q) & 1) - 1);
}
