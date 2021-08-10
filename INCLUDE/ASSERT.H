/*  assert.h

    assert macro

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.3  $ */

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
namespace std {
#endif

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

#ifdef __cplusplus
} // std
#endif /* __cplusplus */

#undef assert

#ifdef NDEBUG
#define assert(p)   ((void)0)
#else
#define assert(p)   ((p) ? (void)0 : _assert(#p, __FILE__, __LINE__))
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__ASSERT_H_USING_LIST)
#define __ASSERT_H_USING_LIST
     using std::_assert;
     using std::__assertfail;
#endif /* __USING_CNAME__ */