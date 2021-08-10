/*-----------------------------------------------------------------------*
 * filename - setenv.c
 *
 * function(s)
 *        _setenv - set OS environment variable
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <_process.h>
#include <_io.h>

/*-----------------------------------------------------------------------*

Name            _setenv - set OS environment variable

Usage           int _setenv(const char *string);

Prototype in    _process.h

Description     _setenv calls the OS API function to set an environment
                variable string.  The string is of the form

                    var=value

                This is a helper function for putenv().
                
Return value    If successful, 0 is returned.  Otherwise -1 is returned
                and errno is set to a non-zero value.

*------------------------------------------------------------------------*/

int _setenv(const char *pathP)
{
    char *p, *q;
    int ret;

    /* Make a copy of the string.
     */
    if ((p = malloc(strlen(pathP)+1)) == NULL)
    {
        errno = ENOMEM;
        return -1;
    }
    strcpy(p, pathP);

    /* Find the '=' character and change it to a nul.
     */
    if ((q = strchr(p, '=')) == NULL)
    {
        errno = EINVAL;
        free(p);
        return -1;
    }
    *q = '\0';

    /* Call the OS to set its own copy of the environment variable.
     * Delete the environment variable if the new value is empty.
     */
    if (SetEnvironmentVariable(p, q[1] == '\0' ? NULL : q+1) != TRUE)
        ret = __NTerror();
    else
        ret = 0;
    free(p);
    return (ret);
}
