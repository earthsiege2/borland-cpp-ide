//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\statusba.h
//   Class TStatusBar.
//----------------------------------------------------------------------------
#if !defined(__OWL_STATUSBA_H)
#define __OWL_STATUSBA_H

#if !defined(__OWL_MESSAGEB_H)
  #include "owl\messageb.h"
#endif
#if !defined(__OWL_TEXTGADG_H)
  #include "owl\textgadg.h"
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
    enum TModeIndicator {ExtendSelection = 1,
                         CapsLock        = 1 << 1,
                         NumLock         = 1 << 2,
                         ScrollLock      = 1 << 3,
                         Overtype        = 1 << 4,
                         RecordingMacro  = 1 << 5};

    TStatusBar(TWindow*              parent = 0,
               TGadget::TBorderStyle borderStyle = TGadget::Recessed,
               UINT                  modeIndicators = 0,
               TFont*                font = new TGadgetWindowFont,
               TModule*              module = 0);

    //
    // by default, adds "gadget" after the existing text gadgets and before
    // the mode indicator gadgets. sets the border style to the style specified
    // during construction.
    //
    void        Insert(TGadget& gadget, TPlacement = After, TGadget* sibling = 0);

    TGadget*    operator [](UINT index);  // can't access mode indicator gadgets

    //
    // in order for the mode indicator status to appear you must have
    // specified the mode when the window was constructed
    //
    BOOL        GetModeIndicator(TModeIndicator i) const 
                  {return (ModeIndicatorState & i) ? 1 : 0;}
    void        SetModeIndicator(TModeIndicator, BOOL state);
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
    UINT                   NumModeIndicators;
    UINT                   ModeIndicators;
    UINT                   ModeIndicatorState;

    void        PositionGadget(TGadget* previous, TGadget* next, TPoint& point);
    BOOL        PreProcessMsg(MSG& msg);
    BOOL        IdleAction(long);

  private:
    BOOL        GetGadgetAndString(TModeIndicator mode, TTextGadget*& gadget, char*& str);
    BOOL        IsModeIndicator(TGadget* gadget);

    //
    // hidden to prevent accidental copying or assignment
    //
    TStatusBar(const TStatusBar&);
    TStatusBar& operator =(const TStatusBar&);

  DECLARE_CASTABLE;
};

#endif  // __OWL_STATUSBA_H
