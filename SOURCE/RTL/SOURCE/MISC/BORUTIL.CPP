/*------------------------------------------------------------------------
 * filename - borutil.cpp
 *
 *   Various internal utility functions
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1999, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <borutil.h>
#include <string.h>
#include <ctype.h>

extern "C" {

/*
 * Return a pointer to the last directory component in the passed in
 * path.
 */
char const * _RTLENTRY _EXPFUNC basename(char const *fn)
{
  char const *rc = fn;
  while (*fn) {
    switch (*fn++)
    {
      case '/':
      case '\\':
        rc = fn;
        break;
    }
  }

  return rc;
}

/*
 * return the length of the common substring in 's1' and 's2' anchored
 * at the end.  compare the characters without case sensitivity.
 */
_SIZE_T _RTLENTRY _EXPFUNC strirshr(const char *s1, const char *s2)
{
  _SIZE_T n1 = strlen(s1);
  _SIZE_T n2 = strlen(s2);

  s1 += n1;
  s2 += n2;

  // set n1 to shortest string length, use n2 as a counter
  if (n2 < n1)
    n1 = n2;
  n2 = 0;

  /* NOTE: not MBCS or locale aware! */
  while (n2 < n1 && _tolower(*s1) == _tolower(*s2))
  {
    s1--;
    s2--;
    n2++;
  }

  return n2;
}

/*
 * return the length of the common substring in 's1' and 's2' anchored
 * at the end.  compare the characters with case sensitivity.
 */
_SIZE_T _RTLENTRY _EXPFUNC strrshr(const char *s1, const char *s2)
{
  _SIZE_T n1 = strlen(s1);
  _SIZE_T n2 = strlen(s2);

  s1 += n1;
  s2 += n2;

  // set n1 to shortest string length, use n2 as a counter
  if (n2 < n1)
    n1 = n2;
  n2 = 0;

  while (n2 < n1 && *s1 == *s2)
  {
    s1--;
    s2--;
    n2++;
  }

  return n2;
}

/*
 * return the length of the common substring in 's1' and 's2' anchored
 * at the beginning.  compare the characters with case sensitivity.
 */
_SIZE_T _RTLENTRY _EXPFUNC strshr(const char *s1, const char *s2)
{
  const char *p = s1;

  while (*s1 == *s2)
  {
    *s1++;
    *s2++;
  }

  return s1 - p;
}


/*
 * return the length of the common substring in 's1' and 's2' anchored
 * at the beginning.  compare the characters without case sensitivity.
 */
_SIZE_T _RTLENTRY _EXPFUNC strishr(const char *s1, const char *s2)
{
  const char *p = s1;

  /* NOTE: not MBCS or locale aware! */
  while (_tolower(*s1) == _tolower(*s2))
  {
    *s1++;
    *s2++;
  }

  return s1 - p;
}

} /* "C" */