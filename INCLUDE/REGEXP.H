/*------------------------------------------------------------------------*/
/*                                                                        */
/*  REGEXP.H                                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.3  $        */

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

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


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
	NOMEMORY,
        TOOLONG
    };

    _RTLENTRY TRegexp( const char *cp );
    _RTLENTRY TRegexp( const TRegexp &r );
    _RTLENTRY ~TRegexp();

    TRegexp & _RTLENTRY operator = ( const TRegexp &r ) throw();
    TRegexp & _RTLENTRY operator = ( const char *cp )   throw();
    size_t _RTLENTRY find( const char *cp,
                           size_t *len,
                           size_t start = 0 ) const;
    StatVal _RTLENTRY status() throw() { return stat; }

private:

    void _RTLENTRY copy_pattern( const TRegexp &r ) throw();
    void _RTLENTRY gen_pattern( const char *cp )    throw();

    unsigned char *the_pattern;
    StatVal stat;
    static const unsigned maxpat;
};


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif /* __REGEXP_H */
