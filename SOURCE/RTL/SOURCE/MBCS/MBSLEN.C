/*-----------------------------------------------------------------------*
 * filename - mbslen.c
 *
 * function(s)
 *        _mbslen - Caluclates the length of a string.
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

/*-----------------------------------------------------------------------*

Name            _mbslen - Caluclates the length of a string.

Usage           size_t _mbslen(const unsigned char *str);

Prototype in    mbstring.h

Description     Returns the number of characters in stirng with
                null-terminating character.

                If the second byte of 2-bytes character is null,
		the first byte of this character is regarded as null. 

                This function is a Japanese version of strlen.
                strlen returns the byte size of the character
                even if the string includes 2-bytes character.
                _mbslen caluclate 2-byte character
                as one character(1byte). 

Return value    Returns the number of characters.

*------------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

size_t _RTLENTRY _EXPFUNC _mbslen(const unsigned char *s)
{
    size_t n;

    for (n = 0; *s; s++, n++)
    {
        if (_ismbblead(*s))
        {
            s++;
            if (*s == '\0')
                break;
        }
    }
    return n;
}
