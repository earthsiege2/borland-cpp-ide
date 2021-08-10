/*------------------------------------------------------------------------*/
/*                                                                        */
/*  FIND2.CPP                                                             */
/*                                                                        */
/*  size_t TRegexp::find( const string& string,                           */
/*                        size_t *len,                                    */
/*                        size_t i ) const;                               */
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

typedef unsigned char PatternType;

int makepat(const char  _FAR *exp, PatternType  _FAR *pat, size_t maxpattern);
const char _FAR * matchs( const char _FAR *str,
                          const PatternType _FAR *pat,
                          char _FAR * _FAR *startpat);

size_t TRegexp::find( const string _FAR &string,
                      size_t _FAR *len,
                      size_t i ) const
{
    PRECONDITION( stat==OK );
    char _FAR * startp;
    const char _FAR * s = string.c_str();
    const char _FAR * endp = ::matchs( s+i, the_pattern, &startp );
    if( endp )
        {
        *len = (char _FAR *)endp - startp + 1;
        return startp - (char _FAR *)s;
        }
    else
        {
        *len = 0;
        return -1;
        }
}


