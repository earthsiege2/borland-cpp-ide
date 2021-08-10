/*-----------------------------------------------------------------------*
 * filename - mbishira.c
 *
 * function(s)
 *        _ismbchira - Tests a character whehter it is a 2-bytes
 *                     Hiragana or not.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _ismbchira - Tests a character whehter it is a 
                             2-bytes Hiragana or not.

Usage           int _ismbchira(unsigned int c);

Prototype in    mbstring.h

Description     _ismbchira judges whether c is a 2-bytes Hiragana char
		or not.

Return value    Returns the value excepting 0 if it is a 2-bytes Hiragana,
		and returns 0 if it is not.i0x829F … c … 0x82F1j 

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbchira(unsigned int c)
{
    return (c >= 0x829F && c <= 0x82F1);
}
