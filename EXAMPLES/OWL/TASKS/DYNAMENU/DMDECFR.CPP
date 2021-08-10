// ---------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1995, 1995 by Borland International, All Rights Reserved
// ---------------------------------------------------------------------------
#include <owl/pch.h>
#include "dynmnu.h"

//
// constructor
//
TDynamicMenuDecoratedFrame::TDynamicMenuDecoratedFrame(
  TWindow* parent,
  const char far* title,
  TWindow* clientWnd,
  bool trackMenuSelection,
  TModule* module)
:
  TDecoratedFrame(parent, title, clientWnd, trackMenuSelection, module)
{
}


//
// On idle message, set the hint text
//
void
TDynamicMenuDecoratedFrame::EvEnterIdle(uint source, HWND hWndDlg)
{
  if (source == MSGF_MENU && MenuItemId) {
    if (CM_DYNFIRST <= MenuItemId && MenuItemId < CM_DYNLAST) {
      // is a dynamic menu item
      //
      TMenuTestWindow* mtWin = TYPESAFE_DOWNCAST(GetClientWindow(), TMenuTestWindow);
      TMessageBar* messageBar = TYPESAFE_DOWNCAST(ChildWithId(IDW_STATUSBAR), TMessageBar);
      if (messageBar && mtWin) {
        // client window and statusbar are valid
        //
        int index = MenuItemId - CM_DYNFIRST;
        if (index >= 0 && index < CM_DYNLAST - CM_DYNFIRST && mtWin->DynamicMenuAttr[index])
          messageBar->SetHintText(mtWin->DynamicMenuAttr[index]->GetHintText().c_str());
      }
    }
    else {
      // default action
      //
      TDecoratedFrame::EvEnterIdle(source, hWndDlg);
    }
  }
}


//
// Response table
//
DEFINE_RESPONSE_TABLE1(TDynamicMenuDecoratedFrame, TDecoratedFrame)
  EV_WM_ENTERIDLE,
END_RESPONSE_TABLE;
