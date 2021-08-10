//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of class TButtonGadget.
//----------------------------------------------------------------------------
#if !defined(OWL_BUTTONGA_H)
#define OWL_BUTTONGA_H

#if !defined(OWL_GADGET_H)
# include <owl/gadget.h>
#endif
class _OWLCLASS TCelArray;

//
//  class TButtonGadget
//  ----- -------------
//
//  buttons begin highlighting and do a capture when pressed (the mouse down
//  occurs). they cancel highlighting when the mouse exits, but begin
//  highlighting again when the mouse re-enters. when the mouse goes up the
//  capture is released
//
//  there are two basic type of buttons: commands and settings (attribute
//  buttons). Settings can be exclusive (like a radio button) or non-exclusive
//  (like a check box)
//
//  there are three normal button states: up, down, and indeterminate. in
//  addition the button can be highlighting (pressed) in all three states
//
//  commands can only be in the "up" state. settings can be in all three states
//
class _OWLCLASS TButtonGadget : public TGadget {
  public:
    enum TState {Up, Down, Indeterminate};
    enum TType {Command, Exclusive, NonExclusive};
    enum TShadowStyle {SingleShadow = 1, DoubleShadow = 2};

    TButtonGadget(TResId bmpResId,
                  int    id,
                  TType  type = Command,
                  bool   enabled = false, // initial state before cmd enabling
                  TState state = Up,
                  bool   repeat = false);
   ~TButtonGadget();

    void          SetButtonState(TState);
    TState        GetButtonState() {return State;}

    TType         GetButtonType() {return Type;}
    void          GetDesiredSize(TSize& size);
    void          SetBounds(TRect& r);

    // A couple of button style options
    //
    void          SetNotchCorners(bool notchCorners=true)
                    {NotchCorners = notchCorners;}
    void          SetShadowStyle(TShadowStyle style=DoubleShadow);
    void          SetAntialiasEdges(bool anti=true) {AntialiasEdges=anti;}

    // Override and initiate a WM_COMMAND_ENABLE message
    //
    void          CommandEnable();

    void          SysColorChange();

  protected:
    TResId        ResId;
    TCelArray*    CelArray;
    TPoint        BitmapOrigin;
    TState        State          : 4;
    TType         Type           : 4;
    TShadowStyle  ShadowStyle    : 4;
    bool          Repeat         : 1;
    bool          NotchCorners   : 1;
    bool          Pressed        : 1;
    bool          AntialiasEdges : 1;

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

    enum {
      //CelMask,
      CelNormal,    // Normal state
      CelDisabled,  // Disabled (grayed)
      CelIndeterm,  // Indeterminate-neither normal nor down
      CelDown,      // Down or checked
      CelsTotal
    };
    virtual TDib* GetGlyphDib();
    virtual void  ReleaseGlyphDib(TDib* glyph);
    virtual void  BuildCelArray();
    
    //
    // button protocol
    // ------ --------
    //

    //
    // invoked by mouse-down & mouse enter events. sets member data "Pressed"
    // to true and highlights the button
    //
    virtual void  BeginPressed(TPoint& p);

    //
    // invoked by mouse exit events. sets member data "Pressed" to false and
    // paints the button in its current state
    //
    virtual void  CancelPressed(TPoint& p);

    //
    // invoked by mouse-up event inside the Gadget. sets member data "Pressed"
    // to false, changes state for attribute buttons, and paints the button
    // in its current state
    //
    // generates WM_COMMAND
    //
    virtual void  Activate(TPoint& p);

  private:
    void          CheckExclusively();
};

#endif  // OWL_BUTTONGA_H
