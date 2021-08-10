/*-----------------------------------------------------------------------*
 * filename - _umask.c
 *
 * function(s)
 *    _umask - set file read/write permission mask
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <io.h>

unsigned    _notUmask = ~0;

/*---------------------------------------------------------------------*

Name            _umask - set file read/write permission mask

Usage           #include <io.h>
                unsigned  _umask(unsigned modeMask)

Prototype in    _io.h

Description     Changes the read/write permission mask used for "open"
                and "creat" calls.

Return value    The replaced value of the umask.  There is no error return.

Note            "umask" is stored internally in inverted form, for convenience.

                This function is the internal version of umask(), which
                is declared in io.h

*---------------------------------------------------------------------*/

unsigned _RTLENTRY _umask(unsigned modeMask)
{
    register    oldMask;

    oldMask = ~_notUmask;
    _notUmask = ~modeMask;
    return (oldMask);
}
