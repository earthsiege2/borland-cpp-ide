/*-----------------------------------------------------------------------*
 * filename - getstrm.c
 *
 * function(s)
 *        __getStream -
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1995, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <_io.h>
#include <stdio.h>

/* This function is provided for CodeGuard(tm) support only */

FILE * _RTLENTRY _EXPFUNC __getStream( int strm )
{
    return &(_streams[strm]);
}

