/*-----------------------------------------------------------------------*
 * filename - files2.c
 *
 * variables:
 *      _openfd  - array of access modes for file/devices
 *      _pidtab  - array of process IDs for _popen and _pclose
 *      _handles - array of OS file handles
 *----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <io.h>
#include <fcntl.h>
#include <_nfile.h>

unsigned _RTLENTRY _EXPDATA _nfile = _NFILE_;

/*----------------------------------------------------------------------
 * The following external reference forces _init_handles (in handles.c)
 * to be called at startup.
 */
extern void _RTLENTRY _init_handles(void);
#pragma startup       _init_handles 4

/*---------------------------------------------------------------------*

Name            _openfd

Usage           unsigned int _openfd[];

Declaration in  _io.h

Description     array of access modes for file/devices

*---------------------------------------------------------------------*/

unsigned int _RTLENTRY _openfd[_NFILE_] =
{
        O_RDONLY | O_TEXT | O_DEVICE,
        O_WRONLY | O_TEXT | O_DEVICE,
        O_WRONLY | O_TEXT | O_DEVICE
};

/*---------------------------------------------------------------------*

Name            _pidtab

Usage           unsigned int _pidtab[];

Declaration in  _io.h

Description     array of process IDs for _popen and _pclose.

*---------------------------------------------------------------------*/

unsigned int _RTLENTRY _pidtab[_NFILE_];

/*---------------------------------------------------------------------*

Name            _handles

Usage           unsigned long _handles[];

Declaration in  _io.h

Description     array of file handles.  Given a low-level UNIX-type
                file handle, this table gives the OS file handle.
                Used on Win32, but not on OS/2.

*---------------------------------------------------------------------*/

#ifdef __WIN32__
unsigned long _RTLENTRY _handles[_NFILE_];
#endif
