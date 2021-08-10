//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Definition of class TGauge, a gauge control encapsulation & implementation.
//----------------------------------------------------------------------------
#if !defined(OWL_GAUGE_H)
#define OWL_GAUGE_H

#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif
#if !defined(WINSYS_COLOR_H)
# include <winsys/color.h>
#endif
#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

//
// class TGauge
// ~~~~~ ~~~~~~
class _OWLCLASS TGauge : public TControl {
  public:
    TGauge(TWindow*        parent,
           const char far* title,
           int             id,
           int x, int y, int w, int h = 0,
           bool            isHorizontal = true,
           int             margin = 1,
           TModule*        module = 0);

    TGauge(TWindow*        parent,
           int             id,
           int x, int y, int w, int h = 0,
           TModule*        module = 0);

    TGauge(TWindow*        parent,
           int             resId,
           TModule*        module = 0);

    // Getting & setting gauge properties
    //
    void          GetRange(int& min, int& max) const;
    int           GetStep() const;
    int           GetValue() const;

    void          SetRange(int min, int max);
    void          SetStep(int step);
    void          SetValue(int value);  
    void          DeltaValue(int delta);
    void          StepIt();
    void operator ++(int);

    // Set whether the control is horizontal. This method is useful
    // for an object coming from a dialog resource. [For objects created
    // by OWL, use the constructor which accepts a boolean 'isHorizontal'
    // parameter.
    //
    void          SetHorizontal(bool horizontal);

    // Set the LED style & sizing as well as the indicator color
    // Ignored by CommonControl impl.
    //
    // NOTE: Invoking these methods may *NOT* be effective if OWL
    //       uses the Common Control support and instead of 
    //       emulating the control.
    //
    void          SetLed(int spacing, int thickPercent = 90);
    void          SetColor(const TColor& color);

    // Specifies whether OWL should use or avoid the system implementation
    // of gauge/progressbar if/when available.
    //
    void          SetNativeUse(TNativeUse nu = nuDontCare);

  protected:

    // Override TWindow virtual member functions
    //
    char far*     GetClassName();
    void          Paint(TDC& dc, bool erase, TRect& rect);
    void          SetupWindow();

    // Self sent by method Paint(). override this is if you want to
    // implement a border style that isn't supported
    //
    virtual void  PaintBorder(TDC& dc);

    // Message response functions
    //
    bool          EvEraseBkgnd(HDC);

  protected_data:
    int           Min;        // Minimum value
    int           Max;        // Maximum value
    int           Value;      // Current value (position)
    int           Step;       // Step factor
    int           Margin;     // margin between bevel & graphic
    int           IsHorizontal;
    int           LedSpacing; // Spacing of 'leds' in value units
    int           LedThick;   // Thickness of leds in percent of spacing
    TColor        BarColor;   // Bar or LED color, defaults to blue
    static TNativeUse ClassNativeUse;  // Default use of native control impl

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TGauge(const TGauge&);
    TGauge& operator=(const TGauge&);

  DECLARE_RESPONSE_TABLE(TGauge);
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
inline void TGauge::GetRange(int& min, int& max) const
{
  min = Min; max = Max;
}

//
// Return the step factor
//
inline int TGauge::GetStep() const
{
  return Step;
}

//
inline int TGauge::GetValue() const
{
  return Value;
}

//
// Another way of stepping (calls StepIt)
//
inline void TGauge::operator ++(int)
{
  StepIt();
}

//
inline void TGauge::SetColor(const TColor& color)
{
  BarColor = color;
}

//
// Specifies whether the class uses the native (operating system) implementation
// or emulates it.
//
inline void TGauge::SetNativeUse(TNativeUse nu)
{
  NativeUse = nu;
}

// Specifies whether the control is a horizontal (or vertical) gauge control
//
inline void TGauge::SetHorizontal(bool isHorizontal)
{
  IsHorizontal = isHorizontal;
}

#endif  // OWL_GAUGE_H
