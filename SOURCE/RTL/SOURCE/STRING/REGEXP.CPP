/*------------------------------------------------------------------------*/
/*                                                                        */
/*  REGEXP.CPP                                                            */
/*                                                                        */
/*  TRegexp::TRegexp( const char *str );                                  */
/*  TRegexp::TRegexp( const TRegexp& r );                                 */
/*  TRegexp::~TRegexp();                                                  */
/*  void TRegexp::copy_pattern( const TRegexp& r );                       */
/*  void TRegexp::gen_pattern( const char *str );                         */
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



#include <regexp.h>
#include <cstring.h>
#include <string.h>
#include <checks.h>

typedef unsigned char PatternType;

int makepat(const char  _FAR *exp, PatternType  _FAR *pat, size_t maxpattern);
const char _FAR * matchs( const char _FAR *str,
                          const PatternType _FAR *pat,
                          char _FAR * _FAR *startpat);

const unsigned TRegexp::maxpat=128;

TRegexp::TRegexp(const char _FAR * str)
{
    gen_pattern( str );
}

TRegexp::TRegexp(const TRegexp _FAR & r)
{
    copy_pattern( r );
}

TRegexp::~TRegexp()
{
    delete[] the_pattern;
}

void TRegexp::copy_pattern(const TRegexp _FAR & r) throw( xalloc )
{
    the_pattern = new PatternType[maxpat];
    memcpy( the_pattern, r.the_pattern, maxpat );
    stat = r.stat;
}

void TRegexp::gen_pattern(const char _FAR * str) throw( xalloc )
{
    the_pattern = new PatternType[maxpat];
    stat = (StatVal)makepat( str, the_pattern, maxpat );
}

