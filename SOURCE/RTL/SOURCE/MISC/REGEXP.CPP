/*------------------------------------------------------------------------*/
/*                                                                        */
/*  REGEXP.CPP                                                            */
/*                                                                        */
/*  TRegexp::TRegexp( const char *str );                                  */
/*  TRegexp::TRegexp( const TRegexp& r );                                 */
/*  TRegexp::~TRegexp();                                                  */
/*  void TRegexp::copy_pattern( const TRegexp& r );                       */
/*  void TRegexp::gen_pattern( const char *str );                         */
/*  size_t TRegexp::find( const char * str,                               */
/*                        size_t *len,                                    */
/*                        size_t i ) const;                               */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1998, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <regexp.h>
#include <string.h>
#include <checks.h>

typedef unsigned char PatternType;

int _rtl_makepat(const char *exp, PatternType *pat, size_t maxpattern);
const char *_rtl_matchs( const char *str,
                         const PatternType *pat,
                         char  **startpat);

const unsigned TRegexp::maxpat=128;

TRegexp::TRegexp(const char *str)
{
    gen_pattern( str );
}

TRegexp::TRegexp(const TRegexp &r)
{
    copy_pattern( r );
}

TRegexp::~TRegexp()
{
    delete[] the_pattern;
}

void TRegexp::copy_pattern(const TRegexp &r) throw()
{
    the_pattern = new PatternType[maxpat];
    memcpy( the_pattern, r.the_pattern, maxpat );
    stat = r.stat;
}

void TRegexp::gen_pattern(const char *str) throw()
{
    the_pattern = new PatternType[maxpat];
    stat = (StatVal)_rtl_makepat( str, the_pattern, maxpat );
}

size_t TRegexp::find( const char  *str,
                      size_t  *len,
                      size_t i ) const
{
    PRECONDITION( stat==OK );
    char  * startp;
    const char  * s = str;
    const char  * endp = ::_rtl_matchs( s+i, the_pattern, &startp );
    if( endp )
    {
        *len = (size_t)((char  *)endp - startp + 1);
        return (size_t)(startp - (char  *)s);
    }
    else
    {
        *len = 0;
        return -1;
    }
}
