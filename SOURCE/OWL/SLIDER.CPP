//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Implementation of TSlider, slider UI widget abstract base class.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_SLIDER_H)
# include <owl/slider.h>
#endif
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif
#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TSlider, TScrollBar)
#if !defined(OWL_NATIVECTRL_ALWAYS)
  EV_WM_GETDLGCODE,
  EV_WM_PAINT,
  EV_WM_LBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
  EV_WM_LBUTTONDBLCLK,
  EV_WM_KEYDOWN,
  EV_WM_SETFOCUS,
  EV_WM_KILLFOCUS,
#endif
END_RESPONSE_TABLE;

TSize  TSlider::MouseOffset;
TDC*   TSlider::SlideDC = 0;

//
// Always use the common control when available for sliders.
//
TNativeUse TSlider::ClassNativeUse = nuAlways;

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
  ThumbRect(0, 0, 0, 0)  // This will get setup whwn bitmap is loaded
{
  SetRange(0, 100);
  Pos = 0;
  ThumbRgn = 0;
  TicGap = Range/10;  // Setup 10 evenly spaced tics by default, no array
  Tics = 0;
  TicCount = 0;
  SlotThick = 4;      // Default for all sliders
  Snap = true;
  SelStart = SelEnd = 0;

  Sliding = false;

#if !defined(OWL_NATIVECTRL_NEVER)
  NativeUse = TCommCtrl::IsAvailable() ? ClassNativeUse : nuNever;
#else
  NativeUse = nuNever;
#endif
}

//
// Constructor for a TSlider object created from resource
//
TSlider::TSlider(TWindow* parent, int resId, TResId thumbResId, TModule* module)
:
  TScrollBar(parent, resId, module),
  ThumbResId(thumbResId),
  ThumbRect(0, 0, 0, 0)  // This will get setup whwn bitmap is loaded
{
  SetRange(0, 100);
  Pos = 0;
  ThumbRgn = 0;
  TicGap = Range/10;  // Setup 10 evenly spaced tics by default, no array
  Tics = 0;
  TicCount = 0;
  SlotThick = 4;      // Default for all sliders
  Snap = true;
  SelStart = SelEnd = 0;

  Sliding = false;

#if !defined(OWL_NATIVECTRL_NEVER)
  NativeUse = TCommCtrl::IsAvailable() ? ClassNativeUse : nuNever;
#else
  NativeUse = nuNever;
#endif
}
//
//
//
TSlider::~TSlider()
{
  delete[] Tics;
  delete ThumbRgn;
  delete SlideDC;
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

#if !defined(OWL_NATIVECTRL_NEVER)
  if ((NativeUse & nuUsing) && GetHandle()) {
//    TParam2 p2 = (Attr.Style & TBS_VERT) ? MkParam2(max, min) : MkParam2(min, max);
    TParam2 p2 = MkParam2(min, max);
    SendMessage(TBM_SETRANGE, true, p2);  // Swapped for vertical
  }
#endif
}

//
// Set the position of the thumb & always redraw
//
void
TSlider::SetPosition(int pos)
{
  SetPosition(pos, true);
}

//
// Set the position of the thumb w/ optional redraw
//
void
TSlider::SetPosition(int pos, bool redraw)
{
  // Constrain pos to be in the range "Min .. Max" & snap to tics if enabled
  //
  pos = SnapPos(pos);

  // Slide thumb to new position, converting pos to pixels
  //
  if (GetHandle()) {
    if (NativeUse & nuUsing) {
      SendMessage(TBM_SETPOS, redraw, pos);
    }
#if !defined(OWL_NATIVECTRL_ALWAYS)
    else {
      if (SlideDC)
        SlideThumb(*SlideDC, pos);
      else
        SlideThumb(TClientDC(GetHandle()), pos);
    }
#endif
  }
  Pos = pos;
}

//
// Set the ruler evenly spaced tics and snap. Snapping is not supported in
// native currently
//
void
TSlider::SetRuler(int ticGap, bool snap)
{
  TicGap = ticGap;
  Snap = snap;
  delete[] Tics;
  Tics = 0;

  if (GetHandle()) {
    if (NativeUse & nuUsing)
      SendMessage(TBM_SETTICFREQ, ticGap, 0);
#if !defined(OWL_NATIVECTRL_ALWAYS)
    else
      Invalidate();  
#endif
  }
}

//
// Set the ruler custom tics and snap. Snapping is not supported in native
// currently
//
void
TSlider::SetRuler(int tics[], int ticCount, bool snap)
{
  PRECONDITION(tics || ticCount == 0);  // A 0 tics array is only OK if no tics

  // Alloc the array if the size is different, or we dont have one. Then copy
  // the tic positions
  //
  if (ticCount > TicCount || !Tics) {
    delete[] Tics;
    Tics = ticCount ? new int[ticCount] : 0;
  }
  for (int i = 0; i < ticCount; i++)
    if (tics[i] >= Min && tics[i] <= Max)  // Ignore out of range tics
      Tics[i] = tics[i];
  TicCount = ticCount;

  Snap = snap;

  if (GetHandle()) {
    if (NativeUse & nuUsing) {
      SendMessage(TBM_CLEARTICS, false);
      for (int i = 0; i < TicCount; i++)
        SendMessage(TBM_SETTIC, i, tics[i]);
    }
#if !defined(OWL_NATIVECTRL_ALWAYS)
    else
      Invalidate();  
#endif
  }
}

//
// Set a selection range for the slider.
// Requires that TBS_ENABLESELRANGE style attribute be set.
//
void
TSlider::SetSel(int start, int end, bool redraw)
{
  // Save selection state
  //
  SelStart = start;
  SelEnd = end;

  if (GetHandle()) {
    if (NativeUse & nuUsing)
      SendMessage(TBM_SETSEL, redraw, MkUint32(uint16(start), uint16(end)));
#if !defined(OWL_NATIVECTRL_ALWAYS)
    else
      Invalidate(); 
#endif
  }
}

//
// Get the selection range from the slider.
// Requires that TBS_ENABLESELRANGE style attribute be set.
//
void
TSlider::GetSel(int& start, int& end)
{
  if (GetHandle()) {
    if (NativeUse & nuUsing) {
      start = (int)SendMessage(TBM_GETSELSTART);
      end = (int)SendMessage(TBM_GETSELEND);
    }
#if !defined(OWL_NATIVECTRL_ALWAYS)
#endif
  }
  // Resync selection state
  //
  SelStart = start;
  SelEnd = end;
}

//----------------------------------------------------------------------------
// Protected implementation

//
// Return the windows system class name that this slider is basing itself on.
// It depends on if NativeUse&nuUsing set.
//
char far*
TSlider::GetClassName()
{
#if defined(OWL_NATIVECTRL_ALWAYS)
  PRECONDITION(TCommCtrl::IsAvailable());
  NativeUse = TNativeUse(NativeUse | nuUsing);
  return TRACKBAR_CLASS;

#elif defined(OWL_NATIVECTRL_NEVER)
  NativeUse = TNativeUse(NativeUse & ~nuUsing);
  return TScrollBar::GetClassName();

#else
  if ((NativeUse & nuSuggestion) >= nuDontCare && TCommCtrl::IsAvailable())
    NativeUse = TNativeUse(NativeUse | nuUsing);
  else
    NativeUse = TNativeUse(NativeUse & ~nuUsing);

  if (NativeUse & nuUsing) {
    if (!Tics)
      Attr.Style |= TBS_AUTOTICKS;
    return TRACKBAR_CLASS;
  }
  // Just use the generic owl class with our own name, since we don't need the
  // native scrollbar window class for any implementation
  //
  return "OWL_Slider";
#endif
}

//
// Setup slider window
//
void
TSlider::SetupWindow()
{
  TScrollBar::SetupWindow();

#if !defined(OWL_NATIVECTRL_ALWAYS)

  // For internal impl, setup the thumb rect & region, & set bkgnd color to
  // transparent since we'll always erase as we paint to avoid flicker
  //
  if (!(NativeUse & nuUsing)) {
    TPoint point = PosToPoint(Pos);
    TDib  thumbDib(*GetModule(), ThumbResId);
    ThumbRect.SetWH(point.x, point.y, thumbDib.Width()/2, thumbDib.Height());
    SetupThumbRgn();
    SetBkgndColor(TColor::Transparent);
  }
  // For native implementation, pass our setup properties to the native control
  //
  else {
#endif

    SetRange(Min, Max);
    if (Tics)
      SetRuler(Tics, TicCount, Snap);
    else
      SetRuler(TicGap, Snap);
    SetSel(SelStart, SelEnd, false);
    SetPosition(Pos, true);

#if !defined(OWL_NATIVECTRL_ALWAYS)
  }
#endif
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

// Leave the whole implemenation out if built with OWL_NATIVECTRL_ALWAYS
//
#if !defined(OWL_NATIVECTRL_ALWAYS)

//
// Setup region that defines the thumb shape for this slider class.
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
    ThumbRect.MoveTo(point.x, point.y);
    PaintSlot(dc);
    PaintThumb(dc);
  }

  {
    TClientDC dc(*this);
    THatch8x8Brush br(THatch8x8Brush::Hatch11F1,
                      TColor::White, TColor::Sys3dFace); 
    dc.FrameRect(GetClientRect(), br);
  }
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
// Get & release a brush obtained from our parent window for use in painting
// background areas in this control.
//
void
TSlider::GetBkColor(TDC& dc)
{
#if defined(BI_PLAT_WIN32)
  Parent->HandleMessage(WM_CTLCOLORSTATIC,
                        TParam1(HDC(dc)),
                        TParam2(GetHandle()));
#else
  Parent->HandleMessage(WM_CTLCOLOR,
                        TParam1(HDC(dc)),
                        MkParam2(GetHandle(), CTLCOLOR_STATIC));
#endif
  BkColor = dc.GetBkColor();
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
  if (NativeUse & nuUsing) {
    DefaultProcessing();
    return;
  }

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
  if (GetFocus() == GetHandle()) {
    TClientDC dc(*this);
    dc.FrameRect(GetClientRect(), THatch8x8Brush(THatch8x8Brush::Hatch11F1));
  }
}

//
// If a button down on the thumb, then enter sliding state.
// If in the slot, pg up or down. If on the ruler, jump there.
//
void
TSlider::EvLButtonDown(uint /*modKeys*/, TPoint& point)
{
  if (NativeUse & nuUsing) {
    DefaultProcessing();
    return;
  }

  if (GetFocus() != GetHandle())
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
      SlideDC = new TClientDC(GetHandle());  // keep this dc around while sliding

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
  if (NativeUse & nuUsing) {
    DefaultProcessing();
    return;
  }

  if (Sliding && SlideDC) {
    if (!(modKeys&MK_LBUTTON)) {
      EvLButtonUp(modKeys, point);    // we missed a lbutton up somehow...
      return;
    }
    // Keep thumb on track & on pos units
    //
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
  if (NativeUse & nuUsing) {
    DefaultProcessing();
    return;
  }

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
  }
  NotifyParent(SB_ENDSCROLL, pos);
}

//
// Catch double clicks and eat them
//
void
TSlider::EvLButtonDblClk(uint modKeys, TPoint& point)
{
  if (NativeUse & nuUsing) {
    TControl::EvLButtonDblClk(modKeys, point);
  }
  else {
    // For our purpose, a DoubleClick's just another click...
    //
    EvLButtonDown(modKeys, point);
  }
}

//
// Translate key messages to scroll events w/ repeat.
//
void
TSlider::EvKeyDown(uint key, uint repeatCount, uint /*flags*/)
{
  if (NativeUse & nuUsing) {
    DefaultProcessing();
    return;
  }

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
// Paint a focus rect when we have focus. Remove it when we lose focus
//
void
TSlider::EvSetFocus(THandle /*hLostFocus*/)
{
  if (NativeUse & nuUsing) {
    DefaultProcessing();
    return;
  }
  TClientDC dc(*this);
  THatch8x8Brush br(THatch8x8Brush::Hatch11F1,
                    TColor::White, TColor::Sys3dFace); 

  dc.FrameRect(GetClientRect(), br);
}

//
//
//
void
TSlider::EvKillFocus(THandle hGetFocus)
{
  if (NativeUse & nuUsing) {
    DefaultProcessing();
    return;
  }
  TClientDC dc(*this);
  dc.FrameRect(GetClientRect(), TBrush(TColor::Sys3dFace));

  TScrollBar::EvKillFocus(hGetFocus); // Need to let TWindow do focus save
}

#endif  // !defined(OWL_NATIVECTRL_ALWAYS)

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_ABSTRACT_STREAMABLE1(TSlider, TScrollBar);

#if !defined(BI_NO_OBJ_STREAMING)

//
//
//
void*
TSlider::Streamer::Read(ipstream& is, uint32 version) const
{
  TSlider* o = GetObject();
  ReadBaseObject((TScrollBar*)o, is);
  is >> o->Min
     >> o->Max
     >> o->Pos
     >> o->ThumbResId
     >> o->ThumbRect;
  if (version == 1) {
    TRect tmpRect;
    is >> tmpRect;     // dummy CaretRect for compatibilty with stream v1
  }
  is >> o->TicGap
     >> o->Snap;

  // In stream version 2 and above, a tic array with count is written, as well
  // as a selection range
  //
  if (version >= 2) {
    is >> o->TicCount;
    o->Tics = o->TicCount ? new int[o->TicCount] : 0;
    for (int i = 0; i < o->TicCount; i++)
      is >> o->Tics[i];

    is >> o->SelStart
       >> o->SelEnd;
  }

  o->SetRange(o->Min, o->Max);  // let it calculate Range
  return o;
}

//
//
//
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
     << o->TicGap
     << o->Snap
     << o->TicCount;

  // In stream version 2 and above, a tic array with count is written, as well
  // as a selection range
  //
  os << o->TicCount;
  for (int i = 0; i < o->TicCount; i++)
    os << o->Tics[i];
  int d1,d2;
  o->GetSel(d1,d2);     // Force retrieval of current selection before writing
  os << o->SelStart
     << o->SelEnd;
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
