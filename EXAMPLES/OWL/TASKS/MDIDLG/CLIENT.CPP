//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    client.cpp
//
// Date:        27-Apr-95
//
// Description:
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include "Test.h"
#include "MdiDlg.h"

//
// TestClient constructor
//
TTestClient::TTestClient(TModule* module)
:
  TMDIClient(module)
{
  TMenu contextMenu(*GetApplication(), IDM_MDIMENU);
  TMenu subMenu(contextMenu.GetSubMenu(0));
  AssignContextMenu(new TPopupMenu(subMenu));
}


//
// TestClient destructor
//
TTestClient::~TTestClient()
{
}


//
// SetupWindow
//
void
TTestClient::SetupWindow()
{
  TMdiClient::SetupWindow();
  // put new stuff here
  //
  SETUP_HELPCONTEXT(TTestApp, TTestClient);
}


//
// CleanupWindow
//
void
TTestClient::CleanupWindow()
{
  // put new stuff here
  //
  CLEANUP_HELPCONTEXT(TTestApp, TTestClient);

  TMdiClient::CleanupWindow();
}


//
// Response table for TestClient
//
DEFINE_RESPONSE_TABLE1(TTestClient, TMdiClient)
  EV_COMMAND(CM_CREATECHILD, CmCreateChild),
END_RESPONSE_TABLE;

DEFINE_HELPCONTEXT(TTestClient)
  HCENTRY_MENU(IDH_CM_CREATECHILD,      CM_CREATECHILD),
  HCENTRY_MENU(IDH_CM_CASCADECHILDREN,  CM_CASCADECHILDREN),
  HCENTRY_MENU(IDH_CM_TILECHILDREN,     CM_TILECHILDREN),
  HCENTRY_MENU(IDH_CM_ARRANGEICONS,     CM_ARRANGEICONS),
  HCENTRY_MENU(IDH_CM_CLOSECHILDREN,    CM_CLOSECHILDREN),
  HCENTRY_MENU(IDH_CM_ABOUTDLG,         CM_ABOUT),
END_HELPCONTEXT;


//
// Create a child
//
void
TTestClient::CmCreateChild()
{
  static bool TestDialog = false;
  TestDialog = !TestDialog;
  TMdiChild* child;
  if (TestDialog)
    child = new TMdiChild(*this, "Test Dialog", new TMdiDialog(0, IDD_MDIDIALOG));
  else
    child = new TMdiChild(*this, "MDI About Dialog", new TAboutDialog(0, IDD_ABOUT));
  child->Create();
}


