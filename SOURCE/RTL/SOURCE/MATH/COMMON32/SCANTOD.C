/*------------------------------------------------------------------------
 * filename - scantod.c
 *
 * function(s)
 *      __scantod  - converts a string to floating-point number
 *      __scanrslt - store conversion result
 *      _scan_init - initialize pointers to conversion routines
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_scanf.h>
#include <ctype.h>
#include <_math.h>
#include <math.h>
#include <stdlib.h>
#include <_locale.h>

/* Pointers to conversion functions.
 */
extern void (*_scantodptr)();
extern void (*_scanrsltptr)();

/*
  Internal RTL function to perform double/float truncations.
  REMOVE!!!!
*/
#define FLT     0
#define DBL     1


#define MAX_IEEE_DIGS 19        /* was 18 */

/*--------------------------------------------------------------------------*

Name            scantod - converts a string to floating-point number

Usage           void __scantod ( long double *valueP,
                                 int (* Get) (void *srceP),
                                 void  (* UnGet) (int ch, void *srceP),
                                 const void  *srceP,
                                 int     width,
                                 int    *countP,
                                 int    *statusP )

Prototype in    _scanf.h

Description     Convert a string to a long double precision real. The syntax
                of the string must be:

                float    ::= [isspace]* [sign] [realnum] [exponent]

                isspace  ::= as per <ctype.h>:isspace

                realnum  ::= {digit [digit]* ['.' [digit]* ]} |
                             {'.' digit [digit]*}

                exponent ::= 'e'|'E' [sign] digit [digit]*

                "srceP"  is a  pointer to  some kind  of object  from which
                         characters are  scanned. For example, it  may be a
                         FILE  *. The  functions Get()  and UnGet() operate
                         upon srceP to get  characters and possibly replace
                         one character, allowing LR(1) scanning rules.

                The digits must be decimal.

                The width is the limit on the number of digits which may be
                accepted. It includes the sign  character, if any, but does
                not include any leading spaces.

                The long double value resulting from the conversion is
                returned to *valueP.

                The count  value returned to the  caller is a count  of all
                the characters  consumed, including leading spaces  even if
                no numerals are found. It is ADDED to the existing value of
                count.

                The status  returned is EOF  if EOF was  encountered before
                conversion could begin, 0 if  no numerals were found before
                some   other   character  occurred,  1  if  the  conversion
                proceeded   correctly,  and  2  if  overflow  or  underflow
                occurred.

                If the source string is  not a valid floating point numeral
                then the result value is zero and the next char left in the
                source will be  the first char encountered which  could not
                be part  of the number. If  the number is too  large or too
                tiny then the result is signed HUGE_VAL or zero.

Method          The conversion proceeds in two stages. Firstly, the decimal
                strings for fraction and exponent must be captured.

                The  fraction is  held as   a 63-bit  unsigned integer  (18
                decimals of  precision), with separate sign.  Digits beyond
                the 18th are truncated.

                The exponent is  held as a short integer  in binary format,
                and is adjusted  to note the position of  the decimal point
                in the fraction so that  the "fraction" is normalized as an
                integer with decimal point to the right.

                When  both fraction  and exponent  have been  captured, the
                second  stage is  to combine  them. This  is done  with the
                formula:

                        result = 10^(exponent) * fraction * sign.

                If the  result overflows + or  - HUGE will be  returned. If
                the result is an underflow, zero is returned.

                The iNDP-87 is not used as  much as might be optimum if the
                user has a coprocessor installed.  A balance is sought,  so
                that the routine makes  strategic use of co-intructions but
                not  frequent use  which would  be quite  slow if  software
                emulation is used in place of a chip.

                The following diagram may be helpful with understanding the
                relations between the variables:

                   000012345789012345.098765432109876E+99
                      |---decimals-->|
                      |--------------.----digits---->|   not counting the '.'

                Decimals are  counted negative if   the '.' is  left of the
                first digit.  Digits are positive unless  no non-zero digit
                is ever seen.

Return value    None; _scantod stores the converted value of the input
                string at *valueP.

*---------------------------------------------------------------------------*/

        /* +/- infinity, +/- NAN */

typedef unsigned short int  extend [5];     /* 80-bit constants */

static const extend INF  = {0x0000, 0x0000, 0x0000, 0x8000, 0x7fff};
static const extend INFM = {0x0000, 0x0000, 0x0000, 0x8000, 0xffff};
static const extend NAN  = {0x0001, 0x0000, 0x0000, 0xC000, 0x7fff};
static const extend NANM = {0x0001, 0x0000, 0x0000, 0xC000, 0xffff};

static void __scantod (
                        long double *valueP,
                        int  (* Get) (void *srceP),
                        void (* UnGet) (int ch, void *srceP),
                        void  *srceP,
                        int     width,
                        int    *countP,
                        int    *statusP )
{
	int     decimals = 0x8000;
	int     digits = -2;
	int     maxdigits = MAX_IEEE_DIGS;  /* try 19 at first */
	int     exponent;
	char    sign    = 0;
	char    FirstDigit = 1;
	char    saw_sign= 0;
	char    expSign = 0;
	char    ExpOflow= 0;
	int     ct      = 0;
	int     status  = 1;
	int     ch;

	long double frac = 0.0;
	long double exp;
	unsigned short  *fracw = (unsigned short *)&frac;
	unsigned long   *fracl = (unsigned long  *)&frac;
	long            tempq[2];
	char            decimal_point_char = *_localeconvention.decimal_point;

    /* Skip leading spaces on the input numeral.
     */
    for (;;)
    {
        ct++;
        if ((ch = Get (srceP)) == EOF)
        {
            status = -1;
            goto std_noResult;
        }
        if ((ch & 0x80) != 0 || !isspace(ch))
            break;
    }

    if (--width < 0)
        goto std_fractionLimited;

    /* Is the numeral preceded by a sign ?
     */
    if (ch == '+')
        saw_sign = 1;
    else if (ch == '-')
        sign = saw_sign = 1;
    else
        goto std_gotChar;

    for (;;)            /* Pick up the next character of the fraction.  */
    {
        if (--width < 0)
            goto std_fractionLimited;
        ct ++;
        ch = Get (srceP);

        /* Check for the special cases where +INF -INF +NAN -NAN 
         * might be specified.
         */
std_gotChar:
        if (FirstDigit == 1 && saw_sign != 0)
        {
            if (ch == 'I')              /* Maybe we have +/-INF         */
                goto PossibleINF;
            else if (ch == 'N')         /* Maybe we have +/-NAN         */
                goto PossibleNAN;
        }

        FirstDigit = 0;

        /* Watch for decimal points.
         */
        if (ch == decimal_point_char )
        {
            if (decimals != 0x8000)     /* Seen a previous decimal point? */
                break;                  /* If so, fraction is terminated */
            decimals = digits > 0 ? digits : 0;
            continue;
        }

        if (ch < '0' || ch > '9')
            break;              /* Non-numeric terminates fraction */
        ch -= '0';              /* convert digit to equivalent number.  */

        if (++digits <= 0)      /* Was it the first digit? */
        {
            /* The first digit begins the fraction.  Leading
             * zeros are noted by setting digits -1, so that the
             * fraction syntax is valid if no other digits are
             * seen, but following digits will still be treated
             * as "firsts".  Leading non-zero digits cause digits
             * to be set to 1.
             */
            fracw[0] = ch;
            if (ch != 0)                /* not a leading zero? */
                digits = 1;
            else
            {
                digits = -1;            /* it is a leading zero */
                if (decimals != 0x8000) /* has decimal point been seen ? */
                    decimals--;         /* if yes, move it to the left. */  
            }
            continue;
        }

        /* If a digit is seen, then multiply the existing fraction by 10 and
         * add in the new digit.  The special case of the first 9 digits is
         * treated separately for speed, because the value can't exceed
         * 32 bits.
         */
        if (digits <= 9)
        {
            *fracl = *fracl * 10L + (long)ch;
        }
        else if (digits <= maxdigits)
        {
            /* Digits beyond the 9th are more rare in practice
             * (even in 10-digit numbers, 9 will be quick), so no
             * further special cases are justified.  Beyond MAX_IEEE_DIGS
             * digits, or beyond 2^64, ignore the digit values
             * but keep scanning.
             */
            tempq[0] = fracl[0];            /* make temporary copy of frac */
            tempq[1] = fracl[1];
            if (_qmul10(tempq, ch) != 0)    /* overflow? */
                maxdigits = digits -1;      /* say we never saw this digit */
            else
            {
                fracl[0] = tempq[0];        /* no overflow, copy temporary */
                fracl[1] = tempq[1];        /*  result to frac */
            }
        }
        continue;

        /* Arrive here when fraction is width-limited but valid.
         */
std_fractionLimited:
        ch = 'e';                   /* Behave as if exponent started. */
        break;
    }

    /* The fraction was ended.  If it was valid, it must have had at least
     * one digit.  AL must hold the character which terminated the fraction.
     */
    if (digits == -2)
        goto std_noDigitSeen;

    /* If no decimal point was seen, then the decimal is assumed to be at
     *  the rightmost edge.
     */
    if (decimals == 0x8000)
        decimals = digits;

    /* Now we must gather the exponent.  First, check for 'E' or 'e' to
     * introduce it, then if found gather the short integer.
     */
    exponent = 0;
    if (ch == 'e' || ch == 'E')
    {
        int SignStage = 1;

        for (;;)
        {
            if (--width < 0)
                goto std_exponentLimited;
            ct ++;
            ch = Get (srceP);
            if (SignStage)
            {
                SignStage = 0;
                if (ch == '-')
                {
                    expSign = 1;
                    continue;
                }
                else if (ch == '+')
                    continue;
            }
            if (ch < '0' || ch > '9')
                break;
            if ((exponent = exponent * 10 + ch - '0') > 4932)
                ExpOflow = 1;
        }
    }

    /* Arrive here when a valid syntax has been terminated
     * ch must still contain the terminating character, unchanged
     */
    UnGet (ch, srceP);
    ct--;

    /* Arrive here with valid termination but no terminator to be pushed back.
     */
std_exponentLimited:
    if (expSign)                /* was the exponent signed ?    */
    {
        exponent = -exponent;

        /* Normal stays normal, Infinity becomes 0 if exponent was hugely
         * negative.
         */
        ExpOflow = -ExpOflow;
    }

    /* The special case when digits = -1 occurs when the fraction is zero.
     * In that case, the result is always zero, whatever the exponent.
     */
    if (digits < 0)
    {
        frac = 0.0;
        goto std_end;
    }

    /* Convert underflows to zero and overflows to ld HUGE_VAL.
     */
    if (ExpOflow)
    {
        if (ExpOflow == 1)              /* big (+) exp -> ld HUGE_VAL */
        {
            /* Make 'frac' a long double HUGE_VAL.
             */
            fracw[0] = fracw[1] = fracw[2] = fracw[3] = 0xffff;
            fracw[4] = 0x7ffe;
        }
        else
            frac = 0.0;
        status = 2;
        goto std_end;
    }

    /* Add the decimal point contribution to the exponent.
     */
    exponent += decimals - (digits > maxdigits ? maxdigits : digits);
    frac = _fuildq((long *)&frac);  /* Convert fraction to a long double */

    /* Multiply fraction * 10^exponent if exponent is non-zero
     */
    if (exponent != 0)
    {
        exp = _pow10(exponent > 0 ? exponent : -exponent);
        if (exponent < 0)       /* negative exponent --> 1 / 10^|exponent|  */
            frac = frac / exp;
        else
            frac = frac * exp;
    }

std_end:
    if (sign)
        frac = -frac;

std_exit:
    *countP += ct;
    *statusP = status;
    *valueP = frac;
    return;

/* Error clauses placed here out of the main loop.
 * Arrive here if an error occurred.
 */
std_noDigitSeen:
    status = 0;

std_noResult:
    if (width >= 0)
    {
        UnGet (ch, srceP);
        ct --;
    }
    frac = 0.0;
    goto std_end;

/*  end of error clauses.
 */

/*-------------------------------------------------------------------------
                Special case code to scan +INF -INF +NAN -NAN
  -------------------------------------------------------------------------
  One side effect here, if this ultimately isn't +INF -INF +NAN -NAN will be
  that the apps input stream is now messed up because we needed to look 
  ahead more than 1 character to recognize INF or NAN. The 'unget' functions
  are only guaranteed to be able to unget a maximum of one char. This means
  on a worst case input like "+INX" there will be 3 characters we won't be 
  able to push back on the stream successfully.  There's not much that can
  be done to prevent this.  The same kind of thing can happen when reading
  E format numbers, for example "1.234E+Q".  By the time the 'Q' is seen
  "E+" has gone by.
--------------------------------------------------------------------------*/
PossibleINF:
    ct ++;
    ch = Get (srceP);
    if (--width < 0 || ch != 'N')
        goto std_noDigitSeen;
    ct ++;
    ch = Get (srceP);
    if (--width < 0 || ch != 'F')
        goto std_noDigitSeen;
    if (sign)
        frac = *(long double *)INFM;
    else
        frac = *(long double *)INF;
    goto std_exit;

PossibleNAN:
    ct ++;
    ch = Get (srceP);
    if (--width < 0 || ch != 'A')
        goto std_noDigitSeen;
    ct ++;
    ch = Get (srceP);
    if (--width < 0 || ch != 'N')
        goto std_noDigitSeen;
    if (sign)
        frac = *(long double *)NANM;
    else
        frac = *(long double *)NAN;
    goto std_exit;
}

/*--------------------------------------------------------------------------*

Name            __scanrslt - Get conversion result

Usage           void __scanrslt(longdouble *valueP,
                                longdouble *rsltP,
                                int rsltType);

Description     This function is used to store the result of a floating
                point convertion in _scanner().  The value to be
                stored is *valueP.   The location to store the result is
                rsltP.  rsltType contains flags indicating whether the
                value is to be stored as a long double, a double, or a float.

                If the value exceeds the allowable range for the indicated
                floating point type, errno is set to ERANGE and the value
                is chop

*---------------------------------------------------------------------------*/

static  void __scanrslt(long double *valueP, void *rsltP, int rsltType)
{
        if (rsltType & isLong)
                *(double *)rsltP = __ldtrunc(DBL, *valueP, HUGE_VAL);
        else if (rsltType & isLongDouble)
                *(long double *)rsltP = *valueP;
        else
                *(float *)rsltP = __ldtrunc(FLT, *valueP, *(long double *)INF);
}

/*--------------------------------------------------------------------------*

Name            _scan_init - initialize pointers to _realcvt and _nextreal

Usage           void _scan_init (void);

Prototype in    none

Description     Initialize the pointers used by _vprinter and _vscanner
                to call the various routines needed to scan and print
                floating point numbers.  Normally these pointers
                point to dummy functions that print a message
                and abort the program.  But if floating point is
                used, the compiler generates an external reference
                that is satisfied by initcvt.asm, which in turns
                causes the following function to be called at
                startup.

Return value    none

*---------------------------------------------------------------------------*/

void _RTLENTRY _scan_init (void)
{
    _scantodptr = __scantod;
    _scanrsltptr = __scanrslt;
}
