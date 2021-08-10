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

const WORD ID_SLIDER = 201;
const WORD ID_SOLIDGAUGE = 208;
const WORD ID_LEDGAUGE = 209;


class TTestWindow : public TWindow {
  public:
    TTestWindow();
    
  protected:
    TSlider*  Slider;
    TGauge*   SolidGauge;
    TGauge*   LedGauge;
    TBrush*   BkBrush;
    
    int       Setting;

    void    SetupWindow();

    void    UpdateGauges(UINT);
    
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
  EV_CHILD_NOTIFY_ALL_CODES(ID_SLIDER, UpdateGauges),
END_RESPONSE_TABLE;

TTestWindow::TTestWindow()
  : TWindow(0, 0, 0)
{
  Attr.X = 20;
  Attr.Y = 20;
  Attr.W = 280;
  Attr.H = 160;

  SolidGauge = new TGauge(this, "%d%%", ID_SOLIDGAUGE, 20, 20, 240, 34, TRUE, 2);
  LedGauge = new TGauge(this, "", ID_LEDGAUGE, 20, 60, 240, 24, TRUE, 2);

  Slider = new THSlider(this, ID_SLIDER, 20, 110, 240, 40);

  BkBrush = new TBrush(::GetSysColor(COLOR_BTNFACE));

  Setting = 50;
}

void
TTestWindow::SetupWindow()
{
  TWindow::SetupWindow();

  Slider->SetRange(0, 100);
  Slider->SetRuler(10, FALSE);
  Slider->SetPosition(50);
  
  SolidGauge->SetRange(0, 100);
  LedGauge->SetRange(0, 100);
  LedGauge->SetLed(4, 80);
  
  UpdateGauges(0);
}

void
TTestWindow::UpdateGauges(UINT)
{
  Setting = Slider->GetPosition();
  SolidGauge->SetValue(Setting);
  LedGauge->SetValue(Setting);
}

//
// Paint a raised, grey, background
//
BOOL
TTestWindow::EvEraseBkgnd(HDC hDC)
{
  TDC dc(hDC);

  // SysColors that are bkgnds for text are never dithered & can use TextRect
  //
  dc.TextRect(GetClientRect(), ::GetSysColor(COLOR_BTNFACE));

  // These sysColors might be dithered. PaBlt is an easy way to paint these
  //
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

//----------------------------------------------------------------------------

class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}
    void InitMainWindow() {
      MainWindow = new TFrameWindow(0, "Gauge Display", new TTestWindow, TRUE);
      MainWindow->EnableKBHandler();
      MainWindow->Attr.Style &= ~WS_THICKFRAME;
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TTestApp().Run();
}
