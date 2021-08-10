//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992 by Borland International
// led.cpp - LedWindow Demo Program
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/window.h>
#include <owl/dc.h>
#include <owl/gdiobjec.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "ledwind.h"

class TLedDemoWindow : public TFrameWindow {
  public:
    TLedDemoWindow(TWindow* parent, const char* title);
    void Paint(TDC& dc, bool erase, TRect& rect);

  DECLARE_RESPONSE_TABLE(TLedDemoWindow);
};
DEFINE_RESPONSE_TABLE1(TLedDemoWindow, TWindow)
  EV_WM_PAINT,
END_RESPONSE_TABLE;

//
//
//
TLedDemoWindow::TLedDemoWindow(TWindow* parent, const char* title)
:
  TFrameWindow(parent, title)
{
  Attr.X = 150;
  Attr.Y = 150;
  Attr.W = 250;
  Attr.H = 195;
  Attr.Style = WS_BORDER | WS_MINIMIZEBOX | WS_SYSMENU;
  SetIcon(GetModule(), "LedICON");
  SetBkgndColor(TColor::Sys3dFace);
}

//
// Label the Demo Leds
//
void TLedDemoWindow::Paint(TDC& dc, bool /*erase*/, TRect& /*rect*/)
{
  dc.SetBkMode(TRANSPARENT);
  dc.TextOut(TPoint(160, 20), "Long Num.", 9);
  dc.TextOut(TPoint(70, 60), "Seconds Timer", 13);
  dc.TextOut(TPoint(135, 100), "Time of Day", 11);
  dc.TextOut(TPoint(135, 140), "Internal Clock", 14);
}

//----------------------------------------------------------------------------

//
//
//
class TLedDemoApp : public TApplication {
  public:
    TLedDemoApp() : TApplication() {}

    void InitMainWindow();
    void InitInstance();
    bool IdleAction(long idleCount);

    TLedWindow* LargeLed;
    TLedWindow* TimerLed;
    TLedWindow* ClockLed;
    TLedWindow* Clock2Led;
};

//
//
//
void TLedDemoApp::InitMainWindow()
{
  TFrameWindow* frame = new TLedDemoWindow(0, "Led Demo");
  LargeLed = new TLedWindow(frame, 15, 15, 10, true, false, 1234567890l);
  TimerLed = new TLedWindow(frame, 15, 55, 3, true, false, 0);
  ClockLed = new TLedWindow(frame, 15, 95, 0, true, true, time(0));
  Clock2Led = new TLedWindow(frame, 15, 135, 0, true, true, 3600);
  SetMainWindow(frame);
}

//
//
//
void TLedDemoApp::InitInstance()
{
  // Start TimerLed Timer (timer must be associated with an HWindow,
  // which does not exist before InitInstance MakeWindow call).
  //
  TApplication::InitInstance();     // perform usual init stuff
  TimerLed->StartTimer(1);          // Update TimerLed every second
  ClockLed->StartTimer(1);          // Update ClockLed every second
}

//
//
//
bool TLedDemoApp::IdleAction(long /*time*/)
{
  if (TimerLed->LedValue == 20) {   // 20 seconds after invoke
    Clock2Led->StartTimer(1);       // Update Clock2Led every second
    LargeLed->DisplayNumber(1111111111l); // Change LargeLed value
  }
  if (TimerLed->LedValue == 30) {   // 30 seconds after invoke
    LargeLed->DisplayNumber(987654321l);  // Change LargeLed value
  }
  if (TimerLed->LedValue == 82) {   // 82 seconds after invoke
    TimerLed->StopTimer();          // Stop TimerLed at 061
    TimerLed->DisplayNumber(1999);  // Move 1999 to TimerLed
                                    // (only 3 digits: 999 displayed)
    Clock2Led->StopTimer();         // Stop Clock2Led at 01:01:01
  }
  return true;
}

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TLedDemoApp().Run();
}
