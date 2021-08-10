//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.24  $
//
// Declares TTreeWindow, TTreeNode, and TTreeItem
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

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TTreeWindow;
class _OWLCLASS TTreeNode;
class _OWLCLASS TTreeItem;

class _OWLCLASS TTwHitTestInfo;
class _OWLCLASS TTwComparator;

//
// class TTreeItem
// ~~~~~ ~~~~~~~~~
// Used to represent the data to be stored in the TTreeWindow.
//
class _OWLCLASS TTreeItem : public TV_ITEM {
  public:
    TTreeItem();               // this is called by some TTreeNode constructors
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
    HTREEITEM GetHTreeitem() const;

    // Set the imagelist index
    //
    void SetImageIndex(int index);

    // Set the selected image index
    //
    void SetSelectedImageIndex(int index);

    // Store additional information
    //
    void   SetItemData(uint32);
    uint32 GetItemData() const;

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

    // How to insert the node
    //
    enum THowToInsert {
      First           = (int)TVI_FIRST,      // First child
      Last            = (int)TVI_LAST,       // Last child
      Sort            = (int)TVI_SORT        // Sort order
    };

    // Constructors
    //

    // The next two constructors are for creating new nodes.  Both create only
    // the C++ TTreeNode object.  Call SetItem to make the new node appear in
    // the treeview control.
    //
    TTreeNode(TTreeWindow& tree, const char far* text);
    TTreeNode(TTreeWindow& tree, const char far* text, int index, int selIndex);

    // The next two constructors create a node object to represent a node
    // that already exists.

    // Use this constructor in event handlers. The event message carries
    // a TTwNotify structure.
    //
    TTreeNode(TTreeWindow& tree, TV_ITEM item);

    // This constructor is useful for enumerating nodes on a tree.
    // Passing just the first parameter creates the node object for
    // the tree's root, a good starting point.
    //
    TTreeNode(TTreeWindow& tree, HTREEITEM hItem = TVI_ROOT);

    // Construct the node neighboring a given node.  A TVGN_* flag indicates
    // whether to create the next, previous, parent, or first child node.
    //
    TTreeNode(const TTreeNode& node, uint32 flag);

    // Copy constructor. Used by functions such as TTreeWindow::GetRoot
    // that return a TTreeNode by value.  
    //
    TTreeNode(const TTreeNode&);

    // Assignment operator
    // 
    TTreeNode& operator=(const TTreeNode& other);

    // Navigation
    //
    TTreeNode GetParent() const;
    TTreeNode GetChild() const;
    TTreeNode GetNextSibling() const;
    TTreeNode GetPrevSibling() const;
    TTreeNode GetNextVisible() const;
    TTreeNode GetPrevVisible() const;
    TTreeNode GetNextItem(uint32 flag) const;

    // Adding and deleting items from the tree
    //
    TTreeNode AddChild(const TTreeNode& node) const;
    TTreeNode AddSibling(const TTreeNode& node) const;
    TTreeNode InsertChild(const TTreeNode& node, THowToInsert how) const;
    TTreeNode InsertItem(const TTreeNode& node) const;
    bool      Delete(void);

    // These older add/delete methods use TTreeItem.  They have
    // been replaced by the versions that operate on the node
    // itself.  They are retained for backward compatibility.
    //
    TTreeNode AddChild(const TTreeItem&) const;         // add item at end
    TTreeNode AddSibling(const TTreeItem&) const;
    TTreeNode InsertChild(const TTreeItem&, THowToInsert) const;
    TTreeNode InsertItem(const TTreeItem&) const;

    // These operations affect only information stored in the node object,
    // not the Windows treeview control itself.
    //
    void       SetMask(uint mask);
    uint       GetMask(void) const;
    void       SetStateMask(uint mask);
    uint       GetStateMask(void) const;
    void       SetHTreeItem(HTREEITEM hItem);
    HTREEITEM  GetHTreeItem() const;

    // These operations send messages to the control.  The message delivery
    // might fail, so they return bool.
    //
    bool       SetHasChildren(int hasChildren, bool sendNow = true);
    bool       GetHasChildren(int& hasChildren, bool getNew = true);
    bool       SetState(uint state, bool sendNow = true);
    bool       GetState(uint& state, bool getNew = true);
    bool       SetImageIndex(int index, bool sendNow = true);
    bool       SetSelectedImageIndex(int index, bool sendNow = true);
    bool       SetItemData(uint32 data, bool sendNow = true);
    bool       GetItemData(uint32& data, bool getNew = true);
    bool       GetItemRect(TRect& rect, bool textOnly = true) const;
    
    // Set/GetText store the text in the node's internal buffer so the
    // caller doesn't have to worry about string length and buffer
    // ownership.
    //
    bool       SetText(const char far* text, bool sendNow = true);

    // This GetText copies the string into the caller's buffer
    //
    bool       GetText(char far* text, uint length, bool getNew = false);

    // This GetText returns a pointer to the node's own internal text buffer
    //
    char far*  GetText(bool getNew = false);

    // The default cache size is _MAX_PATH.  The cache size is used only in 
    // Get functions when allocating buffers for strings received from the
    // control. For a control with strings longer than _MAX_PATH, be sure to
    // bump the cache size before calling Get.  (The buffer size is kept
    // in a static variable, so any alteration affects all TTreeNodes.)
    //
    void       SetCacheSize(uint size);
    void       FlushCache(void);              // empty this node's text cache

    // The Set/Get accessors for individual node attributes send a message
    // to put data into, or receive data from, the treeview control.  The
    // sendNow and getNew parameters make it possible to accumulate requests
    // and send them in a single message.
    //
    //    SetItemData(myData, false);   // this sends no message
    //    SetText("MyText", false);     // this sends no message
    //    SetHasChildren(1, true);      // this sends all 3 attributes

    // The recommended way to get and set attributes is with the access 
    // functions for individual attributes.  Those commands call these
    // two function to interact with the Windows control.
    // 
    bool       GetItem(void);
    bool       SetItem(void);

    // Preserved for 5.0 code that still uses the TTreeItem struct.
    //
    bool       GetItem(TTreeItem* item);
    bool       SetItem(TTreeItem* item);

    // Miscellaneous
    //
    HIMAGELIST CreateDragImage();
    HWND       EditLabel();
    bool       EnsureVisible();
    bool       ExpandItem(uint32 flag);
    bool       SelectItem(uint32 flag);

    // Sort the nodes of the subtree
    //
    bool       SortChildren(bool recurse = false);
    bool       SortChildren(const TTwComparator& Comparator, bool recurse = false,
                            uint32 extraParam = 0);

    // The HTREEITEM() operator is useful when enumerating nodes.
    // For example, to enumerate all the top-level nodes:
    //
    // for (TTreeNode& node = GetRoot().GetChild();
    //      node;               // evaluates to null handle after last node
    //      node = node.GetNextSibling())
    // { /* loop code */ };
    //                          
    operator  HTREEITEM() const;

    // Codes for TTreeNode (TExpandCode, TNextCode)
    //
    // Retained for compatiblity, but no longer recommended.
    // Use the TVE_ and TVGN_ constants directly instead of
    // these enums.

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

  protected:
    TTreeItem ItemStruct;             // contains a TV_ITEM with HTREEITEM
    TTreeWindow* TreeView;            // wrapper for item of this tree

  private:
    TAPointer<char> CacheText;        // buffer for node text
    static uint NodeTextCacheSize;    // size of text caching buffer

    // Clone function used by copy constructor
    //
    TTreeNode& CopyNode(const TTreeNode& node);

    // default constructor disallowed
    //
    TTreeNode(void);      
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
    // The type of the image list
    //
    enum TImageListType {
      Normal = TVSIL_NORMAL,    // Normal imagelist for selected and non-selected items
      State  = TVSIL_STATE      // Imagelist contains images for user-defined states
    };

    // Constructors and destructor
    //
    TTreeWindow(TWindow* parent, int id, int x, int y, int w, int h,
                uint32 style = 0, TModule* module = 0);
    TTreeWindow(TWindow* parent, int resourceId, TModule* module = 0);
   ~TTreeWindow();

    // Style management
    //
    void SetStyle(uint32 style);
    bool HasStyle(uint32 style);

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
    bool ExpandItem(uint32 flag, HTREEITEM);
    bool SelectItem(uint32 flag, HTREEITEM hItem);
    HWND EditLabel(HTREEITEM item);
    HTREEITEM HitTest(TTwHitTestInfo* info);
    HTREEITEM GetNextItem(uint32 nc, HTREEITEM);
    HTREEITEM InsertItem(TV_INSERTSTRUCT far*);
    HIMAGELIST CreateDragImage(HTREEITEM item);

    // Styles for TTreeWindow
    //
    // Retained for compatiblity, but no longer recommended.
    // Use the TVS_* style constants directly instead of this enum.
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

  protected:
    // Override TWindow virtual member functions
    //
    char far* GetClassName();

  protected_data:
    uint32 Style;

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

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

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
  return ItemStruct.hItem;
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
TTreeNode::ExpandItem(uint32 flag)
{
  return TreeView->ExpandItem(flag, (HTREEITEM)*this);
}

//
// Make the next item selected.
//
inline bool
TTreeNode::SelectItem(uint32 flag)
{
  return TreeView->SelectItem(flag, *this);
}

//
// Return the next item.
//
inline TTreeNode
TTreeNode::GetNextItem(uint32 flag) const
{
  return TTreeNode(*TreeView, TreeView->GetNextItem(flag, *this));
}

inline TTreeNode
TTreeNode::InsertChild(const TTreeNode& node, THowToInsert how) const
{
  return InsertChild(node.ItemStruct, how);
}

inline TTreeNode
TTreeNode::InsertItem(const TTreeNode& node) const
{
  return InsertItem(node.ItemStruct);
}

inline TTreeNode
TTreeNode::AddChild(const TTreeNode& node) const
{
  return InsertChild(node.ItemStruct, Last);
}

inline TTreeNode
TTreeNode::AddChild(const TTreeItem& item) const
{
  return InsertChild(item, Last);
}

//
// Return the parent of the current node.
//
inline TTreeNode
TTreeNode::GetParent() const
{
  return GetNextItem(Parent);
}

//
// Get the first child of the current node.
//
inline TTreeNode
TTreeNode::GetChild() const
{
  return GetNextItem(Child);
}

//
// Return the next sibling.
//
inline TTreeNode
TTreeNode::GetNextSibling() const
{
  return GetNextItem(Next);
}

//
// Return the previous sibling.
//
inline TTreeNode
TTreeNode::GetPrevSibling() const
{
  return GetNextItem(Previous);
}

//
// Return the next visible item.
//
inline TTreeNode
TTreeNode::GetNextVisible() const
{
  return GetNextItem(NextVisible);
}

//
// Return the next previous item.
//
inline TTreeNode
TTreeNode::GetPrevVisible() const
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

inline void
TTreeNode::SetMask(uint mask)
{
  ItemStruct.mask = mask;
}

inline uint       
TTreeNode::GetMask() const
{
  return ItemStruct.mask;
}

inline void
TTreeNode::SetStateMask(uint mask)
{
  ItemStruct.stateMask = mask;
}

inline uint
TTreeNode::GetStateMask() const
{
  return ItemStruct.stateMask;
}

//
//  Set and Get the node's item handle.
//

inline void
TTreeNode::SetHTreeItem(HTREEITEM hItem)
{
  ItemStruct.SetHTreeItem(hItem);
}

inline HTREEITEM  
TTreeNode::GetHTreeItem() const
{
  return ItemStruct.GetHTreeitem();
}

//
// Set the item associated with this node
//
inline bool
TTreeNode::SetItem(TTreeItem* item)
{
  PRECONDITION(TreeView);
  PRECONDITION(item && item->mask);
  item->SetHTreeItem(*this);
  return TreeView->SendMessage(TVM_SETITEM, 0, TParam2(item)) != 0;
}

//
//
//
inline bool
TTreeNode::SetItem()
{
  PRECONDITION(TreeView);
  PRECONDITION(ItemStruct.mask);
  return TreeView->SendMessage(TVM_SETITEM, 0, TParam2(&ItemStruct)) != 0;
}

//
// Return the item associated with the node
//
inline bool
TTreeNode::GetItem(TTreeItem* item)
{
  PRECONDITION(ItemStruct.hItem);
  PRECONDITION(TreeView);
  item->SetHTreeItem(*this);
  return TreeView->SendMessage(TVM_GETITEM, 0, TParam2(item)) != 0;
}

//
// Update the item information in the node.
// What's set in the mask determines what will be retrieved.
// Unless the user has explicitly called SetMask, the call should
// retrieve everything.
//
inline bool
TTreeNode::GetItem()
{
  PRECONDITION(ItemStruct.mask & TVIF_HANDLE);
  PRECONDITION(ItemStruct.hItem);
  PRECONDITION(TreeView);
  return TreeView->SendMessage(TVM_GETITEM, 0, TParam2(&ItemStruct)) != 0;
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
TTreeWindow::GetNextItem(uint32 nc, HTREEITEM hItem)
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
  return SendMessage(TVM_DELETEITEM, 0, TParam2(hItem)) != 0;
}

//
// Makes sure the item is visible.
//
inline bool
TTreeWindow::EnsureVisible(HTREEITEM hItem)
{
  return SendMessage(TVM_ENSUREVISIBLE, 0, TParam2(hItem)) != 0;
}

//
// Expand and contract the parent node.
//
inline bool
TTreeWindow::ExpandItem(uint32 flag, HTREEITEM hItem)
{
  return SendMessage(TVM_EXPAND, flag, TParam2(hItem)) != 0;
}

//
// Select the next item.
//
inline bool
TTreeWindow::SelectItem(uint32 flag, HTREEITEM hItem)
{
  return SendMessage(TVM_SELECTITEM, flag, TParam2(hItem)) != 0;
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
  return SendMessage(TVM_SORTCHILDREN, recurse, TParam2(item)) != 0;
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
// Compatability for Win32
//
inline void
TTreeWindow::Update()
{
}

#endif  // BI_PLAT_WIN32

#endif  // OWL_TREEWIND_H
