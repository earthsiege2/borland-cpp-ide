/*-----------------------------------------------------------------------*
 * filename - flushout.c
 *
 * function(s)
 *        _flushout - clears all output buffers
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#include <stdio.h>
#include <_io.h>
#include <RtlData.h>

/*---------------------------------------------------------------------*

Name            _flushout - clears all output buffers

Usage           int _flushout(void);

Prototype in    stdio.h

Description     clears all buffers associated with open input streams,
                and writes all buffers associated with open output streams
                to their respective files.  Any read operation following
                flushall reads new data into the buffers from the input
                files.

Return value    the number of open input and output streams

*---------------------------------------------------------------------*/
int _FARFUNC _flushout(void)
{
    register FILE   *fp;
    register int    Nb;
    int             Cpt;
    int             count;
    _QRTLDataBlock;

    for (Cpt = 0, Nb = _QRTLInstanceData(_nfile), fp = _QRTLInstanceData(_streams);
         Nb--;
         fp++)

         if( fp->level < 0 )            /* output data waiting in buffer */
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

    return(Cpt);
}
