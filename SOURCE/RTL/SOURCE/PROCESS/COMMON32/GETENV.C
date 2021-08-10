/*---------------------------------------------------------------------------
 * filename - getenv.c
 *
 * function(s)
 *        getenv - get string from environment
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdlib.h>
#include <string.h>
#include <_process.h>

/*--------------------------------------------------------------------------*

Name            getenv - get string from environment

Usage           char *getenv(const char *envvar);

Prototype in    stdlib.h

Description     The environment consists of a series of entries that
                are of the form:

                name=string\0

                The global variable environ points to an array of pointers
                to these entries.  The last pointer in the array is NULL.
                getenv searches the environment for the entry corresponding
                to envvar, then returns a pointer to string.

                The string  comparison is case-sensitive, in  the usual "C"
                tradition.

Return value    On  success,   getenv  returns  a  pointer   to  the  value
                associated with envvar.

*---------------------------------------------------------------------------*/

char * _RTLENTRYF _EXPFUNC getenv(const char *nameP)
{
    char  **envP;
    int   len;

    len = strlen(nameP);            /* save length of name */

    _lock_env();                    /* lock out other users of 'environ' */
    
    for (envP = environ; *envP != NULL; envP++)
        if (strncmp(*envP,nameP,len) == 0 && (*envP)[len] == '=')
            break;

    _unlock_env();

    if (*envP)
        return ((*envP)+len+1);     /* point past the '=' */
    else
        return (NULL);
}
