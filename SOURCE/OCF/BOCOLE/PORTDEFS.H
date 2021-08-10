
//**************************************************************************
// 
// PortDefs.h -- Contains some portability macros which are used to compile
//               the same Bolero codebase for Win3.1 and Win32.
//
// Copyright (c) 1993,94 by Borland International, Inc. All rights reserved
//
//**************************************************************************

#ifndef _portdefs_h
#define _portdefs_h

#ifdef WIN32

#	ifdef FAR
#		undef FAR
#	endif

#	ifdef _FAR
#		undef _FAR
#	endif

#	ifdef __FAR
#		undef __FAR
#	endif

#	ifdef PASCAL
#		undef PASCAL
#	endif

#	ifdef CDECL
#		undef CDECL
#	endif

#	ifdef _CDECL
#		undef _CDECL
#	endif

#	ifdef __CDECL
#		undef __CDECL
#	endif

#	ifdef HUGE
#		undef HUGE
#	endif

#	ifdef _HUGE
#		undef _HUGE
#	endif

#	ifdef __HUGE
#		undef __HUGE
#	endif

#	ifdef _LOADDS
#		undef _LOADDS
#	endif

#define PASCAL          __stdcall
#define __STDC__        TRUE

#ifdef far
#undef far
#define far
#endif

#define FAR			far
#define _FAR
#define __FAR
#define _far


#define CDECL
#define __CDECL
#define _CDECL
#define _cdecl

#define HUGE
#define _HUGE
#define __HUGE
#define huge
#define _huge

#define _LOADDS
#define _loadds

#define MAKEPOINT(l)       (*((POINT FAR *)&(l)))

#define SetViewportExt(a,b,c)   SetViewportExtEx(a,b,c,NULL)
#define SetWindowExt(a,b,c)     SetWindowExtEx(a,b,c,NULL)
#define SetWindowOrg(a,b,c)     SetWindowOrgEx(a,b,c,NULL)
#define MoveTo(a,b,c)           MoveToEx(a,b,c,NULL)
#define GetTextExtent(a,b,c)    GetTextExtentPoint(a,b,c,NULL)
#define OffsetWindowOrg(a,b,c)  OffsetWindowOrgEx(a,b,c,NULL)  

#ifdef  strcmpi
#undef  strcmpi
#endif

// String operations on default character set (Unicode)
#define strcpy(a,b)    lstrcpy(a,b)
#define strlen(a)      lstrlen(a)
#define strcat(a,b)    lstrcat(a,b)
#define strcmp(a,b)    lstrcmp(a,b)
#define strcmpi(a,b)   lstrcmpi(a,b)
#define strupr(a)      CharUpper(a)
#define strlwr(a)      CharLower(a)

// String operations on ANSI
#define strcpyA(a,b)    lstrcpyA(a,b)
#define strlenA(a)      lstrlenA(a)
#define strcatA(a,b)    lstrcatA(a,b)
#define strcmpA(a,b)    lstrcmpA(a,b)
#define strcmpiA(a,b)   lstrcmpiA(a,b)

// String operations on Unicode
#define strcpyW(a,b)    lstrcpyW(a,b)
#define strlenW(a)      lstrlenW(a)
#define strcatW(a,b)    lstrcatW(a,b)
#define strcmpW(a,b)    lstrcmpW(a,b)
#define strcmpiW(a,b)   lstrcmpW(a,b)

#else   /* For 16-bit */

// String operations on ANSI
#define strcpyA(a,b)    strcpy(a,b)
#define strlenA(a)      strlen(a)
#define strcatA(a,b)    strcat(a,b)
#define strcmpA(a,b)    strcmp(a,b)
#define strcmpiA(a,b)   strcmpi(a,b)

// String operations on Unicode: NOT supported in 16 bits -> Generate error
#define strcpyW(a,b)    strcpyW_is_not_supported_in_16_bit()
#define strlenW(a)      strlenW_is_not_supported_in_16_bit()
#define strcatW(a,b)    strcatW_is_not_supported_in_16_bit()
#define strcmpW(a,b)    strcmpW_is_not_supported_in_16_bit()
#define strcmpiW(a,b)   strcmpiW_is_not_supported_in_16_bit()

#ifndef __FAR
#	define __FAR	__far
#endif

#ifndef _CDECL
#	define _CDECL	_cdecl
#endif

#ifndef __CDECL
#	define __CDECL	__cdecl
#endif

#ifndef HUGE
#	define HUGE		huge
#endif

#ifndef _HUGE
#	define  _HUGE	_huge
#endif

#ifndef __HUGE
#	define  __HUGE	__huge
#endif

#ifndef _LOADDS
#	define  _LOADDS	_loadds
#endif

#define TEXT(quote) quote

#if ((!defined LPOLESTR) && (!defined UNICODE))
#define LPOLESTR LPSTR
#endif

#if ((!defined LPTSTR) && (!defined UNICODE))
#define LPTSTR LPSTR
#endif

#if ((!defined LPCOLESTR) && (!defined UNICODE))
#define LPCOLESTR LPCSTR
#define LPCTSTR LPCSTR
#endif

#if ((!defined OLECHAR) && (!defined UNICODE))
#define OLECHAR char
#endif

#define OLESTR(s)  s
#endif

#endif
