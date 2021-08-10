//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TControlGadget.
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/controlg.h>
#include <owl/gadgetwi.h>

TControlGadget::TControlGadget(TWindow& control, TBorderStyle border)
:
  TGadget(control.Attr.Id, border)
{
  Control = &control;
}

TControlGadget::~TControlGadget()
{
  Control->Destroy(0);
  delete Control;
}

void
TControlGadget::SetBounds(TRect& bounds)
{
  TGadget::SetBounds(bounds);
  Control->Attr.X = Bounds.left;
  Control->Attr.Y = Bounds.top;
  Control->Attr.W = Bounds.Width();
  Control->Attr.H = Bounds.Height();
  if (Control->HWindow)
    Control->MoveWindow(Bounds);  
}

void
TControlGadget::GetDesiredSize(TSize& size)
{
  TGadget::GetDesiredSize(size);

  if (ShrinkWrapWidth)
    size.cx += Control->Attr.W;
  if (ShrinkWrapHeight)
    size.cy += Control->Attr.H;
}

void
TControlGadget::Inserted()
{
  Control->SetParent(Window);
  if (Window->HWindow && !Control->HWindow) {
    Control->Create();
    Control->ShowWindow(SW_NORMAL);
  }
}

void
TControlGadget::Removed()
{
  Control->SetParent(0);
}

void
TControlGadget::InvalidateRect(const TRect& rect, bool erase)
{
  if (Control->HWindow)
    Control->InvalidateRect(rect, erase);
}

void
TControlGadget::Invalidate(bool erase)
{
  InvalidateRect(TRect(0, 0, Bounds.Width(), Bounds.Height()), erase);
}

//
// cause owning window to paint now if possible
//
void
TControlGadget::Update()
{
  if (Control->HWindow)
    Control->UpdateWindow();
}
