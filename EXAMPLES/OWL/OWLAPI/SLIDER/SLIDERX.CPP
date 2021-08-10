//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\slider.h>
#include <owl\gauge.h>
#include <owl\static.h>
#include <owl\gdiobjec.h>
#include <stdio.h>

const WORD ID_THERMOSTAT = 201;
const WORD ID_HEATERTIME = 202;
const WORD ID_OUTSIDETEMP = 203;
const WORD ID_STATICTEMP = 205;
const WORD ID_STATICTIME = 206;
const WORD ID_STATICOTEMP = 207;
const WORD ID_THERMOMETER = 208;
const UINT ID_TIMER = 1;
const int  Hysteresis = 0;

class TTestWindow : public TWindow {
  public:
    TTestWindow();
    
  protected:
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

    void    SetupWindow();

    void    UpdateTemp();
    void    UpdateHeaterTime(UINT=0);
    void    UpdateOTemp(UINT=0);
    
    BOOL    EvEraseBkgnd(HDC);
    HBRUSH  EvCtlColor(HDC, HWND hWndChild, UINT ctlType);
    void    EvSysColorChange();
    void    EvTimer(UINT timerId);

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_WM_ERASEBKGND,
  EV_WM_CTLCOLOR,
  EV_WM_SYSCOLORCHANGE,
  EV_WM_TIMER,
  EV_CHILD_NOTIFY_ALL_CODES(ID_HEATERTIME, UpdateHeaterTime),
  EV_CHILD_NOTIFY_ALL_CODES(ID_OUTSIDETEMP, UpdateOTemp),
END_RESPONSE_TABLE;

TTestWindow::TTestWindow()
  : TWindow(0, 0, 0)
{
  Attr.X = 20;
  Attr.Y = 20;
  Attr.W = 380;
  Attr.H = 200;

  StaticTemp = new TStatic(this, ID_STATICTEMP, "", 110, 30, 160, 17, 0);
  StaticTemp->Attr.Style |= SS_CENTER;
  Thermometer = new TGauge(this, "%d\xB0", ID_THERMOMETER, 70, 70, 240, 24, TRUE, 2);

  Thermostat = new THSlider(this, ID_THERMOSTAT, 70, 130, 240, 40);

  StaticTime = new TStatic(this, ID_STATICTIME, "", 4, 10, 160, 17, 0);
  StaticTime->Attr.Style |= SS_LEFT;
  HeaterTime = new TVSlider(this, ID_HEATERTIME, 20, 30, 32, 160);

  StaticOTemp = new TStatic(this, ID_STATICOTEMP, "", 216, 10, 160, 17, 0);
  StaticOTemp->Attr.Style |= SS_RIGHT;
  OutsideTemp = new TVSlider(this, ID_OUTSIDETEMP, 330, 30, 32, 160);

  BkBrush = new TBrush(::GetSysColor(COLOR_BTNFACE));

  Temp = 70;
  HeaterTimeLeft = 0;
}

void
TTestWindow::SetupWindow()
{
  TWindow::SetupWindow();

  Thermostat->SetRange(40, 120);
  Thermostat->SetRuler(5, FALSE);
  Thermostat->SetPosition(75);
  
  HeaterTime->SetRange(0, 20);
  HeaterTime->SetRuler(2, FALSE);
  HeaterTime->SetPosition(10);

  OutsideTemp->SetRange(20, 90);
  OutsideTemp->SetRuler(5, FALSE);
  OutsideTemp->SetPosition(40);

  Thermometer->SetRange(40-10, 120+10);
  Thermometer->SetValue(75);
  
  SetTimer(ID_TIMER, 1000);
  
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
TTestWindow::UpdateHeaterTime(UINT)
{
  char str[16];
  sprintf(str, "%d %s", HeaterTime->GetPosition(), "Secs/Cycle");
  StaticTime->SetText(str);
}

void
TTestWindow::UpdateOTemp(UINT)
{
  char str[14];
  sprintf(str, "%d\xB0 %s", OutsideTemp->GetPosition(), "Outside");
  StaticOTemp->SetText(str);
}

//
// Paint a raised, grey, background
//
BOOL
TTestWindow::EvEraseBkgnd(HDC hDC)
{
  TDC dc(hDC);

  // SysColors that are bkgnds for text are never dithered & can use FastRect
  dc.TextRect(GetClientRect(), ::GetSysColor(COLOR_BTNFACE));

  // These sysColors might be dithered. PaBlt is an easy way to paint these
  TBrush highlight(::GetSysColor(COLOR_BTNHIGHLIGHT));
  dc.SelectObject(highlight);
  dc.PatBlt(0, 0, Attr.W, 2);
  dc.PatBlt(0, 2, 2, Attr.H-2);

  TBrush shadow(::GetSysColor(COLOR_BTNSHADOW));
  dc.SelectObject(shadow);
  dc.PatBlt(1, Attr.H-2, Attr.W-1, 2);
  dc.PatBlt(Attr.W-2, 1, 2, Attr.H-2-1);  

  return TRUE;
}

//
// Provide a background color & brush for child controls to use
//
HBRUSH
TTestWindow::EvCtlColor(HDC hDC, HWND /*hWndChild*/, UINT /*ctlType*/)
{
  ::SetBkColor(hDC, ::GetSysColor(COLOR_BTNFACE));
  return *BkBrush;
}

//
// Colors have changed. Rebuild the background brush.
//
void
TTestWindow::EvSysColorChange()
{
  delete BkBrush;
  BkBrush = new TBrush(::GetSysColor(COLOR_BTNFACE));
}

void
TTestWindow::EvTimer(UINT /*timerId*/)
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

//----------------------------------------------------------------------------

class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}
    void InitMainWindow() {
      MainWindow = new TFrameWindow(0, "Home Heater Simulator", new TTestWindow, TRUE);
      MainWindow->EnableKBHandler();
      MainWindow->Attr.Style &= ~WS_THICKFRAME;
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TTestApp app;
  return app.Run();
}
