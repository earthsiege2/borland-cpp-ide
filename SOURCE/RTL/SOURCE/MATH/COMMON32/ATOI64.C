/*---------------------------------------------------------------------------
 * filename - atoi64.c
 *
 * function(s)
 *        _atoi64 - converts a string to a __int64
 *        _wtoi64 - converts a wide-character string to a __int86
 *--------------------------------------------------------------------------*/

/* $Copyright:$ */
/* $Revision:   8.0  $  */

#include <stdlib.h>
#include <ctype.h>
#include <tchar.h>

/*--------------------------------------------------------------------------*

Name            _atoi64, _wtoi64 - converts a string to a __int64

Usage           __int64 atol(const char *nptr);
                __int64 _wtol(const wchar_t *nptr);

Prototype in    stdlib.h

Description     Convert a string to a __int64.  The syntax of
                the string must be:

                        __int64  ::= [isspace]* [sign] digit [digit]*

                Only decimal integers are acceptable.

                Error handling is poor.  The function will protect
                itself (crash-proof) but there is no defined method
                to return an error indication to the caller.  The
                result is undefined if the input string is invalid.

Return value    converted value of the input string.  If the string
                cannot be converted to a __int64, the return value is 0.

*---------------------------------------------------------------------------*/

__int64 _RTLENTRY _EXPFUNC _ttoi64(const _TCHAR *strP)
{
    _TCHAR c;
    int  is_neg;
    __int64 result;

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
