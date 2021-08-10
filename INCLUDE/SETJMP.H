/*  setjmp.h

    Defines typedef and functions for setjmp/longjmp.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.3  $ */

#ifndef __SETJMP_H
#define __SETJMP_H
#define _INC_SETJMP  /* MSC Guard name */

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#ifdef __cplusplus
  namespace std {
#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#pragma pack(push, 1)

#endif  /* !RC_INVOKED */

typedef struct __jmp_buf {
    unsigned    j_ebp;
    unsigned    j_ebx;
    unsigned    j_edi;
    unsigned    j_esi;
    unsigned    j_esp;
    unsigned    j_ret;
    unsigned    j_excep;
    unsigned    j_context;
}   jmp_buf[1];

void    _RTLENTRYF _EXPFUNC longjmp(jmp_buf __jmpb, int __retval);
int     _RTLENTRYF _EXPFUNC setjmp(jmp_buf __jmpb);

#ifdef __cplusplus
}
#endif

#if !defined(RC_INVOKED)

/* restore default packing */
#pragma pack(pop)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
} // std
#endif /* __cplusplus */

#endif  /* __SETJMP_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__SETJMP_H_USING_LIST)
#define __SETJMP_H_USING_LIST
     using std::jmp_buf;
     using std::longjmp;
     using std::setjmp;
#endif /* __USING_CNAME__ */
