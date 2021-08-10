/*------------------------------------------------------------------------*/
/*                                                                        */
/*  APPEND2.CPP                                                           */
/*                                                                        */
/*  string& string::append( const char *cp );                             */
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

string _FAR & string::append( const char _FAR *cp )
    throw( xalloc, string::lengtherror )
{
    if( cp != 0 )
        {
        cow();
        p->splice( p->nchars, 0, cp, strlen(cp) );
        }
    return *this;
}


