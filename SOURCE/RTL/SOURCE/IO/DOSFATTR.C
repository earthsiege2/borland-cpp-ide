/*------------------------------------------------------------------------
 * filename - dosfattr.c
 *
 * function(s)
 *      _dos_getfileattr - get file attributes
 *      _dos_setfileattr - change file attributes
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#include <ntbc.h>
#include <dos.h>
#include <_io.h>

/*--------------------------------------------------------------------------*

Name            _dos_getfileattr - get current attributes of file

Usage           unsigned _dos_getfileattr(const char *filename,
                         unsigned *attrib);

Prototype in    dos.h

Description     Fetch the NT file attributes for filename,
                store them in low byte of *attrib.

Return value    success : 0
                failure : DOS error code, and errno is set to

                    ENOENT  Path or file name not found

Note            Compatible with Microsoft C.

*---------------------------------------------------------------------------*/

unsigned _RTLENTRY _EXPFUNC
_dos_getfileattr(const char *filename, unsigned *attrib)
{
    DWORD   attr;

    if ((attr = GetFileAttributes((LPSTR)filename)) == (DWORD)-1)
        return (__DOSerror());
    *attrib = attr;
    return (0);
}

/*--------------------------------------------------------------------------*

Name            _dos_setfileattr - set current attributes of file

Usage           unsigned _dos_setfileattr(const char *filename,
                         unsigned attrib);

Prototype in    dos.h

Description     Set the NT file attributes for filename to
                the value in the low byte of attrib.

Return value    success : 0
                failure : DOS error code, and errno is set to either

                        ENOENT  Path or file name not found
                        EACCESS Permission denied

Note            Compatible with Microsoft C.

*---------------------------------------------------------------------------*/

unsigned _RTLENTRY _EXPFUNC
_dos_setfileattr(const char *filename, unsigned attrib)
{
    if (SetFileAttributes((LPSTR)filename, (DWORD)attrib) == FALSE)
        return (__DOSerror());
    else
        return (0);
}
