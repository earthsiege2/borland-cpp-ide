//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Defines class TSlider & TVSlider.  This defines the basic behavior
//   of slider controls.
//----------------------------------------------------------------------------
#if !defined(OWL_SLIDER_H)
#define OWL_SLIDER_H

#if !defined(OWL_SCROLLBA_H)
# include <owl/scrollba.h>
#endif
#if !defined(OWL_COLOR_H)
# include <owl/color.h>
#endif
#include <owl/slider.rh>

class _OWLCLASS TDC;
class _OWLCLASS TRegion;
class _OWLCLASS TBrush;

//
//  class TSlider
//  ----- -------
//
class _OWLCLASS TSlider : public TScrollBar {
  public:
    TSlider(TWindow*        parent,
            int             id,
            int X, int Y, int W, int H,
            TResId          thumbResId,
            TModule*        module = 0);

    ~TSlider();

    //
    // Overload TScrollBar virtual functions 
    //
    void          GetRange(int& min, int& max) const {min = Min; max = Max;}
    int           GetPosition() const {return Pos;}
    void          SetRange(int min, int max);
    void          SetPosition(int thumbPos);
    
    void          SetRuler(int ticGap, bool snap = false)
                    {TicGap = ticGap; Snap = snap;}

  protected:

    //
    // Override TWindow virtual member functions
    //
    void          SetupWindow();
  
    //
    // TSlider virtual functions
    //
    virtual int    PointToPos(TPoint& point) = 0;
    virtual TPoint PosToPoint(int pos) = 0;
    virtual void   NotifyParent(int scrollCode, int pos=0) = 0;

    virtual void   SetupThumbRgn();
    virtual int    HitTest(TPoint& point) = 0;
    virtual void   SlideThumb(TDC& dc, int thumbPos);
    
    virtual void   PaintRuler(TDC& dc) = 0;
    virtual void   PaintSlot(TDC& dc) = 0;
    virtual void   PaintThumb(TDC& dc);

    int            SnapPos(int pos);
    void           GetBkColor(TDC& dc);

    //
    // message response functions
    //
    void          EvSize(uint sizeType, TSize& size);
    uint          EvGetDlgCode(MSG far*);
    bool          EvEraseBkgnd(HDC hDC);
    void          EvPaint();
    void          EvLButtonDown(uint modKeys, TPoint& point);
    void          EvMouseMove(uint modKeys, TPoint& point);
    void          EvLButtonUp(uint modKeys, TPoint& point);
    void          EvLButtonDblClk(uint modKeys, TPoint& point);
    void          EvKeyDown(uint key, uint repeatCount, uint flags);
    void          EvSetFocus(HWND hWndLostFocus);
    void          EvKillFocus(HWND hWndGetFocus);
  
  protected:
    int           Min;        // Minimum position value
    int           Max;        // Maximum position value
    uint          Range;      // Positive range
    int           Pos;        // Current position value
    TResId        ThumbResId; // Bitmap res id for thumb knob
    TRect         ThumbRect;  // Bounding rect of Thumb in pixels
    TRegion*      ThumbRgn;   // Optional clipping/hit test region
    TRect         CaretRect;  // Bounding rect of Thumb's blink caret
    int           SlotThick;  // Thickness(width or height) of slot
    int           TicGap;     // Gap between tics in pos units
    bool          Snap;       // Snap Thumb to tics

    bool          Sliding;
    TColor        BkColor;    // color to use to paint background

    //
    // Statics used while the mouse is down & Thumb is sliding
    //
    static TSize  MouseOffset;
    static TDC*   SlideDC;

  DECLARE_RESPONSE_TABLE(TSlider);
  DECLARE_ABSTRACT_STREAMABLE(_OWLCLASS, TSlider, 1);
};

//
//  class THSlider
//  ----- --------
//
class _OWLCLASS THSlider : public TSlider {
  public:
    THSlider(TWindow*        parent,
             int             id,
             int X, int Y, int W, int H,
             TResId          thumbResId = IDB_HSLIDERTHUMB,
             TModule*        module = 0);

  protected:
    //
    // Override TSlider virtual member functions
    //
    int    PointToPos(TPoint& point);
    TPoint PosToPoint(int pos);
    void   NotifyParent(int scrollCode, int pos=0);
    int    HitTest(TPoint& point);
    void   PaintRuler(TDC& dc);
    void   PaintSlot(TDC& dc);
  
  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    THSlider(const THSlider&);
    THSlider& operator =(const THSlider&);

  DECLARE_STREAMABLE(_OWLCLASS, THSlider, 1);
};

//
//  class TVSlider
//  ----- --------
//
class _OWLCLASS TVSlider : public TSlider {
  public:
    TVSlider(TWindow*        parent,
             int             id,
             int X, int Y, int W, int H,
             TResId          thumbResId = IDB_VSLIDERTHUMB,
             TModule*        module = 0);

  protected:
    //
    // Override TSlider virtual member functions
    //
    int    PointToPos(TPoint& point);
    TPoint PosToPoint(int pos);
    void   NotifyParent(int scrollCode, int pos=0);
    int    HitTest(TPoint& point);
    void   PaintRuler(TDC& dc);
    void   PaintSlot(TDC& dc);
  
  private:
    TVSlider(const TVSlider&);
    TVSlider& operator =(const TVSlider&);

  DECLARE_STREAMABLE(_OWLCLASS, TVSlider, 1);
};

#endif  // OWL_SLIDER_H
