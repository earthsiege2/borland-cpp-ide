//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.8  $
//
//  RTTI replacement class
//----------------------------------------------------------------------------
#include <classlib/pch.h>
#include <classlib/objstrm.h>

TStreamableBase::~TStreamableBase()
{
}

#if defined(BI_NO_RTTI)

void *TStreamableBase::FindBase( Type_id ) const
{
    return 0;
}

#endif
