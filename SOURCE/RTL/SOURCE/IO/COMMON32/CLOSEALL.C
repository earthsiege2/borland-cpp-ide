/*------------------------------------------------------------------------
 * filename - closeall.c
 *
 * function(s)
 *        _fcloseall - close open streams
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#include <stdio.h>
#include <_stdio.h>

/*------------------------------------------------------------------------*

Name            _fcloseall - close open streams

Usage           int _fcloseall(void);

Prototype in    stdio.h

Description     _fcloseall closes all open  streams except stdin and stdout.
                All buffers  associated to each  stream are flushed  before
                closing. System  allocated buffers are freed  upon closing.
                Buffers   assigned   with   setbuf   or   setvbuf  are  not
                automatically freed.

Return value    _fcloseall returns the total number of streams it closed or,
                EOF if any errors were detected.

*-------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _fcloseall (void)
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
