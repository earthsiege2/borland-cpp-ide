/*---------------------------------------------------------------------------
 * filename - __eof.c
 *
 * function(s)
 *        __eof - detects end-of-file
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <errno.h>
#include <fcntl.h>
#include <io.h>
#include <_io.h>

/*--------------------------------------------------------------------------*

Name            __eof - detects end-of-file

Usage           int __eof(int handle);

Prototype in    _io.h

Description     determines whether the file associated with handle has
                reached end-of-file

Return value    1 on end of file; otherwise 0.  A return value of -1
                indicates an error; and errno is set to:

                        EBADF  Bad file number

*---------------------------------------------------------------------------*/

int _RTLENTRY __eof(int fd)
{
    int     rc;
    long    endPosn, curPosn;

    if ((unsigned)fd >= _nfile)
        return __IOerror(-EBADF);

    _lock_handle(fd);

    /* If Control-Z has been previously detected by __read(),
     * report an EOF.
     */
    if (_openfd[fd] & _O_EOF)
        RETURN(1);

    /* If this is a character device, never get an EOF.
     */
    if ((_openfd[fd] & O_DEVICE) != 0)
        RETURN (0);

    /* Save current file position.
     */
    if ((curPosn = __lseek(fd,0L,SEEK_CUR)) == -1L)
        RETURN (-1);        /* __lseek sets errno and _doserrno */

    /* Get ending file position.
     */
    if ((endPosn = __lseek(fd,0L,SEEK_END)) == -1L)
        RETURN (-1);        /* __lseek sets errno and _doserrno */

    /* Restore current file position.
     */
    if (__lseek(fd,curPosn,SEEK_SET) == -1L)
        RETURN (-1);        /* __lseek sets errno and _doserrno */

    rc = curPosn >= endPosn;

exit:
    _unlock_handle(fd);
    return (rc);
}
