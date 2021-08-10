//----------------------------------------------------------------------------
// Borland Services Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.7  $
//
// Implementation of memory manipulation functions
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <services/memory.h>
#include <classlib/stdtempl.h>
#include <tchar.h>

//
// Make a duplicate of a 0-terminated string using new char[]
//
_TCHAR* _SVCSFUNC
strnewdup(const _TCHAR* s, size_t allocSize)
{
  if (!s)
    s = "";
  int alloc = max(_tcslen(s)+1, allocSize);
  return _tcscpy(new _TCHAR[alloc], s);
}

//
// Make a far duplicate of a 0-terminated string using new char[] far
//
#if defined(BI_DATA_NEAR)

_TCHAR far*  _SVCSFUNC
strnewdup(const _TCHAR far* s, size_t allocSize)
{
  if (!s)
    s = "";
  int alloc = max(_tcslen(s)+1, allocSize);
  return _tcscpy(new far _TCHAR[alloc], s);
}

_TCHAR*  _SVCSFUNC
nstrnewdup(const _TCHAR far* s, size_t allocSize)
{
  if (!s)
    s = "";
  int alloc = max(_tcslen(s)+1, allocSize);
  _TCHAR* dst = new _TCHAR[alloc];
  _tcscpy(dst, s);
  return dst;
}

long
atol(const _TCHAR far* s)
{
  long val;
  for (val = 0; *s && _istdigit(*s); s++)
    val = val*10 + *s - '0';
  return val;
}

#endif

//
#if !defined(BI_PLAT_WIN16)

//
// Make a duplicate of a wide 0-terminated string using new wchar_t[]
//
wchar_t* _SVCSFUNC
strnewdup(const wchar_t* s, size_t allocSize)
{
  if (!s)
    s = L"";
  int alloc = max((size_t)_tcslen(s)+1, allocSize);
  return _tcscpy(new wchar_t[alloc], s);
}

//
// Wide string copy function.
//
wchar_t* _SVCSFUNC
_tcscpy(wchar_t* dst, const wchar_t* src)
{
  wchar_t* p = dst;
  while ((*p++ = *src++) != 0)
    ;
  return dst;
}

//
// Wide string length function.
//
size_t _SVCSFUNC
_tcslen(const wchar_t* str)
{
  const wchar_t* p = str;
  for (; *p; p++)
    ;
  return p - str;
}

#endif
