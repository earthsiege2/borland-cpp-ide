/*-----------------------------------------------------------------------*
 * filename - _fsopen.c
 *
 * function(s)
 *        _fsopen       - opens a stream with file sharing
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
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            _tfsopen used as _fsopen and _wfsopen
                _fsopen  -  open a stream with file sharing
                _wfsopen -  open a stream with file sharing

Usage           FILE *_fsopen(const char *filename, char *type, int shflag);
                FILE *_wfsopen(const wchar_t *filename, wchar_t *type, int shflag);

Prototype in    stdio.h

Description     Similar to fopen, except that it has a third parameter,
                which specifies the file sharing mode.  This sharing mode
                can be one of the constants defined in share.h; see the
                sopen documention for a complete description.
*---------------------------------------------------------------------*/

FILE * _RTLENTRY _EXPFUNC _tfsopen (const _TCHAR *filename, 
                                    const _TCHAR *type, int shflag)
{
    register FILE   *fp;

    _lock_all_streams();

    if ((fp = __getfp()) != NULL)
        fp = __topenfp (fp, filename, type, shflag);

    _unlock_all_streams();
    return (fp);
}
