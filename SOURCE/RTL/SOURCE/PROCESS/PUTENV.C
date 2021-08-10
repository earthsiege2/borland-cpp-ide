/*-----------------------------------------------------------------------*
 * filename - putenv.c
 *
 * function(s)
 *        putenv - adds string to current environment
 *        wputenv - adds string to current environment
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <tchar.h>
#include <_process.h>
#include <_tchar.h>
#include <string.h>
#include <stdlib.h>

extern int _RTLENTRY _EXPDATA _tenvsize; /* number of env strings allocated */
int _texpandblock (void);

/*-----------------------------------------------------------------------*

Name            putenv, _wputenv - adds string to current environment

Usage           int putenv(const char *envvar);
                int _wputenv(const wchar_t *envvar);

Prototype in    stdlib.h

Description     Define an environment string to be of the form:

                        name=string\0

                This function scans the environment looking for an existing
                string with the same name as the argument *envvar. If it is
                found then the pointer envvar  is substituted in the table.
                The replaced string  is not overwritten or freed,  just the
                reference to it in the environment table is removed.

                If the argument  represents a new name, not  matched in the
                existing  environment,  then  it  will  be  appended to the
                environment  table. The  table is  adjusted in  chunks of 4
                pointers and is initialized with  at least 4 spare entries,
                but if all spare entries in the table have been used then a
                new larger  block is allocated.  The environment is  copied
                into the new  block, the "environ" pointer is  updated, and
                the old block is deallocated. The envp parameter to  main()
                will then be invalid.

                The string  comparison is NOT case-sensitive.



Return value    On success, putenv and _wputenv  return 0; on failure, -1

*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _tputenv( const _TCHAR *nameP )
{
    _TCHAR  **envP;
    int   len, j;
    _TCHAR  *p;

    /* Calculate length of the "NAME=" portion of the environment variable.
     */
    if ((p = _tcschr(nameP,_TEXT('='))) == NULL)
        return (-1);
    len = (p - (_TCHAR *)nameP) + 1;

    _tlock_env();                    /* lock out other users of 'environ' */

    /* Search for this name.
     */
    for (envP = _tenviron; *envP != NULL; envP++)
        if (_tcsnicmp(*envP,nameP,len) == 0)
            break;

    if (*envP)      /* Name already exists in table */
    {
        if (nameP[len] == _TEXT('\0'))
        {
            /* The value of the new string (the part to the right of the
             * '=') is blank.  Delete the existing string from the table.
             */

            *envP = _TEXT("");   /* place holder for the deleted string */
        }
        else
        {
            /* Replace the string with the new string.
             */
            *envP = (_TCHAR *) nameP;
        }
    }
    else
    {
        /* Name doesn't exist. Check for an empty slot in one of the
         * four extra slots.  If none, then expand the table and add
         * the string.
         */

        j = 4;
        while (_tenviron[_tenvsize-j])
        {
            j--;
            if (j == 0)
            {
                if (_texpandblock() == 0)
                {
                    _tunlock_env();
                    return (-1);
                }
                j = 4;
            }
        }
        /* Copy the string in the new spot
         */
        _tenviron[_tenvsize-j] = (_TCHAR *) nameP;
    }

    /* Inform the operating system about this environment string.
     */
#ifdef __WIN32__
    _tsetenv(nameP);
#endif

    _tunlock_env();
    return (0);
}
