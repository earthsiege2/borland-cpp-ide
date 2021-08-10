//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1995 by Borland International, All Rights Reserved
//
// Example to demonstrate TSplashWindow capabilities.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/dialog.h>
#include <owl/static.h>
#include <owl/gauge.h>
#include <owl/gdiobjec.h>
#include <owl/splashwi.h>
#include <stdio.h>

const uint WUM_START = WM_USER + 0x875;

TSplashWindow* Splash = 0;


//
// class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
class TClientWindow : public TWindow {
  public:
    TClientWindow(TWindow* parent= 0);
    int32 WumStart(TParam1, TParam2);

  protected:
    void SetupWindow();
    int LoadPercentDone;

  DECLARE_RESPONSE_TABLE(TClientWindow);
};


DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
  EV_MESSAGE(WUM_START, WumStart),
END_RESPONSE_TABLE;


//
//
//
TClientWindow::TClientWindow(TWindow* parent)
:
  TWindow(parent),
  LoadPercentDone(0)
{
  Attr.Style |= (WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

  // a theoretical 10-step loading process
  //
  LoadPercentDone = 10;
  for (int i = 1; i <= 3; i++, LoadPercentDone += 10) {
    // update the splash dialog for each step
    //
    char buffer[80];
    sprintf(buffer, "Constructor step %d", i);
    ::Splash->SetText(buffer);
    ::Splash->SetPercentDone(LoadPercentDone);

    // application-specific startup initialization
    //
    switch (i) {
      case 1: {
        // maybe load first DLL
        //
        break;
      } // case 1

      // other cases, etc.
      //
    }

    // a delay only for this demo only
    //
    uint32 start = GetTickCount();
    while (GetTickCount() - start < 500)
      ;
  }

}


//
// Called before main window is displayed.
//
void
TClientWindow::SetupWindow()
{
  TWindow::SetupWindow();

  // this initialization stuff requires a valid HWND
  //
  for (int i = 1; i <= 3; i++, LoadPercentDone += 10) {
    // update the splash dialog for each step
    //
    char buffer[80];
    sprintf(buffer, "SetupWindow step %d", i);
    ::Splash->SetText(buffer);
    ::Splash->SetPercentDone(LoadPercentDone);

    // application-specific startup initialization
    //
    switch (i) {
      case 1: {
        // maybe create new controls on the fly
        // or initialize child controls
        //
        break;
      } // case 1

      // other cases, etc.
      //
    }

    // a delay only for this demo only
    //
    uint32 start = GetTickCount();
    while (GetTickCount() - start < 500)
      ;
  }

  // Ensure main window's painting routine is finished before continuing.
  // This will appear that the main window comes up behind the splash.
  PostMessage(WUM_START);
  Parent->SetCaption("Hello World!");
}


//
// Ensure main window's painting routine is finished before continuing.
//
int32
TClientWindow::WumStart(TParam1, TParam2)
{
  // This initialization stuff guaranteed after the window is painted
  //
  for (int i = 1; i <= 4; i++, LoadPercentDone += 10) {
    // Update the splash dialog for each step
    //
    char buffer[80];
    sprintf(buffer, "WumStart step %d", i);
    ::Splash->SetText(buffer);
    ::Splash->SetPercentDone(LoadPercentDone);

    // Application-specific startup initialization
    //
    switch (i) {
      case 1: {
        // Other initialization
        //
        break;
      } // case 1

      // Other cases, etc.
      //
    }

    // A delay only for this demo only
    //
    uint32 start = GetTickCount();
    while (GetTickCount() - start < 500)
      ;
  }

  // Uncomment the next two lines to force splash to close
  //

  // delete ::Splash;
  // ::Splash = 0;

  return 0;
}

//----------------------------------------------------------------------------

//
// class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    void InitMainWindow();
};

//
// Create the main window.
//
void
TSampleApp::InitMainWindow()
{
  // Construct & create the splash screen
  //
  int style = TSplashWindow::MakeStatic |
              TSplashWindow::MakeGauge |
              TSplashWindow::CaptureMouse |
              TSplashWindow::ShrinkToFit;
  int timeOut = 3000;

  ::Splash = new TSplashWindow(*new TDib("splslogo.bmp"), 400, 300,
    style, timeOut, "", this);
  ::Splash->Create();

  // Construct the main window
  //
  SetMainWindow(new TFrameWindow(0, 0, new TClientWindow()));
}


int
OwlMain(int /*argc*/, char* /*argv*/[])
{
  return TSampleApp().Run();
}
