/*------------------------------------------------------------------------
 * filename - realcvt.c
 *
 * function(s)
 *      TrimTrailing    - suppresses trailing zeroes if needed
 *      _realcvt       - converts a double value to an ASCIIZ string
 *      _nextreal      - advance floating point argument pointer
 *      _cvt_init       - initialize pointers to conversion routines
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */


#include <_printf.h>
#include <string.h>
#include <stdarg.h>
#include <_locale.h>

/* Pointers to conversion functions.
 */
extern void (*_realcvtptr)();
extern va_list (*_nextrealptr)();

/*--------------------------------------------------------------------------*

Name            TrimTrailing - suppresses trailing zeroes if needed

Usage           char * TrimTrailing (char formCh, char *start, char *end);

Prototype in    local function

Description     Following  rules derived  from combining  the altFormat and
                formCh  parameters, backspace  to remove  unwanted trailing
                characters.

                        (altFormat || ~(G or g)) == trailing zeroes are wanted
                        altFormat == trailing decimal point is wanted

                Upon entry, start contains the starting address of
                the string, and end points to the end of the string.

Return value    The address of the last byte of the possibly trimmed string.

*---------------------------------------------------------------------------*/

static char * TrimTrailing (char formCh, char *start, char *end)
{
    if (formCh == 'G' || formCh == 'g') /* only G/g removes trailing zeroes */
    {
        while (*(end-1) == '0')
            if (--end <= start)
                return (start);
    }
    /* trim the decimal point */
    if (*(end-1) == *_localeconvention.decimal_point )
		--end;
    return (end);
}

/*--------------------------------------------------------------------------*

Name            _realcvt - converts a double value to an ASCIIZ string

Usage           void _realcvt (double *valueP, int ndec,
                                        char *strP, char formCh,
                                        char altFormat);

Prototype in    _printf.h

Description     The double (value) is converted  to a decimal ASCIIZ string
                (*bufP) either the F format:

                [sign] [zeroes] [digit]* ['.'] [digit]

                or the E format:

                [sign] digit ['.'] [digit]* 'E' sign [digit] digit digit

                Where the  leading sign is  inserted only if  negative, and
                the decimal point is suppressed if ndec == 0, and the total
                count of digits <= MIN (1, ndec).

                The F format is used if formCh == 'f', or if 'g' or 'G' and
                there  would  be  three  or  fewer  leading  zeroes  and no
                trailing zeroes, otherwise the E format is used.

                If formCh ==  'E' or 'G' then the character  'E' is used to
                separate fraction from exponent, otherwise 'e' is used.

                Trailing decimal points are usually suppressed, as also are
                trailing fraction zeroes in the G/g format. If altFormat is
                true  (not zero)  then  trailing  decimals remain,  and G/g
                format will not trim zeroes.

                If ndec > 18 the effect is as if ndec == 18.

                If the  value was infinite  then the string  is "9E+999" or
                "-9E+999".

                The  basic  conversion  to  a  numeral  string  is  done by
                __xcvt(), with  this function responsible  for "customizing"
                the simple format which __xcvt() returns.

Return value    There is no return value

*---------------------------------------------------------------------------*/

static void _realcvt (void *valueP, int ndec,
                        char *strP, char formCh, char altFormat, int type)
{
    char    buf [__XCVTDIG__ + 4];
    int     sign, realcnt, cnt, exponent;
    char    form, ch;
    char    *src, *dst;
    char   decimal_point_char = *_localeconvention.decimal_point;
#   define DECIMAL_POINT decimal_point_char

    if (ndec > __XCVTDIG__)         /* IEEE double is meaningless */
        ndec = __XCVTDIG__;         /*      beyond "__XCVTDIG__" digits. */
    realcnt = ndec;                 /* save *real* requested count */

    if ((form = formCh & 0xdf) == 'F')  /* uppercase formCh */  
    {
        /* F-format works with digits right of the decimal point, specified
         * to __xcvt() as a negative number.
         */
        if ((cnt = -realcnt) > 0)   /* note "ndec" itself still +ve */
            ndec = cnt = 0;         /* no decimals if -ve requested. */
    }
    else
    {
        /* E-format counts overall digits, as does g-format sometimes.
         * There must be at least one.
         */
        if ((cnt = realcnt) <= 0)
            cnt = 1;                /* that one is left of '.'      */
        else if (form == 'E')       /* e format has digit left of '.' */
            cnt++, ndec++;          /* so ask __xcvt() for one more. */
    }

/* __xcvt will do the difficult part, conversion to decimal, but the    */
/*      format it returns must be worked on before it can be passed     */
/*      to the caller.  Therefore put it into a temporary buffer.       */

    exponent = __xcvt(valueP,cnt,&sign,buf,type);

    dst = strP;                 /* Set up pointer to destination string */

    /* Check for Infinity and NAN numbers right up front
     */
    if (exponent == INF_number)
    {
        strcpy(dst,sign ? "-INF" : "+INF");
        return;
    }
    else if (exponent == NAN_number)
    {
        strcpy(dst,sign ? "-NAN" : "+NAN");
        return;
    }

/*+---------------------------------------------------------------------+
  |                     We're printing a regular number                 |
  +---------------------------------------------------------------------+*/

    /* Either format begins with optional sign.
     */
    if (sign)
        *dst++ = '-';

    /* Now that we have the basic string, decide what format the caller
     * wants it to be put into.  Use the F format if either
     * of the following is true:
     *  1. the format is 'f'
     *  2. the format is 'g' and the exponent is between -3 and ndec
     *     (if ndec is zero digits, it is taken as 1).
     * and if no more than __XCVTDIG__ integral digits can result.
     */
    if (( form == 'F' ||
         (form == 'G' && exponent >= -3  && exponent <= (ndec == 0 ? 1 : ndec))
        ) && exponent <= __XCVTDIG__)
    {               /* F FORMAT */
        if (exponent <= 0)
        {
            /* No integral digits, begin with '0.'.
             */
            *dst++ = '0';
            *dst++ = DECIMAL_POINT;

            /* If the exponent is negative then leading zeroes are required.
             */
            while (exponent != 0)
            {
                *dst++ = '0';
                exponent++;
            }
        }

        /* Now write the regular digits, inserting a '.' if it is somewhere
         * in the middle of the numeral.
         */
        for (cnt = 0, src = buf; (ch = *src) != '\0'; src++)
        {
            *dst++ = ch;
            if (--exponent == 0)
            {
                *dst++ = DECIMAL_POINT;
                cnt++;
            }
        }

        /* Remove any trailing zeroes, unless there is an implied decimal at
         * the right edge.
         */
        cnt += realcnt;
        if (ndec > cnt)
        {
            /* Pad with zeroes.
             */
            cnt = ndec - cnt;
            exponent += cnt;
            memset(dst,'0',cnt);
            dst += cnt;
            if (--exponent == 0)
                goto CheckEmpty;
        }
        else if (--exponent != 0 && altFormat == 0)
        {
            /* Trim trailing zeroes, unless altFormat is specified.
             */
            dst = TrimTrailing(formCh, strP, dst);
        }

CheckEmpty:
        if (dst == strP)        /* is the result empty? */
            *dst++ = '0';       /* if so, it is a form of zero */
        *dst = '\0';            /* null terminate */
    }
    else            /* E FORMAT */
    {
        /* The E format always places one digit to the left of the decimal
         * point, followed by fraction digits, and then an 'E' followed
         * by a decimal exponent.  The exponent is always 2 digits unless
         * it is of magnitude > 99.
         */
        src = buf;
        *dst++ = *src++;                /* copy first digit */
        if ((ch = *src++) != '\0')      /* is there a second digit? */
        {
            /* The decimal point appears only if followed by a digit.
             * Then copy second and remaining digits, up to but
             * not including the terminating null.
             */
            *dst++ = DECIMAL_POINT;
            while (ch != '\0')
            {
                *dst++ = ch;
                ch = *src++;
            }

            /* Trailing zeroes are removed from the fraction.
             */
            if (altFormat == 0)
                dst = TrimTrailing(formCh, strP, dst);
        }
        else if (altFormat)     /* If only one digit, but alt format, */
            *dst++ = DECIMAL_POINT;       /* put in a decimal point */
            

        /* Now put in the exponent.  Note that the exponent returned
         * from __xcvt is one digit different, since __xcvt places the
         * decimal point at the left edge.
         */
        *dst++ = (formCh & 0x20) | 'E';     /* output 'e' or 'E' */
        if (--exponent < 0)
        {
            exponent = -exponent;   /* Make it positive for later */
            *dst++ = '-';
        }
        else
            *dst++ = '+';

        /* ANSI says that "The exponent always contains AT LEAST two digits".
         * If the exponent is bigger than 99 then we will use as many as are 
         * required.  It can never be more than 4 digits.
         */
        if (exponent >= 1000)
            cnt = 4;
        else if (exponent >= 100)
            cnt = 3;
        else
            cnt = 2;
        dst[cnt] = '\0';                /* null terminate early */
        while (cnt != 0)
        {
            cnt--;
            dst[cnt] = exponent % 10 + '0';
            exponent /= 10;
        }
    }
}

/*--------------------------------------------------------------------------*

Name            _nextreal - advance floating point argument pointer

Usage           va_list _nextreal (va_list argP, int isLongDouble);

Prototype in    _printf.h

Description     Advance the argument pointer argP to the next double or
                long double value.  The isLongDouble flag is 0 for double,
                and non-zero for long double.  The value pointed to
                by argP is ignored.

                This is an internal function used by __vprinter.  Its
                whole reason for existence is to avoid the use of floating
                point numbers in __vprinter, which can cause an unwanted
                reference to the magic compiler-generated external __fltused.

Return value    The new argument pointer.

*---------------------------------------------------------------------------*/

static va_list _nextreal (va_list argP, int isLongDouble)
{
    if (isLongDouble)
        (void)va_arg(argP,long double);
    else
        (void)va_arg(argP,double);
    return (argP);
}

/*--------------------------------------------------------------------------*

Name            _cvt_init - initialize pointers to _realcvt and _nextreal

Usage           void _cvt_init (void);

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

void _RTLENTRY _cvt_init (void)
{
    _realcvtptr = _realcvt;
    _nextrealptr = _nextreal;
}
