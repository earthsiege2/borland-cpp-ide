/*-----------------------------------------------------------------------*
 * filename - xfflush.c
 *
 * function(s)
 *        _xfflush - flushes streams
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */


#include <stdio.h>
#include <RtlData.h>

/*---------------------------------------------------------------------*

Name            _xfflush - flushes streams

Usage           void _xfflush(void)

Description     called at exit to flush open streams

*---------------------------------------------------------------------*/
void _FARFUNC _xfflush(void)
{
    register FILE   *fp;
    register int    i;
    _QRTLDataBlock;

    for( i = 0, fp = _QRTLInstanceData(_streams);
         i < _QRTLInstanceData(_nfile);
         fp++, i++ )
    {
        if( (fp->flags & _F_RDWR) && (fp->level < 0) )
	         fflush(fp);
    }
}
