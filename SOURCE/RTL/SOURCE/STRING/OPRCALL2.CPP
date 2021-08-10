/*------------------------------------------------------------------------*/
/*                                                                        */
/*  OPRCALL2.CPP                                                          */
/*                                                                        */
/*  char& TSubString::operator()( size_t pos );                           */
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

char _FAR & TSubString::operator()( size_t pos ) throw( string::outofrange )
{
    assert_element(pos);
    s->cow();
    return s->p->array[begin+pos];
}


