/*------------------------------------------------------------------------*/
/*                                                                        */
/*  OPREQL.CPP                                                            */
/*                                                                        */
/*  int TSubString::operator == ( const char *cp );                       */
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

int TSubString::operator == ( const char _FAR *cp ) const throw()
{
    if( cp == 0 )
        cp = "";

    if( is_null())
        return 0;

    if( string::get_case_sensitive_flag() )
        return !strncmp( s->p->array + begin, cp, extent );
    else
        return !strnicmp( s->p->array + begin, cp, extent );
}


