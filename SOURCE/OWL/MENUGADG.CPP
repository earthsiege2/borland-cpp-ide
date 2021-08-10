//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Defines TMenuGadget
//
// A TMenuGadget is a text gadget that when pressed, it acts as a popup menu.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_MENUGADG_H)
# include <owl/menugadg.h>
#endif

OWL_DIAGINFO;

const int MaxMenuTextLen = 512;

//
// Create the popup menu and initialize the text gadget.
//
TMenuGadget::TMenuGadget(TMenu& menu, TWindow* window, int id,
                         TBorderStyle borderStyle, char far* text, TFont* font)
:
  TTextGadget(id, borderStyle, TTextGadget::Left, 15, text, font),
  CmdTarget(window)
{
  SetShrinkWrap(true, true);
  PopupMenu = new TPopupMenu(menu);

  // initialize Text data member
  //
  char menuText[MaxMenuTextLen];
  if (PopupMenu->GetMenuString(0, menuText, MaxMenuTextLen, MF_BYPOSITION))
    SetText(menuText);
}

//
// Delete the allocated popup menu.
//
TMenuGadget::~TMenuGadget()
{
  delete PopupMenu;
}

//
// Popup menu on lbuttondown
//
void
TMenuGadget::LButtonDown(uint modKeys, TPoint& p)
{
  TGadget::LButtonDown(modKeys, p);
  TRect rect = GetBounds();
//  GetInnerRect(rect);
  TPoint p2(rect.TopLeft());
  Window->ClientToScreen(p2);
  PopupMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, p2, 0, *CmdTarget);
}
