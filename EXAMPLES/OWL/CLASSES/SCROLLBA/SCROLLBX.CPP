//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/scrollba.h>
#include <owl/static.h>
#include <stdio.h>

const WORD ID_THERMOMETER = 201;
const WORD ID_STATIC = 202;

//
// class TTestWindow
// ~~~~~ ~~~~~~~~~~~
class TTestWindow : public TWindow {
  public:
    TTestWindow();

  protected:
    void SetupWindow();
    void EvThermometer(uint code);

    TScrollBar* Thermometer;
    TStatic*    Static;

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_CHILD_NOTIFY_ALL_CODES(ID_THERMOMETER, EvThermometer),
END_RESPONSE_TABLE;

//
//
//
TTestWindow::TTestWindow()
:
  TWindow(0, 0, 0)
{
  Attr.X = 20;
  Attr.Y = 20;
  Attr.W = 380;
  Attr.H = 250;
  Thermometer = new TScrollBar(this, ID_THERMOMETER, 100, 150, 180, 0, TRUE);
  Static = new TStatic(this, ID_STATIC, "32 degrees", 135, 40, 160, 17, 0);
}

void
TTestWindow::SetupWindow()
{
  TWindow::SetupWindow();
  Thermometer->SetRange(32, 120);
}

void
TTestWindow::EvThermometer(uint /*code*/)
{
  char string[12];
  sprintf(string, "%d%s", Thermometer->GetPosition(), " degrees");
  Static->SetText(string);
}


//
// class TTestApp
// ~~~~~ ~~~~~~~~
class TTestApp : public TApplication {
  public:
    TTestApp()
    :
      TApplication()
    {
    }

    void InitMainWindow() {
      TFrameWindow* frame = new TFrameWindow(0, "Thermostat", new TTestWindow, true);
      frame->EnableKBHandler();
      SetMainWindow(frame);
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TTestApp app;
  return app.Run();
}
