/*------------------------------------------------------------------------
 * filename - closeall.c
 *
 * function(s)
 *        fcloseall - close open streams
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_stdio.h>

/*------------------------------------------------------------------------*

Name            fcloseall - close open streams

Usage           int fcloseall(void);

Prototype in    stdio.h

Description     fcloseall closes all open  streams except stdin and stdout.
                All buffers  associated to each  stream are flushed  before
                closing. System  allocated buffers are freed  upon closing.
                Buffers   assigned   with   setbuf   or   setvbuf  are  not
                automatically freed.

Return value    fcloseall returns the total number of streams it closed or,
                EOF if any errors were detected.

*-------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC fcloseall (void)
{
    FILE *fp;
    int   i, cnt;

    _lock_all_streams();

    for( i = 3, fp = _streams + 3, cnt = 0; (unsigned)i < _nfile; fp++, i++ )
    {
        if( fp->fd >= 0 )
        {
            if( fclose( fp ) )
                cnt = -9999;
            else
                cnt++;
        }
    }

    _unlock_all_streams();

    return( cnt < 0 ? EOF : cnt );
}
