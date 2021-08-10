/*------------------------------------------------------------------------*/
/*                                                                        */
/*  DATEP.CPP                                                             */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __STRSTREA_H )
#include <strstrea.h>
#endif

#if !defined( CLASSLIB_DATE_H )
#include <classlib/date.h>
#endif

#if !defined( CLASSLIB_OBJSTRM_H )
#include <classlib/objstrm.h>
#endif

opstream _BIDSFAR & _BIDSFUNC operator << ( opstream _BIDSFAR & os, const TDate _BIDSFAR & d )
{
    return os << d.Julnum;
}

ipstream _BIDSFAR & _BIDSFUNC operator >> ( ipstream _BIDSFAR & is, TDate _BIDSFAR & d )
{
    return is >> d.Julnum;
}


