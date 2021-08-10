/*------------------------------------------------------------------------
 * filename - fclose.c
 *
 * function(s)
 *        fclose - closes a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <alloc.h>
#include <_stdio.h>
#include <_io.h>

/*--------------------------------------------------------------------------*

Name            fclose - closes a stream

Usage           int fclose(FILE *stream);

Prototype in    stdio.h

Description     closes the named stream; generally, all buffers associated
                with stream are flushed before closing.  System-allocated
                buffers are freed upon closing.  Buffers assigned with setvbuf
                and setbuf are not automatically freed.

Return value    success : 0
                failure : EOF

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC fclose (FILE *fp)
{
    int rc;

    if (fp == NULL || fp->token != (short) fp)
        return(EOF);                /* invalid pointer */

    _lock_stream(fp);

    if (fp->bsize)
    {
        if (fp->level < 0 && fflush (fp))
            RETURN(EOF);

        if (fp->flags & _F_BUF)
            free (fp->buffer);
    }

    rc = __close (fp->fd);

    fp->flags = 0;
    fp->bsize = 0;
    fp->level = 0;
    fp->fd = -1;

    if (fp->istemp != 0)
    {
        __unlink(__mkname((char *)NULL, (char *)NULL, fp->istemp));
        fp->istemp = 0;
    }

exit:
    _unlock_stream(fp);
    return rc;
}
