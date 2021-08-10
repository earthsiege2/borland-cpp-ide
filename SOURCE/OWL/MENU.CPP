//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Implementation of Window Menu encapsulation class
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/menu.h>

DIAG_DECLARE_GROUP(OwlWin);        // General window diagnostic group

//
// Construct a menu using CreateMenu()
//
TMenu::TMenu(TAutoDelete autoDelete)
:
  Handle(::CreateMenu()),
  ShouldDelete(autoDelete)
{
  WARNX(OwlWin, !Handle, 0, "Cannot Create Menu");
  CheckValid();
}

//
// Construct a menu as a deep copy of an exisiting menu
//
TMenu::TMenu(const TMenu& original, TAutoDelete autoDelete)
:
  Handle(::CreateMenu()),
  ShouldDelete(autoDelete)
{
  WARNX(OwlWin, !Handle, 0, "Cannot Create Menu for Copy");
  CheckValid();
  DeepCopy(*this, original);
}

//
// Construct a menu as an alias for an existing handle
//
TMenu::TMenu(HMENU handle, TAutoDelete autoDelete)
:
  Handle(handle),
  ShouldDelete(autoDelete)
{
}

//
// Construct a menu alias for a given window's menu
//
TMenu::TMenu(HWND hWnd, TAutoDelete autoDelete)
:
  Handle(::GetMenu(hWnd)),
  ShouldDelete(autoDelete)
{
  PRECONDITION(hWnd);
  WARNX(OwlWin, !Handle, 0, "Cannot Get Menu from " << hex << (uint)hWnd);
  CheckValid();
}

//
// Construct a menu from a menu template struct
//
TMenu::TMenu(const void far* menuTemplate)
{
  PRECONDITION(menuTemplate);
  Handle = ::LoadMenuIndirect(menuTemplate);
  WARNX(OwlWin, !Handle, 0, "Cannot Load Menu Indirect " << hex <<
        uint32(menuTemplate));
  CheckValid();
  ShouldDelete = true;
}

//
// Construct a menu by loading it from resource
//
TMenu::TMenu(HINSTANCE resInstance, TResId resId)
{
  PRECONDITION(resInstance && resId);
  Handle = ::LoadMenu(resInstance, resId);
  WARNX(OwlWin, !Handle, 0, "Cannot Load Menu " << hex << (uint)resInstance <<
                            " " << resId);
  CheckValid();
  ShouldDelete = true;
}

//
// Copy an existing menu onto this menu, using DeepCopy
//
TMenu&
TMenu::operator =(const TMenu& original)
{
  // Delete all items and submenus
  // Look at possible alternatives for !ShouldDelete menus? Maybe use Remove
  // then?
  //
  while (GetMenuItemCount())
    DeleteMenu(0, MF_BYPOSITION);
  DeepCopy(*this, original);
  return *this;
}

//
// Destruct the menu by destroying the handle if appropriate.
//
TMenu::~TMenu()
{
  if (ShouldDelete && Handle)
    ::DestroyMenu(Handle);
}

//
// Get the menu ID. If it's a regular menu item just returns its id.
// Otherwise if it's a popup menu use id of the first item in the popup menu.
//
uint
TMenu::GetMenuItemID(int pos) const
{
  uint  id = ::GetMenuItemID(Handle, pos);
  if (id != uint(-1))
    return id;

  // Maybe a submenu
  //
  TMenu subMenu(GetSubMenu(pos));
  if (subMenu.Handle == 0)
    return 0;

  return subMenu.GetMenuItemID(0) - 1;
}

#pragma warn -par  // resId param is never used in small model
void
TMenu::CheckValid(uint resId)
{
  if (!Handle)
    THROW( TXMenu(resId) );
}
#pragma warn .par

void
TMenu::MeasureItem(MEASUREITEMSTRUCT far&)
{
}

void
TMenu::DrawItem(DRAWITEMSTRUCT far&)
{
}

//
// Deep copy 'count' popup-menus or items from 'src' _appending_ to 'dst'
// menu starting at 'offset' position in this menu
//
void
TMenu::DeepCopy(TMenu& dst, const TMenu& src, int srcOff, int count)
{
  if (count < 0)
    count = src.GetMenuItemCount() - srcOff;

  for (int i = 0; i < count; i++) {
    uint  state = src.GetMenuState(srcOff+i, MF_BYPOSITION);
    if (state == uint(-1))
      return;

    char   str[256];
    src.GetMenuString(srcOff+i, str, sizeof(str), MF_BYPOSITION);

    // Currently does NOT support MF_BITMAP or MF_OWNERDRAW
    //
    if (state & MF_POPUP) {
      state &= (MF_STRING | MF_POPUP);  // strip off breaks, separators, etc
      TMenu subMenu(src.GetSubMenu(srcOff+i));
      TMenu newSubMenu(NoAutoDelete);
      DeepCopy(newSubMenu, subMenu);
      dst.AppendMenu(state, newSubMenu, str);
    }
    else {
      dst.AppendMenu(state, src.GetMenuItemID(srcOff+i), str);
    }
  }
}

//
// Deep copy 'count' popup-menus or items from 'src' to 'dst' menu
// starting at 'srcOff' position in src and inserting at 'dstOff' in the
// destination
//
void
TMenu::DeepCopy(TMenu& dst, int dstOff, const TMenu& src, int srcOff, int count)
{
  if (count < 0)
    count = src.GetMenuItemCount() - srcOff;

  for (int i = 0; i < count; i++) {
    uint  state = src.GetMenuState(srcOff+i, MF_BYPOSITION);
    if (state == uint(-1))
      return;

    char   str[256];
    src.GetMenuString(srcOff+i, str, sizeof(str), MF_BYPOSITION);

    // Currently does NOT support MF_BITMAP or MF_OWNERDRAW
    //
    if (state & MF_POPUP) {
      state &= (MF_STRING | MF_POPUP);  // strip off breaks, separators, etc
      TMenu subMenu(src.GetSubMenu(srcOff+i));
      TMenu newSubMenu(NoAutoDelete);
      DeepCopy(newSubMenu, subMenu);
      if (dstOff >= 0)
        dst.InsertMenu(dstOff, state|MF_BYPOSITION, newSubMenu, str);
      else
        dst.AppendMenu(state, newSubMenu, str);
    }
    else {
      if (dstOff >= 0)
        dst.InsertMenu(dstOff, state|MF_BYPOSITION, src.GetMenuItemID(srcOff+i), str);
      else
        dst.AppendMenu(state, src.GetMenuItemID(srcOff+i), str);
    }
  }
}

TSystemMenu::TSystemMenu(HWND wnd, bool revert)
:
  TMenu(::GetSystemMenu(wnd, revert), NoAutoDelete)
{
}

TPopupMenu::TPopupMenu(TAutoDelete autoDelete)
:
  TMenu(::CreatePopupMenu(), autoDelete)
{
}

TPopupMenu::TPopupMenu(HMENU handle, TAutoDelete autoDelete)
:
  TMenu(handle, autoDelete)
{
}

TMenu::TXMenu::TXMenu(unsigned resId) : TXOwl(resId)
{
}

TXOwl*
TMenu::TXMenu::Clone()
{
  return new TXMenu(*this);
}

void
TMenu::TXMenu::Throw()
{
  THROW( *this );
}
