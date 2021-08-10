//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Implementation of obsolete functions in class TModule.
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/applicat.h>
#include <owl/dialog.h>
#include <owl/mdi.h>

TWindow*
TModule::MakeWindow(TWindow* win)
{
  if (win->Create())
    return win;

  win->Destroy();
  delete win;
  return 0;
}

int
TModule::ExecDialog(TDialog* dialog)
{
  int ret = dialog->Execute();
  delete dialog;
  return ret;
}

HWND
TModule::GetClientHandle(HWND hWnd)
{
  if (hWnd) {
    HWND  curWindow = GetWindow(hWnd, GW_CHILD);

    if (curWindow) {
      do {
        char  className[10];

        GetClassName(curWindow, className, sizeof(className));

        if (strnicmp(className, "MDICLIENT", sizeof(className)) == 0)
          return curWindow;

      } while ((curWindow = GetWindow(curWindow, GW_HWNDNEXT)) != 0);
    }
  }

  return 0;
}

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
