//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.9  $
//
// Implementation of classes TMenu and TXMenu, Window Menu encapsulation class
// and its associated exception
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_MENU_H)
# include <owl/menu.h>
#endif
#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif

DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlMenu, 1, 0); // diag. group for menus
DIAG_DECLARE_GROUP(OwlWin);                     // diag. group for windows

#if defined(BI_PLAT_WIN32)
//
//
//
TMenuItemInfo::TMenuItemInfo(uint msk)
{
  memset(LPMENUITEMINFO(this), 0, sizeof(MENUITEMINFO));
  cbSize = sizeof(MENUITEMINFO);
  fMask = msk;
}

//
//
//
TMenuItemInfo::TMenuItemInfo(TMenu& menu, uint posOrId, bool isPos, uint msk)
{
  PRECONDITION(menu.GetHandle());
  memset(LPMENUITEMINFO(this), 0, sizeof(MENUITEMINFO));
  cbSize = sizeof(MENUITEMINFO);
  fMask = msk;
  menu.GetMenuItemInfo(posOrId, isPos ? TRUE : FALSE, *this);
}

//
//
//
TMenuItemInfo::TMenuItemInfo(TMenu& menu, uint posOrId, bool isPos, 
                             void* buffer, uint size, uint msk)
{
  PRECONDITION(menu.GetHandle());
  memset(LPMENUITEMINFO(this), 0, sizeof(MENUITEMINFO));
  cbSize = sizeof(MENUITEMINFO);
  fMask = msk;
  dwTypeData = LPTSTR(buffer);
  cch = size;
  menu.GetMenuItemInfo(posOrId, isPos ? TRUE : FALSE, *this);
}

#endif

//
// Construct a menu using CreateMenu()
//
TMenu::TMenu(TAutoDelete autoDelete)
:
  Handle(::CreateMenu()),
  ShouldDelete(autoDelete)
{
  WARNX(OwlMenu, !Handle, 0, "Cannot Create Menu");
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
  WARNX(OwlMenu, !Handle, 0, "Cannot Create Menu for Copy");
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
  WARNX(OwlMenu, !Handle, 0, "Cannot Get Menu from " << hex << (uint)hWnd);
  CheckValid();
}

//
// Construct a menu from a menu template struct
//
TMenu::TMenu(const void far* menuTemplate)
{
  PRECONDITION(menuTemplate);
  Handle = ::LoadMenuIndirect(menuTemplate);
  WARNX(OwlMenu, !Handle, 0, "Cannot Load Menu Indirect " << hex <<\
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
  WARNX(OwlMenu, !Handle, 0, "Cannot Load Menu " << hex << (uint)resInstance <<\
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
// If it's a popup menu, first attempt to retrieve a user-specified Id
// via the MENUITEMINFO structure (32-bit only). Otherwise, use the Id of 
// first menuitem minus 1.
//
uint
TMenu::GetMenuItemID(int pos) const
{
  // Retrieve identifier
  //
  uint  id = ::GetMenuItemID(Handle, pos);
  if (id != uint(-1)) {
    TRACEX(OwlWin, 1, "GetMenuItemID at pos. " << pos << '=' <<  id);
    return id;
  }

  // Skip separators 
  //
  uint state = GetMenuState(pos, MF_BYPOSITION);
  if (state & MF_SEPARATOR) {
    TRACEX(OwlWin, 1, "MenuItem at " << pos << "is a separator, id=0");
    return 0;
  }

  // Try to retrieve a pop-up menu handle
  //
  HMENU popup = GetSubMenu(pos);
  if (popup) {
    TMenu subMenu(popup);

    // Here could try to retrieve the 'true' id of the popup if the user 
    // provided one before proceeding with the 'Id of firt Item -1' OWL 
    // enhancement. Need more information about MENUITEMINFO etc. 
    // !!

    // Recurse within sub menu to retrieve popup Id.
    //
    id = subMenu.GetMenuItemID(0) - 1;
    TRACEX(OwlWin, 1, "TMenu::GetMenuItemID - returns faked [Id of first "\
                       "menu item - 1, id=" << dec << id);
    return id;
  }
  TRACEX(OwlWin, 1, "TMenu::GetMenuItemID - unable to determine id - "\
                     "returns 0");
  return 0;
}

#pragma warn -par  // resId param is never used in small model
//
//
//
void
TMenu::CheckValid(uint resId)
{
  if (!Handle)
    TXMenu::Raise(resId);
}
#pragma warn .par

//
//
//
void
TMenu::MeasureItem(MEASUREITEMSTRUCT far&)
{
}

//
//
//
void
TMenu::DrawItem(DRAWITEMSTRUCT far&)
{
}

//
//
//
uint        
TMenu::GetDefaultItem(bool getPos, uint flags) const
{
  PRECONDITION(Handle);
#if defined(BI_PLAT_WIN16)
  //
  // For 16-bit applications, this API is only available when running
  // under Win95. So we'll attempt to retrieve the proc. address from USER
  //
  typedef BOOL (WINAPI *FP)(HMENU, UINT, UINT);

  static FP fp = 0;
  static bool getProc = false;
  if (!getProc && !fp) {
    fp = (FP)GetProcAddress(GetModuleHandle("USER"), "GetMenuDefaultItem");
    getProc = true;
  }
  if (fp)
    return fp(Handle, getPos ? TRUE : FALSE, flags) != FALSE;
  return uint(-1);

#elif defined(BI_PLAT_WIN32)
  return ::GetMenuDefaultItem(Handle, getPos ? TRUE : FALSE, flags);
#endif 
}

//
//
//
bool        
TMenu::SetDefaultItem(uint posOrId, bool isPos)
{
  PRECONDITION(Handle);
#if defined(BI_PLAT_WIN16)
  //
  // For 16-bit applications, this API is only available when running
  // under Win95. So we'll attempt to retrieve the proc. address from USER
  //
  typedef BOOL (WINAPI *FP)(HMENU, UINT, UINT);

  static FP fp = 0;
  static bool getProc = false;
  if (!getProc && !fp) {
    fp = (FP)GetProcAddress(GetModuleHandle("USER"), "SetMenuDefaultItem");
    getProc = true;
  }
  if (fp)
    return fp(Handle, posOrId, isPos ? TRUE : FALSE) != FALSE;
  return false;

#elif defined(BI_PLAT_WIN32)
  PRECONDITION(Handle);
  return ::SetMenuDefaultItem(Handle, posOrId, isPos ? TRUE : FALSE);
#endif 
}

//
//
//
bool        
TMenu::CheckRadioItem(uint first, uint last, uint check, uint flags)
{
#if   defined(BI_PLAT_WIN16)
  // Emulate routine using pre-Win95 API
  //
  for (uint i = first; i <= last; i++)
    CheckMenuItem(i, flags|(i == check ? MF_CHECKED : MF_UNCHECKED));
  return true;
#elif defined(BI_PLAT_WIN32)
  PRECONDITION(Handle);
  return ::CheckMenuRadioItem(Handle, first, last, check, flags) != FALSE;
#endif 
}

#if defined(BI_PLAT_WIN32)
//
//
//
bool        
TMenu::GetMenuItemInfo(uint posOrId, bool isPos, TMenuItemInfo& mi) const
{
  PRECONDITION(Handle);
  return ::GetMenuItemInfo(Handle, posOrId, isPos ? TRUE : FALSE, &mi) != FALSE;
}

//
//
//
bool        
TMenu::SetMenuItemInfo(uint posOrId, bool isPos, TMenuItemInfo& mi)
{
  PRECONDITION(Handle);
  return ::SetMenuItemInfo(Handle, posOrId, isPos ? TRUE : FALSE, &mi) != FALSE;
}

//
//
//
bool        
TMenu::InsertMenuItem(uint posOrId, bool isPos, TMenuItemInfo& mi)
{
  PRECONDITION(Handle);
  return ::InsertMenuItem(Handle, posOrId, isPos ? TRUE : FALSE, &mi) != FALSE;
}
#endif

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

    char str[256];
    TUser::GetMenuString(src, srcOff+i, str, sizeof(str), MF_BYPOSITION);

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

//----------------------------------------------------------------------------

//
// Create a system menu wrapper for the given window.
//
TSystemMenu::TSystemMenu(HWND hWnd, bool revert)
:
  TMenu(::GetSystemMenu(hWnd, revert), NoAutoDelete)
{
}

//----------------------------------------------------------------------------

//
// Create an empty popup menu.
//
TPopupMenu::TPopupMenu(TAutoDelete autoDelete)
:
  TMenu(::CreatePopupMenu(), autoDelete)
{
}

//
// Create a popup menu based on an existing popup menu.
//
TPopupMenu::TPopupMenu(HMENU handle, TAutoDelete autoDelete)
:
  TMenu(handle, autoDelete)
{
}

//
// Create a popup menu from an existing menu.
//
TPopupMenu::TPopupMenu(TMenu& menu, TAutoDelete autoDelete)
:
  TMenu(::CreatePopupMenu(), autoDelete)
{
  DeepCopy(*this, menu);
}

//----------------------------------------------------------------------------

//
// Create a TXMenu exception with the resID of the string resource.
//
TXMenu::TXMenu(uint resId)
:
  TXOwl(resId)
{
}


//
// Create a copy of the TXMenu exception.
// It will be rethrown at a safer time.
//
#if defined(BI_NO_COVAR_RET)
TXBase*
#else
TXMenu*
#endif
TXMenu::Clone()
{
  return new TXMenu(*this);
}

//
// Throw the exception.
//
void
TXMenu::Throw()
{
  THROW( *this );
}

//
// Create a TXMenu exception and throw it.
//
void
TXMenu::Raise(uint resId)
{
  TXMenu(resId).Throw();
}
