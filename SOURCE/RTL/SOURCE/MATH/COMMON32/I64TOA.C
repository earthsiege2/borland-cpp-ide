/*-----------------------------------------------------------------------*
 * filename - ltoa2.c
 *
 * function(s)
 *        _i64toa    - converts a __int64 to a string
 *        _ui64toa   - converts an unsigned __int64 to a string
 *        _i64tow    - converts a __int64 to a wide-character string
 *        _ui64tow   - converts an unsigned __int64 to a wide-character string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1996, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $ */

#include <stdlib.h>
#include <_printf.h>
#include <tchar.h>
#include <_tchar.h>

/*-----------------------------------------------------------------------*

Name            _i64toa  - converts a long to a string
                _ui64toa - converts an unsigned long to a string

Usage           char *    _i64toa(__int64 value, char *strP, int radix);
                char *    _ui64toa(unsigned __int64 value, char *strP, int radix);
                wchar_t * _i64tow(__int64 value, wchar_t *strP, int radix);
                wchar_t * _ui64tow(unsigned __int64 value, wchar_t *strP, int radix);

Prototype in    stdlib.h
                _printf.h for __int64toa

Description     These functions  convert value to a  null-terminated string
                and  store the  result in  string. With  _i64toa  it is  a
                __int64, with _ui64toa it is an unsigned long.  __longtoa 
                is the  internal routine used for all these conversions to 
                ASCII (in longtoa.cas).

                radix specifies the base to be used in converting value. it
                must be between  2 and 36 (inclusive). With  itoa and ltoa,
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

_TCHAR * _RTLENTRY _EXPFUNC _ui64tot (unsigned __int64 value, _TCHAR *strP, int radix)
{
        return  __int64tot (value, strP, radix, 0, _TEXT('a'));
}


_TCHAR  * _RTLENTRY _EXPFUNC _i64tot (__int64 value, _TCHAR *strP, int radix)
{
        return  __int64tot (value, strP, radix, (radix == 10), _TEXT('a'));
}
