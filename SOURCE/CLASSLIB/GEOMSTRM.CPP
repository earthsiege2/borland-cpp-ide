//----------------------------------------------------------------------------
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//   Implementation of geometry streaming support
//----------------------------------------------------------------------------

#if !defined(_Windows)
# define _Windows      // pretend we are in windows to get the headers we need
#endif

#include <osl/defs.h>
#include <osl/geometry.h>

ostream& _BIDSFUNC
operator <<(ostream& os, const TRect& r)
{
  return os << '(' << r.left << ',' << r.top << '-'
            << r.right << ',' << r.bottom << ')';
}

//
// streaming operators for resource Ids
//
ostream& _BIDSFUNC
operator <<(ostream& os, const TResId& id)
{
  bool  isNumeric = static_cast<bool>(!id.IsString());

  if (isNumeric)
    os << (long)id.Id;

  else
#if defined(BI_DATA_NEAR)
    os << string(id.Id);
#else
    os << id.Id;
#endif
  return os;
}

//! Could break this file in half here...

ipstream& _BIDSFUNC
operator >>(ipstream& is, TRect& r)
{
  return is >> r.left >> r.top >> r.right >> r.bottom;
}

opstream& _BIDSFUNC
operator <<(opstream& os, const TRect& r)
{
  return os << r.left << r.top << r.right << r.bottom;
}

//
// streaming operators for resource Ids
//
ipstream& _BIDSFUNC
operator >>(ipstream& is, TResId& id)
{
  bool  isNumeric;
  is >> isNumeric;

  if (isNumeric) {
    long  nid;
    is >> nid;
    id = int(nid);

  } else
    id = (const char far *)is.freadString();
  return is;
}

opstream& _BIDSFUNC
operator <<(opstream& os, const TResId& id)
{
  bool  isNumeric = static_cast<bool>(!id.IsString());
  os << isNumeric;

  if (isNumeric)
    os << (long)id.Id;

  else
    os.fwriteString(id.Id);
  return os;
}
