//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.6  $
//
// Implementation of streaming for window system structure and type
// encapsulation
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/wsyscls.h>

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//
// Streaming operators for resource Ids
//
ostream& _WSYSFUNC
operator <<(ostream& os, const TResId& id)
{
  bool  isNumeric = ToBool(!id.IsString());

  if (isNumeric)
    os << id.Num;

  else
#if defined(BI_DATA_NEAR)
    os << string(id.Str);
#else
    os << id.Str;
#endif
  return os;
}

#if defined(BI_NAMESPACE)
}       // namespace ClassLib
#endif

