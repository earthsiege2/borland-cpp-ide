//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\gadget.cpp
//   Implementation of class TGadget and class TSeperatorGadget.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\gadget.h>
#include <owl\gadgetwi.h>

TSeparatorGadget::TSeparatorGadget(int size)
{
  ShrinkWrapWidth = ShrinkWrapHeight = FALSE;
  SetEnabled(FALSE);
  Bounds.right = size * GetSystemMetrics(SM_CXBORDER);
  Bounds.bottom = size * GetSystemMetrics(SM_CYBORDER);
}

TGadget::TGadget(int id, TBorderStyle borderStyle)
{
  Window = 0;
  Bounds = TRect(0, 0, 0, 0);
  Enabled = TRUE;
  TrackMouse = FALSE;
  Clip = FALSE;
  WideAsPossible = FALSE;
  ShrinkWrapWidth = ShrinkWrapHeight = TRUE;
  Next = 0;
  Id = id;

  SetBorderStyle(borderStyle);
}

TGadget::~TGadget()
{
  //
  //    If we're in a window, remove ourselves.
  //
  if (Window)
    Window->Remove(*this);
}

void
TGadget::CommandEnable()
{
}

void
TGadget::SysColorChange()
{
}

void
TGadget::SetShrinkWrap(BOOL shrinkWrapWidth, BOOL shrinkWrapHeight)
{
  ShrinkWrapWidth = shrinkWrapWidth;
  ShrinkWrapHeight = shrinkWrapHeight;
}

void
TGadget::SetSize(TSize& size)
{
  Bounds.right = Bounds.left + size.cx;
  Bounds.bottom = Bounds.top + size.cy;

  if (Window)
    Window->GadgetChangedSize(*this);
}

void
TGadget::SetEnabled(BOOL enabled)
{
  if (Enabled != enabled) {
    Enabled = enabled;
    Invalidate(FALSE);
  }
}

void
TGadget::SetBounds(TRect& rect)
{
  Bounds = rect;
}

void
TGadget::SetBorders(TBorders& borders)
{
  Borders = borders;

  if (Window)
    Window->GadgetChangedSize(*this);
}

void
TGadget::SetMargins(TMargins& margins)
{
  Margins = margins;

  if (Window)
    Window->GadgetChangedSize(*this);
}

void
TGadget::SetBorderStyle(TBorderStyle borderStyle)
{
  int  edgeThickness;

  BorderStyle = borderStyle;

  switch (BorderStyle) {
    case None:
      edgeThickness = 0;
      break;

    case Plain:
    case Raised:
    case Recessed:
      edgeThickness = 1;
      break;

    case Embossed:
      edgeThickness = 3;
      break;
  }

  Borders.Left = Borders.Top = Borders.Right = Borders.Bottom = edgeThickness;

  if (Window)
    Window->GadgetChangedSize(*this);
}

BOOL
TGadget::PtIn(TPoint& point)
{
  return point.x >= 0 && point.y >= 0 &&
         point.x < Bounds.Width() && point.y < Bounds.Height();
}

void
TGadget::Inserted()
{
}

void
TGadget::Removed()
{
}

void
TGadget::InvalidateRect(const TRect& rect, BOOL erase)
{
  if (Window && Window->HWindow) {
    TRect  updateRect(rect.left + Bounds.left, rect.top + Bounds.top,
                      rect.right + Bounds.left, rect.bottom + Bounds.top);

    Window->InvalidateRect(updateRect, erase);
  }
}

void
TGadget::Invalidate(BOOL erase)
{
  InvalidateRect(TRect(0, 0, Bounds.Width(), Bounds.Height()), erase);
}

//
// cause owning window to paint now if possible
//
void
TGadget::Update()
{
  if (Window && Window->HWindow)
    Window->UpdateWindow();
}

void
TGadget::PaintBorder(TDC& dc)
{
  if (BorderStyle != None) {
    int  xBorder = GetSystemMetrics(SM_CXBORDER);
    int  yBorder = GetSystemMetrics(SM_CYBORDER);

    if (BorderStyle == Plain)
      dc.OWLFastWindowFrame(TBrush(GetSysColor(COLOR_WINDOWFRAME)),
                            TRect(0, 0, Bounds.Width(), Bounds.Height()),
                            xBorder, yBorder);

    else {
      TBrush  highlight(GetSysColor(COLOR_BTNHIGHLIGHT));
      TBrush  shadow(GetSysColor(COLOR_BTNSHADOW));

      switch (BorderStyle) {
        case Raised:
          dc.SelectObject(highlight);
          dc.PatBlt(0, 0, Bounds.Width(), yBorder, PATCOPY);
          dc.PatBlt(0, 0, xBorder, Bounds.Height(), PATCOPY);
          dc.SelectObject(shadow);
          dc.PatBlt(0, Bounds.Height() - 1, Bounds.Width(), yBorder, PATCOPY);
          dc.PatBlt(Bounds.Width() - 1, 0, xBorder, Bounds.Height(), PATCOPY);
          break;

        case Recessed:
          dc.SelectObject(shadow);
          dc.PatBlt(0, 0, Bounds.Width(), yBorder, PATCOPY);
          dc.PatBlt(0, 0, xBorder, Bounds.Height(), PATCOPY);
          dc.SelectObject(highlight);
          dc.PatBlt(0, Bounds.Height() - 1, Bounds.Width(), yBorder, PATCOPY);
          dc.PatBlt(Bounds.Width() - 1, 0, xBorder, Bounds.Height(), PATCOPY);
          break;

        case Embossed:
          dc.SelectObject(highlight);
          dc.PatBlt(0, 0, Bounds.Width() - 1, 1, PATCOPY);
          dc.PatBlt(0, 0, 1, Bounds.Height() - 2, PATCOPY);
          dc.PatBlt(2, Bounds.Height() - 3, Bounds.Width() - 4, 1, PATCOPY);
          dc.PatBlt(Bounds.Width() - 3, 3, 1, Bounds.Height() - 5, PATCOPY);
          dc.SelectObject(shadow);
          dc.PatBlt(2, 2, Bounds.Width() - 5, 1, PATCOPY);
          dc.PatBlt(2, 2, 1, Bounds.Height() - 5, PATCOPY);
          dc.PatBlt(1, Bounds.Height() - 1, Bounds.Width() - 2, 1, PATCOPY);
          dc.PatBlt(Bounds.Width() - 1, 1, 1, Bounds.Height() - 1, PATCOPY);
          break;
      }
    }
    dc.RestoreBrush();
  }
}

void
TGadget::Paint(TDC& dc)
{
  PaintBorder(dc);
}

//
//
//
void
TGadget::GetDesiredSize(TSize& size)
{
  int  left, right, top, bottom;

  GetOuterSizes(left, right, top, bottom);

  size.cx = ShrinkWrapWidth ? left+right : Bounds.Width();
  size.cy = ShrinkWrapHeight ? top+bottom : Bounds.Height();
}

//
// Gets the four total outer sizes which consists of the margins plus the 
// borders.
//
void
TGadget::GetOuterSizes(int& left, int& right, int& top, int& bottom)
{
  if (Window) {
    int  cxBorder = GetSystemMetrics(SM_CXBORDER);
    int  cyBorder = GetSystemMetrics(SM_CYBORDER);

    Window->GetMargins(Margins, left, right, top, bottom);
    left += Borders.Left * cxBorder;
    right += Borders.Right * cxBorder;
    top += Borders.Top * cyBorder;
    bottom += Borders.Bottom * cyBorder;
  }
}

//
// Gets the inner working rectangle. Which is, by default, the Bounds minus
// each of the outer sizes
//
void
TGadget::GetInnerRect(TRect& innerRect)
{
  int  left, right, top, bottom;
  GetOuterSizes(left, right, top, bottom);

  innerRect.left = left;
  innerRect.right = Bounds.Width() - right;
  innerRect.top = top;
  innerRect.bottom = Bounds.Height() - bottom;
}

//
// Mouse response functions
//

//
// mouse is moving over this gadget. called by gadget window only if this
// gadget has captured the mouse
//
void
TGadget::MouseMove(UINT /*modKeys*/, TPoint&)
{
}

//
// mouse is entering this gadget. called by gadget window if no other gadget
// has capture
//
void
TGadget::MouseEnter(UINT /*modKeys*/, TPoint&)
{
}

//
// mouse is leaving this gadget. called by gadget window if no other gadget
// has capture
//
void
TGadget::MouseLeave(UINT /*modKeys*/, TPoint&)
{
}

void
TGadget::LButtonDown(UINT /*modKeys*/, TPoint&)
{
  if (TrackMouse)
    Window->GadgetSetCapture(*this);
}

void
TGadget::LButtonUp(UINT /*modKeys*/, TPoint&)
{
  if (TrackMouse)
    Window->GadgetReleaseCapture(*this);
}
