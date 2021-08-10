/*------------------------------------------------------------------------*/
/*                                                                        */
/*  COMPARE1.CPP                                                          */
/*                                                                        */
/*  int string::compare( const string& s ) const;                         */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1992, 1994 by Borland International
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

int string::compare( const string _FAR &s ) const throw()
{
    if( get_case_sensitive_flag() )
        return strcmp( c_str(), s.c_str() );
    else
        return stricmp( c_str(), s.c_str() );
}


