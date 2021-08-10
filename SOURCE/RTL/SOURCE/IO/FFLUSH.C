/*------------------------------------------------------------------------*
 * filename - fflush.c
 *
 * function(s)
 *        fflush - flushes a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <stdio.h>
#include <_stdio.h>
#include <_io.h>

/*------------------------------------------------------------------------*

Name            fflush - flushes a stream

Usage           #include <stdio.h>
                int fflush(FILE *stream);

Prototype in    stdio.h

Description     fflush causes the contents of the buffer associated with
                an open output stream to be written to stream, and clears
                the buffer contents if stream is an open input stream.
                stream remains open.

Return value    success : 0
                failure : EOF

*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC  fflush (FILE *fp)
{
    register count;
    int rc;

    if( fp == NULL )
    {
        _flushout();
        return (0);
    }

    if( fp->token != (unsigned char)fp )
        return( EOF );      /* validity check */

    _lock_stream(fp);

    if( fp->level >= 0 )                    /* no output data in buffer */
    {
        if( fp->flags & _F_LBUF ||
            fp->curp == (unsigned char*)&fp->hold )
        {
            fp->level = 0;                  /* ensure no unget char */
            if( fp->curp == (unsigned char*)&fp->hold )
            fp->curp = fp->buffer;
        }

        RETURN( 0 );
    }

    count = fp->bsize + 1 + fp->level;
    fp->level -= count;

    if( (__write( fp->fd, (fp->curp = fp->buffer), count ) != count) &&
        ((fp->flags & _F_TERM) == 0) )
    {
        fp->flags |= _F_ERR;
        RETURN( EOF );
    }

    rc = 0;

exit:
    _unlock_stream(fp);
    return (rc);
}
