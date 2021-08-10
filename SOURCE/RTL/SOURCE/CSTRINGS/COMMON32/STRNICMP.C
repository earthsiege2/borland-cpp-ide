/*-----------------------------------------------------------------------*
 * filename - strnicmp.cas
 *
 * function(s)
 *        strnicmp  -  compare  one  string  to  another  without case
 *                     sensitivity
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <string.h>
#include <ctype.h>

/*-----------------------------------------------------------------------*

Name            strnicmp  -  compare  one  string  to  another  without case
                             sensitivity

Usage           int strnicmp(const char *str1, const char *str2, size_t maxlen);

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

Return value    strnicmp returns an integer value such as:
                        < 0     if str1 is less than str2
                        = 0     if str1 is the same as str2
                        > 0     if str2 is greater than str2

*------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC strnicmp(const char *str1, const char *str2, size_t maxlen)
{
    while (toupper(*str1) == toupper(*str2) && *str1 != '\0' && maxlen != 0)
    {
        maxlen--;
        str1++;
        str2++;
    }
    if (maxlen == 0)
        return (0);
    else
        return (toupper(*str1) - toupper(*str2));
}
