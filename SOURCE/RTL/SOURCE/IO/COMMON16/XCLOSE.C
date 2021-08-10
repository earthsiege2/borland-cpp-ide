/*-----------------------------------------------------------------------*
 * filename - xclose.c
 *
 * function(s)
 *        _xclose - closes files
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */


#include <io.h>
#include <_io.h>
#include <RtlData.h>

/*---------------------------------------------------------------------*

Name            _xclose - closes files

Usage           void _xclose(void)

Description     called at exit to close open files

*---------------------------------------------------------------------*/
void _xclose(void)
{
    register int    i;

    for (i = 2; i < _nfile; i++)
        if (_RTLInstanceData(_openfd)[i] != 0)
//          close(i);
            ;
}
