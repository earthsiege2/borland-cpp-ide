/*-----------------------------------------------------------------------*
 * filename - gregistr.c
 *
 * function(s)
 *   registerbgidriver - register a BGI driver
 *   registerbgifont   - register a BGI font
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <_graph.h>
#include <process.h>

/*---------------------------------------------------------------------*

Name            registerbgidriver - register a BGI driver

Usage           void registerbgidriver(void (*driver)(void))

Prototype in    graphics.h

Description     informs the graphics system about the presence of a
                linked in graphics driver

Return value    nothing

*---------------------------------------------------------------------*/
void registerbgidriver(void (*driver)(void))
{
        registerfarbgidriver((void far *)driver);
}


/*---------------------------------------------------------------------*

Name            registerbgifont - register a BGI font

Usage           void registerbgifont(void (*font)(void))

Prototype in    graphics.h

Description     informs the graphics system about the presence of a
                linked in stroked font.

Return value    nothing

*---------------------------------------------------------------------*/
void registerbgifont(void (*font)(void))
{
        registerfarbgifont((void far *)font);
}
