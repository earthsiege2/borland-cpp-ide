//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Implementation of TVSlider, vertical slider UI widget
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
#if !defined(OWL_UIHELPER_H)
# include <owl/uihelper.h>
#endif

OWL_DIAGINFO;

#if !defined(SECTION) || SECTION == 1

//
// Constructor for a TVSlider object
//
TVSlider::TVSlider(TWindow*        parent,
                   int             id,
                   int x, int y, int w, int h,
                   TResId          thumbResId,
                   TModule*        module)
:
  TSlider(parent, id, x, y, w, h, thumbResId, module)
{
  if (!w)
    Attr.W = 32;
  Attr.Style |= TBS_VERT;  // In case it is Native, else we dont care
}

//
// Constructor for a slider object created from resource
//
TVSlider::TVSlider(TWindow*        parent,
                   int             resId,
                   TResId          thumbResId,
                   TModule*        module)
:
  TSlider(parent, resId, thumbResId, module)
{
}

//----------------------------------------------------------------------------
// Protected implementation

// Leave the whole implemenation out if built with OWL_NATIVECTRL_ALWAYS
//
#if !defined(OWL_NATIVECTRL_ALWAYS)

//
// Calculate and return position given a thumb upper left point and vice versa.
//
int
TVSlider::PointToPos(const TPoint& point)
{
  int pixelRange = Attr.H - ThumbRect.Height() - 2; // 2 is room for focus rect
  long scaledY = long(point.y-1) * long(Range);
  return int(scaledY/pixelRange + Min);
}

//
//
//
TPoint
TVSlider::PosToPoint(int pos)
{
  int pixelRange = Attr.H - ThumbRect.Height() - 2; // 2 is room for focus rect
  long relPos = pos - Min;
  int left = (Attr.W-ThumbRect.Width()-2)/2+1;
  return TPoint(left, int((relPos*pixelRange)/Range)+1);
}

//
// Notify parent of a scroll event by sending a WM_VSCROLL message
//
void
TVSlider::NotifyParent(int scrollCode, int pos)
{
#if defined(BI_PLAT_WIN32)
  Parent->HandleMessage(WM_VSCROLL, MkParam1(scrollCode, pos), TParam2(GetHandle()));
#else
  Parent->HandleMessage(WM_VSCROLL, scrollCode, MkParam2(pos, GetHandle()));
#endif
}

//
// Determines if a point is within the thumb, or other hot areas of the
// slider. Uses region if available, else uses thumb bounding rect.
// Returns -1 if no hit.
//
int
TVSlider::HitTest(TPoint& point)
{
  if (ThumbRgn ? ThumbRgn->Contains(point) : ThumbRect.Contains(point))
    return SB_THUMBTRACK;

  if (point.x > ThumbRect.right || point.x < ThumbRect.left)
    return SB_THUMBPOSITION;

  else if (point.y < ThumbRect.top)
    return SB_PAGEUP;

  else if (point.y >= ThumbRect.bottom)
    return SB_PAGEDOWN;

  return -1;
}

//
// Paint the ruler. The ruler doesn't overlap with the thumb or slot.
// SysColors for text fg or bg are never dithered & can use TextRect.
//
void
TVSlider::PaintRuler(TDC& dc)
{
  int    ticW = (Attr.W-ThumbRect.Width()-2)/2;

  // Clear ruler areas to bk color
  //
  dc.SetBkColor(BkColor);
  dc.TextRect(0, 0, ticW+1, Attr.H);
  dc.TextRect(Attr.W-ticW-1, 0, Attr.W, Attr.H);

  // Draw bottom tic & internal tics if any, then top tic
  //
  int    margin = ThumbRect.Height()/2;
  int    y;

  dc.SetBkColor(TColor::SysBtnText);

  if (Tics && TicCount) {
    for (int i = 0; i < TicCount; i++) {
      y = PosToPoint(Tics[i]).y + margin;
      dc.TextRect(0, y, ticW, y+1);
      dc.TextRect(Attr.W-ticW-1, y, Attr.W-1, y+1);
    }
  }
  else {
    for (int i = Min; i < Max; i += TicGap) {
      y = PosToPoint(i).y + margin;
      dc.TextRect(0, y, ticW, y+1);
      dc.TextRect(Attr.W-ticW-1, y, Attr.W-1, y+1);
      if (!TicGap)
        break;
    }
  }
  y = Attr.H-margin-1;
  dc.TextRect(0, y, ticW, y+1);
  dc.TextRect(Attr.W-ticW-1, y, Attr.W-1, y+1);
}

//
// Paint the slot that the thumb slides over.
//
void
TVSlider::PaintSlot(TDC& dc)
{
  int    ticW = (Attr.W-ThumbRect.Width()-2)/2;
  int    vmargin = ThumbRect.Height()/2;             // top & bottom margins
  int    hmargin = (ThumbRect.Width()-SlotThick)/2;  // left & right margins

  // Draw margins around slot in background color
  //
  dc.SetBkColor(BkColor);
  // Above
  dc.TextRect(ticW+1, 0, ticW+1+ThumbRect.Width(), vmargin);
  // Left
  dc.TextRect(ticW+1, vmargin, ticW+1+hmargin, Attr.H);
  // Right
  dc.TextRect(Attr.W-ticW-1-hmargin, vmargin, Attr.W-ticW-1, Attr.H);
  // Bottom
  dc.TextRect(ticW+1, Attr.H-vmargin, ticW+1+ThumbRect.Width(), Attr.H);

  // Draw slot frame, shadow, fill & highlight to the right
  //
  TRect slotR(ticW+1+hmargin, vmargin, ticW+1+hmargin+SlotThick, Attr.H-vmargin);
  TUIBorder b(slotR, TUIBorder::WndRecessed);
  b.Paint(dc);
}

#endif  // !defined(OWL_NATIVECTRL_ALWAYS)

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TVSlider, TSlider);

#if !defined(BI_NO_OBJ_STREAMING)

//
//
//
void*
TVSlider::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TSlider*)GetObject(), is);
  return GetObject();
}

//
//
//
void
TVSlider::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TSlider*)GetObject(), os);
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
