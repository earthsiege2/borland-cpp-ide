/*------------------------------------------------------------------------
 * filename - _abort.c
 *
 * function(s)
 *        _abort -
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1992, 1994 by Borland International
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

