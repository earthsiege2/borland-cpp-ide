//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
// This example uses the custom control and dialog box defined in colordlg.cpp
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/framewin.h>
#include <owl/applicat.h>
#include <classlib/pointer.h>
#include <stdio.h>
#include "cctltest.h"
#include "colordlg.h"

//
// class TTestApp
// ~~~~~ ~~~~~~~~
class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication("Custom Control Test") {}

  private:
    void   InitMainWindow();
    void   CmColor();

    TColor Color;

  DECLARE_RESPONSE_TABLE(TTestApp);
};

//
//
//
DEFINE_RESPONSE_TABLE1(TTestApp, TApplication)
  EV_COMMAND(CM_COLOR, CmColor),
END_RESPONSE_TABLE;

//
//
//
void
TTestApp::InitMainWindow()
{
  MainWindow = new TFrameWindow(0, Name);
  MainWindow->AssignMenu(IDM_APPMENU);
  Color = 0;
}

//
//
//
void
TTestApp::CmColor()
{
  TPointer<char> msg = new char[128];
  if (TColorDialog(MainWindow, Color).Execute() == IDOK)
    sprintf(msg,
      "RGB intensities:\r\n\r\n Red: %d\r\n Green: %d\r\n Blue: %d",
      Color.Red(), Color.Green(), Color.Blue());
  else
    strcpy(msg, "Cancelled");

  MainWindow->MessageBox(msg, Name, MB_OK);
}

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TTestApp().Run();
}
