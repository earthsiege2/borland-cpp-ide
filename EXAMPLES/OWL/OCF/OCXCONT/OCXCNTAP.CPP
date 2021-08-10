//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// $Revision:   10.0  $
//
// Sample illustrating a simple container with an OCX as client window
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
#include "ocxcntap.h"
#include "ocxcont.h"
#include "ocxcont.rh"

//============================================================================
// Create Application Dictionary
//
DEFINE_APP_DICTIONARY(AppDictionary);

// Create a pointer to a registrar object which will manage all registration
// tasks for our application.
// NOTE: 1. Using the smart pointer class frees us from cleanup chores
//       2. This variable must be named 'Registrar' to allow us to take
//          advantage of the TOleFactory template provided by the libraries.
//
static TPointer<TOcRegistrar> Registrar;

// Declare registration parameters of our application
//
BEGIN_REGISTRATION(AppReg)
  REGDATA(clsid, "{E0407BA0-B023-11CF-AA17-0020AF1B5D5E}")
  REGDATA(appname, "OCF OCX Container")
  REGDATA(description, "OCX Container using OWL/OCF")
END_REGISTRATION


// TOCXContApp - application's main object
//
TOCXContApp::TOCXContApp()
            :TApplication(::AppReg["appname"], ::Module, &::AppDictionary)
{}

// TApplication method overriden to specify our main window object
//
void
TOCXContApp::InitMainWindow()
{
  TOleFrame* frame = new TOleFrame(GetName(), 0, false);
  frame->AssignMenu(IDM_MAIN);
  SetMainWindow(frame);
}

// TApplication method overriden to specify our client window
//
void TOCXContApp::InitInstance()
{
  TApplication::InitInstance();

  // Create and set Client Window
  //
  GetMainWindow()->SetClientWindow(new TOCXContWindow(0));
}

// Application's entry point
//
int
OwlMain(int /*argc*/, char* /*argv*/[])
{
  try {
    ::Registrar = new TOcRegistrar(::AppReg,
                                   TOleFactory<TOCXContApp>(),
                                   TApplication::GetCmdLine());
	  return ::Registrar->Run();
  }
  catch (xmsg& x) {
	  return ::HandleGlobalException(x, "Exception");
  }
}
