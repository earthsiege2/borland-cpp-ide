//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.5  $
//
// Implementation of persistent streaming for window system geometry classes
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
// Extracts the rectangle from a regular input stream.
//
istream& _WSYSFUNC
operator >>(istream& is, TRect& r)
{
  _TCHAR ch;
  return is >> ch >> r.left >> ch >> r.top >> ch
            >> r.right >> ch >> r.bottom >> ch;
}

//
// Inserts the rectangle into a regular output stream.
//
ostream& _WSYSFUNC
operator <<(ostream& os, const TRect& r)
{
  return os << '(' << r.left << ',' << r.top << '-'
            << r.right << ',' << r.bottom << ')';
}

//----------------------------------------------------------------------------
// TPointL streaming
//

//
// Extract the point from a regular input stream.
//
istream& _WSYSFUNC
operator >>(istream& is, TPointL& p)
{
  _TCHAR c;

  is >> c;

  long x;
  is >> x;
  p.x = x;

  is >> c;

  long y;
  is >> y;
  p.y = y;

  is >> c;

  return is;
}

//
// Insert the point into an output stream.
//
ostream& _WSYSFUNC
operator <<(ostream& os, const TPointL& p)
{
  return os << '(' << p.x << ',' << p.y << ')';
}

//----------------------------------------------------------------------------
// TPointF streaming
//

//
// Extract a point from a regular input stream.
//
istream& _WSYSFUNC
operator >>(istream& is, TPointF& p)
{
  _TCHAR c;
  return is >> c >> p.x >> c >> p.y >> c;
}

//
// Insert a point into the output stream.
//
ostream& _WSYSFUNC
operator <<(ostream& os, const TPointF& p)
{
  return os << '(' << p.x << ',' << p.y << ')';
}


//----------------------------------------------------------------------------
// TPoint streaming
//

//
// Extract a point from an input stream.
//
istream& _WSYSFUNC
operator >>(istream& is, TPoint& p)
{
  _TCHAR c;
  return is >> c >> p.x >> c >> p.y >> c;
}

//
// Insert a point into an output stream.
//
ostream& _WSYSFUNC
operator <<(ostream& os, const TPoint& p)
{
  return os << '(' << p.x << ',' << p.y << ')';
}

//----------------------------------------------------------------------------
// TSize streaming
//

//
// Extract a size from a regular input stream.
//
istream& _WSYSFUNC
operator >>(istream& os, TSize& s)
{
  _TCHAR c;
  return os >> c >> s.cx >> c >> s.cy >> c;
}

//
// Insert a size into an output stream.
//
ostream& _WSYSFUNC
operator <<(ostream& os, const TSize& s)
{
  return os << '(' << s.cx << 'x' << s.cy << ')';
}

#if defined(BI_NAMESPACE)
} // namespace ClassLib
#endif
