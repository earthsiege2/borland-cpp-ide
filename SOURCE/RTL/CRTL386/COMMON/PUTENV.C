/*-----------------------------------------------------------------------*
 * filename - putenv.c
 *
 * function(s)
 *        putenv - adds string to current environment
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_process.h>
#include <string.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------*

Name            putenv - adds string to current environment

Usage           int putenv(const char *envvar);

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

                The string  comparison is case-sensitive, in  the usual "C"
                tradition.


Return value    On success, putenv returns 0; on failure, -1

*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC putenv( const char *nameP )
{
    char  **envP;
    int   len, nstrings;
    char  *p;

    /* Calculate length of the "NAME=" portion of the environment variable.
     */
    if ((p = strchr(nameP,'=')) == NULL)
        return (-1);
    len = (p - (char *)nameP) + 1;

    _lock_env();                    /* lock out other users of 'environ' */
    
    /* Search for this name.
     */
    for (envP = environ; *envP != NULL; envP++)
        if (strncmp(*envP,nameP,len) == 0)
            break;

    if (*envP)      /* Name already exists in table */
    {
        if (nameP[len] == '\0')
        {
            /* The value of the new string (the part to the right of the
             * '=') is blank.  Delete the existing string from the table.
             */
            while ((envP[0] = envP[1]) != NULL)
                envP++;
        }
        else
        {
            /* Replace the string with the new string.
             */
            *envP = (char *)nameP;
        }
    }
    else
    {
        /* Name doesn't exist.  Enlarge the table and add the string
         * to the end of the table, just before the terminating NULL
         * pointer.
         */
        nstrings = envP - environ;
        if ((envP = realloc(environ,(nstrings+2) * sizeof(char *))) == NULL)
            return (-1);
        envP[nstrings] = (char *)nameP;
        envP[nstrings + 1] = NULL;
        environ = envP;
    }

    /* Inform the operating system about this environment string.
     */
#ifdef __WIN32__
    _setenv(nameP);
#endif

    _unlock_env();
    return (0);
}
