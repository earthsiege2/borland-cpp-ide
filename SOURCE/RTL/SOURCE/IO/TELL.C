/*-----------------------------------------------------------------------*
 * filename - tell.c
 *
 * function(s)
 *        tell - gets current position of file pointer
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <io.h>
#include <_io.h>

/*---------------------------------------------------------------------*

Name            tell - gets current position of file pointer

Usage           long tell(int handle);

Prototype in    io.h

Description     gets the current position of the file pointer associated
                with handle and expresses it as the number of bytes from
                the beginning of the file.

Return value    the current file pointer position.  A return of -1L
                indicates an error, and errno is set to:

                        EBADF   Bad file number

*---------------------------------------------------------------------*/

long _RTLENTRY _EXPFUNC tell(int handle)
{
        return (__lseek (handle, 0L, SEEK_CUR));
}
