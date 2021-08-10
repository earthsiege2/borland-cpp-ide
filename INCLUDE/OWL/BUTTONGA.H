//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of class TButtonGadget.
//----------------------------------------------------------------------------
#if !defined(OWL_BUTTONGA_H)
#define OWL_BUTTONGA_H

#if !defined(OWL_GADGET_H)
# include <owl/gadget.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TCelArray;

//
// class TButtonGadget
// ~~~~~ ~~~~~~~~~~~~~
// Buttons begin highlighting and do a capture when pressed (the mouse down
// occurs). they cancel highlighting when the mouse exits, but begin
// highlighting again when the mouse re-enters. when the mouse goes up the
// capture is released
//
// There are two basic type of buttons: commands and settings (attribute
// buttons). Settings can be exclusive (like a radio button) or non-exclusive
// (like a check box), or SemiExclusive where they act like both
//
// There are three normal button states: up, down, and indeterminate. in
// addition the button can be highlighted (pressed) in all three states
//
// Commands can only be in the "up" state. Settings can be in all three states
//
class _OWLCLASS TButtonGadget : public TGadget {
  public:
    enum TType {   // Basic type of this button
      Command,       // Single shot, sends command on press
      Exclusive,     // Sticks down when pressed, pops out neighbors
      NonExclusive,  // Toggles state when pressed, ignores neighbors
      SemiExclusive, // Same as exclusive, plus pops up if pressed when down
      RepeatCmd,     // Auto-repeating command 
    };

    enum TState {  // Current state of this button
      Up,            // Button is up, i.e. unchecked
      Down,          // Button is down, i.e. checked
      Indeterminate, // Button is neither checked nor unchecked
    };

    enum TShadowStyle {  // Bottom & right side shadow width for old UI style
      SingleShadow = 1,
      DoubleShadow = 2,
    };

    TButtonGadget(TResId glyphResIdOrIndex,
                  int    id,
                  TType  type = Command,
                  bool   enabled = false, // initial state before cmd enabling
                  TState state = Up,
                  bool   sharedGlyph = false);
   ~TButtonGadget();

    // Some accessors
    //
    void          SetButtonState(TState newState);
    TState        GetButtonState() const;

    TType         GetButtonType() const;
    void          GetDesiredSize(TSize& size);
    void          SetBounds(const TRect& r);

    // A few button style options. These styles may be ignores on some
    // UI platforms
    //
    bool          GetNotchCorners() const;
    void          SetNotchCorners(bool notchCorners=true);

    TShadowStyle  GetShadowStyle() const;
    void          SetShadowStyle(TShadowStyle style=DoubleShadow);

    bool          GetAntialiasEdges() const;
    void          SetAntialiasEdges(bool anti=true);

    // Override and initiate a WM_COMMAND_ENABLE message
    //
    void          CommandEnable();
    void          SysColorChange();

  protected:
    // Some accessors are protected
    //
    void          SetButtonType(TType newType);

    // Override basic TGadget member functions
    //
    void          Paint(TDC& dc);
    void          Invalidate();

    // Override TGadget member functions and respond to user fiddling with the
    // button by self-sending button protocol messages
    //
    void          LButtonDown(uint modKeys, TPoint& p);
    void          MouseMove(uint modKeys, TPoint& p);
    void          MouseEnter(uint modKeys, TPoint& p);
    void          MouseLeave(uint modKeys, TPoint& p);
    void          LButtonUp(uint modKeys, TPoint& p);

    // Glyph types and construction functions
    //
    enum {
      //CelMask,
      CelNormal,    // Normal state
      CelDisabled,  // Disabled (grayed)
      CelIndeterm,  // Indeterminate-neither normal nor down
      CelDown,      // Down or checked
      CelPressed,   // Optional pressed glyph
      CelsTotal,
    };

    virtual TDib* GetGlyphDib();
    virtual void  ReleaseGlyphDib(TDib* glyph);
    virtual void  BuildCelArray();

    // button protocol
    // ~~~~~~ ~~~~~~~~

    // Invoked by mouse-down & mouse enter events. sets member data "Pressed"
    // to true and highlights the button
    //
    virtual void  BeginPressed(TPoint& p);

    // Invoked by mouse exit events. sets member data "Pressed" to false and
    // paints the button in its current state
    //
    virtual void  CancelPressed(TPoint& p);

    // The action method called on a completed 'click', generates WM_COMMAND
    //
    virtual void  Activate(TPoint& p);

  protected_data:
    TResId        ResId;            // Bmp res id if glyph is owned here
    TCelArray*    CelArray;         // CelArray used to cache glyph states

    TPoint        BitmapOrigin;     // Where glyph sits on button
    TState        State         :4; // Current state of button
    TType         Type          :4; // Type of this button
    TShadowStyle  ShadowStyle   :4; // Shadow style, may be ignored w/ 3dUI
    bool          NotchCorners  :1; // Notch (round) corners? ignored w/ 3dUI
    bool          Pressed       :1; // Is this button current pressed by user
    bool          AntialiasEdges:1; // Should border edges be antialiased?
    bool          SharingGlyph;     // Should the button share glyphs with its
                                    // gadget window?
    int           GlyphIndex;       // Base index for our glyph bitmap

  private:
    int           GlyphCount;       // How many glyphs are we using (1,3,4,5)

  private:
    void          CheckExclusively();
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
// Return the current state of the button.
//
inline TButtonGadget::TState TButtonGadget::GetButtonState() const {
  return State;
}

//
// Return the type of the button.
//
inline TButtonGadget::TType TButtonGadget::GetButtonType() const {
  return Type;
}

//
// Returns true if the button has rounded corners.
//
inline bool TButtonGadget::GetNotchCorners() const {
  return NotchCorners;
}

//
// Sets the flag for rounded corners on the button.
//
inline void TButtonGadget::SetNotchCorners(bool notchCorners) {
  NotchCorners = notchCorners;
}

//
// Return the current shadow style of the button.
//
inline TButtonGadget::TShadowStyle TButtonGadget::GetShadowStyle() const {
  return ShadowStyle;
}

//
// Returns true if the border edges are antialiased.
//
inline bool TButtonGadget::GetAntialiasEdges() const {
  return AntialiasEdges;
}

//
// Sets the flag for antialiased borders.
//
inline void TButtonGadget::SetAntialiasEdges(bool anti) {
  AntialiasEdges=anti;
}

//
// Sets the type of the button.
//
inline void TButtonGadget::SetButtonType(TType newType) {
  Type = newType;
}

#endif  // OWL_BUTTONGA_H
