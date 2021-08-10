//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Implementation of class THelpFileManager & THelpContext
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_HLPMANAG_H)
# include <owl/hlpmanag.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif

OWL_DIAGINFO;

//
// Constructor saves the name of the help file and creates the global
// context table.
//
THelpFileManager::THelpFileManager(const string& helpFileName)
{
  SetHelpFile(helpFileName);
  ContextTable = new TContextList;
}

//
// Deletes the allocated context table.
//
THelpFileManager::~THelpFileManager()
{
  delete ContextTable;
}

//
// Called by EvHelp() to activate the help file with the help context id.
//
void
THelpFileManager::ActivateHelp(TWindow* /*window*/, int helpFileContextId)
{
#if !defined(BI_COMP_MSC)
  TApplication* app = TYPESAFE_DOWNCAST(this, TApplication);
  if (app)
    app->GetMainWindow()->WinHelp(GetHelpFile().c_str(), HELP_CONTEXT, helpFileContextId);
  else
#endif
    ::WinHelp(0, GetHelpFile().c_str(), HELP_CONTEXT, helpFileContextId);
}

//
// Deactivates the help.
//
void
THelpFileManager::DeactivateHelp()
{
#if !defined(BI_COMP_MSC)
  TApplication* app = TYPESAFE_DOWNCAST(this, TApplication);
  if (app)
    app->GetMainWindow()->WinHelp(GetHelpFile().c_str(), HELP_QUIT, 0);
  else
#endif
    ::WinHelp(0, GetHelpFile().c_str(), HELP_QUIT, 0);
}

//
// Changes the name of the help file.
//
void
THelpFileManager::SetHelpFile(const string& helpFileName)
{
  HelpFileName = helpFileName;
}

DEFINE_RESPONSE_TABLE1(THelpFileManager, TEventHandler)
  EV_WM_HELP,
END_RESPONSE_TABLE;

//
// Event handler for the WM_HELP message.
//
void
THelpFileManager::EvHelp(HELPINFO* hi)
{
  THelpContext context;
  bool success = false;

  if (hi) {
    if (hi->iContextType == HELPINFO_MENUITEM)
      success = GetHelpContextFromMenu(context, hi->iCtrlId);
    else if (hi->iContextType == HELPINFO_WINDOW)
      success = GetHelpContextFromControl(context, hi->iCtrlId, (HWND)hi->hItemHandle);
  }

  if (success)
    ActivateHelp(context.GetWindow(), context.GetHelpFileContextId());
}

//
// Return true if the control id is the same as the context entry's control id.
//
static bool
MatchControlId(const THelpContext context, int controlId, HWND hwnd)
{
  if (context.GetControlContextId() == controlId &&
      context.GetWindow() && context.GetWindow()->IsChild(hwnd)) {
    return true;
  }
  return false;
}

//
// Return true if a match for the control id was found.
//
bool
THelpFileManager::GetHelpContextFromControl(THelpContext& context,
                                            int controlId, HWND hwnd) const
{
  // for each item in the context table
  //
  for (TContextListIterator iterator(*ContextTable); iterator; iterator++) {
    context = iterator.Current();

    // try to match the control id
    //
    if (IsIndirectHelpContext(context)) {
      THelpContext* indirect = (THelpContext*)context.GetWindow();
      while (!IsLastIndirectContext(*indirect)) {
        if (MatchControlId(*indirect, controlId, hwnd)) {
          context = *indirect;
          return true;
        }
        indirect++;
      }
    }
    else if (MatchControlId(context, controlId, hwnd))
      return true;
  }
  return false;
}

//
// Return true if the menu item identifier matches a context entry's menu
// item identifier.
//
static bool
MatchMenuId(const THelpContext context, int menuId)
{
  if (context.GetMenuContextId() == menuId) {
    return true;
  }
  return false;
}

//
// Return true if a match for the menu item id was found.
//
bool
THelpFileManager::GetHelpContextFromMenu(THelpContext& context, int menuId) const
{
  // for each item in the context table
  //
  for (TContextListIterator iterator(*ContextTable); iterator; iterator++) {
    context = iterator.Current();

    // try to match the menu item identifier
    //
    if (IsIndirectHelpContext(context)) {
      THelpContext* indirect = (THelpContext*)context.GetWindow();
      while (!IsLastIndirectContext(*indirect)) {
        if (MatchMenuId(*indirect, menuId)) {
          context = *indirect;
          return true;
        }
        indirect++;
      }
    }
    else if (MatchMenuId(context, menuId))
      return true;
  }
  return false;
}

//
// Add an entry into the global context table.
//
void
THelpFileManager::AddContextInfo(TWindow* window, int helpId, int menuId, int controlId)
{
  ContextTable->Add(THelpContext(window, helpId, menuId, controlId));
}

static int
WindowsEqual(const THelpContext& context, void* ptr)
{
  TWindow* targetWindow = (TWindow*)ptr;
  if (context.GetWindow() == targetWindow)
    return 1;
  return 0;
}

//
// Remove all the entries in the context table for the window.
//
void
THelpFileManager::RemoveContextInfo(TWindow* window)
{
  THelpContext* context = ContextTable->FirstThat(WindowsEqual, window);
  while (context != 0) {
    ContextTable->Detach(*context);
    context = ContextTable->FirstThat(WindowsEqual, window);
  }

  if (ContextTable->GetItemsInContainer() == 0) {
    DeactivateHelp();
  }
}

//
// Default constructor that initializes every data member to zero.
//
THelpContext::THelpContext()
:
  HelpFileContextId(0),
  MenuContextId(0),
  ControlContextId(0),
  Window(0)
{
}

//
// Convenient constructor to initialize the context entry with the
// proper ids.
//
THelpContext::THelpContext(TWindow* window, int helpId, int menuId, int controlId)
:
  Window(window),
  HelpFileContextId(helpId),
  MenuContextId(menuId),
  ControlContextId(controlId)
{
}

//
// Make a copy of the context entry.
//
THelpContext::THelpContext(const THelpContext& other)
{
  *this = other;
}

//
// Do nothing.
//
THelpContext::~THelpContext()
{
}

//
// Make a copy of the context entry.
//
THelpContext&
THelpContext::operator =(const THelpContext& other)
{
  HelpFileContextId = other.GetHelpFileContextId();
  MenuContextId     = other.GetMenuContextId();
  ControlContextId  = other.GetControlContextId();
  Window            = other.GetWindow();
  return *this;
}

//
// Return true if the context entries match.
//
int
THelpContext::operator ==(const THelpContext& other) const
{
  return Window == other.GetWindow() &&
         HelpFileContextId == other.GetHelpFileContextId() &&
         MenuContextId == other.GetMenuContextId() &&
         ControlContextId == other.GetControlContextId();
}
