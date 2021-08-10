//----------------------------------------------------------------------------
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    gmplace.cpp
//
// Date:        Sep 28, 1995
//
// Description:
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include "TBExpert.h"

TGadgetManagerPlaceHolder::TGadgetManagerPlaceHolder(TWindow* parent)
:
  TLayoutWindow(parent, 0)
{
  Manager = 0;
  Attr.Style |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
  Attr.ExStyle |= WS_EX_CLIENTEDGE;
}

TGadgetManagerPlaceHolder::~TGadgetManagerPlaceHolder()
{
}

void
TGadgetManagerPlaceHolder::SetupWindow()
{
  TLayoutWindow::SetupWindow();
  CreateGadgetManager();
}

bool
TGadgetManagerPlaceHolder::EvEraseBkgnd(HDC)
{
  return true;
}

DEFINE_RESPONSE_TABLE1(TGadgetManagerPlaceHolder, TLayoutWindow)
//  EV_WM_ERASEBKGND,
END_RESPONSE_TABLE;

void
TGadgetManagerPlaceHolder::CreateGadgetManager()
{
  DeleteGadgetManager();
  Manager = new TGadgetManager(this);
  TLayoutMetrics lmManager;
  lmManager.X.SameAs(lmParent, lmLeft);
  lmManager.Y.SameAs(lmParent, lmTop);
  lmManager.Width.SameAs(lmParent, lmRight);
  lmManager.Height.SameAs(lmParent, lmBottom);
  SetChildLayoutMetrics(*Manager, lmManager);
  if (IsWindow()) {
    Manager->Create();
    Layout();
  }
}

void
TGadgetManagerPlaceHolder::DeleteGadgetManager()
{
  delete Manager;
  Manager = 0;
}


TResult
TGadgetManagerPlaceHolder::EvCommand(uint id, THandle hWndCtl, uint notifyCode)
{
  if (DummyGadgetIdBase <= id && id < DummyGadgetIdBase + MaxGadgetFactories)
    return 0;
  return TLayoutWindow::EvCommand(id, hWndCtl, notifyCode);
}

void
TGadgetManagerPlaceHolder::EvCommandEnable(TCommandEnabler& ce)
{
  if (DummyGadgetIdBase <= ce.GetId() && ce.GetId() < DummyGadgetIdBase + MaxGadgetFactories)
    ce.Enable(true);
  else
    TLayoutWindow::EvCommandEnable(ce);
}

