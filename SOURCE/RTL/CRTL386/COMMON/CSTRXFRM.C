/*-----------------------------------------------------------------------*
 * filename - cstrxfrm.c
 *
 * function(s)
 *        _cstrxfrm - transforms a "C" locale only string by coping
 *                    one string into another
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __OS2__

#include <string.h>

size_t _RTLENTRY _EXPFUNC _cstrxfrm( char *s1, const char *s2, size_t n )
{
    int l = strlen( s2 );

    if (n > l)
        memcpy( s1, s2, l+1 );
  
    return( l );
}

#endif /* __OS2__ */
