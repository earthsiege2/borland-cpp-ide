/*  timeb.h

    Struct and function declarations for ftime().

*/

/* $Copyright: 1987$ */

#if !defined(__TIMEB_H)
#define __TIMEB_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

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

#endif  /* __TIMEB_H */
