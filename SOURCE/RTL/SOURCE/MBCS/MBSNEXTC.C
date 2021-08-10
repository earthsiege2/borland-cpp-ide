/*-----------------------------------------------------------------------*
 * filename - mbsnextc.c
 *
 * function(s)
 *        _mbsnextc - Gets one character from a string.
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

Name            _mbsnextc - Gets one character from a string.

Usage           unsigned int _mbsnextc(unsigned char *p);

Prototype in    mbstring.h

Description     _mbsnextc gets one character from the string pointer p.

Return value    Returns one character indicated by string pointer p.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

unsigned int _RTLENTRY _EXPFUNC _mbsnextc(const unsigned char *s)
{
    return (_ismbblead(*s)) ? (((unsigned int)*s << 8) | s[1]) : *s;
}
