/*---------------------------------------------------------------------------
 * filename - getdisk.c
 *
 * function(s)
 *        getdisk - gets current drive
 *        setdisk - sets current drive
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <dos.h>

/*--------------------------------------------------------------------------*

Name            getdisk - gets current drive

Usage           int getdisk(void);

Prototype in    dir.h

Description     gets the current drive.

Return value    0 = A:, 1 = B:, 2 = C:; etc.

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC getdisk(void)
{
    unsigned drive;

    _dos_getdrive(&drive);
    return (int)drive - 1;
}

/*--------------------------------------------------------------------------*

Name            setdisk - sets current drive

Usage           int setdisk(int drive);

Prototype in    dir.h

Description     sets the current drive.
                0 = A:, 1 = B:, 2 = C:; etc.

Return value    the total number of drives available.

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC setdisk(int drive)
{
    unsigned ndrives;

    _dos_setdrive(drive+1, &ndrives);
    return (int)ndrives;
}
