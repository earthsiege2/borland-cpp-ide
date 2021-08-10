/*------------------------------------------------------------------------
 * filename - _dir.h
 *
 *      Defines structures, macros, and functions for dealing with
 *      directories and pathnames.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

int _RTLENTRYF _EXPFUNC __fnsplit(const char *pathP, char *driveP, char *dirP,
                                  char *nameP, char *extP);

#ifdef __cplusplus
}
#endif

