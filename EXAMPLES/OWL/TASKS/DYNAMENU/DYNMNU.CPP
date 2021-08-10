// ---------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1995, 1995 by Borland International, All Rights Reserved
// ---------------------------------------------------------------------------
#include <owl/pch.h>
#include "dynmnu.h"

//
// constructor
//
TDynamicMenuAttr::TDynamicMenuAttr(const string itemString,
  const string hintText, int id)
:
  ItemString(itemString),
  HintText(hintText),
  ItemId(id),
  Enabled(true)
{
}


//
// destructor
//
TDynamicMenuAttr::~TDynamicMenuAttr()
{
}


//
// MenuTestWindow constructor
//
TMenuTestWindow::TMenuTestWindow()
:
  TWindow(0, 0, 0)
{
  NumMenuItems = 0;
  for (int i = 0; i < NUMDYNMENUITEMS; i++)
    DynamicMenuAttr[i] = 0;
}


//
// MenuTestWindow destructor
//
TMenuTestWindow::~TMenuTestWindow()
{
  for (int i = 0; i < NUMDYNMENUITEMS; i++)
    delete DynamicMenuAttr[i];
}


//
// Response table for MenuTestWindow
//
DEFINE_RESPONSE_TABLE1(TMenuTestWindow, TWindow)
  EV_COMMAND(CM_ADDMENU, CmAddMenu),
  EV_COMMAND       (CM_DELETEMENU, CmDeleteMenu),
  EV_COMMAND_ENABLE(CM_DELETEMENU, CeDeleteMenu),
  EV_COMMAND       (CM_ENABLEMENU, CmEnableMenu),
  EV_COMMAND_ENABLE(CM_ENABLEMENU, CeEnableMenu),
  EV_COMMAND       (CM_DISABLEMENU, CmDisableMenu),
  EV_COMMAND_ENABLE(CM_DISABLEMENU, CeDisableMenu),
  EV_WM_RBUTTONDOWN,
END_RESPONSE_TABLE;


//
// GetIndex
//
int
TMenuTestWindow::GetIndex(int low, int high)
{
  const int bufferSize = 80;
  char buffer[bufferSize];

  lstrcpy(buffer, "");
  if (TInputDialog(this, "", "Enter the menu id (between 10000-19999):",
    buffer, bufferSize).Execute() != IDOK) {
    MessageBox("Cancelled", "Status", MB_OK);
    throw IDCANCEL;
  }

  int id = atoi(buffer);
  if (id < low || high <= id) {
    MessageBox("Number not in range", "Error", MB_OK | MB_ICONSTOP);
    throw IDCANCEL;
  }

  // got a valid id
  //
  return id - low;
}


//
// Add a new menu item
//
void
TMenuTestWindow::CmAddMenu()
{
  const int bufferSize = 80;
  char menuString[bufferSize];
  char hintText[bufferSize];
  int index, id;

  try {
    index = GetIndex(CM_DYNFIRST, CM_DYNLAST);
    id = index + CM_DYNFIRST;
  }
  catch (int) {
    return;   // invalid input
  }

  if (DynamicMenuAttr[index] != 0) {
    MessageBox("Id already in use", "Error", MB_OK | MB_ICONSTOP);
    return;
  }

  lstrcpy(menuString, "");
  if (TInputDialog(this, "", "Enter the menu string:",
    menuString, bufferSize).Execute() != IDOK) {
    MessageBox("Cancelled", "Status", MB_OK);
    return; // not a valid menu id
  }

  lstrcpy(hintText, "");
  if (TInputDialog(this, "", "Enter the hint text:",
    hintText, bufferSize).Execute() != IDOK) {
    MessageBox("Cancelled", "Status", MB_OK);
    return; // not a valid menu id
  }

  DynamicMenuAttr[index] = new TDynamicMenuAttr(menuString, hintText, id);

  TMenu* menu = new TMenu(*GetApplication()->GetMainWindow());
  TMenu* dynMenu = new TMenu(menu->GetSubMenu(1));

  dynMenu->InsertMenu(NumMenuItems, MF_BYPOSITION, id, menuString);

  delete dynMenu;
  delete menu;

  NumMenuItems++;
}

//
// Remove a menu item
//
void
TMenuTestWindow::CmDeleteMenu()
{
  int index;

  try {
    index = GetIndex(CM_DYNFIRST, CM_DYNLAST);
  }
  catch (int) {
    return;   // invalid input
  }

  if (DynamicMenuAttr[index] == 0) {
    MessageBox("Menu item not defined", "Error", MB_OK | MB_ICONSTOP);
    return;
  }

  TMenu* menu = new TMenu(*GetApplication()->GetMainWindow());
  TMenu* dynMenu = new TMenu(menu->GetSubMenu(1));

  dynMenu->DeleteMenu(index + CM_DYNFIRST, MF_BYCOMMAND);

  delete dynMenu;
  delete menu;

  NumMenuItems--;
}

void
TMenuTestWindow::CeDeleteMenu(TCommandEnabler& ce)
{
  ce.Enable(NumMenuItems != 0);
}

//
// Enable a menu item
//
void TMenuTestWindow::CmEnableMenu()
{
  int index;

  try {
    index = GetIndex(CM_DYNFIRST, CM_DYNLAST);
  }
  catch (int) {
    return;   // invalid input
  }

  if (DynamicMenuAttr[index] == 0) {
    MessageBox("Menu item not defined", "Error", MB_OK | MB_ICONSTOP);
    return;
  }

  DynamicMenuAttr[index]->Enable(true);
}

void
TMenuTestWindow::CeEnableMenu(TCommandEnabler& ce)
{
  ce.Enable(NumMenuItems != 0);
}

//
// Disable a menu item
//
void TMenuTestWindow::CmDisableMenu()
{
  int index;

  try {
    index = GetIndex(CM_DYNFIRST, CM_DYNLAST);
  }
  catch (int) {
    return;   // invalid input
  }

  if (DynamicMenuAttr[index] == 0) {
    MessageBox("Menu item not defined", "Error", MB_OK | MB_ICONSTOP);
    return;
  }

  DynamicMenuAttr[index]->Enable(false);
}

void
TMenuTestWindow::CeDisableMenu(TCommandEnabler& ce)
{
  ce.Enable(NumMenuItems != 0);
}


//
// override TWindow's virtual functions
// EvCommand
//
LRESULT
TMenuTestWindow::EvCommand(uint id, HWND hWndCtl, uint notifyCode)
{
  if (CM_DYNFIRST <= id && id < CM_DYNLAST) {
    // execute dynamic menu specific item
    //
    int index = id - CM_DYNFIRST;
    string output = "You've selected " + DynamicMenuAttr[index]->GetItemString();
    MessageBox(output.c_str(), "Command", MB_OK);
    return 0;
  }
  return TWindow::EvCommand(id, hWndCtl, notifyCode);
}


//
// EvCommandEnable
//
void
TMenuTestWindow::EvCommandEnable(TCommandEnabler& ce)
{
  if (CM_DYNFIRST <= ce.Id && ce.Id < CM_DYNLAST) {
    // enable dynamic menu specific item
    //
    int index = ce.Id - CM_DYNFIRST;
    ce.Enable(DynamicMenuAttr[index]->IsEnabled());
  }
  else
    TWindow::EvCommandEnable(ce);
}



//
// WM_RBUTTONDOWN
//
void
TMenuTestWindow::EvRButtonDown(uint, TPoint& point)
{
  HWND hwndFrame = *GetApplication()->GetMainWindow();

  TMenu* menu           = new TMenu(hwndFrame);
  TMenu* dynMenu        = new TMenu(menu->GetSubMenu(1));
  TPopupMenu* popupMenu = new TPopupMenu(*dynMenu);

  ClientToScreen(point);
  // send menu messages to the main window allow menu tracking to work seemlessly
  //
  popupMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
    point, 0, hwndFrame, 0);

  delete popupMenu;
  delete dynMenu;
  delete menu;
}

