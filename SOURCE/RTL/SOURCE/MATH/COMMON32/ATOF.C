/*------------------------------------------------------------------------
 * filename - atof.c
 *
 * function(s)
 *        atof - converts a string to a floating point number
 *        _wtof - converts a wide-character string to a floating point number
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#include <stdio.h>
#include <stddef.h>
#include <_math.h>
#include <math.h>
#include <stdlib.h>
#include <tchar.h>

/*--------------------------------------------------------------------------*

Name            atof,wtof - converts a string to a floating point number

Usage           double atof(const char *strP);
                double _wtof(const wchar_t *strP);

Prototype in    stdlib.h & math.h

Description     atof converts a string pointed to by strP to a double; this
                functions recognizes:
                        - an optional string of tabs and spaces
                        - an optional sign
                        - the  a string of  digits and an  optional decimal
                          point
                        - the  an optional e  or E followed  by an optional
                          signed integer

                The first unrecognized character ends the conversion. There
                are no provisions for overflow.

Return value    atof returns  the converted value  of the input  string. If
                the  string cannot  be converted  to a  number of  the type
                double, the return value is 0.

*---------------------------------------------------------------------------*/

double _RTLENTRY _EXPFUNC _ttof(const _TCHAR *strP)
{
    return _tcstod(strP, NULL);
}
