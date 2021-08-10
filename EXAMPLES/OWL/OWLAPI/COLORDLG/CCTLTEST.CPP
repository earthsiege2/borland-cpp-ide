//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//
// This example uses the custom control and dialog box defined in colordlg.cpp
//
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\framewin.h>
#include <owl\applicat.h>
#include "cctltest.h"
#include "colordlg.h"

class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication("Custom Control Test") {}

  private:
    void   InitMainWindow();
    void   CmColor();

    TColor Color;

  DECLARE_RESPONSE_TABLE(TTestApp);
};

DEFINE_RESPONSE_TABLE1(TTestApp, TApplication)
  EV_COMMAND(CM_COLOR, CmColor),
END_RESPONSE_TABLE;

void
TTestApp::InitMainWindow()
{
  MainWindow = new TFrameWindow(0, Name);
  MainWindow->AssignMenu("Commands");
  Color = 0;
}

void
TTestApp::CmColor()
{
  char   msg[128];
  if (TColorDialog(MainWindow, Color).Execute() == IDOK)
    wsprintf(msg,
             "RGB intensities:\r\n\r\n Red: %d\r\n Green: %d\r\n Blue: %d",
             Color.Red(), Color.Green(), Color.Blue());
  else
    strcpy(msg, "Cancelled");

  MainWindow->MessageBox(msg, Name, MB_OK);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TTestApp().Run();
}
