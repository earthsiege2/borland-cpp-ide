/*-----------------------------------------------------------------------*
 * filename - mkdir.c
 *
 * function(s)
 *        _mkdir - creates a directory
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#define INCL_ERROR_H
#include <ntbc.h>

#include <dir.h>
#include <_io.h>
#include <errno.h>
#include <_tchar.h>

/*-----------------------------------------------------------------------*

Name            _tmkdir used as _mkdir and _wmkdir
                _mkdir   - creates a directory
                _wmkdir - creates a directory

Usage           int _mkdir(const char *pathname);
                int _wmkdir(const wchar_t *pathname);

Related
functions usage int _trmdir(const _TCHAR *pathname);

Prototype in    dir.h

Description     _tmkdir takes the given pathname and creates a new
                directory with that name.

                _trmdir deletes the directory given by pathname. The
                directory named by pathname

                        must be empty

                        must not be the current working directory

                        must not be the root directory

Return value    _tmkdir returns the value 0 if the new directory was
                created.

                _trmdir returns 0 if the directory is successfully deleted.

                With either function, a return value of -1 indicates an error,
                and errno is set to one of the following values:

                        EACCES  Permission denied
                        ENOENT  Path or file name not found

*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _tmkdir(const _TCHAR *pathP)
{
    if (CreateDirectory(pathP,NULL) != TRUE)
        {
        if (GetLastError() == ERROR_ALREADY_EXISTS)
            return (__IOerror(EACCES));
        else
            return (__NTerror());
        }
    else
        return(0);
}
