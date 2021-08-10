/*
    borutil.h - Various internally-used utility functions.
*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1999, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


/* $Revision: 9.4.2.1 $ */

#ifndef __BORUTIL_H
#define __BORUTIL_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Return a pointer to the last directory component in the passed in
 * path.
 */
char const * _RTLENTRY _EXPFUNC basename(char const *fn);

/*
 * return the length of the common substring in 's1' and 's2' anchored
 * at the end.  compare the characters without case sensitivity.
 */
_SIZE_T _RTLENTRY _EXPFUNC strirshr(const char *s1, const char *s2);

/*
 * return the length of the common substring in 's1' and 's2' anchored
 * at the end.  compare the characters with case sensitivity.
 */
_SIZE_T _RTLENTRY _EXPFUNC strrshr(const char *s1, const char *s2);

/*
 * return the length of the common substring in 's1' and 's2' anchored
 * at the beginning.  compare the characters with case sensitivity.
 */
_SIZE_T _RTLENTRY _EXPFUNC strshr(const char *s1, const char *s2);

/*
 * return the length of the common substring in 's1' and 's2' anchored
 * at the beginning.  compare the characters without case sensitivity.
 */
_SIZE_T _RTLENTRY _EXPFUNC strishr(const char *s1, const char *s2);

#ifdef __cplusplus
} /* "C" */
#endif

#endif /* __BORUTIL_H */