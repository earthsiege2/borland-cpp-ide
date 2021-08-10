/*------------------------------------------------------------------------
 * filename - _printf.h
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.6  $ */


#ifndef __PRINTF_H
#define __PRINTF_H

#if !defined(__STDARG_H)
#include <stdarg.h>
#endif

#if !defined(__STDDEF_H)
#include <stddef.h>
#endif

#include <tchar.h>

#define __XCVTDIG__  40   /* xcvt() maximum digits supported    */
#define __XCVTMAX__  47   /* bytes for longest xcvt() string    */
#define __LTOAMAX__  32   /* bytes for radix 2 longtoa() string */
#define __CVTMAX__   48   /* MAX of the above, + 1 for \0       */

typedef unsigned putnF (const _TCHAR *ptr, unsigned n, void *fp);

/*
    Defining the symbol FLOATS_32_BIT enables recognition of
    32 bit floats on the stack by using the 'h' size modifier.
    YOU, must FORCE the float to be pushed as a 32 bit number
    though!  The compiler normally widens floats to 64 bit doubles.

    example:
            union {
                float f;
                long l
                } u;
            printf("%hg\n", u.l);

    This feature can be DISABLED by default for strict ANSI compatability.
*/
#define FLOATS_32_BIT       1

/*
    Floating point parameter types to formatting functions.
    The numbers are the offset of the fraction in the data type.
*/
#define F_4byteFloat    2
#define F_8byteFloat    6
#define F_10byteFloat   8

/* These must NEVER be the same as an unnormalized 87' exponent! */

#define NAN_number  32766   /* xcvt() -> as NAN exponent    */
#define INF_number  32767   /* xcvt() -> as INF exponent    */


#ifdef __cplusplus
extern "C" {
#endif

int                __vprinter  (putnF *__putter, void *__outP,
                                const char *__formatP, va_list __argP );
int                __vprinterw (putnF *__putter, void *__outP,
                                const _TCHAR *__formatP, va_list __argP );
char *             __longtoa   (long __value, char *__S, int __radix,
                                char __maybeSigned, char __hexStyle);
char *             __int64toa  (__int64 __value, char *__S, int __radix,
                                char __maybeSigned, char __hexStyle);
wchar_t *          __int64tow  (__int64 __value, wchar_t *__S, int __radix,
                                wchar_t __maybeSigned, wchar_t __hexStyle);
void _RTLENTRY     __realcvt   (void *__valueP, int __ndec, char *__strP,
                                char __formCh, char __altFormat, int __type);
va_list _RTLENTRY  __nextreal  (va_list __ap, int __isLongDouble);
char *             __utoa      (unsigned __value, char *__buf);
int                __xcvt      (void *__valP, int __digits, int *__signP,
                                char *__strP, int __ftype);

wchar_t *          __utow      (unsigned __value, wchar_t *__buf);
wchar_t *          __longtow   (long __value, wchar_t *__S, int __radix,
                                wchar_t __maybeSigned, wchar_t __hexStyle);
void _RTLENTRY     __realcvtw  (void *__valueP, int __ndec, wchar_t *__strP,
                                wchar_t __formCh, wchar_t __altFormat, int __type);
va_list _RTLENTRY  __nextrealw (va_list __ap, int __isLongDouble);
int                __xcvtw     (void *__valP, int __digits, int *__signP,
                                wchar_t *__strP, int __ftype);
#ifdef __cplusplus
}
#endif

#endif
