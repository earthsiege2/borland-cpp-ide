/*  assert.h

    assert macro

*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */


#pragma warn -nak   /* Ignore non-ansi keywords */

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(__FLAT__)

#ifdef __cplusplus
extern "C" {
#endif

void _Cdecl _FARFUNC __assertfail( char _FAR *__msg,
                                   char _FAR *__cond,
                                   char _FAR *__file,
                                   int __line);

#ifdef  __cplusplus
}
#endif

#undef assert

#ifdef NDEBUG
#  define assert(p)   ((void)0)
#else
#  ifdef _Windows
#    define _ENDL
#  else
#    define _ENDL "\n"
#  endif
#  define assert(p) ((p) ? (void)0 : (void) __assertfail( \
                    "Assertion failed: %s, file %s, line %d" _ENDL, \
                    #p, __FILE__, __LINE__ ) )
#endif

#else  /* defined __FLAT__ */

#ifdef __cplusplus
extern "C" {
#endif

void _RTLENTRY _EXPFUNC _assert(char * __cond, char * __file, int __line);

/* Obsolete interface: __msg should be "Assertion failed: %s, file %s, line %d"
 */
void _RTLENTRY _EXPFUNC __assertfail(char * __msg, char * __cond,
                                     char * __file, int __line);

#ifdef  __cplusplus
}                                  
#endif

#undef assert

#ifdef NDEBUG
#define assert(p)   ((void)0)
#else
#define assert(p)   ((p) ? (void)0 : _assert(#p, __FILE__, __LINE__))
#endif


#endif  /* __FLAT__  */

#pragma warn .nak   /* Ignore non-ansi keywords */

