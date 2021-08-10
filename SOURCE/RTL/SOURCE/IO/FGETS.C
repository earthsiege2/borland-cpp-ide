/*------------------------------------------------------------------------
 * filename - fgets.c
 *
 * function(s)
 *        fgets - gets a string from a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <stdio.h>
#include <string.h>
#include <_io.h>
#include <_stdio.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            _fgetts used as fgets and fgetws
                fgets  - gets a string from a stream
                fgetws - gets a wide string from a stream

Usage           char *fgets(char *string, int n, FILE *stream);
                wchar_t *fgetws(wchar_t *string, int n, FILE *stream);

Prototype in    stdio.h

Description     reads characters from stream into a string:
                The function stops reading when it either reads n-1
                characters or reads a newline character (whichever
                comes first).  fgets retains the newline character.
                The last character read into string is followed by a
                null character.

Return value    success : pointer to string
                failure : NULL

*---------------------------------------------------------------------*/

_TCHAR * _RTLENTRY _EXPFUNC _fgetts (_TCHAR *s, int n, FILE *fp)
{
    _TINT    c;
    int      Chunk;
    _TCHAR  *P;
    _TCHAR  *eolp;

    P = s;

    _lock_stream(fp);

    if (fp->bsize != 0)             /* file is buffered */
    {
        n--;                        /* leave room for null terminator */

        while( n > 0 )              /* In the case of the user passing n == 1
                                       into this function, the previous line
                                       will have decremented it to zero.  This
                                       while block will not be entered, no
                                       bytes will be read from the file, and
                                       the null char will eventually be written
                                       to the string as the one and only char
                                     */
        {
            /* If there is anything in the buffer, copy it directly
             * to the user's buffer.
             */
            if (fp->level > 0)         /* something in the buffer */
            {
                if ((n*sizeof(_TCHAR)) > (unsigned)fp->level)
                    Chunk = fp->level/sizeof(_TCHAR);
                else
                    Chunk = n;

                /* If there's a newline in the buffer, treat that
                 * as the end of the buffer.
                 */
                if ((eolp = _tmemchr(fp->curp, _TEXT('\n'), Chunk)) != NULL)
                    Chunk = eolp - (_TCHAR *)(fp->curp) + 1;

                /* Copy characters from the file buffer to the user's buffer,
                 * then update pointers and counts.
                 */
                _tmemcpy(P, fp->curp, Chunk);
                fp->curp += (Chunk * sizeof(_TCHAR));
                fp->level -= (Chunk * sizeof(_TCHAR));
                P += Chunk;
                n -= Chunk;

                /* If the user's buffer is full, or a newline was seen,
                 * stop reading bytes now.
                 */
                if (eolp != NULL || n == 0)
                {
                    c = _TEXT('\n');
                    break;
                }

            }
            else
                {
                /* The buffer is empty.  Use _gettc() to get one character
                 * and fill the buffer.
                 */
                if ((c = _gettc(fp)) == _TEOF)
                    {
                    fp->flags |= _F_EOF;
                    break;
                    }
                *P++ = c;
                --n;
                if (c == _TEXT('\n'))
                    break;
                }
        }
    }
    else
    {
        /* The file is unbuffered.  Get the characters one-by-one
         * the hard way.
         */
        c = _TEXT('\0');
        while (_TEXT('\n') != c && --n > 0  && (c = _gettc(fp)) != _TEOF)
            *P++ = c;
    }

    if (_TEOF == c && P == s)
        P = NULL;
    else
    {
        *P = _TEXT('\0');
        P = ferror (fp) ? NULL : s;
    }

    _unlock_stream(fp);
    return (P);
}
