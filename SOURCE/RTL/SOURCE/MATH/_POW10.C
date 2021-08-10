/*------------------------------------------------------------------------
 * filename - _pow10.c
 *
 * function(s)
 *        _pow10 - long double power internal library function, 10^p
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <math.h>
#include <errno.h>
#include <stddef.h>
#include <_math.h>

#define MAX_87_EXP      4932

typedef unsigned short int  extend [5];     /* 80-bit constants */

static  const  long double   e0to7 [8] =
{
    1, 1.e1,  1.e2,  1.e3,  1.e4,  1.e5,  1.e6,  1.e7,
};

/* Exponents > 4932 become infinities.  Exponents < -4932 become 0. */

/* These values have been calculated with extra precision to ensure  */
/* that the last bit is rounded correctly.                           */
static  const   long double  e8    = 1.e8;
static  const   long double  e16   = 1.e16;
static  const   extend  e32   = {0xB59E, 0x2B70, 0xADA8, 0x9DC5, 0x4069};
static  const   extend  e64   = {0xA6D5, 0xFFCF, 0x1F49, 0xC278, 0x40D3};
static  const   extend  e128  = {0x8CE0, 0x80E9, 0x47C9, 0x93BA, 0x41A8};
static  const   extend  e256  = {0xDE8E, 0x9DF9, 0xEBFB, 0xAA7E, 0x4351};
static  const   extend  e512  = {0x91C7, 0xA60E, 0xA0AE, 0xE319, 0x46A3};
static  const   extend  e1024 = {0x0C17, 0x8175, 0x7586, 0xC976, 0x4D48};
static  const   extend  e2048 = {0x5DE5, 0xC53D, 0x3B5D, 0x9E8B, 0x5A92};
static  const   extend  e4096 = {0x979B, 0x8A20, 0x5202, 0xC460, 0x7525};
static  const   extend  eINF  = {0x0000, 0x0000, 0x0000, 0x8000, 0x7fff};

/*--------------------------------------------------------------------------*

Name            _pow10 - long double power function, 10^p

Usage           long double near _pow10(int  p);

Prototype in    _math.h

Description     Calculate 10 raised to power.  A lookup table  is used for
                values  from  10  through  10^7,  then this is augmented by
                multiplying with  table entries for  10^8/16/32/64/128/256,
                512/1024/2048/4096 which allows any power up to the
                implementation limit of 4932.

                Negative powers are provided by a final division.

                This is an internal library function used by pow10, pow10l
                and __xcvt.

Return value    _pow10 returns 10^p.

*---------------------------------------------------------------------------*/

long double _RTLENTRY _pow10  (int  p)
{
    int         exp;
    long double result;

/*--------------------------------------------------------------------------
        Take care of all the easy special cases up front.
--------------------------------------------------------------------------*/
    if (p < -MAX_87_EXP)     /* Extremely small -> Zero      */
        return (0.0);
    if (p >  MAX_87_EXP)     /* Extremely large -> Infinity  */
        return (*(long double *)eINF);
    if (p == 0)              /* 10^0 -> 1.0                  */
        return (1.0);

/*--------------------------------------------------------------------------
                The non-trivial cases require some calculation.
--------------------------------------------------------------------------*/

    if ((exp = p) < 0)
        exp = -p;

    result = e0to7[exp & 7];
    exp >>= 3;

    if (exp & 1)
        result *= e8;
    exp >>= 1;

    if (exp != 0)                       /* optimization, skip if all done */
    {
        if (exp & 1)
            result *= e16;
        exp >>= 1;

        if (exp & 1)
            result *= *(long double *)e32;
        exp >>= 1;

        if (exp & 1)
            result *= *(long double *)e64;
        exp >>= 1;

        if (exp & 1)
            result *= *(long double *)e128;
        exp >>= 1;

        if (exp & 1)
            result *= *(long double *)e256;
        exp >>= 1;

        if (exp & 1)
            result *= *(long double *)e512;
        exp >>= 1;

        if (exp & 1)
            result *= *(long double *)e1024;
        exp >>= 1;

        if (exp & 1)
            result *= *(long double *)e2048;
        exp >>= 1;

        if (exp & 1)
            result *= *(long double *)e4096;
    }
    if (p < 0)
        /* 10^(-n) = 1 / 10^n, so we need the reciprocal. */
        return (1.0 / result);
    else
        return (result);
}
