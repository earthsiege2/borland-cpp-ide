//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/slider.h>
#include <owl/gauge.h>
#include <owl/static.h>
#include <owl/gdiobjec.h>
#include <stdio.h>

const uint16 IDC_THERMOSTAT = 201;
const uint16 IDC_HEATERTIME = 202;
const uint16 IDC_OUTSIDETEMP = 203;
const uint16 IDC_STATICTEMP = 205;
const uint16 IDC_STATICTIME = 206;
const uint16 IDC_STATICOTEMP = 207;
const uint16 IDC_THERMOMETER = 208;
const uint IDT_REFRESH = 1;
const int  Hysteresis = 0;

//
// class TTestWindow
//
class TTestWindow : public TWindow {
  public:
    TTestWindow();
   ~TTestWindow();

  protected:
    // overridden
    //
    void    SetupWindow();

    void    UpdateTemp();
    void    UpdateHeaterTime(uint = 0);
    void    UpdateOTemp(uint = 0);

    // handle messages
    //
    bool    EvEraseBkgnd(HDC);
    HBRUSH  EvCtlColor(HDC, HWND hWndChild, uint ctlType);
    void    EvSysColorChange();
    void    EvTimer(uint timerId);

    TSlider*  Thermostat;
    TSlider*  HeaterTime;
    TSlider*  OutsideTemp;
    TStatic*  StaticTemp;
    TStatic*  StaticTime;
    TStatic*  StaticOTemp;
    TGauge*   Thermometer;
    TBrush*   BkBrush;

    int       Temp;
    int       HeaterTimeLeft;


  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_WM_ERASEBKGND,
  EV_WM_CTLCOLOR,
  EV_WM_SYSCOLORCHANGE,
  EV_WM_TIMER,
  EV_CHILD_NOTIFY_ALL_CODES(IDC_HEATERTIME, UpdateHeaterTime),
  EV_CHILD_NOTIFY_ALL_CODES(IDC_OUTSIDETEMP, UpdateOTemp),
END_RESPONSE_TABLE;

TTestWindow::TTestWindow()
:
  TWindow(0, 0, 0)
{
  Attr.X = 20;
  Attr.Y = 20;
  Attr.W = 380;
  Attr.H = 200;

  StaticTemp = new TStatic(this, IDC_STATICTEMP, "", 110, 30, 160, 17, 0);
  StaticTemp->Attr.Style |= SS_CENTER;
  Thermometer = new TGauge(this, "%d\xB0", IDC_THERMOMETER, 70, 70, 240, 24, true, 2);

TSlider::SetNativeUse(nuNever);

  Thermostat = new THSlider(this, IDC_THERMOSTAT, 70, 130, 240, 40);

  StaticTime = new TStatic(this, IDC_STATICTIME, "", 4, 10, 160, 17, 0);
  StaticTime->Attr.Style |= SS_LEFT;
  HeaterTime = new TVSlider(this, IDC_HEATERTIME, 20, 30, 32, 160);

  StaticOTemp = new TStatic(this, IDC_STATICOTEMP, "", 216, 10, 160, 17, 0);
  StaticOTemp->Attr.Style |= SS_RIGHT;
  OutsideTemp = new TVSlider(this, IDC_OUTSIDETEMP, 330, 30, 32, 160);

  BkBrush = new TBrush(TColor::Sys3dFace);

  Temp = 70;
  HeaterTimeLeft = 0;
}

TTestWindow::~TTestWindow()
{
  delete BkBrush;
}

void
TTestWindow::SetupWindow()
{
  TWindow::SetupWindow();

  Thermostat->SetRange(40, 120);
  Thermostat->SetRuler(5, false);
  Thermostat->SetPosition(75);

  HeaterTime->SetRange(0, 20);
  HeaterTime->SetRuler(2, false);
  HeaterTime->SetPosition(10);

  OutsideTemp->SetRange(20, 90);
  OutsideTemp->SetRuler(5, false);
  OutsideTemp->SetPosition(40);

  Thermometer->SetRange(40-10, 120+10);
  Thermometer->SetValue(75);

  SetTimer(IDT_REFRESH, 1000);

  UpdateTemp();
  UpdateHeaterTime();
  UpdateOTemp();
}

void
TTestWindow::UpdateTemp()
{
  char str[18];
  sprintf(str, "%s %s", "Heater is ", HeaterTimeLeft ? "On" : "Off");
  StaticTemp->SetText(str);
  Thermometer->SetValue(Temp);
}

void
TTestWindow::UpdateHeaterTime(uint)
{
  char str[16];
  sprintf(str, "%d %s", HeaterTime->GetPosition(), "Secs/Cycle");
  StaticTime->SetText(str);
}

void
TTestWindow::UpdateOTemp(uint)
{
  char str[14];
  sprintf(str, "%d\xB0 %s", OutsideTemp->GetPosition(), "Outside");
  StaticOTemp->SetText(str);
}

//
// Paint a raised, 3d face, background
//
bool
TTestWindow::EvEraseBkgnd(HDC hDC)
{
  TDC dc(hDC);

  // SysColors that are bkgnds for text are never dithered & can use FastRect
  dc.TextRect(GetClientRect(), TColor::Sys3dFace);

  // These sysColors might be dithered. PaBlt is an easy way to paint these
  TBrush highlight(TColor::Sys3dHilight);
  dc.SelectObject(highlight);
  dc.PatBlt(0, 0, Attr.W, 2);
  dc.PatBlt(0, 2, 2, Attr.H-2);

  TBrush shadow(TColor::Sys3dShadow);
  dc.SelectObject(shadow);
  dc.PatBlt(1, Attr.H-2, Attr.W-1, 2);
  dc.PatBlt(Attr.W-2, 1, 2, Attr.H-2-1);

  return true;
}

//
// Provide a background color & brush for child controls to use
//
HBRUSH
TTestWindow::EvCtlColor(HDC hDC, HWND /*hWndChild*/, uint /*ctlType*/)
{
  ::SetBkColor(hDC, TColor::Sys3dFace);
  return *BkBrush;
}

//
// Colors have changed. Rebuild the background brush.
//
void
TTestWindow::EvSysColorChange()
{
  delete BkBrush;
  BkBrush = new TBrush(TColor::Sys3dFace);
}

void
TTestWindow::EvTimer(uint /*timerId*/)
{
  Temp += (OutsideTemp->GetPosition()-Temp) / 10;  // heat loss

  int tempSetting = Thermostat->GetPosition();   // turn in heater?
  if (!HeaterTimeLeft && Temp < tempSetting-Hysteresis)
    HeaterTimeLeft = HeaterTime->GetPosition();

  if (HeaterTimeLeft) {             // heater is running
    HeaterTimeLeft--;
    Temp += 4;                      // heat flows into house
  }

  UpdateTemp();
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
    void InitMainWindow()
    {
      TFrameWindow* frame = new TFrameWindow(0, "Home Heater Simulator",
        new TTestWindow, true);
      frame->Attr.Style &= ~WS_THICKFRAME;
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
