//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Implementation of THSlider, a horizontal slider UI widget
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
// Constructor for a THSlider object
//
THSlider::THSlider(TWindow*        parent,
                   int             id,
                   int x, int y, int w, int h,
                   TResId          thumbResId,
                   TModule*        module)
:
  TSlider(parent, id, x, y, w, h, thumbResId, module)
{
  if (!h)
    Attr.H = 32;
  Attr.Style |= TBS_HORZ;  // In case it is Native, else we dont care
}

//
// Constructor for a slider object created from resource
//
THSlider::THSlider(TWindow*        parent,
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
THSlider::PointToPos(const TPoint& point)
{
  int pixelRange = Attr.W - ThumbRect.Width() - 2;  // 2 is room for focus rect
  long scaledX = long(point.x-1) * long(Range);
  return int(scaledX/pixelRange + Min);
}

//
//
//
TPoint
THSlider::PosToPoint(int pos)
{
  int pixelRange = Attr.W - ThumbRect.Width() - 2;  // 2 is room for focus rect
  long relPos = pos - Min;
  int  top = 1;
  return TPoint(int((relPos*pixelRange)/Range)+1, top);
}

//
// Notify parent of a scroll event by sending a WM_HSCROLL message
//
void
THSlider::NotifyParent(int scrollCode, int pos)
{
#if defined(BI_PLAT_WIN32)
  Parent->HandleMessage(WM_HSCROLL, MkParam1(scrollCode, pos), TParam2(GetHandle()));
#else
  Parent->HandleMessage(WM_HSCROLL, scrollCode, MkParam2(pos, uint16(GetHandle())));
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
  const int ticH = 3;

  // Clear ruler area to bk color
  //
  dc.TextRect(0, ThumbRect.Height(), Attr.W, Attr.H, BkColor);

  // Draw left tic & internal tics if any, then right tic
  //
  int  margin = ThumbRect.Width()/2 + 1;
  int  rulerY = ThumbRect.Height() + 2;
  int  x;
  int  h = ticH + 2;  // First & last are bigger

  dc.SetBkColor(TColor::SysBtnText);

  if (Tics && TicCount) {
    for (int i = 0; i < TicCount; i++) {
      x = PosToPoint(Tics[i]).x + margin;
      dc.TextRect(x, rulerY, x+1, rulerY+h);
      h = ticH;  // Middle ones are smaller
    }
  }
  else {
    for (int i = Min; i < Max; i += TicGap) {
      x = PosToPoint(i).x + margin;
      dc.TextRect(x, rulerY, x+1, rulerY+h);
      if (!TicGap)
        break;
      h = ticH;  // Middle ones are smaller
    }
  }
  x = Attr.W-margin-1;
  dc.TextRect(x, rulerY, x+1, rulerY + ticH + 2);
}

//
// Paint the slot that the thumb slides over.
//
void
THSlider::PaintSlot(TDC& dc)
{
  int    hmargin = ThumbRect.Width()/2 + 1;             // left & right margins
  int    vmargin = (ThumbRect.Height()-SlotThick+1)/2+1;// top & bottom

  int    focusRectW = 1;  
  int    focusRectH = 1;

  // Draw margins around slot in background color
  //
  dc.SetBkColor(BkColor);
  // Top
  dc.TextRect(focusRectW, focusRectH,
              Attr.W-focusRectW, vmargin-focusRectH+SlotThick);
  // Left
  dc.TextRect(focusRectW, vmargin+focusRectH,
              hmargin-focusRectW, vmargin+SlotThick-focusRectH);
  // Right
  dc.TextRect(Attr.W-hmargin+focusRectW, vmargin+focusRectH,
              Attr.W-focusRectW, vmargin+SlotThick-focusRectH);
  // Bottom
  dc.TextRect(focusRectW, SlotThick+vmargin-focusRectH,
              Attr.W-focusRectW, SlotThick+vmargin+vmargin-focusRectH);

  // Draw slot frame, shadow, fill & highlight below
  //
  TRect slotR(hmargin, vmargin, Attr.W-hmargin, vmargin + SlotThick);
  TUIBorder b(slotR, TUIBorder::WndRecessed);
  b.Paint(dc);
}

#endif  // !defined(OWL_NATIVECTRL_ALWAYS)

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(THSlider, TSlider);

#if !defined(BI_NO_OBJ_STREAMING)

//
//
//
void*
THSlider::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TSlider*)GetObject(), is);
  return GetObject();
}

//
//
//
void
THSlider::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TSlider*)GetObject(), os);
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
