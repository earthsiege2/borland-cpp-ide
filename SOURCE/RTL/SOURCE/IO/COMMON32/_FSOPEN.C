/*-----------------------------------------------------------------------*
 * filename - _fsopen.c
 *
 * function(s)
 *        _fsopen       - opens a stream with file sharing
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_stdio.h>

/*---------------------------------------------------------------------*

Name            _fsopen -  open a stream with file sharing

Usage           FILE *_fsopen(const char *filename, char *type, int shflag);

Prototype in    stdio.h

Description     Similar to fopen, except that it has a third parameter,
                which specifies the file sharing mode.  This sharing mode
                can be one of the constants defined in share.h; see the
                sopen documention for a complete description.
*---------------------------------------------------------------------*/

FILE * _RTLENTRY _EXPFUNC _fsopen (const char *filename, const char *type, int shflag)
{
    register FILE   *fp;

    _lock_all_streams();

    if ((fp = __getfp()) != NULL)
        fp = __openfp (fp, filename, type, shflag);

    _unlock_all_streams();
    return (fp);
}
