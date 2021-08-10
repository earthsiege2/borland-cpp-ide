/*------------------------------------------------------------------------
 * filename - _ostype.h
 *
 *  Operating environment definitions
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1993, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $ */

#include <_defs.h>

#define _DOS32   1
#define _WIN32S  2
#define _WINNT   4
#define _WIN95   8

extern unsigned _EXPDATA _ostype;    /* The operating environment. */
