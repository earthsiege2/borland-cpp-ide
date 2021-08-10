/*-----------------------------------------------------------------------*
 * filename - setenv.c
 *
 * function(s)
 *        _setenv - set OS environment variable
 *        _wsetenv - set OS environment variable
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <ntbc.h>

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <_process.h>
#include <_io.h>
#include <tchar.h>
#include <_tchar.h>

/*-----------------------------------------------------------------------*

Name            _setenv, _wsetenv - set OS environment variable

Usage           int _setenv(const char *string);
                int _wsetenv(const wchar_t *string);

Prototype in    _process.h

Description     _setenv and _wsetenv call the OS API function to set an environment
                variable string.  The string is of the form

                    var=value

                This is a helper function for putenv().

Return value    If successful, 0 is returned.  Otherwise -1 is returned
                and errno is set to a non-zero value.

*------------------------------------------------------------------------*/

int _tsetenv(const _TCHAR *pathP)
{
    _TCHAR *p, *q;
    int ret;

    /* Make a copy of the string.
     */
    if ((p = malloc((_tcslen(pathP)+1)*sizeof(_TCHAR))) == NULL)
    {
        errno = ENOMEM;
        return -1;
    }
    _tcscpy(p, pathP);

    /* Find the '=' character and change it to a nul.
     */
    if ((q = _tcschr(p, _TEXT('='))) == NULL)
    {
        errno = EINVAL;
        free(p);
        return -1;
    }
    *q = _TEXT('\0');

    /* Call the OS to set its own copy of the environment variable.
     * Delete the environment variable if the new value is empty.
     */
    if (SetEnvironmentVariable(p, q[1] == _TEXT('\0') ? NULL : q+1) != TRUE)
        ret = __NTerror();
    else
        ret = 0;
    free(p);
    return (ret);
}
