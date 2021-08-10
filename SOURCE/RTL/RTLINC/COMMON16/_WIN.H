/*------------------------------------------------------------------------
 * filename - _win.h
 *
 *      prototypes for Windows error message functions
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.1  $ */

#if !defined( ___WIN_H )
#define ___WIN_H

#ifdef __cplusplus
extern "C" {
#endif

void _errorBox(const char *);
void _errorExitBox(const char *, int);

#ifdef  __cplusplus
}
#endif

#endif  // ___WIN_H

