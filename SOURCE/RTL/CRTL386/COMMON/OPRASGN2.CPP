/*------------------------------------------------------------------------*/
/*                                                                        */
/*  OPRASGN2.CPP                                                          */
/*                                                                        */
/*  TRegexp& TRegexp::operator = ( const TRegexp& r );                    */
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



#include <regexp.h>
#include <cstring.h>
#include <string.h>
#include <checks.h>

TRegexp _FAR & TRegexp::operator = ( const TRegexp _FAR & r ) throw( xalloc )
{
    if(this != &r)
        {
        delete the_pattern;
        copy_pattern( r );
        }
    return *this;
}


