/*---------------------------------------------------------------------------
 * filename - creatnew.c
 *
 * function(s)
 *        creatnew   - creates a new file
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_io.h>
#include <dos.h>
#include <fcntl.h>

/*--------------------------------------------------------------------------*

Name            creatnew - creates a new file

Usage           int creatnew(char *filename, int attrib);

Prototype in    io.h

Description     identical to _rtl_creat, with the exception that, if
                the file exists, the creatnew call returns an
                error and leaves the file untouched.  Also, the file
                is opened in the translation mode specified by
                the external variable _fmode, whereas _rtl_creat always
                opens the file in binary mode.

Return value    same as _rtl_creat

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC creatnew (const char *pathP, int attr)
{
    int handle;

    if (_dos_creatnew(pathP, attr, &handle) != 0)
        return (-1);
    _openfd[handle] = _FMODE & (O_TEXT | O_BINARY);
    return (handle);
}
