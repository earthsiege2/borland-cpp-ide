/*-----------------------------------------------------------------------*
 * filename - __write.c
 *
 * function(s)
 *        __write    - writes to a file
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1998, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.8.2.1 $        */

#include <errno.h>
#include <_io.h>
#include <io.h>
#include <fcntl.h>
#include <string.h>

#define  SIZE 511            /* size of buffer used to expand newlines */


/*---------------------------------------------------------------------*

Name            __write - writes to a file

Usage           int __write(int handle, void *buf, unsigned nbyte);

Prototype in    io.h

Description     This function writes a buffer of data to the file or device
                named by the given handle.

                handle is a file handle obtained from a creat, open, dup,
                dup2, or fcntl call.

                This function attempts to write nbyte bytes from the buffer
                pointed to by buf to the file associated with handle. Except
                when __write is used to write to a text file, the number of
                bytes written to the file will be no more than the number
                requested.

                On text files, when __write sees a linefeed (LF) character, it
                outputs a CR-LF pair.

                If the number of bytes actually written is less than that
                requested, the condition should be considered an error and
                probably indicates a full disk.

                For disk or diskette files, writing always proceeds from the
                current file pointer (see lseek). For devices, bytes are
                directly sent to the device.

                For files opened with the O_APPEND option, the file pointer is
                positioned to EOF by __write before writing the data.

Return value    The number of bytes written. A write to a text file does not
                count generated carriage returns. In case of error, each
                function returns -1 and sets the global variable errno to
                one of the following:

                        EACCES  Permission denied
                        EBADF   Bad file number

*---------------------------------------------------------------------*/
int _RTLENTRY _EXPFUNC __write(int fd, void *buf, unsigned int len)
{
    int         rc;
    unsigned    skip_cr, charsout, res;
    char        c, *p, *q;
    char        crbuf [SIZE +1];

    if ((unsigned)fd >= _nfile)
        return __IOerror(-EBADF);

    if ((len +1) < 2)
        return (0);       /* can't write 0 or -1 bytes */

    _lock_handle(fd);

    if (_openfd[fd] & O_APPEND)
        __lseek (fd, 0L, SEEK_END);

    /* If the file was not opened in text mode, simply write the bytes
     * without expanding carriage returns.
     */
    if ((_openfd[fd] & O_TEXT) == 0)
        RETURN (_rtl_write (fd, buf, len));

    /* Expand the carriage returns into CR/LF pairs.
     */

    p = buf;
    skip_cr = 0;
    charsout = 0;

    while ((unsigned)(p - (char *)buf) < len)
    {
        q = crbuf;

        /* Fill up the small crbuf until full, translating
           LFs into CR/LFs.  The buffer is purposely one byte
           longer than the max we'll use, in case the last byte
           is an LF and must be translated.
         */
        while (((q - crbuf) < SIZE) &&
               ((unsigned)(p - (char *)buf) < len))
        {
            c = *p++;
            if (c == '\n')
            {
                /* when we hit a LF, write out a CR/LF */
                skip_cr++;
                *q++ = '\r';
                *q++ = '\n';
            }
            else
                *q++ = c;
        }

        /* Now sent the buffer out to the low level writer */

        res = _rtl_write (fd, crbuf, (q - crbuf));

        if (res != (unsigned)(q - crbuf))
        {
            RETURN ((res == ~0U) ? -1 : (charsout - skip_cr) + res);
        }
        charsout += res;
    }
    rc = charsout - skip_cr;
exit:
    _unlock_handle(fd);
    return (rc);
}

