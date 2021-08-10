/*------------------------------------------------------------------------
 * filename - pow10d.c
 *
 * function(s)
 *        pow10 - power function, 10^p
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#include <math.h>
#include <_defs.h>
#include <_math.h>

/*--------------------------------------------------------------------------*

Name            pow10 - power function, 10^p

Usage           double  pow10(int  p);

Prototype in    math.h

Description     Calculate 10  raised to power.  A lookup table  is used for
                values  from  10  through  10^7,  then this is augmented by
                multiplying with  table entries for  10^8/16/32/64/128/256,
                512/1024/2048/4096 which allows any power up to the
                implementation limit of 4932.
                The usual range of double precision is  10e308 but pow10
                has a wider  range so that it can be used for long double
                calculations when the result is retrieved off the TOS
                explicitly by inline code doing a store of an 80 bit #.

                Negative powers are provided by a final division.

Return value    pow10 returns 10^p.

*---------------------------------------------------------------------------*/

double _RTLENTRY _EXPFUNC pow10 (int  p)
{
    return ((double)_pow10(p));
}
