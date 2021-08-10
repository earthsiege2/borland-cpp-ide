//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.5  $
//
// Implementation of persistent streaming for window system structure and type
// encapsulation
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/geometry.h>

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//----------------------------------------------------------------------------
// TRect streaming
//

//
// Extracts the rectangle from the persistent stream.
//
ipstream& _WSYSFUNC
operator >>(ipstream& is, TRect& r)
{
  return is >> r.left >> r.top >> r.right >> r.bottom;
}

//
// Inserts the rectangle into a persistent stream.
//
opstream& _WSYSFUNC
operator <<(opstream& os, const TRect& r)
{
  return os << r.left << r.top << r.right << r.bottom;
}

//----------------------------------------------------------------------------
// TPointL streaming
//

//
// Extract the point from the input persistent stream.
//
ipstream& _WSYSFUNC
operator >>(ipstream& is, TPointL& p)
{
  long x;
  is >> x;
  p.x = x;

  long y;
  is >> y;
  p.y = y;

  return is;
}

//
// Insert the point into an output persistent stream.
//
opstream& _WSYSFUNC
operator <<(opstream& os, const TPointL& p)
{
  return os << p.x << p.y;
}

//----------------------------------------------------------------------------
// TPointF streaming
//

//
// Extract a point from the persistent input stream.
//
ipstream& _WSYSFUNC
operator >>(ipstream& is, TPointF& p)
{
  return is >> p.x >> p.y;
}

//
// Insert a point into the output persistent stream.
//
opstream& _WSYSFUNC
operator <<(opstream& os, const TPointF& p)
{
  return os << p.x << p.y;
}

//----------------------------------------------------------------------------
// TPoint streaming
//

//
// Extract a point from a persistent input stream.
//
ipstream& _WSYSFUNC
operator >>(ipstream& is, TPoint& p)
{
  return is >> p.x >> p.y;
}

//
// Insert a point into a persistent output stream.
//
opstream& _WSYSFUNC
operator <<(opstream& os, const TPoint& p)
{
  return os << p.x << p.y;
}

//----------------------------------------------------------------------------
// TSize streaming
//

//
// Extract a size from a persistent input stream.
//
ipstream& _WSYSFUNC
operator >>(ipstream& is, TSize& s)
{
  return is >> s.cx >> s.cy;
}

//
// Insert a size into a persistent output stream.
//
opstream& _WSYSFUNC
operator <<(opstream& os, const TSize& s)
{
  return os << s.cx << s.cy;
}

#if defined(BI_NAMESPACE)
} // namespace ClassLib
#endif



