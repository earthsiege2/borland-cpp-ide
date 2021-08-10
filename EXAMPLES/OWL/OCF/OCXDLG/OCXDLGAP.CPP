//----------------------------------------------------------------------------
//  Project OcxDlg
//  Borland International, Inc.
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    OcxDlg Application
//  FILE:         OcxDlgAp.cpp
//  AUTHOR:       Chris McConn
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TOcxDlgApp (TApplication).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include <owl/oleframe.h>
#include <owl/olefacto.h>
#include <ocf/ocapp.h>

#include "OcxDlgAp.h"
#include "OcxDlg.h" // Definition of client class.

#include "OcxDlgAp.rh"     // Definition of all resources.

//============================================================================
// Create Application Dictionary
DEFINE_APP_DICTIONARY(AppDictionary);

//============================================================================
// Registration tasks:

// Create a pointer to a registrar object which will manage all registration
// tasks for TOcxDlgApp.  By declaring the pointer this way instead of as a
// TOcRegistrar* ensures the registrar object is deleted.  Since the
// TOleFactory template is used in OwlMain() below this variable MUST be
// called Registrar.
static TPointer<TOcRegistrar> Registrar;
TOcApp* OcApp = 0;

REGISTRATION_FORMAT_BUFFER(200)
TRegLink* RegLinkHead;

BEGIN_REGISTRATION(OcxDialogAppReg)
  REGDATA(clsid, "{2EC13601-3BB4-11CF-A26F-0000C058612D}")
  REGDATA(appname, "OcxDlg Container")
  REGDATA(description, "OcxDlg Container Application")
  REGDATA(cmdline, "")
END_REGISTRATION

//========================================================
// Build a response table for all messages/commands handled by the application.
DEFINE_RESPONSE_TABLE1(TOcxDlgApp, TApplication)
END_RESPONSE_TABLE;

//########################################################
// TOcxDlgApp Constructors/Destructors

//========================================================
TOcxDlgApp::TOcxDlgApp() : TApplication(::OcxDialogAppReg["appname"], ::Module, &::AppDictionary)
{
}

//========================================================
TOcxDlgApp::~TOcxDlgApp()
{
}

//########################################################
// Implement virtual methods of TApplication

//========================================================
// Application main window construction
void TOcxDlgApp::InitMainWindow()
{
  nCmdShow = SW_HIDE;


  TOleFrame* frame = new TOleFrame(GetName(), 0, false);

  // Override the default window style for the main window.
  frame->ModifyStyle( WS_THICKFRAME,
  									  WS_BORDER | WS_CAPTION | WS_CLIPCHILDREN
  									| WS_MINIMIZEBOX | WS_SYSMENU | WS_VISIBLE);

  // Assign ICON w/ this application.
  frame->SetIcon(this, IDI_SDIAPPLICATION);
  frame->SetIconSm(this, IDI_SDIAPPLICATION);

  SetMainWindow(frame);

  // Windows 3-D controls.
  EnableCtl3d(true);
  EnableBWCC();
  
  TAPointer<char> buffer = new char[_MAX_PATH];

  GetModuleFileName(buffer, _MAX_PATH);

  TRegKey(TRegKey::ClassesRoot, "OcxDlg.Application\\DefaultIcon").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
  strcat(buffer, ",1");
  TRegKey(TRegKey::ClassesRoot, "Ocxdlg.Document.1\\DefaultIcon").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
  strcpy(buffer, "Ocxdlg.Document.1");
  TRegKey(TRegKey::ClassesRoot, ".olv").SetDefValue(0, REG_SZ, buffer, strlen(buffer));

}

//========================================================
// Application intialization.
void TOcxDlgApp::InitInstance()
{
  TApplication::InitInstance();

  // Create and set Client Window
  GetMainWindow()->SetClientWindow(new TMyOcxDialog(0));   
}

//########################################################
// Main Windows Routine
int OwlMain(int , char* [])
{
  try {
	  // Create Application registration object
    ::Registrar = new TOcRegistrar(::OcxDialogAppReg,
                                   TOleFactory<TOcxDlgApp>(),
                                   TApplication::GetCmdLine());

	  return ::Registrar->Run();
  }
  catch (xmsg& x) {
	  return ::HandleGlobalException(x, "Exception");
  }
}
