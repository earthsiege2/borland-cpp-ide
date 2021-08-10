//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Implementation of class TOleDialog. This defines the basic behavior of all
// Ole dialogs.
//----------------------------------------------------------------------------
#define INC_OLE2
#include <owl/pch.h>
#if !defined(OWL_OLEDIALG_H)
# include <owl/oledialg.h>
#endif

DEFINE_RESPONSE_TABLE2(TOleDialog, TOleWindow, TDialog)
  EV_OC_VIEWSETSITERECT,
END_RESPONSE_TABLE;

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//
// Construction/Destruction handling.
//
TOleDialog::TOleDialog(TWindow* parent, TResId resId, TModule* module)
:
  TOleWindow(parent, module),
  TDialog(parent, resId, module)
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

    // Loop through all the children and look for controls
    //
    while ((hWnd = ::GetWindow(hWnd, GW_HWNDNEXT)) != 0) {
      if (hWndControl)
        ::DestroyWindow(hWndControl); // destroy the dummy window
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
  TOleWindow::PreProcessMsg(msg);
  return TDialog::PreProcessMsg(msg);
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//
// Override SetSiteRect from TOleWindow since we want to force
// our OCX Controls to keep the size and position defined in
// the resource file. This is done simply returning false
//
bool
TOleDialog::EvOcViewSetSiteRect(TRect far* rect)
{
  TOleWindow::EvOcViewSetSiteRect(rect);
  return false;
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//
// Check if the hWndChild is a placeholder for a control and if so
// load it. Return hWndChild (if a control is found) so that the calling
// procedure can destroy that window since we don't need that any longer
//
HWND
TOleDialog::CheckChild(HWND hWndChild)
{
  char className [50];
  if (::GetClassName(hWndChild, className, 50)) {
    if (strcmp(className, "OCX") == 0) {
      LoadControl(hWndChild);
      return hWndChild;
    }
  }
  return 0;
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//
// Find out ProgId and position for this control and load it
//
void
TOleDialog::LoadControl(HWND hControl)
{
  char ProgId [50];
  TRect ControlRect;

  // Get control size
  //
  ::GetWindowRect(hControl, &ControlRect);
  TPoint TopLeft(ControlRect.left, ControlRect.top);
  ::ScreenToClient(*this, &TopLeft);
  TPoint BottomRight(ControlRect.right, ControlRect.bottom);
  ::ScreenToClient(*this, &BottomRight);
  ControlRect.Set(TopLeft.x, TopLeft.y, BottomRight.x, BottomRight.y);

  // Get ProgId
  //
  ::GetWindowText(hControl, ProgId, 50);

  LoadControl(ProgId, ControlRect);
}


//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//
// Load a control to a given position. This is actually a hidden
// InsertControl
//
void
TOleDialog::LoadControl(TString ProgId, TRect position)
{
  TOcInitInfo initInfo(OcView);

  // Get class id from prog id
  //
  CLSID dummyId = CLSID_NULL;
  ::CLSIDFromProgID(ProgId, &dummyId);
  //if (FAILED(::CLSIDFromProgID(ProgId, &dummyId)))
  //  ::MessageBox(0, "Unable to open control", "Open Error", MB_OK);
  initInfo.CId = (BCID) &dummyId;

  // Fill the remaining fields in InitInfo
  //
  initInfo.Where = iwNewOcx;
  initInfo.How = ihEmbed;

  // Load the control
  //
//  SetSelection(new TOcControl(*GetOcDoc(), &initInfo, position));
  TOcControl* control = new TOcControl(*GetOcDoc());
  control->Init(&initInfo, position);
  SetSelection(control);
  OcView->Rename();
  InvalidatePart(invView);

}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//
// Class for register and unregister OCX window class
//
TRegisterOcxWnd::TRegisterOcxWnd(HINSTANCE hInst)
:
  HAppInst(hInst)
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
  wndClass.lpszClassName = "OCX";

  RegisterClass(&wndClass);
}

//
// Unregister OCX window
//
TRegisterOcxWnd::~TRegisterOcxWnd()
{
  UnregisterClass("OCX", HAppInst);
}

