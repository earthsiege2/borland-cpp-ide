/*  stdarg.h

    Definitions for accessing parameters in functions that accept
    a variable number of arguments.

*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.6.2.1 $ */

#ifndef __STDARG_H
#define __STDARG_H
#define _INC_STDARG  /* MSC Guard name */

#ifdef __VARARGS_H
#error Can't include both STDARG.H and VARARGS.H
#endif

#include <_stddef.h>

#ifdef __cplusplus
namespace std {
#endif /* __cplusplus */

typedef void _FAR *va_list;

#define __size(x) ((sizeof(x)+sizeof(int)-1) & ~(sizeof(int)-1))

#ifdef __cplusplus
#define va_start(ap, parmN) ((void)((ap) = (std::va_list)((char _FAR *)(&parmN)+__size(parmN))))
#else
#define va_start(ap, parmN) ((void)((ap) = (va_list)((char _FAR *)(&parmN)+__size(parmN))))
#endif

#define va_arg(ap, type) (*(type _FAR *)(((*(char _FAR *_FAR *)&(ap))+=__size(type))-(__size(type))))
#define va_end(ap)          ((void)0)

#if !defined(__STDC__)
#define _va_ptr             (...)
#endif

#ifdef __cplusplus
} // std
#endif /* __cplusplus */

#endif  /* __STDARG_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__STDARG_H_USING_LIST)
#define __STDARG_H_USING_LIST
     using std::va_list;
#endif /* __USING_CNAME__ */
