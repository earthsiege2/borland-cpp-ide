//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    app.cpp
//
// Date:        27-Apr-95
//
// Description:
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include "Test.h"

//
// Application constructor
//
TTestApp::TTestApp(const char far* name)
:
  TApplication(name),
  THelpFileManager("testhelp.hlp")
{

}


//
// Application destructor
//
TTestApp::~TTestApp()
{
}


//
// InitMainWindow
//
void
TTestApp::InitMainWindow()
{
  TFrameWindow* frame = new TMDIFrame(GetName(), IDM_MDIMENU, *new TTestClient);
  SetMainWindow(frame);
}

DEFINE_RESPONSE_TABLE2(TTestApp, THelpFileManager, TApplication)
  EV_COMMAND(CM_ABOUT, CmAbout),
END_RESPONSE_TABLE;

//
//
//
void
TTestApp::CmAbout()
{
  TAboutDialog(GetMainWindow(), IDD_ABOUT).Execute();
}

//
// OwlMain
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TTestApp app("Test Application");
  return app.Run();
}


TAboutDialog::TAboutDialog(TWindow* parent, TResId resId)
:
  TDialog(parent, resId)
{

}

void
TAboutDialog::SetupWindow()
{
  TDialog::SetupWindow();
  SETUP_HELPCONTEXT(TTestApp, TAboutDialog);
}

void
TAboutDialog::CleanupWindow()
{
  CLEANUP_HELPCONTEXT(TTestApp, TAboutDialog);
  TDialog::CleanupWindow();
}

DEFINE_HELPCONTEXT(TAboutDialog)
  HCENTRY_CONTROL(IDH_ABOUTDLG_IDOK,     IDOK),
  HCENTRY_CONTROL(IDH_ABOUTDLG_IDCANCEL, IDCANCEL),
  HCENTRY_CONTROL(IDH_ABOUTDLG_IDHELP,   IDHELP),
END_HELPCONTEXT;
