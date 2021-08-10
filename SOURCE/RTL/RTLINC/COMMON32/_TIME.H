/*------------------------------------------------------------------------
 * filename - _time.h
 *
 *  Definitions for time functions.  Must be included after time.h
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.5  $ */

#if !defined( ___DEFS_H )
#include <_defs.h>
#endif

#if !defined( __TCHAR_H )
#include <tchar.h>
#endif

#define DefaultTimeZone 5L
#define DefaultDaylight 1
#if !defined(_UNICODE)
#define _tSWeekday   _SWeekday
#define _tLWeekday   _LWeekday
#define _tSMonth     _SMonth
#define _tLMonth     _LMonth
#define _tAmPm       _AmPm
#else  /* _UNICODE */
#define _tSWeekday   _wSWeekday
#define _tLWeekday   _wLWeekday
#define _tSMonth     _wSMonth
#define _tLMonth     _wLMonth
#define _tAmPm       _wAmPm
#endif /* _UNICODE */

#ifdef __cplusplus
extern "C" {
#endif

int             _isDST      (unsigned __hour,  unsigned __yday,
                                unsigned __month, unsigned __year);
unsigned long   _totalsec   (int __year, int __month, int __day, int __hour,
                                int __min, int __sec);
#if defined(__FLAT__)
void            _watime     (wchar_t *__dest, const struct tm *__tmPtr,
                                wchar_t *__term );
void            _atime      (char *__dest, const struct tm *__tmPtr,
                                char *__term );
#endif

extern _TCHAR *_tSWeekday[7];
extern _TCHAR *_tLWeekday[7];
extern _TCHAR *_tSMonth[12];
extern _TCHAR *_tLMonth[12];
extern _TCHAR *_tAmPm[2];
extern char    _Days[12];
extern int     _YDays[13];

#ifdef __cplusplus
}
#endif

#ifdef _MT
typedef struct          /* per-thread data */
{
    struct tm thread_tm;
    wchar_t   thread_asctime[26]; /* Enough for normal or wide char's */
} THREAD_TIME;
#endif
