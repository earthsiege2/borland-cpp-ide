//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\scroller.h
//   Definition of class TScroller.
//----------------------------------------------------------------------------
#if !defined(__OWL_SCROLLER_H)
#define __OWL_SCROLLER_H

#if !defined(__OWL_OWLDEFS_H)
  #include <owl\owldefs.h>
#endif
#if !defined(__CLASSLIB_OBJSTRM_H)
  #include <classlib\objstrm.h>
#endif
#if !defined(__LIMITS_H)
  #include <limits.h>
#endif

class _OWLCLASS TWindow;
#if !defined(__OWL_POINT_H)
class _OWLCLASS TRect;
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
    virtual void  VScroll(UINT scrollEvent, int thumbPos);
    virtual void  HScroll(UINT scrollEvent, int thumbPos);
    virtual void  ScrollTo(long x, long y);

    //
    // scrolls to a position calculated using the passed "Delta" values
    //
    void          ScrollBy(long dx, long dy) {ScrollTo(XPos+dx, YPos+dy);}

    virtual BOOL  IsAutoMode();
    virtual void  AutoScroll();

    //
    // returns a BOOL value indicating whether or not the passed
    // area (in units) is currently visible
    //
    BOOL          IsVisibleRect(long x, long y, int xExt, int yExt)
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
    BOOL      AutoMode;        // auto scrolling mode
    BOOL      TrackMode;       // track scroll mode
    BOOL      AutoOrg;         // indicates Scroller offsets origin
    BOOL      HasHScrollBar, HasVScrollBar;

  DECLARE_STREAMABLE(_OWLCLASS, TScroller, 1);
};

#endif  // __OWL_SCROLLER_H
