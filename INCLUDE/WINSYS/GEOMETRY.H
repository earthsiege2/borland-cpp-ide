//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.10  $
//
// Classes for window system geometry
//----------------------------------------------------------------------------
#if !defined(WINSYS_GEOMETRY_H)
#define WINSYS_GEOMETRY_H

#if !defined(WINSYS_DEFS_H)
# include <winsys/defs.h>
#endif
#if !defined(CLASSLIB_OBJSTRM_H)
# include <classlib/objstrm.h>    // Need persist streaming classes & operators
#endif

//
// Forward declare some of the classes defined in this file
//
class _WSYSCLASS TSize;
class _WSYSCLASS TRect;

//
// Integer square root for area calculations. Is fairly fast.
//
int16  Sqrt(int32 val);

//
// Get base window system geometry structs compatible with MSW
//
#if defined(BI_PLAT_MSW)
# if !defined(WINSYS_WSYSINC_H)
#   include <winsys/wsysinc.h>
# endif
# if defined(BI_PLAT_WIN16) && !defined(SERVICES_OLE2INC_H)
#   include <services/ole2inc.h>
# endif
#else
  struct tagPOINT {
    int x;
    int y;
  };
  struct POINTL {
    long x;
    long y;
  };
  struct tagSIZE {
    int cx;
    int cy;
  };
  struct tagRECT {
    int left;
    int top;
    int right;
    int bottom;
  };
#endif

  struct tPOINTF {
    float x;
    float y;
  };


//
// class TPoint
// ~~~~~ ~~~~~~
class _WSYSCLASS TPoint : public tagPOINT {
  public:
    // Constructors
    //
    TPoint();
    TPoint(int _x, int _y);
    TPoint(const tagPOINT far& point);
    TPoint(const TPoint far& point);
    TPoint(const tagSIZE far& size);
    TPoint(uint32 u32);

    // Information functions/operators
    //
    bool        operator ==(const TPoint& other) const;
    bool        operator !=(const TPoint& other) const;
    int         X() const;
    int         Y() const;
    int         Magnitude() const;

    // Functions/binary-operators that return points or sizes
    //
    TPoint      OffsetBy(int dx, int dy) const;
    TPoint      operator +(const TSize& size) const;
    TSize       operator -(const TPoint& point) const;
    TPoint      operator -(const TSize& size) const;
    TPoint      operator -() const;

    // Functions/assignement-operators that modify this point
    //
    TPoint&     Offset(int dx, int dy);
    TPoint&     operator +=(const TSize& size);
    TPoint&     operator -=(const TSize& size);
};

ipstream& _WSYSFUNC operator >>(ipstream& is, TPoint& p);
istream& _WSYSFUNC operator >>(istream& is, TPoint& p);
opstream& _WSYSFUNC operator <<(opstream& os, const TPoint& p);
ostream& _WSYSFUNC operator <<(ostream& os, const TPoint& p);

//
// class TPointL
// ~~~~~ ~~~~~~~
class _WSYSCLASS TPointL : public POINTL {
  public:
    // Constructors
    //
    TPointL();
    TPointL(long _x, long _y);
    TPointL(const POINTL far& point);
    TPointL(const TPointL far& point);

    // Information functions/operators
    //
    bool        operator ==(const TPointL& other) const;
    bool        operator !=(const TPointL& other) const;
    long        X() const;
    long        Y() const;

    // Functions/binary-operators that return points or sizes
    //
    TPointL     OffsetBy(long dx, long dy) const;
    TPointL     operator +(const TSize& size) const;
    TPointL     operator -(const TPointL& point) const;
    TPointL     operator -(const TSize& size) const;
    TPointL     operator -() const;

    // Functions/assignement-operators that modify this point
    //
    TPointL&    Offset(long dx, long dy);
    TPointL&    operator +=(const TSize& size);
    TPointL&    operator -=(const TSize& size);
};

ipstream& _WSYSFUNC operator >>(ipstream& is, TPointL& p);
istream& _WSYSFUNC operator >>(istream& is, TPointL& p);
opstream& _WSYSFUNC operator <<(opstream& os, const TPointL& p);
ostream& _WSYSFUNC operator <<(ostream& os, const TPointL& p);

//
// class TPointF
// ~~~~~ ~~~~~~~
class _WSYSCLASS TPointF : public tPOINTF {
  public:
    // Constructors
    //
    TPointF();
    TPointF(float _x, float _y);
//    TPointF(const tagPOINTF far& point) {x = point.x; y = point.y;}
    TPointF(const TPointF far& point);

    // Information functions/operators
    //
    bool        operator ==(const TPointF& other) const;
    bool        operator !=(const TPointF& other) const;
    float       X() const;
    float       Y() const;

    // Functions/binary-operators that return points or sizes
    //
    TPointF     OffsetBy(float dx, float dy) const;
    TPointF     operator +(const TPointF& size) const;
    TPointF     operator -(const TPointF& point) const;
    TPointF     operator -() const;

    // Functions/assignement-operators that modify this point
    //
    TPointF&    Offset(float dx, float dy);
    TPointF&    operator +=(const TPointF& size);
    TPointF&    operator -=(const TPointF& size);
};

ipstream& _WSYSFUNC operator >>(ipstream& is, TPointF& p);
istream& _WSYSFUNC operator >>(istream& is, TPointF& p);
opstream& _WSYSFUNC operator <<(opstream& os, const TPointF& p);
ostream& _WSYSFUNC operator <<(ostream& os, const TPointF& p);

//
// class TSize
// ~~~~~ ~~~~~
//
class _WSYSCLASS TSize : public tagSIZE {
  public:
    // Constructors
    //
    TSize();
    TSize(int dx, int dy);
    TSize(const tagPOINT far& point);
    TSize(const tagSIZE far& size);
    TSize(const TSize far& size);
    TSize(uint32 dw);

    // Information functions/operators
    //
    bool        operator ==(const TSize& other) const;
    bool        operator !=(const TSize& other) const;
    int         X() const;
    int         Y() const;
    int         Magnitude() const;

    // Functions/binary-operators that return sizes
    //
    TSize      operator +(const TSize& size) const;
    TSize      operator -(const TSize& size) const;
    TSize      operator -() const;

    // Functions/assignement-operators that modify this size
    //
    TSize&     operator +=(const TSize& size);
    TSize&     operator -=(const TSize& size);
};

ipstream& _WSYSFUNC operator >>(ipstream& is, TSize& s);
istream& _WSYSFUNC operator >>(istream& os, TSize& s);
opstream& _WSYSFUNC operator <<(opstream& os, const TSize& s);
ostream& _WSYSFUNC operator <<(ostream& os, const TSize& s);

//
// class TRect
// ~~~~~ ~~~~~
class _WSYSCLASS TRect : public tagRECT {
  public:
    // Constructors
    //
    TRect();
    TRect(const tagRECT far& rect);
    TRect(const TRect far& rect);
    TRect(int _left, int _top, int _right, int _bottom);
    TRect(const TPoint& upLeft, const TPoint& loRight);
    TRect(const TPoint& origin, const TSize& extent);

    // (Re)Initializers
    //
    void        SetNull();
    void        SetEmpty();
    void        Set(int _left, int _top, int _right, int _bottom);
    void        SetWH(int _left, int _top, int w, int h);

    // Type Conversion operators
    //
    operator    const TPoint*() const;
    operator    TPoint*();

    // Testing functions
    //
    bool        IsEmpty() const;
    bool        IsNull() const;
    bool        operator ==(const TRect& other) const;
    bool        operator !=(const TRect& other) const;

    // Information/access functions (const and non-const)
    //
    int         Left() const;
    int         X() const;
    int         Top() const;
    int         Y() const;
    int         Right() const;
    int         Bottom() const;

    const TPoint& TopLeft() const;
    TPoint&     TopLeft();
    TPoint      TopRight() const;
    TPoint      BottomLeft() const;
    const TPoint& BottomRight() const;
    TPoint&     BottomRight();

    int         Width() const;
    int         Height() const;
    TSize       Size() const;
    long        Area() const;

    bool        Contains(const TPoint& point) const;
    bool        Contains(const TRect& other) const;
    bool        Touches(const TRect& other) const;
    TRect       OffsetBy(int dx, int dy) const;
    TRect       operator +(const TSize& size) const;
    TRect       operator -(const TSize& size) const;
    TRect       MovedTo(int x, int y);
    TRect       InflatedBy(int dx, int dy) const;
    TRect       InflatedBy(const TSize& size) const;
    TRect       Normalized() const;
    TRect       operator &(const TRect& other) const;
    TRect       operator |(const TRect& other) const;

    int         Subtract(const TRect& other, TRect result[]) const;

    // Manipulation functions/operators
    //
    TRect&      Normalize();
    TRect&      Offset(int dx, int dy);
    TRect&      operator +=(const TSize& delta);
    TRect&      operator -=(const TSize& delta);
    TRect&      MoveTo(int x, int y);
    TRect&      Inflate(int dx, int dy);
    TRect&      Inflate(const TSize& delta);
    TRect&      operator &=(const TRect& other);
    TRect&      operator |=(const TRect& other);
};

ipstream& _WSYSFUNC operator >>(ipstream& is, TRect& r);
istream& _WSYSFUNC operator >>(istream& is, TRect& r);
opstream& _WSYSFUNC operator <<(opstream& os, const TRect& r);
ostream& _WSYSFUNC operator <<(ostream& os, const TRect& r);

//----------------------------------------------------------------------------
// Inlines
//

//----------------------------------------------------------------------------
// TPoint
//

//
// Construct an uninitialized point.
//
inline
TPoint::TPoint()
{
}

//
// Initialize a point a specific location.
//
inline
TPoint::TPoint(int _x, int _y)
{
  x = _x;
  y = _y;
}

//
// Make a copy of the point.
//
inline
TPoint::TPoint(const tagPOINT far& point)
{
  x = point.x;
  y = point.y;
}

//
// Make a copy of the point.
//
inline
TPoint::TPoint(const TPoint far& point)
{
  x = point.x;
  y = point.y;
}

//
// Create a point whose coordinates is the size.
//
inline
TPoint::TPoint(const tagSIZE far& size)
{
  x = size.cx;
  y = size.cy;
}

//
// Create a point object from a packed point.
// This assumes the x coordinate is in the low word of a double word and
// the y coordinate is in the high word.
//
inline
TPoint::TPoint(uint32 u32)
{
  x = LoInt16(u32);
  y = HiInt16(u32);
}

//
// Return the x coordinate of the point.
//
inline int
TPoint::X() const
{
  return x;
}

//
// Return the Y coordinate of the point.
//
inline int
TPoint::Y() const
{
  return y;
}

//
// Return a point whose coordinate is the coordinate of the current point
// plus passed in coordinates.
//
inline TPoint
TPoint::OffsetBy(int dx, int dy) const
{
  return TPoint(x + dx, y + dy);
}

//
// Return a point whose coordinate is the opposite (negative) of the current
// location.
//
inline TPoint
TPoint::operator -() const
{
  return TPoint(-x, -y);
}

//
// Return true if the location of the two points are the same.
//
inline bool
TPoint::operator ==(const TPoint& other) const
{
  return ToBool(other.x == x && other.y == y);
}

//
// Return true if the locations are not the same.
//
inline bool
TPoint::operator !=(const TPoint& other) const
{
  return ToBool(other.x != x || other.y != y);
}

//
// Return a point whose coordinate is the current location plus the
// size.
//
inline TPoint
TPoint::operator +(const TSize& size) const
{
  return TPoint(x + size.cx, y + size.cy);
}

//
// Return the resulting size of subtracting a location from the current location.
//
inline TSize
TPoint::operator -(const TPoint& point) const
{
  return TSize(x - point.x, y - point.y);
}

//
// Return the resulting point of subtracting a size from the current location.
//
inline TPoint
TPoint::operator -(const TSize& size) const
{
  return TPoint(x - size.cx, y - size.cy);
}

//
// Adjust the current location by the offsets passed.
// Return the resulting location.
//
inline TPoint&
TPoint::Offset(int dx, int dy)
{
  x += dx;
  y += dy;
  return *this;
}

//
// Adjust the current location by the size passed.
// Return the resulting location.
//
inline TPoint&
TPoint::operator +=(const TSize& size)
{
  x += size.cx;
  y += size.cy;
  return *this;
}

//
// Subtract the current location by the size passed.
// Return the resulting location.
//
inline TPoint&
TPoint::operator -=(const TSize& size)
{
  x -= size.cx;
  y -= size.cy;
  return *this;
}

//----------------------------------------------------------------------------
// TPointL
//

//
// Default constructor that does nothing.
//
inline
TPointL::TPointL()
{
}

//
// Construct the point to a specific location.
//
inline
TPointL::TPointL(long _x, long _y)
{
  x = _x;
  y = _y;
}

//
// Alias constructor that initializes from an existing point.
//
inline
TPointL::TPointL(const POINTL far& point)
{
  x = point.x;
  y = point.y;
}

//
// Copy constructor. Makes a copy of the location.
//
inline
TPointL::TPointL(const TPointL far& point)
{
  x = point.x;
  y = point.y;
}

//
// Return the X component of the point.
//
inline long
TPointL::X() const
{
  return x;
}

//
// Return the Y component of the point.
//
inline long
TPointL::Y() const
{
  return y;
}

//
// Return the new point (x+dx, y+dy).
//
inline TPointL
TPointL::OffsetBy(long dx, long dy) const
{
  return TPointL(x + dx, y + dy);
}

//
// Return the negative of the point.
//
inline TPointL
TPointL::operator -() const
{
  return TPointL(-x, -y);
}

//
// Return true if positions are the same.
//
inline bool
TPointL::operator ==(const TPointL& other) const
{
  return ToBool(other.x == x && other.y == y);
}

//
// Return true if the positions are not the same.
//
inline bool
TPointL::operator !=(const TPointL& other) const
{
  return ToBool(other.x != x || other.y != y);
}

//
// Return the new point (x+cx, y+cy).
//
inline TPointL
TPointL::operator +(const TSize& size) const
{
  return TPointL(x + size.cx, y + size.cy);
}

//
// Return the difference between the two points.
//
inline TPointL
TPointL::operator -(const TPointL& point) const
{
  return TPointL(x - point.x, y - point.y);
}

//
// Return the new point (x-cx, y-cy).
//
inline TPointL
TPointL::operator -(const TSize& size) const
{
  return TPointL(x - size.cx, y - size.cy);
}

//
// Return the point (x+dx, y+dy).
//
inline TPointL&
TPointL::Offset(long dx, long dy)
{
  x += dx;
  y += dy;
  return *this;
}

//
// Return the point (x+cx, y+cy).
//
inline TPointL&
TPointL::operator +=(const TSize& size)
{
  x += size.cx;
  y += size.cy;
  return *this;
}

//
// Return the point (x-cx, y-cy).
//
inline TPointL&
TPointL::operator -=(const TSize& size)
{
  x -= size.cx;
  y -= size.cy;
  return *this;
}


//----------------------------------------------------------------------------
// TPointF
//

//
// Default constructor that does nothing.
//
inline
TPointF::TPointF()
{
}

//
// Constructor that initializes the location.
//
inline
TPointF::TPointF(float _x, float _y)
{
  x = _x;
  y = _y;
}

//
// Constructor that copies the location.
//
inline
TPointF::TPointF(const TPointF far& point)
{
  x = point.x;
  y = point.y;
}

//
// Return X component of the point.
//
inline float
TPointF::X() const
{
  return x;
}

//
// Return Y component of the point.
//
inline float
TPointF::Y() const
{
  return y;
}

//
// Move the point by an offset.
//
inline TPointF
TPointF::OffsetBy(float dx, float dy) const
{
  return TPointF(x + dx, y + dy);
}

//
// Return the negative of the point.
//
inline TPointF
TPointF::operator -() const
{
  return TPointF(-x, -y);
}

//
// Return true if the points are at the same location.
//
inline bool
TPointF::operator ==(const TPointF& other) const
{
  return ToBool(other.x == x && other.y == y);
}

//
// Return true if the points are not at the same location.
//
inline bool
TPointF::operator !=(const TPointF& other) const
{
  return ToBool(other.x != x || other.y != y);
}

//
// Return a new point (x+cx, y+cy).
//
inline TPointF
TPointF::operator +(const TPointF& size) const
{
  return TPointF(x + size.x, y + size.y);
}

//
// Return a new point subtracted from the current point.
//
inline TPointF
TPointF::operator -(const TPointF& point) const
{
  return TPointF(x - point.x, y - point.y);
}

//
// Move the point by an offset.
//
inline TPointF&
TPointF::Offset(float dx, float dy)
{
  x += dx;
  y += dy;
  return *this;
}

//
// Return the new point moved by the offset.
//
inline TPointF&
TPointF::operator +=(const TPointF& size)
{
  x += size.x;
  y += size.y;
  return *this;
}

//
// Return the new point subtracted from the current.
//
inline TPointF&
TPointF::operator -=(const TPointF& size)
{
  x -= size.x;
  y -= size.y;
  return *this;
}

//----------------------------------------------------------------------------
// TRect
//

//
// Default constructor that does nothing.
//
inline
TRect::TRect()
{
}

//
// Create an empty rectangle.
//
inline void
TRect::SetEmpty()
{
  SetNull();
}

//
// Return an array of two points (upperleft and bottomright)
//
inline
TRect::operator const TPoint*() const
{
  return (const TPoint*)this;
}

//
// Return an array of two points (upperleft and bottomright)
//
inline
TRect::operator TPoint*()
{
  return (TPoint*)this;
}

//
// Return the left value.
//
inline int
TRect::Left() const
{
  return left;
}

//
// Return the left value.
//
inline int
TRect::X() const
{
  return left;
}

//
// Return the top value.
//
inline int
TRect::Top() const
{
  return top;
}

//
// Return the top value.
//
inline int
TRect::Y() const
{
  return top;
}

//
// Return the right value.
//
inline int
TRect::Right() const
{
  return right;
}

//
// Return the bottom value.
//
inline int
TRect::Bottom() const
{
  return bottom;
}

//
// Return the upperleft point.
//
inline const TPoint&
TRect::TopLeft() const
{
  return *(TPoint*)&left;
}

//
// Return the upperleft point.
//
inline TPoint&
TRect::TopLeft()
{
  return *(TPoint*)&left;
}

//
// Return the upperright point.
//
inline TPoint
TRect::TopRight() const
{
  return TPoint(right, top);
}

//
// Return the bottomleft point.
//
inline TPoint
TRect::BottomLeft() const
{
  return TPoint(left, bottom);
}

//
// Return the bottomright point.
//
inline const TPoint&
TRect::BottomRight() const
{
  return *(TPoint*)&right;
}

//
// Return the bottomright point.
//
inline TPoint&
TRect::BottomRight()
{
  return *(TPoint*)&right;
}

//
// Return the width of the rectangle.
//
inline int
TRect::Width() const
{
  return right-left;
}

//
// Return the height of the rectangle.
//
inline int
TRect::Height() const
{
  return bottom-top;
}

//
// Return the size of rectangle.
//
inline TSize
TRect::Size() const
{
  return TSize(Width(), Height());
}

//
// Return the area of th rectangle.
//
inline long
TRect::Area() const
{
  return long(Width())*long(Height());
}

//
// Set all the data members to 0.
//
inline void
TRect::SetNull()
{
  left = 0;
  top = 0;
  right = 0;
  bottom = 0;
}

//
// Explicitly set all of the coordinates of the rectangle.
//
inline void
TRect::Set(int _left, int _top, int _right, int _bottom)
{
  left = _left;
  top = _top;
  right = _right;
  bottom = _bottom;
}

//
// Determine the rectangle, given its upperleft point, width, and height
//
inline void
TRect::SetWH(int _left, int _top, int w, int h)
{
  left = _left;
  top = _top;
  right = _left + w;
  bottom = _top + h;
}

//
// Copy from an existing rectangle.
//
inline
TRect::TRect(const tagRECT far& rect)
{
  *(tagRECT far*)this = rect;
}

//
// Copy from an existing rectangle.
//
inline
TRect::TRect(const TRect far& rect)
{
  *(tagRECT far*)this = *(tagRECT far*)&rect;
}

//
// Constructor that sets all the values explicitly.
//
inline
TRect::TRect(int _left, int _top, int _right, int _bottom)
{
  Set(_left, _top, _right, _bottom);
}

//
// Determine a rectangle given two points.
//
inline
TRect::TRect(const TPoint& topLeft, const TPoint& bottomRight)
{
  Set(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y);
}

//
// Determine a rectangle given its upper left point and a dimension.
//
inline
TRect::TRect(const TPoint& origin, const TSize& extent)
{
  Set(origin.x, origin.y, origin.x + extent.cx, origin.y + extent.cy);
}

//
// Return true if the rectangle is empty.
//
inline bool
TRect::IsEmpty() const
{
  return ToBool(left >= right || top >= bottom);
}

//
// Return true if all of the points on the rectangle is 0.
//
inline bool
TRect::IsNull() const
{
  return ToBool(!left && !right && !top && !bottom);
}

//
// A rectangle is equal to another if all of their points are identical.
//
inline bool
TRect::operator ==(const TRect& other) const
{
  return ToBool(other.left==left   && other.top==top
             && other.right==right && other.bottom==bottom);
}

//
// Return the opposite of operator ==.
//
inline bool
TRect::operator !=(const TRect& other) const
{
  return ToBool(!(other==*this));
}

//
// Return true if the rectangle contains the point.
//
inline bool
TRect::Contains(const TPoint& point) const
{
  return ToBool(point.x >= left && point.x < right
             && point.y >= top  && point.y < bottom);
}

//
// Return true if the rectangle complete surrounds the other.
//
inline bool
TRect::Contains(const TRect& other) const
{
  return ToBool(other.left >= left && other.right <= right
             && other.top >= top   && other.bottom <= bottom);
}

//
// Return true if the intersection of the two rectangles is not null.
//
inline bool
TRect::Touches(const TRect& other) const
{
  return ToBool(other.right > left && other.left < right
             && other.bottom > top && other.top < bottom);
}

//
// Move the points of the rectangle by the offsets.
//
inline TRect
TRect::OffsetBy(int dx, int dy) const
{
  return TRect(left+dx, top+dy, right+dx, bottom+dy);
}

//
// Move the points of the rectangle by the offsets.
//
inline TRect
TRect::operator +(const TSize& size) const
{
  return OffsetBy(size.cx, size.cy);
}

//
// Move the points of the rectangle negatively by the offsets.
//
inline TRect
TRect::operator -(const TSize& size) const
{
  return OffsetBy(-size.cx, -size.cy);
}

//
// Move the upper left point of the rectangle while maintaining the
// current dimension.
//
inline TRect
TRect::MovedTo(int x, int y)
{
  return TRect(x, y, x + Width(), y + Height());
}

//
// Inflate the size of the rectangle.
//
inline TRect
TRect::InflatedBy(int dx, int dy) const
{
  return TRect(left-dx, top-dy, right+dx, bottom+dy);
}

//
// Inflate the size of the rectangle.
//
inline TRect
TRect::InflatedBy(const TSize& size) const
{
  return InflatedBy(size.cx, size.cy);
}

//
// Normalize the rectangle, such that left is less than  right and
// top is less than bottom.
//
inline TRect
TRect::Normalized() const
{
  return TRect(Min(left, right), Min(top, bottom),
               Max(left, right), Max(top, bottom));
}

//
// Return the intersection of two rectangles.
//
inline TRect
TRect::operator &(const TRect& other) const
{
  if (Touches(other))
    return TRect(Max(left, other.left), Max(top, other.top),
                 Min(right, other.right), Min(bottom, other.bottom));
  return TRect(0, 0, 0, 0);
}

//
// Return the union of two rectangles.
//
inline TRect
TRect::operator |(const TRect& other) const
{
  return TRect(Min(left, other.left), Min(top, other.top),
               Max(right, other.right), Max(bottom, other.bottom));
}

//
// Move the rectangle by delta.
//
inline TRect&
TRect::operator +=(const TSize& delta)
{
  Offset(delta.cx, delta.cy);
  return *this;
}

//
// Move the rectangle by negative delta.
//
inline TRect&
TRect::operator -=(const TSize& delta)
{
  return *this += -delta;
}

//
// Move the upper left corner of the rectangle to a new location and
// maintain the current dimension.
//
inline TRect&
TRect::MoveTo(int x, int y)
{
  right = x + Width();
  bottom = y + Height();
  left = x;
  top = y;
  return *this;
}

//
// Inflate the size of the rectangle by delta.
//
inline TRect&
TRect::Inflate(const TSize& delta)
{
  return Inflate(delta.cx, delta.cy);
}


//----------------------------------------------------------------------------
// TSize
//

//
// Default constructor that does nothing.
//
inline
TSize::TSize()
{

}

//
// Constructor to initialize the size.
//
inline
TSize::TSize(int dx, int dy)
{
  cx = dx;
  cy = dy;
}

//
// Constructor to initialize from an existing point.
//
inline
TSize::TSize(const tagPOINT far& point)
{
  cx = point.x;
  cy = point.y;
}

//
// Constructor to initialize from an existing size.
//
inline
TSize::TSize(const tagSIZE far& size)
{
  cx = size.cx;
  cy = size.cy;
}

//
// Constructor to initialize from an existing size.
//
inline
TSize::TSize(const TSize far& size)
{
  cx = size.cx;
  cy = size.cy;
}

//
// Constructor that assumes the high-word of a long is the width
// and the low-word of a long is the height.
//
inline
TSize::TSize(uint32 dw)
{
  cx = LoUint16(dw);
  cy = HiUint16(dw);
}

//
// Return the width.
//
inline int
TSize::X() const
{
  return cx;
}

//
// Return the height.
//
inline int
TSize::Y() const
{
  return cy;
}

//
//
//
inline TSize
TSize::operator -() const
{
  return TSize(-cx, -cy);
}

//
// Return true if the sizes are identical.
//
inline bool
TSize::operator ==(const TSize& other) const
{
  return ToBool(other.cx==cx && other.cy==cy);
}

//
// Return true if the sizes are not identical.
//
inline bool
TSize::operator !=(const TSize& other) const
{
  return ToBool(other.cx!=cx || other.cy!=cy);
}

//
// Increase the width and height by size.
//
inline TSize
TSize::operator +(const TSize& size) const
{
  return TSize(cx+size.cx, cy+size.cy);
}

//
// Decrease the width and height by size.
//
inline TSize
TSize::operator -(const TSize& size) const
{
  return TSize(cx-size.cx, cy-size.cy);
}

//
// Increase the width and height by size.
//
inline TSize&
TSize::operator +=(const TSize& size)
{
  cx += size.cx;
  cy += size.cy;
  return *this;
}

//
// Decrease the width and height by size.
//
inline TSize&
TSize::operator -=(const TSize& size)
{
  cx -= size.cx;
  cy -= size.cy;
  return *this;
}

#endif  // WINSYS_GEOMETRY_H
