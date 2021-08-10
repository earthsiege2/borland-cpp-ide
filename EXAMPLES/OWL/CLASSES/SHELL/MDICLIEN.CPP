//----------------------------------------------------------------------------
//  Project Shell
//  Borland International
//  Copyright © 1995, 1996 Borland International. All Rights Reserved.
//
//  SUBSYSTEM:    shell.exe Application
//  FILE:         mdiclien.cpp
//  AUTHOR:       The OWL Team
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TShellMDIClient (TMDIClient).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>
#include <stdio.h>

#include "shellapp.h"
#include "shellwin.h"
#include "mdichild.h"
#include "mdiclien.h"


//{{TShellMDIClient Implementation}}


//
// Build a response table for all messages/commands handled
// by TShellMDIClient derived from TMDIClient.
//
DEFINE_RESPONSE_TABLE1(TShellMDIClient, TMDIClient)
//{{ShellMDIClientRSP_TBL_BEGIN}}
  EV_COMMAND(CM_MDIFILENEW, CmFileNew),
//{{ShellMDIClientRSP_TBL_END}}
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TShellMDIClient
// ~~~~~~~~~~~
// Construction/Destruction handling.
//
TShellMDIClient::TShellMDIClient(TModule* module)
:
  TMDIClient(module)
{
  // Change the window's background color
  //
  SetBkgndColor(GetSysColor(COLOR_WINDOW));

  ChildCount = 0;

  // INSERT>> Your constructor code here.

}


TShellMDIClient::~TShellMDIClient()
{
  Destroy();

  // INSERT>> Your destructor code here.

}


//--------------------------------------------------------
// TShellMDIClient
// ~~~~~~~~~~~
// MDIClient site initialization.
//
void TShellMDIClient::SetupWindow()
{
  TMDIClient::SetupWindow();
}


//--------------------------------------------------------
// TShellMDIClient
// ~~~~~~~~~~~
// Menu File New command
//
void TShellMDIClient::CmFileNew()
{
  MyFileNew();
}


void TShellMDIClient::MyFileNew(TShellItem* item)
{
  char    title[255];

  // Generate a title for the MDI child window.
  //
  title[0] = '\0';

  TShellMDIChild* child = new TShellMDIChild(*this, title, 0, item);

  // If the current active MDI child is maximize then this one should be also.
  //
  TShellMDIChild* curChild = (TShellMDIChild *)GetActiveMDIChild();
  if (curChild && (curChild->GetWindowLong(GWL_STYLE) & WS_MAXIMIZE))
    child->Attr.Style |= WS_MAXIMIZE;

  child->Create();
}

