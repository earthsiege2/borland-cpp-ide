/*-----------------------------------------------------------------------*
 * filename - getstrm.c
 *
 * function(s)
 *        __getStream -
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1995, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <_io.h>
#include <stdio.h>

/* This function is provided for CodeGuard(tm) support only */

FILE * _RTLENTRY _EXPFUNC __getStream( int strm )
{
    return &(_streams[strm]);
}

