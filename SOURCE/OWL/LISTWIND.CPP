//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.17  $
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

OWL_DIAGINFO;

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
  if (TSystem::Has3dUI())
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
// Create an item structure used primarily for retrieving information about
// existing items within a Listview control.
//
TListWindItem::TListWindItem(uint msk /*= LVIF_ALL*/,
                             bool allocCache /*= true*/)
{
  Init();
  mask = msk;
  if (allocCache) {
    AllocCache(true);
  }
}

//
// Construct based on an existing structure.
//
TListWindItem::TListWindItem(const LV_ITEM& item)
{
  // First do a shallow copy
  //
  *((LV_ITEM*)this) = item;

  // Deep copy text, if necessary
  //
  if( (item.mask & LVIF_TEXT) &&
      item.pszText &&
      item.pszText != LPSTR_TEXTCALLBACK )
  {
    AllocCache();
    strncpy(pszText, item.pszText, _MAX_PATH);
  }
}

//
// Construct based on text, column number, and length of text.
//
TListWindItem::TListWindItem(const char* text, int subItem, int len)
{
  Init();
  SetText(text, len);
  SetSubItem(subItem);
}

//
//
//
TListWindItem::TListWindItem(const TListWindow& ctl, int index, int subItem,
                             uint msk /*= LVIF_ALL*/)
{
  PRECONDITION(ctl.GetHandle());
  Init();
  mask = msk;

  // Allocate room for text if we're retrieving it
  //
  if (mask & LVIF_TEXT) {
    AllocCache();
  }
  ctl.GetItem(*this, index, subItem);
}

//
//
//
TListWindItem::~TListWindItem()
{
  // Cache's self-cleaning
}

// Clear out all members
//
void
TListWindItem::Init()
{
  memset((LV_ITEM*)this, 0, sizeof(LV_ITEM));
}

//
// Returns the text of the item.
//
void
TListWindItem::GetText(char* buffer, int size) const
{
  if (mask & LVIF_TEXT) {
    strncpy(buffer, pszText, size);
  }
}

//
// Sets the text buffer.
//
void
TListWindItem::SetText(const char* buffer, int size)
{
  mask |= LVIF_TEXT;
  pszText = CONST_CAST(char*, buffer);
  cchTextMax = ((size != 0) ? size : (buffer ? lstrlen(buffer) : 0));
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

//
//
//
void
TListWindItem::AllocCache(bool setpszText /*= true*/)
{
  Cache = new char[_MAX_PATH];
  if (setpszText)
    SetText(Cache, _MAX_PATH);
}

//
//
//
void
TListWindItem::FlushCache()
{
  Cache = 0;
}

//----------------------------------------------------------------------------
// TListWindColumn

//
// Constructs a TListWindColumn object used to retrieve information about
// an existing column. For example,
//    TListWindColumn col;
//    ListWnd->GetColumn(1, col);
//    ShowString(col.GetText()
//
TListWindColumn::TListWindColumn(uint flags /*= 0*/, int subItem /*= 0*/)
{
  Init();
  mask = flags;
  SetSubItem(subItem);
  if (flags & LVCF_TEXT)
    AllocCache();
}

//
//
//
TListWindColumn::TListWindColumn(const TListWindow& ctl, int index,
                                 uint flags  /*= LVCF_ALL*/,
                                 int subItem /*= 0 */)
{
  PRECONDITION(ctl.GetHandle());
  Init();
  mask = flags;
  SetSubItem(subItem);
  if (flags & LVCF_TEXT)
    AllocCache();
  ctl.GetColumn(index, *this);
}

//
// Construct based on the text, width of the column, alignment, and column number
//
TListWindColumn::TListWindColumn(char* text, int width,
                                 TFormat how /*= Left*/,
                                 int subItem /*= 0*/)
{
  Init();
  SetText(text);
  SetFormat(how);
  SetWidth(width, text);
  SetSubItem(subItem);
}

//
//
//
TListWindColumn::~TListWindColumn()
{
  // Cache's self-cleaning
}

//
//
//
void
TListWindColumn::Init()
{
  memset((LV_COLUMN*)this, 0, sizeof(LV_COLUMN));
}

//
// Construct based on exising structure.
//
TListWindColumn::TListWindColumn(const LV_COLUMN& column)
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
TListWindColumn::SetText(const char* text, int size)
{
  mask      |= LVCF_TEXT;
  pszText    = CONST_CAST(char*, text);
  cchTextMax = (size != 0) ? size : (text ? lstrlen(text) : 0);
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
// NOTE: Will compute a default width using the system's default GUI
//       font and the text parameter if 'pixels=0' and 'txt != 0'.
//
void
TListWindColumn::SetWidth(int pixels, char* txt /*= 0*/)
{
  mask |= LVCF_WIDTH;

  if (pixels) {
    // Use user provided size
    //
    cx = pixels;
  } else if (txt) {

    // Compute from text - if provided
    //
    cx = TDefaultGUIFont().GetTextExtent(txt).cx;
  } else {

    // Should we use a better default width ??
    //
    cx = 0;
  }
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

//
//
//
void
TListWindColumn::AllocCache(bool setpszText /*= true*/)
{
  Cache = new char[_MAX_PATH];
  if (setpszText)
    SetText(Cache, _MAX_PATH);
}

//
//
//
void
TListWindColumn::FlushCache()
{
  // First make sure 'pszText' does not point to dangling memory
  //
  if (pszText == Cache) {
    pszText = 0;
    mask &= ~LVCF_TEXT;
  }
  Cache = 0;
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
  return ToBool(SendMessage(LVM_SORTITEMS, TParam1(&ct), TParam2(OwlListViewCompare)));
}

//
// Return the number of items currently selected.
// (Useful before calling GetSelIndexes.)
//
int
TListWindow::GetSelCount() const
{
  return CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETSELECTEDCOUNT);
}

//
//  Fill an integer array with indexes of selected items.
//  (Note GetSelCount returns the number of selected items.)
//  Returns the number of indexes placed in the indexes array.
//  If the list view uses the LVS_SINGLESEL, multiple selection
//  has been disabled and the function returns -1.
//
int
TListWindow::GetSelIndexes(int* indexes, int maxCount) const
{
  int count = 0;                  // number of selected items found

  if (GetStyle() & LVS_SINGLESEL)
    return -1;

  // get index of first selected item
  //
  int index = CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETNEXTITEM,
          TParam1(-1), MkParam2(LVNI_ALL|LVNI_SELECTED, 0));

  // while index indicates a selected item
  //
  while (index != -1) {
    indexes[count] = index;
    count++;
    if (count > maxCount)
      break;

    // get next selected item
    //
    index = CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETNEXTITEM,
            TParam1(index), MkParam2(LVNI_ALL|LVNI_SELECTED, 0));
  }

  return count;
}

//
// Fill an array with strings from the selected items.
// maxCount is the size of the strs[] array.  maxChars is
// the size of each array element.  subItem indicates which
// item string to return.
//
// Return the number of strings retrieved, or -1 for errors.
//
int
TListWindow::GetSelStrings(char far** strs, int maxCount, int maxChars,
  int subItem /*=0*/) const
{
  // This function is for multiselect list views only.
  //
  if (GetStyle() & LVS_SINGLESEL)
    return -1;

  // get index of first selected item
  //
  int index = CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETNEXTITEM,
          TParam1(-1), MkParam2(LVNI_ALL|LVNI_SELECTED, 0));

  // loop through selected items
  //
  int count = 0;
  while (index != -1) {
    CONST_CAST(TListWindow*, this)->GetItemText(index, subItem,
      strs[count], maxChars);
    count++;
    if (count > maxCount)
      break;

    // get next selected item
    //
    index = CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETNEXTITEM,
            TParam1(index), MkParam2(LVNI_ALL|LVNI_SELECTED, 0));
  }

  return count;
}

//
//  Determine selection state of an item.
//  Return true if the item is selected.
//
bool
TListWindow::IsSelected(int index) const
{
  return CONST_CAST(TListWindow*, this)->GetItemState(index, LVIS_SELECTED);
}

//
//  Select or deselect an item.
//  Returns true for success.
//
bool
TListWindow::SetSel(int index, bool select)
{
  return SetItemState(index, select ? LVIS_SELECTED : 0, LVIS_SELECTED);
}

//
//  Select or deselect all the items whose indexes appear in indexes[]
//  Returns true for success.
//
bool
TListWindow::SetSelIndexes(int* indexes, int count, bool select)
{
  // This command is only for multiselect list views.
  //
  if (GetStyle() & LVS_SINGLESEL)
    return false;

  for (int i = 0; i < count; i++)
    if (!SetSel(indexes[i], select))
      return false;

  return true;
}

//
//  Select or deselect all the items in the given range.
//  Returns true for success.
//
bool
TListWindow::SetSelItemRange(bool select, int first, int last)
{
  // This command is only for multiselect list views.
  //
  if (GetStyle() & LVS_SINGLESEL)
    return false;

  for (int i = first; i <= last; i++)
    if (!SetSel(i, select))
      return false;

  return true;
}

