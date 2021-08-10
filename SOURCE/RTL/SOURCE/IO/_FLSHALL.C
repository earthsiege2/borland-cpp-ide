/*-----------------------------------------------------------------------*
 * filename - _flshall.c
 *
 * function(s)
 *        _flushall - clears all buffers
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

/*---------------------------------------------------------------------*

Name            _flushall - clears all buffers

Usage           int _flushall(void);

Prototype in    stdio.h

Description     clears all buffers associated with open input streams,
                and writes all buffers associated with open output streams
                to their respective files.  Any read operation following
                _flushall reads new data into the buffers from the input
                files.

Return value    the number of open input and output streams

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _flushall (void)
{
        register FILE   *fp;
        register int    Nb;
        int             Cpt;

        _lock_all_streams();
        for (Cpt = 0, Nb = _nfile, fp = _streams; Nb--; fp++)
                if (fp->flags & _F_RDWR && fp->level)
                {
                        fflush(fp);
                        Cpt++;
                }
        _unlock_all_streams();
        return(Cpt);
}
