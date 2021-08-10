// ---------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1995, 1995 by Borland International, All Rights Reserved
// ---------------------------------------------------------------------------
#include <owl/pch.h>
#include "SimBor.h"

//
// Application constructor
//
TSimBorApp::TSimBorApp()
:
  TApplication()
{
}

//
// Application destructor
//
TSimBorApp::~TSimBorApp()
{
}

//
// InitMainWindow
//
void
TSimBorApp::InitMainWindow()
{
  SetMainWindow(new TFrameWindow(0, "SimBor application", new TSimBorWindow));
  GetMainWindow()->AssignMenu(IDM_MAINMENU);
}

//
// OwlMain
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TSimBorApp app;
  return app.Run();
}

