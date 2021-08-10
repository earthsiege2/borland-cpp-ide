//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.10  $
//
// Declares TTreeWindow, TTreeNode, and TTreeItem
//
//----------------------------------------------------------------------------
#if !defined(OWL_TREEWIND_H)
#define OWL_TREEWIND_H

#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif
#if !defined(OWL_LISTBOX_H)
# include <owl/listbox.h>
#endif
#if defined(BI_PLAT_WIN16)
# include <owl/treewn16.h>
#else

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TTreeWindow;
class _OWLCLASS TTreeNode;
class _OWLCLASS TTreeItem;

class _OWLCLASS TTwHitTestInfo;
class _OWLCLASS TTwComparator;

#include <pshpack1.h>
//
// class TTwNotify
// ~~~~~ ~~~~~~~~~
// Basic TTreeWindow notification
//
class _OWLCLASS TTwNotify : public TNotify {
  public:
    uint    action;     // Notification specific flag
    TV_ITEM itemOld;    // Old item state
    TV_ITEM itemNew;    // New item state
    TPoint  ptDrag;     // Point at the time of drag
};

//
// class TTwDispInfoNotify
// ~~~~~ ~~~~~~~~~~~~~~~~~
// A TTreeWindow notification to repaint an item.
//
class _OWLCLASS TTwDispInfoNotify : public TNotify {
  public:
    TV_ITEM item;       // Item to repaint
};

//
// class TTwKeyDownNotify
// ~~~~~ ~~~~~~~~~~~~~~~~
// A TTreeWindow notification that a key has been pressed.
//
class _OWLCLASS TTwKeyDownNotify : public TNotify {
  public:
    uint16 wVKey;       // Virtual Key
    uint   flags;       // Keyboard flags for the notification
};

//
// class TTwHitTestInfo
// ~~~~~ ~~~~~~~~~~~~~~
// A TTreeWindow notification for hit-testing.
//
class _OWLCLASS TTwHitTestInfo : public TV_HITTESTINFO {
  public:
/*
    TPoint    pt;     // in: client coords
    uint16    flags;  // out: TVHT_ flags
    HTREEITEM hItem;  // out:
*/
};
#include <poppack.h>

//
// class TTreeItem
// ~~~~~ ~~~~~~~~~
// Used to represent the data to be stored in the TTreeWindow.
//
class _OWLCLASS TTreeItem : public TV_ITEM {
  public:
    TTreeItem();
    TTreeItem(TV_ITEM item);
    TTreeItem(const char far*, int len = 0);
    TTreeItem(const char far*, int index, int selIndex);

    // Initialize the text
    //
    void SetText(const char far*, int len = -1);
    void GetText(char far*, int len);

    // Set/Get the "magic cookie"
    //
    void      SetHTreeItem(HTREEITEM hItem);
    HTREEITEM GetHTreeitem();

    // Set the imagelist index
    //
    void SetImageIndex(int index);

    // Set the selected image index
    //
    void SetSelectedImageIndex(int index);

    // Store additional information
    //
    void   SetItemData(uint32);
    uint32 GetItemData();

  protected:
    void Init();
};


//
// class TTwComparator
// ~~~~~ ~~~~~~~~~~~~~
// A base class for comparisons to sort items.
//
class _OWLCLASS TTwComparator {
  public:
    // return value is < 0 if item1 < item2
    //                 = 0 if item1 == item2
    //                 > 0 if item1 > item2
    // lParam is user-defined value, pass to TTreeNode::SortChildren
    //
    virtual int Compare(uint32 item1, uint32 item2, uint32 lParam) const;
};


//
// class TTreeNode
// ~~~~~ ~~~~~~~~~
// Use this class to navigate the TTreeWindow.
// Each node conceptually contains a pointer to a TTreeItem.
//
class _OWLCLASS TTreeNode {
  public:
    // How to expand the item.
    //
    enum TExpandCode {
      Collapse        = TVE_COLLAPSE,       // Always collapse
      Expand          = TVE_EXPAND,         // Always expand
      Toggle          = TVE_TOGGLE,         // Toggle between collapse and expand
      CollapseReset   = TVE_COLLAPSERESET   // Collapse this node and all children
    };

    // How to retrieve the next node
    //
    enum TNextCode {
      Root            = TVGN_ROOT,              // Get the root node
      Next            = TVGN_NEXT,              // Get the next sibling
      Previous        = TVGN_PREVIOUS,          // Get the prev sibling
      Parent          = TVGN_PARENT,            // Get the parent of this node
      Child           = TVGN_CHILD,             // Get the first child
      FirstVisible    = TVGN_FIRSTVISIBLE,      // Get the first visible item
      NextVisible     = TVGN_NEXTVISIBLE,       // Get the next visible item
      PreviousVisible = TVGN_PREVIOUSVISIBLE,   // Get the prev visible item
      DropHilite      = TVGN_DROPHILITE,        // Get the item that is the drop target
      Caret           = TVGN_CARET              // Get the item with the caret
    };

    // How to insert the node
    //
    enum THowToInsert {
      First           = (int)TVI_FIRST,      // First child
      Last            = (int)TVI_LAST,       // Last child
      Sort            = (int)TVI_SORT        // Sort order
    };

    // Constructors
    //
    TTreeNode(TTreeWindow&, HTREEITEM = TVI_ROOT);
    TTreeNode(const TTreeNode&, TNextCode);
    TTreeNode(const TTreeNode&);

    // Navigation
    //
    TTreeNode GetParent();
    TTreeNode GetChild();
    TTreeNode GetNextSibling();
    TTreeNode GetPrevSibling();
    TTreeNode GetNextVisible();
    TTreeNode GetPrevVisible();
    TTreeNode GetNextItem(TNextCode flag);

    // Adding and deleting items from the tree
    //
    TTreeNode AddChild(TTreeItem&);         // add item at end
    TTreeNode AddSibling(TTreeItem&);
    TTreeNode InsertChild(TTreeItem&, THowToInsert);
    TTreeNode InsertItem(TTreeItem&);
    bool      Delete();

    // Operations on the node
    //
    bool       GetItem(TTreeItem* item);
    bool       SetItem(TTreeItem* item);

    // Miscellaneous
    //
    HIMAGELIST CreateDragImage();
    HWND       EditLabel();
    bool       EnsureVisible();
    bool       ExpandItem(TExpandCode flag);
    bool       SelectItem(TNextCode flag);

    // Sort the nodes of the subtree
    //
    bool       SortChildren(bool recurse = false);
    bool       SortChildren(const TTwComparator& Comparator, bool recurse = false,
                            uint32 extraParam = 0);

    operator  HTREEITEM() const;
    TTreeNode& operator=(const TTreeNode& ti);

  protected:
    HTREEITEM    HtItem;       // wrapper for this tree item

  private:
    TTreeWindow* TreeView;     // wrapper for item of this tree
};


//
// class TTreeWindow
// ~~~~~ ~~~~~~~~~~~
// Encapsulates the TreeView common control.
// A TreeWindow displays information in a hierarchical manner.
// Each item in the tree can contain text and a picture.
//
class _OWLCLASS TTreeWindow : public TListBox {
  public:
    // Style for the TTreeWindow
    //
    enum TStyle {
      twsNone            = 0,                     // No style
      twsHasButtons      = TVS_HASBUTTONS,        // Each parent has a button
                                                  // for toggling collapse and expand
      twsHasLines        = TVS_HASLINES,          // There are lines between nodes
      twsLinesAtRoot     = TVS_LINESATROOT,       // There are lines at the root
      twsEditLabels      = TVS_EDITLABELS,        // Text labels for items can be edited
      twsDisableDragDrop = TVS_DISABLEDRAGDROP,   // Do not allow drag and drop
      twsShowSelAlways   = TVS_SHOWSELALWAYS,     // Always keep the selection visible
                                                  // scroll if needed
    };

    // The type of the image list
    //
    enum TImageListType {
      Normal = TVSIL_NORMAL,    // Normal imagelist for selected and non-selected items
      State  = TVSIL_STATE      // Imagelist contains images for user-defined states
    };

    // Constructors and destructor
    //
    TTreeWindow(TWindow* parent, int id, int x, int y, int w, int h,
                TStyle style = twsNone, TModule* module = 0);
    TTreeWindow(TWindow* parent, int resourceId, TModule* module = 0);
   ~TTreeWindow();

    // Style management
    //
    void SetStyle(TStyle style);
    bool HasStyle(TStyle style);

    // TreeNode retrieval
    //
    TTreeNode GetRoot();
    TTreeNode GetSelection();
    TTreeNode GetDropHilite();
    TTreeNode GetFirstVisible();

    // Indent level
    //
    uint GetIndent();
    void SetIndent(uint);

    // Image list
    //
    HIMAGELIST GetImageList(TImageListType type);
    HIMAGELIST SetImageList(TImageListType type, HIMAGELIST newList);

    // Miscellaneous
    //
    bool DeleteAllItems();
    uint GetItemCount();
    uint GetVisibleCount();
    HWND GetEditControl();

    // Provided for API compatability, use TTreeNode instead.
    // These functions are called from TTreeNode
    //
    void Update();
    bool SortChildren(PFNTVCOMPARE, HTREEITEM parent, bool recurse = false, uint32 lParam = 0);
    bool SortChildren(HTREEITEM item, bool recurse = false);
    bool Delete(HTREEITEM);
    bool EnsureVisible(HTREEITEM);
    bool ExpandItem(TTreeNode::TExpandCode flag, HTREEITEM);
    bool SelectItem(TTreeNode::TNextCode flag, HTREEITEM hItem);
    HWND EditLabel(HTREEITEM item);
    HTREEITEM HitTest(TTwHitTestInfo* info);
    HTREEITEM GetNextItem(TTreeNode::TNextCode nc, HTREEITEM);
    HTREEITEM InsertItem(TV_INSERTSTRUCT far*);
    HIMAGELIST CreateDragImage(HTREEITEM item);

  protected:
    // Override TWindow virtual member functions
    //
    char far* GetClassName();

  protected_data:
    TStyle Style;

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TTreeWindow(const TTreeWindow&);
    TTreeWindow& operator=(const TTreeWindow&);

  DECLARE_STREAMABLE(_OWLCLASS, TTreeWindow, 1);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementation
//

//
// Default comparison function that makes every item equal to every
// other item.
// Derived classes should override this to return proper sorting codes.
//
inline int
TTwComparator::Compare(uint32 item1, uint32 item2, uint32 lParam) const
{
  return 0;
}

//
// Return the magic cookie used by the control associated with the item
//
inline
TTreeNode::operator HTREEITEM() const
{
  return HtItem;
}

//
// Return the HWND of the edit control to change the text
//
inline HWND
TTreeNode::EditLabel()
{
  return TreeView->EditLabel(*this);
}

//
// Return the image list used for a dragging purposes
//
inline HIMAGELIST
TTreeNode::CreateDragImage()
{
  return TreeView->CreateDragImage(*this);
}

//
// Delete the item from the control.
//
inline bool
TTreeNode::Delete()
{
  return TreeView->Delete(*this);
}

//
// Makes sure the item is visible.
// Scroll the items if necessary.
//
inline bool
TTreeNode::EnsureVisible()
{
  return TreeView->EnsureVisible(*this);
}

//
// Expand or contract a parent node.
// Similar to the user clicking on the '-' or '+' area of the control.
//
inline bool
TTreeNode::ExpandItem(TExpandCode flag)
{
  return TreeView->ExpandItem(flag, (HTREEITEM)*this);
}

//
// Make the next item selected.
//
inline bool
TTreeNode::SelectItem(TNextCode flag)
{
  return TreeView->SelectItem(flag, *this);
}

//
// Return the next item.
//
inline TTreeNode
TTreeNode::GetNextItem(TNextCode flag)
{
  return TTreeNode(*TreeView, TreeView->GetNextItem(flag, *this));
}

//
// Adds an item to the end of the child list.
//
inline TTreeNode
TTreeNode::AddChild(TTreeItem& item)
{
  return InsertChild(item, Last);
}

//
// Return the parent of the current node.
//
inline TTreeNode
TTreeNode::GetParent()
{
  return GetNextItem(Parent);
}

//
// Get the first child of the current node.
//
inline TTreeNode
TTreeNode::GetChild()
{
  return GetNextItem(Child);
}

//
// Return the next sibling.
//
inline TTreeNode
TTreeNode::GetNextSibling()
{
  return GetNextItem(Next);
}

//
// Return the previous sibling.
//
inline TTreeNode
TTreeNode::GetPrevSibling()
{
  return GetNextItem(Previous);
}

//
// Return the next visible item.
//
inline TTreeNode
TTreeNode::GetNextVisible()
{
  return GetNextItem(NextVisible);
}

//
// Return the next previous item.
//
inline TTreeNode
TTreeNode::GetPrevVisible()
{
  return GetNextItem(PreviousVisible);
}

//
// Sort the children of this node
//
inline bool
TTreeNode::SortChildren(bool recurse)
{
  return TreeView->SortChildren(*this, recurse);
}

//
// Return the item associated with the node
//
inline bool
TTreeNode::GetItem(TTreeItem* item)
{
  item->SetHTreeItem(*this);
  return ToBool(TreeView->SendMessage(TVM_GETITEM, 0, TParam2(item)));
}

//
// Set the item associated with this node
//
inline bool
TTreeNode::SetItem(TTreeItem* item)
{
  item->SetHTreeItem(*this);
  return ToBool(TreeView->SendMessage(TVM_SETITEM, 0, TParam2(item)));
}

//----------------------------------------------------------------------------
// TTreeWindow

//
// Return the item that contains the point.
//
inline HTREEITEM
TTreeWindow::HitTest(TTwHitTestInfo* info)
{
  return (HTREEITEM)SendMessage(TVM_HITTEST, 0, TParam2(info));
}

//
// Set the image list used by the control.
//
inline HIMAGELIST
TTreeWindow::SetImageList(TImageListType type, HIMAGELIST newList)
{
  return (HIMAGELIST)SendMessage(TVM_SETIMAGELIST, TParam1(type), TParam2(newList));
}

//
// Return the image list used by the control.
//
inline HIMAGELIST
TTreeWindow::GetImageList(TImageListType type)
{
  return (HIMAGELIST)SendMessage(TVM_GETIMAGELIST, TParam1(type));
}

//
// Create a drag image.
//
inline HIMAGELIST
TTreeWindow::CreateDragImage(HTREEITEM item)
{
  return (HIMAGELIST)SendMessage(TVM_CREATEDRAGIMAGE, 0, TParam2(item));
}

//
// Return the edit control used for editing the text.
//
inline HWND
TTreeWindow::GetEditControl()
{
  return (HWND)SendMessage(TVM_GETEDITCONTROL);
}

//
// Enable the user to edit the text of an item.
//
inline HWND
TTreeWindow::EditLabel(HTREEITEM item)
{
  return (HWND)SendMessage(TVM_EDITLABEL, 0, TParam2(item));
}

//
// Return the next item.
//
inline HTREEITEM
TTreeWindow::GetNextItem(TTreeNode::TNextCode nc, HTREEITEM hItem)
{
  if (hItem == TVI_ROOT)  // Workaround for Win95 bug.
    hItem = 0;
  return (HTREEITEM)SendMessage(TVM_GETNEXTITEM, nc, TParam2(hItem));
}

//
// Delete the item.
//
inline bool
TTreeWindow::Delete(HTREEITEM hItem)
{
  return ToBool(SendMessage(TVM_DELETEITEM, 0, TParam2(hItem)));
}

//
// Makes sure the item is visible.
//
inline bool
TTreeWindow::EnsureVisible(HTREEITEM hItem)
{
  return ToBool(SendMessage(TVM_ENSUREVISIBLE, 0, TParam2(hItem)));
}

//
// Expand and contract the parent node.
//
inline bool
TTreeWindow::ExpandItem(TTreeNode::TExpandCode flag, HTREEITEM hItem)
{
  return ToBool(SendMessage(TVM_EXPAND, flag, TParam2(hItem)));
}

//
// Select the next item.
//
inline bool
TTreeWindow::SelectItem(TTreeNode::TNextCode flag, HTREEITEM hItem)
{
  return ToBool(SendMessage(TVM_SELECTITEM, flag, TParam2(hItem)));
}

//
// Insert an item.
//
inline HTREEITEM
TTreeWindow::InsertItem(TV_INSERTSTRUCT far* tvis)
{
  return (HTREEITEM)SendMessage(TVM_INSERTITEM, 0, TParam2(tvis));
}

//
// Remove all items from the control
//
inline bool
TTreeWindow::DeleteAllItems()
{
  return Delete(TVI_ROOT);
}

//
// Return the number of items in the control.
//
inline uint
TTreeWindow::GetItemCount()
{
  return (uint)SendMessage(TVM_GETCOUNT);
}

//
// Return the number of the fully visible items in the control.
//
inline uint
TTreeWindow::GetVisibleCount()
{
  return (uint)SendMessage(TVM_GETVISIBLECOUNT);
}

//
// Return the number of pixels per indent level.
//
inline uint
TTreeWindow::GetIndent()
{
  return (uint)SendMessage(TVM_GETINDENT);
}

//
// Set the number of pixels per indent level.
//
inline void
TTreeWindow::SetIndent(uint indent)
{
  SendMessage(TVM_SETINDENT, indent);
}

//
// Sort the children of 'item'.
// Recursively sort each children if 'recurse' is true.
//
inline bool
TTreeWindow::SortChildren(HTREEITEM item, bool recurse)
{
  return ToBool(SendMessage(TVM_SORTCHILDREN, recurse, TParam2(item)));
}

//
// Return the root node.
//
inline TTreeNode
TTreeWindow::GetRoot()
{
  return TTreeNode(*this);
}

//
// Return the selected node.
//
inline TTreeNode
TTreeWindow::GetSelection()
{
  return GetRoot().GetNextItem(TTreeNode::Caret);
}

//
// Return the drop target node.
//
inline TTreeNode
TTreeWindow::GetDropHilite()
{
  return GetRoot().GetNextItem(TTreeNode::DropHilite);
}

//
// Return the first visible node.
//
inline TTreeNode
TTreeWindow::GetFirstVisible()
{
  return GetRoot().GetNextItem(TTreeNode::FirstVisible);
}

//
// Compatability for Win32
//
inline void
TTreeWindow::Update()
{
}

#endif  // BI_PLAT_WIN32

#endif  // OWL_TREEWIND_H
