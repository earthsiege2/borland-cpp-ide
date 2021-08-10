/*-----------------------------------------------------------------------*
 * filename - seterrmd.c
 *
 * function(s)
 *   _seterrormode - MSC compatible function
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1999, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#define INCL_USER
#include <ntbc.h>
#include <stdlib.h>

/* This is a simple wrapper around the WinAPI SetErrorMode */

void _RTLENTRY _EXPFUNC _seterrormode(int __mode)
{
        SetErrorMode(__mode);
}
