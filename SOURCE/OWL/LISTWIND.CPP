//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.10  $
//
// Implementation of TListWindow and support classes
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_LISTWIND_H)
# include <owl/listwind.h>
#endif
#if !defined(WINSYS_SYSTEM_H)
# include <winsys/system.h>
#endif

//
// Constructor that creates a window
//
TListWindow::TListWindow(TWindow* parent, int id,
  int x, int y, int w, int h, TModule* module)
:
  TControl(parent, id, 0, x, y, w, h, module)
{
  if (!TCommCtrl::IsAvailable())
    throw TXCommCtrl();

#if defined(BI_PLAT_WIN32)
  if (TSystem::IsWin95())
    Attr.ExStyle |= WS_EX_CLIENTEDGE;
#endif
}

//
// Constructor from resource
//
TListWindow::TListWindow(TWindow* parent, int resourceId, TModule* module)
:
  TControl(parent, resourceId, module)
{
  if (!TCommCtrl::IsAvailable())
    throw TXCommCtrl();
}

//
// Destructor
//
TListWindow::~TListWindow()
{
}

//----------------------------------------------------------------------------
// TLwFindInfo

//
// Constructor
//
TLwFindInfo::TLwFindInfo()
{
  Init();
}

//
// Construct based on existing structure.
//
TLwFindInfo::TLwFindInfo(LV_FINDINFO findInfo)
{
  *(LV_FINDINFO*)this = findInfo;
}

//
// Private Init to zero out all data members.
//
void
TLwFindInfo::Init()
{
  flags  = 0;
  psz    = 0;
  lParam = 0;
}

//
// Set extra information.
//
void
TLwFindInfo::SetData(TParam2 param)
{
  flags |= LVFI_PARAM;
  lParam = param;
}

//
// Find partial string.
//
void
TLwFindInfo::SetPartial(char far* text)
{
  flags |= LVFI_PARTIAL;
  SetString(text);
}

//
// Find based on string information.
//
void
TLwFindInfo::SetString(char far* text)
{
  flags |= LVFI_STRING;
  psz = text;
}

//
// Find exact substring.
//
void
TLwFindInfo::SetSubstring(char far* text)
{
  flags &= ~LVFI_PARTIAL;
  SetString(text);
}

//
// Continue to search at beginning if reached the end.
//
void
TLwFindInfo::SetWrap(bool flag)
{
  if (flag) {
    flags |= LVFI_WRAP;
  }
  else {
    flags &= ~LVFI_WRAP;
  }
}

//----------------------------------------------------------------------------
// TLwHitTestInfo

//
// Private Init() to zero out data members.
//
void
TLwHitTestInfo::Init()
{
  pt.x  = 0;
  pt.y  = 0;
  flags = 0;
  iItem = 0;
}

//
// Default constructor. Zero out everything.
//
TLwHitTestInfo::TLwHitTestInfo()
{
  Init();
}

//
// Construct based on an existing structure.
//
TLwHitTestInfo::TLwHitTestInfo(LV_HITTESTINFO info)
{
  *(LV_HITTESTINFO*)this = info;
}

//
// Initialize the point.
//
TLwHitTestInfo::TLwHitTestInfo(TPoint& p)
{
  Init();
  SetPoint(p);
}

//
// Sets the point information
//
void
TLwHitTestInfo::SetPoint(TPoint& p)
{
  pt.x = p.x;
  pt.y = p.y;
}

//----------------------------------------------------------------------------
// TListWindItem

//
// Private Init to zero out data members.
//
void
TListWindItem::Init()
{
  mask       = 0;
  iItem      = 0;
  iSubItem   = 0;
  state      = 0;
  stateMask  = 0;
  pszText    = 0;
  cchTextMax = 0;
  iImage     = 0;
  lParam     = 0;
}

//
// Default constructor
//
TListWindItem::TListWindItem()
{
  Init();
}

//
// Construct based on an existing structure.
//
TListWindItem::TListWindItem(LV_ITEM item)
{
  mask       = item.mask;
  iItem      = item.iItem;
  iSubItem   = item.iSubItem;
  state      = item.state;
  stateMask  = item.stateMask;
  pszText    = item.pszText;
  cchTextMax = item.cchTextMax;
  iImage     = item.iImage;
  lParam     = item.lParam;
}

//
// Construct based on text, column number, and length of text.
//
TListWindItem::TListWindItem(char far* text, int subItem, int len)
{
  Init();
  SetText(text, len);
  SetSubItem(subItem);
}

//
// Returns the text of the item.
//
void
TListWindItem::GetText(char far* buffer, int size)
{
  if (mask & LVIF_TEXT) {
    strncpy(buffer, pszText, size);
  }
}

//
// Sets the text buffer.
//
void
TListWindItem::SetText(char far* buffer, int size)
{
  mask |= LVIF_TEXT;
  pszText = buffer;
  cchTextMax = (size == 0) ? strlen(buffer) : size;
}

//
// Sets the item's index number.
//
void
TListWindItem::SetIndex(int index)
{
  iItem = index;
}

//
// Sets the column number.
//
void
TListWindItem::SetSubItem(int subItem)
{
  iSubItem = subItem;
}

//
// Sets the additional data value.
//
void
TListWindItem::SetItemData(uint32 data)
{
  mask  |= LVIF_PARAM;
  lParam = data;
}

//
// Returns the additional data value.
//
uint32
TListWindItem::GetItemData() const
{
  if (mask & LVIF_PARAM) {
    return lParam;
  }
  return 0;
}

//
// Returns the image list index.
//
int
TListWindItem::GetImageIndex() const
{
  if (mask & LVIF_IMAGE) {
    return iImage;
  }
  return 0;
}

//
// Sets the image list index for the item.
//
void
TListWindItem::SetImageIndex(int index)
{
  mask  |= LVIF_IMAGE;
  iImage = index;
}

//
// Return the state of the item.
//
int
TListWindItem::GetState() const
{
  if (mask & LVIF_STATE) {
    return state;
  }
  return 0;
}

//
// Sets the state of the item.
//
void
TListWindItem::SetState(TListState newState)
{
  mask      |= LVIF_STATE;
  stateMask |= state;
  state      = newState;
}

//
// Retrieve the image list index for the state.
//
int
TListWindItem::GetStateImage() const
{
  if ((mask & LVIF_STATE) && (stateMask & LVIS_STATEIMAGEMASK))
    return (state >> 12) - 1;
  return -1;
}

//
// Sets the image list index for the state.
//
void
TListWindItem::SetStateImage(int index)
{
  mask      |= LVIF_STATE;
  stateMask |= LVIS_STATEIMAGEMASK;
  state = INDEXTOSTATEIMAGEMASK(index+1);
}

//----------------------------------------------------------------------------
// TListWindColumn

//
// Private Init to zero out data members.
//
void
TListWindColumn::Init()
{
  mask       = 0;
  fmt        = 0;
  cx         = 0;
  pszText    = 0;
  cchTextMax = 0;
  iSubItem   = 0;
}

//
// Construct based on the text, width of the column, alignment, and column number
//
TListWindColumn::TListWindColumn(char far* text, int width, TFormat how, int subItem)
{
  Init();
  SetText(text);
  SetFormat(how);
  SetWidth(width);
  SetSubItem(subItem);
}

//
// Default constructor
//
TListWindColumn::TListWindColumn()
{
  Init();
}

//
// Construct based on exising structure.
//
TListWindColumn::TListWindColumn(LV_COLUMN column)
{
  mask       = column.mask;
  fmt        = column.fmt;
  cx         = column.cx;
  pszText    = column.pszText;
  cchTextMax = column.cchTextMax;
  iSubItem   = column.iSubItem;
}

//
// Sets the text and buffer size of the column
//
void
TListWindColumn::SetText(char far* text, int size)
{
  mask      |= LVCF_TEXT;
  pszText    = text;
  cchTextMax = (size == 0) ? strlen(text) : size;
}

//
// Sets the alignment for the column
//
void
TListWindColumn::SetFormat(TFormat how)
{
  mask |= LVCF_FMT;
  fmt   = int(how);
}

//
// Sets the width of the column
//
void
TListWindColumn::SetWidth(int pixels)
{
  mask |= LVCF_WIDTH;
  cx    = pixels;
}

//
// Sets the column number
//
void
TListWindColumn::SetSubItem(int item)
{
  mask    |= LVCF_SUBITEM;
  iSubItem = item;
}

//----------------------------------------------------------------------------
// TListWindow

//
// Return the proper class name.
//
char far*
TListWindow::GetClassName()
{
  return WC_LISTVIEW;
}

//
// Sets the state of the item
//
bool
TListWindow::SetItemState(int index, uint state, uint mask)
{
  LV_ITEM item;
  item.state = state;
  item.stateMask = mask;
  return ToBool(SendMessage(LVM_SETITEMSTATE, index, TParam2(&item)));
}

//
// Create a temporary structure to store additional information for the
// comparison object.
//
struct TListCompareThunk {
  const TLwComparator* This;
  uint32               ItemData;
};

int CALLBACK OWL_EXPORT16
OwlListViewCompare(uint32 itemData1, uint32 itemData2, uint32 lParam)
{
  TListCompareThunk* ct = (TListCompareThunk*)lParam;
  return ct->This->Compare(itemData1, itemData2, ct->ItemData);
}

//
// Sort the items within the List Window.
// TLwComparator is the base class for the comparison function
//
bool
TListWindow::SortItems(const TLwComparator& comparator, uint32 lParam)
{
  TListCompareThunk ct;
  ct.This = &comparator;
  ct.ItemData = lParam;
  return ToBool(SendMessage(LVM_SORTITEMS, TParam1(OwlListViewCompare), lParam));
}

IMPLEMENT_STREAMABLE1(TListWindow, TControl);

#if !defined(BI_NO_OBJ_STREAMING)

//
// Reads an instance of TListWindow from the passed ipstream
//
void*
TListWindow::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TControl*)GetObject(), is);
  return GetObject();
}

//
// Writes the TListWindow to the passed opstream
//
void
TListWindow::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TControl*)GetObject(), os);
}

#endif
