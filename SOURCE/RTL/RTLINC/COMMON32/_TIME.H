/*------------------------------------------------------------------------
 * filename - _time.h
 *
 *  Definitions for time functions.  Must be included after time.h
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

int             _isDST      (unsigned __hour,  unsigned __yday,
                                unsigned __month, unsigned __year);
unsigned long   _totalsec   (int __year, int __month, int __day, int __hour,
                                int __min, int __sec);
void            _atime      (char *__dest, const struct tm *__tmPtr,
                                char *__term );
extern char *_SWeekday[7];
extern char *_LWeekday[7];
extern char *_SMonth[12];
extern char *_LMonth[12];
extern char *_AmPm[2];
extern char  _Days[12];
extern int   _YDays[13];

#ifdef __cplusplus
}
#endif

#ifdef _MT
typedef struct          /* per-thread data */
{
    struct tm thread_tm;
    char      thread_asctime[26];
} THREAD_TIME;
#endif
