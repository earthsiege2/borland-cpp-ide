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

#if !defined( __CLASSLIB_DATE_H )
#include "classlib\date.h"
#endif	// __CLASSLIB_DATE_H

#if !defined( __CLASSLIB_OBJSTRM_H )
#include "classlib\objstrm.h"
#endif	// __CLASSLIB_OBJSTRM_H

opstream _BIDSFAR & _BIDSFUNC operator << ( opstream _BIDSFAR & os, const TDate _BIDSFAR & d )
{
    return os << d.Julnum;
}

ipstream _BIDSFAR & _BIDSFUNC operator >> ( ipstream _BIDSFAR & is, TDate _BIDSFAR & d )
{
    return is >> d.Julnum;
}


