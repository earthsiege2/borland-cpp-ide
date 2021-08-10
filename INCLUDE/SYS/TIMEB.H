/*  timeb.h

    Struct and function declarations for ftime().

*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__TIMEB_H)
#define __TIMEB_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


#if !defined(__STDC__)
#define timezone _timezone
#endif

struct timeb {
      long  time;
      short millitm;
#if defined(_RTLDLL)
      short __timezone;
#else
      short _timezone;
#endif
      short dstflag;
      };

#ifdef __cplusplus
extern "C" {
#endif
void _RTLENTRY _EXPFUNC ftime(struct timeb _FAR *);
#ifdef __cplusplus
}
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif


#endif  /* !RC_INVOKED */

#endif  /* __TIMEB_H */
