/*-----------------------------------------------------------------------*
 * filename - lock1.c
 *
 * function(s)
 *        lock   - sets file sharing locks
 *        unlock - resets file sharing locks
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */


#include <_io.h>

/*-----------------------------------------------------------------------*

Name            lock - sets file sharing locks

Usage           int lock(int handle, long offset, long length);

Related
functions usage int unlock(int handle, long offset, long length);

Prototype in    io.h

Description     lock and unlock provide an interface to the MS-DOS
                3.x file-sharing mechanism.

                lock can be placed on arbitrary, non-overlapping regions of
                any file. A program attempting to read or write into a
                locked region will retry the operation three times. If all
                three retries fail, the call fails with an error.

                unlock removes lock; to avoid error, lock must be removed
                before a file is closed. A program must release all lock(s)
                before completing.

Return value    Both functions return 0 on success, -1 on error.

Portability     Unique to MS-DOS 3.x. Older versions of MS-DOS do
                not support these calls.

*------------------------------------------------------------------------*/
int lock(int handle, long offset, long length)
{
    return (_dos_lock(handle, offset, length) == 0 ? 0 : -1);
}

/*-----------------------------------------------------------------------*

Name            unlock - resets file sharing locks

Usage           int unlock(int handle, long offset, long length);

Related
functions usage int lock(int handle, long offset, long length);

Prototype in    io.h

Description     see lock above

Return value    Both functions return 0 on success, -1 on error.

*------------------------------------------------------------------------*/
int unlock(int handle, long offset, long length)
{
    return (_dos_unlock(handle, offset, length) == 0 ? 0 : -1);
}
