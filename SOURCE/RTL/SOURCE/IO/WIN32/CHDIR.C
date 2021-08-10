/*---------------------------------------------------------------------------
 * filename - chdir.c
 *
 * function(s)
 *        chdir   - changes working directory
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.4  $        */

#include <ntbc.h>

#include <_io.h>
#include <stdlib.h>
#include <ctype.h>
#include <_ostype.h>
#include <_tchar.h>

/*--------------------------------------------------------------------------*

Name            _tchdir used as chdir and _wchdir
                chdir   - changes working directory
                _wchdir - changes working directory

Usage           int chdir(const char *path);
                int _wchdir(const wchar_t *path);

Prototype in    dir.h

Description     causes the directory specified by path to become the
                current working directory.

Return value    success : 0
                failure : -1 and errno is set to ENOENT (Path or file
                name not found)

*---------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _tchdir(const _TCHAR *pathP)
{
    _TCHAR buffer[_MAX_PATH];
    _TCHAR envname[4];
    _TCHAR drive;

    if (SetCurrentDirectory(pathP) != TRUE)
        return (__NTerror());

    if (GetCurrentDirectory(sizeof(buffer), buffer) == 0)
        return (__NTerror());

    if (_ostype != _DOS32)
    {
        drive = _totupper(buffer[0]);
        if (drive >= _TEXT('A') && drive <= _TEXT('Z') &&
            buffer[1] == _TEXT(':'))
        {
            /* On NT, you set the current directory for a given drive by
             * setting the magic environment variable =N:, where N is the
             * drive letter.
             */
            envname[0] = _TEXT('=');
            envname[1] = drive;
            envname[2] = _TEXT(':');
            envname[3] = _TEXT('\0');
            if (SetEnvironmentVariable(envname, buffer) != TRUE)
                return (__NTerror());
        }
    }
    return(0);
}
