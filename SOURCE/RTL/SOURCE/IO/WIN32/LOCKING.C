/*-----------------------------------------------------------------------*
 * filename - locking.c
 *
 * function(s)
 *        locking  - sets or resets file sharing locks (MSC compatible)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_ERROR_H

#include <ntbc.h>

#include <io.h>
#include <_io.h>
#include <errno.h>
#include <sys\locking.h>

/*-----------------------------------------------------------------------*

Name            locking - sets file sharing locks

Usage           int locking(int handle, int mode, long length);

Prototype in    io.h

Description     locking provides an interface to the MS-DOS
                3.x file-sharing mechanism.  The region to be locked
                or unlocked starts at the current file position;
                the size of the region is given by length.

                The mode parameter specifies the action (values
                for mode are given in <sys\locking.h>):

                LK_LOCK         lock the region; if unsuccessful, try
                                once a second for 10 seconds before
                                giving up.
                LK_RLCK         Same as LK_LOCK.
                LK_NBLCK        lock the region, if unsuccessful, give
                                up immediately.
                LK_NBRLCK       Same as LK_NBLCK.
                LK_UNLCK        Unlock the region, which must have
                                been previously locked.

                Locks can be placed on arbitrary, non-overlapping regions of
                any file. A program attempting to read or write into a
                locked region will retry the operation three times. If all
                three retries fail, the call fails with an error.

                unlock removes lock; to avoid error, lock must be removed
                before a file is closed. A program must release all lock(s)
                before completing.

Return value    Locking return 0 on success.  On failure, -1 is returned,
                and errno is set to one of the following:

                EACCESS         File already locked or unlocked
                EBADF           Bad file number
                EDEADLOCK       File cannot be locked after 10 retries
                                (mode is LK_LOCK or LK_RLCK)
                EINVAL          Invalid mode
                

Portability     Unique to MS-DOS 3.x, NT, and OS/2. Older versions of
                MS-DOS do not support these calls.  Not available on UNIX.

Note            Compatible with Microsoft C.  Not the same as lock().


*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC locking(int fd, int mode, long length)
{
    int rc, tries, olderrno;
    long offset;
    HANDLE hf;

    _lock_handle(fd);

    /* Get current file offset, which gives the start of
     * the region to be locked or unlocked.  This also
     * verifies the file handle.
     */
    if ((offset = __lseek(fd,0L,SEEK_CUR)) == -1)
        RETURN (-1);
    hf = (HANDLE)_handles[fd];

    switch (mode)
    {
    case LK_LOCK:
    case LK_RLCK:

        /* Try 10 times, once every second, to lock the file.
         */
        olderrno = errno;                   /* save current value of errno */
        for (tries = 1; tries <= 10; tries++)
        {
            if (LockFile(hf, offset, 0, length, 0) == TRUE)
            {
                errno = olderrno;           /* restore orignal errno */
                RETURN (0);                 /* success */
            }
            __NTerror();                    /* failure - set errno */
            
            if (errno != EACCES)            /* not a locking violation? */
                    RETURN (-1);            /* return right away */
            Sleep(1000);                    /* failed - try again 1 sec later */
        }
        errno = EDEADLOCK;                  /* give up */
        rc = -1;
        break;

    case LK_NBLCK:
    case LK_NBRLCK:

        /* Lock the region, give up immediately if not sucessful.
         */
        rc = LockFile(hf, offset, 0, length, 0) == TRUE ? 0 : __NTerror();
        break;

    case LK_UNLCK:

        /* Unlock the region.
         */
        rc = UnlockFile(hf, offset, 0, length, 0) == TRUE ? 0 : __NTerror();
        break;

    default:
        errno = EINVAL;
        rc = -1;
        break;
    }

exit:
    _unlock_handle(fd);
    return (rc);
}
