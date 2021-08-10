//----------------------------------------------------------------------------
//  Project ApxDlg
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxDlg Application
//  FILE:         apxdlgap.cpp
//  AUTHOR:
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxDlgApp (TApplication).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include <owl/buttonga.h>
#include <owl/statusba.h>
#include <classlib/cmdline.h>
#include <winsys/registry.h>
#include <stdio.h>

#include "apxdlgap.h"
#include "apxdlgdc.h"                        // Definition of client class.


//{{TApxDlgApp Implementation}}


//
// Build a response table for all messages/commands handled
// by the application.
//
DEFINE_RESPONSE_TABLE1(TApxDlgApp, TApplication)
//{{TApxDlgAppRSP_TBL_BEGIN}}
  EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
//{{TApxDlgAppRSP_TBL_END}}
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TApxDlgApp
//
TApxDlgApp::TApxDlgApp() : TApplication("AppExpert Dialog Client Example")
{

  // INSERT>> Your constructor code here.
}


TApxDlgApp::~TApxDlgApp()
{
  // INSERT>> Your destructor code here.
}


//--------------------------------------------------------
// TApxDlgApp
// ~~~~~
// Application intialization.
//
void TApxDlgApp::InitMainWindow()
{
  if (nCmdShow != SW_HIDE)
    nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

  TSDIDecFrame* frame = new TSDIDecFrame(0, GetName(), 0, true);
  frame->SetFlag(wfShrinkToClient);

  // Assign icons for this application.
  //
  frame->SetIcon(this, IDI_SDIAPPLICATION);
  frame->SetIconSm(this, IDI_SDIAPPLICATION);

  SetMainWindow(frame);

}


//--------------------------------------------------------
// TApxDlgApp
// ~~~~~
// Application instance initialization.
//
void TApxDlgApp::InitInstance()
{
  TApplication::InitInstance();

  ProcessCmdLine(lpCmdLine);
}


//--------------------------------------------------------
// TApxDlgApp
// ~~~~~
// Process command line parameters.
//
void TApxDlgApp::ProcessCmdLine(char * CmdLine)
{
  TCmdLine cmd(CmdLine);

  while (cmd.Kind != TCmdLine::Done) {
    if (cmd.Kind == TCmdLine::Option) {
      if (strnicmp(cmd.Token, "unregister", cmd.TokenLen) == 0) {
        UnRegisterInfo();
        return;
      }
    }
    cmd.NextToken();
  }

  RegisterInfo();
}


//--------------------------------------------------------
// TApxDlgApp
// ~~~~~
// Register application info.
//
void TApxDlgApp::RegisterInfo()
{
  TAPointer<char> buffer = new char[_MAX_PATH];

  GetModuleFileName(buffer, _MAX_PATH);

  TRegKey(TRegKey::ClassesRoot, "ApxDlg.Application\\DefaultIcon").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
  strcat(buffer, ",1");
}


//--------------------------------------------------------
// TApxDlgApp
// ~~~~~
// Unregister application info.
//
void TApxDlgApp::UnRegisterInfo()
{
  TAPointer<char> buffer = new char[_MAX_PATH];

  GetModuleFileName(buffer, _MAX_PATH);

  TRegKey(TRegKey::ClassesRoot, "ApxDlg.Application").DeleteKey("DefaultIcon");
  TRegKey(TRegKey::ClassesRoot, "ApxDlg.Document.1").DeleteKey("DefaultIcon");

  TRegKey::ClassesRoot.DeleteKey("ApxDlg.Application");
}



//{{TSDIDecFrame Implementation}}


TSDIDecFrame::TSDIDecFrame(TWindow* parent, const char far* title, TWindow* clientWnd, bool trackMenuSelection, TModule* module)
:
  TDecoratedFrame(parent, title, !clientWnd ? new TApxDlgDlgClient(0) : clientWnd, trackMenuSelection, module)
{
  // INSERT>> Your constructor code here.

}


TSDIDecFrame::~TSDIDecFrame()
{
  // INSERT>> Your destructor code here.

}


void TSDIDecFrame::SetupWindow()
{
  TDecoratedFrame::SetupWindow();
  TRect  r;
  GetWindowRect(r);

  r.bottom += 30;
  SetWindowPos(0, r, SWP_NOZORDER | SWP_NOMOVE);

  // INSERT>> Your code here.

}


//--------------------------------------------------------
// TApxDlgApp
// ~~~~~~~~~~~
// Menu Help About ApxDlg command
//
void TApxDlgApp::CmHelpAbout()
{
}



int OwlMain(int , char* [])
{
  TApxDlgApp   app;
  return app.Run();
}
