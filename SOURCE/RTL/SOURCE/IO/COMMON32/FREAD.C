/*-----------------------------------------------------------------------*
 * filename - fread.c
 *
 * function(s)
 *        fread  - reads data from a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <stdio.h>
#include <string.h>
#include <_io.h>
#include <_stdio.h>

/*---------------------------------------------------------------------*

Name            _fgetn - reads data from a stream

Usage           static unsigned
                        _fgetn (register void *ptr, size_t n, FILE *fp);

Prototype in    local to this module

Description     _fgetn reads n bytes of data from the named input stream
                into a block pointed to by ptr.

Return value    success : 0
                else    : non-zero

*---------------------------------------------------------------------*/

static unsigned _fgetn( void *ptr, size_t n, FILE *fp )
{
    int Byte, Chunk;
    char *p;

    p = (char *)ptr;

    if (fp->bsize != 0)             /* file is buffered */
    {
        while( n )
        {
            /* If there is anything in the buffer, copy it directly
             * to the user's buffer.
             */
            if (fp->level != 0)         /* something in the buffer */
            {
                if (n > (unsigned)fp->level)
                    Chunk = fp->level;
                else
                    Chunk = n;

                memcpy(p,fp->curp,Chunk);
                fp->curp += Chunk;
                fp->level -= Chunk;

                if ((unsigned)Chunk == n)   /* nothing more to read */
                    return (0);

                p += Chunk;
                n -= Chunk;
            }

            /* The buffer is empty and we need to read more than a
             * complete buffer.  Read an exact multiple of the
             * buffer size directly to the user's buffer.
             * The remainder will be read into the buffer, then copied
             * to the user's buffer, the next couple of times through
             * the loop.
             */
            if (n >= (unsigned)fp->bsize)
            {
                Chunk = n - (n % fp->bsize);

                if ((unsigned)(Byte = __read(fp->fd, p, Chunk)) == n)
                    return (0);

                if (Byte == -1)
                {
                    fp->flags |= _F_ERR;
                    break;
                }

                p += Byte;
                n -= Byte;

                if( Byte != Chunk )
                {
                    /* We read less than expected.  If this is a binary
                     * file, or the number of bytes read was zero,
                     * this must be the end of file.  Otherwise keep reading.
                     */
                    if ((fp->flags & _F_BIN) != 0 || Byte == 0)
                    {
                        fp->flags |= _F_EOF;
                        break;
                    }
                    else
                        continue;
                }
            }

            /* The buffer is empty but we need to read less than
             * a complete buffer.  Do a single getc() to refill
             * the buffer.  The next time through the loop we'll
             * copy the rest of the bytes from the buffer.
             */
            if ((Byte = _lgetc(fp)) != EOF)
            {
                *p++ = (char)Byte;
                n--;
            }
            else
            {
                fp->flags |= _F_EOF;
                break;
            }
        }
    }
    else
    {
        /* The file is unbuffered.  Get the characters one-by-one
         * the hard way.
         */
        while (n && ( Byte = (int)getc (fp)) != EOF )
        {
            *p++ = (char)Byte;
            n--;
        }

        if( Byte == EOF )
            fp->flags |= _F_EOF;
    }

    return n;
}

/*---------------------------------------------------------------------*

Name            fread - reads data from a stream

Usage           #include <stdio.h>
                size_t fread(void *ptr, size_t size, size_t nitems, FILE *stream);

Related
functions usage size_t fwrite(void *ptr, size_t size, size_t nitems, FILE *stream);

Prototype in    stdio.h

Description     fread reads nitems of data, each of length size
                bytes, from the named input stream into a block pointed to by
                ptr.

                fwrite appends nitems of data, each of length size bytes, to
                the named output stream. The data appended begins at ptr.

                For both functions, the total number of bytes read is (nitems
                * size).

                ptr in the declarations is a pointer to any object.
                size is the size of the object ptr points to. The
                expression sizeof *ptr will produce the proper value.

Return value    On successful completion, each function returns the
                number of items (not bytes) actually read or written. fread
                returns a short count (possibly 0) on end-of-file or error.
                fwrite returns a short count on error.

*---------------------------------------------------------------------*/

size_t _RTLENTRY _EXPFUNC fread (void *ptr, size_t psize, size_t nitems, FILE *fp)
{
    size_t total;

    if( psize == 0 )
        return( 0 );
    total = psize * nitems;

    _lock_stream(fp);
    total -= (size_t)_fgetn( ptr, (unsigned)total, fp );
    _unlock_stream(fp);

    return( total / psize );
}
