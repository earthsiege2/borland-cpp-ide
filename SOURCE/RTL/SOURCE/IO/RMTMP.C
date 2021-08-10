/*------------------------------------------------------------------------
 * filename - rmtmp.c
 *
 * function(s)
 *        _rmtmp - close and delete open temporary file streams
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#include <stdio.h>
#include <_stdio.h>

/*------------------------------------------------------------------------*

Name            _rmtmp - close and delete open temporary streams

Usage           int _rmtmp(void);

Prototype in    stdio.h

Description     _rmtmp closes and deletes all open temporary file streams,
                which were previously created with tmpfil().  The current
                directory must the same as when the files were created, or
                the files will not be deleted.

Return value    _rmtmp returns the total number of temporary files
                it closed and deleted.

*-------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _rmtmp( void )
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
