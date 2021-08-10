/*------------------------------------------------------------------------
 * filename - _abort.c
 *
 * function(s)
 *        _abort -
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1992, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_io.h>
#include <_process.h>
#include <stdlib.h>

void _abort(void)
{
   __ErrorMessage("Abnormal program termination\r\n");
   _exit(3);
}

