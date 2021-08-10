/*-----------------------------------------------------------------------*
 * filename - strnicmp.c
 *
 * function(s)
 *        strnicmp  -  compare one string to another without case sensitivity
 *        wcsnicmp  -  compare one wide-character string to another without
 *			case sensitivity
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <string.h>
#include <tchar.h>
#include <ctype.h>

/*-----------------------------------------------------------------------*

Name            strnicmp, _wcsnicmp - compare one  ASCII/wide-character string
			    to another without case sensitivity

Usage           int strnicmp(const char *str1, const char *str2, size_t maxlen);
		int _wcsnicmp(const wchar_t *str1, const wchar_t *str2, size_t maxlen);

Prototype in    string.h

Description     Case-independent  comparison of  *str1 with  *str2. Compare
                the strings, but act as  if upper and lower case characters
                were  always  upper-case,  returning  a  negative, zero, or
                positive integer  according to whether *str1  is less than,
                equal, or greater than *str2, respectively.

                At most "maxlen" bytes will  be compared before stopping. A
                zero "maxlen"  results in an  equal strnicmp, i.e.  returns
                zero.

                The strings *str1 and *str2 are not changed.

                When  comparing to  punctuation characters  alphabetics are
                always treated as upper-case.

Return value    strnicmp and _wcsicmp return an integer value such as:
                        < 0     if str1 is less than str2
                        = 0     if str1 is the same as str2
                        > 0     if str2 is greater than str2

*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _tcsnicmp(const _TCHAR *str1, const _TCHAR *str2, size_t maxlen)
{
    while ((maxlen != 0) && (*str1 != _TEXT('\0')) && _totupper(*str1) == _totupper(*str2) )
    {
        maxlen--;
        str1++;
        str2++;
    }
    if (maxlen == 0)
        return (0);
    else
        return (_totupper(*str1) - _totupper(*str2));
}
