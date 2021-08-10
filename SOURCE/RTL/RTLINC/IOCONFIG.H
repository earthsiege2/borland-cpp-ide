/*------------------------------------------------------------------------
 * filename - ioconfig.h
 *
 *  contains configuration data for C++ io streams
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1990, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


/* $Revision: 9.4.2.1 $ */

#if !defined( __IOCONFIG_H )
#define __IOCONFIG_H

#undef _BIG_INLINE          // disable expansion of large inline functions

const MaxCharsInLong        = 16;
const MaxCharsInInt64       = 28;
const StreambufSize         = 1024;
const MinStrstreamAlloc     = 16;
const MinStrstreamIncr      = 4;

#endif  // __IOCONFIG_H

