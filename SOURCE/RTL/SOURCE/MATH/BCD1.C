/*-----------------------------------------------------------------------*
 * filename - bcd1.c
 * Library for long double / binary code decimal conversions
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4 $        */

#include <math.h>
#include <_math.h>

/* bcd range:
 * about 17 digits precision
 * exponent range, about 1e-125 to 1e+125
 *
 * bcd format:
 * expo            mantissa                value
 * 0               0                       0
 * 1               +1 or -1                +INF or -INF
 * 2               ?                       NAN
 * 3-255           x                       x * 10 ^ (expo - Bias)
 *
 * The Bias is 147, so exponent range is 3-147=-144 to 255-147=+108.
 * Caution: The decimal representation is not unique.
 * Eg, { 1L, 0L, 1+Bias } is the same as { 10L, 0L, 0+Bias }.
 */

struct decimal {
        long mantissa[2];
        short expo;
};

typedef struct decimal bcd;

enum bcdexpo {
        ExpoZero,
        ExpoInf,
        ExpoNan,
};

#define Bias    147

        /* +/- infinity, +/- NAN */

typedef unsigned short int  extend [5];     /* 80-bit constants */

static const extend INF  = {0x0000, 0x0000, 0x0000, 0x8000, 0x7fff};
static const extend NAN  = {0x0001, 0x0000, 0x0000, 0xC000, 0x7fff};

/*----------------------------------------------------------------------
 * __bcd_tobinary - Convert a decimal number to binary
 */
long double _RTLENTRY _EXPFUNC __bcd_tobinary (const bcd *p)
{
    long double x;

    x = _fildq((long *)p->mantissa);   /* convert mantissa to long double */

    if (p->expo <= 2)           /* handle special cases */
    {
        if (p->expo == 2)       /* if exponent is 2, number is NAN */
            return (*(long double *)NAN);
        else if (p->expo == 0)  /* if exponent is 0, assume mantissa is 0 */
            return (x);
        else                    /* mantissa was +1 or -1 */
            return (x * (*(long double *)INF));
    }
    else
        return (_pow10(p->expo-Bias) * x);
}

/*----------------------------------------------------------------------
 * __bcd_todecimal - round x to n decimal places
 *
 * fixed point!
 * eg,
 * x = 123.4567;
 * round(x, 0) = 123.
 * round(x, 1) = 123.5
 * round(x, 2) = 123.46
 * round(x, -1) = 120.
 * round(x, -2) = 100.
 *
 * uses banker's rounding
 *
 * Convert a binary number to decimals.
 * Use at most 'decimals' after the decimal point.
 * For maximum accuracy, use decimals=5000.
 */

#define Log10of2 0x4d10L        /* 0x10000 * Log10(2), rounded */

void _RTLENTRY _EXPFUNC __bcd_todecimal(long double x, int decimals, bcd *p)
{
    long            templ;
    unsigned short  *fracw;
    unsigned short  exponent;
    int             bcdexpo;
    long double     tempd;

    fracw = (unsigned short *)&x;       /* point to long double value */
    exponent = fracw[4] & 0x7fff;       /* save exponent word, remove sign */

    if (exponent == 0)                  /* zero */
    {
        tempd = 0.0;
        bcdexpo = ExpoZero;
    }
    else if (exponent == 0x7fff)        /* special */
    {
        if (fracw[3] == 0x8000 && fracw[2] == 0 && fracw[1] == 0
                               && fracw[0] == 0)                /* INF */
        {
overflow:
            tempd = fracw[4] & 0x8000 ? -1.0 : 1.0;
            bcdexpo = ExpoInf;
        }
        else                            /* NAN */
        {
underflow:
            tempd = 0.0;
            bcdexpo = ExpoNan;
        }
    }
    else
    {
        /* Bizarre calculation, original assembly code wasn't commented.
         * Apparently it estimates the decimal exponent; similarly
         * obscure code involving Log10of2 can be found in xcvt.c.
         */
        templ = (long)(-(exponent - (0x3fff + 60))) * Log10of2;
        bcdexpo = (int)(templ >> 16);
        if (decimals < bcdexpo)     /* use min(bcdexpo, decimals) */
            bcdexpo = decimals;

        /* -bcdexpo is unbiased exponent, not special,
         * so -144 <= -bcdexpo <= 108
         */
        if (bcdexpo > 144)          /* underflow */
            goto underflow;
        else if (bcdexpo < -108)    /* overflow */
            goto overflow;
        else                        /* normal case */
        {
            tempd = x * _pow10(bcdexpo);
            bcdexpo = -bcdexpo + Bias;
        }
    }
    _fistq(p->mantissa, &tempd);    /* convert tempd to integer mantissa */
    p->expo = bcdexpo;
}


/*----------------------------------------------------------------------
 * __bcdlog10 - compute log10 of BCD number
 */
long double _RTLENTRY _EXPFUNC __bcd_log10(const bcd *p)
{
    return (log10l(_fildq(&p->mantissa[0])) + (long double)(p->expo - Bias));
}

/*----------------------------------------------------------------------
 * __bcd_pow10 - convert 10^n, convert to BCD number
 */
void _RTLENTRY _EXPFUNC __bcd_pow10(int n, bcd *p)
{
    p->mantissa[0] = 1;
    p->mantissa[1] = 0;
    if ((p->expo = n + Bias) > 255)
        p->expo = ExpoInf;
    else if (p->expo < 3)
    {
        p->mantissa[0] = 0;
        p->expo = 0;
    }
}
