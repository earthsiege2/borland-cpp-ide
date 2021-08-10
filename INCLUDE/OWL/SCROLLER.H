//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of class TScroller.
//----------------------------------------------------------------------------
#if !defined(OWL_SCROLLER_H)
#define OWL_SCROLLER_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(CLASSLIB_OBJSTRM_H)
# include <classlib/objstrm.h>
#endif
#if !defined(__LIMITS_H)
# include <limits.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TWindow;
#if !defined(WINSYS_GEOMETRY_H)
 class _BIDSCLASS TRect;
#endif
class _OWLCLASS TDC;

inline long LongMulDiv(long mul1, long mul2, long div1)
                       {return (mul1*mul2) / div1;}

//
// class TScroller
// ~~~~~ ~~~~~~~~~
// Class TScroller implements the actual scroller object. All functions
// are inline or virtual to avoid pulling in code when no scrollers have
// been constructed.
//
class _OWLCLASS TScroller : public TStreamableBase {
  public:
    TScroller(TWindow* window,
              int      xUnit,  int  yUnit,
              long     xRange, long yRange);
    virtual ~TScroller();

            void  SetWindow(TWindow* win);
    virtual void  SetUnits(int xUnit, int yUnit);
    virtual void  SetPageSize();
    virtual void  SetSBarRange();
    virtual void  SetRange(long xRange, long yRange);
    virtual void  SetTotalRangeOfUnits(long xTotalUnits, long yTotalUnits);

    virtual void  BeginView(TDC& dc, TRect& rect);
    virtual void  EndView();
    virtual void  VScroll(uint scrollEvent, int thumbPos);
    virtual void  HScroll(uint scrollEvent, int thumbPos);
    virtual void  ScrollTo(long x, long y);

    // Scrolls to a position calculated using the passed delta values
    //
    void          ScrollBy(long dx, long dy);

    virtual bool  IsAutoMode();
    virtual void  AutoScroll();

    // Returns a bool value indicating whether or not the passed
    // area (in units) is currently visible
    //
    bool          IsVisibleRect(long x, long y, int xExt, int yExt);

    // Converts a horizontal range value from the scrollbar to a
    // horizontal scroll value
    //
    int           XScrollValue(long rangeUnit);

    // Converts a vertical range value from the scrollbar to a
    // vertical scroll value
    //
    int           YScrollValue(long rangeUnit);

    // Converts a horizontal scroll value from the scrollbar to
    // a horizontal range value
    //
    long          XRangeValue(int scrollUnit);

    // Converts a vertical scroll value from the scrollbar to
    // a vertical range value
    //
    long          YRangeValue(int scrollUnit);

  public:
    TWindow*  Window;         // Window that this scroller belongs to
    long      XPos;           // Current pos in horz/vert scroll units
    long      YPos;           //
    long      XRange;         // # of scrollable horz/vert scroll units
    long      YRange;         //
    long      XTotalUnits;    // Total number of horz/vert scroll units
    long      YTotalUnits;    //
    int       XUnit;          // Logical device units per horz/vert scroll unit
    int       YUnit;          //
    int       XLine;          // # of horz/vert scroll units per line
    int       YLine;          //
    int       XPage;          // # of horz/vert scroll units per page
    int       YPage;          //
    bool      AutoMode;       // Auto scrolling mode
    bool      TrackMode;      // Track scroll mode
    bool      AutoOrg;        // Indicates Scroller offsets origin
    bool      HasHScrollBar;
    bool      HasVScrollBar;

  DECLARE_STREAMABLE(_OWLCLASS, TScroller, 1);
};

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
inline void TScroller::SetWindow(TWindow* win)
{
  Window = win;
}

//
inline void TScroller::ScrollBy(long dx, long dy)
{
  ScrollTo(XPos+dx, YPos+dy);
}

//
inline bool TScroller::IsVisibleRect(long x, long y, int xExt, int yExt)
{
  return (x + xExt > XPos) && (y + yExt > YPos) &&
      (x <= XPos + XPage + 1) && (y <= YPos + YPage + 1);
}

//
inline int  TScroller::XScrollValue(long rangeUnit)
{
  return (int)LongMulDiv(rangeUnit, SHRT_MAX, XRange);
}

//
inline int  TScroller::YScrollValue(long rangeUnit)
{
  return (int)LongMulDiv(rangeUnit, SHRT_MAX, YRange);
}

//
inline long TScroller::XRangeValue(int scrollUnit)
{
  return LongMulDiv(scrollUnit, XRange, SHRT_MAX);
}

//
inline long TScroller::YRangeValue(int scrollUnit)
{
  return LongMulDiv(scrollUnit, YRange, SHRT_MAX);
}

#endif  // OWL_SCROLLER_H
