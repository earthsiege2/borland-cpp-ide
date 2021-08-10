//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TButtonGadget.
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/buttonga.h>
#include <owl/gadgetwi.h>
#include <owl/celarray.h>

//
// make the monochrome bitmap large enough to hold any possible bitmap
//
#define GLYPH_MASK_WIDTH   128
#define GLYPH_MASK_HEIGHT  128
const long RopPSDPxax = 0x00B8074AL;  //
const long RopDSPDxax = 0x00E20746L;  // 

//
// local 'class' vars
//
static THatch8x8Brush ditherBrush(THatch8x8Brush::Hatch11F1,
                                  ::GetSysColor(COLOR_BTNHIGHLIGHT),
                                  ::GetSysColor(COLOR_BTNHIGHLIGHT));

static TBitmap      glyphMask(GLYPH_MASK_WIDTH, GLYPH_MASK_HEIGHT, 1, 1, 0);

//
// command enabler for button gadgets
//
class _OWLCLASS TButtonGadgetEnabler : public TCommandEnabler {
  public:
    TButtonGadgetEnabler(HWND hWndReceiver, TButtonGadget* g)
      : TCommandEnabler(g->GetId(), hWndReceiver) {
      Gadget = g;
    }

    //
    // override member functions of TCommandEnabler
    //
    void  Enable(bool);
    void  SetText(const char far*);
    void  SetCheck(int);

  protected:
    TButtonGadget*  Gadget;
};

void
TButtonGadgetEnabler::Enable(bool enable)
{
  TCommandEnabler::Enable(enable);
  Gadget->SetEnabled(enable);
}

void
TButtonGadgetEnabler::SetText(const char far*)
{
# pragma warn -ccc
  CHECK(false);
# pragma warn .ccc
}

void
TButtonGadgetEnabler::SetCheck(int state)
{
  Gadget->SetButtonState(TButtonGadget::TState(state));
}

TButtonGadget::TButtonGadget(TResId bmpResId,
                             int    id,
                             TType  type,
                             bool   enabled,
                             TState state,
                             bool   repeat)
:
  TGadget(id, Plain)
{
  ResId = bmpResId.IsString() ? strnewdup(bmpResId) : (char far*)bmpResId;
  CelArray = 0;
  BitmapOrigin.x = BitmapOrigin.y = 0;
  Type = type;
  Repeat = repeat;
  TrackMouse = true;
  State = state;
  NotchCorners = true;
  Pressed = false;
  SetEnabled(enabled);
  SetShadowStyle(DoubleShadow);
  SetAntialiasEdges(true);
}

TButtonGadget::~TButtonGadget()
{
  delete CelArray;
  if (ResId.IsString())
    delete (char far*)ResId;
}

void
TButtonGadget::SetShadowStyle(TShadowStyle shadowStyle)
{
  TBorders  borders;

  ShadowStyle = shadowStyle;
  borders.Left = borders.Top = 2;
  borders.Right = borders.Bottom = ShadowStyle + 1;
  SetBorders(borders);
}

void
TButtonGadget::CommandEnable()
{
  // Must send, not post here, since a ptr to a temp is passed
  //
  Window->Parent->HandleMessage(
    WM_COMMAND_ENABLE,
    0,
    (LPARAM)&TButtonGadgetEnabler(*Window->Parent, this)
  );
}

void
TButtonGadget::SysColorChange()
{
  ditherBrush.Reconstruct(THatch8x8Brush::Hatch11F1,
                          ::GetSysColor(COLOR_BTNHIGHLIGHT),
                          ::GetSysColor(COLOR_BTNHIGHLIGHT));
  BuildCelArray();
}

void
TButtonGadget::CheckExclusively()
{
  if (State != Down) {
    if (Window) {
      TGadget*        g = Window->FirstGadget();
      TButtonGadget*  first = 0;
      TButtonGadget*  last = this;

      //
      // look for the start of the group in which the receiver is located
      //
      while (g != this) {
        TButtonGadget* bg = TYPESAFE_DOWNCAST(g, TButtonGadget);
        if (!bg || bg->Type != Exclusive)
          first = 0;

        else if (!first)
          first = bg;

        g = g->NextGadget();
      }
      if (!first)
        first = this;

      // Look for the end of the group in which the receiver is located
      //
      while (last->NextGadget()) {
        TButtonGadget* bg = TYPESAFE_DOWNCAST(last->NextGadget(), TButtonGadget);
        if (!bg || bg->Type != Exclusive)
          break;

        else
          last = bg;
      }

      while (true) {
        CHECK(first);     // Already know they are buttons, but just in case...
        if (first->State == Down) {
          first->State = Up;
          first->Invalidate();
          first->Update();
        }

        if (first == last)
          break;

        first = TYPESAFE_DOWNCAST(first->NextGadget(), TButtonGadget);
      }
    }

    State = Down;
  }
}

void
TButtonGadget::SetButtonState(TState state)
{
  if (state != State) {
    if (Type == Exclusive && state == Down)
      CheckExclusively();

    State = state;
    Invalidate();
    Update();
  }
}

void
TButtonGadget::SetBounds(TRect& bounds)
{
  TRect  innerRect;
  TSize  bitmapSize = CelArray->CelSize();

  TGadget::SetBounds(bounds);

  // Center the glyph within the inner bounds
  //
  GetInnerRect(innerRect);

  BitmapOrigin.x = innerRect.left + (innerRect.Width() - bitmapSize.cx) / 2;
  BitmapOrigin.y = innerRect.top + (innerRect.Height() - bitmapSize.cy) / 2;
}

void
TButtonGadget::GetDesiredSize(TSize& size)
{
  TGadget::GetDesiredSize(size);

  if (!CelArray)
    BuildCelArray();

  size += CelArray->CelSize();
}

//
// determines the parts of "r1" that do not lie within "r2"
//
// returns the resulting number of rectangles which will be in the
// range "0 .. 4" inclusive
//
uint
Subtract(TRect& r1, TRect& r2, TRect result[4])
{
  if (!r1.Touches(r2)) {
    result[0] = r1;
    return 1;
  }
  else {
    uint  i = 0;

    if (r2.top > r1.top) {
      result[i].left = r1.left;
      result[i].top = r1.top;
      result[i].right = r1.right;
      result[i].bottom = r2.top;
      i++;
    }

    if (r2.bottom < r1.bottom) {
      result[i].left = r1.left;
      result[i].top = r2.bottom;
      result[i].right = r1.right;
      result[i].bottom = r1.bottom;
      i++;
    }

    if (r2.left > r1.left) {
      result[i].left = r1.left;
      result[i].top = max(r1.top, r2.top);
      result[i].right = r2.left;
      result[i].bottom = min(r1.bottom, r2.bottom);
      i++;
    }

    if (r2.right < r1.right) {
      result[i].left = r2.right;
      result[i].top = max(r1.top, r2.top);
      result[i].right = r1.right;
      result[i].bottom = min(r1.bottom, r2.bottom);
      i++;
    }
    return i;
  }
}

//
// build a monochrome mask bitmap for the glyph that has 1's where
// COLOR_BTNFACE is and 0's everywhere else. assumes glyphDC is already setup
//
static void
BuildMask(TDC& maskDC, TRect& maskRect, TDC& glyphDC, TRect& glyphRect)
{
  maskDC.PatBlt(0, 0, maskRect.Width(), maskRect.Height(), WHITENESS);
  glyphDC.SetBkColor(GetSysColor(COLOR_BTNFACE));  // btnface to white
  maskDC.BitBlt(maskRect.left, maskRect.top, glyphRect.Width(), glyphRect.Height(),
                glyphDC, glyphRect.left, glyphRect.top, SRCCOPY);
}

//
// tiles the rectangle with a even dithered (checkerboard) pattern
//
// maskDC determines the stencil area of dither
//
static void
DitherBackground(TDC& dc, TDC& maskDC, TRect& rect)
{
  dc.SelectObject(HBRUSH(ditherBrush));

  dc.SetTextColor(RGB(0, 0, 0));      // 0 to black
  dc.SetBkColor(RGB(255, 255, 255));  // 1 to white

  dc.BitBlt(rect, maskDC, TPoint(0, 0), RopDSPDxax);
}

//
// virtual function responsible for supplying glyphdib. Can be overriden to
// get dib from elsewhere, cache it, map colors differently, etc.
//
TDib*
TButtonGadget::GetGlyphDib()
{
  TDib* glyph = new TDib(*Window->GetModule(), ResId);
  glyph->MapUIColors(
    TDib::MapFace | TDib::MapText | TDib::MapShadow | TDib::MapHighlight
  );
  return glyph;
}

//
// virtual function responsible for releasing glyph dib as needed based on how
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
// replaced
//
void
TButtonGadget::BuildCelArray()
{
  //
  // Get the base glyph as a dib, & map the colors to current SysColors.
  //
  TDib*  glyph = GetGlyphDib();
  TSize  celSize = glyph->Size();

  //
  // Create a TCelArray if we don't already have one, else use existing one.
  //
  if (!CelArray) {
    TBitmap*   bitmap = new TBitmap(TScreenDC(), celSize.cx*CelsTotal,
                                    celSize.cy);
    CelArray = new TCelArray(bitmap, CelsTotal);
  }
  
  TMemoryDC maskDC;
  maskDC.SelectObject(glyphMask);
  TRect maskRect(0,0, celSize.cx, celSize.cy);

  TMemoryDC celDC;
  celDC.SelectObject(*CelArray);
  
  //
  // CelArray[CelNormal]: normal appearance, blit directly from the glyph dib
  //
  TRect nrmlCelRect = CelArray->CelRect(CelNormal);
  celDC.StretchDIBits(nrmlCelRect, maskRect, *glyph);
  
  ReleaseGlyphDib(glyph);

  //
  // CelArray[CelDisabled]: disabled variant of glyph
  //
  TRect celRect = CelArray->CelRect(CelDisabled);

  //
  // make sure area under highlight color ends up face color
  //
  BuildMask(maskDC, maskRect, celDC, nrmlCelRect);
  celDC.TextRect(celRect, GetSysColor(COLOR_BTNFACE));

  //
  // inactivate mask--convert the highlight color to 1's on existing mask
  //
  celDC.SetBkColor(GetSysColor(COLOR_BTNHIGHLIGHT));
  maskDC.BitBlt(maskRect, celDC, nrmlCelRect.TopLeft(), SRCPAINT);

  //
  // make the image look embossed--highlight color offset down & right
  //
  celDC.SetTextColor(RGB(0, 0, 0));  // 0 to black
  celDC.SetBkColor(RGB(255, 255, 255));  // 1 to white

  TBrush  hiliteBrush(GetSysColor(COLOR_BTNHIGHLIGHT));
  celDC.SelectObject(hiliteBrush);  // 0 -> highlight color
  celDC.BitBlt(celRect.left + 1, celRect.top + 1,
               celRect.Width() - 1, celRect.Height() - 1,
               maskDC, 0, 0, RopPSDPxax);

  //
  // fade the image by replacing the button text color with the button
  // shadow color
  //
  TBrush  shadowBrush(GetSysColor(COLOR_BTNSHADOW));
  celDC.SelectObject(shadowBrush);  // 0 -> shadow
  celDC.BitBlt(celRect, maskDC, TPoint(0, 0), RopPSDPxax);

  //
  // CelArray[CelIndeterm]: Indeterminate variant of glyph
  //
  celRect = CelArray->CelRect(CelIndeterm);

  //
  // fade the image by replacing the button text color with the button
  // shadow color
  //
  celDC.SelectObject(shadowBrush);  // 0 -> shadow
  celDC.BitBlt(celRect, maskDC, TPoint(0, 0), RopPSDPxax);

  //
  // dither the background everywhere except where the glyph is
  //
  DitherBackground(celDC, maskDC, celRect);

  //
  // CelArray[CelDown]: Down (but not Pressed) variant of glyph
  //
  celRect = CelArray->CelRect(CelDown);
  celDC.BitBlt(celRect, celDC, CelArray->CelRect(CelNormal).TopLeft(), SRCCOPY);

  //
  // dither the background everywhere except where the glyph is
  //
  BuildMask(maskDC, maskRect, celDC, celRect);
  DitherBackground(celDC, maskDC, celRect);

  maskDC.RestoreBitmap();
  celDC.RestoreBitmap();
  celDC.RestoreBitmap();
  celDC.RestoreBrush();
}

//
//
//
void
TButtonGadget::Paint(TDC& dc)
{
  int     cxBorder = GetSystemMetrics(SM_CXBORDER);
  int     cyBorder = GetSystemMetrics(SM_CYBORDER);
  TPoint  bitmapOrigin = BitmapOrigin;
  TRect   innerRect(cxBorder, cyBorder,
                    Bounds.Width()-cxBorder, Bounds.Height()-cyBorder);

  PaintBorder(dc);  // Assumes Plain border--other styles will be overpainted

  TBrush  faceBrush(GetSysColor(COLOR_BTNFACE));
  TBrush  hiliteBrush(GetSysColor(COLOR_BTNHIGHLIGHT));
  TBrush  shadowBrush(GetSysColor(COLOR_BTNSHADOW));

  //
  // draw top and left
  //
  int shadow = Pressed && Type != Command ? 2 : 1;
  dc.SelectObject(Pressed || State == Down ? shadowBrush : hiliteBrush);
  dc.PatBlt(innerRect.left, innerRect.top,
            innerRect.Width(), shadow * cyBorder, PATCOPY);
  dc.PatBlt(innerRect.left, innerRect.top,
            shadow * cxBorder, innerRect.Height(), PATCOPY);

  if (Pressed || State == Down) {
    innerRect.left += shadow * cxBorder;
    innerRect.top += shadow * cyBorder;
  }
  else {
    int  i = 0;

    //
    // draw right and bottom
    //
    dc.SelectObject(shadowBrush);
    innerRect.bottom -= cyBorder;
    innerRect.right -= cxBorder;

    while (true) {
      dc.PatBlt(innerRect.left, innerRect.bottom,
                innerRect.Width() + cxBorder, cyBorder, PATCOPY);
      dc.PatBlt(innerRect.right, innerRect.top,
                cxBorder, innerRect.Height(), PATCOPY);

      if (++i == ShadowStyle)
        break;

      innerRect.Inflate(-cxBorder, -cyBorder);
    }
  }

  if (NotchCorners || AntialiasEdges && State == Up && !Pressed) {
    dc.SelectObject(faceBrush);
    
    if (NotchCorners) {
      dc.PatBlt(0, 0, cxBorder, cyBorder);
      dc.PatBlt(Bounds.Width() - cxBorder, 0, cxBorder, cyBorder);
      dc.PatBlt(0, Bounds.Height() - cyBorder, cxBorder, cyBorder);
      dc.PatBlt(Bounds.Width() - cxBorder, Bounds.Height() - cyBorder,
                cxBorder, cyBorder);
    }
    if (AntialiasEdges && State == Up && !Pressed) {
      TRect edge(0, 0, Bounds.Width(), Bounds.Height());
      for (int i = 0; i <= shadow; i++) {
        edge.Inflate(-cxBorder,-cyBorder);
        dc.PatBlt(edge.right-cxBorder, edge.top, cxBorder, cyBorder);
        dc.PatBlt(edge.left, edge.bottom-cyBorder, cxBorder, cyBorder);
      }
    }
    dc.RestoreBrush();
  }

  //
  // adjust the bitmap origin based on the state
  //
  if (Pressed || State == Down)
    bitmapOrigin.Offset(shadow * cxBorder, shadow * cyBorder);
  TRect  bitmapRect(bitmapOrigin, CelArray->CelSize());

  TMemoryDC celDC;
  celDC.SelectObject(*CelArray);

  //
  // blit the appropriate cel at the calculated origin
  //
  if (!GetEnabled() || State == Indeterminate) {
    if (!GetEnabled())
      dc.BitBlt(bitmapRect, celDC, CelArray->CelRect(CelDisabled).TopLeft());

    else //(State == Indeterminate)
      dc.BitBlt(bitmapRect, celDC, CelArray->CelRect(CelIndeterm).TopLeft());
  }
  else {
    TRect dirtyRects[4];
    int   numRects = Subtract(innerRect, bitmapRect, dirtyRects);
    if (numRects) {
      dc.SetBkColor(GetSysColor(COLOR_BTNFACE));
      while (numRects--)
        dc.TextRect(dirtyRects[numRects]);
    }
    if (State == Down && !Pressed)
      dc.BitBlt(bitmapRect, celDC, CelArray->CelRect(CelDown).TopLeft());
    else //(State == Up || Pressed)
      dc.BitBlt(bitmapRect, celDC, CelArray->CelRect(CelNormal).TopLeft());
  }

  celDC.RestoreBitmap();
  dc.RestoreBrush();
}

void
TButtonGadget::Invalidate()
{
  TRect  r(0, 0, Bounds.Width(), Bounds.Height());

  r.Inflate(-GetSystemMetrics(SM_CXBORDER), -GetSystemMetrics(SM_CYBORDER));
  InvalidateRect(r, false);
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
  }

  CancelPressed(pt);

  if (!(Type == Exclusive && State != Down) && GetEnabled())
    Window->Parent->PostMessage(WM_COMMAND, GetId());
}

void
TButtonGadget::LButtonDown(uint modKeys, TPoint& pt)
{
  TGadget::LButtonDown(modKeys, pt);
  BeginPressed(pt);
}

void
TButtonGadget::MouseMove(uint modKeys, TPoint& pt)
{
  TGadget::MouseMove(modKeys, pt);

  bool  hit = PtIn(pt);
  if (Pressed) {
    if (!hit)
      CancelPressed(pt);
  }
  else if (hit) {
    BeginPressed(pt);
  }
}

void
TButtonGadget::MouseEnter(uint modKeys, TPoint& pt)
{
  TGadget::MouseEnter(modKeys, pt);
  if (Window->GetHintMode() == TGadgetWindow::EnterHints)
    Window->SetHintCommand(GetId());
}

void
TButtonGadget::MouseLeave(uint modKeys, TPoint& pt)
{
  TGadget::MouseLeave(modKeys, pt);
  if (Window->GetHintMode() == TGadgetWindow::EnterHints)
    Window->SetHintCommand(-1);
}

void
TButtonGadget::LButtonUp(uint modKeys, TPoint& pt)
{
  TGadget::LButtonUp(modKeys, pt);
  if (Pressed)
    Activate(pt);
}
