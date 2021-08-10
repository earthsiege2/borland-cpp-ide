//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.13  $
//
// Implementation of TSplashWindow
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_LAYOUTWI_H)
# include <owl/layoutwi.h>
#endif
#if !defined(OWL_PICTWIND_H)
# include <owl/pictwind.h>
#endif
#if !defined(OWL_SPLASHWI_H)
# include <owl/splashwi.h>
#endif
#if !defined(OWL_STATIC_H)
# include <owl/static.h>
#endif
#if !defined(OWL_GAUGE_H)
# include <owl/gauge.h>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif

OWL_DIAGINFO;

//
// ID for creating a timer.
//
const int TimerId = 1;

//
// Threshold value for removing the splash screen.
//
const int PercentThreshold = 95;

//
// Response table for the splash window.
//
DEFINE_RESPONSE_TABLE1(TSplashWindow, TLayoutWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_TIMER,
END_RESPONSE_TABLE;

//
// Constructor to create a splash screen.
// The parameters width and height are the dimensions of the window unless
// the style ShrinkToFit is used. In which case, the size of the DIB is used.
// The timeOut parameter is the number of milliseconds to wait until the
// splash screen closes itself. Use 0 to not automatically close the the
// splash screen.
// The splash screen does NOT assume ownership of the DIB. The lifetime of
// the DIB must be as long as the lifetime of the splash screen.
//
TSplashWindow::TSplashWindow(TDib& dib, int width, int height,
  int style, uint timeOut, const char far* title, TModule* module)
:
  TLayoutWindow(0, title, module),
  Style(style),
  TimeOut(timeOut),
  CapturedMouse(false),
  Gauge(0),
  PictWindow(0),
  Static(0)
{
  if (HasStyle(ShrinkToFit)) {
    Attr.W = dib.Width();
    Attr.H = dib.Height();
  }
  else {
    Attr.W = width;
    Attr.H = height;
  }

  Attr.Style = WS_POPUP | WS_VISIBLE | WS_BORDER;

  // If there's a title add the WS_CAPTION style. If ShrinkToFit is set
  // we also want to adjust the height of the window to account for the
  // caption.
  //
  if( title )  {
    Attr.Style |= WS_CAPTION;
    if( HasStyle(ShrinkToFit) )
      Attr.H += ::GetSystemMetrics( SM_CYCAPTION );
  }

  // Ready the layout metrics
  //
  int heightPercentDW = 100;
  TLayoutMetrics lmPictWindow;
  TLayoutMetrics lmGauge;
  TLayoutMetrics lmStatic;

  // Center the dib by default unless ShrinktoFit is set.
  //
  if( HasStyle(ShrinkToFit) )
    PictWindow = new TPictureWindow(this, &dib, TPictureWindow::UpperLeft, "", module);
  else
    PictWindow = new TPictureWindow(this, &dib, TPictureWindow::Center, "", module);

  lmPictWindow.X.SameAs(lmParent, lmLeft);
  lmPictWindow.Y.SameAs(lmParent, lmTop);
  lmPictWindow.Width.SameAs(lmParent, lmWidth);

  // Create optional static control
  //
  if (HasStyle(MakeStatic)) {
    const int StaticPercent = 10;
    Static = new TStatic(this, 1, "", 0, 0, 0, 0, 0, module);
    Static->Attr.Style |= SS_CENTER;
    heightPercentDW -= StaticPercent;
    lmStatic.X.SameAs(lmParent, lmLeft);
    lmStatic.Width.SameAs(lmParent, lmWidth);
    lmStatic.Height.PercentOf(lmParent, StaticPercent, lmHeight);

    lmStatic.Y.Below(PictWindow, 1);
    SetChildLayoutMetrics(*Static, lmStatic);
  }

  // Create optional gauge control
  //
  if (HasStyle(MakeGauge)) {
    const int GaugePercent = 10;
    Gauge = new TGauge(this, "%d%%", 2, 0, 0, 0, 0, true, 0, module);
    heightPercentDW -= GaugePercent;
    lmGauge.X.SameAs(lmParent, lmLeft);
    lmGauge.Width.SameAs(lmParent, lmWidth);
    lmGauge.Height.PercentOf(lmParent, GaugePercent, lmHeight);

    if (HasStyle(MakeStatic))
      lmGauge.Y.Below(Static, 1);
    else
      lmGauge.Y.Below(PictWindow, 1);

    SetChildLayoutMetrics(*Gauge, lmGauge);
  }

  lmPictWindow.Height.PercentOf(lmParent, heightPercentDW, lmHeight);
  SetChildLayoutMetrics(*PictWindow, lmPictWindow);
}

//
// Delete the child controls.
//
TSplashWindow::~TSplashWindow()
{
  delete Static;
  delete Gauge;
  delete PictWindow;
}

//
// After the window has been created, center the window and make it topmost.
//
void
TSplashWindow::SetupWindow()
{
  TLayoutWindow::SetupWindow();

  // Center window, make topmost and adjust size to accomidate static
  // and gauge.
  //
  TRect r  = GetWindowRect();

  if( HasStyle(MakeGauge) && HasStyle(MakeStatic) )  {
    int deltaH = Gauge->Attr.H;
    r.Inflate( 0, deltaH );
  }

  TRect fullRect(0, 0, TUIMetric::CxScreen, TUIMetric::CyScreen);

  int x = (fullRect.Width() - r.Width()) / 2;
  int y = (fullRect.Height() - r.Height()) / 2;
  r.Offset(x, y);
  SetWindowPos(HWND_TOPMOST, r, SWP_SHOWWINDOW);

  if (HasStyle(MakeGauge)) {
    // Set the range
    //
    GetGauge()->SetRange(0, 100);
  }

  if (GetTimeOut() != 0) {
    // Create the timer
    //
    SetTimer(TimerId, GetTimeOut());
  }

  // Trap the mouse click
  //
  if (HasStyle(CaptureMouse)) {
    SetCapture();
    SetCursor(0, IDC_ARROW);
    CapturedMouse = true;
  }
}

//
// Before the window closes, and if the mouse has been captured, release it now.
//
void
TSplashWindow::CleanupWindow()
{
  if (CapturedMouse) {
    ReleaseCapture();
    CapturedMouse = false;
  }

  if (GetTimeOut() != 0)
    KillTimer(TimerId);
}

//
// Overload Create so that we can force the window to paint asap.
//
bool
TSplashWindow::Create()
{
   bool retval = TLayoutWindow::Create();
   UpdateWindow();
   return retval;
}

//
// Change the text within the static control. If the splash screen does not
// have a static control, this does not do anything.
//
void
TSplashWindow::SetText(const char far* text)
{
  if (HasStyle(MakeStatic))
    if (GetStatic()) {
      GetStatic()->SetText(text);
      GetApplication()->PumpWaitingMessages();
    }
}

//
// Set the percentage done for the gauge control. If the splash screen does
// not have a gauge control, this does not do anything.
//
void
TSplashWindow::SetPercentDone(int percent)
{
  if (HasStyle(MakeGauge)) {
    if (GetGauge()) {
      GetGauge()->SetValue(percent);
      GetApplication()->PumpWaitingMessages();
    }

    if (percent > PercentThreshold) {
      // Set up the timer
      //
      if (GetTimeOut() != 0)
        SetTimer(TimerId, GetTimeOut());
    }
  }
}

//
// If the user clicks on the splash screen and the CaptureMouse style
// is on, close the splash screen.
//
void
TSplashWindow::EvLButtonDown(uint /*modKeys*/, TPoint& /*point*/)
{
  if (HasStyle(CaptureMouse)) {
    if (HasStyle(MakeGauge))
      if (GetGauge()->GetValue() < PercentThreshold)
        return;
      SendMessage(WM_CLOSE);
  }
}

//
// Handler for the timer event.
// Closes the window.
//
void
TSplashWindow::EvTimer(uint /*timerId*/)
{
  if (HasStyle(MakeGauge)) {
    if (GetGauge()->GetValue() < PercentThreshold) {
      // If less than 90% and has a gauge, immediately return
      //
      return;
    }
  }
  SendMessage(WM_CLOSE);
}
