//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    gadgtmgr.cpp
//
// Date:        27-Sep-95
//
// Description:
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include "TBExpert.h"

TGadgetManager::TGadgetManager(TWindow* parent, TTileDirection  direction,
                               TFont* font, TModule* module)
:
  TGadgetWindow(parent, direction, font, module),
  LastGadget(0),
  StatusManager(0)
{

  for (int i = 0; i < CountOfGadgetFactories; i++)
    Insert(*GadgetFactories[i]->CreateGadget(i));
}

TGadgetManager::~TGadgetManager()
{

}

DEFINE_RESPONSE_TABLE1(TGadgetManager, TGadgetWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_KILLFOCUS,
END_RESPONSE_TABLE;

void
TGadgetManager::SetupWindow()
{
  TGadgetWindow::SetupWindow();
  TTBExpertWindow* window = TYPESAFE_DOWNCAST(Parent->GetParentO(), TTBExpertWindow);
  if (window)
    StatusManager = window->GetStatusManager();
}

void
TGadgetManager::EvKillFocus(THandle handle)
{
  if (LastGadget) {
    TRect lastBounds = LastGadget->GetBounds();
    InvalidateRect(lastBounds);
  }
  TGadgetWindow::EvKillFocus(handle);
}

void
TGadgetManager::EvLButtonDown(uint /*modKeys*/, TPoint& point)
{
  if (StatusManager) {
    TGadget* gadget = GadgetFromPoint(point);
    if (gadget) {
      StatusManager->SetDragStatus(TStatusManager::ModifyGadget,
        gadget->GetId()-DummyGadgetIdBase);
    }
  }
}

void
TGadgetManager::EvMouseMove(uint /*modKeys*/, TPoint& point)
{
  SetFocus();
  TGadget* gadget = GadgetFromPoint(point);
  if (gadget) {
    if (gadget != LastGadget) {
      // invalidate LastGadget;
      //
      if (LastGadget) {
        TRect lastBounds = LastGadget->GetBounds();
        InvalidateRect(lastBounds, true);
      }
      LastGadget = gadget;
    }
    TRect bounds = gadget->GetBounds();
    bounds.Inflate(-1, -1);
    TClientDC dc(*this);
    dc.DrawFocusRect(bounds);
  }
}
