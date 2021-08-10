/*-----------------------------------------------------------------------*
 * filename - int64toa.c
 *
 * function(s)
 *    __int64toa - converts a __int64 to a character string
 *    __int64tow - converts a __int64 to a wide-character string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1996, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $ */

#include <stdlib.h>
#include <_printf.h>
#include <tchar.h>
#include <_tchar.h>

/*-----------------------------------------------------------------------*

Name            __int64toa - converts a __int64 to a character string
		__int64tow - converts a __int64 to a wide-character string

Usage           char *    __int64toa (__int64 value, char *strP, int radix,
                                      char maybeSigned, char hexStyle);
                wchar_t * __int64tow (__int64 value, wchar_t *strP, int radix,
                                      char maybeSigned, wchar_t hexStyle);

Prototype in    _printf.h

Description     This function converts a long value to a  null-terminated string
                and  stores the result in  string strP.

                radix specifies the base to be used in converting value. it
                must be between  2 and 36 (inclusive).

                maybeSigned is treated as a boolean. If false then value is
                treated  as unsigned  long and  no sign  will be  placed in
                *strP.

                hexStyle  may take  the values  'a' or  'A' and  determines
                whether lower or  upper case alphabetics are used  when the
                radix is 11 or greater.

                Note: The space  allocated for string must be  large enough
                to hold the returned  string including the terminating null
                character (\0).  The maximum is the length the number
                of bits in the integral type plus one for the terminator.

Return value    pointer to the string

*------------------------------------------------------------------------*/

_TCHAR * __int64tot (__int64 value, _TCHAR *strP, int radix,
                    _TCHAR maybeSigned, _TCHAR hexStyle)
{
    _TCHAR    buf [65];
    _TCHAR    c, *p, *bufp;

    p = strP;

    /* If the requested radix is invalid, generate an empty result.
     */
    if (radix >= 2 && radix <= 36)
    {

        /* If the value is signed and less than zero, generate a minus sign.
         */
        if (value < 0 && maybeSigned != 0)
        {
            *p++ = _TEXT('-');
            value = -value;
        }

        /* Now loop, taking each digit as modulo radix, and reducing the value
         * by dividing by radix, until the value is zeroed.  Note that
         * at least one loop occurs even if the value begins as 0,
         * since we want "0" to be generated rather than "".
         */
        bufp = buf;
        for (;;)
        {
            *bufp++ = (char)((unsigned __int64)value % radix);
            if ((value = (unsigned __int64)value / radix) == 0)
                break;
        }

        /* The digits in the buffer must now be copied in reverse order into
         * the target string, translating to ASCII as they are moved.
         */
        while (bufp != buf)
        {
            if ((c = *--bufp) < 10)
                *p++ = (_TCHAR)(c + _TEXT('0'));
            else
                *p++ = (_TCHAR)((c - 10) + hexStyle);
        }
    }

    /* terminate the output string with a zero.
     */
    *p = _TEXT('\0');
    return (strP);          /* return a pointer to the string */
}
