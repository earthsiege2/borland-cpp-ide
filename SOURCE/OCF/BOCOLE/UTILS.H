// $Header:   N:\admin\ocf\source\bocole\utils.h_v   2.0.1.0   10 Apr 1995 18:06:50   CQUINN  $
//**************************************************************************
//
// Utils.h -- Contains some functions to make 32-bit bocole work under Win95.
//
// Copyright (c) 1995 by Borland International, Inc. All rights reserved
//
//**************************************************************************

#ifndef _utils_h
#define _utils_h

#undef lstrcpy
#undef lstrlen
#undef lstrcpyn
#undef lstrcat

#define lstrcpy(a,b)  lstrcpyW2(a,b)
#define lstrlen(a)    lstrlenW2(a)
#define lstrcpyn(a, b, c)   lstrcpynW2(a, b, c)
#define lstrcat(a, b)   lstrcatW2(a, b)

LPWSTR lstrcpyW2(LPWSTR lpString1, LPCWSTR lpString2);
int lstrlenW2(LPCWSTR lpString);
LPWSTR lstrcpynW2(LPWSTR lpString1, LPCWSTR lpString2, int iMaxLength);
LPWSTR lstrcatW2(LPWSTR lpString1, LPCWSTR lpString2);

#undef MAKEINTRESOURCEW
#define MAKEINTRESOURCEW  MAKEINTRESOURCEA
#define LoadCursorW LoadCursorA
#define DefWindowProcW DefWindowProcA

#endif  // _utils_h
