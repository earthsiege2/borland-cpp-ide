/*-----------------------------------------------------------------------*
 * filename - xfclose.c
 *
 * function(s)
 *        _xfclose - closes streams
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <stdio.h>
#include <RtlData.h>

/*---------------------------------------------------------------------*

Name            _xfclose - closes streams

Usage           void _xfclose(void)

Description     called at exit to close open streams

*---------------------------------------------------------------------*/
void _FARFUNC _xfclose( void )
{
    register FILE *fp;
    register int  i;
    _QRTLDataBlock;

    for( i = 0, fp = _QRTLInstanceData(_streams);
         i < _QRTLInstanceData(_nfile);
         fp++, i++ )
    {
        /* Only close temp files.  Leave the others open so CG has a crack
           at them.  This is so that CG can detect when the user has failed
           to close a file he opened.
        */
        if( (fp->flags & _F_RDWR) && (fp->istemp))
            fclose( fp );
    }
}
