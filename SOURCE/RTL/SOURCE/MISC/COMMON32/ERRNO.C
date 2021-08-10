/*-----------------------------------------------------------------------*
 * filename - errno.c
 *
 * function(s)
 *        __errno - return address of errno for this thread
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#ifdef _MT
#include <_thread.h>
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
    return (&_thread_data()->thread_errno);
}

#else

int * _RTLENTRY _EXPFUNC __errno(void)
{
    return (&errno);
}

#endif

