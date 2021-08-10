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
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.5  $        */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <_stdio.h>
#include <_io.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            _lputtc used as _lputc and _lputwc
                _lputc  - puts a character on a stream without locking
                _lputwc - puts a wide character on a stream without locking

Usage           #include <stdio.h>
                int _lputc (int ch, FILE *stream);
                wint_t _lputwc(wint_t wch, FILE *stream);

Related
functions usage _TINT _fputtc(_TINT ch, FILE *stream);
                _TINT _fputtchar(_TINT ch);
                _TINT _puttch(_TINT ch);

                _TINT _puttchar(_TINT ch);
                int putw(int w, FILE *stream);

Prototype in    local

Description     _lputtc is like _puttc but it is a true function that outputs
                ch to the named stream.  It does NOT lock the semaphore
                for the stream.

                _fputtc is identical to _lputtc but locks the semaphore.

Return value    On success _lputtc, _puttc, _fputtc, _fputtchar, and _puttchar
                return the character ch, while putw returns the word w, and
                _puttch returns nothing.

                On error, all the functions except putch return EOF.

*---------------------------------------------------------------------*/

#ifdef _MT
int _lputtc( _TINT ch, FILE *fp )
#else
_TINT _RTLENTRY _EXPFUNC _fputtc (_TINT ch, FILE *fp)
#endif
{

    int           nbytes;
    char          buf[(MB_CUR_MAX>sizeof(_TCHAR))?MB_CUR_MAX:sizeof(_TCHAR)];
#ifdef _UNICODE
    wchar_t       c = (wchar_t) ch;
#else
    unsigned char c = (unsigned char) ch;
#endif

#ifdef _UNICODE
    if ((_openfd[fp->fd] & O_TEXT) != 0)
    {
      if( -1 == (nbytes = wctomb(buf, c)))
          return EOF;
    }
    else
    {
      ((wchar_t*)buf)[0] = c;
      nbytes = sizeof(wchar_t);
    }
#else
    buf[0] = c;
    nbytes = 1;
#endif

    if( fp->level < -nbytes )
    {
        memcpy(fp->curp, buf, nbytes);
        fp->level += nbytes;
        fp->curp  += nbytes;

        if((fp->flags & _F_LBUF) && ((c == _TEXT('\n')) || (c == _TEXT('\r'))))
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

        memcpy(fp->curp, buf, nbytes);
        /* level is one less than number in buffer so it's always less
           than zero. Zero indicates empty buffer */
        fp->level += nbytes - 1;
        fp->curp  += nbytes;

        if( (fp->flags & _F_LBUF) && ((c == _TEXT('\n')) || (c == _TEXT('\r'))) )
        {
            if( fflush( fp ) )
                return( EOF );
        }

        return( c );
    }
    else                     /* the stream is not buffered */
    {
        if (__write( fp->fd, buf , nbytes ) != nbytes)
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
