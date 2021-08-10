/*-----------------------------------------------------------------------*
 * filename - mbsnccnt.c
 *
 * function(s)
 *        _mbsnccnt - Count a number of characters starting with the first
 *                    N bytes in a string.     
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

Name            _mbsnccnt - Counts a number of characters starting with 
                            the first bytes in a string. 

Usage           size_t _mbsnccnt(const unsigned char *s, size_t nbytes);

Prototype in    mbstring.h

Description     _mbsnccnt counts a number of characters starting with
                the heading of string s until given n-th byte or
                until the occurrance of null-character, and returns
                the number of characters.

                If the second byte of 2-bytes character is null character,
                the first byte of this character is not included in the
                retrun value.

Return value    Returns the number of characters in given range.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

size_t _RTLENTRY _EXPFUNC _mbsnccnt(const unsigned char *s, size_t n)
{
    int m;

    for (m = 0; n > 0 && *s; m++, s++)
    {
        n--;
        if (_ismbblead(*s))
        {
            s++;
            if (n <= 0 || *s == '\0')
                break;
            n--;
        }
    }
    return m;
}
