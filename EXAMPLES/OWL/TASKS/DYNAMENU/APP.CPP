// ---------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1995, 1995 by Borland International, All Rights Reserved
// ---------------------------------------------------------------------------
#include <owl/pch.h>
#include "dynmnu.h"

//
// Main menu resource name
//
char* MainMenu = "TrackMenu";


//
// Application constructor
//
TMenuTestApp::TMenuTestApp() :
  TApplication()
{
}


//
// Application destructor
//
TMenuTestApp::~TMenuTestApp()
{
}


//
// InitMainWindow
//
void
TMenuTestApp::InitMainWindow()
{
  TDecoratedFrame* frame = new TDynamicMenuDecoratedFrame(0,
    "MenuTest application", new TMenuTestWindow, true);

  // create status bar
  //
  StatusBar = new TStatusBar(frame, TGadget::Embossed);
  frame->Insert(*StatusBar, TDecoratedFrame::Bottom);

  frame->AssignMenu(MainMenu);
  SetMainWindow(frame);
}


//
// OwlMain
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TMenuTestApp app;
  return app.Run();
}

