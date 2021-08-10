/*-----------------------------------------------------------------------*
 * filename - __read.c
 *
 * function(s)
 *        __removecr - remove carriage returns from a buffer
 *        __read    - read binary or text data from file
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <errno.h>
#include <_io.h>
#include <io.h>
#include <fcntl.h>
#include <string.h>

/* The following definition controls whether partial reads in text
 * mode are allowed.
 *
 * Set PARTIAL_READ to 1 to force read() to perform in
 * the traditional MSC/Borland C style, where it can return less
 * the the requested number of bytes.  This faster if the program
 * requests multiples of 512 bytes, since all read requests to the OS
 * will fall on sector boundaries.
 *
 * Set PARTIAL_READ to 0 to force read() to fill the caller's
 * buffer with the exact number of bytes requested (except at the
 * end of file or on an error).  This is slower, but is more compatible
 * with some UNIX programs, which assume that the end of file has
 * been reached when less then the requested number of bytes were read.
 */
#define PARTIAL_READ    1

/*---------------------------------------------------------------------*

Name            __removecr - remove carriage returns from a buffer

Usage           unsigned __removecr(char *buf, unsigned nbytes);

Related
functions usage unsigned __insertcr(char *src, unsigned nbytes, char *dst);

Description     This function modifies a buffer of characters in place
                by removing all carriage returns.  The function is
                called by read() when reading data from a file that was
                opened in text mode.  The buffer's address is buf,
                and the number of characters in the buffer is nbytes.

Return value    The new number of bytes in the buffer is returned.  This is
                equal to the original buffer size minus the number of
                carriage returns removed.

*---------------------------------------------------------------------*/

static unsigned __removecr(char *buf, unsigned nbytes)
{
    char *src, *dst, *end, *found;
    unsigned n;

    end = &buf[nbytes];
    src = dst = buf;
    for (;;)
    {
        if ((found = memchr(src,'\r',end-src)) == NULL)
            found = end;
        n = found - src;
        if (src != dst)
            memcpy(dst,src,n);
        if (found >= end - 1)
            return (dst - buf + n);
        src = found + 1;
        dst += n;
    }
}

/*-----------------------------------------------------------------------*

Name            __read - reads from file

Usage           int __read(int handle, void *buf, unsigned nbyte);

Prototype in    io.h

Description     __read and _rtl_read attempt to read nbyte bytes from the
                file  associated with handle into the buffer pointed to by buf.
                _rtl_read is nearly a direct call to the OS/2 DosRead system call.

                For a file opened in text mode, __read removes carriage returns.
                No such removal or reporting is performed by _rtl_read.

                handle is a file handle obtained from a creat, open, dup, dup2,
                or fcntl call.

                On disk files, these functions begin reading at the current
                file pointer. When the reading is complete, they increment the
                file pointer by the number of bytes read. On devices, the bytes
                are read directly from the device.

*------------------------------------------------------------------------*/

int _RTLENTRYF __read (int fd, void *buf, unsigned int len)
{
    int      rc;
    unsigned nread;
    unsigned total, chunk, n;
    char *bufp;

    if ((unsigned)fd >= _nfile)
        return __IOerror(-EBADF);

    if ((len + 1) < 2)
        return( 0 );  /* 0, -1 are not allowed lengths */

    _lock_handle(fd);

    /* If the file was not opened in text mode, simply read the bytes
     * without removing carriage returns.
     */
    if ((_openfd[fd] & O_TEXT) == 0)
        RETURN (_rtl_read (fd, buf, len));

    /* Check if a control-Z was previously seen (same as end of file).
     */
    if ((_openfd[fd] & _O_EOF) != 0)
        RETURN (0);

    /* Keep reading until the full number of bytes specified by the
     * the user have been stuffed into the buffer.  If PARTIAL_READ
     * is defined to be 1, then don't keep reading, but allow
     * a partial buffer.
     */
    bufp = buf;     /* type conversion */
    for (total = 0; total < len; )
    {
        char *pctlz;

        /* Read a chunk of binary bytes from the file.
         * Exit if a genuine end of file is reached.
         */
        chunk = len - total;
        if ((nread = _rtl_read(fd, bufp, chunk)) == ~0)
            RETURN (-1);
        if (nread == 0)
            break;

        /* Look for a control-Z, the end-of-file character used
         * on ancient operating systems, and unfortunately still
         * tacked onto the end of files by some editors.
         */
        if ((pctlz = memchr(bufp, 0x1a, nread)) != NULL)
        {
            _openfd[fd] |= _O_EOF;
            if ((nread = pctlz - bufp) == 0)
                break;
        }

        /* If the last byte in the buffer is a carriage return,
         * overwrite it with the next byte in the file, which must
         * be a line feed.  This avoids problems with split CR-LF
         * pairs messing up fseek() in text mode stream files.
         */
        if (bufp[nread-1] == '\r')
            if (_rtl_read(fd, &bufp[nread-1], 1) == ~0)
                RETURN (-1);

        /* Strip out the carriage returns.  Set n to the number
         * of bytes now actually in the buffer.
         */
        n = __removecr(bufp,nread);
        total += n;

        /* If inputting from a console device, or we hit a control-Z,
         * or we allow partial reads and we read at least one byte,
         * don't try to read more bytes.
         */
        if (   (nread < chunk && (_openfd[fd] & O_DEVICE) != 0)
            || pctlz != NULL
#if PARTIAL_READ
            || n != 0
#endif
           )
            break;

        bufp += n;
    }
    rc = total;

exit:
    _unlock_handle(fd);
    return (rc);

}
