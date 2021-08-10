/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CASTABLE.CPP                                                          */
/*                                                                        */
/*  Copyright Borland International 1992, 1993                            */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( BI_NO_RTTI )
#define BI_NO_RTTI
#endif

#if !defined( __CLASSLIB_OBJSTRM_H )
#include "classlib\objstrm.h"
#endif	// __CLASSLIB_OBJSTRM_H

TStreamableBase::~TStreamableBase()
{
}

void *TStreamableBase::FindBase( Type_id ) const
{
    return 0;
}

