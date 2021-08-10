/*-----------------------------------------------------------------------*
 * filename - _open.c
 *
 * function(s)
 *        _rtl_open - opens an existing file for reading or writing
 *        _open - opens an existing file for reading or writing (MS_COMPAT )
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.6.2.1 $        */

#include <fcntl.h>
#include <_io.h>
#include <_tchar.h>

#define BAD_FLAGS (O_BINARY | O_TEXT | O_APPEND | O_CREAT)

/*-----------------------------------------------------------------------*

Name            _trtl_open used as _rtl_open and _wrtl_open
                _rtl_open  - opens a file for reading or writing
                _wrtl_open - opens a file for reading or writing

Usage           #include <fcntl.h>
                int _rtl_open(const char *pathname, int access);
                int _wrtl_open(const wchar_t *pathname, int access);

Prototype in    io.h

Description     _trtl_open opens an existing file for reading or writing.
                The file is always opened in binary mode.  The allowable
                flags are:

                O_RDONLY        Open for reading only.
                O_WRONLY        Open for writing only.
                O_RDWR          Open for reading and writing.
                O_NOINHERIT     Included if the file is not to be passed to
                                child programs.
                O_DENYALL       Allows only the current handle to have access to
                                the file.
                O_DENYWRITE     Allows only reads from any other open to the
                                file.
                O_DENYREAD      Allows only writes from any other open to the
                                file.
                O_DENYNONE      Allows other shared opens to the file.

Return value    On successful completion, _trtl_open returns a non-negative
                integer (the file handle), and the file pointer
                (that marks the current position in the file) is set to the
                beginning of the file. On error, it returns -1 and errno is
                set to one of the following:

                        ENOENT  Path or file name not found
                        EMFILE  Too many open files
                        EACCES  Permission denied

*------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _trtl_open( const _TCHAR *filename, int oflag )
{
    return (___topen(filename, (oflag & ~BAD_FLAGS) | O_BINARY));
}

/*------------------------------------------------------------------------*/


/* _open() is an MS-COMPAT function.  It is identical to our open() function
   which goes straight to __open().
*/

int _RTLENTRYF _EXPFUNC __topen( const _TCHAR *filename, int oflag )
{
   return( ___topen(filename, oflag) );
}
