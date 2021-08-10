//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#if !defined(OWL_UIHANDLE_H)
#define OWL_UIHANDLE_H

#if !defined(OWL_OWLDEFS_H)
# include <owl/owldefs.h>
#endif
#if !defined(OSL_GEOMETRY_H)
# include <osl/geometry.h>
#endif
class _OWLCLASS TDC;

class _OWLCLASS TUIHandle {
  public:
    enum TWhere {
      // Nine handle positions 
      TopLeft=0, TopCenter=1, TopRight=2,
      MidLeft=3, MidCenter=4, MidRight=5,
      BottomLeft=6, BottomCenter=9, BottomRight=8,
      Outside=-1,  // Hit completely outside the object
      Inside=-2    // Hit inside object, not on handles, & InsideSpecial is set
    };
    enum TStyle {
      HandlesIn = 0,        // One of these 2 base styles
      HandlesOut = 1,       //
      Framed = 2,           // Frame rect is drawn solid
      DashFramed = 4,       //  or frame rect is drawn dashed or none
      Grapples = 8,         // Eight grapple boxes are drawn
      HatchBorder = 16,     // Border handle area drawn hatched
      HatchRect = 32,       //  or whole rect drawn hatched or none
      InsideSpecial = 64,   // Inside area hit-tested independently
    };
    TUIHandle(const TRect& frame,
              uint style = HandlesIn|Grapples|HatchBorder,
              int thickness = 5);

    void   MoveTo(int x, int y);
    void   Move(int dx, int dy);
    void   Size(int w, int h);
    TRect  GetBoundingRect() const;

    TWhere HitTest(const TPoint& point) const;
    void   Paint(TDC& dc) const;

    static uint16 GetCursorId(TWhere where);
    
  private:
    TRect  Frame;
    uint   Style;
    TPoint HandleBox;
};

#endif  // OWL_UIHANDLE_H
