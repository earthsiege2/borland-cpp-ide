/*---------------------------------------------------------------------------
 * filename - _chdrive.c
 *
 * function(s)
 *        _chdrive   - change the current working drive
 *        _getrive   - get the current working drive
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <ntbc.h>

#include <stdlib.h>
#include <errno.h>
#include <_io.h>

/*--------------------------------------------------------------------------*

Name            _chdrive - sets current drive

Usage           int _chdrive(int drive);

Prototype in    dir.h

Description     sets the current drive.
                1 = A:, 2 = B:, 3 = C:; etc.

Return value    0 if drive changed successfully, -1 if error.

Note            Compatible with MSC. Not the same as setdisk().

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _chdrive(int drive)
{
    char    buf[3];

    /* Set the current drive by setting the current directory to "X:".
     */
    buf[0] = drive + 'A' - 1;
    buf[1] = ':';
    buf[2] = '\0';

    if (SetCurrentDirectory(buf) != TRUE)
        return(__NTerror());
    return 0;
}

/*--------------------------------------------------------------------------*

Name            _getdrive - sets current drive

Usage           int _getdrive(int drive);

Prototype in    dir.h

Description     gets the current drive.
                1 = A:, 2 = B:, 3 = C:; etc.

Return value    If successful, the drive number; -1 if error.

Note            Compatible with MSC. Not the same as getdisk().

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _getdrive()
{
    char *buf;
    int   drive;
    int   size;

    /* Allocate a buffer big enough to hold the current directory path.
     * Then get the current directory.
     */
    if ((buf = malloc(MAX_PATH)) == NULL)
    {
enomem:
        errno = ENOMEM;
        return -1;
    }
    size = (int)GetCurrentDirectory(MAX_PATH, buf);
    if (size == 0 || size > MAX_PATH)
        goto enomem;

    /* Parse the drive name to get the drive number.
     */
    drive = buf[0];
    if (buf[1] == ':')
    {
	drive = toupper(drive);
        if (drive >= 'A' && drive <= 'Z')
            drive = drive - 'A' + 1;
        else
            drive = 0;      /* something strange about the drive name */
    }
    free(buf);
    return (drive);
}

