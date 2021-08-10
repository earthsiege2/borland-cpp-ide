/*  _null.h

    Definition of NULL.

*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.1  $ */

#ifndef NULL
#  if !defined(__FLAT__)
#    if defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
#      define NULL    0
#    else
#      define NULL    0L
#    endif
#  else
#    if defined(__cplusplus) || defined(_Windows)
#      define NULL 0
#    else
#      define NULL ((void *)0)
#    endif
#  endif
#endif

