/*------------------------------------------------------------------------
 * filename - ioconfig.h
 *
 *  contains configuration data for C++ io streams
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined( __IOCONFIG_H )
#define __IOCONFIG_H

#undef _BIG_INLINE          // disable expansion of large inline functions

const MaxCharsInLong        = 16;
const StreambufSize         = 1024;
const MinStrstreamAlloc     = 16;
const MinStrstreamIncr      = 4;

#endif  // __IOCONFIG_H

