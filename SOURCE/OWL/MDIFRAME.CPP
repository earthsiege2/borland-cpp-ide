//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Implementation of class TMDIFrame.  This defines the basic behavior of
// all MDI frame windows.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_MDI_H)
# include <owl/mdi.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif

DIAG_DECLARE_GROUP(OwlCmd);

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TMDIFrame, TFrameWindow)
END_RESPONSE_TABLE;

//
// Constructor for a TMDIFrame
//
TMDIFrame::TMDIFrame(const char far* title,
                     TResId          menuResId,
                     TMDIClient&     clientWnd,
                     TModule*        module)
{
  // Initialize virtual bases, in case the derived-most used default ctor
  //
  TWindow::Init(0, title, module);
  TFrameWindow::Init(&clientWnd, false);

  if (menuResId)
    AssignMenu(menuResId);
}

//
// Constructor for a TMDIFrame which is being used as an alias for a
// non-OWL window
//
TMDIFrame::TMDIFrame(THandle    handle,
                     THandle    clientHandle,
                     TModule*   module)
:
  TFrameWindow(handle, module),
  TWindow(handle, module)
{
  CHECK(::GetParent(clientHandle) == handle);

  // NOTE: Attr.Menu set in TWindow's constructor
  //
  ClientWnd = new TMDIClient(clientHandle);
  ClientWnd->Parent = this;
}

//
// An MDI frame must have a menu.  Give it an empty one if none supplied.
//
void
TMDIFrame::PerformCreate(int menuOrId)
{
  TFrameWindow::PerformCreate(menuOrId ? menuOrId : (int)::CreateMenu());
}

//
// Look for the MDI submenu in a menubar by looking for the normal MDI
// commands, and return pos if found. Scan from right to left since the Window
// menu is usually near the right.
//
HMENU
TMDIFrame::FindChildMenu(HMENU menu)
{
  if (menu) {
    int   numItems = ::GetMenuItemCount(menu);
    for (int i = numItems-1; i >= 0; i--) {
      HMENU childMenu = ::GetSubMenu(menu, i);
      if (childMenu &&
          (TUser::GetMenuState(childMenu, CM_CASCADECHILDREN, MF_BYCOMMAND) != (uint)-1 ||
           TUser::GetMenuState(childMenu, CM_TILECHILDREN, MF_BYCOMMAND) != (uint)-1 ||
           TUser::GetMenuState(childMenu, CM_ARRANGEICONS, MF_BYCOMMAND) != (uint)-1)) {
        return childMenu;
      }
    }
  }
  return 0;
}

//
// MDI specific version of SetMenu uses WM_MDISETMENU to set a new
// menu bar and childMenu within it.
//
bool
TMDIFrame::SetMenu(HMENU newMenu)
{
  PRECONDITION(newMenu);

  if (IsFlagSet(wfMainWindow))
    GetApplication()->PreProcessMenu(newMenu);

  if (GetHandle()) {
    HMENU childMenu = FindChildMenu(newMenu);
#if defined(BI_PLAT_WIN32)
    HMENU oldMenu = (HMENU)ClientWnd->HandleMessage(WM_MDISETMENU,
                                                    TParam1(newMenu),
                                                    TParam2(childMenu));
#else
    HMENU oldMenu = (HMENU)ClientWnd->HandleMessage(WM_MDISETMENU,
                                                    false,
                                                    MkParam2(newMenu, childMenu));
#endif
    DrawMenuBar();
    if (!oldMenu)
      return false;
  }
  return true;
}

//
// Return the client window of this MDI frame.
//
#if !defined(BI_NO_COVAR_RET)
TMDIClient*
TMDIFrame::GetClientWindow()
{
  return TYPESAFE_DOWNCAST(ClientWnd,TMDIClient);
}
#else
TWindow*
TMDIFrame::GetClientWindow()
{
  return ClientWnd;
}
#endif

//
// Locate and return the child window that is the target of command and command
// enable messages. Pass this to our active mdi child, if any, to let it
// locate its active command target.
//
TWindow::THandle
TMDIFrame::GetCommandTarget()
{
#if !defined(BI_NO_COVAR_RET)
  TFrameWindow* mdiChild = GetClientWindow()->GetActiveMDIChild();
#else
  TFrameWindow* mdiChild = TYPESAFE_DOWNCAST(GetClientWindow(),TMDIClient)->
                             GetActiveMDIChild();
#endif

  TRACEX(OwlCmd, 1, "TMDIFrame::GetCommandTarget - returns " << \
                    (mdiChild ? "ActiveMDIChild->GetCommandTarget()" \
                              : "TFrameWindow::GetCommandTarget()"));

  return mdiChild ? mdiChild->GetCommandTarget() : TFrameWindow::GetCommandTarget();
}

//
// Override TWindow method and call ::DefFrameProc() instead of
// ::DefWindowProc()
//
TResult
TMDIFrame::DefWindowProc(uint message, TParam1 param1, TParam2 param2)
{
  return ::DefFrameProc(GetHandle(), ClientWnd ? ClientWnd->GetHandle() : 0,
                        message, param1, param2);
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE2(TMDIFrame, TFrameWindow, TWindow);

#if !defined(BI_NO_OBJ_STREAMING)

//
// Reads an instance of TMDIFrame from the passed ipstream
//
void*
TMDIFrame::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadVirtualBase((TFrameWindow*)GetObject(), is);
  GetObject()->AssignMenu(GetObject()->Attr.Menu);
  return GetObject();
}

//
// Writes the TMDIFrame to the passed opstream
//
void
TMDIFrame::Streamer::Write(opstream& os) const
{
  WriteVirtualBase((TFrameWindow*)GetObject(), os);
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
