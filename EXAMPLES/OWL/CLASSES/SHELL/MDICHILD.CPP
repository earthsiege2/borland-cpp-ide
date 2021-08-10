//----------------------------------------------------------------------------
//  Project Shell
//  Borland International
//  Copyright © 1995, 1996 Borland International. All Rights Reserved.
//
//  SUBSYSTEM:    shell.exe Application
//  FILE:         mdichild.cpp
//  AUTHOR:       The OWL Team
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TShellMDIChild (TMDIChild).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include "shellapp.h"
#include "shellwin.h"
#include "mdichild.h"


//{{TShellMDIChild Implementation}}


//--------------------------------------------------------
// TShellMDIChild
// ~~~~~~~~~~
// Construction/Destruction handling.
//
TShellMDIChild::TShellMDIChild(TMDIClient& parent, const char far* title, TWindow* clientWnd,
                             TShellItem* item, bool shrinkToClient, TModule* module)
:
  TMDIChild(parent, title, !clientWnd ? new TShellWindow(0, item, "") : clientWnd,
            shrinkToClient, module)
{
  // INSERT>> Your constructor code here.

}


TShellMDIChild::~TShellMDIChild()
{
  Destroy();

  // INSERT>> Your destructor code here.

}

// SetIcon
// ~~~~~~~
//
bool TShellMDIChild::SetIcon(HICON icon)
{
  if (IsWindow())
    SendMessage(WM_SETICON, true, (LPARAM)icon);
  return true;
}

// SetIconSm
// ~~~~~~~~~
//
bool TShellMDIChild::SetIconSm(HICON icon)
{
  if (IsWindow())
    SendMessage(WM_SETICON, false, (LPARAM)icon);
  return true;
}
