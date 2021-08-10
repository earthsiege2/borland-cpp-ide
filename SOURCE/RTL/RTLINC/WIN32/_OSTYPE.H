/*------------------------------------------------------------------------
 * filename - _ostype.h
 *
 *  Operating environment definitions
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1993, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_defs.h>

#define _WIN32   0
#define _WIN32S  1
#define _DOS32   2

extern unsigned _EXPDATA _ostype;    /* The operating environment. */
