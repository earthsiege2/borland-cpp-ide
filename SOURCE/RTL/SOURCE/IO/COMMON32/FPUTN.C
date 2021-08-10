/*-----------------------------------------------------------------------*
 * filename - fputn.c
 *
 * function(s)
 *      __fputn  - writes bytes on a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.5  $        */

#include <stdio.h>
#include <_stdio.h>
#include <_io.h>
#include <mem.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            __fputn - writes bytes on a stream

Usage           size_t __fputn (const _TCHAR *ptr, size_t n, FILE *fp)

Prototype in    stdio.h

Description     __fputn writes n bytes whose address is referenced by ptr to
                an open stream fp.

                WARNING: this function does NOT lock the stream semaphore.
                It assumes that the caller has performed the lock.

Return value    The number of bytes written is returned on success;
                zero is returned on failure.

*---------------------------------------------------------------------*/

size_t __fputnt( const _TCHAR *ptr, size_t n, register FILE *fp )
{
    int ret;


#if !defined(_UNICODE)
    if( fp->flags & _F_LBUF )       /* if it's line buffered or widechar, */
#endif
    {                               /* handle it in the traditional way */
        int len;
        _TCHAR *p;

        for (len = n, p = (_TCHAR *)ptr; len != 0; len--, p++ )
        {
            if( _lputtc( *p, fp ) == _TEOF )
                return( 0 );
        }

        return( n );
    }
#if !defined (_UNICODE)
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
        ret = __write( fp->fd, (void *)ptr, n );
        if( (ret == -1) || ((unsigned)ret < n ))
            return( 0 );
        else
            return( n );
    }
#endif /* _UNICODE */
}
