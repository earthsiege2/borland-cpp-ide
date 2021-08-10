//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.6  $
//
// Implementation of classes for windowing system geometry
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/geometry.h>

#if defined(BI_NAMESPACE)
 namespace ClassLib {
#endif

//
// Calculates the integer square root of a 32bit signed long. Returns a 16bit
// signed. Is fairly fast, esp. compared to FP versions
//
int16 _BIDSFUNC
Sqrt(int32 val)
{
  if (val <= 0)
    return 0;     // Could throw a math exception?

  uint mask = 0x4000;   // Bit mask to shift right
  int best = 0;         // Best estimate so far

  for (; mask; mask >>= 1)
    if (((long)best+mask)*(best+mask) <= val)
      best |= mask;

  return int16(best);
}

#if defined(BI_NAMESPACE)
}         // namespace ClassLib
#endif

//
// Return the distance between the origin and the point.
//
int TPoint::Magnitude() const
{
  return Sqrt(long(x)*long(x)+long(y)*long(y));
}

//
// Return the distance between the origin and the point.
//
int TSize::Magnitude() const
{
  return Sqrt(long(cx)*long(cx)+long(cy)*long(cy));
}

//
// Normalize the rectangle so that left is less than right and
// top is less than bottom.
//
TRect&
TRect::Normalize()
{
  if (left > right)
    Swap(left, right);
  if (top > bottom)
    Swap(top, bottom);
  return *this;
}

//
// Move the rectangle so that the new top left point is (left+dx, top+dy) and
// the new bottom right point is (right+dx, bottom+dy).
//
TRect&
TRect::Offset(int dx, int dy)
{
  left += dx;
  top += dy;
  right += dx;
  bottom += dy;
  return *this;
}

//
// Inflate the rectangle so that new top left point is (left-dx, top-dy) and
// the new bottom right point is (right+dx, bottom+dy).
//
TRect&
TRect::Inflate(int dx, int dy)
{
  left -= dx;
  top -= dy;
  right += dx;
  bottom += dy;
  return *this;
}

//
// Return the largest rectangle that is common to both rectangles.
//
TRect&
TRect::operator &=(const TRect& other)
{
  if (!IsNull()) {
    if (other.IsNull())
      SetNull();
    else {
      left = Max(left, other.left);
      top = Max(top, other.top);
      right = Min(right, other.right);
      bottom = Min(bottom, other.bottom);
    }
  }
  return *this;
}

//
// Return the largest rectangle that contains both rectangles.
//
TRect&
TRect::operator |=(const TRect& other)
{
  if (!other.IsNull()) {
    if (IsNull())
      *this = other;
    else {
      left = Min(left, other.left);
      top = Min(top, other.top);
      right = Max(right, other.right);
      bottom = Max(bottom, other.bottom);
    }
  }
  return *this;
}

//
// Determines the parts of this rect that do not lie within "other"
//
// Resulting rectangles are placed in the "result" array.
//
// Returns the resulting number of rectangles which will be in the
// range "0 .. 4" inclusive
//
int
TRect::Subtract(const TRect& other, TRect result[]) const
{
  // Case of non-intersection, result is just this rectangle
  //
  if (!Touches(other)) {
    result[0] = *this;
    return 1;
  }
  // Check for up to four sub-rectangles produced
  //
  else {
    int  i = 0;

    // Top piece of this rect
    //
    if (other.top > top) {
      result[i].left = left;
      result[i].top = top;
      result[i].right = right;
      result[i].bottom = other.top;
      i++;
    }

    // Bottom piece of this rect
    //
    if (other.bottom < bottom) {
      result[i].left = left;
      result[i].top = other.bottom;
      result[i].right = right;
      result[i].bottom = bottom;
      i++;
    }

    // Left piece of this rect
    //
    if (other.left > left) {
      result[i].left = left;
      result[i].top = max(top, other.top);
      result[i].right = other.left;
      result[i].bottom = min(bottom, other.bottom);
      i++;
    }

    // Right piece of this rect
    //
    if (other.right < right) {
      result[i].left = other.right;
      result[i].top = max(top, other.top);
      result[i].right = right;
      result[i].bottom = min(bottom, other.bottom);
      i++;
    }
    return i;
  }
}
