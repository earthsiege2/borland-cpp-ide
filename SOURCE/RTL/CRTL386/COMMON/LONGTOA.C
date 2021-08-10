/*-----------------------------------------------------------------------*
 * filename - longtoa.c
 *
 * function(s)
 *    __longtoa - converts a long to a character string
 *    __utoa    - converts an unsigned int to a decimal string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdlib.h>
#include <_printf.h>

/*-----------------------------------------------------------------------*

Name            __longtoa - converts a long to a character string

Usage           char * __longtoa (long value, char *strP, int radix,
                                        char maybeSigned, char hexStyle);

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

char * __longtoa (long value, char *strP, int radix,
                        char maybeSigned, char hexStyle)
{
    char    buf [34];
    char    c, *p, *bufp;
    
    p = strP;

    /* If the requested radix is invalid, generate an empty result.
     */
    if (radix >= 2 && radix <= 36)
    {

        /* If the value is signed and less than zero, generate a minus sign.
         */
        if (value < 0 && maybeSigned != 0)
        {
            *p++ = '-';
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
                *p++ = (char)(c + '0');
            else
                *p++ = (char)((c - 10) + hexStyle);
        }
    }

    /* terminate the output string with a zero.
     */
    *p = '\0';
    return (strP);          /* return a pointer to the string */
}

/*-----------------------------------------------------------------------*

Name            __utoa - converts an unsigned int to a decimal string

Usage           char *__utoa(unsigned value, char *buf)

Prototype in    _printf.h

Description     see __longtoa above.

*------------------------------------------------------------------------*/

char * __utoa(unsigned value, char *buf)
{
    return  __longtoa ((long)(unsigned long)value, buf, 10, 0, 'a');
}
