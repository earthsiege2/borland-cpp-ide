/*-----------------------------------------------------------------------*
 * filename - __wread.c
 *
 * function(s)
 *        __wread    - read binary or text data from file
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1996, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $*/

#define  _UNICODE

#include <stdlib.h>
#include <errno.h>
#include <_io.h>
#include <io.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>

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
 * been reached when less then the requested number of wide_characters were read.
 */
#define PARTIAL_READ    1

/*-----------------------------------------------------------------------*

Name            __wread - reads wide characters from file

Usage           int __wread(int handle, void *buf, unsigned nchars);

Prototype in    _io.h

Description     __wread attempts to read nchars wchar_t's from
                the file associated with handle into the buffer pointed to
                by buf.

                For a file opened in text mode, __wread removes carriage returns.

                Files opened in text mode and read as wide characters are
                assumed to be stored in multibyte format.

                handle is a file handle obtained from a creat, open, dup, dup2,
                or fcntl call.

                On disk files, this function begins reading at the current
                file pointer. When the reading is complete, it increments the
                file pointer by the number of bytes read. On devices, the bytes
                are read directly from the device.

*------------------------------------------------------------------------*/
int _RTLENTRYF __wread (int fd, void *buf, unsigned int len)
{
    int      rc;
    unsigned total, nread, chunk;
    wchar_t *bufp;
    char     czbuf [MB_LEN_MAX];
    char     crbuf [MB_LEN_MAX];
    char     eolbuf [MB_LEN_MAX];

    if ((unsigned)fd >= _nfile)
        return __IOerror(-EBADF);

    if ((len + 1) < 2)
        return( 0 );  /* 0, -1 are not allowed lengths */

    _lock_handle(fd);

    /* If the file was not opened in text mode, simply read the bytes
     * without removing carriage returns.
     */
    if ((_openfd[fd] & O_TEXT) == 0)
        RETURN (_rtl_read (fd, buf, len*sizeof(wchar_t))/sizeof(wchar_t));

    /* Check if a control-Z was previously seen (same as end of file).
     */
    if ((_openfd[fd] & _O_EOF) != 0)
        RETURN (0);

    /* Keep reading until the full number of bytes specified by the
     * the user have been stuffed into the buffer.  If PARTIAL_READ
     * is defined to be 1, then don't keep reading, but allow
     * a partial buffer.
     */
    wctomb(czbuf, (wchar_t)0x1a);
    wctomb(crbuf, L'\r');
    wctomb(eolbuf, L'\n');
    bufp = buf;     /* type conversion */
    for (total = 0; total < len; )
    {
        char  mbbuf[MB_LEN_MAX];
        char  mbcount;
        int   nbytes;

        /* Read one byte at a time till valid multibyte.
         * Convert to wide char. Keep going till chunk
         * wide chars are read.
         * Exit if a genuine end of file is reached.
         */
        mbcount = 0;
        nread = 0;
        chunk = len - total;
        while (nread < chunk)
        {
            if ((nbytes = _rtl_read(fd, mbbuf+mbcount, 1)) == ~0)
                RETURN (-1);
            if (nbytes == 0)
                break;
            mbcount++;
            nbytes = mbtowc(bufp, mbbuf, mbcount);
            if (nbytes >= 0)
            {
                mbcount = 0;

                /* nbytes will be zero for the zero character */
                if (nbytes)
                {
                  /* Do we have a control-z */
                  if (0 == memcmp(czbuf, mbbuf, nbytes))
                  {
                      _openfd[fd] |= _O_EOF;
                      break;
                  }
                  /* Do we have a carriage return which we skip */
                  if (0 == memcmp(crbuf, mbbuf, nbytes))
                      continue;

                  /* Check for console device and a line feed */
                  if(0 ==memcmp(eolbuf, mbbuf, nbytes))
                      if ((_openfd[fd] & O_DEVICE) != 0)
                      {
                          nread++;
                          break;
                      }
                }
                bufp++;
                nread++;
            }
            else if (mbcount >= MB_LEN_MAX)
                break;
        }
        if (mbcount != 0)
            RETURN (__IOerror(-EINVDAT));
        total += nread;
        if (nbytes == 0)
            break;

        /* If inputting from a console device, or we hit a control-Z,
         * or we allow partial reads and we read at least one byte,
         * don't try to read more bytes.
         */
        if (   (nread < chunk && (_openfd[fd] & O_DEVICE) != 0)
            || (_openfd[fd] & _O_EOF) != 0
#if PARTIAL_READ
            || nread != 0
#endif
           )
            break;
    }
    rc = total;

exit:
    _unlock_handle(fd);
    return (rc);

}

