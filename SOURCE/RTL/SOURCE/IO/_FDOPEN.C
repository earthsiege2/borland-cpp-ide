/*-----------------------------------------------------------------------*
 * filename - _fdopen.c
 *
 * function(s)
 *        _fdopen        - associates a stream with a file handle
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <stdio.h>
#include <_stdio.h>
#include <_io.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            _tfdopen used as _fdopen and _wfdopen
                _fdopen  -  associates a stream with a file handle
                _wfdopen -  associates a stream with a file handle

Usage           FILE *_fdopen(int handle, char *type);
                FILE *_wfdopen(int handle, wchar_t *type);

Prototype in    _stdio.h (fdopen declared in stdio.h)

Description     This is the internal entry point for fdopen.
                See fopen for details.

*---------------------------------------------------------------------*/

#ifdef _UNICODE
FILE * _RTLENTRY _EXPFUNC _wfdopen (int handle, wchar_t *type)
#else
FILE * _RTLENTRY _EXPFUNC _fdopen (int handle, char *type)
#endif
{
    register FILE   *fp;

    _lock_all_streams();

    if (handle < 0)
        fp = NULL;
    else if ((fp = __getfp()) != NULL)
    {
        fp->fd = handle;
        fp = __topenfp (fp, NULL, type, 0);
    }

    _unlock_all_streams();
    return (fp);
}
