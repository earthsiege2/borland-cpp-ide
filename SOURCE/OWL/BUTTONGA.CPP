//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.15  $
//
// Implementation of class TButtonGadget.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_BUTTONGA_H)
# include <owl/buttonga.h>
#endif
#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif
#if !defined(OWL_CELARRAY_H)
# include <owl/celarray.h>
#endif
#if !defined(OWL_UIHELPER_H)
# include <owl/uihelper.h>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif
#if !defined(WINSYS_SYSTEM_H)
# include <winsys/system.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlGadget);

//
// Command enabler for button gadgets
//
class _OWLCLASS TButtonGadgetEnabler : public TCommandEnabler {
  public:
    TButtonGadgetEnabler(TWindow::THandle hReceiver, TButtonGadget* g)
    :
      TCommandEnabler(g->GetId(), hReceiver),
      Gadget(g)
    {
    }

    // Override TCommandEnabler virtuals
    //
    void  Enable(bool);
    void  SetText(const char far*);
    void  SetCheck(int);

  protected:
    TButtonGadget*  Gadget;
};

//
// Enable or disable the button gadget
//
void
TButtonGadgetEnabler::Enable(bool enable)
{
  TCommandEnabler::Enable(enable);
  Gadget->SetEnabled(enable);
}

//
// Handle the SetText request for a button gadget. Currently does nothing.
//
void
TButtonGadgetEnabler::SetText(const char far*)
{
# pragma warn -ccc
# pragma warn -rch
  CHECK(true);
# pragma warn .rch
# pragma warn .ccc
}

//
// Set the check-state for the button gadget
//
void
TButtonGadgetEnabler::SetCheck(int state)
{
  Gadget->SetButtonState(TButtonGadget::TState(state));
}

//----------------------------------------------------------------------------

//
// Construct a button gadget that loads its own bitmap resource
//
TButtonGadget::TButtonGadget(TResId glyphResIdOrIndex,
                             int    id,
                             TType  type,
                             bool   enabled,
                             TState state,
                             bool   sharedGlyph)
:
  TGadget(id, ButtonUp),
  SharingGlyph(sharedGlyph)
{
  // If we are sharing the glyph held by our window, then we won't need to load
  // the resource
  //
  if (sharedGlyph) {
    ResId = 0;
    GlyphIndex = (int)(const char far*)glyphResIdOrIndex;
    GlyphCount = 1;
  }
  else {
    ResId = glyphResIdOrIndex.IsString() ?
                strnewdup(glyphResIdOrIndex) : (char far*)glyphResIdOrIndex;
    GlyphIndex = -1;   // Need to get during BuildCelArray
    GlyphCount = 4;
  }

  CelArray = 0;
  BitmapOrigin.x = BitmapOrigin.y = 0;
  Type = type;
//  Repeat = repeat;  
  TrackMouse = true;
  State = state;
  NotchCorners = true;
  Pressed = false;
  SetEnabled(enabled);
  SetShadowStyle(DoubleShadow);
  SetAntialiasEdges(true);

  TRACEX(OwlGadget, OWL_CDLEVEL, "TButtonGadget constructed @" << (void*)this);
}

//
// Destruct this button gadget, freeing up allocated resources
//
TButtonGadget::~TButtonGadget()
{
  delete CelArray;
  if (ResId.IsString())
    delete[] (char far*)ResId;

  TRACEX(OwlGadget, OWL_CDLEVEL, "TButtonGadget destructed @" << (void*)this);
}

//
// Set the shadow style for this button. May be ignored on some 3d UI platforms
//
void
TButtonGadget::SetShadowStyle(TShadowStyle shadowStyle)
{
  if (!TSystem::Has3dUI()) {
    TBorders  borders;

    ShadowStyle = shadowStyle;
    borders.Left = borders.Top = 2;
    borders.Right = borders.Bottom = ShadowStyle + 1;
    SetBorders(borders);
  }
}

//
// Initiate a command enable for this button gadget
//
void
TButtonGadget::CommandEnable()
{
  PRECONDITION(Window);

  // Must send, not post here, since a ptr to a temp is passed
  //
  // This might be called during idle processing before the
  // HWND has created.  Therefore, confirm handle exists.
  //
  if (Window->GetHandle()) {
    Window->HandleMessage(
      WM_COMMAND_ENABLE,
      0,
      TParam2(&TButtonGadgetEnabler(*Window, this))
    );
  }
}

//
// Respond to a WM_SYSCOLORCHANGE, in this case to rebuild the CelArray with
// possibly new 3d colors
//
void
TButtonGadget::SysColorChange()
{
}

//
// Perform an exclusive checking of this gadget by unchecking the neighboring
// exclusive button gadgets
//
void
TButtonGadget::CheckExclusively()
{
  PRECONDITION(Window);

  if (State != Down) {
    if (Window) {
      TButtonGadget*  first = 0;
      TButtonGadget*  last = this;

      // Look for the start of the group in which this button is located
      //
      for (TGadget* g = Window->FirstGadget(); g && g != this;
        g = Window->NextGadget(*g)) {

        TButtonGadget* bg = TYPESAFE_DOWNCAST(g, TButtonGadget);
        if (!bg || bg->Type != Exclusive)
          first = 0;

        else if (!first)
          first = bg;
      }

      if (!first)
        first = this;

      // Look for the end of the group in which this button is located
      //
      while (Window->NextGadget(*last)) {
        TButtonGadget* bg = TYPESAFE_DOWNCAST(Window->NextGadget(*last), TButtonGadget);
        if (!bg || bg->Type != Exclusive)
          break;

        else
          last = bg;
      }

      // Walk all the gadget between first and last (inclusive) and pop them up
      // if they are down
      //
      while (true) {
        if (first->State == Down) {
          first->State = Up;
          first->Invalidate();
          first->Update();
        }

        if (first == last)  // All done
          break;

        first = TYPESAFE_DOWNCAST(first->NextGadget(), TButtonGadget);
      }
    }

    State = Down;
  }
}

//
// Set the state of a button. Handles setting down on an exclusive button to
// pop out the neighbors
//
void
TButtonGadget::SetButtonState(TState newState)
{
  if (newState != State) {
      if ((Type == Exclusive || Type == SemiExclusive)
           && newState == Down)
        CheckExclusively();
      else
        State = newState;
    Invalidate();
    Update();
  }
}

//
// Set the bounding rect for this button gadget. Also takes care of
// re-centering the glyph
//
void
TButtonGadget::SetBounds(const TRect& bounds)
{
  PRECONDITION(Window);
  TRACEX(OwlGadget, 1, "TButtonGadget::SetBounds() enter @" << this <<
    " bounds " << bounds);

  TGadget::SetBounds(bounds);

  // Center the glyph within the inner bounds
  //
  TRect  innerRect;
  GetInnerRect(innerRect);

  TSize  bitmapSize = CelArray ? CelArray->CelSize() : Window->GetCelArray().CelSize();
  BitmapOrigin.x = innerRect.left + (innerRect.Width() - bitmapSize.cx) / 2;
  BitmapOrigin.y = innerRect.top + (innerRect.Height() - bitmapSize.cy) / 2;
  TRACEX(OwlGadget, 1, "TButtonGadget::SetBounds() leave @" << this <<
    " bounds " << bounds);
}

//
// Find out how big this button gadget wants to be. Calculated using the base
// size to get the borders, etc. plus the glyph size.
//
void
TButtonGadget::GetDesiredSize(TSize& size)
{
  PRECONDITION(Window);
  TRACEX(OwlGadget, 1, "TButtonGadget::GetDesiredSize() enter @"<< this <<
    " size " << size);

  TGadget::GetDesiredSize(size);

  // Build our CelArray or CelArray entry if not done already
  //
  if (!CelArray && GlyphIndex < 0)
    BuildCelArray();

  size += CelArray ? CelArray->CelSize() : Window->GetCelArray().CelSize();
  TRACEX(OwlGadget, 1, "TButtonGadget::GetDesiredSize() leave @"<< this <<
    " size " << size);
}


//
// Virtual function responsible for supplying the dib for the glyph. Can be
// overriden to get dib from elsewhere, cache it, map colors differently, etc.
//
// Returns 0 if no resource was specified for this button
//
TDib*
TButtonGadget::GetGlyphDib()
{
  PRECONDITION(Window);

  if (ResId) {
    TDib* glyph = new TDib(*Window->GetModule(), ResId);
    glyph->MapUIColors( TDib::MapFace | TDib::MapText | TDib::MapShadow |
      TDib::MapHighlight );
    return glyph;
  }
  return 0;
}

//
// Virtual function responsible for releasing glyph dib as needed based on how
// GetGlyphDib() got it (if different from new/delete).
//
void
TButtonGadget::ReleaseGlyphDib(TDib* glyph)
{
  delete glyph;
}

//
// Build the CelArray member using the resource bitmap as the base glyph
// CelArray may contain an existing cel array that should be deleted if
// replaced.
//
// The CelArray and glyph painting can work in one of the following ways:
//   1. ResId ctor is used, ...., glyph states are cached in this CelArray
//   2. ResId ctor is used, CelArray holds single glyph and paints state on
//      the fly
//   3. ResId ctor is used, glyph is added to Window's CelArray and paints
//      state on the fly
//   4. glyphIndex ctor is used, uses Window's CelArray glyph and paints state
//      on the fly
//
void
TButtonGadget::BuildCelArray()
{
  PRECONDITION(Window);

  TDib*  glyph = GetGlyphDib();

  // Case 4, no resource of our own--using a cel in our Window's CelArray
  //
  if (!glyph)
    return;


  // Case 3, add (or replace old) our glyph to our Window's CelArray
  //
  TSize glyphSize(glyph->Width(), glyph->Height());
  TCelArray& celArray = Window->GetCelArray(glyph->Width(), glyph->Height());

  if (SharingGlyph && (glyphSize == celArray.CelSize())) {
    if (GlyphIndex >= 0)
      celArray.Replace(GlyphIndex, *glyph);
    else
      GlyphIndex = celArray.Add(*glyph);
  }
  else {

    // Case 2, build a CelArray containing only the normal glyph state
    //
    delete CelArray;
    CelArray = new TCelArray(*glyph, 1); //CelsTotal);
    GlyphIndex = 0;
    SharingGlyph = false;
  }

  ReleaseGlyphDib(glyph);

  // Case 1, for compatibility for now...
  //
}

//
// Perform all of the painting for this button gadget
//
void
TButtonGadget::Paint(TDC& dc)
{
  PRECONDITION(Window);

  // Make sure our style matches our state, then paint our gadget borders
  //
  BorderStyle = (Pressed || State == Down) ? ButtonDn : ButtonUp;
  PaintBorder(dc);

  // Determine which CelArray to paint from: ours or our Window's
  //
  TCelArray& celArray = CelArray ? *CelArray : Window->GetCelArray();

  // Get the inner rect to use as the button face
  //
  TRect  faceRect;
  GetInnerRect(faceRect);

  // Calc the source rect from the celarray. The dest point of the glyph is
  // relative to the face rect.
  //
  TRect  srcRect(celArray.CelRect(GlyphIndex));
  TPoint dstPt(BitmapOrigin - faceRect.TopLeft());

  // Create a UI Face object for this button & let it paint the button face
  //
  TUIFace face(faceRect, celArray);

  if (!GetEnabled())
    face.Paint(dc, srcRect, dstPt, TUIFace::Disabled, false);
  else if (State == Indeterminate)
    face.Paint(dc, srcRect, dstPt, TUIFace::Indeterm, Pressed);
  else if (State == Down && !Pressed)
    face.Paint(dc, srcRect, dstPt, TUIFace::Down, false);
  else
    face.Paint(dc, srcRect, dstPt, TUIFace::Normal, Pressed);
}

//
// Invalidate the rectangle used by this gadget to cause it to repaint
//
void
TButtonGadget::Invalidate()
{
  InvalidateRect(TRect(0, 0, Bounds.Width(), Bounds.Height()), false);
}

//
// Begin button pressed state, repaint & enter menuselect state
//
void
TButtonGadget::BeginPressed(TPoint&)
{
  Pressed = true;
  Invalidate();
  Update();
  if (Window->GetHintMode() == TGadgetWindow::PressHints)
    Window->SetHintCommand(GetId());
}

//
// Cancel pressed state, repaint & end menuselect state
//
void
TButtonGadget::CancelPressed(TPoint&)
{
  Pressed = false;
  Invalidate();
  Update();
  if (Window->GetHintMode() == TGadgetWindow::PressHints)
    Window->SetHintCommand(-1);
}

//
// The action method called on a completed 'click', generates WM_COMMAND
//
// Invoked by mouse-up event inside the Gadget. Sets member data "Pressed"
// to false, changes state for attribute buttons, and paints the button
// in its current state.
//
// Command buttons just send the command
// Exclusive buttons check themselves and uncheck neighbors.
// NonExclusive buttons toggle their check state.
// SemiExclusive uncheck neighbors on press, but can also be unpressed.
//
void
TButtonGadget::Activate(TPoint& pt)
{
  switch (Type) {
    case Exclusive:
      if (State != Down)
        CheckExclusively();
      break;

    case NonExclusive:
      State = State == Up ? Down : Up;
      break;

    case SemiExclusive:
      if (State != Down)
        CheckExclusively();
      else
        State = Up;
      break;
  }

  // Unpress the button
  //
  CancelPressed(pt);

  // Send the associated command for all enabled buttons except for exclusive
  // buttons that are being poped up
  //
  if (!((Type == Exclusive || Type == SemiExclusive) && State != Down) &&
      GetEnabled())
    Window->PostMessage(WM_COMMAND, GetId()); 
}

//
// Handle the mouse left button down & enter the pressed state
//
void
TButtonGadget::LButtonDown(uint modKeys, TPoint& pt)
{
  TGadget::LButtonDown(modKeys, pt);
  BeginPressed(pt);
}

//
// Mouse has entered this button, (not pressed). Show hints if that style
// is enabled
//
void
TButtonGadget::MouseEnter(uint modKeys, TPoint& pt)
{
  TGadget::MouseEnter(modKeys, pt);
  if (Window->GetHintMode() == TGadgetWindow::EnterHints)
    Window->SetHintCommand(GetId());
}

//
// Mouse has moved (back) into this gadget. Push or pull the button up & down
// as needed.
//
void
TButtonGadget::MouseMove(uint modKeys, TPoint& pt)
{
  TGadget::MouseMove(modKeys, pt);

  bool hit = PtIn(pt);
  if (Pressed) {
    if (!hit)
      CancelPressed(pt);
  }
  else if (hit) {
    BeginPressed(pt);
  }
}

//
// Mouse has left this button, (not pressed). Hide hints if that style
// is enabled
//
void
TButtonGadget::MouseLeave(uint modKeys, TPoint& pt)
{
  TGadget::MouseLeave(modKeys, pt);
  if (Window->GetHintMode() == TGadgetWindow::EnterHints)
    Window->SetHintCommand(-1);
}

//
// Handle the mouse left button up & leave the pressed state. If the mouse is
// still on this button, i.e. it is still pressed, then perform the button
// action.
//
void
TButtonGadget::LButtonUp(uint modKeys, TPoint& pt)
{
  TGadget::LButtonUp(modKeys, pt);
  if (Pressed)
    Activate(pt);
}
