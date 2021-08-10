//----------------------------------------------------------------------------
//  Project Animals
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    Animals Application
//  FILE:         Beastwin.cpp
//  AUTHOR:
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TAnimalsApp (TApplication).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include <stdio.h>

#include "Beastwin.h"
#include "AnmlsDlC.h"                        // Definition of client class.


//{{TAnimalsApp Implementation}}


//
// Build a response table for all messages/commands handled
// by the application.
//
DEFINE_RESPONSE_TABLE1(TAnimalsApp, TApplication)
//{{TAnimalsAppRSP_TBL_BEGIN}}
  EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
//{{TAnimalsAppRSP_TBL_END}}
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TAnimalsApp
//
TAnimalsApp::TAnimalsApp() : TApplication("Animals")
{

  // INSERT>> Your constructor code here.
}


TAnimalsApp::~TAnimalsApp()
{
  // INSERT>> Your destructor code here.
}


//--------------------------------------------------------
// TAnimalsApp
// ~~~~~
// Application intialization.
//
void TAnimalsApp::InitMainWindow()
{
  if (nCmdShow != SW_HIDE)
    nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

  TSDIDecFrame* frame = new TSDIDecFrame(0, GetName(), 0, false);
  frame->SetFlag(wfShrinkToClient);

  // Override the default window style for the main window.
  //
      frame->Attr.Style |= WS_BORDER | WS_CAPTION | WS_CLIPCHILDREN | WS_SYSMENU | WS_THICKFRAME | WS_VISIBLE;
    frame->Attr.Style &= ~(WS_CHILD | WS_MAXIMIZEBOX | WS_MINIMIZEBOX);

  // Assign ICON w/ this application.
  //
  frame->SetIcon(this, IDI_ANIMALS);
  frame->SetIconSm(this, IDI_ANIMALS);

  SetMainWindow(frame);

}



//{{TSDIDecFrame Implementation}}


TSDIDecFrame::TSDIDecFrame(TWindow* parent, const char far* title, TWindow* clientWnd, bool trackMenuSelection, TModule* module)
  : TDecoratedFrame(parent, title, !clientWnd ? new TAnimalsDlgClient(0) : clientWnd, trackMenuSelection, module)
{
  // INSERT>> Your constructor code here.

}


TSDIDecFrame::~TSDIDecFrame()
{
  // INSERT>> Your destructor code here.

}


//--------------------------------------------------------
// TAnimalsApp
// ~~~~~~~~~~~
// Menu Help About Animals command
//
void TAnimalsApp::CmHelpAbout()
{
}



int OwlMain(int , char* [])
{

	TBIVbxLibrary BiLibrary;
   
	TAnimalsApp   app;
  	return app.Run();
}
