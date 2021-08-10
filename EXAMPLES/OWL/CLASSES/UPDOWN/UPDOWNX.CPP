//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// Illustrates the TUpDown class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(OWL_UPDOWN_H)
# include <owl/updown.h>
#endif
#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif
#if !defined(OWL_GAUGE_H)
# include <owl/gauge.h>
#endif
#if !defined(OWL_EDIT_H)
# include <owl/edit.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif
#include <stdio.h>

const uint16 IDC_CLICKEE = 201;
const uint16 IDC_CLICKER = 202;
const uint16 IDC_BUMPER  = 203;
const uint16 IDC_THERMOMETER = 208;

//
// class TTestWindow
// ~~~~~ ~~~~~~~~~~~
class TTestWindow : public TWindow {
  public:
    TTestWindow();
    
  protected:
    TEdit*    Clickee;
    TUpDown*  Clicker;

    TGauge*   Thermometer;
    TUpDown*  Bumper;

    int       Temp;
    void      SetupWindow();
    bool      EvBump(TNmUpDown& not);
    
  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_WM_SYSCOLORCHANGE,
  EV_UDN_DELTAPOS(IDC_BUMPER, EvBump),
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
  Attr.H = 160;

  Clickee = new TEdit(this, IDC_CLICKEE, "42", 10, 10, 70, 28);
#if defined(BI_PLAT_WIN32)
  Clickee->Attr.ExStyle |= WS_EX_CLIENTEDGE;
#endif
  Clicker = new TUpDown(this, IDC_CLICKER, 76, 11, TUIMetric::CxVScroll, 26, Clickee);
  Clicker->Attr.Style |= UDS_SETBUDDYINT | UDS_ALIGNRIGHT;

  Thermometer = new TGauge(this, "%d\xB0", IDC_THERMOMETER, 70, 70, 240, 24, true);
  Bumper = new TUpDown(this, IDC_BUMPER, 320, 70, 30, 24, Thermometer);
  Bumper->Attr.Style |= UDS_HORZ | UDS_WRAP;

  SetBkgndColor(TColor::Sys3dFace);
}

//
//
//
void
TTestWindow::SetupWindow()
{
  TWindow::SetupWindow();

  Clicker->SetRange(0, 80);
  Clicker->SetPos(75);

  Bumper->SetRange(0, 100);
  Bumper->SetPos(50);

  Thermometer->SetValue(50);
}

//
//
//
bool
TTestWindow::EvBump(TNmUpDown& not)
{
  int pos = not.iPos + not.iDelta;
  Thermometer->SetValue(pos);
  return false; // Allow change
}

//----------------------------------------------------------------------------

//
// class TTestApp
// ~~~~~ ~~~~~~~~
class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}
    void InitMainWindow() {
      MainWindow = new TFrameWindow(0, "UpDown Tester", new TTestWindow, true);
      MainWindow->EnableKBHandler();
      MainWindow->Attr.Style &= ~WS_THICKFRAME;
    }
};

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TTestApp().Run();
}
