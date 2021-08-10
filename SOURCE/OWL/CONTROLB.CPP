//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Implementation of class TControlBar.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_CONTROLB_H)
# include <owl/controlb.h>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif

DIAG_DECLARE_GROUP(OwlWin);

IMPLEMENT_CASTABLE(TControlBar);

//
//
//
TControlBar::TControlBar(TWindow*        parent,
                         TTileDirection  direction,
                         TFont*          font,
                         TModule*        module)
:
  TGadgetWindow(parent, direction, font, module)
{
  Margins.Units = TMargins::BorderUnits;


  Margins.Left = Margins.Right = TUIMetric::CxSizeFrame + 2;  // (6) fixed?
  Margins.Top = Margins.Bottom = TUIMetric::CyFixedFrame;     // (2) fixed?

  // Toolbars default to having tooltips 
  //
  WantTooltip = true;

  TRACEX(OwlWin, OWL_CDLEVEL, "TControlBar constructed @" << (void*)this);
}

//
//
//
TControlBar::~TControlBar()
{
  TRACEX(OwlWin, OWL_CDLEVEL, "TControlBar destructed @" << (void*)this);
}

//
//
bool
TControlBar::PreProcessMsg(MSG& msg)
{
  TRACEX(OwlWin, 1, "TControlBar::PreProcessMsg @" << (void*)this);
  return TGadgetWindow::PreProcessMsg(msg);
}
