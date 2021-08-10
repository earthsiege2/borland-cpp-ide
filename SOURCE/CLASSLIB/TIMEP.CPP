/*------------------------------------------------------------------------*/
/*                                                                        */
/*  TIMEP.CPP                                                             */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __STRSTREA_H )
#include <strstrea.h>
#endif

#if !defined( CLASSLIB_TIME_H )
#include <classlib/time.h>
#endif

#if !defined( CLASSLIB_OBJSTRM_H )
#include <classlib/objstrm.h>
#endif

opstream _BIDSFAR & _BIDSFUNC operator << ( opstream _BIDSFAR & os,
                                            const TTime _BIDSFAR & d )
{
    return os << d.Sec;
}

ipstream _BIDSFAR & _BIDSFUNC operator >> ( ipstream _BIDSFAR & is,
                                            TTime _BIDSFAR & d )
{
    return is >> d.Sec;
}



