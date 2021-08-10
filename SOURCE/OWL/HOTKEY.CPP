//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_HOTKEY_H)
# include <owl/hotkey.h>
#endif
#if !defined(WINSYS_SYSTEM_H)
# include <winsys/system.h>
#endif

OWL_DIAGINFO;

//
// Constructors for THotKey
//
// Initialize data fields using parameters passed and default values
//
// By default, a Hotkey control associated with the TColumnHeader will:
//   - be visible upon creation
//   - have a border
//
THotKey::THotKey(TWindow*   parent,
                 int        id,
                 int x, int y, int w, int h,
                 TModule*   module)
:
  TControl(parent, id, 0, x, y, w, h, module)
{
  if (!TCommCtrl::IsAvailable())
    throw TXCommCtrl();
#if defined(BI_PLAT_WIN32)
  if (TSystem::IsNT())
    Attr.Style |= WS_BORDER;
#endif
}

//
// Construct a hot key control from resource
//
THotKey::THotKey(TWindow*   parent,
                 int        resourceId,
                 TModule*   module)
:
  TControl(parent, resourceId, module)
{
  if (!TCommCtrl::IsAvailable())
    throw TXCommCtrl();
}

//
// Return the class name for a hot key control
//
char far*
THotKey::GetClassName()
{
  return HOTKEY_CLASS;
}

//
// Transfer a uint16 (the virtual key code) for the control.
//
uint
THotKey::Transfer(void* buffer, TTransferDirection direction)
{
  if (direction == tdGetData)
    *((uint16*)buffer) = GetHotKey();
  else if (direction == tdSetData)
    SetHotKey(*((uint16*)buffer));

  return sizeof(uint16);
}

//
// Returns the 16-bit virtual key code for the control.
//
uint16
THotKey::GetHotKey()
{
  return LoUint16(SendMessage(HKM_GETHOTKEY));
}

//
// Sets the virtual key code and modifier flags for the hot key.
// See the Windows API for more details on VK_xxxx and modifier flags.
//
void
THotKey::SetHotKey(uint16 hotKey)
{
  SendMessage(HKM_SETHOTKEY, TParam1(hotKey));
}

//
// Sets the virtual key code and modifier flags for the hot key.
//
void
THotKey::SetHotKey(uint8 vk, uint8 mods)
{
  SetHotKey(MkUint16(vk, mods));
}

//
// Sets the invalid key combinations for the hotkey control.
//
void
THotKey::SetRules(uint16 invalid, uint16 defFlag)
{
  SendMessage(HKM_SETRULES, TParam1(invalid), MkParam2(defFlag, 0));
}
