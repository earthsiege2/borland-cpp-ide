/*-----------------------------------------------------------------------*
 * filename - mbsinc.c
 *
 * function(s)
 *        _mbsinc - Goes a string pointer forward to 1 byte next. 
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

Name            _mbsinc - Goes a string pointer forward to 1 byte next.

Usage           unsigned char *_mbsinc(const unsigned char *p);

Prototype in    mbstring.h

Description     _mbsinc goes a string pointer p forward to 1 byte next.

Return value    Returns a pointer forwarded 1 byte.
*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned char * _RTLENTRY _EXPFUNC _mbsinc(const unsigned char *p)
{
    if (!p)
        return NULL;
    if (_ismbblead(*p))
        p++;
    return (unsigned char *)(p + 1);
}
