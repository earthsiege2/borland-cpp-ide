/*-----------------------------------------------------------------------*
 * filename - rmdir.c
 *
 * function(s)
 *        _rmdir - removes directory
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.4  $        */

#include <ntbc.h>

#include <dir.h>
#include <_io.h>
#include <_tchar.h>

/*-----------------------------------------------------------------------*

Name            _trmdir used as _rmdir and _wrmdir
                _rmdir   - removes directory
                _wrmdir - removes directory

Usage           int _rmdir(const char *pathname);
                int _wrmdir(const wchar_t *pathname);

Prototype in    dir.h

Description     deletes the directory given by pathP.  The directory
                named by pathP

                        1) must be empty

                        2) must not be the current working directory

                        3) must not be the root directory

Return value    success : 0
                failure : -1 and errno is set to one of the following:

                        EACCES  Permission denied
                        ENOENT  Path or file name not found

*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _trmdir(const _TCHAR *pathP)
{
    if (RemoveDirectory(pathP) != TRUE)
        return (__NTerror());
    else
        return(0);
}
