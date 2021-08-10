/*------------------------------------------------------------------------
 * filename - rmtmp.c
 *
 * function(s)
 *        rmtmp - close and delete open temporary file streams
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_stdio.h>

/*------------------------------------------------------------------------*

Name            rmtmp - close and delete open temporary streams

Usage           int rmtmp(void);

Prototype in    stdio.h

Description     rmtmp closes and deletes all open temporary file streams,
                which were previously created with tmpfil().  The current
                directory must the same as when the files were created, or
                the files will not be deleted.

Return value    rmtmp returns the total number of temporary files
                it closed and deleted.

*-------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC rmtmp( void )
{
    FILE *fp;
    int   i, cnt;

    _lock_all_streams();

    for( i = 0, fp = _streams, cnt = 0; i < (int)_nfile; fp++, i++ )
    {
        if( fp->istemp != 0 )
        {
                if( fclose( fp ) == 0 )  cnt++;
        }
    }

    _unlock_all_streams();
    return( cnt );
}
