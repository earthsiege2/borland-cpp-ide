/*-----------------------------------------------------------------------*
 * filename - fpstklen.c
 *
 * function(s)
 *        none
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */


/*---------------------------------------------------------------------*

Name            _fpstklen  - the floating point stack length

Usage           extern  unsigned        _fpstklen;

Description     This module defines the default fp stack size.

*---------------------------------------------------------------------*/

unsigned        _fpstklen = 17 * 12;      /* Default fp stack size in bytes */
