/*-----------------------------------------------------------------------*
 * filename - sopen.c
 *
 * function(s)
 *        _sopen         - open a file for file sharing (MSC compatible)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4 $        */

#include <stdarg.h>
#include <_io.h>
#include <fcntl.h>
#include <_tchar.h>

/*-----------------------------------------------------------------------*

Name            _tsopen used as _sopen and _wsopen
                _sopen   - opens a file for file sharing
                _wsopen - opens a file for file sharing

Usage           #include <fcntl.h>
                #include <sys\stat.h>
                #include <share.h>
                #include <io.h>

                int _sopen(const char *pathname, int access, int shflag
                          [, unsigned permiss] );
                int _wsopen(const wchar_t *pathname, int access, int shflag
                          [, unsigned permiss] );

Prototype in    io.h

Description     Similar to open, except that it has an extra parameter shflag,
                which specifies the file sharing mode.  This sharing mode
                can be one of the constants defined in share.h; see the
                _sopen documention for a complete description.
*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _tsopen(const _TCHAR *pathP, int oflag, int shflag, ...)
{
    if (oflag & O_CREAT)
    {
        int ret;
        va_list ap;

        va_start(ap,shflag);
        ret = ___topen(pathP, oflag|shflag, va_arg(ap,unsigned int));
        va_end(ap);
        return (ret);
    }
    else
       return (___topen(pathP, oflag|shflag));
}
