/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CTOR10.CPP                                                            */
/*                                                                        */
/*  string::string( signed char c );                                      */
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

string::string( signed char c )
    throw( xalloc, string::lengtherror )
{
    p = new TStringRef(c,1);
}

