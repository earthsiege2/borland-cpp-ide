//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TVSlider, vertical slider UI widget
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/slider.h>
#include <owl/dc.h>

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
  ThumbRect = TRect(0, 0, 20, 9);
  ThumbRect += TPoint((Attr.W-ThumbRect.Width())/2, 0);  // move past tics
  CaretRect = TRect(3, 3, 3+14, 3+3);

  // get slot size from Attr.W set by TScrollBar ?
  if (!w)
    Attr.W = 32;
  SlotThick = 14;
}

//
// Calculate and return position given a thumb upper left point
// and vice versa.
//
int
TVSlider::PointToPos(TPoint& point)
{
  return int(((long)point.y*(long)Range)/(Attr.H-ThumbRect.Height()) + Min);
}

TPoint
TVSlider::PosToPoint(int pos)
{
  return TPoint(ThumbRect.left,
                int(((long)(pos-Min)*(Attr.H-ThumbRect.Height()))/Range));
}

//
// Notify parent of a scroll event by sending a WM_VSCROLL message
//
void
TVSlider::NotifyParent(int scrollCode, int pos)
{
  #if defined(BI_PLAT_WIN32)
    Parent->HandleMessage(WM_VSCROLL, MAKEWPARAM(scrollCode, pos), LPARAM(HWindow));
  #else
    Parent->HandleMessage(WM_VSCROLL, scrollCode, MAKELPARAM(pos, HWindow));
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

  //
  //  Clear ruler areas to bk color
  //
  dc.SetBkColor(BkColor);
  dc.TextRect(0, 0, ticW+1, Attr.H);
  dc.TextRect(Attr.W-ticW-1, 0, Attr.W, Attr.H);

  //
  //  Draw bottom tic & internal tics if any, then top tic
  //
  TBrush highlightbrush(::GetSysColor(COLOR_BTNHIGHLIGHT));
  int    margin = ThumbRect.Height()/2;
  int    y;

  dc.SelectObject(highlightbrush);
  dc.SetBkColor(::GetSysColor(COLOR_BTNTEXT));

  for (int i = Min; i < Max; i += TicGap) {
    y = PosToPoint(i).y + margin;
    dc.TextRect(0, y, ticW, y+1);
    dc.PatBlt(1, y+1, ticW, 1);
    dc.TextRect(Attr.W-ticW-1, y, Attr.W-1, y+1);
    dc.PatBlt(Attr.W-ticW, y+1, ticW, 1);
    if (!TicGap)
      break;
  }
  y = Attr.H-margin-1;
  dc.TextRect(0, y, ticW, y+1);
  dc.PatBlt(1, y+1, ticW, 1);
  dc.TextRect(Attr.W-ticW-1, y, Attr.W-1, y+1);
  dc.PatBlt(Attr.W-ticW, y+1, ticW, 1);

  dc.RestoreBrush();
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

  //
  // draw margins in background color
  //
  dc.SetBkColor(BkColor);
  dc.TextRect(ticW+1, 0, ticW+1+ThumbRect.Width(), vmargin);              // above
  dc.TextRect(ticW+1, vmargin, ticW+1+hmargin, Attr.H);                   // left
  dc.TextRect(Attr.W-ticW-1-hmargin, vmargin, Attr.W-ticW-1, Attr.H);     // right
  dc.TextRect(ticW+1, Attr.H-vmargin, ticW+1+ThumbRect.Width(), Attr.H);  // bottom

  //
  // Draw slot frame, shadow, fill & highlight to the right
  //
  dc.FrameRect(ticW+1+hmargin, vmargin, ticW+1+hmargin+SlotThick-1,
               Attr.H-vmargin, TBrush(::GetSysColor(COLOR_BTNTEXT)));
  dc.FillRect(ticW+1+hmargin+1, vmargin+1, ticW+1+hmargin+2, Attr.H-vmargin-1,
              TBrush(::GetSysColor(COLOR_BTNSHADOW)));
  dc.TextRect(ticW+1+hmargin+2, vmargin+1,
              ticW+1+hmargin+SlotThick-2, Attr.H-vmargin-1,
              ::GetSysColor(COLOR_BTNFACE));
  dc.FillRect(ticW+1+hmargin+SlotThick-1, vmargin,
              ticW+1+hmargin+SlotThick, Attr.H-vmargin,
              TBrush(::GetSysColor(COLOR_BTNHIGHLIGHT)));
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TVSlider, TSlider);

void*
TVSlider::Streamer::Read(ipstream& is, uint32 /* version */) const
{
  ReadBaseObject((TSlider*)GetObject(), is);
  return GetObject();
}

void
TVSlider::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TSlider*)GetObject(), os);
}

#endif
