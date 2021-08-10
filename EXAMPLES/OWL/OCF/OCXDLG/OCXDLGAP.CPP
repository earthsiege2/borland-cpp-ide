//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// $Revision:   10.11  $
//
// Sample illustrating the use of OCXes in dialogs - Implements TOcxDlgApp
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_OLEFRAME_H)
# include <owl/oleframe.h>
#endif
#if !defined(OWL_OLEFACTO_H)
# include <owl/olefacto.h>
#endif
#if !defined(OCF_OCAPP_H)
# include <ocf/ocapp.h>
#endif
#include "ocxdlgap.h"
#include "ocxdlg.h" 
#include "ocxdlgap.rh"     

//============================================================================
// Create Application Dictionary
DEFINE_APP_DICTIONARY(AppDictionary);

static TPointer<TOcRegistrar> Registrar;

BEGIN_REGISTRATION(OcxDialogAppReg)
  REGDATA(clsid, 	"{2EC13601-3BB4-11CF-A26F-0000C058612D}")
  REGDATA(appname, 	"OcxDlg Container")
  REGDATA(description, 	"OcxDlg Container Application")
END_REGISTRATION

//
//
TOcxDlgApp::TOcxDlgApp() 
           :TApplication(::OcxDialogAppReg["appname"], ::Module, &::AppDictionary)
{
}

//
//
//
void TOcxDlgApp::InitMainWindow()
{
  nCmdShow = SW_HIDE;

  TOleFrame* frame = new TOleFrame(GetName(), 0, false);

  // Override the default window style for the main window.
  //
  frame->ModifyStyle(WS_THICKFRAME, WS_BORDER|WS_CAPTION|WS_CLIPCHILDREN|
                                    WS_MINIMIZEBOX|WS_SYSMENU|WS_VISIBLE);

  // Assign ICON w/ this application.
  //
  frame->SetIcon(this, IDI_SDIAPPLICATION);
  frame->SetIconSm(this, IDI_SDIAPPLICATION);

  SetMainWindow(frame);

  // Windows 3-D controls.
  //
  EnableCtl3d(true);
  EnableBWCC();
}

// Application intialization.
//
void TOcxDlgApp::InitInstance()
{
  TApplication::InitInstance();

  // Create and set Client Window
  //
  GetMainWindow()->SetClientWindow(new TMyOcxDialog(0));   
}

//
//
int OwlMain(int , char* [])
{
  try {
    // Create Application registration object
    //
    ::Registrar = new TOcRegistrar(::OcxDialogAppReg,
                                   TOleFactory<TOcxDlgApp>(),
                                   TApplication::GetCmdLine());
    return ::Registrar->Run();
  }
  catch (xmsg& x) {
    return ::HandleGlobalException(x, "Exception");
  }
}
