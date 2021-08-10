/*-----------------------------------------------------------------------*
 * filename - getstrm.c
 *
 * function(s)
 *        __getStream -
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1995, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <_io.h>
#include <stdio.h>

/* This function is provided for CodeGuard(tm) support only */

FILE * _RTLENTRY _EXPFUNC __getStream( int strm )
{
    return &(_streams[strm]);
}

