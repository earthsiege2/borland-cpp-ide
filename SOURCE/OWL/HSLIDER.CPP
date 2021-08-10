//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   source\owl\hslider.cpp
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\slider.h>
#include <owl\dc.h>

#if !defined(SECTION) || SECTION == 1

//
// Constructor for a THSlider object
//
THSlider::THSlider(TWindow*        parent,
                   int             id,
                   int x, int y, int w, int h,
                   TResId          thumbResId,
                   TModule*        module)
  : TSlider(parent, id, x, y, w, h, thumbResId, module)
{
  ThumbRect = TRect(0, 0, 9, 20);
  CaretRect = TRect(3, 3, 3+3, 3+13);

  // get slot size from Attr.H set by TScrollBar ?
  if (!h)
    h = 32;

  SlotThick = 17;
}

//
// Calculate and return position given a thumb upper left point 
// and vice versa.
//
int
THSlider::PointToPos(TPoint& point)
{
  return int(((long)point.x*Range)/(Attr.W-ThumbRect.Width()) + Min);
}

TPoint
THSlider::PosToPoint(int pos)
{
  return TPoint(int(((long)(pos-Min)*(Attr.W-ThumbRect.Width()))/Range),
                ThumbRect.top);
}

//
// Notify parent of a scroll event by sending a WM_HSCROLL message
//
void
THSlider::NotifyParent(int scrollCode, int pos)
{
  #if defined(__WIN32__)
    Parent->HandleMessage(WM_HSCROLL, MAKEWPARAM(scrollCode, pos), LPARAM(HWindow));
  #else
    Parent->HandleMessage(WM_HSCROLL, scrollCode, MAKELPARAM(pos, HWindow));
  #endif
}

//
// Determines if a point is within the thumb, or other hot areas of the 
// slider. Uses region if available, else uses thumb bounding rect.
// Returns -1 if no hit.
//
int
THSlider::HitTest(TPoint& point)
{
  if (ThumbRgn ? ThumbRgn->Contains(point) : ThumbRect.Contains(point))
    return SB_THUMBTRACK;
  
  if (point.y > ThumbRect.bottom)
    return SB_THUMBPOSITION;
      
  else if (point.x < ThumbRect.left)
    return SB_PAGEUP;

  else if (point.x >= ThumbRect.right)
    return SB_PAGEDOWN;

  return -1;
}

//
// Paint the ruler. The ruler doesn't overlap with the thumb or slot.
// SysColors for text fg or bg are never dithered & can use TextRect. 
//
void
THSlider::PaintRuler(TDC& dc)
{
  //  Clear ruler area to bk color
  //
  dc.TextRect(0, ThumbRect.Height(), Attr.W, Attr.H, BkColor);

  //  Draw left tic & internal tics if any, then right tic
  //
  TBrush highlightbrush(::GetSysColor(COLOR_BTNHIGHLIGHT));
  int    margin = ThumbRect.Width()/2;
  int    rulerY = ThumbRect.Height()+1;
  int    x;

  dc.SelectObject(highlightbrush);
  dc.SetBkColor(::GetSysColor(COLOR_BTNTEXT));

  for (int i = Min; i < Max; i += TicGap) {
    x = PosToPoint(i).x + margin;
    dc.TextRect(x, rulerY, x+1, rulerY+5);
    dc.PatBlt(x+1, rulerY, 1, 5);
    if (!TicGap)
      break;
  }
  x = Attr.W-margin-1;
  dc.TextRect(x, rulerY, x+1, rulerY+5);
  dc.PatBlt(x+1, rulerY, 1, 6);

  //  Draw ruler bottom
  //
  dc.TextRect(margin, rulerY+5, Attr.W-margin, rulerY+6);
  dc.PatBlt(margin, rulerY+6, Attr.W-2*margin+1, 1);

  dc.RestoreBrush();
}

//
// Paint the slot that the thumb slides over.
//
void
THSlider::PaintSlot(TDC& dc)
{
  int    hmargin = ThumbRect.Width()/2;                   // left & right margins
  int    vmargin = (ThumbRect.Height()-SlotThick+1)/2+1;  // top & bottom

  //
  // draw margins in background color
  //
  dc.SetBkColor(BkColor);
  dc.TextRect(0, 0, Attr.W, vmargin);                               // above
  dc.TextRect(0, vmargin, hmargin, vmargin+SlotThick);              // left
  dc.TextRect(Attr.W-hmargin, vmargin, Attr.W, vmargin+SlotThick);  // right
  dc.TextRect(0, SlotThick, Attr.W, SlotThick+vmargin);             // bottom

  //
  // Draw slot frame, shadow, fill & highlight below
  //
  dc.TextRect(hmargin, vmargin, Attr.W-hmargin, SlotThick-1,
              ::GetSysColor(COLOR_BTNTEXT));
  dc.FillRect(hmargin+1, vmargin+1, Attr.W-hmargin-1, vmargin+2,
              TBrush(::GetSysColor(COLOR_BTNSHADOW)));
  dc.TextRect(hmargin+1, vmargin+2, Attr.W-hmargin-1, SlotThick-2,
              ::GetSysColor(COLOR_BTNFACE));
  dc.FillRect(hmargin, SlotThick-1, Attr.W-hmargin, SlotThick,
              TBrush(::GetSysColor(COLOR_BTNHIGHLIGHT)));
  dc.RestoreBrush();
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(THSlider, TSlider);

void*
THSlider::Streamer::Read(ipstream& is, uint32 /* version */) const
{
  ReadBaseObject((TSlider*)GetObject(), is);
  return GetObject();
}

void
THSlider::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TSlider*)GetObject(), os);
}

#endif
