// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Types.pas' rev: 6.00

#ifndef TypesHPP
#define TypesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Types
{
  struct TPoint : public POINT
  {
    TPoint() {}
    TPoint(int _x, int _y) { x=_x; y=_y; }
    TPoint(POINT& pt)
    {
      x = pt.x;
      y = pt.y;
    }
  };
 
  typedef TPoint tagPoint;
 
  struct TRect : public RECT
  {
    TRect() {}
    TRect(const TPoint& TL, const TPoint& BR) { left=TL.x; top=TL.y; right=BR.x; bottom=BR.y; }
    TRect(int l, int t, int r, int b)         { left=l;    top=t;    right=r;    bottom=b;    }
    TRect(RECT& r)
    {
      left    = r.left;
      top     = r.top;
      right   = r.right;
      bottom  = r.bottom;
    }
    int Width () const { return right  - left; }
    int Height() const { return bottom - top ; }
    bool operator ==(const TRect& rc) const 
    {
       return left ==  rc.left  && top==rc.top &&     
              right == rc.right && bottom==rc.bottom; 
    }
    bool operator !=(const TRect& rc) const 
    {  return !(rc==*this); }
 
       __property LONG Left    = { read=left,   write=left   }; 
       __property LONG Top     = { read=top,       write=top }; 
       __property LONG Right   = { read=right,  write=right  }; 
       __property LONG Bottom  = { read=bottom, write=bottom }; 
  };
} /* namespace Types */ ;

namespace Types
{
//-- type declarations -------------------------------------------------------
typedef TPoint *PPoint;

typedef TRect *PRect;

typedef tagSIZE *PSize;

typedef tagSIZE  TSize;

struct TSmallPoint;
typedef TSmallPoint *PSmallPoint;

#pragma pack(push, 1)
struct TSmallPoint
{
	short x;
	short y;
} ;
#pragma pack(pop)

typedef Shortint TValueRelationship;

//-- var, const, procedure ---------------------------------------------------
static const Shortint LessThanValue = 0xffffffff;
static const Shortint EqualsValue = 0x0;
static const Shortint GreaterThanValue = 0x1;
extern PACKAGE bool __fastcall EqualRect(const TRect &R1, const TRect &R2);
extern PACKAGE bool __fastcall PtInRect(const TRect &Rect, const TPoint &P);
extern PACKAGE bool __fastcall IntersectRect(/* out */ TRect &Rect, const TRect &R1, const TRect &R2);
extern PACKAGE bool __fastcall UnionRect(/* out */ TRect &Rect, const TRect &R1, const TRect &R2);
extern PACKAGE bool __fastcall IsRectEmpty(const TRect &Rect);
extern PACKAGE bool __fastcall OffsetRect(TRect &Rect, int DX, int DY);
extern PACKAGE TPoint __fastcall CenterPoint(const TRect &Rect);

}	/* namespace Types */
using namespace Types;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Types
