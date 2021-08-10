/*-----------------------------------------------------------------------*
 * filename - ltoa1.c
 *
 * function(s)
 *        itoa      - converts an integer to a string
 *        _ltoa      - converts a long to a string
 *        ultoa     - converts an unsigned long to a string
 *        _itow     - converts an integer to a wide-character string
 *        _ltow     - converts a long to a wide-character string
 *        _ultow     - converts an unsigned long to a wide-character string
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

Name            itoa  - converts an integer to a string
                _ltoa  - converts a long to a string
                ultoa - converts an unsigned long to a string

Usage           char *itoa(int value, char *strP, int radix);
                char *_ltoa(long value, char *strP, int radix);
                char *ultoa(unsigned long value, char *strP, int radix);
                wchar_t *itow(int value, wchar_t *strP, int radix);
                wchar_t *ltow(long value, wchar_t *strP, int radix);
                wchar_t *ultow(unsigned long value, wchar_t *strP, int radix);

Prototype in    stdlib.h
                _printf.h for __longtoa

Description     These functions  convert value to a  null-terminated string
                and  store the  result in  string. With  itoa, value  is an
                integer;  with _ltoa  it is  a  long;  with ultoa  it is  an
                unsigned long.  __longtoa is the  internal routine used for
                all these conversions to ASCII (in longtoa.cas).

                radix specifies the base to be used in converting value. it
                must be between  2 and 36 (inclusive). With  itoa and _ltoa,
                if value is negative, and  radix is 10, the first character
                of string is  the minus sign (-). This does  not occur with
                ultoa. Also, ultoa performs no overflow checking.

                maybeSigned is treated as a boolean. If false then value is
                treated  as unsigned  long and  no sign  will be  placed in
                *strP.

                hexStyle  may take  the values  'a' or  'A' and  determines
                whether lower or  upper case alphabetics are used  when the
                radix is 11 or greater.

                Note: The space  allocated for string must be  large enough
                to hold the returned  string including the terminating null
                character (\0).  These functions can return up to 33 bytes.

Return value    All these functions return a pointer to string. There is no
                error return.

*------------------------------------------------------------------------*/

_TCHAR *_RTLENTRY _EXPFUNC _itot( int value, _TCHAR *strP, int radix )
{
#define dword   unsigned long

        return  _longtot ((radix == 10) ? (long) value :
                           (dword)((unsigned)value), strP, radix, (radix == 10),
                           _TEXT('a'));
}


/*-----------------------------------------------------------------------*

Name            ultoa - converts an unsigned long to a string
                _ultow - converts an unsigned long to a string

Usage           char *ultoa(unsigned long value, char *string, int radix);
                wchar_t *_ultow(unsigned long value, wchar_t *string, int radix);

Prototype in    stdlib.h

Description     see itoa

*------------------------------------------------------------------------*/

_TCHAR * _RTLENTRY _EXPFUNC _ultot (unsigned long value, _TCHAR *strP, int radix)
{
        return  _longtot (value, strP, radix, 0, _TEXT('a'));
}


/*-----------------------------------------------------------------------*

Name            _ltoa - converts a long to a string
                _ltow - converts a long to a string

Usage           char *_ltoa(long value, char *string, int radix);

Prototype in    stdlib.h

Description     see itoa

*------------------------------------------------------------------------*/

_TCHAR  * _RTLENTRY _EXPFUNC _ltot (long value, _TCHAR *strP, int radix)
{
        return  _longtot (value, strP, radix, (radix == 10), _TEXT('a'));
}
