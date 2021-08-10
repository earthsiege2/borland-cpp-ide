/*-----------------------------------------------------------------------*
 * filename - mbclen.c
 *
 * function(s)
 *        _mbclen - Caluclates the byte size of character.
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

Name            _mbclen - Caluclates the byte size of characters.

Usage           size_t _mbclen(const unsigned char *str);

Prototype in    mbstring.h

Description     Returns the byte size of the first character of str

                The character of the first byte is not regarded as null
                character even if the second byte of 2-bytes character is
		null character. 

Return value    Returns the byte size of a character.

*------------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

size_t _RTLENTRY _EXPFUNC _mbclen(const unsigned char *s)
{
    return (_ismbblead(*s)) ? 2 : 1;
}
