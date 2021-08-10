/*---------------------------------------------------------------------------
 * filename - atol.c
 *
 * function(s)
 *        atol  - converts a string to a long
 *        atoi  - converts a string to an int
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdlib.h>
#include <ctype.h>

#undef   atoi           /* macro in stdlib */

/*--------------------------------------------------------------------------*

Name            atol - converts a string to an integer

Usage           long atol(const char *nptr);

Prototype in    stdlib.h

Description     Convert a string to a long integer.  The syntax of
                the string must be:

                        long     ::= [isspace]* [sign] digit [digit]*

                Only decimal integers are acceptable.

                Error handling is poor.  The function will protect
                itself (crash-proof) but there is no defined method
                to return an error indication to the caller.  The
                result is undefined if the input string is invalid.

Return value    converted long value of the input string.  If the string
                cannot be converted to a long, the return value is 0.

*---------------------------------------------------------------------------*/

long _RTLENTRYF _EXPFUNC atol(const char *strP)
{
    char c;
    int  is_neg;
    long result;

    result = 0;                     /* default result is 0 */

    while (isspace((c = *strP++)))  /* skip any whitespace characters */
        ;

    if (c == '+' || c == '-')       /* remember if negative sign seen */
    {
        is_neg = c == '-';
        c = *strP++;                /* skip sign, get next char */
    }
    else
        is_neg = 0;

    while (c >= '0' && c <= '9')    /* accumulate digits, ignore overflow */
    {
        result = result * 10 + c - '0';
        c = *strP++;
    }

    return (is_neg ? -result : result); /* negate result if '-' seen */
}

/*--------------------------------------------------------------------------*

Name            atoi - converts a string to an integer

Usage           int atoi(char *nptr);

Prototype in    stdlib.h

Description     Convert ASCII string to word integer.

                The only difference between this and the atol
                function is whether the result is truncated.

Return value    converted long value of the input string.  If the string
                cannot be converted to an int, the return value is 0.

*---------------------------------------------------------------------------*/

int _RTLENTRYF atoi(const char *strP)
{
        return (int) atol (strP);
}
