/*-----------------------------------------------------------------------*
 * filename - truncate.c
 *
 * function(s)
 *        _truncate - truncate a file
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <fcntl.h>
#include <sys/types.h>
#include <io.h>
#include <_io.h>

/*---------------------------------------------------------------------*

Name            _truncate - truncate an open file

Usage           #include <sys/types.h>
                #include <sys/io.h>
                int _truncate(const char *path, off_t size);

Prototype in    io.h

Description     This function truncates the file 'path' to the
                length specified by 'size'.  If the file is currently
                shorter than 'size', it is extended with zeroes;
                otherwise it is shortened to the new length.

Return value    If successful, 0 is returned.  Otherwise -1 is returned
                and errno is set as follows:

                ENOENT      File does not exist
                EACCESS     Permission denied
                EINVAL      Size is negative

*---------------------------------------------------------------------*/

int _RTLENTRY _truncate(const char *path, off_t size)
{
    int fd;

    if ((fd = __open(path, O_WRONLY)) == -1)
        return -1;
    if (__ftruncate(fd, size) == -1)
        return -1;
    __close(fd);
    return 0;
}
