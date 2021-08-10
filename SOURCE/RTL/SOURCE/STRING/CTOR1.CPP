/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CTOR1.CPP                                                             */
/*                                                                        */
/*  string::string();                                                     */
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

string::string() throw( xalloc )
{
    p = new TStringRef(0,0,0,0,string::get_initial_capacity());
}


