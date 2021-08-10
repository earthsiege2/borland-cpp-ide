/*-----------------------------------------------------------------------*
 * filename - lgetwc.c
 *
 * function(s)
 *    _wffill      - fill up the (wide) read-ahead buffer
 *    _lgetwc      - gets (wide) character from stream without locking
 *                  (multi-thread only)
 *    _fgetwc      - gets character from stream with locking
 *                  (single-thread only)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1996, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.0  $        */

#define _UNICODE
#include "lgetc.c"


