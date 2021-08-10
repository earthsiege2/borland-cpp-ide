//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   fmtval.cpp
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

char* formatVal(char* s, long l)
{
  lconv * conv = localeconv();

  sprintf(s, "%ld", l);

  int group = *conv -> grouping;

  if (!group)
    return s; // no grouping info, quit

  int sLen = strlen(s);

  if (sLen <= group) // not enough chars to worry about.
    return s;

  int tempLen =  sLen + (sLen /3);
  if (!(int)fmod(sLen, 3))
    tempLen--;

  char tempStr[30];
  tempStr[tempLen--] = s[sLen--];

  while (sLen >= group)
  {
    int groupCount = 0;
    while (groupCount < group)
    {
      tempStr[tempLen--] = s[sLen--];
      groupCount++;
    }
    tempStr[tempLen--] = *(conv -> thousands_sep);
  } 

  while (sLen >= 0)
    tempStr[tempLen--] = s[sLen--];

  strcpy(s, tempStr);

  return s;
}
