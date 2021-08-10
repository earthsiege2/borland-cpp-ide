/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CASTABLE.CPP                                                          */
/*                                                                        */
/*  Copyright (c) 1992, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( BI_NO_RTTI )
#define BI_NO_RTTI
#endif

#if !defined( CLASSLIB_OBJSTRM_H )
#include <classlib/objstrm.h>
#endif

TStreamableBase::~TStreamableBase()
{
}

void *TStreamableBase::FindBase( Type_id ) const
{
    return 0;
}

