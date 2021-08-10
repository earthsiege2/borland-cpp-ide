/*------------------------------------------------------------------------*/
/*                                                                        */
/*  ASSIGN.CPP                                                            */
/*                                                                        */
/*  string& string::assign( const string& s, size_t n );                  */
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

string _FAR & string::assign( const string _FAR & s, size_t orig, size_t n )
    throw( xalloc )
{
    if( orig != 0 || n < s.length() )
        {
        size_t loc = min(orig,s.length());
        size_t len = min(s.length()-loc,n);
        TStringRef *temp = new TStringRef( s.c_str()+loc, len, 0, 0, 0 );
        if( p->RemoveReference() == 0 )
            delete p;
        p = temp;
        }
    else
        {
        s.p->AddReference();
        if( p->RemoveReference() == 0 )
            delete p;
        p = s.p;
        }
    return *this;
}


