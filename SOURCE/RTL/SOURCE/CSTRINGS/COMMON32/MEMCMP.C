/*-----------------------------------------------------------------------*
 * filename - memcmp.c
 *
 * function(s)
 *        memcmp - compare two memory arrays
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <mem.h>

/*-----------------------------------------------------------------------*

Name            memcmp - compare two memory arrays

Usage           int memcmp(const void *s1, const void *s2, size_t n);

Prototype in    mem.h & string.h

Description     memcmp compares two  memory areas, s1 and s2,  for a length
                of  exactly  n  bytes.  This  function  compares  bytes  as
                unsigned chars, so
                memcmp ("\0xFF", "\0x7F", 1)
                returns a positive value.

Return value    < 0 if s1 is less than s2
                = 0 if s1 is the same as s2
                > 0 if s1 is greater than s2

*------------------------------------------------------------------------*/

#ifdef memcmp
#  undef memcmp
#  define INTRINSIC
#endif

int _RTLENTRY _EXPFUNC memcmp(const void *s1, const void *s2, size_t n)
{
#ifdef INTRINSIC
    return __memcmp__(s1, s2, n);
#else
    unsigned char *p1 = (unsigned char *)s1;
    unsigned char *p2 = (unsigned char *)s2;

	if ( !n )
		return 0;
	
    while ( n-- )
        {
        if (*p1 == *p2)
            {
            ++p1;
            ++p2;
            }
        else
            return *p1 - *p2;
        }
    return  *(p1-1) - *(p2-1);
#endif
}
