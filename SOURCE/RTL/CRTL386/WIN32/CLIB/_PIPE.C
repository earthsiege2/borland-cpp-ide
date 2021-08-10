/*-----------------------------------------------------------------------*
 * filename - _pipe.c
 *
 * function(s)
 *        _pipe       - creates a pipe for reading or writing
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_ERROR_H
#include <ntbc.h>

#include <_io.h>
#include <fcntl.h>

/*-----------------------------------------------------------------------*

Name            _pipe - creates a pipe for reading or writing

Usage           #include <fcntl.h>
                int _pipe(int *phandles, unsigned int psize, int textmode);

Prototype in    io.h

Description     _pipe creates an anonymous pipe that can be used to
                pass information between processes.  The pipe is
                opened for both reading and writing.

                The read handle is returned to phandles[0], and the
                write handle is returned to phandles[1].  The program
                can use these handles in subsequent calls to read, write,
                dup, dup2, or close.  When all pipe handles are closed,
                the pipe is destroyed.

                The size of the internal pipe buffer is psize.  A recommended
                minimum value is 512 bytes.

                The translation mode is specified by textmode, as follows:

                O_BINARY        The pipe is opened in binary mode.
                O_TEXT          The pipe is opened in text mode.

                If textmode is zero, the translation mode is determined
                by the external variable _fmode.

Return value    On successful completion, _pipe returns 0 and returns
                the pipe handles to phandles[0] and phandles[1].  Otherwise
                it returns -1 and sets errno to one of the following:
                set to one of the following:

                        EMFILE  Too many open files
                        ENOMEM  Out of memory

*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _pipe(int *phandles, unsigned int psize, int textmode)
{
    HANDLE  readhandle, writehandle;
    SECURITY_ATTRIBUTES sec;    /* used only to set inheritance flag */
    int     rc;

    _lock_all_handles();

    /* Get the default translation mode from _fmode if not specified
     * by textmode.  Then, If O_BINARY is not specified, set O_TEXT.
     * Although O_TEXT is not actually used elsewhere in the library,
     * one bit must be set so that the flags will be non-zero when
     * stored in _openfd[].
     */
    if ((textmode & (O_TEXT | O_BINARY)) == 0)
        textmode |= _fmode & (O_TEXT | O_BINARY);
    if ((textmode & O_BINARY) == 0)
        textmode |= O_TEXT;

    /* Set the inheritance flag in the security attributes, unless
     * the O_NOINHERIT flag was set.
     */
    sec.nLength = sizeof(sec);
    sec.lpSecurityDescriptor = NULL;
    sec.bInheritHandle = (textmode & O_NOINHERIT) == 0;

    /* At last, we can create the pipe.
     */
    if (CreatePipe(&readhandle, &writehandle, &sec, psize) != TRUE)
        RETURN (__NTerror());

    /* Allocate file handle slots for both handles and
     * return the UNIX-style file handles to phandles[0..1].
     */
    if ((rc = _get_handle((long)readhandle, textmode)) == -1)
    {
        __IOerror(ERROR_TOO_MANY_OPEN_FILES);
        CloseHandle(readhandle);
    }
    else
    {
        phandles[0] = rc;       /* save read handle */

        if ((rc = _get_handle((long)writehandle, textmode)) == -1)
        {
            __IOerror(ERROR_TOO_MANY_OPEN_FILES);
            CloseHandle(readhandle);
            CloseHandle(writehandle);
        }
        else
        {
            phandles[1] = rc;       /* save write handle */
            rc = 0;
        }
    }

exit:
    _unlock_all_handles();

    return rc;

}
