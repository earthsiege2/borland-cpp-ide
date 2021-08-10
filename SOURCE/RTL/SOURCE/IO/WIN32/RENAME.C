/*-----------------------------------------------------------------------*
 * filename - rename.c
 *
 * function(s)
 *        rename - renames a file
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <stdio.h>
#include <_io.h>

/*-----------------------------------------------------------------------*

Name            rename - renames a file

Usage           int rename(const char *oldname, const char *newname);

Prototype in    stdio.h

Description     rename changes the name of a file from oldname to
                newname. If a drive specifier is given in newname, the
                specifier must be the same as that given in oldname.

                Directories in a path need not be the same, so rename can be
                used to move a file from one directory to another. Wildcards
                are not allowed.

Return value    On successfully renaming the file, rename returns
                0. In the event of error, -1 is returned, and errno is set
                to one of the following:

                        ENOENT  Path or file name not found
                        EACCES  Permission denied
                        ENOTSAM Not same device

*------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC rename(const char *oldname, const char *newname)
{
    return (MoveFile((char *)oldname,(char *)newname) == TRUE ?
                0 : __NTerror());
}
