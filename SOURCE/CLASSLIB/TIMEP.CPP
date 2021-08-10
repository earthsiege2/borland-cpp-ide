//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.7  $
//
// TTime class persistent streaming implementation
//----------------------------------------------------------------------------
#include <classlib/pch.h>
#include <classlib/time.h>
#include <classlib/objstrm.h>
#include <strstrea.h>

#if defined(BI_NAMESPACE)
namespace ClassLib {
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

#if defined(BI_NAMESPACE)
}     // namespace ClassLib
#endif
