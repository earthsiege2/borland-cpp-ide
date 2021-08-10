//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Implements TCheckList and TCheckListItem
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/checklst.h>
#include <owl/commctrl.h>
#include <owl/uihelper.h>
#include <string.h>

DIAG_DECLARE_GROUP(OwlControl);

const int CheckBoxWidth = 15;

//
// Constructor to create a window.
//
TCheckList::TCheckList(TWindow* parent, int id, int x, int y, int w, int h,
                       TCheckListItem* items, int numItems,
                       TModule* module)
:
  TListBox(parent, id, x, y, w, h, module),
  Items(items),
  NumberOfItems(numItems)
{
  Attr.Style |= LBS_NOTIFY | LBS_OWNERDRAWVARIABLE | LBS_NOINTEGRALHEIGHT;
  Attr.Style &= ~LBS_HASSTRINGS;
  Attr.Style &= ~LBS_SORT;
  TRACEX(OwlControl, OWL_CDLEVEL, "TCheckList constructed @" << (void*)this);
}

//
// Constructor used for resources
//
TCheckList::TCheckList(TWindow* parent, int resourceId,
                       TCheckListItem* items, int numItems,
                       TModule* module)
:
  TListBox(parent, resourceId, module),
  Items(items),
  NumberOfItems(numItems)
{
  TRACEX(OwlControl, OWL_CDLEVEL, "TCheckList constructed from resource @" << (void*)this);
}

//
//
//
TCheckList::~TCheckList()
{
  TRACEX(OwlControl, OWL_CDLEVEL, "TCheckList destructed @" << (void*)this);
}

DEFINE_RESPONSE_TABLE1(TCheckList, TListBox)
  EV_WM_LBUTTONDOWN,
  EV_WM_CHAR,
END_RESPONSE_TABLE;

//
// Toggle the "checked" state when the space is pressed.
//
void
TCheckList::EvChar(uint key, uint repeatCount, uint flags)
{
  TCheckListItem* item = GetItemAtIndex(GetCaretIndex());

  if (item) {
    if (key == ' ') {
      item->Toggle();
      Update();
    }
  }
  TListBox::EvChar(key, repeatCount, flags);
}

//
// Toggle the "checked" state when the mouse is clicked in the checkbox.
//
void
TCheckList::EvLButtonDown(uint modKeys, TPoint& point)
{
  TListBox::EvLButtonDown(modKeys, point);
  TCheckListItem* item = GetItemAtIndex(GetCaretIndex());
  if (point.x < CheckBoxWidth) {
    item->Toggle();
    Update();
  }
}

//
// Add the strings into the listbox.
//
void
TCheckList::SetupWindow()
{
  TRACEX(OwlControl, 1, "TCheckList::SetupWindow() @" << (void*)this);

  // Call the base class
  //
  TListBox::SetupWindow();
  for (int i = 0; i < NumberOfItems; i++)
    AddString((char far*) &Items[i]);
}

//
// Refresh the window.
//
void
TCheckList::Update()
{
  int topIndex = GetTopIndex();
  int selIndex = GetSelIndex();
  SendMessage(WM_SETREDRAW, false);
  Invalidate();
  SetTopIndex(topIndex);
  if (selIndex != LB_ERR)
    SetSelIndex(selIndex);
  SendMessage(WM_SETREDRAW, true);
}

//
// Repaint the item entirely.
//
void
TCheckList::ODAFocus(DRAWITEMSTRUCT far& drawInfo)
{
  PaintItem(drawInfo);
}

//
// Repaint the item entirely.
//
void
TCheckList::ODASelect(DRAWITEMSTRUCT far& drawInfo)
{
  PaintItem(drawInfo);
}

//
// Repaint the item entirely.
//
void
TCheckList::ODADrawEntire(DRAWITEMSTRUCT far& drawInfo)
{
  PaintItem(drawInfo);
}

//
// Paint the item entirely.
//
void
TCheckList::PaintItem(DRAWITEMSTRUCT far& drawInfo)
{
  TCheckListItem* item = GetItemAtIndex(drawInfo.itemID);
  if (item == 0)
    return;

  // Prepare DC
  //
  TDC dc(drawInfo.hDC);

  // Erase entire line
  //
  TRect rect(drawInfo.rcItem);
  TBrush bkgnd(TColor::SysWindow);
  dc.FillRect(rect, bkgnd);

  // Draw checkbox
  //
  TRect checkboxRect(rect.left + 1, rect.top + 1, rect.left + CheckBoxWidth, rect.bottom - 1);
  dc.Rectangle(checkboxRect);

  if (item->IsIndeterminate()) {
    TRect fillRect = checkboxRect;
    fillRect.Inflate(-1, -1);
    TBrush fillBrush(TColor::Sys3dFace);
    dc.FillRect(fillRect, fillBrush);
  }

  // Draw check if needed
  //
  if (item->IsChecked() || item->IsIndeterminate()) {
    int cx = (checkboxRect.right - checkboxRect.left) / 2 + checkboxRect.left ;
    int cy = (checkboxRect.bottom - checkboxRect.top) / 2 + checkboxRect.top + 2;

    TPen checkPen(TColor::Black, 2);
    dc.SelectObject(checkPen);

    dc.MoveTo(cx, cy);
    dc.LineTo(cx - 3, cy - 3);
    dc.MoveTo(cx, cy);
    dc.LineTo(checkboxRect.right - 2, checkboxRect.top + 2);

    dc.RestorePen();
  }

  // Draw Text
  //
  TRect textRect = rect;
  textRect.left = checkboxRect.right + 2;

  dc.DrawText(item->Text, -1, textRect, DT_SINGLELINE | DT_VCENTER);

  // Draw focus and selected states
  //
  if (drawInfo.itemState & ODS_FOCUS)
    dc.DrawFocusRect(textRect);

  if (drawInfo.itemState & ODS_SELECTED)
    dc.InvertRect(textRect);
}

//
// Return the item at the specified index.
//
TCheckListItem*
TCheckList::GetItemAtIndex(int index)
{
  if (index < 0 || index >= GetCount())
    return 0;
  return (TCheckListItem*)GetItemData(index);
}


//----------------------------------------------------------------------------
// TCheckListItem
//

//
// Initialize the state of TCheckListItem.
//
TCheckListItem::TCheckListItem()
:
  State(BF_UNCHECKED),
  HasThreeStates(false),
  Text(0)
{
}

//
// Construct the object with a text string and a starting state.
//
TCheckListItem::TCheckListItem(const char far* text, uint state)
:
  HasThreeStates(ToBool(state == BF_GRAYED)),
  State(state)
{
  SetText(text);
}

//
// Delete the allocated copied text.
//
TCheckListItem::~TCheckListItem()
{
  delete[] Text;
}

//
// Toggle the state of the item.
// If the item has three states, the cycle goes from
//   unchecked -> checked -> indeterminate -> back to unchecked.
// Otherwise the state toggles between
//   unchecked and checked.
//
void
TCheckListItem::Toggle()
{
  if (HasThreeStates) {
    if (IsIndeterminate())
      Uncheck();
    else if (IsChecked())
      SetIndeterminate();
    else
      Check();
  }
  else {
   if (IsChecked())
     Uncheck();
   else
     Check();
  }
}

//
// Programmatically check the item.
//
void
TCheckListItem::Check()
{
  State = BF_CHECKED;
}

//
// Programmatically uncheck the item.
//
void
TCheckListItem::Uncheck()
{
  State = BF_UNCHECKED;
}

//
// Programmatically make the item indeterminate.
//
void
TCheckListItem::SetIndeterminate()
{
  State = BF_GRAYED;
  HasThreeStates = true;
}

//
// Set the three-state property.
//
void
TCheckListItem::SetThreeStates(bool hasThreeStates)
{
  HasThreeStates = hasThreeStates;
  if (IsIndeterminate() && !hasThreeStates)
    Check();
}

//
// Copy the text string.
//
void
TCheckListItem::SetText(const char far* text)
{
  delete[] Text;
  Text = strnewdup(text);
}

//
// Return the text of the item.
//
void
TCheckListItem::GetText(char far* buffer, int len)
{
  strncpy(buffer, Text, len);
}


