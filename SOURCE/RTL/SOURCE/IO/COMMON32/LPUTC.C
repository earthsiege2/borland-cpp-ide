/*-----------------------------------------------------------------------*
 * filename - lputc.c
 *
 * function(s)
 *      fputc  - puts a character on a stream with locking
 *               (single-thread library only)
 *      _lputc - puts a character on a stream without locking
 *               (multi-thread library only)
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

Name            _lputc - puts a character on a stream without locking

Usage           #include <stdio.h>
                int _lputc(int ch, FILE *stream);

Related
functions usage int fputc(int ch, FILE *stream);
                int fputchar(int ch);
                int putch(int ch);

                int putchar(int ch);
                int putw(int w, FILE *stream);

Prototype in    local

Description     _lputc is like putc but it is a true function that outputs
                ch to the named stream.  It does NOT lock the semaphore
                for the stream.

                fputc is identical to _lputc but locks the semaphore.

Return value    On success _lputc, putc, fputc, fputchar, and putchar return
                the character ch, while putw returns the word w, and putch
                returns nothing.

                On error, all the functions except putch return EOF.

*---------------------------------------------------------------------*/

#ifdef _MT
int _lputc( int ch, FILE *fp )
#else
int _RTLENTRY _EXPFUNC fputc (int ch, FILE *fp)
#endif
{
    unsigned char c;

    c = (unsigned char)ch;

    if( fp->level < -1 )
    {
        ++fp->level;

        *fp->curp++ = c;

        if((fp->flags & _F_LBUF) && ((c == '\n') || (c == '\r')))
        {
            /* If file is line buffered, and character is a carriage
             * return or line feed, flush the buffer.
             */
            if( fflush( fp ) )
                return( EOF );
        }
        return (c);
    }

    if( fp->flags & (_F_IN | _F_ERR) || !(fp->flags & _F_WRIT) )
    {
        fp->flags |= _F_ERR;
        return( EOF );
    }

    fp->flags |= _F_OUT;

    if( fp->bsize != 0 )     /* is the stream buffered ? */
    {
        /*  The level is zero only at initialization or after a rewind
            or seek, when _F_OUT is not yet decided and the buffer empty.
        */
        if( fp->level )
        {
            if( fflush( fp ) )
                return( EOF );
        }

        fp->level = -fp->bsize;

        *fp->curp++ = c;

        if( (fp->flags & _F_LBUF) && ((c == '\n') || (c == '\r')) )
        {
            if( fflush( fp ) )
                return( EOF );
        }

        return( c );
    }
    else                     /* the stream is not buffered */
    {
        if (__write( fp->fd, & c , 1 ) != 1)
        {
            if( (fp->flags & _F_TERM) == 0 )
            {
                fp->flags |= _F_ERR;
                return( EOF );
            }
        }

        return( c );
    }
}
