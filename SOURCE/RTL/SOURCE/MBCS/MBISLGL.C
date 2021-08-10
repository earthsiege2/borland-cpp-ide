/*-----------------------------------------------------------------------*
 * filename - mbislgl.c
 *
 * function(s)
 *        _ismbclegal - Tests a 2-byte character whether it is a legal
 *                      2-byte code or not.
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

Name            _ismbclegal - Tests a character wheter it is a 2-bytes
                              character or not.
 
Usage           int _ismbclegal(unsigned int c);

Prototype in    mbstring.h

Description     _ismbclegal tests c is a legal 2-byte code or not.

Return value    Return the value excepting 0 if it is a legal 2-byte code,
                and return 0 if it is not.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbclegal(unsigned int c)
{
    return (_ismbblead(c >> 8) && _ismbbtrail((unsigned char)c));
}
