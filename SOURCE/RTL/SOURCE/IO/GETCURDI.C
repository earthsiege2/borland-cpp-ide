/*---------------------------------------------------------------------------
 * filename - getcurdi.c
 *
 * function(s)
 *        getcurdir - gets current directory for specified drive
 *        _wgetcurdir - gets current directory for specified drive (wide-character)
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <dir.h>
#include <direct.h>
#include <string.h>
#include <tchar.h>

/*--------------------------------------------------------------------------*

Name            getcurdir, _wgetcurdir - gets current directory for specified drive

Usage           int getcurdir(int drive, char *direc);
                int _wgetcurdir(int drive, wchar_t *direc);

Prototype in    dir.h

Description     getcurdir gets the name of the current working
                directory for the named drive.

                drive contains a drive number (0 = default, 1 = A, etc.).

                direc points to an area of memory of length MAXDIR where
                the directory name will be placed. The null-terminated name
                does not contain the drive specification and does not begin
                with a backslash.

Return value    getcurdir returns 0 on success or -1 in the event
                of error.

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _tgetcurdir(int drive, _TCHAR *direc)
{
    /* Use _getdcwd to do all the messy hard work.  Then
     * strip out the drive name and leading slash from the result.
     */
    if (_tgetdcwd(drive, direc, MAXDIR) == NULL)
        return (-1);
    memmove(direc, direc+3, (_tcslen(direc+3)+1)*sizeof(_TCHAR));
    return (0);
}
