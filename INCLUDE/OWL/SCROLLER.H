//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Definition of class TScroller.
//----------------------------------------------------------------------------
#if !defined(OWL_SCROLLER_H)
#define OWL_SCROLLER_H

#if !defined(OWL_OWLDEFS_H)
# include <owl/owldefs.h>
#endif
#if !defined(CLASSLIB_OBJSTRM_H)
# include <classlib/objstrm.h>
#endif
#if !defined(__LIMITS_H)
# include <limits.h>
#endif

class _OWLCLASS TWindow;
#if !defined(OSL_GEOMETRY_H)
 class _BIDSCLASS TRect;
#endif
class _OWLCLASS TDC;

inline long LongMulDiv(long mul1, long mul2, long div1)
                       {return (mul1*mul2) / div1;}

//
//  class TScroller
//  ----- ---------
//
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

            void  SetWindow(TWindow* win) {Window = win;}
    virtual void  SetUnits(int xUnit, int yUnit);
    virtual void  SetPageSize();
    virtual void  SetSBarRange();
    virtual void  SetRange(long xRange, long yRange);

    virtual void  BeginView(TDC& dc, TRect& rect);
    virtual void  EndView();
    virtual void  VScroll(uint scrollEvent, int thumbPos);
    virtual void  HScroll(uint scrollEvent, int thumbPos);
    virtual void  ScrollTo(long x, long y);

    //
    // scrolls to a position calculated using the passed "Delta" values
    //
    void          ScrollBy(long dx, long dy) {ScrollTo(XPos+dx, YPos+dy);}

    virtual bool  IsAutoMode();
    virtual void  AutoScroll();

    //
    // returns a bool value indicating whether or not the passed
    // area (in units) is currently visible
    //
    bool          IsVisibleRect(long x, long y, int xExt, int yExt)
            {return (x + xExt > XPos) && (y + yExt > YPos) &&
                  (x <= XPos + XPage + 1) && (y <= YPos + YPage + 1);}

    //
    // converts a horizontal range value from the scrollbar to a
    // horizontal scroll value
    //
    int           XScrollValue(long rangeUnit)
            {return (int)LongMulDiv(rangeUnit, SHRT_MAX, XRange);}

    //
    // converts a vertical range value from the scrollbar to a
    // vertical scroll value
    //
    int           YScrollValue(long rangeUnit)
            {return (int)LongMulDiv(rangeUnit, SHRT_MAX, YRange);}

    //
    // converts a horizontal scroll value from the scrollbar to
    // a horizontal range value
    //
    long          XRangeValue(int scrollUnit)
            {return LongMulDiv(scrollUnit, XRange, SHRT_MAX);}

    //
    // converts a vertical scroll value from the scrollbar to
    // a vertical range value
    //
    long          YRangeValue(int scrollUnit)
            {return LongMulDiv(scrollUnit, YRange, SHRT_MAX);}

  public:
    TWindow*  Window;          // Window that this scroller belongs to
    long      XPos, YPos;      // current pos in horz/vert scroll units
    long      XRange, YRange;  // # of scrollable horz/vert scroll units
    int       XUnit, YUnit;    // logical device units per horz/vert scroll unit
    int       XLine, YLine;    // # of horz/vert scroll units per line
    int       XPage, YPage;    // # of horz/vert scroll units per page
    bool      AutoMode;        // auto scrolling mode
    bool      TrackMode;       // track scroll mode
    bool      AutoOrg;         // indicates Scroller offsets origin
    bool      HasHScrollBar, HasVScrollBar;

  DECLARE_STREAMABLE(_OWLCLASS, TScroller, 1);
};

#endif  // OWL_SCROLLER_H
