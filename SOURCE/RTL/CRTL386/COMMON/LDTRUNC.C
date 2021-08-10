/*------------------------------------------------------------------------
 * filename - ldtrunc.c
 *
 * function(s)
 *        __ldtrunc - internal function
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <errno.h>
#include <float.h>
#include <_scanf.h>

/*----------------------------------------------------------*
double __ldtrunc(int flag, long double x, double xhuge);

__ldtrunc() is an internal library function which truncates a
long double to a float (flag=0) or a double (flag=1), within the
constraints of what can be done in a library function.  The
argument is checked for underflow, which is flushed to 0, and
overflowed, which is changed to xhuge.  In either case, the sign
of x is attached to the result.  Otherwise, x is returned
unchanged.  The global errno is set to ERANGE, if an overflow or
underflow would have occurred.  No overflow or underflow
exceptions are generated.

If flag = 0, it is suggested that xhuge = 1./0.
If flag = 1, it is suggested that yhuge = HUGE_VAL.

*-----------------------------------------------------------*/

/*

Method:

The exponent (biased) in long double format is used to determine
whether an overflow or underflow will occur.  This is quick and
reliable, except for a few subtleties involving roundoff at the
extreme exponents.

cutoff values:

largest normal double has biased exponent 43FEh in 10-byte format.
smallest normal double has biased exponent 3C01h in 10-byte format.
smallest denormal double has biased exponent 3BCDh in 10-byte format.

largest normal float has biased exponent 407Eh in 10-byte format.
smallest normal float has biased exponent 3F81h in 10-byte format.
smallest denormal float has biased exponent 3F6Ah in 10-byte format.

*/


double __ldtrunc(int flag, long double x, double xhuge)
{
    volatile unsigned cword;
    unsigned short sign, exponent, maxexp, minexp;
    unsigned short *xp;
    double doubleval;
    float  floatval;

    sign = 0;

    if (flag == 0)          /* is it a float? */
    {
        maxexp = 0x407e;
        minexp = 0x3f6a;
    }
    else                    /* it's a double */
    {
        maxexp = 0x43fe;
        minexp = 0x3bcd;
    }

    /* Peek into the value with a word pointer and extract the
     * sign bit and the exponent.
     */
    xp = (unsigned short *)&x;
    sign = xp[4] & 0x8000;
    exponent = xp[4] & 0x7fff;

    /* let INF, NAN pass
     */
    if (exponent == 0x7fff)
        return ((double)x);

    /* test for overflow
     */
    if (exponent > maxexp)
    {
        doubleval = xhuge;
        goto error;
    }

    /* chop in borderline infinite case, to avoid overflow
     */
    if (exponent == maxexp)
    {
        cword = _control87(0,0);    /* save control word */
        _control87(RC_CHOP,MCW_RC); /* set rounding to chop */
        if (flag == 0)
        {
            floatval = (float)x;    /* chop value to float */
            doubleval = (double)floatval;
        }
        else
            doubleval = (double)x;  /* chop value to double */
        _control87(RC_CHOP,cword);  /* restore control word */
        return doubleval;
    }


    /* test for +0 or -0
     */
    if ((exponent | xp[0] | xp[1] | xp[2] | xp[3]) == 0)
        return ((double)x);

    /* test for underflow
     */
    if (exponent < minexp)
    {
        doubleval = 0;
error:
        errno = ERANGE;
        return (sign ? -doubleval : doubleval);
    }

    /* Normal return, number is in range.
     */
    return ((double)x);
}
