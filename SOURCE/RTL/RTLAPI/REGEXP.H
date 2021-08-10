/*------------------------------------------------------------------------*/
/*                                                                        */
/*  REGEXP.H                                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __cplusplus
#error Must use C++ for REGEXP.H
#endif

#ifndef __REGEXP_H
#define __REGEXP_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined( __EXCEPT_H )
#include <except.h>
#endif

class _EXPCLASS string;

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TRegexp                                                         */
/*                                                                        */
/*  Implements regular expression searching                               */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _EXPCLASS TRegexp
{

public:

    enum StatVal
    {
        OK=0,
        ILLEGAL,
        TOOLONG
    };

    _RTLENTRY TRegexp( const char _FAR *cp );
    _RTLENTRY TRegexp( const TRegexp _FAR &r );
    _RTLENTRY ~TRegexp();

    TRegexp _FAR & _RTLENTRY operator = ( const TRegexp _FAR &r ) throw( xalloc );
    TRegexp _FAR & _RTLENTRY operator = ( const char _FAR *cp ) throw( xalloc );
    size_t _RTLENTRY find( const string _FAR &s,
                           size_t _FAR *len,
                           size_t start = 0 ) const;
    StatVal _RTLENTRY status() throw();

private:

    void _RTLENTRY copy_pattern( const TRegexp _FAR &r ) throw( xalloc );
    void _RTLENTRY gen_pattern( const char _FAR *cp ) throw( xalloc );

    unsigned char _FAR *the_pattern;
    StatVal stat;
    static const unsigned maxpat;
};

#if defined( BI_OLDNAMES )
#define BI_Regexp TRegexp
#endif

#endif /* __REGEXP_H */
