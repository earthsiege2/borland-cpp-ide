//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.11  $
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

#if !defined(SECTION) || SECTION == 1

//
// Construct based on an item.
//
TTreeNode::TTreeNode(TTreeWindow& tv, HTREEITEM hti)
:
  TreeView(&tv),
  HtItem(hti)
{
  // nothing else to do
}

//
// Construct on a next node.
//
TTreeNode::TTreeNode(const TTreeNode& ti, TNextCode nc)
{
  TreeView = ti.TreeView;
  HtItem   = ti.HtItem;
  TreeView->GetNextItem(nc, *this);
}

//
// Copy a node.
//
TTreeNode::TTreeNode(const TTreeNode& ti)
{
  TreeView = ti.TreeView;
  HtItem   = ti.HtItem;
}

//
// Copy a node.
//
TTreeNode&
TTreeNode::operator =(const TTreeNode& ti)
{
  TreeView = ti.TreeView;
  HtItem   = ti.HtItem;
  return *this;
}

//
// Adds the item above this item.
//
TTreeNode
TTreeNode::AddSibling(TTreeItem& item)
{
  return InsertItem(item);
}

//
// Inserts a child before the passed item.
//
TTreeNode
TTreeNode::InsertChild(TTreeItem& item, THowToInsert how)
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
TTreeNode::InsertItem(TTreeItem& item)
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

//----------------------------------------------------------------------------
// TTreeWindow

//
// Dynamically create the window.
//
TTreeWindow::TTreeWindow(TWindow* parent, int id, int x, int y, int w, int h,
                         TStyle style, TModule* module)
:
  TListBox(parent, id, x, y, w, h, module)
{
  if (!TCommCtrl::IsAvailable())
    throw TXCommCtrl();

  Attr.Style = WS_CHILD | WS_VISIBLE | style;

  if (TSystem::IsWin95())
    Attr.ExStyle |= WS_EX_CLIENTEDGE;
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
TTreeWindow::SetStyle(TStyle style)
{
  Style = style;
}

//
// Returns true if a particular style is set.
//
bool
TTreeWindow::HasStyle(TStyle style)
{
  return (Style & style) ? true : false;
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
  mask            = 0;
  hItem           = 0;
  state           = 0;
  stateMask       = 0;
  pszText         = 0;
  cchTextMax      = 0;
  iImage          = 0;
  iSelectedImage  = 0;
  cChildren       = 0;
  lParam          = 0;
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
  cchTextMax = (size < 0) ? strlen(buffer) : size;
}

//
// Returns the text of the item.
//
void
TTreeItem::GetText(char far* buffer, int size)
{
  if (mask & TVIF_TEXT) {
    strncpy(buffer, pszText, size);
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
TTreeItem::GetHTreeitem()
{
  if (mask & TVIF_HANDLE) {
    return hItem;
  }
  return 0;
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
TTreeItem::GetItemData()
{
  if (mask & TVIF_PARAM)
    return lParam;
  return 0;
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
