//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1994 by Borland International
//   Tutorial application -- step02.cpp
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>

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
TDrawWindow::EvLButtonDown(uint, TPoint&)
{
  MessageBox("You have pressed the left mouse button",
    "Message Dispatched", MB_OK);
}

void
TDrawWindow::EvRButtonDown(uint, TPoint&)
{
  MessageBox("You have pressed the right mouse button",
    "Message Dispatched", MB_OK);
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
