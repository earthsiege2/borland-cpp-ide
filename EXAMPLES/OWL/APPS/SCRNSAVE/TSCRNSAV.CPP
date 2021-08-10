//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
//   Windows desktop screensaver classes.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/dialog.h>
#include "tscrnsav.h"

DEFINE_RESPONSE_TABLE1(TScrnSavWindow, TFrameWindow)
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
  EV_WM_MBUTTONDOWN,
  EV_WM_ACTIVATE,
  EV_WM_ACTIVATEAPP,
  EV_WM_KEYDOWN,
  EV_WM_SYSKEYDOWN,
  EV_WM_SYSCOMMAND,
END_RESPONSE_TABLE;

//
//
//
TScrnSavWindow::TScrnSavWindow(TWindow* parent, const char* title, TModule* module)
:
  TFrameWindow(parent, title, 0, false, module)
{
  ShowCursor(false);
  Attr.Style = WS_POPUP;
}

//
//
//
TScrnSavWindow::~TScrnSavWindow()
{
  ShowCursor(true);
}

//
//
//
void
TScrnSavWindow::GetWindowClass(WNDCLASS& wndClass)
{
  TWindow::GetWindowClass(wndClass);
  wndClass.hIcon = 0;
  wndClass.style |= CS_SAVEBITS;
  wndClass.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
}

//
//
//
void
TScrnSavWindow::SetupWindow()
{
  TFrameWindow::SetupWindow();
  GetCursorPos(PrevPt);
  TRect r;
  ::GetWindowRect(GetDesktopWindow(), &r);
  MoveWindow(r, true);
}

//
//
//
void
TScrnSavWindow::EvMouseMove(uint, TPoint& point)
{
  if (point != PrevPt)
    PostMessage(WM_CLOSE);
}

//
//
//
void
TScrnSavWindow::EvLButtonDown(uint, TPoint&)
{
  PostMessage(WM_CLOSE);
}

//
//
//
void
TScrnSavWindow::EvRButtonDown(uint, TPoint&)
{
  PostMessage(WM_CLOSE);
}

//
//
//
void
TScrnSavWindow::EvMButtonDown(uint, TPoint&)
{
  PostMessage(WM_CLOSE);
}

//
//
//
void
TScrnSavWindow::EvActivate(uint active, bool, HWND)
{
  if (!active)
    PostMessage(WM_CLOSE);
}

//
//
//
#if defined(BI_PLAT_WIN32)
void TScrnSavWindow::EvActivateApp(bool active, HANDLE)
#else
void TScrnSavWindow::EvActivateApp(bool active, HTASK)
#endif
{
  if (!active)
    PostMessage(WM_CLOSE);
}

//
//
//
void
TScrnSavWindow::EvKeyDown(uint, uint, uint)
{
  PostMessage(WM_CLOSE);
}

//
//
//
void
TScrnSavWindow::EvSysKeyDown(uint, uint, uint)
{
  PostMessage(WM_CLOSE);
}

//
//
//
void
TScrnSavWindow::EvSysCommand(uint cmdType, TPoint&)
{
  if ((cmdType & 0xFFF0) != SC_SCREENSAVE)
    DefaultProcessing();
}

//
//
//
int
TScrnSavApp::Run()
{
  if (strcmp(lpCmdLine, "/c") == 0 || strcmp(lpCmdLine, "-c") == 0) {
    Configuring = true;
    InitConfigDialog();
    
    // Get the desktop control panel applet's window handle and make a
    // TWindow out of it.
    //
    HWND deskAppletHWnd = ::FindWindow(WC_DIALOG, "Desktop");
    TWindow* deskAppletWnd = 0;
    if (deskAppletHWnd)
      deskAppletWnd = new TWindow(deskAppletHWnd);

    // Set our config dialog to have the applet window as its parent if
    // available
    //
    if (deskAppletWnd)
      ConfigureDialog->SetParent(deskAppletWnd);
    ConfigureDialog->Execute();
    delete ConfigureDialog;

    // When our alias is destructed, it remove its thunk, & restores old proc
    //
    delete deskAppletWnd;
    return 0;
  }
  else {
    Configuring = false;
    return TApplication::Run();
  }
}

//
//
//
void
TScrnSavApp::InitMainWindow()
{
  Configuring = false;
  InitScrnSavWindow();
  if (ScrnSavWnd)
    MainWindow = ScrnSavWnd;
  LastTime = GetCurrentTime();
}

//
//
//
void
TScrnSavApp::InitScrnSavWindow()
{
  ScrnSavWnd = new TScrnSavWindow(0, 0, 0);
}

//
//
//
bool
TScrnSavApp::IdleAction(long)
{
  if (!Configuring) {
    uint32 diffTime = GetCurrentTime() - LastTime;
    if (Speed == 2 || Speed == 1 && diffTime > 10 || diffTime > 50) {
      ScrnSavWnd->AnimateScreen();
      LastTime = GetCurrentTime();
    }
    return true;
  }
  return false;
}
