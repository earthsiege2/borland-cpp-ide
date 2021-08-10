/*-----------------------------------------------------------------------*
 * filename - __write.c
 *
 * function(s)
 *        __insertcr - copy a buffer, inserting carriage returns
 *        __write    - writes to a file
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <errno.h>
#include <_io.h>
#include <io.h>
#include <fcntl.h>
#include <string.h>

#define  SIZE 128           /* size of buffer used to expand newlines */

/*---------------------------------------------------------------------*

Name            __insertcr - copy a buffer, inserting carriage returns

Usage           unsigned __insertcr(char *src, unsigned *srcsize,
                   char *dst, unsigned dstsize);

Related
functions usage unsigned __removecr(char *buf, unsigned srcsize);

Description     This function copies the characters in the buffer 'src'
                to the buffer 'dst', replacing all line feeds in 'src'
                to carriage return/line feed pairs in 'dst'.  The number
                of bytes in 'src' to copy is '*srcsize'.  The number of
                bytes in the 'dst' buffer is 'dstsize'.  The function is
                called by write() when writing data to a file that was
                opened in text mode.  Upon return, *srcsize is set
                to the number of bytes from the src buffer actually
                copied.

Return value    The number of bytes written to 'dst' is returned.  This is
                equal to the number of bytes copied from 'src' (stored in
                *srcsize) plus the number of carriage returns inserted.

*---------------------------------------------------------------------*/

static unsigned
__insertcr(char *src, unsigned *srcsize, char *dst, unsigned dstsize)
{
    char *srcend, *dstend, *found;
    unsigned n, total;

    srcend = &src[*srcsize];
    dstend = &dst[dstsize];
    total = *srcsize = 0;
    for (;;)
    {
        /* Look for a line feed.  If not found, try to copy the
         * remainder of the source buffer.
         */
        if ((found = memchr(src, '\n', srcend - src)) == NULL)
            n = srcend - src;
        else
            n = found - src;

        /* If there are more bytes than will fit in the destination buffer,
         * only copy those that will fit, then return.
         */
        if (n > (unsigned)(dstend - dst))
        {
            n = dstend - dst;
            memcpy(dst,src,n);
            *srcsize += n;
            return (total + n);
        }

        /* Copy the line without the terminating newline character.
         * Return if the destination buffer isn't big enough to
         * hold a CR/LF pair, or if a newline wasn't found.
         */
        memcpy(dst,src,n);
        dst += n;
        if (!found || dstend - dst < 2)
        {
            *srcsize += n;
            return (total + n);
        }

        /* It's a normal LF-terminated line, and there's room
         * to insert a CR/LF pair.
         */
        *dst++    = '\r';
        *dst++    = '\n';
        total    += n + 2;
        src      += n + 1;
        *srcsize += n + 1;
    }
}

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

int _RTLENTRYF __write(int fd, void *buf, unsigned int len)
{
    int         rc;
    unsigned    nsrc, ndst, res, slen;
    char        *sbuf;
    char        crbuf [SIZE];

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
    for (sbuf = buf, slen = len; slen > 0; sbuf += nsrc, slen -= nsrc)
    {   
        nsrc = slen;
        ndst = __insertcr(sbuf,&nsrc,crbuf,sizeof(crbuf));
        if ((res = _rtl_write(fd, crbuf, ndst)) != ndst)
            RETURN (res == ~0U ? -1 : (sbuf - (char *)buf) + res);
    }
    rc = len;

exit:
    _unlock_handle(fd);
    return (rc);
}
