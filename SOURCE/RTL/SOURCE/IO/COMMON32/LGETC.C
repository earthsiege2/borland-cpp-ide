/*-----------------------------------------------------------------------*
 * filename - fgetc.c
 *
 * function(s)
 *    FlushOutStreams - flushes output streams
 *    _ffill      - fill up the read-ahead buffer
 *    _lgetc      - gets character from stream without locking 
 *                  (multi-thread only)
 *    fgetc       - gets character from stream with locking 
 *                  (single-thread only)
 *    _fgetc      - gets character from stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_stdio.h>
#include <_io.h>

/*---------------------------------------------------------------------*

Name            FlushOutStreams - flushes output streams

Usage           static  void FlushOutStreams(void);

Description     flushes all open output streams

Return value    nothing

*---------------------------------------------------------------------*/

static void FlushOutStreams( void )
{
    register FILE *fp;
    register int  Ndx;

    for( Ndx = FOPEN_MAX, fp = _streams; Ndx--; fp++ )
        {
        if( (fp->flags & (_F_TERM | _F_OUT)) == (_F_TERM | _F_OUT) )
            fflush( fp );
        }
}


/*---------------------------------------------------------------------*

Name        _ffill - fill up the read-ahead buffer

Usage       static  int _ffill  (FILE *fp)

Description Fill up the read-ahead buffer.  Trusts caller to have checked
            permission to read before calling.  However, we do check
            for invalid pointers here, since there is no noticeable
            performance cost and it catches trouble before it causes too
            much damage.

Return value    -1 <carry set> if error,
                zero <no carry> if correct.

*---------------------------------------------------------------------*/

static int _ffill( FILE *fp )
{
    if( fp->flags & _F_TERM )
        FlushOutStreams();

    if( (fp->level = __read( fp->fd, (fp->curp = fp->buffer), fp->bsize) ) > 0)
    {
        fp->flags &= ~_F_EOF;
        return 0;
    }
    else
    {
        if( !fp->level )
            fp->flags = (fp->flags & ~(_F_IN | _F_OUT)) | _F_EOF;
        else
        {
            fp->level = 0;
            fp->flags |= _F_ERR;
        }
    }

    return -1;
}


/*---------------------------------------------------------------------*

Name            _fgetc - gets character from stream

Usage           int _fgetc(FILE *stream);

Prototype in    stdio.h

Description     this function is only called by the getc() macro. The
                only purpose for this is to increment the level
                indicator before calling fgetc().

Return value    the character read, after converting it to an int
                without sign extension.  On end-of-file or error,
                fgetchar returns EOF

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _fgetc( register FILE *fp )
{
    ++fp->level;

    return( fgetc( fp ) );
}


/*---------------------------------------------------------------------*

Name            _lgetc - gets character from stream without locking

Usage           int _lgetc(FILE *stream);

Prototype in    stdio.h

Description     behaves exactly like getc, except that it is a true
                function while getc is a macro.  It does NOT lock
                the semaphore for the stream.

Return value    the character read, after converting it to an int
                without sign extension.  On end-of-file or error,
                returns EOF

*---------------------------------------------------------------------*/

#ifdef _MT
int _lgetc( register FILE  *fp )
#else
int _RTLENTRY _EXPFUNC fgetc (FILE  *fp)
#endif
{
    static unsigned char    c;

    if( fp == NULL)
        return( EOF );

    if( fp->level > 0 )
    {
        --fp->level;
        return( (unsigned char)(*fp->curp++) );
    }

    if( fp->level < 0 || fp->flags & (_F_OUT | _F_ERR) || !(fp->flags & _F_READ) )
    {
        fp->flags |= _F_ERR;
        return( EOF );          /* file is in writing mode  */
    }

    fp->flags |= _F_IN;

    if( fp->bsize != 0 )        /* is the stream buffered ? */
    {
        if( _ffill( fp ) )
            return( EOF );
        --fp->level;
        return( (unsigned char)(*fp->curp++) );
    }
    else                /* an unbuffered stream */
    {
        if( fp->flags & _F_TERM )
            FlushOutStreams();

        if( !__read( fp->fd, &c, 1 ) )
        {
            if( __eof( fp->fd ) != 1 )
                fp->flags |= _F_ERR;
            else
                fp->flags = (fp->flags & ~(_F_IN | _F_OUT)) | _F_EOF;

            return( EOF );
        }
        fp->flags &= ~_F_EOF;
        return( (unsigned char) c);
    }
}
