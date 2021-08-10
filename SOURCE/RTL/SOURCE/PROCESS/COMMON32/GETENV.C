/*---------------------------------------------------------------------------
 * filename - getenv.c
 *
 * function(s)
 *        getenv - get string from environment
 *        _wgetenv - get wide-character string from environment
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.6  $        */

#include <stdlib.h>
#include <string.h>
#include <_process.h>
#include <tchar.h>
#include <_tchar.h>
#include <_ostype.h>

/*--------------------------------------------------------------------------*

Name            getenv, _wgetenv - get string from environment

Usage           char *getenv(const char *envvar);
		whar_t *_wgetenv(const wchar_t *envvar);

Prototype in    stdlib.h

Description     The environment consists of a series of entries that
                are of the form:

                name=string\0

                The global variable environ points to an array of pointers
                to these entries.  The last pointer in the array is NULL.
                getenv searches the environment for the entry corresponding
                to envvar, then returns a pointer to string.

                The string  comparison is NOT case-sensitive.

Return value    On  success, getenv and _wgetenv return a pointer to the value
                associated with envvar.

*---------------------------------------------------------------------------*/

_TCHAR * _RTLENTRY _EXPFUNC _tgetenv(const _TCHAR *nameP)
{
#if defined(_UNICODE)
    if (_ostype & _WINNT)
    {
#endif
    _TCHAR  **envP;
    int   len;

    len = _tcslen(nameP);            /* save length of name */
    if (len == 0)
        return NULL;

    _tlock_env();                    /* lock out other users of 'environ' */

    for (envP = _tenviron; *envP != NULL; envP++)
        if (_tcsnicmp(*envP,nameP,len) == 0 && (*envP)[len] == _TEXT('='))
            break;

    _tunlock_env();

    if (*envP)
        return ((*envP)+len+1);     /* point past the '=' */
    else
        return (NULL);
#if defined(_UNICODE)
    }
    else
        return NULL;
#endif
}
