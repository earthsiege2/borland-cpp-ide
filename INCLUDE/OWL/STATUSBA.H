//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.9  $
//
// Definition of class TStatusBar.
//----------------------------------------------------------------------------
#if !defined(OWL_STATUSBA_H)
#define OWL_STATUSBA_H

#if !defined(OWL_MESSAGEB_H)
# include <owl/messageb.h>
#endif
#if !defined(OWL_TEXTGADG_H)
# include <owl/textgadg.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TStatusBar
// ~~~~~ ~~~~~~~~~~
// Status bars have more options than a plain message bar: you can have
// multiple text gadgets, different style borders, and you can reserve space
// for mode indicators
//
class _OWLCLASS TStatusBar : public TMessageBar {
  public:
    enum TModeIndicator {
      ExtendSelection = 1,
      CapsLock        = 1 << 1,
      NumLock         = 1 << 2,
      ScrollLock      = 1 << 3,
      Overtype        = 1 << 4,
      RecordingMacro  = 1 << 5,
      SizeGrip        = 1 << 6
    };

    TStatusBar(TWindow*              parent = 0,
               TGadget::TBorderStyle borderStyle = TGadget::Recessed,
               uint                  modeIndicators = 0,
               TFont*                font = 0, //new TGadgetWindowFont(6),
               TModule*              module = 0);

    // By default, adds "gadget" after the existing text gadgets and before
    // the mode indicator gadgets. Sets the border style to the style specified
    // during construction.
    //
    void        Insert(TGadget& gadget, TPlacement = After, TGadget* sibling = 0);

    // Overriden method of TMessageBar to use our own text gadget
    // Set (or clear if 0) menu/command item hint text displayed in/on bar
    //
    virtual void    SetHintText(const char* text);

    // In order for the mode indicator status to appear you must have
    // specified the mode when the window was constructed
    //
    bool        GetModeIndicator(TModeIndicator i) const;
    void        SetModeIndicator(TModeIndicator, bool state);
    void        ToggleModeIndicator(TModeIndicator);

    struct TSpacing {
      TMargins::TUnits  Units;
      int               Value;
      TSpacing();
    };

    // Sets the spacing to be used between mode indicator gadgets
    //
    void        SetSpacing(const TSpacing& spacing);

    // Control whether hint text is display over the whole window or in
    // a text gadget.
    //
    void        SetWideHints(bool on);

  protected:
    void        PositionGadget(TGadget* previous, TGadget* next, TPoint& point);
    TSpacing&   GetSpacing();

    uint        GetNumModeIndicators();
    uint        GetModeIndicators() const;
    void        SetModeIndicators(uint modeindicators);


    void        EvOwlFrameSize(uint sizeType, TSize&);
    uint        EvNCHitTest(TPoint& point);

  protected_data:
    TGadget::TBorderStyle  BorderStyle;
    TSpacing               Spacing;
    uint                   NumModeIndicators;
    uint                   ModeIndicators;
    uint                   ModeIndicatorState;
    bool                   WideHintText;

  private:
    bool        GetGadgetAndStrings(TModeIndicator mode, TTextGadget*& gadget,
                                    const char*& strOn);
    bool        IsModeIndicator(TGadget* gadget);

#if !defined(BI_PLAT_WIN16)
    void        InsertSizeGrip(void);
#endif

    // Hidden to prevent accidental copying or assignment
    //
    TStatusBar(const TStatusBar&);
    TStatusBar& operator =(const TStatusBar&);

  DECLARE_CASTABLE;

#if !defined(BI_PLAT_WIN16)
  // The event handlers are for managing size grips, which 
  // aren't available in 16-bit Windows
  //
  DECLARE_RESPONSE_TABLE(TStatusBar);
#endif
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

//
// Return true if the mode indicator is on.
//
inline bool TStatusBar::GetModeIndicator(TStatusBar::TModeIndicator i) const {
  return (ModeIndicatorState & i) ? 1 : 0;
}

//
// Initialize spacing.
//
inline TStatusBar::TSpacing::TSpacing() {
  Units = TMargins::LayoutUnits;
  Value = 0;
}

//
// Set the spacing between the mode indicator gadgets.
//
inline void TStatusBar::SetSpacing(const TStatusBar::TSpacing& spacing) {
  Spacing = spacing;
}

//
// Return the spacing between the mode indicator gadgets.
//
inline TStatusBar::TSpacing& TStatusBar::GetSpacing() {
  return Spacing;
}

//
// Return number of mode indicators on.
//
inline uint TStatusBar::GetNumModeIndicators() {
  return NumModeIndicators;
}

//
// Return the bit flags for which indicator is on.
//
inline uint TStatusBar::GetModeIndicators() const {
  return ModeIndicators;
}

//
// Set the bit flags for which indicator is on.
//
inline void TStatusBar::SetModeIndicators(uint modeindicators) {
  ModeIndicators = modeindicators;
}

//
// Informs the StatusBar whether hints should be displayed in a text gadget
// (on == false) or over the area of the whole statusbar (on == true).
//
inline void TStatusBar::SetWideHints(bool on) {
  WideHintText = on;
}

#endif  // OWL_STATUSBA_H
