//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/uihelper.h>
#include <owl/listbox.h>
#include <owl/gdiobjec.h>
#include <winsys/uimetric.h>
#include <stdio.h>

//
// class TSampleWindow
// ~~~~~ ~~~~~~~~~~~~~
class TSampleWindow : public TWindow {
  public:
    TSampleWindow();

  protected:
    void Paint(TDC& dc, bool erase, TRect& rect);

  DECLARE_RESPONSE_TABLE(TSampleWindow);
};

DEFINE_RESPONSE_TABLE1(TSampleWindow, TWindow)
END_RESPONSE_TABLE;

TSampleWindow::TSampleWindow()
:
  TWindow(0, 0, 0)
{
  Attr.X = 0;
  Attr.Y = 0;
  Attr.W = 240;
  Attr.H = 28 * (10+1) + 20;
//  Attr.ExStyle |= WS_EX_CONTROLPARENT; //WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW;

  SetBkgndColor(TColor::Sys3dFace);
}

//
// Paint some UI style thingies
//
void
TSampleWindow::Paint(TDC& dc, bool, TRect&)
{
  // Paint some UIBorders
  //
  TRect r(10,10,10+24,10+24);
  TPoint p(0, 28);
  for (int i = TUIBorder::Plain; i <= TUIBorder::WellSet; i++) { 
    static char* label[] = {
      "Plain",
      "Raised",
      "Recessed",
      "Embossed",
      "Grooved",
      "Button Up",
      "Button Down",
      "Window Raised",
      "Window Recessed",
      "Well Set",
      "Button Up (old)",
      "Button Down (old)",
    };
    TUIBorder b(r, TUIBorder::TStyle(i));
    b.Paint(dc);
    if (i == TUIBorder::WndRaised || i == TUIBorder::WndRecessed ||
        i == TUIBorder::WellSet)
      dc.TextRect(b.GetClientRect(), TColor::SysWindow);
    dc.SetBkColor(TColor::Sys3dFace);
    dc.TextOut(r.right + 5, r.top + 5, label[i-TUIBorder::Plain]);
    r += p;
  }

  // A Mini Window: Window border + an inset field
  //
  r.right += 10;
  r.bottom += 10;
  TUIBorder b1(r, TUIBorder::WndRaised);
  b1.Paint(dc);
  TUIBorder b2(r.InflatedBy(-TUIMetric::CxFixedFrame,-TUIMetric::CyFixedFrame),
    TUIBorder::WndRecessed);
  b2.Paint(dc);
  dc.TextRect(b2.GetClientRect(), TColor::SysWindow);

  // Paint thin divider lines
  //
  TUIBorder b3(TRect(TPoint(5,287),TSize(180,2)), TUIBorder::Recessed);
  b3.Paint(dc);
  TUIBorder b4(TRect(TPoint(150,5),TSize(2,290)), TUIBorder::Recessed);
  b4.Paint(dc);
}

//----------------------------------------------------------------------------

//
// class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    TSampleApp() : TApplication() {}
    void InitMainWindow() {
      TFrameWindow* frame = new TFrameWindow(0, "UI Border", new TSampleWindow, true);
      frame->Attr.Style &= ~WS_THICKFRAME;
      SetMainWindow(frame);
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TSampleApp().Run();
}
