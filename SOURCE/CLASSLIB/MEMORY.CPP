//----------------------------------------------------------------------------
// Borland Services Library
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.5  $
//
// Implementation of memory manipulation functions
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <services/memory.h>
#include <classlib/stdtempl.h>

//
// Make a duplicate of a 0-terminated string using new char[]
//
char* _SVCSFUNC
strnewdup(const char* s, size_t allocSize)
{
  if (!s)
    s = "";
  int alloc = max(strlen(s)+1, allocSize);
  return strcpy(new char[alloc], s);
}

//
// Make a far duplicate of a 0-terminated string using new char[] far
//
#if defined(BI_DATA_NEAR)

char far*  _SVCSFUNC
strnewdup(const char far* s, size_t allocSize)
{
  if (!s)
    s = "";
  int alloc = max(strlen(s)+1, allocSize);
  return strcpy(new far char[alloc], s);
}

char*  _SVCSFUNC
nstrnewdup(const char far* s, size_t allocSize)
{
  if (!s)
    s = "";
  int alloc = max(strlen(s)+1, allocSize);
  char* dst = new char[alloc];
  strcpy(dst, s);
  return dst;
}

long
atol(const char far* s)
{
  long val;
  for (val = 0; *s && isdigit(*s); s++)
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
  int alloc = max((size_t)strlen(s)+1, allocSize);
  return strcpy(new wchar_t[alloc], s);
}

//
// Wide string copy function. 
//
wchar_t* _SVCSFUNC
strcpy(wchar_t* dst, const wchar_t* src)
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
strlen(const wchar_t* str)
{
  const wchar_t* p = str;
  for (; *p; p++)
    ;
  return p - str;
}

#endif
