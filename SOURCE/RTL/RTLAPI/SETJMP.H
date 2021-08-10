/*  setjmp.h

    Defines typedef and functions for setjmp/longjmp.

*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __SETJMP_H
#define __SETJMP_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma option -a-

#if !defined(__FLAT__)

typedef struct __jmp_buf {
    unsigned    j_sp;
    unsigned    j_ss;
    unsigned    j_flag;
    unsigned    j_cs;
    unsigned    j_ip;
    unsigned    j_bp;
    unsigned    j_di;
    unsigned    j_es;
    unsigned    j_si;
    unsigned    j_ds;
    unsigned    j_excep;
    unsigned    j_context;
}   jmp_buf[1];

#if !defined( _Windows ) || defined(_LFOOT)
void    _CType longjmp(jmp_buf __jmpb, int __retval);
int     _CType setjmp(jmp_buf __jmpb);
#else
void far pascal longjmp( struct __jmp_buf far *__jmpb, int __retval );
int far pascal setjmp( struct __jmp_buf far *__jmpb);
#endif

#else    /* defined __FLAT__ */

typedef struct __jmp_buf {
    unsigned    j_ebp;
    unsigned    j_ebx;
    unsigned    j_edi;
    unsigned    j_esi;
    unsigned    j_esp;
    unsigned    j_ret;
#if defined(__FLAT__)
    unsigned    j_excep;
    unsigned    j_context;
#endif
}   jmp_buf[1];

void    _RTLENTRYF _EXPFUNC longjmp(jmp_buf __jmpb, int __retval);
int     _RTLENTRYF _EXPFUNC setjmp(jmp_buf __jmpb);

#endif  /* __FLAT__ */

#pragma option -a.  /* restore default packing */

#ifdef __cplusplus
}
#endif

#endif  /* __SETJMP_H */

