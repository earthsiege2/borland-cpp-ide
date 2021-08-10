//----------------------------------------------------------------------------
//  Project Shell
//  Borland International
//  Copyright © 1995, 1996 Borland International. All Rights Reserved.
//
//  SUBSYSTEM:    shell.exe Application
//  FILE:         shellapp.cpp
//  AUTHOR:       The OWL Team
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TShellApp (TApplication).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include <owl/controlb.h>
#include <owl/buttonga.h>
#include <owl/statusba.h>

#include "shellapp.h"
#include "mdiclien.h"
#include "aboutdlg.h"                        // Definition of about dialog.

//{{TShellApp Implementation}}

//
// Build a response table for all messages/commands handled by the application.
//
DEFINE_RESPONSE_TABLE1(TShellApp, TApplication)
//{{ShellAppRSP_TBL_BEGIN}}
  EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
//{{ShellAppRSP_TBL_END}}
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TShellApp
// ~~~~~
//
TShellApp::TShellApp() : TApplication("OWL Win 95 Shell Classes Sample Application")
{
  CoInitialize(0);
}


TShellApp::~TShellApp()
{
  CoUninitialize();
}


bool TShellApp::CanClose()
{
  bool result = TApplication::CanClose();

  return result;
}


void TShellApp::SetupSpeedBar(TDecoratedMDIFrame* frame)
{
  // Create default toolbar New and associate toolbar buttons with commands.
  //
  TControlBar* cb = new TControlBar(frame);
  cb->Insert(*new TButtonGadget(CM_MDIFILENEW, CM_MDIFILENEW));

  // Add fly-over help hints.
  //
  cb->SetHintMode(TGadgetWindow::EnterHints);

  frame->Insert(*cb, TDecoratedFrame::Top);
}


//--------------------------------------------------------
// TShellApp
// ~~~~~
// Application intialization.
//
void TShellApp::InitMainWindow()
{
  if (nCmdShow != SW_HIDE)
    nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

  MdiClient = new TShellMDIClient;
  TDecoratedMDIFrame* frame = new TDecoratedMDIFrame(Name, IDM_MDI, *MdiClient, true);

  // Assign ICON w/ this application.
  //
  frame->SetIcon(0, IDI_WINLOGO);

  // Associate with the accelerator table.
  //
  frame->Attr.AccelTable = IDM_MDI;

  SetupSpeedBar(frame);

  TStatusBar* sb = new TStatusBar(frame, TGadget::Recessed,
                                  TStatusBar::CapsLock        |
                                  TStatusBar::NumLock         |
                                  TStatusBar::ScrollLock);
  frame->Insert(*sb, TDecoratedFrame::Bottom);
  SetMainWindow(frame);

  frame->SetMenuDescr(TMenuDescr(IDM_MDI));

  // Windows 3-D controls.
  //
  EnableCtl3d(true);
}


// Response Table handlers:
//


// Menu Help About command
void TShellApp::CmHelpAbout()
{
  TShellAboutDlg(&TWindow(::GetFocus(), this)).Execute();
}


//
// Process application messages to provide context sensitive help
//
bool TShellApp::ProcessAppMsg(MSG& msg)
{
  return TApplication::ProcessAppMsg(msg);
}

int OwlMain(int , char* [])
{
  if (TSystem::GetMajorVersion() < 4) {
    ::MessageBox(0, "Windows 4.0 (or greater) is required to run this example.",
               "OWL Shell Example", MB_OK | MB_ICONEXCLAMATION);
    return 0;
  }
  else {
    TShellApp   app;
    return app.Run();
  }
}

