//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.26  $
//
// Implements TTreeWindow, TTreeNode, TTreeItem
//
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_TREEWIND_H)
# include <owl/treewind.h>
#endif
#if !defined(WINSYS_SYSTEM_H)
# include <winsys/system.h>
#endif
#if !defined(__TCHAR_H)
# include <tchar.h>
#endif
#if !defined(__CHECKS_H)
# include <checks.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlCommCtrl);          // CommonCtrl diagnostic group

#if !defined(SECTION) || SECTION == 1

// Cache size for node text (static; default = _MAX_PATH)
//
uint TTreeNode::NodeTextCacheSize = _MAX_PATH;

//
// Construct a new node given the node's text
//
TTreeNode::TTreeNode(TTreeWindow& tree, const char far* text)
:
  TreeView(&tree)
{
  SetText(text, false);
}

//
// Construct a new node given the node's text and image info
//
TTreeNode::TTreeNode(TTreeWindow& tree, const char far* text, int index,
  int selIndex)
:
  TreeView(&tree)
{
  SetText(text, false);
  SetImageIndex(index, false);
  SetSelectedImageIndex(selIndex, false);
}

//
// Construct based on an item.
//
TTreeNode::TTreeNode(TTreeWindow& tree, TV_ITEM item)
:
  ItemStruct(item),
  TreeView(&tree)
{
  if (item.mask & TVIF_TEXT) {
    SetText(item.pszText);
  }
}

//
//
//
TTreeNode::TTreeNode(TTreeWindow& tw, HTREEITEM hItem)
:
  TreeView(&tw)
{
  WARNX(OwlCommCtrl, !hItem, 0, "Constructed TTreeNode passing a null hItem");
  ItemStruct.hItem = hItem;
  ItemStruct.mask = TVIF_HANDLE;
}

//
// Copy constructor: create a new node by copying another node
// Called implicitly by functions that return a TTreeNode by value;
// otherwise, shouldn't be needed.
//
TTreeNode::TTreeNode(const TTreeNode& other)
{
  CopyNode(other);
}

//
//  Assignment operator
//
TTreeNode& TTreeNode::operator=(const TTreeNode& other)
{
  CopyNode(other);
  return *this;
}

//
//  Reset node to make it a copy of another node
//
TTreeNode&
TTreeNode::CopyNode(const TTreeNode& node)
{
  TreeView    = node.TreeView;
  ItemStruct  = node.ItemStruct;
  FlushCache();

  // can't do "n.CacheText" on a const object (TAPointer prevents it)
  //
  TTreeNode& n = CONST_CAST(TTreeNode&, node);
  if (n.CacheText) {
    CacheText = new char[_tcslen(n.CacheText) + 1];
    _tcscpy(CacheText, n.CacheText);
  }
  return *this;
}

//
// Construct the node neighboring a given node.  The flag indicates
// whether to create the next, previous, parent, or first child node.
//
TTreeNode::TTreeNode(const TTreeNode& tn, uint32 flag)
:
  ItemStruct(tn.ItemStruct),
  TreeView(tn.TreeView)
{
  TreeView->GetNextItem(flag, *this);
}

//
// Adds the item above this item.
//
TTreeNode
TTreeNode::AddSibling(const TTreeItem& item) const
{
  return InsertItem(item);
}


TTreeNode
TTreeNode::AddSibling(const TTreeNode& node) const
{
   return InsertItem( node );
}

//
// Inserts a child before the passed item.
//
// If the function fails, the handle in object returned is NULL.  Here's how
// to check for errors:
//
//    node = InsertChild(TTreeItem("node text"), Last);
//    if (!node)                // the HTREEITEM() conversion operator kicks in
//      DoErrorHandling();
//
// Incidentally, the node returned has only the TVIF_HANDLE mask bit
// set, even if the item passed in contained more attributes.  All the
// attributes are correctly sent to the control, but only a handle is
// returned.
//
TTreeNode
TTreeNode::InsertChild(const TTreeItem& item, THowToInsert how) const
{
  TV_INSERTSTRUCT tvis;
  tvis.hParent      = *this;
  tvis.hInsertAfter = (HTREEITEM)how;
  tvis.item         = item;
  HTREEITEM hItem = TreeView->InsertItem(&tvis);
  return TTreeNode(*TreeView, hItem);
}

//
// Inserts an item before this item.
//
TTreeNode
TTreeNode::InsertItem(const TTreeItem& item) const
{
  TV_INSERTSTRUCT tvis;
  TTreeNode parent = GetParent();

  tvis.hParent      = parent;
  tvis.hInsertAfter = *this;
  tvis.item         = item;
  HTREEITEM hItem = TreeView->InsertItem(&tvis);
  return TTreeNode(*TreeView, hItem);
}

//
// Create a temporary structure to store additional information for the
// comparison object.
//
struct TreeCompareThunk {
  const TTwComparator* This;
  uint32             ItemData;
};

//
//
//
int CALLBACK
OwlTreeWindCompare(uint32 itemData1, uint32 itemData2, uint32 lParam)
{
  TreeCompareThunk* ct = (TreeCompareThunk*)lParam;
  return ct->This->Compare(itemData1, itemData2, ct->ItemData);
}

//
// Recursively sort the children of the nodes.
//
bool
TTreeNode::SortChildren(const TTwComparator& comparator, bool recurse, uint32 lParam)
{
  TreeCompareThunk ct;
  ct.This = &comparator;
  ct.ItemData = lParam;
  return TreeView->SortChildren((PFNTVCOMPARE)OwlTreeWindCompare, *this,
                                recurse, (uint32)&ct);
}

//
//
//
bool
TTreeNode::GetState(uint& state, bool getNew)
{
  PRECONDITION(ItemStruct.hItem || !getNew);
  PRECONDITION(TreeView || !getNew);

  // Send a request message to the control if a) the user asked for the
  // message to be sent, or b) the ItemStruct doesn't yet contain
  // the state data.
  //
  if (getNew || !ItemStruct.mask & TVIF_STATE) {
    ItemStruct.mask |= TVIF_STATE;
    if (!GetItem()) {
      ItemStruct.mask &= ~TVIF_STATE;
      return false;
    }
  }

  state = ItemStruct.state;
  return true;
}

//
//
//
bool
TTreeNode::SetState(uint state, bool sendNow /*=true*/ )
{
  PRECONDITION(ItemStruct.hItem || !sendNow);
  PRECONDITION(TreeView || !sendNow);

  ItemStruct.state = state;
  ItemStruct.stateMask |= state;
  ItemStruct.mask |= TVIF_STATE;

  if (sendNow)
    if (!SetItem())
      return false;

  return true;
}

//
// Set the node's text.
// If sendNow is false, the text is merely cached.  It will be
// sent to the control on the next call to SetItem.
//
bool
TTreeNode::SetText(const char far* text, bool sendNow /*=true*/)
{
  PRECONDITION(TreeView || !sendNow);

  if( (uint)ItemStruct.cchTextMax < _tcslen(text) + 1 )
     FlushCache();

  if (!CacheText) {
    CacheText = new char[_tcslen(text) + 1];
  }

  uint length = _tcslen(text) + 1;
  _tcsncpy(CacheText, text, length);
  ItemStruct.pszText    = CacheText;
  ItemStruct.cchTextMax = length;
  ItemStruct.mask      |= TVIF_TEXT;
  return sendNow ? SetItem() : true;
}

//
// Get the node's text.
//
// The text is copied into the "text" buffer.  The caller is responsible
// for creating and managing this buffer.
//
// If getNew if false, the text is simply retrieved from the cache.
// If true, GetText queries the control for the node's current text.
// If the TTreeNode doesn't yet have any text cached, it always ignores
// getNew and queries the control directly.
//
bool
TTreeNode::GetText(char far* text, uint length, bool getNew /*=false*/)
{
  // Update the cache if necessary
  //
  GetText(getNew);

  if (CacheText) {
    _tcsncpy(text, CacheText, length);
  }
  return CacheText != 0;
}

// Retrieve a pointer to the node's text string.  The node object
// owns the buffer pointed to.  The caller should not delete it.
// If GetText fails, it returns 0.
//
char far*
TTreeNode::GetText(bool getNew /*=false*/)
{
  PRECONDITION(TreeView || !getNew);

  // Send a request message to the control if a) the user asked for the
  // message to be sent, or b) the ItemStruct hasn't yet received
  // the text data.
  //
  if (getNew || !CacheText || !(ItemStruct.mask & TVIF_TEXT))  {
    FlushCache();
    CacheText             = new char[NodeTextCacheSize];
    ItemStruct.mask      |= TVIF_TEXT;
    ItemStruct.pszText    = CacheText;
    ItemStruct.cchTextMax = NodeTextCacheSize;
    if (!GetItem()) {
      ItemStruct.mask &= ~TVIF_TEXT;
      return 0;
    }
  }
  return CacheText;
}

//
//  Set the node's image indexes.
//
bool
TTreeNode::SetImageIndex(int index, bool sendNow /*=true*/)
{
  PRECONDITION(TreeView || !sendNow);
  ItemStruct.mask  |= TVIF_IMAGE;
  ItemStruct.iImage = index;
  return sendNow ? SetItem() : true;
}

//
//
//
bool
TTreeNode::SetSelectedImageIndex(int index, bool sendNow)
{
  PRECONDITION(TreeView || !sendNow);
  ItemStruct.mask |= TVIF_SELECTEDIMAGE;
  ItemStruct.iSelectedImage = index;
  return sendNow ? SetItem() : true;
}

//
// Set and Get the user-defined node data.
//

bool
TTreeNode::SetItemData(uint32 data, bool sendNow)
{
  PRECONDITION(TreeView || !sendNow);
  ItemStruct.mask  |= TVIF_PARAM;
  ItemStruct.lParam = data;
  return sendNow ? SetItem() : true;
}

//
//
//
bool
TTreeNode::GetItemData(uint32& data, bool getNew)
{
  PRECONDITION(ItemStruct.hItem || !getNew);
  PRECONDITION(TreeView || !getNew);

  // Send a request message to the control if a) the user asked for the
  // message to be sent, or b) the ItemStruct doesn't yet contain
  // the lParam data.
  //
  if (getNew || !ItemStruct.mask & TVIF_PARAM) {
    ItemStruct.mask |= TVIF_PARAM;
    if (!GetItem()) {
      ItemStruct.mask &= ~TVIF_PARAM;
      return false;
    }
  }

  data = ItemStruct.lParam;
  return true;
}

//
// Set and Get the node's HasChildren info (TV_ITEM.cChildren).
//

bool
TTreeNode::GetHasChildren(int& hasChildren, bool getNew)
{
  PRECONDITION(ItemStruct.hItem || !getNew);
  PRECONDITION(TreeView || !getNew);

  // Send a request message to the control if a) the user asked for the
  // message to be sent, or b) the ItemStruct doesn't yet contain
  // the cChildren data.
  //
  if (getNew || !ItemStruct.mask & TVIF_CHILDREN) {
    ItemStruct.mask |= TVIF_CHILDREN;
    if (!GetItem()) {
      ItemStruct.mask &= ~TVIF_CHILDREN;
      return false;
    }
  }

  hasChildren = ItemStruct.cChildren;
  return true;
}

//
//
//
bool
TTreeNode::SetHasChildren(int count, bool sendNow)
{
  PRECONDITION(TreeView || !sendNow);
  ItemStruct.mask |= TVIF_CHILDREN;
  ItemStruct.cChildren = count;
  return sendNow ? SetItem(&ItemStruct) : true;
}

//
// Return the selected node.
//
TTreeNode
TTreeWindow::GetSelection()
{
  return GetRoot().GetNextItem(TTreeNode::Caret);
}

//
// Return the drop target node.
//
TTreeNode
TTreeWindow::GetDropHilite()
{
  return GetRoot().GetNextItem(TTreeNode::DropHilite);
}

//
// Return the first visible node.
//
TTreeNode
TTreeWindow::GetFirstVisible()
{
  return GetRoot().GetNextItem(TTreeNode::FirstVisible);
}

//
// Retrieve an item's bounding rectangle
//
bool
TTreeNode::GetItemRect(TRect& rect, bool textOnly /*=true*/) const
{
  PRECONDITION(TreeView);
  PRECONDITION(ItemStruct.hItem);

  // The control expects to receive the HTREEITEM in the LPARAM
  //
  *(REINTERPRET_CAST(HTREEITEM*, &rect)) = ItemStruct.hItem;

  return TreeView->SendMessage(TVM_GETITEMRECT, TParam1(textOnly), TParam2(&rect));
}

//
// Empty the node's text cache
//
void
TTreeNode::FlushCache()
{
  CacheText = 0;          // CacheText is a smart pointer
}

//
// Delete the item from the control.
//
bool
TTreeNode::Delete()
{
  PRECONDITION(TreeView);
  if (TreeView->Delete(*this)) {
    ItemStruct.hItem = 0;
    ItemStruct.mask &= ~TVIF_HANDLE;
    return true;
  }
  else
    return false;
}

//----------------------------------------------------------------------------
// TTreeWindow

//
// Dynamically create the window.
//
TTreeWindow::TTreeWindow(TWindow* parent, int id, int x, int y, int w, int h,
                         uint32 style, TModule* module)
:
  TListBox(parent, id, x, y, w, h, module)
{
  if (!TCommCtrl::IsAvailable())
    throw TXCommCtrl();

  SetStyle(WS_CHILD | WS_VISIBLE | style);

  if (TSystem::Has3dUI()) {
    uint32 exStyle = GetExStyle();
    SetExStyle(exStyle |= WS_EX_CLIENTEDGE);
  }
}

//
// Create the TTreeWindow object from a resource.
//
TTreeWindow::TTreeWindow(TWindow* parent, int resourceId, TModule* module)
:
  TListBox(parent, resourceId, module)
{
  if (!TCommCtrl::IsAvailable())
    throw TXCommCtrl();
}

//
// Destructor
//
TTreeWindow::~TTreeWindow()
{
}

//
// Sets the style of the control.
//
void
TTreeWindow::SetStyle(uint32 style)
{
  TWindow::SetStyle(WS_CHILD | WS_VISIBLE | style);
}

//
// Returns true if a particular style is set.
//
bool
TTreeWindow::HasStyle(uint32 style)
{
  return (GetStyle() & style) ? true : false;
}

//
// Returns the common control class name WC_TREEVIEW
//
char far*
TTreeWindow::GetClassName()
{
  return WC_TREEVIEW;
}

//
// Recursively sort the children nodes.
//
bool
TTreeWindow::SortChildren(PFNTVCOMPARE func, HTREEITEM parent, bool recurse, uint32 lParam)
{
  TV_SORTCB cb;
  cb.hParent     = parent;
  cb.lpfnCompare = func;
  cb.lParam      = lParam;

  return ToBool(SendMessage(TVM_SORTCHILDRENCB, TParam1(recurse), TParam2(&cb)));
}

//
// Private Init function to zero out the data members.
//
void
TTreeItem::Init()
{
  memset(this, 0, sizeof(TV_ITEM));
}

//
// Default constructor.
//
TTreeItem::TTreeItem()
{
  Init();
}

//
// Initialize based on an existing item.
//
TTreeItem::TTreeItem(TV_ITEM item)
{
  Init();
  *(TV_ITEM*)this = item;
}

//
// Construct using only text.
//
TTreeItem::TTreeItem(const char far* text, int len)
{
  Init();
  SetText(text, len);
}

//
// Construct based on text, an image index, and a selected index.
//
TTreeItem::TTreeItem(const char far* text, int index, int selIndex)
{
  Init();
  SetText(text);
  SetImageIndex(index);
  SetSelectedImageIndex(selIndex);
}

//
// Sets the text of the item.
//
void
TTreeItem::SetText(const char far* buffer, int size)
{
  mask      |= TVIF_TEXT;
  pszText    = CONST_CAST(char far*, buffer);
  cchTextMax = max(_tcslen(buffer) + 1, size);
}

//
// Returns the text of the item.
//
void
TTreeItem::GetText(char far* buffer, int size)
{
  if (mask & TVIF_TEXT) {
    _tcsncpy(buffer, pszText, size);
  }
}

//
// Sets the magic cookie for the item.
//
void
TTreeItem::SetHTreeItem(HTREEITEM item)
{
  mask |= TVIF_HANDLE;
  hItem = item;
}

//
// Returns the magic cookie of the item.
//
HTREEITEM
TTreeItem::GetHTreeitem() const
{
  return (mask & TVIF_HANDLE) ? hItem : 0;
}

//
// Sets the extra data of the item.
//
void
TTreeItem::SetItemData(uint32 data)
{
  mask  |= TVIF_PARAM;
  lParam = data;
}

//
// Sets the image index of the item.
//
void
TTreeItem::SetImageIndex(int index)
{
  mask  |= TVIF_IMAGE;
  iImage = index;
}

//
// Sets the selected image index of the item.
//
void
TTreeItem::SetSelectedImageIndex(int index)
{
  mask          |= TVIF_SELECTEDIMAGE;
  iSelectedImage = index;
}

//
// Returns the extra data.
//
uint32
TTreeItem::GetItemData() const
{
  return (mask & TVIF_PARAM) ? lParam : 0;
}

#endif // section 1
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TTreeWindow, TListBox);

#if !defined(BI_NO_OBJ_STREAMING)

//
// Reads an instance of TTreeWindow from the passed ipstream
//
void*
TTreeWindow::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TListBox*)GetObject(), is);
  return GetObject();
}

//
// Writes the TTreeWindow to the passed opstream
//
void
TTreeWindow::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TListBox*)GetObject(), os);
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif // section 2
