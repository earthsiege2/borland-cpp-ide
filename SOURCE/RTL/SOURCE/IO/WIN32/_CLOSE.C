/*---------------------------------------------------------------------------
 * filename - _close.c
 *
 * function(s)
 *        _rtl_close - close a file handle             
 *        _close     - close a file handle ( obsolete )
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_io.h>
#include <io.h>

/*--------------------------------------------------------------------------*

Name            _rtl_close - close a file handle

Usage           int _rtl_close(int handle);

Prototype in    io.h

Description     _rtl_close closes the  file handle indicated by handle  which is
                obtained  from a  _creat, creat,  creatnew, creattemp, dup,
                dup2, _rtl_open or open call.

Return value    Upon  successful completion,  close returns  0 otherwise,  a
                value of  -1 is returned  and, errno is  set to
                        EBADF   Bad file number

*---------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _rtl_close (int fd)
{
    return (__close(fd));
}

int _RTLENTRYF _EXPFUNC _close (int fd)
{
    return (__close(fd));
}

