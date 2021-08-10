/*-----------------------------------------------------------------------*
 * filename - xfflush.c
 *
 * function(s)
 *        _xfflush - flushes streams
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
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
        register int    i = 4;

        for (fp = _RTLInstanceData(_streams); i; i--, fp++)
                if (fp->flags & _F_RDWR)
                        fflush(fp);
}
