// $Header:   N:\admin\ocf\source\bocole\utils.cpv   2.0.1.0   10 Apr 1995 18:06:48   CQUINN  $
//**************************************************************************
//
// Utils.h -- Contains some functions to make 32-bit bocole work under WIN95.
//
// Copyright (c) 1995 by Borland International, Inc. All rights reserved
//
//**************************************************************************
#include "BOle.h"
#include "Utils.h"

#ifdef ANSI
LPWSTR lstrcpyW2(LPWSTR lpString1, LPCWSTR lpString2)
{
  while (*lpString1++ = *lpString2++)
  ;

  return lpString1;
}
 
LPWSTR lstrcpynW2(LPWSTR lpString1, LPCWSTR lpString2, int count)
{
  for (int i = 0; i < count; i++)
    *(lpString1+i) = *(lpString2+i);

  return lpString1;
}

LPWSTR lstrcatW2(LPWSTR lpString1, LPCWSTR lpString2)
{
  lstrcpyW2(lpString1+lstrlenW2(lpString1), lpString2);

  return lpString1;
}

int lstrlenW2(LPCWSTR lpString)
{
  int count = 0;

  while (*lpString++)
    count++;

  return count;
}
#endif
