/*  _ctype.h

    Defines the "C" locale ctype macros.

    Copyright (c) 1987, 1993 by Borland International
    All Rights Reserved.
*/

#ifndef __CTYPE_H
#include <ctype.h>
#endif

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(__LOCALE_H)
#include <locale.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif

int _CType iscalnum (int __c);
int _CType iscalpha (int __c);
int _CType isccntrl (int __c);
int _CType iscdigit (int __c);
int _CType iscgraph (int __c);
int _CType isclower (int __c);
int _CType iscprint (int __c);
int _CType iscpunct (int __c);
int _CType iscspace (int __c);
int _CType iscupper (int __c);
int _CType iscxdigit(int __c);

#ifdef __cplusplus
}
#endif

/* "C" locale only character classification macros */
#define iscalnum(c)  (_ctype[ (c)+1 ] & (_IS_ALNUM))

#define iscalpha(c)  (_ctype[ (c)+1 ] & (_IS_ALPHA))

#define isccntrl(c)  (_ctype[ (c)+1 ] & (_IS_CTL))

#define iscdigit(c)  (_ctype[ (c)+1 ] & (_IS_DIG))

#define iscgraph(c)  (_ctype[ (c)+1 ] & (_IS_GRAPH))

#define isclower(c)  (_ctype[ (c)+1 ] & (_IS_LOW))

#define iscprint(c)  (_ctype[ (c)+1 ] & (_IS_GRAPH | _IS_BLK))

#define iscpunct(c)  (_ctype[ (c)+1 ] & (_IS_PUN))

#define iscspace(c)  (_ctype[ (c)+1 ] & (_IS_SP))

#define iscupper(c)  (_ctype[ (c)+1 ] & (_IS_UPP))

#define iscxdigit(c) (_ctype[ (c)+1 ] & (_IS_HEX))

#define _isctype( c, type )  (int) (_locale->pctype[ (((c) & 0x00ff) +1) ] & (type))

#ifdef __cplusplus
extern "C" {
#endif
int _CType _FARFUNC ctolower(int __ch);
int _CType _fctolower(int __ch);
int _CType _FARFUNC ctoupper(int __ch);
int _CType _fctoupper(int __ch);
int _CType _ftolower(int __ch);
int _CType _ftoupper(int __ch);
#ifdef __cplusplus
}
#endif

#if defined( __USELOCALES__ )

#define _ftoupper  _ltoupper
#define _ftolower  _ltolower

#endif

/* "C" locale only character conversion */
#define ctolower(c) ( _lower[ (c) ] )
#define ctoupper(c) ( _upper[ (c) ] )

