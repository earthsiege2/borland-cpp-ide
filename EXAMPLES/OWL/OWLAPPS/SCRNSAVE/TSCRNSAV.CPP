//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//
//   Windows desktop screensaver classes.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\dialog.h>
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

TScrnSavWindow::TScrnSavWindow(TWindow* parent, const char* title, TModule* module)
  : TFrameWindow(parent, title, 0, FALSE, module)
{
  ShowCursor(FALSE);
  Attr.Style = WS_POPUP;
}

TScrnSavWindow::~TScrnSavWindow()
{
  ShowCursor(TRUE);
}

void
TScrnSavWindow::GetWindowClass(WNDCLASS& wndClass)
{
  TWindow::GetWindowClass(wndClass);
  wndClass.hIcon = 0;
  wndClass.style |= CS_SAVEBITS;
  wndClass.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
}

void
TScrnSavWindow::SetupWindow()
{
  TFrameWindow::SetupWindow();
  GetCursorPos(PrevPt);
  TRect r;
  ::GetWindowRect(GetDesktopWindow(), &r);
  MoveWindow(r, TRUE);
}

void
TScrnSavWindow::EvMouseMove(UINT, TPoint& point)
{
  if (point != PrevPt)
    PostMessage(WM_CLOSE);
}

void
TScrnSavWindow::EvLButtonDown(UINT, TPoint&)
{
  PostMessage(WM_CLOSE);
}

void
TScrnSavWindow::EvRButtonDown(UINT, TPoint&)
{
  PostMessage(WM_CLOSE);
}

void
TScrnSavWindow::EvMButtonDown(UINT, TPoint&)
{
  PostMessage(WM_CLOSE);
}

void
TScrnSavWindow::EvActivate(UINT active, BOOL, HWND)
{
  if (!active)
    PostMessage(WM_CLOSE);
}

#if defined(__WIN32__)
  void TScrnSavWindow::EvActivateApp(BOOL active, HANDLE)
#else
  void TScrnSavWindow::EvActivateApp(BOOL active, HTASK)
#endif
{
  if (!active)
    PostMessage(WM_CLOSE);
}

void
TScrnSavWindow::EvKeyDown(UINT, UINT, UINT)
{
  PostMessage(WM_CLOSE);
}

void
TScrnSavWindow::EvSysKeyDown(UINT, UINT, UINT)
{
  PostMessage(WM_CLOSE);
}

void
TScrnSavWindow::EvSysCommand(UINT cmdType, TPoint&)
{
  if ((cmdType & 0xFFF0) != SC_SCREENSAVE)
    DefaultProcessing();
}

int
TScrnSavApp::Run()
{
  if (strcmp(lpCmdLine, "/c") == 0 || strcmp(lpCmdLine, "-c") == 0) {
    Configuring = TRUE;
    InitConfigDialog();
    
    //
    // Get the desktop control panel applet's window handle and make a
    // TWindow out of it.
    //
    HWND deskAppletHWnd = ::FindWindow(WC_DIALOG, "Desktop");
    TWindow* deskAppletWnd = 0;
    if (deskAppletHWnd)
      deskAppletWnd = new TWindow(deskAppletHWnd);

    //
    // Set our config dialog to have the applet window as its parent if
    // available
    //
    if (deskAppletWnd)
      ConfigureDialog->SetParent(deskAppletWnd);
    ConfigureDialog->Execute();
    delete ConfigureDialog;

    //
    // When our alias is destructed, it remove its thunk, & restores old proc
    //
    delete deskAppletWnd;
    return Status;

  } else {
    Configuring = FALSE;
    return TApplication::Run();
  }
}

void
TScrnSavApp::InitMainWindow()
{
  Configuring = FALSE;
  InitScrnSavWindow();
  if (ScrnSavWnd)
    MainWindow = ScrnSavWnd;
  LastTime = GetCurrentTime();
}

void
TScrnSavApp::InitScrnSavWindow()
{
  ScrnSavWnd = new TScrnSavWindow(0, 0, 0);
}

BOOL
TScrnSavApp::IdleAction(long)
{
  if (!Configuring) {
    uint32 diffTime = GetCurrentTime() - LastTime;
    if (Speed == 2 || Speed == 1 && diffTime > 10 || diffTime > 50) {
      ScrnSavWnd->AnimateScreen();
      LastTime = GetCurrentTime();
    }
    return TRUE;
  }
  return FALSE;
}
