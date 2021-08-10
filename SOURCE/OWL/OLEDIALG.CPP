//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.10  $
//
// Implementation of class TOleDialog. This defines the basic behavior of all
// Ole dialogs.
//----------------------------------------------------------------------------
#define INC_OLE2
#include <owl/pch.h>
#if !defined(OWL_OLEDIALG_H)
# include <owl/oledialg.h>
#endif

OWL_DIAGINFO;

DEFINE_RESPONSE_TABLE2(TOleDialog, TOleWindow, TDialog)
  EV_OC_VIEWSETSITERECT,
END_RESPONSE_TABLE;

//
//
//
TOleDialog::TOleDialog(TWindow* parent, TResId resId, TModule* module)
           :TOleWindow(parent, module), TDialog(parent, resId, module)
{
  // Register OCX class
  //
  static TRegisterOcxWnd regWnd(GetApplication()->GetHandle());

  // Override TDialog's desire to not be autocreated
  //
  SetFlag(wfAutoCreate);
}

//
//
//
TOleDialog::~TOleDialog()
{
  Destroy();
}

//
//
//
void
TOleDialog::SetupWindow()
{
  // Call parents setup
  //
  TOleWindow::SetupWindow();
  TDialog::SetupWindow();

  HWND hWnd = ::GetWindow(*this, GW_CHILD);
  if (hWnd) {
    // Check if it is a control class and if so, load it
    //
    HWND hWndControl = CheckChild(hWnd);

    // Loop through all the children and look for 'stub' windows
    // that should be replaced with an OCX control...
    //
    while ((hWnd = ::GetWindow(hWnd, GW_HWNDNEXT)) != 0) {
      if (hWndControl)
        ::DestroyWindow(hWndControl);
      hWndControl = CheckChild(hWnd);
    }

    if (hWndControl)
      ::DestroyWindow(hWndControl);
  }
}

//
// Pass thru functions routed to TDialog base
//
bool
TOleDialog::IdleAction(long idleCount)
{
  TOleWindow::IdleAction(idleCount);
  return TDialog::IdleAction(idleCount);
}

bool
TOleDialog::PreProcessMsg(MSG& msg)
{
  if (TOleWindow::PreProcessMsg(msg) || TDialog::PreProcessMsg(msg))
    return true;
  return false;
}

//
// Override SetSiteRect from TOleWindow since we want to force
// our OCX Controls to keep the size and position defined in
// the resource file. This is done by simply returning false
//
bool
TOleDialog::EvOcViewSetSiteRect(TRect far* rect)
{
  TOleWindow::EvOcViewSetSiteRect(rect);
  return false;
}

//
// Check if the hWndChild is a placeholder for a control and if so
// load it. Return hWndChild (if a control is found) so that the calling
// procedure can destroy that window since we don't need that any longer
//
HWND
TOleDialog::CheckChild(HWND hWndChild)
{
  char className [50];
  if (::GetClassName(hWndChild, className, sizeof(className))) {
    if (strcmp(className, OCX_STUB_CLASS) == 0) {
      LoadControl(hWndChild);
      return hWndChild;
    }
  }
  return 0;
}

//
// Find out ProgId (from caption of control) and position for this
// control and load it
//
void
TOleDialog::LoadControl(HWND hControl)
{
  // Get stub control's location
  //
  TRect ControlRect;
  ::GetWindowRect(hControl, &ControlRect);
  TPoint TopLeft(ControlRect.left, ControlRect.top);
  ::ScreenToClient(*this, &TopLeft);
  TPoint BottomRight(ControlRect.right, ControlRect.bottom);
  ::ScreenToClient(*this, &BottomRight);
  ControlRect.Set(TopLeft.x, TopLeft.y, BottomRight.x, BottomRight.y);

  // Get ProgId
  //
  char progId [80];
  ::GetWindowText(hControl, progId, sizeof(progId));

  // Create control with specified progid at location
  //
  InsertControl(TString(progId), &ControlRect);
}

//
// Class to register and unregister the window class which acts as a
// stub window for an OCX in a dialog
//
TRegisterOcxWnd::TRegisterOcxWnd(HINSTANCE hInst)
                :HAppInst(hInst)
{
  // Registration for OCX window
  //
  WNDCLASS wndClass;

  wndClass.style = CS_GLOBALCLASS;   // Global registration
  wndClass.lpfnWndProc = ::DefWindowProc;
  wndClass.cbClsExtra = 0;
  wndClass.cbWndExtra = 0;
  wndClass.hInstance = HAppInst;
  wndClass.hIcon = 0;
  wndClass.hCursor = 0;
  wndClass.hbrBackground = 0;
  wndClass.lpszMenuName = 0;
  wndClass.lpszClassName = OCX_STUB_CLASS;

  RegisterClass(&wndClass);
}

//
// Unregister OCX stub-window class
//
TRegisterOcxWnd::~TRegisterOcxWnd()
{
  UnregisterClass("OCX", HAppInst);
}

