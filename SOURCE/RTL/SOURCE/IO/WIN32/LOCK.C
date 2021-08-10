/*-----------------------------------------------------------------------*
 * filename - lock.c
 *
 * function(s)
 *        lock   - sets file sharing locks
 *        unlock - resets file sharing locks
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_ERROR_H

#include <ntbc.h>

#include <io.h>
#include <_io.h>
#include <errno.h>

/*-----------------------------------------------------------------------*

Name            lock - sets file sharing locks

Usage           int lock(int handle, long ofs, long length);

Related
functions usage int unlock(int handle, long ofs, long length);

Prototype in    io.h

Description     lock and unlock provide an interface to the WinNT
                file-sharing mechanism.

                lock can be placed on arbitrary, non-overlapping regions of
                any file. A program attempting to read or write into a
                locked region will retry the operation three times. If all
                three retries fail, the call fails with an error.

                unlock removes lock; to avoid error, lock must be removed
                before a file is closed. A program must release all lock(s)
                before completing.

Return value    Both functions return 0 on success, -1 on error.

Portability     Unique to MS-DOS 3.x, OS/2, and NT. Older versions of
                MS-DOS do not support these calls.

*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC lock(int handle, long ofs, long length)
{
    int rc;

    if ((unsigned)handle >= _nfile)
        return __IOerror(ERROR_INVALID_HANDLE);
    _lock_handle(handle);
    if (LockFile((HANDLE)_handles[handle], ofs, 0, length, 0) != TRUE)
        rc = __NTerror();
    else
        rc = 0;
    _unlock_handle(handle);
    return (rc);
}


/*-----------------------------------------------------------------------*

Name            unlock - resets file sharing locks

Usage           int unlock(int handle, long ofs, long length);

Related
functions usage int lock(int handle, long ofs, long length);

Prototype in    io.h

Description     see lock above

Return value    Both functions return 0 on success, -1 on error.

*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC unlock(int handle, long ofs, long length)
{
    int rc;

    if ((unsigned)handle >= _nfile)
        return __IOerror(ERROR_INVALID_HANDLE);
    _lock_handle(handle);
    if (UnlockFile((HANDLE)_handles[handle], ofs, 0, length, 0) != TRUE)
        rc = __NTerror();
    else
        rc = 0;
    _unlock_handle(handle);
    return (rc);
}
