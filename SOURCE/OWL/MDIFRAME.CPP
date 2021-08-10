//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\mdiframe.cpp
//   Implementation of class TMDIFrame.  This defines the basic behavior of
//   all MDI frame windows.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\mdi.h>

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TMDIFrame, TFrameWindow)
END_RESPONSE_TABLE;

//
// constructor for a TMDIFrame
//
TMDIFrame::TMDIFrame(const char far* title,
                     TResId          menuResId,
                     TMDIClient&     clientWnd,
                     TModule*        module)
{
  //
  // Initialize virtual bases, in case the derived-most used default ctor
  //
  TWindow::Init(0, title, module);
  TFrameWindow::Init(&clientWnd, FALSE);

  if (menuResId)
    AssignMenu(menuResId);
}

//
// constructor for a TMDIFrame which is being used as an alias for a
// non-OWL window
//
TMDIFrame::TMDIFrame(HWND       hWnd,
                     HWND       clientHWnd,
                     TModule*   module)
  : TFrameWindow(hWnd, module),
    TWindow(hWnd, module)
{
  CHECK(::GetParent(clientHWnd) == hWnd);

  //
  // NOTE: Attr.Menu set in TWindow's constructor
  //
  ClientWnd = new TMDIClient(clientHWnd);
  ClientWnd->Parent = this;
}

//
//	an MDI frame must have a menu.  Give it an empty one if none supplied.
//
void
TMDIFrame::PerformCreate(int menuOrId)
{
  TFrameWindow::PerformCreate(menuOrId ? menuOrId : (int)::CreateMenu());
}

//
// look for the MDI submenu in a menubar by looking for the normal
// MDI commands, and return pos if found. Scan from right to
// left since the Window menu is usually near the right.
//
HMENU
TMDIFrame::FindChildMenu(HMENU menu)
{
  if (menu) {
    int   numItems = ::GetMenuItemCount(menu);
    for (int i = numItems-1; i >= 0; i--) {
      HMENU childMenu = ::GetSubMenu(menu, i);
      if (childMenu &&
          ::GetMenuState(childMenu, CM_CASCADECHILDREN, MF_BYCOMMAND) != (UINT)-1 ||
          ::GetMenuState(childMenu, CM_TILECHILDREN, MF_BYCOMMAND) != (UINT)-1 ||
          ::GetMenuState(childMenu, CM_ARRANGEICONS, MF_BYCOMMAND) != (UINT)-1) {
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
BOOL
TMDIFrame::SetMenu(HMENU newMenu)
{
  PRECONDITION(newMenu);

  HMENU childMenu = FindChildMenu(newMenu);

  if (HWindow) {
    #if defined(__WIN32__)
      HMENU oldMenu = (HMENU)ClientWnd->HandleMessage(WM_MDISETMENU,
                                                      (WPARAM)newMenu,
                                                      (LPARAM)childMenu);
    #else
      HMENU oldMenu = (HMENU)ClientWnd->HandleMessage(WM_MDISETMENU,
                                                      FALSE,
                                                      MAKELPARAM(newMenu, childMenu));
    #endif
    DrawMenuBar();
    if (!oldMenu)
      return FALSE;
  }
  return TRUE;
}

TMDIClient*
TMDIFrame::GetClientWindow()
{
  return TYPESAFE_DOWNCAST(ClientWnd,TMDIClient);
}

//
// override TWindow method and call ::DefFrameProc() instead of
// ::DefWindowProc()
//
LRESULT
TMDIFrame::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
  return ::DefFrameProc(HWindow, ClientWnd ? ClientWnd->HWindow : 0,
                        message, wParam, lParam);
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE2(TMDIFrame, TFrameWindow, TWindow);

//
// reads an instance of TMDIFrame from the passed ipstream
//
void*
TMDIFrame::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadVirtualBase((TFrameWindow*)GetObject(), is);
  GetObject()->AssignMenu(GetObject()->Attr.Menu);
  return GetObject();
}

//
// writes the TMDIFrame to the passed opstream
//
void
TMDIFrame::Streamer::Write(opstream& os) const
{
  WriteVirtualBase((TFrameWindow*)GetObject(), os);
}

#endif
