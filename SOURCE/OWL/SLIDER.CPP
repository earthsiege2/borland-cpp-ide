//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TSlider, slider UI widget abstract base class.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/slider.h>
#include <owl/dc.h>

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TSlider, TScrollBar)
  EV_WM_SIZE,
  EV_WM_GETDLGCODE,
  EV_WM_ERASEBKGND,
  EV_WM_PAINT,
  EV_WM_LBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
  EV_WM_LBUTTONDBLCLK,
  EV_WM_KEYDOWN,
  EV_WM_SETFOCUS,
  EV_WM_KILLFOCUS,
END_RESPONSE_TABLE;

TSize  TSlider::MouseOffset;
TDC*   TSlider::SlideDC = 0;

//
// Constructor for a TSlider object
//
TSlider::TSlider(TWindow*        parent,
                 int             id,
                 int x, int y, int w, int h,
                 TResId          thumbResId,
                 TModule*        module)
:
  TScrollBar(parent, id, x, y, w, h, true, module),
  ThumbResId(thumbResId),
  ThumbRect(0, 0, 9, 20),
  CaretRect(3, 3, 3+3, 3+13)
{
  SetRange(0, 100);
  Pos = 0;
  ThumbRgn = 0;
  TicGap = Range/10;
  SlotThick = 17;
  Snap = true;

  Sliding = false;
  
  // get slot size from Attr.H set by TScrollBar ?

  Attr.W = w;
  Attr.H = h;
}

//
//
//
TSlider::~TSlider()
{
  delete ThumbRgn;
}

//
// Setup slider window
//
void
TSlider::SetupWindow()
{
  TScrollBar::SetupWindow();
  SetupThumbRgn();
}

//
// Check & set the slider range
//
void
TSlider::SetRange(int min, int max) 
{
  Min = min;
  Max = max;
  if (Max > Min)
    Range = Max - Min;
  else if (Min > Max)
    Range = Min - Max;
  else
    Range = 1;
}

//
// Set the position of the thumb
//
void
TSlider::SetPosition(int pos)
{
  //
  // constrain pos to be in the range "Min .. Max" & snap to tics if enabled
  //
  pos = SnapPos(pos);

  //
  // Slide thumb to new position, converting pos to pixels
  //
  if (pos != Pos) {
    if (HWindow) {
      TDC* dc = SlideDC ? SlideDC : new TClientDC(HWindow);
      SlideThumb(*dc, pos);
      if (!SlideDC)
        delete dc;
    }
    Pos = pos;
  }
}

//
// setup region that defines the thumb shape for this slider class.
// default region is a simple bounding rect, but could be any shape.
//
void
TSlider::SetupThumbRgn()
{
  if (!ThumbRgn)
    ThumbRgn = new TRegion(ThumbRect);
}

//
// Slide the thumb & perform necessary blitting & painting.
// Assumes that Pos, Min & Max are up to date.
//
void
TSlider::SlideThumb(TDC& dc, int pos)
{
  TPoint point = PosToPoint(pos);

  HideCaret();
  GetBkColor(dc);
  if (ThumbRgn) {
    TRegion  oldRgn(ThumbRect);
    TRect    newThumbRect(point, ThumbRect.Size());

    *ThumbRgn += point-ThumbRect.TopLeft();
  
    dc.SelectClipRgn(*ThumbRgn);
    dc.BitBlt(newThumbRect, dc, ThumbRect.TopLeft());

    ThumbRect = newThumbRect;

    oldRgn -= *ThumbRgn;
    dc.SelectClipRgn(oldRgn);
    PaintSlot(dc);
  }
  else {
    ThumbRect = TRect(point, ThumbRect.Size());
    PaintSlot(dc);
    PaintThumb(dc);
  }
  SetCaretPos(ThumbRect.left+CaretRect.left, ThumbRect.top+CaretRect.top);
  ShowCaret();
}

//
// Paint the thumb itself using a resource DIB translated to the current system
// button colors. Overlaps the slot.
//
void
TSlider::PaintThumb(TDC& dc)
{
  TDib  thumbDib(*GetModule(), ThumbResId);
  thumbDib.MapUIColors(
    TDib::MapFace|TDib::MapText|TDib::MapShadow|TDib::MapHighlight,
    &dc.GetBkColor()
  );
  int  dibX = (Sliding || !IsWindowEnabled()) ? thumbDib.Width()/2 : 0;
  dc.SetDIBitsToDevice(ThumbRect, TPoint(dibX, 0), thumbDib);
}

//
// Constrain pos to be in the range "Min .. Max" &
// perform 'Snap'ing if enabled by rounding pos to nearest TicGap
//
int
TSlider::SnapPos(int pos)
{
  if (pos > Max)
    pos = Max;

  else if (pos < Min)
    pos = Min;

  return Snap ? (((pos-Min)+TicGap/2)/TicGap)*TicGap + Min : pos;
}

//
// Get & release a brush obtained from our parent window for use in painting 
// background areas in this control.
//
void
TSlider::GetBkColor(TDC& dc)
{
#if defined(BI_PLAT_WIN32)
  Parent->HandleMessage(WM_CTLCOLORSTATIC,
                        (WPARAM)(HDC)dc,
                        LPARAM(HWindow));
#else
  Parent->HandleMessage(WM_CTLCOLOR, 
                        (WPARAM)(HDC)dc,
                        MAKELPARAM(HWindow, CTLCOLOR_STATIC));
#endif  
  BkColor = dc.GetBkColor();
}

//
// 
//
void
TSlider::EvSize(uint sizeType, TSize& size)
{
  TScrollBar::EvSize(sizeType, size);
}

//
// Make sure we get cursor movement keys to move the thumb
//
uint
TSlider::EvGetDlgCode(MSG far*)
{
  return DLGC_WANTARROWS;
}

//
// Paint the whole slider: ruler, slot & thumb
//
void
TSlider::EvPaint()
{
  HideCaret();
  if (ThumbRgn) {                   // use thumb region if avalable
    TRegion updateRgn;
    GetUpdateRgn(updateRgn);

    TPaintDC  dc(*this);

    GetBkColor(dc);

    TRegion thumbClip = *ThumbRgn;  // set clip to intersect of update & thumb
    thumbClip &= updateRgn;
    dc.SelectClipRgn(thumbClip);
    PaintThumb(dc);

    updateRgn -= thumbClip;
    dc.SelectClipRgn(updateRgn);    // set clip to update minus thumb
    ValidateRgn(*ThumbRgn);
    PaintSlot(dc);
    PaintRuler(dc);
  }
  else {                          // no region, thumb will flicker a little
    TPaintDC  dc(*this);

    GetBkColor(dc);
    PaintSlot(dc);
    PaintRuler(dc);
    PaintThumb(dc);
  }
  ShowCaret();
}

//
// We'll always erase as we paint to avoid flicker
//
bool
TSlider::EvEraseBkgnd(HDC)
{
  return true;
}

//
// If a button down on the thumb, then enter sliding state.
// If in the slot, pg up or down. If on the ruler, jump there.
//
void
TSlider::EvLButtonDown(uint /*modKeys*/, TPoint& point)
{
  if (GetFocus() != HWindow)
    SetFocus();

  int scrollCode = HitTest(point);
  switch (scrollCode) {
    case SB_THUMBPOSITION:
      NotifyParent(scrollCode, SnapPos(PointToPos(point)));
      break;
      
    case SB_LINEUP:
    case SB_LINEDOWN:
    case SB_PAGEUP:
    case SB_PAGEDOWN:
      NotifyParent(scrollCode);
      break;

    case SB_THUMBTRACK: {
      Sliding = true;
      SetCapture();
      HideCaret();
      SlideDC = new TClientDC(HWindow);  // keep this dc around while sliding

      GetBkColor(*SlideDC);  // repaint thumb in pressed state
      PaintThumb(*SlideDC);

      MouseOffset = point-ThumbRect.TopLeft();
      point -= MouseOffset;
      int pos = SnapPos(PointToPos(point));// keep thumb on track & on pos units
      NotifyParent(9, pos);     // undocumented 'begin track' code
      NotifyParent(SB_THUMBTRACK, pos);
    }
  }
}

//
// If sliding then either slide thumb, or detect a lost button up & simulate
// it.
//
void
TSlider::EvMouseMove(uint modKeys, TPoint& point)
{
  if (Sliding && SlideDC) {
    if (!(modKeys&MK_LBUTTON)) {
      EvLButtonUp(modKeys, point);    // we missed a lbutton up somehow...
      return;
    }
    // keep thumb on track & on pos units
    NotifyParent(SB_THUMBTRACK, SnapPos(PointToPos(point - MouseOffset)));
  }
}

//
// Handle button messages if we are sliding by releasing capture & ending
// sliding state
//
void
TSlider::EvLButtonUp(uint /*modKeys*/, TPoint& point)
{
  int pos = SnapPos(PointToPos(point - MouseOffset));
  if (Sliding) {
    Sliding = false;
    NotifyParent(SB_THUMBPOSITION, pos);

    GetBkColor(*SlideDC);   // repaint thumb in released state
    if (ThumbRgn)
      SlideDC->SelectClipRgn(*ThumbRgn);
    PaintThumb(*SlideDC);

    ReleaseCapture();
    delete SlideDC;
    SlideDC = 0;

    ShowCaret();
  }
  NotifyParent(SB_ENDSCROLL, pos);
}

//
// Catch double clicks and eat them
//
void
TSlider::EvLButtonDblClk(uint /*modKeys*/, TPoint&)
{
}

//
// Translate key messages to scroll events w/ repeat.
//
void
TSlider::EvKeyDown(uint key, uint repeatCount, uint /*flags*/)
{
  static int KeyToCode[] = {
    SB_PAGEUP,    // VK_PRIOR
    SB_PAGEDOWN,  // VK_NEXT 
    SB_BOTTOM,    // VK_END
    SB_TOP,       // VK_HOME
    SB_LINEUP,    // VK_LEFT(same as SB_LINELEFT)
    SB_LINEUP,    // VK_UP
    SB_LINEDOWN,  // VK_RIGHT(same as SB_LINERIGHT)
    SB_LINEDOWN   // VK_DOWN
  };

  if (key >= VK_PRIOR && key <= VK_DOWN) {
    for (int i = 0; i < repeatCount; i++)
      NotifyParent(KeyToCode[key-VK_PRIOR], Pos);
    NotifyParent(SB_ENDSCROLL, Pos);
  }
}

//
// Create, position & show a caret when we have focus. Remove it when we lose
// focus
//
void
TSlider::EvSetFocus(HWND /*hWndLostFocus*/)
{
  CreateCaret(true, CaretRect.Width(), CaretRect.Height());
  SetCaretPos(ThumbRect.left+CaretRect.left, ThumbRect.top+CaretRect.top);
  ShowCaret();

//  TScrollBar::EvSetFocus(hWndLostFocus);  // Can't let SCROLLBAR see this
}

void
TSlider::EvKillFocus(HWND hWndGetFocus)
{
  HideCaret();
  DestroyCaret();

  TScrollBar::EvKillFocus(hWndGetFocus); // need to let TWindow do focus save
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_ABSTRACT_STREAMABLE1(TSlider, TScrollBar);

void*
TSlider::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TSlider* o = GetObject();
  ReadBaseObject((TScrollBar*)o, is);
  is >> o->Min
     >> o->Max
     >> o->Pos
     >> o->ThumbResId
     >> o->ThumbRect
     >> o->TicGap
     >> o->CaretRect
     >> o->Snap;
  o->SetRange(o->Min, o->Max);  // let it calculate Range
  return o;
}

void
TSlider::Streamer::Write(opstream& os) const
{
  TSlider* o = GetObject();
  WriteBaseObject((TScrollBar*)o, os);
  os << o->Min
     << o->Max
     << o->Pos
     << o->ThumbResId
     << o->ThumbRect
     << o->CaretRect
     << o->TicGap
     << o->Snap;
}

#endif
