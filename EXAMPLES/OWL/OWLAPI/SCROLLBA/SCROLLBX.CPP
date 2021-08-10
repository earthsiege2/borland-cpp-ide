//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\scrollba.h>
#include <owl\static.h>
#include <stdio.h>

const WORD ID_THERMOMETER = 201;
const WORD ID_STATIC = 202;

class TTestWindow : public TWindow {
  public:
    TTestWindow();
    
  protected:
    void SetupWindow();

    void EvThermometer(UINT code);

    TScrollBar* Thermometer;
    TStatic*    Static;

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_CHILD_NOTIFY_ALL_CODES(ID_THERMOMETER, EvThermometer),
END_RESPONSE_TABLE;

TTestWindow::TTestWindow()
  : TWindow(0, 0, 0)
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
TTestWindow::EvThermometer(UINT /*code*/)
{
  char string[12];
  sprintf(string, "%d%s", Thermometer->GetPosition(), " degrees");
  Static->SetText(string);
}

//----------------------------------------------------------------------------

class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}
    void InitMainWindow() {
      MainWindow = new TFrameWindow(0, "Thermostat", new TTestWindow, TRUE);
      MainWindow->EnableKBHandler();
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TTestApp app;
  return app.Run();
}
