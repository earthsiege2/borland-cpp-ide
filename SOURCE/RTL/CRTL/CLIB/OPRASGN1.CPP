/*------------------------------------------------------------------------*/
/*                                                                        */
/*  OPRASGN1.CPP                                                          */
/*                                                                        */
/*  TSubString& TSubString::operator = ( const string& str );             */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1992, 1993 by Borland International
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


TSubString _FAR & TSubString::operator = ( const string _FAR &str ) throw()
{
    if( !is_null() )
        {
        s->cow();
        s->p->splice(begin, min(extent,str.length()-begin),
                     str.c_str(), str.length());
        }
    return *this;
}


