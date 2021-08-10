/*-----------------------------------------------------------------------*
 * filename - mbsninc.c
 *
 * function(s)
 *        _mbsninc - Moves a string pointer.
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

Name            _mbsninc - Moves a string pointer.

Usage           unsigned char *_mbsninc(const unsigned char *s, size_t n);

Prototype in    mbstring.h

Description     _mbsninc moves the pointer s in a null-terminating string
                to the place skipped the number of characters n.
                If string s occurs null character before completing n,
                _mbsninc returns a pointer indicating the null character.

                If the second byte of 2-bytes character is null,
                _mbsninc returns the pointer indicating the first byte
                of the character.

Return value    Returns a pointer skipped the number of characters n.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsninc(const unsigned char *s, size_t n)
{
    if (!s)
        return NULL;
    return (unsigned char *)( s + _mbsnbcnt(s, n) );
}
