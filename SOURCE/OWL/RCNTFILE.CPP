//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.14  $
//
// Implementation of class TRecentFiles
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(WINSYS_PROFILE_H)
# include <winsys/profile.h>
#endif
#if !defined(OWL_RCNTFILE_H)
# include <owl/rcntfile.h>
#endif
#if !defined(CLASSLIB_POINTER_H)
# include <classlib/pointer.h>
#endif
#if !defined(OWL_WINDOW_RH)
# include <owl/window.rh>
#endif
#if !defined(OWL_EDITFILE_RH)
# include <owl/editfile.rh>
#endif
#include <stdio.h>

OWL_DIAGINFO;

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

const int CM_MRU_FIRST      = 31990;
const int CM_MRU_LAST       = CM_MRU_FIRST + TRecentFiles::MaxMenuItems;

const char* Section   = "MRU";
const char* CountKey  = "Count";
const char* MruPrefix = "MRU";
const char* MenuItemDefault = "Default";
const int   MaxMenuItemLen = 255;
uint TRecentFiles::MruMessage = 0;

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

IMPLEMENT_CASTABLE(TRecentFiles);

//
// Response Table to catch the items selected from the menu.
//
DEFINE_RESPONSE_TABLE1(TRecentFiles, TEventHandler)
  EV_COMMAND_AND_ID(CM_MRU_FIRST + 0, CmFile),
  EV_COMMAND_AND_ID(CM_MRU_FIRST + 1, CmFile),
  EV_COMMAND_AND_ID(CM_MRU_FIRST + 2, CmFile),
  EV_COMMAND_AND_ID(CM_MRU_FIRST + 3, CmFile),
  EV_COMMAND_AND_ID(CM_MRU_FIRST + 4, CmFile),
  EV_COMMAND_AND_ID(CM_MRU_FIRST + 5, CmFile),
  EV_COMMAND_AND_ID(CM_MRU_FIRST + 6, CmFile),
  EV_COMMAND_AND_ID(CM_MRU_FIRST + 7, CmFile),
  EV_COMMAND_AND_ID(CM_MRU_FIRST + 8, CmFile),
  EV_COMMAND_AND_ID(CM_MRU_FIRST + 9, CmFile),
  EV_COMMAND_ENABLE(CM_EXIT, CeExit),
END_RESPONSE_TABLE;

//
// Constructor to initialize the external storage and the maximum number of
// items to save in the most-recently-used (MRU) list.
//
TRecentFiles::TRecentFiles(const char far* iniName, int numSavedFiles)
:
  AddedSeparator(false),
  LastHMenu(0)
{
  MaxFilesToSave = min(numSavedFiles, (int)MaxMenuItems);
  Profile        = new TProfile(Section, iniName);
  SetMaxMruItems(MaxFilesToSave);
  MruMessage     = ::RegisterWindowMessage(MruFileMessage);
}

//
// Deletes the allocated profile.
//
TRecentFiles::~TRecentFiles()
{
  delete Profile;
}

//
// Sets the maximum number of items that can be saved with this MRU.
//
void
TRecentFiles::SetMaxMruItems(int max)
{
  Profile->WriteInt(CountKey, max);
  Profile->Flush();
}

//
// Respond to a menu item selection
//
void
TRecentFiles::CmFile(uint id)
{
  TApplication* app    = TYPESAFE_DOWNCAST(this, TApplication);
  TFrameWindow* window = app ? app->GetMainWindow() : 0;

  if (window) {
    // Foward menu selection command to specified target
    //
    window->SendMessage(MruMessage, id, 0);
  }
}

//
// Searches the menu to find the position of a menu item.
//
int
TRecentFiles::GetMenuPos(HMENU menu, uint id)
{
  for (int i = ::GetMenuItemCount(menu) - 1; i >= 0; i--)
    if (::GetMenuItemID(menu, i) == id)
      return i;
  return -1;
}

//
// Retrieve the menu position of the CM_EXIT menu item.
// Returns -1 if not found.
//
int
TRecentFiles::GetExitMenuPos(HMENU hMenu)
{
  int exitPos = GetMenuPos(hMenu, CM_EXIT);
  return exitPos;
}

//
// Returns true if the menu has any MRU items in it.
//
bool
TRecentFiles::MruItemsInsertedIntoMenu(HMENU hMenu)
{
  int menuPos = GetMenuPos(hMenu, CM_MRU_FIRST + 0);
  return menuPos != -1;
}

//
// Removes the MRU items from the menu.
//
void
TRecentFiles::RemoveMruItemsFromMenu(HMENU hMenu)
{
  int exitPos = GetExitMenuPos(hMenu);
  if (exitPos > 1)
    if (::GetMenuItemID(hMenu, exitPos - 1) == 0 && AddedSeparator) {
      AddedSeparator = false;
      if (LastHMenu == hMenu)
        ::RemoveMenu(hMenu, exitPos - 1, MF_BYPOSITION);
    }

  // remove MRU items
  //
  if (MruItemsInsertedIntoMenu(hMenu)) {
    for (int i = CM_MRU_FIRST; i < CM_MRU_LAST; i++) {
      int menuPos = GetMenuPos(hMenu, i);
      if (menuPos != -1) {
        ::RemoveMenu(hMenu, i, MF_BYCOMMAND);
      }
    }
  }
}

//
// Reads external information and adds the MRU items into the menu.
// Adds a separator between the MRU items and the exit menu item.
//
void
TRecentFiles::InsertMruItemsToMenu(HMENU hMenu)
{
  TAPointer<char> keyBuffer      = new char[80];
  TAPointer<char> tempBuffer     = new char[MaxMenuItemLen];
  TAPointer<char> menuItemBuffer = new char[MaxMenuItemLen];

  TMenu menu(hMenu);
  int exitPos       = GetExitMenuPos(hMenu);
  int count         = GetMruCount();
  int i;
  int numItemsAdded = 0;

  for (i = 0; i < count; i++) {
    sprintf(keyBuffer, "%s%d", MruPrefix, i);
    tempBuffer[0] = 0;
    Profile->GetString(keyBuffer, tempBuffer, MaxMenuItemLen, MenuItemDefault);

    if (tempBuffer[0] == 0)
      continue;
    if (strcmp(tempBuffer, MenuItemDefault) == 0)    // key not found
      continue;

    numItemsAdded++;
    sprintf(menuItemBuffer, "&%d %s", i + 1, (char*)tempBuffer);
    menu.InsertMenu(exitPos + i, MF_BYPOSITION | MF_STRING, CM_MRU_FIRST + i, menuItemBuffer);
  }

  if (numItemsAdded > 0) {
    if (AddedSeparator == false) {
      LastHMenu = hMenu;
      AddedSeparator = true;
      tempBuffer[0] = 0;
      ::InsertMenu(hMenu, exitPos + numItemsAdded, MF_BYPOSITION | MF_SEPARATOR, 0, tempBuffer);
    }
  }
}

//
// Reads information in the external storage to display the menu choices.
//
void
TRecentFiles::CeExit(TCommandEnabler& ce)
{
  ce.Enable(true);

  TMenuItemEnabler* me = TYPESAFE_DOWNCAST(&ce, TMenuItemEnabler);
  if (me == 0)
    return;

  HMENU hMenu = me->GetMenu();
  RemoveMruItemsFromMenu(hMenu);
  InsertMruItemsToMenu(hMenu);
}

//
// Retrieves the text of the choice based on the id.
//
bool
TRecentFiles::GetMenuText(int id, char far* text, int maxTextLen)
{
  id -= CM_MRU_FIRST;
  int count = GetMruCount();
  if (id < 0 || count <= id)
    return false;
  TAPointer<char> keyBuffer = new char[80];
  sprintf(keyBuffer, "%s%d", MruPrefix, id);
  bool successful = Profile->GetString(keyBuffer, text, maxTextLen);
  return successful;
}

//
// Saves the menu choice into the profile.
//
void
TRecentFiles::SaveMenuChoice(const char far* text)
{
  int index = GetMruItemIndex(text);
  RemoveMruIndex(index);
  AddMruItem(text);
}

//
// Return the number of files that are currently in the MRU list.
//
int
TRecentFiles::GetMruCount()
{
  return Profile->GetInt(CountKey, MaxFilesToSave);
}

//
// Removes the MRU item at index.
// Shuffles the items below index up.
//
void
TRecentFiles::RemoveMruIndex(int index)
{
  int count = GetMruCount();
  if (index < 0 || count <= index)
    return;

  TAPointer<char> srcKeyBuffer = new char[80];
  TAPointer<char> dstKeyBuffer = new char[80];
  TAPointer<char> menuText     = new char[MaxMenuItemLen];

  if (index != count - 1) {
    // shuffle so the item to be deleted is at index count-1
    //
    for (int i = index; i < count - 1; i++) {
      sprintf(srcKeyBuffer, "%s%d", MruPrefix, i + 1);
      Profile->GetString(srcKeyBuffer, menuText, MaxMenuItemLen, MenuItemDefault);
      sprintf(dstKeyBuffer, "%s%d", MruPrefix, i);
      if (strcmp(menuText, MenuItemDefault) == 0)
        menuText[0] = 0;
      Profile->WriteString(dstKeyBuffer, menuText);
    }
  }

  // delete the last item
  //
  sprintf(dstKeyBuffer, "%s%d", MruPrefix, count - 1);
  menuText[0] = 0;
  Profile->WriteString(dstKeyBuffer, menuText);
  Profile->Flush();
}

//
// Adds an item into the top of the MRU list.
// If there is a duplicate, the item is moved from its current position
// to the top of the list.
//
void
TRecentFiles::AddMruItem(const char far* text)
{
  TAPointer<char> srcKeyBuffer = new char[80];
  TAPointer<char> dstKeyBuffer = new char[80];
  TAPointer<char> menuText     = new char[MaxMenuItemLen];

  int count = GetMruCount();

  if (count > 0) {
    // Shuffle items down to make room at index 0
    //
    for (int i = count - 1; i >= 0; i--) {
      sprintf(srcKeyBuffer, "%s%d", MruPrefix, i);
      Profile->GetString(srcKeyBuffer, menuText, MaxMenuItemLen, MenuItemDefault);
      sprintf(dstKeyBuffer, "%s%d", MruPrefix, i + 1);
      if (strcmp(menuText, MenuItemDefault) == 0) {
        menuText[0] = 0;
        continue;
      }
      Profile->WriteString(dstKeyBuffer, menuText);
    }
  }

  // Add item to the top of the list
  //
  sprintf(dstKeyBuffer, "%s%d", MruPrefix, 0);
  Profile->WriteString(dstKeyBuffer, text);
  Profile->Flush();
}

//
// Returns true if there are any items in the MRU list matches the text.
//
bool
TRecentFiles::ExistMruItem(const char far* text)
{
  return GetMruItemIndex(text) != -1;
}

//
// Returns the index of the MRU item containing text.
// Returns -1 if not found.
//
int
TRecentFiles::GetMruItemIndex(const char far* text)
{
  TAPointer<char> srcKeyBuffer = new char[80];
  TAPointer<char> menuText     = new char[MaxMenuItemLen];

  int count = GetMruCount();
  for (int i = 0; i < count; i++) {
    sprintf(srcKeyBuffer, "%s%d", MruPrefix, i);
    Profile->GetString(srcKeyBuffer, menuText, MaxMenuItemLen, MenuItemDefault);
    if (strcmpi(text, menuText) == 0)
      return i;
  }
  return -1;
}
