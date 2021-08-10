/*-----------------------------------------------------------------------*
 * filename - rename.c
 *
 * function(s)
 *        rename - renames a file
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#include <ntbc.h>

#include <stdio.h>
#include <_io.h>
#include <_tchar.h>

/*-----------------------------------------------------------------------*

Name            _trename used as rename and _wrename
                rename   - renames a file
                _wrename - renames a file

Usage           int rename(const char *oldname, const char *newname);
                int _wrename(const wchar_t *oldname, const wchar_t *newname);

Prototype in    stdio.h

Description     _trename changes the name of a file from oldname to
                newname. If a drive specifier is given in newname, the
                specifier must be the same as that given in oldname.

                Directories in a path need not be the same, so rename can be
                used to move a file from one directory to another. Wildcards
                are not allowed.

Return value    On successfully renaming the file, _trename returns
                0. In the event of error, -1 is returned, and errno is set
                to one of the following:

                        ENOENT  Path or file name not found
                        EACCES  Permission denied
                        ENOTSAM Not same device

*------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _trename(const _TCHAR *oldname, const _TCHAR *newname)
{
    return (MoveFile(oldname,newname) == TRUE ?
                0 : __NTerror());
}
