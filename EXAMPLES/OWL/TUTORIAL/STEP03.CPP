//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1994 by Borland International
//   Tutorial application -- step03.cpp
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dc.h>
#include <string.h>

class TDrawWindow : public TWindow {
  public:
    TDrawWindow(TWindow* parent = 0);

  protected:
    // Override member function of TWindow
    bool CanClose();

    // Message response functions
    void EvLButtonDown(uint, TPoint&);
    void EvRButtonDown(uint, TPoint&);

  DECLARE_RESPONSE_TABLE(TDrawWindow);
};

DEFINE_RESPONSE_TABLE1(TDrawWindow, TWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
END_RESPONSE_TABLE;

TDrawWindow::TDrawWindow(TWindow* parent)
{
  Init(parent, 0, 0);
}

bool
TDrawWindow::CanClose()
{
  return MessageBox("Do you want to save?", "Drawing has changed",
                    MB_YESNO | MB_ICONQUESTION) == IDNO;
}

void
TDrawWindow::EvLButtonDown(uint, TPoint& point)
{
  char s[16];
  TClientDC dc(*this);

  wsprintf(s, "(%d,%d)", point.x, point.y);
  dc.TextOut(point, s, strlen(s));
}

void
TDrawWindow::EvRButtonDown(uint, TPoint&)
{
  Invalidate();
}

class TDrawApp : public TApplication {
  public:
    TDrawApp() : TApplication() {}

    void InitMainWindow()
    {
      SetMainWindow(new TFrameWindow(0, "Sample ObjectWindows Program",
        new TDrawWindow));
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TDrawApp().Run();
}
