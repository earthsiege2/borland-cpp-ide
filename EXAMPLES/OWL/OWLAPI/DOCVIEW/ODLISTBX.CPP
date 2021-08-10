//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   Implements class TODListBox
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include "odlistbx.h"

TODListBox::TODListBox(int id)
          : TControl(0, id, 0, 0,0, 100,100), BufTemp(0), BufLen(0), MaxWidth(0)
{
  Attr.Style &= ~(LBS_SORT | LBS_HASSTRINGS | LBS_MULTIPLESEL);
  Attr.Style |= (LBS_NOTIFY | WS_VSCROLL | WS_HSCROLL | WS_BORDER | LBS_OWNERDRAWVARIABLE);
}

char far *
TODListBox::GetClassName()
{
  return "LISTBOX";
}

void TODListBox::ItemRedraw(int index)   // force item to be redrawn
{
  TRect rect;
  if (GetItemRect(index, rect) <= 0)
    return;   // return 1 if OK, -1 if error
  InvalidateRect(rect);
}

void TODListBox::DrawItem(DRAWITEMSTRUCT far & dis)
{
  ODItemInfo item;
  UINT action = dis.itemAction;
  item.Hdc = dis.hDC;
  item.State = dis.itemState;
  item.Data  = (void far*) dis.itemData;
  item.Index = dis.itemID;
  item.Bound.Set(dis.rcItem.left, dis.rcItem.top,
                 dis.rcItem.right,dis.rcItem.bottom);

  if (item.Index < 0)
    return; // ignore if empty listbox, no focus rect?
  GetItemInfo(item);       // must fill in: Extent,Text,TextLen,Offset
  if (action & ODA_DRAWENTIRE){
//   // shift the item rect to account for horizontal scrolling
//if (item.Bound.right > clientrect.right)
//      item.Bound.left = -(item.Bound.right - clientrect.right);
  if (item.Extent.cx > MaxWidth) {
    SetHorizontalExtent(MaxWidth = item.Extent.cx);
  }
  DrawItemData(item);      
  action = 0;  // redraw destoys previous focus and selection painting
  if (item.State & ODS_SELECTED) action |= ODA_SELECT;
  if (item.State & ODS_FOCUS)    action |= ODA_FOCUS;
  }
  if (action & ODA_SELECT) {
    ChangeHilight(item);
  }
  if (action & ODA_FOCUS){
   item.Bound.right = item.Extent.cx;  // focus drawn around entire item
   ChangeFocus(item);
  }
}

void TODListBox::MeasureItem (MEASUREITEMSTRUCT far& mis)
{
  ODItemInfo item;
  item.Hdc = ::GetDC(*this);
  item.Data  = (void far*) mis.itemData;
  item.Index = mis.itemID;
  item.State = 0;
  GetItemInfo(item);
  mis.itemHeight = item.Extent.cy;
  mis.itemWidth  = item.Extent.cx;
  if (item.Extent.cx > MaxWidth) {
     SetHorizontalExtent(MaxWidth = item.Extent.cx);
  }
  ::ReleaseDC(*this, item.Hdc);
}

// The following methods are defaults for use with text string items only.
// These must be overridden if for data items that are not standard text.
// If the style LBS_HASSTRINGS is set, strings are stored within the list box.
// Otherwise only the pointers are stored; data must be managed by the caller.

BOOL TODListBox::GetItemInfo(ODItemInfo& item) {
  LPSTR str;
  int len;
  if (Attr.Style & LBS_HASSTRINGS) {   // strings stored in list box
    len = GetStringLen(item.Index);
    if (len == 0) {
      str = 0;
    } else {
      if (len >= BufLen){  // check temporary buffer size
        if (BufTemp) delete BufTemp;
        BufTemp = new char[BufLen = len+1];
      }
      GetString(str = BufTemp, item.Index);
    }
  } else { // assume text pointer is allocated data stored in item data     
    str = (char far*)item.Data;
    len = str ? lstrlen(str) : 0;
  }
  item.TextLen = len;
  item.Text = str;
  if (!len) {
    str = " ";     // must have text to measure
    len++;
  }
  GetTextExtentPoint(item.Hdc, str, len, &item.Extent);
  item.Extent.cx += 2; // room for focus rectangle
  item.Extent.cy += 2; // room for focus rectangle
  item.Offset.x = 1;   // room for focus rectangle, no indentation
  item.Offset.y = 1;   // room for focus rectangle
  return TRUE;         // OK to draw
}

void TODListBox::ChangeHilight(ODItemInfo& item)
{
  InvertRect(item.Hdc, &item.Bound);  // need to fix to do nicer!!
}

void TODListBox::ChangeFocus(ODItemInfo& item)
{
  int brushtype = item.State & ODS_FOCUS ? LTGRAY_BRUSH
                :(item.State & ODS_SELECTED ? BLACK_BRUSH : WHITE_BRUSH);
  FrameRect(item.Hdc, &item.Bound, (HBRUSH)GetStockObject(brushtype));
}

void TODListBox::DrawItemData(ODItemInfo& item)
{
//HFONT oldfont = SelectObject(item.Hdc, StdFont);  // need member HFONT StdFont
  ExtTextOut(item.Hdc, 
         item.Bound.left + item.Offset.x,
         item.Bound.top  + item.Offset.y,
         ETO_CLIPPED | ETO_OPAQUE, 
         &item.Bound,
         item.Text, item.TextLen,
         (LPINT) NULL); /* default char spacing */ 
//SelectObject(item.Hdc, oldfont);
}

IMPLEMENT_STREAMABLE1(TODListBox, TControl);

void*
TODListBox::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TControl*)GetObject(), is);
  is >> GetObject()->MaxWidth;
  GetObject()->BufTemp = 0;
  GetObject()->BufLen  = 0;
  return GetObject();
}

void
TODListBox::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TControl*)GetObject(), os);
  os << GetObject()->MaxWidth;
}
