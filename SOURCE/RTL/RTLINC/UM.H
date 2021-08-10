/*------------------------------------------------------------------------
 * filename - um.h - helper file for um.c
 *
 * function(s)
 *
 *   _rtl_unmangle
 *   _rtl_setUnmangleMode
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1988, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


/* $Revision: 9.4.2.1 $        */

#ifndef __UM_H
#define __UM_H

#include <windows.h>                      /* prototype for wsprintf */
#define sprintf wsprintf                  /* so that the RTL's vprinter */
                                          /*   doesn't come in */

#include <unmangle.h>

#define unmangle        _rtl_unmangle        /* the RTL version */
#define setUnmangleMode _rtl_setUnmangleMode /* the RTL version */
#define MAXBUFFLEN      _UM_MAXBUFFLEN
#define umKind          _umKind
#define UMAPI           _UMAPI

#endif /* __UM_H */