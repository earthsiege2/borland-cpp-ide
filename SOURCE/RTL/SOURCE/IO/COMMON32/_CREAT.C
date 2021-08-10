/*---------------------------------------------------------------------------
 * filename - _creat.c
 *
 * function(s)
 *        _rtl_creat - creates a new file or rewrites an existing one.
 *        _creat     - ( obsolete )
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_io.h>
#include <dos.h>
#include <fcntl.h>

/*--------------------------------------------------------------------------*

Name            _rtl_creat - creates a new file or rewrites an existing
                         one.

Usage           int _rtl_creat(const char *filename, int attrib);

Prototype in    io.h

Description     _rtl_creat accepts attrib, an OS/2 attribute word.  Any
                attribute bits may be set with this call.  The file
                is always opened in binary mode.  Upon successful
                creation, the file pointer is set to the beginning
                of the file.  The file is opened for both reading
                and writing.

                The attrib argument to _rtl_creat, creatnew, and creattemp
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

int _RTLENTRYF _EXPFUNC _rtl_creat (const char *pathP, int attr)
{
    int handle;

    if (_dos_creat(pathP, attr, &handle) != 0)
        return (-1);
    _openfd[handle] = O_BINARY;
    return (handle);
}

/* obsolete version */
int _RTLENTRYF _EXPFUNC _creat (const char *pathP, int attr)
{
   return _rtl_creat(pathP,attr);
}

