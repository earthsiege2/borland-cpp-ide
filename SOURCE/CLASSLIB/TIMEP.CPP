/*------------------------------------------------------------------------*/
/*                                                                        */
/*  DATEP.CPP                                                             */
/*                                                                        */
/*  Copyright Borland International 1993                                  */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __STRSTREA_H )
#include <strstrea.h>
#endif	// __STRSTREA_H

#if !defined( __CLASSLIB_TIME_H )
#include "classlib\time.h"
#endif	// __CLASSLIB_TIME_H

#if !defined( __CLASSLIB_OBJSTRM_H )
#include "classlib\objstrm.h"
#endif	// __CLASSLIB_OBJSTRM_H

opstream _BIDSFAR & _BIDSFUNC operator << ( opstream _BIDSFAR & os, const TTime _BIDSFAR & d )
{
    return os << d.Sec;
}

ipstream _BIDSFAR & _BIDSFUNC operator >> ( ipstream _BIDSFAR & is, TTime _BIDSFAR & d )
{
    return is >> d.Sec;
}



