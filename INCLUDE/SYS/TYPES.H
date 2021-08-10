/*  types.h

    Types for dealing with time.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $ */

#if !defined(__TYPES_H)
#define __TYPES_H

#ifdef __cplusplus
namespace std {
#endif /* __cplusplus */

#ifndef  _TIME_T
typedef long time_t;
#ifdef __cplusplus
#  define _TIME_T std::time_t
#else
#  define _TIME_T time_t
#endif /* __cplusplus */
#endif

typedef short dev_t;
typedef short ino_t;
typedef short mode_t;
typedef short nlink_t;
typedef int   uid_t;
typedef int   gid_t;
typedef long  off_t;

#ifdef __cplusplus
} // std
#  ifndef __USING_CNAME__
   using std::time_t;
   using std::dev_t;
   using std::ino_t;
   using std::mode_t;
   using std::nlink_t;
   using std::uid_t;
   using std::gid_t;
   using std::off_t;
#endif
#endif /* __cplusplus */


#endif  /* __TYPES_H */

