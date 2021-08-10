//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Class TStatusBar.
//----------------------------------------------------------------------------
#if !defined(OWL_STATUSBA_H)
#define OWL_STATUSBA_H

#if !defined(OWL_MESSAGEB_H)
# include <owl/messageb.h>
#endif
#if !defined(OWL_TEXTGADG_H)
# include <owl/textgadg.h>
#endif

//
//  class TStatusBar
//  ----- ----------
//
//  status bars have more options than a plain message bar: you can have
//  multiple text gadgets, different style borders, and you can reserve space
//  for mode indicators
//
class _OWLCLASS TStatusBar : public TMessageBar {
  public:
    enum TModeIndicator {
      ExtendSelection = 1,
      CapsLock        = 1 << 1,
      NumLock         = 1 << 2,
      ScrollLock      = 1 << 3,
      Overtype        = 1 << 4,
      RecordingMacro  = 1 << 5
    };

    TStatusBar(TWindow*              parent = 0,
               TGadget::TBorderStyle borderStyle = TGadget::Recessed,
               uint                  modeIndicators = 0,
               TFont*                font = new TGadgetWindowFont,
               TModule*              module = 0);

    //
    // by default, adds "gadget" after the existing text gadgets and before
    // the mode indicator gadgets. sets the border style to the style specified
    // during construction.
    //
    void        Insert(TGadget& gadget, TPlacement = After, TGadget* sibling = 0);

    TGadget*    operator [](uint index);  // can't access mode indicator gadgets

    //
    // in order for the mode indicator status to appear you must have
    // specified the mode when the window was constructed
    //
    bool        GetModeIndicator(TModeIndicator i) const 
                  {return (ModeIndicatorState & i) ? 1 : 0;}
    void        SetModeIndicator(TModeIndicator, bool state);
    void        ToggleModeIndicator(TModeIndicator);

    struct TSpacing {
      TMargins::TUnits  Units;
      int               Value;

      TSpacing() {Units = TMargins::LayoutUnits; Value = 0;}
    };

    //
    // sets the spacing to be used between mode indicator gadgets
    //
    void        SetSpacing(TSpacing& spacing) {Spacing = spacing;}

  protected:
    TGadget::TBorderStyle  BorderStyle;
    TSpacing               Spacing;
    uint                   NumModeIndicators;
    uint                   ModeIndicators;
    uint                   ModeIndicatorState;

    void        PositionGadget(TGadget* previous, TGadget* next, TPoint& point);
    bool        PreProcessMsg(MSG& msg);
    bool        IdleAction(long);

  private:
    bool        GetGadgetAndStrings(TModeIndicator mode, TTextGadget*& gadget,
                                    const char*& strOn, const char*& strOff);
    bool        IsModeIndicator(TGadget* gadget);

    //
    // hidden to prevent accidental copying or assignment
    //
    TStatusBar(const TStatusBar&);
    TStatusBar& operator =(const TStatusBar&);

  DECLARE_CASTABLE;
};

#endif  // OWL_STATUSBA_H
