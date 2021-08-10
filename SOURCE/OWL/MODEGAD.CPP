//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Defines TModeGadget.
//
// A mode gadget is a gadget that displays the mode of a key.
// The key code is defined as VK_XXXX in Windows.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_MODEGAD_H)
# include <owl/modegad.h>
#endif

OWL_DIAGINFO;

//
// Initialize the text gadget with text key's text.
//
TModeGadget::TModeGadget(int vkKey, const char far* text, int id,
  TBorderStyle border, TAlign align, TFont* font)
:
  TTextGadget(id, border, align, 10, text, font), VkKey(vkKey)
{
  SetShrinkWrap(true, true);
}

//
// Override from TGadget to update the state of the key.
//
bool
TModeGadget::IdleAction(long count)
{
  TTextGadget::IdleAction(count);
  int state = ::GetKeyState(VkKey);

  // Toggle keys
  //
  if (VkKey == VK_SCROLL || VkKey == VK_INSERT ||
      VkKey == VK_NUMLOCK || VkKey == VK_CAPITAL) {
    if (state & 1)
      SetEnabled(true);
    else
      SetEnabled(false);
  }
  else {
    // This is a regular key, highlite only when pressed
    //
    if (state & (1 << (sizeof(int) * 8 - 1)))
      SetEnabled(true);
    else
      SetEnabled(false);
  }
  return false;
}

