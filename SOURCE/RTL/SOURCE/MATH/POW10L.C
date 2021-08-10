/*------------------------------------------------------------------------
 * filename - pow10l.c
 *
 * function(s)
 *        pow10l - long double power function, 10^p
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <math.h>
#include <_defs.h>
#include <_math.h>

/*--------------------------------------------------------------------------*

Name            pow10l - long double power function, 10^p

Usage           long double  pow10l(int  p);

Prototype in    math.h

Description     Calculate 10  raised to power.  A lookup table  is used for
                values  from  10  through  10^7,  then this is augmented by
                multiplying with  table entries for  10^8/16/32/64/128/256,
                512/1024/2048/4096 which allows any power up to the
                implementation limit of 4932.

                Negative powers are provided by a final division.

Return value    pow10l returns 10^p.

*---------------------------------------------------------------------------*/

long double _RTLENTRY _EXPFUNC pow10l (int  p)
{
    return (_pow10(p));
}
