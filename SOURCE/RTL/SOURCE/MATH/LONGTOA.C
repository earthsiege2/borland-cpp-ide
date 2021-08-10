/*-----------------------------------------------------------------------*
 * filename - longtoa.c
 *
 * function(s)
 *    __longtoa - converts a long to a character string
 *    __utoa    - converts an unsigned int to a decimal string
 *    __longtow - converts a long to a wide-character string
 *    __utow    - converts an unsigned int to a wide-character decimal string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <stdlib.h>
#include <_printf.h>
#include <tchar.h>
#include <_tchar.h>

/*-----------------------------------------------------------------------*

Name            __longtoa - converts a long to a character string
		__longtow - converts a long to a wide-character string

Usage           char * __longtoa (long value, char *strP, int radix,
                                        char maybeSigned, char hexStyle);
                wchar_t * __longtow (long value, wchar_t *strP, int radix,
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
                character (\0).  itoa can return  up to 17  bytes; ltoa and
                ultoa, up to 33 bytes.

Return value    pointer to the string

*------------------------------------------------------------------------*/

_TCHAR * _longtot (long value, _TCHAR *strP, int radix,
                        _TCHAR maybeSigned, _TCHAR hexStyle)
{
    _TCHAR    buf [34];
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
            *bufp++ = (char)((unsigned long)value % radix);
            if ((value = (unsigned long)value / radix) == 0)
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

/*-----------------------------------------------------------------------*

Name            __utoa, __utow - converts an unsigned int to a decimal string

Usage           char *__utoa(unsigned value, char *buf)
                wchar_t *__utoa(unsigned value, wchar_t *buf)

Prototype in    _printf.h

Description     see __longtoa above.

*------------------------------------------------------------------------*/

_TCHAR * _utot(unsigned value, _TCHAR *buf)
{
    return  _longtot ((long)(unsigned long)value, buf, 10, 0, _TEXT('a'));
}
