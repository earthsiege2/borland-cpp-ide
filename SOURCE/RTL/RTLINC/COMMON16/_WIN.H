/*------------------------------------------------------------------------
 * filename - _win.h
 *
 *      prototypes for Windows error message functions
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

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

