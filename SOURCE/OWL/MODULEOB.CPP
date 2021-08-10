//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Implementation of obsolete functions in class TModule.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#if !defined(OWL_MDI_H)
# include <owl/mdi.h>
#endif

//
//
//
TWindow*
TModule::MakeWindow(TWindow* win)
{
  if (win->Create())
    return win;

  win->Destroy();
  delete win;
  return 0;
}

//
//
//
int
TModule::ExecDialog(TDialog* dialog)
{
  int ret = dialog->Execute();
  delete dialog;
  return ret;
}

//
//
//
HWND
TModule::GetClientHandle(HWND hWnd)
{
  if (hWnd) {
    HWND  curWindow = GetWindow(hWnd, GW_CHILD);

    if (curWindow) {
      do {
        char  className[10];

        ::GetClassName(curWindow, className, sizeof(className));

        if (strnicmp(className, "MDICLIENT", sizeof(className)) == 0)
          return curWindow;

      } while ((curWindow = GetWindow(curWindow, GW_HWNDNEXT)) != 0);
    }
  }

  return 0;
}

//
//
//
TWindow*
TModule::GetParentObject(HWND hWndParent)
{
  TWindow*  window = GetWindowPtr(hWndParent);
  HWND      clientHandle;

  if (window)
    return window;

  if ((clientHandle = GetClientHandle(hWndParent)) != 0)
    return new TMDIFrame(hWndParent, clientHandle);

  return new TWindow(hWndParent);
}
