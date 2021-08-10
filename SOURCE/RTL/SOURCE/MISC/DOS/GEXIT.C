/*-----------------------------------------------------------------------*
 * filename - gexit.c
 *
 * function(s)
 *   _graphexit - abort program (for graphics library)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <graphics.h>
#include <process.h>

/*-----------------------------------------------------------------------*

Name            _graphexit - abort program (for graphics library)

Usage           void far _graphexit(int status);

Prototype in    graphics.h

Description     This is the default version of "_graphexit". It merely
                calls "exit" with the specified exit status.

*------------------------------------------------------------------------*/
void far _graphexit(int status)
{
        exit(status);
}
