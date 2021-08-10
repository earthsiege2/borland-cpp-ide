//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.7  $
//
// TDate class persistant streaming implementation
//----------------------------------------------------------------------------
#include <classlib/pch.h>
#include <classlib/date.h>
#include <classlib/objstrm.h>
#include <strstrea.h>

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

opstream _BIDSFAR & _BIDSFUNC operator << ( opstream _BIDSFAR & os, const TDate _BIDSFAR & d )
{
    return os << d.Julnum;
}

ipstream _BIDSFAR & _BIDSFUNC operator >> ( ipstream _BIDSFAR & is, TDate _BIDSFAR & d )
{
    return is >> d.Julnum;
}

#if defined(BI_NAMESPACE)
}       // namespace ClassLib
#endif

