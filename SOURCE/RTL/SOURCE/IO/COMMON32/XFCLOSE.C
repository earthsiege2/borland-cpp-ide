/*-----------------------------------------------------------------------*
 * filename - xfclose.c
 *
 * function(s)
 *        _xfclose - closes streams
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

/*---------------------------------------------------------------------*

Name        _xfclose - closes streams

Usage       void _xfclose(void)

Description called at exit to close open streams

*---------------------------------------------------------------------*/

void _xfclose( void )
{
    register FILE *fp;
    register int  i;

    _lock_all_streams();
    for( i = 0, fp = _streams; i < _nfile; fp++, i++ )
        if (fp->flags & _F_RDWR)
            fclose( fp );
    _unlock_all_streams();
}
