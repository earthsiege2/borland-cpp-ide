/*---------------------------------------------------------------------------
 * filename - __dup.c
 *
 * function(s)
 *        __dup  - duplicate a file handle
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#define INCL_ERROR_H

#include <ntbc.h>

#include <io.h>
#include <_io.h>

/*--------------------------------------------------------------------------*

Name            __dup - duplicate a file handle

Usage           int   __dup(int handle);

Prototype in    io.h

Description     __dup returns a new file handle that has the
                following in common with the original file handle:

                    . same open file or device
                    . same file pointer(that is, changing the file pointer of
                      one changes th other
                    . same access mode(read,write,read/write)

                __dup returns the next file handle available.

Return value    Upon successful completion, __dup returns the new file handle,
                Otherwise it returns -1.

                In the event of an error, errno is set to one of the
                following:
                    EMFILE  Too many open files
                    EBADF   Bad file number

*---------------------------------------------------------------------------*/

int _RTLENTRY __dup (int oldfd)
{
    return __dup2(oldfd, -1);
}
