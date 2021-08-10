/*-----------------------------------------------------------------------*
 * filename - mbbtype.c
 *
 * function(s)
 *        _mbbtype - examines a character type of 2 byte code.
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

Name            _mbbtype - examine a character type of 2 byte code.

Usage           #include <mbctype.h>
                #include <mbstring.h>
                int _mbbtype(unsigned char c, int mode);

Prototype in    mbstring.h

Description     _mbbyte desides the character type of code, c, according
                the last character type given to mode.

                If you want to examine suitable strings from first
                in order,define _MBC_SINGLE (0) or _MBC_ILLEGAL (-1)
                as the default value of mode.

Return value    Returns any character type as following;

                symbol       value meaning 
                --------------------------------------------------------
                 _MBC_SINGLE    0   1 byte code(excepting 2 byte code)
                 _MBC_LEAD      1   the first byte of 2 byte code
                 _MBC_TRAIL     2   the 2nd byte of 2 byte code
                 _MBC_ILLEGAL  -1   the type excepting the above

                 The retarn value can be used for next mode to examine
                 the character type.

*---------------------------------------------------------------------*/

#if defined(__FARFUNCS__)
#include <_farfunc.h>
#include <_mbfarfn.h>
#endif

int _RTLENTRY _EXPFUNC _mbbtype(unsigned char c, int mode)
{
    if (mode == _MBC_LEAD)
    {
        if (_ismbbtrail(c))
            return (_MBC_TRAIL);
    }
    else if (mode == _MBC_SINGLE || mode == _MBC_TRAIL ||
             mode == _MBC_ILLEGAL)
    {
        if (_ismbblead(c))
            return (_MBC_LEAD);
        if (isprint(c) || _ismbbkana(c))
            return (_MBC_SINGLE);
    }
    return (_MBC_ILLEGAL);
}
