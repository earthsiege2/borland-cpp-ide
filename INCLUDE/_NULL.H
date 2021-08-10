/*  _null.h

    Definition of NULL.

*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


/* $Revision: 9.5.2.2 $ */

#ifndef NULL
#  if defined(__cplusplus) || defined(_Windows)
#    define NULL 0
#  else
#    define NULL ((void *)0)
#  endif
#endif

