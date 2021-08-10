//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\controlb.cpp
//   Implementation of class TControlBar.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\controlb.h>

IMPLEMENT_CASTABLE(TControlBar);

TControlBar::TControlBar(TWindow*        parent,
                         TTileDirection  direction,
                         TFont*          font,
                         TModule*        module)
  : TGadgetWindow(parent, direction, font, module)
{
  Margins.Units = TMargins::BorderUnits;

  if (Direction == Horizontal) {
    Margins.Left = Margins.Right = 6;
    Margins.Top = Margins.Bottom = 2;

  } else {
    Margins.Left = Margins.Right = 2;
    Margins.Top = Margins.Bottom = 6;
  }
}

BOOL
TControlBar::PreProcessMsg(MSG&)
{
  return FALSE;
}

void
TControlBar::PositionGadget(TGadget* previous, TGadget* next, TPoint& origin)
{
  //
  // overlap the button borders
  //
  if (previous->GetBorderStyle() == TGadget::Plain &&
      next->GetBorderStyle() == TGadget::Plain)
    if (Direction == Horizontal)
      origin.x -= GetSystemMetrics(SM_CXBORDER);

    else
      origin.y -= GetSystemMetrics(SM_CYBORDER);
}
