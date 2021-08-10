/*------------------------------------------------------------------------
 * filename - xcvt.c
 *
 * function(s)
 *        __xcvt - converts a double value to an ASCIIZ string
 *        __xcvtw - converts a double value to a wide-character string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <float.h>      /* for _status87 */
#include <string.h>     /* for memset */
#include <math.h>
#include <_printf.h>
#include <_math.h>
#include <_tchar.h>

/*--------------------------------------------------------------------------*

Name            __xcvt, __xcvtw - convert double/long double value to an
				  ASCIIZ/wide-character string

Usage           int __xcvt(void *valP,
                           short ndigits,
                           int *signP,
                           char *strP,
                           int ftype)
                int __xcvtw(void *valP,
                           short ndigits,
                           int *signP,
                           wchar_t *strP,
                           int ftype)

Prototype in    _printf.h

Description     The double/long double (*valP) is converted to a decimal
                string (*strP) of up to 18 digits, a  sign (*signP,
                false == positive) and a decimal exponent (the function
                return value).

                "ndigits" specifies  how the number  should be rounded.  If
                positive,  then  ndigits  specifies  the  maximum number of
                digits. Otherwise, ndigits specifies  the maximum number of
                fractional decimals (to the right of the decimal point). If
                |ndigits| is > 18 then ndigits will be limited to +-18.

                The string  is in ASCIIZ   form. The string  is padded with
                zeros  to the  right to  fill in  the requested  number of
                digits or decimal places.

                The exponent is calculated as  if the decimal point were at
                the left (most significant) end  of the string (there is no
                "." character  in the string).  If the value  was zero then
                the exponent is set to zero.

                If the value was zero then the exponent is 0 and the string
                is  all "0".  If the  value was  infinite or  NAN then  the
                exponent is MAXSHORT and the string is all "9".

                The ftype parameter will be :

                    2 - FLOAT
                    6 - DOUBLE
                    8 - LONG DOUBLE

                The numbers correspond to the offset of the exponent word
                from the start of the number.

Return value    __xcvt returns the decimal exponent of the number.

Note: A #define in '_printf.h' can be used to enable recognition of floats
      as well as doubles and long doubles.  This feature may be disabled
      though because it isn't strictly ANSI standard.  The code in this module
      is set up to recognize floats but the higher modules will never pass
      the float flag unless the variable is defined in _float.h
*---------------------------------------------------------------------------*/

#define MaxSigDigits    19

int __xcvtt(void *valP, int digits, int *signP, _TCHAR *strP, int ftype)
{
    short   ten = 10;
    short   SW;             /* iNDP status word */
    long double     frac;
    unsigned short  *fracw;
    unsigned char   *fracb;
    unsigned short  exponent;
    short           tempw;
    long            templ;
    int             prec, decimals, power, abspower, roundup, ndigs;
    long            double power10;
    _TCHAR            *p, *endp;

    /* Convert parm to 'long double' and store locally.  We ZAP the sign
     * bit out of the number in the local copy, but after saving
     * the exponent word.  This saves having to do a FABS later on
     * which saves lots of time if this code is running emulated
     * and really doesn't cost any more than a real FABS running on a 8087
     * in terms of speed.
     */
    switch (ftype)
    {
    case F_4byteFloat:      /* 4 byte float */
        frac = *(float *)valP;
        break;
    case F_8byteFloat:      /* 8 byte double */
        frac = *(double *)valP;
        break;
    case F_10byteFloat:     /* 10 byte long double */
        frac = *(long double *)valP;
        break;
    }

    /* Return the sign to the caller, then zap off the sign bit locally.
     */
    fracw = (unsigned short *)&frac;    /* point to long double value */
    fracb = (unsigned char *)&frac;     /* point to long double value */
    exponent = fracw[4];                /* save exponent word */
    fracw[4] = exponent & 0x7fff;       /* zap the sign bit */
    *signP = (exponent & 0x8000) != 0;  /* return sign to caller */

    /*
        Weed out all the 'strange' numbers here(0, Infinity & NANs).

        The format of C0, C1, C2 & C4 in the status word is:

        15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
        --+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--
           C3          C2 C1 C0
        ----- upper byte ------+----- lower byte ------
                   AH                      AL

        C3 C2 C1 C0
        -----------
         0  0  0  0     +Unnormal
         0  0  0  1     +NAN
         0  0  1  0     -Unnormal       (*)
         0  0  1  1     -NAN            (*)
         0  1  0  0     +Normal
         0  1  0  1     +Infinity
         0  1  1  0     -Normal         (*)
         0  1  1  1     -Infinity       (*)
         1  0  0  0     +Zero
         1  0  0  1     Empty
         1  0  1  0     -Zero           (*)
         1  0  1  1     Empty
         1  1  0  0     +Denormal
         1  1  0  1     Empty
         1  1  1  0     -Denormal       (*)
         1  1  1  1     Empty

         (*) We'll never see these in operation because we've zapped the
             sign bit before loading the number (it was saved though
             before being clobbered).

        Note : 286/287 specific porters.

                The 80287/80387 know how to do a FSTSW directly into the
                AX register.
    */

    SW = _fxam(&frac) & 0x4700;         /* do FXAM on the number */

    /* Zero is the most likely 'strange' number, so it's checked first.
     * Remember, signs were zapped above so we only need to look for the
     * positive cases!
     */
    if (SW == 0x4000)                   /* +0   */
    {
        /* True zero and 'rounds to zero' results wind up here.
         */
roundToZero:
        if ((ndigs = digits) <= 0)
            ndigs = -ndigs + 1;         /* digit left of decimal point */
        if (ndigs > __XCVTDIG__)        /* limit caller's buffer */
            ndigs = __XCVTDIG__;
        _tmemset(strP,_TEXT('0'),ndigs);/* fill in with '0' */
        strP[ndigs] = _TEXT('\0');      /* null terminate string */

/*
   The following line is removed so that negative zero CAN exist.  The ISO
   C spec. doesn't seem to care officially, but MSC and a number of Unix
   compilers do allow this.  I'm not so sure I like having both
   positive and negative zero values availible, but I'll allow it until I
   can think of a good reason not to.
*/
#if 0
        *signP = 0;                     /* eliminate negative zero */
#endif

        return (1);                     /* We really want 0.0E+01       */
    }
    else if (SW == 0x0500)              /* +INF */
        return (INF_number);
    else if (SW == 0x0100)              /* +NAN */
        return (NAN_number);

/************************************************************************
*               Normal numbers are not zero, infinite or NANs.          *
*                                                                       *
* Note: upon arrival here --                                            *
*               87' TOS contains the number to convert                  *
************************************************************************/

/*
        How many decimal places are there in the number?  It is not good
        to use the log10 function for two reasons:

        - it is slow and clumsy (even when not emulated)

        - the answer can be wrong: it is somewhat rare but rounding errors
          in the log function can cause the wrong number of digits.

        An alternative method is to make a swift estimate of the log, then
        check it later.  So long as the error is at most one digit up or
        down, and happens in a minority of cases, performance will be
        reasonable.  We can form the estimate by multiplying the binary
        exponent by a conversion factor Log10of2.  Since 16 bit accuracy
        is OK at this stage, it is possible to use fixed point arithmetic
        on the main CPU.
*/
    templ = (exponent & 0x7fff) - 0x3fff;   /* remove bias and sign */
    templ *= (long)0x4d10;          /* 10000h * Log10of2, rounded.  */

    tempw = ((fracb[7] << 1) & 0xff) * 0x4d; /* Get high 4 bits of fraction */
    templ += (long)tempw & 0xffffL;
    decimals = (int)(templ >> 16);  /* estimated exponent, or decimals */
    if ((templ & 0xffff) != 0)      /*  to the left of decimal point */
        decimals++;

    /* Now we are ready to do the rounding.  decimals estimates the decimal
     * digits left of the decimal point.  prec contains the requested
     * precision.
     */
    if ((prec = digits) <= 0)       /* -,0,+ = decimals, dflt, digits */
    {
        /* The caller has requested (-digits) decimals following the
         * decimal point.
         */
        if ((prec = decimals - digits) < 0)
            goto roundToZero;       /* Ignore if it rounds to zero  */
    }

/*
        The caller has requested (prec) significant digits (approximately).
        This is now limited to 18, the maximum precision convertible by
        the iNDP-87 (equivalent to around 59 bits of precision: double
        precision in C is 53 bits, roughly 16 decimals).  Zeros will be
        appended later to make up the extra digits requested.
*/
    if (prec > MaxSigDigits)
        prec = MaxSigDigits;

/*
        Now the number is scaled to place the requested number of digits
        left of the decimal point, and that number is rounded and converted
        to a BCD integer.  Upon arrival here:

        decimals is the estimated decimal magnitude of the number (i.e.
                 the number of digits to the left of the decimal point)
        prec     is the total number of digits required
*/
    power = prec - decimals;
    while (power != 0)
    {
        if ((abspower = power) < 0)
            abspower = -power;
        if (abspower > 4932)
            abspower = 4932;
        power10 = _pow10(abspower);

        /* Now the value 10^(|power|) is in power10.  That is multiplied
         * or divided with the value in frac to yield a number with an
         * integral part probably having just the number of wanted digits.
         */
        if (power < 0)
        {
            frac /= power10;
            power += abspower;
        }
        else
        {
            frac *= power10;
            power -= abspower;
        }
    }

    /* Before unpacking frac, we must check that the number of actual
     * decimals is correct, since up till now everything has depended on
     * an estimate.
     */
    power10 = _pow10(prec);
    if (frac > power10)
    {
        /* If arrived here then the number is too high.  The error is never
         * as great as tenfold, so divide by 10 to correct it.
         */
        decimals++;                     /* correct the estimate of decimals */
        prec++;                         /*  and size of result string */
        if (prec <= MaxSigDigits && digits > 0) /* is format F or E? */
        {
            frac /= ten;                /* E formats: maintain requested */
            prec--;                     /*  count of digits */
        }
    }
    else
    {
        /* If arrived here the number was not too high, but may be too low.
         */
        power10 = _pow10(prec-1);
        if (frac < power10)
        {
            /* Adjust upward tenfold to correct the alignment.
             */
            decimals--;                 /* correct the estimate of decimals */
            prec--;                     /*      and size of result string */
            if (digits > 0)             /* is format F or E ? */
            {
                frac *= ten;            /* E formats: maintain requested */
                prec++;                 /*      count of digits */
            }
        }
    }
    if (prec < 0)
        goto roundToZero;       /* Ignore if it rounds to zero  */

    /* Now convert the number in TOS into an unsigned 64-bit integer.
     * The default rounding mode applies.
     */
    _fuistq((long *)&frac,&frac);/* Convert to unsigned 64-bit integer */
    p = endp = &strP[prec];     /* Locate the end of string .. */
    *p-- = _TEXT('\0');         /* .. and put the zero terminator there. */

    /* The roundup flag is necessary because the rounding to integer can change
     * a 999.. value to 1000..  by rounding up.  In that case the number
     * of digits changes, and we will not scan as far as the '1' digit.
     * The roundup flag accumulates the OR of all digits: if it remains zero,
     * then we know we have a round-up problem.
     */
    roundup = 0;

    /* Fractions which may round up to 1 are checked here as a special case.
     */
    if (prec == 0)
    {
        if ((roundup = (*fracb & 0xff) ^ 1) != 0)   /* if 1, enable roundup */
            goto roundToZero;                       /* if 0, print as 0 */
    }
    else
    {
        /* Note that string direction is reversed, least significant
         * digits are converted first.
         */
        for (;;)
        {
            char ch;

            ch = _qdiv10((long *)&frac);    /* get frac % 10; frac /= 10 */
            roundup |= ch;
            *p-- = ch + _TEXT('0');
            if (--prec == 0)
                break;
        }
    }

    if (roundup == 0)                   /* is the string all zeros? */
    {
        /* If all zeros, then we can assume the leading digit will be '1'
         * due to a round-up.  Increment decimals to correct the
         * estimated digits.
         */
        decimals++;
        if (digits <= 0)
            *endp = _TEXT('0');
        endp++;
        *(p+1) = _TEXT('1');
    }

    /* The caller may want more than 18 digits.  We oblige, with limits,
     * by appending zeros up to the intended length.
     */
    if ((ndigs = digits) <= 0)
    {
        /* Request was for fixed decimals so add digits to get intended size.
         */
        ndigs = decimals - digits;
    }
    if (ndigs > __XCVTDIG__)
        ndigs = __XCVTDIG__;

    *endp = _TEXT('\0');                /* make sure null terminated */
    ndigs -= (endp - strP);             /* calculate actual digits */
    if (ndigs > 0)
    {
        _tmemset(endp,_TEXT('0'),ndigs);  /* extend the string */
        *(endp+ndigs) = _TEXT('\0');    /* null-terminate it */
    }
    return (decimals);
}
