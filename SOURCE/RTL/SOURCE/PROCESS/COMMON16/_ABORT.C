/*------------------------------------------------------------------------
 * filename - _abort.c
 *
 * function(s)
 *        _abort -
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <_io.h>
#include <_process.h>
#include <stdlib.h>

void _abort(void)
{
   __ErrorMessage("Abnormal program termination\r\n");
   _exit(3);
}

