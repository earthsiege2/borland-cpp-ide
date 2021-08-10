/*-----------------------------------------------------------------------*
 * filename - flushout.c
 *
 * function(s)
 *        _flushout - clears all output buffers
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

/*---------------------------------------------------------------------*

Name            _flushout - writes all output buffers

Usage           int _flushout(void);

Prototype in    stdio.h

Description     Writes all buffers associated with open output streams
                to their respective files.

Return value    the number of open output streams

*---------------------------------------------------------------------*/
int _RTLENTRY _EXPFUNC _flushout(void)
{
    register FILE   *fp;
    register int    Nb;
    int             Cpt;
    int             count;

    _lock_all_streams();

    for (Cpt = 0, Nb = _nfile, fp = _streams; Nb--; fp++)
        if( fp->level < 0 )                 /* output data waiting in buffer */
            {
            count = fp->bsize + 1 + fp->level;
            fp->level -= count;

            if( (__write( fp->fd, (fp->curp = fp->buffer), count ) != count) &&
                ((fp->flags & _F_TERM) == 0) )
                {
                fp->flags |= _F_ERR;
                }
            Cpt++;
            }

    _unlock_all_streams();
    return(Cpt);
}
