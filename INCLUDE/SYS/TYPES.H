/*  types.h

    Types for dealing with time.

*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__TYPES_H)
#define __TYPES_H

#ifndef  _TIME_T
#define  _TIME_T
typedef long time_t;
#endif

#if defined(__FLAT__)
typedef short dev_t;
typedef short ino_t;
typedef short mode_t;
typedef short nlink_t;
typedef int   uid_t;
typedef int   gid_t;
typedef long  off_t;

#endif  /* __FLAT__ */

#endif  /* __TYPES_H */

