//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Defines class TGauge.  This defines the basic behavior
//   of gauge controls.
//----------------------------------------------------------------------------
#if !defined(OWL_GAUGE_H)
#define OWL_GAUGE_H

#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif
#if !defined(OWL_COLOR_H)
# include <owl/color.h>
#endif

//
//  class TGauge
//  ----- ------
//
class _OWLCLASS TGauge : public TControl {
  public:
    TGauge(TWindow*        parent,
           const char far* title,
           int             id,
           int X, int Y, int W, int H,
           bool            isHorizontal = true,
           int             margin = 0,
           TModule*        module = 0);

    //
    // Getting & setting gauge properties
    //
    void          GetRange(int& min, int& max) const {min = Min; max = Max;}
    int           GetValue() const {return Value;}
    void          SetRange(int min, int max);
    void          SetValue(int value);
    void          SetLed(int spacing, int thickPercent = 90);
    void          SetColor(TColor color) {BarColor = color;}

  protected:

    //
    // Override TWindow virtual member functions
    //
    void          Paint(TDC& dc, bool erase, TRect& rect);

    //
    // self sent by method Paint(). override this is if you want to
    // implement a border style that isn't supported
    //
    virtual void   PaintBorder(TDC& dc);

    //
    // message response functions
    //
    bool          EvEraseBkgnd(HDC);
  
  protected:
    int           Min;        // Minimum value
    int           Max;        // Maximum value
    int           Value;      // Current value
    int           Margin;     // margin between bevel & graphic
    int           IsHorizontal;
    int           LedSpacing; // Spacing of 'leds' in value units
    int           LedThick;   // Thickness of leds in percent of spacing
    TColor        BarColor;   // Bar or LED color, defaults to blue

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TGauge(const TGauge&);
    TGauge& operator=(const TGauge&);

  DECLARE_RESPONSE_TABLE(TGauge);
};

#endif  // OWL_GAUGE_H
