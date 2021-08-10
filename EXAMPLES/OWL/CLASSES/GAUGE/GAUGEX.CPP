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
#include <owl/uihelper.h>
#include <owl/gdiobjec.h>
#include <stdio.h>

const uint16 IDC_SLIDER = 201;
const uint16 IDC_SOLIDGAUGE = 208;
const uint16 IDC_LEDGAUGE = 209;

//
// class TTestWindow
// ~~~~~ ~~~~~~~~~~~
class TTestWindow : public TWindow {
  public:
    TTestWindow();

  protected:
    TSlider*  Slider;
    TGauge*   SolidGauge;
    TGauge*   LedGauge;

    void    SetupWindow();
    void    UpdateGauges(uint);

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_CHILD_NOTIFY_ALL_CODES(IDC_SLIDER, UpdateGauges),
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
  Attr.W = 280;
  Attr.H = 160;
  Attr.Style |= WS_CLIPCHILDREN;
  Attr.ExStyle |= WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW;

//  TGauge::SetNativeUse(nuNever);

  SolidGauge = new TGauge(this, "%d%%", IDC_SOLIDGAUGE, 20, 20, 240, 34, true);
  SolidGauge->SetRange(0, 100);

  LedGauge = new TGauge(this, IDC_LEDGAUGE, 20, 60, 240, 40 /*24*/);
  LedGauge->SetRange(0, 100);
  LedGauge->SetLed(4, 80);
  LedGauge->SetStep(8);

  // Construct & set initial settings for slider. The settings can be changed
  // before or after the window is created
  //
  Slider = new THSlider(this, IDC_SLIDER, 20, 110, 240, 40);
  Slider->SetRange(0, 100);
  Slider->SetRuler(10, false);
  Slider->SetPosition(50);

  SetBkgndColor(TColor::Sys3dFace);
}

//
// Use this oportunity to make sure that the gauges positions are sync'd with
// the slider position
//
void
TTestWindow::SetupWindow()
{
  TWindow::SetupWindow();
  UpdateGauges(0);
}

//
// Retrieve the slider position & use it to position the gauges
//
void
TTestWindow::UpdateGauges(uint)
{
  int setting = Slider->GetPosition();
  SolidGauge->SetValue(setting);
  LedGauge->SetValue(setting);
}

//
// class TTestApp
// ~~~~~ ~~~~~~~~
class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}
    void InitMainWindow() {
      TFrameWindow* frame = new TFrameWindow(0, "Gauge Display",
                                             new TTestWindow, true);
//      frame->EnableKBHandler();
      frame->Attr.Style &= ~WS_THICKFRAME;
      SetMainWindow(frame);
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TTestApp().Run();
}
