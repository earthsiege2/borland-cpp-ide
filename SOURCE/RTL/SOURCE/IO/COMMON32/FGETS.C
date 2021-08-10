/*------------------------------------------------------------------------
 * filename - fgets.c
 *
 * function(s)
 *        fgets - gets a string from a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <string.h>
#include <_io.h>
#include <_stdio.h>

/*---------------------------------------------------------------------*

Name            fgets - gets a string from a stream

Usage           char *fgets(char *string, int n, FILE *stream);

Prototype in    stdio.h

Description     reads characters from stream into the string string:
                The function stops reading when it either reads n-1
                characters or reads a newline character (whichever
                comes first).  fgets retains the newline character.
                The last character read into string is followed by a
                null character.

Return value    success : pointer to string
                failure : NULL

*---------------------------------------------------------------------*/

char * _RTLENTRY _EXPFUNC fgets (char *s, int n, FILE *fp)
{
    int     c, Chunk;
    char    *P, *eolp;

    P = s;

    _lock_stream(fp);

    if (fp->bsize != 0)             /* file is buffered */
    {
        n--;                        /* leave room for null terminator */
        while( n >= 0 )
        {
            /* If there is anything in the buffer, copy it directly
             * to the user's buffer.
             */
            if (fp->level > 0)         /* something in the buffer */
            {
                if (n > (unsigned)fp->level)
                    Chunk = fp->level;
                else
                    Chunk = n;

                /* If there's a newline in the buffer, treat that
                 * the end of the buffer.
                 */
                if ((eolp = memchr(fp->curp, '\n', Chunk)) != NULL)
                    Chunk = eolp - (char *)fp->curp + 1;

                /* Copy bytes from the file buffer to the user's buffer,
                 * then update pointers and counts.
                 */
                memcpy(P, fp->curp, Chunk);
                fp->curp += Chunk;
                fp->level -= Chunk;
                P += Chunk;
                n -= Chunk;

                /* If the user's buffer is full, or a newline was seen,
                 * stop reading bytes now.
                 */
                if (eolp != NULL || n == 0)
                {
                    c = '\n';
                    break;
                }

            }
            else
                {
                /* The buffer is empty.  Use getc() to get one character
                 * and fill the buffer.
                 */
                if ((c = (int)getc(fp)) == EOF)
                    {
                    fp->flags |= _F_EOF;
                    break;
                    }
                *P++ = (char)c;
                --n;
                if (c == '\n')
                    break;
                }
        }
    }
    else
    {
        /* The file is unbuffered.  Get the characters one-by-one
         * the hard way.
         */
        c = '\0';
        while ('\n' != c && --n > 0  &&  (c = (int)getc(fp)) != EOF)
            *P++ = (char)c;
    }

    if (EOF == c && P == s)
        P = NULL;
    else
    {
        *P = '\0';
        P = ferror (fp) ? NULL : s;
    }

    _unlock_stream(fp);
    return (P);
}
