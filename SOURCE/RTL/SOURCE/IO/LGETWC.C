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
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1996, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#define _UNICODE
#include "lgetc.c"


