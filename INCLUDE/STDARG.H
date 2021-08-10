/*  stdarg.h

    Definitions for accessing parameters in functions that accept
    a variable number of arguments.

*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __STDARG_H
#define __STDARG_H

#ifdef __VARARGS_H
#error Can't include both STDARG.H and VARARGS.H
#endif

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

typedef void _FAR *va_list;

#define __size(x) ((sizeof(x)+sizeof(int)-1) & ~(sizeof(int)-1))

#define va_start(ap, parmN) ((void)((ap) = (va_list)((char _FAR *)(&parmN)+__size(parmN))))
#define va_arg(ap, type) (*(type _FAR *)(((*(char _FAR *_FAR *)&(ap))+=__size(type))-(__size(type))))
#define va_end(ap)          ((void)0)

#if !defined(__STDC__)
#define _va_ptr             (...)
#endif

#endif  /* __STDARG_H */
