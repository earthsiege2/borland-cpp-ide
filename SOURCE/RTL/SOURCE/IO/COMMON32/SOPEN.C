/*-----------------------------------------------------------------------*
 * filename - sopen.c
 *
 * function(s)
 *        sopen         - open a file for file sharing (MSC compatible)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdarg.h>
#include <_io.h>
#include <fcntl.h>

/*-----------------------------------------------------------------------*

Name            sopen - opens a file for file sharing

Usage           #include <fcntl.h>
                #include <sys\stat.h>
                #include <share.h>
                #include <io.h>

                int sopen(const char *pathname, int access, int shflag
                          [, unsigned permiss] );

Prototype in    io.h

Description     Similar to open, except that it has an extra parameter shflag,
                which specifies the file sharing mode.  This sharing mode
                can be one of the constants defined in share.h; see the
                sopen documention for a complete description.
*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC sopen(const char *pathP, int oflag, int shflag, ...)
{
    if (oflag & O_CREAT)
    {
        int ret;
        va_list ap;

        va_start(ap,shflag);
        ret = __open(pathP, oflag|shflag, va_arg(ap,unsigned int));
        va_end(ap);
        return (ret);
    }
    else
       return (__open(pathP, oflag|shflag));
}
