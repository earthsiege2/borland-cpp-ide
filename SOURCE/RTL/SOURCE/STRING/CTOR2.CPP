/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CTOR2.CPP                                                             */
/*                                                                        */
/*  string::string( const string& s );                                    */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1992, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__FLAT__)
#if defined(__MEDIUM__) || defined(__LARGE__) || defined(__HUGE__)
static void __debug(void){}
#pragma codeseg _TEXTC
#endif
#endif



#include <string.h>
#include <cstring.h>

string::string( const string _FAR &s ) throw( xalloc )
{
    p = s.p;
    p->AddReference();
}


