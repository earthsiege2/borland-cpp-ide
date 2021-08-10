/*------------------------------------------------------------------------*/
/*                                                                        */
/*  OPRPLUS.CPP                                                           */
/*                                                                        */
/*  string operator + ( const char *cp, const string& s );                */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#if !defined(__FLAT__)
#if defined(__MEDIUM__) || defined(__LARGE__) || defined(__HUGE__)
static void __debug(void){}
#pragma codeseg _TEXTC
#endif
#endif



#include <string.h>
#include <cstring.h>

string _Cdecl _FARFUNC operator + ( const char _FAR *cp,
                                    const string _FAR &s )
    throw( xalloc, string::lengtherror )
{
    return string(cp) + s.c_str();
}


