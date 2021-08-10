//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\static.h>

class TTestWindow : public TWindow {
  public:
    TTestWindow();
};

TTestWindow::TTestWindow()
  : TWindow(0, 0, 0)
{
  TStatic* statik;

  Attr.W = 390;
  Attr.H = 334;
  
  new TStatic(this, -1, "Default Static", 20, 20, 150, 24, 0);
  new TStatic(this, -1, "SS_SIMPLE", 20, 50, 150, 24, 0);
  new TStatic(this, -1, "SS_LEFT", 20, 80, 150, 24, 0);
  new TStatic(this, -1, "SS_CENTER", 20, 110, 150, 24, 0);
  new TStatic(this, -1, "SS_RIGHT", 20, 140, 150, 24, 0);
  new TStatic(this, -1, "SS_BLACKFRAME", 20, 170, 150, 24, 0);
  new TStatic(this, -1, "SS_BLACKRECT", 20, 200, 150, 24, 0);
  new TStatic(this, -1, "SS_GRAYFRAME", 20, 230, 150, 24, 0);
  new TStatic(this, -1, "SS_GRAYRECT", 20, 260, 150, 24, 0);
  new TStatic(this, -1, "SS_NOPREFIX", 20, 290, 150, 24, 0);
  new TStatic(this, -1, "Sample &Text", 170, 20, 200, 24, 0);

  statik = new TStatic(this, -1, "Sample &Text", 170, 50, 200, 24, 14);
  statik->Attr.Style = (statik->Attr.Style & ~SS_LEFT) | SS_SIMPLE;
  new TStatic(this, -1, "Sample &Text", 170, 80, 200, 24, 0);
  statik = new TStatic(this, -1, "Sample &Text", 170, 110, 200, 24, 14);
  statik->Attr.Style = (statik->Attr.Style & ~SS_LEFT) | SS_CENTER;
  statik = new TStatic(this, -1, "Sample &Text", 170, 140, 200, 24, 14);
  statik->Attr.Style = (statik->Attr.Style & ~SS_LEFT) | SS_RIGHT;
  statik = new TStatic(this, -1, "Sample &Text", 170, 170, 200, 24, 0);
  statik->Attr.Style = (statik->Attr.Style & ~SS_LEFT) | SS_BLACKFRAME;
  statik = new TStatic(this, -1, "Sample &Text", 170, 200, 200, 24, 0);
  statik->Attr.Style = (statik->Attr.Style & ~SS_LEFT) | SS_BLACKRECT;
  statik = new TStatic(this, -1, "Sample &Text", 170, 230, 200, 24, 0);
  statik->Attr.Style = (statik->Attr.Style & ~SS_LEFT) | SS_GRAYFRAME;
  statik = new TStatic(this, -1, "Sample &Text", 170, 260, 200, 24, 0);
  statik->Attr.Style = (statik->Attr.Style & ~SS_LEFT) | SS_GRAYRECT;
  statik = new TStatic(this, -1, "Sample &Text", 170, 290, 200, 24, 0);
  statik->Attr.Style = (statik->Attr.Style & ~SS_LEFT) | SS_RIGHT|SS_NOPREFIX;
}

//----------------------------------------------------------------------------

class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}
    void InitMainWindow() {
      MainWindow = new TFrameWindow(0, "Static Control Tester", new TTestWindow, TRUE);
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TTestApp app;
  return app.Run();
}
