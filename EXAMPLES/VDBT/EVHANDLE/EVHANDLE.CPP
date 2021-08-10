//----------------------------------------------------------------------------
//  Project EVHANDLE
//  
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    EVHANDLE Application
//  FILE:         EVHANDLE.CPP
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TSinkDlgApp (TApplication).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>


#include <owl/vbxctl.h>
#include <stdio.h>

#include "evhandle.h"
#include "dialog.h"                 // Definition of client class.


//
// Build a response table for all messages/commands handled
// by the application.
//
DEFINE_RESPONSE_TABLE1(TSinkDlgApp, TApplication)
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TSinkDlgApp
//
TSinkDlgApp::TSinkDlgApp() : TApplication("Source-Sink Application")
{

}


TSinkDlgApp::~TSinkDlgApp()
{

}


//--------------------------------------------------------
// TSinkDlgApp
// ~~~~~
// Application intialization.
//
void TSinkDlgApp::InitMainWindow()
{
  if (nCmdShow != SW_HIDE)
    nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

  TSDIDecFrame* frame = new TSDIDecFrame(0, GetName(), 0, false);
  frame->SetFlag(wfShrinkToClient);

  // Assign ICON w/ this application.
  //
  frame->SetIcon(this, IDI_SDIAPPLICATION);
  frame->SetIconSm(this, IDI_SDIAPPLICATION);

  SetMainWindow(frame);

}



TSDIDecFrame::TSDIDecFrame(TWindow* parent, const char far* title, TWindow* clientWnd, bool trackMenuSelection, TModule* module)
:
  TDecoratedFrame(parent, title, !clientWnd ? new TDlgClient(0) : clientWnd, trackMenuSelection, module)
{
   // Place the main window under the helper window
	Attr.X= 5;
   Attr.Y= 110;
}


TSDIDecFrame::~TSDIDecFrame()
{

}

int OwlMain(int , char* [])
{
  TBIVbxLibrary   vbxSupport;    // This application has VBX controls.
  TSinkDlgApp   app;
  return app.Run();
}
