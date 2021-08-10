/*-----------------------------------------------------------------------*
 * filename - lgetc.c
 *
 * function(s)
 *    FlushOutStreams - flushes output streams
 *    _ffill      - fill up the read-ahead buffer
 *    _lgetc      - gets character from stream without locking
 *                  (multi-thread only)
 *    _fgetc      - gets character from stream with locking
 *                  (single-thread only)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#include <stdio.h>
#include <_stdio.h>
#include <_io.h>
#include <ctype.h>
#include <_tchar.h>

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

Name        _tffill used as _ffill and _wffill
            _ffill  - fill up the read-ahead buffer
            _wffill - fill up the (wide) read-ahead buffer

Usage       static  int _ffill  (FILE *fp)
            static  int _wffill  (FILE *fp)

Description Fill up the read-ahead buffer.  Trusts caller to have checked
            permission to read before calling.  However, we do check
            for invalid pointers here, since there is no noticeable
            performance cost and it catches trouble before it causes too
            much damage.

Return value    -1 <carry set> if error,
                zero <no carry> if correct.

*---------------------------------------------------------------------*/

static int _tffill( FILE *fp )
{
    if( fp->flags & _F_TERM )
        FlushOutStreams();

    fp->level = __tread( fp->fd, (fp->curp = fp->buffer), fp->bsize/sizeof(_TCHAR));
    fp->level *= sizeof(_TCHAR);
    if( fp->level > 0)
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

Name            __fgettc used as _fgetc and _fgetwc
                _fgetc  - gets character from stream
                _fgetwc - gets (wide) character from stream

Usage           int _fgetc(FILE *stream);
                wint_t _fgetwc(FILE *stream);

Prototype in    stdio.h

Description     this function is only called by the getc() macro. The
                only purpose for this is to increment the level
                indicator before calling fgetc().

Return value    the character read, after converting it to an int
                without sign extension.  On end-of-file or error,
                _fgetc returns EOF

*---------------------------------------------------------------------*/

_TINT _RTLENTRY _EXPFUNC __fgettc( register FILE *fp )
{
    fp->level += sizeof(_TCHAR);

    return( _fgettc( fp ) );
}


/*---------------------------------------------------------------------*

Name            _lgettc used as _lgetc and _lgetwc
                _lgetc  - gets character from stream without locking
                _lgetwc - gets (wide) character from stream without locking

Usage           int _lgetc(FILE *stream);
                wint_t _lgetwc(FILE *stream);

Prototype in    _stdio.h

Description     behaves exactly like getc, except that it is a true
                function while getc is a macro.  It does NOT lock
                the semaphore for the stream.

Return value    the character read, after converting it to an int
                without sign extension.  On end-of-file or error,
                returns EOF

*---------------------------------------------------------------------*/

#ifdef _MT
int _lgettc( register FILE  *fp )
#else
_TINT _RTLENTRY _EXPFUNC _fgettc (FILE  *fp)
#endif
{
#ifdef _UNICODE
    static wchar_t c;
#else
    static unsigned char c;
#endif

    if( fp == NULL)
        return( EOF );

    if( fp->level > 0 )
    {
        fp->level -= sizeof(_TCHAR);
        c = *((_TCHAR*)fp->curp)++;
        return c;
    }

    if( fp->level < 0 || fp->flags & (_F_OUT | _F_ERR) || !(fp->flags & _F_READ) )
    {
        fp->flags |= _F_ERR;
        return( EOF );          /* file is in writing mode  */
    }

    fp->flags |= _F_IN;

    if( fp->bsize != 0 )        /* is the stream buffered ? */
    {
        if( _tffill( fp ) )
            return( EOF );
        fp->level -= sizeof(_TCHAR);
        c = *((_TCHAR*)fp->curp)++;
        return c;
    }
    else                /* an unbuffered stream */
    {
        if( fp->flags & _F_TERM )
            FlushOutStreams();

        if( !__tread( fp->fd, &c, 1 ) )
        {
            if( __eof( fp->fd ) != 1 )
                fp->flags |= _F_ERR;
            else
                fp->flags = (fp->flags & ~(_F_IN | _F_OUT)) | _F_EOF;

            return( EOF );
        }
        fp->flags &= ~_F_EOF;
        return c;
    }
}
