/*---------------------------------------------------------------------------
 * filename - getcurdi.c
 *
 * function(s)
 *        getcurdir - gets current directory for specified drive
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <direct.h>
#include <string.h>

/*--------------------------------------------------------------------------*

Name            getcurdir - gets current directory for specified drive

Usage           int getcurdir(int drive, char *direc);

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

int _RTLENTRY _EXPFUNC getcurdir(int drive, char *direc)
{
    /* Use _getdcwd to do all the messy hard work.  Then
     * strip out the drive name and leading slash from the result.
     */
    if (_getdcwd(drive, direc, MAXDIR) == NULL)
        return (-1);
    memmove(direc, direc+3, strlen(direc+3)+1);
    return (0);
}
