/*-----------------------------------------------------------------------*
 * filename - errno.c
 *
 * function(s)
 *        __errno - return address of errno for this thread
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.7.2.1 $        */

#ifdef _MT
#include <_thread.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#include <errno.h>
#include <stddef.h>             /* _threadid */

#ifndef _MT

int _RTLENTRY _EXPDATA errno = 0;                  /* error code */

#endif

/*-----------------------------------------------------------------------*

Name            __errno - return address of errno value for this thread

Usage           #include <errno.h>
                int *__errno (void);

Prototype in    errno.h

Description     This function returns the address of the integer containing
                the error code for this thread.  This integer is
                stored in the per-thread data structure allocated by
                _thread_data().

Return value    The address of the DOS error code for this thread.

*------------------------------------------------------------------------*/

#ifdef _MT

int * _RTLENTRY _EXPFUNC __errno(void)
{
    int *ret;
    DWORD winerr;

    /* Save the Win32 GetLastError value across the call to _thread_data()
       since it can corrupt the value.
    */
    winerr = GetLastError();
    ret = &_thread_data()->thread_errno;
    SetLastError(winerr);

    return ret;
}

#else

int * _RTLENTRY _EXPFUNC __errno(void)
{
    return (&errno);
}

#endif

