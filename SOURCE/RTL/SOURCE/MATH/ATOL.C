/*---------------------------------------------------------------------------
 * filename - atol.c
 *
 * function(s)
 *        atol  - converts a string to a long
 *        atoi  - converts a string to an int
 *        _wtol  - converts a wide-character string to a long
 *        _wtoi  - converts a wide-character string to an int
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <stdlib.h>
#include <ctype.h>
#include <tchar.h>

#undef   atoi           /* macro in stdlib */

/*--------------------------------------------------------------------------*

Name            atol, _wtol - converts a string to an integer

Usage           long atol(const char *nptr);
                long _wtol(const wchar_t *nptr);

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

long _RTLENTRY _EXPFUNC _ttol(const _TCHAR *strP)
{
    _TCHAR c;
    int  is_neg;
    long result;

    result = 0;                     /* default result is 0 */

    while (_istspace((c = *strP++)))  /* skip any whitespace characters */
        ;

    if (c == _TEXT('+') || c == _TEXT('-'))       /* remember if negative sign seen */
    {
        is_neg = c == _TEXT('-');
        c = *strP++;                /* skip sign, get next char */
    }
    else
        is_neg = 0;

    while (c >= _TEXT('0') && c <= _TEXT('9'))    /* accumulate digits, ignore overflow */
    {
        result = result * 10 + c - _TEXT('0');
        c = *strP++;
    }

    return (is_neg ? -result : result); /* negate result if '-' seen */
}

/*--------------------------------------------------------------------------*

Name            atoi, _wtoi - converts a string to an integer

Usage           int atoi(char *nptr);
                int atoi(wchar_t *nptr);

Prototype in    stdlib.h

Description     Convert ASCII string to word integer.

                The only difference between this and the atol
                function is whether the result is truncated.

Return value    converted long value of the input string.  If the string
                cannot be converted to an int, the return value is 0.

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ttoi(const _TCHAR *strP)
{
        return (int) _ttol (strP);
}
