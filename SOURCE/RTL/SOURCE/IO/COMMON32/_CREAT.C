/*---------------------------------------------------------------------------
 * filename - _creat.c
 *
 * function(s)
 *        _rtl_creat - creates a new file or rewrites an existing one.
 *        _creat     - ( obsolete )
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#define INCL_ERROR_H
#include <ntbc.h>

#include <_io.h>
#include <dos.h>
#include <fcntl.h>
#include <_tchar.h>

/*--------------------------------------------------------------------------*

Name            _trtl_creat used as _rtl_creat and _wrtl_creat
                _rtl_creat  - creates a new file or rewrites an existing one.
                _wrtl_creat - creates a new file or rewrites an existing one.

Usage           int _rtl_creat(const char *filename, int attrib);
                int _wrtl_creat(const wchar_t *filename, int attrib);

Prototype in    io.h

Description     _trtl_creat accepts attrib, an OS/2 attribute word.  Any
                attribute bits may be set with this call.  The file
                is always opened in binary mode.  Upon successful
                creation, the file pointer is set to the beginning
                of the file.  The file is opened for both reading
                and writing.

                The attrib argument to _trtl_creat, creatnew, and creattemp
                can be one of the following constants (defined in dos.h):

                        FA_RDONLY   Read only attribute
                        FA_HIDDEN   Hidden file
                        FA_SYSTEM   System file

Return value    success : the new file handle
                else    : -1 and errno is set to one of the following:

                        ENOENT   Path or file name not found
                        EMFILE   Too many open files
                        EACCESS  Permission denied

*---------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _trtl_creat (const _TCHAR *pathP, int attr)
{
    int handle;

    if (_tDosCreate((_TCHAR*)pathP, attr, &handle, CREATE_ALWAYS) != 0)
        return (-1);
    _openfd[handle] = O_BINARY;
    return (handle);
}

#ifndef _UNICODE

/* obsolete version */
int _RTLENTRYF _EXPFUNC _creat (const char *pathP, int attr)
{
   return _rtl_creat(pathP,attr);
}

#endif

