//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/static.h>

//
// class TTestWindow
// ~~~~~ ~~~~~~~~~~~
class TTestWindow : public TWindow {
  public:
    TTestWindow(TWindow* parent = 0);
};

//
//
//
TTestWindow::TTestWindow(TWindow* parent)
:
  TWindow(parent)
{
  struct {
    char*  Text;
    uint32 And;
    uint32 Or;
  }
  ctlInfo[] = {
    { "Default",     0xFFFFFFFFL, 0 },
    { "SS_SIMPLE",      ~SS_LEFT, SS_SIMPLE },
    { "SS_LEFT",        ~SS_LEFT, SS_LEFT },
    { "SS_NOPREFIX",    ~SS_LEFT, SS_NOPREFIX },
    { "SS_CENTER",      ~SS_LEFT, SS_CENTER },
    { "SS_RIGHT",       ~SS_LEFT, SS_RIGHT },
    { "SS_BLACKRECT",   ~SS_LEFT, SS_BLACKRECT },
    { "SS_GRAYRECT",    ~SS_LEFT, SS_GRAYRECT },
    { "SS_BLACKFRAME",  ~SS_LEFT, SS_BLACKFRAME },
    { "SS_GRAYFRAME",   ~SS_LEFT, SS_GRAYFRAME },
    { "SS_WHITEFRAME",  ~SS_LEFT, SS_WHITEFRAME },
#if defined(BI_PLAT_WIN32)
    { "SS_ETCHEDHORZ",  ~SS_LEFT, SS_ETCHEDHORZ },   //0x00000010L
    { "SS_ETCHEDVERT",  ~SS_LEFT, SS_ETCHEDVERT },   //0x00000011L
    { "SS_ETCHEDFRAME", ~SS_LEFT, SS_ETCHEDFRAME },   //0x00000012L
#endif
  };

  Attr.W = 390;
  Attr.H = 460;

#if defined(BI_PLAT_WIN32)
  Attr.ExStyle |= WS_EX_CONTROLPARENT;
#endif

  for (int i = 0; i < COUNTOF(ctlInfo); i++) {
    new TStatic(this, -1, ctlInfo[i].Text, 20, 20 + i*30, 150, 24, 0);
    TStatic* statik = new TStatic(this, -1, "Sample &Text", 170, 20 + i*30, 200, 24, 0);
    statik->Attr.Style = (statik->Attr.Style & ctlInfo[i].And) | ctlInfo[i].Or;
  }

  SetBkgndColor(TColor::Sys3dFace);
}


//
// class TTestApp
// ~~~~~ ~~~~~~~~
class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}
    void InitMainWindow() {
      SetMainWindow(new TFrameWindow(0, "Static Control Tester", new TTestWindow, true));
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TTestApp app;
  return app.Run();
}
