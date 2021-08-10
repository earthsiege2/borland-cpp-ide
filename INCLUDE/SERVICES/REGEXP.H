//----------------------------------------------------------------------------
// Borland Services Library
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.2  $
//
// Implementation of class TRegexp -- expression searching
//
//----------------------------------------------------------------------------
#if !defined(SERVICES_REGEX_H)
#define SERVICES_REGEX_H

#if !defined(SERVICES_DEFS_H)
# include <services/defs.h>
#endif
#if !defined(SERVICES_EXCEPT_H )
# include <services/except.h>
#endif

#if defined(BI_COMP_BORLANDC)
# include <regexp.h>

#else

#if !defined(RC_INVOKED)
# if defined(__STDC__)
#   pragma warn -nak
# endif
#endif

class _EXPCLASS string;

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

    TRegexp _FAR & _RTLENTRY operator = ( const TRegexp _FAR &r ) THROW_SPEC1( xalloc );
    TRegexp _FAR & _RTLENTRY operator = ( const char _FAR *cp ) THROW_SPEC1( xalloc );
    size_t _RTLENTRY find( const string _FAR &s,
                           size_t _FAR *len,
                           size_t start = 0 ) const;
    StatVal _RTLENTRY status() THROW_SPEC0;

  private:
    void _RTLENTRY copy_pattern( const TRegexp _FAR &r ) THROW_SPEC1( xalloc );
    void _RTLENTRY gen_pattern( const char _FAR *cp ) THROW_SPEC1( xalloc );

    unsigned char _FAR *the_pattern;
    StatVal stat;
    static const unsigned maxpat;
};

#if defined( BI_OLDNAMES )
# define BI_Regexp TRegexp
#endif

#if !defined(RC_INVOKED)
# if defined(__STDC__)
#   pragma warn .nak
# endif
#endif

#endif

#endif  // SERVICES_REGEX_H
