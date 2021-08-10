/*-----------------------------------------------------------------------*
 * filename - allocbuf.c
 *
 * function(s)
 *        _allocbuf - allocate buffer for a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <stdio.h>
#include <stdlib.h>
#include <_stdio.h>

extern  void    (*_exitbuf)();
extern  void      _xfflush();

/*-----------------------------------------------------------------------*

Name            _allocbuf - assigns buffering to a stream

Usage           #include <stdio.h>
                int _allocbuf(FILE *stream, char *buf, int type,
                            size_t size);

Prototype in    stdio.h

Description     This function is a helper function used by setvbuf and
                _init_streams to allocate a buffer for a stream file.
                It performs the same functions as setvbuf, except
                that it does not verify the file pointer, flush the file,
                or lock/unlock the file.  See setvbuf.c for more information.

Return value    _allocbuf returns 0 on success. It returns non-zero if
                buf is NULL and there is not enough space to allocate a
                buffer.

*-----------------------------------------------------------------------*/

int _allocbuf(FILE *fp, char *buf, int type, size_t size)
{
    if (fp->flags & _F_BUF)
        free (fp->buffer);

    fp->flags &= ~(_F_BUF | _F_LBUF);
    fp->bsize = 0;
    fp->curp = fp->buffer = (unsigned char*)&fp->hold;

    if (_IONBF != type && size > 0)
    {
        _exitbuf = _xfflush;

        if (NULL == buf)
        {
            if ((buf = malloc (size)) != NULL)
                fp->flags |= _F_BUF;
            else
                return (EOF);
        }
        fp->buffer = fp->curp = (unsigned char *)buf;
        fp->bsize = size;
        if (_IOLBF == type)
            fp->flags |= _F_LBUF;
    }
    return (0);
}
