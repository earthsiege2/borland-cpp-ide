//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.6  $
//
// Implementation of persistent streaming for window system structure and type
// encapsulation
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/wsyscls.h>

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//
// Persistent streaming operators for resource Ids
//
ipstream& _WSYSFUNC
operator >>(ipstream& is, TResId& id)
{
  bool  isNumeric;
  is >> isNumeric;

  if (isNumeric) {
    long  nid;
    is >> nid;
    id = int(nid);
  }
  else
    id = (const _TCHAR far *)is.freadString();
  return is;
}

opstream& _WSYSFUNC
operator <<(opstream& os, const TResId& id)
{
  bool  isNumeric = ToBool(!id.IsString());
  os << isNumeric;

  if (isNumeric)
    os << id.Num;

  else
    os.fwriteString(id.Str);
  return os;
}

#if defined(BI_NAMESPACE)
}       // namespace ClassLib
#endif

