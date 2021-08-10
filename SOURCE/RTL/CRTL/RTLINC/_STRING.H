/*  _string.h

    Definitions for memory and string functions.

    Copyright (c) 1987, 1993 by Borland International
    All Rights Reserved.
*/

#ifndef __STRING_H
#include <string.h>
#endif

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif

char _FAR * _CType _FARFUNC cstrlwr(char _FAR *__s);
char _FAR * _CType _FARFUNC cstrupr(char _FAR *__s);

int         _CType _FARFUNC _strcoll(const char _FAR *__s1, const char _FAR *__s2);
size_t      _CType _FARFUNC _strxfrm(char _FAR *__s1, const char _FAR *__s2,
               size_t __n );

#ifdef __cplusplus
}
#endif

