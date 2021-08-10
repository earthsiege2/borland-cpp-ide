/*-----------------------------------------------------------------------*
 * filename - strtok.c
 *
 * function(s)
 *        strtok - searches one string for tokens, which are
 *                 separated by delimiters defined in a second string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#ifdef _MT
#include <_thread.h>
#endif
#include <string.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            strtok, wcstok - searches one (wide-character) string for tokens,
			which are separated by delimiters defined in a second
			(wide-character)string

Usage           char *strtok(char *str1, const char *str2);
		wchar_t *wcstok(wchar_t *str1, const wchar_t *str2);

Prototype in    string.h

Description     strtok and wcstok consider the string str1 to consist of a sequence
		of zero or more text tokens, separated by spans of one or more
                characters from the separator string str2.

                The first call to strtok returns a pointer to the first
                character of the first token in str1 and writes a null character
                into str1 immediately following the returned token. Subsequent
                calls with NULL for the first argument will work through the
                string str1 in this way until no tokens remain.

                The separator string, str2, may be different from call to
                call.

Return value    pointer to the scanned token.  When no tokens remain in str1,
                strtok and wcstok return a NULL pointer.

*---------------------------------------------------------------------*/
_TCHAR * _RTLENTRYF _EXPFUNC _tcstok(_TCHAR *s1, const _TCHAR *s2)
{
    register const _TCHAR *sp;
    _TCHAR *tok;
    _TCHAR **save;
#ifndef _MT
    static _TCHAR *token;
#endif

    /* Get address of saved token pointer
     */
#ifdef _MT
    save = (_TCHAR **)&_thread_data()->thread_token;
#else
    save = &token;
#endif

    if (s1 == NULL)
        s1 = *save;

    /* First skip separators
     */
    while (*s1)
    {
        for (sp = s2; *sp; sp++)
            if (*sp == *s1)
                break;
        if (*sp == 0)
            break;
        s1++;
    }
    if (*s1 == 0)
    {
        *save = s1;
        return (0);
    }
    tok = s1;
    while (*s1)
    {
        for (sp = s2; *sp; sp++)
            if (*sp == *s1)
            {
                *s1++ = 0;
                *save = s1;
                return (tok);
            }
        s1++;
    }
    *save = s1;
    return (tok);
}
