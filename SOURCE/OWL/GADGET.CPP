//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TGadget and class TSeperatorGadget.
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/gadget.h>
#include <owl/gadgetwi.h>

TSeparatorGadget::TSeparatorGadget(int size)
{
  ShrinkWrapWidth = ShrinkWrapHeight = false;
  SetEnabled(false);
  Bounds.right = size * GetSystemMetrics(SM_CXBORDER);
  Bounds.bottom = size * GetSystemMetrics(SM_CYBORDER);
}

void
TSeparatorGadget::Inserted()
{
  BorderStyle = None;  // prohibit our style from being changed
}

TGadget::TGadget(int id, TBorderStyle borderStyle)
{
  Window = 0;
  Bounds = TRect(0, 0, 0, 0);
  Enabled = true;
  TrackMouse = false;
  Clip = false;
  WideAsPossible = false;
  ShrinkWrapWidth = ShrinkWrapHeight = true;
  Next = 0;
  Id = id;

  SetBorderStyle(borderStyle);
}

TGadget::~TGadget()
{
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
TGadget::SetShrinkWrap(bool shrinkWrapWidth, bool shrinkWrapHeight)
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
TGadget::SetEnabled(bool enabled)
{
  if (Enabled != enabled) {
    Enabled = enabled;
    Invalidate(false);
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
    default:
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

bool
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
TGadget::InvalidateRect(const TRect& rect, bool erase)
{
  if (Window && Window->HWindow) {
    TRect  updateRect(rect.left + Bounds.left, rect.top + Bounds.top,
                      rect.right + Bounds.left, rect.bottom + Bounds.top);

    Window->InvalidateRect(updateRect, erase);
  }
}

void
TGadget::Invalidate(bool erase)
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
    int  xB = GetSystemMetrics(SM_CXBORDER);
    int  yB = GetSystemMetrics(SM_CYBORDER);

    if (BorderStyle == Plain)
      dc.OWLFastWindowFrame(TBrush(GetSysColor(COLOR_WINDOWFRAME)),
                            TRect(0, 0, Bounds.Width(), Bounds.Height()),
                            xB, yB);

    else {
      TBrush  highlight(GetSysColor(COLOR_BTNHIGHLIGHT));
      TBrush  shadow(GetSysColor(COLOR_BTNSHADOW));

      switch (BorderStyle) {
        case Raised:
          dc.SelectObject(highlight);
          dc.PatBlt(0, 0, Bounds.Width()-xB, yB, PATCOPY);
          dc.PatBlt(0, 0, xB, Bounds.Height()-yB, PATCOPY);
          dc.SelectObject(shadow);
          dc.PatBlt(1, Bounds.Height()-yB, Bounds.Width()-xB, yB, PATCOPY);
          dc.PatBlt(Bounds.Width()-xB, yB, xB, Bounds.Height()-yB, PATCOPY);
          break;

        case Recessed:
          dc.SelectObject(shadow);
          dc.PatBlt(0, 0, Bounds.Width()-xB, yB, PATCOPY);
          dc.PatBlt(0, 0, xB, Bounds.Height()-yB, PATCOPY);
          dc.SelectObject(highlight);
          dc.PatBlt(xB, Bounds.Height()-yB, Bounds.Width()-xB, yB, PATCOPY);
          dc.PatBlt(Bounds.Width()-xB, yB, xB, Bounds.Height()-yB, PATCOPY);
          break;

        case Embossed:
          dc.SelectObject(highlight);
          dc.PatBlt(0, 0, Bounds.Width()-xB, yB, PATCOPY);
          dc.PatBlt(0, 0, xB, Bounds.Height()-yB, PATCOPY);
          dc.PatBlt(3*xB, Bounds.Height()-3*yB, Bounds.Width()-5*xB, yB, PATCOPY);
          dc.PatBlt(Bounds.Width()-3*xB, 3*yB, xB, Bounds.Height()-5*xB, PATCOPY);
          dc.SelectObject(shadow);
          dc.PatBlt(2*xB, 2*yB, Bounds.Width()-5*xB, yB, PATCOPY);
          dc.PatBlt(2*xB, 2*yB, xB, Bounds.Height()-5*yB, PATCOPY);
          dc.PatBlt(xB, Bounds.Height()-yB, Bounds.Width()-2*xB, yB, PATCOPY);
          dc.PatBlt(Bounds.Width()-xB, yB, xB, Bounds.Height()-yB, PATCOPY);
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
    int  xBorder = GetSystemMetrics(SM_CXBORDER);
    int  yBorder = GetSystemMetrics(SM_CYBORDER);

    Window->GetMargins(Margins, left, right, top, bottom);
    left += Borders.Left * xBorder;
    right += Borders.Right * xBorder;
    top += Borders.Top * yBorder;
    bottom += Borders.Bottom * yBorder;
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
TGadget::MouseMove(uint /*modKeys*/, TPoint&)
{
}

//
// mouse is entering this gadget. called by gadget window if no other gadget
// has capture
//
void
TGadget::MouseEnter(uint /*modKeys*/, TPoint&)
{
}

//
// mouse is leaving this gadget. called by gadget window if no other gadget
// has capture
//
void
TGadget::MouseLeave(uint /*modKeys*/, TPoint&)
{
}

void
TGadget::LButtonDown(uint /*modKeys*/, TPoint&)
{
  if (TrackMouse)
    Window->GadgetSetCapture(*this);
}

void
TGadget::LButtonUp(uint /*modKeys*/, TPoint&)
{
  if (TrackMouse)
    Window->GadgetReleaseCapture(*this);
}
