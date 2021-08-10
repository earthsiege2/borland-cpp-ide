/*------------------------------------------------------------------------
 * filename - ioconfig.h
 *
 *      configuration data for C++ I/O streams
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.1  $ */

#if !defined( __IOCONFIG_H )
#define __IOCONFIG_H


#undef _BIG_INLINE          // disable expansion of large inline functions

const MaxCharsInLong        = 16;
const StreambufSize         = 1024;
const MinStrstreamAlloc     = 16;
const MinStrstreamIncr      = 4;

#endif  // __IOCONFIG_H

