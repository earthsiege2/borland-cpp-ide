/*-----------------------------------------------------------------------*
 * filename - heaplen.c
 *
 * function(s)
 *        none
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


/*---------------------------------------------------------------------*

Name            _heaplen - the heap  length

Usage           extern  unsigned        _heaplen;

Description     This module defines the default near heap size.

*---------------------------------------------------------------------*/

#if !(LDATA)
unsigned        _heaplen = 0x0000;      /* To expand DS as much as possible */
#endif
