/*-----------------------------------------------------------------------*
 * filename - fputn.c
 *
 * function(s)
 *      __fputn  - writes bytes on a stream
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
#include <_io.h>
#include <mem.h>

/*---------------------------------------------------------------------*

Name            __fputn - writes bytes on a stream

Usage           size_t __fputn (const void *ptr, size_t n, FILE *fp)

Prototype in    stdio.h

Description     __fputn writes n bytes whose address is referenced by ptr to
                an open stream fp.

                WARNING: this function does NOT lock the stream semaphore.
                It assumes that the caller has performed the lock.

Return value    The number of bytes written is returned on success;
                zero is returned on failure.

*---------------------------------------------------------------------*/

size_t __fputn( const void *ptr, size_t n, register FILE *fp )
{

    if( fp->flags & _F_LBUF )       /* if it's line buffered, */
    {                               /* handle it in the traditional way */
        int len;
        char *p;

        for (len = n, p = (char *)ptr; len != 0; len--, p++ )
        {
            if( _lputc( *p, fp ) == EOF )
                return( 0 );
        }

        return( n );
    }
    else if (fp->bsize && n <= (unsigned)fp->bsize)   /* buffer big enough? */
    {
        if( fp->level + (int)n >= 0 )  /* must we flush it to make room? */
        {
            if( fp->level == 0 )
            {
                fp->level = -1 - fp->bsize;
            }
            else
            {
                if( fflush( fp ) )
                    return( 0 );
            }
        }

        /* stuff it into the file buffer all at once! */
        memcpy( fp->curp, ptr, n );
        fp->level += n;
        fp->curp += n;

        return( n );
    }
    else            /* it is unbuffered or buffer is too small */
    {
        if (fp->bsize && fp->level)     /* something in the buffer? */
        {
            if( fflush( fp ) )
                return( 0 );
        }

        /* write it all at once! */
        if( (unsigned)__write( fp->fd, (void *)ptr, n ) < n )
            return( 0 );
        else
            return( n );
    }
}
