//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\buttonga.h
//   Base class TButtonGadget.
//----------------------------------------------------------------------------
#if !defined(__OWL_BUTTONGA_H)
#define __OWL_BUTTONGA_H

#if !defined(__OWL_GADGET_H)
  #include "owl\gadget.h"
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
                  BOOL   enabled = FALSE, // initial state before cmd enabling
                  TState state = Up,
                  BOOL   repeat = FALSE);
   ~TButtonGadget();

    void          SetButtonState(TState);
    TState        GetButtonState() {return State;}

    TType         GetButtonType() {return Type;}

    //
    // a couple of button style options
    //
    void          SetNotchCorners(BOOL notchCorners=TRUE)
                    {NotchCorners = notchCorners;}
    void          SetShadowStyle(TShadowStyle style=DoubleShadow);
    void          SetAntialiasEdges(BOOL anti=TRUE) {AntialiasEdges=anti;}

    //
    // override and initiate a WM_COMMAND_ENABLE message
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
    BOOL          Repeat         : 1;
    BOOL          NotchCorners   : 1;
    BOOL          Pressed        : 1;
    BOOL          AntialiasEdges : 1;

    //
    // overrive basic TGadget member functions
    //
    void          GetDesiredSize(TSize& size);
    void          Paint(TDC& dc);
    void          Invalidate();
    void          SetBounds(TRect& r);

    //
    // override TGadget member functions and respond to user fiddling with the
    // button by self-sending button protocol messages
    //
    void          LButtonDown(UINT modKeys, TPoint& p);
    void          MouseMove(UINT modKeys, TPoint& p);
    void          MouseEnter(UINT modKeys, TPoint& p);
    void          MouseLeave(UINT modKeys, TPoint& p);
    void          LButtonUp(UINT modKeys, TPoint& p);

    enum {
      //CelMask,
      CelNormal,
      CelDisabled,
      CelIndeterm,
      CelDown,
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
    // to TRUE and highlights the button
    //
    virtual void  BeginPressed(TPoint& p);

    //
    // invoked by mouse exit events. sets member data "Pressed" to FALSE and
    // paints the button in its current state
    //
    virtual void  CancelPressed(TPoint& p);

    //
    // invoked by mouse-up event inside the Gadget. sets member data "Pressed"
    // to FALSE, changes state for attribute buttons, and paints the button
    // in its current state
    //
    // generates WM_COMMAND
    //
    virtual void  Activate(TPoint& p);

  private:
    void          CheckExclusively();
};

#endif  // __OWL_BUTTONGA_H
