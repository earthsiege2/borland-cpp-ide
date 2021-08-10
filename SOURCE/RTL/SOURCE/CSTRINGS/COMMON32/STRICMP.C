/*-----------------------------------------------------------------------*
 * filename - stricmp.c
 *
 * function(s)
 *        stricmp - compare  one  string  to  another  without case
 *                  sensitivity
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <string.h>
#include <ctype.h>

/*-----------------------------------------------------------------------*

Name            stricmp - compare  one  string  to  another  without case
                          sensitivity

Usage           int stricmp(const char *str1, const char *str2);

Prototype in    string.h

Description     Case-independent  comparison of  *str1 with  *str2. Compare
                the strings, but act as  if upper and lower case characters
                were  always  upper-case,  returning  a  negative, zero, or
                positive integer  according to whether *str1  is less than,
                equal, or greater than *str2, respectively.

                The strings *str1 and *str2 are not changed.

                When  comparing to  punctuation characters  alphabetics are
                always treated as upper-case.

Return value    stricmp return an integer value that is:
                        < 0     if str1 is less than str2
                        = 0     if str1 is the same as str2
                        > 0     if str2 is greater than str2

*------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC stricmp(const char *str1, const char *str2)
{
    char c1, c2;

    while ((c1 = (char)toupper(*str1)) == (c2 = (char)toupper(*str2)) && c1 != '\0')
    {
        str1++;
        str2++;
    }
    return (c1 - c2);
}
